//
//  WinLibCocoaTouchContext.h
//  GHL
//
//  Created by Andrey Kunitsyn on 3/5/13.
//  Copyright (c) 2013 AndryBlack. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <OpenGLES/EAGL.h>
#import <QuartzCore/QuartzCore.h>

@interface WinLibCocoaTouchContext : NSObject {

    EAGLContext*	m_context;
    // The OpenGL ES names for the framebuffer and renderbuffer used to render to this view
    unsigned int m_defaultFramebuffer, m_colorRenderbuffer;
    // The pixel dimensions of the CAEAGLLayer
    int m_backingWidth;
    int m_backingHeight;

}

-(id)initWithContext:(EAGLContext*)context;
-(void)createBuffers;
-(void)onLayout:(CAEAGLLayer*)layer;
-(void)makeCurrent;
-(void)present;
-(void)deleteBuffers;

-(unsigned int)colorRenderbuffer;
-(int)backingWidth;
-(int)backingHeight;

@end
