
#include <ghl_api.h>
#include <ghl_application.h>
#include <ghl_settings.h>
#include <ghl_log.h>
#include <ghl_system.h>
#include <ghl_event.h>


#include <AS3/AS3.h>
#include <Flash++.h>

#include <iostream>

#include "../ghl_log_impl.h"
#include "../image/image_decoders.h"
#include "../vfs/vfs_posix.h"
#include "../render/stage3d/render_stage3d.h"
#include "../sound/flash/ghl_sound_flash.h"
#include <cstdio>

#include <sys/time.h>

static const char* MODULE = "WinLib";
static bool need_depth = false;
class Profiler {
public:
    explicit Profiler( const char* text ) : m_text(text) {
        ::gettimeofday(&m_start,0);
    }
    ~Profiler() {
        ::timeval end;
        ::gettimeofday(&end,0);
        GHL::UInt32 time = (end.tv_sec-m_start.tv_sec)*1000000 + (end.tv_usec-m_start.tv_usec);
        LOG_INFO("Profiler: " << m_text << " " << time << "usecs");
    }
private:
    const char* m_text;
    ::timeval m_start;
};

using namespace AS3::ui;


class FlashSystem : public GHL::System {
public:
    FlashSystem() : vfs("/","/local"), sound(0),imageDecoder(0),render(0) {
        started = false;
        valid = false;
        loaded = false;
        fullscreen = false;
    }
    ~FlashSystem() {
        delete sound;
        delete render;
        delete imageDecoder;
    }
    
	void GHL_CALL Exit() {
		LOG_ERROR("Exit not supported on this platform");
	}
	///
	virtual bool GHL_CALL IsFullscreen() const {
		return fullscreen;
	}
    ///
	virtual void GHL_CALL SwitchFullscreen(bool fs) {
        if (fs==fullscreen) return;
		if (fs && stage->allowsFullScreen) {
            stage->displayState = flash::display::StageDisplayState::FULL_SCREEN;
            fullscreen = true;
            render->Resize(stage->fullScreenWidth,stage->fullScreenHeight);
        } else {
            fullscreen = false;
            stage->displayState = flash::display::StageDisplayState::NORMAL;
            render->Resize(stage->width,stage->height);
        }
        render->RenderSetFullScreen(fullscreen);
        ctx3d->configureBackBuffer(render->GetWidth(),
                                    render->GetHeight(), 0,
                                    need_depth, false);
	}
    ///
	virtual void GHL_CALL ShowKeyboard() {
	}
    ///
	virtual void GHL_CALL HideKeyboard() {
	}
    ///
	virtual GHL::UInt32  GHL_CALL GetKeyMods() const {
		/// @todo
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
		/// @todo
	}
    void addStartupParam(const char* val);
public:
    GHL::Application* application;
    flash::display::Stage stage;
    flash::display::Stage3D s3d;
    flash::display3D::Context3D ctx3d;
    bool started;
    bool valid;
    bool loaded;
    timeval lastTime;
    GHL::VFSPosixImpl   vfs;
    GHL::SoundFlash* sound;
    GHL::ImageDecoderImpl* imageDecoder;
    GHL::RenderStage3d* render;
    bool fullscreen;
    std::string m_flash_var;
};


static FlashSystem ctx;

static GHL::Key convert_key( GHL::UInt32 code ) {
    switch (code) {
        case 8:     return GHL::KEY_BACKSPACE;
        case 9:     return GHL::KEY_TAB;
        case 13:    return GHL::KEY_ENTER;
        case 27:    return GHL::KEY_ESCAPE;
            
        case 32:    return GHL::KEY_SPACE;
        case 33:    return GHL::KEY_PGUP;
        case 34:    return GHL::KEY_PGDN;
        case 35:    return GHL::KEY_END;
        case 36:    return GHL::KEY_HOME;
            
        case 37:    return GHL::KEY_LEFT;
        case 38:    return GHL::KEY_UP;
        case 39:    return GHL::KEY_RIGHT;
        case 40:    return GHL::KEY_DOWN;
            
        case 45:    return GHL::KEY_INSERT;
        case 46:    return GHL::KEY_DELETE;
        case 19:    return GHL::KEY_PAUSE;
            
        case 65:    return GHL::KEY_A;
        case 66:    return GHL::KEY_B;
        case 67:    return GHL::KEY_C;
        case 68:    return GHL::KEY_D;
        case 69:    return GHL::KEY_E;
        case 70:    return GHL::KEY_F;
        case 71:    return GHL::KEY_G;
        case 72:    return GHL::KEY_H;
        case 73:    return GHL::KEY_I;
        case 74:    return GHL::KEY_J;
        case 75:    return GHL::KEY_K;
        case 76:    return GHL::KEY_L;
        case 77:    return GHL::KEY_M;
        case 78:    return GHL::KEY_N;
        case 79:    return GHL::KEY_O;
        case 80:    return GHL::KEY_P;
        case 81:    return GHL::KEY_Q;
        case 82:    return GHL::KEY_R;
        case 83:    return GHL::KEY_S;
        case 84:    return GHL::KEY_T;
        case 85:    return GHL::KEY_U;
        case 86:    return GHL::KEY_V;
        case 87:    return GHL::KEY_W;
        case 88:    return GHL::KEY_X;
        case 89:    return GHL::KEY_Y;
        case 90:    return GHL::KEY_Z;
            
        case 48:    return GHL::KEY_0;
        case 49:    return GHL::KEY_1;
        case 50:    return GHL::KEY_2;
        case 51:    return GHL::KEY_3;
        case 52:    return GHL::KEY_4;
        case 53:    return GHL::KEY_5;
        case 54:    return GHL::KEY_6;
        case 55:    return GHL::KEY_7;
        case 56:    return GHL::KEY_8;
        case 57:    return GHL::KEY_9;
            
        case 186:    return GHL::KEY_COMMA;
        //case 187:    return GHL::KEY_PLUS;
        case 189:    return GHL::KEY_MINUS;
            
        case 96:    return GHL::KEY_NUMPAD0;
        case 97:    return GHL::KEY_NUMPAD1;
        case 98:    return GHL::KEY_NUMPAD2;
        case 99:    return GHL::KEY_NUMPAD3;
        case 100:    return GHL::KEY_NUMPAD4;
        case 101:    return GHL::KEY_NUMPAD5;
        case 102:    return GHL::KEY_NUMPAD6;
        case 103:    return GHL::KEY_NUMPAD7;
        case 104:    return GHL::KEY_NUMPAD8;
        case 105:    return GHL::KEY_NUMPAD9;
            
        case 106:   return GHL::KEY_MULTIPLY;
        case 107:   return GHL::KEY_ADD;
        case 109:   return GHL::KEY_SUBTRACT;
        case 111:   return GHL::KEY_DIVIDE;
        case 110:   return GHL::KEY_DECIMAL;
            
        case 112:   return GHL::KEY_F1;
        case 113:   return GHL::KEY_F2;
        case 114:   return GHL::KEY_F3;
        case 115:   return GHL::KEY_F4;
        case 116:   return GHL::KEY_F5;
        case 117:   return GHL::KEY_F6;
        case 118:   return GHL::KEY_F7;
        case 119:   return GHL::KEY_F8;
        case 120:   return GHL::KEY_F9;
        //case 121:   return GHL::KEY_F10;
        case 122:   return GHL::KEY_F11;
        case 123:   return GHL::KEY_F12;
    }
    
   
    
//    ;: = 186
//    =+ = 187
//    -_ = 189
//    /? = 191
//    `~ = 192
//    [{ = 219
//     \| = 220
//     ]} = 221
//"' = 222
//, = 188
//. = 190
/// = 191
    return GHL::KEY_NONE;

}

static var handleKeyUp(void *arg, var as3Args)
{
    flash::events::KeyboardEvent ke = var(as3Args[0]);
    if (ctx.valid) {
        GHL::Key key = convert_key(ke->keyCode);
        if (key != GHL::KEY_NONE) {
            GHL::Event e;
            e.type = GHL::EVENT_TYPE_KEY_RELEASE;
            e.data.key_press.key = key;
            e.data.key_press.charcode = 0;
            e.data.key_press.modificators = 0;
            ctx.application->OnEvent(&e);
        }
    }
    ke->stopPropagation();
    return internal::_undefined;
}

static var handleKeyDown(void *arg, var as3Args)
{
    flash::events::KeyboardEvent ke = var(as3Args[0]);
    if (ctx.valid) {
        

        GHL::Key key = convert_key(ke->keyCode);
        if (key != GHL::KEY_NONE) {
            GHL::Event e;
            e.type = GHL::EVENT_TYPE_KEY_PRESS;
            e.data.key_press.key = key;
            e.data.key_press.charcode = 0;
            e.data.key_press.modificators = 0;
            ctx.application->OnEvent(&e);
        }
    }
    ke->stopPropagation();
    return internal::_undefined;
}

static var handleRightClick(void *arg, var as3Args)
{
    // As long as there is a right click handler function
    // registered the default Flash right-click menu will
    // be disabled. but you could also use this event handler
    // for actual input handling.
    
    return internal::_undefined;
}

static var handleMouseDown(void *arg, var as3Args)
{
    flash::events::MouseEvent me = var(as3Args[0]);
    if (ctx.valid) {
        GHL::Event e;
        e.type = GHL::EVENT_TYPE_MOUSE_PRESS;
        e.data.mouse_press.button =  GHL::MOUSE_BUTTON_LEFT;
        e.data.mouse_press.modificators = 0;
        e.data.mouse_press.x = me->stageX;
        e.data.mouse_press.y = me->stageY;
        ctx.application->OnEvent(&e);
    }
    me->stopPropagation();
    return internal::_undefined;
}

static var handleMouseMove(void *arg, var as3Args)
{
    flash::events::MouseEvent me = var(as3Args[0]);
    //thegame.handleKeyDown(ke->keyCode);
    if (ctx.valid) {
        GHL::Event e;
        e.type = GHL::EVENT_TYPE_MOUSE_MOVE;
        e.data.mouse_press.button =  me->buttonDown ? GHL::MOUSE_BUTTON_LEFT : GHL::MOUSE_BUTTON_NONE;
        e.data.mouse_press.modificators = 0;
        e.data.mouse_press.x = me->stageX;
        e.data.mouse_press.y = me->stageY;
        ctx.application->OnEvent(&e);
    }
    me->stopPropagation();
    return internal::_undefined;
}

static var handleMouseUp(void *arg, var as3Args)
{
    flash::events::MouseEvent me = var(as3Args[0]);
    //thegame.handleKeyDown(ke->keyCode);
    if (ctx.valid) {
        GHL::Event e;
        e.type = GHL::EVENT_TYPE_MOUSE_RELEASE;
        e.data.mouse_press.button =  GHL::MOUSE_BUTTON_LEFT;
        e.data.mouse_press.modificators = 0;
        e.data.mouse_press.x = me->stageX;
        e.data.mouse_press.y = me->stageY;
        ctx.application->OnEvent(&e);
    }
    me->stopPropagation();
    return internal::_undefined;
}

static void startApplication();
// This function will be attached to the ENTER_FRAME event to drive the
// animation.
static var enterFrame(void *arg, var as3Args)
{
    try {
//        if (!) {
////            startApplication();
////            ctx.started = true;
//            return;
//        }
        if (ctx.started && ctx.valid) {
            if (!ctx.loaded) {
                Profiler pf("Load");
                if (!ctx.application->Load()) {
                    ctx.valid = false;
                    return internal::_undefined;
                }
                ctx.loaded = true;
            }
            
            
            timeval nowTime;
            gettimeofday(&nowTime,0);
            GHL::UInt32 frameTime = (nowTime.tv_sec-ctx.lastTime.tv_sec)*1000000 + (nowTime.tv_usec-ctx.lastTime.tv_usec);
            ctx.lastTime = nowTime;
           
            ctx.application->OnFrame( frameTime );
            
            ctx.ctx3d->present();
        }
        
    } catch(var e) {
        char *err = internal::utf8_toString(e);
        LOG_ERROR(  "enterFrame Exception: " << err );
        free(err);
        ctx.valid = ctx.loaded;
    }
    return internal::_undefined;
}


// If we fail to create the Context3D we display a warning
static var context3DError(void *arg, var as3Args)
{
    LOG_INFO("context3DError");
     
    flash::text::TextFormat fmt = flash::text::TextFormat::_new();
    fmt->size = internal::new_int(24);
    fmt->align = flash::text::TextFormatAlign::CENTER;
    
    flash::text::TextField tf = flash::text::TextField::_new();
    tf->defaultTextFormat = fmt;
    tf->width = ctx.stage->stageWidth;
    tf->height = ctx.stage->stageHeight;
    tf->multiline = true;
    tf->wordWrap = true;
    tf->text =
    "\nUnable to create a Stage3D context. Usually this means you ran the swf "
    "directly in a web browser, use the HTML wrapper instead so the wmode "
    "gets set correctly to 'direct'.";
    
    ctx.stage->addChild(tf);
    return internal::_undefined;
}

// After a Context3D is created this function will be called.
static var initContext3D(void *arg, var as3Args)
{
	LOG_INFO("initContext3D");
    
    
    try {
    
        ctx.ctx3d = ctx.s3d->context3D;
        
        {
            String driverInfoStr = ctx.ctx3d->driverInfo;
            char *driverInfo = internal::utf8_toString(driverInfoStr);
            LOG_INFO(  "driverInfo: " << driverInfo );
            free(driverInfo);
        }
#ifdef GHL_DEBUG
        ctx.ctx3d->enableErrorChecking = true;
#endif
        ctx.ctx3d->configureBackBuffer(ctx.stage->stageWidth,
                                       ctx.stage->stageHeight, 0,
                                    need_depth, false, false);
        if (!ctx.render) {
            Profiler pf("initRender");
            ctx.render = new GHL::RenderStage3d(ctx.stage->stageWidth,
                                                ctx.stage->stageHeight,need_depth);
            ctx.render->SetContext(ctx.ctx3d);
            
            if (ctx.render->RenderInit()){
                ctx.application->SetRender(ctx.render);
                ctx.valid = true;
                enterFrame(arg,as3Args);
            } else {
                LOG_ERROR("RenderInit failed");
            }
        } else {
            ctx.render->SetContext(ctx.ctx3d);
            ctx.valid = true;
        }
        gettimeofday(&ctx.lastTime,0);
        
        
    } catch(var e) {
        char *err = internal::utf8_toString(e);
        LOG_ERROR(  "initContext3D Exception: " << err );
        free(err);
    }
    return internal::_undefined;
}

static void startApplication() {
    try {
        LOG_INFO( "StartApplication ...." );
        Profiler pf("startApplication");
        
        ctx.stage = internal::get_Stage();
        
        ctx.application->SetSystem(&ctx);
        ctx.imageDecoder = new GHL::ImageDecoderImpl();
        ctx.application->SetImageDecoder(ctx.imageDecoder);
        ctx.application->SetVFS(&ctx.vfs);
        
        ctx.sound = new GHL::SoundFlash(4);
        ctx.application->SetSound(ctx.sound);
        
        ctx.sound->SoundInit();
        
        GHL::Settings settings;
        /// default settings
        settings.width = ctx.stage->fullScreenWidth;
        settings.height = ctx.stage->fullScreenHeight;
        settings.fullscreen = false;
        settings.depth = false;
        {
            Profiler pf("FillSettings");
            ctx.application->FillSettings(&settings);
        }
        
        need_depth = settings.depth;
        
        ctx.stage->addEventListener(flash::events::KeyboardEvent::KEY_DOWN, Function::_new(handleKeyDown, NULL));
        ctx.stage->addEventListener(flash::events::KeyboardEvent::KEY_UP, Function::_new(handleKeyUp, NULL));
        ctx.stage->addEventListener(flash::events::MouseEvent::MOUSE_MOVE, Function::_new(handleMouseMove, NULL));
        ctx.stage->addEventListener(flash::events::MouseEvent::MOUSE_DOWN, Function::_new(handleMouseDown, NULL));
        ctx.stage->addEventListener(flash::events::MouseEvent::MOUSE_UP, Function::_new(handleMouseUp, NULL));
        
        try {
            ctx.stage->addEventListener(flash::events::MouseEvent::RIGHT_CLICK, Function::_new(handleRightClick, NULL));
        } catch(var e) {
            // Old players don't support this event so we catch that here
            // sadly that means old players will still show the default
            // Flash right-click menu.
        }
        
        // Ask for a Stage3D context to be created
        ctx.s3d = var(var(ctx.stage->stage3Ds)[0]);
        ctx.s3d->addEventListener(flash::events::Event::CONTEXT3D_CREATE, Function::_new(initContext3D, NULL));
        ctx.s3d->addEventListener(flash::events::ErrorEvent::ERROR, Function::_new(context3DError, NULL));
//        ctx.s3d->requestContext3D(flash::display3D::Context3DRenderMode::AUTO,
//                                  flash::display3D::Context3DProfile::BASELINE_CONSTRAINED);
        ctx.started = true;
        ctx.stage->addEventListener(flash::events::Event::ENTER_FRAME, Function::_new(&enterFrame, NULL));
        ctx.s3d->requestContext3D(flash::display3D::Context3DRenderMode::AUTO,
                                  flash::display3D::Context3DProfile::BASELINE);
        
        LOG_INFO( "StartApplication ok" );
    } catch (var e) {
        LOG_ERROR( "startApplication exception" );
    }
}


GHL_API int GHL_CALL GHL_StartApplication( GHL::Application* app , int /*argc*/, char** /*argv*/) {
    
    ctx.application = app;
    
    LOG_INFO(  "GHL_StartApplication" );
    try {
        flash::display::Stage stage = internal::get_Stage();
        stage->scaleMode = flash::display::StageScaleMode::NO_SCALE;
        stage->align = flash::display::StageAlign::TOP_LEFT;
        stage->frameRate = 60;
        ctx.started = false;
        startApplication();
        
    } catch (var e) {
        LOG_ERROR( "GHL_StartApplication exception" );
    }
    LOG_INFO(  "go async" );
  
    AS3_GoAsync();
    
    LOG_INFO( "end background" );
    
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
