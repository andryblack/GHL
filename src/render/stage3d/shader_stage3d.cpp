#include "shader_stage3d.h"
#include "../../ghl_data_impl.h"

namespace GHL {
    
    ShaderUniformStage3d::ShaderUniformStage3d(const AGAL::RegisterName& reg,AGALData::constants_map& constants) : m_register(reg),m_constants(constants) {
        
    }
    void GHL_CALL ShaderUniformStage3d::SetValueFloat(float v) {
        m_constants[m_register].data[0] = v;
    }
    void GHL_CALL ShaderUniformStage3d::SetValueFloat2(float x, float y) {
        m_constants[m_register].data[0] = x;
        m_constants[m_register].data[1] = y;
    }
    void GHL_CALL ShaderUniformStage3d::SetValueFloat3(float x, float y, float z) {
        m_constants[m_register].data[0] = x;
        m_constants[m_register].data[1] = y;
        m_constants[m_register].data[2] = z;
    }
    void GHL_CALL ShaderUniformStage3d::SetValueFloat4(float x, float y, float z, float w) {
        m_constants[m_register].data[0] = x;
        m_constants[m_register].data[1] = y;
        m_constants[m_register].data[2] = z;
        m_constants[m_register].data[3] = w;
    }
    void GHL_CALL ShaderUniformStage3d::SetValueMatrix(const float* v) {
        
    }
    
    AS3::ui::flash::utils::ByteArray ShaderProgramStage3d::byteArrayFromData( const Data* data ) {
        AS3::ui::flash::utils::ByteArray ba = AS3::ui::flash::utils::ByteArray::_new();
        ba->endian = AS3::ui::flash::utils::Endian::__LITTLE_ENDIAN;
        ba->writeBytes(
                           AS3::ui::internal::get_ram(), (int)data->GetData(), data->GetSize(), (void*)data->GetData());
        return ba;
    }
    
    VertexShaderStage3d::VertexShaderStage3d(RenderImpl* render,const Data* data)
    : VertexShaderImpl(render) , m_data(data) {
        if (m_data) {
            m_data->AddRef();
        }
    }
    VertexShaderStage3d::~VertexShaderStage3d() {
        if (!m_data) {
            m_data->Release();
        }
    }
    
    FragmentShaderStage3d::FragmentShaderStage3d(RenderImpl* render,const Data* data)
    : FragmentShaderImpl(render) , m_data(data) {
        if (m_data) {
            m_data->AddRef();
        }
    }
    
    FragmentShaderStage3d::~FragmentShaderStage3d() {
        if (m_data) {
            m_data->Release();
        }
    }
    
    ShaderProgramStage3d::ShaderProgramStage3d(RenderImpl* render,const AS3::ui::flash::display3D::Program3D& p) : ShaderProgramImpl(render),m_program(p) {
        
    
    }
    
    ShaderProgramStage3d::~ShaderProgramStage3d() {
        
    }
    
    ShaderUniform* GHL_CALL ShaderProgramStage3d::GetUniform(const char* name) const {
        return 0;
    }
    
    void ShaderProgramStage3d::ApplyConstants( AS3::ui::flash::display3D::Context3D& ctx, const float* VPMatrix) const {
        ctx->setProgramConstantsFromByteArray(AS3::ui::flash::display3D::Context3DProgramType::VERTEX,
                                                0,4,AS3::ui::internal::get_ram(),(int)VPMatrix);
    }
    
    ShaderProgramUserStage3d::ShaderProgramUserStage3d(RenderImpl* render, const AS3::ui::flash::display3D::Program3D& p) : ShaderProgramStage3d( render, p) {
        
    }
    ShaderProgramUserStage3d::~ShaderProgramUserStage3d() {
        
    }
    
    bool ShaderProgramUserStage3d::load(const Data* vsrc, const Data* fsrc) {
        AGALAssembler assembler(&m_data);
        if (!assembler.parse(vsrc,fsrc)) {
            return false;
        }
        for (AGALData::name_to_register_map::iterator i = m_data.uniforms.begin();
             i!=m_data.uniforms.end();++i) {
            m_uniforms.insert(std::make_pair(i->first,ShaderUniformStage3d(i->second,m_data.constants)));
        }
        return update();
    }
    
    bool ShaderProgramUserStage3d::update() {
        if (!m_data.codev || !m_data.codef)
            return false;
        AS3::ui::flash::utils::ByteArray vdata = byteArrayFromData(m_data.codev);
        AS3::ui::flash::utils::ByteArray fdata = byteArrayFromData(m_data.codef);
        
        m_program->upload(vdata, fdata);
        return true;
    }
    
    void ShaderProgramUserStage3d::ApplyConstants( AS3::ui::flash::display3D::Context3D& ctx,const float* VPMatrix) const {
        for (AGALData::constants_map::const_iterator it = m_data.constants.begin();
             it!=m_data.constants.end();++it) {
            if (it->first.def == &AGAL::FC) {
                ctx->setProgramConstantsFromByteArray(AS3::ui::flash::display3D::Context3DProgramType::FRAGMENT,
                                                        it->first.idx,1,AS3::ui::internal::get_ram(),(int)it->second.data);
            } else if (it->first.def == &AGAL::VC) {
                ctx->setProgramConstantsFromByteArray(AS3::ui::flash::display3D::Context3DProgramType::VERTEX,
                                                      it->first.idx,1,AS3::ui::internal::get_ram(),(int)it->second.data);
            }
        }
        AGALData::name_to_register_map::const_iterator it = m_data.uniforms.find("mProjectionModelView");
        if (it!=m_data.uniforms.end()) {
            ctx->setProgramConstantsFromByteArray(AS3::ui::flash::display3D::Context3DProgramType::VERTEX,
                                                  it->second.idx,4,AS3::ui::internal::get_ram(),(int)VPMatrix);
        }
    }
    
    
    ShaderUniform* GHL_CALL ShaderProgramUserStage3d::GetUniform(const char* name) const {
        std::map<std::string,ShaderUniformStage3d>::iterator it = m_uniforms.find(name);
        if (it!=m_uniforms.end()) {
            return &(it->second);
        }
        return 0;
    }

}