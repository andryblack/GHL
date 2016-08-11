#include "vfs_emscripten.h"

namespace GHL {

	VFSEmscriptenImpl::VFSEmscriptenImpl() : VFSPosixImpl("/","/") {
		m_cache_dir = "/tmp/";
	}

	VFSEmscriptenImpl::~VFSEmscriptenImpl() {

	}

}