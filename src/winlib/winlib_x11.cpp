#include "ghl_application.h"
#include "ghl_settings.h"
#include "ghl_vfs.h"
#include "ghl_keys.h"
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
    Window root;
    GLXContext ctx;
    XSetWindowAttributes attr;
    bool fs;
    bool needFS;
#ifdef HAVE_XF86VMODE
    XF86VidModeModeInfo deskMode;
    XF86VidModeModeInfo fsMode;
#endif
    int x, y;
    unsigned int width, height;
    unsigned int depth;
    GHL::RenderImpl*	render;
    GHL::Application*	application;
    timeval	lastTime;
    GHL::UInt32 keyMods;
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



static void get_modifier_masks(unsigned mask)
{
    static unsigned meta_l_mask, meta_r_mask, alt_l_mask, alt_r_mask;
    static unsigned num_mask, mode_switch_mask;

    static bool got_masks = true;
    unsigned i, j;
    unsigned n;

    if(got_masks) {
        XModifierKeymap *xmods;

        xmods = XGetModifierMapping(GLWin.dpy);
        n = xmods->max_keypermod;
        for(i = 3; i < 8; i++) {
            for(j = 0; j < n; j++) {
                KeyCode kc = xmods->modifiermap[i * n + j];
                KeySym ks = XKeycodeToKeysym(GLWin.dpy, kc, 0);
                unsigned mask = 1 << i;
                switch(ks) {
                case XK_Num_Lock:
                    num_mask = mask; break;
                case XK_Alt_L:
                    alt_l_mask = mask; break;
                case XK_Alt_R:
                    alt_r_mask = mask; break;
                case XK_Meta_L:
                    meta_l_mask = mask; break;
                case XK_Meta_R:
                    meta_r_mask = mask; break;
                case XK_Mode_switch:
                    mode_switch_mask = mask; break;
                }
            }
        }
        XFreeModifiermap(xmods);
        got_masks = false;
    }
    GLWin.keyMods = 0;
    if (mask & (meta_l_mask|meta_r_mask)) {
        GLWin.keyMods |= GHL::KEYMOD_CTRL;
    }
    if (mask & (alt_l_mask|alt_r_mask)) {
        GLWin.keyMods |= GHL::KEYMOD_ALT;
    }
    if (mask & (mode_switch_mask)) {
        GLWin.keyMods |= GHL::KEYMOD_SHIFT;
    }
}



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
    GHL::UInt32  GHL_CALL GetKeyMods() const {
        return GLWin.keyMods;
    }

    bool IsDone() const { return m_done;}

    virtual bool GHL_CALL IsFullscreen() const {
        return GLWin.fs;
    }
    virtual void GHL_CALL SwitchFullscreen(bool fs) {
        GLWin.needFS = fs;
    }
};


/* function called when our window is resized (should only happen in window mode) */
void resizeGLScene(unsigned int width, unsigned int height)
{
    if (height == 0)    /* Prevent A Divide By Zero If The Window Is Too Small */
        height = 1;
    GLWin.render->Resize( width, height );
}

/* general OpenGL initialization function */
int initGL()
{
    GLWin.render = GHL_CreateRenderOpenGL( GLWin.width, GLWin.height );

    if (GLWin.render) {

    } else {
    return False;
    }
    return True;
}

/* Here goes our drawing code */
int drawGLScene()
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
        }
        XSetWMNormalHints(GLWin.dpy,GLWin.win, hints);
        XSync(GLWin.dpy,True);
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

    XGrabKeyboard(GLWin.dpy, GLWin.win, True, GrabModeAsync,
        GrabModeAsync, CurrentTime);

    if (GLWin.fs) {
        //XMapRaised(GLWin.dpy,GLWin.win);
        //XWarpPointer(GLWin.dpy, None, GLWin.win, 0, 0, 0, 0, 0, 0);
        /*
        XGrabPointer(GLWin.dpy, GLWin.win, True, ButtonPressMask,
            GrabModeAsync, GrabModeAsync, GLWin.win, None, CurrentTime);
            */
    } else {
        //XMapWindow(GLWin.dpy,GLWin.win);
        //XWarpPointer(GLWin.dpy, None, 0, 0, 0, 0, 0, 0, 0);
    }
}


/* function to release/destroy our resources and restoring the old desktop */
GLvoid killGLWindow()
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

static void switchGLWindow() {

    XUnmapWindow(GLWin.dpy, GLWin.win);

    GLWin.fs = GLWin.needFS;
#ifdef HAVE_XF86VMODE
    if (!GLWin.fs) {
        XF86VidModeSwitchToMode(GLWin.dpy, GLWin.screen, &GLWin.deskMode);
        XF86VidModeSetViewPort(GLWin.dpy, GLWin.screen, 0, 0);
    } else {
        XF86VidModeSwitchToMode(GLWin.dpy, GLWin.screen, &GLWin.fsMode);
        XF86VidModeSetViewPort(GLWin.dpy, GLWin.screen, 0, 0);
    }
#endif

    unsigned int attributesMask = 0;
    if (GLWin.fs) {
        GLWin.attr.override_redirect = True;
        GLWin.attr.event_mask = ExposureMask | KeyPressMask | ButtonPressMask |
            StructureNotifyMask;
        attributesMask = CWBorderPixel | CWColormap | CWEventMask | CWOverrideRedirect;
    }
    else
    {
        attributesMask = CWBorderPixel | CWColormap | CWEventMask | CWOverrideRedirect;
        GLWin.attr.event_mask = ExposureMask | KeyPressMask | ButtonPressMask |
            StructureNotifyMask;
        GLWin.attr.override_redirect = False;
    }
    XChangeWindowAttributes(GLWin.dpy, GLWin.win,attributesMask,&GLWin.attr);


     X11_SetSizeHints();
     XMapRaised(GLWin.dpy, GLWin.win);
     if (GLWin.fs) {
         XMoveWindow(GLWin.dpy, GLWin.win, 0, 0);
     }
     XSync(GLWin.dpy, True);
    glXMakeCurrent(GLWin.dpy, GLWin.win, GLWin.ctx);
    Window winDummy;
    unsigned int borderDummy;
    XGetGeometry(GLWin.dpy, GLWin.win, &winDummy, &GLWin.x, &GLWin.y,
        &GLWin.width, &GLWin.height, &borderDummy, &GLWin.depth);
    std::cout << "Geometry: " << GLWin.x << "," << GLWin.y << " " << GLWin.width << "x"<<GLWin.height << " Depth " << GLWin.depth << std::endl;
    if (glXIsDirect(GLWin.dpy, GLWin.ctx))
        std::cout << "Congrats, you have Direct Rendering!" << std::endl;
    else
        std::cout << "Sorry, no Direct Rendering possible!" << std::endl;
}

/* this function creates our window and sets it up properly */
Bool createGLWindow(const char* title, int width, int height,
                    Bool fullscreenflag)
{
    XVisualInfo *vi;
    Colormap cmap;
    int dpyWidth = width;
    int dpyHeight = height;
    int glxMajorVersion, glxMinorVersion;
#ifdef HAVE_XF86VMODE
    int vidModeMajorVersion, vidModeMinorVersion;
    XF86VidModeModeInfo **modes;
    int i;
    int modeNum = 0;
    int bestMode = 0;
#endif
    Atom wmDelete;

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
    GLWin.fsMode = *modes[bestMode];
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
    GLWin.root = RootWindow(GLWin.dpy, vi->screen);
    cmap = XCreateColormap(GLWin.dpy, GLWin.root ,
        vi->visual, AllocNone);
    GLWin.attr.colormap = cmap;
    GLWin.attr.border_pixel = 0;

    if (GLWin.fs)
    {
#ifdef HAVE_XF86VMODE
        dpyWidth = GLWin.fsMode.hdisplay;
        dpyHeight = GLWin.fsMode.vdisplay;
        std::cout << "Resolution " << dpyWidth << "x" << dpyHeight << std::endl;
#endif
    }
    int w = width;
    int h = height;
    unsigned int attributesMask = 0;
    if (GLWin.fs) {
        /* create a fullscreen window */
        GLWin.attr.override_redirect = True;
        GLWin.attr.event_mask = ExposureMask | KeyPressMask | ButtonPressMask |
            StructureNotifyMask;
        attributesMask = CWBorderPixel | CWColormap | CWEventMask | CWOverrideRedirect;
        w = dpyWidth;
        h = dpyHeight;
    }
    else
    {
        /* create a window in window mode*/
        attributesMask = CWBorderPixel | CWColormap | CWEventMask;
        GLWin.attr.event_mask = ExposureMask | KeyPressMask | ButtonPressMask |
            StructureNotifyMask;
        GLWin.attr.override_redirect = False;
    }

    GLWin.win = XCreateWindow(GLWin.dpy, GLWin.root,
        0, 0, w, h, 0, vi->depth, InputOutput, vi->visual,
        attributesMask,
        &GLWin.attr);


    /*
    */


    wmDelete = XInternAtom(GLWin.dpy, "WM_DELETE_WINDOW", True);
    XSetWMProtocols(GLWin.dpy, GLWin.win, &wmDelete, 1);
    XSetStandardProperties(GLWin.dpy, GLWin.win, title,
        title, None, NULL, 0, NULL);



#ifdef HAVE_XF86VMODE
    XFree(modes);
#endif

    switchGLWindow();

    initGL();


    return True;
}




bool ConvertX11Key(KeySym key,GHL::Key& out) {
    switch (key) {
        case XK_Escape:     out=GHL::KEY_ESCAPE; break;
        case XK_F1:     out=GHL::KEY_F1; break;
        case XK_F2:     out=GHL::KEY_F2; break;
        case XK_F3:     out=GHL::KEY_F3; break;
        case XK_F4:     out=GHL::KEY_F4; break;
        case XK_F5:     out=GHL::KEY_F5; break;
        case XK_F6:     out=GHL::KEY_F6; break;
        case XK_F7:     out=GHL::KEY_F7; break;
        case XK_F8:     out=GHL::KEY_F8; break;
        case XK_F9:     out=GHL::KEY_F9; break;
        case XK_F10:     out=GHL::KEY_F10; break;
        case XK_F11:     out=GHL::KEY_F11; break;
        case XK_F12:     out=GHL::KEY_F12; break;
        case XK_Return:  out=GHL::KEY_ENTER;break;
        case XK_space:  out=GHL::KEY_SPACE;break;
        case XK_BackSpace: out=GHL::KEY_BACKSPACE;break;
        case XK_Left:       out=GHL::KEY_LEFT;break;
        case XK_Right:      out=GHL::KEY_RIGHT;break;
        case XK_Up:         out=GHL::KEY_UP;break;
        case XK_Down:       out=GHL::KEY_DOWN;break;
        case XK_Page_Up:    out=GHL::KEY_PGUP;break;
        case XK_Page_Down:  out=GHL::KEY_PGDN;break;
        case XK_KP_0:  out=GHL::KEY_NUMPAD0;break;
        case XK_KP_1:  out=GHL::KEY_NUMPAD1;break;
        case XK_KP_2:  out=GHL::KEY_NUMPAD2;break;
        case XK_KP_3:  out=GHL::KEY_NUMPAD3;break;
        case XK_KP_4:  out=GHL::KEY_NUMPAD4;break;
        case XK_KP_5:  out=GHL::KEY_NUMPAD5;break;
        case XK_KP_6:  out=GHL::KEY_NUMPAD6;break;
        case XK_KP_7:  out=GHL::KEY_NUMPAD7;break;
        case XK_KP_8:  out=GHL::KEY_NUMPAD8;break;
        case XK_KP_9:  out=GHL::KEY_NUMPAD9;break;
        case XK_0:  out=GHL::KEY_0;break;
        case XK_1:  out=GHL::KEY_1;break;
        case XK_2:  out=GHL::KEY_2;break;
        case XK_3:  out=GHL::KEY_3;break;
        case XK_4:  out=GHL::KEY_4;break;
        case XK_5:  out=GHL::KEY_5;break;
        case XK_6:  out=GHL::KEY_6;break;
        case XK_7:  out=GHL::KEY_7;break;
        case XK_8:  out=GHL::KEY_8;break;
        case XK_9:  out=GHL::KEY_9;break;
        case XK_A:  out=GHL::KEY_A;break;
        case XK_B:  out=GHL::KEY_B;break;
        case XK_C:  out=GHL::KEY_C;break;
        case XK_D:  out=GHL::KEY_D;break;
        case XK_E:  out=GHL::KEY_E;break;
        case XK_F:  out=GHL::KEY_F;break;
        case XK_G:  out=GHL::KEY_G;break;
        case XK_H:  out=GHL::KEY_H;break;
        case XK_I:  out=GHL::KEY_I;break;
        case XK_J:  out=GHL::KEY_J;break;
        case XK_K:  out=GHL::KEY_K;break;
        case XK_L:  out=GHL::KEY_L;break;
        case XK_M:  out=GHL::KEY_M;break;
        case XK_N:  out=GHL::KEY_N;break;
        case XK_O:  out=GHL::KEY_O;break;
        case XK_P:  out=GHL::KEY_P;break;
        case XK_Q:  out=GHL::KEY_Q;break;
        case XK_R:  out=GHL::KEY_R;break;
        case XK_S:  out=GHL::KEY_S;break;
        case XK_T:  out=GHL::KEY_T;break;
        case XK_U:  out=GHL::KEY_U;break;
        case XK_V:  out=GHL::KEY_V;break;
        case XK_W:  out=GHL::KEY_W;break;
        case XK_X:  out=GHL::KEY_X;break;
        case XK_Y:  out=GHL::KEY_Y;break;
        case XK_Z:  out=GHL::KEY_Z;break;
        default:
            return false;
    }
    return true;
}



GHL_API int GHL_CALL GHL_StartApplication( GHL::Application* app , int /*argc*/, char** /*argv*/) {
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
    GLWin.needFS = settings.fullscreen;

    if (createGLWindow("HGL Window", settings.width, settings.height,  GLWin.fs)) {
        app->SetRender(GLWin.render);
    } else {
        std::cout << "Error initialize window" << std::endl;
        return 1;
    }

    GLWin.keyMods = 0;
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
                if ((event.xconfigure.width != int(GLWin.width)) ||
                    (event.xconfigure.height != int(GLWin.height)))
                {
                    GLWin.width = event.xconfigure.width;
                    GLWin.height = event.xconfigure.height;
                    resizeGLScene(event.xconfigure.width,
                        event.xconfigure.height);
                }
                break;
            case ButtonPress:
                break;
            case KeyPress: {
                    KeySym sym = XKeycodeToKeysym(GLWin.dpy,event.xkey.keycode,0);
                    GHL::Key key;
                    get_modifier_masks(event.xkey.state);
                    if (ConvertX11Key(sym,key)) {
                        app->OnKeyDown(key);
                    }
                } break;
            case KeyRelease: {
                    KeySym sym = XKeycodeToKeysym(GLWin.dpy,event.xkey.keycode,0);
                    get_modifier_masks(event.xkey.state);
                    GHL::Key key;
                    if (ConvertX11Key(sym,key)) {
                        app->OnKeyUp(key);
                    }
                } break;
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
        if (!done) {
            if (GLWin.fs!=GLWin.needFS) {
                std::cout << "switch mode" << std::endl;
                switchGLWindow();
                GLWin.needFS = GLWin.fs;
            } else {
                drawGLScene();
            }
        }
    }

    app->Release();

    killGLWindow();


    GHL_DestroyVFS(vfs);


    return 0;
}
