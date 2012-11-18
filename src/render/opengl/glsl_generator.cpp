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
    
    const char* MODULE = "GLSLGenerator";
    
    GLSLGenerator::GLSLGenerator() : m_render(0), m_simple_v(0) {
        
    }
    
    void GLSLGenerator::init(GHL::Render *render) {
        m_render = render;
    }
    
    static const char* simple_v =
    "void main(void) {\n"
    " gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;\n"
    " gl_TexCoord[0] = gl_MultiTexCoord0;\n"
    " gl_FrontColor = gl_Color;\n"
    " gl_BackColor = gl_Color;\n"
    "}\n";
    
    
    ShaderProgram* GLSLGenerator::generate(const pfpl_state_data& entry, bool tex2 ) {
        if (!m_simple_v) {
            ConstInlinedData data((const Byte*)simple_v,strlen(simple_v));
            m_simple_v = m_render->CreateVertexShader(&data);
            if (!m_simple_v) {
                LOG_ERROR("create vertex shader");
                return 0;
            }
        }
        std::stringstream ss;
        for (size_t i=0;i<MAX_TEXTURE_STAGES;++i) {
            if (entry.texture_stages[i].rgb.c.texture) {
                ss << "uniform sampler2D texture_" << i << "\n;";
            }
        }
        ss << "void main(void) {\n";
        ss << "vec4 clr = gl_Color;\n";
        for (size_t i=0;i<MAX_TEXTURE_STAGES;++i) {
            if (entry.texture_stages[i].rgb.c.texture) {
                ss << "clr = clr * texture2D(texture_" << i <<",gl_TexCoord["<<i<<"].st);\n";
            }
        }
        ss << "gl_FragColor = clr; \n";
        ss << "}\n";
        std::string s = ss.str();
        ConstInlinedData data((const Byte*)s.c_str(),s.length());
        FragmentShader* fs = m_render->CreateFragmentShader(&data);
        if (!fs) {
            LOG_ERROR("create fragment shader");
            return 0;
        }
        return m_render->CreateShaderProgram(m_simple_v, fs);
    }
    
}

