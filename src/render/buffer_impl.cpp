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
    
    
    SoftVertexBuffer::SoftVertexBuffer( RenderImpl* parent, VertexType type, UInt32 size ) : VertexBufferImpl(parent,type,size),m_data(0) {}
    SoftVertexBuffer::~SoftVertexBuffer() {
        if (m_data) {
            m_data->Release();
        }
    }
    void GHL_CALL SoftVertexBuffer::SetData(const Data* data) {
        if (m_data) {
            m_data->Release();
        }
        m_data = 0;
        if (data) {
            m_data = data->Clone();
        }
    }
    
    const void* SoftVertexBuffer::GetData() const {
        if (m_data) return m_data->GetData();
        return 0;
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
    
    SoftIndexBuffer::SoftIndexBuffer( RenderImpl* parent, UInt32 size ) : IndexBufferImpl(parent,size),m_data(0) {}
    SoftIndexBuffer::~SoftIndexBuffer() {
        if (m_data) {
            m_data->Release();
        }
    }
    void GHL_CALL SoftIndexBuffer::SetData(const Data* data) {
        if (m_data) {
            m_data->Release();
        }
        m_data = 0;
        if (data) {
            m_data = data->Clone();
        }
    }
    
    const void* SoftIndexBuffer::GetData() const {
        if (m_data) return m_data->GetData();
        return 0;
    }
}

