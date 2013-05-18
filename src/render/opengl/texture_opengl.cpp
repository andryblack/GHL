/*
 *  texture_opengl.cpp
 *  TurboSquirrel
 *
 *  Created by Андрей Куницын on 08.03.10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "texture_opengl.h"
#include "render_opengl_base.h"

namespace GHL {

    static const char* MODULE = "RENDER:OpenGL";
	
	static inline  GL::GLenum convert_int_format( const GL& gl,TextureFormat fmt ) {
#ifdef GHL_OPENGLES
//		if (DinamicGLFeature_IMG_texture_compression_pvrtc_Supported()) {
//			if ( fmt == TEXTURE_FORMAT_PVRTC_2BPPV1 )
//				return  gl.COMPRESSED_RGBA_PVRTC_2BPPV1_IMG;
//			if ( fmt == TEXTURE_FORMAT_PVRTC_4BPPV1 )
//				return  gl.COMPRESSED_RGBA_PVRTC_4BPPV1_IMG;
//		} 
        if (fmt==TEXTURE_FORMAT_ALPHA )
            return  gl.ALPHA;
		if (fmt==TEXTURE_FORMAT_RGB )
			return  gl.RGB;
		if (fmt==TEXTURE_FORMAT_565)
			return  gl.RGB;
#else
        if (fmt==TEXTURE_FORMAT_ALPHA )
            return  gl.ALPHA;
		if (fmt==TEXTURE_FORMAT_565)
			return  gl.RGB;
		if (fmt==TEXTURE_FORMAT_RGB)
			return  gl.RGB8;
		if (fmt==TEXTURE_FORMAT_RGBA)
			return  gl.RGBA8;
#endif
		return  gl.RGBA;
	}
	
	static inline bool format_compressed( TextureFormat fmt ) {
		return fmt == TEXTURE_FORMAT_PVRTC_2BPPV1 ||
		fmt == TEXTURE_FORMAT_PVRTC_4BPPV1;
	}

	static inline  GL::GLenum convert_format(const GL& gl, TextureFormat fmt ) {
        if (fmt==TEXTURE_FORMAT_ALPHA )
            return  gl.ALPHA;
		if (fmt==TEXTURE_FORMAT_RGB )
			return  gl.RGB;
		if (fmt==TEXTURE_FORMAT_565)
			return  gl.RGB;
		return  gl.RGBA;
	}
	
	static inline  GL::GLenum convert_storage(const GL& gl, TextureFormat fmt ) {
		if (fmt==TEXTURE_FORMAT_565)
			return  gl.UNSIGNED_SHORT_5_6_5;
		if (fmt==TEXTURE_FORMAT_4444)
			return  gl.UNSIGNED_SHORT_4_4_4_4;
		return  gl.UNSIGNED_BYTE;
	}
	
	static inline  GL::GLenum convert_wrap(const GL& gl, TextureWrapMode m ) {
		if (m==TEX_WRAP_CLAMP )
			return  gl.CLAMP_TO_EDGE;
		return  gl.REPEAT;
	}
	
	TextureOpenGL::TextureOpenGL(GL::GLuint name,RenderOpenGLBase* parent,TextureFormat fmt,UInt32 w,UInt32 h) : TextureImpl(parent,w,h), gl(parent->get_api()),
		m_name(name),
		m_fmt(fmt),
		m_have_mipmaps(false)
	{
        (void)MODULE;
	}
	
	TextureOpenGL* TextureOpenGL::Create( RenderOpenGLBase* parent,TextureFormat fmt,UInt32 w,UInt32 h, const Image* data) {
        if (fmt==TEXTURE_FORMAT_UNKNOWN)
            return 0;
        const GL& gl(parent->get_api());
        GL::GLuint name = 0;
		CHECK_GL(gl.ActiveTexture(gl.TEXTURE0));
		CHECK_GL(gl.GenTextures(1, &name));
		if (!name) return 0;
		CHECK_GL(gl.BindTexture(gl.TEXTURE_2D, name));

        CHECK_GL(gl.TexParameteri(gl.TEXTURE_2D,  gl.TEXTURE_MIN_FILTER,  gl.NEAREST));
		CHECK_GL(gl.TexParameteri(gl.TEXTURE_2D,  gl.TEXTURE_MAG_FILTER,  gl.NEAREST));
        CHECK_GL(gl.TexParameteri(gl.TEXTURE_2D,  gl.TEXTURE_WRAP_S,  gl.CLAMP_TO_EDGE));
        CHECK_GL(gl.TexParameteri(gl.TEXTURE_2D,  gl.TEXTURE_WRAP_T,  gl.CLAMP_TO_EDGE));
		
        
        if (format_compressed(fmt)) {
			if ( data ) {
                const Data* tdata = data->GetData();
				CHECK_GL(gl.CompressedTexImage2D  (gl.TEXTURE_2D, 0, convert_int_format(gl,fmt), w, h, 0,tdata->GetSize(), tdata->GetData() ));
			} else {
				CHECK_GL(gl.BindTexture  (gl.TEXTURE_2D, 0));
				CHECK_GL(gl.DeleteTextures(1, &name));
				return 0;
			}
		} else {
            if (data) {
                const Data* tdata = data->GetData();
                ImageFormat ifmt = GHL_TextureFormatToImageFormat(fmt);
                if (ifmt!=data->GetFormat()) {
                    Image* cpy = data->Clone();
                    cpy->Convert(ifmt);
                    tdata = cpy->GetData();
                    CHECK_GL(gl.TexImage2D  (gl.TEXTURE_2D, 0,
                                    convert_int_format(gl,fmt), w, h, 0,
                                    convert_format(gl,fmt), convert_storage(gl,fmt),
                                    tdata->GetData() ));
                    cpy->Release();
                } else {
                    CHECK_GL(gl.TexImage2D  (gl.TEXTURE_2D, 0,
                                convert_int_format(gl,fmt), w, h, 0,
                                convert_format(gl,fmt), convert_storage(gl,fmt),
                                tdata->GetData() ));
                }
            } else {
                CHECK_GL(gl.TexImage2D  (gl.TEXTURE_2D, 0,
                                convert_int_format(gl,fmt), w, h, 0,
                                convert_format(gl,fmt), convert_storage(gl,fmt),
                                0));
            }
            
			
		}
		
		return new TextureOpenGL( name, parent, fmt, w,h );
	}
    
    TextureOpenGL::~TextureOpenGL() {
        CHECK_GL(gl.DeleteTextures(1, &m_name));
    }
	
	void TextureOpenGL::bind() const {
		CHECK_GL(gl.BindTexture(gl.TEXTURE_2D, m_name));
	}
	
	void TextureOpenGL::calc_filtration_min() {
        const  GL::GLenum min_filters[3][3] = {
            /// none					// near						// linear
            {gl.NEAREST,				gl.NEAREST,				    gl.LINEAR},               /// mip none
            {gl.NEAREST_MIPMAP_NEAREST, gl.NEAREST_MIPMAP_NEAREST,	gl.LINEAR_MIPMAP_NEAREST},/// mip near
            {gl.NEAREST_MIPMAP_LINEAR,	gl.NEAREST_MIPMAP_LINEAR,	gl.LINEAR_MIPMAP_LINEAR}, /// mip linear
        };
        GL::GLenum filter = min_filters[m_mip_filter][m_min_filter];
		CHECK_GL(gl.ActiveTexture(gl.TEXTURE0));
		bind();
		CHECK_GL(gl.TexParameteri(gl.TEXTURE_2D,  gl.TEXTURE_MIN_FILTER, filter));
		RestoreTexture(0);
	}
	
	void TextureOpenGL::calc_filtration_mag() {
		CHECK_GL(gl.ActiveTexture(gl.TEXTURE0));
		bind();
        const  GL::GLenum mag_filters[] = {gl.NEAREST,gl.NEAREST,gl.LINEAR};
        GL::GLenum filter = mag_filters[m_mag_filter];
		CHECK_GL(gl.TexParameteri(gl.TEXTURE_2D,  gl.TEXTURE_MAG_FILTER, filter));
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
        TextureImpl::SetMinFilter(min);
		calc_filtration_min();
		check_mips();
	}
	/// set magnification texture filtration
	void GHL_CALL TextureOpenGL::SetMagFilter(TextureFilter mag) {
        TextureImpl::SetMagFilter(mag);
		calc_filtration_mag();
		check_mips();
	}
	/// set mipmap texture filtration
	void GHL_CALL TextureOpenGL::SetMipFilter(TextureFilter mip) {
        TextureImpl::SetMipFilter(mip);
		calc_filtration_min();
		calc_filtration_mag();
		check_mips();
	}
	
	/// set texture wrap U
	void GHL_CALL TextureOpenGL::SetWrapModeU(TextureWrapMode wm) {
        TextureImpl::SetWrapModeU(wm);
		CHECK_GL(gl.ActiveTexture(gl.TEXTURE0);
		bind());
		CHECK_GL(gl.TexParameteri(gl.TEXTURE_2D,  gl.TEXTURE_WRAP_S, convert_wrap(gl,wm)));
		RestoreTexture(0);
	}
	/// set texture wrap V
	void GHL_CALL TextureOpenGL::SetWrapModeV(TextureWrapMode wm) {
        TextureImpl::SetWrapModeV(wm);
		CHECK_GL(gl.ActiveTexture(gl.TEXTURE0));
		bind();
		CHECK_GL(gl.TexParameteri(gl.TEXTURE_2D,  gl.TEXTURE_WRAP_T, convert_wrap(gl,wm)));
		RestoreTexture(0);
	}
	
	/// set texture pixels
	void GHL_CALL TextureOpenGL::SetData(UInt32 x,UInt32 y,const Image* data,UInt32 level) {
		CHECK_GL(gl.ActiveTexture  (gl.TEXTURE0));
		//glClientActiveTexture(GL_TEXTURE0);
		bind();
        if (gl.UNPACK_ALIGNMENT)
            CHECK_GL(gl.PixelStorei(gl.UNPACK_ALIGNMENT,1));
        UInt32 w = data->GetWidth();
        UInt32 h = data->GetHeight();
        if (gl.UNPACK_ROW_LENGTH)
            CHECK_GL(gl.PixelStorei(gl.UNPACK_ROW_LENGTH,w));
		if (format_compressed(m_fmt)) {
            const Data* tdata = data->GetData();
			CHECK_GL(gl.CompressedTexSubImage2D  (gl.TEXTURE_2D, level, x, y, w, h,
                                         convert_int_format(gl,m_fmt), tdata->GetSize(), tdata->GetData()));
		} else {
            ImageFormat ifmt = GHL_TextureFormatToImageFormat(GetFormat());
            if (ifmt!=data->GetFormat()) {
                Image* cpy = data->Clone();
                cpy->Convert(ifmt);
                const Data* tdata = cpy->GetData();
                CHECK_GL(gl.TexSubImage2D  (gl.TEXTURE_2D, level, x, y, w, h,
                                   convert_format(gl,m_fmt), convert_storage(gl,m_fmt), tdata->GetData()));
                cpy->Release();
            } else {
                CHECK_GL(gl.TexSubImage2D  (gl.TEXTURE_2D, level, x, y, w, h,
                                   convert_format(gl,m_fmt), convert_storage(gl,m_fmt), data->GetData()->GetData()));
            }
		}
        if (gl.UNPACK_ALIGNMENT)
            CHECK_GL(gl.PixelStorei  (gl.UNPACK_ALIGNMENT,4));
		if (gl.UNPACK_ROW_LENGTH)
            CHECK_GL(gl.PixelStorei  (gl.UNPACK_ROW_LENGTH,0));
		RestoreTexture(0);
	}
	/// generate mipmaps
	void GHL_CALL TextureOpenGL::GenerateMipmaps() {
		/// @todo
	}

}
