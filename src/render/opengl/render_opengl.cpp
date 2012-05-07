/*
 *  render_opengl.cpp
 *  TurboSquirrel
 *
 *  Created by Андрей Куницын on 07.03.10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#include "render_opengl.h"
#include "texture_opengl.h"
#include "ghl_opengl.h"
#include <ghl_data_stream.h>
#include "../../ghl_log_impl.h"

#include "rendertarget_opengl.h"
#include "shader_glsl.h"

#include <cstdio>
#include <cctype>

#include <algorithm>
#include <cassert>

namespace GHL {

    static const char* MODULE = "RENDER";
	
	static const GLenum texture_stages[] = {
		GL_TEXTURE0,
		GL_TEXTURE1,
		GL_TEXTURE2,
		GL_TEXTURE3,
	};
	
	static void set_texture_stage(UInt32 stage) {
        static UInt32 oldStage = 1000;
        if (oldStage!=stage) {
            glActiveTexture(texture_stages[stage]);
            oldStage=stage;
        }
	}
	
	static inline GLenum convert_blend(BlendFactor bf ) {
		if (bf==BLEND_FACTOR_SRC_COLOR)
			return GL_SRC_COLOR;
		if (bf==BLEND_FACTOR_SRC_COLOR_INV)
			return GL_ONE_MINUS_SRC_COLOR;
		if (bf==BLEND_FACTOR_SRC_ALPHA)
			return GL_SRC_ALPHA;
		if (bf==BLEND_FACTOR_SRC_ALPHA_INV)
			return GL_ONE_MINUS_SRC_ALPHA;
		if (bf==BLEND_FACTOR_DST_COLOR)
			return GL_DST_COLOR;
		if (bf==BLEND_FACTOR_DST_COLOR_INV)
			return GL_ONE_MINUS_DST_COLOR;
		if (bf==BLEND_FACTOR_DST_ALPHA)
			return GL_DST_ALPHA;
		if (bf==BLEND_FACTOR_DST_ALPHA_INV)
			return GL_ONE_MINUS_DST_ALPHA;
		if (bf==BLEND_FACTOR_ZERO)
			return GL_ZERO;
		return GL_ONE;
	}
	
	static inline GLenum conv_compare(CompareFunc f) {
		if (f==COMPARE_FUNC_LESS)
			return GL_LESS;
		if (f==COMPARE_FUNC_GREATER)
			return GL_GREATER;
		if (f==COMPARE_FUNC_EQUAL)
			return GL_EQUAL;
		if (f==COMPARE_FUNC_ALWAYS)
			return GL_ALWAYS;
		if (f==COMPARE_FUNC_NEQUAL)
			return GL_NOTEQUAL;
		if (f==COMPARE_FUNC_GEQUAL)
			return GL_GEQUAL;
		if (f==COMPARE_FUNC_LEQUAL)
			return GL_LEQUAL;
		return GL_NEVER;
	}
	
	static inline void conv_texarg(TextureArgument f,bool alpha,GLenum& arg,GLenum& op) {
		if (f==TEX_ARG_CURRENT) {
			arg = GL_PREVIOUS;
			op = alpha ? GL_SRC_ALPHA : GL_SRC_COLOR;
		} else if (f==TEX_ARG_DIFFUSE) {
			arg = GL_PRIMARY_COLOR;
			op = alpha ? GL_SRC_ALPHA : GL_SRC_COLOR;
		} else if (f==TEX_ARG_TEXTURE) {
			arg = GL_TEXTURE;
			op = alpha ? GL_SRC_ALPHA : GL_SRC_COLOR;
		}else if (f==TEX_ARG_CURRENT_INV) {
			arg = GL_PREVIOUS;
			op = alpha ? GL_ONE_MINUS_SRC_ALPHA : GL_ONE_MINUS_SRC_COLOR;
		} else if (f==TEX_ARG_DIFFUSE_INV) {
			arg = GL_PRIMARY_COLOR;
			op = alpha ? GL_ONE_MINUS_SRC_ALPHA : GL_ONE_MINUS_SRC_COLOR;
		} else if (f==TEX_ARG_TEXTURE_INV) {
			arg = GL_TEXTURE;
			op = alpha ? GL_ONE_MINUS_SRC_ALPHA : GL_ONE_MINUS_SRC_COLOR;
		}
	}
	
	RenderOpenGL::RenderOpenGL(UInt32 w,UInt32 h) : RenderImpl(w,h) {
#ifndef GHL_SHADERS_UNSUPPORTED
		m_shaders_support_glsl = false;
#endif
	}

	RenderOpenGL::~RenderOpenGL() {
#ifdef GHL_DYNAMIC_GL
            DynamicGLFinish();
#endif
        LOG_VERBOSE("Destructor");
	}

#define NOT_IMPLEMENTED LOG_ERROR( "render openGL function " << __FUNCTION__ << " not implemented" )

#ifdef GHL_DEBUG
#define CHECK_GL_ERROR do { GLenum err = glGetError(); if (err!=0) { LOG_ERROR( "GL error at "<<__FUNCTION__<<" : " << err ); } } while(0);	
	
#define CHECK_GL_ERROR_F( func )  do { GLenum err = glGetError(); if (err!=0) { LOG_ERROR( "GL error " << func << " at  " << __FUNCTION__ << "  : " <<  err );} } while(0);	
#else
#define CHECK_GL_ERROR_F( func )
#define CHECK_GL_ERROR
#endif
	bool	RenderOpenGL::ExtensionSupported(const char* all,const char* ext) const {
		return strstr(all,ext)!=0;
	}
	bool RenderOpenGL::RenderInit() {
        LOG_INFO("RenderOpenGL::RenderInit");
#ifdef GHL_DYNAMIC_GL
		DynamicGLInit();
		DynamicGLLoadSubset();
		if (!DinamicGLFeature_VERSION_1_1_Supported()) {
			LOG_ERROR( "!DinamicGLFeature_VERSION_1_1_Supported" );
			return false;
		}
#endif		
		const char* render = (const char*) glGetString(GL_RENDERER);
		LOG_INFO( "GL_RENDERER : " << render );
		const char* version = (const char*) glGetString(GL_VERSION);
		LOG_INFO( "GL_VERSION : " << version );
		const char* vendor =(const char*) glGetString(GL_VENDOR);
		LOG_INFO( "GL_VENDOR : " << vendor );
		const char* extensions = (const char*) glGetString(GL_EXTENSIONS);
        std::string str( extensions );
        LOG_INFO("GL_EXTENSIONS :");
        {
            std::string::size_type ppos = 0;
            std::string::size_type pos = str.find(' ');
            while ( pos!=str.npos ) {
                LOG_INFO( str.substr(ppos,pos-ppos) );
                std::string::size_type next = pos+1;
                pos = str.find( ' ', next );
                ppos = next;
                if (pos == str.npos ) {
                    LOG_INFO( str.substr(ppos,str.npos) );
                    break;
                }
            }
        }
		LOG_INFO( "Render size : " << m_width << "x" << m_height );
		
#ifndef GHL_SHADERS_UNSUPPORTED
		m_shaders_support_glsl = ExtensionSupported(extensions,"GL_ARB_shader_objects");
		m_shaders_support_glsl = m_shaders_support_glsl && ExtensionSupported(extensions,"GL_ARB_fragment_shader");
		m_shaders_support_glsl = m_shaders_support_glsl && ExtensionSupported(extensions,"GL_ARB_vertex_shader");
#endif
		
#ifdef GHL_DYNAMIC_GL
        DynamicGLInit();
        DynamicGLLoadSubset();
		
        if (!DinamicGLFeature_VERSION_1_1_Supported()) {
			LOG_WARNING( "!DinamicGLFeature_VERSION_1_1_Supported" );
			//return false;
		}
        
#ifndef GHL_OPENGLES
		if (!DinamicGLFeature_VERSION_1_2_Supported()) {
			LOG_WARNING( "!DinamicGLFeature_VERSION_1_2_Supported" );
			//return false;
		}
		if (!DinamicGLFeature_VERSION_1_3_Supported()) {
			LOG_WARNING( "!DinamicGLFeature_VERSION_1_3_Supported" );
			//return false;
		}
        if (!DinamicGLFeature_VERSION_1_3_DEPRECATED_Supported()) {
			LOG_WARNING( "!DinamicGLFeature_VERSION_1_3_DEPRECATED_Supported" );
			//return false;
		}
		if (!DinamicGLFeature_VERSION_1_4_Supported()) {
			LOG_WARNING( "!DinamicGLFeature_VERSION_1_4_Supported" );
			//return false;
		}
		if (!DinamicGLFeature_VERSION_1_5_Supported()) {
			LOG_WARNING( "!DinamicGLFeature_VERSION_1_4_Supported" );
			//return false;
		}
            
		if (!DinamicGLFeature_EXT_framebuffer_object_Supported()) {
			LOG_WARNING( "!DinamicGLFeature_EXT_framebuffer_object_Supported" );
			//return false;
		}
		if (!DinamicGLFeature_ARB_depth_texture_Supported()) {
			LOG_WARNING( "!DinamicGLFeature_ARB_depth_texture_Supported" );
			//return false;
		}
		if (m_shaders_support_glsl && !DinamicGLFeature_ARB_shader_objects_Supported()) {
			LOG_INFO( "!DinamicGLFeature_ARB_shader_objects_Supported" );
			m_shaders_support_glsl = false;
		}
		if (m_shaders_support_glsl && !DinamicGLFeature_ARB_fragment_shader_Supported()) {
			LOG_INFO( "!DinamicGLFeature_ARB_fragment_shader_Supported" );
			m_shaders_support_glsl = false;
		}
		if (m_shaders_support_glsl && !DinamicGLFeature_ARB_vertex_shader_Supported()) {
			LOG_INFO( "!DinamicGLFeature_ARB_vertex_shader_Supported" );
			m_shaders_support_glsl = false;
		}
#endif	
		
#endif
		
#ifndef GHL_SHADERS_UNSUPPORTED		
#if 0
		m_shaders_support_glsl = false;
#endif
		LOG_INFO( "GLSL shaders " << (m_shaders_support_glsl?"supported":"not supported") );
#endif
        
		glViewport(0, 0, m_width, m_height);
		CHECK_GL_ERROR_F("glViewport");
		CHECK_GL_ERROR_F("glEnable(GL_TEXTURE_2D)");
		set_texture_stage(0);
		glEnable(GL_TEXTURE_2D);
		glClientActiveTexture(GL_TEXTURE0);
		glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_COMBINE);
		CHECK_GL_ERROR_F("glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_COMBINE)");
		set_texture_stage(1);
		glEnable(GL_TEXTURE_2D);
		//glClientActiveTexture(GL_TEXTURE1);
		glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_COMBINE);
		set_texture_stage(0);
		//glClientActiveTexture(GL_TEXTURE0);
		
		CHECK_GL_ERROR_F("glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_COMBINE)");
		glEnableClientState(GL_VERTEX_ARRAY);
		CHECK_GL_ERROR_F("glEnableClientState(GL_VERTEX_ARRAY);");
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		CHECK_GL_ERROR_F("glEnableClientState(GL_TEXTURE_COORD_ARRAY);");
		glEnableClientState(GL_COLOR_ARRAY);
		CHECK_GL_ERROR_F("glEnableClientState(GL_COLOR_ARRAY);");
		
		
		//glClientActiveTexture(GL_TEXTURE0);
		
		glCullFace(GL_BACK);
		CHECK_GL_ERROR_F("glCullFace(GL_BACK);");

#ifndef GHL_OPENGLES
        glReadBuffer(GL_BACK);
        CHECK_GL_ERROR_F("glReadBuffer(GL_BACK);");
#endif
		CHECK_GL_ERROR
		ResetRenderState();
		return RenderImpl::RenderInit();
	}
	
	void RenderOpenGL::RenderDone() {
		ResetRenderState();
	}
	
	bool RenderOpenGL::RenderSetFullScreen(bool fs)
	{
            ///@ todo
            GHL_UNUSED(fs);
            return true;
	}
	
	
	
	
	void GHL_CALL RenderOpenGL::SetViewport(UInt32 x,UInt32 y,UInt32 w,UInt32 h) {
		UInt32 _y = GetHeight()-h-y;
		glViewport(x,_y,w,h);
		CHECK_GL_ERROR
	}
	
	/// setup scisor test
	void GHL_CALL RenderOpenGL::SetupScisor( bool enable, UInt32 x, UInt32 y, UInt32 w, UInt32 h ) {
		if (!enable) {
			glDisable(GL_SCISSOR_TEST);
		} else {
			glEnable(GL_SCISSOR_TEST);
			UInt32 _y = GetHeight()-h-y;
			glScissor(x, _y, w, h);
		}
		CHECK_GL_ERROR
	}
	 
	
		
	/// clear scene
	void GHL_CALL RenderOpenGL::Clear(float r,float g,float b,float a=1.0f) {
		glClearColor(r, g, b, a);
		glClear(GL_COLOR_BUFFER_BIT);
		CHECK_GL_ERROR
	}
	/// clear depth
	void GHL_CALL RenderOpenGL::ClearDepth(float d) {
#ifdef GHL_OPENGLES
            glClearDepthf(d);
#else
            glClearDepth(d);
#endif
		glClear(GL_DEPTH_BUFFER_BIT);
		CHECK_GL_ERROR
	}
	
	
	
	/// create empty texture
	Texture* GHL_CALL RenderOpenGL::CreateTexture(UInt32 width,UInt32 height,TextureFormat fmt,bool mip_maps) {
		TextureOpenGL* tex = new TextureOpenGL(this,fmt,width,height);
		/// @todo
		GHL_UNUSED(mip_maps);
		CHECK_GL_ERROR
#ifdef GHL_DEBUG
		TextureCreated(tex);
#endif
		return tex;
	}
        
	void RenderOpenGL::ReleaseTexture(TextureOpenGL* tex) {
#ifdef GHL_DEBUG
		TextureReleased(tex);
#endif
	}
	
	void RenderOpenGL::RestoreTexture() {
		SetTexture(m_current_texture, 0);
	}

	/// set current texture
	void GHL_CALL RenderOpenGL::SetTexture( const Texture* texture, UInt32 stage) {
		if (stage>=2) return;
		if (stage==0) {
            if (m_current_texture) {
                const_cast<Texture*>(m_current_texture)->Release();
            }
			m_current_texture = texture;
            if (m_current_texture) {
                const_cast<Texture*>(m_current_texture)->AddRef();
            }
        }
		set_texture_stage(stage);
		//glClientActiveTexture(texture_stages[stage]);
		if (texture) {
			const TextureOpenGL* tex = reinterpret_cast<const TextureOpenGL*>(texture);
			{
#ifdef GHL_DEBUG
				if (!CheckTexture(tex)) {
                    LOG_FATAL( "bind unknown texture" );
					assert(false && "bind unknown texture");
					return;
				}
#endif
			}
            glEnable(GL_TEXTURE_2D);
			tex->bind();
		} else {
			glBindTexture(GL_TEXTURE_2D, 0);
            glDisable(GL_TEXTURE_2D);
		}
		set_texture_stage(0);
		//glClientActiveTexture(texture_stages[0]);
		CHECK_GL_ERROR
	}
	/// set texture stage color operation
	void GHL_CALL RenderOpenGL::SetupTextureStageColorOp(TextureOperation op,TextureArgument arg1,TextureArgument arg2,UInt32 stage ) {
		set_texture_stage(stage);
		
		if (op==TEX_OP_DISABLE) {
			glDisable(GL_TEXTURE_2D);
		} else {
			glEnable(GL_TEXTURE_2D);
			glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_COMBINE);
			GLenum src0 = GL_PREVIOUS;
			GLenum op0 = GL_SRC_COLOR;
			conv_texarg(arg1,false,src0,op0);
			GLenum src1 = GL_TEXTURE;
			GLenum op1 = GL_SRC_COLOR;
			conv_texarg(arg2,false,src1,op1);
			if (op==TEX_OP_SELECT_1)
			{
				glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_RGB, GL_REPLACE);
				glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE0_RGB,src0);
				glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND0_RGB,op0);
				
			} else if (op==TEX_OP_SELECT_2)
			{
				glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_RGB, GL_REPLACE);
				glTexEnvi(GL_TEXTURE_ENV,GL_SOURCE0_RGB,src1);
				glTexEnvi(GL_TEXTURE_ENV,GL_OPERAND0_RGB,op1);
				
			} else if (op==TEX_OP_ADD) {
				glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_RGB, GL_ADD);
				glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE0_RGB,src0);
				glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND0_RGB,op0);
				glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE1_RGB,src1);
				glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND1_RGB,op1);
			} else if (op==TEX_OP_MODULATE) {
				glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_RGB, GL_MODULATE);
				glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE0_RGB,src0);
				glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND0_RGB,op0);
				glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE1_RGB,src1);
				glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND1_RGB,op1);
			} else if (op==TEX_OP_INT_DIFFUSE_ALPHA) {
				NOT_IMPLEMENTED;
			} else if (op==TEX_OP_INT_TEXTURE_ALPHA) {
				glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_RGB, GL_INTERPOLATE);
				glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE0_RGB,src0);
				glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND0_RGB,op0);
				glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE1_RGB,src1);
				glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND1_RGB,op1);
				glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE2_RGB,GL_TEXTURE);
				glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND2_RGB,GL_SRC_ALPHA);
			} else if (op==TEX_OP_INT_CURRENT_ALPHA) {
				glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_RGB, GL_INTERPOLATE);
				glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE0_RGB,src0);
				glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND0_RGB,op0);
				glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE1_RGB,src1);
				glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND1_RGB,op1);
				glTexEnvi(GL_TEXTURE_ENV,GL_SOURCE2_RGB,GL_PREVIOUS);
				glTexEnvi(GL_TEXTURE_ENV,GL_OPERAND2_RGB,GL_SRC_ALPHA);
			}
		}
		set_texture_stage(0);
		CHECK_GL_ERROR
	}
	/// set texture stage alpha operation
	void GHL_CALL RenderOpenGL::SetupTextureStageAlphaOp(TextureOperation op,TextureArgument arg1,TextureArgument arg2,UInt32 stage ) {
		//return;
		
		set_texture_stage(stage);
		if (op==TEX_OP_DISABLE) {
			glDisable(GL_TEXTURE_2D);
		} else {
			glEnable(GL_TEXTURE_2D);
			GLenum _arg1 = GL_PREVIOUS;
			GLenum _op1 = GL_SRC_ALPHA;
			conv_texarg(arg1,true,_arg1,_op1);
			GLenum _arg2 = GL_TEXTURE;
			GLenum _op2 = GL_SRC_ALPHA;
			conv_texarg(arg2,true,_arg2,_op2);
			if (op==TEX_OP_SELECT_1) 
			{
				glTexEnvi(GL_TEXTURE_ENV,GL_SOURCE0_ALPHA,_arg1);
				glTexEnvi(GL_TEXTURE_ENV,GL_OPERAND0_ALPHA,_op1);
				glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_ALPHA, GL_REPLACE);
			} else if (op==TEX_OP_SELECT_2) 
			{
				glTexEnvi(GL_TEXTURE_ENV,GL_SOURCE0_ALPHA,_arg2);
				glTexEnvi(GL_TEXTURE_ENV,GL_OPERAND0_ALPHA,_op2);
				glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_ALPHA, GL_REPLACE);
			} else {
				glTexEnvi(GL_TEXTURE_ENV,GL_SOURCE0_ALPHA,_arg1);
				glTexEnvi(GL_TEXTURE_ENV,GL_OPERAND0_ALPHA,_op1);
				glTexEnvi(GL_TEXTURE_ENV,GL_SOURCE1_ALPHA,_arg2);
				glTexEnvi(GL_TEXTURE_ENV,GL_OPERAND1_ALPHA,_op2);
				GLenum mode = GL_MODULATE;
				if (op==TEX_OP_ADD) 
					mode = GL_ADD;
				else if (op==TEX_OP_INT_DIFFUSE_ALPHA) {
					NOT_IMPLEMENTED;
				} else if (op==TEX_OP_INT_TEXTURE_ALPHA) {
					NOT_IMPLEMENTED;
				} else if (op==TEX_OP_INT_CURRENT_ALPHA) {
					NOT_IMPLEMENTED;
				}
				glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_ALPHA, mode);
			}
		}
		set_texture_stage(0);
		CHECK_GL_ERROR
	}
	
	/// set blend factors
	void GHL_CALL RenderOpenGL::SetupBlend(bool enable,BlendFactor src_factor,BlendFactor dst_factor) {
		if (enable) {
			glEnable(GL_BLEND);
			glBlendFunc(convert_blend(src_factor), convert_blend(dst_factor));
		} else {
			glDisable(GL_BLEND);
		}
		CHECK_GL_ERROR
	}
	/// set alpha test parameters
	void GHL_CALL RenderOpenGL::SetupAlphaTest(bool enable,CompareFunc func,float ref=0) {
		if (enable) {
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(conv_compare(func), ref);
		} else {
			glDisable(GL_ALPHA_TEST);
		}
		CHECK_GL_ERROR
	}
	
	/// set depth test
	void GHL_CALL RenderOpenGL::SetupDepthTest(bool enable,CompareFunc func,bool write_enable) {
		if (enable) {
			glEnable(GL_DEPTH_TEST);
			glDepthFunc(conv_compare(func));
		} else {
			glDisable(GL_DEPTH_TEST);
		}
		glDepthMask(write_enable ? GL_TRUE : GL_FALSE);
		CHECK_GL_ERROR
	}
	
	/// setup faces culling
	void GHL_CALL RenderOpenGL::SetupFaceCull(bool enable,bool cw = true) {
		if (enable) {
			glEnable(GL_CULL_FACE);
			glFrontFace( cw ? GL_CW : GL_CCW );
		} else {
			glDisable(GL_CULL_FACE);
		}
		CHECK_GL_ERROR
	}
	
	/// create index buffer
	IndexBuffer* GHL_CALL RenderOpenGL::CreateIndexBuffer(UInt32 size) {
		NOT_IMPLEMENTED;
		/// @todo
		GHL_UNUSED(size);
		return 0;
	}
	
	/// set current index buffer
	void GHL_CALL RenderOpenGL::SetIndexBuffer(const IndexBuffer* buf) {
		if (buf==0) {
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
			CHECK_GL_ERROR
			return;
		}
		///@todo
		NOT_IMPLEMENTED;
	}
	
	/// create vertex buffer
	VertexBuffer* GHL_CALL RenderOpenGL::CreateVertexBuffer(VertexType type,UInt32 size) {
		NOT_IMPLEMENTED;
		/// @todo
		GHL_UNUSED(type);
		GHL_UNUSED(size);
		return 0;
	}
	/// set current vertex buffer
	void GHL_CALL RenderOpenGL::SetVertexBuffer(const VertexBuffer* buf) {
		if (buf==0) {
			glBindBuffer(GL_ARRAY_BUFFER,0);
			CHECK_GL_ERROR
			return;
		}
		NOT_IMPLEMENTED;
	}
	
	/// set projection matrix
	void GHL_CALL RenderOpenGL::SetProjectionMatrix(const float *m) {
        glMatrixMode(GL_PROJECTION);
		glLoadMatrixf(m);
		glMatrixMode(GL_MODELVIEW);
		CHECK_GL_ERROR
	}
	
	/// set view matrix
	void GHL_CALL RenderOpenGL::SetViewMatrix(const float* m) {
		glMatrixMode(GL_MODELVIEW);
		glLoadMatrixf(m);
	}
	
	/// draw primitives
	/**
	 * @par type primitives type
	 * @par v_amount vertices amount used in this call
	 * @par i_begin start index buffer position
	 * @par amount drw primitives amount
	 */
	void GHL_CALL RenderOpenGL::DrawPrimitives(PrimitiveType type,UInt32 v_amount,UInt32 i_begin,UInt32 amount) {
            /// @todo
            GHL_UNUSED(type);
            GHL_UNUSED(v_amount);
            GHL_UNUSED(i_begin);
            GHL_UNUSED(amount);
        NOT_IMPLEMENTED;
	}
	
	/// draw primitives from memory
	void GHL_CALL RenderOpenGL::DrawPrimitivesFromMemory(PrimitiveType type,VertexType v_type,const void* vertices,UInt32 v_amount,const UInt16* indexes,UInt32 prim_amount) {
            /// @todo
            GHL_UNUSED(v_amount);
            UInt32 vertex_size = 0;
		const Vertex* v =  reinterpret_cast<const Vertex*> (vertices);
		//const Vertex2Tex* v2 = 0;
		
		if (v_type == VERTEX_TYPE_SIMPLE) {
			vertex_size = sizeof(Vertex);
		} else if (v_type == VERTEX_TYPE_2_TEX ) {
			vertex_size = sizeof(Vertex2Tex);
			//v2 = reinterpret_cast<const Vertex2Tex*> (vertices);
            NOT_IMPLEMENTED;
            return;
		}
		GLenum element = GL_TRIANGLES;
		UInt32 indexes_amount = prim_amount * 3;
		if (type==PRIMITIVE_TYPE_TRIANGLE_STRIP) {
			element = GL_TRIANGLE_STRIP;
			indexes_amount = prim_amount + 2;
		} else if (type==PRIMITIVE_TYPE_TRIANGLE_FAN) {
			element = GL_TRIANGLE_FAN;
			indexes_amount = prim_amount + 2;
		} else if (type==PRIMITIVE_TYPE_LINES) {
			element = GL_LINES;
			indexes_amount = prim_amount * 2;
		} else if (type==PRIMITIVE_TYPE_LINE_STRIP) {
			element = GL_LINE_STRIP;
			indexes_amount = prim_amount + 1;
		}
		glTexCoordPointer(2, GL_FLOAT, vertex_size, &v->tx);
		glColorPointer(4, GL_UNSIGNED_BYTE, vertex_size, v->color);
		glVertexPointer(2, GL_FLOAT, vertex_size , &v->x);
		glDrawElements(element, indexes_amount, GL_UNSIGNED_SHORT, indexes);
		CHECK_GL_ERROR
	}
	
	
	
	
	
	/// create render target
	RenderTarget* GHL_CALL RenderOpenGL::CreateRenderTarget(UInt32 w,UInt32 h,TextureFormat fmt,bool depth) {
		assert(!m_scene_started);
		CHECK_GL_ERROR_F("before CreateRenderTarget");
		RenderTargetOpenGL* rt = new RenderTargetOpenGL(this,w,h,fmt,depth);
		CHECK_GL_ERROR
		if (!rt->check()) {
			LOG_ERROR( "rendertarget check failed" );
			delete rt;
			rt = 0;
		}
#ifdef GHL_DEBUG	
		RenderTargetCreated( rt );
#endif
		return rt;
	}
		
	void RenderOpenGL::ReleaseRendertarget(RenderTargetOpenGL* rt) {
		CHECK_GL_ERROR
#ifdef GHL_DEBUG
        RenderTargetReleased(rt);
#endif
	}
	
#ifndef GHL_SHADERS_UNSUPPORTED	
	static bool LoadShaderGLSL(GLhandleARB handle,DataStream* ds) {
		ds->Seek(0,F_SEEK_END);
		const UInt32 dsize = ds->Tell();
		ds->Seek(0,F_SEEK_BEGIN);
		std::vector<Byte> buffer(dsize+1);
		buffer.resize(dsize+1);
		ds->Read(&buffer[0],dsize);
		buffer.back()=0;
		const GLcharARB* source[] = {
			reinterpret_cast<const GLcharARB*>(&buffer[0])
		};
		GLint len[] = {dsize};
		glShaderSourceARB(handle,1,source,len);
		glCompileShaderARB(handle);
		GLint res;
		glGetObjectParameterivARB(handle,GL_OBJECT_COMPILE_STATUS_ARB,&res);
		GLcharARB log[512];
		GLsizei size;
		glGetInfoLogARB(handle,512,&size,log);
		log[size]=0;
		LOG_VERBOSE( "shader compile result : " << log );
		if (res!=GL_TRUE)
		{
			return false;
		}
		return true;
	}
#endif
	
	VertexShader* GHL_CALL RenderOpenGL::CreateVertexShader(DataStream* ds) {
#ifndef GHL_SHADERS_UNSUPPORTED
		if (!m_shaders_support_glsl) return 0;
		GLhandleARB handle = glCreateShaderObjectARB(GL_VERTEX_SHADER_ARB);
		if (LoadShaderGLSL(handle,ds)) {
			VertexShaderGLSL* fs = new VertexShaderGLSL(this,handle);
			m_v_shaders_glsl.push_back(fs);
			return fs;
		}
		glDeleteObjectARB(handle);
#endif
		return 0;
	}

#ifndef GHL_SHADERS_UNSUPPORTED
	void RenderOpenGL::ReleaseVertexShader(VertexShaderGLSL* vs) {
		if (!m_shaders_support_glsl) return;
		std::vector<VertexShaderGLSL*>::iterator it = std::find(m_v_shaders_glsl.begin(),m_v_shaders_glsl.end(),vs);
		assert(it!=m_v_shaders_glsl.end() && "release unknown vertex shader");
		if (it!=m_v_shaders_glsl.end()) {
			m_v_shaders_glsl.erase(it);
			delete vs;
		}
	}
#endif
	 
	FragmentShader* GHL_CALL RenderOpenGL::CreateFragmentShader(DataStream* ds) {
#ifndef GHL_SHADERS_UNSUPPORTED
		if (!m_shaders_support_glsl) return 0;
		GLhandleARB handle = glCreateShaderObjectARB(GL_FRAGMENT_SHADER_ARB);
		if (LoadShaderGLSL(handle,ds)) {
			FragmentShaderGLSL* fs = new FragmentShaderGLSL(this,handle);
			m_f_shaders_glsl.push_back(fs);
			return fs;
		}
		glDeleteObjectARB(handle);
#endif
		return 0;
	}
#ifndef GHL_SHADERS_UNSUPPORTED
	void RenderOpenGL::ReleaseFragmentShader(FragmentShaderGLSL* fs) {
		if (!m_shaders_support_glsl) return;
		std::vector<FragmentShaderGLSL*>::iterator it = std::find(m_f_shaders_glsl.begin(),m_f_shaders_glsl.end(),fs);
		assert(it!=m_f_shaders_glsl.end() && "release unknown fragment shader");
		if (it!=m_f_shaders_glsl.end()) {
			m_f_shaders_glsl.erase(it);
			delete fs;
		}
	}
#endif
	
	ShaderProgram* GHL_CALL RenderOpenGL::CreateShaderProgram(VertexShader* v,FragmentShader* f) {
#ifndef GHL_SHADERS_UNSUPPORTED
		if (!m_shaders_support_glsl) return 0;
		GLhandleARB handle = glCreateProgramObjectARB();
		VertexShaderGLSL* vs = reinterpret_cast<VertexShaderGLSL*> (v);
		FragmentShaderGLSL* fs = reinterpret_cast<FragmentShaderGLSL*> (f);
		// @todo check vs ans fs
		glAttachObjectARB(handle, vs->handle());
		glAttachObjectARB(handle, fs->handle());
		glLinkProgramARB(handle);
		GLint res;
		glGetObjectParameterivARB(handle,GL_OBJECT_LINK_STATUS_ARB,&res);
		GLcharARB log[512];
		GLsizei size;
		glGetInfoLogARB(handle,512,&size,log);
		log[size]=0;
		LOG_VERBOSE( "Shader link result : " << log );
		if (res!=GL_TRUE) {
			glDeleteObjectARB(handle);
			return 0;
		}
		ShaderProgramGLSL* prg = new ShaderProgramGLSL(this,handle,vs,fs);
		m_shaders_glsl.push_back(prg);
		return prg;
#else
		return 0;
#endif
	}
#ifndef GHL_SHADERS_UNSUPPORTED
	void RenderOpenGL::ReleaseShaderProgram(ShaderProgramGLSL* sp) {
		if (!m_shaders_support_glsl) return;
		std::vector<ShaderProgramGLSL*>::iterator it = std::find(m_shaders_glsl.begin(),m_shaders_glsl.end(),sp);
		assert(it!=m_shaders_glsl.end() && "release unknown shader program");
		if (it!=m_shaders_glsl.end()) {
			m_shaders_glsl.erase(it);
			delete sp;
		}
	}
#endif
	
	void RenderOpenGL::SetShader(const ShaderProgram* shader) {
#ifndef GHL_SHADERS_UNSUPPORTED
		if (!m_shaders_support_glsl) return;
		if (shader) {
			const ShaderProgramGLSL* sp = reinterpret_cast<const ShaderProgramGLSL*>(shader);
			{
				std::vector<ShaderProgramGLSL*>::iterator it = std::find(m_shaders_glsl.begin(),m_shaders_glsl.end(),sp);
				assert(it!=m_shaders_glsl.end() && "bind unknown shader");
				if (it==m_shaders_glsl.end()) {
					LOG_ERROR( "bind unknown shader" );
					return;
				}
			}
			glUseProgramObjectARB(sp->handle());
		} else {
			glUseProgramObjectARB(0);
		}
		CHECK_GL_ERROR
#endif
	}

	
}

GHL_API GHL::RenderImpl* GHL_CALL GHL_CreateRenderOpenGL(GHL::UInt32 w,GHL::UInt32 h) {
	GHL::RenderOpenGL* render = new GHL::RenderOpenGL(w,h);
	if (!render->RenderInit()) {
		delete render;
		render = 0;	
	}
	return render;
} 
GHL_API void GHL_DestroyRenderOpenGL(GHL::RenderImpl* render_) {
	GHL::RenderOpenGL* render = reinterpret_cast<GHL::RenderOpenGL*>(render_);
	if (render) {
		render->RenderDone();
		delete render;
	}
}

