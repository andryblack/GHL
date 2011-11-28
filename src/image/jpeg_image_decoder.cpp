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

#include <cstring>
#include <cstdio>
#include <iostream>
#include <setjmp.h>
#include "jpeg/jpeglib.h"

namespace GHL {
    
    JpegDecoder::JpegDecoder() : ImageFileDecoder( IMAGE_FILE_FORMAT_JPEG )
    {
    }
    JpegDecoder::~JpegDecoder()
    {
    }
    
    
    // struct for handling jpeg errors
    struct ghl_jpeg_error_mgr
    {
        // public jpeg error fields
        struct jpeg_error_mgr pub;
        
        // for longjmp, to return to caller on a fatal error
        jmp_buf setjmp_buffer;
    };
    
    static void ghl_jpeg_init_source (j_decompress_ptr cinfo)
    {
        // DO NOTHING
    }
    
    
    
    static boolean ghl_jpeg_fill_input_buffer (j_decompress_ptr cinfo)
    {
        // DO NOTHING
        return 1;
    }
    
    static void ghl_jpeg_skip_input_data (j_decompress_ptr cinfo, long count)
    {
        jpeg_source_mgr * src = cinfo->src;
        if(count > 0)
        {
            src->bytes_in_buffer -= count;
            src->next_input_byte += count;
        }
    }
    
    static void ghl_jpeg_term_source (j_decompress_ptr cinfo)
    {
        // DO NOTHING
    }
    
    
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
        std::cout << "JPEG error : " << temp1 << std::endl;
        //os::Printer::log("JPEG FATAL ERROR",temp1, ELL_ERROR); ///@todo
    }
    
    Image* JpegDecoder::Decode(DataStream* file)
    {
        if (!file) return 0;
        ImageImpl* img = 0;
        
        size_t file_size = 0;
        file->Seek(0,F_SEEK_END);
        file_size = file->Tell();
        file->Seek(0,F_SEEK_BEGIN);
        
        Byte **rowPtr=0;
        Byte* input = new Byte[file_size];
        file->Read(input, UInt32(file_size));
        
        
        // allocate and initialize JPEG decompression object
        struct jpeg_decompress_struct cinfo;
        struct ghl_jpeg_error_mgr jerr;
        
        //We have to set up the error handler first, in case the initialization
        //step fails.  (Unlikely, but it could happen if you are out of memory.)
        //This routine fills in the contents of struct jerr, and returns jerr's
        //address which we place into the link field in cinfo.
        
        cinfo.err = jpeg_std_error(&jerr.pub);
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
            
            delete [] input;
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
        jpeg_source_mgr jsrc;
        
        // Set up data pointer
        jsrc.bytes_in_buffer = file_size;
        jsrc.next_input_byte = (JOCTET*)input;
        cinfo.src = &jsrc;
        
        jsrc.init_source = ghl_jpeg_init_source;
        jsrc.fill_input_buffer = ghl_jpeg_fill_input_buffer;
        jsrc.skip_input_data = ghl_jpeg_skip_input_data;
        jsrc.resync_to_restart = jpeg_resync_to_restart;
        jsrc.term_source = ghl_jpeg_term_source;
        
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
        
        img = new ImageImpl(width,height,IMAGE_FORMAT_RGB);
        Byte* output = img->GetDataPtr();
        
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
        
        delete [] input;
        return img;
    }
    
    bool JpegDecoder::Encode( const Image* image, DataStream* ds) {
        return false;
    }
    
} /*namespace*/