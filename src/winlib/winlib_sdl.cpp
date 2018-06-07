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

#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>

#include <sys/time.h>

#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif

static const char* MODULE = "WinLib";
static GHL::Application* g_application = 0;
static Uint32 g_last_time;
static bool g_done = false;
static SDL_Window* g_window = 0;
static GHL::RenderImpl* g_render = 0;
static GHL::UInt32 g_height = 0;
static GHL::UInt32 g_width = 0;
static GHL::UInt32 g_frame_interval = 0;


class SystemSDL : public GHL::System {
private:
public:
    explicit SystemSDL() {
    }
    ~SystemSDL() {
    }
    virtual void GHL_CALL Exit() {
        SDL_Quit();
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
        SDL_StartTextInput();
    }
        
    ///
    virtual void GHL_CALL HideKeyboard() {
        SDL_StopTextInput();
    }
    
    virtual GHL::UInt32  GHL_CALL GetKeyMods() const {
        return 0;
    }
    ///
    virtual bool GHL_CALL SetDeviceState( GHL::DeviceState name, const void* data) {
        if (name == GHL::DEVICE_STATE_RESIZEABLE_WINDOW) {
            bool enabled = *(const bool*)data;
            SDL_SetWindowResizable(g_window,enabled?SDL_TRUE:SDL_FALSE);
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

static GHL::Key translate_key(SDL_Scancode sc) {
    switch (sc) {
        case SDL_SCANCODE_LEFT:     return GHL::KEY_LEFT;
        case SDL_SCANCODE_RIGHT:    return GHL::KEY_RIGHT;
        case SDL_SCANCODE_UP:       return GHL::KEY_UP;
        case SDL_SCANCODE_DOWN:     return GHL::KEY_DOWN;
        case SDL_SCANCODE_ESCAPE:   return GHL::KEY_ESCAPE;
        case SDL_SCANCODE_RETURN:   return GHL::KEY_ENTER;
        case SDL_SCANCODE_BACKSPACE:return GHL::KEY_BACKSPACE;
    }
    return GHL::KEY_NONE;
}
static GHL::UInt32 translate_mods(Uint16 mods) {
    GHL::UInt32 res = 0;
    if (mods & KMOD_SHIFT) {
        res |= GHL::KEYMOD_SHIFT;
    }
    if (mods & KMOD_CTRL) {
        res |= GHL::KEYMOD_CTRL;
    }
    if (mods & KMOD_ALT) {
        res |= GHL::KEYMOD_ALT;
    }
    return res;
};
static GHL::UInt32 parse_charcode(const char* data) {
    const GHL::Byte* str = reinterpret_cast<const GHL::Byte*>(data);
    GHL::UInt32 ch = 0;
    unsigned int length = 0;
    if (*str < 0x80) {
        ch = *str;
        return ch;
    } else if (*str < 0xC0){
        ch = ' ';
        return ch;
    } else if (*str < 0xE0) {
        length = 2;
        ch = *str & ~0xC0;
    }
    else if (*str < 0xF0) {
        length = 3;
        ch = *str & ~0xE0;
    }
    else if (*str < 0xF8) {
        length = 4;
        ch = *str & ~0xF0;
    } 
    else
    {
        ch = ' ';
        return ch;
    }
    ++str;
    switch (length)
    {
        case 4:
            ch <<= 6;
            ch |= (*str++ & 0x3F);
        case 3:
            ch <<= 6;
            ch |= (*str++ & 0x3F);
        case 2:
            ch <<= 6;
            ch |= (*str++ & 0x3F);
    }
    return ch;
};
static void loop_iteration(SDL_Window* window) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        switch (e.type) {
            case SDL_KEYDOWN: {
                GHL::Event ae;
                ae.type = GHL::EVENT_TYPE_KEY_PRESS;
                ae.data.key_press.key = translate_key(e.key.keysym.scancode);
                ae.data.key_press.charcode = 0;
                ae.data.key_press.modificators = translate_mods(e.key.keysym.mod);
                g_application->OnEvent(&ae);
            } break;
            case SDL_KEYUP: {
                GHL::Event ae;
                ae.type = GHL::EVENT_TYPE_KEY_RELEASE;
                ae.data.key_press.key = translate_key(e.key.keysym.scancode);
                ae.data.key_press.charcode = 0;
                ae.data.key_press.modificators =translate_mods(e.key.keysym.mod);
                g_application->OnEvent(&ae);
            } break;
            case SDL_TEXTINPUT: {
                GHL::Event ae;
                ae.type = GHL::EVENT_TYPE_KEY_PRESS;
                ae.data.key_press.key = GHL::KEY_NONE;
                ae.data.key_press.charcode = parse_charcode(e.text.text);
                ae.data.key_press.modificators =0;
                g_application->OnEvent(&ae);
            } break;
            case SDL_MOUSEBUTTONDOWN: {
                if (g_width * g_height) {
                    GHL::Event ae;
                    ae.type = GHL::EVENT_TYPE_MOUSE_PRESS;
                    ae.data.mouse_press.button =  GHL::MOUSE_BUTTON_LEFT;
                    ae.data.mouse_press.modificators = 0;
                    ae.data.mouse_press.x = e.button.x * g_render->GetWidth() / g_width;
                    ae.data.mouse_press.y = e.button.y * g_render->GetHeight() / g_height;
                    g_application->OnEvent(&ae);
                }
            }break;
            case SDL_MOUSEBUTTONUP: {
                if (g_width * g_height) {
                    GHL::Event ae;
                    ae.type = GHL::EVENT_TYPE_MOUSE_RELEASE;
                    ae.data.mouse_press.button =  GHL::MOUSE_BUTTON_LEFT;
                    ae.data.mouse_press.modificators = 0;
                    ae.data.mouse_press.x = e.button.x * g_render->GetWidth() / g_width;
                    ae.data.mouse_press.y = e.button.y * g_render->GetHeight() / g_height;
                    g_application->OnEvent(&ae);
                }
            }break;
            case SDL_MOUSEMOTION: {
                if (g_width * g_height) {
                    GHL::Event ae;
                    ae.type = GHL::EVENT_TYPE_MOUSE_MOVE;
                    ae.data.mouse_move.button =  (e.motion.state & SDL_BUTTON_LMASK) ? GHL::MOUSE_BUTTON_LEFT : GHL::MOUSE_BUTTON_NONE;
                    ae.data.mouse_move.modificators = 0;
                    ae.data.mouse_move.x = e.motion.x * g_render->GetWidth() / g_width;
                    ae.data.mouse_move.y = e.motion.y * g_render->GetHeight() / g_height;
                    g_application->OnEvent(&ae);
                }
            }break;
            case SDL_QUIT:
                g_done = true;
                return;
                break;
            case SDL_WINDOWEVENT: {
                switch (e.window.event) {
                    case SDL_WINDOWEVENT_RESIZED:
                        if (g_render) {
                            int w,h;
                            SDL_GL_GetDrawableSize(g_window,&w,&h);
                            g_render->Resize(w,h);
                            g_width = e.window.data1;
                            g_height = e.window.data2;
                        }
                        break;
                }
            } break;
            
                
            default:
                break;
        }
    }
    static GHL::UInt32 frame_cntr = 0;
    if (g_frame_interval != 0 ) {
        ++frame_cntr;
        if (frame_cntr < g_frame_interval) {
            return;
        }
        frame_cntr = 0;
    }

    Uint32 cur_time = SDL_GetTicks();
    Uint32 delta = cur_time - g_last_time;
    g_last_time = cur_time;

    //g_render->ResetRenderState();

    g_application->OnFrame(delta * 1000);

    SDL_GL_SwapWindow(window);
}

GHL_API int GHL_CALL GHL_StartApplication( GHL::Application* app , int /*argc*/, char** /*argv*/) {
    
    g_application = app;
    
    LOG_INFO(  "start" );
    SDL_Init(SDL_INIT_VIDEO);


    GHL::VFS* vfs = GHL_CreateVFS();


    g_application->SetVFS(vfs);

    SystemSDL system;
    g_application->SetSystem(&system);

    {
        GHL::Event e;
        e.type = GHL::EVENT_TYPE_APP_STARTED;
        g_application->OnEvent(&e);
    }

    GHL::Settings settings;
    settings.width = 800;
    settings.height = 600;
    settings.depth = false;
    settings.screen_dpi = 50;

    float hdpi,vdpi;
    if (SDL_GetDisplayDPI(0,0,&hdpi,&vdpi)==0) {
        settings.screen_dpi = (hdpi + vdpi) * 0.5f;
    }

    app->FillSettings(&settings);

    GHL::ImageDecoderImpl image_decoder;
    g_application->SetImageDecoder(&image_decoder);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    if (settings.depth) {
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
        SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    }
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    
    g_window = SDL_CreateWindow(
        "GHL", 0, 0, settings.width, settings.height, 
        SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI
        );

    int w = 0;
    int h = 0;
    SDL_GetWindowSize(g_window,&w,&h);
    g_width = w;
    g_height = h;

    SDL_GLContext glcontext = SDL_GL_CreateContext(g_window);

    
    SDL_GL_GetDrawableSize(g_window,&w,&h);
    settings.width = w;
    settings.height = h;

    g_done = false;
    LOG_INFO("create render " << settings.width << "x" << settings.height);
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

    g_last_time = SDL_GetTicks();

    
    if (!g_done) {
#ifdef GHL_PLATFORM_EMSCRIPTEN
        emscripten_set_main_loop_arg((em_arg_callback_func)loop_iteration, g_window, 0, 1);
#else
        while (!g_done) {
            loop_iteration(g_window);
        }
#endif
    }

    LOG_INFO(  "done" );
    SDL_GL_DeleteContext(glcontext);  
    // Cleanup
   
    GHL_DestroyVFS(vfs);
    SDL_Quit();

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