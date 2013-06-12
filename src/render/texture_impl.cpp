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
    }
    
    TextureImpl::~TextureImpl() {
        m_parent->TextureReleased(this);
    }
    
    void TextureImpl::RestoreTexture(UInt32 stage) {
        m_parent->SetTexture(m_parent->GetTexture(stage), stage);
    }
}

GHL_API GHL::TextureFormat GHL_CALL GHL_ImageFormatToTextureFormat( GHL::ImageFormat fmt ) {
    switch (fmt) {
        case GHL::IMAGE_FORMAT_GRAY:    return GHL::TEXTURE_FORMAT_ALPHA;
        case GHL::IMAGE_FORMAT_RGB:     return GHL::TEXTURE_FORMAT_RGB;
        case GHL::IMAGE_FORMAT_RGBA:    return GHL::TEXTURE_FORMAT_RGBA;
        case GHL::IMAGE_FORMAT_565:     return GHL::TEXTURE_FORMAT_565;
        case GHL::IMAGE_FORMAT_4444:    return GHL::TEXTURE_FORMAT_4444;
        case GHL::IMAGE_FORMAT_PVRTC_2: return GHL::TEXTURE_FORMAT_PVRTC_2BPPV1;
        case GHL::IMAGE_FORMAT_PVRTC_4: return GHL::TEXTURE_FORMAT_PVRTC_4BPPV1;
        default: break;
    }
    return GHL::TEXTURE_FORMAT_UNKNOWN;
}

GHL_API GHL::ImageFormat GHL_CALL GHL_TextureFormatToImageFormat( GHL::TextureFormat fmt ) {
    switch (fmt) {
        case GHL::TEXTURE_FORMAT_ALPHA:     return GHL::IMAGE_FORMAT_GRAY;
        case GHL::TEXTURE_FORMAT_RGB:       return GHL::IMAGE_FORMAT_RGB;
        case GHL::TEXTURE_FORMAT_RGBA:      return GHL::IMAGE_FORMAT_RGBA;
        case GHL::TEXTURE_FORMAT_565:       return GHL::IMAGE_FORMAT_565;
        case GHL::TEXTURE_FORMAT_4444:      return GHL::IMAGE_FORMAT_4444;
        case GHL::TEXTURE_FORMAT_PVRTC_2BPPV1: return GHL::IMAGE_FORMAT_PVRTC_2;
        case GHL::TEXTURE_FORMAT_PVRTC_4BPPV1: return GHL::IMAGE_FORMAT_PVRTC_4;
        default: break;
    }
    return GHL::IMAGE_FORMAT_UNKNOWN;
}