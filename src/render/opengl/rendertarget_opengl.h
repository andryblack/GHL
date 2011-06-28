/*
 *  rendertarget_opengl.h
 *  GHLiPhone
 *
 *  Created by Андрей Куницын on 08.06.10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef RENDERTARGET_OPENGL_H
#define RENDERTARGET_OPENGL_H

#include <ghl_texture.h>
#include "../rendertarget_impl.h"
#include "ghl_opengl.h"

namespace GHL {
	
    class RenderOpenGL;
	class TextureOpenGL;
	
	class RenderTargetOpenGL : public RenderTargetImpl {
	private:
		RenderOpenGL* m_parent;
		UInt32	m_width;
		UInt32	m_height;
		bool	m_have_depth;
		TextureOpenGL*	m_texture;
		GLuint m_framebuffer;
		GLuint m_depth_renderbuffer;
	public:
		RenderTargetOpenGL(RenderOpenGL* parent,UInt32 w,UInt32 h,bool depth);
		~RenderTargetOpenGL();
		
		void bind();
		static void unbind();
		
		bool check() const;
		
		/// width
		virtual UInt32 GHL_CALL GetWidth() const { return m_width;}
		/// height
		virtual UInt32 GHL_CALL GetHeight() const { return m_height;}
		/// have depth
		virtual	bool GHL_CALL HaveDepth() const { return m_have_depth;}
		/// get texture
		virtual Texture* GHL_CALL GetTexture() const;
		/// release
		virtual void GHL_CALL Release() ;
		
		virtual void BeginScene( RenderImpl* render ) ;
		virtual void EndScene( RenderImpl* render ) ;
	};
}

#endif