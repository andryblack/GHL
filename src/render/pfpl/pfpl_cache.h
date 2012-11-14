/*
 GHL - Game Helpers Library
 Copyright (C)  Andrey Kunitsyn 2012
 
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 
 Andrey (AndryBlack) Kunitsyn
 blackicebox (at) gmail (dot) com
 */

#ifndef PFPL_CACHE_H_INCLUDED
#define PFPL_CACHE_H_INCLUDED

#include "pfpl_state.h"
#include <vector>

namespace GHL {
    
    struct pfpl_cache_entry {
        pfpl_state_data state;
        FragmentShader* shader;
        size_t  usage;
    };
    
    class pfpl_shader_generator_base {
    public:
        virtual FragmentShader* generate( const pfpl_state_data& entry ) = 0;
    };
    
    class pfpl_cache {
    public:
        explicit pfpl_cache();
        bool init(pfpl_shader_generator_base* generator);
        ~pfpl_cache();
        FragmentShader* get_shader( const pfpl_state_data& state );
        void clear();
    private:
        pfpl_shader_generator_base* m_generator;
        static const size_t max_cache_entries = 64;
        pfpl_cache_entry    m_entries[max_cache_entries];
        size_t  m_entries_amount;
    };
    
}

#endif /* PFPL_CACHE_H_INCLUDED */
