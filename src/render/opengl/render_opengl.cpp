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
	
	static const GL::GLenum texture_stages[] = {
		GL::TEXTURE0,
		GL::TEXTURE1,
		GL::TEXTURE2,
		GL::TEXTURE3,
	};
	
	static void set_texture_stage(UInt32 stage) {
        static UInt32 oldStage = 1000;
        if (oldStage!=stage) {
            gl.ActiveTexture(texture_stages[stage]);
            oldStage=stage;
        }
	}
	
	static inline GL::GLenum convert_blend(BlendFactor bf ) {
		if (bf==BLEND_FACTOR_SRC_COLOR)
			return GL::SRC_COLOR;
		if (bf==BLEND_FACTOR_SRC_COLOR_INV)
			return GL::ONE_MINUS_SRC_COLOR;
		if (bf==BLEND_FACTOR_SRC_ALPHA)
			return GL::SRC_ALPHA;
		if (bf==BLEND_FACTOR_SRC_ALPHA_INV)
			return GL::ONE_MINUS_SRC_ALPHA;
		if (bf==BLEND_FACTOR_DST_COLOR)
			return GL::DST_COLOR;
		if (bf==BLEND_FACTOR_DST_COLOR_INV)
			return GL::ONE_MINUS_DST_COLOR;
		if (bf==BLEND_FACTOR_DST_ALPHA)
			return GL::DST_ALPHA;
		if (bf==BLEND_FACTOR_DST_ALPHA_INV)
			return GL::ONE_MINUS_DST_ALPHA;
		if (bf==BLEND_FACTOR_ZERO)
			return GL::ZERO;
		return GL::ONE;
	}
	
	static inline GL::GLenum conv_compare(CompareFunc f) {
		if (f==COMPARE_FUNC_LESS)
			return GL::LESS;
		if (f==COMPARE_FUNC_GREATER)
			return GL::GREATER;
		if (f==COMPARE_FUNC_EQUAL)
			return GL::EQUAL;
		if (f==COMPARE_FUNC_ALWAYS)
			return GL::ALWAYS;
		if (f==COMPARE_FUNC_NEQUAL)
			return GL::NOTEQUAL;
		if (f==COMPARE_FUNC_GEQUAL)
			return GL::GEQUAL;
		if (f==COMPARE_FUNC_LEQUAL)
			return GL::LEQUAL;
		return GL::NEVER;
	}
	
	static inline void conv_texarg(TextureArgument f,bool alpha,GL::GLenum& arg,GL::GLenum& op) {
		if (f==TEX_ARG_CURRENT) {
			arg = GL::PREVIOUS;
			op = alpha ? GL::SRC_ALPHA : GL::SRC_COLOR;
		} else if (f==TEX_ARG_DIFFUSE) {
			arg = GL::PRIMARY_COLOR;
			op = alpha ? GL::SRC_ALPHA : GL::SRC_COLOR;
		} else if (f==TEX_ARG_TEXTURE) {
			arg = GL::TEXTURE;
			op = alpha ? GL::SRC_ALPHA : GL::SRC_COLOR;
		}else if (f==TEX_ARG_CURRENT_INV) {
			arg = GL::PREVIOUS;
			op = alpha ? GL::ONE_MINUS_SRC_ALPHA : GL::ONE_MINUS_SRC_COLOR;
		} else if (f==TEX_ARG_DIFFUSE_INV) {
			arg = GL::PRIMARY_COLOR;
			op = alpha ? GL::ONE_MINUS_SRC_ALPHA : GL::ONE_MINUS_SRC_COLOR;
		} else if (f==TEX_ARG_TEXTURE_INV) {
			arg = GL::TEXTURE;
			op = alpha ? GL::ONE_MINUS_SRC_ALPHA : GL::ONE_MINUS_SRC_COLOR;
		}
	}
	
	RenderOpenGL::RenderOpenGL(UInt32 w,UInt32 h) : RenderImpl(w,h) {
#ifndef GHL_SHADERS_UNSUPPORTED
		m_shaders_support_glsl = false;
#endif
	}

	RenderOpenGL::~RenderOpenGL() {
        gl.DynamicGLFinish();
        LOG_VERBOSE("Destructor");
	}

#define NOT_IMPLEMENTED LOG_ERROR( "render openGL function " << __FUNCTION__ << " not implemented" )

	bool	RenderOpenGL::ExtensionSupported(const char* all,const char* ext) const {
		return strstr(all,ext)!=0;
	}
	bool RenderOpenGL::RenderInit() {
        LOG_INFO("RenderOpenGL::RenderInit");
		gl.DynamicGLInit();
		if (!gl.DinamicGLFeature_CORE_Supported()) {
			LOG_ERROR( "!DinamicGLFeature_CORE_Supported" );
			return false;
		}
		const char* render = (const char*) gl.GetString(GL::RENDERER);
		LOG_INFO( "GL_RENDERER : " << render );
		const char* version = (const char*) gl.GetString(GL::VERSION);
		LOG_INFO( "GL_VERSION : " << version );
		const char* vendor =(const char*) gl.GetString(GL::VENDOR);
		LOG_INFO( "GL_VENDOR : " << vendor );
		const char* extensions = (const char*) gl.GetString(GL::EXTENSIONS);
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
		LOG_INFO( "Render size : " << GetRenderWidth() << "x" << GetRenderHeight() );
		
#ifndef GHL_SHADERS_UNSUPPORTED
		m_shaders_support_glsl = ExtensionSupported(extensions,"GL_ARB_shader_objects");
		m_shaders_support_glsl = m_shaders_support_glsl && ExtensionSupported(extensions,"GL_ARB_fragment_shader");
		m_shaders_support_glsl = m_shaders_support_glsl && ExtensionSupported(extensions,"GL_ARB_vertex_shader");
#endif
		
        
#ifndef GHL_OPENGLES
		if (!gl.DinamicGLFeature_VERSION_1_2_Supported()) {
			LOG_WARNING( "!DinamicGLFeature_VERSION_1_2_Supported" );
			//return false;
		}
		if (!gl.DinamicGLFeature_VERSION_1_3_Supported()) {
			LOG_WARNING( "!DinamicGLFeature_VERSION_1_3_Supported" );
			//return false;
		}
//        if (!gl.DinamicGLFeature_VERSION_1_3_Supported()) {
//			LOG_WARNING( "!DinamicGLFeature_VERSION_1_3_DEPRECATED_Supported" );
//			//return false;
//		}
		if (!gl.DinamicGLFeature_VERSION_1_4_Supported()) {
			LOG_WARNING( "!DinamicGLFeature_VERSION_1_4_Supported" );
			//return false;
		}
		if (!gl.DinamicGLFeature_VERSION_1_5_Supported()) {
			LOG_WARNING( "!DinamicGLFeature_VERSION_1_4_Supported" );
			//return false;
		}
            
		if (!gl.DinamicGLFeature_EXT_framebuffer_object_Supported()) {
			LOG_WARNING( "!DinamicGLFeature_EXT_framebuffer_object_Supported" );
			//return false;
		}
		if (!gl.DinamicGLFeature_ARB_depth_texture_Supported()) {
			LOG_WARNING( "!DinamicGLFeature_ARB_depth_texture_Supported" );
			//return false;
		}
		if (m_shaders_support_glsl && !gl.DinamicGLFeature_ARB_shader_objects_Supported()) {
			LOG_INFO( "!DinamicGLFeature_ARB_shader_objects_Supported" );
			m_shaders_support_glsl = false;
		}
		if (m_shaders_support_glsl && !gl.DinamicGLFeature_ARB_fragment_shader_Supported()) {
			LOG_INFO( "!DinamicGLFeature_ARB_fragment_shader_Supported" );
			m_shaders_support_glsl = false;
		}
		if (m_shaders_support_glsl && !gl.DinamicGLFeature_ARB_vertex_shader_Supported()) {
			LOG_INFO( "!DinamicGLFeature_ARB_vertex_shader_Supported" );
			m_shaders_support_glsl = false;
		}
#endif	
				
#ifndef GHL_SHADERS_UNSUPPORTED		
#if 0
		m_shaders_support_glsl = false;
#endif
		LOG_INFO( "GLSL shaders " << (m_shaders_support_glsl?"supported":"not supported") );
#endif
        
		gl.Viewport(0, 0, GetRenderWidth(), GetRenderHeight());
		set_texture_stage(0);
		gl.Enable(GL::TEXTURE_2D);
		gl.ClientActiveTexture(GL::TEXTURE0);
		gl.TexEnvi(GL::TEXTURE_ENV,GL::TEXTURE_ENV_MODE,GL::COMBINE);
		set_texture_stage(1);
		gl.Enable(GL::TEXTURE_2D);
		gl.TexEnvi(GL::TEXTURE_ENV,GL::TEXTURE_ENV_MODE,GL::COMBINE);
		set_texture_stage(0);
		
		gl.EnableClientState(GL::VERTEX_ARRAY);
		gl.EnableClientState(GL::TEXTURE_COORD_ARRAY);
		gl.EnableClientState(GL::COLOR_ARRAY);
		
		gl.CullFace(GL::BACK);
		
#ifndef GHL_OPENGLES
        gl.ReadBuffer(GL::BACK);
#endif
		ResetRenderState();
		return RenderImpl::RenderInit();
	}
	
	void RenderOpenGL::RenderDone() {
		RenderImpl::RenderDone();
	}
	
	bool RenderOpenGL::RenderSetFullScreen(bool fs)
	{
            ///@ todo
            GHL_UNUSED(fs);
            return true;
	}
	
	
	
	
	void GHL_CALL RenderOpenGL::SetViewport(UInt32 x,UInt32 y,UInt32 w,UInt32 h) {
		UInt32 _y = GetHeight()-h-y;
		gl.Viewport(x,_y,w,h);
	}
	
	/// setup scisor test
	void GHL_CALL RenderOpenGL::SetupScisor( bool enable, UInt32 x, UInt32 y, UInt32 w, UInt32 h ) {
		if (!enable) {
			gl.Disable(GL::SCISSOR_TEST);
		} else {
			gl.Enable(GL::SCISSOR_TEST);
			UInt32 _y = GetHeight()-h-y;
			gl.Scissor(x, _y, w, h);
		}
	}
	 
	
		
	/// clear scene
	void GHL_CALL RenderOpenGL::Clear(float r,float g,float b,float a=1.0f) {
		gl.ClearColor(r, g, b, a);
		gl.Clear(GL::COLOR_BUFFER_BIT);
	}
	/// clear depth
	void GHL_CALL RenderOpenGL::ClearDepth(float d) {
        gl.ClearDepth(d);
		gl.Clear(GL::DEPTH_BUFFER_BIT);
	}
	
	
	
	/// create empty texture
	Texture* GHL_CALL RenderOpenGL::CreateTexture(UInt32 width,UInt32 height,TextureFormat fmt,const Data* data) {
		if ( fmt == TEXTURE_FORMAT_PVRTC_2BPPV1 || fmt == TEXTURE_FORMAT_PVRTC_4BPPV1 ) {
#ifdef GHL_OPENGLES
			if ( !DinamicGLFeature_IMG_texture_compression_pvrtc_Supported() ) {
				return 0;
			}
			if ( !data )
				return 0;
#else
			return 0;
#endif
		}
		TextureOpenGL* tex = TextureOpenGL::Create(this,fmt,width,height,data);
		if (!tex) return tex;
		return tex;
	}
	
	void RenderOpenGL::RestoreTexture() {
		SetTexture(GetTexture(0), 0);
	}

	/// set current texture
	void GHL_CALL RenderOpenGL::SetTexture( const Texture* texture, UInt32 stage) {
        RenderImpl::SetTexture(texture, stage);
		set_texture_stage(stage);
		//glClientActiveTexture(texture_stages[stage]);
		if (texture) {
			const TextureOpenGL* tex = reinterpret_cast<const TextureOpenGL*>(texture);
            gl.Enable(GL::TEXTURE_2D);
			tex->bind();
		} else {
			gl.BindTexture(GL::TEXTURE_2D, 0);
            gl.Disable(GL::TEXTURE_2D);
		}
		set_texture_stage(0);
	}
	/// set texture stage color operation
	void GHL_CALL RenderOpenGL::SetupTextureStageColorOp(TextureOperation op,TextureArgument arg1,TextureArgument arg2,UInt32 stage ) {
		set_texture_stage(stage);
		
		if (op==TEX_OP_DISABLE) {
			gl.Disable(GL::TEXTURE_2D);
		} else {
			gl.Enable(GL::TEXTURE_2D);
			gl.TexEnvi(GL::TEXTURE_ENV,GL::TEXTURE_ENV_MODE,GL::COMBINE);
			GL::GLenum src0 = GL::PREVIOUS;
			GL::GLenum op0 = GL::SRC_COLOR;
			conv_texarg(arg1,false,src0,op0);
			GL::GLenum src1 = GL::TEXTURE;
			GL::GLenum op1 = GL::SRC_COLOR;
			conv_texarg(arg2,false,src1,op1);
			if (op==TEX_OP_SELECT_1)
			{
				gl.TexEnvi(GL::TEXTURE_ENV, GL::COMBINE_RGB, GL::REPLACE);
				gl.TexEnvi(GL::TEXTURE_ENV, GL::SOURCE0_RGB,src0);
				gl.TexEnvi(GL::TEXTURE_ENV, GL::OPERAND0_RGB,op0);
				
			} else if (op==TEX_OP_SELECT_2)
			{
				gl.TexEnvi(GL::TEXTURE_ENV, GL::COMBINE_RGB, GL::REPLACE);
				gl.TexEnvi(GL::TEXTURE_ENV,GL::SOURCE0_RGB,src1);
				gl.TexEnvi(GL::TEXTURE_ENV,GL::OPERAND0_RGB,op1);
				
			} else if (op==TEX_OP_ADD) {
				gl.TexEnvi(GL::TEXTURE_ENV, GL::COMBINE_RGB, GL::ADD);
				gl.TexEnvi(GL::TEXTURE_ENV, GL::SOURCE0_RGB,src0);
				gl.TexEnvi(GL::TEXTURE_ENV, GL::OPERAND0_RGB,op0);
				gl.TexEnvi(GL::TEXTURE_ENV, GL::SOURCE1_RGB,src1);
				gl.TexEnvi(GL::TEXTURE_ENV, GL::OPERAND1_RGB,op1);
			} else if (op==TEX_OP_MODULATE) {
				gl.TexEnvi(GL::TEXTURE_ENV, GL::COMBINE_RGB, GL::MODULATE);
				gl.TexEnvi(GL::TEXTURE_ENV, GL::SOURCE0_RGB,src0);
				gl.TexEnvi(GL::TEXTURE_ENV, GL::OPERAND0_RGB,op0);
				gl.TexEnvi(GL::TEXTURE_ENV, GL::SOURCE1_RGB,src1);
				gl.TexEnvi(GL::TEXTURE_ENV, GL::OPERAND1_RGB,op1);
			} else if (op==TEX_OP_INT_DIFFUSE_ALPHA) {
				NOT_IMPLEMENTED;
			} else if (op==TEX_OP_INT_TEXTURE_ALPHA) {
				gl.TexEnvi(GL::TEXTURE_ENV, GL::COMBINE_RGB, GL::INTERPOLATE);
				gl.TexEnvi(GL::TEXTURE_ENV, GL::SOURCE0_RGB,src0);
				gl.TexEnvi(GL::TEXTURE_ENV, GL::OPERAND0_RGB,op0);
				gl.TexEnvi(GL::TEXTURE_ENV, GL::SOURCE1_RGB,src1);
				gl.TexEnvi(GL::TEXTURE_ENV, GL::OPERAND1_RGB,op1);
				gl.TexEnvi(GL::TEXTURE_ENV, GL::SOURCE2_RGB,GL::TEXTURE);
				gl.TexEnvi(GL::TEXTURE_ENV, GL::OPERAND2_RGB,GL::SRC_ALPHA);
			} else if (op==TEX_OP_INT_CURRENT_ALPHA) {
				gl.TexEnvi(GL::TEXTURE_ENV, GL::COMBINE_RGB, GL::INTERPOLATE);
				gl.TexEnvi(GL::TEXTURE_ENV, GL::SOURCE0_RGB,src0);
				gl.TexEnvi(GL::TEXTURE_ENV, GL::OPERAND0_RGB,op0);
				gl.TexEnvi(GL::TEXTURE_ENV, GL::SOURCE1_RGB,src1);
				gl.TexEnvi(GL::TEXTURE_ENV, GL::OPERAND1_RGB,op1);
				gl.TexEnvi(GL::TEXTURE_ENV, GL::SOURCE2_RGB,GL::PREVIOUS);
				gl.TexEnvi(GL::TEXTURE_ENV, GL::OPERAND2_RGB,GL::SRC_ALPHA);
			}
		}
		set_texture_stage(0);
	}
	/// set texture stage alpha operation
	void GHL_CALL RenderOpenGL::SetupTextureStageAlphaOp(TextureOperation op,TextureArgument arg1,TextureArgument arg2,UInt32 stage ) {
		//return;
		
		set_texture_stage(stage);
		if (op==TEX_OP_DISABLE) {
			gl.Disable(GL::TEXTURE_2D);
		} else {
			gl.Enable(GL::TEXTURE_2D);
            GL::GLenum _arg1 = GL::PREVIOUS;
            GL::GLenum _op1 = GL::SRC_ALPHA;
			conv_texarg(arg1,true,_arg1,_op1);
			GL::GLenum _arg2 = GL::TEXTURE;
			GL::GLenum _op2 = GL::SRC_ALPHA;
			conv_texarg(arg2,true,_arg2,_op2);
			if (op==TEX_OP_SELECT_1) 
			{
				gl.TexEnvi(GL::TEXTURE_ENV, GL::SOURCE0_ALPHA,_arg1);
				gl.TexEnvi(GL::TEXTURE_ENV, GL::OPERAND0_ALPHA,_op1);
				gl.TexEnvi(GL::TEXTURE_ENV, GL::COMBINE_ALPHA, GL::REPLACE);
			} else if (op==TEX_OP_SELECT_2) 
			{
				gl.TexEnvi(GL::TEXTURE_ENV, GL::SOURCE0_ALPHA,_arg2);
				gl.TexEnvi(GL::TEXTURE_ENV, GL::OPERAND0_ALPHA,_op2);
				gl.TexEnvi(GL::TEXTURE_ENV, GL::COMBINE_ALPHA, GL::REPLACE);
			} else {
				gl.TexEnvi(GL::TEXTURE_ENV,GL::SOURCE0_ALPHA,_arg1);
				gl.TexEnvi(GL::TEXTURE_ENV,GL::OPERAND0_ALPHA,_op1);
				gl.TexEnvi(GL::TEXTURE_ENV,GL::SOURCE1_ALPHA,_arg2);
				gl.TexEnvi(GL::TEXTURE_ENV,GL::OPERAND1_ALPHA,_op2);
                GL::GLenum mode = GL::MODULATE;
				if (op==TEX_OP_ADD) 
					mode = GL::ADD;
				else if (op==TEX_OP_INT_DIFFUSE_ALPHA) {
					NOT_IMPLEMENTED;
				} else if (op==TEX_OP_INT_TEXTURE_ALPHA) {
					NOT_IMPLEMENTED;
				} else if (op==TEX_OP_INT_CURRENT_ALPHA) {
					NOT_IMPLEMENTED;
				}
				gl.TexEnvi(GL::TEXTURE_ENV, GL::COMBINE_ALPHA, mode);
			}
		}
		set_texture_stage(0);
	}
	
	/// set blend factors
	void GHL_CALL RenderOpenGL::SetupBlend(bool enable,BlendFactor src_factor,BlendFactor dst_factor) {
		if (enable) {
			gl.Enable(GL::BLEND);
			gl.BlendFunc(convert_blend(src_factor), convert_blend(dst_factor));
		} else {
			gl.Disable(GL::BLEND);
		}
	}
	/// set alpha test parameters
	void GHL_CALL RenderOpenGL::SetupAlphaTest(bool enable,CompareFunc func,float ref=0) {
		if (enable) {
			gl.Enable(GL::ALPHA_TEST);
			gl.AlphaFunc(conv_compare(func), ref);
		} else {
			gl.Disable(GL::ALPHA_TEST);
		}
	}
	
	/// set depth test
	void GHL_CALL RenderOpenGL::SetupDepthTest(bool enable,CompareFunc func,bool write_enable) {
		if (enable) {
			gl.Enable(GL::DEPTH_TEST);
			gl.DepthFunc(conv_compare(func));
		} else {
			gl.Disable(GL::DEPTH_TEST);
		}
		gl.DepthMask(write_enable ? GL::TRUE : GL::FALSE);
	}
	
	/// setup faces culling
	void GHL_CALL RenderOpenGL::SetupFaceCull(bool enable,bool cw = true) {
		if (enable) {
			gl.Enable(GL::CULL_FACE);
			gl.FrontFace( cw ? GL::CW : GL::CCW );
		} else {
			gl.Disable(GL::CULL_FACE);
		}
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
			gl.BindBuffer(GL::ELEMENT_ARRAY_BUFFER,0);
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
			gl.BindBuffer(GL::ARRAY_BUFFER,0);
			return;
		}
		NOT_IMPLEMENTED;
	}
	
	/// set projection matrix
	void GHL_CALL RenderOpenGL::SetProjectionMatrix(const float *m) {
        gl.MatrixMode(GL::PROJECTION);
		gl.LoadMatrixf(m);
		gl.MatrixMode(GL::MODELVIEW);
	}
	
	/// set view matrix
	void GHL_CALL RenderOpenGL::SetViewMatrix(const float* m) {
		gl.MatrixMode(GL::MODELVIEW);
		gl.LoadMatrixf(m);
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
        GL::GLenum element = GL::TRIANGLES;
		UInt32 indexes_amount = prim_amount * 3;
		if (type==PRIMITIVE_TYPE_TRIANGLE_STRIP) {
			element = GL::TRIANGLE_STRIP;
			indexes_amount = prim_amount + 2;
		} else if (type==PRIMITIVE_TYPE_TRIANGLE_FAN) {
			element = GL::TRIANGLE_FAN;
			indexes_amount = prim_amount + 2;
		} else if (type==PRIMITIVE_TYPE_LINES) {
			element = GL::LINES;
			indexes_amount = prim_amount * 2;
		} else if (type==PRIMITIVE_TYPE_LINE_STRIP) {
			element = GL::LINE_STRIP;
			indexes_amount = prim_amount + 1;
		}
		gl.TexCoordPointer(2, GL::FLOAT, vertex_size, &v->tx);
		gl.ColorPointer(4, GL::UNSIGNED_BYTE, vertex_size, v->color);
		gl.VertexPointer(2, GL::FLOAT, vertex_size , &v->x);
		gl.DrawElements(element, indexes_amount, GL::UNSIGNED_SHORT, indexes);
	}
	
	
	
	
	
	/// create render target
	RenderTarget* GHL_CALL RenderOpenGL::CreateRenderTarget(UInt32 w,UInt32 h,TextureFormat fmt,bool depth) {
		assert(!IsSceneStarted());
		RenderTargetOpenGL* rt = new RenderTargetOpenGL(this,w,h,fmt,depth);
		if (!rt->check()) {
			LOG_ERROR( "rendertarget check failed" );
			delete rt;
			rt = 0;
		}
		return rt;
	}
	
#ifndef GHL_SHADERS_UNSUPPORTED	
	static bool LoadShaderGLSL(GL::GLhandleARB handle,DataStream* ds) {
		ds->Seek(0,F_SEEK_END);
		const UInt32 dsize = ds->Tell();
		ds->Seek(0,F_SEEK_BEGIN);
		std::vector<Byte> buffer(dsize+1);
		buffer.resize(dsize+1);
		ds->Read(&buffer[0],dsize);
		buffer.back()=0;
		const GL::GLcharARB* source[] = {
			reinterpret_cast<const GL::GLcharARB*>(&buffer[0])
		};
        GL::GLint len[] = {dsize};
		gl.ShaderSourceARB(handle,1,source,len);
		gl.CompileShaderARB(handle);
		GL::GLint res;
		gl.GetObjectParameterivARB(handle,GL::OBJECT_COMPILE_STATUS_ARB,&res);
		GL::GLcharARB log[512];
		GL::GLsizei size;
		gl.GetInfoLogARB(handle,512,&size,log);
		log[size]=0;
		LOG_VERBOSE( "shader compile result : " << log );
		if (res!=GL::TRUE)
		{
			return false;
		}
		return true;
	}
#endif
	
	VertexShader* GHL_CALL RenderOpenGL::CreateVertexShader(DataStream* ds) {
#ifndef GHL_SHADERS_UNSUPPORTED
		if (!m_shaders_support_glsl) return 0;
        GL::GLhandleARB handle = gl.CreateShaderObjectARB(GL::VERTEX_SHADER_ARB);
		if (LoadShaderGLSL(handle,ds)) {
			VertexShaderGLSL* fs = new VertexShaderGLSL(this,handle);
			return fs;
		}
		gl.DeleteObjectARB(handle);
#endif
		return 0;
	}


	 
	FragmentShader* GHL_CALL RenderOpenGL::CreateFragmentShader(DataStream* ds) {
#ifndef GHL_SHADERS_UNSUPPORTED
		if (!m_shaders_support_glsl) return 0;
        GL::GLhandleARB handle = gl.CreateShaderObjectARB(GL::FRAGMENT_SHADER_ARB);
		if (LoadShaderGLSL(handle,ds)) {
			FragmentShaderGLSL* fs = new FragmentShaderGLSL(this,handle);
			return fs;
		}
		gl.DeleteObjectARB(handle);
#endif
		return 0;
	}

	
	ShaderProgram* GHL_CALL RenderOpenGL::CreateShaderProgram(VertexShader* v,FragmentShader* f) {
#ifndef GHL_SHADERS_UNSUPPORTED
		if (!m_shaders_support_glsl) return 0;
        GL::GLhandleARB handle = gl.CreateProgramObjectARB();
		VertexShaderGLSL* vs = reinterpret_cast<VertexShaderGLSL*> (v);
		FragmentShaderGLSL* fs = reinterpret_cast<FragmentShaderGLSL*> (f);
		// @todo check vs ans fs
		gl.AttachObjectARB(handle, vs->handle());
		gl.AttachObjectARB(handle, fs->handle());
		gl.LinkProgramARB(handle);
        GL::GLint res;
		gl.GetObjectParameterivARB(handle,GL::OBJECT_LINK_STATUS_ARB,&res);
        GL::GLcharARB log[512];
		GL::GLsizei size;
		gl.GetInfoLogARB(handle,512,&size,log);
		log[size]=0;
		LOG_VERBOSE( "Shader link result : " << log );
		if (res!=GL::TRUE) {
			gl.DeleteObjectARB(handle);
			return 0;
		}
		ShaderProgramGLSL* prg = new ShaderProgramGLSL(this,handle,vs,fs);
		return prg;
#else
		return 0;
#endif
	}

	
	void RenderOpenGL::SetShader(const ShaderProgram* shader) {
        RenderImpl::SetShader(shader);
#ifndef GHL_SHADERS_UNSUPPORTED
		if (!m_shaders_support_glsl) return;
		if (shader) {
			const ShaderProgramGLSL* sp = reinterpret_cast<const ShaderProgramGLSL*>(shader);
			gl.UseProgramObjectARB(sp->handle());
		} else {
			gl.UseProgramObjectARB(0);
		}
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

