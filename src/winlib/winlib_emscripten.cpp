#include "ghl_application.h"
#include "ghl_settings.h"
#include "ghl_vfs.h"
#include "ghl_keys.h"
#include "../ghl_log_impl.h"
#include "../render/render_impl.h"
#include "../image/image_decoders.h"
#include "../vfs/vfs_posix.h"
#include "../sound/emscripten/ghl_sound_emscripten.h"
#include "ghl_system.h"
#include "ghl_event.h"
#include "ghl_font.h"
#include <string>
#include <iostream>
#include <cassert>


#include <sys/time.h>
#include <EGL/EGL.h>
#include <emscripten.h>
#include <emscripten/html5.h>

static const char* MODULE = "WinLib";
static GHL::Application* g_application = 0;
static double g_last_time = 0;
static bool g_done = true;
static GHL::RenderImpl* g_render = 0;
static double g_mouse_scale_x = 1.0;
static double g_mouse_scale_y = 1.0;

static bool g_window_resizeable = false;
static EGLDisplay g_egl_display = EGL_NO_DISPLAY;
static EGLSurface g_egl_surface = EGL_NO_SURFACE;
static EGLContext g_egl_context = EGL_NO_CONTEXT;
static double g_pixel_ratio = 1.0;
static bool g_system_input_active = false;

static void limit_render_size(double& w,double& h) {
    if (w < 1.0) w = 1.0;
    if (h < 1.0) h = 1.0;
    double original_w = w;
    double original_h = h;
    EM_ASM({
        if (Module.GHL_LimitRenderSize) {
            Module.GHL_LimitRenderSize($0,$1);
        }
    },&w,&h);
    if (w != original_w || h!=original_h) {
        g_mouse_scale_x = w / original_w;
        g_mouse_scale_y = h / original_h;
    } else {
        g_mouse_scale_x = 1.0;
        g_mouse_scale_y = 1.0;
    }
}

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
            input.setAttribute('class','emscripten');
            input = canvas.appendChild(input);
           

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
        input = canvas.parentElement.appendChild(input);
        input.style.display = 'block';
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

extern "C" EMSCRIPTEN_KEEPALIVE GHL::Image* GHL_Font_allocate_image(GHL::UInt32 w,GHL::UInt32 h) {
    assert(w>0);
    assert(h>0);
    return GHL_CreateImage(w,h,GHL::IMAGE_FORMAT_RGBA);
}

extern "C" EMSCRIPTEN_KEEPALIVE GHL::Byte* GHL_Font_get_image_data_ptr(GHL::Image* img) {
    return img->GetData()->GetDataPtr();
}
extern "C" EMSCRIPTEN_KEEPALIVE void GHL_Font_set_glyph_info(GHL::Glyph* g, GHL::Image* img, GHL::Int32 x, GHL::Int32 y) {
    g->bitmap = img;
    g->x = x;
    g->y = y;
    g->advance = img->GetWidth();
    img->PremultiplyAlpha();
}

class EmscriptenFont : public GHL::RefCounterImpl<GHL::Font>
{
private:
    int m_handle;
    std::string m_name;
    float m_size;
    float m_xscale;
    float m_outline_width;
public:
    explicit EmscriptenFont(int handle,const GHL::FontConfig* fc) : m_handle(handle) {
        m_name = fc->name;
        m_size = fc->size;
        m_xscale = fc->xscale;
        m_outline_width = fc->outline_width;
    }
    ~EmscriptenFont() {
        EM_ASM({
            delete Module._text_render.fonts[$0];
        },m_handle);
    }

    virtual const char* GHL_CALL GetName() const {
        return m_name.c_str();
    }
    virtual float GHL_CALL GetSize() const {
        return m_size;
    }
    virtual bool GHL_CALL RenderGlyph( GHL::UInt32 ch, GHL::Glyph* g ) {
        GHL::UInt32 str[] = {ch,0};
        g->bitmap = 0;
        g->x = 0;
        g->y = 0;
        EM_ASM({
            let handle = $0;
            let text = $1;
            let glyph = $2;
            let str = UTF32ToString(text);
            let fnt = Module._text_render.fonts[handle];
            let img = fnt.render(str);
            let ghl_img = Module['_GHL_Font_allocate_image'](img.width | 0,img.height | 0);
            let ghl_img_ptr = Module['_GHL_Font_get_image_data_ptr'](ghl_img);
            writeArrayToMemory(img.data,ghl_img_ptr);
            Module['_GHL_Font_set_glyph_info'](glyph,ghl_img,img.x|0,img.y|0);
        },m_handle,str,g);
        return true;
    }
    virtual float GHL_CALL GetAscender() const {
        return 0;
    }
    virtual float GHL_CALL GetDescender() const {
        return 0;
    }
};


class SystemEmscripten : public GHL::System {
private:
    bool m_keyboard_active;
public:
    explicit SystemEmscripten() {
        m_keyboard_active = false;
    }
    ~SystemEmscripten() {
    }

    bool keyboardActive() const {
        return m_keyboard_active;
    }
    
    virtual void GHL_CALL Exit() {
        
    }
    
    ///
    virtual bool GHL_CALL IsFullscreen() const {
        EmscriptenFullscreenChangeEvent status;
        emscripten_get_fullscreen_status(&status);
        return status.isFullscreen;
    }
    ///
    virtual void GHL_CALL SwitchFullscreen(bool fs) {
        EmscriptenFullscreenChangeEvent status;
        emscripten_get_fullscreen_status(&status);
        if ((status.isFullscreen && fs)||(!status.isFullscreen && !fs)) 
            return;
        if (fs) {
            emscripten_request_fullscreen("#canvas",0);
        } else {
            emscripten_exit_fullscreen();
        }
    }
    
    virtual void GHL_CALL ShowKeyboard(const GHL::TextInputConfig* input) {
        if (input && input->system_input) {
            show_system_input(input);
        } else {
            EM_ASM({
                window.focus();
            });
            m_keyboard_active = true;
        }
    }
        
    ///
    virtual void GHL_CALL HideKeyboard() {
        hide_system_input();
        m_keyboard_active = false;
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
            emscripten_set_main_loop_timing(EM_TIMING_RAF,*state);
            return true;
        } 
        else if (name==GHL::DEVICE_STATE_SYSTEM_CURSOR && data) {
            GHL::SystemCursor cursor = static_cast<GHL::SystemCursor>(*(const GHL::UInt32*)data);
            const char* system_cursor = "default";
            switch (cursor) {
                case GHL::SYSTEM_CURSOR_HAND: system_cursor = "pointer"; break;
                case GHL::SYSTEM_CURSOR_MOVE: system_cursor = "move"; break;
                default: break;
            }
            EM_ASM({
                    if (Module['canvas']) {
                        Module['canvas'].style['cursor'] = Pointer_stringify($0);
                    }
                }, system_cursor);
            return true;
        }
        return false;
    }
    ///
    virtual bool GHL_CALL GetDeviceData( GHL::DeviceData name, void* data) {
        if (name == GHL::DEVICE_DATA_LANGUAGE) {
            char* buffer = (char*)EM_ASM_INT({
                let text = navigator.language || navigator.userLanguage; 
                let length = lengthBytesUTF8(text)+1;
                let buffer = Module._malloc(length);
                stringToUTF8(text,buffer,length);
                return buffer;
            });
            char* dest = static_cast<char*>(data);
            ::strncpy(dest,buffer, 32);
            ::free(buffer);
            return true;
        } else if (name == GHL::DEVICE_DATA_UTC_OFFSET) {
            GHL::Int32* output = static_cast<GHL::Int32*>(data);
            *output = static_cast<GHL::Int32>(EM_ASM_INT({
                let d = new Date();
                let n = d.getTimezoneOffset();
                return n*(-60);
            }));
            return true;
        }
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
        int handle = EM_ASM_INT(({
            if (!Module._text_render) {
                Module._text_render = {};
                Module._text_render.fonts = {};
                Module._text_render.fonts_cntr = 0;
                Module._text_render.canvas = document.createElement("canvas");
                document.body.appendChild(Module._text_render.canvas);
                Module._text_render.canvas.style['background-color'] = 'rgb(0,0,0)';
                Module._text_render.canvas.style.visibility = 'hidden';
                Module._text_render.Font = function(size,outline,name) {
                    this._size = size;
                    this._outline = outline;
                    this._name = name;
                    this._canvas = Module._text_render.canvas;
                    this._ctx = this._canvas.getContext('2d');
                    this._ctx.textAlign = 'left';
                    this._ctx.textBaseline = 'alphabetic';
                    this._ctx.fillStyle = 'rgb(255,255,255)';
                    this._ctx.strokeStyle = 'rgb(255,255,255)';
                    // let tmp_div = document.createElement("div");
                    // tmp_div.style.fontSize = size;
                    // tmp_div.style.visibility = 'hidden';
                    // tmp_div.style.width = 'auto';
                    // tmp_div.style.height = 'auto';
                    // tmp_div.style['white-space']='nowrap';
                    // tmp_div.style.position = 'absolute';
                    // document.body.appendChild(tmp_div);
                    // this._measure_div = tmp_div;
                };
                Module._text_render.Font.prototype.render = function(text) {
                    this._ctx.font = this._size + 'px ' + this._name;
                    let metrics = this._ctx.measureText(text);
                    let w = metrics.width | 0;
                    if (w < 1) {
                        w = 1;
                    };
                    let h = this._size | 0;
                    if (canvas.width < w || canvas.height < (h*2)) {
                        this._canvas.width = w; 
                        this._canvas.height = h * 2;
                    };
                    this._ctx.clearRect(0,0,this._canvas.width,this._canvas.height);
                    if (this._outline > 0) {
                        this._ctx.lineWidth = this._outline * 2;
                        this._ctx.strokeText(text,0,h);
                    } else {
                        this._ctx.fillText(text,0,h);
                    }
                    let img = this._ctx.getImageData(0,0,w,h*2);
                    let d = img.data;
                    let begin_y = -1;
                    for (let y=0; (y<h) && (begin_y<0) ;y++) {
                        let pos = y * w * 4;
                        for (let x=0;x<w;++x) {
                            if (d[pos+x*4+3] != 0) {
                                begin_y = y; 
                                break;
                            };
                        };
                    };
                    let end_y = -1;
                    for (let y=0; (y<h) && (end_y<0) ;y++) {
                        let pos = (h*2-y-1) * w * 4;
                        for (let x=0;x<w;++x) {
                            if (d[pos+x*4+3] != 0) {
                                end_y = (h*2-y-1); 
                                break;
                            };
                        };
                    };
                    if (begin_y < 0) {
                        begin_y = h;
                    };
                    if (end_y < 0) {
                        end_y = h;
                    };
                    if (end_y <= begin_y) {
                        end_y = h+1;
                        begin_y = h;
                    };
                    let r = {
                        x:0,
                        y:(h-begin_y),
                        width: (w | 0),
                        height:(end_y-begin_y+1) | 0,
                        data:d.slice(begin_y*w*4,(end_y*w+w-1)*4)
                    };
                    return r;
                };
            };
            let size = $0;
            let outline = $1;
            Module._text_render.fonts_cntr++;
            let handle = Module._text_render.fonts_cntr;
            let name = Pointer_stringify($2);
            let fnt = new Module._text_render.Font(size,outline,name);
            Module._text_render.fonts[handle] = fnt;
            return handle | 0;
        }),double(config->size),double(config->outline_width),config->name);
        return new EmscriptenFont(handle,config);
    }

    //w = w * (window.devicePixelRatio || 1.0);
    //h = h * (window.devicePixelRatio || 1.0);
                   
};

static SystemEmscripten g_system;

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
static GHL::UInt32 translate_mods(const EmscriptenKeyboardEvent *keyEvent) {
    GHL::UInt32 res = 0;
    if (keyEvent->shiftKey) {
        res |= GHL::KEYMOD_SHIFT;
    }
    if (keyEvent->ctrlKey) {
        res |= GHL::KEYMOD_CTRL;
    }
    if (keyEvent->altKey) {
        res |= GHL::KEYMOD_ALT;
    }
    return res;
};


static EM_BOOL
emscripten_handle_mouse_move(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData) {
    if (g_application) {
        GHL::Event ae;
        ae.type = GHL::EVENT_TYPE_MOUSE_MOVE;
        ae.data.mouse_move.button =  GHL::MOUSE_BUTTON_LEFT;
        ae.data.mouse_move.modificators = 0;
        ae.data.mouse_move.x = mouseEvent->canvasX * g_pixel_ratio * g_mouse_scale_x;
        ae.data.mouse_move.y = mouseEvent->canvasY * g_pixel_ratio * g_mouse_scale_y;
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
            ae.data.mouse_press.x = mouseEvent->canvasX * g_pixel_ratio * g_mouse_scale_x;
            ae.data.mouse_press.y = mouseEvent->canvasY * g_pixel_ratio * g_mouse_scale_y;
        } else {
            ae.type = GHL::EVENT_TYPE_MOUSE_RELEASE;
            ae.data.mouse_press.button =  GHL::MOUSE_BUTTON_LEFT;
            ae.data.mouse_press.modificators = 0;
            ae.data.mouse_press.x = mouseEvent->canvasX * g_pixel_ratio * g_mouse_scale_x;
            ae.data.mouse_press.y = mouseEvent->canvasY * g_pixel_ratio * g_mouse_scale_y;
        }
        g_application->OnEvent(&ae);
    }
    return EM_TRUE;
}
static EM_BOOL 
emscripten_handle_wheel(int eventType, const EmscriptenWheelEvent *wheelEvent, void *userData) {
    if (g_application) {
        GHL::Event ae;
        ae.type = GHL::EVENT_TYPE_WHEEL;
        ae.data.wheel.delta = -wheelEvent->deltaY;
        if (wheelEvent->deltaMode == DOM_DELTA_PIXEL) {
            ae.data.wheel.delta *= 0.2f;
        }
        g_application->OnEvent(&ae);
        return EM_TRUE;
    }
    return EM_FALSE;
}


static EM_BOOL
emscripten_handle_key(int eventType, const EmscriptenKeyboardEvent *keyEvent, void *userData)
{
    if (g_system_input_active) 
        return EM_FALSE;
    if (!g_system.keyboardActive())
        return EM_FALSE;
    if (g_application) {
        GHL::Key key = translate_key(keyEvent);
        if (key!=GHL::KEY_NONE) {
            GHL::Event ae;
            ae.data.key_press.key = key;
            if (eventType == EMSCRIPTEN_EVENT_KEYDOWN) {
                ae.type = GHL::EVENT_TYPE_KEY_PRESS;
                ae.data.key_press.charcode = 0;
                ae.data.key_press.modificators = translate_mods(keyEvent);
            } else {
                ae.type = GHL::EVENT_TYPE_KEY_RELEASE;
                ae.data.key_press.charcode =  0;
                ae.data.key_press.modificators = translate_mods(keyEvent);
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
    if (!g_system.keyboardActive())
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
    limit_render_size(w,h);
    emscripten_set_canvas_element_size("#canvas",w*g_pixel_ratio,h*g_pixel_ratio);
    if (g_render) {
        g_render->Resize(w*g_pixel_ratio,h*g_pixel_ratio);
    }
    return EM_TRUE;
}

static EM_BOOL
emscripten_handle_fullscreen_change(int eventType, const EmscriptenFullscreenChangeEvent *fullscreenChangeEvent, void *userData) {
    double w;
    double h;
    if (fullscreenChangeEvent->isFullscreen) {
        w = fullscreenChangeEvent->screenWidth;
        h = fullscreenChangeEvent->screenHeight;
        LOG_INFO("switched to fullscreen " << w << "x" << h);
    } else {
        emscripten_get_element_css_size(NULL,&w,&h);
        LOG_INFO("exit from fullscreen " << w << "x" << h);
    }
    limit_render_size(w,h);
    emscripten_set_canvas_element_size("#canvas",w*g_pixel_ratio,h*g_pixel_ratio);
    if (g_render) {
        g_render->Resize(w*g_pixel_ratio,h*g_pixel_ratio);
    }
    if (g_application) {
        GHL::Event ae;
        ae.type = GHL::EVENT_TYPE_FULLSCREEN_CHANGED;
        g_application->OnEvent(&ae);
    }
    return EM_TRUE;
}

static EM_BOOL
emscripten_handle_visibilitychange(int eventType, const EmscriptenVisibilityChangeEvent *visibilityChangeEvent, void *userData) {
    if (visibilityChangeEvent->visibilityState==EMSCRIPTEN_VISIBILITY_VISIBLE) {
        if (g_application) {
            GHL::Event ae;
            ae.type = GHL::EVENT_TYPE_RESUME;
            g_application->OnEvent(&ae);
        }
    } else {
        if (g_application) {
            GHL::Event ae;
            ae.type = GHL::EVENT_TYPE_SUSPEND;
            g_application->OnEvent(&ae);
        }
    }
    return EM_TRUE;
}

static GHL::SoundEmscripten g_sound;

static void loop_iteration(void* arg) {
    
    eglMakeCurrent(g_egl_display,g_egl_surface,g_egl_surface, g_egl_context);

    if (!g_done) {
        double cur_time = emscripten_get_now();
        GHL::UInt32 delta = (cur_time - g_last_time)*1000;
        g_last_time = cur_time;

        g_application->OnFrame(delta);
        g_sound.Process();

    }
    
    // EM_ASM({
    //     GLctx.finish();
    // });

}


static GHL::ImageDecoderImpl g_image_decoder;

GHL_API int GHL_CALL GHL_StartApplication( GHL::Application* app , int /*argc*/, char** /*argv*/) {

    
    

    emscripten_cancel_main_loop();
    emscripten_set_main_loop_arg(loop_iteration, &g_system,0, 0);



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
    settings.screen_dpi = 50 * g_pixel_ratio;


    app->FillSettings(&settings);

    
    g_application->SetImageDecoder(&g_image_decoder);


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

    GHL::UInt32 r = EM_ASM_INT(({
        let contextAttributes = {
            antialias: false,
            depth: ($0 != 0),
            stencil: false,
            alpha: false,
            premultipliedAlpha: false
        };
        Module.ctx = Browser.createContext(Module['canvas'], true, true, contextAttributes);
        return (Module.ctx ? 1 : 0) | 0;
    }),settings.depth?1:0);

    if (!r) {
        LOG_ERROR("failed create context");
        return 1;
    }
   
    g_sound.SoundInit();
    g_application->SetSound(&g_sound);

    eglMakeCurrent(g_egl_display,g_egl_surface,g_egl_surface, g_egl_context);

    g_done = false;
    LOG_INFO("create render " << settings.width << "x" << settings.height);
    w = settings.width / g_pixel_ratio;
    h = settings.height / g_pixel_ratio;
    limit_render_size(w,h);
    emscripten_set_canvas_element_size("#canvas",w*g_pixel_ratio,h*g_pixel_ratio);
    g_render = GHL_CreateRenderOpenGL(w*g_pixel_ratio,h*g_pixel_ratio,settings.depth);
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
    emscripten_set_wheel_callback("#canvas", 0, 0, emscripten_handle_wheel);
    emscripten_set_resize_callback("#window",0,0, emscripten_handle_resize);
    emscripten_set_fullscreenchange_callback("#window",0,0, emscripten_handle_fullscreen_change);

    emscripten_set_keydown_callback("#window", 0, 0, emscripten_handle_key);
    emscripten_set_keyup_callback("#window", 0, 0, emscripten_handle_key);
    emscripten_set_keypress_callback("#window", 0, 0, emscripten_handle_key_press);


    emscripten_set_visibilitychange_callback(0,0,emscripten_handle_visibilitychange);

    g_last_time = emscripten_get_now();
    

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
    EM_ASM(({
        if (!Module.GHL_LogLevelNames) {
            Module.GHL_LogLevelNames = [
                "F:",
                "E:",
                "W:",
                "I:",
                "V:",
                "D:"
            ];
        }
        Module.print(Module.GHL_LogLevelNames[$0],Pointer_stringify($1));
    }),GHL::UInt32(level),message);
}