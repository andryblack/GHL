//
//  WinLibCocoaTouchContext.m
//  GHL
//
//  Created by Andrey Kunitsyn on 3/5/13.
//  Copyright (c) 2013 AndryBlack. All rights reserved.
//

#import "WinLibCocoaTouchContext.h"
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>


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
    glGenFramebuffers(1, &m_defaultFramebuffer);
    glGenRenderbuffers(1, &m_colorRenderbuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, m_defaultFramebuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, m_colorRenderbuffer);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, m_colorRenderbuffer);
    
    if (depth) {
        glGenRenderbuffers(1, &m_depthRenderbuffer);
        glBindRenderbuffer(GL_RENDERBUFFER, m_depthRenderbuffer);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, m_depthRenderbuffer);
    }
}

-(void)deleteBuffers
{
    // Tear down GL
    if (m_defaultFramebuffer)
    {
        glDeleteFramebuffers(1, &m_defaultFramebuffer);
        m_defaultFramebuffer = 0;
    }
    
    if (m_colorRenderbuffer)
    {
        glDeleteRenderbuffers(1, &m_colorRenderbuffer);
        m_colorRenderbuffer = 0;
    }
    
    if (m_depthRenderbuffer)
    {
        glDeleteRenderbuffers(1, &m_depthRenderbuffer);
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
    glBindFramebuffer(GL_FRAMEBUFFER, m_defaultFramebuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, m_colorRenderbuffer);
    [m_context renderbufferStorage:GL_RENDERBUFFER fromDrawable:layer];
    glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_WIDTH, &m_backingWidth);
    glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_HEIGHT, &m_backingHeight);
    if (m_depthRenderbuffer) {
        glBindRenderbuffer(GL_RENDERBUFFER, m_depthRenderbuffer);
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, m_backingWidth, m_backingHeight);
    }
    
    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
    {
        NSLog(@"Failed to make complete framebuffer object %d" , glCheckFramebufferStatus(GL_FRAMEBUFFER));
    }

}

-(void)makeCurrent
{
    [EAGLContext setCurrentContext:m_context];
    if (m_defaultFramebuffer) {
        glBindFramebuffer(GL_FRAMEBUFFER, m_defaultFramebuffer);
    }
}

-(void)present
{
    if (m_defaultFramebuffer) {
        glBindFramebuffer(GL_FRAMEBUFFER, m_defaultFramebuffer);
    }
    if (m_colorRenderbuffer) {
        glBindRenderbuffer(GL_RENDERBUFFER, m_colorRenderbuffer);
    }
    [m_context presentRenderbuffer:GL_RENDERBUFFER];
}

-(bool)haveDepth
{
    return m_depthRenderbuffer!=0;
}

@end
