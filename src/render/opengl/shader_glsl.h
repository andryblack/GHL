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
#include "../shader_impl.h"

#include <map>
#include <string>

namespace GHL {
	
	class RenderOpenGL;
	class VertexShaderGLSL;
	class FragmentShaderGLSL;
	class ShaderUniformGLSL;
	
	
	class VertexShaderGLSL : public VertexShaderImpl {
	public:
		VertexShaderGLSL(RenderOpenGL* parent,GL::GLhandle handle);
		virtual ~VertexShaderGLSL();
		
		GL::GLhandle    handle() const { return m_handle;}
	private:
        const GL& gl;
		GL::GLhandle	m_handle;
	};
	
	class FragmentShaderGLSL : public FragmentShaderImpl {
	public:
		FragmentShaderGLSL(RenderOpenGL* parent,GL::GLhandle handle);
		virtual ~FragmentShaderGLSL();
		
		GL::GLhandle handle() const { return m_handle;}
	private:
        const GL& gl;
		GL::GLhandle	m_handle;
	};
	
	class ShaderUniformGLSL : public ShaderUniform {
	private:
        const GL& gl;
		GL::GLint m_location;
	public:
		explicit ShaderUniformGLSL(const GL& gl,GL::GLint location_) : gl(gl),
            m_location(location_) {}
		virtual ~ShaderUniformGLSL() {}
		GL::GLint location() const { return m_location;}
		virtual void GHL_CALL SetValueFloat(float v);
		virtual void GHL_CALL SetValueInt(Int32 v);
	};
	
	class ShaderProgramGLSL : public ShaderProgramImpl {
	public:
		ShaderProgramGLSL(RenderOpenGL* parent,GL::GLhandle handle,VertexShaderGLSL* vt,FragmentShaderGLSL* fr);
		virtual ~ShaderProgramGLSL();
		
		/// get uniform
		ShaderUniform* GHL_CALL GetUniform(const char* name) ;
		
		GL::GLhandle handle() const { return m_handle;}
	private:
        const GL& gl;
		GL::GLhandle	m_handle;
		VertexShaderGLSL* m_v;
		FragmentShaderGLSL* m_f;
		std::map<std::string,ShaderUniformGLSL> m_uniforms;
	};
}

#endif /*SHADER_GLSL_H*/
