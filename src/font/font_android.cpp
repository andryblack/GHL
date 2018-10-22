#include "font_android.h"
#include "../ghl_log_impl.h"
#include "../image/image_impl.h"

#include <android/bitmap.h>

namespace GHL {

	static const char* MODULE = "SystemFont";

	static bool check_exception(JNIEnv* env,const char* text) {
		if (env->ExceptionCheck()) {
            LOG_ERROR(text);
           	env->ExceptionDescribe();
            env->ExceptionClear();
            return true;
        }
        return false;
	}

	FontAndroid::FontAndroid( const FontConfig& config , jobject java, JNIEnv* env) : FontImpl(config),m_env(env) {
		m_java = env->NewGlobalRef(java);
		jclass clazz = env->GetObjectClass(m_java);
		jmethodID setSize = env->GetMethodID(clazz,"setSize","(FF)V");
        if (check_exception(env,"failed find setSize")) {
        	return;
        }
        env->CallVoidMethod(m_java,setSize,GetSize(),get_config().xscale);
        m_render_glyph = env->GetMethodID(clazz,"renderGlyph","(IZ)Z");
        m_get_bitmap = env->GetMethodID(clazz,"getBitmap","()Landroid/graphics/Bitmap;");
        m_get_bounds = env->GetMethodID(clazz,"getBounds","()Landroid/graphics/Rect;");
        m_get_x = env->GetMethodID(clazz,"getX","()I");
        m_get_y = env->GetMethodID(clazz,"getY","()I");
        m_get_w = env->GetMethodID(clazz,"getW","()I");
        m_get_h = env->GetMethodID(clazz,"getH","()I");
        m_get_advance = env->GetMethodID(clazz,"getAdvance","()F");
        jmethodID getAscent = env->GetMethodID(clazz,"getAscent","()I");
        m_ascent = env->CallIntMethod(m_java,getAscent);
        jmethodID getDescent = env->GetMethodID(clazz,"getDescent","()I");
        m_descent = env->CallIntMethod(m_java,getDescent);
        if (get_config().outline_width != 0.0f) {
        	jmethodID setOutline = env->GetMethodID(clazz,"setOutline","(F)V");
        	m_env->CallVoidMethod(m_java,setOutline,get_config().outline_width);
        }
        env->DeleteLocalRef(clazz);
	}

	FontAndroid::~FontAndroid() {
		m_env->DeleteGlobalRef(m_java);
	}


	float GHL_CALL FontAndroid::GetAscender() const {
		return m_ascent;
	}
   	float GHL_CALL FontAndroid::GetDescender() const {
   		return m_descent;
   	}

   	bool GHL_CALL FontAndroid::RenderGlyph( UInt32 ch, Glyph* g ) {
   		jboolean res = m_env->CallBooleanMethod(m_java,m_render_glyph,jint(ch),is_emoji(ch)?JNI_FALSE:JNI_TRUE);
   		if (!res) return false;
   		jobject bm = m_env->CallObjectMethod(m_java,m_get_bitmap);
   		AndroidBitmapInfo info;
   		if (AndroidBitmap_getInfo(m_env,bm,&info)!= ANDROID_BITMAP_RESULT_SUCCESS) {
   			return false;
   		}
   		void* addr = 0;
   		if (AndroidBitmap_lockPixels(m_env,bm,&addr) != ANDROID_BITMAP_RESULT_SUCCESS) {
   			return false;
   		}

   		int hsx = m_env->CallIntMethod(m_java,m_get_x);
		int hsy = m_env->CallIntMethod(m_java,m_get_y);
   		int w = m_env->CallIntMethod(m_java,m_get_w);
   		int h = m_env->CallIntMethod(m_java,m_get_h);


   		g->x = hsx;
   		g->y = hsy;
   		g->advance = m_env->CallFloatMethod(m_java,m_get_advance);

   		ImageImpl* img = new ImageImpl(w,h, info.format == ANDROID_BITMAP_FORMAT_A_8 ? IMAGE_FORMAT_GRAY : IMAGE_FORMAT_RGBA);
   		img->Fill(0);
   		const Byte* src = static_cast<Byte*>(addr);
   		for (int y=0;y<h;++y) {
   			const Byte* s = src + info.stride * y;
   			Byte* d = img->GetData()->GetDataPtr() + (y * img->GetWidth() ) * img->GetBpp();
   			memcpy(d,s,img->GetWidth()*img->GetBpp());
   		}
   		g->bitmap = img;

   		AndroidBitmap_unlockPixels(m_env,bm);
   		m_env->DeleteLocalRef(bm);
   		return true;
   	}




	FontAndroid* FontAndroid::Create(const FontConfig* config, JNIEnv* env, jobject java) {
		if (!config) return 0;
		FontAndroid* res = new FontAndroid(*config,java,env);
        return res;
	}

}