//
//  render_opengl2.cpp
//  GHL
//
//  Created by Andrey Kunitsyn on 11/18/12.
//  Copyright (c) 2012 AndryBlack. All rights reserved.
//

#include "render_opengl2.h"
#include "../../ghl_log_impl.h"
#include "ghl_shader.h"

namespace GHL {

    static const char* MODULE = "RENDER:OpenGL";
    
    RenderOpenGL2::RenderOpenGL2(UInt32 w,UInt32 h) : RenderOpenGLBase(w,h) {
        
    }
    
    bool RenderOpenGL2::RenderInit() {
        LOG_INFO("RenderOpenGL2::RenderInit");
        
        if (!RenderOpenGLBase::RenderInit())
            return false;
        if (!gl.sdrapi.valid)
            return false;
        m_generator.init(this);
        m_shaders_render.init(&m_generator);
        return true;
    }
    
    void RenderOpenGL2::RenderDone() {
        m_shaders_render.done();
        RenderOpenGLBase::RenderDone();
    }
    
    void RenderOpenGL2::ResetRenderState() {
        RenderOpenGLBase::ResetRenderState();
        
    }
    
    void GHL_CALL RenderOpenGL2::SetTexture(const Texture* texture, UInt32 stage ) {
        RenderOpenGLBase::SetTexture(texture, stage);
        if (texture) {
            m_crnt_state.texture_stages[stage].rgb.c.texture = true;
            m_crnt_state.texture_stages[stage].alpha.c.texture = HaveAlpha(texture);
        } else {
            m_crnt_state.texture_stages[stage].rgb.c.texture = false;
            m_crnt_state.texture_stages[stage].alpha.c.texture = false;
        }
    }
    
    /// set texture stage color operation
    void GHL_CALL RenderOpenGL2::SetupTextureStageColorOp(TextureOperation op,TextureArgument arg1,TextureArgument arg2,UInt32 stage ) {
        m_crnt_state.texture_stages[stage].rgb.c.operation = op;
        m_crnt_state.texture_stages[stage].rgb.c.arg_1 = arg1;
        m_crnt_state.texture_stages[stage].rgb.c.arg_2 = arg2;
    }
    
    /// set texture stage alpha operation
    void GHL_CALL RenderOpenGL2::SetupTextureStageAlphaOp(TextureOperation op,TextureArgument arg1,TextureArgument arg2,UInt32 stage ) {
        m_crnt_state.texture_stages[stage].alpha.c.operation = op;
        m_crnt_state.texture_stages[stage].alpha.c.arg_1 = arg1;
        m_crnt_state.texture_stages[stage].alpha.c.arg_2 = arg2;
    }
    
    void GHL_CALL RenderOpenGL2::SetShader(const ShaderProgram* shader)  {
        RenderOpenGLBase::SetShader(shader);
        m_shaders_render.set_shader(shader);
    }
    
    void GHL_CALL RenderOpenGL2::DrawPrimitives(PrimitiveType type,UInt32 v_amount,UInt32 i_begin,UInt32 amount) {
    //    ShaderProgram* prg = m_shaders_render.get_shader(m_crnt_state, type==)
    }
    
    void GHL_CALL RenderOpenGL2::DrawPrimitivesFromMemory(PrimitiveType type,VertexType v_type,const void* vertices,UInt32 v_amount,const UInt16* indexes,UInt32 prim_amoun) {
        ShaderProgram* prg = m_shaders_render.get_shader(m_crnt_state, v_type==VERTEX_TYPE_2_TEX);
        if (prg) {
            RenderOpenGLBase::SetShader(prg);
            for (size_t i=0;i<MAX_TEXTURE_STAGES;++i) {
                if (m_crnt_state.texture_stages[i].rgb.c.texture) {
                    char uf[64];
                    ::snprintf(uf, 64, "texture_%d",int(i));
                    ShaderUniform* uniform = prg->GetUniform(uf);
                    if (uniform) {
                        uniform->SetValueInt(i);
                    }
                }
            }

        }
        RenderOpenGLBase::DrawPrimitivesFromMemory(type, v_type, vertices, v_amount, indexes, prim_amoun);
    }

}

GHL_API GHL::RenderImpl* GHL_CALL GHL_CreateRenderOpenGL(GHL::UInt32 w,GHL::UInt32 h) {
    GHL::RenderOpenGLBase* render = new GHL::RenderOpenGL2(w,h);
	if (!render->RenderInit()) {
        render->RenderDone();
		delete render;
		render = 0;
	} else {
        return render;
    }
	render = new GHL::RenderOpenGL(w,h);
	if (!render->RenderInit()) {
		render->RenderDone();
		delete render;
		render = 0;
	}
	return render;
}

GHL_API void GHL_DestroyRenderOpenGL(GHL::RenderImpl* render_) {
	GHL::RenderOpenGLBase* render = reinterpret_cast<GHL::RenderOpenGLBase*>(render_);
	if (render) {
		render->RenderDone();
		delete render;
	}
}
