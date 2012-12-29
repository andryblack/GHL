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
    
    VertexBufferImpl::VertexBufferImpl(RenderImpl* parent, VertexType type, UInt32 size ) : m_type(type),m_size(size),m_parent(parent)
	{
        parent->BufferCreated(this);
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

