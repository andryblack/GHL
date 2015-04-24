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
#include "../ghl_data_impl.h"

namespace GHL
{
    static inline UInt32 u_min( UInt32 a, UInt32 b) {
        return a < b ? a : b;
    }
    class MemoryDataStream : public RefCounterImpl<GHL::DataStream> {
    private:
        const GHL::Data*  m_data;
        GHL::UInt32 m_pointer;
    public:
        explicit MemoryDataStream(const GHL::Data* data) : m_data(data),m_pointer(0) {}
        
        /// read data
		virtual GHL::UInt32 GHL_CALL Read(GHL::Byte* dest,GHL::UInt32 bytes) {
            GHL::UInt32 size = u_min(bytes,m_data->GetSize() - m_pointer);
            ::memcpy(dest, m_data->GetData()+m_pointer, size);
            return size;
        }
		/// tell
		virtual GHL::UInt32 GHL_CALL Tell() const { return m_pointer; }
		/// seek
		virtual	bool GHL_CALL Seek(GHL::Int32 offset,GHL::FileSeekType st) {
            if (st == F_SEEK_BEGIN) {
                m_pointer = u_min(UInt32(offset > 0 ? offset : 0) , m_data->GetSize());
            } else if (st == F_SEEK_CURRENT) {
                if (offset > 0) {
                    m_pointer = u_min(UInt32(m_pointer+offset) , m_data->GetSize());
                } else {
                    if (GHL::Int32(m_pointer) < (-offset)) {
                        m_pointer = 0;
                    } else {
                        m_pointer = m_pointer + offset;
                    }
                }
            } else if (st == F_SEEK_END) {
                if (offset < 0) m_pointer = m_data->GetSize();
                else {
					if (m_data->GetSize() < GHL::UInt32(offset)) {
                        m_pointer = 0;
                    } else {
                        m_pointer = m_data->GetSize() - offset;
                    }
                }
            }
            return true;
        }
		/// End of file
		virtual bool GHL_CALL Eof() const {
            return m_pointer >= m_data->GetSize();
        }
    };
	
}

GHL_API GHL::DataStream* GHL_CALL GHL_CreateMemoryStream( const GHL::Data* ds ) {
    return new GHL::MemoryDataStream(ds);
}
