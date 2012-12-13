/*
 *  texture_stage3d.h
 *  TurboSquirrel
 *
 *  Created by Андрей Куницын on 08.03.10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef TEXTURE_STAGE3D_H
#define TEXTURE_STAGE3D_H

#include "../texture_impl.h"
#include "render_stage3d.h"

#include <AS3/AS3.h>
#include <Flash++.h>

namespace GHL {
    
    class RenderStage3d;
    
	class TextureStage3d : public TextureImpl {
	private:
        AS3::ui::flash::display3D::textures::Texture	m_tex;
		bool	m_have_mipmaps;
	 public:
        ~TextureStage3d();
    
        TextureStage3d(const AS3::ui::flash::display3D::textures::Texture& tex,RenderStage3d* parent,UInt32 w,UInt32 h);
        
        AS3::ui::flash::display3D::textures::Texture texture() const { return m_tex;}
		/// get texture format
		virtual TextureFormat GHL_CALL GetFormat() const { return TEXTURE_FORMAT_RGBA;}
		/// get texture is have mipmaps
		virtual bool GHL_CALL HeveMipmaps() const { return m_have_mipmaps;}
		
		/// set texture pixels
		virtual void GHL_CALL SetData(UInt32 x,UInt32 y,const Image* data,UInt32 level);
		/// generate mipmaps
		virtual void GHL_CALL GenerateMipmaps();
	};
}

#endif /*TEXTURE_STAGE3D_H*/
