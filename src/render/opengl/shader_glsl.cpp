/*
 *  shader_opengl.cpp
 *  SR
 *
 *  Created by Андрей Куницын on 13.02.11.
 *  Copyright 2011 andryblack. All rights reserved.
 *
 */

#include "shader_glsl.h"
#include "render_opengl.h"

#ifndef GHL_SHADERS_UNSUPPORTED

namespace GHL {

	VertexShaderGLSL::VertexShaderGLSL(RenderOpenGL* parent,GL::GLhandleARB handle_) : m_parent(parent),m_handle(handle_) {
	
	}
	
	VertexShaderGLSL::~VertexShaderGLSL() {
		gl.DeleteObjectARB(m_handle);
 	}

	
	FragmentShaderGLSL::FragmentShaderGLSL(RenderOpenGL* parent,GL::GLhandleARB handle_) : m_parent(parent),m_handle(handle_) {
		
	}
	
	FragmentShaderGLSL::~FragmentShaderGLSL() {
		gl.DeleteObjectARB(m_handle);
	}
	
	
	
	
	ShaderProgramGLSL::ShaderProgramGLSL(RenderOpenGL* parent,GL::GLhandleARB handle_,VertexShaderGLSL* vt,FragmentShaderGLSL* fr) :
		m_parent(parent),m_handle(handle_),m_v(vt),m_f(fr) {
			m_v->AddRef();
			m_f->AddRef();
	}
	
	ShaderProgramGLSL::~ShaderProgramGLSL() {
		gl.DeleteObjectARB(m_handle);
        if (m_v) m_v->Release();
        m_v = 0;
        if (m_f) m_f->Release();
        m_f = 0;
    }
	
	
	void GHL_CALL ShaderUniformGLSL::SetValueFloat(float v) {
		gl.Uniform1fARB(m_location,v);
	}
	
	void GHL_CALL ShaderUniformGLSL::SetValueInt(Int32 v) {
		gl.Uniform1iARB(m_location,v);
	}
	ShaderUniform* GHL_CALL ShaderProgramGLSL::GetUniform(const char* name) {
		std::string sname(name);
		std::map<std::string,ShaderUniformGLSL>::iterator it = m_uniforms.find(sname);
		if (it!=m_uniforms.end())
			return &it->second;
        GL::GLint location = gl.GetUniformLocationARB(m_handle,name);
		if (location==-1)
			return 0;
		m_uniforms.insert(std::make_pair(sname,ShaderUniformGLSL(location)));
		it = m_uniforms.find(sname);
		return &it->second;
	}
	
}


#endif /*GHL_SHADERS_UNSUPPORTED*/