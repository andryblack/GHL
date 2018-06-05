/*
 *  render_opengl.h
 *  TurboSquirrel
 *
 *  Created by Андрей Куницын on 07.03.10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef GHL_RENDER_OPENGL_H
#define GHL_RENDER_OPENGL_H

#include "../render_impl.h"
#include "../pfpl/pfpl_render.h"
#include "glsl_generator.h"
#include "render_opengl_api.h"
#include "shader_glsl.h"

#include <vector>

namespace GHL
{
    class TextureOpenGL;
	class RenderTargetOpenGL;
	class VertexShaderGLSL;
	class FragmentShaderGLSL;
	class ShaderProgramGLSL;
	
	class RenderOpenGLBase : public RenderImpl
	{
	protected:
        GL  gl;
        bool    m_depth_write_enabled;
        void GetPrimitiveInfo(PrimitiveType type,UInt32 amount,GL::GLenum& ptype,UInt32& iamount) const;
	public:
		RenderOpenGLBase(UInt32 w,UInt32 h,bool haveDepth);
		~RenderOpenGLBase();
		
        const GL& get_api() const { return gl;}
		
		virtual bool RenderInit() ;
		virtual void RenderDone() ;
		virtual bool RenderSetFullScreen(bool fs) ;
		virtual void SetOrthoProjection();
        virtual void ResetRenderState();
        virtual void SetupVertexData(const Vertex* v,VertexType vt) = 0;
		void RestoreTexture();
		/// Render impl

		/// Begin graphics scene (frame)
		virtual void GHL_CALL BeginScene(RenderTarget* target);
        
		/// clear scene
		virtual void GHL_CALL Clear(float r,float g,float b,float a, float depth) ;
		
		
		/// create texture
		virtual Texture* GHL_CALL CreateTexture(UInt32 width,UInt32 height,TextureFormat fmt,const Image* data);
        virtual bool GHL_CALL IsTextureFormatSupported(TextureFormat fmt);
        
			
		/// set blend factors
		virtual void GHL_CALL SetupBlend(bool enable,BlendFactor src_factor,BlendFactor dst_factor) ;
		/// set depth test
		virtual void GHL_CALL SetupDepthTest(bool enable,CompareFunc func,bool write_enable) ;
		/// setup faces culling
		virtual void GHL_CALL SetupFaceCull(bool enable,bool cw ) ;
		
		/// create index buffer
		virtual IndexBuffer* GHL_CALL CreateIndexBuffer(UInt32 size) ;
		/// set current index buffer
		virtual void GHL_CALL SetIndexBuffer(const IndexBuffer* buf) ;
		/// create vertex buffer
		virtual VertexBuffer* GHL_CALL CreateVertexBuffer(VertexType type,UInt32 size) ;
		/// set current vertex buffer
		virtual void GHL_CALL SetVertexBuffer(const VertexBuffer* buf) ;
		
		
		/// setup scisor test
		virtual void GHL_CALL SetupScisor( bool enable, UInt32 x, UInt32 y, UInt32 w, UInt32 h );
		
		/// draw primitives
		/**
		 * @par type primitives type
		 * @par v_amount vertices amount used in this call
		 * @par i_begin start index buffer position
		 * @par amount drw primitives amount
		 */
		virtual void GHL_CALL DrawPrimitives(PrimitiveType type,UInt32 v_amount,UInt32 i_begin,UInt32 amount);
		
		/// draw primitives from memory
		virtual void GHL_CALL DrawPrimitivesFromMemory(PrimitiveType type,VertexType v_type,const void* vertices,UInt32 v_amount,const UInt16* indexes,UInt32 prim_amoun);
		
			
		virtual RenderTarget* GHL_CALL CreateRenderTarget(UInt32 w,UInt32 h,TextureFormat fmt,bool depth);
		
		
		virtual VertexShader* GHL_CALL CreateVertexShader(const Data* ds) ;
		virtual FragmentShader* GHL_CALL CreateFragmentShader(const Data* ds) ;
		virtual ShaderProgram* GHL_CALL CreateShaderProgram(VertexShader* v,FragmentShader* f) ;
		virtual void GHL_CALL SetShader(const ShaderProgram* shader);
        
        
	};
    
    class RenderOpenGLFFPL : public RenderOpenGLBase {
    protected:
        GLffpl  glffpl;
        RenderOpenGLFFPL(UInt32 w,UInt32 h,bool haveDepth);
        bool m_enabled_tex2;
    public:
        virtual void ResetRenderState();
        virtual void SetupVertexData(const Vertex* v,VertexType vt);
        
        /// set current texture
		virtual void GHL_CALL SetTexture(const Texture* texture, UInt32 stage );
        
        /// set projection matrix
		virtual void GHL_CALL SetProjectionMatrix(const float *m) ;
		/// set view matrix
		virtual void GHL_CALL SetViewMatrix(const float* m) ;
		
        /// set texture stage color operation
		virtual void GHL_CALL SetupTextureStageColorOp(TextureOperation op,TextureArgument arg1,TextureArgument arg2,UInt32 stage );
		/// set texture stage alpha operation
		virtual void GHL_CALL SetupTextureStageAlphaOp(TextureOperation op,TextureArgument arg1,TextureArgument arg2,UInt32 stage );
        
    };
    
    class RenderOpenGLPPL : public RenderOpenGLBase {
    public:
        RenderOpenGLPPL(UInt32 w,UInt32 h,bool haveDepth);
        
        bool RenderInit();
        void RenderDone();
        
        
        virtual void ResetRenderState();
        virtual void SetupVertexData(const Vertex* v,VertexType vt);
        
        /// set projection matrix
		virtual void GHL_CALL SetProjectionMatrix(const float *m) ;
		/// set view matrix
		virtual void GHL_CALL SetViewMatrix(const float* m) ;
		
        
        /// set current texture
		virtual void GHL_CALL SetTexture(const Texture* texture, UInt32 stage );
        
        /// set texture stage color operation
		virtual void GHL_CALL SetupTextureStageColorOp(TextureOperation op,TextureArgument arg1,TextureArgument arg2,UInt32 stage );
		/// set texture stage alpha operation
		virtual void GHL_CALL SetupTextureStageAlphaOp(TextureOperation op,TextureArgument arg1,TextureArgument arg2,UInt32 stage );
        
        virtual void GHL_CALL SetShader(const ShaderProgram* shader) ;
        
        virtual void GHL_CALL DrawPrimitives(PrimitiveType type,UInt32 v_amount,UInt32 i_begin,UInt32 amount);
		
		virtual void GHL_CALL DrawPrimitivesFromMemory(PrimitiveType type,VertexType v_type,const void* vertices,UInt32 v_amount,const UInt16* indexes,UInt32 prim_amoun);
        
        /// set current index buffer
        virtual void GHL_CALL SetIndexBuffer(const IndexBuffer* buf) ;
        /// set current vertex buffer
        virtual void GHL_CALL SetVertexBuffer(const VertexBuffer* buf) ;

    protected:
        GLSLGenerator&  GetGenerator() { return m_generator; }
        void ResetPointers();
        enum VertexAttributeUsage {
            VERTEX_POSITION,
            VERTEX_TEX_COORD0,
            VERTEX_TEX_COORD1,
            VERTEX_COLOR,
            VERTEX_MAX_ATTRIBUTES
        };
        void SetupAttribute(const void* ptr,
                            VertexAttributeUsage u,
                            UInt32 cnt,
                            GL::GLenum t,
                            bool norm,
                            UInt32 vsize);
        void DoDrawPrimitives(VertexType v_type);
    private:
        pfpl_render         m_shaders_render;
        pfpl_state_data     m_crnt_state;
        GLSLGenerator       m_generator;
        float               m_projection_matrix[16];
        float               m_view_matrix[16];
        float               m_projection_view_matrix[16];
        bool    m_reset_uniforms;
        
        const void*               m_current_pointers[VERTEX_MAX_ATTRIBUTES];
    };
    
}

#endif /*GHL_RENDER_OPENGL_H*/
