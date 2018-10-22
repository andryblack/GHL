/*
 GHL - Game Helpers Library
 Copyright (C)  Andrey Kunitsyn 2009
 
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 
 Andrey (AndryBlack) Kunitsyn
 blackicebox (at) gmail (dot) com
 */

#include "render_impl.h"
#include "lucida_console_regular_8.h"
#include "rendertarget_impl.h"
#include "texture_impl.h"
#include "shader_impl.h"
#include "buffer_impl.h"
#include <cstdio>
#include <algorithm>
#include <cassert>
#include "../ghl_log_impl.h"
#include "../ghl_data_impl.h"

namespace GHL {
    
    
    bool HaveAlpha(const Texture* tex) {
        if (!tex) return false;
        switch (tex->GetFormat()) {
            case TEXTURE_FORMAT_4444:
            case TEXTURE_FORMAT_ALPHA:
            case TEXTURE_FORMAT_RGBA:
                return true;
            default:
                break;
        }
        return false;
    }
	
    static const char* MODULE = "RENDER";
    
    RenderImpl::RenderImpl(UInt32 w,UInt32 h,bool haveDepth) :
	m_width(w),m_height(h),m_sfont_texture(0)
    {
        m_scene_target = 0;
        m_have_depth = haveDepth;
        for (UInt32 i=0;i<MAX_TEXTURE_STAGES;++i)
            m_current_texture[i]=0;
        m_current_shader = 0;
        m_current_v_buffer = 0;
        m_current_i_buffer = 0;
		m_scene_started = false;
        m_textures_mem = 0;
        m_rt_mem = 0;
        (void)MODULE;
    }
	
    RenderImpl::~RenderImpl()
    {
    }
	
	
	
    void GHL_CALL RenderImpl::Release() {
        delete this;
    }
	
    /// Begin graphics scene (frame)
    void GHL_CALL RenderImpl::BeginScene(RenderTarget* target) {
        if (m_scene_started) {
            m_scene_started = false;
            assert(false && "scene already started");
        }
        m_scene_target = static_cast<RenderTargetImpl*>(target);
        if (m_scene_target) {
            m_scene_target->AddRef();
			m_scene_target->BeginScene(this);
		}
        SetOrthoProjection();
		ResetRenderState();
        m_scene_started = true;
    }
	
    /// End graphics scene (frame)
    void GHL_CALL RenderImpl::EndScene()  {
		assert(m_scene_started);
		if (m_scene_target) {
			m_scene_target->EndScene(this);
            m_scene_target->Release();
		}
        m_scene_target = 0;
		m_scene_started = false;
    }
	
    
    
    void RenderImpl::Resize(UInt32 w,UInt32 h) {
        m_width = w;
        m_height = h;
        LOG_INFO( "Render size : " << m_width << "x" << m_height );
    }
	
	
    UInt32 GHL_CALL RenderImpl::GetWidth() const {
        if (m_scene_target) return m_scene_target->GetWidth();
        return m_width;
    }
    UInt32 GHL_CALL RenderImpl::GetHeight() const {
        if (m_scene_target) return m_scene_target->GetHeight();
        return m_height;
    }
	
	
	
    void RenderImpl::ResetRenderState()
    {
        SetShader(0);
        SetTexture(0,0);
        SetTexture(0,1);
        SetIndexBuffer(0);
        SetVertexBuffer(0);
        SetupBlend(true,BLEND_FACTOR_SRC_ALPHA,BLEND_FACTOR_SRC_ALPHA_INV);
        SetupDepthTest(false);
        SetupTextureStageColorOp(TEX_OP_MODULATE,TEX_ARG_TEXTURE,TEX_ARG_CURRENT,0);
        SetupTextureStageAlphaOp(TEX_OP_MODULATE,TEX_ARG_TEXTURE,TEX_ARG_CURRENT,0);
        SetupTextureStageColorOp(TEX_OP_DISABLE,TEX_ARG_TEXTURE,TEX_ARG_CURRENT,1);
        SetupTextureStageAlphaOp(TEX_OP_DISABLE,TEX_ARG_TEXTURE,TEX_ARG_CURRENT,1);
        SetupFaceCull(false);
		SetupScisor(false);
    }
	
	
	
    bool RenderImpl::RenderInit() {
        LOG_VERBOSE("RenderImpl::RenderInit");
        if (m_sfont_texture) return true;
        Data* data = GHL_HoldData((const Byte*)lucida_console_regular_8_data,
                                  lucida_console_regular_8_width*lucida_console_regular_8_height*4);
        Image* img = GHL_CreateImageWithData(lucida_console_regular_8_width,
                                     lucida_console_regular_8_height,
                                     IMAGE_FORMAT_RGBA,
                                             data);
        data->Release();
        m_sfont_texture = CreateTexture(lucida_console_regular_8_width,
                                        lucida_console_regular_8_height,
                                        TEXTURE_FORMAT_RGBA,img);
        img->Release();
        m_sfont_texture->DiscardInternal();
        return m_sfont_texture != 0;
    }
	
	
    void RenderImpl::RenderDone() {
        ResetRenderState();
        if (m_sfont_texture) {
            m_sfont_texture->Release();
            m_sfont_texture = 0;
        }
        this->RenderImpl::SetShader(0);
#ifdef GHL_DEBUG
        if (!m_textures.empty()) {
            LOG_ERROR("unreleased " << m_textures.size() << " textures");
        }
        if (!m_targets.empty()) {
            LOG_ERROR("unreleased " << m_targets.size() << " targets");
        }
        if (!m_v_shaders.empty()) {
            LOG_ERROR("unreleased " << m_v_shaders.size() << " vertex shaders");
        }
        if (!m_f_shaders.empty()) {
            LOG_ERROR("unreleased " << m_f_shaders.size() << " fragment shaders");
        }
        if (!m_shaders.empty()) {
            LOG_ERROR("unreleased " << m_shaders.size() << " shaders");
        }
        if (!m_v_buffers.empty()) {
            LOG_ERROR("unreleased " << m_v_buffers.size() << " vertex buffers");
        }
        if (!m_i_buffers.empty()) {
            LOG_ERROR("unreleased " << m_i_buffers.size() << " index buffers");
        }
#endif
    }
    
    static const float identity[4][4] = {
        { 1.0f, 0.0f, 0.0f, 0.0f },
        { 0.0f, 1.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 1.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f, 1.0f }
    };
    
	
    void RenderImpl::SetOrthoProjection() {
        float projectionOrtho[16];
        const float w = float(GetWidth());
        const float h = float(GetHeight());
        std::fill(projectionOrtho,projectionOrtho+16,0.0f);
        projectionOrtho[0+0*4] = (2.0f / (w - 0.0f));
        projectionOrtho[1+1*4] = (2.0f / (0.0f - h));
        projectionOrtho[2+2*4] = (-2.0f / (1.0f - -1.0f));
        projectionOrtho[0+3*4] = -(w + 0.0f) / (w - 0.0f);
        projectionOrtho[1+3*4] = -(0.0f + h) / (0.0f - h);
        projectionOrtho[2+3*4] = -(1.0f + -1.0f) / (1.0f - -1.0f);
        projectionOrtho[3+3*4] = 1.0f;
        SetProjectionMatrix(&projectionOrtho[0]);
        SetViewMatrix(&identity[0][0]);
    }
	
    void GHL_CALL RenderImpl::DebugDrawText(Int32 x, Int32 y, const char *text) {
        if (m_sfont_texture) {
            SetOrthoProjection();
            const Texture* oldTexture = m_current_texture[0];
            SetTexture(m_sfont_texture,0);
            SetupTextureStageColorOp(TEX_OP_MODULATE,TEX_ARG_TEXTURE,TEX_ARG_CURRENT,0);
            SetupTextureStageAlphaOp(TEX_OP_MODULATE,TEX_ARG_TEXTURE,TEX_ARG_CURRENT,0);
            SetupTextureStageColorOp(TEX_OP_DISABLE,TEX_ARG_TEXTURE,TEX_ARG_CURRENT,1);
            SetupTextureStageAlphaOp(TEX_OP_DISABLE,TEX_ARG_TEXTURE,TEX_ARG_CURRENT,1);

            static Vertex vtxbuf[128];
            static const UInt16 indxbuf[] = {
                0,1,2,2,3,0,
                0+4*1,1+4*1,2+4*1,2+4*1,3+4*1,0+4*1,
                0+4*2,1+4*2,2+4*2,2+4*2,3+4*2,0+4*2,
                0+4*3,1+4*3,2+4*3,2+4*3,3+4*3,0+4*3,
                0+4*4,1+4*4,2+4*4,2+4*4,3+4*4,0+4*4,
                0+4*5,1+4*5,2+4*5,2+4*5,3+4*5,0+4*5,
                0+4*6,1+4*6,2+4*6,2+4*6,3+4*6,0+4*6,
                0+4*7,1+4*7,2+4*7,2+4*7,3+4*7,0+4*7,
                0+4*8,1+4*8,2+4*8,2+4*8,3+4*8,0+4*8,
                0+4*9,1+4*9,2+4*9,2+4*9,3+4*9,0+4*9,
                0+4*10,1+4*10,2+4*10,2+4*10,3+4*10,0+4*10,
                0+4*11,1+4*11,2+4*11,2+4*11,3+4*11,0+4*11,
                0+4*12,1+4*12,2+4*12,2+4*12,3+4*12,0+4*12,
                0+4*13,1+4*13,2+4*13,2+4*13,3+4*13,0+4*13,
                0+4*14,1+4*14,2+4*14,2+4*14,3+4*14,0+4*14,
                0+4*15,1+4*15,2+4*15,2+4*15,3+4*15,0+4*15,
                0+4*16,1+4*16,2+4*16,2+4*16,3+4*16,0+4*16,
                0+4*17,1+4*17,2+4*17,2+4*17,3+4*17,0+4*17,
                0+4*18,1+4*18,2+4*18,2+4*18,3+4*18,0+4*18,
                0+4*19,1+4*19,2+4*19,2+4*19,3+4*19,0+4*19,
                0+4*20,1+4*20,2+4*20,2+4*20,3+4*20,0+4*20,
                0+4*21,1+4*21,2+4*21,2+4*21,3+4*21,0+4*21,
                0+4*22,1+4*22,2+4*22,2+4*22,3+4*22,0+4*22,
                0+4*23,1+4*23,2+4*23,2+4*23,3+4*23,0+4*23,
                0+4*24,1+4*24,2+4*24,2+4*24,3+4*24,0+4*24,
                0+4*25,1+4*25,2+4*25,2+4*25,3+4*25,0+4*25,
                0+4*26,1+4*26,2+4*26,2+4*26,3+4*26,0+4*26,
                0+4*27,1+4*27,2+4*27,2+4*27,3+4*27,0+4*27,
                0+4*28,1+4*28,2+4*28,2+4*28,3+4*28,0+4*28,
                0+4*29,1+4*29,2+4*29,2+4*29,3+4*29,0+4*29,
                0+4*20,1+4*30,2+4*30,2+4*30,3+4*30,0+4*30,
                0+4*21,1+4*31,2+4*31,2+4*31,3+4*31,0+4*31,
                0+4*22,1+4*32,2+4*32,2+4*32,3+4*32,0+4*32,
            };
			
            Vertex* v = vtxbuf;
            const float itw = 1.0f / lucida_console_regular_8_width;
            const float ith = 1.0f / lucida_console_regular_8_height;
            UInt32 chars = 0;
            while (*text) {
                const CharDef& cd = lucida_console_regular_8_chars[size_t(*text)];
                float cx = float(x)  + cd.ox;
                float cy = float(y)  - cd.oy;
                {
                    v->x = cx; v->y = cy; v->z = 0.0f;
                    v->tx = itw * cd.x; v->ty = ith * cd.y;
                    v->color = 0xffffffff;
                }
                v++;
                {
                    v->x = cx + cd.w; v->y = cy; v->z = 0.0f;
                    v->tx = itw * (cd.x+ cd.w); v->ty = ith * cd.y;
                    v->color = 0xffffffff;
                }
                v++;
                {
                    v->x = cx + cd.w; v->y = cy+cd.h; v->z = 0.0f;
                    v->tx = itw * (cd.x+ cd.w); v->ty = ith * (cd.y+cd.h);
                    v->color = 0xffffffff;
                }
                v++;
                {
                    v->x = cx ; v->y = cy+cd.h; v->z = 0.0f;
                    v->tx = itw * (cd.x); v->ty = ith * (cd.y+cd.h);
                    v->color = 0xffffffff;
                }
                v++;
                text++;
                
				x+=cd.a;
				
                chars++;
                if (chars>=(sizeof(vtxbuf)/sizeof(vtxbuf[0])/4)) {
                    DrawPrimitivesFromMemory(PRIMITIVE_TYPE_TRIANGLES,VERTEX_TYPE_SIMPLE,vtxbuf,chars*4,indxbuf,chars*2);
                    chars = 0;
                    v = vtxbuf;
                }
            }
            if (chars) {
                DrawPrimitivesFromMemory(PRIMITIVE_TYPE_TRIANGLES,VERTEX_TYPE_SIMPLE,vtxbuf,chars*4,indxbuf,chars*2);
            }
			SetTexture(oldTexture,0);
        }
    }
	
#ifdef GHL_DEBUG
	
    bool RenderImpl::CheckTexture(const Texture* tex) {
        std::vector<const TextureImpl*>::iterator it = std::find(m_textures.begin(),m_textures.end(),tex);
        if (it==m_textures.end()) {
            return false;
        }
        return true;
    }
	
    bool RenderImpl::CheckRenderTarget(const RenderTarget* target) {
        std::vector<const RenderTargetImpl*>::iterator it = std::find(m_targets.begin(),m_targets.end(),target);
        if (it==m_targets.end()) {
            return false;
        }
        return true;
    }
#endif

    void RenderImpl::TextureCreated(const TextureImpl * tex)     {
        if (tex) {
            m_textures_mem += tex->GetMemoryUsage();
        }
#ifdef GHL_DEBUG
        m_textures.push_back(tex);
#endif
    }

    void RenderImpl::TextureReleased(const TextureImpl* tex) {
        if (tex) {
            UInt32 mem = tex->GetMemoryUsage();
#ifdef GHL_DEBUG
            assert(m_textures_mem>=mem);
#endif
            m_textures_mem -= mem;
        }
#ifdef GHL_DEBUG
        std::vector<const TextureImpl*>::iterator it = std::find(m_textures.begin(),m_textures.end(),tex);
        assert(it!=m_textures.end() && "release unknown texture");
        if (it!=m_textures.end()) {
            m_textures.erase(it);
        }
#endif
    }
    
    void RenderImpl::RenderTargetCreated(const RenderTargetImpl * target)  {
        if (target) {
            m_rt_mem += target->GetMemoryUsage();
        }
#ifdef GHL_DEBUG
        m_targets.push_back(target);
#endif
    }
    
    void RenderImpl::RenderTargetReleased(const RenderTargetImpl * target) {
        if (target) {
            UInt32 mem = target->GetMemoryUsage();
#ifdef GHL_DEBUG
            assert(m_rt_mem >= mem);
#endif
            m_rt_mem -= mem;
        }
#ifdef GHL_DEBUG
        std::vector<const RenderTargetImpl*>::iterator it = std::find(m_targets.begin(),m_targets.end(),target);
        if (it==m_targets.end()) {
            assert( false && "unknown target");
        } else {
            m_targets.erase(it);
        }
#endif
    }
    
    void RenderImpl::VertexShaderCreated(const VertexShaderImpl* vs) {
        (void)vs;
#ifdef GHL_DEBUG
		m_v_shaders.push_back(vs);
#endif
	}
    
	void RenderImpl::VertexShaderReleased(const VertexShaderImpl* vs) {
#ifdef GHL_DEBUG
		std::vector<const VertexShaderImpl*>::iterator it = std::find(m_v_shaders.begin(),m_v_shaders.end(),vs);
		assert(it!=m_v_shaders.end() && "release unknown vertex shader");
		if (it!=m_v_shaders.end()) {
			m_v_shaders.erase(it);
		}
#endif
	}
    
    void RenderImpl::FragmentShaderCreated(const FragmentShaderImpl* fs) {
        (void)fs;
#ifdef GHL_DEBUG
		m_f_shaders.push_back(fs);
#endif
	}
    
	void RenderImpl::FragmentShaderReleased(const FragmentShaderImpl* fs) {
#ifdef GHL_DEBUG
		std::vector<const FragmentShaderImpl*>::iterator it = std::find(m_f_shaders.begin(),m_f_shaders.end(),fs);
		assert(it!=m_f_shaders.end() && "release unknown fragment shader");
		if (it!=m_f_shaders.end()) {
			m_f_shaders.erase(it);
		}
#endif
	}
    
    void RenderImpl::ShaderProgramCreated(const ShaderProgramImpl* sp) {
        (void)sp;
#ifdef GHL_DEBUG
		m_shaders.push_back(sp);
#endif
	}
	void RenderImpl::ShaderProgramReleased(const ShaderProgramImpl* sp) {
#ifdef GHL_DEBUG
		std::vector<const ShaderProgramImpl*>::iterator it = std::find(m_shaders.begin(),m_shaders.end(),sp);
		assert(it!=m_shaders.end() && "release unknown shader program");
		if (it!=m_shaders.end()) {
			m_shaders.erase(it);
		}
#endif
	}
    
    
    void RenderImpl::BufferCreated(const VertexBufferImpl * b)     {
        (void)b;
#ifdef GHL_DEBUG
        m_v_buffers.push_back(b);
#endif
    }
    
    void RenderImpl::BufferReleased(const VertexBufferImpl* b) {
        (void)b;
#ifdef GHL_DEBUG
        std::vector<const VertexBufferImpl*>::iterator it = std::find(m_v_buffers.begin(),m_v_buffers.end(),b);
        assert(it!=m_v_buffers.end() && "release unknown vertex buffer");
        if (it!=m_v_buffers.end()) {
            m_v_buffers.erase(it);
        }
#endif
    }
    
    void RenderImpl::BufferCreated(const IndexBufferImpl * b)     {
        (void)b;
#ifdef GHL_DEBUG
        m_i_buffers.push_back(b);
#endif
    }
    
    void RenderImpl::BufferReleased(const IndexBufferImpl* b) {
        (void)b;
#ifdef GHL_DEBUG
        std::vector<const IndexBufferImpl*>::iterator it = std::find(m_i_buffers.begin(),m_i_buffers.end(),b);
        assert(it!=m_i_buffers.end() && "release unknown index buffer");
        if (it!=m_i_buffers.end()) {
            m_i_buffers.erase(it);
        }
#endif
    }
	
    UInt32 GHL_CALL RenderImpl::GetMemoryUsage() const {
        UInt32 res = 0;
        res += m_textures_mem;
        res += m_rt_mem;
        return res;
    }
    
    
    const Texture* RenderImpl::GetTexture(UInt32 stage) {
        assert(stage<MAX_TEXTURE_STAGES);
        return m_current_texture[stage];
    }
    
    void GHL_CALL RenderImpl::SetTexture( const Texture* texture, UInt32 stage)  {
        assert(stage<MAX_TEXTURE_STAGES);
#ifdef GHL_DEBUG
        if (texture && !CheckTexture(texture)) {
            LOG_FATAL( "bind unknown texture" );
            assert(false && "bind unknown texture");
            return;
        }
        if (m_scene_target) {
            if (m_scene_target->GetTexture()==texture) {
                LOG_FATAL( "bind texture from active target");
                assert(false && "bind unknown texture");
                return;
            }
        }
        if (texture && !static_cast<const TextureImpl*>(texture)->IsValid()) {
            LOG_ERROR("bind invalid texture");
        }
#endif
        if (texture) {
            texture->AddRef();
        }
        if (m_current_texture[stage]) {
            m_current_texture[stage]->Release();
        }
        m_current_texture[stage] = texture;
    }
	
    
    void GHL_CALL RenderImpl::SetShader(const ShaderProgram *shader) {
#ifdef GHL_DEBUG
        if (shader) {
            std::vector<const ShaderProgramImpl*>::iterator it = std::find(m_shaders.begin(),m_shaders.end(),shader);
            assert(it!=m_shaders.end() && "bind unknown shader");
            if (it==m_shaders.end()) {
                LOG_ERROR( "bind unknown shader" );
                return;
            }
        }
#endif
        if (shader) {
            shader->AddRef();
        }
        if (m_current_shader) {
            m_current_shader->Release();
        }
        m_current_shader = shader;
    }
    
    
    void GHL_CALL RenderImpl::SetIndexBuffer(const IndexBuffer* buf) {
#ifdef GHL_DEBUG
        if (buf) {
            std::vector<const IndexBufferImpl*>::iterator it = std::find(m_i_buffers.begin(),m_i_buffers.end(),buf);
            assert(it!=m_i_buffers.end() && "bind unknown index buffer");
            if (it==m_i_buffers.end()) {
                LOG_ERROR( "bind unknown index buffer" );
                return;
            }
        }
#endif
        if (buf) {
            buf->AddRef();
        }
        if (m_current_i_buffer) {
            m_current_i_buffer->Release();
        }
        m_current_i_buffer = static_cast<const IndexBufferImpl*>(buf);
    }
    
    void GHL_CALL RenderImpl::SetVertexBuffer(const VertexBuffer* buf) {
#ifdef GHL_DEBUG
        if (buf) {
            std::vector<const VertexBufferImpl*>::iterator it = std::find(m_v_buffers.begin(),m_v_buffers.end(),buf);
            assert(it!=m_v_buffers.end() && "bind unknown vertex buffer");
            if (it==m_v_buffers.end()) {
                LOG_ERROR( "bind unknown vertex buffer" );
                return;
            }
        }
#endif
        if (buf) {
            buf->AddRef();
        }
        if (m_current_v_buffer) {
            m_current_v_buffer->Release();
        }
        m_current_v_buffer = static_cast<const VertexBufferImpl*>(buf);
    }
    
    bool GHL_CALL RenderImpl::IsFeatureSupported(RenderFeature /*feature*/) {
        return false;
    }
    bool GHL_CALL RenderImpl::IsTextureFormatSupported(TextureFormat fmt) {
        return false;
    }
    void RenderImpl::MatrixMul(const float* a,const float* b,float* r) {
        for (int x=0; x<4; x++)
        {
            for (int y=0; y<4; y++)
            {
                r[x+y*4] =
                a[0*4 + x]*b[y*4 + 0] +
                a[1*4 + x]*b[y*4 + 1] +
                a[2*4 + x]*b[y*4 + 2] +
                a[3*4 + x]*b[y*4 + 3];
            }
        }
    }
    
    void RenderImpl::MatrixTranspose(const float* original,float* matrix) {
        matrix[0] = original[0*4+0];
        matrix[1] = original[1*4+0];
        matrix[2] = original[2*4+0];
        matrix[3] = original[3*4+0];
        
        matrix[1*4+0] = original[0*4+1];
        matrix[1*4+1] = original[1*4+1];
        matrix[1*4+2] = original[2*4+1];
        matrix[1*4+3] = original[3*4+1];
        
        matrix[2*4+0] = original[0*4+2];
        matrix[2*4+1] = original[1*4+2];
        matrix[2*4+2] = original[2*4+2];
        matrix[2*4+3] = original[3*4+2];
        
        matrix[3*4+0] = original[0*4+3];
        matrix[3*4+1] = original[1*4+3];
        matrix[3*4+2] = original[2*4+3];
        matrix[3*4+3] = original[3*4+3];
    }
    
    void RenderImpl::MatrixTranspose(float* matrix) {
        float original[16];
        for (int cnt=0; cnt<16; cnt++)
            original[cnt] = matrix[cnt];
        MatrixTranspose(original, matrix);
        
    }
}


