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
    
    static const char* MODULE = "GLSL";

	VertexShaderGLSL::VertexShaderGLSL(RenderOpenGLBase* parent,GL::GLhandle handle_)
    : VertexShaderImpl(parent),gl(parent->get_api()),m_handle(handle_) {
        (void)MODULE;
	}
	
	VertexShaderGLSL::~VertexShaderGLSL() {
		gl.sdrapi.DeleteShader(m_handle);
 	}

	
	FragmentShaderGLSL::FragmentShaderGLSL(RenderOpenGLBase* parent,GL::GLhandle handle_)
    : FragmentShaderImpl(parent),gl(parent->get_api()),m_handle(handle_) {
		
	}
	
	FragmentShaderGLSL::~FragmentShaderGLSL() {
		gl.sdrapi.DeleteShader(m_handle);
	}
	
	
	
	
	ShaderProgramGLSL::ShaderProgramGLSL(RenderOpenGLBase* parent,GL::GLhandle handle_,VertexShaderGLSL* vt,FragmentShaderGLSL* fr)
    : ShaderProgramImpl(parent),gl(parent->get_api()),m_handle(handle_),m_v(vt),m_f(fr),m_pmv_uniform(-1) {
        m_v->AddRef();
        m_f->AddRef();
        
    }
	
	ShaderProgramGLSL::~ShaderProgramGLSL() {
		gl.sdrapi.DeleteProgram(m_handle);
        if (m_v) m_v->Release();
        m_v = 0;
        if (m_f) m_f->Release();
        m_f = 0;
    }
	
    void GHL_CALL ShaderUniformGLSL::SetSamplerSlot(UInt32 s) {
        const ShaderProgram* prg = m_program->GetCurrent();
        if (prg!=m_program) m_program->SetCurrent(m_program);
        const GL& gl = m_program->gl;
        CHECK_GL(gl.sdrapi.Uniform1i(m_location,s));
        if (prg!=m_program) m_program->SetCurrent(prg);
    }
	
	void GHL_CALL ShaderUniformGLSL::SetValueFloat(float v) {
        const ShaderProgram* prg = m_program->GetCurrent();
        if (prg!=m_program) m_program->SetCurrent(m_program);
        const GL& gl = m_program->gl;
		CHECK_GL(gl.sdrapi.Uniform1f(m_location,v));
        if (prg!=m_program) m_program->SetCurrent(prg);
	}
	
    void GHL_CALL ShaderUniformGLSL::SetValueFloat2(float x, float y) {
        const ShaderProgram* prg = m_program->GetCurrent();
        if (prg!=m_program) m_program->SetCurrent(m_program);
        const GL& gl = m_program->gl;
        CHECK_GL(gl.sdrapi.Uniform2f(m_location,x,y));
        if (prg!=m_program) m_program->SetCurrent(prg);
    }
    
    void GHL_CALL ShaderUniformGLSL::SetValueFloat3(float x, float y, float z) {
        const ShaderProgram* prg = m_program->GetCurrent();
        if (prg!=m_program) m_program->SetCurrent(m_program);
        const GL& gl = m_program->gl;
        CHECK_GL(gl.sdrapi.Uniform3f(m_location,x,y,z));
        if (prg!=m_program) m_program->SetCurrent(prg);
    }
    
    void GHL_CALL ShaderUniformGLSL::SetValueFloat4(float x, float y, float z, float w) {
        const ShaderProgram* prg = m_program->GetCurrent();
        if (prg!=m_program) m_program->SetCurrent(m_program);
        const GL& gl = m_program->gl;
        CHECK_GL(gl.sdrapi.Uniform4f(m_location,x,y,z,w));
        if (prg!=m_program) m_program->SetCurrent(prg);
    }
   
    void GHL_CALL ShaderUniformGLSL::SetValueMatrix(const float* v) {
        const ShaderProgram* prg = m_program->GetCurrent();
        if (prg!=m_program) m_program->SetCurrent(m_program);
        const GL& gl = m_program->gl;
        CHECK_GL(gl.sdrapi.UniformMatrix4fv(m_location,1,gl._FALSE,v));
        if (prg!=m_program) m_program->SetCurrent(prg);
    }
    void GHL_CALL ShaderUniformGLSL::SetArrayMatrix(const float* v,UInt32 cnt) {
        const ShaderProgram* prg = m_program->GetCurrent();
        if (prg!=m_program) m_program->SetCurrent(m_program);
        const GL& gl = m_program->gl;
        CHECK_GL(gl.sdrapi.UniformMatrix4fv(m_location,cnt,gl._FALSE,v));
        if (prg!=m_program) m_program->SetCurrent(prg);
    }
	
    ShaderUniform* GHL_CALL ShaderProgramGLSL::GetUniform(const char* name) const {
		std::string sname(name);
		std::map<std::string,ShaderUniformGLSL>::iterator it = m_uniforms.find(sname);
		if (it!=m_uniforms.end())
			return &it->second;
        GL::GLint location = -1;
        CHECK_GL(location=gl.sdrapi.GetUniformLocation(m_handle,name));
		if (location<0)
			return 0;
		return &m_uniforms.insert(std::make_pair(sname,ShaderUniformGLSL(this,location))).first->second;
	}
    
    
    void ShaderProgramGLSL::Setup() {
        for (size_t i=0;i<STATE_MAX_TEXTURE_STAGES;++i) {
            char uf[64];
            ::snprintf(uf, 64, "texture_%d",int(i));
            GL::GLint location = -1;
            CHECK_GL(location = gl.sdrapi.GetUniformLocation(m_handle,uf));
            if (location>=0) {
                gl.sdrapi.Uniform1i(location,GL::GLint(i));
            }
        }
        m_pmv_uniform = gl.sdrapi.GetUniformLocation(m_handle,"mProjectionModelView");
    }
    void ShaderProgramGLSL::SetPMVMatrix(const float* m) const {
        if (m_pmv_uniform >= 0) {
            CHECK_GL(gl.sdrapi.UniformMatrix4fv(m_pmv_uniform,1,gl._FALSE,m));
        }
    }
   
    const ShaderProgram* ShaderProgramGLSL::GetCurrent() const {
        return GetParent()->GetShader();
    }
    void ShaderProgramGLSL::SetCurrent(const ShaderProgram* prg) const {
        GetParent()->SetShader(prg);
    }
	
    
}


#endif /*GHL_SHADERS_UNSUPPORTED*/
