/*
 GHL - Game Helpers Library
 Copyright (C)  Andrey Kunitsyn 2017
 
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

#ifndef GHL_BUFFER_H
#define GHL_BUFFER_H

#include "ghl_ref_counter.h"
#include "ghl_data.h"

namespace GHL {
  
    enum VertexDataType {
        VERTEX_4_BYTE,
        VERTEX_2_FLOAT,
        VERTEX_3_FLOAT,
        VERTEX_4_FLOAT
    };
    
    enum VertexAttributeUsage {
        VERTEX_POSITION,
        VERTEX_TEX_COORD0,
        VERTEX_TEX_COORD1,
        VERTEX_COLOR,
        VERTEX_NORMAL,
        VERTEX_WEIGHT,
        VERTEX_INDEX,
        VERTEX_TANGENT,
        VERTEX_MAX_ATTRIBUTES
    };
    
    struct VertexAttributeDef {
        UInt32          offset;
        VertexDataType  data;
        VertexAttributeUsage usage;
    };
    
    /// vertex buffer object
    struct VertexBuffer : RefCounter
    {
        /// get vertex size
        virtual UInt32 GHL_CALL GetVertexSize() const = 0;
        /// get buffer capacity (elements)
        virtual UInt32 GHL_CALL GetCapacity() const = 0;
        /// set buffer data
        virtual void GHL_CALL SetData(const Data* data) = 0;
        /// attributes count
        virtual UInt32 GHL_CALL GetAttributesCount() const = 0;
        /// attribute
        virtual const VertexAttributeDef* GHL_CALL GetAttribute(UInt32 i) const = 0;
    };
    
    /// index buffer object
    struct IndexBuffer : RefCounter
    {
        /// get buffer capacity (elements)
        virtual UInt32 GHL_CALL GetCapacity() const = 0;
        /// set buffer data
        virtual void GHL_CALL SetData(const Data* data) = 0;
    };

}

#endif /*GHL_BUFFER_H*/
