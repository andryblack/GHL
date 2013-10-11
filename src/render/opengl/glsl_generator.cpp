//
//  glsl_generator.cpp
//  GHL
//
//  Created by Andrey Kunitsyn on 11/18/12.
//  Copyright (c) 2012 AndryBlack. All rights reserved.
//

#include "glsl_generator.h"
#include "../../ghl_data_impl.h"
#include "../../ghl_log_impl.h"

namespace GHL {
    
    static const char* MODULE = "GLSLGenerator";
    
    GLSLGenerator::GLSLGenerator() : m_render(0), m_simple_v(0) {
        
    }
    
    void GLSLGenerator::init(GHL::Render *render) {
        m_render = render;
    }
    
    static const char* simple_v =
    "attribute vec3 vPosition;\n"
    "attribute vec2 vTexCoord;\n"
    "attribute vec4 vColor;\n"
    "uniform mat4 mProjection;\n"
    "uniform mat4 mModelView;\n"
    "varying vec2 varTexCoord_0;\n"
    "varying vec4 varColor;\n"
    "void main(void) {\n"
    " gl_Position = mProjection * mModelView * vec4(vPosition,1.0);\n"
    " varTexCoord_0 = vTexCoord;\n"
    " varColor = vColor;\n"
    "}\n";
    
    static void append_tex_stage( std::stringstream& ss,
                                 const pfpl_state_data::texture_stage::state& state,
                                 const char* dst, const char* src, const char* tex) {
        if (state.c.operation == TEX_OP_DISABLE)
            return;
        const char* op1 = src;
        if (state.c.arg_1 == TEX_ARG_TEXTURE) {
            op1  = tex;
        } else if (state.c.arg_1 == TEX_ARG_TEXTURE_INV) {
            LOG_ERROR("unimplemented texture stage argument");
            return;
        } else if (state.c.arg_1 == TEX_ARG_CURRENT_INV) {
            LOG_ERROR("unimplemented texture stage argument");
            return;
        }
        const char* op2 = tex;
        if (state.c.arg_2 == TEX_ARG_CURRENT) {
            op2  = src;
        } else if (state.c.arg_2 == TEX_ARG_TEXTURE_INV) {
            LOG_ERROR("unimplemented texture stage argument");
            return;
        } else if (state.c.arg_2 == TEX_ARG_CURRENT_INV) {
            LOG_ERROR("unimplemented texture stage argument");
            return;
        }
        if (state.c.operation == TEX_OP_SELECT_1) {
            if (state.c.arg_1!=TEX_ARG_CURRENT) {
                ss << "    "<<dst<<"="<<op1<<";\n";
            }
        } else if (state.c.operation == TEX_OP_SELECT_2) {
            if (state.c.arg_2!=TEX_ARG_CURRENT) {
                ss << "    "<<dst<<"="<<op2<<";\n";
            }
        } else if (state.c.operation == TEX_OP_MODULATE) {
            ss << "    "<<dst<<"="<<op1<<"*"<<op2<<";\n";
        } else if (state.c.operation == TEX_OP_ADD) {
            ss << "    "<<dst<<"="<<op1<<"+"<<op2<<";\n";
        } else if (state.c.operation == TEX_OP_INT_TEXTURE_ALPHA) {
            ss << "    "<<dst<<"=mix("<<op1<<","<<op2<<",tex.a);\n";
        } else if (state.c.operation == TEX_OP_INT_CURRENT_ALPHA) {
            ss << "    "<<dst<<"=mix("<<op1<<","<<op2<<",clr.a);\n";
        }

    }
    
    ShaderProgram* GLSLGenerator::generate(const pfpl_state_data& entry, bool tex2 ) {
        if (!m_simple_v) {
            ConstInlinedData data((const Byte*)simple_v,UInt32(strlen(simple_v)));
            m_simple_v = m_render->CreateVertexShader(&data);
            if (!m_simple_v) {
                LOG_ERROR("create vertex shader");
                return 0;
            } else {
                LOG_VERBOSE("created vertex shader:\n" << simple_v);
            }
        }
        std::stringstream ss;
        if  (!m_fshader_header.empty()) {
            ss << m_fshader_header;
        }
        for (size_t i=0;i<MAX_TEXTURE_STAGES;++i) {
            if (entry.texture_stages[i].rgb.c.texture) {
                ss << "uniform sampler2D texture_" << i << ";\n";
            }
        }
        ss << "varying vec2 varTexCoord_0;\n";
        ss << "varying vec4 varColor;\n";
        
        ss << "void main(void) {\n";
        ss << "  vec4 clr = varColor;\n";
        size_t texCoordIdx = 0;
        //char buf[128];
        for (size_t i=0;i<MAX_TEXTURE_STAGES;++i) {
            if (entry.texture_stages[i].rgb.c.texture) {
                std::stringstream stage;
                if (entry.texture_stages[i].rgb.c.operation != TEX_OP_DISABLE) {
                    stage << "    vec4 tex = texture2D(texture_" << i << ",varTexCoord_"<<texCoordIdx<<");\n";
                    if (operation_equal(entry.texture_stages[i].alpha,entry.texture_stages[i].rgb)) {
                        append_tex_stage(stage,entry.texture_stages[i].rgb,"clr","clr","tex");
                    } else {
                        append_tex_stage(stage,entry.texture_stages[i].rgb,"clr.rgb","clr.rgb","tex.rgb");
                        append_tex_stage(stage,entry.texture_stages[i].alpha,"clr.a","clr.a","tex.a");
                    }
                }                
                ss << "  {\n" << stage.str() << "  }\n";
            }
        }
        ss << "  gl_FragColor = clr; \n";
        ss << "}\n";
        std::string s = ss.str();
        ConstInlinedData data((const Byte*)s.c_str(),UInt32(s.length()));
        FragmentShader* fs = m_render->CreateFragmentShader(&data);
        if (!fs) {
            LOG_ERROR("create fragment shader:\n");
            LOG_ERROR("failed with:\n" << s);
            return 0;
        } else {
            LOG_VERBOSE("created fragment shader:\n" << s);
        }
        return m_render->CreateShaderProgram(m_simple_v, fs);
    }
    
}

