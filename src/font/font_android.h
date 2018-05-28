#ifndef FONT_ANDROID_H
#define FONT_ANDROID_H

#include "font_impl.h"

#include <jni.h>

namespace GHL {
    
    
    class FontAndroid : public FontImpl {
    private:
        jobject m_java;
        JNIEnv* m_env;
        jmethodID   m_render_glyph;
        jmethodID   m_get_bitmap;
        jmethodID   m_get_bounds;
        jmethodID   m_get_x;
        jmethodID   m_get_y;
        jmethodID   m_get_w;
        jmethodID   m_get_h;
        jmethodID   m_get_advance;
        float m_ascent;
        float m_descent;
    protected:
        FontAndroid(const FontConfig& config , jobject java, JNIEnv* env );
        bool Init();
    public:
        ~FontAndroid();
        static FontAndroid* Create( const FontConfig* config, JNIEnv* env , jobject java);
        
        virtual float GHL_CALL GetAscender() const;
        virtual float GHL_CALL GetDescender() const;
        
        virtual bool GHL_CALL RenderGlyph( UInt32 ch, Glyph* g );
    };
    
}

#endif /*FONT_ANDROID_H*/
