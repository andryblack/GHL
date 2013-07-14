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
    : ShaderProgramImpl(parent),gl(parent->get_api()),m_handle(handle_),m_v(vt),m_f(fr) {
			m_v->AddRef();
			m_f->AddRef();
        for (size_t i=0;i<sizeof(m_attributes)/sizeof(m_attributes[0]);++i) {
            m_attributes[i] = -1;
        }
	}
	
	ShaderProgramGLSL::~ShaderProgramGLSL() {
		gl.sdrapi.DeleteProgram(m_handle);
        if (m_v) m_v->Release();
        m_v = 0;
        if (m_f) m_f->Release();
        m_f = 0;
    }
	
	
	void GHL_CALL ShaderUniformGLSL::SetValueFloat(float v) {
		CHECK_GL(gl.sdrapi.Uniform1f(m_location,v));
	}
	
	void GHL_CALL ShaderUniformGLSL::SetValueInt(Int32 v) {
		CHECK_GL(gl.sdrapi.Uniform1i(m_location,v));
	}
    void GHL_CALL ShaderUniformGLSL::SetValueMatrix(const float* v) {
        CHECK_GL(gl.sdrapi.UniformMatrix4fv(m_location,1,gl._FALSE,v));
    }
	ShaderUniform* GHL_CALL ShaderProgramGLSL::GetUniform(const char* name) const {
		std::string sname(name);
		std::map<std::string,ShaderUniformGLSL>::iterator it = m_uniforms.find(sname);
		if (it!=m_uniforms.end())
			return &it->second;
        GL::GLint location = gl.sdrapi.GetUniformLocation(m_handle,name);
        CHECK_GL();
		if (location<0)
			return 0;
		m_uniforms.insert(std::make_pair(sname,ShaderUniformGLSL(gl,location)));
		it = m_uniforms.find(sname);
		return &it->second;
	}
    
    static const char* predefinedAttributeNames[GLSLPredefinedAttributesAmount] = {
        "vPosition",
        "vTexCoord",
        "vColor"
    };
    GL::GLint   ShaderProgramGLSL::GetAttribute(GLSLPredefinedAttribute attr) const {
        if (m_attributes[attr]<0) {
            m_attributes[attr] = gl.sdrapi.GetAttribLocation(m_handle,predefinedAttributeNames[attr]);
            CHECK_GL(gl.sdrapi.EnableVertexAttribArray(m_attributes[attr]));
        }
        return m_attributes[attr];
    }
	
    
}


#endif /*GHL_SHADERS_UNSUPPORTED*/