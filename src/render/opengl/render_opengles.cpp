//
//  render_opengles.cpp
//  GHL
//
//  Created by Andrey Kunitsyn on 3/6/13.
//  Copyright (c) 2013 AndryBlack. All rights reserved.
//

#include "render_opengles.h"
#include "gles1_api.h"
#include "gles2_api.h"
#include "../../ghl_log_impl.h"

#ifdef GHL_PLATFORM_EMSCRIPTEN
#include "render_webgl.h"
#endif

namespace GHL {
    
    UInt32 g_default_framebuffer = 0;
    
    
    
         
    static const char* MODULE = "RENDER:OpenGLES";
    
    #ifndef GHL_NO_ES1
    RenderOpenGLES::RenderOpenGLES(UInt32 w,UInt32 h,bool depth) : RenderOpenGLFFPL(w,h,depth) {
        
    }
    
    void GHL_CALL RenderOpenGLES::BeginScene(RenderTarget* target) {
        gl.rtapi.default_framebuffer = g_default_framebuffer;
        RenderOpenGLFFPL::BeginScene(target);
    }
    
    bool RenderOpenGLES::RenderInit() {
        LOG_INFO("RenderInit");
        if (!GLES1Api::InitGL(&gl)) {
            return false;
        }
        if (!RenderOpenGLBase::RenderInit())
            return false;
        return GLES1Api::InitGLffpl(&glffpl);
    }
    #endif
    
    RenderOpenGLES2::RenderOpenGLES2(UInt32 w,UInt32 h,bool depth) : RenderOpenGLPPL(w,h,depth) {
        m_vertex_shader_prefix = "/*GHL*/\n";
        m_fragment_shader_prefix = "/*GHL*/\n"
            "precision mediump float;\n";
    }
    
    bool RenderOpenGLES2::RenderInit() {
        if (!GLES2Api::InitGL(&gl)) {
            return false;
        }
        return RenderOpenGLPPL::RenderInit();
    }
    
    bool GHL_CALL RenderOpenGLES2::IsFeatureSupported(RenderFeature feature) {
        if (feature == RENDER_FEATURE_NPOT_TEXTURES) {
            return true;
        }
        if (feature == RENDER_FEATURE_NPOT_TARGET) {
            return true;
        }
        return RenderOpenGLPPL::IsFeatureSupported(feature);
    }
    
    void GHL_CALL RenderOpenGLES2::BeginScene(RenderTarget* target) {
        gl.rtapi.default_framebuffer = g_default_framebuffer;
        RenderOpenGLPPL::BeginScene(target);
    }
    
    
    

}

GHL_API GHL::RenderImpl* GHL_CALL GHL_CreateRenderOpenGL(GHL::UInt32 w,GHL::UInt32 h,bool depth) {
    GHL::RenderOpenGLBase* render = 0;
#ifdef GHL_PLATFORM_EMSCRIPTEN
    render = new GHL::RenderWebGL(w,h,depth);
#else
    render = new GHL::RenderOpenGLES2(w,h,depth);
#endif
    if (!render->RenderInit()) {
        render->RenderDone();
        delete render;
        render = 0;
    } else {
        return render;
    }
#ifndef GHL_NO_ES1
    render = new GHL::RenderOpenGLES(w,h,depth);
    if (!render->RenderInit()) {
        render->RenderDone();
        delete render;
        render = 0;
    }
#endif
    return render;
}

GHL_API void GHL_DestroyRenderOpenGL(GHL::RenderImpl* render_) {
    GHL::RenderOpenGLBase* render = reinterpret_cast<GHL::RenderOpenGLBase*>(render_);
    if (render) {
        render->RenderDone();
        delete render;
    }
}

