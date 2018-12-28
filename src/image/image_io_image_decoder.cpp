#include "ghl_image_config.h"
#ifdef USE_IPHONE_IMAGE_DECODER
#include <CoreGraphics/CoreGraphics.h>

#include "image_io_image_decoder.h"
#include "jpeg_image_decoder.h"
#include "image_impl.h"

namespace GHL {

    ImageIOImageDecoder::ImageIOImageDecoder() : GHL::ImageFileDecoder(IMAGE_FILE_FORMAT_JPEG) {
        
    }
    
    ImageIOImageDecoder::~ImageIOImageDecoder() {
        
    }
    
    
    void release_data_callback(void * __nullable info,
                                              const void *  data, size_t size) {
        GHL::Data* datap = static_cast<GHL::Data*>(info);
        datap->Release();
    }

    
    Image* ImageIOImageDecoder::Decode(DataStream* ds) {
        if (!ds) return 0;
        GHL::Data* data = GHL_ReadAllData(ds);
        
        CGDataProviderRef provider = CGDataProviderCreateWithData(data,
                                                                  data->GetData(),
                                                                  data->GetSize(),
                                                                &release_data_callback);
        
        CGImageRef img =
            CGImageCreateWithJPEGDataProvider(provider, nil, FALSE, kCGRenderingIntentDefault);
    
        
        CGDataProviderRelease(provider);
        if (!img)
            return NULL;
        
        UInt32 imageWidth = UInt32(CGImageGetWidth( img ));
        UInt32 imageHeight = UInt32(CGImageGetHeight( img ));
        ImageFormat format = IMAGE_FORMAT_GRAY;
        UInt32 bpp = 1;
        if ( CGImageGetBitsPerPixel(img) == 24 ) {
            bpp = 3;
            format = IMAGE_FORMAT_RGB;
        } else if ( CGImageGetBitsPerPixel(img) == 32 ) {
            bpp = 4;
            format = IMAGE_FORMAT_RGBX;
        }
        ImageImpl* res = new ImageImpl( imageWidth, imageHeight, format );
                                       
        // Get pixel data
        CFDataRef pdata = CGDataProviderCopyData( CGImageGetDataProvider( img ) );
        if (pdata) {
            CFRange range = CFRangeMake( 0, imageWidth*imageHeight*bpp );
            CFDataGetBytes(pdata, range , res->GetData()->GetDataPtr());
            CFRelease(pdata);
        }
        CGImageRelease(img);
        return res;
    }
    
    const Data* ImageIOImageDecoder::Encode( const Image* image) {
        return 0;
    }
   

    ImageFileFormat ImageIOImageDecoder::GetFileFormat(const CheckBuffer& buf) const {
        return JpegDecoder::GetJpegFileFormat(buf) ? GHL::IMAGE_FILE_FORMAT_JPEG : ImageFileDecoder::GetFileFormat(buf);
    }
    
    
   
    
    
    bool ImageIOImageDecoder::GetFileInfo(DataStream* ds, ImageInfo* info) {
        return JpegDecoder::GetJpegFileInfo(ds, info);
    }
    
    
}

#endif

