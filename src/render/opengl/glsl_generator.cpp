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
    
    GLSLGenerator::GLSLGenerator() : m_render(0), m_simple_v(0),m_simple_v2(0) {
        
    }
    
    void GLSLGenerator::init(GHL::Render *render) {
        m_render = render;
    }
    
    static const char* simple_v =
    "attribute vec3 vPosition;\n"
    "attribute vec2 vTexCoord;\n"
    "attribute vec4 vColor;\n"
    "uniform mat4 mProjectionModelView;\n"
    "varying vec2 varTexCoord_0;\n"
    "varying vec4 varColor;\n"
    "void main(void) {\n"
    " gl_Position = mProjectionModelView * vec4(vPosition,1.0);\n"
    " varTexCoord_0 = vTexCoord;\n"
    " varColor = vColor;\n"
    "}\n";
    
    static const char* simple_v2 =
    "attribute vec3 vPosition;\n"
    "attribute vec2 vTexCoord;\n"
    "attribute vec2 vTex2Coord;\n"
    "attribute vec4 vColor;\n"
    "uniform mat4 mProjectionModelView;\n"
    "varying vec2 varTexCoord_0;\n"
    "varying vec2 varTexCoord_1;\n"
    "varying vec4 varColor;\n"
    "void main(void) {\n"
    " gl_Position = mProjectionModelView * vec4(vPosition,1.0);\n"
    " varTexCoord_0 = vTexCoord;\n"
    " varTexCoord_1 = vTex2Coord;\n"
    " varColor = vColor;\n"
    "}\n";
    
    static void append_tex_stage( std::stringstream& ss,
                                 const pfpl_state_data::texture_stage::state& state,
                                 const char* dst, const char* src, const char* tex,
                                 const char* fetch,const char* fetch_a) {
        if (state.c.operation == TEX_OP_DISABLE)
            return;
        const char* op1 = src;
        const char* op1_fetch = fetch;
        if (state.c.arg_1 == TEX_ARG_TEXTURE) {
            op1  = tex;
        } if (state.c.arg_1 == TEX_ARG_TEXTURE_ALPHA) {
            op1  = tex;
            op1_fetch = fetch_a;
        } else if (state.c.arg_1 == TEX_ARG_TEXTURE_INV) {
            LOG_ERROR("unimplemented texture stage argument");
            return;
        } else if (state.c.arg_1 == TEX_ARG_CURRENT_INV) {
            LOG_ERROR("unimplemented texture stage argument");
            return;
        }
        const char* op2 = tex;
        const char* op2_fetch = fetch;
        if (state.c.arg_2 == TEX_ARG_CURRENT) {
            op2  = src;
        } if (state.c.arg_2 == TEX_ARG_CURRENT_ALPHA) {
            op2  = src;
            op2_fetch = fetch_a;
        } else if (state.c.arg_2 == TEX_ARG_TEXTURE_INV) {
            LOG_ERROR("unimplemented texture stage argument");
            return;
        } else if (state.c.arg_2 == TEX_ARG_CURRENT_INV) {
            LOG_ERROR("unimplemented texture stage argument");
            return;
        }
        if (state.c.operation == TEX_OP_SELECT_1) {
            if (state.c.arg_1!=TEX_ARG_CURRENT) {
                ss << "    "<<dst<<fetch<<"="<<op1<<op1_fetch<<";\n";
            }
        } else if (state.c.operation == TEX_OP_SELECT_2) {
            if (state.c.arg_2!=TEX_ARG_CURRENT) {
                ss << "    "<<dst<<fetch<<"="<<op2<<op2_fetch<<";\n";
            }
        } else if (state.c.operation == TEX_OP_MODULATE) {
            ss << "    "<<dst<<fetch<<"="<<op1<<op1_fetch<<"*"<<op2<<op2_fetch<<";\n";
        } else if (state.c.operation == TEX_OP_ADD) {
            ss << "    "<<dst<<fetch<<"="<<op1<<op1_fetch<<"+"<<op2<<op2_fetch<<";\n";
        } else if (state.c.operation == TEX_OP_INT_TEXTURE_ALPHA) {
            ss << "    "<<dst<<fetch<<"=mix("<<op1<<op2_fetch<<","<<op2<<op2_fetch<<",tex.a);\n";
        } else if (state.c.operation == TEX_OP_INT_CURRENT_ALPHA) {
            ss << "    "<<dst<<fetch<<"=mix("<<op1<<op1_fetch<<","<<op2<<op2_fetch<<",clr.a);\n";
        }

    }
    
    ShaderProgram* GLSLGenerator::generate(const pfpl_state_data& entry, bool tex2 ) {
        
        if ((!tex2 && !m_simple_v) || (tex2 && !m_simple_v2)) {
            ConstInlinedData data((const Byte*)(tex2 ? simple_v2 : simple_v),UInt32(strlen((tex2 ? simple_v2 : simple_v))));
            (tex2 ? m_simple_v2 : m_simple_v) = m_render->CreateVertexShader(&data);
            if (!(tex2 ? simple_v2 : simple_v)) {
                LOG_ERROR("create vertex shader");
                return 0;
            } else {
                LOG_VERBOSE("created vertex shader:\n" << (tex2 ? simple_v2 : simple_v));
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
        if (tex2) {
            ss << "varying vec2 varTexCoord_1;\n";
        }
        ss << "varying vec4 varColor;\n";
        
        ss << "void main(void) {\n";
        ss << "  vec4 clr = varColor;\n";
        size_t texCoordIdx = 0;
        //char buf[128];
        for (size_t i=0;i<MAX_TEXTURE_STAGES;++i) {
            texCoordIdx = 0;
            if (tex2 && i==1)
                texCoordIdx = 1;
            if (entry.texture_stages[i].rgb.c.texture) {
                std::stringstream stage;
                if (entry.texture_stages[i].rgb.c.operation != TEX_OP_DISABLE) {
                    stage << "    vec4 tex = texture2D(texture_" << i << ",varTexCoord_"<<texCoordIdx<<");\n";
                    if (operation_equal(entry.texture_stages[i].alpha,entry.texture_stages[i].rgb)) {
                        append_tex_stage(stage,entry.texture_stages[i].rgb,"clr","clr","tex","",".aaaa");
                    } else {
                        append_tex_stage(stage,entry.texture_stages[i].rgb,"clr","clr","tex",".rgb",".aaa");
                        append_tex_stage(stage,entry.texture_stages[i].alpha,"clr","clr","tex",".a",".a");
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
        return m_render->CreateShaderProgram(tex2 ? m_simple_v2 : m_simple_v, fs);
    }
    
}

