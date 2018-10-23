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

#include "../texture_impl.h"
#include "render_opengl_api.h"

namespace GHL {

    class RenderOpenGLBase;
    struct GL;

	class TextureOpenGL : public TextureImpl {
	private:
        const GL& gl;
		GL::GLuint	m_name;
		
		void calc_filtration_min();
		void calc_filtration_mag();
		void check_mips();
		TextureOpenGL(GL::GLuint name,RenderOpenGLBase* parent,TextureFormat fmt,UInt32 w,UInt32 h);
   public:
        ~TextureOpenGL();
        
		static TextureOpenGL* Create( RenderOpenGLBase* parent,TextureFormat fmt,UInt32 w,UInt32 h, const Image* data);
		void bind() const;
		GL::GLuint name() const { return m_name;}
		/// set minification texture filtration
		virtual void GHL_CALL SetMinFilter(TextureFilter min);
		/// set magnification texture filtration
		virtual void GHL_CALL SetMagFilter(TextureFilter mag);
		/// set mipmap texture filtration
		virtual void GHL_CALL SetMipFilter(TextureFilter mip);
		
		/// set texture wrap U
		virtual void GHL_CALL SetWrapModeU(TextureWrapMode wm);
		/// set texture wrap V
		virtual void GHL_CALL SetWrapModeV(TextureWrapMode wm);
		
		/// set texture pixels
		virtual void GHL_CALL SetData(UInt32 x,UInt32 y,const Image* data,UInt32 level);
		/// generate mipmaps
		virtual void GHL_CALL GenerateMipmaps();
	};
}

#endif /*TEXTURE_OPENGL_H*/
