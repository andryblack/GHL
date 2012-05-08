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

#ifndef IMAGE_IMPL_H
#define IMAGE_IMPL_H

#include "ghl_image.h"
#include "../ghl_ref_counter_impl.h"
#include "../ghl_data_impl.h"

#include <cstring>


namespace GHL {

    class ImageImpl : public RefCounterImpl<Image>
    {
	private:
		UInt32 m_width;
		UInt32 m_height;
		ImageFormat m_fmt;
		DataImpl*  m_data;
		ImageImpl(const ImageImpl&);
		ImageImpl& operator = (const ImageImpl&);
	public:
		ImageImpl(UInt32 w,UInt32 h,ImageFormat fmt);
		ImageImpl(UInt32 w,UInt32 h,ImageFormat fmt,DataImpl* data);
		virtual ~ImageImpl();
		virtual UInt32 GHL_CALL GetWidth() const { return m_width;}
		virtual UInt32 GHL_CALL GetHeight() const { return m_height;}
		virtual const Data* GHL_CALL GetData() const { return m_data;}
		virtual ImageFormat GHL_CALL GetFormat() const { return m_fmt;}
		virtual bool GHL_CALL Convert(ImageFormat fmt);
		virtual bool GHL_CALL SetAlpha(const Image* img);
		virtual Image* GHL_CALL SubImage(UInt32 x,UInt32 y,UInt32 w,UInt32 h) const;
		bool SwapChannelsRB();
		/// swap RB channels
		virtual bool GHL_CALL SwapRB() { return SwapChannelsRB() ; }
		UInt32 GetBpp() const;
		void FlipV();
		DataImpl*	GetRawData() { return m_data; }
    };

}/*namespace*/

#endif /*IMAGE_IMPL_H*/
