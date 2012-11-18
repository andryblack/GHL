//
//  pfpl_cache.cpp
//  GHL
//
//  Created by Andrey Kunitsyn on 11/13/12.
//  Copyright (c) 2012 AndryBlack. All rights reserved.
//

#include "pfpl_cache.h"

namespace GHL {
    
    pfpl_cache::pfpl_cache() : m_generator(0),m_entries_amount(0) {
        
    }
    
    pfpl_cache::~pfpl_cache() {
        clear();
    }
    
    bool pfpl_cache::init(pfpl_shader_generator_base* generator) {
        if (!generator)
            return false;
        m_generator = generator;
        clear();
        return true;
    }
    
    void pfpl_cache::clear() {
        for (size_t i=0;i<m_entries_amount;++i) {
            if (m_entries[i].shader) {
                m_entries[i].shader->Release();
                m_entries[i].shader = 0;
            }
        }
        m_entries_amount = 0;
    }
    
    ShaderProgram* pfpl_cache::get_shader(const pfpl_state_data &state,bool tex2) {
        pfpl_state_data copy(state);
        normalize(copy);
        for (size_t i=0;i<m_entries_amount;++i) {
            if (compare(copy, m_entries[i].state) && m_entries[i].tex2==tex2) {
                return m_entries[i].shader;
            }
        }
        if (!m_generator)
            return 0;
        size_t idx = 0;
        if (m_entries_amount<max_cache_entries) {
            idx = m_entries_amount;
            m_entries[idx].shader = 0;
            ++m_entries_amount;
        } else {
            for (size_t i=0;i<m_entries_amount;++i) {
                if (m_entries[i].usage < m_entries[idx].usage) {
                    idx = i;
                }
            }
        }
        if (m_entries[idx].shader) {
            m_entries[idx].shader->Release();
        }
        m_entries[idx].state = copy;
        m_entries[idx].shader = m_generator->generate(copy,tex2);
        m_entries[idx].usage = 0;
        m_entries[idx].tex2 = tex2;
        return m_entries[idx].shader;
    }
    
}