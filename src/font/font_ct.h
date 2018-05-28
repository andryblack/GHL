#ifndef FONT_CT_H
#define FONT_CT_H

#include "font_impl.h"

#include <CoreText/CoreText.h>

namespace GHL {
    
    
    class FontCT : public FontImpl {
    private:
        CTFontRef m_font;
        CFDictionaryRef m_attributes;
        CGColorSpaceRef m_colorspace;
        CFDictionaryRef m_attributes_gray;
        CGColorSpaceRef m_colorspace_gray;
    protected:
        FontCT(const FontConfig& config );
        bool Init();
    public:
        ~FontCT();
        static FontCT* Create( const FontConfig* config );
        
        virtual float GHL_CALL GetAscender() const;
        virtual float GHL_CALL GetDescender() const;
        
        virtual bool GHL_CALL RenderGlyph( UInt32 ch, Glyph* g );
    };
    
}

#endif /*FONT_CT_H*/
