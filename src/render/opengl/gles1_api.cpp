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
#include <GLES/glext.h>
#else
#error "usupported platform"
#endif

#include "../../ghl_log_impl.h"
#include "render_opengl_api.h"

namespace GHL {
    
    static const char* MODULE = "DYNAMIC_GL";
    
    
    
    
    struct GLES1Api_impl {
        
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
    const char* GLES1Api_impl::all_extensions = 0;
    
    int GLES1Api_impl::gl_v1 = 0;
    int GLES1Api_impl::gl_v2 = 0;
    
    static GHL_GL_API void glClearDepth(double v) { glClearDepthf(v);}
    
    
    
    
    
#define GL_RGB8 GL_RGB
#define GL_RGBA8 GL_RGBA
#define GL_UNPACK_ROW_LENGTH 0
    
    bool GLES1Api::InitGL(GL* api) {
        GLES1Api_impl::Init();
        
        
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
        
        
        //        }
        
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