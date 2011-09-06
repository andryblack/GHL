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

#ifndef PNG_DECODER_H
#define PNG_DECODER_H

#include "image_file_decoder.h"

namespace GHL {

class PngDecoder : public ImageFileDecoder
{
	public:
		PngDecoder();
		~PngDecoder();
		Image* Decode(DataStream* ds);
		bool Encode( const Image* image, DataStream* ds);
};

}/*namespace*/

#endif /*PNG_DECODER_H*/