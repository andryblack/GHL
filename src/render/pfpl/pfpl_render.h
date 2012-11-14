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
    
    class PFPLRenderImpl : public RenderImpl {
    public:
        PFPLRenderImpl(UInt32 w, UInt32 h);
        virtual bool RenderInit();
		virtual void RenderDone();
        
        
        /// render impl
        /// set current texture
		virtual void GHL_CALL SetTexture(const Texture* texture, UInt32 stage = 0) ;
		/// set texture stage color operation
		virtual void GHL_CALL SetupTextureStageColorOp(TextureOperation op,TextureArgument arg1,TextureArgument arg2,UInt32 stage = 0) ;
		/// set texture stage alpha operation
		virtual void GHL_CALL SetupTextureStageAlphaOp(TextureOperation op,TextureArgument arg1,TextureArgument arg2,UInt32 stage = 0) ;
		
		virtual void GHL_CALL SetShader(const ShaderProgram* shader);
		/////
    
    protected:
        void ApplyShader();
        virtual pfpl_shader_generator_base* get_generator() = 0;
    private:
        pfpl_cache          m_shaders_cache;
        pfpl_state_data     m_crnt_state;
    };
    
}

#endif /* PFPL_RENDER_H_INCLUDED */
