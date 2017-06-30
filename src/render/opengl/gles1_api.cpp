//
//  gles1_api.cpp
//  GHL
//
//  Created by Andrey Kunitsyn on 3/6/13.
//  Copyright (c) 2013 AndryBlack. All rights reserved.
//

#include "gles1_api.h"

#if defined ( GHL_PLATFORM_IOS )
#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>
#elif defined ( GHL_PLATFORM_ANDROID ) || defined ( GHL_PLATFORM_EMSCRIPTEN )
#include <GLES/gl.h>
#define GL_GLEXT_PROTOTYPES
#include <GLES/glext.h>
#else
#error "usupported platform"
#endif

#include "../../ghl_log_impl.h"
#include "render_opengl_api.h"

namespace GHL {
    
    static const char* MODULE = "GLES1";
    
    
    
    
    struct GLES1Api_impl {
        
        static const char* all_extensions;
        
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
            
        }
        static bool CheckExtensionSupported(const char* extensionName) {
            if (::strcmp(extensionName, "CORE")==0) {
                return true;
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
    const char* GLES1Api_impl::all_extensions = 0;
    
    static GHL_GL_API void glClearDepth(double v) { glClearDepthf(v);}
    
    
    
    
    
#define GL_RGB8 GL_RGB
#define GL_RGBA8 GL_RGBA
#define GL_UNPACK_ROW_LENGTH 0
    
    bool GLES1Api::InitGL(GL* api) {
        GLES1Api_impl::Init();
        
        api->IsTextureFormatSupported = 0;
        api->rtapi.valid = false;
        api->sdrapi.valid = false;
        
        
#define DYNAMIC_GL_CONSTANT(Name) api->Name = GL_##Name;
        DYNAMIC_GL_CONSTANTS
        DYNAMIC_GL_CONSTANTS_Multitexture
#undef DYNAMIC_GL_CONSTANT
#define DYNAMIC_GL_FUNCTION(Name,Args) api->Name = &gl##Name;
        DYNAMIC_GL_FUNCTIONS
        DYNAMIC_GL_FUNCTIONS_Multitexture
#undef DYNAMIC_GL_FUNCTION
        
        api->GetError = &glGetError;
        
        if (GLES1Api_impl::CheckExtensionSupported("GL_OES_rgb8_rgba8")) {
            api->RGB8 = GL_RGB8_OES;
            api->RGBA8 = GL_RGBA8_OES;
        }
        
      
        if (GLES1Api_impl::CheckExtensionSupported("GL_OES_framebuffer_object")) {
            api->rtapi.valid = true;
            api->rtapi.FRAMEBUFFER = GL_FRAMEBUFFER_OES;
            api->rtapi.COLOR_ATTACHMENT0 = GL_COLOR_ATTACHMENT0_OES;
            api->rtapi.RENDERBUFFER = GL_RENDERBUFFER_OES;
            api->rtapi.DEPTH_ATTACHMENT = GL_DEPTH_ATTACHMENT_OES;
            api->rtapi.DEPTH_COMPONENT16 = GL_DEPTH_COMPONENT16_OES;
            api->rtapi.FRAMEBUFFER_COMPLETE = GL_FRAMEBUFFER_COMPLETE_OES;
            api->rtapi.GenFramebuffers = glGenFramebuffersOES;
            api->rtapi.BindFramebuffer = glBindFramebufferOES;
            api->rtapi.DeleteFramebuffers = glDeleteFramebuffersOES;
            api->rtapi.FramebufferTexture2D = glFramebufferTexture2DOES;
            api->rtapi.BindRenderbuffer = glBindRenderbufferOES;
            api->rtapi.DeleteRenderbuffers = glDeleteRenderbuffersOES;
            api->rtapi.GenRenderbuffers = glGenRenderbuffersOES;
            api->rtapi.RenderbufferStorage = glRenderbufferStorageOES;
            api->rtapi.FramebufferRenderbuffer = glFramebufferRenderbufferOES;
            api->rtapi.CheckFramebufferStatus = glCheckFramebufferStatusOES;
        }
        
        api->vboapi.valid = false;
        
        
        api->Release = 0;
        return true;
    }
    
    
#define GL_SOURCE0_RGB GL_SRC0_RGB
#define GL_SOURCE1_RGB GL_SRC1_RGB
#define GL_SOURCE2_RGB GL_SRC2_RGB
    
#define GL_SOURCE0_ALPHA GL_SRC0_ALPHA
#define GL_SOURCE1_ALPHA GL_SRC1_ALPHA
#define GL_SOURCE2_ALPHA GL_SRC2_ALPHA
    
    
    
    bool GLES1Api::InitGLffpl(GLffpl* api) {
        
#define DYNAMIC_GL_ffpl_CONSTANT(Name) api->Name = GL_##Name;
        DYNAMIC_GL_ffpl_CONSTANTS
        DYNAMIC_GL_ffpl_CONSTANTS_Combiners
#undef DYNAMIC_GL_ffpl_CONSTANT
        
#define DYNAMIC_GL_ffpl_FUNCTION(Name,Args) api->Name = &gl##Name;
        DYNAMIC_GL_ffpl_FUNCTIONS
#undef DYNAMIC_GL_ffpl_FUNCTION
        
        return true;
    }

}
