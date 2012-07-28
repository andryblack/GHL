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
#include <cstdio>
#include <algorithm>
#include <cassert>
#include "../ghl_log_impl.h"
#include "../ghl_data_impl.h"

namespace GHL {
	
    static const char* MODULE = "RENDER";
    
    RenderImpl::RenderImpl(UInt32 w,UInt32 h) :
	m_width(w),m_height(h),m_sfont_texture(0)
    {
        m_scene_target = 0;
		m_current_texture = 0;
		m_scene_started = false;
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
		assert(!m_scene_started);
        m_scene_target = static_cast<RenderTargetImpl*>(target);
        SetViewport(0,0,GetWidth(),GetHeight());
		if (m_scene_target) {
            m_scene_target->AddRef();
			m_scene_target->BeginScene(this);
		}
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
        SetTexture(0,0);
        SetTexture(0,1);
        SetIndexBuffer(0);
        SetVertexBuffer(0);
        SetupBlend(true,BLEND_FACTOR_SRC_ALPHA,BLEND_FACTOR_SRC_ALPHA_INV);
        SetupAlphaTest(true,COMPARE_FUNC_GREATER,0.01f);
        SetupDepthTest(false);
        SetupTextureStageColorOp(TEX_OP_MODULATE,TEX_ARG_TEXTURE,TEX_ARG_DIFFUSE,0);
        SetupTextureStageAlphaOp(TEX_OP_MODULATE,TEX_ARG_TEXTURE,TEX_ARG_DIFFUSE,0);
        SetupTextureStageColorOp(TEX_OP_DISABLE,TEX_ARG_TEXTURE,TEX_ARG_DIFFUSE,1);
        SetupTextureStageAlphaOp(TEX_OP_DISABLE,TEX_ARG_TEXTURE,TEX_ARG_DIFFUSE,1);
        SetupFaceCull(false);
		SetupScisor(false);
    }
	
	
	
    bool RenderImpl::RenderInit() {
        LOG_VERBOSE("RenderImpl::RenderInit");
        size_t size = lucida_console_regular_8_width*lucida_console_regular_8_height*4;
        ConstInlinedData data((const Byte*)lucida_console_regular_8_data,size);
        
        m_sfont_texture = CreateTexture(lucida_console_regular_8_width,lucida_console_regular_8_height,TEXTURE_FORMAT_RGBA,&data);
        return m_sfont_texture;
    }
	
	
    void RenderImpl::RenderDone() {
        if (m_sfont_texture)
            m_sfont_texture->Release();
    }
	
	
    void GHL_CALL RenderImpl::DebugDrawText(Int32 x, Int32 y, const char *text) {
        if (m_sfont_texture) {
			const Texture* oldTexture = m_current_texture;
            SetTexture(m_sfont_texture);
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
                    v->color[0] = v->color[1] = v->color[2] = v->color[3] = 0xff;
                }
                v++;
                {
                    v->x = cx + cd.w; v->y = cy; v->z = 0.0f;
                    v->tx = itw * (cd.x+ cd.w); v->ty = ith * cd.y;
                    v->color[0] = v->color[1] = v->color[2] = v->color[3] = 0xff;
                }
                v++;
                {
                    v->x = cx + cd.w; v->y = cy+cd.h; v->z = 0.0f;
                    v->tx = itw * (cd.x+ cd.w); v->ty = ith * (cd.y+cd.h);
                    v->color[0] = v->color[1] = v->color[2] = v->color[3] = 0xff;
                }
                v++;
                {
                    v->x = cx ; v->y = cy+cd.h; v->z = 0.0f;
                    v->tx = itw * (cd.x); v->ty = ith * (cd.y+cd.h);
                    v->color[0] = v->color[1] = v->color[2] = v->color[3] = 0xff;
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
			SetTexture(oldTexture);
        }
    }
	
#ifdef GHL_DEBUG
	
    void RenderImpl::TextureCreated(const Texture * tex)     {
        m_textures.push_back(tex);
    }
	
    void RenderImpl::TextureReleased(const Texture* tex) {
        if ( m_current_texture == tex ) {
            LOG_ERROR( "Release current texture" );
        }
        std::vector<const Texture*>::iterator it = std::find(m_textures.begin(),m_textures.end(),tex);
        assert(it!=m_textures.end() && "release unknown texture");
        if (it!=m_textures.end()) {
            m_textures.erase(it);
        }
    }
	
    bool RenderImpl::CheckTexture(const Texture* tex) {
        std::vector<const Texture*>::iterator it = std::find(m_textures.begin(),m_textures.end(),tex);
        if (it==m_textures.end()) {
            return false;
        }
        return true;
    }
	
	
    void RenderImpl::RenderTargetCreated(const RenderTarget * target)  {
        m_targets.push_back(target);
    }
	
    void RenderImpl::RenderTargetReleased(const RenderTarget * target) {
        std::vector<const RenderTarget*>::iterator it = std::find(m_targets.begin(),m_targets.end(),target);
        if (it==m_targets.end()) {
            assert( false && "unknown target");
        } else {
            m_targets.erase(it);
        }
    }
    bool RenderImpl::CheckRenderTarget(const RenderTarget* target) {
        std::vector<const RenderTarget*>::iterator it = std::find(m_targets.begin(),m_targets.end(),target);
        if (it==m_targets.end()) {
            return false;
        }
        return true;
    }
#endif
	
    UInt32 GHL_CALL RenderImpl::GetTexturesMemory() const {
        UInt32 res = 0;
#ifdef GHL_DEBUG
        for (size_t i=0;i<m_textures.size();i++) {
            UInt32 size = m_textures[i]->GetWidth() * m_textures[i]->GetHeight();
            if (m_textures[i]->GetFormat()==TEXTURE_FORMAT_RGBA)
                size*=4;
            else
                size*=3;
            if (m_textures[i]->HeveMipmaps())
                size*=2;
            res+=size;
        }
        for (size_t i=0;i<m_targets.size();i++) {
            UInt32 size = m_targets[i]->GetTexture()->GetWidth() * m_targets[i]->GetTexture()->GetHeight();
            if (m_targets[i]->GetTexture()->GetFormat()==TEXTURE_FORMAT_RGBA)
                size*=4;
            else
                size*=3;
            if (m_targets[i]->GetTexture()->HeveMipmaps())
                size*=2;
            if (m_targets[i]->HaveDepth())
                size+=m_targets[i]->GetWidth() * m_targets[i]->GetHeight()*4;
            res+=size;
        }
#endif
        return res;
    }
	
}

GHL_API GHL::TextureFormat GHL_CALL GHL_ImageFormatToTextureFormat( GHL::ImageFormat fmt ) {
    switch (fmt) {
        case GHL::IMAGE_FORMAT_GRAY:    return GHL::TEXTURE_FORMAT_ALPHA;
        case GHL::IMAGE_FORMAT_RGB:     return GHL::TEXTURE_FORMAT_RGB;
        case GHL::IMAGE_FORMAT_RGBA:    return GHL::TEXTURE_FORMAT_RGBA;
        case GHL::IMAGE_FORMAT_PVRTC_2: return GHL::TEXTURE_FORMAT_PVRTC_2BPPV1;
        case GHL::IMAGE_FORMAT_PVRTC_4: return GHL::TEXTURE_FORMAT_PVRTC_4BPPV1;
        default: break;
    }
    return GHL::TEXTURE_FORMAT_UNKNOWN;
}
