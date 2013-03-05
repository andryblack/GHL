//
//  gles1_api.h
//  GHL
//
//  Created by Andrey Kunitsyn on 3/6/13.
//  Copyright (c) 2013 AndryBlack. All rights reserved.
//

#ifndef __GHL__gles1_api__
#define __GHL__gles1_api__

#include <cstddef>

namespace GHL {
    struct GL;
    struct GLffpl;
    
    struct GLES1Api {
        static bool InitGL(GL* api);
        static bool InitGLffpl(GLffpl* api);
    };
}


#endif /* defined(__GHL__gles1_api__) */
