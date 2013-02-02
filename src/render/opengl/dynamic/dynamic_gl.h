#ifndef DYNAMIC_GL_H
#define DYNAMIC_GL_H

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
