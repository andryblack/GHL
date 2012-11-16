#include "dynamic_gl.h"
#include <ghl_api.h>
#include "dynamic_gl_api.h"

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

    
    static const char* MODULE = "DYNAMIC_GL";
    
    
  
    template <typename FUNCPROTO>
    static inline FUNCPROTO LoadFunction(const char* name){
#ifdef DYNAMIC_GL_PLATFORM_WIN
        DYNAMIC_GL_PROTO func = GetProcAddress(gl_library,name);
        if (func==0) {
            if (DYNAMIC_GL_GetProcAddress==0) return reinterpret_cast<FUNCPROTO>(0);
            func = DYNAMIC_GL_GetProcAddress(name);
        }
#else
        DYNAMIC_GL_PROTO func = DYNAMIC_GL_GetProcAddress(name);
#endif
        if (!func) {
			LOG_WARNING( "not found entry point for " << name );
#ifdef DYNAMIC_GL_USE_DLFCN
            LOG_WARNING( const_cast<const char*>(dlerror()) );
#endif
        }
        return (FUNCPROTO) ( func );
    }
    
    struct GLApi_impl {
        
        static void DynamicGLInit() {
#ifdef DYNAMIC_GL_PLATFORM_WIN
            gl_library = LoadLibraryA("OpenGL32");
            DYNAMIC_GL_GetProcAddress = reinterpret_cast<wglGetProcAddressProc>(GetProcAddress(gl_library,"wglGetProcAddress"));
#endif
#ifdef DYNAMIC_GL_USE_DLFCN
            gl_library = dlopen(0,RTLD_NOW|RTLD_GLOBAL);
#endif
        }
        static void DynamicGLFinish() {
#ifdef DYNAMIC_GL_PLATFORM_WIN
            FreeLibrary(gl_library);
#endif
#ifdef DYNAMIC_GL_USE_DLFCN
            dlclose(gl_library);
#endif
        }
        
        static const char* all_extensions;
        static int gl_v1;
        static int gl_v2;
        
        static void Init() {
            DynamicGLInit();
            
            LOG_INFO( "RENDERER : " << (char*)GetString(RENDERER) );
            const char* version_string = (const char*)GetString(VERSION);
            LOG_INFO( "VERSION : " << version_string );
            all_extensions = (const char*)GetString(EXTENSIONS);
            std::string str( all_extensions );
            LOG_INFO("EXTENSIONS :");
            {
                std::string::size_type ppos = 0;
                std::string::size_type pos = str.find(' ');
                while ( pos!=str.npos ) {
                    LOG_INFO( "\t" << str.substr(ppos,pos-ppos) );
                    std::string::size_type next = pos+1;
                    pos = str.find( ' ', next );
                    ppos = next;
                    if (pos == str.npos ) {
                        LOG_INFO( "\t" << str.substr(ppos,str.npos) );
                        break;
                    }
                }
            }

            gl_v1 = 0;
            gl_v2 = 0;
            if (::sscanf(version_string, "%d.%d",&gl_v1,&gl_v2)!=2) {
                gl_v1 = 0;
                gl_v2 = 0;
            }
            LOG_INFO("Parsed version: " << gl_v1 << "." << gl_v2);
        }
        static bool CheckExtensionSupported(const char* extensionName) {
            if (::strcmp(extensionName, "CORE")==0) {
                return true;
            }
            int v1 = 0;
            int v2 = 0;
            if (::sscanf(extensionName, "VERSION_%d_%d",&v1,&v2)==2) {
                if (v1<gl_v1) return true;
                if (v1>gl_v1) return false;
                return v2 <= gl_v2;
            }
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
        
#define USE_DYNAMIC_GL_CORE
#define USE_DYNAMIC_GL_VERSION_1_2
#define USE_DYNAMIC_GL_VERSION_1_3
#define USE_DYNAMIC_GL_ARB_multitexture
#define USE_DYNAMIC_GL_ARB_texture_env_combine
#define USE_DYNAMIC_GL_EXT_texture_env_combine
        
//#define USE_DYNAMIC_GL_VERSION_1_3_DEPRECATED
//#define USE_DYNAMIC_GL_VERSION_1_4
//#define USE_DYNAMIC_GL_VERSION_1_5
//        
//        
//        //#define USE_DYNAMIC_GL_SGIS_texture_edge_clamp
//        
//        //
//        
//        //#define USE_DYNAMIC_GL_ARB_texture_env_combine
//        
//        //#define USE_DYNAMIC_GL_ARB_vertex_buffer_object
//        
//#define USE_DYNAMIC_GL_EXT_framebuffer_object
//        
//#define USE_DYNAMIC_GL_ARB_depth_texture
//        
//#define USE_DYNAMIC_GL_ARB_shader_objects
//        
//#define USE_DYNAMIC_GL_ARB_fragment_shader
//        
//#define USE_DYNAMIC_GL_ARB_vertex_shader
        
    
#define DYNAMIC_GL_FEATURE(Name) static bool Feature_##Name##_Supported() { \
        static bool supported = CheckExtensionSupported(#Name); \
        return supported; \
    }
#define DYNAMIC_GL_TYPEDEF(Type,Alias) typedef Type GL##Alias;
#define DYNAMIC_GL_CONSTANT(Name,Val) static const GLenum Name = Val;
#define DYNAMIC_GL_TYPE(Type) GL##Type
#define MAKE_CHECK_FUNC(Ret,Name,Args) \
    typedef Ret (APIENTRYP Name##_Proto) Args; \
    static Name##_Proto func_ptr = 0; \
    if (!func_ptr) func_ptr = LoadFunction<Name##_Proto>("gl"#Name);

#define DYNAMIC_GL_FUNCTION(Ret,Name,Args,ArgNames) \
    static Ret Name Args { \
        MAKE_CHECK_FUNC(Ret,Name,Args)\
        if (func_ptr) return func_ptr ArgNames;\
        return 0; \
    }
#define DYNAMIC_GL_FUNCTION_V(Name,Args,ArgNames) \
    static void Name Args { \
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

    };
    const char* GLApi_impl::all_extensions = 0;
    
    int GLApi_impl::gl_v1 = 0;
    int GLApi_impl::gl_v2 = 0;
    
    
    bool GLApi::InitGL(GL* api) {
        GLApi_impl::Init();
        
        
        api->rtapi = 0;
        api->sdrapi = 0;
        
        if (!GLApi_impl::Feature_VERSION_1_2_Supported()) {
            LOG_ERROR("minimal OpenGL v1.2 notfound");
            return false;
        }
        
#define DYNAMIC_GL_CONSTANT(Name) api->Name = GLApi_impl::Name;
        DYNAMIC_GL_CONSTANTS
#undef DYNAMIC_GL_CONSTANT
#define DYNAMIC_GL_FUNCTION(Name,Args) api->Name = &GLApi_impl::Name;
        DYNAMIC_GL_FUNCTIONS
#undef DYNAMIC_GL_FUNCTION
    
        
        if (!GLApi_impl::Feature_VERSION_1_3_Supported()) {
            if (GLApi_impl::Feature_ARB_multitexture_Supported()) {
                LOG_INFO("using extension ARB_multitexture");
#define DYNAMIC_GL_CONSTANT(Name) api->Name = GLApi_impl::Name##_ARB;
                DYNAMIC_GL_CONSTANTS_Multitexture
#undef DYNAMIC_GL_CONSTANT
#define DYNAMIC_GL_FUNCTION(Name,Args) api->Name = &GLApi_impl::Name##ARB;
                DYNAMIC_GL_FUNCTIONS_Multitexture
#undef DYNAMIC_GL_FUNCTION

            } else {
                LOG_ERROR("extension ARB_multitexture not found");
                return false;
            }
        } else {
            
#define DYNAMIC_GL_CONSTANT(Name) api->Name = GLApi_impl::Name;
            DYNAMIC_GL_CONSTANTS_Multitexture
#undef DYNAMIC_GL_CONSTANT
#define DYNAMIC_GL_FUNCTION(Name,Args) api->Name = &GLApi_impl::Name;
            DYNAMIC_GL_FUNCTIONS_Multitexture
#undef DYNAMIC_GL_FUNCTION

        }
        api->Release = &GLApi_impl::DynamicGLFinish;
        return true;
    }
    
    bool GLApi::InitGLffpl(GLffpl* api) {
        
        if (!GLApi_impl::Feature_VERSION_1_3_Supported()) {
            if (GLApi_impl::Feature_ARB_texture_env_combine_Supported()) {
                LOG_INFO("using extension ARB_texture_env_combine");
#define DYNAMIC_GL_ffpl_CONSTANT(Name) api->Name = GLApi_impl::Name##_ARB;
                DYNAMIC_GL_ffpl_CONSTANTS
#undef DYNAMIC_GL_ffpl_CONSTANT
            } else if (GLApi_impl::Feature_EXT_texture_env_combine_Supported()) {
                LOG_INFO("using extension EXT_texture_env_combine");
#define DYNAMIC_GL_ffpl_CONSTANT(Name) api->Name = GLApi_impl::Name##_EXT;
                DYNAMIC_GL_ffpl_CONSTANTS
#undef DYNAMIC_GL_ffpl_CONSTANT
            } else {
                LOG_ERROR("extensions (ARB|EXT)_texture_env_combine not found");
                return false;
            }
        } else {
#define DYNAMIC_GL_ffpl_CONSTANT(Name) api->Name = GLApi_impl::Name;
            DYNAMIC_GL_ffpl_CONSTANTS
#undef DYNAMIC_GL_ffpl_CONSTANT
            
        }
        
        
        return true;
    }
    
}
