//
//  render_opengl2.h
//  GHL
//
//  Created by Andrey Kunitsyn on 11/18/12.
//  Copyright (c) 2012 AndryBlack. All rights reserved.
//

#ifndef __GHL__render_opengl2__
#define __GHL__render_opengl2__

#include "render_opengl_base.h"

namespace GHL {
    
    
    
    
    class RenderOpenGL : public RenderOpenGLFFPL {
    private:
        
    public:
        RenderOpenGL(UInt32 w,UInt32 h,bool depth);
        
        bool RenderInit();
        
    };
    
    class RenderOpenGL2 : public RenderOpenGLPPL {
    public:
        RenderOpenGL2(UInt32 w,UInt32 h, bool depth);
        
        bool RenderInit();
        
        virtual bool GHL_CALL IsFeatureSupported(RenderFeature feature);
    };
}

GHL_API GHL::RenderOpenGLBase* GHL_CALL GHL_CreateRenderOpenGL(GHL::UInt32 w,GHL::UInt32 h,bool depth);
GHL_API void GHL_DestroyRenderOpenGL(GHL::RenderOpenGLBase* render);

#endif /* defined(__GHL__render_opengl2__) */
