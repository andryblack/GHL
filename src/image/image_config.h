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

#ifndef IMAGE_CONFIG_H
#define IMAGE_CONFIG_H

#include "ghl_api.h"

#define USE_TGA_IMAGE_DECODER

#if defined( GHL_QT )
#define USE_QT_IMAGE_DECODER
#elif defined( GHL_PLATFORM_IPHONE )
//#define USE_IPHONE_IMAGE_DECODER
//#define USE_PNG_DECODER
//#define USE_JPEG_DECODER
#else
//#define USE_PNG_DECODER
//#define USE_JPEG_DECODER
#endif
#endif /*IMAGE_COFIG_H*/
