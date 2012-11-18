/*
 *  rendertarget_openm_api->cpp
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

#include "../../ghl_log_impl.h"

namespace GHL {
	
	static const char* MODULE = "RENDER";


    RenderTargetOpenGL::RenderTargetOpenGL(RenderOpenGLBase* parent,UInt32 w,UInt32 h,TextureFormat fmt,bool depth) :
		RenderTargetImpl(parent),gl(parent->get_api()),m_width(w),m_height(h),m_have_depth(depth),m_texture(0)
	{
        if (!gl.rtapi.valid) return;
        gl.rtapi.GenFramebuffers(1, &m_framebuffer);
		gl.rtapi.BindFramebuffer(gl.rtapi.FRAMEBUFFER,m_framebuffer);
		m_texture = reinterpret_cast<TextureOpenGL*>(GetParent()->CreateTexture(w, h, fmt, 0));
		gl.rtapi.FramebufferTexture2D(gl.rtapi.FRAMEBUFFER, gl.rtapi.COLOR_ATTACHMENT0, gl.TEXTURE_2D, m_texture->name(), 0);
		gl.BindTexture(gl.TEXTURE_2D,0);
		if (depth) {
            gl.rtapi.GenRenderbuffers(1, &m_depth_renderbuffer);
            gl.rtapi.BindRenderbuffer(gl.rtapi.RENDERBUFFER, m_depth_renderbuffer);
            gl.rtapi.RenderbufferStorage(gl.rtapi.RENDERBUFFER, gl.rtapi.DEPTH_COMPONENT16, w, h);
            gl.rtapi.FramebufferRenderbuffer(gl.rtapi.FRAMEBUFFER, gl.rtapi.DEPTH_ATTACHMENT, gl.rtapi.RENDERBUFFER, m_depth_renderbuffer);
		}
		unbind();
	}
	
	bool RenderTargetOpenGL::check() const {
		if (!gl.rtapi.valid) return false;
		bind();
        GL::GLenum status = gl.rtapi.CheckFramebufferStatus(gl.rtapi.FRAMEBUFFER) ;
		unbind();
		return status == gl.rtapi.FRAMEBUFFER_COMPLETE ;
	}
	
	RenderTargetOpenGL::~RenderTargetOpenGL() {
		if (!gl.rtapi.valid) return;
		if (m_have_depth)
			gl.rtapi.DeleteRenderbuffers(1,&m_depth_renderbuffer);
		if (m_texture)
			m_texture->Release();
		m_texture = 0;
		gl.rtapi.DeleteFramebuffers(1,&m_framebuffer);
    }
		
	void RenderTargetOpenGL::bind() const {
        if (!gl.rtapi.valid) return;
		gl.rtapi.BindFramebuffer(gl.rtapi.FRAMEBUFFER,m_framebuffer);
	}
	
	void RenderTargetOpenGL::unbind() const {
        if (!gl.rtapi.valid) return;
		gl.rtapi.BindFramebuffer(gl.rtapi.FRAMEBUFFER,gl.rtapi.default_renderbuffer);
	}
		
		
		/// get texture
	Texture* GHL_CALL RenderTargetOpenGL::GetTexture() const {
		return m_texture;
	}
		
	void RenderTargetOpenGL::BeginScene(RenderImpl* /*render*/)  {
		bind();
	}
	
	void RenderTargetOpenGL::EndScene(RenderImpl* /*render*/) {
		//glFlush();
		unbind();
	}
	
	void GHL_CALL RenderTargetOpenGL::GetPixels(UInt32 x,UInt32 y,UInt32 w,UInt32 h,Byte* data) {
		gl.Flush();
		bind();
		gl.ReadPixels(x,y, w, h, gl.RGBA, gl.UNSIGNED_BYTE, data);
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

