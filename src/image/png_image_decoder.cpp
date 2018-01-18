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

#include "png_image_decoder.h"
#include "image_impl.h"
#include "../ghl_log_impl.h"

#include "libpng/png.h"
#include <cstdio>
#include <cassert>

namespace GHL {

    static const char* MODULE = "IMAGE:PNG";
    
	PngDecoder::PngDecoder() : ImageFileDecoder(IMAGE_FILE_FORMAT_PNG)
	{
	}

	PngDecoder::~PngDecoder()
	{
	}

    static void error_func(png_structp /*png_ptr*/,const char* msg)
    {
        LOG_ERROR( msg );	 
    }
	
	

    static void warning_func(png_structp /*png*/,const char* err)
	{
        LOG_WARNING( err );
	}

    // PNG function for file reading
    static void PNGAPI read_data_fcn(png_structp png_ptr, png_bytep data, png_size_t length)
    {
        png_size_t check;

        DataStream* file=(DataStream*)png_get_io_ptr(png_ptr);
        check=(png_size_t) file->Read((Byte*)data,UInt32(length));

        if (check != length)
            png_error(png_ptr, "Read Error");
            
    }

    ImageFileFormat PngDecoder::GetFileFormat(const CheckBuffer& buf) const {
        if (png_sig_cmp(buf, 0, 8)==0)
            return IMAGE_FILE_FORMAT_PNG;
        return ImageFileDecoder::GetFileFormat(buf);
    }

    bool PngDecoder::CheckSignature(const Byte* data,UInt32 len) {
        if (len<8) return false;
        if ( png_sig_cmp(data, 0, 8)!=0 )
        {
            return false;
        }
        return true;
    }

    bool PngDecoder::GetFileInfo(DataStream* file, ImageInfo* info) {
        png_byte buffer[8];
        // Read the first few bytes of the PNG file
        if (file->Read(buffer, 8) != 8) {
            LOG_VERBOSE("error reading signature");
            return false;
        }
        
        // Check if it really is a PNG file
        if ( png_sig_cmp(buffer, 0, 8)!=0 )
        {
            //LOG_VERBOSE("is not a png file");
            return false;
        }
        
        png_structp png_ptr = png_create_read_struct
        (PNG_LIBPNG_VER_STRING, (png_voidp)this,
         &error_func, &warning_func);
        
        if (!png_ptr) {
            LOG_ERROR("png_create_read_struct");
            return false;
        }
        
        // Allocate the png info struct
        png_infop info_ptr = png_create_info_struct(png_ptr);
        if (!info_ptr)
        {
            LOG_ERROR(" Internal PNG create info struct failure");
            png_destroy_read_struct(&png_ptr, NULL, NULL);
            return false;
        }
        
        // for proper error handling
        if (setjmp(png_jmpbuf(png_ptr)))
        {
            png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
            LOG_ERROR(" error");
            return false;
        }
        
        png_set_read_fn(png_ptr, file, read_data_fcn);
        
        png_set_sig_bytes(png_ptr, 8); // Tell png that we read the signature
        
        png_read_info(png_ptr, info_ptr); // Read the info section of the png file
        
        info->width = png_get_image_width(png_ptr, info_ptr);
        info->height = png_get_image_height(png_ptr, info_ptr);
        
        int ColorType = png_get_color_type(png_ptr,info_ptr);
        //int BitDepth = png_get_bit_depth(png_ptr,info_ptr);

        if (ColorType == PNG_COLOR_TYPE_PALETTE) {
            if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS))
                info->image_format = IMAGE_FORMAT_RGBA;
            else
                info->image_format = IMAGE_FORMAT_RGB;
        } else if (ColorType == PNG_COLOR_TYPE_GRAY_ALPHA) {
            info->image_format = IMAGE_FORMAT_RGBA;
        } else if (ColorType == PNG_COLOR_TYPE_RGB_ALPHA ) {
            info->image_format = IMAGE_FORMAT_RGBA;
        } else if ( ColorType == PNG_COLOR_TYPE_GRAY ) {
            info->image_format = IMAGE_FORMAT_GRAY;
        } else {
            info->image_format = IMAGE_FORMAT_RGB;
        }
        
        png_destroy_read_struct(&png_ptr,&info_ptr, 0); // Clean up memory
        
        return true;
    }
    
Image* PngDecoder::Decode(DataStream* file)
{
	if (!file)
		return 0;
    
    //LOG_VERBOSE("try decode png");

	ImageImpl* image = 0;
	//Used to point to image rows
	Byte** RowPointers = 0;

	png_byte buffer[8];
	// Read the first few bytes of the PNG file
	if (file->Read(buffer, 8) != 8) {
		LOG_VERBOSE("error reading signature");
		return 0;
	}

	// Check if it really is a PNG file
	if ( png_sig_cmp(buffer, 0, 8)!=0 )
	{
		//LOG_VERBOSE("is not a png file");
		return 0;
	}

	png_structp png_ptr = png_create_read_struct
       (PNG_LIBPNG_VER_STRING, (png_voidp)this,
        &error_func, &warning_func);

	if (!png_ptr) {
		LOG_ERROR("png_create_read_struct");
        return (0);
	}
	
	// Allocate the png info struct
	png_infop info_ptr = png_create_info_struct(png_ptr);
	if (!info_ptr)
	{
		LOG_ERROR(" Internal PNG create info struct failure");
		png_destroy_read_struct(&png_ptr, NULL, NULL);
		return 0;
	}

	// for proper error handling
	if (setjmp(png_jmpbuf(png_ptr)))
	{
		png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
		if (RowPointers)
			delete [] RowPointers;
		LOG_ERROR(" error");
		return 0;
	}

	png_set_read_fn(png_ptr, file, read_data_fcn);

	png_set_sig_bytes(png_ptr, 8); // Tell png that we read the signature

	png_read_info(png_ptr, info_ptr); // Read the info section of the png file
	
	unsigned int Width;
	unsigned int Height;
    int ColorType = png_get_color_type(png_ptr,info_ptr);
    int BitDepth = png_get_bit_depth(png_ptr,info_ptr);

	// Convert palette color to true color
	if (ColorType==PNG_COLOR_TYPE_PALETTE)
		png_set_palette_to_rgb(png_ptr);

	if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS))
		png_set_tRNS_to_alpha(png_ptr);

	// Convert high bit colors to 8 bit colors
	if (BitDepth == 16)
		png_set_strip_16(png_ptr);
		
	// Convert gray with alpha color to true color
	if ( ColorType==PNG_COLOR_TYPE_GRAY_ALPHA)
		png_set_gray_to_rgb(png_ptr);
		
	// Update the changes
	png_read_update_info(png_ptr, info_ptr);
	{
		// Use temporary variables to avoid passing casted pointers
		png_uint_32 w,h;
		// Extract info
		png_get_IHDR(png_ptr, info_ptr,
			&w, &h,
			&BitDepth, &ColorType, NULL, NULL, NULL);
		Width=w;
		Height=h;
	}
		
	// Convert RGBA to BGRA
	if (ColorType==PNG_COLOR_TYPE_RGB_ALPHA)
	{
#ifdef __BIG_ENDIAN__
		//png_set_swap_alpha(png_ptr);
#else
		//png_set_bgr(png_ptr);
#endif
	}

	//png_set_bgr(png_ptr);
	
	// Update the changes
	{
		// Use temporary variables to avoid passing casted pointers
		png_uint_32 w,h;
		// Extract info
		png_get_IHDR(png_ptr, info_ptr,
			&w, &h,
			&BitDepth, &ColorType, NULL, NULL, NULL);
		Width=w;
		Height=h;
	}

	size_t pw = 0;
	// Create the image structure to be filled by png data
	if (ColorType==PNG_COLOR_TYPE_RGB_ALPHA)
	{
		image = new ImageImpl(Width,Height,IMAGE_FORMAT_RGBA);
		pw = 4;
	}
	else if (ColorType==PNG_COLOR_TYPE_GRAY )
	{
		image = new ImageImpl(Width,Height,IMAGE_FORMAT_GRAY);
		pw = 1;
	} else
	{
		image = new ImageImpl(Width,Height,IMAGE_FORMAT_RGB);
		pw = 3;
	}
	if (!image)
	{
		LOG_ERROR(" Internal PNG create image struct failure");
		png_destroy_read_struct(&png_ptr, NULL, NULL);
		return 0;
	}

	// Create array of pointers to rows in image data
	RowPointers = new png_bytep[Height];
	if (!RowPointers)
	{
		LOG_ERROR(" Internal PNG create row pointers failure");
		png_destroy_read_struct(&png_ptr, NULL, NULL);
		delete image;
		return 0;
	}

	// Fill array of pointers to rows in image data
	Data* dataBuffer = image->GetData();
	if (!buffer) {
		png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
		delete [] RowPointers;
		delete image;
		return 0;
	}
	Byte* data = dataBuffer->GetDataPtr();
	for (size_t i=0; i<Height; ++i)
	{
		RowPointers[i]=data;
		data += image->GetWidth()*pw;
	}

	// for proper error handling
	if (setjmp(png_jmpbuf(png_ptr)))
	{
		png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
		delete [] RowPointers;
		delete image;
		return 0;
	}

	// Read data using the library function that handles all transformations including interlacing
	png_read_image(png_ptr, RowPointers);

	png_read_end(png_ptr, NULL);
	delete [] RowPointers;
	png_destroy_read_struct(&png_ptr,&info_ptr, 0); // Clean up memory

	return image;
}
    
    static void write_png_func(png_structp p, png_bytep d, png_size_t s) {
        DataArrayImpl* res = reinterpret_cast<DataArrayImpl*>(png_get_io_ptr(p));
        res->append(d, UInt32(s));
    }
    static void flush_png_func (png_structp p) {
        
    }

	
    const Data* PngDecoder::Encode( const Image* image,Int32 settings) {
        int bit_depth = 0;
        int color_type = 0;
        int bpp = 0;
        if (image->GetFormat()==IMAGE_FORMAT_RGBA) {
            bit_depth = 8;
            color_type = PNG_COLOR_TYPE_RGB_ALPHA;
            bpp = 4;
        } else if (image->GetFormat() == IMAGE_FORMAT_RGB) {
            bit_depth = 8;
            color_type = PNG_COLOR_TYPE_RGB;
            bpp = 3;
        } else {
            return 0;
        }
        
        size_t line_bytes = image->GetWidth() * bpp;

        /* prepare the standard PNG structures */
        png_structp png_ptr = png_create_write_struct (png_get_libpng_ver(NULL), NULL, NULL,
                                           NULL);
        if (!png_ptr)
        {
            return 0;
        }
        png_infop info_ptr = png_create_info_struct (png_ptr);
        if (!info_ptr)
        {
            png_destroy_write_struct (&png_ptr, (png_infopp) NULL);
            return 0;
        }

        if (settings != 0) 
            png_set_compression_level(png_ptr, settings);
        
        DataArrayImpl* res = new DataArrayImpl();
        std::vector<const Byte*> row_ptrs;
        
        /* setjmp() must be called in every function that calls a PNG-reading libpng function */
        if (setjmp (png_jmpbuf(png_ptr)))
        {
            png_destroy_write_struct (&png_ptr, &info_ptr);
            res->Release();
            return 0;
        }
        
        png_set_write_fn(png_ptr, res, &write_png_func, &flush_png_func);
        
        png_set_IHDR (png_ptr, info_ptr, image->GetWidth(), image->GetHeight(), bit_depth, color_type,
                      PNG_INTERLACE_NONE,
                      PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
        
        /* write the file header information */
        png_write_info (png_ptr, info_ptr);
        row_ptrs.resize(image->GetHeight());
        
        /* set the individual row_pointers to point at the correct offsets */
        for (UInt32 i = 0; i < image->GetHeight(); i++)
            row_ptrs[i] = image->GetData()->GetData() + i * line_bytes;
        
        
        png_write_image (png_ptr, const_cast<png_bytepp>(&row_ptrs[0]));
        
        /* write the additional chunks to the PNG file (not really needed) */
        png_write_end (png_ptr, info_ptr);
        
        /* clean up after the write, and free any memory allocated */
        png_destroy_write_struct (&png_ptr, &info_ptr);
        return res;
	}

}/*namespace*/
