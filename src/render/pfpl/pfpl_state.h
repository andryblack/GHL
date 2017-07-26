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


#ifndef PFPL_STATE_H_INCLUDED
#define PFPL_STATE_H_INCLUDED

#include "ghl_render.h"

namespace GHL {
    
    static const UInt32 STATE_MAX_TEXTURE_STAGES = 2;
    
    struct pfpl_state_data {
        struct texture_stage {
            union state {
                struct c_t {
					UInt32              texture:8;
                    TextureOperation    operation:8;
                    TextureArgument     arg_1:8;
                    TextureArgument     arg_2:8;
                } c;
                UInt32 all;
            };
            state rgb;
            state alpha;
            union tex_t {
                struct c_t {
                    TextureFilter       min_filter:8;
                    TextureFilter       mag_filter:8;
                    TextureFilter       mip_filter:8;
                    TextureWrapMode     wrap_u:4;
                    TextureWrapMode     wrap_v:4;
                } c;
                UInt32 all;
            } tex;
        };
        texture_stage   texture_stages[STATE_MAX_TEXTURE_STAGES];
    };
	GHL_STATIC_ASSERT(sizeof(pfpl_state_data::texture_stage::state::c_t) == sizeof(UInt32));
	GHL_STATIC_ASSERT(sizeof(pfpl_state_data::texture_stage::tex_t::c_t) == sizeof(UInt32));

    static inline bool operation_equal( const pfpl_state_data::texture_stage::state& a,
                                       const pfpl_state_data::texture_stage::state& b) {
        return (a.c.operation == b.c.operation) &&
            (a.c.arg_1 == b.c.arg_1) &&
            (a.c.arg_2 == b.c.arg_2);
    }
    static inline void normalize( pfpl_state_data& s ) {
        for (UInt32 i=0;i<STATE_MAX_TEXTURE_STAGES;++i) {
            s.texture_stages[i].alpha.c.texture = s.texture_stages[i].rgb.c.texture;
            if (!s.texture_stages[i].rgb.c.texture) {
                s.texture_stages[i].rgb.c.operation = TEX_OP_DISABLE;
                s.texture_stages[i].alpha.c.operation = TEX_OP_DISABLE;
                s.texture_stages[i].alpha.c.texture = false;
                s.texture_stages[i].tex.all = 0;
            }
            if (s.texture_stages[i].rgb.c.operation == TEX_OP_DISABLE) {
                s.texture_stages[i].rgb.c.arg_1 = TEX_ARG_TEXTURE;
                s.texture_stages[i].rgb.c.arg_2 = TEX_ARG_CURRENT;
            }
            if (s.texture_stages[i].alpha.c.operation == TEX_OP_DISABLE) {
                s.texture_stages[i].alpha.c.arg_1 = TEX_ARG_TEXTURE;
                s.texture_stages[i].alpha.c.arg_2 = TEX_ARG_CURRENT;
            }
        }
    }
    static inline bool compare( const pfpl_state_data& a, const pfpl_state_data& b ) {
        for (UInt32 i=0;i<STATE_MAX_TEXTURE_STAGES;++i) {
            if (a.texture_stages[i].rgb.all!=b.texture_stages[i].rgb.all)
                return false;
            if (a.texture_stages[i].alpha.all!=b.texture_stages[i].alpha.all)
                return false;
            if (a.texture_stages[i].tex.all!=b.texture_stages[i].tex.all)
                return false;
        }
        return true;
    }
}


#endif /* PFPL_STATE_H_INCLUDED */
