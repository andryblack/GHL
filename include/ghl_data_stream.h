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

#ifndef GHL_DATA_STREAM_H
#define GHL_DATA_STREAM_H

#include "ghl_types.h"
#include "ghl_api.h"
#include "ghl_ref_counter.h"

namespace GHL
{
    
    struct Data;

	/// file seek type
	enum FileSeekType
	{
		F_SEEK_BEGIN,	///< seek from begin of stream
		F_SEEK_CURRENT,	///< seek from current position
        F_SEEK_END		///< seek from end of stream
	};

	/// data stream interface
    struct DataStream : RefCounter
	{
		/// read data
		virtual UInt32 GHL_CALL Read(Byte* dest,UInt32 bytes) = 0;
		/// tell
		virtual UInt32 GHL_CALL Tell() const = 0;
		/// seek
		virtual	bool GHL_CALL Seek(Int32 offset,FileSeekType st) = 0;
		/// End of file
		virtual bool GHL_CALL Eof() const = 0;
	};
    
} /* namespace */

GHL_API GHL::Data* GHL_CALL GHL_ReadAllData( GHL::DataStream* ds );
GHL_API GHL::DataStream* GHL_CALL GHL_CreateMemoryStream( const GHL::Data* ds );


#endif /*GHL_DATA_STREAM_H*/
