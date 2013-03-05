//
//  render_opengl2.cpp
//  GHL
//
//  Created by Andrey Kunitsyn on 11/18/12.
//  Copyright (c) 2012 AndryBlack. All rights reserved.
//

#include "render_opengl.h"
#include "../../ghl_log_impl.h"
#include "ghl_shader.h"
#include "dynamic/dynamic_gl.h"


#ifdef _MSC_VER
#define snprintf _snprintf
#endif

namespace GHL {

    static const char* MODULE = "RENDER:OpenGL";
    
    
    
    RenderOpenGL::RenderOpenGL(UInt32 w,UInt32 h) : RenderOpenGLFFPL(w,h){
        
    }
    
    bool RenderOpenGL::RenderInit() {
        LOG_INFO("RenderOpenGL::RenderInit");
        if (!GLApi::InitGL(&gl)) {
            return false;
        }
        if (!RenderOpenGLBase::RenderInit())
            return false;
        return GLApi::InitGLffpl(&glffpl);
    }
    
    RenderOpenGL2::RenderOpenGL2(UInt32 w,UInt32 h) : RenderOpenGLPPL(w,h) {
        
    }
        
    bool RenderOpenGL2::RenderInit() {
        if (!GLApi::InitGL(&gl)) {
            return false;
        }
        return RenderOpenGLPPL::RenderInit();
    }
    
}

GHL_API GHL::RenderImpl* GHL_CALL GHL_CreateRenderOpenGL(GHL::UInt32 w,GHL::UInt32 h) {
    GHL::RenderOpenGLBase* render = new GHL::RenderOpenGL2(w,h);
	if (!render->RenderInit()) {
        render->RenderDone();
		delete render;
		render = 0;
	} else {
        return render;
    }
	render = new GHL::RenderOpenGL(w,h);
	if (!render->RenderInit()) {
		render->RenderDone();
		delete render;
		render = 0;
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
