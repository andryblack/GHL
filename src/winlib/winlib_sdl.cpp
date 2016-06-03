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

#include <SDL/SDL.h>
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
    
    virtual void GHL_CALL ShowKeyboard() {}
        
    ///
    virtual void GHL_CALL HideKeyboard() {}
    
    virtual GHL::UInt32  GHL_CALL GetKeyMods() const {
        return 0;
    }
    ///
    virtual bool GHL_CALL SetDeviceState( GHL::DeviceState name, const void* data) {
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
};

static void loop_iteration(SDL_Window* window) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        switch (e.type) {
            case SDL_KEYDOWN:
            case SDL_KEYUP:
                switch (e.key.keysym.scancode) {
                    case SDL_SCANCODE_LEFT:
                    case SDL_SCANCODE_RIGHT: {
                        // const Uint8* keys = SDL_GetKeyboardState(0);
                        // Sint16 xpos = 0;

                        // if (keys[SDL_SCANCODE_LEFT] && keys[SDL_SCANCODE_RIGHT]) {
                        //     xpos = 0;
                        // } else if (keys[SDL_SCANCODE_LEFT]) {
                        //     xpos = -1.0f;
                        // } else if (keys[SDL_SCANCODE_RIGHT]) {
                        //     xpos = 1.0f;
                        // }

                        // game->apply_input(Game::InputForce_X_AXIS, xpos);
                    }
                        break;
                    case SDL_SCANCODE_UP:
                        //game->apply_input(Game::InputForce_SHOOT, e.key.state == SDL_PRESSED ? 1 : 0);
                        break;
                    case SDL_SCANCODE_ESCAPE:
                        //game->apply_input(Game::InputForce_START, e.key.state == SDL_PRESSED ? 1 : 0);
                    default:
                        break;
                }
                break;
            case SDL_MOUSEBUTTONDOWN: {
                GHL::Event ae;
                ae.type = GHL::EVENT_TYPE_MOUSE_PRESS;
                ae.data.mouse_press.button =  GHL::MOUSE_BUTTON_LEFT;
                ae.data.mouse_press.modificators = 0;
                ae.data.mouse_press.x = e.button.x;
                ae.data.mouse_press.y = e.button.y;
                g_application->OnEvent(&ae);
            }break;
            case SDL_MOUSEBUTTONUP: {
                GHL::Event ae;
                ae.type = GHL::EVENT_TYPE_MOUSE_RELEASE;
                ae.data.mouse_press.button =  GHL::MOUSE_BUTTON_LEFT;
                ae.data.mouse_press.modificators = 0;
                ae.data.mouse_press.x = e.button.x;
                ae.data.mouse_press.y = e.button.y;
                g_application->OnEvent(&ae);
            }break;
            case SDL_MOUSEMOTION: {
                GHL::Event ae;
                ae.type = GHL::EVENT_TYPE_MOUSE_MOVE;
                ae.data.mouse_move.button =  (e.motion.state & SDL_BUTTON_LMASK) ? GHL::MOUSE_BUTTON_LEFT : GHL::MOUSE_BUTTON_NONE;
                ae.data.mouse_move.modificators = 0;
                ae.data.mouse_move.x = e.motion.x;
                ae.data.mouse_move.y = e.motion.y;
                g_application->OnEvent(&ae);
            }break;
            case SDL_QUIT:
                g_done = true;
                return;
                break;
                
            default:
                break;
        }
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

    GHL::Settings settings;
    settings.width = 800;
    settings.height = 600;
    settings.depth = false;
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
        SDL_WINDOW_OPENGL);

    SDL_GLContext glcontext = SDL_GL_CreateContext(g_window);

    g_height = settings.height;

    g_render = GHL_CreateRenderOpenGL(settings.width,settings.height,settings.depth);
    if ( g_render && g_application ) {
        g_application->SetRender(g_render);
        g_application->Load();
    }

    g_last_time = SDL_GetTicks();

    g_done = false;

#ifdef GHL_PLATFORM_EMSCRIPTEN
    emscripten_set_main_loop_arg((em_arg_callback_func)loop_iteration, g_window, 0, 1);
#else
    while (!g_done) {
        loop_iteration(g_window);
    }
#endif

    LOG_INFO(  "done" );
    SDL_GL_DeleteContext(glcontext);  
    // Cleanup
   
    GHL_DestroyVFS(vfs);
    SDL_Quit();

    return 0;
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