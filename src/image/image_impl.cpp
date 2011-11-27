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

#include "image_impl.h"

#include <algorithm>

namespace GHL
{

	ImageImpl::ImageImpl(UInt32 w,UInt32 h,ImageFormat fmt) : m_width(w),m_height(h),m_fmt(fmt),m_data(0) {
			if (fmt==IMAGE_FORMAT_RGB)
				m_data = new Byte [w*h*3];
			else if (fmt==IMAGE_FORMAT_RGBA)
				m_data = new Byte [w*h*4];
			else if (fmt==IMAGE_FORMAT_GRAY)
				m_data = new Byte [w*h];
	}

	ImageImpl::~ImageImpl() {
		delete [] m_data;
	}
	
	void GHL_CALL ImageImpl::Convert(ImageFormat fmt) {
		if (fmt==m_fmt) return;
		if (!m_data) return;
		if (fmt==IMAGE_FORMAT_RGB)
		{
			size_t len = m_width*m_height;
			Byte* data = new Byte [len*3];
			if (m_fmt==IMAGE_FORMAT_RGBA) {
				for (size_t i=0;i<len;i++) {
					data[i*3+0]=m_data[i*4+0];
					data[i*3+1]=m_data[i*4+1];
					data[i*3+2]=m_data[i*4+2];
				}
			} else if (m_fmt==IMAGE_FORMAT_GRAY)
			{
				for (size_t i=0;i<len;i++) {
					data[i*3+0]=m_data[i];
					data[i*3+1]=m_data[i];
					data[i*3+2]=m_data[i];
				}
			}
			delete [] m_data;
			m_data = data;
		}
		else if (fmt==IMAGE_FORMAT_RGBA)
		{
			size_t len = m_width*m_height;
			Byte* data = new Byte [len*4];
			if (m_fmt==IMAGE_FORMAT_RGB) {
				for (size_t i=0;i<len;i++) {
					data[i*4+0]=m_data[i*3+0];
					data[i*4+1]=m_data[i*3+1];
					data[i*4+2]=m_data[i*3+2];
					data[i*4+3]=0xff;
				}
			} else if (m_fmt==IMAGE_FORMAT_GRAY) {
				for (size_t i=0;i<len;i++) {
					data[i*4+0]=m_data[i];
					data[i*4+1]=m_data[i];
					data[i*4+2]=m_data[i];
					data[i*4+3]=0xff;
				}
			}
			delete [] m_data;
			m_data = data;
		}
        m_fmt = fmt;
	}
	
	void ImageImpl::SwapChannelsRB()
	{
		if (!m_data) return;
		if (m_fmt==IMAGE_FORMAT_RGB)
		{
			size_t len = m_width*m_height;
			for (size_t i=0;i<len;i++) {
				std::swap(m_data[i*3+0],m_data[i*3+2]);
			}
		}
		else if (m_fmt==IMAGE_FORMAT_RGBA)
		{
			size_t len = m_width*m_height;
			for (size_t i=0;i<len;i++) {
				std::swap(m_data[i*4+0],m_data[i*4+2]);
			}
		}
	}

	void GHL_CALL ImageImpl::SetAlpha(const Image* img) {
		if (!img) return;
		const Byte* data = img->GetData();
		if (GetWidth()!=img->GetWidth()) return;
		if (GetHeight()!=img->GetHeight()) return;
		if (!data) return;
		if (img->GetFormat()==IMAGE_FORMAT_GRAY)
		{
			Convert(IMAGE_FORMAT_RGBA);
			size_t len = m_width*m_height;
			for (size_t i=0;i<len;i++)
				m_data[i*4+3]=data[i];
		} else if (img->GetFormat()==IMAGE_FORMAT_RGBA)
		{
			Convert(IMAGE_FORMAT_RGBA);
			size_t len = m_width*m_height;
			for (size_t i=0;i<len;i++)
				m_data[i*4+3]=data[i*4+3];
		}

	}

	UInt32 ImageImpl::GetBpp() const {
		if (m_fmt==IMAGE_FORMAT_RGB) return 3;
		if (m_fmt==IMAGE_FORMAT_RGBA) return 4;
		if (m_fmt==IMAGE_FORMAT_GRAY) return 1;
		return 0;
	}
	
	void ImageImpl::FlipV() {
		const UInt32 line_size = GetBpp()*GetWidth();
		Byte* line = new Byte[line_size];
		UInt32 y1 = 0;
		UInt32 y2 = GetHeight()-1;
		while (y1<y2) {
			::memcpy(line,&m_data[y2*line_size],line_size);
			::memcpy(&m_data[y2*line_size],&m_data[y1*line_size],line_size);
			::memcpy(&m_data[y1*line_size],line,line_size);
			y1++;
			if (y2==0) break;
			y2--;
		}
		delete [] line;
	}
	
	Image* GHL_CALL ImageImpl::SubImage(UInt32 x,UInt32 y,UInt32 w,UInt32 h) const {
		if (x>m_width) return 0;
		if (y>m_height) return 0;
		if (w>m_width) return 0;
		if (h>m_height) return 0;
		if ((x+w)>m_width) return 0;
		if ((y+h)>m_height) return 0;
		ImageImpl* res = new ImageImpl(w,h,m_fmt);
		for (UInt32 _y = 0; _y<h;_y++) {
			const Byte* src = m_data + (_y+y)*m_width*GetBpp();
			src+=x*GetBpp();
			Byte* dst = res->GetDataPtr()+_y*w*GetBpp();
			::memcpy(dst,src,w*GetBpp());
		}
		return res;
	}

}
GHL_API GHL::Image* GHL_CALL GHL_CreateImage( GHL::UInt32 w, GHL::UInt32 h,GHL::ImageFormat fmt) {
	return new GHL::ImageImpl( w,h,fmt);
}