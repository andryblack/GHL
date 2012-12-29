
#include <ghl_api.h>
#include <ghl_application.h>
#include <ghl_settings.h>
#include <ghl_log.h>
#include <ghl_system.h>


#include <AS3/AS3.h>
#include <Flash++.h>

#include <iostream>

#include "../ghl_log_impl.h"
#include "../image/image_decoders.h"
#include "../vfs/vfs_posix.h"
#include "../render/stage3d/render_stage3d.h"
#include <cstdio>

#include <sys/time.h>

static const char* MODULE = "WinLib";

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
    FlashSystem() : vfs("","/local"), imageDecoder(0),render(0) {
        started = false;
        valid = false;
        loaded = false;
    }
    ~FlashSystem() {
        delete render;
        delete imageDecoder;
    }
    
	void GHL_CALL Exit() {
		LOG_ERROR("Exit not supported on this platform");
	}
	///
	virtual bool GHL_CALL IsFullscreen() const {
		return false;
	}
    ///
	virtual void GHL_CALL SwitchFullscreen(bool fs) {
		/// @todo
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
	virtual bool GHL_CALL SetDeviceState( GHL::DeviceState name, void* data) {
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
    GHL::ImageDecoderImpl* imageDecoder;
    GHL::RenderStage3d* render;
};


static FlashSystem ctx;

static var handleKeyUp(void *arg, var as3Args)
{
    flash::events::KeyboardEvent ke = var(as3Args[0]);
    //thegame.handleKeyUp(ke->keyCode);
    ke->stopPropagation();
    return internal::_undefined;
}

static var handleKeyDown(void *arg, var as3Args)
{
    flash::events::KeyboardEvent ke = var(as3Args[0]);
    //thegame.handleKeyDown(ke->keyCode);
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
        ctx.application->OnMouseDown( GHL::MOUSE_BUTTON_LEFT, me->stageX , me->stageY );
    }
    //thegame.handleKeyDown(ke->keyCode);
    me->stopPropagation();
    return internal::_undefined;
}

static var handleMouseMove(void *arg, var as3Args)
{
    flash::events::MouseEvent me = var(as3Args[0]);
    //thegame.handleKeyDown(ke->keyCode);
    if (ctx.valid) {
        ctx.application->OnMouseMove( GHL::MOUSE_BUTTON_LEFT, me->stageX , me->stageY );
    }
    me->stopPropagation();
    return internal::_undefined;
}

static var handleMouseUp(void *arg, var as3Args)
{
    flash::events::MouseEvent me = var(as3Args[0]);
    //thegame.handleKeyDown(ke->keyCode);
    if (ctx.valid) {
        ctx.application->OnMouseUp( GHL::MOUSE_BUTTON_LEFT, me->stageX , me->stageY );
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
        ctx.valid = false;
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
        ctx.ctx3d->enableErrorChecking = true;
        ctx.ctx3d->configureBackBuffer(ctx.stage->stageWidth,
                                       ctx.stage->stageHeight, 0,
                                    false, false);
        if (!ctx.render) {
            Profiler pf("initRender");
            ctx.render = new GHL::RenderStage3d(ctx.stage->stageWidth,
                                                ctx.stage->stageHeight);
            ctx.render->SetContext(ctx.ctx3d);
            
            if (ctx.render->RenderInit()){
                ctx.application->SetRender(ctx.render);
            } else {
                LOG_ERROR("RenderInit failed");
            }
        } else {
            ctx.render->SetContext(ctx.ctx3d);
        }
        gettimeofday(&ctx.lastTime,0);
        ctx.valid = true;
        
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
        
        GHL::Settings settings;
        /// default settings
        settings.width = ctx.stage->stageWidth;
        settings.height = ctx.stage->stageHeight;
        settings.fullscreen = false;
        {
            Profiler pf("FillSettings");
            ctx.application->FillSettings(&settings);
        }
        
        
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
        ctx.s3d->requestContext3D(flash::display3D::Context3DRenderMode::AUTO,
                                  flash::display3D::Context3DProfile::BASELINE_CONSTRAINED);
        ctx.started = true;
        LOG_INFO( "StartApplication ok" );
    } catch (var e) {
        LOG_ERROR( "startApplication exception" );
    }
}

GHL_API int GHL_CALL GHL_StartApplication( GHL::Application* app , int /*argc*/, char** /*argv*/) {
    
    ctx.application = app;
    
    LOG_INFO(  "listen frames" );
    try {
        flash::display::Stage stage = internal::get_Stage();
        stage->scaleMode = flash::display::StageScaleMode::NO_SCALE;
        stage->align = flash::display::StageAlign::TOP_LEFT;
        stage->frameRate = 60;
        ctx.started = false;
        startApplication();
        stage->addEventListener(flash::events::Event::ENTER_FRAME, Function::_new(&enterFrame, NULL));
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

