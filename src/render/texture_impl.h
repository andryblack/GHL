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

#ifndef TEXTURE_IMPL_H_INCLUDED
#define TEXTURE_IMPL_H_INCLUDED

#include "ghl_texture.h"
#include "../ghl_ref_counter_impl.h"

namespace GHL {
    
    class RenderImpl;
    
    class TextureImpl : public RefCounterImpl<Texture> {
    public:
        virtual ~TextureImpl();
        
        /// get texture width
		virtual UInt32 GHL_CALL GetWidth() const { return m_width;}
		/// get texture height
		virtual UInt32 GHL_CALL GetHeight() const { return m_height;}
		
        /// get minification texture filtration
		virtual TextureFilter GHL_CALL GetMinFilter( ) const { return m_min_filter;}
		/// set minification texture filtration
		virtual void GHL_CALL SetMinFilter(TextureFilter min) { m_min_filter = min; }
		/// get magnification texture filtration
		virtual TextureFilter GHL_CALL GetMagFilter( ) const { return m_mag_filter;}
		/// set magnification texture filtration
		virtual void GHL_CALL SetMagFilter(TextureFilter mag) { m_mag_filter = mag; }
		/// get mipmap texture filtration
		virtual TextureFilter GHL_CALL GetMipFilter( ) const { return m_mip_filter;}
		/// set mipmap texture filtration
		virtual void GHL_CALL SetMipFilter(TextureFilter mip) { m_min_filter = mip; }
		/// get texture wrap mode U
		virtual TextureWrapMode GHL_CALL GetWrapModeU() const { return m_wrap_u;}
		/// set texture wrap U
		virtual void GHL_CALL SetWrapModeU(TextureWrapMode wm) { m_wrap_u = wm; }
        /// get texture wrap mode V
		virtual TextureWrapMode GHL_CALL GetWrapModeV() const { return m_wrap_v;}
		/// set texture wrap V
		virtual void GHL_CALL SetWrapModeV(TextureWrapMode wm) { m_wrap_v = wm; }
		/// get texture wrap mode V
		
        /// flush internal data to texture
        virtual void GHL_CALL FlushInternal() {
#ifdef GHL_DEBUG
            if (m_data_setted) {
                m_is_valid = true;
            }
#endif
        }
        
        /// discard internal data
        virtual void GHL_CALL DiscardInternal() {
            FlushInternal();
        }
#ifdef GHL_DEBUG
        bool IsValid() const { return m_is_valid; }
#endif
        void NotifySetData() {
#ifdef GHL_DEBUG
            m_data_setted = true;
#endif
        }
        void MarkAsValid() {
#ifdef GHL_DEBUG
            m_is_valid = true;
#endif
        }

    private:
        RenderImpl* m_parent;
#ifdef GHL_DEBUG
        bool    m_data_setted;
        bool    m_is_valid;
#endif
    protected:

        
        explicit TextureImpl( RenderImpl* parent, UInt32 w,UInt32 h );
        void RestoreTexture(UInt32 stage);
        UInt32	m_width;
        UInt32	m_height;
        TextureFilter	m_min_filter;
        TextureFilter	m_mag_filter;
        TextureFilter	m_mip_filter;
        TextureWrapMode m_wrap_u;
        TextureWrapMode m_wrap_v;
    };
    
}

#endif /* TEXTURE_IMPL_H_INCLUDED */
