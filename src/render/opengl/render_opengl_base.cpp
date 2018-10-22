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
	
		
	RenderOpenGLBase::RenderOpenGLBase(UInt32 w,UInt32 h,bool haveDepth) : RenderImpl(w,h,haveDepth) {
        m_depth_write_enabled = false;
        m_reset_uniforms = true;
        m_reset_attributes = true;
        
        VertexAttributeDef def;
        def.usage = VERTEX_POSITION;
        def.data = VERTEX_3_FLOAT;
        def.offset = 0;
        m_simple_vdef.push_back(def);
        m_2tex_vdef.push_back(def);
        
        def.usage = VERTEX_COLOR;
        def.data = VERTEX_4_BYTE;
        def.offset = 3*sizeof(float);
        m_simple_vdef.push_back(def);
        m_2tex_vdef.push_back(def);
        
        def.usage = VERTEX_TEX_COORD0;
        def.data = VERTEX_2_FLOAT;
        def.offset = 3*sizeof(float)+sizeof(UInt32);
        m_simple_vdef.push_back(def);
        m_2tex_vdef.push_back(def);
        
        def.usage = VERTEX_TEX_COORD1;
        def.data = VERTEX_2_FLOAT;
        def.offset = 3*sizeof(float)+sizeof(UInt32)+2*sizeof(float);
        m_2tex_vdef.push_back(def);
        m_vertex_shader_prefix = "/*GHL*/\n";
        m_fragment_shader_prefix = "/*GHL*/\n";
    }

	RenderOpenGLBase::~RenderOpenGLBase() {
        LOG_VERBOSE("Destructor");
	}
    
    static const void* NO_POINTER = (const void*)(0xffffffff);

#define NOT_IMPLEMENTED LOG_ERROR( "render openGL function " << __FUNCTION__ << " not implemented" )

	bool RenderOpenGLBase::RenderInit() {
        LOG_INFO("RenderOpenGLBase::RenderInit");
        
        		
        LOG_INFO( "Render size : " << GetRenderWidth() << "x" << GetRenderHeight() );
		
        if (!gl.sdrapi.valid)
            return false;
        if (!RenderImpl::RenderInit())
            return false;
        m_generator.init(this);
        m_shaders_render.init(&m_generator);
        for (UInt32 i=0;i<STATE_MAX_TEXTURE_STAGES;++i) {
            m_crnt_state.texture_stages[i].tex.all = 0;
        }
        ResetPointers();
        return true;
	}
	
	void RenderOpenGLBase::RenderDone() {
        LOG_INFO("RenderOpenGLBase::RenderDone");
        m_shaders_render.done();
        m_generator.done();
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
        ResetPointers();
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
        return 0;
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
	VertexBuffer* GHL_CALL RenderOpenGLBase::CreateVertexBuffer(UInt32 vsize,const VertexAttributeDef* attributes,UInt32 count) {
		if (gl.vboapi.valid) {
            GL::GLuint name;
            CHECK_GL(gl.vboapi.GenBuffers(1,&name));
            return new VertexBufferOpenGL(this, vsize, count, attributes,name);
        } 
		return 0;
	}
	/// set current vertex buffer
	void GHL_CALL RenderOpenGLBase::SetVertexBuffer(const VertexBuffer* buf) {
        if (GetVertexBuffer() != buf) {
            m_reset_attributes = true;
        }
		RenderImpl::SetVertexBuffer(buf);
        if (gl.vboapi.valid) {
            if (buf) {
                static_cast<const VertexBufferOpenGL*>(buf)->bind();
            } else {
                CHECK_GL(gl.vboapi.BindBuffer(gl.vboapi.ARRAY_BUFFER,0));
            }
        } 
	}

	void RenderOpenGLBase::GetPrimitiveInfo(PrimitiveType type,UInt32 prim_amount,GL::GLenum& element,UInt32& indexes_amount) const {
		element = gl.TRIANGLES;
		indexes_amount = prim_amount * 3;
		if (type==PRIMITIVE_TYPE_TRIANGLE_STRIP) {
			element = gl.TRIANGLE_STRIP;
			indexes_amount = prim_amount + 2;
		} else if (type==PRIMITIVE_TYPE_TRIANGLE_FAN) {
			element = gl.TRIANGLE_FAN;
			indexes_amount = prim_amount + 2;
		} else if (type==PRIMITIVE_TYPE_LINES) {
			element = gl.LINES;
			indexes_amount = prim_amount * 2;
		} else if (type==PRIMITIVE_TYPE_LINE_STRIP) {
			element = gl.LINE_STRIP;
			indexes_amount = prim_amount + 1;
		}
	}
	
		
	/// draw primitives
    void GHL_CALL RenderOpenGLBase::DrawPrimitives(PrimitiveType type,UInt32 prim_amount) {
        const VertexBufferImpl* vb = GetVertexBuffer();
        if (!vb) {
            LOG_ERROR("DrawPrimitives without vertex buffer");
            return;
        }
        const IndexBufferImpl* ib = GetIndexBuffer();
        if (!ib) {
            LOG_ERROR("DrawPrimitives without index buffer");
            return;
        }
        if (!GetShader())
            return;
        
        GL::GLenum element =gl.TRIANGLES;
		UInt32 indexes_amount = prim_amount * 3;
		GetPrimitiveInfo(type,prim_amount,element,indexes_amount);
        
        
        if (gl.vboapi.valid) {
            SetupVertexData(0,vb->GetVertexSize(), vb->GetAttributes());
            CHECK_GL(gl.DrawElements(element, indexes_amount,gl.UNSIGNED_SHORT, (void*)0));
        }
        
    }
	
	/// draw primitives from memory
	void GHL_CALL RenderOpenGLBase::DrawPrimitivesFromMemory(PrimitiveType type,VertexType v_type,const void* vertices,UInt32 v_amount,const UInt16* indexes,UInt32 prim_amount) {
        DoDrawPrimitives(v_type);
        /// @todo
        GHL_UNUSED(v_amount);
        UInt32 vertex_size = 0;
        const VertexAttributes* vdef = 0;
        
        if (v_type == VERTEX_TYPE_SIMPLE) {
            vertex_size = sizeof(Vertex);
            vdef = &m_simple_vdef;
        } else if (v_type == VERTEX_TYPE_2_TEX ) {
            vertex_size = sizeof(Vertex2Tex);
            vdef = &m_2tex_vdef;
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
        SetupVertexData(vertices,vertex_size,*vdef);
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
    
	
	static bool LoadShaderGLSL(const GL& gl,GL::GLhandle handle,const Data* ds, const std::string& prefix) {
        if (!gl.sdrapi.valid) return false;
        const GL::GLchar* source[] = {
        	reinterpret_cast<const GL::GLchar*>(prefix.c_str()),
			reinterpret_cast<const GL::GLchar*>(ds->GetData())
		};
        GL::GLint len[] = {GL::GLint(prefix.length()),GL::GLint(ds->GetSize())};
		CHECK_GL(gl.sdrapi.ShaderSource(handle,2,source,len));
		CHECK_GL(gl.sdrapi.CompileShader(handle));
		GL::GLint res;
		gl.sdrapi.GetShaderiv(handle,gl.sdrapi.COMPILE_STATUS,&res);
        if (res!=GL::_TRUE)
		{
            GL::GLchar log[512];
            GL::GLsizei size = 0;
            gl.sdrapi.GetShaderInfoLog(handle,512,&size,log);
            log[size]=0;
            LOG_ERROR( "shader compile result : " << log );
            
            return false;
		}
		return true;
	}
	
	VertexShader* GHL_CALL RenderOpenGLBase::CreateVertexShader(const Data* ds) {
        if (!gl.sdrapi.valid) return 0;
        GL::GLhandle handle = 0;
        CHECK_GL(handle = gl.sdrapi.CreateShader(gl.sdrapi.VERTEX_SHADER));
		if (LoadShaderGLSL(gl,handle,ds,m_vertex_shader_prefix)) {
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
		if (LoadShaderGLSL(gl,handle,ds,m_fragment_shader_prefix)) {
			FragmentShaderGLSL* fs = new FragmentShaderGLSL(this,handle);
			return fs;
		}
		CHECK_GL(gl.sdrapi.DeleteShader(handle));
		return 0;
	}

    static const char* predefinedAttributeNames[VERTEX_MAX_ATTRIBUTES] = {
        "vPosition",
        "vTexCoord",
        "vTex2Coord",
        "vColor",
        "vNormal",
        "vWeight",
        "vIndex",
        "vTangent"
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
    
	void RenderOpenGLBase::SetShaderImpl(const ShaderProgram* shader) {
        RenderImpl::SetShader(shader);
        m_reset_uniforms = true;
        if (!gl.sdrapi.valid) return;
		if (shader) {
			const ShaderProgramGLSL* sp = static_cast<const ShaderProgramGLSL*>(shader);
			CHECK_GL(gl.sdrapi.UseProgram(sp->handle()));
		} else {
			CHECK_GL(gl.sdrapi.UseProgram(0));
		}
	}
    void RenderOpenGLBase::ResetPointers() {
        for (size_t i=0;i<VERTEX_MAX_ATTRIBUTES;++i) {
            if (m_current_pointers[i]!=NO_POINTER) {
                gl.sdrapi.DisableVertexAttribArray(GL::GLuint(i));
            }
            m_current_pointers[i] = NO_POINTER;
        }
        m_reset_attributes = true;
    }

    void RenderOpenGLBase::SetupAttribute(const VertexAttributeDef& def,size_t vsize,const void* ptr) {
        GL::GLuint cnt;
        GL::GLenum type;
        GL::GLboolean norm;
        switch(def.data) {
            case VERTEX_4_BYTE:
                cnt = 4; type = gl.UNSIGNED_BYTE;
                break;
            case VERTEX_2_FLOAT:
                cnt = 2; type = gl.FLOAT;
                break;
            case VERTEX_3_FLOAT:
                cnt = 3; type = gl.FLOAT;
                break;
            case VERTEX_4_FLOAT:
                cnt = 4; type = gl.FLOAT;
        }
        norm = (def.usage == VERTEX_COLOR) ? gl._TRUE : gl._FALSE;
        CHECK_GL(gl.sdrapi.VertexAttribPointer(def.usage,cnt,type,norm,GL::GLsizei(vsize),ptr));
    }

    void RenderOpenGLBase::SetupVertexData(const void* v,UInt32 vsize,const VertexAttributes& vt) {

        const ShaderProgramGLSL* prg = static_cast<const ShaderProgramGLSL*>(GetShader());
        if (!prg) {
            LOG_ERROR("not have current shader");
            return;
        }

        bool used[VERTEX_MAX_ATTRIBUTES];
        for (size_t i=0;i<VERTEX_MAX_ATTRIBUTES;++i) {
            used[i] = false;
        }
        bool force = m_reset_attributes;
        for (VertexAttributes::const_iterator it = vt.begin();it!=vt.end();++it) {
            const void* ptr = static_cast<const Byte*>(v) + it->offset;
            if (ptr != m_current_pointers[it->usage] || force) {
                SetupAttribute(*it, vsize, ptr);
            }
            used[it->usage] = true;
            if (m_current_pointers[it->usage] == NO_POINTER) {
                CHECK_GL(gl.sdrapi.EnableVertexAttribArray(it->usage));
            }
            m_current_pointers[it->usage] = ptr;
        }
        for (GL::GLuint i=0;i<VERTEX_MAX_ATTRIBUTES;++i) {
            if (!used[i] && m_current_pointers[i]!=NO_POINTER) {
                CHECK_GL(gl.sdrapi.DisableVertexAttribArray(i));
                m_current_pointers[i] = NO_POINTER;
            }
        }
        m_reset_attributes = false;
    }
    
    /// set projection matrix
	void GHL_CALL RenderOpenGLBase::SetProjectionMatrix(const float *m) {
        if (GetTarget()) {
            MatrixMul(sm, m, m_projection_matrix);
        } else {
            std::copy(m, m+16, m_projection_matrix);
        }
        MatrixMul(m_projection_matrix, m_view_matrix, m_projection_view_matrix);
        m_reset_uniforms = true;
    }
	
	/// set view matrix
	void GHL_CALL RenderOpenGLBase::SetViewMatrix(const float* m) {
		std::copy(m, m+16, m_view_matrix);
        MatrixMul(m_projection_matrix, m_view_matrix, m_projection_view_matrix);
        m_reset_uniforms = true;
	}

    
    void GHL_CALL RenderOpenGLBase::SetTexture(const Texture* texture, UInt32 stage ) {
        RenderImpl::SetTexture(texture, stage);
        set_texture_stage(gl,stage);
        //glClientActiveTexture(texture_stages[stage]);
        if (texture) {
            const TextureOpenGL* tex = static_cast<const TextureOpenGL*>(texture);
            tex->bind();
        } else {
            CHECK_GL(gl.BindTexture(gl.TEXTURE_2D, 0));
        }
        set_texture_stage(gl,0);

        if (stage < STATE_MAX_TEXTURE_STAGES) {
            if (texture) {
                m_crnt_state.texture_stages[stage].rgb.c.texture = true;
                m_crnt_state.texture_stages[stage].alpha.c.texture = true;
            } else {
                m_crnt_state.texture_stages[stage].rgb.c.texture = false;
                m_crnt_state.texture_stages[stage].alpha.c.texture = false;
            }
        }
    }
    
    /// set texture stage color operation
    void GHL_CALL RenderOpenGLBase::SetupTextureStageColorOp(TextureOperation op,TextureArgument arg1,TextureArgument arg2,UInt32 stage ) {
        if (stage >= STATE_MAX_TEXTURE_STAGES)
            return;
        m_crnt_state.texture_stages[stage].rgb.c.operation = op;
        m_crnt_state.texture_stages[stage].rgb.c.arg_1 = arg1;
        m_crnt_state.texture_stages[stage].rgb.c.arg_2 = arg2;
    }
    
    /// set texture stage alpha operation
    void GHL_CALL RenderOpenGLBase::SetupTextureStageAlphaOp(TextureOperation op,TextureArgument arg1,TextureArgument arg2,UInt32 stage ) {
        if (stage >= STATE_MAX_TEXTURE_STAGES)
            return;
        m_crnt_state.texture_stages[stage].alpha.c.operation = op;
        m_crnt_state.texture_stages[stage].alpha.c.arg_1 = arg1;
        m_crnt_state.texture_stages[stage].alpha.c.arg_2 = arg2;
    }
    
    void GHL_CALL RenderOpenGLBase::SetShader(const ShaderProgram* shader)  {
        SetShaderImpl(shader);
        m_shaders_render.set_shader(shader);
    }
    
    void RenderOpenGLBase::DoDrawPrimitives(VertexType v_type) {
        const ShaderProgram* prg = m_shaders_render.get_shader(m_crnt_state, v_type==VERTEX_TYPE_2_TEX);
        if (prg) {
            SetShaderImpl(prg);
        } else if (m_reset_uniforms) {
            prg = GetShader();
        }
        if (prg) {
            static_cast<const ShaderProgramGLSL*>(prg)->SetPMVMatrix(m_projection_view_matrix);
        }
        m_reset_uniforms = false;
    }
    
}



