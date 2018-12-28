//
//  stb_image_decoder.h
//  fishes
//
//  Created by Андрей Куницын on 27.11.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef fishes_stb_image_decoder_h
#define fishes_stb_image_decoder_h

#include "image_file_decoder.h"

namespace GHL {
    
    class JpegDecoder : public ImageFileDecoder
    {
	public:
		JpegDecoder();
		~JpegDecoder();
		Image* Decode(DataStream* ds);
		const Data* Encode( const Image* image);
		virtual ImageFileFormat GetFileFormat(const CheckBuffer&) const;
        virtual bool GetFileInfo(DataStream* ds, ImageInfo* info);
        static const Data* ReEncode(GHL::DataStream* src);
        static bool GetJpegFileFormat(const CheckBuffer& buf);
        static bool GetJpegFileInfo(DataStream* ds, ImageInfo* info);
    };
    
}/*namespace*/


#endif
