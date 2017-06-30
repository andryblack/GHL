/*
 GHL - Game Helpers Library
 Copyright (C)  Andrey Kunitsyn 2016
 
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

#include "../ghl_data_impl.h"
#include <ghl_data_stream.h>
#include "../zlib/zlib.h"
#include <cstdlib>
#undef Byte

//static const char* MODULE = "VFS";

namespace GHL {
    static voidpf z__alloc_func (voidpf opaque, uInt items, uInt size) {
        (void)opaque;
        return ::calloc(items, size);
    }
    static void   z__free_func  (voidpf opaque, voidpf address) {
        ::free(address);
        (void)opaque;
    }
    
    class UnpackZlibStream : public RefCounterImpl<GHL::DataStream> {
    private:
        GHL::DataStream*  m_ds;
        z_stream m_z;
        static const size_t BUFFER_SIZE = 1024 * 4;
        Byte m_buffer[BUFFER_SIZE];
        void FillBuffer() {
            UInt32 size = m_ds->Read(m_buffer,BUFFER_SIZE);
            m_z.next_in = m_buffer;
            m_z.avail_in = size;
        }
        int m_error;
        UInt32 m_pos;
    public:
        explicit UnpackZlibStream( GHL::DataStream* data) : m_ds(data) {
            m_ds->AddRef();
            m_pos = 0;
            ::memset(&m_z,0,sizeof(m_z));
            m_error = Z_OK;
            m_z.zalloc = &z__alloc_func;
            m_z.zfree = &z__free_func;
            FillBuffer();
            m_error = inflateInit2(&m_z,32+15);
        }
        ~UnpackZlibStream() {
            m_error = inflateEnd(&m_z);
            m_ds->Release();
        }
        
        /// read data
        virtual GHL::UInt32 GHL_CALL Read(GHL::Byte* dest,GHL::UInt32 bytes) {
            UInt32 readed = 0;
           
            while (m_error == Z_OK) {
               
                if (m_z.avail_in==0) {
                    FillBuffer();
                }
                bool all_data_complete = (m_z.avail_in == 0) && m_ds->Eof();
                
                m_z.next_out = dest;
                m_z.avail_out = bytes;
                m_error = inflate(&m_z,all_data_complete ? Z_FINISH : 0);
                
                UInt32 decompressed = bytes - m_z.avail_out;
                dest += decompressed;
                bytes -= decompressed;
                readed += decompressed;
                m_pos += decompressed;
                if (bytes == 0)
                    break;
                if ((m_error == Z_OK || m_error == Z_BUF_ERROR) && all_data_complete && m_z.avail_out) {
                    m_error = Z_STREAM_END;
                }
            }
            if (m_error == Z_BUF_ERROR) {
                m_error = Z_OK;
            }
            return readed;
        }
        /// tell
        virtual GHL::UInt32 GHL_CALL Tell() const {
            return m_pos;
        }
        /// seek
        virtual	bool GHL_CALL Seek(GHL::Int32 offset,GHL::FileSeekType st) {
            return false;
        }
        /// End of file
        virtual bool GHL_CALL Eof() const {
            return m_error != Z_OK;
        }
    };
}

GHL_API GHL::DataStream* GHL_CALL GHL_CreateUnpackZlibStream( GHL::DataStream* ds ) {
    if (!ds)  return 0;
    return new GHL::UnpackZlibStream(ds);
}

GHL_API GHL::Data* GHL_CALL GHL_ReadAllData( GHL::DataStream* ds ) {
    if (!ds) return 0;
    GHL::DataArrayImpl* data = new GHL::DataArrayImpl();
    static const GHL::UInt32 buffer_size = 1024 * 8;
    ds->Seek(0, GHL::F_SEEK_END);
    GHL::UInt32 size = ds->Tell();
    ds->Seek(0, GHL::F_SEEK_BEGIN);
    data->reserve(size + buffer_size);
    while (!ds->Eof()) {
        GHL::UInt32 pos = data->GetSize();
        data->resize(pos + buffer_size);
        GHL::UInt32 readed = ds->Read(data->GetDataPtr() + pos,buffer_size);
        data->resize(pos+readed);
        if( readed == 0 ) break;
    }
    return data;
}
