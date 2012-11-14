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

	static inline GL::GLenum convert_int_format( TextureFormat fmt ) {
#ifdef GHL_OPENGLES
		if (DinamicGLFeature_IMG_texture_compression_pvrtc_Supported()) {
			if ( fmt == TEXTURE_FORMAT_PVRTC_2BPPV1 )
				return GL::GL_COMPRESSED_RGBA_PVRTC_2BPPV1_IMG;
			if ( fmt == TEXTURE_FORMAT_PVRTC_4BPPV1 )
				return GL::GL_COMPRESSED_RGBA_PVRTC_4BPPV1_IMG;
		} 
        if (fmt==TEXTURE_FORMAT_ALPHA )
            return GL::GL_ALPHA;
		if (fmt==TEXTURE_FORMAT_RGB )
			return GL::GL_RGB;
		if (fmt==TEXTURE_FORMAT_565)
			return GL::GL_RGB;
#else
        if (fmt==TEXTURE_FORMAT_ALPHA )
            return GL::ALPHA;
		if (fmt==TEXTURE_FORMAT_565)
			return GL::RGB;
		if (fmt==TEXTURE_FORMAT_RGB)
			return GL::RGB8;
		if (fmt==TEXTURE_FORMAT_RGBA)
			return GL::RGBA8;
#endif
		return GL::RGBA;
	}
	
	static inline bool format_compressed( TextureFormat fmt ) {
		return fmt == TEXTURE_FORMAT_PVRTC_2BPPV1 ||
		fmt == TEXTURE_FORMAT_PVRTC_4BPPV1;
	}

	static inline GL::GLenum convert_format( TextureFormat fmt ) {
        if (fmt==TEXTURE_FORMAT_ALPHA )
            return GL::ALPHA;
		if (fmt==TEXTURE_FORMAT_RGB )
			return GL::RGB;
		if (fmt==TEXTURE_FORMAT_565)
			return GL::RGB;
		return GL::RGBA;
	}
	
	static inline GL::GLenum convert_storage( TextureFormat fmt ) {
		if (fmt==TEXTURE_FORMAT_565)
			return GL::UNSIGNED_SHORT_5_6_5;
		if (fmt==TEXTURE_FORMAT_4444)
			return GL::UNSIGNED_SHORT_4_4_4_4;
		return GL::UNSIGNED_BYTE;
	}
	
	static inline GL::GLenum convert_wrap( TextureWrapMode m ) {
		if (m==TEX_WRAP_CLAMP )
			return GL::CLAMP_TO_EDGE;
		return GL::REPEAT;
	}
	
	TextureOpenGL::TextureOpenGL(GL::GLuint name,RenderOpenGL* parent,TextureFormat fmt,UInt32 w,UInt32 h) : TextureImpl(parent),
		m_name(name),m_width(w),m_height(h),
		m_fmt(fmt),
		m_min_filter(TEX_FILTER_NEAR),
		m_mag_filter(TEX_FILTER_NEAR),
		m_mip_filter(TEX_FILTER_NONE),
		m_have_mipmaps(false),
        m_wrap_u(TEX_WRAP_CLAMP),
        m_wrap_v(TEX_WRAP_CLAMP)
	{
		
	}
	
	TextureOpenGL* TextureOpenGL::Create( RenderOpenGL* parent,TextureFormat fmt,UInt32 w,UInt32 h, const Data* data) {
        if (fmt==TEXTURE_FORMAT_UNKNOWN)
            return 0;
        GL::GLuint name = 0;
		gl.ActiveTexture(GL::TEXTURE0);
		gl.GenTextures(1, &name);
		if (!name) return 0;
		gl.BindTexture(GL::TEXTURE_2D, name);

		gl.TexParameteri(GL::TEXTURE_2D, GL::TEXTURE_MIN_FILTER, GL::NEAREST);
		gl.TexParameteri(GL::TEXTURE_2D, GL::TEXTURE_MAG_FILTER, GL::NEAREST);
        gl.TexParameteri(GL::TEXTURE_2D, GL::TEXTURE_WRAP_S, GL::CLAMP_TO_EDGE);
        gl.TexParameteri(GL::TEXTURE_2D, GL::TEXTURE_WRAP_T, GL::CLAMP_TO_EDGE);
		if (format_compressed(fmt)) {
			if ( data )
				gl.CompressedTexImage2D(GL::TEXTURE_2D, 0, convert_int_format(fmt), w, h, 0, data->GetSize(), data->GetData() );
			else {
				gl.BindTexture(GL::TEXTURE_2D, 0);
				gl.DeleteTextures(1, &name);
				return 0;
			}
		} else {
			gl.TexImage2D(GL::TEXTURE_2D, 0, convert_int_format(fmt), w, h, 0, convert_format(fmt), convert_storage(fmt),
						 data ? data->GetData() : 0);
		}
		
		return new TextureOpenGL( name, parent, fmt, w,h );
	}
    
    TextureOpenGL::~TextureOpenGL() {
        gl.DeleteTextures(1, &m_name);
    }
	
	void TextureOpenGL::bind() const {
		gl.BindTexture(GL::TEXTURE_2D, m_name);
	}
	static const GL::GLenum min_filters[3][3] = {
		/// none					// near						// linear
		{GL::NEAREST,				GL::NEAREST,				GL::LINEAR},               /// mip none
		{GL::NEAREST_MIPMAP_NEAREST,GL::NEAREST_MIPMAP_NEAREST,	GL::LINEAR_MIPMAP_NEAREST},/// mip near
		{GL::NEAREST_MIPMAP_LINEAR,	GL::NEAREST_MIPMAP_LINEAR,	GL::LINEAR_MIPMAP_LINEAR}, /// mip linear
	};
	
	void TextureOpenGL::calc_filtration_min() {
        GL::GLenum filter = min_filters[m_mip_filter][m_min_filter];
		gl.ActiveTexture(GL::TEXTURE0);
		bind();
		gl.TexParameteri(GL::TEXTURE_2D, GL::TEXTURE_MIN_FILTER, filter);
		RestoreTexture(0);
	}
	
	void TextureOpenGL::calc_filtration_mag() {
		gl.ActiveTexture(GL::TEXTURE0);
		bind();
        GL::GLenum filter = min_filters[0][m_mag_filter];
		gl.TexParameteri(GL::TEXTURE_2D, GL::TEXTURE_MAG_FILTER, filter);
		RestoreTexture(0);
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
		gl.ActiveTexture(GL::TEXTURE0);
		bind();
		gl.TexParameteri(GL::TEXTURE_2D, GL::TEXTURE_WRAP_S, convert_wrap(wm));
		RestoreTexture(0);
	}
	/// set texture wrap V
	void GHL_CALL TextureOpenGL::SetWrapModeV(TextureWrapMode wm) {
		gl.ActiveTexture(GL::TEXTURE0);
		bind();
		gl.TexParameteri(GL::TEXTURE_2D, GL::TEXTURE_WRAP_T, convert_wrap(wm));
		RestoreTexture(0);
	}
	
	/// set texture pixels
	void GHL_CALL TextureOpenGL::SetData(UInt32 x,UInt32 y,UInt32 w,UInt32 h,const Data* data,UInt32 level) {
		gl.ActiveTexture(GL::TEXTURE0);
		//glClientActiveTexture(GL_TEXTURE0);
		bind();
		gl.PixelStorei(GL::UNPACK_ALIGNMENT,1);
#ifndef GHL_OPENGLES
		gl.PixelStorei(GL::UNPACK_ROW_LENGTH,w);
#endif
		if (format_compressed(m_fmt)) {
			gl.CompressedTexSubImage2D(GL::TEXTURE_2D, level, x, y, w, h, convert_int_format(m_fmt), data->GetSize(), data->GetData());
		} else {
			gl.TexSubImage2D(GL::TEXTURE_2D, level, x, y, w, h, convert_format(m_fmt), convert_storage(m_fmt), data->GetData());
		}
		gl.PixelStorei(GL::UNPACK_ALIGNMENT,4);
#ifndef GHL_OPENGLES
		gl.PixelStorei(GL::UNPACK_ROW_LENGTH,0);
#endif
		RestoreTexture(0);
	}
	/// generate mipmaps
	void GHL_CALL TextureOpenGL::GenerateMipmaps() {
		/// @todo
	}

}
