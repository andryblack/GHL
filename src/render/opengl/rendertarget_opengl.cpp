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
	
	UInt32 g_default_renderbuffer = 0;
    static const char* MODULE = "RENDER";

/*
    static bool extensions_supported() {
        static bool checked = false;
        static bool result = false;
        if (!checked) {
#ifdef GHL_OPENGLES
            result = m_api->DinamicGLFeature_OES_framebuffer_object_Supported();
            checked = true;
            LOG_VERBOSE("DinamicGLFeature_OES_framebuffer_object_Supported result : " << result);
#else
            result = m_api->DinamicGLFeature_EXT_framebuffer_object_Supported();
            checked = true;
            LOG_VERBOSE("DinamicGLFeature_EXT_framebuffer_object_Supported result : " << result);
#endif
        }
        return result;
    }
*/

    RenderTargetOpenGL::RenderTargetOpenGL(RenderOpenGL* parent,UInt32 w,UInt32 h,TextureFormat fmt,bool depth) :
		RenderTargetImpl(parent),m_width(w),m_height(h),m_have_depth(depth),m_texture(0)
	{
        if (!m_api) return;
        m_api->GenFramebuffers(1, &m_framebuffer);
		m_api->BindFramebuffer(m_api->FRAMEBUFFER,m_framebuffer);
		m_texture = reinterpret_cast<TextureOpenGL*>(GetParent()->CreateTexture(w, h, fmt, 0));
		m_api->FramebufferTexture2D(m_api->FRAMEBUFFER, m_api->COLOR_ATTACHMENT0, GL::TEXTURE_2D, m_texture->name(), 0);
		gl.BindTexture(GL::TEXTURE_2D,0);
		if (depth) {
            m_api->GenRenderbuffers(1, &m_depth_renderbuffer);
            m_api->BindRenderbuffer(m_api->RENDERBUFFER, m_depth_renderbuffer);
            m_api->RenderbufferStorage(m_api->RENDERBUFFER, m_api->DEPTH_COMPONENT16, w, h);
            m_api->FramebufferRenderbuffer(m_api->FRAMEBUFFER, m_api->DEPTH_ATTACHMENT, m_api->RENDERBUFFER, m_depth_renderbuffer);
		}
		unbind();
	}
	
	bool RenderTargetOpenGL::check() const {
		if (!m_api) return false;
		bind();
        GL::GLenum status = m_api->CheckFramebufferStatus(m_api->FRAMEBUFFER) ;
		unbind();
		return status == m_api->FRAMEBUFFER_COMPLETE ;
	}
	
	RenderTargetOpenGL::~RenderTargetOpenGL() {
		if (!m_api) return;
		if (m_have_depth)
			m_api->DeleteRenderbuffers(1,&m_depth_renderbuffer);
		if (m_texture)
			m_texture->Release();
		m_texture = 0;
		m_api->DeleteFramebuffers(1,&m_framebuffer);
    }
		
	void RenderTargetOpenGL::bind() const {
        if (!m_api) return;
		m_api->BindFramebuffer(m_api->FRAMEBUFFER,m_framebuffer);
	}
	
	void RenderTargetOpenGL::unbind() const {
        if (!m_api) return;
		m_api->BindFramebuffer(m_api->FRAMEBUFFER,g_default_renderbuffer);
	}
		
		
		/// get texture
	Texture* GHL_CALL RenderTargetOpenGL::GetTexture() const {
		return m_texture;
	}
		
	void RenderTargetOpenGL::BeginScene(RenderImpl* /*render*/)  {
		bind();
		gl.Viewport(0, 0, m_width, m_height);
		gl.MatrixMode(GL::PROJECTION);
		gl.LoadIdentity();
		gl.MatrixMode(GL::MODELVIEW);
		gl.LoadIdentity();
		gl.Ortho(0, m_width, 0, m_height, -10, 10);
	}
	
	void RenderTargetOpenGL::EndScene(RenderImpl* /*render*/) {
		//glFlush();
		unbind();
	}
	
	void GHL_CALL RenderTargetOpenGL::GetPixels(UInt32 x,UInt32 y,UInt32 w,UInt32 h,Byte* data) {
		gl.Flush();
		bind();
		gl.ReadPixels(x,y, w, h, GL::RGBA, GL::UNSIGNED_BYTE, data);
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

