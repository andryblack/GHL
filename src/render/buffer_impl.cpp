//
//  texture_impl.cpp
//  GHL
//
//  Created by Andrey Kunitsyn on 11/13/12.
//  Copyright (c) 2012 AndryBlack. All rights reserved.
//

#include "buffer_impl.h"
#include "render_impl.h"

namespace GHL {
    
    VertexBufferImpl::VertexBufferImpl(RenderImpl* parent,
                                       UInt32 vsize,
                                       UInt32 count,
                                       const VertexAttributeDef* attributes ) : m_vertex_size(vsize), m_capacity(count),m_parent(parent)
	{
        parent->BufferCreated(this);
        size_t i = 0;
        while (attributes[i].usage != VERTEX_MAX_ATTRIBUTES) {
            m_attributes.push_back(attributes[i]);
            ++i;
        }
    }
    
    VertexBufferImpl::~VertexBufferImpl() {
        m_parent->BufferReleased(this);
    }
  
    const VertexBuffer* VertexBufferImpl::GetCurrent() const {
        return m_parent->GetVertexBuffer();
    }
    void VertexBufferImpl::RestoreCurrent(const VertexBuffer* vb) {
        m_parent->SetVertexBuffer(vb);
    }
    
    
    
    IndexBufferImpl::IndexBufferImpl(RenderImpl* parent,UInt32 size ) : m_size(size),m_parent(parent)
	{
        parent->BufferCreated(this);
    }
    
    IndexBufferImpl::~IndexBufferImpl() {
        m_parent->BufferReleased(this);
    }
    
    const IndexBuffer* IndexBufferImpl::GetCurrent() const {
        return m_parent->GetIndexBuffer();
    }
    void IndexBufferImpl::RestoreCurrent(const IndexBuffer* vb) {
        m_parent->SetIndexBuffer(vb);
    }
    
    
}

