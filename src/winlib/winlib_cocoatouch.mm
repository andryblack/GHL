//
//  winlib_cocoatouch.mm
//  SR
//
//  Created by Андрей Куницын on 26.06.11.
//  Copyright 2011 andryblack. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>
#include <sys/time.h>

#include "../render/opengl/render_opengles.h"

#include "ghl_application.h"
#include "ghl_settings.h"
#include "ghl_system.h"
#include "ghl_event.h"
#include "../ghl_log_impl.h"

#include "../sound/ghl_sound_impl.h"
#include "../vfs/vfs_cocoa.h"
#include "../image/image_decoders.h"

#import <OpenGLES/EAGLDrawable.h>

#import <CoreMotion/CoreMotion.h>

#import "WinLibCocoaTouchContext2.h"

#include <pthread.h>

static const char* MODULE = "WINLIB";

static GHL::Application* g_application = 0;
static UIInterfaceOrientation g_orientation = UIInterfaceOrientationLandscapeLeft;
static bool g_orientationLocked = false;
static bool g_retina_enabled = true;
static bool g_need_depth = false;

#ifndef GHL_NOSOUND
extern GHL::SoundImpl* GHL_CreateSoundCocoa();
#endif

namespace GHL {
	extern UInt32 g_default_framebuffer;
}

@class WinLibView;

@interface AccelerometerDelegate : NSObject
{
	CMMotionManager* manager;
	float data[3];
}
- (id)init;
@end

@implementation AccelerometerDelegate

- (id)init
{
	if (self = [super init]) {
		manager = [[CMMotionManager alloc] init];
        [manager startDeviceMotionUpdates];
        data[0]=data[1]=data[2]=0;
	}
	return self;
}

- (float*)get_data
{
    CMDeviceMotion* g = manager.deviceMotion;
    if (g) {
        data[0] = g.gravity.x;
        data[1] = g.gravity.y;
        data[2] = g.gravity.z;
    }
	return data;
}

- (void)dealloc
{
    [manager stopDeviceMotionUpdates];
	[manager release];
	[super dealloc];
}



@end

class SystemCocoaTouch;

static const size_t max_touches = 10;

@interface WinLibView : UIView<UITextFieldDelegate> {
    WinLibCocoaTouchContext*    m_context;
    
	GHL::ImageDecoderImpl* m_imageDecoder;
	GHL::SoundImpl*	m_sound;
	NSString*	m_appName;
	GHL::RenderImpl* m_render;
	NSTimer*	m_timer;
	bool	m_loaded;
	::timeval	m_timeval;
	bool	m_active;
	UITextField* m_hiddenInput;
	UITouch* m_touches[max_touches];
}

- (void)prepareOpenGL:(Boolean) gles2;
- (void)makeCurrent;
- (void)setActive:(bool) a;
- (bool)loaded;
- (void)showKeyboard;
- (void)hideKeyboard;

@end

@interface WinLibViewController : UIViewController
{
	
}

@end

class SystemCocoaTouch : public GHL::System {
private:
	WinLibViewController* m_controller;
	AccelerometerDelegate* m_accelerometer;
public:
	explicit SystemCocoaTouch(WinLibViewController* controller) : m_controller(controller) {
		m_accelerometer = 0;
	}
	~SystemCocoaTouch() {
		[m_accelerometer release]; 
	}
	virtual void GHL_CALL Exit() {
		///
		LOG_ERROR("Call GHL::System::Exit on iOS disallow");
	}
	
	///
	virtual bool GHL_CALL IsFullscreen() const {
		return true;
	}
	///
	virtual void GHL_CALL SwitchFullscreen(bool fs) {
		/// do nothing
	}
	
	virtual void GHL_CALL SwapBuffers();	
	///
	virtual void GHL_CALL ShowKeyboard();
		
	///
	virtual void GHL_CALL HideKeyboard();
	
	virtual GHL::UInt32  GHL_CALL GetKeyMods() const {
		return 0;
	}
	///
	virtual bool GHL_CALL SetDeviceState( GHL::DeviceState name, const void* data);
	///
    virtual bool GHL_CALL GetDeviceData( GHL::DeviceData name, void* data) {
		if (name==GHL::DEVICE_DATA_ACCELEROMETER) {
			if (!m_accelerometer)
				return false;
			memcpy(data, [m_accelerometer get_data], sizeof(float)*3);
			return true;
		} else if (name==GHL::DEVICE_DATA_VIEW_CONTROLLER) {
			if (data) {
				*((UIViewController**)data) = m_controller;
                return true;
			}
        } else if (name == GHL::DEVICE_DATA_UTC_OFFSET) {
            if (data) {
                GHL::Int32* output = static_cast<GHL::Int32*>(data);
                *output = static_cast<GHL::Int32>([[NSTimeZone localTimeZone] secondsFromGMT]);
                return true;
            }
        } else if (name == GHL::DEVICE_DATA_LANGUAGE) {
            NSString* language = [[NSLocale preferredLanguages] objectAtIndex:0];
            if (language && data) {
                char* dest = static_cast<char*>(data);
                ::strncpy(dest, [language UTF8String], 32);
                return true;
            }
        }
		return false;
	}
    ///
    virtual void GHL_CALL SetTitle( const char* title ) {
        /// do nothing
    }
};







@implementation WinLibView

+ (Class)layerClass
{
    return [CAEAGLLayer class];
}


- (bool)loaded{
	return m_loaded;
}
- (void)setActive:(bool) a {
	if (m_active!=a) {
		m_active = a;
	}
}

-(id) initWithFrame:(CGRect) rect {
	if (self = [super initWithFrame:rect]) {
		m_appName = (NSString*)[[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleName"];
		m_imageDecoder = 0;
		
		m_active = false;
		
#ifndef GHL_NO_IMAGE_DECODERS
		m_imageDecoder = new GHL::ImageDecoderImpl();		
		g_application->SetImageDecoder(m_imageDecoder);
#endif
		
		// Get the layer
        CAEAGLLayer *eaglLayer = (CAEAGLLayer *)self.layer;
		
        eaglLayer.opaque = TRUE;
        eaglLayer.drawableProperties = [NSDictionary dictionaryWithObjectsAndKeys:
                                        [NSNumber numberWithBool:FALSE], kEAGLDrawablePropertyRetainedBacking,
										kEAGLColorFormatRGBA8, kEAGLDrawablePropertyColorFormat, nil];
        EAGLContext* context = 0;
		Boolean gles2 = YES;
        
        
		context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];
		
        
        if (!context) {
            gles2 = NO;
            context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES1];
        }
        if (!context || ![EAGLContext setCurrentContext:context])
        {
            [self release];
            return nil;
        }
		
        if (gles2) {
            m_context = [[WinLibCocoaTouchContext2 alloc] initWithContext:context];
        } else {
            m_context = [[WinLibCocoaTouchContext alloc] initWithContext:context];
        }
        
        
        if([self respondsToSelector:@selector(setContentScaleFactor:)]){
            if (!g_retina_enabled) {
				self.contentScaleFactor = 1.0;
            } else {
                self.contentScaleFactor = [[UIScreen mainScreen] scale];
            }
            LOG_VERBOSE("contentScaleFactor:"<<self.contentScaleFactor);
        }
		
		
        [m_context createBuffers:g_need_depth];

		
		GHL::g_default_framebuffer = [m_context defaultFramebuffer];
		
		m_sound = 0;
#ifndef GHL_NO_SOUND
		m_sound = GHL_CreateSoundCocoa();
		if (!m_sound->SoundInit()) {
			delete m_sound;
			m_sound = 0;
		}
		g_application->SetSound(m_sound);
#endif
		
		for (size_t i=0;i<max_touches;i++) {
			m_touches[i] = 0;
		}
		
		m_hiddenInput = [[UITextField alloc] initWithFrame:CGRectMake(0, 0, 0, 0)];
		m_hiddenInput.delegate = self;
		m_hiddenInput.keyboardType = UIKeyboardTypeASCIICapable;
		m_hiddenInput.returnKeyType = UIReturnKeyDone;
		m_hiddenInput.text = @"*";
        m_hiddenInput.autocorrectionType = UITextAutocorrectionTypeNo;
		[self addSubview:m_hiddenInput];
		
        [self setAutoresizesSubviews:YES];
        
		if([self respondsToSelector:@selector(setContentScaleFactor:)]){
            if (!g_retina_enabled) {
				self.contentScaleFactor = 1.0;
            } else {
                self.contentScaleFactor = [[UIScreen mainScreen] scale];
            }
			LOG_VERBOSE("contentScaleFactor:"<<self.contentScaleFactor);
		}
		
		[self prepareOpenGL:gles2];
	}
	return self;
}

- (void)makeCurrent {
    [m_context makeCurrent];
}

- (void)layoutSubviews
{
    LOG_VERBOSE( "layoutSubviews" ); 
	if([self respondsToSelector:@selector(setContentScaleFactor:)]){
        if (!g_retina_enabled) {
			self.contentScaleFactor = 1.0;
        } else {
            self.contentScaleFactor = [[UIScreen mainScreen] scale];
        }
		LOG_VERBOSE("contentScaleFactor:"<<self.contentScaleFactor);
	}

	[m_context onLayout:(CAEAGLLayer*)self.layer];
    GHL::g_default_framebuffer = [m_context defaultFramebuffer];
	m_render->Resize([m_context backingWidth], [m_context backingHeight]);
 	
}

- (void)prepareOpenGL:(Boolean) gles2 {
	LOG_VERBOSE( "prepareOpenGL " << (gles2 ? "GLES2" : "GLES1") );
	NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
	[self makeCurrent];
	int w = [self bounds].size.width;
	int h = [self bounds].size.height;
	if([self respondsToSelector:@selector(setContentScaleFactor:)]){
        if (!g_retina_enabled) {
			self.contentScaleFactor = 1.0;
        } else {
            self.contentScaleFactor = [[UIScreen mainScreen] scale];
			w *= self.contentScaleFactor;
			h *= self.contentScaleFactor;
		}
		LOG_VERBOSE("contentScaleFactor:"<<self.contentScaleFactor);
	}
	
    if (gles2) {
        m_render = new GHL::RenderOpenGLES2(GHL::UInt32(w),
									 GHL::UInt32(h),[m_context haveDepth]);
    } else {
        m_render = new GHL::RenderOpenGLES(GHL::UInt32(w),
                                            GHL::UInt32(h), [m_context haveDepth]);
    }
	m_render->RenderInit();
	g_application->SetRender(m_render);
	GHL::g_default_framebuffer = [m_context defaultFramebuffer];
	if (g_application->Load()) {
		m_timer = [NSTimer scheduledTimerWithTimeInterval: 1.0f/200.0f target:self selector:@selector(timerFireMethod:) userInfo:nil repeats:YES];
		[m_timer fire];
		m_loaded = true;
	}
	::gettimeofday(&m_timeval,0);
	[pool drain];
}

- (void)drawRect:(CGRect)dirtyRect {
    (void)dirtyRect;
	if (m_loaded  && m_active) {
		NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
		::timeval time;
		::gettimeofday(&time,0);
		GHL::UInt32 dt = static_cast<GHL::UInt32>((time.tv_sec - m_timeval.tv_sec)*1000000 + time.tv_usec - m_timeval.tv_usec);
		m_timeval = time;
		[self makeCurrent];
		GHL::g_default_framebuffer = [m_context defaultFramebuffer];
		if (g_application->OnFrame(dt)) {
			
		}
        [m_context present];
        [pool drain];
	}
}

- (int)touchNum:(UITouch*)touch {
	for (size_t i=0;i<max_touches;i++) {
		if (m_touches[i]==touch)
			return int(i);
	}
	return -1;
}


- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {
	for (UITouch* touch in touches) {
		CGPoint pos = [touch locationInView:self];
        pos.x*=self.contentScaleFactor;
		pos.y*=self.contentScaleFactor;
		int touch_num = -1;
		for (size_t i=0;i<max_touches;i++) {
			if (m_touches[i]==0) {
				touch_num = int(i);
				break;
			}
		}
		if (touch_num<0)
			continue;
		m_touches[touch_num]=touch; /// no retain!!
		GHL::MouseButton btn = GHL::TOUCH_1;
		if (touch_num>0) {
			btn = GHL::MouseButton(GHL::MUTITOUCH_1+touch_num-1);
		}
        GHL::Event e;
        e.type = GHL::EVENT_TYPE_MOUSE_PRESS;
        e.data.mouse_press.button = btn;
        e.data.mouse_press.modificators = 0;
        e.data.mouse_press.x = pos.x;
        e.data.mouse_press.y = pos.y;
        g_application->OnEvent(&e);
        //LOG_DEBUG("touchBegan " << touch_num << " : " << pos.x << pos.y );
	}
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event {
	for (UITouch* touch in touches) {
		CGPoint pos = [touch locationInView:self];
        pos.x*=self.contentScaleFactor;
		pos.y*=self.contentScaleFactor;
		int touch_num = [self touchNum:touch];
		if (touch_num<0) {
			continue;
		}
		m_touches[touch_num]=0;
		GHL::MouseButton btn = GHL::TOUCH_1;
		if (touch_num>0) {
			btn = GHL::MouseButton(GHL::MUTITOUCH_1+touch_num-1);
		}
        GHL::Event e;
        e.type = GHL::EVENT_TYPE_MOUSE_RELEASE;
        e.data.mouse_release.button = btn;
        e.data.mouse_release.modificators = 0;
        e.data.mouse_release.x = pos.x;
        e.data.mouse_release.y = pos.y;
        g_application->OnEvent(&e);
        //LOG_DEBUG("touchesEnded " << touch_num << " : " << pos.x << pos.y );
	}
}

- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event {
	[self touchesEnded:touches withEvent:event];
}

- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event {
	for (UITouch* touch in touches) {
		CGPoint pos = [touch locationInView:self];
        pos.x*=self.contentScaleFactor;
		pos.y*=self.contentScaleFactor;
		int touch_num = [self touchNum:touch];
		if (touch_num<0) {
			continue;
		}
		GHL::MouseButton btn = GHL::TOUCH_1;
		if (touch_num>0) {
			btn = GHL::MouseButton(GHL::MUTITOUCH_1+touch_num-1);
		}
        GHL::Event e;
        e.type = GHL::EVENT_TYPE_MOUSE_MOVE;
        e.data.mouse_move.button = btn;
        e.data.mouse_move.modificators = 0;
        e.data.mouse_move.x = pos.x;
        e.data.mouse_move.y = pos.y;
        g_application->OnEvent(&e);
        //LOG_DEBUG("touchesMoved " << touch_num << " : " << pos.x << pos.y );
	}
}


- (void)timerFireMethod:(NSTimer*)theTimer {
    (void)theTimer;
	if (m_active) {
        [self drawRect:[self bounds]];
	}
}

-(void)showKeyboard {
	[m_hiddenInput becomeFirstResponder];
}

-(void)hideKeyboard {
	[m_hiddenInput resignFirstResponder];
}

- (BOOL)textField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string {
	//use string here for the text input
	if (string!=nil && [string length]>0) {
		unichar wc = [string characterAtIndex:0];
        GHL::Event e;
        e.type = GHL::EVENT_TYPE_KEY_PRESS;
        e.data.key_press.key = GHL::KEY_NONE;
        e.data.key_press.modificators = 0;
        e.data.key_press.charcode = wc;
        g_application->OnEvent(&e);
    } else {
        GHL::Event e;
        e.type = GHL::EVENT_TYPE_KEY_PRESS;
        e.data.key_press.key = GHL::KEY_BACKSPACE;
        e.data.key_press.modificators = 0;
        e.data.key_press.charcode = 0;
        g_application->OnEvent(&e);
        e.type = GHL::EVENT_TYPE_KEY_RELEASE;
        g_application->OnEvent(&e);
   }
	/// always have one char
	textField.text = @"*";
	return NO;
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField {
    GHL::Event e;
    e.type = GHL::EVENT_TYPE_KEY_PRESS;
    e.data.key_press.key = GHL::KEY_ENTER;
    e.data.key_press.modificators = 0;
    e.data.key_press.charcode = 0;
    g_application->OnEvent(&e);
    e.type = GHL::EVENT_TYPE_KEY_RELEASE;
    g_application->OnEvent(&e);
	return NO;
}

-(void)dealloc {
	if (m_timer) {
		[m_timer release];
	}
	if (m_render) {
		m_render->RenderDone();
		delete m_render;
		m_render = 0;
	}
	[m_context deleteBuffers];
	
    [m_context release];
    m_context = nil;
	delete m_imageDecoder;
	delete m_sound;

	[super dealloc];
}

@end

@implementation WinLibViewController

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)orientation {
	if (g_orientation==UIInterfaceOrientationLandscapeRight && !g_orientationLocked) {
		if (orientation==UIInterfaceOrientationLandscapeLeft)
			return YES;
	}
    return orientation == g_orientation ? YES : NO; 
}

- (void)viewWillAppear:(BOOL)animated    // Called when the view is about to made visible. Default does nothing
{
    [super viewWillAppear:animated];
    [self registerForKeyboardNotifications];
}
- (void)viewDidAppear:(BOOL)animated     // Called when the view has been fully transitioned onto the screen. Default does nothing
{
	[(WinLibView*)self.view setActive: true];
}
- (void)viewWillDisappear:(BOOL)animated // Called when the view is dismissed, covered or otherwise hidden. Default does nothing
{
    [super viewWillDisappear:animated];
    
    [[NSNotificationCenter defaultCenter] removeObserver:self
                                                    name:UIKeyboardWillHideNotification
                                                  object:nil];
    [[NSNotificationCenter defaultCenter] removeObserver:self
                                                    name:UIKeyboardDidShowNotification
                                                  object:nil];
    [[NSNotificationCenter defaultCenter] removeObserver:self
                                                    name:UIKeyboardDidChangeFrameNotification
                                                  object:nil];
	[(WinLibView*)self.view setActive: false];
}
- (void)viewDidDisappear:(BOOL)animated  // Called after the view was dismissed, covered or otherwise hidden. Default does 
{
	
}

- (void)registerForKeyboardNotifications {
    
    
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(keyboardDidHide:)
                                                 name:UIKeyboardWillHideNotification object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(keyboardDidShow:)
                                                 name:UIKeyboardDidShowNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(keyboardDidChangeFrame:)
                                                 name:UIKeyboardDidChangeFrameNotification object:nil];
}

- (void)keyboardDidShow:(NSNotification *)note {
    [self keyboardDidChangeFrame:note];
    
}

- (void)keyboardDidHide:(NSNotification *)note {
	GHL::Event event;
    event.type = GHL::EVENT_TYPE_VISIBLE_RECT_CHANGED;
    event.data.visible_rect_changed.x = 0;
    event.data.visible_rect_changed.y = 0;
    event.data.visible_rect_changed.w = self.view.bounds.size.width * self.view.contentScaleFactor;
    event.data.visible_rect_changed.h = self.view.bounds.size.height * self.view.contentScaleFactor;
	g_application->OnEvent(&event);
}

- (void)keyboardDidChangeFrame:(NSNotification *)note {
    CGRect keyboardRect = [note.userInfo[UIKeyboardFrameEndUserInfoKey] CGRectValue];
    CGRect localRect = [self.view convertRect:keyboardRect fromView:nil];
    
    GHL::Event event;
    event.type = GHL::EVENT_TYPE_VISIBLE_RECT_CHANGED;
    event.data.visible_rect_changed.x = 0;
    event.data.visible_rect_changed.y = 0;
    event.data.visible_rect_changed.w = self.view.bounds.size.width * self.view.contentScaleFactor;
    event.data.visible_rect_changed.h = (self.view.bounds.size.height-localRect.origin.y) * self.view.contentScaleFactor;
	g_application->OnEvent(&event);
}

@end

@interface WinLibAppDelegate : NSObject<UIApplicationDelegate> {
	UIWindow* window;
	WinLibView*	view;
	WinLibViewController* controller;
	GHL::VFSCocoaImpl*	m_vfs;
	SystemCocoaTouch*	m_system;
}
@end

@implementation WinLibAppDelegate

- (void)doStartup {
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
    LOG_INFO("applicationDidFinishLaunching");
    
    m_vfs = new GHL::VFSCocoaImpl();
    g_application->SetVFS(m_vfs);
    
    CGRect rect = [[UIScreen mainScreen] bounds];
    float scale = [[UIScreen mainScreen] scale];
    
    GHL::Settings settings;
    settings.width = rect.size.width * scale;
    settings.height = rect.size.height * scale;
    settings.fullscreen = true;
    settings.depth = g_need_depth;
    settings.screen_dpi = 72.0 * scale;
    
    g_application->FillSettings(&settings);
    LOG_INFO("application require " << settings.width << "x" << settings.height);
    settings.fullscreen = true;
    
    if ( rect.size.width==320 && rect.size.height==480 ) {
        if (( settings.width >= 480*2 && settings.height >= 320*2 ) ||
            ( settings.height >= 480*2 && settings.width >= 320*2 ) ) {
            LOG_VERBOSE("Enable retina");
            g_retina_enabled = true;
        }
    }
    
    g_need_depth = settings.depth;
    
    if (settings.width > settings.height) {
        g_orientation = UIInterfaceOrientationLandscapeRight;
        settings.width = rect.size.height;
        settings.height = rect.size.width;
        LOG_VERBOSE("UIInterfaceOrientationLandscapeRight");
    } else {
        g_orientation = UIInterfaceOrientationPortrait;
        settings.width = rect.size.width;
        settings.height = rect.size.height;
        LOG_VERBOSE("UIInterfaceOrientationPortrait");
    }
    
    
    /// setup audio session
    AVAudioSession *session = [AVAudioSession sharedInstance];
    [session setCategory:AVAudioSessionCategoryAmbient error:nil];
    
    
    
    controller = [[WinLibViewController alloc] init];
    m_system = new SystemCocoaTouch(controller);
    g_application->SetSystem(m_system);
    
    window = [[UIWindow alloc] initWithFrame:rect];
    [window setAutoresizesSubviews:YES];
    
    GHL::Event e;
    e.type = GHL::EVENT_TYPE_APP_STARTED;
    g_application->OnEvent(&e);
    
    view = [[WinLibView alloc] initWithFrame:CGRectMake(0, 0, settings.width, settings.height)];
    controller.view = view;
    
    NSString *reqSysVer = @"4.0";
    NSString *currSysVer = [[UIDevice currentDevice] systemVersion];
    if ([currSysVer compare:reqSysVer options:NSNumericSearch] != NSOrderedAscending) {
        LOG_INFO("setRootViewController");
        [window setRootViewController:controller];
    } else
    {
        while(window.subviews.count > 0)
            [[window.subviews objectAtIndex:0] removeFromSuperview];
        [window addSubview:controller.view];
    }
    [window setOpaque:YES];
    
    
    [window makeKeyAndVisible];
    
    
    
    [pool drain];
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(nullable NSDictionary *)launchOptions {
    [self doStartup];
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    [view makeCurrent];
    GHL::Event e;
    e.type = GHL::EVENT_TYPE_DEACTIVATE;
    g_application->OnEvent(&e);
	[view setActive:false];
	//[view drawRect:[view bounds]];
	LOG_INFO("Deactivated");
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    [view makeCurrent];
    GHL::Event e;
    e.type = GHL::EVENT_TYPE_ACTIVATE;
    g_application->OnEvent(&e);
	[view setActive:true];
	//if ([view loaded]) [view drawRect:[view bounds]];
	LOG_INFO("Activated");
}

- (void)dealloc
{
	delete m_system;
	[super dealloc];
}

@end


void GHL_CALL SystemCocoaTouch::SwapBuffers() {
	//[[m_view getContext] presentRenderbuffer:GL_RENDERBUFFER_OES];	
}

void GHL_CALL SystemCocoaTouch::ShowKeyboard() {
	[(WinLibView*)m_controller.view showKeyboard];
}

void GHL_CALL SystemCocoaTouch::HideKeyboard() {
	[(WinLibView*)m_controller.view hideKeyboard];
}

bool GHL_CALL SystemCocoaTouch::SetDeviceState( GHL::DeviceState name, const void* data) {
	if (!data) return false;
	if (name==GHL::DEVICE_STATE_ACCELEROMETER_ENABLED) {
		const bool* state = (const bool*)data;
		if (*state && !m_accelerometer) {
			m_accelerometer = [[AccelerometerDelegate alloc] init];
		} else if (!*state && m_accelerometer) {
			[m_accelerometer release];
			m_accelerometer = nil;
		}
		return true;
	} else if (name==GHL::DEVICE_STATE_ORIENTATION_LOCKED) {
		g_orientationLocked = *(const bool*)data;
		return true;
	} else if (name==GHL::DEVICE_STATE_MULTITOUCH_ENABLED) {
		const bool* state = (const bool*)data;
		m_controller.view.multipleTouchEnabled = *state ? YES : NO;
		return true;
	} else if (name==GHL::DEVICE_STATE_RETINA_ENABLED) {
		const bool* state = (const bool*)data;
		g_retina_enabled = *state;
		return true;
    }
	return false;
}

static const char* level_descr[] = {
    "F:",
    "E:",
    "W:",
    "I:",
    "V:",
    "D:"
};

GHL_API void GHL_CALL GHL_Log( GHL::LogLevel level,const char* message) {
    (void)level;
   	NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
    NSLog( @"%s%@",level_descr[level],[NSString stringWithUTF8String:message] );
    [pool release];
}

GHL_API GHL::UInt32 GHL_CALL GHL_GetCurrentThreadId() {
    __uint64_t thread_id;
    pthread_threadid_np(pthread_self(),&thread_id);
    return (GHL::UInt32)(thread_id ^ (thread_id>>32));
}

GHL_API int GHL_CALL GHL_StartApplication( GHL::Application* app , int argc, char** argv) {
    (void)MODULE;
    g_application = app;
	NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
	UIApplicationMain(argc, argv, nil, @"WinLibAppDelegate");
	[pool release];
	return 0;
}
