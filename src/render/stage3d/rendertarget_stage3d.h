/*
 *  rendertarget_stage3d.h
 *  TurboSquirrel
 *
 *  Created by Андрей Куницын on 08.03.10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef RENDERTARGET_STAGE3D_H
#define RENDERTARGET_STAGE3D_H

#include "../rendertarget_impl.h"
#include "render_stage3d.h"
#include "texture_stage3d.h"

#include <AS3/AS3.h>
#include <Flash++.h>

namespace GHL {
    
    class RenderStage3d;
    class TextureStage3d;
    
	class RenderTargetStage3d : public RenderTargetImpl {
	private:
        TextureStage3d* m_texture;
        bool    m_have_depth;
    public:
        ~RenderTargetStage3d();
    
        RenderTargetStage3d(TextureStage3d* texture,RenderStage3d* parent,bool have_depth);
        
        const AS3::ui::flash::display3D::textures::Texture& texture() const { return m_texture->texture(); }
        
        virtual void BeginScene( RenderImpl* render );
		virtual void EndScene( RenderImpl* render );
        
        /// width
		virtual UInt32 GHL_CALL GetWidth() const { return m_texture->GetWidth(); }
		/// height
		virtual UInt32 GHL_CALL GetHeight() const { return m_texture->GetHeight(); }
		/// have depth
		virtual	bool GHL_CALL HaveDepth() const { return m_have_depth; }
		/// get texture
		virtual Texture* GHL_CALL GetTexture() const { return m_texture; }
		/// read pixels
		virtual void GHL_CALL GetPixels(UInt32 x,UInt32 y,UInt32 w,UInt32 h,Byte* data);

	};
}

#endif /*RENDERTARGET_STAGE3D_H*/
