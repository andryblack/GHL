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

namespace GHL {

	VertexShaderGLSL::VertexShaderGLSL(RenderOpenGL* parent,GLhandleARB handle_) : m_parent(parent),m_handle(handle_) {
	
	}
	
	VertexShaderGLSL::~VertexShaderGLSL() {
		glDeleteObjectARB(m_handle);
	}

	
	void GHL_CALL VertexShaderGLSL::Release() {
		if (DeRef()) {
			if (m_parent) {
				m_parent->ReleaseVertexShader(this);
			}
		}
	}
	
	
	FragmentShaderGLSL::FragmentShaderGLSL(RenderOpenGL* parent,GLhandleARB handle_) : m_parent(parent),m_handle(handle_) {
		
	}
	
	FragmentShaderGLSL::~FragmentShaderGLSL() {
		glDeleteObjectARB(m_handle);
	}
	
	
	void GHL_CALL FragmentShaderGLSL::Release() {
		if (DeRef()) {
			if (m_parent) {
				m_parent->ReleaseFragmentShader(this);
			}
		}
	}
	
	
	
	ShaderProgramGLSL::ShaderProgramGLSL(RenderOpenGL* parent,GLhandleARB handle_,VertexShaderGLSL* vt,FragmentShaderGLSL* fr) : 
		m_parent(parent),m_handle(handle_),m_v(vt),m_f(fr) {
			m_v->AddRef();
			m_f->AddRef();
	}
	
	ShaderProgramGLSL::~ShaderProgramGLSL() {
		glDeleteObjectARB(m_handle);
	}
	
	
	void GHL_CALL ShaderProgramGLSL::Release() {
		if (DeRef()) {
			if (m_v) m_v->Release();
			m_v = 0;
			if (m_f) m_f->Release();
			m_f = 0;
			if (m_parent) {
				m_parent->ReleaseShaderProgram(this);
			}
		}
	}
	
	void GHL_CALL ShaderUniformGLSL::SetValueFloat(float v) {
		glUniform1fARB(m_location,v);
	}
	
	void GHL_CALL ShaderUniformGLSL::SetValueInt(Int32 v) {
		glUniform1iARB(m_location,v);
	}
	ShaderUniform* GHL_CALL ShaderProgramGLSL::GetUniform(const char* name) {
		std::string sname(name);
		std::map<std::string,ShaderUniformGLSL>::iterator it = m_uniforms.find(sname);
		if (it!=m_uniforms.end())
			return &it->second;
		GLint location = glGetUniformLocationARB(m_handle,name);
		if (location==-1)
			return 0;
		m_uniforms.insert(std::make_pair(sname,ShaderUniformGLSL(location)));
		it = m_uniforms.find(sname);
		return &it->second;
	}
	
}