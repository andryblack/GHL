#include "render_stage3d.h"
#include "../../ghl_log_impl.h"
#include "../../ghl_data_impl.h"
#include "texture_stage3d.h"

namespace GHL {

    using namespace AS3::ui;
    
    static const char* MODULE = "RENDER";
    
    
    RenderStage3d::VertexShaderStage3d::VertexShaderStage3d(RenderImpl* render,const Data* data)
    : VertexShaderImpl(render) {
        m_data = AS3::ui::flash::utils::ByteArray::_new();
        m_data->endian = AS3::ui::flash::utils::Endian::__LITTLE_ENDIAN;
        m_data->writeBytes(
                           AS3::ui::internal::get_ram(), (int)data->GetData(), data->GetSize(), (void*)data->GetData());
    }
    RenderStage3d::VertexShaderStage3d::~VertexShaderStage3d() {
    }
    RenderStage3d::FragmentShaderStage3d::FragmentShaderStage3d(RenderImpl* render,const Data* data)
    : FragmentShaderImpl(render) {
        m_data = AS3::ui::flash::utils::ByteArray::_new();
        m_data->endian = AS3::ui::flash::utils::Endian::__LITTLE_ENDIAN;
        m_data->writeBytes(
                           AS3::ui::internal::get_ram(), (int)data->GetData(), data->GetSize(), (void*)data->GetData());
    }
    
    RenderStage3d::FragmentShaderStage3d::~FragmentShaderStage3d() {
    }
    
    RenderStage3d::ShaderProgramStage3d::ShaderProgramStage3d(RenderImpl* render,const AS3::ui::flash::display3D::Program3D& p) : ShaderProgramImpl(render),m_program(p) {
        
    }
    RenderStage3d::ShaderProgramStage3d::~ShaderProgramStage3d() {
        
    }
    
    ShaderUniform* GHL_CALL RenderStage3d::ShaderProgramStage3d::GetUniform(const char* name) {
        return 0;
    }
    
    
    RenderStage3d::VertexBufferStage3d::VertexBufferStage3d( RenderImpl* render,
                            VertexType type, UInt32 size,AS3::ui::flash::display3D::VertexBuffer3D data) : VertexBufferImpl( render,type, size),m_buffer(data) {
        
    }
    RenderStage3d::VertexBufferStage3d::~VertexBufferStage3d() {
        
    }
    void GHL_CALL RenderStage3d::VertexBufferStage3d::SetData(UInt32 offset,const Data* data) {
        size_t vsize = GetType() == VERTEX_TYPE_SIMPLE ? sizeof(Vertex) : sizeof(Vertex2Tex);
        m_buffer->uploadFromByteArray(AS3::ui::internal::get_ram(),
                                      (int)data->GetData(),
                                      offset,data->GetSize()/vsize);
    }
    
    RenderStage3d::IndexBufferStage3d::IndexBufferStage3d( RenderImpl* render,
                                                          UInt32 size,AS3::ui::flash::display3D::IndexBuffer3D data) : IndexBufferImpl(render,size),m_buffer(data) {
        
    }
    RenderStage3d::IndexBufferStage3d::~IndexBufferStage3d() {
        
    }
    void GHL_CALL RenderStage3d::IndexBufferStage3d::SetData(UInt32 offset,const Data* data) {
        m_buffer->uploadFromByteArray(AS3::ui::internal::get_ram(),
                                      (int)data->GetData(),offset,data->GetSize()/2);
    }
    
    
//#define NOT_IMPLEMENTED LOG_VERBOSE("not implemented " << __FUNCTION__ );
#define NOT_IMPLEMENTED (void)0;
    
    RenderStage3d::RenderStage3d(UInt32 w,UInt32 h) : RenderImpl(w,h) {
        
    }
    
    void RenderStage3d::SetContext( const flash::display3D::Context3D& ctx ) {
        m_ctx = ctx;
    }
    
    
    bool RenderStage3d::RenderInit() {
        m_generator.init(this);
        m_shaders_render.init(&m_generator);
        return RenderImpl::RenderInit();
    }
    
    void RenderStage3d::RenderDone() {
        
        RenderImpl::RenderDone();
    }
    bool RenderStage3d::RenderSetFullScreen(bool fs) {
        NOT_IMPLEMENTED;
    }
    
    
    /// Begin graphics scene (frame)
    void GHL_CALL RenderStage3d::BeginScene(RenderTarget* target) {
        RenderImpl::BeginScene(target);
        if (!target) {
            m_ctx->setRenderToBackBuffer();
        } else {
            
        }
    }
    
    /// End graphics scene (frame)
    void GHL_CALL RenderStage3d::EndScene() {
        RenderImpl::EndScene();
    }
    
    
    /// set viewport
    void GHL_CALL RenderStage3d::SetViewport(UInt32 x,UInt32 y,UInt32 w,UInt32 h) {
        
    }
    
    /// clear scene
    void GHL_CALL RenderStage3d::Clear(float r,float g,float b,float a) {
        m_ctx->clear(r, g, b, a, 1, 0, flash::display3D::Context3DClearMask::COLOR);
    }
    
    /// clear depth
    void GHL_CALL RenderStage3d::ClearDepth(float d) {
         m_ctx->clear(0, 0, 0, 0, d, 0, flash::display3D::Context3DClearMask::DEPTH);
    }
    
    
    /// create empty texture
    Texture* GHL_CALL RenderStage3d::CreateTexture(UInt32 width,UInt32 height,TextureFormat fmt,const Image* data) {
        flash::display3D::textures::Texture tex =
            m_ctx->createTexture(width,height,
                                 flash::display3D::Context3DTextureFormat::BGRA,false,0);
        if (data) {
            Image* img = data->Clone();
            img->Convert(IMAGE_FORMAT_RGBA);
            img->SwapRB();
            const Data* dt = img->GetData();
            
            //, (int)data->GetData(), data->GetSize(), (void*)data->GetData()
            
            tex->uploadFromByteArray( AS3::ui::internal::get_ram(), (int)dt->GetData(),0 );
            img->Release();
        }
        return new TextureStage3d(tex,this,width,height);
    }
    
    /// set current texture
    void GHL_CALL RenderStage3d::SetTexture(const Texture* texture, UInt32 stage) {
        RenderImpl::SetTexture(texture,stage);
        if (texture) {
            m_crnt_state.texture_stages[stage].rgb.c.texture = true;
            m_crnt_state.texture_stages[stage].alpha.c.texture = HaveAlpha(texture);
            m_ctx->setTextureAt(stage,reinterpret_cast<const TextureStage3d*>(texture)->texture());
        } else {
            m_crnt_state.texture_stages[stage].rgb.c.texture = false;
            m_crnt_state.texture_stages[stage].alpha.c.texture = false;
            m_ctx->setTextureAt(stage,flash::display3D::textures::Texture(internal::_null));
        }
        
    }
    
    
    /// set texture stage color operation
    void GHL_CALL RenderStage3d::SetupTextureStageColorOp(TextureOperation op,TextureArgument arg1,TextureArgument arg2,UInt32 stage ) {
        m_crnt_state.texture_stages[stage].rgb.c.operation = op;
        m_crnt_state.texture_stages[stage].rgb.c.arg_1 = arg1;
        m_crnt_state.texture_stages[stage].rgb.c.arg_2 = arg2;
    }
    
    /// set texture stage alpha operation
    void GHL_CALL RenderStage3d::SetupTextureStageAlphaOp(TextureOperation op,TextureArgument arg1,TextureArgument arg2,UInt32 stage) {
        m_crnt_state.texture_stages[stage].alpha.c.operation = op;
        m_crnt_state.texture_stages[stage].alpha.c.arg_1 = arg1;
        m_crnt_state.texture_stages[stage].alpha.c.arg_2 = arg2;
    }
    
    static String convert( BlendFactor bf ) {
        switch (bf) {
            case BLEND_FACTOR_SRC_COLOR:
                return flash::display3D::Context3DBlendFactor::SOURCE_COLOR;
            case BLEND_FACTOR_SRC_COLOR_INV:
                return flash::display3D::Context3DBlendFactor::ONE_MINUS_SOURCE_COLOR;
            case BLEND_FACTOR_SRC_ALPHA:
                return flash::display3D::Context3DBlendFactor::SOURCE_ALPHA;
            case BLEND_FACTOR_SRC_ALPHA_INV:
                return flash::display3D::Context3DBlendFactor::ONE_MINUS_SOURCE_ALPHA;
            case BLEND_FACTOR_DST_COLOR:
                return flash::display3D::Context3DBlendFactor::DESTINATION_COLOR;
            case BLEND_FACTOR_DST_COLOR_INV:
                return flash::display3D::Context3DBlendFactor::ONE_MINUS_DESTINATION_COLOR;
            case BLEND_FACTOR_DST_ALPHA:
                return flash::display3D::Context3DBlendFactor::DESTINATION_ALPHA;
            case BLEND_FACTOR_DST_ALPHA_INV:
                return flash::display3D::Context3DBlendFactor::ONE_MINUS_DESTINATION_ALPHA;
            case BLEND_FACTOR_ONE:
                return flash::display3D::Context3DBlendFactor::ONE;
            default:
                break;
        }
        return flash::display3D::Context3DBlendFactor::ZERO;
    }
    /// set blend factors
    void GHL_CALL RenderStage3d::SetupBlend(bool enable,BlendFactor src_factor,BlendFactor dst_factor) {
        m_ctx->setBlendFactors(convert(src_factor),convert(dst_factor));
    }
    /// set alpha test parameters
    void GHL_CALL RenderStage3d::SetupAlphaTest(bool enable,CompareFunc func,float ref) {
        //NOT_IMPLEMENTED;
    }
    static String convert( CompareFunc f ) {
        switch (f) {
            case COMPARE_FUNC_ALWAYS:
                return flash::display3D::Context3DCompareMode::ALWAYS;
            case COMPARE_FUNC_GREATER:
                return flash::display3D::Context3DCompareMode::GREATER;
            case COMPARE_FUNC_LESS:
                return flash::display3D::Context3DCompareMode::LESS;
            case COMPARE_FUNC_EQUAL:
                return flash::display3D::Context3DCompareMode::EQUAL;
            case COMPARE_FUNC_NEQUAL:
                return flash::display3D::Context3DCompareMode::NOT_EQUAL;
            case COMPARE_FUNC_GEQUAL:
                return flash::display3D::Context3DCompareMode::GREATER_EQUAL;
            case COMPARE_FUNC_LEQUAL:
                return flash::display3D::Context3DCompareMode::LESS_EQUAL;
                
            default:
                break;
        }
        return flash::display3D::Context3DCompareMode::NEVER;
    }
    /// set depth test
    void GHL_CALL RenderStage3d::SetupDepthTest(bool enable,CompareFunc func,bool write_enable) {
        if (!enable) {
            m_ctx->setDepthTest(write_enable,flash::display3D::Context3DCompareMode::ALWAYS);
        } else {
            m_ctx->setDepthTest(write_enable,convert(func));
        }
    }
    /// setup faces culling
    void GHL_CALL RenderStage3d::SetupFaceCull(bool enable,bool cw) {
        if (!enable) {
            m_ctx->setCulling(flash::display3D::Context3DTriangleFace::NONE);
        } else {
            if (cw) {
                m_ctx->setCulling(flash::display3D::Context3DTriangleFace::FRONT);
            } else {
                m_ctx->setCulling(flash::display3D::Context3DTriangleFace::BACK);
            }
        }
    }
    
    /// create index buffer
    IndexBuffer* GHL_CALL RenderStage3d::CreateIndexBuffer(UInt32 size) {
        ;
        AS3::ui::flash::display3D::IndexBuffer3D buf = m_ctx->createIndexBuffer(size);

        return new IndexBufferStage3d(this,size,buf);
    }
    /// set current index buffer
    void GHL_CALL RenderStage3d::SetIndexBuffer(const IndexBuffer* buf) {
        RenderImpl::SetIndexBuffer(buf);
    }
    
    /// create vertex buffer
    VertexBuffer* GHL_CALL RenderStage3d::CreateVertexBuffer(VertexType type,UInt32 size) {
        AS3::ui::flash::display3D::VertexBuffer3D buf = m_ctx->createVertexBuffer(size,type==VERTEX_TYPE_SIMPLE ? 3+1+2 : 3+1+2+2);
        return new VertexBufferStage3d(this,type,size,buf);
    }
    /// set current vertex buffer
    void GHL_CALL RenderStage3d::SetVertexBuffer(const VertexBuffer* buf) {
        RenderImpl::SetVertexBuffer(buf);
        if (buf) {
            AS3::ui::flash::display3D::VertexBuffer3D vbuf = reinterpret_cast<const VertexBufferStage3d*>(buf)->buffer();
            m_ctx->setVertexBufferAt(0,vbuf,0,AS3::ui::flash::display3D::Context3DVertexBufferFormat::FLOAT_3);
            m_ctx->setVertexBufferAt(1,vbuf,3,AS3::ui::flash::display3D::Context3DVertexBufferFormat::BYTES_4);
            m_ctx->setVertexBufferAt(2,vbuf,4,AS3::ui::flash::display3D::Context3DVertexBufferFormat::FLOAT_2);
            
            if (buf->GetType()!=VERTEX_TYPE_SIMPLE) {
                m_ctx->setVertexBufferAt(3,vbuf,6,AS3::ui::flash::display3D::Context3DVertexBufferFormat::FLOAT_2);
            }
        }
    }
    
    void GHL_CALL RenderStage3d::SetProjectionMatrix(const float *m) {
        for (size_t x=0;x<4;++x) {
            for (size_t y=0;y<4;++y) {
                m_p_matrix[x+y*4] = m[y+x*4];
            }
        }
    }
    
    void GHL_CALL RenderStage3d::SetViewMatrix(const float* m) {
        for (size_t x=0;x<4;++x) {
            for (size_t y=0;y<4;++y) {
                m_v_matrix[x+y*4] = m[y+x*4];
            }
        }
    }
    
    void GHL_CALL RenderStage3d::SetupScisor( bool enable, UInt32 x, UInt32 y, UInt32 w, UInt32 h ) {
        if (!enable) {
            m_ctx->setScissorRectangle(AS3::ui::flash::geom::Rectangle(internal::_null));
        } else {
            m_ctx->setScissorRectangle(flash::geom::Rectangle::_new(x,y,w,h));
        }
    }
    
    void GHL_CALL RenderStage3d::DrawPrimitives(PrimitiveType type,UInt32 v_amount,UInt32 i_begin,UInt32 amount) {
        
        if (type==PRIMITIVE_TYPE_TRIANGLES) {
            const IndexBufferStage3d* ibuf = reinterpret_cast<const IndexBufferStage3d*>(GetIndexBuffer());
            if (!ibuf) {
                return;
            }
            m_ctx->drawTriangles(ibuf->buffer(),i_begin,amount);
        } else {
            NOT_IMPLEMENTED;
        }
    }
    
    /// draw primitives from memory
    void GHL_CALL RenderStage3d::DrawPrimitivesFromMemory(PrimitiveType type,VertexType v_type,const void* vertices,UInt32 v_amount,const UInt16* indexes,UInt32 prim_amount) {
        ShaderProgram* prg = m_shaders_render.get_shader(m_crnt_state, v_type==VERTEX_TYPE_2_TEX);
        if (prg) {
        
            const ShaderProgramStage3d* prg3d = reinterpret_cast<const ShaderProgramStage3d*>(prg);
            m_ctx->setProgram(prg3d->program());
            
        }
        
         m_ctx->setProgramConstantsFromByteArray(AS3::ui::flash::display3D::Context3DProgramType::VERTEX,
                                                0,4,AS3::ui::internal::get_ram(),(int)m_p_matrix);
        RenderImpl::SetShader(prg);
        const VertexBuffer* crntV = GetVertexBuffer();
        
        if (type==PRIMITIVE_TYPE_TRIANGLES) {
            const size_t vsize = v_type == VERTEX_TYPE_SIMPLE ? sizeof(Vertex) : sizeof(Vertex2Tex);
            IndexBufferStage3d* ib = reinterpret_cast<IndexBufferStage3d*>(CreateIndexBuffer(prim_amount*3));
            ConstInlinedData ibd((const Byte*)indexes,(prim_amount*3)*2);
            ib->SetData(0,&ibd);
            VertexBufferStage3d* vb = reinterpret_cast<VertexBufferStage3d*>(CreateVertexBuffer(v_type,v_amount));
            ConstInlinedData vbd((const Byte*)vertices,v_amount*vsize);
            vb->SetData(0,&vbd);
            SetVertexBuffer(vb);
            m_ctx->drawTriangles(ib->buffer(),0,prim_amount);
            SetVertexBuffer(crntV);
            ib->Release();
            vb->Release();
        } else {
            NOT_IMPLEMENTED;
        }
    }
    
    RenderTarget* GHL_CALL RenderStage3d::CreateRenderTarget(UInt32 w,UInt32 h,TextureFormat fmt,bool depth) {
        NOT_IMPLEMENTED;
        return 0;
    }
    
    VertexShader* GHL_CALL RenderStage3d::CreateVertexShader(const Data* ds) {
        return new VertexShaderStage3d(this,ds);
    }
    
    FragmentShader* GHL_CALL RenderStage3d::CreateFragmentShader(const Data* ds) {
        return new FragmentShaderStage3d(this,ds);
    }
    ShaderProgram* GHL_CALL RenderStage3d::CreateShaderProgram(VertexShader* v,FragmentShader* f) {
        AS3::ui::flash::utils::ByteArray vdata = reinterpret_cast<VertexShaderStage3d*>(v)->data();
        AS3::ui::flash::utils::ByteArray fdata = reinterpret_cast<FragmentShaderStage3d*>(f)->data();
        AS3::ui::flash::display3D::Program3D program = m_ctx->createProgram();
        program->upload(vdata, fdata);
        
        return new ShaderProgramStage3d(this,program);
    }
    void GHL_CALL RenderStage3d::SetShader(const ShaderProgram* shader) {
        RenderImpl::SetShader(shader);
        m_ctx->setProgram(reinterpret_cast<const ShaderProgramStage3d*>(shader)->program());
        m_shaders_render.set_shader(shader);
    }
    
    
}