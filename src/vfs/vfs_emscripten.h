#ifndef VFS_EMSCRIPTEN_H
#define VFS_EMSCRIPTEN_H

#include "vfs_posix.h"

namespace GHL {

	class VFSEmscriptenImpl : public VFSPosixImpl {
	public:
		VFSEmscriptenImpl();
		~VFSEmscriptenImpl();
	};
}

#endif /*VFS_EMSCRIPTEN_H*/