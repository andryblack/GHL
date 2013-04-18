//
//  WinLibCocoaTouchContext2.m
//  GHL
//
//  Created by Andrey Kunitsyn on 3/5/13.
//  Copyright (c) 2013 AndryBlack. All rights reserved.
//

#import "WinLibCocoaTouchContext2.h"
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

@implementation WinLibCocoaTouchContext2

-(id)initWithContext:(EAGLContext*)context {
    if (self=[super initWithContext:context]) {
        
    }
    return self;
}

-(void)createBuffers
{
    // Create default framebuffer object. The backing will be allocated for the current layer in -resizeFromLayer
    glGenFramebuffers(1, &m_defaultFramebuffer);
    glGenRenderbuffers(1, &m_colorRenderbuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, m_defaultFramebuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, m_colorRenderbuffer);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, m_colorRenderbuffer);
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
}

-(void)onLayout:(CAEAGLLayer*)layer
{
    [EAGLContext setCurrentContext:m_context];
	// Allocate color buffer backing based on the current layer size
    glBindRenderbuffer(GL_RENDERBUFFER, m_colorRenderbuffer);
    [m_context renderbufferStorage:GL_RENDERBUFFER fromDrawable:layer];
    glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_WIDTH, &m_backingWidth);
    glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_HEIGHT, &m_backingHeight);
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
    if (m_colorRenderbuffer) {
        glBindRenderbuffer(GL_RENDERBUFFER, m_colorRenderbuffer);
    }
}

-(void)present
{
    [m_context presentRenderbuffer:GL_RENDERBUFFER];
}



@end
