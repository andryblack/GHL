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
    /// int 8
    typedef signed char Int8;
	/// unsigned 32
	typedef unsigned int UInt32;
	/// int 32
	typedef int Int32;
	/// unsigned 16
	typedef unsigned short UInt16;
	/// int 16
	typedef short Int16;
    
    /// concat 2 names
#define GHL_CONCAT(x, y) GHL_CONCAT1 (x, y)
    /// @internal
#define GHL_CONCAT1(x, y) x##y
    /// compile time checks
#define GHL_STATIC_ASSERT(expr) typedef char GHL_CONCAT(ghl_static_assert_failed_at_line_, __LINE__) [(expr) ? 1 : -1]
    
    /// ensure Byte is 1 byte size
    GHL_STATIC_ASSERT(sizeof(Byte) == 1);
    /// ensure Int8 is 1 byte size
    GHL_STATIC_ASSERT(sizeof(Int8) == 1);
    /// ensure UInt32 is 4 bytes size
    GHL_STATIC_ASSERT(sizeof(UInt32) == 4);
    /// ensure Int32 is 4 bytes size
    GHL_STATIC_ASSERT(sizeof(Int32) == 4);
    /// ensure UInt16 is 2 bytes size
    GHL_STATIC_ASSERT(sizeof(UInt16) == 2);
    /// ensure Int16 is 2 bytes size
    GHL_STATIC_ASSERT(sizeof(Int16) == 2);
    
}

#endif /*GHL_TYPES_H*/
