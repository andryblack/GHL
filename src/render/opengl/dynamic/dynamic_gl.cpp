#include "dynamic_gl.h"
#include <ghl_api.h>
#include "../render_opengl_api.h"
#include <string.h>

#if defined ( GHL_PLATFORM_WIN )
//#include <windows.h>
#define APIENTRY __stdcall
#define PROC void*
#define HMODULE void*
#define LPCSTR const char*
#define BOOL int
typedef PROC  (__stdcall *wglGetProcAddressProc)(LPCSTR);
static wglGetProcAddressProc DYNAMIC_GL_GetProcAddress = 0;
static HMODULE gl_library = 0;
extern "C" HMODULE __stdcall LoadLibraryA(const char*);
extern "C" PROC __stdcall GetProcAddress(HMODULE, const char*);
extern "C" BOOL __stdcall FreeLibrary(HMODULE);
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
            
            LOG_INFO( "RENDERER : " << (char*)GetString(GL_RENDERER) );
            const char* version_string = (const char*)GetString(GL_VERSION);
            LOG_INFO( "VERSION : " << version_string );
            all_extensions = (const char*)GetString(GL_EXTENSIONS);
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
#define USE_DYNAMIC_GL_ARB_shader_objects
#define USE_DYNAMIC_GL_ARB_vertex_shader
#define USE_DYNAMIC_GL_ARB_fragment_shader
#define USE_DYNAMIC_GL_ARB_vertex_program
#define USE_DYNAMIC_GL_ARB_shading_language_100
#define USE_DYNAMIC_GL_VERSION_2_0
#define USE_DYNAMIC_GL_VERSION_1_5
#define USE_DYNAMIC_GL_ARB_framebuffer_object
#define USE_DYNAMIC_GL_EXT_framebuffer_object
#define USE_DYNAMIC_GL_ARB_texture_non_power_of_two
#define USE_DYNAMIC_GL_VERSION_1_4
        
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
#define DYNAMIC_GL_TYPEDEF(Type,Alias) typedef Type Alias;
#define DYNAMIC_GL_CONSTANT(Name,Val) static const GLenum Name = Val;
#define DYNAMIC_GL_TYPE(Type) Type
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

        static void GetShaderInfoLogARB(GLuint shader , GLsizei bufSize , GLsizei * length , GLchar * infoLog) {
            GetInfoLogARB(shader, bufSize, length, infoLog);
        }
        static void GetProgramInfoLogARB(GLuint shader , GLsizei bufSize , GLsizei * length , GLchar * infoLog) {
            GetInfoLogARB(shader, bufSize, length, infoLog);
        }
        static GLhandleARB CreateShaderARB(GLenum type) {
            return CreateShaderObjectARB(type);
        }
        static GLhandleARB CreateProgramARB() {
            return CreateProgramObjectARB();
        }
        static void DeleteShaderARB(GLhandleARB obj) {
            DeleteObjectARB(obj);
        }
        static void DeleteProgramARB(GLhandleARB obj) {
            DeleteObjectARB(obj);
        }
        static void UseProgramARB(GLhandleARB prg) {
            UseProgramObjectARB(prg);
        }
        static void AttachShaderARB(GLhandleARB prh,GLhandleARB sdr) {
            AttachObjectARB(prh, sdr);
        }
        static void GetShaderivARB(GLhandleARB prg,GLenum prm,GLint* v) {
            GetObjectParameterivARB(prg, prm, v);
        }
        static void ShaderSourceARB(GLhandleARB sdr,GLsizei sz,const GLchar*const* src,const GLint *len) {
            ShaderSourceARB(sdr,sz, (const GLchar**)src, len);
        }
    };
    const char* GLApi_impl::all_extensions = 0;
    
    int GLApi_impl::gl_v1 = 0;
    int GLApi_impl::gl_v2 = 0;
    
    
    bool GLApi::InitGL(GL* api) {
        GLApi_impl::Init();
        
        
        api->rtapi.valid = false;
        api->sdrapi.valid = false;
        api->GetError = &GLApi_impl::GetError;
        
        if (!GLApi_impl::Feature_VERSION_1_2_Supported()) {
            LOG_ERROR("minimal OpenGL v1.2 notfound");
            return false;
        }
        
        api->npot_textures = GLApi_impl::Feature_ARB_texture_non_power_of_two_Supported();
        
#define DYNAMIC_GL_CONSTANT(Name) api->Name = GLApi_impl::GL_##Name;
        DYNAMIC_GL_CONSTANTS
#undef DYNAMIC_GL_CONSTANT
#define DYNAMIC_GL_FUNCTION(Name,Args) api->Name = &GLApi_impl::Name;
        DYNAMIC_GL_FUNCTIONS
#undef DYNAMIC_GL_FUNCTION
    
        
        if (!GLApi_impl::Feature_VERSION_1_3_Supported()) {
            if (GLApi_impl::Feature_ARB_multitexture_Supported()) {
                LOG_INFO("using extension ARB_multitexture");
#define DYNAMIC_GL_CONSTANT(Name) api->Name = GLApi_impl::GL_##Name##_ARB;
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
            
#define DYNAMIC_GL_CONSTANT(Name) api->Name = GLApi_impl::GL_##Name;
            DYNAMIC_GL_CONSTANTS_Multitexture
#undef DYNAMIC_GL_CONSTANT
#define DYNAMIC_GL_FUNCTION(Name,Args) api->Name = &GLApi_impl::Name;
            DYNAMIC_GL_FUNCTIONS_Multitexture
#undef DYNAMIC_GL_FUNCTION

        }
        
        api->vboapi.valid = false;
        if (GLApi_impl::Feature_VERSION_1_5_Supported()) {
#define DYNAMIC_GL_FUNCTION(Res,Name,Args) api->vboapi.Name = &GLApi_impl::Name;
            DYNAMIC_GL_FUNCTIONS_VBO
#undef DYNAMIC_GL_FUNCTION
            api->vboapi.ARRAY_BUFFER = GLApi_impl::GL_ARRAY_BUFFER;
            api->vboapi.ELEMENT_ARRAY_BUFFER = GLApi_impl::GL_ELEMENT_ARRAY_BUFFER;
            api->vboapi.STATIC_DRAW = GLApi_impl::GL_STATIC_DRAW;
            api->vboapi.DYNAMIC_DRAW = GLApi_impl::GL_DYNAMIC_DRAW;
            api->vboapi.valid = true;
        } else {
            
        }
        
        if (GLApi_impl::Feature_VERSION_2_0_Supported()) {
            api->sdrapi.valid = true;
#define DYNAMIC_GL_FUNCTION(Res,Name,Args) api->sdrapi.Name = &GLApi_impl::Name;
            DYNAMIC_GL_FUNCTIONS_ShaderObject
#undef DYNAMIC_GL_FUNCTION
            
            api->sdrapi.COMPILE_STATUS = GLApi_impl::GL_COMPILE_STATUS;
            api->sdrapi.LINK_STATUS = GLApi_impl::GL_LINK_STATUS;
            api->sdrapi.VERTEX_SHADER = GLApi_impl::GL_VERTEX_SHADER;
            api->sdrapi.FRAGMENT_SHADER = GLApi_impl::GL_FRAGMENT_SHADER;
 
            LOG_INFO("GLSL: " << (const char*)GLApi_impl::GetString(GLApi_impl::GL_SHADING_LANGUAGE_VERSION));
            
        } else if (GLApi_impl::Feature_ARB_shader_objects_Supported() &&
            GLApi_impl::Feature_ARB_vertex_shader_Supported() &&
            GLApi_impl::Feature_ARB_fragment_shader_Supported() &&
            GLApi_impl::Feature_ARB_shading_language_100_Supported() &&
            GLApi_impl::Feature_ARB_vertex_program_Supported()) {
            LOG_INFO("using extension ARB_shader_objects");
            api->sdrapi.valid = true;
#define DYNAMIC_GL_FUNCTION(Res,Name,Args) api->sdrapi.Name = &GLApi_impl::Name##ARB;
            DYNAMIC_GL_FUNCTIONS_ShaderObject
#undef DYNAMIC_GL_FUNCTION
            api->sdrapi.COMPILE_STATUS = GLApi_impl::GL_OBJECT_COMPILE_STATUS_ARB;
            api->sdrapi.LINK_STATUS = GLApi_impl::GL_OBJECT_LINK_STATUS_ARB;
            LOG_INFO("using extension ARB_vertex_shader");
            api->sdrapi.VERTEX_SHADER = GLApi_impl::GL_VERTEX_SHADER_ARB;
            LOG_INFO("using extension ARB_fragment_shader");
            api->sdrapi.FRAGMENT_SHADER = GLApi_impl::GL_FRAGMENT_SHADER_ARB;
            LOG_INFO("using extension ARB_shading_language_100");
            LOG_INFO("GLSL: " << (const char*)GLApi_impl::GetString(GLApi_impl::GL_SHADING_LANGUAGE_VERSION_ARB));
            
        }
        
        if (GLApi_impl::Feature_ARB_framebuffer_object_Supported()) {
            api->rtapi.valid = true;
            api->rtapi.GenFramebuffers = &GLApi_impl::GenFramebuffers;
            api->rtapi.BindFramebuffer = &GLApi_impl::BindFramebuffer;
            api->rtapi.DeleteFramebuffers = &GLApi_impl::DeleteFramebuffers;
            api->rtapi.FramebufferTexture2D = &GLApi_impl::FramebufferTexture2D;
            api->rtapi.BindRenderbuffer = &GLApi_impl::BindRenderbuffer;
            api->rtapi.DeleteRenderbuffers = &GLApi_impl::DeleteRenderbuffers;
            api->rtapi.GenRenderbuffers = &GLApi_impl::GenRenderbuffers;
            api->rtapi.RenderbufferStorage = &GLApi_impl::RenderbufferStorage;
            api->rtapi.FramebufferRenderbuffer = &GLApi_impl::FramebufferRenderbuffer;
            api->rtapi.CheckFramebufferStatus = &GLApi_impl::CheckFramebufferStatus;
            
            api->rtapi.FRAMEBUFFER = GLApi_impl::GL_FRAMEBUFFER;
            api->rtapi.COLOR_ATTACHMENT0 = GLApi_impl::GL_COLOR_ATTACHMENT0;
            api->rtapi.RENDERBUFFER = GLApi_impl::GL_RENDERBUFFER;
            api->rtapi.DEPTH_ATTACHMENT = GLApi_impl::GL_DEPTH_ATTACHMENT;
            if (GLApi_impl::Feature_VERSION_1_4_Supported()) {
                api->rtapi.DEPTH_COMPONENT16 = GLApi_impl::GL_DEPTH_COMPONENT16;
            } else {
                api->rtapi.DEPTH_COMPONENT16 = GLApi_impl::GL_DEPTH_COMPONENT;
            }
            api->rtapi.FRAMEBUFFER_COMPLETE = GLApi_impl::GL_FRAMEBUFFER_COMPLETE;
            
            api->rtapi.default_framebuffer = 0;
        } else if (GLApi_impl::Feature_EXT_framebuffer_object_Supported()) {
            api->rtapi.valid = true;
            api->rtapi.GenFramebuffers = &GLApi_impl::GenFramebuffersEXT;
            api->rtapi.BindFramebuffer = &GLApi_impl::BindFramebufferEXT;
            api->rtapi.DeleteFramebuffers = &GLApi_impl::DeleteFramebuffersEXT;
            api->rtapi.FramebufferTexture2D = &GLApi_impl::FramebufferTexture2DEXT;
            api->rtapi.BindRenderbuffer = &GLApi_impl::BindRenderbufferEXT;
            api->rtapi.DeleteRenderbuffers = &GLApi_impl::DeleteRenderbuffersEXT;
            api->rtapi.GenRenderbuffers = &GLApi_impl::GenRenderbuffersEXT;
            api->rtapi.RenderbufferStorage = &GLApi_impl::RenderbufferStorageEXT;
            api->rtapi.FramebufferRenderbuffer = &GLApi_impl::FramebufferRenderbufferEXT;
            api->rtapi.CheckFramebufferStatus = &GLApi_impl::CheckFramebufferStatusEXT;
            
            api->rtapi.FRAMEBUFFER = GLApi_impl::GL_FRAMEBUFFER_EXT;
            api->rtapi.COLOR_ATTACHMENT0 = GLApi_impl::GL_COLOR_ATTACHMENT0_EXT;
            api->rtapi.RENDERBUFFER = GLApi_impl::GL_RENDERBUFFER_EXT;
            api->rtapi.DEPTH_ATTACHMENT = GLApi_impl::GL_DEPTH_ATTACHMENT_EXT;
            if (GLApi_impl::Feature_VERSION_1_4_Supported()) {
                api->rtapi.DEPTH_COMPONENT16 = GLApi_impl::GL_DEPTH_COMPONENT16;
            } else {
                api->rtapi.DEPTH_COMPONENT16 = GLApi_impl::GL_DEPTH_COMPONENT;
            }
            api->rtapi.FRAMEBUFFER_COMPLETE = GLApi_impl::GL_FRAMEBUFFER_COMPLETE_EXT;
            
            api->rtapi.default_framebuffer = 0;
        }
        
        api->Release = &GLApi_impl::DynamicGLFinish;
        return true;
    }
    
    bool GLApi::InitGLffpl(GLffpl* api) {
#define DYNAMIC_GL_ffpl_CONSTANT(Name) api->Name = GLApi_impl::GL_##Name;
        DYNAMIC_GL_ffpl_CONSTANTS
#undef DYNAMIC_GL_ffpl_CONSTANT
#define DYNAMIC_GL_ffpl_FUNCTION(Name,Args) api->Name = &GLApi_impl::Name;
        DYNAMIC_GL_ffpl_FUNCTIONS
#undef DYNAMIC_GL_ffpl_FUNCTION

        if (!GLApi_impl::Feature_VERSION_1_3_Supported()) {
            if (GLApi_impl::Feature_ARB_texture_env_combine_Supported()) {
                LOG_INFO("using extension ARB_texture_env_combine");
#define DYNAMIC_GL_ffpl_CONSTANT(Name) api->Name = GLApi_impl::GL_##Name##_ARB;
                DYNAMIC_GL_ffpl_CONSTANTS_Combiners
#undef DYNAMIC_GL_ffpl_CONSTANT
            } else if (GLApi_impl::Feature_EXT_texture_env_combine_Supported()) {
                LOG_INFO("using extension EXT_texture_env_combine");
#define DYNAMIC_GL_ffpl_CONSTANT(Name) api->Name = GLApi_impl::GL_##Name##_EXT;
                DYNAMIC_GL_ffpl_CONSTANTS_Combiners
#undef DYNAMIC_GL_ffpl_CONSTANT
            } else {
                LOG_ERROR("extensions (ARB|EXT)_texture_env_combine not found");
                return false;
            }
        } else {
#define DYNAMIC_GL_ffpl_CONSTANT(Name) api->Name = GLApi_impl::GL_##Name;
            DYNAMIC_GL_ffpl_CONSTANTS_Combiners
#undef DYNAMIC_GL_ffpl_CONSTANT
            
        }
        
        
        return true;
    }
    
}
