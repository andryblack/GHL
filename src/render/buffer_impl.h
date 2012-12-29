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

namespace GHL {
    
    class RenderImpl;
    
    class VertexBufferImpl : public RefCounterImpl<VertexBuffer> {
    public:
        virtual ~VertexBufferImpl();
        
        /// get vertex type
		virtual VertexType GHL_CALL GetType() const { return m_type; }
		/// get buffer capacity
		virtual UInt32 GHL_CALL GetCapacity() const { return m_size; }

    protected:
        explicit VertexBufferImpl( RenderImpl* parent, VertexType type, UInt32 size );
        VertexType	m_type;
		UInt32	m_size;
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
