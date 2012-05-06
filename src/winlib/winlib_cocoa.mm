//
//  winlib_cocoa.m
//  SR
//
//  Created by Андрей Куницын on 03.02.11.
//  Copyright 2011 andryblack. All rights reserved.
//


#include "../render/render_impl.h"

#import "winlib_cocoa.h"

#import <Cocoa/Cocoa.h>

#include <ghl_application.h>
#include <ghl_settings.h>

#include <ghl_system.h>
#include <ghl_log.h>

#include "../vfs/vfs_cocoa.h"
#include "../image/image_decoders.h"
#include "../sound/iOS/sound_iphone.h"

#include "../ghl_log_impl.h"

static bool g_fullscreen = false;
static bool g_need_fullscreen = false;
static std::string g_title = "GHL";
static NSRect g_rect;

static const char* MODULE = "WINLIB";

class SystemCocoa : public GHL::System {
public:
	virtual void GHL_CALL Exit() {
		[[NSApplication sharedApplication] terminate:nil];
	}
    ///
    virtual bool GHL_CALL IsFullscreen() const {
        return g_fullscreen;
    }
    ///
    virtual void GHL_CALL SwitchFullscreen(bool fs);
    ///
    virtual void GHL_CALL SwapBuffers();
    ///
    virtual void GHL_CALL ShowKeyboard() {
        /// do nothing
    }
    ///
    virtual void GHL_CALL HideKeyboard() {
        /// do nothing
    }
    ///
    virtual GHL::UInt32  GHL_CALL GetKeyMods() const {
        /// @todo stub
        return 0;
    }
    ///
    virtual bool GHL_CALL SetDeviceState( GHL::DeviceState name, void* data);
    ///
    virtual bool GHL_CALL GetDeviceData( GHL::DeviceData name, void* data) {
        return false;
    }
    ///
    virtual void GHL_CALL SetTitle( const char* title );
};



@implementation WinLibWindow

- (BOOL)canBecomeKeyWindow
{
	return YES;
}

- (BOOL) acceptsFirstResponder
{
    // We want this view to be able to receive key events
    return YES;
}

- (BOOL)isMainWindow
{
	return YES;
}
- (void)closeWindow {
    LOG_INFO( "WinLibWindow::closeWindow" );
    [super close];
}
- (void)close {
    LOG_INFO( "WinLibWindow::close" );
	[super close];
	[[NSApplication sharedApplication] terminate:self];
}


@end





@implementation WinLibOpenGLView

- (id) initWithFrame:(NSRect)frameRect pixelFormat:(NSOpenGLPixelFormat *)format
{
	self = [super initWithFrame:frameRect pixelFormat:format];
	if (self) {
        m_render = 0;
        m_loaded = false;
        m_null_cursor = nil;
        m_cursor_visible = YES;
        LOG_INFO( "WinLibOpenGLView::initWithFrame ok" ); 
 	} else {
        LOG_ERROR("WinLibOpenGLView::initWithFrame failed");
    }
    return self;
}

-(void)setApplication:(WinLibAppDelegate*) app {
	m_application = app;
}

-(void)setCursorVisible:(BOOL) visible
{
    m_cursor_visible = visible;
    [self.window invalidateCursorRectsForView:self];
}

-(void)resetCursorRects
{
    if ( !m_null_cursor && !m_cursor_visible ) {
        NSImage* img = [[NSImage alloc] initWithSize:NSMakeSize(8, 8)];
        m_null_cursor = [[NSCursor alloc] initWithImage:img hotSpot:NSMakePoint(0, 0)];
        [img release];
    }
    [self addCursorRect:self.visibleRect cursor:(m_cursor_visible ? [NSCursor arrowCursor]:m_null_cursor)];
}


static GHL::Key translate_key(unichar c,unsigned short kk) {
	GHL::Key key = GHL::KEY_NONE;
	switch (c) {
		case NSDownArrowFunctionKey:
			key = GHL::KEY_DOWN;
			break;
		case NSUpArrowFunctionKey:
			key = GHL::KEY_UP;
			break;
		case NSLeftArrowFunctionKey:
			key = GHL::KEY_LEFT;
			break;
		case NSRightArrowFunctionKey:
			key = GHL::KEY_RIGHT;
			break;
		default:
			switch (kk) {
				case 0x12: key = GHL::KEY_1; break;
				case 0x13: key = GHL::KEY_2; break;
				case 0x14: key = GHL::KEY_3; break;
				case 0x15: key = GHL::KEY_4; break;
				case 0x17: key = GHL::KEY_5; break;
				case 0x16: key = GHL::KEY_6; break;
				case 0x1a: key = GHL::KEY_7; break;
				case 0x1c: key = GHL::KEY_8; break;
				case 0x19: key = GHL::KEY_9; break;
				case 0x1d: key = GHL::KEY_0; break;	
					
				case 0x1b: key = GHL::KEY_MINUS; break;		
				case 0x18: key = GHL::KEY_EQUALS; break;
				
				case 0x21: key = GHL::KEY_LBRACKET; break;
				case 0x1e: key = GHL::KEY_RBRACKET; break;
					
				case 0x29: key = GHL::KEY_SEMICOLON; break;	
				case 0x27: key = GHL::KEY_SEMICOLON; break;	
					
				case 0x32: key = GHL::KEY_APOSTROPHE; break;	
					
					
					
				case 0x00: key = GHL::KEY_A; break;	
				case 0x0b: key = GHL::KEY_B; break;		
				case 0x08: key = GHL::KEY_C; break;	
				case 0x02: key = GHL::KEY_D; break;	
				case 0x0e: key = GHL::KEY_E; break;	
				case 0x03: key = GHL::KEY_F; break;	
				case 0x05: key = GHL::KEY_G; break;	
				case 0x04: key = GHL::KEY_H; break;	
				case 0x22: key = GHL::KEY_I; break;	
				case 0x26: key = GHL::KEY_J; break;	
				case 0x28: key = GHL::KEY_K; break;	
				case 0x25: key = GHL::KEY_L; break;	
				case 0x2e: key = GHL::KEY_M; break;	
				case 0x2d: key = GHL::KEY_N; break;	
				case 0x1f: key = GHL::KEY_O; break;	
				case 0x23: key = GHL::KEY_P; break;	
				case 0x0c: key = GHL::KEY_Q; break;	
				case 0x0f: key = GHL::KEY_R; break;	
				case 0x01: key = GHL::KEY_S; break;	
				case 0x11: key = GHL::KEY_T; break;	
				case 0x20: key = GHL::KEY_U; break;	
				case 0x09: key = GHL::KEY_V; break;	
				case 0x0d: key = GHL::KEY_W; break;	
				case 0x07: key = GHL::KEY_X; break;
				case 0x10: key = GHL::KEY_Y; break;
				case 0x06: key = GHL::KEY_Z; break;
				
				case 0x30: key = GHL::KEY_TAB; break;	
				case 0x31: key = GHL::KEY_SPACE; break;
				case 0x24: key = GHL::KEY_ENTER; break;
				case 0x33: key = GHL::KEY_BACKSPACE; break;
				case 0x35: key = GHL::KEY_ESCAPE; break;
					
					
				default:
					break;
			};
			break;
	}
	return key;
}

- (void)keyDown:(NSEvent *)event {
	unichar c = [[event charactersIgnoringModifiers] characterAtIndex:0];
	unsigned short kk = [event keyCode];
	GHL::Key key = translate_key(c,kk);
	if (key==GHL::KEY_NONE) {
		[super keyDown:event];
	} else {
		[m_application getApplication]->OnKeyDown(key);
	}
    [m_application getApplication]->OnChar( [[event characters] characterAtIndex:0] );
    
   
}
- (void)keyUp:(NSEvent *)event {
	unichar c = [[event charactersIgnoringModifiers] characterAtIndex:0];
	unsigned short kk = [event keyCode];
	GHL::Key key = translate_key(c,kk);
	if (key==GHL::KEY_NONE) {
		[super keyDown:event];
	} else {
		[m_application getApplication]->OnKeyUp(key);
	}
}
- (NSPoint) scale_point:(NSPoint)point {
    NSPoint res = point;
    res.y = self.frame.size.height - res.y;
    return res;
}
- (void)mouseDown:(NSEvent *)theEvent {
    NSPoint event_location = [theEvent locationInWindow];
    NSPoint local_point = [self convertPoint:event_location fromView:nil];
    local_point = [self scale_point: local_point ];
    [m_application getApplication]->OnMouseDown(GHL::MOUSE_BUTTON_LEFT, local_point.x, local_point.y);
}
- (void)mouseUp:(NSEvent *)theEvent {
    NSPoint event_location = [theEvent locationInWindow];
    NSPoint local_point = [self convertPoint:event_location fromView:nil];
    local_point = [self scale_point: local_point ];
    [m_application getApplication]->OnMouseUp(GHL::MOUSE_BUTTON_LEFT, local_point.x, local_point.y);
}
- (void)mouseMoved:(NSEvent *)theEvent {
    NSPoint event_location = [theEvent locationInWindow];
    NSPoint local_point = [self convertPoint:event_location fromView:nil];
    local_point = [self scale_point: local_point ];
    //LOG_DEBUG("mouseMoved: " << local_point.x << "x" << local_point.y);
    [m_application getApplication]->OnMouseMove(GHL::MOUSE_BUTTON_NONE, local_point.x, local_point.y);
}
- (void)mouseDragged:(NSEvent *)theEvent {
    NSPoint event_location = [theEvent locationInWindow];
    NSPoint local_point = [self convertPoint:event_location fromView:nil];
    local_point = [self scale_point: local_point ];
    [m_application getApplication]->OnMouseMove(GHL::MOUSE_BUTTON_LEFT, local_point.x, local_point.y);
}

- (BOOL) acceptsFirstResponder
{
    // We want this view to be able to receive key events
    return YES;
}

- (BOOL)canBecomeKeyView {
	return YES;
}

- (void)prepareOpenGL {
	LOG_INFO( "WinLibOpenGLView::prepareOpenGL" ); 
   
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
	
	m_render = GHL_CreateRenderOpenGL(GHL::UInt32(self.bounds.size.width),
									 GHL::UInt32(self.bounds.size.height));
	if (m_render) {
        LOG_VERBOSE( "WinLibOpenGLView::prepareOpenGL render created" );
        [m_application getApplication]->SetRender(m_render);
        if ([m_application getApplication]->Load()) {
            LOG_VERBOSE( "WinLibOpenGLView::prepareOpenGL application loaded" );
            m_timer = [NSTimer scheduledTimerWithTimeInterval: 1.0f/200.0f target:self selector:@selector(timerFireMethod:) userInfo:nil repeats:YES];
            m_loaded = true;
        }
    
        
        GLint val = 1;
        [[NSOpenGLContext currentContext] setValues:&val forParameter: NSOpenGLCPSwapInterval];
        
    }
	::gettimeofday(&m_timeval,0);
	[pool drain];
	//[pool release];
}

- (void)reshape {
    if ( m_render ) {
        LOG_VERBOSE( "WinLibOpenGLView::reshape" );
        m_render->Resize( self.bounds.size.width, self.bounds.size.height );
    }
}

- (void)drawRect:(NSRect)dirtyRect {
    (void)dirtyRect;
    static bool in_draw = false;
    if (in_draw) return;
    if (g_need_fullscreen!=g_fullscreen)  {
        return;
    }
    if ( m_loaded  ) {
        in_draw = true;
        
		::timeval time;
		::gettimeofday(&time,0);
		GHL::UInt32 dt = static_cast<GHL::UInt32>((time.tv_sec - m_timeval.tv_sec)*1000000 + time.tv_usec - m_timeval.tv_usec);
		m_timeval = time;
		
		[[self openGLContext] makeCurrentContext];
		m_render->ResetRenderState();
		GHL::Application* app = [m_application getApplication];
		if (app->OnFrame(dt)) {
        }
        [[self openGLContext] flushBuffer];
        in_draw = false;
   }
}

- (void)renewGState
{
	/* Overload this function to ensure the NSOpenGLView doesn't
     flicker when you resize it.                               */
	NSWindow *window;
	[super renewGState];
	window = [self window];
    
	/* Only available in 10.4 and later, so check that it exists */
	if(window && [window respondsToSelector:@selector(disableScreenUpdatesUntilFlush)])
		[window disableScreenUpdatesUntilFlush];
}


- (void)swapBuffers {
    //[[self openGLContext] flushBuffer];
}

- (void)timerFireMethod:(NSTimer*)theTimer {
    (void)theTimer;
    
    if ( g_fullscreen != g_need_fullscreen ) {
        WinLibAppDelegate* delegate = (WinLibAppDelegate*)[NSApplication sharedApplication].delegate;
       if (delegate) {
            [delegate switchFullscreen];
        }
    }
    
    if ([self window] && [self.window isVisible]) {
        [self setNeedsDisplay:YES];
    }
}


-(void)dealloc {
    LOG_INFO( "WinLibOpenGLView::dealloc" );
	if (m_timer) {
		[m_timer release];
	}
	if (m_render) {
		GHL_DestroyRenderOpenGL( m_render );
		m_render = 0;
	}
    [m_null_cursor release];
	[super dealloc];
}

@end


@implementation WinLibAppDelegate


- (id)init {
    self = [super init];
    if (self) {
        // Initialization code here.
		m_system = new SystemCocoa();
        m_gl_view = nil;
		m_appName = (NSString*)[[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleName"];
		m_vfs = new GHL::VFSCocoaImpl();
		m_imageDecoder = new GHL::ImageDecoderImpl();
		m_sound = 0;
        LOG_INFO( "WinLibAppDelegate::init" );
    }
    return self;
}

-(void) initSound {
#ifndef GHL_NOSOUND
	m_sound = new GHL::SoundIPhone();
	if (!m_sound->SoundInit()) {
		delete m_sound;
		m_sound = 0;
	}
#endif
}

-(void) setApplication:(GHL::Application*) app {
	m_application = app;
}

-(GHL::Application*) getApplication {
	return m_application;
}
-(SystemCocoa*) getSystem {
	return m_system;
}

-(GHL::VFSCocoaImpl*) getVFS {
	return m_vfs;
}
-(GHL::ImageDecoderImpl*) getImageDecoder {
	return m_imageDecoder;
}
-(GHL::SoundIPhone*) getSound {
	return m_sound;
}
-(NSString*) getAppName {
	return m_appName;
}
-(void)swapBuffers {
    [m_gl_view swapBuffers];
}
-(void) setCursorVisible:(BOOL) visible
{
    [m_gl_view setCursorVisible:visible];
}
-(void)dealloc {
    LOG_INFO( "WinLibAppDelegate::dealloc" );
	if (m_application)
		m_application->Release();
	delete m_vfs;
	delete m_imageDecoder;
	delete m_system;
	if (m_sound) {
#ifndef GHL_NOSOUND
		m_sound->SoundDone();
		delete m_sound;
#endif
		m_sound = 0;
	}
	[super dealloc];
}

- (void)switchFullscreen {
    LOG_INFO( "WinLibAppDelegate::switchFullscreen" );
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
	
	if (m_application) {
        m_application->OnDeactivated();
    }
    
    NSInteger style = NSTitledWindowMask | NSClosableWindowMask | NSMiniaturizableWindowMask;
    
    NSScreen* screen = 0;
    
    NSInteger windowLevel = NSNormalWindowLevel;
    
    NSRect rect = m_rect;
    
    bool recreateWindow = false; 
    
    
    if (m_window) {
        screen = m_window.screen;
        if (g_need_fullscreen)
            m_rect.origin = [m_window frame].origin;
        
        if (![m_window respondsToSelector:@selector(setStyleMask:)]) {
            recreateWindow = true;
        }
        
        if (recreateWindow) {
            LOG_DEBUG( "WinLibAppDelegate::switchFullscreen recreateWindow" );
            [m_window setContentView:nil];
            [m_window setDelegate:nil];
            [m_window closeWindow];
            m_window = nil;
        }
    } else {
        screen = [NSScreen mainScreen];
    }
    
    if (g_need_fullscreen) {
        rect = [screen frame];
        style = NSBorderlessWindowMask ;
        windowLevel = NSMainMenuWindowLevel+1;
    } else {
        
    }
    if (!m_window) {
        LOG_DEBUG( "WinLibAppDelegate::switchFullscreen create new window" );
        m_window = [[WinLibWindow alloc] initWithContentRect:rect styleMask:style backing:NSBackingStoreBuffered defer:YES];
        [m_window disableFlushWindow];
        [m_window setContentView:m_gl_view];
        [m_window setDelegate:self];
    } else {
        [m_window disableFlushWindow];
        [m_window disableScreenUpdatesUntilFlush];
        [m_gl_view setHidden:YES];
        
        
        [m_window setStyleMask:style];
        
        if (g_need_fullscreen) {
            [m_window setFrame:rect display:YES];
        } else {
            [m_window setContentSize:rect.size];
            [m_window setFrameOrigin:m_rect.origin];
        }
    }
    
    [m_window setLevel:windowLevel];
    
    if (g_need_fullscreen) {
        [m_window setOpaque:YES];
        [m_window setHasShadow:NO];
        [m_window setHidesOnDeactivate:YES];
        [m_window setMovable:NO];
    } else {
        [m_window setHasShadow:YES];
        [m_window setOpaque:NO];
        [m_window setHidesOnDeactivate:NO];
        [m_window setMovable:YES];
    }
    
    [m_window setAcceptsMouseMovedEvents:YES];
    [m_window setTitle:[NSString stringWithUTF8String:g_title.c_str()] ];
    
    [m_gl_view reshape];
    
    g_fullscreen = g_need_fullscreen;
    
    [m_gl_view setHidden:NO];
    [m_window enableFlushWindow];
    [m_window makeKeyAndOrderFront:nil];
    [m_window makeKeyWindow];
    [m_window makeFirstResponder:m_gl_view];

    if (m_application) {
        m_application->OnActivated();
    }
    
    [pool release];
}

- (void)updateWindowTitle {
    if (m_window) {
        [ m_window setTitle:[NSString stringWithUTF8String:g_title.c_str()] ];
    }
}

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    LOG_INFO( "WinLibAppDelegate::applicationDidFinishLaunching" );
    (void)aNotification;
	NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
	// Insert code here to initialize your application 
	GHL::Settings settings;
	settings.width = 800;
	settings.height = 600;
	settings.fullscreen = g_fullscreen;
    settings.title = 0;
    
	m_application->FillSettings(&settings);
	if (settings.title)
        g_title = settings.title;
	
	[self initSound];
	m_application->SetSound([self getSound]);

	NSOpenGLPixelFormatAttribute attrs[] =
	{
		NSOpenGLPFADoubleBuffer,
		NSOpenGLPFAColorSize, 24,
		NSOpenGLPFAAlphaSize, 8,
		NSOpenGLPFAStencilSize, 8,
		NSOpenGLPFADepthSize, 24,
        0
	};
	
	NSScreen* screen = [NSScreen mainScreen];
	NSRect rect = NSMakeRect((screen.frame.size.width-settings.width)/2 ,
                             (screen.frame.size.height-settings.height)/2,
                             settings.width,settings.height);
	m_rect = rect;
    g_rect = rect;
    
	NSOpenGLPixelFormat* pf = [[NSOpenGLPixelFormat alloc] initWithAttributes:attrs];
    if (!pf) {
        LOG_ERROR("Create pixel format failed");
        return;
    }
	WinLibOpenGLView* gl = [[WinLibOpenGLView alloc] initWithFrame:rect pixelFormat:pf];
    if (!gl) {
        LOG_ERROR("creating WinLibOpenGLView failed");
        return;
    }
    [gl retain];
	[gl setApplication:self];
	
    
    g_fullscreen = g_need_fullscreen = settings.fullscreen;
    
    m_gl_view = gl;
	
    [self switchFullscreen];
    
    [m_window makeKeyAndOrderFront:nil];
	
	[pool release];
}
- (void)applicationWillTerminate:(NSNotification *)aNotification {
    LOG_INFO( "WinLibAppDelegate::applicationWillTerminate" );
    (void)aNotification;
	if (m_application)
		m_application->Release();
	m_application = 0;
	delete m_vfs;
	m_vfs = 0;
	delete m_imageDecoder;
	m_imageDecoder = 0;
	if (m_sound) {
#ifndef GHL_NOSOUND
		m_sound->SoundDone();
		delete m_sound;
#endif
		m_sound = 0;
	}
	if (m_window)
		[m_window release];
	
}

/// ---- NSWindowDelegate
- (void)windowDidBecomeKey:(NSNotification *)notification {
    if (g_fullscreen) {
        //[m_window setIsVisible:YES];
        [m_window setLevel: NSMainMenuWindowLevel+1];
    } else {
        
    }
	LOG_VERBOSE("Activated");
    if (m_application) {
        m_application->OnActivated();
    }
}

- (void)windowDidResignKey:(NSNotification *)notification {
    if (g_fullscreen) {
        //[m_window setIsVisible:NO];
        [m_window setLevel:NSNormalWindowLevel];
    }
	LOG_VERBOSE("Deactivated");
    if (m_application) {
        m_application->OnDeactivated();
    }
}

@end


void GHL_CALL SystemCocoa::SwitchFullscreen(bool fs) {
    g_need_fullscreen = fs;
}
void GHL_CALL SystemCocoa::SwapBuffers() {
    WinLibAppDelegate* delegate = (WinLibAppDelegate*)[NSApplication sharedApplication].delegate;
    if (delegate) {
        [delegate swapBuffers];
    }
}

///
void GHL_CALL SystemCocoa::SetTitle( const char* title ) {
    g_title = title;
    WinLibAppDelegate* delegate = (WinLibAppDelegate*)[NSApplication sharedApplication].delegate;
    if (delegate) {
        [delegate updateWindowTitle];
    }
}

bool GHL_CALL SystemCocoa::SetDeviceState(GHL::DeviceState name, void *data) {
    WinLibAppDelegate* delegate = (WinLibAppDelegate*)[NSApplication sharedApplication].delegate;
  
    if ( name == GHL::DEVICE_STATE_SYSTEM_CURSOR_ENABLED && data ) {
        BOOL enabled = *(bool*)data;
        if (delegate) {
            [delegate setCursorVisible:enabled];
        }
      return true;
    }
    return false;
}

GHL_API int GHL_CALL GHL_StartApplication( GHL::Application* app , int /*argc*/, char** /*argv*/) {
    
    LOG_INFO( "GHL_StartApplication" );
    
	NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
	[NSApplication sharedApplication];
	WinLibAppDelegate* delegate = [[WinLibAppDelegate alloc] init];
	[delegate setApplication:app];
	app->SetSystem([delegate getSystem]);
	app->SetVFS([delegate getVFS]);
	app->SetImageDecoder([delegate getImageDecoder]);
	
	/// create menu
    
	NSMenu * mainMenu = [[[NSMenu alloc] initWithTitle:@"MainMenu"] autorelease];
	
    
    if ([[NSBundle mainBundle] loadNibFile:@"MainMenu" externalNameTable:nil withZone:nil])
    {
        LOG_INFO( "GHL_StartApplication: loaded MainMenu from bundle" );
    } else {
    
        LOG_INFO( "GHL_StartApplication: create menu" );
        
        // The titles of the menu items are for identification purposes only
        //and shouldn't be localized.
        // The strings in the menu bar come from the submenu titles,
        // except for the application menu, whose title is ignored at runtime.
        NSMenuItem *item = [mainMenu addItemWithTitle:@"Apple" action:NULL keyEquivalent:@""];
        NSMenu *submenu = [[[NSMenu alloc] initWithTitle:@"Apple"] autorelease];
        //[NSApp performSelector:@selector(setAppleMenu:) withObject:submenu];
        
        NSMenuItem * appItem = [submenu addItemWithTitle:[NSString stringWithFormat:@"%@ %@",
                                                                     NSLocalizedString(@"Quit", nil), [delegate getAppName]]
                                                             action:@selector(terminate:)
                                                      keyEquivalent:@"q"];
        [appItem setTarget:NSApp];

                                      
        [mainMenu setSubmenu:submenu forItem:item];
        
           
        [NSApp setMainMenu:mainMenu];
        //[NSApp setServicesMenu:[[[NSMenu alloc] initWithTitle:@"Services"] autorelease]];
	}
    
	[NSApp setDelegate:delegate];
	
	[pool release];
	[NSApp run];
	
	return 0;
}

GHL_API void GHL_CALL GHL_Log( GHL::LogLevel level,const char* message) {
   	NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
    NSLog( @"%@",[NSString stringWithUTF8String:message] );
    [pool release];
}