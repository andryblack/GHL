/*
 GHL - Game Helpers Library
 Copyright (C)  Andrey Kunitsyn 2009
 
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 
 Andrey (AndryBlack) Kunitsyn
 blackicebox (at) gmail (dot) com
 */

#include "jpeg_image_decoder.h"
#include "image_impl.h"

#include "../ghl_log_impl.h"

#include <cstring>
#include <cstdio>
#include <iostream>
#include <setjmp.h>
#include "jpeg/jpeglib.h"
#include "jpeg/jerror.h"

namespace GHL {
	
	static const char* MODULE = "IMAGE:JPEG";
    
    JpegDecoder::JpegDecoder() : ImageFileDecoder( IMAGE_FILE_FORMAT_JPEG )
    {
    }
    JpegDecoder::~JpegDecoder()
    {
    }
    
    
    // struct for handling jpeg errors
    struct ghl_jpeg_error_mgr : jpeg_error_mgr
    {
        
        // for longjmp, to return to caller on a fatal error
        jmp_buf setjmp_buffer;
    };
    
    struct ghl_jpeg_source_mgr : jpeg_source_mgr {
        
        GHL::DataStream*    stream;
        static const size_t BUFFER_SIZE = 1024 * 8;
        GHL::Byte           buffer[BUFFER_SIZE];
        bool    start_file;
        
        static void ghl_jpeg_init_source (j_decompress_ptr cinfo)
        {
            ghl_jpeg_source_mgr * src = (ghl_jpeg_source_mgr*)cinfo->src;
            src->start_file = true;
            src->bytes_in_buffer = 0;
        }
        
        
        
        static boolean ghl_jpeg_fill_input_buffer (j_decompress_ptr cinfo)
        {
            ghl_jpeg_source_mgr * src = (ghl_jpeg_source_mgr*)cinfo->src;
            if (src->stream->Eof()) {
                if (src->start_file) {
                    ERREXIT(cinfo, JERR_INPUT_EMPTY);
                } 
                WARNMS(cinfo, JWRN_JPEG_EOF);
                /* Insert a fake EOI marker */
                src->buffer[0] = (JOCTET) 0xFF;
                src->buffer[1] = (JOCTET) JPEG_EOI;
                src->bytes_in_buffer = 2;
                src->next_input_byte = src->buffer;
                return TRUE;
            }
            GHL::UInt32 readed = src->stream->Read(src->buffer, BUFFER_SIZE);
            src->bytes_in_buffer = readed;
            src->next_input_byte = src->buffer;
            src->start_file = false;
            // DO NOTHING
            return TRUE;
        }
        
        static void ghl_jpeg_skip_input_data (j_decompress_ptr cinfo, long num_bytes)
        {
            ghl_jpeg_source_mgr * src = (ghl_jpeg_source_mgr*)cinfo->src;
            if (num_bytes>0) {
                while (num_bytes > (long) src->bytes_in_buffer) {
                    num_bytes -= (long) src->bytes_in_buffer;
                    (void) ghl_jpeg_fill_input_buffer(cinfo);
                    /* note we assume that fill_input_buffer will never return FALSE,
                     * so suspension need not be handled.
                     */
                }
                src->next_input_byte += (size_t) num_bytes;
                src->bytes_in_buffer -= (size_t) num_bytes;

            }
        }
        
        static void ghl_jpeg_term_source (j_decompress_ptr /*cinfo*/)
        {
            // DO NOTHING
        }

    };
    
        
    
    static void ghl_jpeg_error_exit (j_common_ptr cinfo)
    {
        // unfortunately we need to use a goto rather than throwing an exception
        // as gcc crashes under linux crashes when using throw from within
        // extern c code
        
        // Always display the message
        (*cinfo->err->output_message) (cinfo);
        
        // cinfo->err really points to a irr_error_mgr struct
        ghl_jpeg_error_mgr *myerr = (ghl_jpeg_error_mgr*) cinfo->err;
        
        longjmp(myerr->setjmp_buffer, 1);
    }
    
    static void ghl_jpeg_output_message(j_common_ptr cinfo)
    {
        // display the error message.
        char temp1[JMSG_LENGTH_MAX];
        (*cinfo->err->format_message)(cinfo, temp1);
		LOG_ERROR( temp1 );
    }
    
	ImageFileFormat JpegDecoder::GetFileFormat(const CheckBuffer& buf) const {
		for ( size_t i=0; i<sizeof(CheckBuffer);++i) {
			if (buf[i]!=0xff) {
				if( buf[i]==0xd8 && i!=0 )
					return IMAGE_FILE_FORMAT_JPEG;
				break;
			}
		}
		return ImageFileDecoder::GetFileFormat(buf);
	}
    
    bool JpegDecoder::GetFileInfo(DataStream* file, ImageInfo* info) {
    
        // allocate and initialize JPEG decompression object
        struct jpeg_decompress_struct cinfo;
        struct ghl_jpeg_error_mgr jerr;
        
        //We have to set up the error handler first, in case the initialization
        //step fails.  (Unlikely, but it could happen if you are out of memory.)
        //This routine fills in the contents of struct jerr, and returns jerr's
        //address which we place into the link field in cinfo.
        
        cinfo.err = jpeg_std_error(&jerr);
        cinfo.err->error_exit = ghl_jpeg_error_exit;
        cinfo.err->output_message = ghl_jpeg_output_message;
        
        // compatibility fudge:
        // we need to use setjmp/longjmp for error handling as gcc-linux
        // crashes when throwing within external c code
        if (setjmp(jerr.setjmp_buffer))
        {
            // If we get here, the JPEG code has signaled an error.
            // We need to clean up the JPEG object and return.
            
            jpeg_destroy_decompress(&cinfo);
            return false;
        }
        
        // Now we can initialize the JPEG decompression object.
        jpeg_create_decompress(&cinfo);
        
        // specify data source
        ghl_jpeg_source_mgr jsrc;
        jsrc.stream = file;
        
        
        jsrc.init_source = &ghl_jpeg_source_mgr::ghl_jpeg_init_source;
        jsrc.fill_input_buffer = &ghl_jpeg_source_mgr::ghl_jpeg_fill_input_buffer;
        jsrc.skip_input_data = &ghl_jpeg_source_mgr::ghl_jpeg_skip_input_data;
        jsrc.resync_to_restart = &jpeg_resync_to_restart;
        jsrc.term_source = &ghl_jpeg_source_mgr::ghl_jpeg_term_source;
        
        cinfo.src = &jsrc;
        
        // Decodes JPG input from whatever source
        // Does everything AFTER jpeg_create_decompress
        // and BEFORE jpeg_destroy_decompress
        // Caller is responsible for arranging these + setting up cinfo
        
        // read file parameters with jpeg_read_header()
        jpeg_read_header(&cinfo, TRUE);

        info->image_format = IMAGE_FORMAT_RGB;
        info->width = cinfo.image_width;
        info->height = cinfo.image_height;
        
        jpeg_destroy_decompress(&cinfo);
        
        return true;
    }
    
    Image* JpegDecoder::Decode(DataStream* file)
    {
        if (!file) return 0;
        ImageImpl* img = 0;
        
        Byte **rowPtr=0;
        
        
        // allocate and initialize JPEG decompression object
        struct jpeg_decompress_struct cinfo;
        struct ghl_jpeg_error_mgr jerr;
        
        //We have to set up the error handler first, in case the initialization
        //step fails.  (Unlikely, but it could happen if you are out of memory.)
        //This routine fills in the contents of struct jerr, and returns jerr's
        //address which we place into the link field in cinfo.
        
        cinfo.err = jpeg_std_error(&jerr);
        cinfo.err->error_exit = ghl_jpeg_error_exit;
        cinfo.err->output_message = ghl_jpeg_output_message;
        
        // compatibility fudge:
        // we need to use setjmp/longjmp for error handling as gcc-linux
        // crashes when throwing within external c code
        if (setjmp(jerr.setjmp_buffer))
        {
            // If we get here, the JPEG code has signaled an error.
            // We need to clean up the JPEG object and return.
            
            jpeg_destroy_decompress(&cinfo);
            
            // if the row pointer was created, we delete it.
            if (rowPtr)
                delete [] rowPtr;
            delete img;
            // return null pointer
            return 0;
        }
        
        // Now we can initialize the JPEG decompression object.
        jpeg_create_decompress(&cinfo);
        
        // specify data source
        ghl_jpeg_source_mgr jsrc;
        jsrc.stream = file;
        
        
        jsrc.init_source = &ghl_jpeg_source_mgr::ghl_jpeg_init_source;
        jsrc.fill_input_buffer = &ghl_jpeg_source_mgr::ghl_jpeg_fill_input_buffer;
        jsrc.skip_input_data = &ghl_jpeg_source_mgr::ghl_jpeg_skip_input_data;
        jsrc.resync_to_restart = &jpeg_resync_to_restart;
        jsrc.term_source = &ghl_jpeg_source_mgr::ghl_jpeg_term_source;
        cinfo.src = &jsrc;
        
        // Decodes JPG input from whatever source
        // Does everything AFTER jpeg_create_decompress
        // and BEFORE jpeg_destroy_decompress
        // Caller is responsible for arranging these + setting up cinfo
        
        // read file parameters with jpeg_read_header()
        jpeg_read_header(&cinfo, TRUE);
        
        cinfo.out_color_space=JCS_RGB;
        cinfo.out_color_components=3;
        cinfo.do_fancy_upsampling=FALSE;
        
        // Start decompressor
        jpeg_start_decompress(&cinfo);
        
        
        // Get image data
        UInt32 rowspan = cinfo.image_width * cinfo.out_color_components;
        UInt32 width = cinfo.image_width;
        UInt32 height = cinfo.image_height;
        DataImpl* data = new DataImpl(width*height*3);
        img = new ImageImpl(width,height,IMAGE_FORMAT_RGB,data);
        Byte* output = data->GetDataPtr();
        
		// Here we use the library's state variable cinfo.output_scanline as the
        // loop counter, so that we don't have to keep track ourselves.
        // Create array of row pointers for lib
        rowPtr = new Byte* [height];
        
        for( size_t i = 0; i < height; i++ )
            rowPtr[i] = &output[ i * rowspan ];
        
        UInt32 rowsRead = 0;
        
        while( cinfo.output_scanline < cinfo.output_height )
            rowsRead += jpeg_read_scanlines( &cinfo, &rowPtr[rowsRead], cinfo.output_height - rowsRead );
        
        delete [] rowPtr;
        // Finish decompression
        
        jpeg_finish_decompress(&cinfo);
        
        // Release JPEG decompression object
        // This is an important step since it will release a good deal of memory.
        jpeg_destroy_decompress(&cinfo);
        
        return img;
    }
    
    bool JpegDecoder::Encode( const Image* /*image*/, DataStream* /*ds*/) {
        return false;
    }
    
} /*namespace*/
