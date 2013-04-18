//
//  glsl_generator.h
//  GHL
//
//  Created by Andrey Kunitsyn on 11/18/12.
//  Copyright (c) 2012 AndryBlack. All rights reserved.
//

#ifndef __GHL__glsl_generator__
#define __GHL__glsl_generator__

#include "../pfpl/pfpl_cache.h"
#include "ghl_render.h"
#include <string>

namespace GHL {
    
    class GLSLGenerator : public pfpl_shader_generator_base {
    public:
        GLSLGenerator();
        void init(GHL::Render* render);
        virtual ShaderProgram* generate( const pfpl_state_data& entry, bool tex2 );
        
        void set_fshader_header( const char* v) { m_fshader_header = v; }
    protected:
        
    private:
        GHL::Render*    m_render;
        VertexShader*   m_simple_v;
        std::string     m_fshader_header;
    };
    
}
#endif /* defined(__GHL__glsl_generator__) */
