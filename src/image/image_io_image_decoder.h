#ifndef image_io_image_decoder_h
#define image_io_image_decoder_h

#include "image_file_decoder.h"

namespace GHL {
    
    class ImageIOImageDecoder : public ImageFileDecoder
    {
    public:
        ImageIOImageDecoder();
        ~ImageIOImageDecoder();
        Image* Decode(DataStream* ds);
        const Data* Encode( const Image* image,Int32 settings);
        virtual ImageFileFormat GetFileFormat(const CheckBuffer&) const;
        virtual bool GetFileInfo(DataStream* ds, ImageInfo* info);
    };
    
}/*namespace*/


#endif /*image_io_image_decoder_h*/
