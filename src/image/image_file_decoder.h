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

#ifndef IMAGE_DECODER_H
#define IMAGE_DECODER_H

#include "ghl_data_stream.h"
#include "ghl_image_decoder.h"
#include "ghl_image.h"

namespace GHL {

	class ImageFileDecoder
	{
	private:
		ImageFileFormat	m_file_format;
	public:
		explicit ImageFileDecoder(ImageFileFormat fmt) : m_file_format(fmt)  {}
		ImageFileFormat GetFileFormat() const { return m_file_format;}
		virtual ~ImageFileDecoder() {}
		virtual Image* Decode(DataStream* ds) = 0;
		virtual bool Encode( const Image* /*image*/, DataStream* /*ds*/) {
			return false;
		}
	};

}/*namespace*/

#endif /*IMAGE_DECODER_H*/