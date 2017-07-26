//
//  render_opengles.cpp
//  GHL
//
//  Created by Andrey Kunitsyn on 3/6/13.
//  Copyright (c) 2013 AndryBlack. All rights reserved.
//

#include "render_opengles.h"
#include "gles2_api.h"
#include "../../ghl_log_impl.h"

namespace GHL {
    
    UInt32 g_default_framebuffer = 0;
    
    

    RenderOpenGLES2::RenderOpenGLES2(UInt32 w,UInt32 h,bool depth) : RenderOpenGLBase(w,h,depth) {
        GetGenerator().set_fshader_header("precision mediump float;\n");
    }
    
    bool RenderOpenGLES2::RenderInit() {
        if (!GLES2Api::InitGL(&gl)) {
            return false;
        }
        return RenderOpenGLBase::RenderInit();
    }
    
    bool GHL_CALL RenderOpenGLES2::IsFeatureSupported(RenderFeature feature) {
        if (feature == RENDER_FEATURE_NPOT_TEXTURES) {
            return true;
        }
        if (feature == RENDER_FEATURE_NPOT_TARGET) {
            return true;
        }
        return RenderOpenGLBase::IsFeatureSupported(feature);
    }
    
    void GHL_CALL RenderOpenGLES2::BeginScene(RenderTarget* target) {
        gl.rtapi.default_framebuffer = g_default_framebuffer;
        RenderOpenGLBase::BeginScene(target);
    }
    
    
    

}

GHL_API GHL::RenderImpl* GHL_CALL GHL_CreateRenderOpenGL(GHL::UInt32 w,GHL::UInt32 h,bool depth) {
    GHL::RenderOpenGLBase* render = 0;
    render = new GHL::RenderOpenGLES2(w,h,depth);
    if (!render->RenderInit()) {
        render->RenderDone();
        delete render;
        render = 0;
    } else {
        return render;
    }
    return render;
}

GHL_API void GHL_DestroyRenderOpenGL(GHL::RenderImpl* render_) {
    GHL::RenderOpenGLBase* render = reinterpret_cast<GHL::RenderOpenGLBase*>(render_);
    if (render) {
        render->RenderDone();
        delete render;
    }
}

