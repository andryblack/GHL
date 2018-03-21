//
//  rendertarget_impl.cpp
//  GHL
//
//  Created by Andrey Kunitsyn on 11/13/12.
//  Copyright (c) 2012 AndryBlack. All rights reserved.
//

#include "rendertarget_impl.h"
#include "render_impl.h"

namespace GHL {

    RenderTargetImpl::RenderTargetImpl(RenderImpl* parent) : m_parent(parent),m_have_depth(false){
        m_mem_usage = 0;
        parent->RenderTargetCreated(this);
    }
    
    RenderTargetImpl::~RenderTargetImpl() {
        m_parent->RenderTargetReleased(this);
    }
    
    void RenderTargetImpl::SetMemoryUsage(UInt32 m) {
        m_parent->RenderTargetReleased(this);
        m_mem_usage = m;
        m_parent->RenderTargetCreated(this);
    }
    
    RenderImpl* RenderTargetImpl::GetParent() {
        return m_parent;
    }
    
    UInt32 RenderTargetImpl::GetMemoryUsage() const {
        return m_mem_usage;
    }
    
}
