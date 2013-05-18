/*
 GHL - Game Helpers Library
 Copyright (C)  Andrey Kunitsyn 2011
 
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

#include "pvrtc_image_decoder.h"
#include "../ghl_data_impl.h"
#include "image_impl.h"

namespace GHL {
	
	
	struct PVRTexHeader
	{
		UInt32 headerLength;
		UInt32 height;
		UInt32 width;
		UInt32 numMipmaps;
		UInt32 flags;
		UInt32 dataLength;
		UInt32 bpp;
		UInt32 bitmaskRed;
		UInt32 bitmaskGreen;
		UInt32 bitmaskBlue;
		UInt32 bitmaskAlpha;
		Byte	pvrTag[4];
		UInt32 numSurfs;
	};
	static const Byte gPVRTexIdentifier[4] = {'P','V','R','!'};
	static const UInt32 gPVRTexIdentifierOffset = 4*11;
	static const UInt32 PVR_TEXTURE_FLAG_TYPE_MASK = 0xff;
	
	enum
	{
		kPVRTextureFlagTypePVRTC_2 = 24,
		kPVRTextureFlagTypePVRTC_4
	};
	
	PVRTCDecoder::PVRTCDecoder() : ImageFileDecoder( IMAGE_FILE_FORMAT_PVRTC ) {
		
	}
	
	PVRTCDecoder::~PVRTCDecoder() {
		
	}
	
    bool PVRTCDecoder::GetFileInfo(DataStream* ds, ImageInfo* info) {
        PVRTexHeader header;
		if ( ds->Read((Byte*)&header, sizeof(header))!=sizeof(header) )
			return false;
        if ( header.pvrTag[0] != gPVRTexIdentifier[0] ||
			header.pvrTag[1] != gPVRTexIdentifier[1] ||
			header.pvrTag[2] != gPVRTexIdentifier[2] ||
			header.pvrTag[3] != gPVRTexIdentifier[3] )
			return false;
        
        UInt32 formatFlags = SwapLittleToHost(header.flags) & PVR_TEXTURE_FLAG_TYPE_MASK;
		if ( formatFlags == kPVRTextureFlagTypePVRTC_2 ) {
            info->image_format = IMAGE_FORMAT_PVRTC_4;
        } else if ( formatFlags == kPVRTextureFlagTypePVRTC_4 ) {
			info->image_format = IMAGE_FORMAT_PVRTC_4;
		} else
            return false;
        
        info->width = header.width;
        info->height = header.height;
        return true;
    }
    
	Image* PVRTCDecoder::Decode(DataStream* ds) {
		PVRTexHeader header;
		if (!ds) return 0;
		if ( ds->Read((Byte*)&header, sizeof(header))!=sizeof(header) )
			return 0;
		if ( header.pvrTag[0] != gPVRTexIdentifier[0] ||
			header.pvrTag[1] != gPVRTexIdentifier[1] ||
			header.pvrTag[2] != gPVRTexIdentifier[2] ||
			header.pvrTag[3] != gPVRTexIdentifier[3] )
			return 0;
		/// @todo swap bytes ordering
		UInt32 formatFlags = SwapLittleToHost(header.flags) & PVR_TEXTURE_FLAG_TYPE_MASK;
		if ( formatFlags != kPVRTextureFlagTypePVRTC_2 &&
			formatFlags != kPVRTextureFlagTypePVRTC_4 ) {
			return 0;
		}
		//bool haveAlpha = SwapLittleToHost(header.bitmaskAlpha);
		UInt32 width = SwapLittleToHost(header.width);
		UInt32 height = SwapLittleToHost(header.height);
		UInt32 dataLength = SwapLittleToHost(header.dataLength);
		
		UInt32 blockSize = 0;
		UInt32 widthBlocks = 0;
		UInt32 heightBlocks = 0;
		UInt32 bpp = 0;
		ImageFormat format;
		if (formatFlags == kPVRTextureFlagTypePVRTC_4)
		{
			blockSize = 4 * 4; // Pixel by pixel block size for 4bpp
			widthBlocks = width / 4;
			heightBlocks = height / 4;
			bpp = 4;
			format = IMAGE_FORMAT_PVRTC_4;
		}
		else
		{
			blockSize = 8 * 4; // Pixel by pixel block size for 2bpp
			widthBlocks = width / 8;
			heightBlocks = height / 4;
			bpp = 2;
			format = IMAGE_FORMAT_PVRTC_2;
		} 
		
		// Clamp to minimum number of blocks
		if (widthBlocks < 2)
			widthBlocks = 2;
		if (heightBlocks < 2)
			heightBlocks = 2;
		
		UInt32 dataSize = widthBlocks * heightBlocks * ((blockSize  * bpp) / 8);
		if ( dataSize < dataLength ) return 0;
		DataImpl* buffer = new DataImpl( dataSize );
		if ( ds->Read(buffer->GetDataPtr(), dataSize )!=dataSize ) {
			buffer->Release();
			return 0;
		}
		return new ImageImpl(width,height,format,buffer);
	}
	
	ImageFileFormat PVRTCDecoder::GetFileFormat(const CheckBuffer& buf) const {
		if ( sizeof(buf) <= (gPVRTexIdentifierOffset+4)) {
			if ( buf[gPVRTexIdentifierOffset+0]==gPVRTexIdentifier[0] &&
				buf[gPVRTexIdentifierOffset+1]==gPVRTexIdentifier[1] &&
				buf[gPVRTexIdentifierOffset+2]==gPVRTexIdentifier[2] &&
				buf[gPVRTexIdentifierOffset+3]==gPVRTexIdentifier[3] ) {
				return IMAGE_FILE_FORMAT_PVRTC;
			}
		}
		return ImageFileDecoder::GetFileFormat( buf );
	}
}
