//
//  shader_impl.cpp
//  GHL
//
//  Created by Andrey Kunitsyn on 11/13/12.
//  Copyright (c) 2012 AndryBlack. All rights reserved.
//

#include "shader_impl.h"
#include "render_impl.h"

namespace GHL {

    VertexShaderImpl::VertexShaderImpl( RenderImpl* parent) : m_parent(parent) {
        parent->VertexShaderCreated(this);
    }
    
    VertexShaderImpl::~VertexShaderImpl() {
        m_parent->VertexShaderReleased(this);
    }
    
    FragmentShaderImpl::FragmentShaderImpl( RenderImpl* parent) : m_parent(parent) {
        parent->FragmentShaderCreated(this);
    }
    
    FragmentShaderImpl::~FragmentShaderImpl() {
        m_parent->FragmentShaderReleased(this);
    }
    
    ShaderProgramImpl::ShaderProgramImpl( RenderImpl* parent) : m_parent(parent) {
        parent->ShaderProgramCreated(this);
    }
    
    ShaderProgramImpl::~ShaderProgramImpl() {
        m_parent->ShaderProgramReleased(this);
    }
}
