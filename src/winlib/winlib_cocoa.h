//
//  winlib_cocoa.h
//  SR
//
//  Created by Андрей Куницын on 03.02.11.
//  Copyright 2011 andryblack. All rights reserved.
//

#include "winlib_application.h"
#import <Cocoa/Cocoa.h>

#include <sys/time.h>

namespace GHL {
	class VFSCocoaImpl;
	class ImageDecoderImpl;
	class SoundOpenAL;
	class RenderOpenGL;
}

class SystemCocoa;

@interface WinLibAppDelegate : NSObject <NSApplicationDelegate> {
	WinLib::Application* m_application;
	SystemCocoa*	m_system;
	GHL::VFSCocoaImpl*	m_vfs;
	GHL::ImageDecoderImpl* m_imageDecoder;
	GHL::SoundOpenAL*	m_sound;
	NSWindow*	m_window;
	NSString*	m_appName;
}
-(void) setApplication:(WinLib::Application*) app;
-(WinLib::Application*) getApplication;
-(GHL::VFSCocoaImpl*) getVFS;
-(GHL::ImageDecoderImpl*) getImageDecoder;
-(GHL::SoundOpenAL*) getSound;
-(NSString*) getAppName;
-(SystemCocoa*) getSystem;
-(void) initSound;

@end

@interface WinLibWindow : NSWindow
{
	
}
@end

@interface WinLibFSView : NSView
{
	
}
@end

@interface WinLibOpenGLView : NSOpenGLView 
{
	WinLibAppDelegate* m_application;
	GHL::RenderOpenGL* m_render;
	NSTimer*	m_timer;
	bool	m_loaded;
	::timeval	m_timeval;
}
-(void)setApplication:(WinLibAppDelegate*) app;

@end
