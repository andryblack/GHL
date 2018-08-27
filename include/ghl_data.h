/*
 GHL - Game Helpers Library
 Copyright (C)  Andrey Kunitsyn 20011
 
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

#ifndef GHL_DATA_H
#define GHL_DATA_H

#include "ghl_types.h"
#include "ghl_api.h"
#include "ghl_ref_counter.h"

namespace GHL {
	
	/// Data buffer holder
	struct Data : RefCounter 
	{
		/// Data size
		virtual UInt32 GHL_CALL	GetSize() const = 0;	
		/// Const data ptr
		virtual const Byte* GHL_CALL	GetData() const = 0;
		/// Write data ptr
		virtual Byte* GHL_CALL	GetDataPtr() = 0;
        /// clone data
        virtual Data* GHL_CALL  Clone() const = 0;
	};

    
} /*namespace*/

GHL_API GHL::Data* GHL_CALL GHL_CreateData( GHL::UInt32 size , 
                                           bool fill = false , 
                                           GHL::Byte filler = 0 );
GHL_API GHL::Data* GHL_CALL GHL_HoldData( const GHL::Byte* data, GHL::UInt32 size  );

GHL_API bool GHL_CALL GHL_UnpackZlib(const GHL::Data* src, GHL::Byte* dst, GHL::UInt32* dst_size);
GHL_API GHL::Data* GHL_CALL GHL_UnpackZlibData(const GHL::Data* src);
GHL_API GHL::Data* GHL_CALL GHL_PackZlib(const GHL::Data* src);
GHL_API GHL::UInt32 GHL_CALL GHL_DataCRC32(const GHL::Data* data );
GHL_API GHL::UInt32 GHL_CALL GHL_CRC32(const GHL::Byte* data , GHL::UInt32 data_size);

#endif /*GHL_DATA_H*/
