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


#ifndef PFPL_RENDER_H_INCLUDED
#define PFPL_RENDER_H_INCLUDED

#include "../render_impl.h"
#include "pfpl_cache.h"

namespace GHL {
    
    class pfpl_render {
    public:
        pfpl_render();
        void init(pfpl_shader_generator_base* g);
        void done();
        void set_shader( const ShaderProgram* prg );
        ShaderProgram* get_shader(const pfpl_state_data& c,bool tex2);
    private:
        const ShaderProgram*    m_extern;
        const ShaderProgram*    m_prev;
        pfpl_cache  m_cache;
    };
}

#endif /* PFPL_RENDER_H_INCLUDED */
