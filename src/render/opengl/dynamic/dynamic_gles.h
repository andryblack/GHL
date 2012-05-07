#ifndef DYNAMIC_GLES_H
#define DYNAMIC_GLES_H

#if defined(_WIN32) || defined(WIN32)
#error "OpenGLES not supported on win32 platform"
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

#ifdef __APPLE__
typedef signed char khronos_int8_t;
typedef unsigned char khronos_uint8_t;
typedef float khronos_float_t;
typedef int khronos_int32_t;
typedef long            khronos_intptr_t;
typedef long            khronos_ssize_t;
#define DYNAMIC_GL_NO_FUCPOINTERS
#endif

#define DYNAMIC_GL_API GLAPI
#define DYNAMIC_GL_APIENTRY APIENTRY
#define DYNAMIC_GL_APIENTRYP APIENTRYP

#include "dynamic_gles_subset.h"

#include <stddef.h>
namespace GHL {
#include "dynamic_gles_h.inc"
    void DynamicGLInit();
    void DynamicGLLoadSubset();
    void DynamicGLFinish();
}

#endif // DYNAMIC_GLES_H
