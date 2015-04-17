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
#include "zlib/zlib.h"
#undef Byte

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

GHL_API GHL::Data* GHL_CALL GHL_HoldData( const GHL::Byte* data_ptr, GHL::UInt32 size  ) {
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

GHL_API bool GHL_CALL GHL_UnpackZlib(const GHL::Data* src, GHL::Byte* dst,GHL::UInt32* dst_size) {
    if (!src || !dst || !dst_size)
        return false;
    
    z_stream stream;
    int err;
    
    stream.next_in = (Bytef*)src->GetData();
    stream.avail_in = src->GetSize();
    
    stream.next_out = dst;
    stream.avail_out = (uInt)*dst_size;
    
    stream.zalloc = (alloc_func)0;
    stream.zfree = (free_func)0;
    
    err = inflateInit(&stream);
    if (err != Z_OK) return false;
    
    err = inflate(&stream, Z_FINISH);
    if (err != Z_STREAM_END) {
        inflateEnd(&stream);
        return false;
    }
    *dst_size = stream.total_out;
    
    err = inflateEnd(&stream);
    
    return true;
}

GHL_API GHL::Data* GHL_CALL GHL_PackZlib(const GHL::Data* src) {
    if (!src) {
        return 0;
    }
    int level = Z_DEFAULT_COMPRESSION;
    GHL::DataArrayImpl* data = new GHL::DataArrayImpl();
    z_stream stream;
    int err;
    
    stream.next_in = (z_const Bytef *)src->GetData();
    stream.avail_in = (uInt)src->GetSize();

    GHL::Byte buf[1024*8];
    
    stream.next_out = buf;
    stream.avail_out = sizeof(buf);
    
    stream.zalloc = (alloc_func)0;
    stream.zfree = (free_func)0;
    stream.opaque = (voidpf)0;
    
    err = deflateInit(&stream, level);
    if (err != Z_OK)
    {
        delete data;
        return 0;
    }
    while (true) {
        err = deflate(&stream, Z_FINISH);
        data->append(buf, sizeof(buf)-stream.avail_out);
        if (err == Z_OK) {
            if (stream.avail_out==0) {
                stream.next_out = buf;
                stream.avail_out = sizeof(buf);
                continue;
            }
        }
        if (err == Z_STREAM_END) {
            break;
        }
        delete data;
        deflateEnd(&stream);
        return 0;
    }
    err = deflateEnd(&stream);
    return data;
}

GHL_API GHL::UInt32 GHL_CALL GHL_DataCRC32(const GHL::Data* data ) {
    return crc32(0,data->GetData(),data->GetSize());
}