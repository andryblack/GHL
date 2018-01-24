#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

namespace GHL {
    class VFSCocoaImpl;
}

@class WinLibView;
@interface WinLibViewController : UIViewController
@end

class SystemCocoaTouch;

@interface WinLibAppDelegate : NSObject<UIApplicationDelegate> {
    UIWindow* window;
    WinLibView*	view;
    WinLibViewController* controller;
    GHL::VFSCocoaImpl*	m_vfs;
    SystemCocoaTouch*	m_system;
}

- (WinLibViewController*) createController;

@end
