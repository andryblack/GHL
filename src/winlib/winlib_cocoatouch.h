#import <Foundation/Foundation.h>


@class WinLibView;
@class WinLibViewController;

class SystemCocoaTouch;

@interface WinLibAppDelegate : NSObject<UIApplicationDelegate> {
    UIWindow* window;
    WinLibView*	view;
    WinLibViewController* controller;
    GHL::VFSCocoaImpl*	m_vfs;
    SystemCocoaTouch*	m_system;
}

@end
