#include "ghl_application.h"
#include "ghl_settings.h"
#include "ghl_vfs.h"
#include "ghl_keys.h"
#include "../ghl_log_impl.h"
#include "../render/render_impl.h"
#include "../image/image_decoders.h"
#include "../vfs/vfs_posix.h"
#include "ghl_system.h"
#include "ghl_event.h"
#include <string>
#include <iostream>


#include <sys/time.h>
#include <EGL/EGL.h>
#include <emscripten.h>
#include <emscripten/html5.h>

static const char* MODULE = "WinLib";
static GHL::Application* g_application = 0;
static double g_last_time = 0;
static bool g_done = false;
static GHL::RenderImpl* g_render = 0;
static GHL::UInt32 g_frame_interval = 0;
static bool g_window_resizeable = false;
static EGLDisplay g_egl_display = EGL_NO_DISPLAY;
static EGLSurface g_egl_surface = EGL_NO_SURFACE;
static EGLContext g_egl_context = EGL_NO_CONTEXT;
static double g_pixel_ratio = 1.0;
static bool g_system_input_active = false;

extern "C" EMSCRIPTEN_KEEPALIVE void  GHL_Winlib_OnSystemInputTextChanged(const char* text) {
    if (g_application) {
        GHL::Event e;
        e.type = GHL::EVENT_TYPE_TEXT_INPUT_TEXT_CHANGED;
        e.data.text_input_text_changed.text = text;
        e.data.text_input_text_changed.cursor_position = 0;
        g_application->OnEvent(&e);
    }
}

extern "C" EMSCRIPTEN_KEEPALIVE void  GHL_Winlib_OnSystemInputTextAccepted(const char* text) {
    if (g_application) {
        GHL::Event e;
        e.type = GHL::EVENT_TYPE_TEXT_INPUT_ACCEPTED;
        e.data.text_input_accepted.text = text;
        g_application->OnEvent(&e);
    }
}

static void show_system_input(const GHL::TextInputConfig* input) {
    EM_ASM({
        let input = document.getElementById("ghl-system-input");
        let canvas = document.getElementById('canvas');
        if (!input || input === undefined) {
            
            input = document.createElement("input");
            input.id = 'ghl-system-input';
            input.type = 'text';
            input.style.width = '100%';
            input.style.position = 'absolute';
            input.style.left = '0px';
            input.style['z-index']='10';
            input.setAttribute('class','emscripten');
            input = canvas.parentElement.appendChild(input);
           

            input.oninput = function() {
                let text = input.value;;
                let length = lengthBytesUTF8(text)+1;
                let buffer = Module._malloc(length);
                stringToUTF8(text,buffer,length);
                Module['_GHL_Winlib_OnSystemInputTextChanged'](buffer);
                _free(buffer);
            };

            input.addEventListener("keyup", function(event) {
                event.preventDefault();
                if (event.keyCode === 13) {
                    let text = input.value;;
                    let length = lengthBytesUTF8(text)+1;
                    let buffer = Module._malloc(length);
                    stringToUTF8(text,buffer,length);
                    Module['_GHL_Winlib_OnSystemInputTextAccepted'](buffer);
                    _free(buffer);
                };
            });
        };
        input.style.display = 'block';
        input.style.bottom = '0px';
        input.value = '';
        input.focus();
    });
    if (input->max_length!=0) {
        EM_ASM({
           let input = document.getElementById("ghl-system-input");
           input.maxlength = $0;
        },input->max_length);
    }
    if (input->placeholder) {
        EM_ASM({
           let input = document.getElementById("ghl-system-input");
           input.placeholder = Pointer_stringify($0);
        },input->placeholder);
    }
    g_system_input_active = true;
}

static void hide_system_input() {
    EM_ASM({
        let input = document.getElementById("ghl-system-input");
        if (input && input !== undefined) {
            input.style.display = 'none';
        };
    });
    g_system_input_active = false;
}


class SystemEmscripten : public GHL::System {
private:
public:
    explicit SystemEmscripten() {
    }
    ~SystemEmscripten() {
    }
    virtual void GHL_CALL Exit() {
        
    }
    
    ///
    virtual bool GHL_CALL IsFullscreen() const {
        return false;
    }
    ///
    virtual void GHL_CALL SwitchFullscreen(bool fs) {
        /// do nothing
    }
    
    virtual void GHL_CALL ShowKeyboard(const GHL::TextInputConfig* input) {
        if (input && input->system_input) {
            show_system_input(input);
        }
    }
        
    ///
    virtual void GHL_CALL HideKeyboard() {
        hide_system_input();
    }
    
    virtual GHL::UInt32  GHL_CALL GetKeyMods() const {
        return 0;
    }
    ///
    virtual bool GHL_CALL SetDeviceState( GHL::DeviceState name, const void* data) {
        if (name == GHL::DEVICE_STATE_RESIZEABLE_WINDOW) {
            bool enabled = *(const bool*)data;
            g_window_resizeable = enabled;
            return true;
        }
        else if (name==GHL::DEVICE_STATE_FRAME_INTERVAL) {
            const GHL::Int32* state = static_cast<const GHL::Int32*>(data);
            g_frame_interval = *state;
            return true;
        } 
        return false;
    }
    ///
    virtual bool GHL_CALL GetDeviceData( GHL::DeviceData name, void* data) {
        return false;
    }
    ///
    virtual void GHL_CALL SetTitle( const char* title ) {
        /// do nothing
    }
    virtual bool GHL_CALL OpenURL( const char* url ) {
        /// @todo
        return false;
    }
    virtual GHL::Font* GHL_CALL CreateFont( const GHL::FontConfig* config ) {
        return 0;
    }
};

static GHL::Key translate_key(const EmscriptenKeyboardEvent *keyEvent) {
    switch (keyEvent->keyCode) {
        case 37:     return GHL::KEY_LEFT;
        case 39:     return GHL::KEY_RIGHT;
        case 38:     return GHL::KEY_UP;
        case 40:     return GHL::KEY_DOWN;
        case 27:     return GHL::KEY_ESCAPE;
        case 13:     return GHL::KEY_ENTER;
        case 8:      return GHL::KEY_BACKSPACE;
    }
    return GHL::KEY_NONE;
}
// static GHL::UInt32 translate_mods(Uint16 mods) {
//     GHL::UInt32 res = 0;
//     if (mods & KMOD_SHIFT) {
//         res |= GHL::KEYMOD_SHIFT;
//     }
//     if (mods & KMOD_CTRL) {
//         res |= GHL::KEYMOD_CTRL;
//     }
//     if (mods & KMOD_ALT) {
//         res |= GHL::KEYMOD_ALT;
//     }
//     return res;
// };
// static GHL::UInt32 parse_charcode(const char* data) {
//     const GHL::Byte* str = reinterpret_cast<const GHL::Byte*>(data);
//     GHL::UInt32 ch = 0;
//     unsigned int length = 0;
//     if (*str < 0x80) {
//         ch = *str;
//         return ch;
//     } else if (*str < 0xC0){
//         ch = ' ';
//         return ch;
//     } else if (*str < 0xE0) {
//         length = 2;
//         ch = *str & ~0xC0;
//     }
//     else if (*str < 0xF0) {
//         length = 3;
//         ch = *str & ~0xE0;
//     }
//     else if (*str < 0xF8) {
//         length = 4;
//         ch = *str & ~0xF0;
//     } 
//     else
//     {
//         ch = ' ';
//         return ch;
//     }
//     ++str;
//     switch (length)
//     {
//         case 4:
//             ch <<= 6;
//             ch |= (*str++ & 0x3F);
//         case 3:
//             ch <<= 6;
//             ch |= (*str++ & 0x3F);
//         case 2:
//             ch <<= 6;
//             ch |= (*str++ & 0x3F);
//     }
//     return ch;
// };

static EM_BOOL
emscripten_handle_mouse_move(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData) {
    if (g_application) {
        GHL::Event ae;
        ae.type = GHL::EVENT_TYPE_MOUSE_MOVE;
        ae.data.mouse_move.button =  GHL::MOUSE_BUTTON_LEFT;
        ae.data.mouse_move.modificators = 0;
        ae.data.mouse_move.x = mouseEvent->canvasX * g_pixel_ratio;
        ae.data.mouse_move.y = mouseEvent->canvasY * g_pixel_ratio;
        g_application->OnEvent(&ae);
    }
    return EM_TRUE;
}

static EM_BOOL
emscripten_handle_mouse_button(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData) {
    if (g_application) {
        GHL::Event ae;
        if (eventType == EMSCRIPTEN_EVENT_MOUSEDOWN) {
            ae.type = GHL::EVENT_TYPE_MOUSE_PRESS;
            ae.data.mouse_press.button =  GHL::MOUSE_BUTTON_LEFT;
            ae.data.mouse_press.modificators = 0;
            ae.data.mouse_press.x = mouseEvent->canvasX * g_pixel_ratio;;
            ae.data.mouse_press.y = mouseEvent->canvasY * g_pixel_ratio;;
        } else {
            ae.type = GHL::EVENT_TYPE_MOUSE_RELEASE;
            ae.data.mouse_press.button =  GHL::MOUSE_BUTTON_LEFT;
            ae.data.mouse_press.modificators = 0;
            ae.data.mouse_press.x = mouseEvent->canvasX * g_pixel_ratio;;
            ae.data.mouse_press.y = mouseEvent->canvasY * g_pixel_ratio;;
        }
        g_application->OnEvent(&ae);
    }
    return EM_TRUE;
}

static EM_BOOL
emscripten_handle_key(int eventType, const EmscriptenKeyboardEvent *keyEvent, void *userData)
{
    if (g_system_input_active) 
        return EM_FALSE;
    if (g_application) {
        GHL::Key key = translate_key(keyEvent);
        if (key!=GHL::KEY_NONE) {
            GHL::Event ae;
            ae.data.key_press.key = key;
            if (eventType == EMSCRIPTEN_EVENT_KEYDOWN) {
                ae.type = GHL::EVENT_TYPE_KEY_PRESS;
                ae.data.key_press.charcode = 0;
                ae.data.key_press.modificators = 0;
            } else {
                ae.type = GHL::EVENT_TYPE_KEY_RELEASE;
                ae.data.key_press.charcode =  0;
                ae.data.key_press.modificators = 0;
            }
            g_application->OnEvent(&ae);
            return EM_TRUE;
        }
    }
    return EM_FALSE;
}


static EM_BOOL
emscripten_handle_key_press(int eventType, const EmscriptenKeyboardEvent *keyEvent, void *userData)
{
    if (g_system_input_active) 
        return EM_FALSE;
    if (g_application) {
        GHL::Event ae;
        ae.type = GHL::EVENT_TYPE_KEY_PRESS;
        ae.data.key_press.key = GHL::KEY_NONE;
        ae.data.key_press.charcode = keyEvent->charCode;
        ae.data.key_press.modificators = 0;
        g_application->OnEvent(&ae);
    }
    return EM_TRUE;
}

static EM_BOOL
emscripten_handle_resize(int eventType, const EmscriptenUiEvent *uiEvent, void *userData) {
    double w;
    double h;
    emscripten_get_element_css_size(NULL,&w,&h);
    emscripten_set_canvas_element_size("#canvas",w*g_pixel_ratio,h*g_pixel_ratio);
    if (g_render) {
        g_render->Resize(w*g_pixel_ratio,h*g_pixel_ratio);
    }
    return EM_TRUE;
}



static void loop_iteration(void* arg) {
    
    eglMakeCurrent(g_egl_display,g_egl_surface,g_egl_surface, g_egl_context);

    static GHL::UInt32 frame_cntr = 0;
    if (g_frame_interval != 0 ) {
        ++frame_cntr;
        if (frame_cntr < g_frame_interval) {
            return;
        }
        frame_cntr = 0;
    }

    double cur_time = emscripten_get_now();
    GHL::UInt32 delta = (cur_time - g_last_time)*1000;
    g_last_time = cur_time;

    g_application->OnFrame(delta);
    eglSwapBuffers(g_egl_display,g_egl_surface);
}

static SystemEmscripten g_system;

GHL_API int GHL_CALL GHL_StartApplication( GHL::Application* app , int /*argc*/, char** /*argv*/) {
    
    g_application = app;
    
    LOG_INFO(  "start" );
    
    GHL::VFS* vfs = GHL_CreateVFS();


    g_application->SetVFS(vfs);

    
    g_application->SetSystem(&g_system);

    {
        GHL::Event e;
        e.type = GHL::EVENT_TYPE_APP_STARTED;
        g_application->OnEvent(&e);
    }

    GHL::Settings settings;


    double w;
    double h;
    emscripten_get_element_css_size(NULL,&w,&h);
    g_pixel_ratio = emscripten_get_device_pixel_ratio();
    LOG_INFO("initial size: " << w << "x" << h);
    settings.width = w * g_pixel_ratio;
    settings.height = h * g_pixel_ratio;
    settings.depth = false;
    settings.screen_dpi = 50 * emscripten_get_device_pixel_ratio();


    app->FillSettings(&settings);

    GHL::ImageDecoderImpl image_decoder;
    g_application->SetImageDecoder(&image_decoder);


    g_egl_display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    if (g_egl_display == EGL_NO_DISPLAY) {
        LOG_ERROR("failed get display");
        return 1;
    }
    if (eglInitialize(g_egl_display,0,0)!=EGL_TRUE) {
        LOG_ERROR("failed initialize display");
        return 1;
    }
   
    eglBindAPI(EGL_OPENGL_ES_API);

    EGLint config_attribs[] = {
        EGL_RED_SIZE, 8,
        EGL_GREEN_SIZE, 8,
        EGL_BLUE_SIZE, 8,
        EGL_DEPTH_SIZE, settings.depth ? 24 : EGL_DONT_CARE,
        EGL_STENCIL_SIZE, settings.depth ? 8 : EGL_DONT_CARE,
        EGL_RENDERABLE_TYPE,EGL_OPENGL_ES2_BIT,
        EGL_NONE
    };
    EGLConfig configs[16];
    EGLint found_configs = 0;
    if (eglChooseConfig(g_egl_display,config_attribs,configs,16,&found_configs) == EGL_FALSE ||
            found_configs == 0) {
        LOG_ERROR("failed choose config");
        return 1;
    }
    EGLint context_attribs[] = {
        EGL_CONTEXT_CLIENT_VERSION,2,
        EGL_NONE
    };

    g_egl_context = eglCreateContext(g_egl_display,configs[0],EGL_NO_CONTEXT,context_attribs);
    if (g_egl_context == EGL_NO_CONTEXT) {
         LOG_ERROR("failed create context");
        return 1;
    }

    eglMakeCurrent(g_egl_display,g_egl_surface,g_egl_surface, g_egl_context);

    g_done = false;
    LOG_INFO("create render " << settings.width << "x" << settings.height);
    emscripten_set_canvas_element_size("#canvas",settings.width,settings.height);
    g_render = GHL_CreateRenderOpenGL(settings.width,settings.height,settings.depth);
    if ( g_render && g_application ) {
        g_application->SetRender(g_render);
        if (!g_application->Load()) {
            LOG_ERROR(  "not loaded" );
            g_done = true;
        }
    } else {
         LOG_ERROR(  "not started" );
         g_done = true;
    }


    emscripten_set_mousedown_callback("#canvas", 0, 0, emscripten_handle_mouse_button);
    emscripten_set_mouseup_callback("#document", 0, 0, emscripten_handle_mouse_button);
    emscripten_set_mousemove_callback("#canvas", 0, 0, emscripten_handle_mouse_move);
    emscripten_set_resize_callback("#canvas",0,0, emscripten_handle_resize);

    emscripten_set_keydown_callback("#window", 0, 0, emscripten_handle_key);
    emscripten_set_keyup_callback("#window", 0, 0, emscripten_handle_key);
    emscripten_set_keypress_callback("#window", 0, 0, emscripten_handle_key_press);

    g_last_time = emscripten_get_now();
    while (!g_done) {
        emscripten_set_main_loop_arg(loop_iteration, &g_system,0, 1);

        LOG_INFO(  "done" );
    }

    
    //SDL_GL_DeleteContext(glcontext);  
    // Cleanup
   
    GHL_DestroyVFS(vfs);
    //SDL_Quit();

    return 0;
}

GHL_API GHL::UInt32 GHL_CALL GHL_GetCurrentThreadId() {
    return 1;
}

GHL_API void GHL_CALL GHL_GlobalLock() {
    
}

GHL_API void GHL_CALL GHL_GlobalUnlock() {
    
}

GHL_API void GHL_CALL GHL_Log( GHL::LogLevel level,const char* message) {
    static const char* levelName[] = {
        "F:",
        "E:",
        "W:",
        "I:",
        "V:",
        "D:"
    };
    std::cout << levelName[level] << message << std::endl;
}