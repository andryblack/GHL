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
#include "ghl_opengl.h"
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
	public:
		RenderOpenGLBase(UInt32 w,UInt32 h);
		~RenderOpenGLBase();
		
        const GL& get_api() const { return gl;}
		
		virtual bool RenderInit() ;
		virtual void RenderDone() ;
		virtual bool RenderSetFullScreen(bool fs) ;
		virtual void SetOrthoProjection();
        virtual void ResetRenderState();

		void RestoreTexture();
		/// Render impl

		/// Begin graphics scene (frame)
		virtual void GHL_CALL BeginScene(RenderTarget* target);
        
		/// clear scene
		virtual void GHL_CALL Clear(float r,float g,float b,float a) ;
		/// clear depth
		virtual void GHL_CALL ClearDepth(float d) ;
		
		virtual void GHL_CALL SetViewport(UInt32 x,UInt32 y,UInt32 w,UInt32 h);
		
		/// create empty texture
		virtual Texture* GHL_CALL CreateTexture(UInt32 width,UInt32 height,TextureFormat fmt,const Data* data);
		
		/// set current texture
		virtual void GHL_CALL SetTexture(const Texture* texture, UInt32 stage );
			
		/// set blend factors
		virtual void GHL_CALL SetupBlend(bool enable,BlendFactor src_factor,BlendFactor dst_factor) ;
		/// set alpha test parameters
		virtual void GHL_CALL SetupAlphaTest(bool enable,CompareFunc func,float ref) ;
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
		
		/// set projection matrix
		virtual void GHL_CALL SetProjectionMatrix(const float *m) ;
		/// set view matrix
		virtual void GHL_CALL SetViewMatrix(const float* m) ;
		
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
		virtual void GHL_CALL SetShader(const ShaderProgram* shader) ;
	};
    
    class RenderOpenGL : public RenderOpenGLBase {
    private:
        GLffpl  glffpl;
    public:
        RenderOpenGL(UInt32 w,UInt32 h);
        
        bool RenderInit();
        
        /// set texture stage color operation
		virtual void GHL_CALL SetupTextureStageColorOp(TextureOperation op,TextureArgument arg1,TextureArgument arg2,UInt32 stage );
		/// set texture stage alpha operation
		virtual void GHL_CALL SetupTextureStageAlphaOp(TextureOperation op,TextureArgument arg1,TextureArgument arg2,UInt32 stage );
        
    };
}

#endif /*GHL_RENDER_OPENGL_H*/
