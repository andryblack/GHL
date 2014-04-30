//
//  glsl_generator.h
//  GHL
//
//  Created by Andrey Kunitsyn on 11/18/12.
//  Copyright (c) 2012 AndryBlack. All rights reserved.
//

#ifndef __GHL__agal_generator__
#define __GHL__agal_generator__

#include "../pfpl/pfpl_cache.h"
#include "ghl_render.h"
#include <AS3/AS3.h>
#include <Flash++.h>

namespace GHL {
    
    class RenderStage3d;
    
    class AGALGenerator : public pfpl_shader_generator_base {
    public:
        AGALGenerator();
        void init(GHL::RenderStage3d* render);
        virtual ShaderProgram* generate( const pfpl_state_data& entry, bool tex2 );
    private:
        GHL::RenderStage3d*    m_render;
        AS3::ui::flash::utils::ByteArray   m_simple_v;
    };
    
}
#endif /* defined(__GHL__agal_generator__) */
