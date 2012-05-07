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
		bool Encode( const Image* image, DataStream* ds);
		virtual ImageFileFormat GetFileFormat(const CheckBuffer&) const;
    };
    
}/*namespace*/


#endif
