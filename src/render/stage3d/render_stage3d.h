#ifndef GHL_RENDER_STAGE3D_H
#define GHL_RENDER_STAGE3D_H

#include "../render_impl.h"
#include "../shader_impl.h"
#include "../buffer_impl.h"
#include "agal_generator.h"
#include "../pfpl/pfpl_render.h"

#include <AS3/AS3.h>
#include <Flash++.h>


namespace GHL {
    
    
    class RenderStage3d : public RenderImpl {
    private:
        AS3::ui::flash::display3D::Context3D m_ctx;
        AGALGenerator   m_generator;
        pfpl_render         m_shaders_render;
        pfpl_state_data     m_crnt_state;
        
        class VertexShaderStage3d : public VertexShaderImpl {
        private:
            AS3::ui::flash::utils::ByteArray   m_data;
        public:
            VertexShaderStage3d( RenderImpl* render, const Data* data);
            ~VertexShaderStage3d();
            const AS3::ui::flash::utils::ByteArray& data() { return m_data; }
        };
        class FragmentShaderStage3d : public FragmentShaderImpl {
        private:
            AS3::ui::flash::utils::ByteArray   m_data;
        public:
            FragmentShaderStage3d( RenderImpl* render, const Data* data);
            ~FragmentShaderStage3d();
            const AS3::ui::flash::utils::ByteArray& data() { return m_data; }
        };
        class ShaderProgramStage3d : public ShaderProgramImpl {
        private:
            AS3::ui::flash::display3D::Program3D m_program;
        public:
            ShaderProgramStage3d(RenderImpl* render, const AS3::ui::flash::display3D::Program3D& p );
            ~ShaderProgramStage3d();
            const AS3::ui::flash::display3D::Program3D& program() const { return m_program; }
            virtual ShaderUniform* GHL_CALL GetUniform(const char* name);
        };
        class VertexBufferStage3d : public VertexBufferImpl {
        private:
            AS3::ui::flash::display3D::VertexBuffer3D m_buffer;
        public:
            VertexBufferStage3d( RenderImpl* render,
                                VertexType type,
                                UInt32 size,
                                const AS3::ui::flash::display3D::VertexBuffer3D& data);
            ~VertexBufferStage3d();
            const AS3::ui::flash::display3D::VertexBuffer3D& buffer() const { return m_buffer; }
            
            virtual void GHL_CALL SetData(const Data* data);
        };
        class IndexBufferStage3d : public IndexBufferImpl {
        private:
            AS3::ui::flash::display3D::IndexBuffer3D m_buffer;
        public:
            IndexBufferStage3d( RenderImpl* render,
                                UInt32 size,
                                const AS3::ui::flash::display3D::IndexBuffer3D& data);
            ~IndexBufferStage3d();
            const AS3::ui::flash::display3D::IndexBuffer3D& buffer() const { return m_buffer; }
            
            virtual void GHL_CALL SetData(const Data* data);
        };
        void BeginDrawPrimitives(PrimitiveType type,VertexType v_type);
        static const size_t RING_BUFFERS_AMOUNT = 128;
        struct RingElement {
            AS3::ui::flash::display3D::VertexBuffer3D   vbuffer;
            AS3::ui::flash::display3D::IndexBuffer3D    ibuffer;
            size_t vsize;
            size_t isize;
            RingElement() : vsize(0),isize(0) {}
        };
        RingElement   m_ring[RING_BUFFERS_AMOUNT];
        size_t  m_ring_pos;
    public:
        RenderStage3d( UInt32 w, UInt32 h, bool depth );
        
        void SetContext( const AS3::ui::flash::display3D::Context3D& ctx );
        
        
        virtual bool RenderInit();
		virtual void RenderDone();
		virtual bool RenderSetFullScreen(bool fs);
        
        /// render
        
        /// Begin graphics scene (frame)
		virtual void GHL_CALL BeginScene(RenderTarget* target);
		/// End graphics scene (frame)
		virtual void GHL_CALL EndScene();
		
		/// clear scene
		virtual void GHL_CALL Clear(float r,float g,float b,float a,float depth);
		
		/// create empty texture
		virtual Texture* GHL_CALL CreateTexture(UInt32 width,UInt32 height,TextureFormat fmt,const Image* data=0);
		
		/// set current texture
		virtual void GHL_CALL SetTexture(const Texture* texture, UInt32 stage = 0);
		/// set texture stage color operation
		virtual void GHL_CALL SetupTextureStageColorOp(TextureOperation op,TextureArgument arg1,TextureArgument arg2,UInt32 stage = 0);
		/// set texture stage alpha operation
		virtual void GHL_CALL SetupTextureStageAlphaOp(TextureOperation op,TextureArgument arg1,TextureArgument arg2,UInt32 stage = 0);
		
		/// set blend factors
		virtual void GHL_CALL SetupBlend(bool enable,BlendFactor src_factor = BLEND_FACTOR_ONE,BlendFactor dst_factor=BLEND_FACTOR_ZERO);
		/// set alpha test parameters
		virtual void GHL_CALL SetupAlphaTest(bool enable,CompareFunc func=COMPARE_FUNC_ALWAYS,float ref=0);
		/// set depth test
		virtual void GHL_CALL SetupDepthTest(bool enable,CompareFunc func=COMPARE_FUNC_ALWAYS,bool write_enable=false);
		/// setup faces culling
		virtual void GHL_CALL SetupFaceCull(bool enable,bool cw = true);
		
		/// create index buffer
		virtual IndexBuffer* GHL_CALL CreateIndexBuffer(UInt32 size);
		/// set current index buffer
		virtual void GHL_CALL SetIndexBuffer(const IndexBuffer* buf);
		/// create vertex buffer
		virtual VertexBuffer* GHL_CALL CreateVertexBuffer(VertexType type,UInt32 size);
		/// set current vertex buffer
		virtual void GHL_CALL SetVertexBuffer(const VertexBuffer* buf);
        
		/// set projection matrix
		virtual void GHL_CALL SetProjectionMatrix(const float *m);
		/// set view matrix
		virtual void GHL_CALL SetViewMatrix(const float* m);
		
		/// setup scisor test
		virtual void GHL_CALL SetupScisor( bool enable, UInt32 x=0, UInt32 y=0, UInt32 w=0, UInt32 h=0 );
		/// draw primitives
		/**
		 * @par type primitives type
		 * @par v_amount vertices amount used in this call
		 * @par i_begin start index buffer position
		 * @par amount drw primitives amount
		 */
		virtual void GHL_CALL DrawPrimitives(PrimitiveType type,UInt32 v_amount,UInt32 i_begin,UInt32 amount);
        
		/// draw primitives from memory
		virtual void GHL_CALL DrawPrimitivesFromMemory(PrimitiveType type,VertexType v_type,const void* vertices,UInt32 v_amount,const UInt16* indexes,UInt32 prim_amount);
		
		virtual RenderTarget* GHL_CALL CreateRenderTarget(UInt32 w,UInt32 h,TextureFormat fmt,bool depth);
		
		virtual VertexShader* GHL_CALL CreateVertexShader(const Data* ds);
		virtual FragmentShader* GHL_CALL CreateFragmentShader(const Data* ds);
		virtual ShaderProgram* GHL_CALL CreateShaderProgram(VertexShader* v,FragmentShader* f);
		
		virtual void GHL_CALL SetShader(const ShaderProgram* shader);
        
    private:
        float   m_p_matrix[16];
        float   m_v_matrix[16];
        float   m_pv_matrix[16];
        void CalcPVMatrix();
        bool    m_scene_cleared;
    };
    
}


#endif /*GHL_RENDER_STAGE3D_H*/