//
//  render_opengl_api.h
//  GHL
//
//  Created by Andrey Kunitsyn on 3/6/13.
//  Copyright (c) 2013 AndryBlack. All rights reserved.
//

#ifndef GHL_render_opengl_api_h
#define GHL_render_opengl_api_h

#include "ghl_api.h"
#include <stddef.h>

#if defined(GHL_PLATFORM_IOS) || defined(GHL_PLATFORM_ANDROID)
#define GHL_OPENGLES
#endif

namespace GHL {
    
    struct GL {
        typedef unsigned int GLenum;
        typedef unsigned char GLboolean;
        typedef unsigned int GLbitfield;
        typedef void GLvoid;
        typedef signed char GLbyte;
        typedef short GLshort;
        typedef int GLint;
        typedef unsigned char GLubyte;
        typedef unsigned short GLushort;
        typedef unsigned int GLuint;
        typedef int GLsizei;
        typedef float GLfloat;
        typedef float GLclampf;
        typedef double GLdouble;
        typedef double GLclampd;
        
        typedef char GLchar;
        typedef unsigned int GLhandle;
        typedef ptrdiff_t GLsizeiptr;
        
        static const GLboolean _TRUE;
        static const GLboolean _FALSE;
#define DYNAMIC_GL_CONSTANTS_Multitexture \
\
DYNAMIC_GL_CONSTANT(TEXTURE0)\
DYNAMIC_GL_CONSTANT(TEXTURE1)\
DYNAMIC_GL_CONSTANT(TEXTURE2)\
DYNAMIC_GL_CONSTANT(TEXTURE3)\
DYNAMIC_GL_CONSTANT(TEXTURE4)\

#define DYNAMIC_GL_CONSTANTS \
\
DYNAMIC_GL_CONSTANT(ZERO)\
DYNAMIC_GL_CONSTANT(ONE)\
DYNAMIC_GL_CONSTANT(SRC_COLOR)\
DYNAMIC_GL_CONSTANT(ONE_MINUS_SRC_COLOR)\
DYNAMIC_GL_CONSTANT(SRC_ALPHA)\
DYNAMIC_GL_CONSTANT(ONE_MINUS_SRC_ALPHA)\
DYNAMIC_GL_CONSTANT(DST_ALPHA)\
DYNAMIC_GL_CONSTANT(ONE_MINUS_DST_ALPHA)\
DYNAMIC_GL_CONSTANT(DST_COLOR)\
DYNAMIC_GL_CONSTANT(ONE_MINUS_DST_COLOR)\
\
DYNAMIC_GL_CONSTANT(NEVER)\
DYNAMIC_GL_CONSTANT(LESS)\
DYNAMIC_GL_CONSTANT(EQUAL)\
DYNAMIC_GL_CONSTANT(LEQUAL)\
DYNAMIC_GL_CONSTANT(GREATER)\
DYNAMIC_GL_CONSTANT(NOTEQUAL)\
DYNAMIC_GL_CONSTANT(GEQUAL)\
DYNAMIC_GL_CONSTANT(ALWAYS)\
\
DYNAMIC_GL_CONSTANT(TEXTURE)\
\
DYNAMIC_GL_CONSTANT(TEXTURE_2D)\
\
DYNAMIC_GL_CONSTANT(ALPHA)\
DYNAMIC_GL_CONSTANT(RGB)\
DYNAMIC_GL_CONSTANT(RGBA)\
DYNAMIC_GL_CONSTANT(RGB8)\
DYNAMIC_GL_CONSTANT(RGBA8)\
\
DYNAMIC_GL_CONSTANT(UNSIGNED_SHORT_5_6_5)\
DYNAMIC_GL_CONSTANT(UNSIGNED_SHORT_4_4_4_4)\
\
DYNAMIC_GL_CONSTANT(BYTE)\
DYNAMIC_GL_CONSTANT(UNSIGNED_BYTE)\
DYNAMIC_GL_CONSTANT(SHORT)\
DYNAMIC_GL_CONSTANT(UNSIGNED_SHORT)\
DYNAMIC_GL_CONSTANT(FLOAT)\
\
DYNAMIC_GL_CONSTANT(SCISSOR_TEST)\
DYNAMIC_GL_CONSTANT(DEPTH_TEST)\
DYNAMIC_GL_CONSTANT(BLEND)\
\
DYNAMIC_GL_CONSTANT(COLOR_BUFFER_BIT)\
DYNAMIC_GL_CONSTANT(DEPTH_BUFFER_BIT)\
\
DYNAMIC_GL_CONSTANT(CW)\
DYNAMIC_GL_CONSTANT(CCW)\
DYNAMIC_GL_CONSTANT(CULL_FACE)\
\
DYNAMIC_GL_CONSTANT(LINES)\
DYNAMIC_GL_CONSTANT(LINE_LOOP)\
DYNAMIC_GL_CONSTANT(LINE_STRIP)\
DYNAMIC_GL_CONSTANT(TRIANGLES)\
DYNAMIC_GL_CONSTANT(TRIANGLE_STRIP)\
DYNAMIC_GL_CONSTANT(TRIANGLE_FAN)\
\
DYNAMIC_GL_CONSTANT(CLAMP_TO_EDGE)\
DYNAMIC_GL_CONSTANT(REPEAT)\
\
DYNAMIC_GL_CONSTANT(TEXTURE_WRAP_S)\
DYNAMIC_GL_CONSTANT(TEXTURE_WRAP_T)\
DYNAMIC_GL_CONSTANT(TEXTURE_MAG_FILTER)\
DYNAMIC_GL_CONSTANT(TEXTURE_MIN_FILTER)\
\
DYNAMIC_GL_CONSTANT(NEAREST)\
DYNAMIC_GL_CONSTANT(LINEAR)\
DYNAMIC_GL_CONSTANT(NEAREST_MIPMAP_NEAREST)\
DYNAMIC_GL_CONSTANT(LINEAR_MIPMAP_NEAREST)\
DYNAMIC_GL_CONSTANT(NEAREST_MIPMAP_LINEAR)\
DYNAMIC_GL_CONSTANT(LINEAR_MIPMAP_LINEAR)\
\
DYNAMIC_GL_CONSTANT(UNPACK_ALIGNMENT)\
DYNAMIC_GL_CONSTANT(UNPACK_ROW_LENGTH)\
\
DYNAMIC_GL_CONSTANT(NO_ERROR)\

#define DYNAMIC_GL_CONSTANT(Name) GLenum Name;
        DYNAMIC_GL_CONSTANTS_Multitexture
        DYNAMIC_GL_CONSTANTS
#undef DYNAMIC_GL_CONSTANT
        
#define DYNAMIC_GL_FUNCTIONS_Multitexture \
DYNAMIC_GL_FUNCTION(ActiveTexture,(GLenum))\

#define DYNAMIC_GL_FUNCTIONS \
DYNAMIC_GL_FUNCTION(BindTexture,(GLenum,GLuint))\
DYNAMIC_GL_FUNCTION(Flush,())\
DYNAMIC_GL_FUNCTION(ReadPixels,(GLint,GLint,GLsizei,GLsizei,GLenum,GLenum,GLvoid*))\
DYNAMIC_GL_FUNCTION(Viewport,(GLint,GLint,GLsizei,GLsizei))\
DYNAMIC_GL_FUNCTION(Enable,(GLenum))\
DYNAMIC_GL_FUNCTION(Disable,(GLenum))\
DYNAMIC_GL_FUNCTION(Scissor,(GLint,GLint,GLsizei,GLsizei))\
DYNAMIC_GL_FUNCTION(ClearColor,(GLclampf,GLclampf,GLclampf,GLclampf))\
DYNAMIC_GL_FUNCTION(Clear,(GLbitfield))\
DYNAMIC_GL_FUNCTION(ClearDepth,(GLclampd))\
DYNAMIC_GL_FUNCTION(BlendFunc,(GLenum,GLenum))\
DYNAMIC_GL_FUNCTION(DepthFunc,(GLenum))\
DYNAMIC_GL_FUNCTION(DepthMask,(GLboolean))\
DYNAMIC_GL_FUNCTION(FrontFace,(GLenum))\
DYNAMIC_GL_FUNCTION(DrawElements,(GLenum,GLsizei,GLenum,const GLvoid *))\
DYNAMIC_GL_FUNCTION(DrawArrays,(GLenum,GLint,GLsizei))\
DYNAMIC_GL_FUNCTION(TexParameteri,(GLenum,GLenum,GLint))\
DYNAMIC_GL_FUNCTION(GenTextures,(GLsizei,GLuint *))\
DYNAMIC_GL_FUNCTION(DeleteTextures,(GLsizei,const GLuint *))\
DYNAMIC_GL_FUNCTION(CompressedTexImage2D,(GLenum,GLint,GLenum,GLsizei,GLsizei,GLint,GLsizei,const GLvoid *))\
DYNAMIC_GL_FUNCTION(TexImage2D,(GLenum,GLint,GLint,GLsizei,GLsizei,GLint,GLenum,GLenum,const GLvoid *))\
DYNAMIC_GL_FUNCTION(CompressedTexSubImage2D,(GLenum,GLint,GLint,GLint,GLsizei,GLsizei,GLenum,GLsizei, const GLvoid *))\
DYNAMIC_GL_FUNCTION(TexSubImage2D,(GLenum,GLint,GLint,GLint,GLsizei,GLsizei,GLenum,GLenum,const GLvoid *))\
DYNAMIC_GL_FUNCTION(PixelStorei,(GLenum,GLint))\

        
#define DYNAMIC_GL_FUNCTION(Name,Args) void (*Name) Args;
        DYNAMIC_GL_FUNCTIONS
        DYNAMIC_GL_FUNCTIONS_Multitexture
#undef DYNAMIC_GL_FUNCTION
        
        GLenum (*GetError)();
        
        struct RenderTargetAPI {
            bool valid;
            void (*GenFramebuffers)(GLsizei n , GLuint *framebuffers);
            void (*BindFramebuffer)(GLenum target , GLuint framebuffer);
            void (*DeleteFramebuffers)(GLsizei n , const GLuint *framebuffers);
            void (*FramebufferTexture2D)(GLenum  ,GLenum  ,GLenum  ,GLuint  , GLint );
            void (*BindRenderbuffer)(GLenum target , GLuint renderbuffer);
            void (*DeleteRenderbuffers)(GLsizei n , const GLuint *renderbuffers);
            void (*GenRenderbuffers)(GLsizei n , GLuint *renderbuffers);
            void (*RenderbufferStorage)(GLenum target , GLenum internalformat , GLsizei width , GLsizei height);
            void (*FramebufferRenderbuffer)(GLenum ,GLenum ,GLenum ,GLuint renderbuffer);
            GLenum (*CheckFramebufferStatus)(GLenum target);
            GLenum FRAMEBUFFER;
            GLenum COLOR_ATTACHMENT0;
            GLenum RENDERBUFFER;
            GLenum DEPTH_ATTACHMENT;
            GLenum DEPTH_COMPONENT16;
            GLenum FRAMEBUFFER_COMPLETE;
            
            GLuint default_framebuffer;
        } rtapi;
        
        struct VBOAPI {
            bool valid;
#define DYNAMIC_GL_FUNCTIONS_VBO \
DYNAMIC_GL_FUNCTION(void,GenBuffers,(GLsizei,GLuint *))\
DYNAMIC_GL_FUNCTION(void,BindBuffer,(GLenum,GLuint))\
DYNAMIC_GL_FUNCTION(void,DeleteBuffers,(GLsizei,const GLuint *))\
DYNAMIC_GL_FUNCTION(void,BufferData,(GLenum,GLsizeiptr,const GLvoid *, GLenum))\

#define DYNAMIC_GL_FUNCTION(Res,Name,Args) Res(*Name)Args;
            DYNAMIC_GL_FUNCTIONS_VBO
#undef DYNAMIC_GL_FUNCTION
            
            GLenum ARRAY_BUFFER;
            GLenum ELEMENT_ARRAY_BUFFER;
            GLenum STATIC_DRAW;
            
        } vboapi;
        
        struct ShaderAPI {
            bool valid;
#define DYNAMIC_GL_FUNCTIONS_ShaderObject \
DYNAMIC_GL_FUNCTION(GLhandle,CreateProgram,())\
DYNAMIC_GL_FUNCTION(void,LinkProgram,(GLhandle))\
DYNAMIC_GL_FUNCTION(void,UseProgram,(GLhandle))\
DYNAMIC_GL_FUNCTION(void,GetProgramiv,(GLhandle,GLenum,GLint *))\
DYNAMIC_GL_FUNCTION(void,GetProgramInfoLog,(GLhandle,GLsizei,GLsizei *,GLchar *))\
DYNAMIC_GL_FUNCTION(void,DeleteProgram,(GLhandle))\
DYNAMIC_GL_FUNCTION(void,Uniform1f,(GLint,GLfloat))\
DYNAMIC_GL_FUNCTION(void,Uniform2f,(GLint,GLfloat,GLfloat))\
DYNAMIC_GL_FUNCTION(void,Uniform3f,(GLint,GLfloat,GLfloat,GLfloat))\
DYNAMIC_GL_FUNCTION(void,Uniform4f,(GLint,GLfloat,GLfloat,GLfloat,GLfloat))\
DYNAMIC_GL_FUNCTION(void,Uniform1i,(GLint,GLint))\
DYNAMIC_GL_FUNCTION(void,UniformMatrix4fv,(GLint,GLsizei,GLboolean, const GLfloat * ))\
DYNAMIC_GL_FUNCTION(GLint,GetUniformLocation,(GLhandle,const GLchar *))\
DYNAMIC_GL_FUNCTION(GLint,GetAttribLocation,(GLhandle,const GLchar *))\
DYNAMIC_GL_FUNCTION(GLhandle,CreateShader,(GLenum))\
DYNAMIC_GL_FUNCTION(void,DeleteShader,(GLhandle))\
DYNAMIC_GL_FUNCTION(void,ShaderSource,(GLhandle,GLsizei,const GLchar*const*,const GLint *))\
DYNAMIC_GL_FUNCTION(void,CompileShader,(GLhandle))\
DYNAMIC_GL_FUNCTION(void,GetShaderiv,(GLhandle,GLenum,GLint *))\
DYNAMIC_GL_FUNCTION(void,GetShaderInfoLog,(GLhandle,GLsizei,GLsizei *,GLchar *))\
DYNAMIC_GL_FUNCTION(void,AttachShader,(GLhandle,GLhandle))\
DYNAMIC_GL_FUNCTION(void,VertexAttribPointer,(GLuint,GLint,GLenum,GLboolean,GLsizei,const GLvoid *))\
DYNAMIC_GL_FUNCTION(void,EnableVertexAttribArray,(GLuint))\

            
#define DYNAMIC_GL_FUNCTION(Res,Name,Args) Res(*Name)Args;
            DYNAMIC_GL_FUNCTIONS_ShaderObject
#undef DYNAMIC_GL_FUNCTION
            
            GLenum COMPILE_STATUS;
            GLenum LINK_STATUS;
            GLenum VERTEX_SHADER;
            GLenum FRAGMENT_SHADER;
        } sdrapi;
        
        void (*Release)();
    };
    
    struct GLffpl {
        
#define DYNAMIC_GL_ffpl_CONSTANTS_Combiners \
\
DYNAMIC_GL_ffpl_CONSTANT(PREVIOUS)\
DYNAMIC_GL_ffpl_CONSTANT(COMBINE)\
DYNAMIC_GL_ffpl_CONSTANT(COMBINE_RGB)\
DYNAMIC_GL_ffpl_CONSTANT(COMBINE_ALPHA)\
DYNAMIC_GL_ffpl_CONSTANT(SOURCE0_RGB)\
DYNAMIC_GL_ffpl_CONSTANT(SOURCE1_RGB)\
DYNAMIC_GL_ffpl_CONSTANT(SOURCE2_RGB)\
DYNAMIC_GL_ffpl_CONSTANT(SOURCE0_ALPHA)\
DYNAMIC_GL_ffpl_CONSTANT(SOURCE1_ALPHA)\
DYNAMIC_GL_ffpl_CONSTANT(SOURCE2_ALPHA)\
DYNAMIC_GL_ffpl_CONSTANT(OPERAND0_RGB)\
DYNAMIC_GL_ffpl_CONSTANT(OPERAND1_RGB)\
DYNAMIC_GL_ffpl_CONSTANT(OPERAND2_RGB)\
DYNAMIC_GL_ffpl_CONSTANT(OPERAND0_ALPHA)\
DYNAMIC_GL_ffpl_CONSTANT(OPERAND1_ALPHA)\
DYNAMIC_GL_ffpl_CONSTANT(OPERAND2_ALPHA)\

#define DYNAMIC_GL_ffpl_CONSTANTS \
\
DYNAMIC_GL_ffpl_CONSTANT(MODULATE)\
DYNAMIC_GL_ffpl_CONSTANT(REPLACE)\
DYNAMIC_GL_ffpl_CONSTANT(ADD)\
\
DYNAMIC_GL_ffpl_CONSTANT(TEXTURE_ENV)\
DYNAMIC_GL_ffpl_CONSTANT(TEXTURE_ENV_MODE)\
DYNAMIC_GL_ffpl_CONSTANT(INTERPOLATE)\
\
DYNAMIC_GL_ffpl_CONSTANT(MODELVIEW)\
DYNAMIC_GL_ffpl_CONSTANT(PROJECTION)\
\
DYNAMIC_GL_ffpl_CONSTANT(VERTEX_ARRAY)\
DYNAMIC_GL_ffpl_CONSTANT(COLOR_ARRAY)\
DYNAMIC_GL_ffpl_CONSTANT(TEXTURE_COORD_ARRAY)\

//#define DYNAMIC_GL_ffpl_CONSTANTS_Multitexture

#define DYNAMIC_GL_ffpl_CONSTANT(Name) GL::GLenum Name;
        DYNAMIC_GL_ffpl_CONSTANTS
        DYNAMIC_GL_ffpl_CONSTANTS_Combiners
//        DYNAMIC_GL_ffpl_CONSTANTS_Multitexture
#undef DYNAMIC_GL_ffpl_CONSTANT
        
        typedef GL::GLenum GLenum;
        typedef GL::GLint GLint;
        typedef GL::GLfloat GLfloat;
        typedef GL::GLsizei GLsizei;
        typedef GL::GLvoid GLvoid;
        
#define DYNAMIC_GL_ffpl_FUNCTIONS \
\
DYNAMIC_GL_ffpl_FUNCTION(TexEnvi,(GLenum,GLenum,GLint))\
DYNAMIC_GL_ffpl_FUNCTION(MatrixMode,(GLenum))\
DYNAMIC_GL_ffpl_FUNCTION(LoadMatrixf,(const GLfloat *))\
DYNAMIC_GL_ffpl_FUNCTION(LoadIdentity,())\
DYNAMIC_GL_ffpl_FUNCTION(EnableClientState,(GLenum))\
DYNAMIC_GL_ffpl_FUNCTION(TexCoordPointer,(GLint,GLenum,GLsizei,const GLvoid *))\
DYNAMIC_GL_ffpl_FUNCTION(ColorPointer,(GLint,GLenum,GLsizei,const GLvoid *))\
DYNAMIC_GL_ffpl_FUNCTION(VertexPointer,(GLint,GLenum,GLsizei,const GLvoid *))\
        
//#define DYNAMIC_GL_ffpl_FUNCTIONS_Multitexture \
//DYNAMIC_GL_ffpl_FUNCTION(ClientActiveTexture,(GLenum))\

        
#define DYNAMIC_GL_ffpl_FUNCTION(Name,Args) void (*Name) Args;
        DYNAMIC_GL_ffpl_FUNCTIONS
//        DYNAMIC_GL_ffpl_FUNCTIONS_Multitexture
#undef DYNAMIC_GL_ffpl_FUNCTION

    };
    
}

void gl_error_report_bp();

#ifdef GHL_DEBUG
#define CHECK_GL(Func) \
    do { \
        Func; \
        GL::GLenum err = gl.GetError(); \
        if (err!=gl.NO_ERROR) { \
            LOG_ERROR("GL error: " << err << " at " << #Func); \
            gl_error_report_bp(); \
        }\
    } while(false)
#else
#define CHECK_GL(Func) Func
#endif


#endif
