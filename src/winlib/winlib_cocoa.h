//
//  winlib_cocoa.h
//  SR
//
//  Created by Андрей Куницын on 03.02.11.
//  Copyright 2011 andryblack. All rights reserved.
//

#include <ghl_application.h>
#import <Cocoa/Cocoa.h>

#include <sys/time.h>

namespace GHL {
	class VFSCocoaImpl;
	class ImageDecoderImpl;
	class SoundOpenAL;
	class RenderImpl;
}

class SystemCocoa;
@class WinLibOpenGLView;
@class WinLibWindow;

@interface WinLibAppDelegate : NSObject <NSApplicationDelegate,NSWindowDelegate> {
	GHL::Application* m_application;
	SystemCocoa*	m_system;
	GHL::VFSCocoaImpl*	m_vfs;
	GHL::ImageDecoderImpl* m_imageDecoder;
	GHL::SoundOpenAL*	m_sound;
	WinLibWindow*	m_window;
	NSString*	m_appName;
    WinLibOpenGLView*   m_gl_view;
    NSRect      m_rect;
}
-(void) setApplication:(GHL::Application*) app;
-(GHL::Application*) getApplication;
-(GHL::VFSCocoaImpl*) getVFS;
-(GHL::ImageDecoderImpl*) getImageDecoder;
-(GHL::SoundOpenAL*) getSound;
-(NSString*) getAppName;
-(SystemCocoa*) getSystem;
-(void) initSound;
-(void) switchFullscreen;
-(void) setCursorVisible:(BOOL) visible;
@end

@interface WinLibWindow : NSWindow
{
	
}
@end



@interface WinLibOpenGLView : NSOpenGLView 
{
	WinLibAppDelegate* m_application;
	GHL::RenderImpl* m_render;
	NSTimer*	m_timer;
	bool	m_loaded;
	::timeval	m_timeval;
    NSCursor*   m_null_cursor;
    BOOL        m_cursor_visible;
}
-(void)setApplication:(WinLibAppDelegate*) app;
-(void)setCursorVisible:(BOOL) visible;
@end


