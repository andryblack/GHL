#include "ghl_application.h"
#include "ghl_settings.h"
#include "ghl_vfs.h"
#include "../render/render_impl.h"
#include "ghl_system.h"


#include <GL/glx.h>
#ifdef HAVE_XF86VMODE
#include <X11/extensions/xf86vmode.h>
#endif
#include <X11/keysym.h>

#include <sys/time.h>

#include <iostream>

/* stuff about our window grouped together */
typedef struct {
    Display *dpy;
    int screen;
    Window win;
    GLXContext ctx;
    XSetWindowAttributes attr;
    Bool fs;
#ifdef HAVE_XF86VMODE
    XF86VidModeModeInfo deskMode;
#endif
    int x, y;
    unsigned int width, height;
    unsigned int depth;    
    GHL::RenderImpl*	render;
    GHL::Application*	application;
    timeval	lastTime;
} GLWindow;


/* attributes for a double buffered visual in RGBA format with at least
 * 8 bits per color and a 24 bit depth buffer */
static int attrListDbl[] = { GLX_RGBA, GLX_DOUBLEBUFFER, 
    GLX_RED_SIZE, 8, 
    GLX_GREEN_SIZE, 8, 
    GLX_BLUE_SIZE, 8, 
    GLX_DEPTH_SIZE, 24,
    None };

GLWindow GLWin;


class SystemImpl : public GHL::System  {
    private:
	bool	m_done;
    public:
	SystemImpl() {
	    m_done = false;
	}
	///
	virtual void GHL_CALL Exit() {
	    m_done = true;
	}
	///
	virtual void GHL_CALL SwapBuffers() {
	    glXSwapBuffers(GLWin.dpy, GLWin.win);
	}
	///
	virtual void GHL_CALL ShowKeyboard() {
	}
	///
	virtual void GHL_CALL HideKeyboard() {
	}
	
	bool IsDone() const { return m_done;}
};


/* function called when our window is resized (should only happen in window mode) */
void resizeGLScene(unsigned int width, unsigned int height)
{
    if (height == 0)    /* Prevent A Divide By Zero If The Window Is Too Small */
        height = 1;
    GLWin.render->Resize( width, height );
}

/* general OpenGL initialization function */
int initGL(GLvoid)
{
    GLWin.render = GHL_CreateRenderOpenGL( GLWin.width, GLWin.height );

    if (GLWin.render) {
	
    } else {
	return False;
    }
    return True;
}

/* Here goes our drawing code */
int drawGLScene(GLvoid)
{
    timeval nowTime;
    gettimeofday(&nowTime,0);
    GHL::UInt32 frameTime = (nowTime.tv_sec-GLWin.lastTime.tv_sec)*1000 + (nowTime.tv_usec-GLWin.lastTime.tv_usec)/1000;
    GLWin.lastTime = nowTime;
    GLWin.render->ResetRenderState();
    if (GLWin.application->OnFrame( frameTime )) {
	glXSwapBuffers(GLWin.dpy, GLWin.win);
    }
    return True;    
}



static void X11_SetSizeHints( )
{
	XSizeHints *hints;

	hints = XAllocSizeHints();
	if ( hints ) {
		{
			hints->min_width = hints->max_width = GLWin.width;
			hints->min_height = hints->max_height = GLWin.height;
			hints->flags = PMaxSize | PMinSize;
		}
		if ( GLWin.fs ) {
			hints->x = 0;
			hints->y = 0;
			hints->flags |= USPosition;
		} else {
		    /* Center it, if desired */
		    /*if ( X11_WindowPosition( GLWin.wi, &hints->x, &hints->y, w, h) ) {
			hints->flags |= USPosition;
			XMoveWindow(SDL_Display, WMwindow, hints->x, hints->y);

			//Flush the resize event so we don't catch it later 
			XSync(SDL_Display, True);
		    }*/
		}
		XSetWMNormalHints(GLWin.dpy,GLWin.win, hints);
		XFree(hints);
	}

	/* Respect the window caption style */
	if ( GLWin.fs ) {
		bool set;
		Atom WM_HINTS;

		set = false;

		/* First try to set MWM hints */
		WM_HINTS = XInternAtom(GLWin.dpy, "_MOTIF_WM_HINTS", True);
		if ( WM_HINTS != None ) {
			/* Hints used by Motif compliant window managers */
			struct {
				unsigned long flags;
				unsigned long functions;
				unsigned long decorations;
				long input_mode;
				unsigned long status;
			} MWMHints = { (1L << 1), 0, 0, 0, 0 };

			XChangeProperty(GLWin.dpy, GLWin.win,
			                WM_HINTS, WM_HINTS, 32,
			                PropModeReplace,
					(unsigned char *)&MWMHints,
					sizeof(MWMHints)/sizeof(long));
			set = True;
		}
		/* Now try to set KWM hints */
		WM_HINTS = XInternAtom(GLWin.dpy, "KWM_WIN_DECORATION", True);
		if ( WM_HINTS != None ) {
			long KWMHints = 0;

			XChangeProperty(GLWin.dpy, GLWin.win,
			                WM_HINTS, WM_HINTS, 32,
			                PropModeReplace,
					(unsigned char *)&KWMHints,
					sizeof(KWMHints)/sizeof(long));
			set = True;
		}
		/* Now try to set GNOME hints */
		WM_HINTS = XInternAtom(GLWin.dpy, "_WIN_HINTS", True);
		if ( WM_HINTS != None ) {
			long GNOMEHints = 0;

			XChangeProperty(GLWin.dpy, GLWin.win,
			                WM_HINTS, WM_HINTS, 32,
			                PropModeReplace,
					(unsigned char *)&GNOMEHints,
					sizeof(GNOMEHints)/sizeof(long));
			set = True;
		}
		/* Finally set the transient hints if necessary */
		if (!set) {
		    XSetTransientForHint(GLWin.dpy,GLWin.win,None);
		}
	} else {
		bool set;
		Atom WM_HINTS;

		/* We haven't modified the window manager hints yet */
		set = False;

		/* First try to unset MWM hints */
		WM_HINTS = XInternAtom(GLWin.dpy, "_MOTIF_WM_HINTS", True);
		if ( WM_HINTS != None ) {
			XDeleteProperty(GLWin.dpy, GLWin.win, WM_HINTS);
			set = True;
		}
		/* Now try to unset KWM hints */
		WM_HINTS = XInternAtom(GLWin.dpy, "KWM_WIN_DECORATION", True);
		if ( WM_HINTS != None ) {
			XDeleteProperty(GLWin.dpy, GLWin.win, WM_HINTS);
			set = True;
		}
		/* Now try to unset GNOME hints */
		WM_HINTS = XInternAtom(GLWin.dpy, "_WIN_HINTS", True);
		if ( WM_HINTS != None ) {
			XDeleteProperty(GLWin.dpy, GLWin.win, WM_HINTS);
			set = True;
		}
		/* Finally unset the transient hints if necessary */
		if ( ! set ) {
			/* NOTE: Does this work? */
			XSetTransientForHint(GLWin.dpy, GLWin.win, None);
		}
	}
}


/* function to release/destroy our resources and restoring the old desktop */
GLvoid killGLWindow(GLvoid)
{
    if (GLWin.ctx)
    {
	if (GLWin.render) {
	    GHL_DestroyRenderOpenGL(GLWin.render);
	    GLWin.render = 0;
	}
        if (!glXMakeCurrent(GLWin.dpy, None, NULL))
        {
            std::cout << "Could not release drawing context." << std::endl;
        }
        glXDestroyContext(GLWin.dpy, GLWin.ctx);
        GLWin.ctx = NULL;
    }
    /* switch back to original desktop resolution if we were in fs */
    if (GLWin.fs)
    {
#ifdef HAVE_XF86VMODE    
        XF86VidModeSwitchToMode(GLWin.dpy, GLWin.screen, &GLWin.deskMode);
        XF86VidModeSetViewPort(GLWin.dpy, GLWin.screen, 0, 0);
#endif
    }
    XCloseDisplay(GLWin.dpy);
}

/* this function creates our window and sets it up properly */
Bool createGLWindow(char* title, int width, int height, 
                    Bool fullscreenflag)
{
    XVisualInfo *vi;
    Colormap cmap;
    int dpyWidth, dpyHeight;
    int i;
    int glxMajorVersion, glxMinorVersion;
#ifdef HAVE_XF86VMODE    
    int vidModeMajorVersion, vidModeMinorVersion;
    XF86VidModeModeInfo **modes;
    int modeNum = 0;
    int bestMode = 0;
#endif
    Atom wmDelete;
    Window winDummy;
    unsigned int borderDummy;
    
    GLWin.fs = fullscreenflag;
    /* set best mode to current */
    /* get a connection */
    GLWin.dpy = XOpenDisplay(0);
    GLWin.screen = DefaultScreen(GLWin.dpy);
#ifdef HAVE_XF86VMODE    
    XF86VidModeQueryVersion(GLWin.dpy, &vidModeMajorVersion,
        &vidModeMinorVersion);
    std::cout << "XF86VidModeExtension-Version " << vidModeMajorVersion << "." << vidModeMinorVersion << std::endl;
    XF86VidModeGetAllModeLines(GLWin.dpy, GLWin.screen, &modeNum, &modes);
    /* save desktop-resolution before switching modes */
    GLWin.deskMode = *modes[0];
    /* look for mode with requested resolution */
    for (i = 0; i < modeNum; i++)
    {
        if ((modes[i]->hdisplay == width) && (modes[i]->vdisplay == height))
        {
            bestMode = i;
        }
    }
#endif    
    /* get an appropriate visual */
    vi = glXChooseVisual(GLWin.dpy, GLWin.screen, attrListDbl);
    if (!vi) {
	std::cout << "Error glXChooseVisual" << std::endl;
	return 1;
    }
    glXQueryVersion(GLWin.dpy, &glxMajorVersion, &glxMinorVersion);
    std::cout << "glX-Version " << glxMajorVersion << "." << glxMinorVersion << std::endl;
    /* create a GLX context */
    GLWin.ctx = glXCreateContext(GLWin.dpy, vi, 0, GL_TRUE);
    /* create a color map */
    cmap = XCreateColormap(GLWin.dpy, RootWindow(GLWin.dpy, vi->screen),
        vi->visual, AllocNone);
    GLWin.attr.colormap = cmap;
    GLWin.attr.border_pixel = 0;

    if (GLWin.fs)
    {
#ifdef HAVE_XF86VMODE    
        XF86VidModeSwitchToMode(GLWin.dpy, GLWin.screen, modes[bestMode]);
        XF86VidModeSetViewPort(GLWin.dpy, GLWin.screen, 0, 0);
        dpyWidth = modes[bestMode]->hdisplay;
        dpyHeight = modes[bestMode]->vdisplay;
        std::cout << "Resolution " << dpyWidth << "x" << dpyHeight << std::endl;
#endif    
        /* create a fullscreen window */
        GLWin.attr.override_redirect = True;
        GLWin.attr.event_mask = ExposureMask | KeyPressMask | ButtonPressMask |
            StructureNotifyMask;
        GLWin.win = XCreateWindow(GLWin.dpy, RootWindow(GLWin.dpy, vi->screen),
            0, 0, dpyWidth, dpyHeight, 0, vi->depth, InputOutput, vi->visual,
            CWBorderPixel | CWColormap | CWEventMask | CWOverrideRedirect,
            &GLWin.attr);
        XWarpPointer(GLWin.dpy, None, GLWin.win, 0, 0, 0, 0, 0, 0);
		XMapRaised(GLWin.dpy, GLWin.win);
        XGrabKeyboard(GLWin.dpy, GLWin.win, True, GrabModeAsync,
            GrabModeAsync, CurrentTime);
        XGrabPointer(GLWin.dpy, GLWin.win, True, ButtonPressMask,
            GrabModeAsync, GrabModeAsync, GLWin.win, None, CurrentTime);
    }
    else
    {
        /* create a window in window mode*/
        GLWin.attr.event_mask = ExposureMask | KeyPressMask | ButtonPressMask |
            StructureNotifyMask;
        GLWin.win = XCreateWindow(GLWin.dpy, RootWindow(GLWin.dpy, vi->screen),
            0, 0, width, height, 0, vi->depth, InputOutput, vi->visual,
            CWBorderPixel | CWColormap | CWEventMask, &GLWin.attr);
        /* only set window title and handle wm_delete_events if in windowed mode */
        wmDelete = XInternAtom(GLWin.dpy, "WM_DELETE_WINDOW", True);
        XSetWMProtocols(GLWin.dpy, GLWin.win, &wmDelete, 1);
        XSetStandardProperties(GLWin.dpy, GLWin.win, title,
            title, None, NULL, 0, NULL);
        XMapRaised(GLWin.dpy, GLWin.win);
    }       
    
    X11_SetSizeHints();

    
#ifdef HAVE_XF86VMODE    
    XFree(modes);
#endif
    
    /* connect the glx-context to the window */
    glXMakeCurrent(GLWin.dpy, GLWin.win, GLWin.ctx);
    XGetGeometry(GLWin.dpy, GLWin.win, &winDummy, &GLWin.x, &GLWin.y,
        &GLWin.width, &GLWin.height, &borderDummy, &GLWin.depth);
    std::cout << "Depth " << GLWin.depth << std::endl;
    if (glXIsDirect(GLWin.dpy, GLWin.ctx)) 
        std::cout << "Congrats, you have Direct Rendering!" << std::endl;
    else
        std::cout << "Sorry, no Direct Rendering possible!" << std::endl;
    initGL();
    return True;    
}




GHL_API int GHL_CALL GHL_StartApplication( GHL::Application* app , int argc, char** argv) {
    GHL::Settings settings;
    /// default settings
    settings.width = 800;
    settings.height = 600;
    settings.fullscreen = false;
    
    
    GHL::VFS* vfs = GHL_CreateVFS();
    app->SetVFS(vfs);
    
    app->FillSettings(&settings);

    GLWin.application = app;
    GLWin.width = settings.width;
    GLWin.height = settings.height;


    XEvent event;
    Bool done;
    
    done = False;

    GLWin.fs = settings.fullscreen ? True : False;
    
    if (createGLWindow("HGL Window", settings.width, settings.height,  GLWin.fs)) {
	app->SetRender(GLWin.render);
    } else {
	std::cout << "Error initialize window" << std::endl;
	return 1;
    }
    
    SystemImpl	sys;
    app->SetSystem(&sys);
    
    gettimeofday(&GLWin.lastTime,0);

    /* wait for events*/ 
    while (!done && !sys.IsDone())
    {
        /* handle the events in the queue */
        while (XPending(GLWin.dpy) > 0)
        {
            XNextEvent(GLWin.dpy, &event);
            switch (event.type)
            {
            case Expose:
	                if (event.xexpose.count != 0)
	                    break;
                	drawGLScene();
         	        break;
            case ConfigureNotify:
            /* call resizeGLScene only if our window-size changed */
                if ((event.xconfigure.width != GLWin.width) || 
                    (event.xconfigure.height != GLWin.height))
                {
                    GLWin.width = event.xconfigure.width;
                    GLWin.height = event.xconfigure.height;
                    resizeGLScene(event.xconfigure.width,
                        event.xconfigure.height);
                }
                break;
            case ButtonPress:     
                break;
            case KeyPress:
                if (XLookupKeysym(&event.xkey, 0) == XK_Escape)
                {
                    done = True;
                }
                /*if (XLookupKeysym(&event.xkey,0) == XK_F1)
                {
                    killGLWindow();
                    GLWin.fs = !GLWin.fs;
                    createGLWindow("NeHe's OpenGL Framework", 640, 480, 24, GLWin.fs);
                }*/
                break;
            case ClientMessage:    
                if (*XGetAtomName(GLWin.dpy, event.xclient.message_type) == 
                    *"WM_PROTOCOLS")
                {
                    std::cout << "Exiting sanely..." << std::endl;
                    done = True;
                }
                break;
            default:
                break;
            }
        }
        if (!done) drawGLScene();
    }
    
    app->Release();
    
    killGLWindow();

    
    GHL_DestroyVFS(vfs);
    
    
    return 0;
}