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
#include <ghl_data_stream.h>
#include "../../ghl_log_impl.h"

#include "rendertarget_opengl.h"
#include "shader_glsl.h"
#include "buffers_opengl.h"

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
	
	RenderOpenGLBase::RenderOpenGLBase(UInt32 w,UInt32 h) : RenderImpl(w,h) {
        m_depth_write_enabled = false;
    }

	RenderOpenGLBase::~RenderOpenGLBase() {
        LOG_VERBOSE("Destructor");
	}

#define NOT_IMPLEMENTED LOG_ERROR( "render openGL function " << __FUNCTION__ << " not implemented" )

	bool RenderOpenGLBase::RenderInit() {
        LOG_INFO("RenderOpenGLBase::RenderInit");
        
        		
        LOG_INFO( "Render size : " << GetRenderWidth() << "x" << GetRenderHeight() );
		
        return RenderImpl::RenderInit();
	}
	
	void RenderOpenGLBase::RenderDone() {
        gl.Release();
		RenderImpl::RenderDone();
	}
	
	bool RenderOpenGLBase::RenderSetFullScreen(bool fs)
	{
            ///@ todo
            GHL_UNUSED(fs);
            return true;
	}
	
    void RenderOpenGLBase::SetOrthoProjection(){
        RenderImpl::SetOrthoProjection();
    }
	
	
    void RenderOpenGLBase::ResetRenderState() {
        RenderImpl::ResetRenderState();
        m_depth_write_enabled = false;
        gl.EnableClientState(gl.VERTEX_ARRAY);
        gl.EnableClientState(gl.COLOR_ARRAY);
        gl.EnableClientState(gl.TEXTURE_COORD_ARRAY);
    }
	
    /// Begin graphics scene (frame)
    void GHL_CALL RenderOpenGLBase::BeginScene(RenderTarget* target) {
        RenderImpl::BeginScene(target);
    }
    
	void GHL_CALL RenderOpenGLBase::SetViewport(UInt32 x,UInt32 y,UInt32 w,UInt32 h) {
		UInt32 _y = GetHeight()-h-y;
		gl.Viewport(x,_y,w,h);
	}
	
	/// setup scisor test
	void GHL_CALL RenderOpenGLBase::SetupScisor( bool enable, UInt32 x, UInt32 y, UInt32 w, UInt32 h ) {
		if (!enable) {
			gl.Disable(gl.SCISSOR_TEST);
		} else {
			gl.Enable(gl.SCISSOR_TEST);
			UInt32 _y = GetHeight()-h-y;
			gl.Scissor(x, _y, w, h);
		}
	}
	 
	
		
	/// clear scene
	void GHL_CALL RenderOpenGLBase::Clear(float r,float g,float b,float a=1.0f) {
		gl.ClearColor(r, g, b, a);
		gl.Clear(gl.COLOR_BUFFER_BIT);
	}
	/// clear depth
	void GHL_CALL RenderOpenGLBase::ClearDepth(float d) {
        if (!m_depth_write_enabled) {
            gl.DepthMask(gl._TRUE);
        }
        gl.ClearDepth(d);
		gl.Clear(gl.DEPTH_BUFFER_BIT);
        if (!m_depth_write_enabled) {
            gl.DepthMask(gl._FALSE);
        }
	}
	
	
	
	/// create empty texture
	Texture* GHL_CALL RenderOpenGLBase::CreateTexture(UInt32 width,UInt32 height,TextureFormat fmt,const Image* data) {
		if ( fmt == TEXTURE_FORMAT_PVRTC_2BPPV1 || fmt == TEXTURE_FORMAT_PVRTC_4BPPV1 ) {
#ifdef GHL_OPENGLES
//			if ( !DinamicGLFeature_IMG_texture_compression_pvrtc_Supported() ) {
//				return 0;
//			}
//			if ( !data )
				return 0;
#else
			return 0;
#endif
		}
		TextureOpenGL* tex = TextureOpenGL::Create(this,fmt,width,height,data);
		if (!tex) return tex;
		return tex;
	}
	
	void RenderOpenGLBase::RestoreTexture() {
		SetTexture(GetTexture(0), 0);
	}

	/// set current texture
	void GHL_CALL RenderOpenGLBase::SetTexture( const Texture* texture, UInt32 stage) {
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
		
	/// set blend factors
	void GHL_CALL RenderOpenGLBase::SetupBlend(bool enable,BlendFactor src_factor,BlendFactor dst_factor) {
		if (enable) {
			gl.Enable(gl.BLEND);
			gl.BlendFunc(convert_blend(gl,src_factor), convert_blend(gl,dst_factor));
		} else {
			gl.Disable(gl.BLEND);
		}
	}
	/// set alpha test parameters
	void GHL_CALL RenderOpenGLBase::SetupAlphaTest(bool enable,CompareFunc func,float ref=0) {
		if (enable) {
			gl.Enable(gl.ALPHA_TEST);
			gl.AlphaFunc(conv_compare(gl,func), ref);
		} else {
			gl.Disable(gl.ALPHA_TEST);
		}
	}
	
	/// set depth test
	void GHL_CALL RenderOpenGLBase::SetupDepthTest(bool enable,CompareFunc func,bool write_enable) {
		if (enable) {
			gl.Enable(gl.DEPTH_TEST);
			gl.DepthFunc(conv_compare(gl,func));
		} else {
			gl.Disable(gl.DEPTH_TEST);
		}
		gl.DepthMask(write_enable ?gl._TRUE :gl._FALSE);
        m_depth_write_enabled = write_enable;
	}
	
	/// setup faces culling
	void GHL_CALL RenderOpenGLBase::SetupFaceCull(bool enable,bool cw = true) {
		if (enable) {
			gl.Enable(gl.CULL_FACE);
			gl.FrontFace( cw ?gl.CW :gl.CCW );
		} else {
			gl.Disable(gl.CULL_FACE);
		}
	}
	
	/// create index buffer
	IndexBuffer* GHL_CALL RenderOpenGLBase::CreateIndexBuffer(UInt32 size) {
		if (gl.vboapi.valid) {
            GL::GLuint name;
            gl.vboapi.GenBuffers(1,&name);
            return new IndexBufferOpenGL(this,size, name);
        }
        return new SoftIndexBuffer(this,size);
	}
	
	/// set current index buffer
	void GHL_CALL RenderOpenGLBase::SetIndexBuffer(const IndexBuffer* buf) {
        RenderImpl::SetIndexBuffer(buf);
        if (gl.vboapi.valid) {
            if (buf) {
                reinterpret_cast<const IndexBufferOpenGL*>(buf)->bind();
            } else {
                gl.vboapi.BindBuffer(gl.vboapi.ELEMENT_ARRAY_BUFFER,0);
            }
        }
	}
	
	/// create vertex buffer
	VertexBuffer* GHL_CALL RenderOpenGLBase::CreateVertexBuffer(VertexType type,UInt32 size) {
		if (gl.vboapi.valid) {
            GL::GLuint name;
            gl.vboapi.GenBuffers(1,&name);
            return new VertexBufferOpenGL(this, type, size, name);
        } 
		return new SoftVertexBuffer(this,type,size);
	}
	/// set current vertex buffer
	void GHL_CALL RenderOpenGLBase::SetVertexBuffer(const VertexBuffer* buf) {
		RenderImpl::SetVertexBuffer(buf);
        if (gl.vboapi.valid) {
            if (buf) {
                reinterpret_cast<const VertexBufferOpenGL*>(buf)->bind();
            } else {
                gl.vboapi.BindBuffer(gl.vboapi.ARRAY_BUFFER,0);
            }
        } 
	}
	
	/// set projection matrix
	void GHL_CALL RenderOpenGLBase::SetProjectionMatrix(const float *m) {
        gl.MatrixMode(gl.PROJECTION);
		gl.LoadMatrixf(m);
		gl.MatrixMode(gl.MODELVIEW);
	}
	
	/// set view matrix
	void GHL_CALL RenderOpenGLBase::SetViewMatrix(const float* m) {
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
	void GHL_CALL RenderOpenGLBase::DrawPrimitives(PrimitiveType type,UInt32 v_amount,UInt32 i_begin,UInt32 prim_amount) {
        const VertexBuffer* vb = GetVertexBuffer();
        if (!vb) {
            LOG_ERROR("DrawPrimitives without vertex buffer");
            return;
        }
        const IndexBuffer* ib = GetIndexBuffer();
        if (!ib) {
            LOG_ERROR("DrawPrimitives without index buffer");
            return;
        }
        VertexType v_type = vb->GetType();
        /// @todo
        GHL_UNUSED(v_amount);
        UInt32 vertex_size = 0;
		const Vertex* v =  reinterpret_cast<const Vertex*> (0);
		
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
        
        
        if (gl.vboapi.valid) {
            gl.TexCoordPointer(2,gl.FLOAT, vertex_size, &v->tx);
            gl.ColorPointer(4,gl.UNSIGNED_BYTE, vertex_size, v->color);
            gl.VertexPointer(3,gl.FLOAT, vertex_size , &v->x);
            gl.DrawElements(element, indexes_amount,gl.UNSIGNED_SHORT, (void*)(i_begin*sizeof(UInt16)));
        } else {
            const SoftVertexBuffer* sv = static_cast<const SoftVertexBuffer*>(vb);
            const SoftIndexBuffer* si = static_cast<const SoftIndexBuffer*>(ib);
            const Vertex* v =  reinterpret_cast<const Vertex*> (sv->GetData());
            gl.TexCoordPointer(2,gl.FLOAT, vertex_size, &v->tx);
            gl.ColorPointer(4,gl.UNSIGNED_BYTE, vertex_size, v->color);
            gl.VertexPointer(3,gl.FLOAT, vertex_size , &v->x);
            const UInt16* bi = reinterpret_cast<const UInt16*>(si->GetData());
            gl.DrawElements(element, indexes_amount,gl.UNSIGNED_SHORT, bi+i_begin);
        }
        
		
	}
	
	/// draw primitives from memory
	void GHL_CALL RenderOpenGLBase::DrawPrimitivesFromMemory(PrimitiveType type,VertexType v_type,const void* vertices,UInt32 v_amount,const UInt16* indexes,UInt32 prim_amount) {
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
        gl.VertexPointer(3,gl.FLOAT, vertex_size , &v->x);
        gl.DrawElements(element, indexes_amount,gl.UNSIGNED_SHORT, indexes);
	}
	
	
	
	
	
	/// create render target
	RenderTarget* GHL_CALL RenderOpenGLBase::CreateRenderTarget(UInt32 w,UInt32 h,TextureFormat fmt,bool depth) {
		assert(!IsSceneStarted());
		RenderTargetOpenGL* rt = new RenderTargetOpenGL(this,w,h,fmt,depth);
		if (!rt->check()) {
			LOG_ERROR( "rendertarget check failed" );
			delete rt;
			rt = 0;
		}
		return rt;
	}
    
	
	static bool LoadShaderGLSL(const GL& gl,GL::GLhandle handle,const Data* ds) {
        if (!gl.sdrapi.valid) return false;
        const GL::GLchar* source[] = {
			reinterpret_cast<const GL::GLchar*>(ds->GetData())
		};
        GL::GLint len[] = {ds->GetSize()};
		gl.sdrapi.ShaderSource(handle,1,source,len);
		gl.sdrapi.CompileShader(handle);
		GL::GLint res;
		gl.sdrapi.GetShaderiv(handle,gl.sdrapi.COMPILE_STATUS,&res);
        if (res!=GL::_TRUE)
		{
            GL::GLchar log[512];
            GL::GLsizei size = 0;
            gl.sdrapi.GetShaderInfoLog(handle,512,&size,log);
            log[size]=0;
            LOG_VERBOSE( "shader compile result : " << log );
            
            return false;
		}
		return true;
	}
	
	VertexShader* GHL_CALL RenderOpenGLBase::CreateVertexShader(const Data* ds) {
        if (!gl.sdrapi.valid) return 0;
		 GL::GLhandle handle = gl.sdrapi.CreateShader(gl.sdrapi.VERTEX_SHADER);
		if (LoadShaderGLSL(gl,handle,ds)) {
			VertexShaderGLSL* fs = new VertexShaderGLSL(this,handle);
			return fs;
		}
		gl.sdrapi.DeleteShader(handle);
		return 0;
	}


	 
	FragmentShader* GHL_CALL RenderOpenGLBase::CreateFragmentShader(const Data* ds) {
        if (!gl.sdrapi.valid) return 0;
		 GL::GLhandle handle = gl.sdrapi.CreateShader(gl.sdrapi.FRAGMENT_SHADER);
		if (LoadShaderGLSL(gl,handle,ds)) {
			FragmentShaderGLSL* fs = new FragmentShaderGLSL(this,handle);
			return fs;
		}
		gl.sdrapi.DeleteShader(handle);
		return 0;
	}

	
	ShaderProgram* GHL_CALL RenderOpenGLBase::CreateShaderProgram(VertexShader* v,FragmentShader* f) {
        if (!gl.sdrapi.valid) return 0;
        if (!v || !f) return 0;
        GL::GLhandle handle = gl.sdrapi.CreateProgram();
		VertexShaderGLSL* vs = reinterpret_cast<VertexShaderGLSL*> (v);
		FragmentShaderGLSL* fs = reinterpret_cast<FragmentShaderGLSL*> (f);
		// @todo check vs ans fs
		gl.sdrapi.AttachShader(handle, vs->handle());
		gl.sdrapi.AttachShader(handle, fs->handle());
		gl.sdrapi.LinkProgram(handle);
        GL::GLint res;
		gl.sdrapi.GetProgramiv(handle,gl.sdrapi.LINK_STATUS,&res);
        if (res!=GL::_TRUE) {
            GL::GLchar log[512];
            GL::GLsizei size;
            gl.sdrapi.GetProgramInfoLog(handle,512,&size,log);
            log[size]=0;
            LOG_VERBOSE( "Shader link result : " << log );
            
            gl.sdrapi.DeleteProgram(handle);
			return 0;
		}
		ShaderProgramGLSL* prg = new ShaderProgramGLSL(this,handle,vs,fs);
		return prg;
	}

	
	void RenderOpenGLBase::SetShader(const ShaderProgram* shader) {
        RenderImpl::SetShader(shader);
        if (!gl.sdrapi.valid) return;
		if (shader) {
			const ShaderProgramGLSL* sp = reinterpret_cast<const ShaderProgramGLSL*>(shader);
			gl.sdrapi.UseProgram(sp->handle());
		} else {
			gl.sdrapi.UseProgram(0);
		}
	}

    
    RenderOpenGLFFPL::RenderOpenGLFFPL(UInt32 w,UInt32 h) : RenderOpenGLBase(w,h) {
        
    }
    
    /// set texture stage color operation
	void GHL_CALL RenderOpenGLFFPL::SetupTextureStageColorOp(TextureOperation op,TextureArgument arg1,TextureArgument arg2,UInt32 stage ) {
		set_texture_stage(gl,stage);
		
		if (op==TEX_OP_DISABLE) {
			gl.Disable(gl.TEXTURE_2D);
		} else {
			gl.Enable(gl.TEXTURE_2D);
			gl.TexEnvi(gl.TEXTURE_ENV,gl.TEXTURE_ENV_MODE,glffpl.COMBINE);
			GL::GLenum src0 = gl.PREVIOUS;
			GL::GLenum op0 = gl.SRC_COLOR;
			conv_texarg(gl,arg1,false,src0,op0);
			GL::GLenum src1 = gl.TEXTURE;
			GL::GLenum op1 = gl.SRC_COLOR;
			conv_texarg(gl,arg2,false,src1,op1);
			if (op==TEX_OP_SELECT_1)
			{
				gl.TexEnvi(gl.TEXTURE_ENV, glffpl.COMBINE_RGB,gl.REPLACE);
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.SOURCE0_RGB,src0);
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.OPERAND0_RGB,op0);
				
			} else if (op==TEX_OP_SELECT_2)
			{
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.COMBINE_RGB,gl.REPLACE);
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.SOURCE0_RGB,src1);
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.OPERAND0_RGB,op1);
				
			} else if (op==TEX_OP_ADD) {
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.COMBINE_RGB,gl.ADD);
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.SOURCE0_RGB,src0);
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.OPERAND0_RGB,op0);
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.SOURCE1_RGB,src1);
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.OPERAND1_RGB,op1);
			} else if (op==TEX_OP_MODULATE) {
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.COMBINE_RGB,gl.MODULATE);
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.SOURCE0_RGB,src0);
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.OPERAND0_RGB,op0);
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.SOURCE1_RGB,src1);
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.OPERAND1_RGB,op1);
			} else if (op==TEX_OP_INT_DIFFUSE_ALPHA) {
				NOT_IMPLEMENTED;
			} else if (op==TEX_OP_INT_TEXTURE_ALPHA) {
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.COMBINE_RGB,glffpl.INTERPOLATE);
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.SOURCE0_RGB,src0);
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.OPERAND0_RGB,op0);
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.SOURCE1_RGB,src1);
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.OPERAND1_RGB,op1);
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.SOURCE2_RGB,gl.TEXTURE);
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.OPERAND2_RGB,gl.SRC_ALPHA);
			} else if (op==TEX_OP_INT_CURRENT_ALPHA) {
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.COMBINE_RGB,glffpl.INTERPOLATE);
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.SOURCE0_RGB,src0);
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.OPERAND0_RGB,op0);
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.SOURCE1_RGB,src1);
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.OPERAND1_RGB,op1);
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.SOURCE2_RGB,gl.PREVIOUS);
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.OPERAND2_RGB,gl.SRC_ALPHA);
			}
		}
		set_texture_stage(gl,0);
	}
	/// set texture stage alpha operation
	void GHL_CALL RenderOpenGLFFPL::SetupTextureStageAlphaOp(TextureOperation op,TextureArgument arg1,TextureArgument arg2,UInt32 stage ) {
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
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.SOURCE0_ALPHA,_arg1);
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.OPERAND0_ALPHA,_op1);
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.COMBINE_ALPHA,gl.REPLACE);
			} else if (op==TEX_OP_SELECT_2)
			{
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.SOURCE0_ALPHA,_arg2);
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.OPERAND0_ALPHA,_op2);
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.COMBINE_ALPHA,gl.REPLACE);
			} else {
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.SOURCE0_ALPHA,_arg1);
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.OPERAND0_ALPHA,_op1);
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.SOURCE1_ALPHA,_arg2);
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.OPERAND1_ALPHA,_op2);
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
				gl.TexEnvi(gl.TEXTURE_ENV,glffpl.COMBINE_ALPHA, mode);
			}
		}
		set_texture_stage(gl,0);
	}
    
    
    
    RenderOpenGLPPL::RenderOpenGLPPL(UInt32 w,UInt32 h) : RenderOpenGLBase(w,h) {
        
    }
    
    bool RenderOpenGLPPL::RenderInit() {
        LOG_INFO("RenderOpenGL2::RenderInit");
        if (!gl.sdrapi.valid)
            return false;
        if (!RenderOpenGLBase::RenderInit())
            return false;
        m_generator.init(this);
        m_shaders_render.init(&m_generator);
        for (UInt32 i=0;i<MAX_TEXTURE_STAGES;++i) {
            m_crnt_state.texture_stages[i].tex.all = 0;
        }
        return true;
    }
    
    void RenderOpenGLPPL::RenderDone() {
        m_shaders_render.done();
        RenderOpenGLBase::RenderDone();
    }
    
    void RenderOpenGLPPL::ResetRenderState() {
        RenderOpenGLBase::ResetRenderState();
        
    }
    
    void GHL_CALL RenderOpenGLPPL::SetTexture(const Texture* texture, UInt32 stage ) {
        RenderOpenGLBase::SetTexture(texture, stage);
        if (texture) {
            m_crnt_state.texture_stages[stage].rgb.c.texture = true;
            m_crnt_state.texture_stages[stage].alpha.c.texture = HaveAlpha(texture);
        } else {
            m_crnt_state.texture_stages[stage].rgb.c.texture = false;
            m_crnt_state.texture_stages[stage].alpha.c.texture = false;
        }
    }
    
    /// set texture stage color operation
    void GHL_CALL RenderOpenGLPPL::SetupTextureStageColorOp(TextureOperation op,TextureArgument arg1,TextureArgument arg2,UInt32 stage ) {
        m_crnt_state.texture_stages[stage].rgb.c.operation = op;
        m_crnt_state.texture_stages[stage].rgb.c.arg_1 = arg1;
        m_crnt_state.texture_stages[stage].rgb.c.arg_2 = arg2;
    }
    
    /// set texture stage alpha operation
    void GHL_CALL RenderOpenGLPPL::SetupTextureStageAlphaOp(TextureOperation op,TextureArgument arg1,TextureArgument arg2,UInt32 stage ) {
        m_crnt_state.texture_stages[stage].alpha.c.operation = op;
        m_crnt_state.texture_stages[stage].alpha.c.arg_1 = arg1;
        m_crnt_state.texture_stages[stage].alpha.c.arg_2 = arg2;
    }
    
    void GHL_CALL RenderOpenGLPPL::SetShader(const ShaderProgram* shader)  {
        RenderOpenGLBase::SetShader(shader);
        m_shaders_render.set_shader(shader);
    }
    void RenderOpenGLPPL::DoDrawPrimitives(VertexType v_type) {
        ShaderProgram* prg = m_shaders_render.get_shader(m_crnt_state, v_type==VERTEX_TYPE_2_TEX);
        if (prg) {
            RenderOpenGLBase::SetShader(prg);
            for (size_t i=0;i<MAX_TEXTURE_STAGES;++i) {
                if (m_crnt_state.texture_stages[i].rgb.c.texture) {
                    char uf[64];
                    ::snprintf(uf, 64, "texture_%d",int(i));
                    ShaderUniform* uniform = prg->GetUniform(uf);
                    if (uniform) {
                        uniform->SetValueInt(i);
                    }
                }
            }
        }
    }
    void GHL_CALL RenderOpenGLPPL::DrawPrimitives(PrimitiveType type,UInt32 v_amount,UInt32 i_begin,UInt32 amount) {
        const VertexBuffer* vb = GetVertexBuffer();
        if (!vb) {
            LOG_ERROR("DrawPrimitives without vertex buffer");
            return;
        }
        const IndexBuffer* ib = GetIndexBuffer();
        if (!ib) {
            LOG_ERROR("DrawPrimitives without index buffer");
            return;
        }
        DoDrawPrimitives(vb->GetType());
        RenderOpenGLBase::DrawPrimitives(type, v_amount, i_begin, amount);
    }
    
    void GHL_CALL RenderOpenGLPPL::DrawPrimitivesFromMemory(PrimitiveType type,VertexType v_type,const void* vertices,UInt32 v_amount,const UInt16* indexes,UInt32 prim_amoun) {
        DoDrawPrimitives(v_type);
        RenderOpenGLBase::DrawPrimitivesFromMemory(type, v_type, vertices, v_amount, indexes, prim_amoun);
    }
    
    

}



