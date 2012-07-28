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

Image* PngDecoder::Decode(DataStream* file)
{
	if (!file)
		return 0;

	ImageImpl* image = 0;
	//Used to point to image rows
	Byte** RowPointers = 0;

	png_byte buffer[8];
	// Read the first few bytes of the PNG file
	if (file->Read(buffer, 8) != 8) {
		//log_error("png: error reading signature");
		return 0;
	}

	// Check if it really is a PNG file
	if ( png_sig_cmp(buffer, 0, 8)!=0 )
	{
		//log_error("png: is not a png file");
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
	DataImpl* dataBuffer = image->GetRawData();
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
	
    bool PngDecoder::Encode( const Image* /*image*/, DataStream* /*ds*/) {
		return false;
	}

}/*namespace*/
