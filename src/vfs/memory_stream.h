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

#ifndef MEMORY_STREAM_H
#define MEMORY_STREAM_H

#include "ghl_data_stream.h"

namespace GHL
{

    class MemoryStream : public DataStream
    {
        protected:
            Byte*	m_data;
            UInt32	m_size;
            UInt32	m_pos;
        public:
            MemoryStream(Byte* data,UInt32 size);
            virtual ~MemoryStream();

            Byte* GetData() { return m_data;}

            virtual UInt32 GHL_CALL Read(Byte* dest,UInt32 bytes) ;
            virtual UInt32 GHL_CALL Write(const Byte* src,UInt32 bytes) ;
            virtual UInt32 GHL_CALL Tell() const;
            virtual	bool GHL_CALL Seek(Int32 offset,FileSeekType st) ;
            virtual bool GHL_CALL Eof() const;
            virtual void GHL_CALL Release() ;

    };


}

#endif /*MEMORY_STREAM_H*/
