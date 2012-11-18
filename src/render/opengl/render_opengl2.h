//
//  render_opengl2.h
//  GHL
//
//  Created by Andrey Kunitsyn on 11/18/12.
//  Copyright (c) 2012 AndryBlack. All rights reserved.
//

#ifndef __GHL__render_opengl2__
#define __GHL__render_opengl2__

#include "render_opengl.h"
#include "../pfpl/pfpl_render.h"
#include "glsl_generator.h"

namespace GHL {
    
    
    class RenderOpenGL2 : public RenderOpenGLBase {
    public:
        RenderOpenGL2(UInt32 w,UInt32 h);
        
        bool RenderInit();
        void RenderDone();
        
        
        virtual void ResetRenderState();
        
        /// set current texture
		virtual void GHL_CALL SetTexture(const Texture* texture, UInt32 stage );
        
        /// set texture stage color operation
		virtual void GHL_CALL SetupTextureStageColorOp(TextureOperation op,TextureArgument arg1,TextureArgument arg2,UInt32 stage );
		/// set texture stage alpha operation
		virtual void GHL_CALL SetupTextureStageAlphaOp(TextureOperation op,TextureArgument arg1,TextureArgument arg2,UInt32 stage );
        
        virtual void GHL_CALL SetShader(const ShaderProgram* shader) ;
        
        virtual void GHL_CALL DrawPrimitives(PrimitiveType type,UInt32 v_amount,UInt32 i_begin,UInt32 amount);
		
		virtual void GHL_CALL DrawPrimitivesFromMemory(PrimitiveType type,VertexType v_type,const void* vertices,UInt32 v_amount,const UInt16* indexes,UInt32 prim_amoun);
        
    private:
        pfpl_render         m_shaders_render;
        pfpl_state_data     m_crnt_state;
        GLSLGenerator       m_generator;
    };
    
}

#endif /* defined(__GHL__render_opengl2__) */
