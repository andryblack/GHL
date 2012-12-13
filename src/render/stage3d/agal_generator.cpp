//
//  glsl_generator.cpp
//  GHL
//
//  Created by Andrey Kunitsyn on 11/18/12.
//  Copyright (c) 2012 AndryBlack. All rights reserved.
//

#include "agal_generator.h"
#include "agal_assembler.h"
#include "../../ghl_data_impl.h"
#include "../../ghl_log_impl.h"

namespace GHL {
    
    const char* MODULE = "AGALGenerator";
    
    AGALGenerator::AGALGenerator() : m_render(0), m_simple_v(0) {
        
    }
    
    void AGALGenerator::init(GHL::Render *render) {
        m_render = render;
    }
    
    
    
    ShaderProgram* AGALGenerator::generate(const pfpl_state_data& entry, bool tex2 ) {
        if (!m_simple_v) {
            AGALCodeGen codegen(AGALCodeGen::VERTEX_PROGRAM);
            codegen.add(AGAL::MOV,AGAL::I[0],AGAL::VA[1]);
            codegen.add(AGAL::MOV,AGAL::I[1],AGAL::VA[2]);
            codegen.add(AGAL::M44,AGAL::VO,AGAL::VA[0],AGAL::VC[0]);
            codegen.dump();
            ConstInlinedData data(codegen.data(),codegen.size());
            m_simple_v = m_render->CreateVertexShader(&data);
            if (!m_simple_v) {
                LOG_ERROR("create vertex shader");
                return 0;
            }
        }
//        std::stringstream ss;
//        for (size_t i=0;i<MAX_TEXTURE_STAGES;++i) {
//            if (entry.texture_stages[i].rgb.c.texture) {
//                ss << "uniform sampler2D texture_" << i << "\n;";
//            }
//        }
//        ss << "void main(void) {\n";
//        ss << "vec4 clr = gl_Color;\n";
//        for (size_t i=0;i<MAX_TEXTURE_STAGES;++i) {
//            if (entry.texture_stages[i].rgb.c.texture) {
//                ss << "clr = clr * texture2D(texture_" << i <<",gl_TexCoord["<<i<<"].st);\n";
//            }
//        }
//        ss << "gl_FragColor = clr; \n";
//        ss << "}\n";
//        std::string s = ss.str();
//        ConstInlinedData data((const Byte*)s.c_str(),s.length());
//        FragmentShader* fs = m_render->CreateFragmentShader(&data);
//        if (!fs) {
//            LOG_ERROR("create fragment shader");
//            return 0;
//        }
//
        FragmentShader* fs = 0;
        {
            AGALCodeGen codegen(AGALCodeGen::FRAGMENT_PROGRAM);
            codegen.add(AGAL::MOV,AGAL::FT[0],AGAL::I[0]);
            codegen.add(AGAL::TEX,AGAL::FT[1],AGAL::I[1],AGAL::FS[0]);
            codegen.add(AGAL::MUL,AGAL::FT[0],AGAL::FT[0],AGAL::FT[1]);
            codegen.add(AGAL::MOV,AGAL::FO,AGAL::FT[0]);
            codegen.dump();
            ConstInlinedData data(codegen.data(),codegen.size());
            fs = m_render->CreateFragmentShader(&data);
        }
        if (!fs) {
            LOG_ERROR("create fragment shader");
            return 0;
        }
        return m_render->CreateShaderProgram(m_simple_v, fs);
    }
    
}

