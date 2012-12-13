/*
    GHL - Game Helpers Library
    Copyright (C)  Andrey Kunitsyn 2009

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    Andrey (AndryBlack) Kunitsyn
    blackicebox (at) gmail (dot) com
*/

#ifndef GHL_API_H
#define GHL_API_H



#if defined( __APPLE__ )
#ifndef GHL_PLATFORM_IOS
#ifndef GHL_PLATFORM_MAC
#define GHL_PLATFORM_MAC
#endif
#endif
#elif defined( WIN32 )
#define GHL_PLATFORM_WIN
#elif defined( ANDROID )
#define GHL_PLATFORM_ANDROID
#elif defined( __linux__ )
#define GHL_PLATFORM_LINUX
#elif defined( __FLASHPLAYER__ )
#define GHL_PLATFORM_FLASH
#else 
#error "unknown platform"
#endif

#ifdef MONOLITIC_APPLICATION
////
////
#define GHL_CALL
#define GHL_API


#else /*!MONOLITIC_APPLICATION*/


/// dll configuration
#ifdef GHL_PLATFORM_WIN
#define GHL_CALL	__stdcall
#if defined(GHL_DLL_SOURCE)
#define GHL_API extern "C" __declspec(dllexport)
#else
#define GHL_API extern "C" __declspec(dllimport)
#endif
#else
#define GHL_API extern "C"
#endif

#endif /*MONOLITIC_APPLICATION*/

#define GHL_UNUSED(arg) (void)arg

#ifndef GHL_CALL
#define GHL_CALL
#endif
#ifndef GHL_API 
#define GHL_API extern "C"
#endif

#endif /*GHL_API_H*/
