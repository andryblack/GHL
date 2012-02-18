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

#ifndef RENDER_IMPL_H
#define RENDER_IMPL_H

#include "ghl_render.h"

#include <cstring>
#include <vector>

namespace GHL {

	class RenderTargetImpl;

	class RenderImpl : public Render
	{
	protected:
		UInt32 	m_width;
		UInt32	m_height;
		RenderTargetImpl* m_scene_target;
		bool	m_scene_started;
#ifdef GHL_DEBUG
		void TextureCreated(const Texture*);
		bool CheckTexture(const Texture*);
		void TextureReleased(const Texture*);
		void RenderTargetCreated(const RenderTarget*);
		bool CheckRenderTarget(const RenderTarget*);
		void RenderTargetReleased(const RenderTarget*);
#endif
		const Texture*	m_current_texture;
	public:
		RenderImpl(UInt32 w,UInt32 h);
		virtual ~RenderImpl();
	
		void Resize(UInt32 w,UInt32 h);
        
		virtual void GHL_CALL Release();
	
		/// Begin graphics scene (frame)
		virtual void GHL_CALL BeginScene(RenderTarget* target);
		/// End graphics scene (frame)
		virtual void GHL_CALL EndScene() ;
	
	
		void ResetRenderState();
		virtual bool RenderInit() = 0;
		virtual void RenderDone() = 0;
		virtual bool RenderSetFullScreen(bool fs) = 0;
	
		virtual UInt32 GHL_CALL GetWidth() const;
		virtual UInt32 GHL_CALL GetHeight() const;
	
		virtual void GHL_CALL DebugDrawText( Int32 x,Int32 y,const char* text );
	
		virtual UInt32 GHL_CALL GetTexturesMemory() const ;
	private:
		Texture* m_sfont_texture;
#ifdef GHL_DEBUG
		std::vector<const Texture*>       m_textures;
		std::vector<const RenderTarget*>  m_targets;
#endif
	}; 

}


GHL_API GHL::RenderImpl* GHL_CALL GHL_CreateRenderOpenGL(GHL::UInt32 w,GHL::UInt32 h);
GHL_API void GHL_DestroyRenderOpenGL(GHL::RenderImpl* render);


#endif /*RENDER_IMPL_H*/