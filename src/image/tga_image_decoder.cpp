/*
 *  tga_image_decoder.cpp
 *  SR
 *
 *  Created by Андрей Куницын on 04.02.11.
 *  Copyright 2011 andryblack. All rights reserved.
 *
 */


#include "tga_image_decoder.h"
#include <ghl_data_stream.h>
#include "image_impl.h"
#include <cassert>

namespace GHL {

    // byte-align structures
#if defined(_MSC_VER) ||  defined(__BORLANDC__) || defined (__BCPLUSPLUS__)
#	pragma pack( push, packing )
#	pragma pack( 1 )
#	define PACK_STRUCT
#elif defined(__MINGW32__) || defined(__MINGW64__)
   _Pragma("pack(push,1)")
#   define PACK_STRUCT
#elif defined(__GNUC__) || defined(__clang__)
#	define PACK_STRUCT	__attribute__((packed))
#else
#   error "unknown compilator need pack structure"
#	define PACK_STRUCT
#endif


    struct TGAHeader
    {
        unsigned char idlength; //0: Size of Image-ID-Area
        unsigned char colourmaptype; //1: 0=no palette ; 1=palette present
        unsigned char datatypecode; //2: 0 - No IMage Date Included
        //   1 - Uncompressed Paletted Image
        //   2 - Uncompressed True Color
        //   3 - Uncompressed Black-White
        // 8+1 - RLE          Paletted Image
        // 8+2 - RLE          True Color
        // 8+3 - RLE          Black-White
        unsigned short int colourmaporigin; //3:
        unsigned short int colourmaplength; //5: Number of palette entries
        unsigned char colourmapdepth; //7: Bits per entry. Typicaly: 15,16,24,32
        unsigned short int x_origin; //8:
        unsigned short int y_origin; //10: Position coordinates on a display device
        unsigned short int width; //12:
        unsigned short int height; //14: Size of image in pixels
        unsigned char bitsperpixel; //16: Bits per pixel. Typicaly: 8,16,24,32
        unsigned char imagedescriptor; //17: 76-54-3210
        // NA-Orign-Alpha channel bits
    }PACK_STRUCT;

    // Default alignment
#if defined(_MSC_VER) ||  defined(__BORLANDC__) || defined (__BCPLUSPLUS__)
#	pragma pack( pop, packing )
#elif defined(__MINGW32__) || defined(__MINGW64__)
    _Pragma("pack(pop)")
#endif

    GHL_STATIC_ASSERT(sizeof(TGAHeader) == (18));

#undef PACK_STRUCT




    static Byte* copy_data(const Byte* from,Byte* to,UInt32 size) {
        while (size) { *to++=*from++;size--;}
        return to;
    }

    struct BufferedReader {
        Byte* buffer;
        DataStream* strm;
        UInt32 size;
        UInt32 readed;
        bool	eof;
        /*BufferedReader(DataStream* ds,UInt32 sz) {
            this->strm = ds;
        }
        UInt32 Read(Byte* to,UInt32 s)  { return strm->Read(to,s);}
        bool Eof() const { return strm->Eof();}
        */
        BufferedReader(DataStream* ds,UInt32 sz) {
            buffer = new Byte[sz];
            this->strm = ds;
            this->size = ds->Read(buffer,sz);
            readed = 0;
            eof = false;
        }
        ~BufferedReader() {
            delete [] buffer;
        }
        void LoadBuffer() {
            size = strm->Read(buffer,size);
            readed = 0;
            if (size==0 && strm->Eof())
                eof = true;
        }
        UInt32 Read(Byte* to,UInt32 s) {
            UInt32 rdd = 0;
            while (s && !eof) {
                if (readed==size)
                    LoadBuffer();
                UInt32 cpy = size - readed;
                if (cpy>s) cpy=s;
                if (cpy) ::memcpy(to+rdd,buffer+readed,cpy);
                s-=cpy;
                readed+=cpy;
                rdd+=cpy;
            }
            return rdd;
        }
        bool Eof() const { return eof;}

    };

    struct BufferedWriter {
        Byte* buffer;
        DataArrayImpl* strm;
        UInt32 size;
        UInt32 bufSize;
        BufferedWriter(DataArrayImpl* ds,UInt32 sz) {
            buffer = new Byte[sz];
            this->strm = ds;
            this->bufSize = 0;
            this->size = sz;
        }
        ~BufferedWriter() {
            FlushBuffer();
            delete [] buffer;
        }
        void FlushBuffer() {
            strm->append(buffer,bufSize);
            bufSize = 0;
        }
        UInt32 Write(const Byte* to,UInt32 s) {
            UInt32 rdd = 0;
            while (s) {
                if (bufSize==size)
                    FlushBuffer();
                UInt32 cpy = size - bufSize;
                if (cpy>s) cpy=s;
                if (cpy) ::memcpy(buffer+bufSize,to+rdd,cpy);
                s-=cpy;
                bufSize+=cpy;
                rdd+=cpy;
            }
            return rdd;
        }
    };

    bool TGAImageDecoder::LoadRLE(DataStream* ds,ImageImpl* img) {
        Byte* data = img->GetData()->GetDataPtr();
        UInt32 pixels = img->GetWidth()*img->GetHeight();
        const UInt32 bpp = img->GetBpp();
        UInt32 c = 0;
        BufferedReader rdr(ds,2048);
        while (pixels && !rdr.Eof()) {
            /// @todo warning endianless
            rdr.Read(reinterpret_cast<Byte*> (&c),1);
            if (c < 128) {
                c++;
                if (c>pixels) c = pixels;
                data+=rdr.Read(data,c*bpp);
                pixels -= c;
            } else {
                c-=127;
                if (c>pixels) c = pixels;
                Byte* data_c = data;
                data+=rdr.Read(data,bpp);
                for(UInt32 counter = 1; counter < c; counter++)
                {
                    data=copy_data(data_c,data,bpp);
                }
                pixels-= c;
            }
        }
        return pixels == 0;
    }
    bool TGAImageDecoder::SaveRAW32(DataArrayImpl* _ds,const Image* img) {
		const Data* buffer = img->GetData();
		if (!buffer) return false;
        const Byte* data = buffer->GetData();
        UInt32 pixels = img->GetWidth()*img->GetHeight();
        BufferedWriter ds(_ds,1024);
        for (size_t i=0;i<pixels;i++) {
            ds.Write(&data[2],1);
            ds.Write(&data[1],1);
            ds.Write(&data[0],1);
            ds.Write(&data[3],1);
            data+=4;
        }
        return true;
    }
    bool TGAImageDecoder::SaveRLE32(DataArrayImpl* _ds,const Image* img) {
        const Data* buffer = img->GetData();
		if (!buffer) return false;
        const Byte* data = buffer->GetData();
        UInt32 pixels = img->GetWidth()*img->GetHeight();
        BufferedWriter ds(_ds,1024);
        UInt32 line_pixels = img->GetWidth();
        while (pixels) {
            UInt32 serie = 1;
            for (size_t i=1;i<128;i++) {
                if (i>=pixels) break;
                if (i>=line_pixels) break;
                if ((data[i*4]!=data[0])||
                    (data[i*4+1]!=data[1]) ||
                    (data[i*4+2]!=data[2]) ||
                    (data[i*4+3]!=data[3])) break;
                serie++;
            }
            if (serie>=2) {
                Byte c = (serie+127);
                ds.Write(&c,1);
                ds.Write(data,4);
                pixels-=serie;
                line_pixels-=serie;
                data+=serie*4;
            } else {
                for (size_t i=1;i<128;i++) {
                    if (i>=pixels) {
                        break;
                    }
                    if (i>=line_pixels) break;
                    if ((data[i*4]==data[i*4-4])&&
                        (data[i*4+1]==data[i*4-3])&&
                        (data[i*4+2]==data[i*4-2])&&
                        (data[i*4+3]==data[i*4-1])) {
                        break;
                    }
                    serie++;
                }
                Byte c = ( Byte(serie-1) );
                assert(c<128);
                ds.Write(&c,1);
                for (size_t i=0;i<serie;i++) {
                    ds.Write(&data[2],1);
                    ds.Write(&data[1],1);
                    ds.Write(&data[0],1);
                    ds.Write(&data[3],1);
                    data+=4;
                }
                pixels-=serie;
                line_pixels-=serie;
            }
            if (line_pixels==0)
                line_pixels = img->GetWidth();
        }
        return true;
    }

    bool TGAImageDecoder::LoadRAW(DataStream* ds,ImageImpl* img) {
        UInt32 pixels = img->GetWidth()*img->GetHeight();
        const UInt32 bpp = img->GetBpp();
        Byte* data = img->GetData()->GetDataPtr();
        UInt32 readed = ds->Read(data,pixels*bpp);
        return readed == pixels*bpp;
    }
    
    static bool check_header(const TGAHeader* header) {
        /// @todo normalize endian
        
        if (header->colourmaptype)
            return false;
        /// support only True Color data
        if ( (header->datatypecode&7) != 2)
            return false;
        int bpp = header->bitsperpixel;
        /// support only 24,32 and 8 bpp
        if (bpp!=24 && bpp!=32 && bpp!=8)
            return false;
        return true;
    }

    bool TGAImageDecoder::LoadHeader(TGAHeader* header,DataStream* ds) {
        const size_t len = sizeof(TGAHeader);
        if (ds->Read(reinterpret_cast<Byte*>(header),len)!=len) return false;
        return check_header(header);
    }
    
    ImageFileFormat TGAImageDecoder::GetFileFormat( const CheckBuffer& cb) const {
        if (check_header(reinterpret_cast<const TGAHeader*>(&cb))) {
            return IMAGE_FILE_FORMAT_TGA;
        }
        return ImageFileDecoder::GetFileFormat(cb);
    }
    
    bool TGAImageDecoder::GetFileInfo(DataStream* ds, ImageInfo* info) {
        TGAHeader header;
        if (!LoadHeader(&header, ds)) return false;
        if (header.bitsperpixel==32)
            info->image_format = IMAGE_FORMAT_RGBA;
        else if(header.bitsperpixel==24)
            info->image_format = IMAGE_FORMAT_RGB;
        else if (header.bitsperpixel==8)
            info->image_format = IMAGE_FORMAT_GRAY;
        else
            return false;
        info->width = header.width;
        info->height = header.height;
        return true;
    }

    Image* TGAImageDecoder::Decode(DataStream* ds) {
        TGAHeader header;
        if (!LoadHeader(&header, ds)) return 0;
        ImageFormat fmt = IMAGE_FORMAT_UNKNOWN;
        if (header.bitsperpixel==32)
            fmt = IMAGE_FORMAT_RGBA;
        else if(header.bitsperpixel==24)
            fmt = IMAGE_FORMAT_RGB;
        else if (header.bitsperpixel==8)
            fmt = IMAGE_FORMAT_GRAY;

        bool rle = (header.datatypecode & 8)!=0;
        UInt32 width = header.width;
        UInt32 height = header.height;
        ImageImpl* img = new ImageImpl(width,height,fmt);
        bool res = rle ? LoadRLE(ds,img) : LoadRAW(ds,img);
        if (!res) {
            delete img;
            img = 0;
        } else {
            img->SwapChannelsRB();
            if ( (header.imagedescriptor & 0x20 ) == 0) {
                img->FlipV();
            }
        }
        return img;
    }

    const Data* TGAImageDecoder::Encode( const Image* image) {
        if (!image) return 0;
        
        if (image->GetFormat()==IMAGE_FORMAT_GRAY)
            return 0;
        TGAHeader header;
        header.idlength = 0;
        header.colourmaptype = 0;
        header.datatypecode = 8 + 2;
        header.colourmaporigin = 0;
        header.colourmaplength = 0;
        header.colourmapdepth = 0;
        header.x_origin = 0;
        header.y_origin = 0;
        header.width = image->GetWidth();
        header.height = image->GetHeight();
        if (image->GetFormat()==IMAGE_FORMAT_RGB) {
            header.bitsperpixel = 24;
            header.imagedescriptor = 0;
            /// @todo uniplemented
            return 0;
        } else if (image->GetFormat()==IMAGE_FORMAT_RGBA) {
            header.bitsperpixel = 32;
            header.imagedescriptor = 8 | 0x20;
        }
        DataArrayImpl* ds = new DataArrayImpl();
        ds->append(reinterpret_cast<const Byte*> (&header),sizeof(header));

        if (image->GetFormat()==IMAGE_FORMAT_RGBA) {
            //return SaveRAW32(ds,image);
            if (!SaveRLE32(ds,image)) {
                delete ds;
                return 0;
            }
        }
        return ds;
    }
}
