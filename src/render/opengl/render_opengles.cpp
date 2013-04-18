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

namespace GHL {
    
    UInt32 g_default_renderbuffer = 0;
    
    
    
         
    static const char* MODULE = "RENDER:OpenGLES";
    
    RenderOpenGLES::RenderOpenGLES(UInt32 w,UInt32 h) : RenderOpenGLFFPL(w,h) {
        
    }
    
    void GHL_CALL RenderOpenGLES::BeginScene(RenderTarget* target) {
        gl.rtapi.default_renderbuffer = g_default_renderbuffer;
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
    
    RenderOpenGLES2::RenderOpenGLES2(UInt32 w,UInt32 h) : RenderOpenGLPPL(w,h) {
        GetGenerator().set_fshader_header("precision mediump float;\n");
    }
    
    bool RenderOpenGLES2::RenderInit() {
        if (!GLES2Api::InitGL(&gl)) {
            return false;
        }
        return RenderOpenGLPPL::RenderInit();
    }
    
    
    
    

}

