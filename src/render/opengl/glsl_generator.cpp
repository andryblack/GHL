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
    
    
    ShaderProgram* GLSLGenerator::generate(const pfpl_state_data& entry, bool tex2 ) {
        if (!m_simple_v) {
            ConstInlinedData data((const Byte*)simple_v,strlen(simple_v));
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
        ss << "  vec3 clr = varColor.rgb;\n";
        ss << "  float alpha = varColor.a;\n";
        size_t texCoordIdx = 0;
        //char buf[128];
        for (size_t i=0;i<MAX_TEXTURE_STAGES;++i) {
            if (entry.texture_stages[i].rgb.c.texture) {
                std::stringstream stage;
                stage << "    vec4 tex = texture2D(texture_" << i << ",varTexCoord_"<<texCoordIdx<<");\n";
                stage << "    vec3 tclr = tex.rgb;\n";
                if (entry.texture_stages[i].alpha.c.texture) {
                    stage << "    float talpha = tex.a;\n";
                } else {
                    stage << "    float talpha = 1.0;\n";
                }
                if (entry.texture_stages[i].rgb.c.operation != TEX_OP_DISABLE) {
                    const char* arg1 = "clr";
                    const char* arg2 = "tclr";
                    const char* op = "*";
                
                    if (entry.texture_stages[i].rgb.c.arg_1==TEX_ARG_TEXTURE) {
                        arg1 = "tclr";
                    } else if (entry.texture_stages[i].rgb.c.arg_1==TEX_ARG_TEXTURE_INV){
                        arg1 = "vec3(1.0-tclr.r,1.0-tclr.g,1.0-tclr.b)";
                    }
                    if (entry.texture_stages[i].rgb.c.arg_2==TEX_ARG_CURRENT) {
                        arg2 = "clr";
                    } else if (entry.texture_stages[i].rgb.c.arg_2==TEX_ARG_TEXTURE_INV) {
                        arg2 = "vec3(1.0-tclr.r,1.0-tclr.g,1.0-tclr.b)";
                    }
                    
                    if (entry.texture_stages[i].rgb.c.operation==TEX_OP_ADD) {
                        op = "+";
                    } else if (entry.texture_stages[i].rgb.c.operation==TEX_OP_SELECT_1) {
                        op = "";
                        arg2= "";
                    } else if (entry.texture_stages[i].rgb.c.operation==TEX_OP_SELECT_2) {
                        op = "";
                        arg1 = "";
                    }
                    if (entry.texture_stages[i].rgb.c.operation==TEX_OP_INT_CURRENT_ALPHA) {
                        stage << "    clr = mix(" << arg1 << "," << arg2 << ",alpha);\n";
                    } else {
                        stage << "    clr = " << arg1 << op << arg2 << ";\n";
                    }
                }
                if (entry.texture_stages[i].alpha.c.operation != TEX_OP_DISABLE) {
                    const char* arg1 = "alpha";
                    const char* arg2 = "talpha";
                    const char* op = "*";
                    if (entry.texture_stages[i].alpha.c.arg_1 == TEX_ARG_TEXTURE) {
                        arg1 = "talpha";
                    }
                    if (entry.texture_stages[i].alpha.c.arg_2 == TEX_ARG_CURRENT) {
                        arg2 = "alpha";
                    }
                    if (entry.texture_stages[i].alpha.c.operation==TEX_OP_ADD) {
                        op = "+";
                    } else if (entry.texture_stages[i].alpha.c.operation==TEX_OP_SELECT_1) {
                        op = "";
                        arg2= "";
                        if (entry.texture_stages[i].alpha.c.arg_1 == TEX_ARG_CURRENT) {
                            arg1 = 0;
                        }
                    } else if (entry.texture_stages[i].alpha.c.operation==TEX_OP_SELECT_2) {
                        op = "";
                        arg1 = "";
                        if (entry.texture_stages[i].alpha.c.arg_2 == TEX_ARG_CURRENT) {
                            arg1 = 0;
                        }
                    }
                    if (arg1) {
                        stage << "    alpha = " << arg1 << op << arg2 << ";\n";
                    }
                }
                ss << "  {\n" << stage.str() << "  }\n";
            }
        }
        ss << "  gl_FragColor = vec4(clr,alpha); \n";
        ss << "}\n";
        std::string s = ss.str();
        ConstInlinedData data((const Byte*)s.c_str(),s.length());
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

