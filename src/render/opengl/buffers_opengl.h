//
//  buffers_opengl.h
//  GHL
//
//  Created by Andrey Kunitsyn on 12/29/12.
//  Copyright (c) 2012 AndryBlack. All rights reserved.
//

#ifndef __GHL__buffers_opengl__
#define __GHL__buffers_opengl__

#include "../buffer_impl.h"
#include "render_opengl_api.h"

namespace GHL {
    
    class RenderOpenGLBase;
    
    
    class VertexBufferOpenGL : public VertexBufferImpl {
        const GL& gl;
		GL::GLuint  m_name;
    public:
        VertexBufferOpenGL(RenderOpenGLBase* parent, UInt32 vsize,
                           UInt32 count,
                           const VertexAttributeDef* attributes,GL::GLuint name);
        ~VertexBufferOpenGL();
        void bind() const;
        /// set buffer data
		virtual void GHL_CALL SetData(const Data* data);
    };
    
    class IndexBufferOpenGL : public IndexBufferImpl {
        const GL& gl;
		GL::GLuint  m_name;
    public:
        IndexBufferOpenGL(RenderOpenGLBase* parent,UInt32 size,GL::GLuint name);
        ~IndexBufferOpenGL();
        void bind() const;
        /// set buffer data
		virtual void GHL_CALL SetData(const Data* data);
    };
    
}

#endif /* defined(__GHL__buffers_opengl__) */
