//
//  texture_impl.cpp
//  GHL
//
//  Created by Andrey Kunitsyn on 11/13/12.
//  Copyright (c) 2012 AndryBlack. All rights reserved.
//

#include "texture_impl.h"
#include "render_impl.h"

namespace GHL {
    
    TextureImpl::TextureImpl(RenderImpl* parent,UInt32 w,UInt32 h) : m_parent(parent),m_width(w),m_height(h),
        m_min_filter(TEX_FILTER_NEAR),
        m_mag_filter(TEX_FILTER_NEAR),
        m_mip_filter(TEX_FILTER_NONE),
        m_wrap_u(TEX_WRAP_CLAMP),
        m_wrap_v(TEX_WRAP_CLAMP)
	{
        parent->TextureCreated(this);
#ifdef GHL_DEBUG
        m_is_valid = false;
        m_data_setted = false;
#endif
    }
    
    TextureImpl::~TextureImpl() {
        m_parent->TextureReleased(this);
    }
    
    void TextureImpl::RestoreTexture(UInt32 stage) {
        m_parent->SetTexture(m_parent->GetTexture(stage), stage);
    }
    
    UInt32 GHL_CALL TextureImpl::GetMemoryUsage() const {
        UInt32 res = m_width * m_height;
        switch (GetFormat()) {
            case GHL::TEXTURE_FORMAT_ALPHA:     res *= 1; break;
            case GHL::TEXTURE_FORMAT_RGB:       res *= 3; break;
            case GHL::TEXTURE_FORMAT_RGBA:      res *= 4; break;
            case GHL::TEXTURE_FORMAT_RGBX:      res *= 4; break;
            case GHL::TEXTURE_FORMAT_565:       res *= 2; break;
            case GHL::TEXTURE_FORMAT_4444:      res *= 2; break;
            case GHL::TEXTURE_FORMAT_PVRTC_2BPPV1: res = (res * 2 + 7)/8; break;
            case GHL::TEXTURE_FORMAT_PVRTC_4BPPV1: res = (res * 4 + 7)/8; break;
            case GHL::TEXTURE_FORMAT_ETC1:      res = (res * 8 + 15)/16; break;
            default: break;
        }
        if (HeveMipmaps())
            res *= 2;
        return res;
    }
}

GHL_API GHL::TextureFormat GHL_CALL GHL_ImageFormatToTextureFormat( GHL::ImageFormat fmt ) {
    switch (fmt) {
        case GHL::IMAGE_FORMAT_GRAY:    return GHL::TEXTURE_FORMAT_ALPHA;
        case GHL::IMAGE_FORMAT_RGB:     return GHL::TEXTURE_FORMAT_RGB;
        case GHL::IMAGE_FORMAT_RGBA:    return GHL::TEXTURE_FORMAT_RGBA;
        case GHL::IMAGE_FORMAT_RGBX:    return GHL::TEXTURE_FORMAT_RGBX;
        case GHL::IMAGE_FORMAT_565:     return GHL::TEXTURE_FORMAT_565;
        case GHL::IMAGE_FORMAT_4444:    return GHL::TEXTURE_FORMAT_4444;
        case GHL::IMAGE_FORMAT_PVRTC_2: return GHL::TEXTURE_FORMAT_PVRTC_2BPPV1;
        case GHL::IMAGE_FORMAT_PVRTC_4: return GHL::TEXTURE_FORMAT_PVRTC_4BPPV1;
        case GHL::IMAGE_FORMAT_ETC_1:   return GHL::TEXTURE_FORMAT_ETC1;
        default: break;
    }
    return GHL::TEXTURE_FORMAT_UNKNOWN;
}

GHL_API GHL::ImageFormat GHL_CALL GHL_TextureFormatToImageFormat( GHL::TextureFormat fmt ) {
    switch (fmt) {
        case GHL::TEXTURE_FORMAT_ALPHA:     return GHL::IMAGE_FORMAT_GRAY;
        case GHL::TEXTURE_FORMAT_RGB:       return GHL::IMAGE_FORMAT_RGB;
        case GHL::TEXTURE_FORMAT_RGBA:      return GHL::IMAGE_FORMAT_RGBA;
        case GHL::TEXTURE_FORMAT_RGBX:      return GHL::IMAGE_FORMAT_RGBX;
        case GHL::TEXTURE_FORMAT_565:       return GHL::IMAGE_FORMAT_565;
        case GHL::TEXTURE_FORMAT_4444:      return GHL::IMAGE_FORMAT_4444;
        case GHL::TEXTURE_FORMAT_PVRTC_2BPPV1: return GHL::IMAGE_FORMAT_PVRTC_2;
        case GHL::TEXTURE_FORMAT_PVRTC_4BPPV1: return GHL::IMAGE_FORMAT_PVRTC_4;
        case GHL::TEXTURE_FORMAT_ETC1:      return GHL::IMAGE_FORMAT_ETC_1;
        default: break;
    }
    return GHL::IMAGE_FORMAT_UNKNOWN;
}

GHL_API bool GHL_CALL GHL_IsCompressedFormat( GHL::TextureFormat fmt ) {
    switch (fmt) {
        case GHL::TEXTURE_FORMAT_PVRTC_2BPPV1:
        case GHL::TEXTURE_FORMAT_PVRTC_4BPPV1:
        case GHL::TEXTURE_FORMAT_ETC1:
            return true;
        default: break;
    }
    return false;
}
