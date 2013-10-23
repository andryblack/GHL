/*
 GHL - Game Helpers Library
 Copyright (C)  Andrey Kunitsyn 2011
 
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


#include "ghl_data_impl.h"
#include <ghl_data_stream.h>

namespace GHL {
 
	void GHL_CALL	InlinedData::SetData( UInt32 offset, const Byte* data, UInt32 size ) {
		if (offset>=m_size) return;
		Byte* begin = m_buffer + offset;
		Byte* end = m_buffer + offset + size;
		if ( end > ( m_buffer + m_size ) ) {
			end = m_buffer + m_size;
		}
		size = UInt32(end - begin);
		::memcpy(m_buffer, data, size);
	}
	
}

GHL_API GHL::Data* GHL_CALL GHL_CreateData( GHL::UInt32 size , 
                                           bool fill  , 
                                           GHL::Byte filler ) {
    GHL::DataImpl* data = new GHL::DataImpl( size );
    if ( fill ) {
        ::memset(data->GetDataPtr(), filler, size );
    }
    return data;
}

GHL_API GHL::Data* GHL_CALL GHL_HoldData( GHL::Byte* data_ptr, GHL::UInt32 size  ) {
    GHL::DataImpl* data = new GHL::DataImpl( size );
    ::memcpy(data->GetDataPtr(),data_ptr,size);
    return data;
}

GHL_API GHL::Data* GHL_CALL GHL_ReadAllData( GHL::DataStream* ds ) {
    if (!ds) return 0;
    GHL::DataArrayImpl* data = new GHL::DataArrayImpl();
    GHL::Byte buf[1024*8];
    ds->Seek(0, GHL::F_SEEK_END);
    GHL::UInt32 size = ds->Tell();
    ds->Seek(0, GHL::F_SEEK_BEGIN);
    data->reserve(size);
    while (!ds->Eof()) {
        GHL::UInt32 readed = ds->Read(buf,sizeof(buf));
        if( readed == 0 ) break;
        data->append(buf,readed);
    }
    return data;
}