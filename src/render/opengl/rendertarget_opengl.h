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
        const GL&  gl;
        UInt32	m_width;
		UInt32	m_height;
		bool	m_have_depth;
		TextureOpenGL*	m_texture;
        GL::GLuint m_framebuffer;
		GL::GLuint m_depth_renderbuffer;
    public:
		RenderTargetOpenGL(RenderOpenGL* parent,UInt32 w,UInt32 h,TextureFormat fmt,bool depth);
		~RenderTargetOpenGL();
		
		void bind() const;
        void unbind() const;
		
		bool check() const;
		
		/// width
		virtual UInt32 GHL_CALL GetWidth() const { return m_width;}
		/// height
		virtual UInt32 GHL_CALL GetHeight() const { return m_height;}
		/// have depth
		virtual	bool GHL_CALL HaveDepth() const { return m_have_depth;}
		/// get texture
		virtual Texture* GHL_CALL GetTexture() const;
		/// 
		virtual void GHL_CALL GetPixels(UInt32 x,UInt32 y,UInt32 w,UInt32 h,Byte* data);
		
		virtual void BeginScene( RenderImpl* render ) ;
		virtual void EndScene( RenderImpl* render ) ;
	};
}

#endif