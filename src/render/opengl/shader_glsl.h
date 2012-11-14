/*
 *  shader_glsl.h
 *  SR
 *
 *  Created by Андрей Куницын on 13.02.11.
 *  Copyright 2011 andryblack. All rights reserved.
 *
 */

#ifndef SHADER_GLSL_H
#define SHADER_GLSL_H

#include "ghl_shader.h"
#include "ghl_opengl.h"
#include "../../ghl_ref_counter_impl.h"

#include <map>
#include <string>

namespace GHL {
	
	class RenderOpenGL;
	class VertexShaderGLSL;
	class FragmentShaderGLSL;
	class ShaderUniformGLSL;
	
#ifndef GHL_SHADERS_UNSUPPORTED
	
	class VertexShaderGLSL : public RefCounterImpl<VertexShader> {
	public:
		VertexShaderGLSL(RenderOpenGL* parent,GL::GLhandleARB handle);
		virtual ~VertexShaderGLSL();
		
		GL::GLhandleARB handle() const { return m_handle;}
	private:
		RenderOpenGL* m_parent;
		GL::GLhandleARB	m_handle;
	};
	
	class FragmentShaderGLSL : public RefCounterImpl<FragmentShader> {
	public:
		FragmentShaderGLSL(RenderOpenGL* parent,GL::GLhandleARB handle);
		virtual ~FragmentShaderGLSL();
		
		GL::GLhandleARB handle() const { return m_handle;}
	private:
		RenderOpenGL* m_parent;
		GL::GLhandleARB	m_handle;
	};
	
	class ShaderUniformGLSL : public ShaderUniform {
	private:
		GL::GLint m_location;
	public:
		explicit ShaderUniformGLSL(GL::GLint location_) : m_location(location_) {}
		virtual ~ShaderUniformGLSL() {}
		GL::GLint location() const { return m_location;}
		virtual void GHL_CALL SetValueFloat(float v);
		virtual void GHL_CALL SetValueInt(Int32 v);
	};
	
	class ShaderProgramGLSL : public RefCounterImpl<ShaderProgram> {
	public:
		ShaderProgramGLSL(RenderOpenGL* parent,GL::GLhandleARB handle,VertexShaderGLSL* vt,FragmentShaderGLSL* fr);
		virtual ~ShaderProgramGLSL();
		
		/// get uniform
		ShaderUniform* GHL_CALL GetUniform(const char* name) ;
		
		GL::GLhandleARB handle() const { return m_handle;}
	private:
		RenderOpenGL* m_parent;
		GL::GLhandleARB	m_handle;
		VertexShaderGLSL* m_v;
		FragmentShaderGLSL* m_f;
		std::map<std::string,ShaderUniformGLSL> m_uniforms;
	};
#endif
	
}

#endif /*SHADER_GLSL_H*/
