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

static const char* MODULE = "WinLib";

char message_buffer[256];

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

static GHL::Application* temp_app = 0;

int ghl_android_app_main(int argc,char** argv);
static GHL::Application* android_app_create() {
    ghl_android_app_main(0,0);
    return temp_app;
}

static GHL::Key convert_key(uint32_t k) {
    switch (k) {
        case AKEYCODE_ENTER: return GHL::KEY_ENTER;
        case AKEYCODE_DEL: return GHL::KEY_BACKSPACE;
    }
    return GHL::KEY_NONE;
}


namespace GHL {


    ANativeActivity* g_native_activity = 0;

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
            m_display = EGL_NO_DISPLAY;
            m_context = EGL_NO_CONTEXT;
            m_surface = EGL_NO_SURFACE;
            
            pthread_mutex_init(&m_mutex, NULL);
            pthread_cond_init(&m_cond, NULL);

        }
        ~GHLActivity() {
            delete m_vfs;
            pthread_cond_destroy(&m_cond);
            pthread_mutex_destroy(&m_mutex);
        }
        
        /// GHL::System impl
        /// Exit from application
        virtual void GHL_CALL Exit() {
            
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
            jmethodID method = m_activity->env->GetMethodID(ActivityClass,visible ? "showSoftKeyboard" : "hideSoftKeyboard","()V");
            if (m_activity->env->ExceptionCheck()) {
                m_activity->env->ExceptionDescribe();
                m_activity->env->ExceptionClear();
                ILOG_INFO("[native] not found method");
                return false;
            }
            m_activity->env->CallVoidMethod(m_activity->clazz,method);
            m_activity->env->DeleteLocalRef(ActivityClass);
            return true;
        }
        /// Show soft keyboard
        virtual void GHL_CALL ShowKeyboard() {
            if (!set_keyboard_visible(true))
                ANativeActivity_showSoftInput(m_activity,ANATIVEACTIVITY_SHOW_SOFT_INPUT_FORCED);
        }
        /// Hide soft keyboard
        virtual void GHL_CALL HideKeyboard() {
            if (!set_keyboard_visible(false))
                ANativeActivity_hideSoftInput(m_activity,0);
        }
        /// Get current key modifiers state
        virtual UInt32  GHL_CALL GetKeyMods() const {
            return 0;
        }
        /// Set device specific state
        virtual bool GHL_CALL SetDeviceState( DeviceState name, const void* data) {
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
            }
            return false;
        }
        /// Set window title
        virtual void GHL_CALL SetTitle( const char* title ) {
            
        }
        static const unsigned int AWINDOW_FLAG_KEEP_SCREEN_ON = 0x00000080;
        void OnCreate() {
            LOG_INFO("OnCreate");
            g_native_activity = m_activity;
            ANativeActivity_setWindowFlags(m_activity, AWINDOW_FLAG_KEEP_SCREEN_ON, 0);

            m_app = android_app_create();

            if (m_app) {
                m_app->SetSystem(this);
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
            g_native_activity = m_activity;
            StartTimerThread();
        }
        void OnResume() {
            LOG_INFO("OnResume");
            g_native_activity = m_activity;
            if (m_app) {
                GHL::Event e;
                e.type = GHL::EVENT_TYPE_ACTIVATE;
                m_app->OnEvent(&e);
            }
        }
        void* onSaveInstanceState(size_t* outSize) {
            return 0;
        }
        void OnPause() {
            LOG_INFO("OnPause");
            g_native_activity = m_activity;
            if (m_app) {
                GHL::Event e;
                e.type = GHL::EVENT_TYPE_DEACTIVATE;
                m_app->OnEvent(&e);
            }
        }
        void OnStop() {
            LOG_INFO("OnStop");
            g_native_activity = m_activity;
            StopTimerThread();
        }
        void OnDestroy() {
            LOG_INFO("OnDestroy");
            if (m_app) {
                m_app->Release();
                m_app = 0;
            }
        }
        void OnWindowFocusChanged(int hasFocus) {
            LOG_VERBOSE("OnWindowFocusChanged:" << hasFocus);
            m_sound.SetFocus(hasFocus);
        }
        void DestroyContext() {
            eglMakeCurrent(m_display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
            if (m_context != EGL_NO_CONTEXT) {
                eglDestroyContext(m_display, m_context);
                m_context = EGL_NO_CONTEXT;
            }
            if (m_surface != EGL_NO_SURFACE) {
                eglDestroySurface(m_display, m_surface);
                m_surface = EGL_NO_SURFACE;
            }
        }
        bool CreateContext(const EGLint* attribs) {
            EGLConfig config = 0;
            EGLint numConfigs;
            EGLint format;

             /* Here, the application chooses the configuration it desires. In this
             * sample, we have a very simplified selection process, where we pick
             * the first EGLConfig that matches our criteria */
            eglChooseConfig(m_display, attribs, &config, 1, &numConfigs);
            
            /* EGL_NATIVE_VISUAL_ID is an attribute of the EGLConfig that is
             * guaranteed to be accepted by ANativeWindow_setBuffersGeometry().
             * As soon as we picked a EGLConfig, we can safely reconfigure the
             * ANativeWindow buffers to match, using EGL_NATIVE_VISUAL_ID. */
            eglGetConfigAttrib(m_display, config, EGL_NATIVE_VISUAL_ID, &format);
            
            ANativeWindow_setBuffersGeometry(m_window, 0, 0, format);
            
            m_surface = eglCreateWindowSurface(m_display, config, m_window, NULL);
            const EGLint ctx_attribs[] = {
                EGL_CONTEXT_CLIENT_VERSION,
                2,
                EGL_NONE
            };
            m_context = eglCreateContext(m_display, config, NULL, ctx_attribs);
            
            if (eglMakeCurrent(m_display, m_surface, m_surface, m_context) == EGL_FALSE) {
                GHL_Log(GHL::LOG_LEVEL_ERROR,"Unable to eglMakeCurrent");
                return false ;
            }
            return true;
        }
        void OnNativeWindowCreated(ANativeWindow* window) {
            LOG_INFO("OnNativeWindowCreated");
            g_native_activity = m_activity;
            if (m_window==0) {
                
                
                 if (m_app && m_sound.SoundInit()) {
                     m_app->SetSound(&m_sound);
                 }
                
                m_window = window;
                // initialize OpenGL ES and EGL
                
                /*
                 * Here specify the attributes of the desired configuration.
                 * Below, we select an EGLConfig with at least 8 bits per color
                 * component compatible with on-screen windows
                 */
                const EGLint attribs[] = {
                    EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
                    EGL_BLUE_SIZE, 8,
                    EGL_GREEN_SIZE, 8,
                    EGL_RED_SIZE, 8,
                    EGL_NONE
                };
                EGLint w, h, dummy;
                
                
                m_display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
                
                EGLint major=0;
                EGLint minor=0;
                if (eglInitialize(m_display, &major, &minor)!=EGL_TRUE) {
                    LOG_ERROR("Unable to eglInitialize");
                    return;
                } else {
                    LOG_INFO("EGL: " << major << "." << minor);
                }
                
                CreateContext(attribs);
                
                eglQuerySurface(m_display, m_surface, EGL_WIDTH, &w);
                eglQuerySurface(m_display, m_surface, EGL_HEIGHT, &h);
                
                GHL::Settings settings;
                /// default settings
                settings.width = w;
                settings.height = h;
                settings.fullscreen = true;
                settings.depth = false;
                if (m_app)
                {
                    m_app->FillSettings(&settings);
                    if (m_activity->env->ExceptionCheck()) {
                        return;
                    }
                }

                if (settings.depth) {
                    DestroyContext();
                     const EGLint depth_attribs[] = {
                        EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
                        EGL_BLUE_SIZE, 8,
                        EGL_GREEN_SIZE, 8,
                        EGL_RED_SIZE, 8,
                        EGL_DEPTH_SIZE, 16,
                        EGL_NONE
                    };
                    CreateContext(depth_attribs);
                }

                
                m_render = GHL_CreateRenderOpenGL(w,h,settings.depth);
                if ( m_render && m_app ) {
                    m_app->SetRender(m_render);
                    m_app->Load();
                    if (m_activity->env->ExceptionCheck()) {
                        return;
                    }
                }
                Render();
            } else {
                LOG_INFO("skip another window");
            }
        }
        void OnNativeWindowResized(ANativeWindow* window) {
            LOG_INFO("OnNativeWindowResized");
            g_native_activity = m_activity;
            if (window==m_window) {
                if ( m_render && m_context!=EGL_NO_CONTEXT ) {
                    if (eglMakeCurrent(m_display, m_surface, m_surface, m_context) == EGL_FALSE) {
                        GHL_Log(GHL::LOG_LEVEL_ERROR,"Unable to eglMakeCurrent");
                        return ;
                    }
                    EGLint w, h;
                    eglQuerySurface(m_display, m_surface, EGL_WIDTH, &w);
                    eglQuerySurface(m_display, m_surface, EGL_HEIGHT, &h);
                    m_render->Resize(w,h);
                    Render();
                }
            } else {
                LOG_INFO("skip another window");
            }
        }
        void OnNativeWindowRedrawNeeded(ANativeWindow* window) {
            
        }
        void OnNativeWindowDestroyed(ANativeWindow* window) {
            LOG_INFO("OnNativeWindowDestroyed");
            g_native_activity = m_activity;
            if (m_window==window) {
                
                
                if (m_render) {
                    if (m_app) {
                        m_app->Unload();
                    }
                    GHL_DestroyRenderOpenGL(m_render);
                    m_render = 0;
                }

                 m_sound.SoundDone();
               
                if (m_display != EGL_NO_DISPLAY) {
                    DestroyContext();
                    eglTerminate(m_display);
                }
                m_display = EGL_NO_DISPLAY;
                m_context = EGL_NO_CONTEXT;
                m_surface = EGL_NO_SURFACE;
                m_window = 0;
            } else {
                LOG_INFO("skip another window");
            }
        }
        void OnInputQueueCreated(AInputQueue* queue) {
            LOG_INFO("OnInputQueueCreated");
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
            LOG_INFO("OnInputQueueCreated");
            if (m_input_queue==queue) {
                AInputQueue_detachLooper(queue);
                m_input_queue = 0;
            }
        }
        void OnContentRectChanged(const ARect* rect) {
            if (m_render) {
                m_render->Resize(rect->right - rect->left, rect->bottom - rect->top );
            }
        }
        void OnConfigurationChanged() {
            
        }
        void OnLowMemory() {
            LOG_WARNING("OnLowMemory");
        }

        void onKey(int key_code,uint32_t unicode,int action) {
            if (!m_app) 
                return;
            if (AKEY_EVENT_ACTION_DOWN == action) {
                //ILOG_INFO("AKEY_EVENT_ACTION_DOWN " << key_code << " " << unicode);
                GHL::Event e;
                e.type = GHL::EVENT_TYPE_KEY_PRESS;
                e.data.key_press.key = convert_key(key_code);
                e.data.key_press.modificators = 0;
                e.data.key_press.charcode = unicode;
                m_app->OnEvent(&e);
            } else if (AKEY_EVENT_ACTION_UP == action) {
                //ILOG_INFO("AKEY_EVENT_ACTION_UP " << key_code << " " << unicode);
                GHL::Event e;
                e.type = GHL::EVENT_TYPE_KEY_RELEASE;
                e.data.key_release.key = convert_key(key_code);
                m_app->OnEvent(&e);
            } else {
                ILOG_INFO("unknown key event " << action);
            }
        }

    protected:
        bool HandleEvent(const AInputEvent* event) {
            g_native_activity = m_activity;
            if (AINPUT_EVENT_TYPE_MOTION==AInputEvent_getType(event)) {
                int x = int( AMotionEvent_getX(event,0) );
                int y = int( AMotionEvent_getY(event,0) );
                int32_t action = AMotionEvent_getAction(event);
                int32_t actionType = action & AMOTION_EVENT_ACTION_MASK;
                int32_t ptr = ( action & AMOTION_EVENT_ACTION_POINTER_INDEX_MASK ) >> AMOTION_EVENT_ACTION_POINTER_INDEX_SHIFT;
                GHL::MouseButton btn = GHL::TOUCH_1;
                if ( ptr!=0 ) {
                    /// @todo
                    /// support multitouch
                }
                if (m_app) {
                    GHL::Event e;
                    if ( action == AMOTION_EVENT_ACTION_DOWN ) {
                        e.type = GHL::EVENT_TYPE_MOUSE_PRESS;
                        e.data.mouse_press.button = btn;
                        e.data.mouse_press.modificators = 0;
                        e.data.mouse_press.x = x;
                        e.data.mouse_press.y = y;
                    } else if (action == AMOTION_EVENT_ACTION_UP) {
                        e.type = GHL::EVENT_TYPE_MOUSE_RELEASE;
                        e.data.mouse_release.button = btn;
                        e.data.mouse_release.modificators = 0;
                        e.data.mouse_release.x = x;
                        e.data.mouse_release.y = y;
                    } else if (action == AMOTION_EVENT_ACTION_MOVE) {
                        e.type = GHL::EVENT_TYPE_MOUSE_MOVE;
                        e.data.mouse_move.button = btn;
                        e.data.mouse_move.modificators = 0;
                        e.data.mouse_move.x = x;
                        e.data.mouse_move.y = y;
                    } else {
                        return false;
                    }
                    m_app->OnEvent(&e);
                }
                return true;
            } else if (AINPUT_EVENT_TYPE_KEY == AInputEvent_getType(event)) {
                int32_t key_code = AKeyEvent_getKeyCode(event);
                onKey(key_code,0,AKeyEvent_getAction(event));
            } else {
                LOG_INFO("unknown event type " << AInputEvent_getType(event));
            }
            return false;
        }
        
        void OnInputCallback() {
            g_native_activity = m_activity;
            if (m_input_queue) {
                AInputEvent* event = 0;
                while ( AInputQueue_getEvent(m_input_queue,&event)>=0 ) {
                    if (AInputQueue_preDispatchEvent(m_input_queue, event)) {
                       continue;
                    }
                    bool handled = HandleEvent(event);
                    AInputQueue_finishEvent(m_input_queue,event,handled?0:1);
                }
            }
        }
        void OnTimerCallback() {
            g_native_activity = m_activity;
            //LOG_DEBUG("OnTimerCallback");
            Render();
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
        void Render() {
            //LOG_DEBUG("Render ->");
            if (m_app && m_surface!=EGL_NO_SURFACE) {
                timeval now;
                gettimeofday(&now,0);
                GHL::UInt32 frameTime = (now.tv_sec-m_last_time.tv_sec)*1000000 + (now.tv_usec-m_last_time.tv_usec);
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

            const char *path_chars = m_activity->env->GetStringUTFChars( path_string, NULL );
            std::string temp_folder( path_chars );

            m_activity->env->ReleaseStringUTFChars( path_string, path_chars );
            
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
                        const char *language_chars = m_activity->env->GetStringUTFChars( language, NULL );
                        if (language_chars) {
                            result = language_chars;
                            m_activity->env->ReleaseStringUTFChars( language, language_chars );
                        }
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
        EGLContext          m_context;
        RenderImpl*         m_render;
        timeval             m_last_time;
        AInputQueue*        m_input_queue;
        static void* TimerThread(void* param);
        int m_msgread;
        int m_msgwrite;
        pthread_t   m_thread;
        pthread_mutex_t m_mutex;
        pthread_cond_t m_cond;
        enum {
            TS_NONE,
            TS_START,
            TS_RUNNING,
            TS_STOP,
            TS_STOPPED
        } m_timer_state;
    };
    template <void(GHLActivity::*func)()> static inline void proxy_func(ANativeActivity* activity) {
        if ( activity && activity->instance ) {
            ((static_cast<GHLActivity*>(activity->instance))->*(func))();
        }
    }
    template <class T,void(GHLActivity::*func)(T)> static inline void proxy_func_1(ANativeActivity* activity,T a) {
        if ( activity && activity->instance ) {
            ((static_cast<GHLActivity*>(activity->instance))->*(func))(a);
        }
    }
    template <class R,class T,R(GHLActivity::*func)(T)> static inline R proxy_func_2(ANativeActivity* activity,T a) {
        if ( activity && activity->instance ) {
            return ((static_cast<GHLActivity*>(activity->instance))->*(func))(a);
        }
        return 0;
    }

    
    void* GHLActivity::TimerThread(void* param) {
        GHLActivity* activity = static_cast<GHLActivity*>(param);
        
        pthread_mutex_lock(&activity->m_mutex);
        activity->m_timer_state = TS_RUNNING;
        int fd  = activity->m_msgwrite;
        pthread_cond_broadcast(&activity->m_cond);
        pthread_mutex_unlock(&activity->m_mutex);
        
        bool exit = false;
        while (!exit) {
            pthread_mutex_lock(&activity->m_mutex);
            exit = activity->m_timer_state==TS_STOP;
            pthread_mutex_unlock(&activity->m_mutex);
   
            if (!exit) {
                usleep(1000000/60);
                int8_t cmd = 1;
                if (write(fd, &cmd, sizeof(cmd)) != sizeof(cmd)) {
                    LOG_ERROR("Failure writing android_app cmd:" << strerror(errno));
                }
            }
            
        }
        
        pthread_mutex_lock(&activity->m_mutex);
        activity->m_timer_state = TS_STOPPED;
        pthread_cond_broadcast(&activity->m_cond);
        pthread_mutex_unlock(&activity->m_mutex);
        return NULL;
    }
    
    void GHLActivity::StartTimerThread() {

        jclass ActivityClass = m_activity->env->GetObjectClass(m_activity->clazz);
        jmethodID method = m_activity->env->GetMethodID(ActivityClass, "reportRenderThread","()V");
        if (m_activity->env->ExceptionCheck()) {
            m_activity->env->ExceptionDescribe();
            m_activity->env->ExceptionClear();
            LOG_INFO("[native] not found method reportRenderThread");
        } else {
            m_activity->env->CallVoidMethod(m_activity->clazz,method);
        }
        m_activity->env->DeleteLocalRef(ActivityClass);


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
        
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
        pthread_create(&m_thread, &attr, &GHLActivity::TimerThread , this);
        
        // Wait for thread to start.
        pthread_mutex_lock(&m_mutex);
        m_timer_state = TS_START;
        while (m_timer_state!=TS_RUNNING) {
            pthread_cond_wait(&m_cond, &m_mutex);
        }
        pthread_mutex_unlock(&m_mutex);

    }
    void GHLActivity::StopTimerThread() {
        pthread_mutex_lock(&m_mutex);
        m_timer_state = TS_STOP;
        while (m_timer_state!=TS_STOPPED) {
            pthread_cond_wait(&m_cond, &m_mutex);
        }
        pthread_mutex_unlock(&m_mutex);
        
        ALooper_removeFd(ALooper_forThread(),m_msgread);
        
        close(m_msgread);
        close(m_msgwrite);
        m_timer_state = TS_NONE;
    }
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_GHL_Activity_nativeOnKey
  (JNIEnv *, jclass, jint key_code, jlong unicode, jlong action) {
    if (GHL::g_native_activity) {
        static_cast<GHL::GHLActivity*>(GHL::g_native_activity->instance)->onKey(key_code,unicode,action);
        return true;
    }
    return false;
  }

extern "C" __attribute__ ((visibility ("default"))) void ANativeActivity_onCreate(ANativeActivity* activity,
                                                                                  void* savedState, size_t savedStateSize);
extern "C" {
    __attribute__ ((visibility ("default"))) void ANativeActivity_onCreate(ANativeActivity* activity,
                                  void* savedState, size_t savedStateSize) {
        GHL_Log(GHL::LOG_LEVEL_INFO,"Create\n");
        activity->callbacks->onDestroy = &GHL::proxy_func<&GHL::GHLActivity::OnDestroy>;
        activity->callbacks->onStart = &GHL::proxy_func<&GHL::GHLActivity::OnStart>;
        activity->callbacks->onResume = &GHL::proxy_func<&GHL::GHLActivity::OnResume>;
        //activity->callbacks->onSaveInstanceState = onSaveInstanceState;
        activity->callbacks->onPause = &GHL::proxy_func<&GHL::GHLActivity::OnPause>;
        activity->callbacks->onStop = &GHL::proxy_func<&GHL::GHLActivity::OnStop>;
        activity->callbacks->onConfigurationChanged = &GHL::proxy_func<&GHL::GHLActivity::OnConfigurationChanged>;
        activity->callbacks->onLowMemory = &GHL::proxy_func<&GHL::GHLActivity::OnLowMemory>;
        activity->callbacks->onWindowFocusChanged = &GHL::proxy_func_1<int,&GHL::GHLActivity::OnWindowFocusChanged>;
        activity->callbacks->onNativeWindowCreated = &GHL::proxy_func_1<ANativeWindow*,&GHL::GHLActivity::OnNativeWindowCreated>;
        activity->callbacks->onNativeWindowDestroyed = &GHL::proxy_func_1<ANativeWindow*,&GHL::GHLActivity::OnNativeWindowDestroyed>;
        activity->callbacks->onInputQueueCreated = &GHL::proxy_func_1<AInputQueue*,&GHL::GHLActivity::OnInputQueueCreated>;
        activity->callbacks->onInputQueueDestroyed = &GHL::proxy_func_1<AInputQueue*,&GHL::GHLActivity::OnInputQueueDestroyed>;
        GHL::GHLActivity* ghl_activity = new GHL::GHLActivity(activity, savedState, savedStateSize);
        activity->instance = ghl_activity;
        ghl_activity->OnCreate();
    }
}


GHL_API int GHL_CALL GHL_StartApplication( GHL::Application* app,int argc, char** argv) {
    temp_app = app;
    GHL_Log(GHL::LOG_LEVEL_INFO,"GHL_StartApplication\n");
    (void)&ANativeActivity_onCreate;
    return 0;
}
    
