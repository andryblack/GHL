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
#include "../ghl_log_impl.h"

#include <algorithm>

namespace GHL
{
    static const char* MODULE = "Image";

	ImageImpl::ImageImpl(UInt32 w,UInt32 h,ImageFormat fmt) : m_width(w),m_height(h),m_fmt(fmt),m_data(0) {
		UInt32 size = 0;	
		if (fmt==IMAGE_FORMAT_RGB)
			size = w * h * 3;
		else if (fmt==IMAGE_FORMAT_RGBA)
			size = w * h * 4;
		else if (fmt==IMAGE_FORMAT_GRAY)
			size = w * h;
        else if (fmt==IMAGE_FORMAT_565 || fmt==IMAGE_FORMAT_4444)
			size = w * h * 2;
		if ( size ) {
			m_data = new DataImpl( size );
		}
	}
	
	ImageImpl::ImageImpl(UInt32 w,UInt32 h,ImageFormat fmt,DataImpl* data) : m_width(w),m_height(h),m_fmt(fmt),m_data(data) {
		
	}

	ImageImpl::~ImageImpl() {
		if (m_data) m_data->Release();
	}
    
    void GHL_CALL ImageImpl::Fill(UInt32 clr) {
        Byte* data = m_data->GetDataPtr();
        const size_t len = m_width*m_height;
        
        if (m_fmt==IMAGE_FORMAT_RGB)
		{
			size_t len = m_width*m_height;
            const Byte b1 = clr & 0xFF;
            const Byte b2 = (clr>>8) & 0xFF;
            const Byte b3 = (clr>>16) & 0xFF;
            for (size_t i =0;i<len;++i) {
                *data = b1; ++data;
                *data = b2; ++data;
                *data = b3; ++data;
            }
		} else if (m_fmt==IMAGE_FORMAT_RGBA) {
            UInt32* ddata = reinterpret_cast<UInt32*>(data);
            std::fill(ddata, ddata+len, clr);
        } else if (m_fmt==IMAGE_FORMAT_GRAY)
        {
            std::fill(data, data+len, clr&0xFF);
        }
    }
	
	bool GHL_CALL ImageImpl::Convert(ImageFormat fmt) {
		if (fmt==m_fmt) return true;
		if (!m_data) return false;
		const Byte* original = m_data->GetData();
		if (fmt==IMAGE_FORMAT_RGB)
		{
			size_t len = m_width*m_height;
			DataImpl* buffer = new DataImpl( UInt32(len * 3) );
			Byte* data = buffer->GetDataPtr();
			if (m_fmt==IMAGE_FORMAT_RGBA) {
				for (size_t i=0;i<len;i++) {
					data[i*3+0]=original[i*4+0];
					data[i*3+1]=original[i*4+1];
					data[i*3+2]=original[i*4+2];
				}
			} else if (m_fmt==IMAGE_FORMAT_GRAY)
			{
				for (size_t i=0;i<len;i++) {
					data[i*3+0]=original[i];
					data[i*3+1]=original[i];
					data[i*3+2]=original[i];
				}
            } else {
                LOG_ERROR("not implemented conversion");
            }
			m_data->Release();
			m_data = buffer;
		}
		else if (fmt==IMAGE_FORMAT_RGBA)
		{
			size_t len = m_width*m_height;
			DataImpl* buffer = new DataImpl( UInt32(len * 4) );
			Byte* data = buffer->GetDataPtr();
			if (m_fmt==IMAGE_FORMAT_RGB) {
				for (size_t i=0;i<len;i++) {
					data[i*4+0]=original[i*3+0];
					data[i*4+1]=original[i*3+1];
					data[i*4+2]=original[i*3+2];
					data[i*4+3]=0xff;
				}
			} else if (m_fmt==IMAGE_FORMAT_GRAY) {
				for (size_t i=0;i<len;i++) {
					data[i*4+0]=original[i];
					data[i*4+1]=original[i];
					data[i*4+2]=original[i];
					data[i*4+3]=0xff;
				}
            } else if (m_fmt==IMAGE_FORMAT_4444) {
                for (size_t i=0;i<len;i++) {
                    data[i*4+0]=(original[i*2]&0x0F)<<4;
                    data[i*4+1]=(original[i*2]&0xF0);
                    data[i*4+2]=(original[i*2+1]&0x0F)<<4;
                    data[i*4+3]=(original[i*2+1]&0xF0);
                }
            } else {
                LOG_ERROR("not implemented conversion");
            }
			m_data->Release();
			m_data = buffer;
		} else {
			return false;
		}
        m_fmt = fmt;
		return true;
	}
	
	bool ImageImpl::SwapChannelsRB()
	{
		if (!m_data) return false;
		Byte* data = m_data->GetDataPtr();
		if (m_fmt==IMAGE_FORMAT_RGB)
		{
			const size_t len = m_width*m_height;
			for (size_t i=0;i<len;i++) {
				std::swap(data[i*3+0],data[i*3+2]);
			}
		}
		else if (m_fmt==IMAGE_FORMAT_RGBA)
		{
			const size_t len = m_width*m_height;
			for (size_t i=0;i<len;i++) {
				std::swap(data[i*4+0],data[i*4+2]);
			}
		} else {
			return false;
		}
		return true;
	}

	bool GHL_CALL ImageImpl::SetAlpha(const Image* img) {
		if (!img) return false;
		if (!m_data) return false;
		if (GetWidth()!=img->GetWidth()) return false;
		if (GetHeight()!=img->GetHeight()) return false;
		const Data* data = img->GetData();
		if (!data) return false;
		const Byte* source = data->GetData();
		if (img->GetFormat()==IMAGE_FORMAT_GRAY)
		{
			if (!Convert(IMAGE_FORMAT_RGBA))
                return false;
            Byte* dst = m_data->GetDataPtr();
            size_t len = m_width*m_height;
			for (size_t i=0;i<len;i++)
				dst[i*4+3]=source[i];
		} else if (img->GetFormat()==IMAGE_FORMAT_RGBA)
		{
            if (!Convert(IMAGE_FORMAT_RGBA))
                return false;
            Byte* dst = m_data->GetDataPtr();
			size_t len = m_width*m_height;
			for (size_t i=0;i<len;i++)
				dst[i*4+3]=source[i*4+3];
		} else {
			return false;
		}
		return true;
	}

	UInt32 ImageImpl::GetBpp() const {
		if (m_fmt==IMAGE_FORMAT_RGB) return 3;
		if (m_fmt==IMAGE_FORMAT_RGBA) return 4;
		if (m_fmt==IMAGE_FORMAT_GRAY) return 1;
        if (m_fmt==IMAGE_FORMAT_565) return 2;
        if (m_fmt==IMAGE_FORMAT_4444) return 2;
		return 0;
	}
	
	void ImageImpl::FlipV() {
		if (!m_data) return;
		if (!GetBpp()) return;
		Byte* data = m_data->GetDataPtr();
		const UInt32 line_size = GetBpp()*GetWidth();
		Byte* line = new Byte[line_size];
		UInt32 y1 = 0;
		UInt32 y2 = GetHeight()-1;
		while (y1<y2) {
			::memcpy(line,&data[y2*line_size],line_size);
			::memcpy(&data[y2*line_size],&data[y1*line_size],line_size);
			::memcpy(&data[y1*line_size],line,line_size);
			y1++;
			if (y2==0) break;
			y2--;
		}
		delete [] line;
	}
	
	Image* GHL_CALL ImageImpl::SubImage(UInt32 x,UInt32 y,UInt32 w,UInt32 h) const {
		if (!m_data) return 0;
		if (x>m_width) return 0;
		if (y>m_height) return 0;
		if (w>m_width) return 0;
		if (h>m_height) return 0;
		if ((x+w)>m_width) return 0;
		if ((y+h)>m_height) return 0;
		DataImpl* res = new DataImpl( w * h * GetBpp() );
		Byte* data = m_data->GetDataPtr();
		for (UInt32 _y = 0; _y<h;_y++) {
			const Byte* src = data + (_y+y)*m_width*GetBpp();
			src+=x*GetBpp();
			Byte* dst = res->GetDataPtr()+_y*w*GetBpp();
			::memcpy(dst,src,w*GetBpp());
		}
		return new ImageImpl( w, h, GetFormat(), res );
	}
    void GHL_CALL ImageImpl::Draw(UInt32 x,UInt32 y,const Image* src) {
        Image* simg = 0;
        const UInt32 bpp = GetBpp();
        if (!bpp) {
            LOG_ERROR("Unsupported format for Draw");
            return;
        }
        if ((x+src->GetWidth())>GetWidth()) {
            LOG_ERROR("invalid argument for Draw x");
            return;
        }
        if ((y+src->GetHeight())>GetHeight()) {
            LOG_ERROR("invalid argument for Draw y");
            return;
        }
        if (src->GetFormat()!=GetFormat()) {
            simg = src->Clone();
            simg->Convert(GetFormat());
            src = simg;
        }
        const Byte* srcPtr = src->GetData()->GetData();
        Byte* dstPtr = m_data->GetDataPtr();
        dstPtr+=x*bpp;
        dstPtr+=y*(bpp*GetWidth());
        const UInt32 line = bpp * src->GetWidth();
        const UInt32 destLine = bpp * GetWidth();
        for (UInt32 y=0;y<src->GetHeight();++y) {
            ::memcpy(dstPtr, srcPtr, line);
            dstPtr += destLine;
            srcPtr += line;
        }
        if (simg) {
            simg->Release();
        }
    }
    
    /// Premultiply alpha
    void GHL_CALL ImageImpl::PremultiplyAlpha() {
        if (!m_data) return;
        Byte* data = m_data->GetDataPtr();
        if (GetFormat()==IMAGE_FORMAT_RGBA) {
            const size_t len = m_width*m_height;
			for (size_t i=0;i<len;i++) {
				UInt16 a = data[3];
                data[0] = UInt16(data[0]) * a / 255;
                data[1] = UInt16(data[1]) * a / 255;
                data[2] = UInt16(data[2]) * a / 255;
                data+=4;
			}
        } else if (GetFormat()==IMAGE_FORMAT_4444) {
            LOG_ERROR("PremultiplyAlpha for IMAGE_FORMAT_4444 not implemented");
        }
    }

    /// clone image
    Image* GHL_CALL ImageImpl::Clone() const {
        ImageImpl* res = new ImageImpl(GetWidth(),GetHeight(),GetFormat(),
                                       new DataImpl(m_data->GetSize(),m_data->GetData()));
        return res;
    }
}
GHL_API GHL::Image* GHL_CALL GHL_CreateImage( GHL::UInt32 w, GHL::UInt32 h,GHL::ImageFormat fmt) {
	return new GHL::ImageImpl( w,h,fmt);
}
GHL_API GHL::Image* GHL_CALL GHL_CreateImageWithData( GHL::UInt32 w, GHL::UInt32 h,GHL::ImageFormat fmt,const GHL::Byte* data) {
	GHL::ImageImpl* res = new GHL::ImageImpl( w,h,fmt);
    ::memcpy(res->GetRawData()->GetDataPtr(), data, w*h*res->GetBpp());
    return res;
}
