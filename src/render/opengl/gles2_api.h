//
//  gles1_api.h
//  GHL
//
//  Created by Andrey Kunitsyn on 3/6/13.
//  Copyright (c) 2013 AndryBlack. All rights reserved.
//

#ifndef __GHL__gles2_api__
#define __GHL__gles2_api__

#include <ghl_api.h>
#include <cstddef>

namespace GHL {
    struct GL;
    
    struct GLES2Api {
        static bool InitGL(GL* api);
    };
}


#endif /* defined(__GHL__gles2_api__) */
