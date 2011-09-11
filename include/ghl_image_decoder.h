/*
 GHL - Game Helpers Library
 Copyright (C)  Andrey Kunitsyn 2010
 
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
 mailto:support.andryblack@gmail.com
 */

#ifndef GHL_IMAGE_DECODER_H
#define GHL_IMAGE_DECODER_H

#include "ghl_api.h"
#include "ghl_image.h"

namespace GHL 
{
	
	struct DataStream;
	
	enum ImageFileFormat {
		IMAGE_FILE_FORMAT_UNKNOWN,
		IMAGE_FILE_FORMAT_PNG,
		IMAGE_FILE_FORMAT_JPEG,
		IMAGE_FILE_FORMAT_TGA,
	};
	
	
	struct ImageDecoder 
	{
		/// create image from data
		virtual Image* GHL_CALL CreateImage( UInt32 w, UInt32 h,ImageFormat fmt, const Byte* data ) const = 0;
		/// get image file format
		virtual ImageFileFormat GHL_CALL GetFileFormat( DataStream* stream ) const = 0;
		/// decode
		virtual Image* GHL_CALL Decode( DataStream* stream ) const = 0;
		/// encode
		virtual bool GHL_CALL Encode( const Image* image, DataStream* to, ImageFileFormat fmt) const = 0;
	};
	
} /*namespace*/

#endif /*GHL_IMAGE_DECODER_H*/
