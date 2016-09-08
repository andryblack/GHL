//
//  gles2_api.cpp
//  GHL
//
//  Created by Andrey Kunitsyn on 3/6/13.
//  Copyright (c) 2013 AndryBlack. All rights reserved.
//

#include "gles2_api.h"

#if defined ( GHL_PLATFORM_IOS )
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>
#elif defined ( GHL_PLATFORM_ANDROID ) || defined ( GHL_PLATFORM_EMSCRIPTEN )
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#else
#error "usupported platform"
#endif

#include "../../ghl_log_impl.h"
#include "render_opengl_api.h"

namespace GHL {
    
    static const char* MODULE = "DYNAMIC_GL";
    
    
    
    
    struct GLES2Api_impl {
        
        static const char* all_extensions;
        static int gl_v1;
        static int gl_v2;
        
        static void Init() {
            
            LOG_INFO( "RENDERER : " << (char*)glGetString(GL_RENDERER) );
            const char* version_string = (const char*)glGetString(GL_VERSION);
            LOG_INFO( "VERSION : " << version_string );
            all_extensions = (const char*)glGetString(GL_EXTENSIONS);
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
        
    };
    const char* GLES2Api_impl::all_extensions = 0;
    
    int GLES2Api_impl::gl_v1 = 0;
    int GLES2Api_impl::gl_v2 = 0;
    
    static GHL_GL_API void glClearDepth(double v) { glClearDepthf(v);}
    
    
    static GHL_GL_API void glShaderSource(GL::GLhandle s,GLsizei count,const GLchar*const* string,const GLint * length) {
            ::glShaderSource(s, count, const_cast<const char**>(string), length);
    }
    
#define GL_RGB8 GL_RGB
#define GL_RGBA8 GL_RGBA
#define GL_UNPACK_ROW_LENGTH 0
    
    static GHL_GL_API void _glBufferData (GLenum target, GL::GLsizeiptr size, const GLvoid *data, GLenum usage) {
        glBufferData(target, size, data, usage);
    }
    
    bool GLES2Api::InitGL(GL* api) {
        GLES2Api_impl::Init();
        
        
        api->rtapi.valid = false;
        api->sdrapi.valid = false;
        
        
#define DYNAMIC_GL_CONSTANT(Name) api->Name = GL_##Name;
        DYNAMIC_GL_CONSTANTS
#undef DYNAMIC_GL_CONSTANT
#define DYNAMIC_GL_FUNCTION(Name,Args) api->Name = &gl##Name;
        DYNAMIC_GL_FUNCTIONS
#undef DYNAMIC_GL_FUNCTION
        
        api->GetError = &glGetError;
        
        if (GLES2Api_impl::CheckExtensionSupported("GL_OES_rgb8_rgba8")) {
            api->RGB8 = GL_RGB8_OES;
            api->RGBA8 = GL_RGBA8_OES;
        }
        
        
#define DYNAMIC_GL_CONSTANT(Name) api->Name = GL_##Name;
        DYNAMIC_GL_CONSTANTS_Multitexture
#undef DYNAMIC_GL_CONSTANT
#define DYNAMIC_GL_FUNCTION(Name,Args) api->Name = &gl##Name;
        DYNAMIC_GL_FUNCTIONS_Multitexture
#undef DYNAMIC_GL_FUNCTION
        
        
        api->sdrapi.valid = true;
        {
#define DYNAMIC_GL_FUNCTION(Res,Name,Args) api->sdrapi.Name = &gl##Name;
            DYNAMIC_GL_FUNCTIONS_ShaderObject
#undef DYNAMIC_GL_FUNCTION
            
            api->sdrapi.COMPILE_STATUS = GL_COMPILE_STATUS;
            api->sdrapi.LINK_STATUS = GL_LINK_STATUS;
            api->sdrapi.VERTEX_SHADER = GL_VERTEX_SHADER;
            api->sdrapi.FRAGMENT_SHADER = GL_FRAGMENT_SHADER;
            
            LOG_INFO("GLSL: " << (const char*)glGetString(GL_SHADING_LANGUAGE_VERSION));
        }
        
        //        }
        
        api->vboapi.valid = true;
        api->vboapi.STATIC_DRAW = GL_STATIC_DRAW;
        api->vboapi.ELEMENT_ARRAY_BUFFER = GL_ELEMENT_ARRAY_BUFFER;
        api->vboapi.ARRAY_BUFFER = GL_ARRAY_BUFFER;
        api->vboapi.BindBuffer = glBindBuffer;
        api->vboapi.BufferData = _glBufferData;
        api->vboapi.DeleteBuffers = glDeleteBuffers;
        api->vboapi.GenBuffers = glGenBuffers;
        
        api->rtapi.valid = true;
        api->rtapi.FRAMEBUFFER = GL_FRAMEBUFFER;
        api->rtapi.COLOR_ATTACHMENT0 = GL_COLOR_ATTACHMENT0;
        api->rtapi.RENDERBUFFER = GL_RENDERBUFFER;
        api->rtapi.DEPTH_ATTACHMENT = GL_DEPTH_ATTACHMENT;
        api->rtapi.DEPTH_COMPONENT16 = GL_DEPTH_COMPONENT16;
        api->rtapi.FRAMEBUFFER_COMPLETE = GL_FRAMEBUFFER_COMPLETE;
        api->rtapi.GenFramebuffers = glGenFramebuffers;
        api->rtapi.BindFramebuffer = glBindFramebuffer;
        api->rtapi.DeleteFramebuffers = glDeleteFramebuffers;
        api->rtapi.FramebufferTexture2D = glFramebufferTexture2D;
        api->rtapi.BindRenderbuffer = glBindRenderbuffer;
        api->rtapi.DeleteRenderbuffers = glDeleteRenderbuffers;
        api->rtapi.GenRenderbuffers = glGenRenderbuffers;
        api->rtapi.RenderbufferStorage = glRenderbufferStorage;
        api->rtapi.FramebufferRenderbuffer = glFramebufferRenderbuffer;
        api->rtapi.CheckFramebufferStatus = glCheckFramebufferStatus;
        
        
        api->Release = 0;
        return true;
    }
    
    
#define GL_SOURCE0_RGB GL_SRC0_RGB
#define GL_SOURCE1_RGB GL_SRC1_RGB
#define GL_SOURCE2_RGB GL_SRC2_RGB
    
#define GL_SOURCE0_ALPHA GL_SRC0_ALPHA
#define GL_SOURCE1_ALPHA GL_SRC1_ALPHA
#define GL_SOURCE2_ALPHA GL_SRC2_ALPHA
    
    
    

}