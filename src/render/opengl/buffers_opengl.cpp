//
//  buffers_opengl.cpp
//  GHL
//
//  Created by Andrey Kunitsyn on 12/29/12.
//  Copyright (c) 2012 AndryBlack. All rights reserved.
//

#include "buffers_opengl.h"
#include "render_opengl.h"

namespace GHL {
    VertexBufferOpenGL::VertexBufferOpenGL(RenderOpenGLBase* parent, UInt32 vsize,
                                           UInt32 count,
                                           const VertexAttributeDef* attributes
                                           ,GL::GLuint name)
    : VertexBufferImpl(parent,vsize,count,attributes),gl(parent->get_api()),m_name(name) {
        
    }
    
    VertexBufferOpenGL::~VertexBufferOpenGL() {
        gl.vboapi.DeleteBuffers(1,&m_name);
    }
    
    void VertexBufferOpenGL::bind() const {
        gl.vboapi.BindBuffer(gl.vboapi.ARRAY_BUFFER,m_name);
    }
    
    void VertexBufferOpenGL::SetData(const GHL::Data *data) {
        const VertexBuffer* crnt = GetCurrent();
        bind();
        gl.vboapi.BufferData(gl.vboapi.ARRAY_BUFFER,data->GetSize(),data->GetData(),gl.vboapi.STATIC_DRAW);
        RestoreCurrent(crnt);
    }
    
    
    IndexBufferOpenGL::IndexBufferOpenGL(RenderOpenGLBase* parent, UInt32 size,GL::GLuint name)
    : IndexBufferImpl(parent,size),gl(parent->get_api()),m_name(name) {
        
    }
    
    IndexBufferOpenGL::~IndexBufferOpenGL() {
        gl.vboapi.DeleteBuffers(1,&m_name);
    }
    
    void IndexBufferOpenGL::bind() const {
        gl.vboapi.BindBuffer(gl.vboapi.ELEMENT_ARRAY_BUFFER,m_name);
    }
    
    void IndexBufferOpenGL::SetData(const GHL::Data *data) {
        const IndexBuffer* crnt = GetCurrent();
        bind();
        gl.vboapi.BufferData(gl.vboapi.ELEMENT_ARRAY_BUFFER,data->GetSize(),data->GetData(),gl.vboapi.STATIC_DRAW);
        RestoreCurrent(crnt);
    }
        
}
