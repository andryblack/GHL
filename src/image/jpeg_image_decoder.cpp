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

#include "ghl_image_config.h"

#include "jpeg_image_decoder.h"
#include "image_impl.h"

#include "../ghl_log_impl.h"
#include "../ghl_data_impl.h"

#include <cstring>
#include <cstdio>
#include <iostream>
#include <setjmp.h>
#include "jpeg/jpeglib.h"
#include "jpeg/jerror.h"

namespace GHL {
	
	static const char* MODULE = "IMAGE:JPEG";
    
#ifdef USE_JPEG_DECODER
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
    
        
    struct ghl_jpeg_destination_mgr : jpeg_destination_mgr {
        GHL::DataArrayImpl* data;
        static const size_t OUTPUT_BUF_SIZE = 1024 * 64;
        static void ghl_jpeg_init_destination(j_compress_ptr cinfo) {
            ghl_jpeg_destination_mgr* dest = (ghl_jpeg_destination_mgr*) cinfo->dest;
            dest->data->resize(OUTPUT_BUF_SIZE);
            dest->next_output_byte = dest->data->GetDataPtr();
            dest->free_in_buffer = OUTPUT_BUF_SIZE;

        }
        static boolean ghl_jpeg_empty_output_buffer(j_compress_ptr cinfo) {
            ghl_jpeg_destination_mgr* dest = (ghl_jpeg_destination_mgr*) cinfo->dest;
            size_t pos = dest->data->GetSize();
            dest->data->resize(pos+OUTPUT_BUF_SIZE);
            dest->next_output_byte = dest->data->GetDataPtr() + pos;
            dest->free_in_buffer = OUTPUT_BUF_SIZE;
            return TRUE;
        }
        static void ghl_jpeg_term_destination(j_compress_ptr cinfo) {
            ghl_jpeg_destination_mgr* dest = (ghl_jpeg_destination_mgr*) cinfo->dest;
            dest->data->resize(dest->data->GetSize()-dest->free_in_buffer);
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
        return GetJpegFileFormat(buf) ? GHL::IMAGE_FILE_FORMAT_JPEG : ImageFileDecoder::GetFileFormat(buf);
	}
    
    bool JpegDecoder::GetFileInfo(DataStream* file, ImageInfo* info) {
        return JpegDecoder::GetJpegFileInfo(file,info);
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
        data->Release();
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
    
    const Data* JpegDecoder::Encode( const Image* image) {
        if (!image) {
            return 0;
        }
        if (image->GetFormat() != GHL::IMAGE_FORMAT_RGB)
            return 0;
        
        Int32 settings = GetEncodeSettings();
        
        int quality = (settings == 0) ? 90 : settings;
        struct ghl_jpeg_error_mgr jerr;
        
        struct jpeg_compress_struct cinfo;

        cinfo.err = jpeg_std_error(&jerr);
        cinfo.err->error_exit = ghl_jpeg_error_exit;
        cinfo.err->output_message = ghl_jpeg_output_message;

        struct ghl_jpeg_destination_mgr dest;
        dest.data = new DataArrayImpl();
        
        // compatibility fudge:
        // we need to use setjmp/longjmp for error handling as gcc-linux
        // crashes when throwing within external c code
        if (setjmp(jerr.setjmp_buffer))
        {
            // If we get here, the JPEG code has signaled an error.
            // We need to clean up the JPEG object and return.
            
            jpeg_destroy_compress(&cinfo);
            if (dest.data)
                dest.data->Release();
             // return null pointer
            return 0;
        }
        /* Now we can initialize the JPEG compression object. */
        jpeg_create_compress(&cinfo);

        

        dest.init_destination = &ghl_jpeg_destination_mgr::ghl_jpeg_init_destination;
        dest.empty_output_buffer = &ghl_jpeg_destination_mgr::ghl_jpeg_empty_output_buffer;
        dest.term_destination = &ghl_jpeg_destination_mgr::ghl_jpeg_term_destination;
        
        cinfo.dest = &dest;
        cinfo.image_width = image->GetWidth();    /* image width and height, in pixels */
        cinfo.image_height = image->GetHeight();
        cinfo.input_components = 3;       /* # of color components per pixel */
        cinfo.in_color_space = JCS_RGB;   /* colorspace of input image */

        /* Now use the library's routine to set default compression parameters.
         * (You must set at least cinfo.in_color_space before calling this,
         * since the defaults depend on the source color space.)
         */
        jpeg_set_defaults(&cinfo);
        /* Now you can set any non-default parameters you wish to.
         * Here we just illustrate the use of quality (quantization table) scaling:
         */
        jpeg_set_quality(&cinfo, quality, TRUE /* limit to baseline-JPEG values */);


        /* TRUE ensures that we will write a complete interchange-JPEG file.
         * Pass TRUE unless you are very sure of what you're doing.
         */
        jpeg_start_compress(&cinfo, TRUE);
        size_t row_stride = cinfo.image_width * 3;   /* JSAMPLEs per row in image_buffer */
        JSAMPROW row_pointer[1];
        while (cinfo.next_scanline < cinfo.image_height) {
            row_pointer[0] = const_cast<JSAMPROW>(image->GetData()->GetData() + (cinfo.next_scanline * row_stride));
            jpeg_write_scanlines(&cinfo, row_pointer, 1);
        }
        jpeg_finish_compress(&cinfo);
        jpeg_destroy_compress(&cinfo);
        return dest.data;
    }
    
    
    const Data* JpegDecoder::ReEncode(GHL::DataStream* src) {
        // allocate and initialize JPEG decompression object
        struct jpeg_decompress_struct srcinfo;
        struct ghl_jpeg_error_mgr jerr;
        
        //We have to set up the error handler first, in case the initialization
        //step fails.  (Unlikely, but it could happen if you are out of memory.)
        //This routine fills in the contents of struct jerr, and returns jerr's
        //address which we place into the link field in cinfo.
        
        srcinfo.err = jpeg_std_error(&jerr);
        srcinfo.err->error_exit = ghl_jpeg_error_exit;
        srcinfo.err->output_message = ghl_jpeg_output_message;
        
        struct jpeg_compress_struct dstinfo;
        
        
        ghl_jpeg_destination_mgr dest;
        dest.init_destination = &ghl_jpeg_destination_mgr::ghl_jpeg_init_destination;
        dest.empty_output_buffer = &ghl_jpeg_destination_mgr::ghl_jpeg_empty_output_buffer;
        dest.term_destination = &ghl_jpeg_destination_mgr::ghl_jpeg_term_destination;
        
        dest.data = new DataArrayImpl();
        
        
        // compatibility fudge:
        // we need to use setjmp/longjmp for error handling as gcc-linux
        // crashes when throwing within external c code
        if (setjmp(jerr.setjmp_buffer))
        {
            // If we get here, the JPEG code has signaled an error.
            // We need to clean up the JPEG object and return.
            
            jpeg_destroy_decompress(&srcinfo);
            jpeg_destroy_compress(&dstinfo);
           
            if (dest.data)
                dest.data->Release();
            return 0;
        }
        
        
        // specify data source
        ghl_jpeg_source_mgr jsrc;
        jsrc.init_source = &ghl_jpeg_source_mgr::ghl_jpeg_init_source;
        jsrc.fill_input_buffer = &ghl_jpeg_source_mgr::ghl_jpeg_fill_input_buffer;
        jsrc.skip_input_data = &ghl_jpeg_source_mgr::ghl_jpeg_skip_input_data;
        jsrc.resync_to_restart = &jpeg_resync_to_restart;
        jsrc.term_source = &ghl_jpeg_source_mgr::ghl_jpeg_term_source;
        
        jsrc.stream = src;
        
        
        // Now we can initialize the JPEG decompression object.
        jpeg_create_decompress(&srcinfo);
        
        srcinfo.src = &jsrc;
        
        // Decodes JPG input from whatever source
        // Does everything AFTER jpeg_create_decompress
        // and BEFORE jpeg_destroy_decompress
        // Caller is responsible for arranging these + setting up cinfo
        
        // read file parameters with jpeg_read_header()
        jpeg_read_header(&srcinfo, TRUE);
        
        /* Now we can initialize the JPEG compression object. */
        jpeg_create_compress(&dstinfo);
        dstinfo.dest = &dest;
        
        dstinfo.err = jpeg_std_error(&jerr);
        dstinfo.err->error_exit = ghl_jpeg_error_exit;
        dstinfo.err->output_message = ghl_jpeg_output_message;
        
        
        /* Read source file as DCT coefficients */
        jvirt_barray_ptr * coef_arrays = jpeg_read_coefficients(&srcinfo);
     
        /* Initialize destination compression parameters from source values */
        jpeg_copy_critical_parameters(&srcinfo, &dstinfo);
        
        // use arithmetic coding if input file is arithmetic coded
        if (srcinfo.arith_code) {
            dstinfo.arith_code = true;
            dstinfo.optimize_coding = false;
        } else {
            dstinfo.optimize_coding = true;
        }

        /* Start compressor (note no image data is actually written here) */
        jpeg_write_coefficients(&dstinfo, coef_arrays);
        
        /* Finish compression and release memory */
        jpeg_finish_compress(&dstinfo);
        
        (void)jpeg_finish_decompress(&srcinfo);
        jpeg_destroy_decompress(&srcinfo);
        
        return dest.data;
    }
    

#endif
    
    static const GHL::Byte JPEG_MARKER_NONE = 0xff;
    static const GHL::Byte JPEG_MARKER_SOI = 0xd8;
    static const GHL::Byte JPEG_MARKER_SOF0 = 0xc0;                // Baseline
    static const GHL::Byte JPEG_MARKER_SOF1 = 0xc1;                // Extended sequential, Huffman
    static const GHL::Byte JPEG_MARKER_SOF2 = 0xc2;                // Progressive, Huffman
    static const GHL::Byte JPEG_MARKER_SOF9 = 0xc9;                // Extended sequential, arithmetic
    static const GHL::Byte JPEG_MARKER_SOF10 = 0xca;               //Progressive, arithmetic
    static const GHL::Byte JPEG_MARKER_DQT = 0xdb;                  // define quantization table
    
    static inline bool is_sof(GHL::Byte m) {
        return m == JPEG_MARKER_SOF0 ||
        m == JPEG_MARKER_SOF1 ||
        m == JPEG_MARKER_SOF2 ||
        m == JPEG_MARKER_SOF9 ||
        m == JPEG_MARKER_SOF10;
    }
    
    struct jpeg_ctx {
        GHL::Byte marker;
        GHL::Byte buffer[128];
        GHL::UInt32 size;
        GHL::UInt32 pos;
        GHL::DataStream* ds;
        explicit jpeg_ctx(GHL::DataStream* ds) : marker(JPEG_MARKER_NONE),size(0),pos(0),ds(ds){
            
        }
        void read() {
            pos = 0;
            size = ds->Read(buffer, GHL::UInt32(sizeof(buffer)));
        }
        GHL::Byte get_byte() {
            if (pos == size) {
                read();
                if (pos == size) {
                    return 0;
                }
            }
            GHL::Byte ret = buffer[pos];
            ++pos;
            return ret;
        }
        GHL::UInt16 get16be() {
            GHL::UInt16 res = get_byte();
            res <<= 8;
            res |= get_byte();
            return res;
        }
        GHL::Byte get_marker() {
            GHL::Byte ret = marker;
            if (ret != JPEG_MARKER_NONE) {
                marker = JPEG_MARKER_NONE;
                return ret;
            }
            ret = get_byte();
            if (ret != 0xff) return JPEG_MARKER_NONE;
            while (ret == 0xff) {
                ret = get_byte(); // consume repeated 0xff fill bytes
            }
            if (ret == 0 && size==pos && ds->Eof())
                return JPEG_MARKER_NONE;
            return ret;
        }
        void skip(GHL::UInt32 len) {
            pos += len;
            if (pos > size) {
                len = pos - size;
                pos = size = 0;
                ds->Seek(len, GHL::F_SEEK_CURRENT);
            }
        }
    };
    
    bool JpegDecoder::GetJpegFileFormat(const CheckBuffer& buf) {
        for ( size_t i=0; i<sizeof(CheckBuffer);++i) {
            if (buf[i]!=0xff) {
                if( buf[i]==JPEG_MARKER_SOI && i!=0 )
                    return IMAGE_FILE_FORMAT_JPEG;
                break;
            }
        }
        return IMAGE_FILE_FORMAT_UNKNOWN;
    }
    
    bool JpegDecoder::GetJpegFileInfo(DataStream* ds, ImageInfo* info) {
        if (!ds) return false;
        
        jpeg_ctx ctx(ds);
        GHL::Byte m = ctx.get_marker();
        if (m != JPEG_MARKER_SOI) {
            // should not happen
            return false;
        }
        m = ctx.get_marker();
        while (!is_sof(m)) {
            switch (m) {
                case JPEG_MARKER_NONE: // no marker found
                    LOG_ERROR("not found marker");
                    return false;
                case 0xe0: case 0xe1: case 0xe2: case 0xe3: case 0xe4: case 0xe5: case 0xe6: case 0xe7:
                case 0xe8: case 0xe9: case 0xea: case 0xeb: case 0xec: case 0xed: case 0xee: case 0xef: { // APP
                    GHL::UInt16 len = ctx.get16be();
                    if (len < 2) {
                        LOG_ERROR("bad APP len");
                        return false;
                    }
                    len-=2;
                    ctx.skip(len);
                } break;
                case JPEG_MARKER_DQT: {
                    GHL::UInt16 len = ctx.get16be();
                    if (len < 2) {
                        LOG_ERROR("bad DQT len");
                        return false;
                    }
                    len-=2;
                    ctx.skip(len);
                } break;
                default:
                    LOG_ERROR("unexpected marker " << int(m));
                    return false;
            }
            m = ctx.get_marker();
        }
        GHL::UInt16 sof_len = ctx.get16be();
        if (sof_len < 11) {
            LOG_ERROR("bad SOF len");
            return false;
        }
        GHL::Byte p = ctx.get_byte();
        if (p!=8) {
            LOG_ERROR("unsupported BPP:" << int(p));
            return false;
        }
        info->height = ctx.get16be();
        if (info->height == 0) {
            LOG_ERROR("unsupported height==0");
            return false;
        }
        info->width = ctx.get16be();
        if (info->width == 0) {
            LOG_ERROR("unsupported width==0");
            return false;
        }
        GHL::Byte ccount = ctx.get_byte();
        info->image_format = ccount == 1 ? GHL::IMAGE_FORMAT_GRAY : GHL::IMAGE_FORMAT_RGB;
        return true;
    }
} /*namespace*/

