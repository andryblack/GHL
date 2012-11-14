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

#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif
#ifndef GLAPI
#define GLAPI extern
#endif


namespace GHL {

    void GL::DynamicGLInit() {
#ifdef DYNAMIC_GL_PLATFORM_WIN
        gl_library = LoadLibraryA("OpenGL32");
        DYNAMIC_GL_GetProcAddress = reinterpret_cast<wglGetProcAddressProc>(GetProcAddress(gl_library,"wglGetProcAddress"));
#endif
#ifdef DYNAMIC_GL_USE_DLFCN
        gl_library = dlopen(0,RTLD_NOW|RTLD_GLOBAL);
#endif
    }
    void GL::DynamicGLFinish() {
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
    
    static bool DynamicGL_CheckExtensionSupported(const char* extensionName) {
        if (::strcmp(extensionName, "CORE")==0) {
            return true;
        }
		static const char* all_extensions = (const char*)gl.GetString(GL::EXTENSIONS);
		if (!all_extensions) return false;
		const char* pos = all_extensions;
		while ( pos ) {
			pos = ::strstr(pos, extensionName);
			if (!pos) return false;
			pos += ::strlen(extensionName);
			if (*pos == ' ' || *pos=='\0' || *pos=='\n' || *pos=='\r' || *pos=='\t')
				return true;
		}
		return false;
	}
    
#define DYNAMIC_GL_FEATURE(Name) bool GL::DinamicGLFeature_##Name##_Supported() { \
        static bool supported = DynamicGL_CheckExtensionSupported(#Name); \
        return supported; \
    }
#define DYNAMIC_GL_TYPEDEF(Type,Alias)
#define DYNAMIC_GL_CONSTANT(Name,Val) 
#define DYNAMIC_GL_TYPE(Type) GL::GL##Type
#define MAKE_CHECK_FUNC(Ret,Name,Args) \
    typedef Ret (APIENTRYP Name##_Proto) Args; \
    static Name##_Proto func_ptr = 0; \
    if (!func_ptr) func_ptr = DynamicGL_LoadFunction<Name##_Proto>("gl"#Name);

#define DYNAMIC_GL_FUNCTION(Ret,Name,Args,ArgNames) \
    Ret GL::Name Args { \
        MAKE_CHECK_FUNC(Ret,Name,Args)\
        if (func_ptr) return func_ptr ArgNames;\
        return 0; \
    }
#define DYNAMIC_GL_FUNCTION_V(Name,Args,ArgNames) \
    void GL::Name Args { \
        MAKE_CHECK_FUNC(void,Name,Args)\
        if (func_ptr) func_ptr ArgNames;\
    }
#include "dynamic_gl_inc.h"
#undef DYNAMIC_GL_FUNCTION
#undef DYNAMIC_GL_CONSTANT
#undef DYNAMIC_GL_FEATURE
#undef DYNAMIC_GL_TYPEDEF
#undef DYNAMIC_GL_TYPE
#undef DYNAMIC_GL_FUNCTION_V

    
    
    
    GL gl;
}
