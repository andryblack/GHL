/*
 *  ghl_render_target.h
 *  SR
 *
 *  Created by Андрей Куницын on 03.02.11.
 *  Copyright 2011 andryblack. All rights reserved.
 *
 */

#ifndef GHL_RENDER_TARGET_H
#define GHL_RENDER_TARGET_H

#include "ghl_api.h"
#include "ghl_types.h"

namespace GHL {

	/// render target interface
	struct RenderTarget 
	{
		/// width
		virtual UInt32 GHL_CALL GetWidth() const = 0;
		/// height
		virtual UInt32 GHL_CALL GetHeight() const = 0;
		/// have depth
		virtual	bool GHL_CALL HaveDepth() const = 0;
		/// get texture
		virtual Texture* GHL_CALL GetTexture() const = 0;
		/// read pixels
		virtual void GHL_CALL GetPixels(UInt32 x,UInt32 y,UInt32 w,UInt32 h,Byte* data) = 0;
		/// release
		virtual void GHL_CALL Release() = 0;
	};
	
}

#endif /*GHL_RENDER_TARGET_H*/

