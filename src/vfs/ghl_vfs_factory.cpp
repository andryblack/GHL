/*
 *  ghl_vfs_factory.cpp
 *  SR
 *
 *  Created by Андрей Куницын on 20.05.11.
 *  Copyright 2011 andryblack. All rights reserved.
 *
 */

#include <ghl_api.h>

#ifndef GHL_BUILD_TOOLS
#if defined(GHL_PLATFORM_MAC) || defined(GHL_PLATFORM_IOS)
#include "vfs_cocoa.h"
GHL_API GHL::VFS* GHL_CALL GHL_CreateVFS() {
	return new GHL::VFSCocoaImpl();
}
GHL_API void GHL_CALL GHL_DestroyVFS(GHL::VFS* vfs) {
	delete reinterpret_cast<GHL::VFSCocoaImpl*> (vfs);
}
#endif

#ifdef GHL_PLATFORM_WIN
#include "vfs_win32.h"
GHL_API GHL::VFS* GHL_CALL GHL_CreateVFS() {
	return new GHL::VFSWin32Impl();
}
GHL_API void GHL_CALL GHL_DestroyVFS(GHL::VFS* vfs) {
	delete reinterpret_cast<GHL::VFSWin32Impl*> (vfs);
}
#endif

#ifdef GHL_PLATFORM_EMSCRIPTEN
#include "vfs_emscripten.h"
GHL_API GHL::VFS* GHL_CALL GHL_CreateVFS() {
    return new GHL::VFSEmscriptenImpl();
}
GHL_API void GHL_CALL GHL_DestroyVFS(GHL::VFS* vfs) {
    delete reinterpret_cast<GHL::VFSEmscriptenImpl*>(vfs);
}
#endif
#endif

#if defined(GHL_PLATFORM_LINUX) || defined(GHL_BUILD_TOOLS)
#include "vfs_posix.h"
GHL_API GHL::VFS* GHL_CALL GHL_CreateVFS() {
    return new GHL::VFSPosixImpl("/","/");
}
GHL_API void GHL_CALL GHL_DestroyVFS(GHL::VFS* vfs) {
    delete reinterpret_cast<GHL::VFSPosixImpl*>(vfs);
}
#endif

