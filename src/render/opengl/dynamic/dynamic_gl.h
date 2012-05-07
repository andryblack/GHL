#ifndef DYNAMIC_GL_H
#define DYNAMIC_GL_H

#if defined(_WIN32) && !defined(APIENTRY) && !defined(__CYGWIN__) && !defined(__SCITECH_SNAP__)
#define WIN32_LEAN_AND_MEAN 1
#include <windows.h>
#endif

#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif
#ifndef GLAPI
#define GLAPI extern
#endif

#define DYNAMIC_GL_API GLAPI
#define DYNAMIC_GL_APIENTRY APIENTRY
#define DYNAMIC_GL_APIENTRYP APIENTRYP

#include "dynamic_gl_subset.h"

#include <stddef.h>
#include <inttypes.h>

namespace GHL {
#include "dynamic_gl_h.inc"
    void DynamicGLInit();
    void DynamicGLLoadSubset();
    void DynamicGLFinish();
}

#endif // DYNAMIC_GL_H
