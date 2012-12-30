/*
 *  tga_image_decoder.h
 *  SR
 *
 *  Created by Андрей Куницын on 04.02.11.
 *  Copyright 2011 andryblack. All rights reserved.
 *
 */
#ifndef TGA_IMAGE_DECODER_H
#define TGA_IMAGE_DECODER_H

#include "image_file_decoder.h"

namespace GHL {

	struct TGAHeader;
	class ImageImpl;
	
	class TGAImageDecoder : public ImageFileDecoder
	{
	private:
		bool LoadHeader(TGAHeader* header,DataStream* ds);
		bool LoadRLE(DataStream* ds,ImageImpl* img);
		bool LoadRAW(DataStream* ds,ImageImpl* img);
		bool SaveRAW32(DataStream* ds,const Image* img);
		bool SaveRLE32(DataStream* ds,const Image* img);
	public:
		TGAImageDecoder() : ImageFileDecoder(IMAGE_FILE_FORMAT_TGA) {}
		virtual ~TGAImageDecoder() {}
		virtual Image* Decode(DataStream* ds) ;
		virtual bool Encode( const Image* image, DataStream* ds);
        virtual ImageFileFormat GetFileFormat( const CheckBuffer& ) const;
	};
	
}


#endif /*TGA_IMAGE_DECODER_H*/