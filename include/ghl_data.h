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
		/// set data
		virtual void GHL_CALL	SetData( UInt32 offset, const Byte* data, UInt32 size ) = 0;
	};
	
} /*namespace*/

#endif /*GHL_DATA_H*/
