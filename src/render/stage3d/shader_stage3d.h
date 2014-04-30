#ifndef SHADER_STAGE_3D_H_INCLUDED
#define SHADER_STAGE_3D_H_INCLUDED

#include "../shader_impl.h"
#include "agal_assembler.h"

#include <AS3/AS3.h>
#include <Flash++.h>

namespace GHL {

	class VertexShaderStage3d : public VertexShaderImpl {
    private:
        const Data*   m_data;
    public:
        VertexShaderStage3d( RenderImpl* render, const Data* data);
        ~VertexShaderStage3d();
        const Data* data() { return m_data; }
    };

    class FragmentShaderStage3d : public FragmentShaderImpl {
    private:
        const Data*   m_data;
    public:
        FragmentShaderStage3d( RenderImpl* render, const Data* data);
        ~FragmentShaderStage3d();
        const Data* data() { return m_data; }
    };
    
    
    

	class ShaderProgramStage3d : public ShaderProgramImpl {
	protected:
    	AS3::ui::flash::display3D::Program3D m_program;
    public:
    	ShaderProgramStage3d(RenderImpl* render, const AS3::ui::flash::display3D::Program3D& p );
        ~ShaderProgramStage3d();
        
        const AS3::ui::flash::display3D::Program3D& program() const { return m_program; }
        virtual ShaderUniform* GHL_CALL GetUniform(const char* name) const;
        
        virtual void ApplyConstants( AS3::ui::flash::display3D::Context3D& ctx, const float*  VPMatrix) const;
        
        static AS3::ui::flash::utils::ByteArray byteArrayFromData( const Data* data );
	};
    
    class ShaderUniformStage3d : public ShaderUniform {
    private:
        AGAL::RegisterName m_register;
        AGALData::constants_map& m_constants;
    public:
        explicit ShaderUniformStage3d(const AGAL::RegisterName& reg,AGALData::constants_map& constants);
		virtual void GHL_CALL SetValueFloat(float v);
        virtual void GHL_CALL SetValueFloat2(float x, float y);
        virtual void GHL_CALL SetValueFloat3(float x, float y, float z);
        virtual void GHL_CALL SetValueFloat4(float x, float y, float z, float w);
		virtual void GHL_CALL SetValueMatrix(const float* v);
	};
    
    class ShaderProgramUserStage3d : public ShaderProgramStage3d {
    protected:
        AGALData m_data;
        mutable std::map<std::string,ShaderUniformStage3d> m_uniforms;
    public:
        ShaderProgramUserStage3d(RenderImpl* render, const AS3::ui::flash::display3D::Program3D& p);
        ~ShaderProgramUserStage3d();
        virtual void ApplyConstants( AS3::ui::flash::display3D::Context3D& ctx,const float* VPMatrix) const;
        bool load( const Data* vsrc, const Data* fsrc );
        bool update();
        virtual ShaderUniform* GHL_CALL GetUniform(const char* name) const;
    };
    
  
}

#endif /*SHADER_STAGE_3D_H_INCLUDED*/
