#include "dynamic_gl.h"
#include <ghl_api.h>
#include <cstdio>

#if defined ( GHL_PLATFORM_WIN )
#include <windows.h>
typedef PROC  (__stdcall *wglGetProcAddressProc)(LPCSTR);
static wglGetProcAddressProc DYNAMIC_GL_GetProcAddress = 0;
static HMODULE gl_library = 0;
#define DYNAMIC_GL_PLATFORM_WIN
#define DYNAMIC_GL_PROTO PROC
#elif defined ( GHL_PLATFORM_LINUX )
//#include <GL/glx.h>
typedef void* DYNAMIC_GL_PROTO;
extern "C"  void* glXGetProcAddressARB(const char*);
void * DYNAMIC_GL_GetProcAddress( const char* name ) {
	return glXGetProcAddressARB( name );
}
#elif  defined ( GHL_PLATFORM_MAC )
/// mac platform
#include <dlfcn.h>
static void* gl_library = 0;
static void* DYNAMIC_GL_GetProcAddress (const char *name)
{
    return dlsym(gl_library,name);
}
typedef void* DYNAMIC_GL_PROTO;
#define DYNAMIC_GL_USE_DLFCN
#else
#error "usupported platform"
#endif

#include "../../../ghl_log_impl.h"

namespace GHL {

    void DynamicGLInit() {
#ifdef DYNAMIC_GL_PLATFORM_WIN
        gl_library = LoadLibraryA("OpenGL32");
        DYNAMIC_GL_GetProcAddress = reinterpret_cast<wglGetProcAddressProc>(GetProcAddress(gl_library,"wglGetProcAddress"));
#endif
#ifdef DYNAMIC_GL_USE_DLFCN
        gl_library = dlopen(0,RTLD_NOW|RTLD_GLOBAL);
#endif
    }
    void DynamicGLFinish() {
#ifdef DYNAMIC_GL_PLATFORM_WIN
        FreeLibrary(gl_library);
#endif
#ifdef DYNAMIC_GL_USE_DLFCN
        dlclose(gl_library);
#endif
    }

  
    template <typename FUNCPROTO>
    inline FUNCPROTO DynamicGL_LoadFunction(const char* name){
#ifdef DYNAMIC_GL_PLATFORM_WIN
        DYNAMIC_GL_PROTO func = GetProcAddress(gl_library,name);
        if (func==0) {
            if (DYNAMIC_GL_GetProcAddress==0) return reinterpret_cast<FUNCPROTO>(0);
            func = DYNAMIC_GL_GetProcAddress(name);
        }
#else
        DYNAMIC_GL_PROTO func = DYNAMIC_GL_GetProcAddress(name);
#endif
        static const char* MODULE = "DYNAMIC_GL";
        if (!func) {
			LOG_WARNING( "not found entry point for " << name );
#ifdef DYNAMIC_GL_USE_DLFCN
            LOG_WARNING( const_cast<const char*>(dlerror()) );
#endif
        }
        return (FUNCPROTO) ( func );
    }
    void InternalDynamicGLLoadSubset();
#include "dynamic_gl_cpp.inc"

    void DynamicGLLoadSubset() {
        InternalDynamicGLLoadSubset();
    }
}
