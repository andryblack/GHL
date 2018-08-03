#include <jni.h>
#include <android/log.h>
#include <android/input.h>
#include <android/native_activity.h>
#include <android/looper.h>
#include <android/keycodes.h>
#include <ghl_log.h>
#include <ghl_system.h>
#include <ghl_event.h>
#include <EGL/egl.h>
#include "../render/render_impl.h"
#include "ghl_application.h"
#include "../ghl_log_impl.h"
#include "../vfs/vfs_android.h"
#include "../image/image_decoders.h"
#include "../sound/android/ghl_sound_android.h"

#include <sys/time.h>
#include <pthread.h>
#include <errno.h>
#include "ghl_settings.h"
#include <unistd.h>
#include <sys/uio.h>
#include <cassert>
#include <cstdlib>

#include <sys/system_properties.h>

#define ANDROID_OS_BUILD_VERSION_RELEASE     "ro.build.version.release"          // * The user-visible version string. E.g., "1.0" or "3.4b5".
#define ANDROID_OS_BUILD_MODEL               "ro.product.model"                  // * The end-user-visible name for the end product..
#define ANDROID_OS_BUILD_MANUFACTURER        "ro.product.manufacturer"           // The manufacturer of the product/hardware.

static GHL::UInt32 g_main_thread_id = 0;
static GHL::Int32 g_frame_interval = 1;

JavaVM *g_jvm = 0;

static const char* MODULE = "WinLib";

static void check_main_thread() {
    if (g_main_thread_id != GHL_GetCurrentThreadId()) {
        LOG_ERROR("main thread expected");
    }
}
static char message_buffer[256];

GHL_API jstring GHL_CALL GHL_JNI_CreateStringUTF8(JNIEnv* env,const char* str);

static std::string get_string(JNIEnv* env,jstring str) {
    if (!str) return "";
    const char *chars = env->GetStringUTFChars( str, NULL );
            
    std::string text( chars );

    env->ReleaseStringUTFChars( str, chars );
    return text;
}
GHL_API void GHL_CALL GHL_Log( GHL::LogLevel level,const char* message) {
    if (::strlen(message)>=sizeof(message_buffer)) {
        // truncate
        ::strncpy(message_buffer,message,sizeof(message_buffer)-1);
        GHL_Log(level,message_buffer);
        return;
    }
	 switch ( level ) {
        case GHL::LOG_LEVEL_FATAL:
            __android_log_write(ANDROID_LOG_FATAL,"GHL",message);
            break;
        case GHL::LOG_LEVEL_ERROR:
            __android_log_write(ANDROID_LOG_ERROR,"GHL",message);
            break;
        case GHL::LOG_LEVEL_WARNING:
            __android_log_write(ANDROID_LOG_WARN,"GHL",message);
            break;
        case GHL::LOG_LEVEL_INFO:
            __android_log_write(ANDROID_LOG_INFO,"GHL",message);
            break;
        case GHL::LOG_LEVEL_VERBOSE:
            __android_log_write(ANDROID_LOG_VERBOSE,"GHL",message);
            break;
        default:
            __android_log_write(ANDROID_LOG_DEBUG,"GHL",message);
            break;
    };
}

extern "C" JNIEXPORT void JNICALL Java_com_GHL_Log_d
  (JNIEnv * env, jclass, jstring tag, jstring text) {
    const char *tag_chars = env->GetStringUTFChars( tag, NULL );
    const char *text_chars = env->GetStringUTFChars( text, NULL );
    if (!GHL::LoggerImpl::LogExternal(GHL::LOG_LEVEL_DEBUG,tag_chars,text_chars)) {
        __android_log_write(ANDROID_LOG_DEBUG,tag_chars,text_chars);
    }
    env->ReleaseStringUTFChars( tag, tag_chars );
    env->ReleaseStringUTFChars( text, text_chars );
}
extern "C" JNIEXPORT void JNICALL Java_com_GHL_Log_v
  (JNIEnv * env, jclass, jstring tag, jstring text) {
    const char *tag_chars = env->GetStringUTFChars( tag, NULL );
    const char *text_chars = env->GetStringUTFChars( text, NULL );
    if (!GHL::LoggerImpl::LogExternal(GHL::LOG_LEVEL_VERBOSE,tag_chars,text_chars)) {
        __android_log_write(ANDROID_LOG_VERBOSE,tag_chars,text_chars);
    }
    env->ReleaseStringUTFChars( tag, tag_chars );
    env->ReleaseStringUTFChars( text, text_chars );
}
extern "C" JNIEXPORT void JNICALL Java_com_GHL_Log_i
  (JNIEnv * env, jclass, jstring tag, jstring text) {
    const char *tag_chars = env->GetStringUTFChars( tag, NULL );
    const char *text_chars = env->GetStringUTFChars( text, NULL );
    if (!GHL::LoggerImpl::LogExternal(GHL::LOG_LEVEL_INFO,tag_chars,text_chars)) {
        __android_log_write(ANDROID_LOG_INFO,tag_chars,text_chars);
    }
    env->ReleaseStringUTFChars( tag, tag_chars );
    env->ReleaseStringUTFChars( text, text_chars );
}
extern "C" JNIEXPORT void JNICALL Java_com_GHL_Log_w
  (JNIEnv * env, jclass, jstring tag, jstring text) {
    const char *tag_chars = env->GetStringUTFChars( tag, NULL );
    const char *text_chars = env->GetStringUTFChars( text, NULL );
    if (!GHL::LoggerImpl::LogExternal(GHL::LOG_LEVEL_WARNING,tag_chars,text_chars)) {
        __android_log_write(ANDROID_LOG_WARN,tag_chars,text_chars);
    }
    env->ReleaseStringUTFChars( tag, tag_chars );
    env->ReleaseStringUTFChars( text, text_chars );
}
extern "C" JNIEXPORT void JNICALL Java_com_GHL_Log_e
  (JNIEnv * env, jclass, jstring tag, jstring text) {
    const char *tag_chars = env->GetStringUTFChars( tag, NULL );
    const char *text_chars = env->GetStringUTFChars( text, NULL );
    if (!GHL::LoggerImpl::LogExternal(GHL::LOG_LEVEL_ERROR,tag_chars,text_chars)) {
        __android_log_write(ANDROID_LOG_ERROR,tag_chars,text_chars);
    }
    env->ReleaseStringUTFChars( tag, tag_chars );
    env->ReleaseStringUTFChars( text, text_chars );
}

static GHL::Application* volatile temp_app = 0;

extern int ghl_android_app_main(int argc,char** argv);
static GHL::Application* android_app_create() {
    ghl_android_app_main(0,0);
    return temp_app;
}

static GHL::Key convert_key(uint32_t k) {
    switch (k) {
        case AKEYCODE_ENTER: return GHL::KEY_ENTER;
        case AKEYCODE_DEL: return GHL::KEY_BACKSPACE;
        case AKEYCODE_BACK: return GHL::KEY_BACK;
    }
    return GHL::KEY_NONE;
}


namespace GHL {



    class GHLActivity  : public System {
      
    public:
        explicit GHLActivity( ANativeActivity* activity,
                             void* savedState,
                             size_t savedStateSize)
            : m_app(0)
            , m_activity(activity)
            , m_window(0)
            , m_vfs(0)
            , m_input_queue(0)
        {
            m_running = false;

            m_render = 0;

            m_display = EGL_NO_DISPLAY;
            m_context = EGL_NO_CONTEXT;
            m_surface = EGL_NO_SURFACE;
            m_offscreen_surface = EGL_NO_SURFACE;
            m_config = 0;
            m_app_state = APP_SUSPENDED;

            m_multitouch_enabled = false;
        }
        ~GHLActivity() {
            delete m_vfs;
        }
        
        /// GHL::System impl
        /// Exit from application
        virtual void GHL_CALL Exit() {
            if (m_activity ) {
                ANativeActivity_finish(m_activity);
            }
        }
        /// Current fullscreen / windowed state
        virtual bool GHL_CALL IsFullscreen() const {
            return true;
        }
        /// Switch fullscreen / windowed state
        virtual void GHL_CALL SwitchFullscreen(bool fs) {
            
        }
        bool set_keyboard_visible(bool visible) {
            
            jclass ActivityClass = m_activity->env->GetObjectClass(m_activity->clazz);
            jmethodID method = m_activity->env->GetMethodID(ActivityClass,visible ? "showSoftKeyboard" : "hideSoftKeyboard","()Z");
            if (m_activity->env->ExceptionCheck()) {
                m_activity->env->ExceptionDescribe();
                m_activity->env->ExceptionClear();
                ILOG_INFO("[native] not found method");
                if (visible) {
                        ANativeActivity_showSoftInput(m_activity,ANATIVEACTIVITY_SHOW_SOFT_INPUT_FORCED);
                } else {
                        ANativeActivity_hideSoftInput(m_activity,0);
                }
                
                return false;
            }
            jboolean res = m_activity->env->CallBooleanMethod(m_activity->clazz,method);
            m_activity->env->DeleteLocalRef(ActivityClass);
            return res == JNI_TRUE;
        }

        bool show_system_input(const TextInputConfig* config) {
            
            jclass ActivityClass = m_activity->env->GetObjectClass(m_activity->clazz);
            jmethodID method = m_activity->env->GetMethodID(ActivityClass,"showTextInput","(ILjava/lang/String;)V");
            if (m_activity->env->ExceptionCheck()) {
                m_activity->env->ExceptionDescribe();
                m_activity->env->ExceptionClear();
                ILOG_INFO("[native] not found method");
                SetGLContext();
                ANativeActivity_showSoftInput(m_activity,ANATIVEACTIVITY_SHOW_SOFT_INPUT_FORCED);
                return false;
            }
            jstring placeholder = 0;
            jint accept_button = 0x00000006; ///  IME_ACTION_DONE
            if (config->accept_button == GHL::TIAB_SEND) {
                accept_button = 0x00000004; /// IME_ACTION_SEND
            }
            if (config->placeholder) {
                placeholder = GHL_JNI_CreateStringUTF8(m_activity->env,config->placeholder);
            }
            m_activity->env->CallVoidMethod(m_activity->clazz,method,accept_button,placeholder);
            m_activity->env->DeleteLocalRef(ActivityClass);
            if (placeholder) {
                m_activity->env->DeleteLocalRef(placeholder);
            }
            return SetGLContext();
        }
        /// Show soft keyboard
        virtual void GHL_CALL ShowKeyboard(const TextInputConfig* input) {
            if (input && input->system_input) {
                show_system_input(input);    
            } else {
                set_keyboard_visible(true);
            }
            if (!SetGLContext()) {
               return;
            }
        }
        /// Hide soft keyboard
        virtual void GHL_CALL HideKeyboard() {
            set_keyboard_visible(false);
            if (!SetGLContext()) {
               return;
            }
        }
        /// Get current key modifiers state
        virtual UInt32  GHL_CALL GetKeyMods() const {
            return 0;
        }
        /// Set device specific state
        virtual bool GHL_CALL SetDeviceState( DeviceState name, const void* data) {
            if (name==GHL::DEVICE_STATE_FRAME_INTERVAL) {
                const GHL::Int32* state = (const GHL::Int32*)data;
                g_frame_interval = *state;
                return true;
            } else if (name == GHL::DEVICE_STATE_KEEP_SCREEN_ON) {
                if (m_activity) {
                    const bool* state = (const bool*)data;
                    if (*state) {
                        ANativeActivity_setWindowFlags(m_activity, AWINDOW_FLAG_KEEP_SCREEN_ON, 0);
                    } else {
                        ANativeActivity_setWindowFlags(m_activity, 0, AWINDOW_FLAG_KEEP_SCREEN_ON);
                    }
                    return true;
                }
            } else if (name==GHL::DEVICE_STATE_MULTITOUCH_ENABLED) {
                const bool* state = static_cast<const bool*>(data);
                m_multitouch_enabled = *state;
                return true;
            } 
            return false;
        }
        /// Get device specific data
        virtual bool GHL_CALL GetDeviceData( DeviceData name, void* data) {
            if (name == DEVICE_DATA_APPLICATION ) {
                ANativeActivity** na = reinterpret_cast<ANativeActivity**>(data);
                if (na) {
                    *na = m_activity;
                    return true;
                }
            } else if (name == GHL::DEVICE_DATA_UTC_OFFSET) {
                if (data) {
                    GHL::Int32* output = static_cast<GHL::Int32*>(data);

                    struct ::timeval tv = {0,0};
                    struct ::timezone tz = {0,0};
                    ::gettimeofday(&tv, &tz);
                    *output = - tz.tz_minuteswest * 60;
                    return true;
                }
            } else if (name == GHL::DEVICE_DATA_LANGUAGE) {
                std::string language = android_language_name();
                if (!language.empty() && data) {
                    char* dest = static_cast<char*>(data);
                    ::strncpy(dest, language.c_str(), 32);
                    return true;
                }
            } else if (name == GHL::DEVICE_DATA_NAME) {
                char manufacturer[PROP_VALUE_MAX]; 
                int len_manufacturer = __system_property_get(ANDROID_OS_BUILD_MANUFACTURER, manufacturer); 
                char model[PROP_VALUE_MAX]; 
                int len_model = __system_property_get(ANDROID_OS_BUILD_MODEL, model); 
                if (data) {
                    char* dest = static_cast<char*>(data);
                    if (len_manufacturer || len_model) {
                        if (len_manufacturer == 0 || ::strncmp(model,manufacturer,len_manufacturer)==0) {
                            ::strncpy(dest,model,128);
                        } else {
                            ::snprintf(dest,128,"%s %s",manufacturer,model);
                        } 
                        return true;
                    }
                    
                }
            } else if (name == GHL::DEVICE_DATA_OS) {
                char version[PROP_VALUE_MAX]; 
                int len = __system_property_get(ANDROID_OS_BUILD_VERSION_RELEASE, version); 
                if (len && data) {
                    char* dest = static_cast<char*>(data);
                    ::snprintf(dest,128,"android %s",version);
                    return true;
                }
            }

            return false;
        }
        /// Set window title
        virtual void GHL_CALL SetTitle( const char* title ) {
            
        }
        virtual bool GHL_CALL OpenURL( const char* url ) {
            jclass ActivityClass = m_activity->env->GetObjectClass(m_activity->clazz);
            jmethodID method = m_activity->env->GetMethodID(ActivityClass,"openURL","(Ljava/lang/String;)Z");
            if (m_activity->env->ExceptionCheck()) {
                m_activity->env->ExceptionDescribe();
                m_activity->env->ExceptionClear();
                ILOG_INFO("[native] not found openURL method");
                return false;
            }
            jstring urlobj = GHL_JNI_CreateStringUTF8(m_activity->env,url);
            jboolean res = m_activity->env->CallBooleanMethod(m_activity->clazz,method,urlobj);
            m_activity->env->DeleteLocalRef(ActivityClass);
            m_activity->env->DeleteLocalRef(urlobj);
            return res;
        }
        static const unsigned int AWINDOW_FLAG_KEEP_SCREEN_ON = 0x00000080;
        void OnCreate() {
            LOG_INFO("OnCreate");
              /* Set the window color depth to 24bpp, since the default is
                * ugly-looking 16bpp. */
            ANativeActivity_setWindowFormat(m_activity, WINDOW_FORMAT_RGBX_8888);

            m_app = android_app_create();

            if (m_app) {
                m_app->SetSystem(this);
            }

            if (m_app && m_sound.SoundInit()) {
                m_app->SetSound(&m_sound);
            }
            
            gettimeofday(&m_last_time,0);
            if (!m_vfs) {
                m_vfs = new VFSAndroidImpl(m_activity->assetManager,m_activity->internalDataPath);
                m_vfs->SetCacheDir(android_temp_folder());
            }
            if (m_app) {
                m_app->SetVFS(m_vfs);
                m_app->SetImageDecoder(&m_image_decoder);
            }
           
                

            if (m_app) {
                GHL::Event e;
                e.type = GHL::EVENT_TYPE_APP_STARTED;
                m_app->OnEvent(&e);
            }



        }
        void OnStart() {
            LOG_INFO("OnStart");

            check_main_thread();
      
        }
        void OnResume() {
            LOG_INFO("OnResume");
            check_main_thread();
           
            if (m_app) {
                if (m_app_state == APP_SUSPENDED) {
                    GHL::Event e;
                    e.type = GHL::EVENT_TYPE_RESUME;
                    m_app->OnEvent(&e);
                    m_app_state = APP_INACTIVE;
                }
            }
            StartTimerThread();
        }
        void* onSaveInstanceState(size_t* outSize) {
            return 0;
        }
        void OnPause() {
            LOG_INFO("OnPause: " << m_app_state);
            check_main_thread();
       
            if (m_app) {
                if (m_app_state == APP_ACTIVE) {
                    GHL::Event e;
                    e.type = GHL::EVENT_TYPE_DEACTIVATE;
                    m_app->OnEvent(&e);
                    m_app_state = APP_INACTIVE;
                }
                if (m_app_state == APP_INACTIVE) {
                    GHL::Event e;
                    e.type = GHL::EVENT_TYPE_SUSPEND;
                    m_app->OnEvent(&e);
                    m_app_state = APP_SUSPENDED;
                }
                
            }
            StopTimerThread();
        }
        void OnStop() {
            LOG_INFO("OnStop");
            check_main_thread();
        }
        void OnDestroy() {
            LOG_INFO("OnDestroy");
            check_main_thread();

            if (m_app) {
                m_app->SetSound(0);
                m_sound.SoundDone();
            }

            DestroySurface();

            if (m_display != EGL_NO_DISPLAY && m_offscreen_surface != EGL_NO_CONTEXT) {

                eglMakeCurrent(m_display,m_offscreen_surface,m_offscreen_surface,m_context);
                if (m_app) {
                    m_app->Unload();
                }
            }
            

            DestroyContext();

       
            if (m_app) {
                m_app->Release();
                m_app = 0;
            }
        }
        void OnWindowFocusChanged(int hasFocus) {
            LOG_VERBOSE("OnWindowFocusChanged:" << hasFocus);
            check_main_thread();
            m_sound.SetFocus(hasFocus);
            if (m_app) {
                if (hasFocus) {
                    if (m_app_state == APP_INACTIVE) {
                        GHL::Event e;
                        e.type = GHL::EVENT_TYPE_ACTIVATE;
                        m_app->OnEvent(&e);
                        m_app_state = APP_ACTIVE;
                    }
                } else {
                    if (m_app_state == APP_ACTIVE) {
                        GHL::Event e;
                        e.type = GHL::EVENT_TYPE_DEACTIVATE;
                        m_app->OnEvent(&e);
                        m_app_state = APP_INACTIVE;
                    }
                }
            }
        }

        bool onIntent(JNIEnv* env,jobject intent) {
            if (!m_app ) {
                LOG_INFO("no app");
                return false;
            }
            jclass IntentClass = env->GetObjectClass(intent);
            jmethodID get_data = env->GetMethodID(IntentClass,"getDataString","()Ljava/lang/String;");
            assert(get_data);
            jstring url = (jstring)env->CallObjectMethod(intent,get_data);
            if (url) {
                std::string url_str = get_string(env,url);
                env->DeleteLocalRef((jobject)url);

                GHL::Event e;
                e.type = GHL::EVENT_TYPE_HANDLE_URL;
                e.data.handle_url.url = url_str.c_str();
                LOG_INFO("handle url: " << e.data.handle_url.url);
                m_app->OnEvent(&e);
            } else {
                LOG_INFO("intent data empty");
            }
            env->DeleteLocalRef(IntentClass);
            return true;
        }

        void DestroySurface() {
            LOG_INFO("DestroySurface");
            if (m_display != EGL_NO_DISPLAY) {
                if (m_surface != EGL_NO_SURFACE) {
                    if (m_offscreen_surface == EGL_NO_SURFACE) {
                        if (m_app) {
                            LOG_INFO("unload");
                            SetGLContext();
                            m_app->Unload();
                        }
                    }
                    eglMakeCurrent(m_display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
                    eglDestroySurface(m_display,m_surface);
                    m_surface = EGL_NO_SURFACE;
                }
                if (m_offscreen_surface == EGL_NO_SURFACE) {
                    DestroyContext();
                }
            }
        }

        void DestroyContext() {
            LOG_INFO("DestroyContext");
            if (m_render) {
                m_app->SetRender(0);
                GHL_DestroyRenderOpenGL(m_render);
                m_render = 0;
            }
            DestroySurface();
            if (m_display != EGL_NO_DISPLAY) {

                eglMakeCurrent(m_display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
                if (m_offscreen_surface != EGL_NO_SURFACE) {
                    eglDestroySurface(m_display,m_offscreen_surface);
                    m_offscreen_surface = EGL_NO_SURFACE;
                }
                if (m_context != EGL_NO_CONTEXT) {
                    eglDestroyContext(m_display, m_context);
                    m_context = EGL_NO_CONTEXT;
                }
                eglTerminate(m_display);
                m_display = EGL_NO_DISPLAY;
            }
        }
        void dump_config(EGLConfig c) {
            EGLint v;
            eglGetConfigAttrib(m_display, c, EGL_NATIVE_VISUAL_ID, &v);
            LOG_INFO("EGL_NATIVE_VISUAL_ID: " << v);
            eglGetConfigAttrib(m_display, c, EGL_ALPHA_SIZE, &v);
            LOG_INFO("EGL_ALPHA_SIZE:   " << v);
            eglGetConfigAttrib(m_display, c, EGL_RED_SIZE, &v);
            LOG_INFO("EGL_RED_SIZE:     " << v);
            eglGetConfigAttrib(m_display, c, EGL_GREEN_SIZE, &v);
            LOG_INFO("EGL_GREEN_SIZE:   " << v);
            eglGetConfigAttrib(m_display, c, EGL_BLUE_SIZE, &v);
            LOG_INFO("EGL_BLUE_SIZE:    " << v);
            eglGetConfigAttrib(m_display, c, EGL_SAMPLES, &v);
            LOG_INFO("EGL_SAMPLES:      " << v);
            eglGetConfigAttrib(m_display, c, EGL_STENCIL_SIZE, &v);

            LOG_INFO("EGL_STENCIL_SIZE: " << v);
            eglGetConfigAttrib(m_display, c, EGL_DEPTH_SIZE, &v);
            LOG_INFO("EGL_DEPTH_SIZE:   " << v);
            eglGetConfigAttrib(m_display, c, EGL_NATIVE_RENDERABLE, &v);
            LOG_INFO("EGL_NATIVE_RENDERABLE: " << v);
            eglGetConfigAttrib(m_display, c, EGL_RENDERABLE_TYPE, &v);
            LOG_INFO("EGL_RENDERABLE_TYPE:   " << v);
            eglGetConfigAttrib(m_display, c, EGL_SAMPLE_BUFFERS, &v);
            LOG_INFO("EGL_SAMPLE_BUFFERS:    " << v);
            eglGetConfigAttrib(m_display, c, EGL_SURFACE_TYPE, &v);
            std::string type;
            if (v&EGL_WINDOW_BIT) {
                type = "WINDOW";
                v&=~EGL_WINDOW_BIT;
            }
            if (v&EGL_PBUFFER_BIT) {
                if (!type.empty()) type +="|";
                type += "PBUFFER";
                v&=~EGL_PBUFFER_BIT;
            }
            if (v&EGL_PIXMAP_BIT) {
                if (!type.empty()) type +="|";
                type += "PIXMAP";
                v&=~EGL_PIXMAP_BIT;
            }
            if (v&EGL_MULTISAMPLE_RESOLVE_BOX_BIT) {
                if (!type.empty()) type +="|";
                type += "MULTISAMPLE";
                v&=~EGL_MULTISAMPLE_RESOLVE_BOX_BIT;
            }
            LOG_INFO("EGL_SURFACE_TYPE:    " << type << (type.empty() ? "" : "|") << v);
        }
        
        bool CreateContext(const EGLint* attribs) {
            m_config = 0;

            if (m_display == EGL_NO_DISPLAY) {
                m_display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
                EGLint major=0;
                EGLint minor=0;
                if (eglInitialize(m_display, &major, &minor)!=EGL_TRUE) {
                    LOG_ERROR("Unable to eglInitialize");
                    return false;
                } else {
                    LOG_INFO("EGL: " << major << "." << minor);
                }
            }

            EGLint numConfigs;
            
             /* Here, the application chooses the configuration it desires. In this
             * sample, we have a very simplified selection process, where we pick
             * the first EGLConfig that matches our criteria */
            eglChooseConfig(m_display, attribs, &m_config, 1, &numConfigs);
            if (numConfigs <= 0) {
                GHL_Log(GHL::LOG_LEVEL_ERROR,"Unable to eglChooseConfig");
                return false ;
            }
            LOG_INFO("EGL selected config:");
            dump_config(m_config);
            
            
            const EGLint ctx_attribs[] = {
                EGL_CONTEXT_CLIENT_VERSION,
                2,
                EGL_NONE
            };
            m_context = eglCreateContext(m_display, m_config, NULL, ctx_attribs);
            if (m_context == EGL_NO_CONTEXT) {
                GHL_Log(GHL::LOG_LEVEL_ERROR,"Unable to eglCreateContext");
                return false ;
            }

            EGLint renderable_type = 0;
            eglGetConfigAttrib(m_display,m_config,EGL_SURFACE_TYPE,&renderable_type);
            if (renderable_type & EGL_PBUFFER_BIT) {
                LOG_INFO("create offscreen surface");
                const EGLint surface_attribs[] = {
                    EGL_WIDTH, 32,
                    EGL_HEIGHT, 32,
                    EGL_NONE
                };
                m_offscreen_surface = eglCreatePbufferSurface(m_display,m_config,surface_attribs);
                if (m_offscreen_surface == EGL_NO_SURFACE) {
                    LOG_ERROR("failed create offscreen surface");
                }
            } else {
                LOG_INFO("config dnt support offscreen surface");
            }

            
            return true;
            
        }
        bool SetGLContext() {
            if (m_display == EGL_NO_DISPLAY ||
                m_context == EGL_NO_CONTEXT) {
                return false;
            }
            if (m_surface != EGL_NO_SURFACE) {
                if (eglMakeCurrent(m_display, m_surface, m_surface, m_context) == EGL_FALSE) {
                    GHL_Log(GHL::LOG_LEVEL_ERROR,"Unable to eglMakeCurrent");
                    return false ;
                }
            } else if (m_offscreen_surface != EGL_NO_SURFACE) {
                if (eglMakeCurrent(m_display, m_offscreen_surface, m_offscreen_surface, m_context) == EGL_FALSE) {
                    GHL_Log(GHL::LOG_LEVEL_ERROR,"Unable to eglMakeCurrent for offscreen");
                    return false ;
                }
            } else {
                return false;
            }
            
            return true;
        }

        bool CreateSurface() {
            EGLint format = 0;
             /* EGL_NATIVE_VISUAL_ID is an attribute of the EGLConfig that is
             * guaranteed to be accepted by ANativeWindow_setBuffersGeometry().
             * As soon as we picked a EGLConfig, we can safely reconfigure the
             * ANativeWindow buffers to match, using EGL_NATIVE_VISUAL_ID. */
            eglGetConfigAttrib(m_display, m_config, EGL_NATIVE_VISUAL_ID, &format);
            
            ANativeWindow_setBuffersGeometry(m_window, 0, 0, format);
            
            m_surface = eglCreateWindowSurface(m_display, m_config, m_window, NULL);
            if (!m_surface) {
                GHL_Log(GHL::LOG_LEVEL_ERROR,"Unable to eglCreateWindowSurface");
                return false ;
            }
            return SetGLContext();
        }

        void OnNativeWindowCreated(ANativeWindow* window) {
            LOG_INFO("OnNativeWindowCreated");
            check_main_thread();
          
            if (m_window==0) {
                // initialize OpenGL ES and EGL

                GHL::Settings settings;
                /// default settings
                settings.width = ANativeWindow_getWidth(window);
                settings.height = ANativeWindow_getHeight(window);
                settings.fullscreen = true;
                settings.depth = false;

                
                
                if (m_context == EGL_NO_CONTEXT) {

                    
                    if (m_app)
                    {                        
                        m_app->FillSettings(&settings);
                        if (m_activity->env->ExceptionCheck()) {
                            return;
                        }
                    }

                    /*
                     * Here specify the attributes of the desired configuration.
                     * Below, we select an EGLConfig with at least 8 bits per color
                     * component compatible with on-screen windows
                     */
                 
                    if (settings.depth) {
                        const EGLint depth_attribs[] = {
                            EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
                            EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
                            EGL_BLUE_SIZE, 8,
                            EGL_GREEN_SIZE, 8,
                            EGL_RED_SIZE, 8,
                            EGL_DEPTH_SIZE, 16,
                            EGL_SAMPLE_BUFFERS, 0,
                            EGL_SAMPLES, 0,
                            EGL_NONE
                        };
                        if (!CreateContext(depth_attribs)) {
                            LOG_ERROR("Unable to CreateContext with depth");
                            return;
                        }
                    } else {
                        const EGLint attribs[] = {
                            EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
                            EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
                            EGL_BLUE_SIZE, 8,
                            EGL_GREEN_SIZE, 8,
                            EGL_RED_SIZE, 8,
                            EGL_DEPTH_SIZE, 0,
                            EGL_SAMPLE_BUFFERS, 0,
                            EGL_SAMPLES, 0,
                            EGL_NONE
                        };

                        if (!CreateContext(attribs)) {
                            LOG_ERROR("Unable to CreateContext");
                            return;
                        }
                    }
                     
                }

                m_window = window;
                if (m_surface == EGL_NO_SURFACE) {
                    if (!CreateSurface()) {
                        LOG_ERROR("Unable to CreateSurface");
                        return;
                    }
                }
                 
                
                
                
                if (!m_render) {

                    EGLint w, h;
                   
                    eglQuerySurface(m_display, m_surface, EGL_WIDTH, &w);
                    eglQuerySurface(m_display, m_surface, EGL_HEIGHT, &h);


                    m_render = GHL_CreateRenderOpenGL(w,h,settings.depth);
                    if ( m_render && m_app ) {
                        m_app->SetRender(m_render);
                        m_app->Load();
                        if (m_activity->env->ExceptionCheck()) {
                            return;
                        }
                    }
                }
                

               

                Render();
            } else {
                LOG_INFO("skip another window");
            }
        }

        void OnNativeWindowResized(ANativeWindow* window) {
            LOG_INFO("OnNativeWindowResized");
            check_main_thread();
            int32_t w = ANativeWindow_getWidth(window);
            int32_t h = ANativeWindow_getHeight(window);
            LOG_INFO("window size: " << w << "x" << h);
        }
        void OnNativeWindowRedrawNeeded(ANativeWindow* window) {
            
        }
        void OnNativeWindowDestroyed(ANativeWindow* window) {
            LOG_INFO("OnNativeWindowDestroyed");
            check_main_thread();
           
            if (m_window==window) {
                
                DestroySurface();
                
                m_window = 0;
            } else {
                LOG_INFO("skip another window");
            }
        }
        void OnInputQueueCreated(AInputQueue* queue) {
            LOG_INFO("OnInputQueueCreated");
            check_main_thread();
           
            if (m_input_queue) {
                OnInputQueueDestroyed(m_input_queue);
                m_input_queue = 0;
            }
            ALooper* looper = ALooper_forThread();
            if (!looper) {
                LOG_ERROR("ALooper_forThread return zero");
                return;
            }
            m_input_queue = queue;
            AInputQueue_attachLooper(queue,looper,ALOOPER_POLL_CALLBACK,
                                     &GHLActivity::ALooper_InputCallback,this);
        }
        void OnInputQueueDestroyed(AInputQueue* queue) {
            LOG_INFO("OnInputQueueDestroyed");
            check_main_thread();
     
            if (m_input_queue==queue) {
                AInputQueue_detachLooper(queue);
                m_input_queue = 0;
            }
        }
        void OnContentRectChanged(const ARect* rect) {
            if (!rect) return;
            check_main_thread();
            ILOG_INFO("OnContentRectChanged " << rect->left << "," << rect->top << "," << rect->right << "," << rect->bottom);
                
            if (m_render && m_context!=EGL_NO_CONTEXT) {
                int w = rect->right-rect->left;
                int h = rect->bottom-rect->top;
                if (w >0 && h > 0) {
                    m_render->Resize(w,h);
                }
            }
        }
        void OnVisibleRectChanged(int x,int y,int w,int h) {
             if (!m_app) return;
             check_main_thread();

             GHL::Event event;
             event.type = GHL::EVENT_TYPE_VISIBLE_RECT_CHANGED;
             event.data.visible_rect_changed.x = x;
             event.data.visible_rect_changed.y = y;
             event.data.visible_rect_changed.w = w;
             event.data.visible_rect_changed.h = h;
             m_app->OnEvent(&event);
        }
        void OnConfigurationChanged() {
            ILOG_INFO("OnConfigurationChanged");
        }
        void OnLowMemory() {
            LOG_WARNING("OnLowMemory");
            if (!m_app) return;
            check_main_thread();

            GHL::Event e;
            e.type = GHL::EVENT_TYPE_TRIM_MEMORY;
            m_app->OnEvent(&e);
        }

        bool onJavaKey(int key_code,uint32_t unicode,int action) {
            if (!m_app) return false;
            check_main_thread();
            if (!SetGLContext()) {
                return false;
            }
            return onKey(key_code,unicode,action);
        }

        bool onKey(int key_code,uint32_t unicode,int action) {
            if (!m_app) 
                return false;
            

            if (AKEY_EVENT_ACTION_DOWN == action) {
                //ILOG_INFO("AKEY_EVENT_ACTION_DOWN " << key_code << " " << unicode);
                GHL::Event e;
                e.type = GHL::EVENT_TYPE_KEY_PRESS;
                e.data.key_press.handled = false;
                e.data.key_press.key = convert_key(key_code);
                e.data.key_press.modificators = 0;
                e.data.key_press.charcode = unicode;
                m_app->OnEvent(&e);
                return e.data.key_press.handled;
            } else if (AKEY_EVENT_ACTION_UP == action) {
                //ILOG_INFO("AKEY_EVENT_ACTION_UP " << key_code << " " << unicode);
                GHL::Event e;
                e.type = GHL::EVENT_TYPE_KEY_RELEASE;
                e.data.key_release.handled = false;
                e.data.key_release.key = convert_key(key_code);
                m_app->OnEvent(&e);
                return e.data.key_release.handled;
            } else {
                ILOG_INFO("unknown key event " << action);
            }
            return false;
        }

        void onTextInputDismiss() {
            if (m_app) {
                check_main_thread();
                if (!SetGLContext()) {
                   return;
                }
                GHL::Event e;
                e.type = GHL::EVENT_TYPE_TEXT_INPUT_CLOSED;
                m_app->OnEvent(&e);
            }
        }

        void onTextInputAccepted(const std::string& text) {
            if (m_app) {
                check_main_thread();
                if (!SetGLContext()) {
                   return;
                }
                GHL::Event e;
                e.type = GHL::EVENT_TYPE_TEXT_INPUT_ACCEPTED;
                e.data.text_input_accepted.text = text.c_str();
                m_app->OnEvent(&e);
            }
        }

        void onTextInputChanged(const std::string& text) {
            if (m_app) {
                check_main_thread();
                if (!SetGLContext()) {
                   return;
                }
                GHL::Event e;
                e.type = GHL::EVENT_TYPE_TEXT_INPUT_TEXT_CHANGED;
                e.data.text_input_text_changed.text = text.c_str();
                m_app->OnEvent(&e);
            }
        }
        void onKeyboardHide() {
             if (m_app) {
                GHL::Event e;
                e.type = GHL::EVENT_TYPE_KEYBOARD_HIDE;
                m_app->OnEvent(&e);
            }
        }

    protected:

        GHL::MouseButton get_touch(int32_t pointer_id) const {
            std::map<int32_t,GHL::MouseButton>::const_iterator it = m_touch_map.find(pointer_id);
            if (it == m_touch_map.end()) return GHL::MOUSE_BUTTON_NONE;
            return it->second;
        }
        bool HandleEvent(const AInputEvent* event) {
            check_main_thread();
            if (!SetGLContext()) {
                return false;
            }
          
            if (AINPUT_EVENT_TYPE_MOTION==AInputEvent_getType(event)) {
                int32_t action = AMotionEvent_getAction(event);
                int32_t actionType = action & AMOTION_EVENT_ACTION_MASK;
                
                
                if (m_app) {
                    GHL::Event e;
                    if ( actionType == AMOTION_EVENT_ACTION_DOWN ) {
                        e.data.mouse_press.button = GHL::TOUCH_1;
                        e.type = GHL::EVENT_TYPE_MOUSE_PRESS;
                        e.data.mouse_press.modificators = 0;
                        e.data.mouse_press.x = int( AMotionEvent_getX(event,0) );
                        e.data.mouse_press.y = int( AMotionEvent_getY(event,0) );
                        m_touch_map.clear();
                        m_touch_map[AMotionEvent_getPointerId(event,0)] = e.data.mouse_press.button;
                        //LOG_DEBUG("set touch1 " << AMotionEvent_getPointerId(event,0) << " " << e.data.mouse_press.button);
                        m_app->OnEvent(&e);
                    } else if (actionType == AMOTION_EVENT_ACTION_UP) {
                        e.type = GHL::EVENT_TYPE_MOUSE_RELEASE;
                        int32_t id = AMotionEvent_getPointerId(event,0);
                        e.data.mouse_release.button = get_touch(id);
                        if (e.data.mouse_release.button == GHL::MOUSE_BUTTON_NONE) {
                            //LOG_DEBUG("skip up touch1 " << id);
                            return true;
                        }
                        e.data.mouse_release.modificators = 0;
                        e.data.mouse_release.x = int( AMotionEvent_getX(event,0) );
                        e.data.mouse_release.y = int( AMotionEvent_getY(event,0) );
                        m_touch_map.erase(id);
                        //LOG_DEBUG("erase touch1 " << id);
                        m_app->OnEvent(&e);
                    } else if ( actionType == AMOTION_EVENT_ACTION_POINTER_DOWN ) {
                        int32_t ptr = ( action & AMOTION_EVENT_ACTION_POINTER_INDEX_MASK ) >> AMOTION_EVENT_ACTION_POINTER_INDEX_SHIFT;
                        if (!m_multitouch_enabled && m_touch_map.size()>0) {
                            //LOG_DEBUG("skip touch down" << AMotionEvent_getPointerId(event,ptr));
                            return true;
                        }
                        if (m_touch_map.size()==0)
                            e.data.mouse_press.button = GHL::TOUCH_1;
                        else
                            e.data.mouse_press.button = static_cast<GHL::MouseButton>(GHL::MULTITOUCH_1 + m_touch_map.size() - 1);
                        e.type = GHL::EVENT_TYPE_MOUSE_PRESS;
                        e.data.mouse_press.modificators = 0;
                        e.data.mouse_press.x = int( AMotionEvent_getX(event,ptr) );
                        e.data.mouse_press.y = int( AMotionEvent_getY(event,ptr) );
                        m_touch_map[AMotionEvent_getPointerId(event,ptr)] = e.data.mouse_press.button;
                        //LOG_DEBUG("set touch " << AMotionEvent_getPointerId(event,ptr) << " " << ptr << " " << e.data.mouse_press.button);
                        m_app->OnEvent(&e);
                    } else if (actionType == AMOTION_EVENT_ACTION_POINTER_UP) {
                        int32_t ptr =  ( action & AMOTION_EVENT_ACTION_POINTER_INDEX_MASK ) >> AMOTION_EVENT_ACTION_POINTER_INDEX_SHIFT;
                        e.type = GHL::EVENT_TYPE_MOUSE_RELEASE;
                        int32_t id = AMotionEvent_getPointerId(event,ptr);
                        e.data.mouse_release.button = get_touch(id);
                        if (e.data.mouse_release.button == GHL::MOUSE_BUTTON_NONE) {
                            //LOG_DEBUG("skip up touch " << id);
                            return true;
                        }
                        e.data.mouse_release.modificators = 0;
                        e.data.mouse_release.x = int( AMotionEvent_getX(event,ptr) );
                        e.data.mouse_release.y = int( AMotionEvent_getY(event,ptr) );
                        m_touch_map.erase(id);
                        //LOG_DEBUG("erase touch " << id);
                        m_app->OnEvent(&e);
                    } else if (actionType == AMOTION_EVENT_ACTION_MOVE) {
                        size_t cnt = AMotionEvent_getPointerCount(event);
                        e.type = GHL::EVENT_TYPE_MOUSE_MOVE;
                            
                        for (size_t i=0;i<cnt;++i) {
                            e.data.mouse_move.button = get_touch(AMotionEvent_getPointerId(event,i));
                            if (e.data.mouse_move.button == GHL::MOUSE_BUTTON_NONE) {
                                //LOG_DEBUG("skip move touch " << AMotionEvent_getPointerId(event,i));
                                continue;
                            }
                            //LOG_DEBUG("move touch " << AMotionEvent_getPointerId(event,i));
                            e.data.mouse_move.modificators = 0;
                            e.data.mouse_move.x =  int( AMotionEvent_getX(event,i) );
                            e.data.mouse_move.y =  int( AMotionEvent_getY(event,i) );
                            m_app->OnEvent(&e);
                        }
                        
                    } else {
                        return false;
                    }
                    
                }
                return true;
            } else if (AINPUT_EVENT_TYPE_KEY == AInputEvent_getType(event)) {
                if (IsBackPress(event)) {
                    if (set_keyboard_visible(false)) {
                        if (m_app) {
                            GHL::Event e;
                            e.type = GHL::EVENT_TYPE_KEYBOARD_HIDE;
                            m_app->OnEvent(&e);
                        }
                        return true;
                    }
                }
                int32_t key_code = AKeyEvent_getKeyCode(event);
                return onKey(key_code,0,AKeyEvent_getAction(event));
            } else {
                LOG_INFO("unknown event type " << AInputEvent_getType(event));
            }
            return false;
        }

        bool IsBackPress(const AInputEvent* event) {
            return AInputEvent_getType(event) == AINPUT_EVENT_TYPE_KEY &&
                AKeyEvent_getKeyCode(event) == AKEYCODE_BACK &&
                AKeyEvent_getAction(event) == AKEY_EVENT_ACTION_DOWN;
        }
        
        void OnInputCallback() {
            if (m_input_queue) {
                AInputEvent* event = 0;
                while ( AInputQueue_getEvent(m_input_queue,&event)>=0 ) {
                    if (!IsBackPress(event) && AInputQueue_preDispatchEvent(m_input_queue, event)) {
                       continue;
                    }
                    bool handled = HandleEvent(event);
                    AInputQueue_finishEvent(m_input_queue,event,handled?1:0);
                }
            }
        }
        void OnTimerCallback() {
            check_main_thread();
            
            Render(true);

            if (m_running) {
                ScheduleFrame();
            }
        }
        void ScheduleFrame() {
            int8_t cmd = 1;
            if (write(m_msgwrite, &cmd, sizeof(cmd)) != sizeof(cmd)) {
                LOG_ERROR("Failure writing android_app cmd:" << strerror(errno));
            }
        }
        static int ALooper_InputCallback(int fd, int events, void* data) {
            //LOG_INFO("ALooper_InputCallback");
            GHLActivity* _this = static_cast<GHLActivity*>(data);
            if (events&ALOOPER_EVENT_INPUT)
                _this->OnInputCallback();
            return 1;
        }
        static int ALooper_TimerCallback(int fd, int events, void* data) {
            GHLActivity* _this = static_cast<GHLActivity*>(data);
            if (events&ALOOPER_EVENT_INPUT) {
                int8_t cmd;
                if (read(_this->m_msgread, &cmd, sizeof(cmd)) == sizeof(cmd)) {
                    _this->OnTimerCallback();
                }
            }
            return 1;
        }
        void Render(bool from_timer = false) {
            //LOG_DEBUG("Render ->");
            if (!SetGLContext()) {
               return;
            }
            
            if (m_app) {
                timeval now;
                gettimeofday(&now,0);
                GHL::UInt32 frameTime = (now.tv_sec-m_last_time.tv_sec)*1000000 + (now.tv_usec-m_last_time.tv_usec);
                if (from_timer && (frameTime < (1000000*g_frame_interval/60)))
                    return;
                m_app->OnFrame( frameTime );
                eglSwapBuffers(m_display, m_surface);
                m_last_time = now;
            }
            //LOG_DEBUG("Render <-");
        }
        void StartTimerThread();
        void StopTimerThread();

         std::string android_temp_folder(  ) {

            jclass ActivityClass = m_activity->env->GetObjectClass(m_activity->clazz);
            jmethodID method = m_activity->env->GetMethodID(ActivityClass,"getCacheDir", "()Ljava/io/File;");
            if (m_activity->env->ExceptionCheck()) {
                m_activity->env->ExceptionDescribe();
                m_activity->env->ExceptionClear();
                ILOG_INFO("[native] not found method");
                return "";
            }
            jobject cache_dir = m_activity->env->CallObjectMethod(m_activity->clazz,method);
            m_activity->env->DeleteLocalRef(ActivityClass);

            jclass fileClass = m_activity->env->GetObjectClass( cache_dir );
            jmethodID getPath = m_activity->env->GetMethodID( fileClass, "getPath", "()Ljava/lang/String;" );
            jstring path_string = (jstring)m_activity->env->CallObjectMethod( cache_dir, getPath );
            m_activity->env->DeleteLocalRef(fileClass);

            std::string temp_folder = get_string(m_activity->env,path_string);
            m_activity->env->DeleteLocalRef(path_string);
            return temp_folder;
        }

        std::string android_language_name() {
            std::string result;
            jclass LocaleClass = m_activity->env->FindClass("java/util/Locale");
            if (m_activity->env->ExceptionCheck()) {
                ILOG_INFO("[native] not found class java/util/Locale");
                m_activity->env->ExceptionDescribe();
                m_activity->env->ExceptionClear();
                ILOG_INFO("[native] not found method");
                return result;
            }
            jmethodID getDefault = m_activity->env->GetStaticMethodID(LocaleClass,"getDefault","()Ljava/util/Locale;");
            if (getDefault) {
                jobject obj = m_activity->env->CallStaticObjectMethod(LocaleClass,getDefault);
                jmethodID getLanguage = m_activity->env->GetMethodID(LocaleClass,"getLanguage","()Ljava/lang/String;");
                if (getLanguage) {
                    jstring language = (jstring)m_activity->env->CallObjectMethod(obj,getLanguage);
                    if (language) {
                        result = get_string(m_activity->env,language);
                        m_activity->env->DeleteLocalRef(language);
                    }
                }
                m_activity->env->DeleteLocalRef(obj);
            }
            m_activity->env->DeleteLocalRef(LocaleClass);
            return result;
        }

    private:
        GHL::ImageDecoderImpl   m_image_decoder;
        GHL::SoundAndroid   m_sound;
        Application*        m_app;
        ANativeActivity*    m_activity;
        ANativeWindow*      m_window;
        VFSAndroidImpl*     m_vfs;
        EGLDisplay          m_display;
        EGLSurface          m_surface;
        EGLSurface          m_offscreen_surface;
        EGLContext          m_context;
        EGLConfig           m_config;
        RenderImpl*         m_render;
        timeval             m_last_time;
        AInputQueue*        m_input_queue;
        
        int m_msgread;
        int m_msgwrite;
        bool m_running;
       
        bool m_multitouch_enabled;
        std::map<int32_t,GHL::MouseButton> m_touch_map;

        enum {
            APP_SUSPENDED,
            APP_INACTIVE,
            APP_ACTIVE
        } m_app_state;
    };
   
    
    void GHLActivity::StartTimerThread() {
        m_running = true;
        
        int msgpipe[2];
        if (pipe(msgpipe)) {
            LOG_ERROR("could not create pipe: " << strerror(errno));
            return ;
        }
        m_msgread = msgpipe[0];
        m_msgwrite = msgpipe[1];
        
        ALooper* looper = ALooper_forThread();
        if (!looper) {
            LOG_ERROR("StartTimerThread:ALooper_forThread return zero");
            return;
        }
        
        ALooper_addFd(looper, m_msgread, ALOOPER_POLL_CALLBACK, ALOOPER_EVENT_INPUT, &GHLActivity::ALooper_TimerCallback,
                      this);
        
        m_running = true;
        ScheduleFrame();
    }
    void GHLActivity::StopTimerThread() {
        m_running = false;
        
        ALooper_removeFd(ALooper_forThread(),m_msgread);
        
        close(m_msgread);
        close(m_msgwrite);
    }
}


static const unsigned char UTF8_BYTE_MARK = 0x80;
static const unsigned char UTF8_BYTE_MASK_READ = 0x3F;
static const unsigned char UTF8_FIRST_BYTE_MARK[7] = { 0x00, 0x00, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC };

static bool check_utf8(const char* s) {
    const unsigned char* str = reinterpret_cast<const unsigned char*>(s);
    while (*str) {
        unsigned char c = *str;
        if ( (c & 0x80) == 0x00 ) {
            // single char
            ++str;
        } else if ((c & 0xe0)==0xc0) {
            ++str;
            if (!*str) return false;
            c = *str;
            if ((c & 0xc0) != 0x80 ) 
                return false;
            ++str;
        } else if ((c & 0x0f) == 0xe0) {
            ++str;
            if (!*str) return false;
            c = *str;
            if ((c & 0xc0) != 0x80 ) 
                return false;
            ++str;
            if (!*str) return false;
            c = *str;
            if ((c & 0xc0) != 0x80 ) 
                return false;
            ++str;
        } else {
            return false;
        }
    }
    return true;
}
struct utf8_to_jchar_array_converter {
    size_t size;
    jchar* buffer;
    size_t allocated;
    utf8_to_jchar_array_converter() {
        size = 0;
        allocated = 32;
        buffer = static_cast<jchar*>(::malloc(sizeof(jchar)*allocated));
    }
    ~utf8_to_jchar_array_converter() {
        ::free(buffer);
    }
    void reallocate() {
        allocated = allocated * 2;
        buffer = static_cast<jchar*>(::realloc(buffer,sizeof(jchar)*allocated));
    }
    static const char* get_char(const char* s,uint32_t& ch) {
        unsigned int length;
    
        const unsigned char* str = reinterpret_cast<const unsigned char*>(s);
        
        if (*str < UTF8_BYTE_MARK)
        {
            ch = *str;
            return s + 1;
        }
        else if (*str < 0xC0)
        {
            ch = ' ';
            return s + 1;
        }
        else if (*str < 0xE0) length = 2;
        else if (*str < 0xF0) length = 3;
        else if (*str < 0xF8) length = 4;
        else
        {
            ch = ' ';
            return s + 1;
        }
        
        ch = (*str++ & ~UTF8_FIRST_BYTE_MARK[length]);
        if (!*str) {
            ch = ' ';
            length = 0;
        }
        // Scary scary fall throughs.
        switch (length)
        {
            case 4:
                ch <<= 6;
                ch += (*str++ & UTF8_BYTE_MASK_READ);
                if (!*str) {
                    ch = ' ';
                    break;
                }
            case 3:
                ch <<= 6;
                ch += (*str++ & UTF8_BYTE_MASK_READ);
                if (!*str) {
                    ch = ' ';
                    break;
                }
            case 2:
                ch <<= 6;
                ch += (*str++ & UTF8_BYTE_MASK_READ);
        }
        
        return reinterpret_cast<const char*>(str);
    }
    void convert(const char* str) {
        while (*str) {
            uint32_t ch = 0;
            str = get_char(str,ch);
            if (size>=allocated) {
                reallocate();
            }
            if (ch < 0x10000) {
                buffer[size++] = static_cast<uint16_t>(ch);
            } else {
                uint32_t msh = static_cast<uint32_t>(ch - 0x10000) >> 10;
                buffer[size++] = static_cast<uint16_t>(0xD800 + msh);
                if (size>=allocated) {
                    reallocate();
                }
                uint32_t lsh = static_cast<uint32_t>(ch - 0x10000) & 0x3ff;
                buffer[size++] = static_cast<uint16_t>(0xDC00 + lsh);
            }
        }
    }
};

GHL_API jstring GHL_CALL GHL_JNI_CreateStringUTF8(JNIEnv* env,const char* str) {
    if (!str) {
        return 0;
    }
    if (check_utf8(str)) {
        return env->NewStringUTF(str);
    } else {
        utf8_to_jchar_array_converter c;
        c.convert(str);
        jstring res = env->NewString(c.buffer,c.size);
        return res;
    }
    return 0;
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_GHL_Activity_nativeOnKey
  (JNIEnv *, jclass, jlong instance,jint key_code, jlong unicode, jlong action) {
    if (instance) {
        reinterpret_cast<GHL::GHLActivity*>(instance)->onJavaKey(key_code,unicode,action);
        return true;
    }
    return false;
  }

extern "C" JNIEXPORT void JNICALL Java_com_GHL_Activity_nativeOnScreenRectChanged
  (JNIEnv *, jclass, jlong instance,jint left, jint top, jint width, jint height) {
    if (instance) {
       LOG_INFO("nativeOnScreenRectChanged " << left << "," << top << "," << width << "," << height);
       if (instance) {
            reinterpret_cast<GHL::GHLActivity*>(instance)->OnVisibleRectChanged(left,top,width,height);
       }
       
    };
  }

extern "C" JNIEXPORT void JNICALL Java_com_GHL_Activity_nativeOnTextInputDismiss
  (JNIEnv *, jclass, jlong instance) {
    if (instance) {
        reinterpret_cast<GHL::GHLActivity*>(instance)->onTextInputDismiss();
    }
  }

extern "C" JNIEXPORT void JNICALL Java_com_GHL_Activity_nativeOnTextInputAccepted
  (JNIEnv *env, jclass, jlong instance, jstring text) {
    if (instance) {
        std::string temp_text = get_string(env,text);
        reinterpret_cast<GHL::GHLActivity*>(instance)->onTextInputAccepted(temp_text);
    }
  }

extern "C" JNIEXPORT void JNICALL Java_com_GHL_Activity_nativeOnTextInputChanged
  (JNIEnv * env, jclass, jlong instance, jstring text) {
    if (instance) {
        std::string temp_text = get_string(env,text);
        reinterpret_cast<GHL::GHLActivity*>(instance)->onTextInputChanged(temp_text);
    }
  }

  extern "C" JNIEXPORT void JNICALL Java_com_GHL_Activity_nativeOnKeyboardHide
  (JNIEnv * env, jclass,jlong instance) {
    if (instance) {
        reinterpret_cast<GHL::GHLActivity*>(instance)->onKeyboardHide();
    }
  }

  extern "C" JNIEXPORT jboolean JNICALL Java_com_GHL_Activity_nativeOnIntent
  (JNIEnv * env,jclass, jlong instance, jobject intent) {
    if (instance) {
        return reinterpret_cast<GHL::GHLActivity*>(instance)->onIntent(env,intent) ? JNI_TRUE : JNI_FALSE;
    }
    return JNI_FALSE;
  }

  

static GHL::GHLActivity* g_active_instance = 0;

static void ANativeActivity_onDestroy(ANativeActivity* activity) {
    if ( activity && activity->instance ) {
        GHL::GHLActivity* instance = static_cast<GHL::GHLActivity*>(activity->instance);
        instance->OnDestroy();
        if (g_active_instance == instance) {
            g_active_instance = 0;
        }
        delete instance;
    }
}

static void ANativeActivity_onStart(ANativeActivity* activity) {
    if (activity && activity->instance) {
        static_cast<GHL::GHLActivity*>(activity->instance)->OnStart();
    }
}
static void ANativeActivity_onStop(ANativeActivity* activity) {
    if (activity && activity->instance) {
        static_cast<GHL::GHLActivity*>(activity->instance)->OnStop();
    }
}
static void ANativeActivity_onPause(ANativeActivity* activity) {
    if (activity && activity->instance) {
        static_cast<GHL::GHLActivity*>(activity->instance)->OnPause();
    }
}
static void ANativeActivity_onResume(ANativeActivity* activity) {
    if (activity && activity->instance) {
        static_cast<GHL::GHLActivity*>(activity->instance)->OnResume();
    }
}
static void ANativeActivity_onConfigurationChanged(ANativeActivity* activity) {
    if (activity && activity->instance) {
        static_cast<GHL::GHLActivity*>(activity->instance)->OnConfigurationChanged();
    }
}
static void ANativeActivity_onLowMemory(ANativeActivity* activity) {
    if (activity && activity->instance) {
        static_cast<GHL::GHLActivity*>(activity->instance)->OnLowMemory();
    }
}
static void ANativeActivity_onWindowFocusChanged(ANativeActivity* activity,int focus) {
    if (activity && activity->instance) {
        static_cast<GHL::GHLActivity*>(activity->instance)->OnWindowFocusChanged(focus);
    }
}
static void ANativeActivity_onNativeWindowCreated(ANativeActivity* activity,ANativeWindow* window) {
    if (activity && activity->instance) {
        static_cast<GHL::GHLActivity*>(activity->instance)->OnNativeWindowCreated(window);
    }
}
static void ANativeActivity_onNativeWindowDestroyed(ANativeActivity* activity,ANativeWindow* window) {
    if (activity && activity->instance) {
        static_cast<GHL::GHLActivity*>(activity->instance)->OnNativeWindowDestroyed(window);
    }
}
static void ANativeActivity_onNativeWindowResized(ANativeActivity* activity,ANativeWindow* window) {
    if (activity && activity->instance) {
        static_cast<GHL::GHLActivity*>(activity->instance)->OnNativeWindowResized(window);
    }
}
static void ANativeActivity_onInputQueueCreated(ANativeActivity* activity,AInputQueue* queue) {
    if (activity && activity->instance) {
        static_cast<GHL::GHLActivity*>(activity->instance)->OnInputQueueCreated(queue);
    }
}
static void ANativeActivity_onInputQueueDestroyed(ANativeActivity* activity,AInputQueue* queue) {
    if (activity && activity->instance) {
        static_cast<GHL::GHLActivity*>(activity->instance)->OnInputQueueDestroyed(queue);
    }
}
static void ANativeActivity_onContentRectChanged(ANativeActivity* activity,const ARect* rect) {
    if (activity && activity->instance) {
        static_cast<GHL::GHLActivity*>(activity->instance)->OnContentRectChanged(rect);
    }
}


extern "C" JNIEXPORT void ANativeActivity_onCreate(ANativeActivity* activity,
                                  void* savedState, size_t savedStateSize) {

        activity->env->GetJavaVM(&g_jvm);

        GHL_Log(GHL::LOG_LEVEL_INFO,"Create\n");
        if (g_active_instance) {
            GHL_Log(GHL::LOG_LEVEL_ERROR,"Destroy active instance\n");
            g_active_instance->OnDestroy();
        }

        g_main_thread_id = GHL_GetCurrentThreadId();

        activity->callbacks->onDestroy = &ANativeActivity_onDestroy;
        activity->callbacks->onStart = &ANativeActivity_onStart;
        activity->callbacks->onResume = &ANativeActivity_onResume;
        activity->callbacks->onPause = &ANativeActivity_onPause;
        activity->callbacks->onStop = &ANativeActivity_onStop;
        activity->callbacks->onConfigurationChanged = &ANativeActivity_onConfigurationChanged;
        activity->callbacks->onLowMemory = &ANativeActivity_onLowMemory;
        activity->callbacks->onWindowFocusChanged = &ANativeActivity_onWindowFocusChanged;
        activity->callbacks->onNativeWindowCreated = &ANativeActivity_onNativeWindowCreated;
        activity->callbacks->onNativeWindowDestroyed = &ANativeActivity_onNativeWindowDestroyed;
        activity->callbacks->onNativeWindowResized = &ANativeActivity_onNativeWindowResized;
        activity->callbacks->onInputQueueCreated = &ANativeActivity_onInputQueueCreated;
        activity->callbacks->onInputQueueDestroyed = &ANativeActivity_onInputQueueDestroyed;
        activity->callbacks->onContentRectChanged = &ANativeActivity_onContentRectChanged;
        
        GHL::GHLActivity* ghl_activity = new GHL::GHLActivity(activity, savedState, savedStateSize);
        activity->instance = ghl_activity;
        g_active_instance = ghl_activity;
        

        jclass ActivityClass = activity->env->GetObjectClass(activity->clazz);
        jmethodID method = activity->env->GetMethodID(ActivityClass, "setInstance" ,"(J)V");
        if (activity->env->ExceptionCheck()) {
            activity->env->ExceptionDescribe();
            activity->env->ExceptionClear();
            ILOG_INFO("[native] not found method setInstance");
        }
        activity->env->CallVoidMethod(activity->clazz,method,reinterpret_cast<jlong>(ghl_activity));
        activity->env->DeleteLocalRef(ActivityClass);

        ghl_activity->OnCreate();
}

GHL_API GHL::UInt32 GHL_CALL GHL_GetCurrentThreadId() {
    return (GHL::UInt32) pthread_self();
}
static pthread_mutex_t ghl_system_mutex = PTHREAD_MUTEX_INITIALIZER;

GHL_API void GHL_CALL GHL_GlobalLock() {
    pthread_mutex_lock(&ghl_system_mutex);
}

GHL_API void GHL_CALL GHL_GlobalUnlock() {
    pthread_mutex_unlock(&ghl_system_mutex);
}

GHL_API int GHL_CALL GHL_StartApplication( GHL::Application* app,int argc, char** argv) {
    temp_app = app;
    GHL_Log(GHL::LOG_LEVEL_INFO,"GHL_StartApplication\n");
    return 0;
}
    
