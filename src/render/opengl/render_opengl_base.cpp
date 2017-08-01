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

#ifdef _MSC_VER
#define snprintf _snprintf
#endif

void gl_error_report_bp() {
    (void)0;
}

namespace GHL {

    static const char* MODULE = "RENDER:OpenGL";
	
    const GL::GLboolean GL::_TRUE = 1;
    const GL::GLboolean GL::_FALSE = 0;
    
	static const float sm[16] = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f,-1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
    static void set_texture_stage(const GL& gl,UInt32 stage) {
        GL::GLenum texture_stages[] = {
            gl.TEXTURE0,
            gl.TEXTURE1,
            gl.TEXTURE2,
            gl.TEXTURE3,
        };
        static UInt32 oldStage = 1000;
        if (oldStage!=stage) {
            CHECK_GL(gl.ActiveTexture(texture_stages[stage]));
            oldStage=stage;
        }
	}
    static void set_client_texture_stage(const GL& gl, const GLffpl& ffpl, UInt32 stage) {
        GL::GLenum texture_stages[] = {
            gl.TEXTURE0,
            gl.TEXTURE1,
            gl.TEXTURE2,
            gl.TEXTURE3,
        };
        CHECK_GL(ffpl.ClientActiveTexture(texture_stages[stage]));
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
	
	static inline void conv_texarg(const GL& gl,const GLffpl& ffpl,TextureArgument f,bool alpha,GL::GLenum& arg,GL::GLenum& op) {
		if (f==TEX_ARG_CURRENT) {
			arg = ffpl.PREVIOUS;
			op = alpha ? gl.SRC_ALPHA : gl.SRC_COLOR;
		} else if (f==TEX_ARG_TEXTURE) {
			arg = gl.TEXTURE;
			op = alpha ? gl.SRC_ALPHA : gl.SRC_COLOR;
		}else if (f==TEX_ARG_CURRENT_INV) {
			arg = ffpl.PREVIOUS;
			op = alpha ? gl.ONE_MINUS_SRC_ALPHA : gl.ONE_MINUS_SRC_COLOR;
		} else if (f==TEX_ARG_TEXTURE_INV) {
			arg = gl.TEXTURE;
			op = alpha ? gl.ONE_MINUS_SRC_ALPHA : gl.ONE_MINUS_SRC_COLOR;
        } else if (f==TEX_ARG_TEXTURE_ALPHA) {
            arg = gl.TEXTURE;
            op = gl.SRC_ALPHA;
        } else if (f==TEX_ARG_TEXTURE_ALPHA_INV) {
            arg = gl.TEXTURE;
            op = gl.ONE_MINUS_SRC_ALPHA;
        } else if (f==TEX_ARG_CURRENT_ALPHA) {
            arg = ffpl.PREVIOUS;
            op = gl.SRC_ALPHA;
        } else if (f==TEX_ARG_CURRENT_ALPHA_INV) {
            arg = ffpl.PREVIOUS;
            op = gl.ONE_MINUS_SRC_ALPHA;
        }
	}
	
	RenderOpenGLBase::RenderOpenGLBase(UInt32 w,UInt32 h,bool haveDepth) : RenderImpl(w,h,haveDepth) {
        m_depth_write_enabled = false;
    }

	RenderOpenGLBase::~RenderOpenGLBase() {
        LOG_VERBOSE("Destructor");
	}
    
    static const void* NO_POINTER = (const void*)(0xffffffff);

#define NOT_IMPLEMENTED LOG_ERROR( "render openGL function " << __FUNCTION__ << " not implemented" )

	bool RenderOpenGLBase::RenderInit() {
        LOG_INFO("RenderOpenGLBase::RenderInit");
        
        		
        LOG_INFO( "Render size : " << GetRenderWidth() << "x" << GetRenderHeight() );
		
        return RenderImpl::RenderInit();
	}
	
	void RenderOpenGLBase::RenderDone() {
        if (gl.Release) gl.Release();
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
    }
	
    /// Begin graphics scene (frame)
    void GHL_CALL RenderOpenGLBase::BeginScene(RenderTarget* target) {
        RenderImpl::BeginScene(target);
        if (!target && gl.rtapi.valid)
            CHECK_GL(gl.rtapi.BindFramebuffer(gl.rtapi.FRAMEBUFFER,gl.rtapi.default_framebuffer));
        CHECK_GL(gl.Viewport(0,0,GetWidth(),GetHeight()));
    }
    
	
	/// setup scisor test
	void GHL_CALL RenderOpenGLBase::SetupScisor( bool enable, UInt32 x, UInt32 y, UInt32 w, UInt32 h ) {
		if (!enable) {
			CHECK_GL(gl.Disable(gl.SCISSOR_TEST));
		} else {
			CHECK_GL(gl.Enable(gl.SCISSOR_TEST));
            UInt32 _y = GetTarget() ? y : (GetHeight()-h-y);
			CHECK_GL(gl.Scissor(x, _y, w, h));
		}
	}
	 
	
		
	/// clear scene
	void GHL_CALL RenderOpenGLBase::Clear(float r,float g,float b,float a,float depth) {
        bool have_depth = GetTarget() ? GetTarget()->GetHaveDepth() : GetHaveDepth();
		CHECK_GL(gl.ClearColor(r, g, b, a));
        GL::GLuint mask = gl.COLOR_BUFFER_BIT;
        if (have_depth) {
            mask |= gl.DEPTH_BUFFER_BIT;
            if (!m_depth_write_enabled) {
                CHECK_GL(gl.DepthMask(gl._TRUE));
            }
        }
		CHECK_GL(gl.Clear(mask));
        if (have_depth && !m_depth_write_enabled) {
            CHECK_GL(gl.DepthMask(gl._FALSE));
        }
	}
	
    bool GHL_CALL RenderOpenGLBase::IsTextureFormatSupported(TextureFormat fmt) {
        switch (fmt) {
            case TEXTURE_FORMAT_ALPHA:
            case TEXTURE_FORMAT_RGB:
            case TEXTURE_FORMAT_RGBA:
            case TEXTURE_FORMAT_RGBX:
            case TEXTURE_FORMAT_565:
            case TEXTURE_FORMAT_4444:
                return true;
                
            default:
                break;
        }
        if (gl.IsTextureFormatSupported) {
            if (gl.IsTextureFormatSupported(fmt))
                return true;
        }
        return RenderImpl::IsTextureFormatSupported(fmt);
    }
	
	/// create empty texture
	Texture* GHL_CALL RenderOpenGLBase::CreateTexture(UInt32 width,UInt32 height,TextureFormat fmt,const Image* data) {
        if (GHL_IsCompressedFormat(fmt)) {
            if (!data) {
                LOG_ERROR("CreateTexture failed create empty compressed texture");
                return 0;
            }
            if (GHL_ImageFormatToTextureFormat(data->GetFormat())!=fmt && fmt != GHL::TEXTURE_FORMAT_UNKNOWN) {
                LOG_ERROR("CreateTexture invalid format for compressed texure");
                return 0;
            }
            fmt = GHL_ImageFormatToTextureFormat(data->GetFormat());
            if (!IsTextureFormatSupported(fmt)) {
                LOG_ERROR("CreateTexture not supported compressed texure format");
                return 0;
            }
        }
        
        if (data) {
            if (data->GetWidth() != width || data->GetHeight() != height) {
                LOG_ERROR("CreateTexture with invalid data size");
                return 0;
            }
        }
		TextureOpenGL* tex = TextureOpenGL::Create(this,fmt,width,height,data);
        if (!tex) {
            LOG_ERROR("CreateTexture failed: " << width << "x" << height);
        }
		return tex;
	}
	
	void RenderOpenGLBase::RestoreTexture() {
		SetTexture(GetTexture(0), 0);
	}
		
	/// set blend factors
	void GHL_CALL RenderOpenGLBase::SetupBlend(bool enable,BlendFactor src_factor,BlendFactor dst_factor) {
		if (enable) {
			CHECK_GL(gl.Enable(gl.BLEND));
			CHECK_GL(gl.BlendFunc(convert_blend(gl,src_factor), convert_blend(gl,dst_factor)));
		} else {
			CHECK_GL(gl.Disable(gl.BLEND));
		}
	}
	
	
	/// set depth test
	void GHL_CALL RenderOpenGLBase::SetupDepthTest(bool enable,CompareFunc func,bool write_enable) {
		if (enable) {
			CHECK_GL(gl.Enable(gl.DEPTH_TEST));
			CHECK_GL(gl.DepthFunc(conv_compare(gl,func)));
		} else {
			CHECK_GL(gl.Disable(gl.DEPTH_TEST));
		}
		CHECK_GL(gl.DepthMask(write_enable ?gl._TRUE :gl._FALSE));
        m_depth_write_enabled = write_enable;
	}
	
	/// setup faces culling
	void GHL_CALL RenderOpenGLBase::SetupFaceCull(bool enable,bool cw = true) {
		if (enable) {
            if (GetTarget())
                cw = !cw;
			CHECK_GL(gl.Enable(gl.CULL_FACE));
			CHECK_GL(gl.FrontFace( cw ?gl.CW :gl.CCW ));
		} else {
			CHECK_GL(gl.Disable(gl.CULL_FACE));
		}
	}
	
	/// create index buffer
	IndexBuffer* GHL_CALL RenderOpenGLBase::CreateIndexBuffer(UInt32 size) {
		if (gl.vboapi.valid) {
            GL::GLuint name;
            CHECK_GL(gl.vboapi.GenBuffers(1,&name));
            return new IndexBufferOpenGL(this,size, name);
        }
        return new SoftIndexBuffer(this,size);
	}
	
	/// set current index buffer
	void GHL_CALL RenderOpenGLBase::SetIndexBuffer(const IndexBuffer* buf) {
        RenderImpl::SetIndexBuffer(buf);
        if (gl.vboapi.valid) {
            if (buf) {
                static_cast<const IndexBufferOpenGL*>(buf)->bind();
            } else {
                CHECK_GL(gl.vboapi.BindBuffer(gl.vboapi.ELEMENT_ARRAY_BUFFER,0));
            }
        }
	}
	
	/// create vertex buffer
	VertexBuffer* GHL_CALL RenderOpenGLBase::CreateVertexBuffer(VertexType type,UInt32 size) {
		if (gl.vboapi.valid) {
            GL::GLuint name;
            CHECK_GL(gl.vboapi.GenBuffers(1,&name));
            return new VertexBufferOpenGL(this, type, size, name);
        } 
		return new SoftVertexBuffer(this,type,size);
	}
	/// set current vertex buffer
	void GHL_CALL RenderOpenGLBase::SetVertexBuffer(const VertexBuffer* buf) {
		RenderImpl::SetVertexBuffer(buf);
        if (gl.vboapi.valid) {
            if (buf) {
                static_cast<const VertexBufferOpenGL*>(buf)->bind();
            } else {
                CHECK_GL(gl.vboapi.BindBuffer(gl.vboapi.ARRAY_BUFFER,0));
            }
        } 
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
            SetupVertexData(v,v_type);
            CHECK_GL(gl.DrawElements(element, indexes_amount,gl.UNSIGNED_SHORT, (void*)(i_begin*sizeof(UInt16))));
        } else {
            const SoftVertexBuffer* sv = static_cast<const SoftVertexBuffer*>(vb);
            const SoftIndexBuffer* si = static_cast<const SoftIndexBuffer*>(ib);
            const Vertex* v =  reinterpret_cast<const Vertex*> (sv->GetData());
            SetupVertexData(v,v_type);
            const UInt16* bi = reinterpret_cast<const UInt16*>(si->GetData());
            CHECK_GL(gl.DrawElements(element, indexes_amount,gl.UNSIGNED_SHORT, bi+i_begin));
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
            v = reinterpret_cast<const Vertex2Tex*> (vertices);
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
#ifdef GHL_DEBUG
        if (indexes) {
            for (UInt32 i=0;i<indexes_amount;++i) {
                if (indexes[i]>=v_amount) {
                    LOG_ERROR("DrawPrimitivesFromMemory invalid index " << indexes[i]);
                }
            }
        }
#endif
        SetupVertexData(v,v_type);
        if (indexes) {
            CHECK_GL(gl.DrawElements(element, indexes_amount,gl.UNSIGNED_SHORT, indexes));
        } else {
            CHECK_GL(gl.DrawArrays(element,0,indexes_amount));
        }
	}
	
	
	
	
	
	/// create render target
	RenderTarget* GHL_CALL RenderOpenGLBase::CreateRenderTarget(UInt32 w,UInt32 h,TextureFormat fmt,bool depth) {
		assert(!IsSceneStarted());
		RenderTargetOpenGL* rt = new RenderTargetOpenGL(this,w,h,fmt,depth);
		if (!rt->check()) {
			LOG_ERROR( "rendertarget check failed" );
            rt->Release();
			rt = 0;
		}
		return rt;
	}
    
	
	static bool LoadShaderGLSL(const GL& gl,GL::GLhandle handle,const Data* ds) {
        if (!gl.sdrapi.valid) return false;
        const GL::GLchar* source[] = {
			reinterpret_cast<const GL::GLchar*>(ds->GetData())
		};
        GL::GLint len[] = {GL::GLint(ds->GetSize())};
		CHECK_GL(gl.sdrapi.ShaderSource(handle,1,source,len));
		CHECK_GL(gl.sdrapi.CompileShader(handle));
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
        GL::GLhandle handle = 0;
        CHECK_GL(handle = gl.sdrapi.CreateShader(gl.sdrapi.VERTEX_SHADER));
		if (LoadShaderGLSL(gl,handle,ds)) {
			VertexShaderGLSL* fs = new VertexShaderGLSL(this,handle);
			return fs;
		}
		CHECK_GL(gl.sdrapi.DeleteShader(handle));
		return 0;
	}


	 
	FragmentShader* GHL_CALL RenderOpenGLBase::CreateFragmentShader(const Data* ds) {
        if (!gl.sdrapi.valid) return 0;
        GL::GLhandle handle = 0;
        CHECK_GL(handle = gl.sdrapi.CreateShader(gl.sdrapi.FRAGMENT_SHADER));
		if (LoadShaderGLSL(gl,handle,ds)) {
			FragmentShaderGLSL* fs = new FragmentShaderGLSL(this,handle);
			return fs;
		}
		CHECK_GL(gl.sdrapi.DeleteShader(handle));
		return 0;
	}

    static const char* predefinedAttributeNames[] = {
        "vPosition",
        "vTexCoord",
        "vTex2Coord",
        "vColor"
    };

	
	ShaderProgram* GHL_CALL RenderOpenGLBase::CreateShaderProgram(VertexShader* v,FragmentShader* f) {
        if (!gl.sdrapi.valid) return 0;
        if (!v || !f) return 0;
        GL::GLhandle handle = 0;
        CHECK_GL(handle=gl.sdrapi.CreateProgram());
		VertexShaderGLSL* vs = static_cast<VertexShaderGLSL*> (v);
		FragmentShaderGLSL* fs = static_cast<FragmentShaderGLSL*> (f);
		// @todo check vs ans fs
		CHECK_GL(gl.sdrapi.AttachShader(handle, vs->handle()));
		CHECK_GL(gl.sdrapi.AttachShader(handle, fs->handle()));

        for (GL::GLuint i=0;i<(sizeof(predefinedAttributeNames)/sizeof(predefinedAttributeNames[0]));++i) {
            CHECK_GL(gl.sdrapi.BindAttribLocation(handle,i,predefinedAttributeNames[i]));
        }
        
		CHECK_GL(gl.sdrapi.LinkProgram(handle));
        GL::GLint res = GL::_TRUE;
		gl.sdrapi.GetProgramiv(handle,gl.sdrapi.LINK_STATUS,&res);
        if (res!=GL::_TRUE) {
            GL::GLchar log[512];
            GL::GLsizei size = 0;
            gl.sdrapi.GetProgramInfoLog(handle,511,&size,log);
            log[size]=0;
            LOG_ERROR( "Shader link result : " << size << " " << log );
            
            CHECK_GL(gl.sdrapi.DeleteProgram(handle));
			return 0;
		}
		ShaderProgramGLSL* prg = new ShaderProgramGLSL(this,handle,vs,fs);
        const ShaderProgram* current = GetShader();
        CHECK_GL(gl.sdrapi.UseProgram(handle));
        prg->Setup();
        if (current) {
            const ShaderProgramGLSL* sp = static_cast<const ShaderProgramGLSL*>(current);
            CHECK_GL(gl.sdrapi.UseProgram(sp->handle()));
        } else {
            CHECK_GL(gl.sdrapi.UseProgram(0));
        }
		return prg;
	}
    
	
	void RenderOpenGLBase::SetShader(const ShaderProgram* shader) {
        RenderImpl::SetShader(shader);
        if (!gl.sdrapi.valid) return;
		if (shader) {
			const ShaderProgramGLSL* sp = static_cast<const ShaderProgramGLSL*>(shader);
			CHECK_GL(gl.sdrapi.UseProgram(sp->handle()));
		} else {
			CHECK_GL(gl.sdrapi.UseProgram(0));
		}
	}

    
    RenderOpenGLFFPL::RenderOpenGLFFPL(UInt32 w,UInt32 h,bool haveDepth) : RenderOpenGLBase(w,h,haveDepth) {
        m_enabled_tex2 = false;
    }
    
    void RenderOpenGLFFPL::ResetRenderState() {
        RenderOpenGLBase::ResetRenderState();
        CHECK_GL(glffpl.EnableClientState(glffpl.VERTEX_ARRAY));
        CHECK_GL(glffpl.EnableClientState(glffpl.COLOR_ARRAY));
        CHECK_GL(glffpl.EnableClientState(glffpl.TEXTURE_COORD_ARRAY));
        m_enabled_tex2 = false;
    }
    
    /// set projection matrix
	void GHL_CALL RenderOpenGLFFPL::SetProjectionMatrix(const float *m) {
        CHECK_GL(glffpl.MatrixMode(glffpl.PROJECTION));
        if (GetTarget()) {
            float matrix[16];
            MatrixMul(sm, m, matrix);
            CHECK_GL(glffpl.LoadMatrixf(matrix));
        } else {
            CHECK_GL(glffpl.LoadMatrixf(m));
        }
        CHECK_GL(glffpl.MatrixMode(glffpl.MODELVIEW));
	}
	
	/// set view matrix
	void GHL_CALL RenderOpenGLFFPL::SetViewMatrix(const float* m) {
		CHECK_GL(glffpl.MatrixMode(glffpl.MODELVIEW));
		CHECK_GL(glffpl.LoadMatrixf(m));
	}
    
    void RenderOpenGLFFPL::SetupVertexData(const Vertex* v,VertexType vt) {
        GL::GLsizei vs = sizeof(*v);
        if (vt == VERTEX_TYPE_2_TEX) {
            set_client_texture_stage(gl, glffpl, 1);
            CHECK_GL(glffpl.EnableClientState(glffpl.TEXTURE_COORD_ARRAY));
            m_enabled_tex2 = true;
            const Vertex2Tex* v2 = static_cast<const Vertex2Tex*>(v);
            vs = sizeof(*v2);
            CHECK_GL(glffpl.TexCoordPointer(2,gl.FLOAT, vs, &v2->t2x));
            set_client_texture_stage(gl,glffpl, 0);
        } else if (m_enabled_tex2) {
            set_client_texture_stage(gl, glffpl, 1);
            CHECK_GL(glffpl.DisableClientState(glffpl.TEXTURE_COORD_ARRAY));
            set_client_texture_stage(gl,glffpl, 0);
            m_enabled_tex2 = false;
        }
        CHECK_GL(glffpl.TexCoordPointer(2,gl.FLOAT, vs, &v->tx));
        CHECK_GL(glffpl.ColorPointer(4,gl.UNSIGNED_BYTE, vs, &v->color));
        CHECK_GL(glffpl.VertexPointer(3,gl.FLOAT, vs , &v->x));
    }

    void GHL_CALL RenderOpenGLFFPL::SetTexture(const Texture* texture, UInt32 stage ) {
        RenderOpenGLBase::SetTexture(texture, stage);
        set_texture_stage(gl,stage);
        //set_client_texture_stage(gl, glffpl, stage);
		//glClientActiveTexture(texture_stages[stage]);
		if (texture) {
			const TextureOpenGL* tex = static_cast<const TextureOpenGL*>(texture);
            CHECK_GL(gl.Enable(gl.TEXTURE_2D));
			tex->bind();
		} else {
			CHECK_GL(gl.BindTexture(gl.TEXTURE_2D, 0));
            CHECK_GL(gl.Disable(gl.TEXTURE_2D));
		}
        //set_client_texture_stage(gl, glffpl, 0);
		set_texture_stage(gl,0);
    }
    
    /// set texture stage color operation
	void GHL_CALL RenderOpenGLFFPL::SetupTextureStageColorOp(TextureOperation op,TextureArgument arg1,TextureArgument arg2,UInt32 stage ) {
		set_texture_stage(gl,stage);
		
		if (op==TEX_OP_DISABLE) {
			CHECK_GL(gl.Disable(gl.TEXTURE_2D));
		} else {
			CHECK_GL(gl.Enable(gl.TEXTURE_2D));
			CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.TEXTURE_ENV_MODE,glffpl.COMBINE));
			GL::GLenum src0 = glffpl.PREVIOUS;
			GL::GLenum op0 = gl.SRC_COLOR;
			conv_texarg(gl,glffpl,arg1,false,src0,op0);
			GL::GLenum src1 = gl.TEXTURE;
			GL::GLenum op1 = gl.SRC_COLOR;
			conv_texarg(gl,glffpl,arg2,false,src1,op1);
			if (op==TEX_OP_SELECT_1)
			{
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.COMBINE_RGB,glffpl.REPLACE));
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.SOURCE0_RGB,src0));
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.OPERAND0_RGB,op0));
				
			} else if (op==TEX_OP_SELECT_2)
			{
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.COMBINE_RGB,glffpl.REPLACE));
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.SOURCE0_RGB,src1));
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.OPERAND0_RGB,op1));
				
			} else if (op==TEX_OP_ADD) {
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.COMBINE_RGB,glffpl.ADD));
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.SOURCE0_RGB,src0));
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.OPERAND0_RGB,op0));
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.SOURCE1_RGB,src1));
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.OPERAND1_RGB,op1));
			} else if (op==TEX_OP_MODULATE) {
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.COMBINE_RGB,glffpl.MODULATE));
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.SOURCE0_RGB,src0));
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.OPERAND0_RGB,op0));
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.SOURCE1_RGB,src1));
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.OPERAND1_RGB,op1));
			} else if (op==TEX_OP_INT_TEXTURE_ALPHA) {
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.COMBINE_RGB,glffpl.INTERPOLATE));
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.SOURCE0_RGB,src1));
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.OPERAND0_RGB,op1));
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.SOURCE1_RGB,src0));
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.OPERAND1_RGB,op0));
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.SOURCE2_RGB,gl.TEXTURE));
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.OPERAND2_RGB,gl.SRC_ALPHA));
			} else if (op==TEX_OP_INT_CURRENT_ALPHA) {
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.COMBINE_RGB,glffpl.INTERPOLATE));
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.SOURCE0_RGB,src1));
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.OPERAND0_RGB,op1));
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.SOURCE1_RGB,src0));
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.OPERAND1_RGB,op0));
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.SOURCE2_RGB,glffpl.PREVIOUS));
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.OPERAND2_RGB,gl.SRC_ALPHA));
			}
		}
		set_texture_stage(gl,0);
	}
	/// set texture stage alpha operation
	void GHL_CALL RenderOpenGLFFPL::SetupTextureStageAlphaOp(TextureOperation op,TextureArgument arg1,TextureArgument arg2,UInt32 stage ) {
		//return;
		
		set_texture_stage(gl,stage);
		if (op==TEX_OP_DISABLE) {
			CHECK_GL(gl.Disable(gl.TEXTURE_2D));
		} else {
			CHECK_GL(gl.Enable(gl.TEXTURE_2D));
            GL::GLenum _arg1 =glffpl.PREVIOUS;
            GL::GLenum _op1 =gl.SRC_ALPHA;
			conv_texarg(gl,glffpl,arg1,true,_arg1,_op1);
			GL::GLenum _arg2 =gl.TEXTURE;
			GL::GLenum _op2 =gl.SRC_ALPHA;
			conv_texarg(gl,glffpl,arg2,true,_arg2,_op2);
			if (op==TEX_OP_SELECT_1)
			{
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.SOURCE0_ALPHA,_arg1));
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.OPERAND0_ALPHA,_op1));
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.COMBINE_ALPHA,glffpl.REPLACE));
			} else if (op==TEX_OP_SELECT_2)
			{
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.SOURCE0_ALPHA,_arg2));
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.OPERAND0_ALPHA,_op2));
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.COMBINE_ALPHA,glffpl.REPLACE));
			} else {
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.SOURCE0_ALPHA,_arg1));
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.OPERAND0_ALPHA,_op1));
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.SOURCE1_ALPHA,_arg2));
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.OPERAND1_ALPHA,_op2));
                GL::GLenum mode =glffpl.MODULATE;
				if (op==TEX_OP_ADD) {
					mode =glffpl.ADD;
                } else if (op==TEX_OP_INT_TEXTURE_ALPHA) {
					NOT_IMPLEMENTED;
				} else if (op==TEX_OP_INT_CURRENT_ALPHA) {
					NOT_IMPLEMENTED;
				}
				CHECK_GL(glffpl.TexEnvi(glffpl.TEXTURE_ENV,glffpl.COMBINE_ALPHA, mode));
			}
		}
		set_texture_stage(gl,0);
	}
    
    
    
    RenderOpenGLPPL::RenderOpenGLPPL(UInt32 w,UInt32 h,bool haveDepth) : RenderOpenGLBase(w,h,haveDepth) {
        m_reset_uniforms = true;
    }
    
    bool RenderOpenGLPPL::RenderInit() {
        LOG_INFO("RenderOpenGLPPL::RenderInit");
        if (!gl.sdrapi.valid)
            return false;
        if (!RenderOpenGLBase::RenderInit())
            return false;
        m_generator.init(this);
        m_shaders_render.init(&m_generator);
        for (UInt32 i=0;i<MAX_TEXTURE_STAGES;++i) {
            m_crnt_state.texture_stages[i].tex.all = 0;
        }
        ResetPointers();
        return true;
    }
    
    
    void RenderOpenGLPPL::RenderDone() {
        LOG_INFO("RenderOpenGLPPL::RenderDone");
        m_shaders_render.done();
        m_generator.done();
        RenderOpenGLBase::RenderDone();
    }
    
    void RenderOpenGLPPL::ResetRenderState() {
        RenderOpenGLBase::ResetRenderState();
        ResetPointers();
    }
    
    void RenderOpenGLPPL::ResetPointers() {
        for (size_t i=0;i<VERTEX_MAX_ATTRIBUTES;++i) {
            if (m_current_pointers[i]!=NO_POINTER) {
                gl.sdrapi.DisableVertexAttribArray(GL::GLuint(i));
            }
            m_current_pointers[i] = NO_POINTER;
        }
    }
    void RenderOpenGLPPL::SetupAttribute(const void* ptr,
                                         VertexAttributeUsage u,
                                         UInt32 cnt,
                                         GL::GLenum t,
                                         bool norm,
                                         UInt32 vsize) {
        if (m_current_pointers[u]!=ptr) {
            CHECK_GL(gl.sdrapi.VertexAttribPointer(u,cnt,t,norm?gl._TRUE:gl._FALSE,GL::GLsizei(vsize),ptr));
            if (m_current_pointers[u] == NO_POINTER) {
                CHECK_GL(gl.sdrapi.EnableVertexAttribArray(u));
            }
            m_current_pointers[u]=ptr;
            
        }
    }
    void RenderOpenGLPPL::SetupVertexData(const Vertex* v,VertexType vt) {
        const ShaderProgramGLSL* prg = static_cast<const ShaderProgramGLSL*>(GetShader());
        if (!prg) {
            LOG_ERROR("not have current shader");
            return;
        }
        GL::GLsizei vs = sizeof(*v);
        const Vertex2Tex* v2 = static_cast<const Vertex2Tex*>(v);
        if (vt == VERTEX_TYPE_2_TEX) {
            vs = sizeof(*v2);
            SetupAttribute(&v2->t2x, VERTEX_TEX_COORD1, 2, gl.FLOAT, false, vs);
        } else if (m_current_pointers[VERTEX_TEX_COORD1] != NO_POINTER) {
            CHECK_GL(gl.sdrapi.DisableVertexAttribArray(VERTEX_TEX_COORD1));
            m_current_pointers[VERTEX_TEX_COORD1] = NO_POINTER;
        }
        SetupAttribute(&v->x, VERTEX_POSITION, 3, gl.FLOAT, false, vs);
        SetupAttribute(&v->tx, VERTEX_TEX_COORD0, 2, gl.FLOAT, false, vs);
        SetupAttribute(&v->color, VERTEX_COLOR, 4, gl.UNSIGNED_BYTE, true, vs);
    }
    
    /// set projection matrix
	void GHL_CALL RenderOpenGLPPL::SetProjectionMatrix(const float *m) {
        if (GetTarget()) {
            MatrixMul(sm, m, m_projection_matrix);
        } else {
            std::copy(m, m+16, m_projection_matrix);
        }
        MatrixMul(m_projection_matrix, m_view_matrix, m_projection_view_matrix);
        m_reset_uniforms = true;
    }
	
	/// set view matrix
	void GHL_CALL RenderOpenGLPPL::SetViewMatrix(const float* m) {
		std::copy(m, m+16, m_view_matrix);
        MatrixMul(m_projection_matrix, m_view_matrix, m_projection_view_matrix);
        m_reset_uniforms = true;
	}

    
    void GHL_CALL RenderOpenGLPPL::SetTexture(const Texture* texture, UInt32 stage ) {
        RenderOpenGLBase::SetTexture(texture, stage);
        set_texture_stage(gl,stage);
		//glClientActiveTexture(texture_stages[stage]);
		if (texture) {
			const TextureOpenGL* tex = static_cast<const TextureOpenGL*>(texture);
        	tex->bind();
		} else {
			CHECK_GL(gl.BindTexture(gl.TEXTURE_2D, 0));
        }
		set_texture_stage(gl,0);
        
        if (texture) {
            m_crnt_state.texture_stages[stage].rgb.c.texture = true;
            m_crnt_state.texture_stages[stage].alpha.c.texture = true;
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
        m_reset_uniforms = true;
        RenderOpenGLBase::SetShader(shader);
        m_shaders_render.set_shader(shader);
    }
    void RenderOpenGLPPL::DoDrawPrimitives(VertexType v_type) {
        const ShaderProgram* prg = m_shaders_render.get_shader(m_crnt_state, v_type==VERTEX_TYPE_2_TEX);
        if (prg) {
            RenderOpenGLBase::SetShader(prg);
        } else if (m_reset_uniforms) {
            prg = GetShader();
        }
        if (prg) {
            static_cast<const ShaderProgramGLSL*>(prg)->SetPMVMatrix(m_projection_view_matrix);
        }
        m_reset_uniforms = false;
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
    
    /// set current index buffer
    void GHL_CALL RenderOpenGLPPL::SetIndexBuffer(const IndexBuffer* buf) {
        RenderOpenGLBase::SetIndexBuffer(buf);
    }
    /// set current vertex buffer
    void GHL_CALL RenderOpenGLPPL::SetVertexBuffer(const VertexBuffer* buf) {
        RenderOpenGLBase::SetVertexBuffer(buf);
    }

}



