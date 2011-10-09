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

#include "image_decoders.h"
#include "image_config.h"
#include "image_impl.h"

#ifdef USE_PNG_DECODER
#include "png_image_decoder.h"
#endif

#ifdef USE_JPEG_DECODER
#include "jpeg_decoder.h"
#endif

#ifdef USE_QT_IMAGE_DECODER
#include "qt/qt_image_decoder.h"
#endif

#ifdef USE_IPHONE_IMAGE_DECODER
#include "iphone/iphone_image_decoder.h"
#endif

#ifdef USE_TGA_IMAGE_DECODER
#include "tga_image_decoder.h"
#endif

#include <iostream>

namespace GHL {

ImageDecoderImpl::ImageDecoderImpl() {
#ifdef USE_PNG_DECODER
	m_decoders.push_back(new PngDecoder());
#endif
#ifdef USE_JPEG_DECODER
	m_decoders.push_back(new JpegDecoder());
#endif
#ifdef USE_QT_IMAGE_DECODER
        m_decoders.push_back(new QtImageFileDecoder());
#endif
#ifdef USE_IPHONE_IMAGE_DECODER
	m_decoders.push_back(new iPhoneImageDecoder());
#endif
#ifdef USE_TGA_IMAGE_DECODER
	m_decoders.push_back(new TGAImageDecoder());
#endif
}

ImageDecoderImpl::~ImageDecoderImpl()
{
	for (size_t i=0;i<m_decoders.size();i++)
		delete m_decoders[i];
}


Image* GHL_CALL ImageDecoderImpl::Decode(DataStream* ds) const
{
	Image* img = 0;
	for (size_t i=0;i<m_decoders.size();i++)
	{
		img = m_decoders[i]->Decode(ds);
		if (img) break;
	}
	if (!img) {
		if (true) {
			std::cout << "[IMAGE] error decoding"  << std::endl;
		}
	}
	return img;
}
	
	/// create image from data
	Image* GHL_CALL ImageDecoderImpl::CreateImage( UInt32 w, UInt32 h,ImageFormat fmt, const Byte* data ) const {
		ImageImpl* impl = new ImageImpl( w, h, fmt);
		if (data) {
			memcpy( impl->GetDataPtr(), data,w*h*impl->GetBpp() );
		}
		return impl;
	}
	
	ImageFileFormat GHL_CALL ImageDecoderImpl::GetFileFormat( DataStream* stream ) const {
		(void)stream;
		/// @todo
		return IMAGE_FILE_FORMAT_UNKNOWN;
	}
	
	bool GHL_CALL ImageDecoderImpl::Encode( const Image* image, DataStream* to, ImageFileFormat fmt) const {
		for (size_t i=0;i<m_decoders.size();i++)
		{
			if (m_decoders[i]->GetFileFormat()==fmt) {
				return m_decoders[i]->Encode(image,to);
			}
		}
		return false;
	}

}/*namespace*/

GHL_API GHL::ImageDecoder* GHL_CALL GHL_CreateImageDecoder() {
	return new GHL::ImageDecoderImpl();
}
GHL_API void GHL_CALL GHL_DestroyImageDecoder(GHL::ImageDecoder* decoder) {
	delete reinterpret_cast<GHL::ImageDecoderImpl*>(decoder);
}
