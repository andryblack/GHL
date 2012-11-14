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
    
    struct pfpl_state_data {
        struct texture_stage {
            union state {
                struct {
                    bool                texture:8;
                    TextureOperation    operation:8;
                    TextureArgument     arg_1:8;
                    TextureArgument     arg_2:8;
                } c;
                UInt32 all;
            };
            state rgb;
            state alpha;
        };
        texture_stage   texture_stages[MAX_TEXTURE_STAGES];
        CompareFunc alpha_test_func: 7;
        bool    alpha_test: 1;
        float   alpha_test_ref;
    };
    static inline void normalize( pfpl_state_data& s ) {
        for (UInt32 i=0;i<MAX_TEXTURE_STAGES;++i) {
            if (s.texture_stages[i].rgb.c.operation == TEX_OP_DISABLE) {
                s.texture_stages[i].rgb.c.arg_1 = TEX_ARG_TEXTURE;
                s.texture_stages[i].rgb.c.arg_2 = TEX_ARG_CURRENT;
            }
            if (s.texture_stages[i].alpha.c.operation == TEX_OP_DISABLE) {
                s.texture_stages[i].alpha.c.arg_1 = TEX_ARG_TEXTURE;
                s.texture_stages[i].alpha.c.arg_2 = TEX_ARG_CURRENT;
            }
        }
        if (!s.alpha_test) {
            s.alpha_test_func = COMPARE_FUNC_ALWAYS;
            s.alpha_test_ref = 0.0f;
        }
    }
    static inline bool compare( const pfpl_state_data& a, const pfpl_state_data& b ) {
        for (UInt32 i=0;i<MAX_TEXTURE_STAGES;++i) {
            if (a.texture_stages[i].rgb.all!=b.texture_stages[i].rgb.all)
                return false;
            if (a.texture_stages[i].alpha.all!=b.texture_stages[i].alpha.all)
                return false;
        }
        if (a.alpha_test_func!=b.alpha_test_func)
            return false;
        if (a.alpha_test!=b.alpha_test)
            return false;
        if (a.alpha_test_ref!=b.alpha_test_ref)
            return false;
        return true;
    }
}


#endif /* PFPL_STATE_H_INCLUDED */
