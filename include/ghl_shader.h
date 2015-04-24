/*
 GHL - Game Helpers Library
 Copyright (C)  Andrey Kunitsyn 2011
 
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

#ifndef GHL_SHADER_H
#define GHL_SHADER_H

#include "ghl_types.h"
#include "ghl_api.h"
#include "ghl_ref_counter.h"

namespace GHL 
{
	
	/// Shader
	struct Shader : RefCounter
	{
	};
	
	/// Vertex shader
	struct VertexShader : Shader
	{
	};
	
	/// Fragment shader
	struct FragmentShader : Shader
	{
	};
	
	/// Uniform
	struct ShaderUniform {
		/// Set float value
		virtual void GHL_CALL SetValueFloat(float v) = 0;
		/// Set 2 floats value
        virtual void GHL_CALL SetValueFloat2(float x, float y) = 0;
        /// Set 3 floats value
        virtual void GHL_CALL SetValueFloat3(float x, float y, float z) = 0;
        /// Set 4 floats value
        virtual void GHL_CALL SetValueFloat4(float x, float y, float z, float w) = 0;
        /// Set matrix value (16 floats)
		virtual void GHL_CALL SetValueMatrix(const float* v) = 0;
	};
	
	/// Shader program interface
	struct ShaderProgram : RefCounter
	{
		/// get uniform
		virtual ShaderUniform* GHL_CALL GetUniform(const char* name) const = 0;
	};
	
}

#endif /*GHL_SHADER_H*/
