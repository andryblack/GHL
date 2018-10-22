/*
 GHL - Game Helpers Library
 Copyright (C)  Andrey Kunitsyn 2018
 
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

#ifndef GHL_FONT_H
#define GHL_FONT_H

#include "ghl_ref_counter.h"
#include "ghl_types.h"

namespace GHL {
    
    struct Image;
    
    struct Glyph {
        float x;
        float y;
        float advance;
        Image* bitmap;
    };
    
    struct Font : RefCounter
    {
        virtual const char* GHL_CALL GetName() const = 0;
        virtual float GHL_CALL GetSize() const = 0;
        virtual bool GHL_CALL RenderGlyph( UInt32 ch, Glyph* g ) = 0;
        virtual float GHL_CALL GetAscender() const = 0;
        virtual float GHL_CALL GetDescender() const = 0;
    };
    
}

#endif /*GHL_FONT_H*/
