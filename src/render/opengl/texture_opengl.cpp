/*
 *  texture_opengl.cpp
 *  TurboSquirrel
 *
 *  Created by Андрей Куницын on 08.03.10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "texture_opengl.h"
#include "render_opengl.h"
namespace GHL {

	static inline GLenum convert_int_format( TextureFormat fmt ) {
		if (fmt==TEXTURE_FORMAT_RGB )
			return GL_RGB;
		if (fmt==TEXTURE_FORMAT_565)
			return GL_RGB;
		return GL_RGBA;
	}

	static inline GLenum convert_format( TextureFormat fmt ) {
		if (fmt==TEXTURE_FORMAT_RGB )
			return GL_RGB;
		if (fmt==TEXTURE_FORMAT_565)
			return GL_RGB;
		return GL_RGBA;
	}
	
	static inline GLenum convert_storage( TextureFormat fmt ) {
		if (fmt==TEXTURE_FORMAT_565)
			return GL_UNSIGNED_SHORT_5_6_5;
		if (fmt==TEXTURE_FORMAT_4444)
			return GL_UNSIGNED_SHORT_4_4_4_4;
		return GL_UNSIGNED_BYTE;
	}
	
	static inline GLenum convert_wrap( TextureWrapMode m ) {
		if (m==TEX_WRAP_CLAMP )
			return GL_CLAMP_TO_EDGE;
		return GL_REPEAT;
	}
	
        TextureOpenGL::TextureOpenGL(RenderOpenGL* parent,TextureFormat fmt,UInt32 w,UInt32 h) : m_parent(parent), m_name(0),m_width(w),m_height(h),
		m_fmt(fmt),
		m_min_filter(TEX_FILTER_NEAR),
		m_mag_filter(TEX_FILTER_NEAR),
		m_mip_filter(TEX_FILTER_NONE),
		m_have_mipmaps(false),
        m_wrap_u(TEX_WRAP_CLAMP),
        m_wrap_v(TEX_WRAP_CLAMP)
	{
		glActiveTexture(GL_TEXTURE0);
		//glClientActiveTexture(GL_TEXTURE0);
		glGenTextures(1, &m_name);
		bind();
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexImage2D(GL_TEXTURE_2D, 0, convert_int_format(m_fmt), w, h, 0, convert_format(m_fmt), convert_storage(m_fmt), 0);
	}
    
    TextureOpenGL::~TextureOpenGL() {
        m_parent->ReleaseTexture(this);
        glDeleteTextures(1, &m_name);
    }
	
	void TextureOpenGL::bind() const {
		glBindTexture(GL_TEXTURE_2D, m_name);
	}
	static const GLenum min_filters[3][3] = {
		/// none					// near						// linear
		{GL_NEAREST,				GL_NEAREST,					GL_LINEAR},					/// mip none
		{GL_NEAREST_MIPMAP_NEAREST,	GL_NEAREST_MIPMAP_NEAREST,	GL_LINEAR_MIPMAP_NEAREST},	/// mip near
		{GL_NEAREST_MIPMAP_LINEAR,	GL_NEAREST_MIPMAP_LINEAR,	GL_LINEAR_MIPMAP_LINEAR}, /// mip linear
	};
	
	void TextureOpenGL::calc_filtration_min() {
		GLenum filter = min_filters[m_mip_filter][m_min_filter];
		glActiveTexture(GL_TEXTURE0);
		bind();
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
		m_parent->RestoreTexture();
	}
	
	void TextureOpenGL::calc_filtration_mag() {
		glActiveTexture(GL_TEXTURE0);
		bind();
		GLenum filter = min_filters[0][m_min_filter];
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
		m_parent->RestoreTexture();
	}
	
	void TextureOpenGL::check_mips() {
		if (m_mip_filter!=TEX_FILTER_NONE) {
			if (!m_have_mipmaps) {
				GenerateMipmaps();
			}
		}
	}
	
    /// set minification texture filtration
	void GHL_CALL TextureOpenGL::SetMinFilter(TextureFilter min) {
		m_min_filter = min;
		calc_filtration_min();
		check_mips();
	}
	/// set magnification texture filtration
	void GHL_CALL TextureOpenGL::SetMagFilter(TextureFilter mag) {
		m_mag_filter = mag;
		calc_filtration_mag();
		check_mips();
	}
	/// set mipmap texture filtration
	void GHL_CALL TextureOpenGL::SetMipFilter(TextureFilter mip) {
		m_mip_filter = mip;
		calc_filtration_min();
		calc_filtration_mag();
		check_mips();
	}
	
	/// set texture wrap U
	void GHL_CALL TextureOpenGL::SetWrapModeU(TextureWrapMode wm) {
		glActiveTexture(GL_TEXTURE0);
		bind();
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, convert_wrap(wm));
		m_parent->RestoreTexture();
	}
	/// set texture wrap V
	void GHL_CALL TextureOpenGL::SetWrapModeV(TextureWrapMode wm) {
		glActiveTexture(GL_TEXTURE0);
		bind();
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, convert_wrap(wm));
		m_parent->RestoreTexture();
	}
	
	/// set texture pixels
	void GHL_CALL TextureOpenGL::SetData(UInt32 x,UInt32 y,UInt32 w,UInt32 h,const Byte* data,UInt32 level) {
		glActiveTexture(GL_TEXTURE0);
		//glClientActiveTexture(GL_TEXTURE0);
		bind();
		glPixelStorei(GL_UNPACK_ALIGNMENT,1);
#ifndef GHL_OPENGLES
		glPixelStorei(GL_UNPACK_ROW_LENGTH,w);
#endif
		glTexSubImage2D(GL_TEXTURE_2D, level, x, y, w, h, convert_format(m_fmt), convert_storage(m_fmt), data);
		glPixelStorei(GL_UNPACK_ALIGNMENT,4);
#ifndef GHL_OPENGLES
		glPixelStorei(GL_UNPACK_ROW_LENGTH,0);
#endif
		m_parent->RestoreTexture();
	}
	/// generate mipmaps
	void GHL_CALL TextureOpenGL::GenerateMipmaps() {
		/// @todo
	}

}
