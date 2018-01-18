#include "ghl_image_config.h"
#ifdef USE_IPHONE_IMAGE_DECODER
#include <CoreGraphics/CoreGraphics.h>

#include "image_io_image_decoder.h"
#include "image_impl.h"

namespace GHL {

    ImageIOImageDecoder::ImageIOImageDecoder() : GHL::ImageFileDecoder(IMAGE_FILE_FORMAT_JPEG) {
        
    }
    
    ImageIOImageDecoder::~ImageIOImageDecoder() {
        
    }
    
    static size_t dp_getBytes(void * __nullable info,
                                                    void *  buffer, size_t count) {
        DataStream* ds = static_cast<DataStream*>(info);
        return ds->Read(static_cast<Byte*>(buffer), UInt32(count));
    }
    
    static off_t dp_skipForward(void * __nullable info,
                                               off_t count) {
        DataStream* ds = static_cast<DataStream*>(info);
        if (ds->Seek(Int32(count), F_SEEK_CURRENT))
            return count;
        return 0;
    }
    
    static void dp_rewind(void * __nullable info) {
        DataStream* ds = static_cast<DataStream*>(info);
        ds->Seek(0, F_SEEK_BEGIN);
    }
    
    static void dp_releaseInfo(void * __nullable info) {
        DataStream* ds = static_cast<DataStream*>(info);
        ds->Release();
    }
    
    static CGDataProviderSequentialCallbacks data_provider_callbacks = {
        0,
        &dp_getBytes,
        &dp_skipForward,
        &dp_rewind,
        &dp_releaseInfo
    };
    
    
    
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
    
    const Data* ImageIOImageDecoder::Encode( const Image* image,Int32 settings) {
        return 0;
    }
    ImageFileFormat ImageIOImageDecoder::GetFileFormat(const CheckBuffer& buf) const {
        for ( size_t i=0; i<sizeof(CheckBuffer);++i) {
            if (buf[i]!=0xff) {
                if( buf[i]==0xd8 && i!=0 )
                    return IMAGE_FILE_FORMAT_JPEG;
                break;
            }
        }
        return ImageFileDecoder::GetFileFormat(buf);
    }
    bool ImageIOImageDecoder::GetFileInfo(DataStream* ds, ImageInfo* info) {
        if (!ds) return 0;
        ds->AddRef();
        CGDataProviderRef provider = CGDataProviderCreateSequential(ds, &data_provider_callbacks);
        
        CGImageRef img =
        CGImageCreateWithJPEGDataProvider(provider, nil, FALSE, kCGRenderingIntentDefault);
        
        CGDataProviderRelease(provider);
        if (!img)
            return false;
        info->file_format = IMAGE_FILE_FORMAT_JPEG;
        info->width = UInt32(CGImageGetWidth(img));
        info->height = UInt32(CGImageGetHeight(img));
        if (CGImageGetBitsPerPixel(img) == 24)
            info->image_format = IMAGE_FORMAT_RGB;
        else if (CGImageGetBitsPerPixel(img) == 32)
            info->image_format = IMAGE_FORMAT_RGB;
        else if (CGImageGetBitsPerPixel(img) == 8)
            info->image_format = IMAGE_FORMAT_GRAY;
        CGImageRelease(img);
        return true;
    }
    
    
}

#endif

