/*
 *  ghl_openal.h
 *  SR
 *
 *  Created by Андрей Куницын on 27.02.11.
 *  Copyright 2011 andryblack. All rights reserved.
 *
 */

#ifndef GHL_OPENAL_H
#define GHL_OPENAL_H

#include <ghl_api.h>

#ifdef GHL_PLATFORM_MAC

#include <OpenAL/al.h>
#include <OpenAL/alc.h>

#endif

#if defined( GHL_PLATFORM_IOS) || defined( GHL_PLATFORM_TVOS )

#include <OpenAL/al.h>
#include <OpenAL/alc.h>

#endif

#endif /*GHL_OPENAL_H*/