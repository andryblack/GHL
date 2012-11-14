//
//  texture_impl.cpp
//  GHL
//
//  Created by Andrey Kunitsyn on 11/13/12.
//  Copyright (c) 2012 AndryBlack. All rights reserved.
//

#include "texture_impl.h"
#include "render_impl.h"

namespace GHL {
    
    TextureImpl::TextureImpl(RenderImpl* parent) : m_parent(parent) {
        parent->TextureCreated(this);
    }
    
    TextureImpl::~TextureImpl() {
        m_parent->TextureReleased(this);
    }
    
    void TextureImpl::RestoreTexture(UInt32 stage) {
        m_parent->SetTexture(m_parent->GetTexture(stage), stage);
    }
}