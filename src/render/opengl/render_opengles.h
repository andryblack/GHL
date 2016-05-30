//
//  render_opengles.h
//  GHL
//
//  Created by Andrey Kunitsyn on 3/6/13.
//  Copyright (c) 2013 AndryBlack. All rights reserved.
//

#ifndef __GHL__render_opengles__
#define __GHL__render_opengles__

#include "render_opengl_base.h"

namespace GHL {
    class RenderOpenGLES : public RenderOpenGLFFPL {
    private:
        
    public:
        RenderOpenGLES(UInt32 w,UInt32 h,bool haveDepth);
        
        void GHL_CALL BeginScene(RenderTarget* target);
        bool RenderInit();
        
    };
    
    class RenderOpenGLES2 : public RenderOpenGLPPL {
    public:
        RenderOpenGLES2(UInt32 w,UInt32 h,bool haveDepth);
        
        void GHL_CALL BeginScene(RenderTarget* target);
        bool RenderInit();
        
        virtual bool GHL_CALL IsFeatureSupported(RenderFeature feature);
    };
}

#endif /* defined(__GHL__render_opengles__) */
