/*
 *  os_opengl.h
 *  TurboSquirrel
 *
 *  Created by Андрей Куницын on 08.03.10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef GHL_OPENGL_H
#define GHL_OPENGL_H

#include "ghl_api.h"

#if defined( GHL_PLATFORM_IOS )
#include "dynamic/dynamic_gles.h"
#define GHL_OPENGLES
#elif defined ( GHL_PLATFORM_ANDROID )
#include "dynamic/dynamic_gles.h"
#define GHL_OPENGLES
#elif defined ( GHL_PLATFORM_MAC )
#include "dynamic/dynamic_gl.h"
#elif defined ( GHL_PLATFORM_WIN )
#include "dynamic/dynamic_gl.h"
#elif defined ( GHL_PLATFORM_LINUX )
#include "dynamic/dynamic_gl.h"
#else
#error "Unsupported platform"
#endif

#ifdef GHL_QT
#endif

#ifdef GHL_OPENGLES

#define GHL_SHADERS_UNSUPPORTED
#define glOrtho glOrthof

#ifndef GL_SOURCE0_RGB
#define GL_SOURCE0_RGB GL_SRC0_RGB
#endif
#ifndef GL_SOURCE0_ALPHA
#define GL_SOURCE0_ALPHA GL_SRC0_ALPHA
#endif

#ifndef GL_SOURCE1_RGB
#define GL_SOURCE1_RGB GL_SRC1_RGB
#endif
#ifndef GL_SOURCE1_ALPHA
#define GL_SOURCE1_ALPHA GL_SRC1_ALPHA
#endif

#ifndef GL_SOURCE2_RGB
#define GL_SOURCE2_RGB GL_SRC2_RGB
#endif
#ifndef GL_SOURCE2_ALPHA
#define GL_SOURCE2_ALPHA GL_SRC2_ALPHA
#endif

#endif

#endif /*GHL_OPENGL_H*/
