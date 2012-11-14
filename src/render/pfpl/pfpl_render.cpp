//
//  prpl_render.cpp
//  GHL
//
//  Created by Andrey Kunitsyn on 11/13/12.
//  Copyright (c) 2012 AndryBlack. All rights reserved.
//

#include "pfpl_render.h"

namespace GHL {
    
    PFPLRenderImpl::PFPLRenderImpl(UInt32 w, UInt32 h) : RenderImpl(w,h) {
        
    }
    
    bool PFPLRenderImpl::RenderInit() {
        if (!m_shaders_cache.init(get_generator()))
            return false;
        return true;
    }
    
    void PFPLRenderImpl::RenderDone() {
        m_shaders_cache.clear();
    }
    
    
    void GHL_CALL PFPLRenderImpl::SetTexture(const Texture* texture, UInt32 stage ) {
        RenderImpl::SetTexture(texture, stage);
        if (texture) {
            m_crnt_state.texture_stages[stage].rgb.c.texture = true;
            m_crnt_state.texture_stages[stage].alpha.c.texture = HaveAlpha(texture);
        } else {
            m_crnt_state.texture_stages[stage].rgb.c.texture = false;
            m_crnt_state.texture_stages[stage].alpha.c.texture = false;
        }
    }
    
    /// set texture stage color operation
    void GHL_CALL PFPLRenderImpl::SetupTextureStageColorOp(TextureOperation op,TextureArgument arg1,TextureArgument arg2,UInt32 stage ) {
        m_crnt_state.texture_stages[stage].rgb.c.operation = op;
        m_crnt_state.texture_stages[stage].rgb.c.arg_1 = arg1;
        m_crnt_state.texture_stages[stage].rgb.c.arg_2 = arg2;
    }
    /// set texture stage alpha operation
    void GHL_CALL PFPLRenderImpl::SetupTextureStageAlphaOp(TextureOperation op,TextureArgument arg1,TextureArgument arg2,UInt32 stage ) {
        m_crnt_state.texture_stages[stage].alpha.c.operation = op;
        m_crnt_state.texture_stages[stage].alpha.c.arg_1 = arg1;
        m_crnt_state.texture_stages[stage].alpha.c.arg_2 = arg2;
    }
    
    void GHL_CALL PFPLRenderImpl::SetShader(const ShaderProgram* shader) {
        RenderImpl::SetShader(shader);
    }
    
    void PFPLRenderImpl::ApplyShader() {
        FragmentShader* fsh = m_shaders_cache.get_shader(m_crnt_state);
        if (fsh) {
            
        }
    }
}