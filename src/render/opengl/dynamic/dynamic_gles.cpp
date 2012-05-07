#include "dynamic_gles.h"
#include <ghl_api.h>
#include <cstdio>

#if defined ( GHL_PLATFORM_IOS )
#else
#error "usupported platform"
#endif

#include "../../../ghl_log_impl.h"

namespace GHL {

    void DynamicGLInit() {
    }
    void DynamicGLFinish() {
    }

  
    template <typename FUNCPROTO>
    inline FUNCPROTO DynamicGL_LoadFunction(const char* name){
		FUNCPROTO func = 0;
        static const char* MODULE = "DYNAMIC_GL";
        if (!func) {
			LOG_WARNING( "not found entry point for " << name );
        }
        return (FUNCPROTO) ( func );
    }
    void InternalDynamicGLLoadSubset();
#include "dynamic_gles_cpp.inc"

    void DynamicGLLoadSubset() {
        InternalDynamicGLLoadSubset();
    }
}
