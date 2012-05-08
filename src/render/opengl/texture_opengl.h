/*
 *  texture_opengl.h
 *  TurboSquirrel
 *
 *  Created by Андрей Куницын on 08.03.10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef TEXTURE_OPENGL_H
#define TEXTURE_OPENGL_H

#include "ghl_texture.h"
#include "ghl_opengl.h"
#include "../../ghl_ref_counter_impl.h"

namespace GHL {

    class RenderOpenGL;

	class TextureOpenGL : public RefCounterImpl<Texture> {
	private:
		RenderOpenGL* m_parent;
		GLuint	m_name;
		UInt32	m_width;
		UInt32	m_height;
		TextureFormat	m_fmt;
		TextureFilter	m_min_filter;
		TextureFilter	m_mag_filter;
		TextureFilter	m_mip_filter;
		bool	m_have_mipmaps;
		TextureWrapMode m_wrap_u;
		TextureWrapMode m_wrap_v;
		void calc_filtration_min();
		void calc_filtration_mag();
		void check_mips();
		TextureOpenGL(GLuint name,RenderOpenGL* parent,TextureFormat fmt,UInt32 w,UInt32 h);
   public:
        ~TextureOpenGL();
        
		static TextureOpenGL* Create( RenderOpenGL* parent,TextureFormat fmt,UInt32 w,UInt32 h, const Data* data);
		void bind() const;
		GLuint name() const { return m_name;}
		/// get texture width
		virtual UInt32 GHL_CALL GetWidth() const { return m_width;}
		/// get texture height
		virtual UInt32 GHL_CALL GetHeight() const { return m_height;}
		/// get texture format
		virtual TextureFormat GHL_CALL GetFormat() const { return m_fmt;}
		/// get texture is have mipmaps
		virtual bool GHL_CALL HeveMipmaps() const { return m_have_mipmaps;}
		/// get minification texture filtration
		virtual TextureFilter GHL_CALL GetMinFilter( ) const { return m_min_filter;}
		/// set minification texture filtration
		virtual void GHL_CALL SetMinFilter(TextureFilter min);
		/// get magnification texture filtration
		virtual TextureFilter GHL_CALL GetMagFilter( ) const { return m_mag_filter;}
		/// set magnification texture filtration
		virtual void GHL_CALL SetMagFilter(TextureFilter mag);
		/// get mipmap texture filtration
		virtual TextureFilter GHL_CALL GetMipFilter( ) const { return m_mip_filter;}
		/// set mipmap texture filtration
		virtual void GHL_CALL SetMipFilter(TextureFilter mip);
		
		/// set texture wrap U
		virtual void GHL_CALL SetWrapModeU(TextureWrapMode wm);
		/// get texture wrap mode U
		virtual TextureWrapMode GHL_CALL GetWrapModeU() const { return m_wrap_u;}
		/// set texture wrap V
		virtual void GHL_CALL SetWrapModeV(TextureWrapMode wm);
		/// get texture wrap mode V
		virtual TextureWrapMode GHL_CALL GetWrapModeV() const { return m_wrap_v;}
		
		/// set texture pixels
		virtual void GHL_CALL SetData(UInt32 x,UInt32 y,UInt32 w,UInt32 h,const Data* data,UInt32 level);
		/// generate mipmaps
		virtual void GHL_CALL GenerateMipmaps();
	};
}

#endif /*TEXTURE_OPENGL_H*/
