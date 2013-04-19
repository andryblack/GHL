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
    
    void append_texture_operation(AGALCodeGen& codegen,
                                  const pfpl_state_data::texture_stage::state& state,
                                  const AGAL::Register& dst,
                                  const AGAL::Register& src,
                                  const AGAL::Register& tex) {
        if (state.c.operation == TEX_OP_DISABLE) {
            return;
        }
        
        const AGAL::Register* op1 = &src;
        if (state.c.arg_1 == TEX_ARG_TEXTURE) {
            op1 = &tex;
        } else if (state.c.arg_1 == TEX_ARG_CURRENT_INV) {
            LOG_ERROR("unimplemented argument");
            return;
        } else if (state.c.arg_1 == TEX_ARG_TEXTURE_INV) {
            LOG_ERROR("unimplemented argument");
            return;
        }
        const AGAL::Register* op2 = &tex;
        if (state.c.arg_2 == TEX_ARG_CURRENT) {
            op2 = &src;
        } else if (state.c.arg_2 == TEX_ARG_CURRENT_INV) {
            LOG_ERROR("unimplemented argument");
            return;
        } else if (state.c.arg_2 == TEX_ARG_TEXTURE_INV) {
            LOG_ERROR("unimplemented argument");
            return;
        }
        
        
        if (state.c.operation == TEX_OP_SELECT_1) {
            if (state.c.arg_1!=TEX_ARG_CURRENT) {
                codegen.add(AGAL::MOV,dst,*op1);
            }
        } else if (state.c.operation == TEX_OP_SELECT_2) {
            if (state.c.arg_2!=TEX_ARG_CURRENT) {
                codegen.add(AGAL::MOV,dst,*op2);
            }
        } else if (state.c.operation == TEX_OP_MODULATE) {
            codegen.add(AGAL::MUL,dst,*op1,*op2);
        } else if (state.c.operation == TEX_OP_ADD) {
            codegen.add(AGAL::ADD,dst,*op1,*op2);
        } else if (state.c.operation == TEX_OP_INT_TEXTURE_ALPHA) {
            codegen.add(AGAL::MUL,AGAL::FT[2],*op2,tex.a());
            codegen.add(AGAL::MUL,AGAL::FT[3],*op1,tex.a());
            codegen.add(AGAL::ADD,dst,AGAL::FT[2],AGAL::FT[3]);
        } else if (state.c.operation == TEX_OP_INT_CURRENT_ALPHA) {
            codegen.add(AGAL::MUL,AGAL::FT[2],*op2,src.a());
            codegen.add(AGAL::MUL,AGAL::FT[3],*op1,src.a());
            codegen.add(AGAL::ADD,dst,AGAL::FT[2],AGAL::FT[3]);
        }
        
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

        FragmentShader* fs = 0;
        {
            AGALCodeGen codegen(AGALCodeGen::FRAGMENT_PROGRAM);
            codegen.add(AGAL::MOV,AGAL::FT[0],AGAL::I[0]);      /// FT0 - clr
            for (UInt32 i=0;i<MAX_TEXTURE_STAGES;++i) {
                if (entry.texture_stages[i].rgb.c.texture) {
                    AGAL::Sampler s = AGAL::FS[i];
                    if (entry.texture_stages[i].tex.c.wrap_u == TEX_WRAP_REPEAT) {
                        s.repeat();
                    }
                    if (entry.texture_stages[i].tex.c.min_filter == TEX_FILTER_LINEAR) {
                        s.linear();
                    }
                    codegen.add(AGAL::TEX,AGAL::FT[1],AGAL::I[1],s);    /// FT1 - tex
                    if (operation_equal(entry.texture_stages[i].alpha,entry.texture_stages[i].rgb)) {
                        append_texture_operation(codegen,entry.texture_stages[i].rgb,AGAL::FT[0],AGAL::FT[0],AGAL::FT[1]);
                    } else {
                        append_texture_operation(codegen,entry.texture_stages[i].rgb,AGAL::FT[0].rgb(),AGAL::FT[0].rgb(),AGAL::FT[1].rgb());
                        append_texture_operation(codegen,entry.texture_stages[i].alpha,AGAL::FT[0].a(),AGAL::FT[0].a(),AGAL::FT[1].a());
                    }
               }
            }
            
            
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

