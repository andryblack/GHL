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

#ifndef RENDER_IMPL_H
#define RENDER_IMPL_H

#include "ghl_render.h"

#include <cstring>
#include <vector>

namespace GHL {

	class RenderTargetImpl;
    class TextureImpl;
    class VertexShaderImpl;
    class FragmentShaderImpl;
    class ShaderProgramImpl;
    class VertexBufferImpl;
    class IndexBufferImpl;
    
    bool HaveAlpha(const Texture* tex);

	class RenderImpl : public Render
	{
	public:
		RenderImpl(UInt32 w,UInt32 h,bool haveDepth);
		virtual ~RenderImpl();

		void Resize(UInt32 w,UInt32 h);
        
		virtual void GHL_CALL Release();
	
		/// Begin graphics scene (frame)
		virtual void GHL_CALL BeginScene(RenderTarget* target);
		/// End graphics scene (frame)
		virtual void GHL_CALL EndScene() ;
	
	
		virtual void ResetRenderState();
		virtual bool RenderInit() = 0;
		virtual void RenderDone() = 0;
		virtual bool RenderSetFullScreen(bool fs) = 0;
        virtual void SetOrthoProjection();
	
		virtual UInt32 GHL_CALL GetWidth() const;
		virtual UInt32 GHL_CALL GetHeight() const;
	
        virtual void GHL_CALL SetTexture( const Texture* texture, UInt32 stage);
        virtual void GHL_CALL SetShader(const GHL::ShaderProgram *shader);
        virtual void GHL_CALL SetIndexBuffer(const IndexBuffer* buf);
		virtual void GHL_CALL SetVertexBuffer(const VertexBuffer* buf);

        virtual bool GHL_CALL IsFeatureSupported(RenderFeature feature);
        virtual bool GHL_CALL IsTextureFormatSupported(TextureFormat fmt);
        
		virtual void GHL_CALL DebugDrawText( Int32 x,Int32 y,const char* text );
	
		virtual UInt32 GHL_CALL GetMemoryUsage() const;
    protected:
#ifdef GHL_DEBUG
		bool CheckTexture(const Texture*);
		bool CheckRenderTarget(const RenderTarget*);
#endif
        const Texture* GetTexture(UInt32 stage);
        UInt32  GetRenderWidth() const { return m_width; }
        UInt32  GetRenderHeight() const { return m_height; }
        bool  IsSceneStarted() const { return m_scene_started; }
        const IndexBuffer* GetIndexBuffer() const { return m_current_i_buffer; }
        const VertexBuffer* GetVertexBuffer() const { return m_current_v_buffer; }
        const ShaderProgram* GetShader() const { return m_current_shader; }
        RenderTargetImpl* GetTarget() { return m_scene_target; }
        bool GetHaveDepth() const { return m_have_depth; }
        static void MatrixMul(const float* a,const float* b,float* r);
        static void MatrixTranspose(float* m);
        static void MatrixTranspose(const float* from,float* to);
	private:
        UInt32 	m_width;
		UInt32	m_height;
        UInt32  m_textures_mem;
        UInt32  m_rt_mem;
        bool    m_have_depth;
		RenderTargetImpl* m_scene_target;
		bool	m_scene_started;
		const Texture*	m_current_texture[MAX_TEXTURE_STAGES];
        const ShaderProgram*   m_current_shader;
        const VertexBuffer*     m_current_v_buffer;
        const IndexBuffer*      m_current_i_buffer;
		Texture* m_sfont_texture;
#ifdef GHL_DEBUG
		std::vector<const TextureImpl*>         m_textures;
		std::vector<const RenderTargetImpl*>    m_targets;
        std::vector<const VertexShaderImpl*>    m_v_shaders;
		std::vector<const FragmentShaderImpl*>  m_f_shaders;
		std::vector<const ShaderProgramImpl*>   m_shaders;
        std::vector<const VertexBufferImpl*>    m_v_buffers;
        std::vector<const IndexBufferImpl*>    m_i_buffers;
#endif
        friend class TextureImpl;
        void TextureCreated(const TextureImpl*);
        void TextureReleased(const TextureImpl*);
        friend class RenderTargetImpl;
		void RenderTargetCreated(const RenderTargetImpl*);
        void RenderTargetReleased(const RenderTargetImpl*);
        friend class VertexShaderImpl;
        void VertexShaderCreated(const VertexShaderImpl* vs);
        void VertexShaderReleased(const VertexShaderImpl* vs);
        friend class FragmentShaderImpl;
		void FragmentShaderCreated(const FragmentShaderImpl* fs);
        void FragmentShaderReleased(const FragmentShaderImpl* fs);
        friend class ShaderProgramImpl;
		void ShaderProgramCreated(const ShaderProgramImpl* sp);
        void ShaderProgramReleased(const ShaderProgramImpl* sp);
        friend class VertexBufferImpl;
        void BufferCreated( const VertexBufferImpl* b );
        void BufferReleased( const VertexBufferImpl* b );
        friend class IndexBufferImpl;
        void BufferCreated( const IndexBufferImpl* b );
        void BufferReleased( const IndexBufferImpl* b );
        friend class ShaderProgramGLSL;
	};

}


GHL_API GHL::RenderImpl* GHL_CALL GHL_CreateRenderOpenGL(GHL::UInt32 w,GHL::UInt32 h,bool depth);
GHL_API void GHL_DestroyRenderOpenGL(GHL::RenderImpl* render);


#endif /*RENDER_IMPL_H*/
