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

#ifndef GHL_RENDER_H
#define GHL_RENDER_H

#include "ghl_types.h"
#include "ghl_api.h"

#include "ghl_texture.h"
#include "ghl_render_target.h"
#include "ghl_shader.h"
#include "ghl_data.h"

namespace GHL
{
	
	/// draw primitive type
	enum PrimitiveType
	{
		PRIMITIVE_TYPE_TRIANGLES,		///< triangles
		PRIMITIVE_TYPE_TRIANGLE_STRIP,	///< tringle strip
		PRIMITIVE_TYPE_TRIANGLE_FAN,	///< tringle fan
		PRIMITIVE_TYPE_LINES,			///< lines
		PRIMITIVE_TYPE_LINE_STRIP		///< line strip
	};

	/// vertex data
	struct Vertex
	{
		float	x;	///< vertex position  x
		float	y;	///< vertex position  y
		float  	z;	///< vertex position  z
		UInt32	color;	///< diffuse color
		float	tx;		///< texture coordinate x
		float 	ty;		///< texture coordinate y
	};

	/// vertex with 2 texture coordinates data
	struct Vertex2Tex : public Vertex
	{
		float	t2x;	///< second texture coordinate x
		float	t2y;	///< second texture coordinate y
	};

	/// vertex type name
	enum VertexType
	{
		VERTEX_TYPE_SIMPLE,	///<x,y,z color, one texture coords ( Vertex )
		VERTEX_TYPE_2_TEX,	///<x,y,z color, two texture coords ( Vertex2Tex )
	};

	/// vertex buffer object
	struct VertexBuffer : RefCounter
	{
		/// get vertex type
		virtual VertexType GHL_CALL GetType() const = 0;
		/// get buffer capacity
		virtual UInt32 GHL_CALL GetCapacity() const = 0;
		/// set buffer data
		virtual void GHL_CALL SetData(const Data* data) = 0;
	};

	/// index buffer object
	struct IndexBuffer : RefCounter
	{
		/// get buffer capacity
		virtual UInt32 GHL_CALL GetCapacity() const = 0;
		/// set buffer data
		virtual void GHL_CALL SetData(const Data* data) = 0;
	};



	/// source or destination blend factor
	enum BlendFactor
	{
		BLEND_FACTOR_SRC_COLOR,		///< source color
		BLEND_FACTOR_SRC_COLOR_INV,	///< inverse source color
		BLEND_FACTOR_SRC_ALPHA,		///< source alpha
		BLEND_FACTOR_SRC_ALPHA_INV,	///< inverse source alpha
		BLEND_FACTOR_DST_COLOR,		///< destination color
		BLEND_FACTOR_DST_COLOR_INV,	///< inverse destination color
		BLEND_FACTOR_DST_ALPHA,		///< destination alpha
		BLEND_FACTOR_DST_ALPHA_INV,	///< inverse destination alpha
		BLEND_FACTOR_ONE,			///< one
		BLEND_FACTOR_ZERO,			///< zero
	};

	/// compare function
	enum CompareFunc
	{
		COMPARE_FUNC_ALWAYS,	///< alvays true
		COMPARE_FUNC_NEVER,		///< alvays false
		COMPARE_FUNC_GREATER,	///< value is greater
		COMPARE_FUNC_LESS,		///< value is less
		COMPARE_FUNC_EQUAL,		///< value is equal
		COMPARE_FUNC_NEQUAL,		///< value is not equal
		COMPARE_FUNC_GEQUAL,		///< value is greater or equal
		COMPARE_FUNC_LEQUAL,		///< value is less or equal
	};

	/// texture stage operation argument
	enum TextureArgument
	{
		TEX_ARG_TEXTURE,		///< current texture
		TEX_ARG_TEXTURE_INV,	///< inverse current texture
		TEX_ARG_CURRENT,		///< prev stage value
		TEX_ARG_CURRENT_INV,    ///< inverse prev stage value
        TEX_ARG_TEXTURE_ALPHA,	///< current texture alpha
        TEX_ARG_TEXTURE_ALPHA_INV,	///< inverse current texture alpha
        TEX_ARG_CURRENT_ALPHA,		///< prev stage alpha value
        TEX_ARG_CURRENT_ALPHA_INV   ///< inverse prev stage alpha value
  	};

	/// texture stage operation
	enum TextureOperation
	{
		TEX_OP_DISABLE,			///< disable stage
		TEX_OP_SELECT_1,		///< select arg 1
		TEX_OP_SELECT_2,		///< select arg 2
		TEX_OP_MODULATE,		///< modulate (multiply)
		TEX_OP_ADD,				///< add
		TEX_OP_INT_TEXTURE_ALPHA,///< interpolate from arg1 to arg2 by texture alpha value
		TEX_OP_INT_CURRENT_ALPHA,///< interpolate from arg1 to arg2 by current alpha value
	};
    
    /// render feature
    enum RenderFeature
    {
        RENDER_FEATURE_NPOT_TEXTURES,   ///< NPOT textures support
        RENDER_FEATURE_NPOT_TARGET,     ///< NPOT Render target
    };
    
    static const UInt32 MAX_TEXTURE_STAGES = 4;
    
    struct Image;

	/// render interface
	struct Render
	{
		/// Begin graphics scene (frame)
		virtual void GHL_CALL BeginScene(RenderTarget* target) = 0;
		/// End graphics scene (frame)
		virtual void GHL_CALL EndScene() = 0;
		
		/// Get render width
		virtual UInt32 GHL_CALL GetWidth() const = 0;
		/// Get render height
		virtual UInt32 GHL_CALL GetHeight() const = 0;
		
		/// clear scene
		virtual void GHL_CALL Clear(float r,float g,float b,float a, float depth) = 0;
		
		/// create empty texture
		virtual Texture* GHL_CALL CreateTexture(UInt32 width,UInt32 height,TextureFormat fmt,const Image* data=0) = 0;
		
		/// set current texture
		virtual void GHL_CALL SetTexture(const Texture* texture, UInt32 stage = 0) = 0;
		/// set texture stage color operation
		virtual void GHL_CALL SetupTextureStageColorOp(TextureOperation op,TextureArgument arg1,TextureArgument arg2,UInt32 stage = 0) = 0;
		/// set texture stage alpha operation
		virtual void GHL_CALL SetupTextureStageAlphaOp(TextureOperation op,TextureArgument arg1,TextureArgument arg2,UInt32 stage = 0) = 0;
		
		/// set blend factors
		virtual void GHL_CALL SetupBlend(bool enable,BlendFactor src_factor = BLEND_FACTOR_ONE,BlendFactor dst_factor=BLEND_FACTOR_ZERO) = 0;
		/// set depth test
		virtual void GHL_CALL SetupDepthTest(bool enable,CompareFunc func=COMPARE_FUNC_ALWAYS,bool write_enable=false) = 0;
		/// setup faces culling
		virtual void GHL_CALL SetupFaceCull(bool enable,bool cw = true) = 0;
		
		/// create index buffer
		virtual IndexBuffer* GHL_CALL CreateIndexBuffer(UInt32 size) = 0;
		/// set current index buffer
		virtual void GHL_CALL SetIndexBuffer(const IndexBuffer* buf) = 0;
		/// create vertex buffer
		virtual VertexBuffer* GHL_CALL CreateVertexBuffer(VertexType type,UInt32 size) = 0;
		/// set current vertex buffer
		virtual void GHL_CALL SetVertexBuffer(const VertexBuffer* buf) = 0;

		/// set projection matrix
		virtual void GHL_CALL SetProjectionMatrix(const float *m) = 0;
		/// set view matrix
		virtual void GHL_CALL SetViewMatrix(const float* m) = 0;
		
		/// setup scisor test
		virtual void GHL_CALL SetupScisor( bool enable, UInt32 x=0, UInt32 y=0, UInt32 w=0, UInt32 h=0 ) = 0;
		/// draw primitives
		/**
		 * @par type primitives type
		 * @par v_amount vertices amount used in this call
		 * @par i_begin start index buffer position
		 * @par amount drw primitives amount
		 */
		virtual void GHL_CALL DrawPrimitives(PrimitiveType type,UInt32 v_amount,UInt32 i_begin,UInt32 amount) = 0;

		/// draw primitives from memory
		virtual void GHL_CALL DrawPrimitivesFromMemory(PrimitiveType type,VertexType v_type,const void* vertices,UInt32 v_amount,const UInt16* indexes,UInt32 prim_amount) = 0;
		
		/// create render target interface
		virtual RenderTarget* GHL_CALL CreateRenderTarget(UInt32 w,UInt32 h,TextureFormat fmt,bool depth) = 0;
		/// create vertex shader interface
		virtual VertexShader* GHL_CALL CreateVertexShader(const Data* ds) = 0;
		/// create fragment shader interface
		virtual FragmentShader* GHL_CALL CreateFragmentShader(const Data* ds) = 0;
		/// create shader program interface
		virtual ShaderProgram* GHL_CALL CreateShaderProgram(VertexShader* v,FragmentShader* f) = 0;
		/// set current shader
		virtual void GHL_CALL SetShader(const ShaderProgram* shader) = 0;
        
        /// feature is supported
        virtual bool GHL_CALL IsFeatureSupported(RenderFeature feature) = 0;
        /// texture format is supported
        virtual bool GHL_CALL IsTextureFormatSupported(TextureFormat fmt) = 0;
		
		/// draw debug text
		virtual void GHL_CALL DebugDrawText( Int32 x,Int32 y,const char* text ) = 0;
		/// get data memory usage
		virtual UInt32 GHL_CALL GetMemoryUsage() const = 0;
	};
	
	


}/*namespace*/





#endif /*GHL_RENDER_H*/
