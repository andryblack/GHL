/*
 GHL - Game Helpers Library
 Copyright (C)  Andrey Kunitsyn 2012
 
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

#ifndef BUFFER_IMPL_H_INCLUDED
#define BUFFER_IMPL_H_INCLUDED

#include "ghl_render.h"
#include "../ghl_ref_counter_impl.h"
#include <vector>

namespace GHL {
    
    class RenderImpl;
    
    typedef std::vector<VertexAttributeDef> VertexAttributes;
    
    class VertexBufferImpl : public RefCounterImpl<VertexBuffer> {
    public:
        virtual ~VertexBufferImpl();
        
        virtual UInt32 GHL_CALL GetVertexSize() const { return m_vertex_size; }
        /// get buffer capacity
		virtual UInt32 GHL_CALL GetCapacity() const { return m_capacity; }

        /// attributes count
        virtual UInt32 GHL_CALL GetAttributesCount() const { return UInt32(m_attributes.size()); }
        /// attribute
        virtual const VertexAttributeDef* GHL_CALL GetAttribute(UInt32 i) const {
            if (i>=UInt32(m_attributes.size()))
                return 0;
            return &m_attributes[i];
        }
        
        const VertexAttributes& GetAttributes() const { return m_attributes; }
    protected:
        explicit VertexBufferImpl( RenderImpl* parent, UInt32 vsize, UInt32 count, const VertexAttributeDef* attributes );
        VertexAttributes m_attributes;
        UInt32  m_vertex_size;
		UInt32	m_capacity;
        const VertexBuffer* GetCurrent() const;
        void RestoreCurrent(const VertexBuffer* vb);
    private:
        RenderImpl* m_parent;
    };
    
    class IndexBufferImpl : public RefCounterImpl<IndexBuffer> {
    public:
        virtual ~IndexBufferImpl();
        
        /// get buffer capacity
		virtual UInt32 GHL_CALL GetCapacity() const { return m_size; }
    protected:
        explicit IndexBufferImpl( RenderImpl* parent, UInt32 size );
      	UInt32	m_size;
        const IndexBuffer* GetCurrent() const;
        void RestoreCurrent(const IndexBuffer* vb);
    private:
        RenderImpl* m_parent;
    };
    
}

#endif /* BUFFER_IMPL_H_INCLUDED */
