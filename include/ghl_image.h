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

#ifndef GHL_IMAGE_H
#define GHL_IMAGE_H

#include "ghl_types.h"
#include "ghl_api.h"
#include "ghl_ref_counter.h"
#include "ghl_data.h"

namespace GHL
{

    /// image color format
    enum ImageFormat
    {
        IMAGE_FORMAT_UNKNOWN,   ///< unknown
        IMAGE_FORMAT_GRAY,		///< grayscale
        IMAGE_FORMAT_RGB,		///< r,g,b channels
        IMAGE_FORMAT_RGBA,		///< r,g,b,alpha channels
		IMAGE_FORMAT_PVRTC_2,	///< compressed format PVRTC_2
		IMAGE_FORMAT_PVRTC_4	///< compressed format PVRTC_4
    };

    /// image object interface
    struct Image : RefCounter
    {
        /// get image width
        virtual UInt32 GHL_CALL GetWidth() const = 0;
        /// get image height
        virtual UInt32 GHL_CALL GetHeight() const = 0;
        /// get image format
        virtual ImageFormat GHL_CALL GetFormat() const = 0;
        /// get image data
        virtual const Data* GHL_CALL GetData() const = 0;
		/// convert image to format
        virtual bool GHL_CALL Convert(ImageFormat fmt) = 0;
        /// fill image with specified color
        virtual void GHL_CALL Fill(UInt32 clr) = 0;
        /// swap RB channels
        virtual bool GHL_CALL SwapRB() = 0;
        /// set alpha from another image
        /**
         * @arg img image with format IMAGE_FORMAT_GRAY or IMAGE_FORMAT_RGBA
         */
        virtual bool GHL_CALL SetAlpha(const Image* img) = 0;
        /// create sub image
        virtual Image* GHL_CALL SubImage(UInt32 x,UInt32 y,UInt32 w,UInt32 h) const = 0;
        /// clone image
        virtual Image* GHL_CALL Clone() const = 0;
    };

} /*namespace*/

GHL_API GHL::Image* GHL_CALL GHL_CreateImage( GHL::UInt32 w, GHL::UInt32 h,GHL::ImageFormat fmt);
GHL_API GHL::Image* GHL_CALL GHL_CreateImageWithData( GHL::UInt32 w, GHL::UInt32 h,GHL::ImageFormat fmt,const GHL::Byte* data);

#endif /*GHL_IMAGE_H*/
