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
#include "ghl_data_stream.h"

namespace GHL 
{
	
	/// Shader
	struct Shader
	{
		/// release shader
		virtual void GHL_CALL Release() = 0;
	};
	
	/// Vertex shader
	struct VertexShader : Shader
	{
	};
	
	/// Vertex shader
	struct FragmentShader : Shader
	{
	};
	
	/// Uniform
	struct ShaderUniform {
		virtual void GHL_CALL SetValueFloat(float v) = 0;
		virtual void GHL_CALL SetValueInt(Int32 v) = 0;
	};
	
	struct ShaderProgram 
	{
		/// release program
		virtual void GHL_CALL Release() = 0;
		/// get uniform
		virtual ShaderUniform* GHL_CALL GetUniform(const char* name) = 0;
	};
	
}

#endif /*GHL_SHADER_H*/