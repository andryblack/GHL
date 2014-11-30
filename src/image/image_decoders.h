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

#ifndef DECODERS_H
#define DECODERS_H

#include "ghl_image_decoder.h"
#include "image_file_decoder.h"

#include <vector>

namespace GHL {

	class ImageDecoderImpl : public ImageDecoder
	{
		private:
			std::vector<ImageFileDecoder*> m_decoders;
		public:
			ImageDecoderImpl();
			virtual ~ImageDecoderImpl();
			/// get image file format
			virtual bool GHL_CALL GetFileInfo( DataStream* stream, ImageInfo* info ) const;
			virtual Image* GHL_CALL Decode(DataStream* ds) const;
			virtual const Data* GHL_CALL Encode( const Image* image, ImageFileFormat fmt) const;
	};

}/*namespace*/
#endif /*DECODERS_H*/
