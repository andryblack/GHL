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

#include "memory_stream.h"
#include <cstring>

namespace GHL
{

	MemoryStream::MemoryStream(Byte* data,UInt32 size) : m_data(data),m_size(size),m_pos(0)
	{
	}
	
	MemoryStream::~MemoryStream()
	{
	}

	static inline UInt32 m_min(UInt32 x,UInt32 y) {
		return x<y ? x : y;
	}
	
	UInt32 GHL_CALL MemoryStream::Read(Byte* dest,UInt32 bytes) 
	{
		UInt32 res = m_min(bytes,m_size-m_pos);
		if (!res) return 0;
		::memcpy(dest,&m_data[m_pos],res);
		m_pos+=res;
		return res;
	}
	UInt32 GHL_CALL MemoryStream::Write(const Byte* src,UInt32 bytes) 
	{
		UInt32 res = m_min(bytes,m_size-m_pos);
		if (!res) return 0;
		::memcpy(&m_data[m_pos],src,res);
		m_pos+=res;
		return res;
	}
	UInt32 GHL_CALL MemoryStream::Tell() const
	{
		return m_pos;
	}
	bool GHL_CALL MemoryStream::Eof() const
	{
		return m_pos==m_size;
	}
	
	bool GHL_CALL MemoryStream::Seek(Int32 offset,FileSeekType st) 
	{
		if (st==F_SEEK_BEGIN) {
			if (offset<0) return false;
			if (offset>static_cast<Int32>(m_size)) return false;
			m_pos = offset;
			return true;
		} else
		if (st==F_SEEK_CURRENT) {
			if ((m_pos+offset)>m_size) return false;
			m_pos = m_pos+offset;
			return true;
		} else
		if (st==F_SEEK_END) {
			if (offset<0) return false;
			if (offset>static_cast<Int32>(m_size)) return false;
			m_pos = m_size-offset;
			return true;
		} 
		return false;
	}
	


	
}
