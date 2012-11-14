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
	
    struct RenderTargetAPI {
        void (*GenFramebuffers)(GL::GLsizei n , GL::GLuint *framebuffers);
        void (*BindFramebuffer)(GL::GLenum target , GL::GLuint framebuffer);
        void (*DeleteFramebuffers)(GL::GLsizei n , const GL::GLuint *framebuffers);
        void (*FramebufferTexture2D)(GL::GLenum target ,
                                     GL::GLenum attachment ,
                                     GL::GLenum textarget ,
                                     GL::GLuint texture , GL::GLint level);
        void (*BindRenderbuffer)(GL::GLenum target , GL::GLuint renderbuffer);
        void (*DeleteRenderbuffers)(GL::GLsizei n , const GL::GLuint *renderbuffers);
        void (*GenRenderbuffers)(GL::GLsizei n , GL::GLuint *renderbuffers);
        void (*RenderbufferStorage)(GL::GLenum target , GL::GLenum internalformat , GL::GLsizei width , GL::GLsizei height);
        void (*FramebufferRenderbuffer)(GL::GLenum target ,
                                           GL::GLenum attachment ,
                                           GL::GLenum renderbuffertarget ,
                                           GL::GLuint renderbuffer);
        GL::GLenum (*CheckFramebufferStatus)(GL::GLenum target);
        GL::GLenum FRAMEBUFFER;
        GL::GLenum COLOR_ATTACHMENT0;
        GL::GLenum RENDERBUFFER;
        GL::GLenum DEPTH_ATTACHMENT;
        GL::GLenum DEPTH_COMPONENT16;
        GL::GLenum FRAMEBUFFER_COMPLETE;
    };
    
	class RenderTargetOpenGL : public RenderTargetImpl {
	private:
		UInt32	m_width;
		UInt32	m_height;
		bool	m_have_depth;
		TextureOpenGL*	m_texture;
        GL::GLuint m_framebuffer;
		GL::GLuint m_depth_renderbuffer;
        const RenderTargetAPI* m_api;
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