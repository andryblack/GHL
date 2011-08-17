/*
 *  rendertarget_opengl.cpp
 *  GHLiPhone
 *
 *  Created by Андрей Куницын on 08.06.10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "ghl_opengl.h"


#include "rendertarget_opengl.h"
#include "render_opengl.h"
#include "texture_opengl.h"

#include <iostream>

#ifdef GHL_DYNAMIC_GL
#endif

namespace GHL {
	
	UInt32 g_default_renderbuffer = 0;
	
#ifdef GHL_DYNAMIC_GL
    static bool extensions_supported() {
        static bool checked = false;
        static bool result = false;
        if (!checked) {
            result = DinamicGLFeature_EXT_framebuffer_object_Supported();
            checked = true;
        }
        return result;
    }
#endif

#ifdef GHL_OPENGLES
#define _glGenFramebuffers glGenFramebuffersOES
#define _glFramebufferTexture2D glFramebufferTexture2DOES
#define _glGenRenderbuffers glGenRenderbuffersOES
#define _glBindRenderbuffer glBindRenderbufferOES
#define _glRenderbufferStorage glRenderbufferStorageOES
#define _glFramebufferRenderbuffer glFramebufferRenderbufferOES
#define _glCheckFramebufferStatus glCheckFramebufferStatusOES
#define _glDeleteFramebuffers glDeleteFramebuffersOES
#define _glDeleteRenderbuffers glDeleteRenderbuffersOES
#define _glBindFramebuffer glBindFramebufferOES
#define _GL_FRAMEBUFFER GL_FRAMEBUFFER_OES
#define _GL_FRAMEBUFFER_READ GL_FRAMEBUFFER_READ_OES
#define _GL_FRAMEBUFFER_WRITE GL_FRAMEBUFFER_WRITE_OES
#define _GL_COLOR_ATTACHMENT0 GL_COLOR_ATTACHMENT0_OES
#define _GL_RENDERBUFFER GL_RENDERBUFFER_OES
#define _GL_DEPTH_COMPONENT16 GL_DEPTH_COMPONENT16_OES
#define _GL_DEPTH_ATTACHMENT GL_DEPTH_ATTACHMENT_OES
#define _GL_FRAMEBUFFER_COMPLETE GL_FRAMEBUFFER_COMPLETE_OES
#else
#define _glGenFramebuffers glGenFramebuffersEXT
#define _glFramebufferTexture2D glFramebufferTexture2DEXT
#define _glGenRenderbuffers glGenRenderbuffersEXT
#define _glBindRenderbuffer glBindRenderbufferEXT
#define _glRenderbufferStorage glRenderbufferStorageEXT
#define _glFramebufferRenderbuffer glFramebufferRenderbufferEXT
#define _glCheckFramebufferStatus glCheckFramebufferStatusEXT
#define _glDeleteFramebuffers glDeleteFramebuffersEXT
#define _glDeleteRenderbuffers glDeleteRenderbuffersEXT
#define _glBindFramebuffer glBindFramebufferEXT
#define _GL_FRAMEBUFFER GL_FRAMEBUFFER_EXT
#define _GL_COLOR_ATTACHMENT0 GL_COLOR_ATTACHMENT0_EXT
#define _GL_RENDERBUFFER GL_RENDERBUFFER_EXT
#define _GL_DEPTH_COMPONENT16 GL_DEPTH_COMPONENT16
#define _GL_DEPTH_ATTACHMENT GL_DEPTH_ATTACHMENT_EXT
#define _GL_FRAMEBUFFER_COMPLETE GL_FRAMEBUFFER_COMPLETE_EXT
#endif
	
#define CHECK_GL_ERROR do { GLenum err = glGetError(); if (err!=0) { std::cout << "GL error at "<<__FUNCTION__<<" : " << err << std::endl; } } while(0);	
#define CHECK_GL_ERROR_F( func )  do { GLenum err = glGetError(); if (err!=0) { std::cout << "GL error " << func << " at  " << __FUNCTION__ << "  : " <<  err << std::endl;} } while(0);	

	RenderTargetOpenGL::RenderTargetOpenGL(RenderOpenGL* parent,UInt32 w,UInt32 h,TextureFormat fmt,bool depth) :
		m_parent(parent),m_width(w),m_height(h),m_have_depth(depth),m_texture(0)
	{
#ifdef GHL_DYNAMIC_GL
            if (!extensions_supported()) return;
#endif
		CHECK_GL_ERROR_F("before");
		_glGenFramebuffers(1, &m_framebuffer);
		CHECK_GL_ERROR_F("_glGenFramebuffers");
		_glBindFramebuffer(_GL_FRAMEBUFFER,m_framebuffer);
		CHECK_GL_ERROR_F("ctr _glBindFramebuffer");
		m_texture = reinterpret_cast<TextureOpenGL*>(m_parent->CreateTexture(w, h, fmt, false));
		_glFramebufferTexture2D(_GL_FRAMEBUFFER, _GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_texture->name(), 0);
		CHECK_GL_ERROR_F("_glFramebufferTexture2D");
		glBindTexture(GL_TEXTURE_2D,0);
		CHECK_GL_ERROR_F("glBindTexture");
		if (depth) {
				_glGenRenderbuffers(1, &m_depth_renderbuffer);
				CHECK_GL_ERROR;
				_glBindRenderbuffer(_GL_RENDERBUFFER, m_depth_renderbuffer);
				CHECK_GL_ERROR;
				_glRenderbufferStorage(_GL_RENDERBUFFER, _GL_DEPTH_COMPONENT16, w, h);
				CHECK_GL_ERROR;
				_glFramebufferRenderbuffer(_GL_FRAMEBUFFER, _GL_DEPTH_ATTACHMENT, _GL_RENDERBUFFER, m_depth_renderbuffer);
				CHECK_GL_ERROR;
		}
		unbind();
	}
	
	bool RenderTargetOpenGL::check() const {
#ifdef GHL_DYNAMIC_GL
		if (!extensions_supported()) return false;
#endif
		bind();
		GLenum status = _glCheckFramebufferStatus(_GL_FRAMEBUFFER) ;
		unbind();
		return status == _GL_FRAMEBUFFER_COMPLETE ;
	}
	
	RenderTargetOpenGL::~RenderTargetOpenGL() {
#ifdef GHL_DYNAMIC_GL
		if (!extensions_supported()) return;
#endif
		if (m_have_depth)
			_glDeleteRenderbuffers(1,&m_depth_renderbuffer);
		if (m_texture)
			m_texture->Release();
		m_texture = 0;
		_glDeleteFramebuffers(1,&m_framebuffer);
	}
		
	void RenderTargetOpenGL::bind() const {
		_glBindFramebuffer(_GL_FRAMEBUFFER,m_framebuffer);
		CHECK_GL_ERROR_F("bind");
	}
	
	void RenderTargetOpenGL::unbind() {
		_glBindFramebuffer(_GL_FRAMEBUFFER,g_default_renderbuffer);
		CHECK_GL_ERROR_F("unbind");
	}
		
		
		/// get texture
	Texture* GHL_CALL RenderTargetOpenGL::GetTexture() const {
		return m_texture;
	}
		/// release
	void GHL_CALL RenderTargetOpenGL::Release()  {
		m_parent->ReleaseRendertarget(this);
	}
	
	void RenderTargetOpenGL::BeginScene(RenderImpl* /*render*/)  {
		bind();
		glViewport(0, 0, m_width, m_height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glOrtho(0, m_width, 0, m_height, -10, 10);
	}
	
	void RenderTargetOpenGL::EndScene(RenderImpl* /*render*/) {
		glFlush();
		unbind();
	}
	
	void GHL_CALL RenderTargetOpenGL::GetPixels(UInt32 x,UInt32 y,UInt32 w,UInt32 h,Byte* data) {
		bind();
		glReadPixels(x,y, w, h, GL_RGBA, GL_UNSIGNED_BYTE, data);
		unbind();
		/*const size_t line_size = w*4;
		Byte line[line_size];
		UInt32 y1 = 0;
		UInt32 y2 = h-1;
		while (y1<y2) {
			::memcpy(line,&data[y2*line_size],line_size);
			::memcpy(&data[y2*line_size],&data[y1*line_size],line_size);
			::memcpy(&data[y1*line_size],line,line_size);
			y1++;
			if (y2==0) break;
			y2--;
		}*/
		
	}
}

