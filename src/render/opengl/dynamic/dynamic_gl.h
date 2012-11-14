#ifndef DYNAMIC_GL_H
#define DYNAMIC_GL_H

#include "dynamic_gl_subset.h"
#include <cstddef>

namespace GHL {
    struct GL {
#define DYNAMIC_GL_FEATURE(Name) bool DinamicGLFeature_##Name##_Supported();
#define DYNAMIC_GL_TYPEDEF(Type,Alias) typedef Type GL##Alias;
#define DYNAMIC_GL_CONSTANT(Name,Val) static const GLenum Name = Val;
#define DYNAMIC_GL_TYPE(Type) GL##Type
#define DYNAMIC_GL_FUNCTION(Ret,Name,Args,ArgNames) Ret Name Args;
#define DYNAMIC_GL_FUNCTION_V(Name,Args,ArgNames) void Name Args;
#include "dynamic_gl_inc.h"
#undef DYNAMIC_GL_FUNCTION
#undef DYNAMIC_GL_FUNCTION_V
#undef DYNAMIC_GL_CONSTANT
#undef DYNAMIC_GL_FEATURE
#undef DYNAMIC_GL_TYPEDEF
#undef DYNAMIC_GL_TYPE
        static void DynamicGLInit();
        static void DynamicGLFinish();
        
    };
    extern GL gl;
}

#endif // DYNAMIC_GL_H
