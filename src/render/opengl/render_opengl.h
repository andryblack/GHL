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
        RenderOpenGL(UInt32 w,UInt32 h);
        
        bool RenderInit();
        
    };
    
    class RenderOpenGL2 : public RenderOpenGLPPL {
    public:
        RenderOpenGL2(UInt32 w,UInt32 h);
        
        bool RenderInit();
    };
}

#endif /* defined(__GHL__render_opengl2__) */
