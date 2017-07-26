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
#include "../shader_impl.h"
#include "render_opengl_api.h"
#include <ghl_render.h>

#include <map>
#include <string>

namespace GHL {
	
	class RenderOpenGLBase;
	class VertexShaderGLSL;
	class FragmentShaderGLSL;
	class ShaderUniformGLSL;
	
	
	class VertexShaderGLSL : public VertexShaderImpl {
	public:
		VertexShaderGLSL(RenderOpenGLBase* parent,GL::GLhandle handle);
		virtual ~VertexShaderGLSL();
		
		GL::GLhandle    handle() const { return m_handle;}
	private:
        const GL& gl;
		GL::GLhandle	m_handle;
	};
	
	class FragmentShaderGLSL : public FragmentShaderImpl {
	public:
		FragmentShaderGLSL(RenderOpenGLBase* parent,GL::GLhandle handle);
		virtual ~FragmentShaderGLSL();
		
		GL::GLhandle handle() const { return m_handle;}
	private:
        const GL& gl;
		GL::GLhandle	m_handle;
	};
	
    class ShaderProgramGLSL;
	class ShaderUniformGLSL : public ShaderUniform {
	private:
        const ShaderProgramGLSL* m_program;
		GL::GLint m_location;
  	public:
		explicit ShaderUniformGLSL(const ShaderProgramGLSL* prog,GL::GLint location_ ) : m_program(prog),
            m_location(location_) {}
		virtual ~ShaderUniformGLSL() {}
		GL::GLint location() const { return m_location;}
		virtual void GHL_CALL SetValueFloat(float v);
        virtual void GHL_CALL SetValueFloat2(float x,float y);
        virtual void GHL_CALL SetValueFloat3(float x, float y, float z);
        virtual void GHL_CALL SetValueFloat4(float x, float y, float z, float w);
		virtual void GHL_CALL SetValueMatrix(const float* v);
	};
    
	
	class ShaderProgramGLSL : public ShaderProgramImpl {
	public:
		ShaderProgramGLSL(RenderOpenGLBase* parent,GL::GLhandle handle,VertexShaderGLSL* vt,FragmentShaderGLSL* fr);
		virtual ~ShaderProgramGLSL();
		
		/// get uniform
		ShaderUniform* GHL_CALL GetUniform(const char* name) const;
		
		GL::GLhandle handle() const { return m_handle;}
        void  Setup();
        void SetPMVMatrix(const float* m) const;
	private:
        friend class ShaderUniformGLSL;
        const GL& gl;
		GL::GLhandle	m_handle;
		VertexShaderGLSL* m_v;
		FragmentShaderGLSL* m_f;
      	mutable std::map<std::string,ShaderUniformGLSL> m_uniforms;
        GL::GLint m_pmv_uniform;
        const ShaderProgram* GetCurrent() const;
        void SetCurrent(const ShaderProgram* prg) const;
	};
}

#endif /*SHADER_GLSL_H*/
