#include "dynamic_gles.h"
#include <ghl_api.h>
#include <cstdio>

#if defined ( GHL_PLATFORM_IOS )
#include <OpenGLES/ES1/gl.h>
#else
#error "usupported platform"
#endif

#include "../../../ghl_log_impl.h"

namespace GHL {

    void DynamicGLInit() {
    }
    void DynamicGLFinish() {
    }

	static bool DynamicGL_CheckExtensionSupported(const char* extensionName) {
		static const char* all_extensions = (const char*)glGetString(GL_EXTENSIONS);
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
	
    void InternalDynamicGLLoadSubset();
#include "dynamic_gles_cpp.inc"

    void DynamicGLLoadSubset() {
        InternalDynamicGLLoadSubset();
    }
}
