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

#ifndef GHL_TEXTURE_H
#define GHL_TEXTURE_H

#include "ghl_types.h"
#include "ghl_api.h"
#include "ghl_ref_counter.h"

namespace GHL 
{

	/// texture format
	enum TextureFormat
	{
		TEXTURE_FORMAT_RGB,		///< r,g,b channels
		TEXTURE_FORMAT_RGBA,	///< r,g,b,alpha channels
		TEXTURE_FORMAT_565,		///< 5-6-5
		TEXTURE_FORMAT_4444		///< 4-4-4-4
	};


	/// texture filtration type
	enum TextureFilter
	{
		TEX_FILTER_NONE,	///< none filtering (mipmaps)
		TEX_FILTER_NEAR,	///< near point 
		TEX_FILTER_LINEAR, 	///< linear interpolation
	};
	
	/// texture wrap mode
	enum TextureWrapMode
	{
		TEX_WRAP_CLAMP,		///< clamp
		TEX_WRAP_REPEAT,	///< repeat
	};
	
	/// texture
	struct Texture : RefCounter
	{
		/// get texture width
		virtual UInt32 GHL_CALL GetWidth() const = 0;
		/// get texture height
		virtual UInt32 GHL_CALL GetHeight() const = 0;
		/// get texture format
		virtual TextureFormat GHL_CALL GetFormat() const = 0;
		/// get texture is have mipmaps
		virtual bool GHL_CALL HeveMipmaps() const = 0;
		/// get minification texture filtration
		virtual TextureFilter GHL_CALL GetMinFilter( ) const = 0;
		/// set minification texture filtration
		virtual void GHL_CALL SetMinFilter(TextureFilter min) = 0;
		/// get magnification texture filtration
		virtual TextureFilter GHL_CALL GetMagFilter( ) const = 0;
		/// set magnification texture filtration
		virtual void GHL_CALL SetMagFilter(TextureFilter mag) = 0;
		/// get mipmap texture filtration
		virtual TextureFilter GHL_CALL GetMipFilter( ) const = 0;
		/// set mipmap texture filtration
		virtual void GHL_CALL SetMipFilter(TextureFilter mip) = 0;
		
		/// set texture wrap U
		virtual void GHL_CALL SetWrapModeU(TextureWrapMode wm) = 0;
		/// get texture wrap mode U
		virtual TextureWrapMode GHL_CALL GetWrapModeU() const = 0;
		/// set texture wrap V
		virtual void GHL_CALL SetWrapModeV(TextureWrapMode wm) = 0;
		/// get texture wrap mode V
		virtual TextureWrapMode GHL_CALL GetWrapModeV() const = 0;

		/// set texture pixels
		virtual void GHL_CALL SetData(UInt32 x,UInt32 y,UInt32 w,UInt32 h,const Byte* data,UInt32 level=0) = 0;
		/// generate mipmaps
		virtual void GHL_CALL GenerateMipmaps() = 0;
	};

}

#endif /*GHL_TEXTURE_H*/
