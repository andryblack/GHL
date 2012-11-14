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

    RenderTargetImpl::RenderTargetImpl(RenderImpl* parent) : m_parent(parent) {
        parent->RenderTargetCreated(this);
    }
    
    RenderTargetImpl::~RenderTargetImpl() {
        m_parent->RenderTargetReleased(this);
    }
    
    RenderImpl* RenderTargetImpl::GetParent() {
        return m_parent;
    }
    
}
