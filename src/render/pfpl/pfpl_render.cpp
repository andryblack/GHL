//
//  prpl_render.cpp
//  GHL
//
//  Created by Andrey Kunitsyn on 11/13/12.
//  Copyright (c) 2012 AndryBlack. All rights reserved.
//

#include "pfpl_render.h"

namespace GHL {
    
    pfpl_render::pfpl_render() : m_extern(0),m_prev(0) {
        
    }
    
    void pfpl_render::set_shader( const ShaderProgram* prg ) {
        m_extern = prg;
        m_prev = 0;
    }
    
    ShaderProgram* pfpl_render::get_shader(const pfpl_state_data& c,bool tex2) {
        if (m_extern) return 0;
        ShaderProgram* prg = m_cache.get_shader(c, tex2);
        if (prg==m_prev) {
            return 0;
        }
        m_prev = prg;
        return prg;
    }
    
    void pfpl_render::init(pfpl_shader_generator_base* g) {
        m_cache.init(g);
    }
    
    void pfpl_render::done() {
        m_cache.clear();
    }
}