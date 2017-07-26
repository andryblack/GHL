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

    
    RenderOpenGL2::RenderOpenGL2(UInt32 w,UInt32 h,bool depth) : RenderOpenGLBase(w,h,depth) {
        
    }
        
    bool RenderOpenGL2::RenderInit() {
        if (!GLApi::InitGL(&gl)) {
            return false;
        }
        return RenderOpenGLBase::RenderInit();
    }
    
    bool GHL_CALL RenderOpenGL2::IsFeatureSupported(RenderFeature feature) {
        if (feature == RENDER_FEATURE_NPOT_TEXTURES ||
            feature == RENDER_FEATURE_NPOT_TARGET) {
            return gl.npot_textures;
        }
        return RenderOpenGLBase::IsFeatureSupported(feature);
    }
}

GHL_API GHL::RenderImpl* GHL_CALL GHL_CreateRenderOpenGL(GHL::UInt32 w,GHL::UInt32 h,bool depth) {
    GHL::RenderOpenGLBase* render = 0;
    render = new GHL::RenderOpenGL2(w,h,depth);
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
