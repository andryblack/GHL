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

#include "../sound/cocoa/ghl_sound_cocoa.h"
#include "../vfs/vfs_cocoa.h"
#include "../image/image_decoders.h"

#import <OpenGLES/EAGLDrawable.h>

#import <CoreMotion/CoreMotion.h>

#import "WinLibCocoaTouchContext2.h"
#import "winlib_cocoatouch.h"

#include <pthread.h>
#include <sys/utsname.h>


static const char* MODULE = "WINLIB";

static GHL::Application* g_application = 0;
static UIInterfaceOrientation g_orientation = UIInterfaceOrientationLandscapeLeft;
static bool g_orientationLocked = false;
static bool g_multitouchEnabled = false;
static bool g_need_depth = false;
static GHL::Int32 g_frame_interval = 1;

#ifndef GHL_NOSOUND
extern GHL::SoundCocoa* GHL_CreateSoundCocoa();
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

@interface TextInputDelegate : NSObject<UITextFieldDelegate> {
    UIScrollView* m_input_view;
    CGSize m_kb_size;
}

@end

@implementation TextInputDelegate

+(void)configureInput:(NSObject<UIKeyInput>*) input config:(const GHL::TextInputConfig*) config {
    
    input.keyboardType = UIKeyboardTypeDefault;
    
    input.spellCheckingType = UITextSpellCheckingTypeNo;
    input.autocapitalizationType = UITextAutocapitalizationTypeNone;
    input.autocorrectionType = UITextAutocorrectionTypeNo;
    if ([input respondsToSelector:@selector(setKeyboardAppearance:)]) {
        input.keyboardAppearance = UIKeyboardAppearanceDark;
    }
    
    switch (config->accept_button) {
        case GHL::TIAB_SEND:
            input.returnKeyType = UIReturnKeySend;
            break;
        default:
            input.returnKeyType = UIReturnKeyDone;
            break;
    }

}

-(id)init {
    if (self=[super init]) {
        m_input_view = 0;
        m_kb_size = CGSizeZero;
    }
    return self;
}

-(void)dealloc {
    [super dealloc];
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField {
    GHL::Event e;
    e.type = GHL::EVENT_TYPE_TEXT_INPUT_ACCEPTED;
    e.data.text_input_accepted.text = textField.text.UTF8String;
    g_application->OnEvent(&e);
    return YES;
}

-(void)textFieldDidEndEditing:(UITextField *)textField {
    GHL::Event e;
    e.type = GHL::EVENT_TYPE_TEXT_INPUT_TEXT_CHANGED;
    e.data.text_input_text_changed.text = textField.text.UTF8String;}

-(void)cenacelEditing:(id)sendr {
    [self close];
}

-(void)show:(const GHL::TextInputConfig*)input withController:(UIViewController*) controller {
    [self close];
    
    
    UITextField* field = 0;
    if (!m_input_view) {
        m_input_view = [[UIScrollView alloc] initWithFrame:controller.view.bounds];
        m_input_view.scrollEnabled = NO;
        m_input_view.contentSize = m_input_view.frame.size;
        CGRect rect = CGRectMake(0, 0, m_input_view.frame.size.width, 32);
        field = [[UITextField alloc] initWithFrame:rect];
        field.backgroundColor = [UIColor darkGrayColor];
        field.textColor = [UIColor whiteColor];
        field.delegate = self;
        field.borderStyle = UITextBorderStyleRoundedRect;
        field.tag = 123;
        
        UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(cenacelEditing:)];
        [m_input_view addGestureRecognizer:tap];
        
        [controller.view addSubview:m_input_view];
        [m_input_view addSubview:field];
    } else {
        [controller.view addSubview:m_input_view];
        field = (UITextField*)[m_input_view viewWithTag:123];
    }
    
    [TextInputDelegate configureInput:field config:input];
    
    field.text = @"";
    const char* placeholder = input->placeholder;
    if (placeholder && *placeholder) {
        field.placeholder = [NSString stringWithUTF8String:placeholder];
    } else {
        field.placeholder = @"";
    }
    
    [self layout:m_kb_size];
    
    if (field.window && [field becomeFirstResponder]) {
        
    } else {
        [field performSelector:@selector(becomeFirstResponder) withObject:nil afterDelay:0.1];
    }
}

-(void)layout:(CGSize)kbSize {
    m_kb_size = kbSize;
    

    UIEdgeInsets contentInsets = UIEdgeInsetsMake(0,0,0,0);
    if (m_input_view) {
        contentInsets.bottom = m_kb_size.height;
#if __IPHONE_OS_VERSION_MAX_ALLOWED > __IPHONE_11_0
        if (@available(iOS 11.0, *)) {
            UIEdgeInsets insets = m_input_view.safeAreaInsets;
            contentInsets.left = insets.left;
            contentInsets.right = insets.right;
            contentInsets.top = insets.top;
            if (insets.bottom > contentInsets.bottom) {
                contentInsets.bottom = insets.bottom;
            }
        }
#endif
        m_input_view.contentInset = contentInsets;
    }
    if (m_input_view && (m_input_view.superview!=0)) {
        m_input_view.frame = m_input_view.superview.bounds;
        m_input_view.contentSize = m_input_view.window.screen.bounds.size;
        
        UITextField* field = (UITextField*)[m_input_view viewWithTag:123];
        field.frame = CGRectMake(contentInsets.left,
                                 m_input_view.contentSize.height-32,
                                 m_input_view.contentSize.width-contentInsets.left-contentInsets.right, 32);
        [m_input_view scrollRectToVisible:field.frame animated:YES];
    }
}

-(void)close {
    if (m_input_view && (m_input_view.superview!=nil)) {
        [m_input_view removeFromSuperview];
        GHL::Event e;
        e.type = GHL::EVENT_TYPE_TEXT_INPUT_CLOSED;
        g_application->OnEvent(&e);
    }
    if (m_input_view) {
        [m_input_view removeFromSuperview];
    }
}

@end

@interface HiddenInput : UIView <UIKeyInput>

@property(nonatomic) UITextAutocapitalizationType autocapitalizationType; // default is UITextAutocapitalizationTypeSentences
@property(nonatomic) UITextAutocorrectionType autocorrectionType;         // default is UITextAutocorrectionTypeDefault
@property(nonatomic) UITextSpellCheckingType spellCheckingType;  // default is UITextSpellCheckingTypeDefault;
@property(nonatomic) UIKeyboardType keyboardType;                         // default is UIKeyboardTypeDefault
@property(nonatomic) UIKeyboardAppearance keyboardAppearance;             // default is UIKeyboardAppearanceDefault
@property(nonatomic) UIReturnKeyType returnKeyType;                       // default is

@end


@implementation HiddenInput
- (void)insertText:(NSString *)text {
    if (text!=nil && [text length]>0) {
        unichar wc = [text characterAtIndex:0];
        GHL::Event e;
        e.type = GHL::EVENT_TYPE_KEY_PRESS;
        e.data.key_press.key = wc == '\n' ? GHL::KEY_ENTER : GHL::KEY_NONE;
        e.data.key_press.modificators = 0;
        e.data.key_press.charcode = wc;
        g_application->OnEvent(&e);
        e.type = GHL::EVENT_TYPE_KEY_RELEASE;
        e.data.key_release.key = e.data.key_press.key;
        g_application->OnEvent(&e);
    }
}
- (void)deleteBackward {
    GHL::Event e;
    e.type = GHL::EVENT_TYPE_KEY_PRESS;
    e.data.key_press.key = GHL::KEY_BACKSPACE;
    e.data.key_press.modificators = 0;
    e.data.key_press.charcode = 0;
    g_application->OnEvent(&e);
    e.type = GHL::EVENT_TYPE_KEY_RELEASE;
    e.data.key_release.key = e.data.key_press.key;
    g_application->OnEvent(&e);
}
- (BOOL)hasText {
    // Return whether there's any text present
    return YES;
}
- (BOOL)canBecomeFirstResponder {
    return YES;
}
@end

@interface WinLibView : UIView<UITextFieldDelegate> {
    WinLibCocoaTouchContext*    m_context;
    
	GHL::ImageDecoderImpl* m_imageDecoder;
	GHL::SoundCocoa*	m_sound;
	NSString*	m_appName;
	GHL::RenderImpl* m_render;
	CADisplayLink *m_timer;
	bool	m_loaded;
	::timeval	m_timeval;
	bool	m_active;
	HiddenInput* m_hiddenInput;
	UITouch* m_touches[max_touches];
    GHL::Int32 m_borders[4];
    bool m_need_relayout;
}

- (void)prepareOpenGL:(Boolean) gles2;
- (void)makeCurrent;
- (void)setActive:(bool) a;
- (bool)loaded;
- (void)showKeyboard:(const GHL::TextInputConfig*) config;
- (void)hideKeyboard;
- (void)setFrameInterval:(GHL::Int32)interval;
- (void)fillBorders:(GHL::Int32*)borders;
@end

@interface WinLibViewController : UIViewController
{
    
    TextInputDelegate* m_text_input;
}

- (void) closeTextInput;

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
    virtual void GHL_CALL ShowKeyboard(const GHL::TextInputConfig* input);
		
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
        } else if (name == GHL::DEVICE_DATA_NAME) {
            struct utsname systemInfo;
            uname(&systemInfo);
            
            if (data) {
                char* dest = static_cast<char*>(data);
                ::strncpy(dest, systemInfo.machine, 128);
                return true;
            }
        } else if (name == GHL::DEVICE_DATA_OS) {
            NSString* name = [[UIDevice currentDevice] systemName];
            NSString* ver = [[UIDevice currentDevice] systemVersion];
            NSString* full = [NSString stringWithFormat:@"%@ %@",name,ver];
            if (full && data) {
                char* dest = static_cast<char*>(data);
                ::strncpy(dest, [full UTF8String], 32);
                return true;
            }
        } else if ( name == GHL::DEVICE_DATA_SCREEN_BORDERS) {
            if (m_controller && m_controller.viewLoaded) {
                WinLibView* v = (WinLibView*)m_controller.view;
                [v fillBorders:static_cast<GHL::Int32*>(data)];
                return true;
            }
        } else if ( name == GHL::DEVICE_DATA_ORIENTATION) {
            if (m_controller) {
                *static_cast<char*>(data) = 0;
                if (m_controller.interfaceOrientation == UIInterfaceOrientationPortrait) {
                    strncpy(static_cast<char*>(data),"portrait",32);
                } else if (m_controller.interfaceOrientation == UIInterfaceOrientationPortraitUpsideDown) {
                    strncpy(static_cast<char*>(data),"portrait_ud",32);
                } else if (m_controller.interfaceOrientation == UIInterfaceOrientationLandscapeLeft) {
                    strncpy(static_cast<char*>(data),"landscape_left",32);
                } else if (m_controller.interfaceOrientation == UIInterfaceOrientationLandscapeRight) {
                    strncpy(static_cast<char*>(data),"landscape_right",32);
                } else {
                    return false;
                }
                return true;
            }
        }
        return false;
	}
    ///
    virtual void GHL_CALL SetTitle( const char* title ) {
        /// do nothing
    }
    virtual bool GHL_CALL OpenURL( const char* url ) {
        return [[UIApplication sharedApplication] openURL:[NSURL URLWithString:[NSString stringWithUTF8String:url]]];
    }
};







@implementation WinLibView

+ (Class)layerClass
{
    return [CAEAGLLayer class];
}

- (void)markRelayout {
    m_need_relayout = true;
}

- (bool)loaded{
	return m_loaded;
}
- (void)setActive:(bool) a {
	if (m_active!=a) {
		m_active = a;
	}
    if (m_timer) {
        [m_timer setPaused:!m_active];
    }
    if (m_active) {
        [self updateScale];
        [self resumeSound];
    }
}

-(void)didMoveToWindow
{
    [self updateScale];
}

-(float)updateScale {
    UIScreen* screen = self.window.screen;
    float scale = 1.0f;
    if (!screen) {
        screen = [UIScreen mainScreen];
    }
    if ([UIScreen instancesRespondToSelector:@selector(nativeScale)]) {
        scale = screen.nativeScale;
    } else {
        scale = screen.scale;
    }
    self.contentScaleFactor = scale;
    self.multipleTouchEnabled = g_multitouchEnabled ? YES : NO;
    return scale;
}

-(id) initWithFrame:(CGRect) rect {
	if (self = [super initWithFrame:rect]) {
        m_timer = nil;
        
		m_appName = (NSString*)[[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleName"];
		m_imageDecoder = 0;
		
		m_active = false;
        
        m_borders[0]=m_borders[1]=m_borders[2]=m_borders[3]=0;
        m_need_relayout = false;
		
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
        
        [self updateScale];
		
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
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onAudioSessionEvent:) name:AVAudioSessionInterruptionNotification object:nil];

#endif
		
		for (size_t i=0;i<max_touches;i++) {
			m_touches[i] = 0;
		}
		
        m_hiddenInput = [[HiddenInput alloc] init];
		[self addSubview:m_hiddenInput];
		
        [self setAutoresizesSubviews:YES];
        [self updateScale];
		
		[self prepareOpenGL:gles2];
	}
	return self;
}

- (void) onAudioSessionEvent: (NSNotification *) notification
{
    //Check the type of notification, especially if you are sending multiple AVAudioSession events here
    NSLog(@"Interruption notification name %@", notification.name);
    
    if ([notification.name isEqualToString:AVAudioSessionInterruptionNotification]) {
        NSLog(@"Interruption notification received %@!", notification);
        
        //Check to see if it was a Begin interruption
        if ([[notification.userInfo valueForKey:AVAudioSessionInterruptionTypeKey] isEqualToNumber:[NSNumber numberWithInt:AVAudioSessionInterruptionTypeBegan]]) {
            LOG_INFO("Interruption began!");
            [self suspendSound];
            
        } else if([[notification.userInfo valueForKey:AVAudioSessionInterruptionTypeKey] isEqualToNumber:[NSNumber numberWithInt:AVAudioSessionInterruptionTypeEnded]]){
            LOG_INFO("Interruption ended!");
            //Resume your audio
            [self resumeSound];
            
        }
    }
}

- (void)suspendSound {
#ifndef GHL_NO_SOUND
    if (m_sound) {
        m_sound->Suspend();
    }
    //AVAudioSession *session = [AVAudioSession sharedInstance];
    //[session setActive:NO error:nil];

#endif
}

- (void)resumeSound {
#ifndef GHL_NO_SOUND
    AVAudioSession *session = [AVAudioSession sharedInstance];
    [session setActive:YES error:nil];

    if (m_sound) {
        m_sound->Resume();
    }
#endif
}

- (void)makeCurrent {
    [m_context makeCurrent];
}

- (void)layoutSubviews
{
    LOG_VERBOSE( "layoutSubviews" );
    [self updateScale];

	[m_context onLayout:(CAEAGLLayer*)self.layer];
    GHL::g_default_framebuffer = [m_context defaultFramebuffer];
    
#if __IPHONE_OS_VERSION_MAX_ALLOWED > __IPHONE_11_0
    if (@available(iOS 11.0, *)) {
        UIEdgeInsets insets = self.safeAreaInsets;
        m_borders[0]=insets.left * self.contentScaleFactor;
        m_borders[1]=insets.right * self.contentScaleFactor;
        m_borders[2]=insets.top * self.contentScaleFactor;
        m_borders[3]=insets.bottom * self.contentScaleFactor;
        m_need_relayout = true;
    } else {
        // Fallback on earlier versions
    }
#endif
    
	m_render->Resize([m_context backingWidth], [m_context backingHeight]);
 	
}

- (void)fillBorders:(GHL::Int32*)borders {
    for (size_t i=0;i<4;++i)
        borders[i]=m_borders[i];
}
- (void)prepareOpenGL:(Boolean) gles2 {
	LOG_VERBOSE( "prepareOpenGL " << (gles2 ? "GLES2" : "GLES1") );
	NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
	[self makeCurrent];
	int w = [self bounds].size.width;
	int h = [self bounds].size.height;
    [self updateScale];
    w *= self.contentScaleFactor;
    h *= self.contentScaleFactor;
	
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
        m_timer = [CADisplayLink displayLinkWithTarget:self selector:@selector(tick:)];
        [m_timer setFrameInterval:g_frame_interval];
        [m_timer addToRunLoop:[NSRunLoop mainRunLoop] forMode:NSDefaultRunLoopMode];
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
        
        if (m_need_relayout) {
            GHL::Event e;
            e.type = GHL::EVENT_TYPE_RELAYOUT;
            m_need_relayout = false;
            g_application->OnEvent(&e);
        }
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
			btn = GHL::MouseButton(GHL::MULTITOUCH_1+touch_num-1);
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
			btn = GHL::MouseButton(GHL::MULTITOUCH_1+touch_num-1);
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
			btn = GHL::MouseButton(GHL::MULTITOUCH_1+touch_num-1);
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

- (void)tick:(CADisplayLink*)displayLink {
    (void)displayLink;
    if (m_active) {
        [self drawRect:[self bounds]];
    }
}

-(void)showKeyboard:(const GHL::TextInputConfig*) config {
    if (config) {
        [TextInputDelegate configureInput:m_hiddenInput config:config];
    } else {
        
        m_hiddenInput.keyboardType = UIKeyboardTypeDefault;
        m_hiddenInput.returnKeyType = UIReturnKeyDone;
        m_hiddenInput.spellCheckingType = UITextSpellCheckingTypeNo;
        m_hiddenInput.autocapitalizationType = UITextAutocapitalizationTypeNone;
        m_hiddenInput.autocorrectionType = UITextAutocorrectionTypeNo;
        if ([m_hiddenInput respondsToSelector:@selector(setKeyboardAppearance:)]) {
            m_hiddenInput.keyboardAppearance = UIKeyboardAppearanceDark;
        }
        
    }
    [m_hiddenInput becomeFirstResponder];
}

-(void)hideKeyboard {
	[m_hiddenInput resignFirstResponder];
}

- (void)setFrameInterval:(GHL::Int32)interval {
    [m_timer setFrameInterval:interval];
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
    if (m_sound) {
        m_sound->SoundDone();
        delete m_sound;
    }

    [[NSNotificationCenter defaultCenter] removeObserver:self name:AVAudioSessionInterruptionNotification object:nil];
    
	[super dealloc];
}

@end

@implementation WinLibViewController

- (id)init {
    if (self = [super init]) {
        m_text_input = [[TextInputDelegate alloc] init];
    }
    return self;
}

- (void) dealloc {
    [m_text_input release];
    [super dealloc];
}

- (void) showTextInput:(const GHL::TextInputConfig*) input {
    [m_text_input show:input withController:self];
}

- (void) closeTextInput {
    [m_text_input close];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)orientation {
	if (g_orientation==UIInterfaceOrientationLandscapeRight && !g_orientationLocked) {
		if (orientation==UIInterfaceOrientationLandscapeLeft)
			return YES;
	}
    return orientation == g_orientation ? YES : NO; 
}

- (void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation {
    [super didRotateFromInterfaceOrientation:fromInterfaceOrientation];
    if (self.viewLoaded) {
        [(WinLibView*)self.view markRelayout];
    }
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
    [m_text_input layout:CGSizeZero];
	GHL::Event event;
    event.type = GHL::EVENT_TYPE_VISIBLE_RECT_CHANGED;
    event.data.visible_rect_changed.x = 0;
    event.data.visible_rect_changed.y = 0;
    event.data.visible_rect_changed.w = self.view.bounds.size.width * self.view.contentScaleFactor;
    event.data.visible_rect_changed.h = self.view.bounds.size.height * self.view.contentScaleFactor;
	g_application->OnEvent(&event);
    event.type = GHL::EVENT_TYPE_KEYBOARD_HIDE;
    g_application->OnEvent(&event);
}

- (void)keyboardDidChangeFrame:(NSNotification *)note {
    if (![note userInfo])
        return;
    if (![[note userInfo] objectForKey:UIKeyboardFrameEndUserInfoKey] )
        return;
    CGRect keyboardRect = [note.userInfo[UIKeyboardFrameEndUserInfoKey] CGRectValue];
    CGRect localRect = [self.view convertRect:keyboardRect fromView:nil];
    
    [m_text_input layout:keyboardRect.size];
    
    GHL::Event event;
    event.type = GHL::EVENT_TYPE_VISIBLE_RECT_CHANGED;
    event.data.visible_rect_changed.x = 0;
    event.data.visible_rect_changed.y = 0;
    event.data.visible_rect_changed.w = self.view.bounds.size.width * self.view.contentScaleFactor;
    event.data.visible_rect_changed.h = localRect.origin.y * self.view.contentScaleFactor;
	g_application->OnEvent(&event);
}

@end


@implementation WinLibAppDelegate

- (void)doStartup {
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
    LOG_INFO("applicationDidFinishLaunching");
    
    controller = [[WinLibViewController alloc] init];
    m_system = new SystemCocoaTouch(controller);
    g_application->SetSystem(m_system);
    
    m_vfs = new GHL::VFSCocoaImpl();
    g_application->SetVFS(m_vfs);
    
    GHL::Event e;
    e.type = GHL::EVENT_TYPE_APP_STARTED;
    g_application->OnEvent(&e);
    
    
    CGRect rect = [[UIScreen mainScreen] bounds];
    float scale = [[UIScreen mainScreen] scale];
    if ([UIScreen instancesRespondToSelector:@selector(nativeScale)]) {
        scale = [[UIScreen mainScreen] nativeScale];
    }
    
    GHL::Settings settings;
    settings.width = rect.size.width * scale;
    settings.height = rect.size.height * scale;
    settings.fullscreen = true;
    settings.depth = g_need_depth;
    settings.screen_dpi = 72.0 * scale;
    
    g_application->FillSettings(&settings);
    LOG_INFO("application require " << settings.width << "x" << settings.height);
    settings.fullscreen = true;
    
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
    
    
    
    
    
    window = [[UIWindow alloc] initWithFrame:rect];
    [window setAutoresizesSubviews:YES];
    
    
    view = [[WinLibView alloc] initWithFrame:CGRectMake(0, 0, settings.width, settings.height)];
    controller.view = view;
    view.multipleTouchEnabled = g_multitouchEnabled ? YES : NO;
    
    [window setRootViewController:controller];
    [window setOpaque:YES];
    
    
    [window makeKeyAndVisible];
    
    
    
    [pool drain];
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(nullable NSDictionary *)launchOptions {
    [self doStartup];
    
    return YES;
}

#if __IPHONE_OS_VERSION_MAX_ALLOWED > __IPHONE_9_3
- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey, id> *)options {
    if (g_application) {
        GHL::Event e;
        e.type = GHL::EVENT_TYPE_HANDLE_URL;
        e.data.handle_url.url = [[url absoluteString] UTF8String];
        g_application->OnEvent(&e);
    }
    
    return YES;
}
#endif

- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(nullable NSString *)sourceApplication annotation:(id)annotation  {
    if (g_application) {
        GHL::Event e;
        e.type = GHL::EVENT_TYPE_HANDLE_URL;
        e.data.handle_url.url = [[url absoluteString] UTF8String];
        g_application->OnEvent(&e);
    }
    
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

void GHL_CALL SystemCocoaTouch::ShowKeyboard(const GHL::TextInputConfig* input) {
    if (input && input->system_input) {
        [m_controller showTextInput:input];
    } else {
        [(WinLibView*)m_controller.view showKeyboard:input];
    }
}

void GHL_CALL SystemCocoaTouch::HideKeyboard() {
    [m_controller closeTextInput];
	[(WinLibView*)m_controller.view hideKeyboard];
}

bool GHL_CALL SystemCocoaTouch::SetDeviceState( GHL::DeviceState name, const void* data) {
	if (!data) return false;
	if (name==GHL::DEVICE_STATE_ACCELEROMETER_ENABLED) {
		const bool* state = static_cast<const bool*>(data);
		if (*state && !m_accelerometer) {
			m_accelerometer = [[AccelerometerDelegate alloc] init];
		} else if (!*state && m_accelerometer) {
			[m_accelerometer release];
			m_accelerometer = nil;
		}
		return true;
	} else if (name==GHL::DEVICE_STATE_ORIENTATION_LOCKED) {
		g_orientationLocked = *static_cast<const bool*>(data);
		return true;
	} else if (name==GHL::DEVICE_STATE_MULTITOUCH_ENABLED) {
		const bool* state = static_cast<const bool*>(data);
		m_controller.view.multipleTouchEnabled = *state ? YES : NO;
        g_multitouchEnabled = *state;
		return true;
	} else if (name==GHL::DEVICE_STATE_FRAME_INTERVAL) {
        const GHL::Int32* state = static_cast<const GHL::Int32*>(data);
        g_frame_interval = *state;
        if (m_controller.isViewLoaded) {
            [(WinLibView*)m_controller.view setFrameInterval:*state];
        }
        return true;
    } else if (name==GHL::DEVICE_STATE_KEEP_SCREEN_ON) {
        const bool* state = static_cast<const bool*>(data);
        UIApplication.sharedApplication.idleTimerDisabled = (*state) ? YES : NO;
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

static pthread_mutex_t ghl_system_mutex = PTHREAD_MUTEX_INITIALIZER;

GHL_API void GHL_CALL GHL_GlobalLock() {
    pthread_mutex_lock(&ghl_system_mutex);
}

GHL_API void GHL_CALL GHL_GlobalUnlock() {
    pthread_mutex_unlock(&ghl_system_mutex);
}


GHL_API int GHL_CALL GHL_StartApplication( GHL::Application* app , int argc, char** argv) {
    (void)MODULE;
    g_application = app;
	NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
    NSString* app_delegate_class = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"WinLibAppDelegateClass"];
    if (!app_delegate_class) {
        app_delegate_class =  @"WinLibAppDelegate";
    }
    
	UIApplicationMain(argc, argv, nil, app_delegate_class);
	[pool release];
	return 0;
}
