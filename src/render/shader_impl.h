/*
 GHL - Game Helpers Library
 Copyright (C)  Andrey Kunitsyn 2012
 
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

#ifndef SHADER_IMPL_H_INCLUDED
#define SHADER_IMPL_H_INCLUDED

#include "ghl_shader.h"
#include "../ghl_ref_counter_impl.h"

namespace GHL {
    
    class RenderImpl;
    
    class VertexShaderImpl : public RefCounterImpl<VertexShader> {
    public:
        virtual ~VertexShaderImpl();
    protected:
        explicit VertexShaderImpl( RenderImpl* parent );
    private:
        RenderImpl* m_parent;
    };
    
    class FragmentShaderImpl : public RefCounterImpl<FragmentShader> {
    public:
        virtual ~FragmentShaderImpl();
    protected:
        explicit FragmentShaderImpl( RenderImpl* parent );
    private:
        RenderImpl* m_parent;
    };
    
    class ShaderProgramImpl : public RefCounterImpl<ShaderProgram> {
    public:
        virtual ~ShaderProgramImpl();
    protected:
        explicit ShaderProgramImpl( RenderImpl* parent );
    private:
        RenderImpl* m_parent;
    };
    
}

#endif /* SHADER_IMPL_H_INCLUDED */
