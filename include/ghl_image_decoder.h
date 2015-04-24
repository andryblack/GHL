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
	
	/// Image file format
	enum ImageFileFormat {
		IMAGE_FILE_FORMAT_UNKNOWN,
		IMAGE_FILE_FORMAT_PNG,		///< png
		IMAGE_FILE_FORMAT_JPEG,		///< jpeg
		IMAGE_FILE_FORMAT_TGA,		///< targa
		IMAGE_FILE_FORMAT_PVRTC,	///< pvrtc
	};
    
    /// Image information
    struct ImageInfo {
        ImageFileFormat file_format;	///< file format
        ImageFormat     image_format;	///< image data format
        GHL::UInt32     width;			///< image width
        GHL::UInt32     height;			///< image height
    };
	
	/// Image file decoder
	struct ImageDecoder 
	{
		/// get image file info
		virtual bool GHL_CALL GetFileInfo( DataStream* stream , ImageInfo* info ) const = 0;
		/// decode
		virtual Image* GHL_CALL Decode( DataStream* stream ) const = 0;
		/// encode
		virtual const Data* GHL_CALL Encode( const Image* image, ImageFileFormat fmt) const = 0;
	};
    
    
	
} /*namespace*/

/// Create image decoder
GHL_API GHL::ImageDecoder* GHL_CALL GHL_CreateImageDecoder();
/// Destroy image decoder
GHL_API void GHL_CALL GHL_DestroyImageDecoder(GHL::ImageDecoder* decoder);

#endif /*GHL_IMAGE_DECODER_H*/
