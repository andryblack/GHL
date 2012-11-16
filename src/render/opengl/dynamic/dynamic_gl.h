#ifndef DYNAMIC_GL_H
#define DYNAMIC_GL_H

#include "dynamic_gl_subset.h"
#include <cstddef>

namespace GHL {
    struct GL;
    struct GLffpl;
    
    struct GLApi {
        static bool InitGL(GL* api);
        static bool InitGLffpl(GLffpl* api);
    };
}

#endif // DYNAMIC_GL_H
