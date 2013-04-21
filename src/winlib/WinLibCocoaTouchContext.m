//
//  WinLibCocoaTouchContext.m
//  GHL
//
//  Created by Andrey Kunitsyn on 3/5/13.
//  Copyright (c) 2013 AndryBlack. All rights reserved.
//

#import "WinLibCocoaTouchContext.h"
#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>


@implementation WinLibCocoaTouchContext

-(id)initWithContext:(EAGLContext*)context
{
    if (self = [super init]) {
        m_context = context;
        m_colorRenderbuffer = 0;
        m_defaultFramebuffer = 0;
        m_depthRenderbuffer = 0;
    }
    return self;
}

-(void)dealloc
{
	
    // Tear down context
    if ([EAGLContext currentContext] == m_context)
        [EAGLContext setCurrentContext:nil];
    
    [m_context release];
    [super dealloc];
}

-(void)createBuffers:(bool) depth;
{
    // Create default framebuffer object. The backing will be allocated for the current layer in -resizeFromLayer
    glGenFramebuffersOES(1, &m_defaultFramebuffer);
    glGenRenderbuffersOES(1, &m_colorRenderbuffer);
    glBindFramebufferOES(GL_FRAMEBUFFER_OES, m_defaultFramebuffer);
    glBindRenderbufferOES(GL_RENDERBUFFER_OES, m_colorRenderbuffer);
    glFramebufferRenderbufferOES(GL_FRAMEBUFFER_OES, GL_COLOR_ATTACHMENT0_OES, GL_RENDERBUFFER_OES, m_colorRenderbuffer);
    if (depth) {
        glGenRenderbuffersOES(1, &m_depthRenderbuffer);
        glBindRenderbufferOES(GL_RENDERBUFFER_OES, m_depthRenderbuffer);
        glFramebufferRenderbufferOES(GL_FRAMEBUFFER_OES, GL_DEPTH_ATTACHMENT_OES, GL_RENDERBUFFER_OES, m_depthRenderbuffer);
    }
}

-(void)deleteBuffers
{
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
    
    if (m_depthRenderbuffer)
    {
        glDeleteRenderbuffersOES(1, &m_depthRenderbuffer);
        m_depthRenderbuffer = 0;
    }
}

-(unsigned int)defaultFramebuffer
{
    return m_defaultFramebuffer;
}

-(int)backingWidth
{
    return m_backingWidth;
}

-(int)backingHeight
{
    return m_backingHeight;
}

-(void)onLayout:(CAEAGLLayer*)layer
{
    [EAGLContext setCurrentContext:m_context];
	// Allocate color buffer backing based on the current layer size
    glBindRenderbufferOES(GL_RENDERBUFFER_OES, m_colorRenderbuffer);
    [m_context renderbufferStorage:GL_RENDERBUFFER_OES fromDrawable:layer];
    glGetRenderbufferParameterivOES(GL_RENDERBUFFER_OES, GL_RENDERBUFFER_WIDTH_OES, &m_backingWidth);
    glGetRenderbufferParameterivOES(GL_RENDERBUFFER_OES, GL_RENDERBUFFER_HEIGHT_OES, &m_backingHeight);
    if (m_depthRenderbuffer) {
        glBindRenderbufferOES(GL_RENDERBUFFER_OES, m_depthRenderbuffer);
        glRenderbufferStorageOES(GL_RENDERBUFFER_OES, GL_DEPTH_COMPONENT16_OES, m_backingWidth, m_backingHeight);
    }
    
	if (glCheckFramebufferStatusOES(GL_FRAMEBUFFER_OES) != GL_FRAMEBUFFER_COMPLETE_OES)
    {
        NSLog(@"Failed to make complete framebuffer object %d" , glCheckFramebufferStatusOES(GL_FRAMEBUFFER_OES));
    }
}

-(void)makeCurrent
{
    [EAGLContext setCurrentContext:m_context];
    if (m_defaultFramebuffer) {
        glBindFramebufferOES(GL_FRAMEBUFFER_OES, m_defaultFramebuffer);
    }
    if (m_colorRenderbuffer) {
        glBindRenderbufferOES(GL_RENDERBUFFER_OES, m_colorRenderbuffer);
    }
    if (m_depthRenderbuffer) {
        glBindRenderbufferOES(GL_RENDERBUFFER_OES, m_depthRenderbuffer);
    }
}

-(void)present
{
    if (m_defaultFramebuffer) {
        glBindFramebufferOES(GL_FRAMEBUFFER_OES, m_defaultFramebuffer);
    }
    [m_context presentRenderbuffer:GL_RENDERBUFFER_OES];
}

-(bool)haveDepth
{
    return m_depthRenderbuffer!=0;
}

@end
