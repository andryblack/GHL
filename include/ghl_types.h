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

#ifndef GHL_TYPES_H
#define GHL_TYPES_H

/// GHL namespace
namespace GHL
{

	/// byte
	typedef unsigned char Byte;
	/// unsigned 32
	typedef unsigned int UInt32;
	/// int 32
	typedef int Int32;
	/// unsigned 16
	typedef unsigned short UInt16;
	/// int 16
	typedef short Int16;
    
#define GHL_CONCAT(x, y) GHL_CONCAT1 (x, y)
#define GHL_CONCAT1(x, y) x##y
#define GHL_STATIC_ASSERT(expr) typedef char GHL_CONCAT(ghl_static_assert_failed_at_line_, __LINE__) [(expr) ? 1 : -1]
    
    GHL_STATIC_ASSERT(sizeof(Byte) == 1);
    GHL_STATIC_ASSERT(sizeof(UInt32) == 4);
    GHL_STATIC_ASSERT(sizeof(Int32) == 4);
    GHL_STATIC_ASSERT(sizeof(UInt16) == 2);
    GHL_STATIC_ASSERT(sizeof(Int16) == 2);
    
}

#endif /*GHL_TYPES_H*/
