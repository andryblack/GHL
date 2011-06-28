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
#include "refcount_opengl.h"

#include <map>
#include <string>

namespace GHL {
	
	class RenderOpenGL;
	class VertexShaderGLSL;
	class FragmentShaderGLSL;
	class ShaderUniformGLSL;
	
#ifndef GHL_SHADERS_UNSUPPORTED
	
	class VertexShaderGLSL : public RefCount<VertexShader> {
	public:
		VertexShaderGLSL(RenderOpenGL* parent,GLhandleARB handle);
		virtual ~VertexShaderGLSL();
		
		virtual void GHL_CALL Release();
		
		GLhandleARB handle() const { return m_handle;}
	private:
		RenderOpenGL* m_parent;
		GLhandleARB	m_handle;
	};
	
	class FragmentShaderGLSL : public RefCount<FragmentShader> {
	public:
		FragmentShaderGLSL(RenderOpenGL* parent,GLhandleARB handle);
		virtual ~FragmentShaderGLSL();
		
		virtual void GHL_CALL Release();
		
		GLhandleARB handle() const { return m_handle;}
	private:
		RenderOpenGL* m_parent;
		GLhandleARB	m_handle;
	};
	
	class ShaderUniformGLSL : public ShaderUniform {
	private:
		GLint m_location;
	public:
		explicit ShaderUniformGLSL(GLint location_) : m_location(location_) {}
		virtual ~ShaderUniformGLSL() {}
		GLint location() const { return m_location;}
		virtual void GHL_CALL SetValueFloat(float v);
		virtual void GHL_CALL SetValueInt(Int32 v);
	};
	
	class ShaderProgramGLSL : public RefCount<ShaderProgram> {
	public:
		ShaderProgramGLSL(RenderOpenGL* parent,GLhandleARB handle,VertexShaderGLSL* vt,FragmentShaderGLSL* fr);
		virtual ~ShaderProgramGLSL();
		
		virtual void GHL_CALL Release();
		
		/// get uniform
		ShaderUniform* GHL_CALL GetUniform(const char* name) ;
		
		GLhandleARB handle() const { return m_handle;}
	private:
		RenderOpenGL* m_parent;
		GLhandleARB	m_handle;
		VertexShaderGLSL* m_v;
		FragmentShaderGLSL* m_f;
		std::map<std::string,ShaderUniformGLSL> m_uniforms;
	};
#endif
	
}

#endif /*SHADER_GLSL_H*/
