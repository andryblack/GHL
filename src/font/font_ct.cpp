#include "font_ct.h"
#include "../image/image_impl.h"
#include "../ghl_log_impl.h"

#include <CoreGraphics/CoreGraphics.h>

static const char* MODULE = "fnt";

namespace GHL {
    FontCT::FontCT(const FontConfig& config) : FontImpl(config),
        m_font(0),m_attributes(0),m_colorspace(0),
        m_attributes_gray(0),m_colorspace_gray(0) {
        
    }
    
    FontCT::~FontCT() {
        if (m_font) {
            CFRelease(m_font);
        }
        if (m_attributes) {
            CFRelease(m_attributes);
        }
        if (m_attributes_gray) {
            CFRelease(m_attributes_gray);
        }
        if (m_colorspace) {
            CFRelease(m_colorspace);
        }
        if (m_colorspace_gray) {
            CFRelease(m_colorspace_gray);
        }
    }
    
    static void _BitmapContextReleaseDataCallback(void *releaseInfo, void *data) {
        static_cast<GHL::ImageImpl*>(releaseInfo)->Release();
    }
    
    bool GHL_CALL FontCT::RenderGlyph( UInt32 ch, Glyph* g ) {
        bool is_emoji = this->is_emoji(ch);
        UniChar chars[2] = {
            UniChar(ch),
            UniChar(0)
        };
        CFIndex nchars = 1;
        if (CFStringGetSurrogatePairForLongCharacter(ch,chars)) {
            nchars = 2;
        }
        CFStringRef str = CFStringCreateWithCharacters(0, chars, nchars);
        CFAttributedStringRef string = CFAttributedStringCreate(0, str, is_emoji ? m_attributes : m_attributes_gray);
        CFRelease(str);
        
        CTLineRef line = CTLineCreateWithAttributedString(string);
        CFRelease(string);
        
        CGRect bounds = CTLineGetBoundsWithOptions(line,
                                                   kCTLineBoundsExcludeTypographicShifts |
                                                   kCTLineBoundsExcludeTypographicLeading |
                                                   kCTLineBoundsUseOpticalBounds );
        Int32 width = bounds.size.width;
        Int32 height = bounds.size.height;
        
        if (width < 1) width = 1;
        if (height < 1) height = 1;
        
        Int32 add_size = int(get_config().outline_width+0.5);
        
        CGPoint position = CGPointMake(
                                -bounds.origin.x+add_size,
                                -bounds.origin.y+add_size);
        
        g->x = -bounds.origin.x + add_size;
        g->y = (bounds.size.height+bounds.origin.y) + add_size;
        
        ImageImpl* img = new ImageImpl(width+add_size*2,height+add_size*2,is_emoji?IMAGE_FORMAT_RGBA:IMAGE_FORMAT_GRAY);
        img->Fill(0);
        
        img->AddRef();
        CGContextRef ctx = CGBitmapContextCreateWithData(img->GetData()->GetDataPtr(), width+add_size*2, height+add_size*2, 8,
                                                         (width+add_size*2)*(is_emoji?4:1), is_emoji ? m_colorspace : m_colorspace_gray,
                                                         is_emoji?(kCGBitmapByteOrder32Big|kCGImageAlphaPremultipliedLast):
                                                         (kCGImageAlphaOnly),
                                                                 &_BitmapContextReleaseDataCallback,img);
        
        
        if (!ctx) {
            img->Release();
            return false;
        }
        if (get_config().outline_width == 0.0f) {
            CGContextSetTextDrawingMode(ctx, kCGTextFill);
        } else {
            CGContextSetTextDrawingMode(ctx, kCGTextStroke);
            CGContextSetGrayStrokeColor(ctx, 1, 1);
            CGContextSetLineWidth(ctx, get_config().outline_width * 2);
        }
        CGContextSetShouldSubpixelPositionFonts(ctx,false);
        CGContextSetTextPosition(ctx, position.x, position.y);
        CTLineDraw(line, ctx);
        
        g->advance = CGContextGetTextPosition(ctx).x - position.x;
        
        CGContextFlush(ctx);
        CFRelease(line);
        CGContextRelease(ctx);

        g->bitmap = img;
  
        return true;
    }
    
    
    bool FontCT::Init() {
        
        m_colorspace = CGColorSpaceCreateDeviceRGB();
        m_colorspace_gray = CGColorSpaceCreateDeviceGray();
        if (strcmp(GetName(),"System")==0) {
            m_font = CTFontCreateUIFontForLanguage(kCTFontUIFontSystem, GetSize(), 0);
        } else if (strcmp(GetName(),"Message")==0) {
            m_font = CTFontCreateUIFontForLanguage(kCTFontUIFontMessage, GetSize(), 0);
        } else {
            bool need_transform = false;
            CGAffineTransform tr = CGAffineTransformIdentity;
            if (get_config().xscale != 1.0f) {
                tr = CGAffineTransformScale(tr, get_config().xscale, 1.0);
            }
            CFStringRef name = CFStringCreateWithCString(0, GetName(), kCFStringEncodingUTF8);
            m_font = CTFontCreateWithName(name, GetSize(), need_transform ? &tr : 0);
            CFRelease(name);
        }
        if (!m_font) {
            LOG_ERROR("failed create font " << GetName());
            return false;
        }
        CGFloat comps[] = {1.0,1.0,1.0,1.0};
        CGColorRef fg_clr = CGColorCreate(m_colorspace,comps);
        const void* keys[] = {kCTFontAttributeName,kCTForegroundColorAttributeName,kCTStrokeColorAttributeName};
        const void* values[] = {m_font,fg_clr,fg_clr};
        m_attributes = CFDictionaryCreate(0, keys, values, 2,
                                                        &kCFCopyStringDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
        CFRelease(fg_clr);
        fg_clr = CGColorCreate(m_colorspace_gray,comps);
        {
            const void* keys[] = {kCTFontAttributeName,kCTForegroundColorAttributeName,kCTStrokeColorAttributeName};
            const void* values[] = {m_font,fg_clr,fg_clr};
            m_attributes_gray = CFDictionaryCreate(0, keys, values, 2,
                                              &kCFCopyStringDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
        }
        CFRelease(fg_clr);
        return true;
    }
    
    float GHL_CALL FontCT::GetAscender() const {
        return CTFontGetAscent(m_font);
    }
    float GHL_CALL FontCT::GetDescender() const {
        return CTFontGetDescent(m_font);
    }
    
    FontCT* FontCT::Create( const FontConfig* config ) {
        if (!config) return 0;
        FontCT* r = new FontCT( *config);
        if (!r->Init()) {
            r->Release();
            r = 0;
        }
        return r;
    }
}
