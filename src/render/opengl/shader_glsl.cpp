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

	VertexShaderGLSL::VertexShaderGLSL(RenderOpenGL* parent,GL::GLhandle handle_)
    : VertexShaderImpl(parent),gl(parent->get_api()),m_handle(handle_) {
	
	}
	
	VertexShaderGLSL::~VertexShaderGLSL() {
		gl.sdrapi->DeleteObject(m_handle);
 	}

	
	FragmentShaderGLSL::FragmentShaderGLSL(RenderOpenGL* parent,GL::GLhandle handle_)
    : FragmentShaderImpl(parent),gl(parent->get_api()),m_handle(handle_) {
		
	}
	
	FragmentShaderGLSL::~FragmentShaderGLSL() {
		gl.sdrapi->DeleteObject(m_handle);
	}
	
	
	
	
	ShaderProgramGLSL::ShaderProgramGLSL(RenderOpenGL* parent,GL::GLhandle handle_,VertexShaderGLSL* vt,FragmentShaderGLSL* fr)
    : ShaderProgramImpl(parent),gl(parent->get_api()),m_handle(handle_),m_v(vt),m_f(fr) {
			m_v->AddRef();
			m_f->AddRef();
	}
	
	ShaderProgramGLSL::~ShaderProgramGLSL() {
		gl.sdrapi->DeleteObject(m_handle);
        if (m_v) m_v->Release();
        m_v = 0;
        if (m_f) m_f->Release();
        m_f = 0;
    }
	
	
	void GHL_CALL ShaderUniformGLSL::SetValueFloat(float v) {
		gl.sdrapi->Uniform1f(m_location,v);
	}
	
	void GHL_CALL ShaderUniformGLSL::SetValueInt(Int32 v) {
		gl.sdrapi->Uniform1i(m_location,v);
	}
	ShaderUniform* GHL_CALL ShaderProgramGLSL::GetUniform(const char* name) {
		std::string sname(name);
		std::map<std::string,ShaderUniformGLSL>::iterator it = m_uniforms.find(sname);
		if (it!=m_uniforms.end())
			return &it->second;
        GL::GLint location = gl.sdrapi->GetUniformLocation(m_handle,name);
		if (location==-1)
			return 0;
		m_uniforms.insert(std::make_pair(sname,ShaderUniformGLSL(gl,location)));
		it = m_uniforms.find(sname);
		return &it->second;
	}
	
}


#endif /*GHL_SHADERS_UNSUPPORTED*/