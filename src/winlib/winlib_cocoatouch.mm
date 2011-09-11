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

#include "../render/opengl/render_opengl.h"

#include "ghl_application.h"
#include "ghl_settings.h"
#include "ghl_system.h"

#include "../sound/openal/ghl_sound_openal.h"
#include "../vfs/vfs_cocoa.h"
#include "../image/image_decoders.h"

#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>
#import <OpenGLES/EAGL.h>
#import <OpenGLES/EAGLDrawable.h>
#import <QuartzCore/QuartzCore.h>

static GHL::Application* g_application = 0;
static UIInterfaceOrientation g_orientation = UIInterfaceOrientationLandscapeLeft;
static bool g_orientationLocked = false;

namespace GHL {
	extern UInt32 g_default_renderbuffer;
}

@class WinLibView;

@interface AccelerometerDelegate : NSObject<UIAccelerometerDelegate>
{
	UIAccelerometer* accelerometer;
	float data[3];
}
- (id)init;
- (void)accelerometer:(UIAccelerometer *)accelerometer didAccelerate:(UIAcceleration *)acceleration;
float* get_data;
@end

@implementation AccelerometerDelegate

- (id)init
{
	if (self = [super init]) {
		accelerometer = [UIAccelerometer sharedAccelerometer];
		accelerometer.updateInterval = 0.1;
		accelerometer.delegate = self;
	}
	return self;
}

- (float*)get_data
{
	return data;
}

- (void)dealloc
{
	accelerometer.delegate = nil;
	[super dealloc];
}

- (void)accelerometer:(UIAccelerometer *)accelerometer didAccelerate:(UIAcceleration *)acceleration
{
	data[0]=acceleration.x;
	data[1]=acceleration.y;
	data[2]=acceleration.y;
}


@end



class SystemCocoaTouch : public GHL::System {
private:
	WinLibView* m_view;
	AccelerometerDelegate* m_accelerometer;
public:
	explicit SystemCocoaTouch(WinLibView* view) : m_view(view) {
		m_accelerometer = 0;
	}
	~SystemCocoaTouch() {
		[m_accelerometer release]; 
	}
	virtual void GHL_CALL Exit() {
		///
		NSLog(@"Call GHL::System::Exit on iOS disallow");
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
	virtual bool GHL_CALL SetDeviceState( GHL::DeviceState name, void* data) {
		if (name==GHL::DEVICE_STATE_ACCELEROMETER_ENABLED) {
			bool* state = (bool*)data;
			if (*state && !m_accelerometer) {
				m_accelerometer = [[AccelerometerDelegate alloc] init];
			} else if (!*state && m_accelerometer) {
				[m_accelerometer release];
				m_accelerometer = nil;
			}
			return true;
		} else if (name==GHL::DEVICE_STATE_ORIENTATION_LOCKED) {
			g_orientationLocked = *(bool*)data;
		}
		return false;
	}
	///
	virtual bool GHL_CALL GetDeviceData( GHL::DeviceData name, void* data) {
		if (name==GHL::DEVICE_DATA_ACCELEROMETER) {
			if (!m_accelerometer)
				return false;
			memcpy(data, [m_accelerometer get_data], sizeof(float)*3);
			return true;
		}
		return false;
	}
};

@interface WinLibViewController : UIViewController
{
	
}

@end

@implementation WinLibViewController

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)orientation {
	if (g_orientation==UIInterfaceOrientationLandscapeRight && !g_orientationLocked) {
		if (orientation==UIInterfaceOrientationLandscapeLeft)
			return YES;
	}
    return orientation == g_orientation; 
}

@end

@interface WinLibView : UIView<UITextFieldDelegate> {
	EAGLContext*	m_context;
	// The OpenGL ES names for the framebuffer and renderbuffer used to render to this view
    GLuint m_defaultFramebuffer, m_colorRenderbuffer;
	// The pixel dimensions of the CAEAGLLayer
    GLint m_backingWidth;
    GLint m_backingHeight;
	SystemCocoaTouch*	m_system;
	GHL::ImageDecoderImpl* m_imageDecoder;
	GHL::SoundOpenAL*	m_sound;
	NSString*	m_appName;
	GHL::RenderOpenGL* m_render;
	NSTimer*	m_timer;
	bool	m_loaded;
	::timeval	m_timeval;
	bool	m_active;
	UITextField* m_hiddenInput;
}

- (void)prepareOpenGL;
- (EAGLContext*) getContext;
- (void)setActive:(bool) a;
- (bool)loaded;
- (void)showKeyboard;
- (void)hideKeyboard;

@end


@implementation WinLibView

+ (Class)layerClass
{
    return [CAEAGLLayer class];
}

- (EAGLContext*) getContext {
	return m_context;
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
		
		m_context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES1];
		
        if (!m_context || ![EAGLContext setCurrentContext:m_context])
        {
            [self release];
            return nil;
        }
		
		m_system = new SystemCocoaTouch(self);
		g_application->SetSystem(m_system);
		
        // Create default framebuffer object. The backing will be allocated for the current layer in -resizeFromLayer
        glGenFramebuffersOES(1, &m_defaultFramebuffer);
        glGenRenderbuffersOES(1, &m_colorRenderbuffer);
        glBindFramebufferOES(GL_FRAMEBUFFER_OES, m_defaultFramebuffer);
        glBindRenderbufferOES(GL_RENDERBUFFER_OES, m_colorRenderbuffer);
        glFramebufferRenderbufferOES(GL_FRAMEBUFFER_OES, GL_COLOR_ATTACHMENT0_OES, GL_RENDERBUFFER_OES, m_colorRenderbuffer);
		
		GHL::g_default_renderbuffer = m_colorRenderbuffer;
		
		m_sound = 0;
#ifndef GHL_NO_SOUND
		m_sound = new GHL::SoundOpenAL();
		if (!m_sound->SoundInit()) {
			delete m_sound;
			m_sound = 0;
		}
		g_application->SetSound(m_sound);
#endif
		
		m_hiddenInput = [[UITextField alloc] initWithFrame:CGRectMake(0, 0, 0, 0)];
		m_hiddenInput.delegate = self;
		m_hiddenInput.keyboardType = UIKeyboardTypeASCIICapable;
		m_hiddenInput.returnKeyType = UIReturnKeyDone;
		m_hiddenInput.text = @"*";
		[self addSubview:m_hiddenInput];
		
		[self prepareOpenGL];
	}
	return self;
}

- (void)layoutSubviews
{
	[EAGLContext setCurrentContext:m_context];
	// Allocate color buffer backing based on the current layer size
    glBindRenderbufferOES(GL_RENDERBUFFER_OES, m_colorRenderbuffer);
    [m_context renderbufferStorage:GL_RENDERBUFFER_OES fromDrawable:(CAEAGLLayer*)self.layer];
    glGetRenderbufferParameterivOES(GL_RENDERBUFFER_OES, GL_RENDERBUFFER_WIDTH_OES, &m_backingWidth);
    glGetRenderbufferParameterivOES(GL_RENDERBUFFER_OES, GL_RENDERBUFFER_HEIGHT_OES, &m_backingHeight);
	GHL::g_default_renderbuffer = m_colorRenderbuffer;
	m_render->Resize(m_backingWidth, m_backingHeight);
    if (glCheckFramebufferStatusOES(GL_FRAMEBUFFER_OES) != GL_FRAMEBUFFER_COMPLETE_OES)
    {
        NSLog(@"Failed to make complete framebuffer object %x", glCheckFramebufferStatusOES(GL_FRAMEBUFFER_OES));
    }
	
}

- (void)prepareOpenGL {
	/// @todo create render there
	NSLog( @"prepareOpenGL" ); 
	NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
	[EAGLContext setCurrentContext:m_context];
	m_render = new GHL::RenderOpenGL(GHL::UInt32([self bounds].size.width),
									 GHL::UInt32([self bounds].size.height));
	m_render->RenderInit();
	g_application->SetRender(m_render);
	GHL::g_default_renderbuffer = m_colorRenderbuffer;
	if (g_application->Load()) {
		m_timer = [NSTimer scheduledTimerWithTimeInterval: 1.0f/200.0f target:self selector:@selector(timerFireMethod:) userInfo:nil repeats:YES];
		[m_timer fire];
		m_loaded = true;
		m_active = true;
	}
	::gettimeofday(&m_timeval,0);
	[pool drain];
	//[pool release];
}

- (void)drawRect:(CGRect)dirtyRect {
    (void)dirtyRect;
	if (m_loaded ) {
		NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
		::timeval time;
		::gettimeofday(&time,0);
		GHL::UInt32 dt = static_cast<GHL::UInt32>((time.tv_sec - m_timeval.tv_sec)*1000000 + time.tv_usec - m_timeval.tv_usec);
		m_timeval = time;
		[EAGLContext setCurrentContext:m_context];
		GHL::g_default_renderbuffer = m_colorRenderbuffer;
		m_render->ResetRenderState();
		if (g_application->OnFrame(dt)) {
			[m_context presentRenderbuffer:GL_RENDERBUFFER_OES];
		}
		[pool drain];
	}
}


- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {
	UITouch* touch = (UITouch*)[touches anyObject];
	CGPoint pos = [touch locationInView:self];
	g_application->OnMouseDown(GHL::TOUCH_1,pos.x,pos.y);
	//NSLog(@"touchBegan %dx%d",int(pos.x),int(pos.y));
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event {
	UITouch* touch = (UITouch*)[touches anyObject];
	CGPoint pos = [touch locationInView:self];
	g_application->OnMouseUp(GHL::TOUCH_1,pos.x,pos.y);
	//NSLog(@"touchEnded %dx%d",int(pos.x),int(pos.y));
}

- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event {
	/// @todo handle all touches
	[self touchesEnded:touches withEvent:event];
}

- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event {
	UITouch* touch = (UITouch*)[touches anyObject];
	CGPoint pos = [touch locationInView:self];
	g_application->OnMouseMove(GHL::TOUCH_1,pos.x,pos.y);
	//NSLog(@"touchMoved %dx%d",int(pos.x),int(pos.y));
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
		wchar_t wc = [string characterAtIndex:0];
		g_application->OnChar(wc);
	} else {
		//NSLog(@"backspace");
		g_application->OnKeyDown(GHL::KEY_BACKSPACE);
		g_application->OnKeyUp(GHL::KEY_BACKSPACE);
	}
	/// always have one char
	textField.text = @"*";
	return NO;
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField {
	g_application->OnKeyDown(GHL::KEY_ENTER);
	g_application->OnKeyUp(GHL::KEY_ENTER);
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
	// Tear down GL
    if (m_defaultFramebuffer)
    {
        glDeleteFramebuffersOES(1, &m_defaultFramebuffer);
        m_defaultFramebuffer = 0;
    }
	
    if (m_colorRenderbuffer)
    {
        glDeleteRenderbuffersOES(1, &m_colorRenderbuffer);
        m_colorRenderbuffer = 0;
    }
	
    // Tear down context
    if ([EAGLContext currentContext] == m_context)
        [EAGLContext setCurrentContext:nil];
	
    [m_context release];
    m_context = nil;
	delete m_imageDecoder;
	delete m_sound;

	delete m_system;
	[super dealloc];
}

@end

@interface WinLibAppDelegate : NSObject<UIApplicationDelegate> {
	UIWindow* window;
	WinLibView*	view;
	WinLibViewController* controller;
	GHL::VFSCocoaImpl*	m_vfs;
}
@end

@implementation WinLibAppDelegate

- (void)applicationDidFinishLaunching:(UIApplication *)application {
	
	NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
	
	m_vfs = new GHL::VFSCocoaImpl();
	g_application->SetVFS(m_vfs);

	GHL::Settings settings;
	settings.width = 1024;
	settings.height = 768;
	settings.fullscreen = true;
	g_application->FillSettings(&settings);
	
	if (settings.width > settings.height) {
		g_orientation = UIInterfaceOrientationLandscapeRight;
	} else {
		g_orientation = UIInterfaceOrientationPortrait;
	}
	
	
	/// setup audio session
	AVAudioSession *session = [AVAudioSession sharedInstance];
	[session setCategory:AVAudioSessionCategoryAmbient error:nil];
	
	
	
	controller = [[WinLibViewController alloc] init];
	
	window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
	
	view = [[WinLibView alloc] initWithFrame:CGRectMake(0, 0, settings.width, settings.height)];
	controller.view = view;
	
	NSString *reqSysVer = @"4.0";
	NSString *currSysVer = [[UIDevice currentDevice] systemVersion];
	if ([currSysVer compare:reqSysVer options:NSNumericSearch] != NSOrderedAscending)
		[window setRootViewController:controller];
	else
	{
		while(window.subviews.count > 0)
			[[window.subviews objectAtIndex:0] removeFromSuperview];
		[window addSubview:controller.view];
	}
	[window setOpaque:YES];
	[window makeKeyAndVisible];
	
	[pool drain];
}

- (void)applicationWillResignActive:(UIApplication *)application
{
	[EAGLContext setCurrentContext:[view getContext]];
	g_application->OnDeactivated();
	[view setActive:false];
	//[view drawRect:[view bounds]];
	NSLog(@"Deactivated");
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
	[EAGLContext setCurrentContext:[view getContext]];
	g_application->OnActivated();
	[view setActive:true];
	//if ([view loaded]) [view drawRect:[view bounds]];
	NSLog(@"Activated");
}
@end


void GHL_CALL SystemCocoaTouch::SwapBuffers() {
	[[m_view getContext] presentRenderbuffer:GL_RENDERBUFFER_OES];	
}

void GHL_CALL SystemCocoaTouch::ShowKeyboard() {
	[m_view showKeyboard];
}

void GHL_CALL SystemCocoaTouch::HideKeyboard() {
	[m_view hideKeyboard];
}




GHL_API int GHL_CALL GHL_StartApplication( GHL::Application* app , int argc, char** argv) {
    g_application = app;
	NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
	UIApplicationMain(argc, argv, nil, @"WinLibAppDelegate");
	[pool release];
	return 0;
}