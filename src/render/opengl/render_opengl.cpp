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

#include "dynamic/dynamic_gl.h"

#include <cstdio>
#include <cctype>

#include <algorithm>
#include <cassert>

namespace GHL {

    static const char* MODULE = "RENDER:OpenGL";
	
	
	
	static void set_texture_stage(const GL& gl,UInt32 stage) {
        GL::GLenum texture_stages[] = {
            gl.TEXTURE0,
            gl.TEXTURE1,
            gl.TEXTURE2,
            gl.TEXTURE3,
        };
        static UInt32 oldStage = 1000;
        if (oldStage!=stage) {
            gl.ActiveTexture(texture_stages[stage]);
            oldStage=stage;
        }
	}
	
	static inline GL::GLenum convert_blend(const GL& gl,BlendFactor bf ) {
		if (bf==BLEND_FACTOR_SRC_COLOR)
			return gl.SRC_COLOR;
		if (bf==BLEND_FACTOR_SRC_COLOR_INV)
			return gl.ONE_MINUS_SRC_COLOR;
		if (bf==BLEND_FACTOR_SRC_ALPHA)
			return gl.SRC_ALPHA;
		if (bf==BLEND_FACTOR_SRC_ALPHA_INV)
			return gl.ONE_MINUS_SRC_ALPHA;
		if (bf==BLEND_FACTOR_DST_COLOR)
			return gl.DST_COLOR;
		if (bf==BLEND_FACTOR_DST_COLOR_INV)
			return gl.ONE_MINUS_DST_COLOR;
		if (bf==BLEND_FACTOR_DST_ALPHA)
			return gl.DST_ALPHA;
		if (bf==BLEND_FACTOR_DST_ALPHA_INV)
			return gl.ONE_MINUS_DST_ALPHA;
		if (bf==BLEND_FACTOR_ZERO)
			return gl.ZERO;
		return gl.ONE;
	}
	
	static inline GL::GLenum conv_compare(const GL& gl,CompareFunc f) {
		if (f==COMPARE_FUNC_LESS)
			return gl.LESS;
		if (f==COMPARE_FUNC_GREATER)
			return gl.GREATER;
		if (f==COMPARE_FUNC_EQUAL)
			return gl.EQUAL;
		if (f==COMPARE_FUNC_ALWAYS)
			return gl.ALWAYS;
		if (f==COMPARE_FUNC_NEQUAL)
			return gl.NOTEQUAL;
		if (f==COMPARE_FUNC_GEQUAL)
			return gl.GEQUAL;
		if (f==COMPARE_FUNC_LEQUAL)
			return gl.LEQUAL;
		return gl.NEVER;
	}
	
	static inline void conv_texarg(const GL& gl,TextureArgument f,bool alpha,GL::GLenum& arg,GL::GLenum& op) {
		if (f==TEX_ARG_CURRENT) {
			arg = gl.PREVIOUS;
			op = alpha ? gl.SRC_ALPHA : gl.SRC_COLOR;
		} else if (f==TEX_ARG_DIFFUSE) {
			arg = gl.PRIMARY_COLOR;
			op = alpha ? gl.SRC_ALPHA : gl.SRC_COLOR;
		} else if (f==TEX_ARG_TEXTURE) {
			arg = gl.TEXTURE;
			op = alpha ? gl.SRC_ALPHA : gl.SRC_COLOR;
		}else if (f==TEX_ARG_CURRENT_INV) {
			arg = gl.PREVIOUS;
			op = alpha ? gl.ONE_MINUS_SRC_ALPHA : gl.ONE_MINUS_SRC_COLOR;
		} else if (f==TEX_ARG_DIFFUSE_INV) {
			arg = gl.PRIMARY_COLOR;
			op = alpha ? gl.ONE_MINUS_SRC_ALPHA : gl.ONE_MINUS_SRC_COLOR;
		} else if (f==TEX_ARG_TEXTURE_INV) {
			arg = gl.TEXTURE;
			op = alpha ? gl.ONE_MINUS_SRC_ALPHA : gl.ONE_MINUS_SRC_COLOR;
		}
	}
	
	RenderOpenGL::RenderOpenGL(UInt32 w,UInt32 h) : RenderImpl(w,h) {
	}

	RenderOpenGL::~RenderOpenGL() {
        LOG_VERBOSE("Destructor");
	}

#define NOT_IMPLEMENTED LOG_ERROR( "render openGL function " << __FUNCTION__ << " not implemented" )

	bool RenderOpenGL::RenderInit() {
        LOG_INFO("RenderOpenGL::RenderInit");
        if (!GLApi::InitGL(&gl)) {
            return false;
        }
        if (!GLApi::InitGLffpl(&gl)) {
            return false;
        }
        		
        LOG_INFO( "Render size : " << GetRenderWidth() << "x" << GetRenderHeight() );
		
        return RenderImpl::RenderInit();
	}
	
	void RenderOpenGL::RenderDone() {
        gl.Release();
		RenderImpl::RenderDone();
	}
	
	bool RenderOpenGL::RenderSetFullScreen(bool fs)
	{
            ///@ todo
            GHL_UNUSED(fs);
            return true;
	}
	
    void RenderOpenGL::SetOrthoProjection(){
        gl.MatrixMode(gl.PROJECTION);
        gl.LoadIdentity();
        gl.Ortho(0,GetWidth(),GetHeight(),0,-1.0,1.0);
        gl.MatrixMode(gl.MODELVIEW);
        gl.LoadIdentity();
    }
	
	
    void RenderOpenGL::ResetRenderState() {
        RenderImpl::ResetRenderState();
        gl.EnableClientState(gl.VERTEX_ARRAY);
        gl.EnableClientState(gl.COLOR_ARRAY);
        gl.EnableClientState(gl.TEXTURE_COORD_ARRAY);
    }
	
    /// Begin graphics scene (frame)
    void GHL_CALL RenderOpenGL::BeginScene(RenderTarget* target) {
        RenderImpl::BeginScene(target);
    }
    
	void GHL_CALL RenderOpenGL::SetViewport(UInt32 x,UInt32 y,UInt32 w,UInt32 h) {
		UInt32 _y = GetHeight()-h-y;
		gl.Viewport(x,_y,w,h);
	}
	
	/// setup scisor test
	void GHL_CALL RenderOpenGL::SetupScisor( bool enable, UInt32 x, UInt32 y, UInt32 w, UInt32 h ) {
		if (!enable) {
			gl.Disable(gl.SCISSOR_TEST);
		} else {
			gl.Enable(gl.SCISSOR_TEST);
			UInt32 _y = GetHeight()-h-y;
			gl.Scissor(x, _y, w, h);
		}
	}
	 
	
		
	/// clear scene
	void GHL_CALL RenderOpenGL::Clear(float r,float g,float b,float a=1.0f) {
		gl.ClearColor(r, g, b, a);
		gl.Clear(gl.COLOR_BUFFER_BIT);
	}
	/// clear depth
	void GHL_CALL RenderOpenGL::ClearDepth(float d) {
        gl.ClearDepth(d);
		gl.Clear(gl.DEPTH_BUFFER_BIT);
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
		set_texture_stage(gl,stage);
		//glClientActiveTexture(texture_stages[stage]);
		if (texture) {
			const TextureOpenGL* tex = reinterpret_cast<const TextureOpenGL*>(texture);
            gl.Enable(gl.TEXTURE_2D);
			tex->bind();
		} else {
			gl.BindTexture(gl.TEXTURE_2D, 0);
            gl.Disable(gl.TEXTURE_2D);
		}
		set_texture_stage(gl,0);
	}
	/// set texture stage color operation
	void GHL_CALL RenderOpenGL::SetupTextureStageColorOp(TextureOperation op,TextureArgument arg1,TextureArgument arg2,UInt32 stage ) {
		set_texture_stage(gl,stage);
		
		if (op==TEX_OP_DISABLE) {
			gl.Disable(gl.TEXTURE_2D);
		} else {
			gl.Enable(gl.TEXTURE_2D);
			gl.TexEnvi(gl.TEXTURE_ENV,gl.TEXTURE_ENV_MODE,gl.COMBINE);
			GL::GLenum src0 = gl.PREVIOUS;
			GL::GLenum op0 = gl.SRC_COLOR;
			conv_texarg(gl,arg1,false,src0,op0);
			GL::GLenum src1 = gl.TEXTURE;
			GL::GLenum op1 = gl.SRC_COLOR;
			conv_texarg(gl,arg2,false,src1,op1);
			if (op==TEX_OP_SELECT_1)
			{
				gl.TexEnvi(gl.TEXTURE_ENV, gl.COMBINE_RGB,gl.REPLACE);
				gl.TexEnvi(gl.TEXTURE_ENV,gl.SOURCE0_RGB,src0);
				gl.TexEnvi(gl.TEXTURE_ENV,gl.OPERAND0_RGB,op0);
				
			} else if (op==TEX_OP_SELECT_2)
			{
				gl.TexEnvi(gl.TEXTURE_ENV,gl.COMBINE_RGB,gl.REPLACE);
				gl.TexEnvi(gl.TEXTURE_ENV,gl.SOURCE0_RGB,src1);
				gl.TexEnvi(gl.TEXTURE_ENV,gl.OPERAND0_RGB,op1);
				
			} else if (op==TEX_OP_ADD) {
				gl.TexEnvi(gl.TEXTURE_ENV,gl.COMBINE_RGB,gl.ADD);
				gl.TexEnvi(gl.TEXTURE_ENV,gl.SOURCE0_RGB,src0);
				gl.TexEnvi(gl.TEXTURE_ENV,gl.OPERAND0_RGB,op0);
				gl.TexEnvi(gl.TEXTURE_ENV,gl.SOURCE1_RGB,src1);
				gl.TexEnvi(gl.TEXTURE_ENV,gl.OPERAND1_RGB,op1);
			} else if (op==TEX_OP_MODULATE) {
				gl.TexEnvi(gl.TEXTURE_ENV,gl.COMBINE_RGB,gl.MODULATE);
				gl.TexEnvi(gl.TEXTURE_ENV,gl.SOURCE0_RGB,src0);
				gl.TexEnvi(gl.TEXTURE_ENV,gl.OPERAND0_RGB,op0);
				gl.TexEnvi(gl.TEXTURE_ENV,gl.SOURCE1_RGB,src1);
				gl.TexEnvi(gl.TEXTURE_ENV,gl.OPERAND1_RGB,op1);
			} else if (op==TEX_OP_INT_DIFFUSE_ALPHA) {
				NOT_IMPLEMENTED;
			} else if (op==TEX_OP_INT_TEXTURE_ALPHA) {
				gl.TexEnvi(gl.TEXTURE_ENV,gl.COMBINE_RGB,gl.INTERPOLATE);
				gl.TexEnvi(gl.TEXTURE_ENV,gl.SOURCE0_RGB,src0);
				gl.TexEnvi(gl.TEXTURE_ENV,gl.OPERAND0_RGB,op0);
				gl.TexEnvi(gl.TEXTURE_ENV,gl.SOURCE1_RGB,src1);
				gl.TexEnvi(gl.TEXTURE_ENV,gl.OPERAND1_RGB,op1);
				gl.TexEnvi(gl.TEXTURE_ENV,gl.SOURCE2_RGB,gl.TEXTURE);
				gl.TexEnvi(gl.TEXTURE_ENV,gl.OPERAND2_RGB,gl.SRC_ALPHA);
			} else if (op==TEX_OP_INT_CURRENT_ALPHA) {
				gl.TexEnvi(gl.TEXTURE_ENV,gl.COMBINE_RGB,gl.INTERPOLATE);
				gl.TexEnvi(gl.TEXTURE_ENV,gl.SOURCE0_RGB,src0);
				gl.TexEnvi(gl.TEXTURE_ENV,gl.OPERAND0_RGB,op0);
				gl.TexEnvi(gl.TEXTURE_ENV,gl.SOURCE1_RGB,src1);
				gl.TexEnvi(gl.TEXTURE_ENV,gl.OPERAND1_RGB,op1);
				gl.TexEnvi(gl.TEXTURE_ENV,gl.SOURCE2_RGB,gl.PREVIOUS);
				gl.TexEnvi(gl.TEXTURE_ENV,gl.OPERAND2_RGB,gl.SRC_ALPHA);
			}
		}
		set_texture_stage(gl,0);
	}
	/// set texture stage alpha operation
	void GHL_CALL RenderOpenGL::SetupTextureStageAlphaOp(TextureOperation op,TextureArgument arg1,TextureArgument arg2,UInt32 stage ) {
		//return;
		
		set_texture_stage(gl,stage);
		if (op==TEX_OP_DISABLE) {
			gl.Disable(gl.TEXTURE_2D);
		} else {
			gl.Enable(gl.TEXTURE_2D);
           GL::GLenum _arg1 =gl.PREVIOUS;
           GL::GLenum _op1 =gl.SRC_ALPHA;
			conv_texarg(gl,arg1,true,_arg1,_op1);
			GL::GLenum _arg2 =gl.TEXTURE;
			GL::GLenum _op2 =gl.SRC_ALPHA;
			conv_texarg(gl,arg2,true,_arg2,_op2);
			if (op==TEX_OP_SELECT_1) 
			{
				gl.TexEnvi(gl.TEXTURE_ENV,gl.SOURCE0_ALPHA,_arg1);
				gl.TexEnvi(gl.TEXTURE_ENV,gl.OPERAND0_ALPHA,_op1);
				gl.TexEnvi(gl.TEXTURE_ENV,gl.COMBINE_ALPHA,gl.REPLACE);
			} else if (op==TEX_OP_SELECT_2) 
			{
				gl.TexEnvi(gl.TEXTURE_ENV,gl.SOURCE0_ALPHA,_arg2);
				gl.TexEnvi(gl.TEXTURE_ENV,gl.OPERAND0_ALPHA,_op2);
				gl.TexEnvi(gl.TEXTURE_ENV,gl.COMBINE_ALPHA,gl.REPLACE);
			} else {
				gl.TexEnvi(gl.TEXTURE_ENV,gl.SOURCE0_ALPHA,_arg1);
				gl.TexEnvi(gl.TEXTURE_ENV,gl.OPERAND0_ALPHA,_op1);
				gl.TexEnvi(gl.TEXTURE_ENV,gl.SOURCE1_ALPHA,_arg2);
				gl.TexEnvi(gl.TEXTURE_ENV,gl.OPERAND1_ALPHA,_op2);
               GL::GLenum mode =gl.MODULATE;
				if (op==TEX_OP_ADD) 
					mode =gl.ADD;
				else if (op==TEX_OP_INT_DIFFUSE_ALPHA) {
					NOT_IMPLEMENTED;
				} else if (op==TEX_OP_INT_TEXTURE_ALPHA) {
					NOT_IMPLEMENTED;
				} else if (op==TEX_OP_INT_CURRENT_ALPHA) {
					NOT_IMPLEMENTED;
				}
				gl.TexEnvi(gl.TEXTURE_ENV,gl.COMBINE_ALPHA, mode);
			}
		}
		set_texture_stage(gl,0);
	}
	
	/// set blend factors
	void GHL_CALL RenderOpenGL::SetupBlend(bool enable,BlendFactor src_factor,BlendFactor dst_factor) {
		if (enable) {
			gl.Enable(gl.BLEND);
			gl.BlendFunc(convert_blend(gl,src_factor), convert_blend(gl,dst_factor));
		} else {
			gl.Disable(gl.BLEND);
		}
	}
	/// set alpha test parameters
	void GHL_CALL RenderOpenGL::SetupAlphaTest(bool enable,CompareFunc func,float ref=0) {
		if (enable) {
			gl.Enable(gl.ALPHA_TEST);
			gl.AlphaFunc(conv_compare(gl,func), ref);
		} else {
			gl.Disable(gl.ALPHA_TEST);
		}
	}
	
	/// set depth test
	void GHL_CALL RenderOpenGL::SetupDepthTest(bool enable,CompareFunc func,bool write_enable) {
		if (enable) {
			gl.Enable(gl.DEPTH_TEST);
			gl.DepthFunc(conv_compare(gl,func));
		} else {
			gl.Disable(gl.DEPTH_TEST);
		}
		gl.DepthMask(write_enable ?gl.TRUE :gl.FALSE);
	}
	
	/// setup faces culling
	void GHL_CALL RenderOpenGL::SetupFaceCull(bool enable,bool cw = true) {
		if (enable) {
			gl.Enable(gl.CULL_FACE);
			gl.FrontFace( cw ?gl.CW :gl.CCW );
		} else {
			gl.Disable(gl.CULL_FACE);
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
			//gl.BindBuffer(gl.ELEMENT_ARRAY_BUFFER,0);
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
			//gl.BindBuffer(gl.ARRAY_BUFFER,0);
			return;
		}
		NOT_IMPLEMENTED;
	}
	
	/// set projection matrix
	void GHL_CALL RenderOpenGL::SetProjectionMatrix(const float *m) {
        gl.MatrixMode(gl.PROJECTION);
		gl.LoadMatrixf(m);
		gl.MatrixMode(gl.MODELVIEW);
	}
	
	/// set view matrix
	void GHL_CALL RenderOpenGL::SetViewMatrix(const float* m) {
		gl.MatrixMode(gl.MODELVIEW);
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
       GL::GLenum element =gl.TRIANGLES;
		UInt32 indexes_amount = prim_amount * 3;
		if (type==PRIMITIVE_TYPE_TRIANGLE_STRIP) {
			element =gl.TRIANGLE_STRIP;
			indexes_amount = prim_amount + 2;
		} else if (type==PRIMITIVE_TYPE_TRIANGLE_FAN) {
			element =gl.TRIANGLE_FAN;
			indexes_amount = prim_amount + 2;
		} else if (type==PRIMITIVE_TYPE_LINES) {
			element =gl.LINES;
			indexes_amount = prim_amount * 2;
		} else if (type==PRIMITIVE_TYPE_LINE_STRIP) {
			element =gl.LINE_STRIP;
			indexes_amount = prim_amount + 1;
		}
		gl.TexCoordPointer(2,gl.FLOAT, vertex_size, &v->tx);
		gl.ColorPointer(4,gl.UNSIGNED_BYTE, vertex_size, v->color);
		gl.VertexPointer(2,gl.FLOAT, vertex_size , &v->x);
		gl.DrawElements(element, indexes_amount,gl.UNSIGNED_SHORT, indexes);
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
    
	
	static bool LoadShaderGLSL(const GL& gl,GL::GLhandle handle,DataStream* ds) {
        if (!gl.sdrapi) return false;
		ds->Seek(0,F_SEEK_END);
		const UInt32 dsize = ds->Tell();
		ds->Seek(0,F_SEEK_BEGIN);
		std::vector<Byte> buffer(dsize+1);
		buffer.resize(dsize+1);
		ds->Read(&buffer[0],dsize);
		buffer.back()=0;
        const GL::GLchar* source[] = {
			reinterpret_cast<GL::GLchar*>(&buffer[0])
		};
        GL::GLint len[] = {dsize};
		gl.sdrapi->ShaderSource(handle,1,source,len);
		gl.sdrapi->CompileShader(handle);
		GL::GLint res;
		gl.sdrapi->GetObjectParameteriv(handle,gl.sdrapi->OBJECT_COMPILE_STATUS,&res);
		GL::GLchar log[512];
		GL::GLsizei size;
		gl.sdrapi->GetInfoLog(handle,512,&size,log);
		log[size]=0;
		LOG_VERBOSE( "shader compile result : " << log );
		if (res!=GL::TRUE)
		{
			return false;
		}
		return true;
	}
	
	VertexShader* GHL_CALL RenderOpenGL::CreateVertexShader(DataStream* ds) {
        if (!gl.sdrapi) return 0;
		 GL::GLhandle handle = gl.sdrapi->CreateShaderObject(gl.sdrapi->VERTEX_SHADER_ARB);
		if (LoadShaderGLSL(gl,handle,ds)) {
			VertexShaderGLSL* fs = new VertexShaderGLSL(this,handle);
			return fs;
		}
		gl.sdrapi->DeleteObject(handle);
		return 0;
	}


	 
	FragmentShader* GHL_CALL RenderOpenGL::CreateFragmentShader(DataStream* ds) {
        if (!gl.sdrapi) return 0;
		 GL::GLhandle handle = gl.sdrapi->CreateShaderObject(gl.sdrapi->FRAGMENT_SHADER);
		if (LoadShaderGLSL(gl,handle,ds)) {
			FragmentShaderGLSL* fs = new FragmentShaderGLSL(this,handle);
			return fs;
		}
		gl.sdrapi->DeleteObject(handle);
		return 0;
	}

	
	ShaderProgram* GHL_CALL RenderOpenGL::CreateShaderProgram(VertexShader* v,FragmentShader* f) {
        if (!gl.sdrapi) return 0;
        GL::GLhandle handle = gl.sdrapi->CreateProgramObject();
		VertexShaderGLSL* vs = reinterpret_cast<VertexShaderGLSL*> (v);
		FragmentShaderGLSL* fs = reinterpret_cast<FragmentShaderGLSL*> (f);
		// @todo check vs ans fs
		gl.sdrapi->AttachObject(handle, vs->handle());
		gl.sdrapi->AttachObject(handle, fs->handle());
		gl.sdrapi->LinkProgram(handle);
        GL::GLint res;
		gl.sdrapi->GetObjectParameteriv(handle,gl.sdrapi->OBJECT_LINK_STATUS,&res);
        GL::GLchar log[512];
		GL::GLsizei size;
		gl.sdrapi->GetInfoLog(handle,512,&size,log);
		log[size]=0;
		LOG_VERBOSE( "Shader link result : " << log );
		if (res!=GL::TRUE) {
			gl.sdrapi->DeleteObject(handle);
			return 0;
		}
		ShaderProgramGLSL* prg = new ShaderProgramGLSL(this,handle,vs,fs);
		return prg;
	}

	
	void RenderOpenGL::SetShader(const ShaderProgram* shader) {
        RenderImpl::SetShader(shader);
        if (!gl.sdrapi) return;
		if (shader) {
			const ShaderProgramGLSL* sp = reinterpret_cast<const ShaderProgramGLSL*>(shader);
			gl.sdrapi->UseProgramObject(sp->handle());
		} else {
			gl.sdrapi->UseProgramObject(0);
		}
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

