#include <ghl_application.h>
#include <ghl_settings.h>

#include "../vfs/vfs_win32.h"
#include "../render/opengl/render_opengl.h"
#include "../image/image_decoders.h"
#ifndef GHL_NO_SOUND
#include "../sound/dsound/ghl_sound_dsound.h"
#endif
#include "../ghl_log_impl.h"
#include <ghl_event.h>

#include <windows.h>
#include <mmsystem.h>
#include <cstdio>
#include <time.h>

#include <ghl_system.h>
#include <ghl_time.h>
#include <windowsx.h>


#ifdef _MSC_VER
#define snprintf _snprintf
#endif

static const char* MODULE="WinLib";


static const WCHAR WINDOW_CLASS_NAME[] = L"GHL_WINLIB_WINDOW";
static const WCHAR WINDOW_TITLE[] = L"GHL";
static const WCHAR INPUT_MODAL_CLASS_NAME[] = L"GHL_WINLIB_INPUT_WINDOW";


#ifndef DPI_ENUMS_DECLARED
typedef enum PROCESS_DPI_AWARENESS
{
    PROCESS_DPI_UNAWARE = 0,
    PROCESS_SYSTEM_DPI_AWARE = 1,
    PROCESS_PER_MONITOR_DPI_AWARE = 2
} PROCESS_DPI_AWARENESS;
#endif


typedef BOOL (WINAPI * SETPROCESSDPIAWARE_T)(void);
typedef HRESULT (WINAPI * SETPROCESSDPIAWARENESS_T)(PROCESS_DPI_AWARENESS);

static bool win32_SetProcessDpiAware(void) {
    HMODULE shcore = LoadLibraryA("Shcore.dll");
    SETPROCESSDPIAWARENESS_T SetProcessDpiAwareness = NULL;
    if (shcore) {
        SetProcessDpiAwareness = (SETPROCESSDPIAWARENESS_T) GetProcAddress(shcore, "SetProcessDpiAwareness");
    }
    HMODULE user32 = LoadLibraryA("User32.dll");
    SETPROCESSDPIAWARE_T SetProcessDPIAware = NULL;
    if (user32) {
        SetProcessDPIAware = (SETPROCESSDPIAWARE_T) GetProcAddress(user32, "SetProcessDPIAware");
    }

    bool ret = false;
    if (SetProcessDpiAwareness) {
        ret = SetProcessDpiAwareness(PROCESS_SYSTEM_DPI_AWARE) == S_OK;
    } else if (SetProcessDPIAware) {
        ret = SetProcessDPIAware() != 0;
    }

    if (user32) {
        FreeLibrary(user32);
    }
    if (shcore) {
        FreeLibrary(shcore);
    }
    return ret;
}

static GHL::Key convert_key( DWORD code ) {
	switch (code) {
		case VK_SPACE:	return GHL::KEY_SPACE;
		case VK_LEFT:	return GHL::KEY_LEFT;
		case VK_RIGHT:	return GHL::KEY_RIGHT;
		case VK_UP:		return GHL::KEY_UP;
		case VK_DOWN:	return GHL::KEY_DOWN;
		case VK_ESCAPE:	return GHL::KEY_ESCAPE;
		case VK_RETURN:	return GHL::KEY_ENTER;
		case VK_BACK:	return GHL::KEY_BACKSPACE;
		
		case 0x30:		return GHL::KEY_0;
		case 0x31:		return GHL::KEY_1;
		case 0x32:		return GHL::KEY_2;
		case 0x33:		return GHL::KEY_3;
		case 0x34:		return GHL::KEY_4;
		case 0x35:		return GHL::KEY_5;
		case 0x36:		return GHL::KEY_6;
		case 0x37:		return GHL::KEY_7;
		case 0x38:		return GHL::KEY_8;
		case 0x39:		return GHL::KEY_9;

		case 0x41:		return GHL::KEY_A;
		case 0x42:		return GHL::KEY_B;
		case 0x43:		return GHL::KEY_C;
		case 0x44:		return GHL::KEY_D;
		case 0x45:		return GHL::KEY_E;
		case 0x46:		return GHL::KEY_F;
		case 0x47:		return GHL::KEY_G;
		case 0x48:		return GHL::KEY_H;
		case 0x49:		return GHL::KEY_I;
		case 0x4A:		return GHL::KEY_J;
		case 0x4B:		return GHL::KEY_K;
		case 0x4C:		return GHL::KEY_L;
		case 0x4D:		return GHL::KEY_M;
		case 0x4E:		return GHL::KEY_N;
		case 0x4F:		return GHL::KEY_O;
		case 0x50:		return GHL::KEY_P;
		case 0x51:		return GHL::KEY_Q;
		case 0x52:		return GHL::KEY_R;
		case 0x53:		return GHL::KEY_S;
		case 0x54:		return GHL::KEY_T;
		case 0x55:		return GHL::KEY_U;
		case 0x56:		return GHL::KEY_V;
		case 0x57:		return GHL::KEY_W;
		case 0x58:		return GHL::KEY_Z;
		case 0x59:		return GHL::KEY_Y;
		case 0x5A:		return GHL::KEY_Z;
	};
	return GHL::KEY_NONE;
}



class Win32System : public GHL::System {
private:
	GHL::Application*	m_app;
	bool 	m_active;
	HWND	m_hwnd;
	HWND 	m_edit;
	std::string m_title;
public:
	explicit Win32System(GHL::Application* app) : 
		m_app(app), 
		m_active(true),
		m_hwnd(0),
		m_edit(0) {
	}
	
	void SetWnd(HWND wnd) {
		m_hwnd = wnd;
		if (!m_title.empty()) {
			SetTitle(m_title.c_str());
		}
	}

	void SetActive(bool a) {
		m_active = a;
	}
	
	const std::string& GetTitle() const { return m_title; }
	GHL::Application* GetApp() { return m_app; }
	bool IsActive() const { return m_active; }

	void GHL_CALL Exit() {
		PostMessage(m_hwnd,WM_QUIT,0,0);
	}
	///
	virtual bool GHL_CALL IsFullscreen() const {
		return false;
	}
        ///
	virtual void GHL_CALL SwitchFullscreen(bool fs) {
		/// @todo
	}
        ///
	virtual void GHL_CALL ShowKeyboard(const GHL::TextInputConfig* input) {
		if (!m_edit && input && input->system_input)  {
			RECT rect;
			GetWindowRect(m_hwnd,&rect);
			m_edit = CreateWindowW(INPUT_MODAL_CLASS_NAME, 0, 
				WS_POPUP|WS_CLIPSIBLINGS|WS_VISIBLE|WS_BORDER|WS_THICKFRAME ,
				 rect.left+4, rect.bottom-4-80, rect.right-rect.left-8, 80, m_hwnd, 0, GetModuleHandle(0), 0);
			EnableWindow(m_hwnd,FALSE);
			ShowWindow(m_edit,SW_SHOW);
			SetFocus(GetDlgItem(m_edit, 1));
			MSG        msg;
		    while(GetMessage(&msg,NULL,0,0))
		    {
		    	if (msg.message == WM_CLOSE || 
		    		msg.message == WM_QUIT ||
		    		msg.message == WM_DESTROY) {
		    		break;
		    	}
		        TranslateMessage(&msg);
		        DispatchMessage(&msg);
		    }
		    EnableWindow(m_hwnd,TRUE);
		    if (m_edit) {
		    	DestroyWindow(m_edit);
		    	m_edit = 0;
		    }
		    SetFocus(m_hwnd);
		}
	}
        ///
	virtual void GHL_CALL HideKeyboard() {
		if (m_edit) {
			PostMessageW(m_edit, WM_QUIT, 0, 0);
		}
	}
        ///
	virtual GHL::UInt32  GHL_CALL GetKeyMods() const {
		/// @todo
		return 0;
	}
		///
	virtual bool GHL_CALL SetDeviceState( GHL::DeviceState name, const void* data) {
		return false;
	}
	///
	virtual bool GHL_CALL GetDeviceData( GHL::DeviceData name, void* data) {
		return false;
	}
        ///
	virtual void GHL_CALL SetTitle( const char* title ) {
		m_title = title;
		if (m_hwnd) {
			UINT32 l = MultiByteToWideChar(CP_UTF8, 0, title, -1, NULL, 0);
			WCHAR* text = new WCHAR[l];
			MultiByteToWideChar(CP_UTF8, 0, title, -1, text, l);
			SetWindowTextW(m_hwnd,text);
			delete [] text;
		}
	}
	virtual bool GHL_CALL OpenURL( const char* url ) {
		UINT32 l = MultiByteToWideChar(CP_UTF8, 0, url, -1, NULL, 0);
		WCHAR* text = new WCHAR[l];
		MultiByteToWideChar(CP_UTF8, 0, url, -1, text, l);
		ShellExecuteW(0, 0, text, 0, 0 , SW_SHOW );
		delete [] text;
		return true;
    }
    virtual GHL::Font* GHL_CALL CreateFont( const GHL::FontConfig* config ) {
        /// @todo
        return 0;
    }
};


LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
	Win32System* sys = reinterpret_cast<Win32System*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
	GHL::Application* appl = sys ? sys->GetApp() : 0;
	switch(msg)
	{

		case WM_MOUSEMOVE: {
			GHL::Event e;
			e.type = GHL::EVENT_TYPE_MOUSE_MOVE;
			e.data.mouse_move.button = (wparam & MK_LBUTTON) ? GHL::MOUSE_BUTTON_LEFT : GHL::MOUSE_BUTTON_NONE;
			e.data.mouse_move.x = GET_X_LPARAM(lparam);
			e.data.mouse_move.y = GET_Y_LPARAM(lparam);
			e.data.mouse_move.modificators = 0;
			if (appl) appl->OnEvent(&e);
		} break;

		case WM_LBUTTONDOWN: {
			{
				GHL::Event e;
				e.type = GHL::EVENT_TYPE_MOUSE_PRESS;
				e.data.mouse_press.button = GHL::MOUSE_BUTTON_LEFT;
				e.data.mouse_press.x = GET_X_LPARAM(lparam);
				e.data.mouse_press.y = GET_Y_LPARAM(lparam);
				e.data.mouse_press.modificators = 0;
				if (appl) appl->OnEvent(&e);
			}
		} break;

		case WM_LBUTTONUP: {
			{
				GHL::Event e;
				e.type = GHL::EVENT_TYPE_MOUSE_RELEASE;
				e.data.mouse_release.button = GHL::MOUSE_BUTTON_LEFT;
				e.data.mouse_release.x = GET_X_LPARAM(lparam);
				e.data.mouse_release.y = GET_Y_LPARAM(lparam);
				e.data.mouse_release.modificators = 0;
				if (appl) appl->OnEvent(&e);
			}
		} break;

		case WM_KEYDOWN: {
			GHL::Key key = convert_key(wparam);
			if (key!=GHL::KEY_NONE) {
				GHL::Event e;
				e.type = GHL::EVENT_TYPE_KEY_PRESS;
				e.data.key_press.key = key;
				e.data.key_press.charcode = 0;
				e.data.key_press.modificators = 0;
				if (appl) appl->OnEvent(&e);
			}
			return TRUE;
		} break;
		case WM_KEYUP: {
			GHL::Key key = convert_key(wparam);
			if (key!=GHL::KEY_NONE) {
				GHL::Event e;
				e.type = GHL::EVENT_TYPE_KEY_RELEASE;
				e.data.key_release.key = key;
				e.data.key_release.modificators = 0;
				if (appl) appl->OnEvent(&e);
			}
			return TRUE;
		} break;

		case WM_UNICHAR: {
			if (wparam != UNICODE_NOCHAR) {
				GHL::Event e;
				e.type = GHL::EVENT_TYPE_KEY_PRESS;
				e.data.key_press.key = GHL::KEY_NONE;
				e.data.key_press.modificators = 0;
				e.data.key_press.charcode = wparam;
				if (appl) appl->OnEvent(&e);
				e.type = GHL::EVENT_TYPE_KEY_RELEASE;
				if (appl) appl->OnEvent(&e);
				return FALSE;
			} 
			return TRUE;
		} break;

		case WM_CHAR: {
			GHL::Event e;
			e.type = GHL::EVENT_TYPE_KEY_PRESS;
			e.data.key_press.key = GHL::KEY_NONE;
			e.data.key_press.modificators = 0;
			e.data.key_press.charcode = wparam;
			if (appl) appl->OnEvent(&e);
			e.type = GHL::EVENT_TYPE_KEY_RELEASE;
			if (appl) appl->OnEvent(&e);
			return FALSE;
		} break;

		case WM_CLOSE:
			DestroyWindow(hwnd);
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		case WM_ACTIVATE: 
			if (sys) {
				if (!HIWORD(wparam))                    // Check Minimization State
				{
					sys->SetActive(true);
				}
				else
				{
					sys->SetActive(false);
				}
			}
			break;
		default:
			return DefWindowProcW(hwnd, msg, wparam, lparam);
	}
	return FALSE;
}

LRESULT CALLBACK InputEditWindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
   switch (msg)
   {
    case WM_KEYDOWN:
         switch (wparam)
         {
          case VK_RETURN:
          	SendMessage(GetParent(hwnd),WM_COMMAND,(WPARAM)2,LPARAM(0));
          	break;  //or return 0; if you don't want to pass it further to def proc
         }
    default: {
    	WNDPROC oldEditProc = reinterpret_cast<WNDPROC>((LONG_PTR)GetWindowLongPtr(hwnd, GWLP_USERDATA));
        return CallWindowProc(oldEditProc, hwnd, msg, wparam, lparam);
    }
   }
   return 0;
}

LRESULT CALLBACK InputWindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
	switch(msg)
	{
		case WM_CREATE: {
			RECT rect;
			GetClientRect(hwnd,&rect);
			HWND edit = CreateWindowW(L"EDIT", L"",    
          		WS_VISIBLE | WS_CHILD ,
          		rect.left+4 , rect.top+4, rect.right-rect.left-8, 25, hwnd, (HMENU) 1, NULL, NULL); 
			WNDPROC oldEditProc = (WNDPROC)SetWindowLongPtr(edit, GWLP_WNDPROC, (LONG_PTR)InputEditWindowProc);
			SetWindowLongPtr(edit,GWLP_USERDATA,(LONG_PTR)oldEditProc);
			CreateWindowW(L"BUTTON", L"Ok",    
          		WS_VISIBLE | WS_CHILD ,
          		rect.right-84 , rect.bottom-29, 80, 25, hwnd, (HMENU) 2, NULL, NULL); 
		} break;
		case WM_CLOSE:
      		// Sends us a WM_DESTROY
      		DestroyWindow(hwnd);
      		break;

		case WM_DESTROY:
			break;

		case WM_KEYDOWN: {
			if (wparam == VK_RETURN) {
				SendMessageW(hwnd,WM_COMMAND,(WPARAM)2,LPARAM(0));
				break;
			}
			return DefWindowProcW(hwnd, msg, wparam, lparam);
		} break;
		
        case WM_COMMAND:
            switch(LOWORD(wparam))
            {
            case 2:{
            	HWND parent = GetParent(hwnd);
            	if (parent) {

            		HWND edit = GetDlgItem(hwnd, 1); // I tried with and without this
            		int len = GetWindowTextLengthW(edit);
            		if (len > 0) {
            			WCHAR* text = new WCHAR[len+1];
            			GetWindowTextW(edit,text,len+1);

            			UINT32 l = WideCharToMultiByte(CP_UTF8, 0, text, -1, NULL, 0, "?", NULL);
						char* textu8 = new char[l];
						WideCharToMultiByte(CP_UTF8, 0, text, -1, textu8, l, "?", NULL);
						delete [] text;

						Win32System* sys = reinterpret_cast<Win32System*>(GetWindowLongPtr(parent, GWLP_USERDATA));
						GHL::Application* appl = sys ? sys->GetApp() : 0;

						GHL::Event e;
						e.type = GHL::EVENT_TYPE_TEXT_INPUT_ACCEPTED;
						e.data.text_input_accepted.text = textu8;
						if (appl) appl->OnEvent(&e);

						delete [] textu8;
            		}
				}
				CloseWindow(hwnd);
               }break;
            }
            break;
        default:
        	return DefWindowProcW(hwnd, msg, wparam, lparam);
	}
	return FALSE;
}

GHL_API int GHL_CALL GHL_StartApplication( GHL::Application* app,int argc, char** argv)
{
	(void)argc;
	(void)argv;

	win32_SetProcessDpiAware(); //true

	OSVERSIONINFO	os_ver;
	SYSTEMTIME		tm;
	MEMORYSTATUS	mem_st;

	GetLocalTime(&tm);
	char buf[256];
	snprintf(buf,256,"Date: %02d.%02d.%d, %02d:%02d:%02d",tm.wDay, tm.wMonth, tm.wYear, tm.wHour, tm.wMinute, tm.wSecond);
	LOG_INFO( buf );

	os_ver.dwOSVersionInfoSize=sizeof(os_ver);
	GetVersionEx(&os_ver);
	snprintf(buf,256,"OS: Windows %ld.%ld.%ld",os_ver.dwMajorVersion,os_ver.dwMinorVersion,os_ver.dwBuildNumber);
	LOG_INFO( buf );
	GlobalMemoryStatus(&mem_st);
	snprintf(buf,256,"Memory: %ldK total, %ldK free",mem_st.dwTotalPhys/1024L,mem_st.dwAvailPhys/1024L);
	LOG_INFO( buf );

	Win32System sys(app);
	app->SetSystem(&sys);

	std::string app_name = sys.GetTitle();
	if (app_name.empty()) {
		app_name = "ghl_app";
	}

	GHL::VFSWin32Impl vfs;
	vfs.SetApplicationName(app_name);
	app->SetVFS(&vfs);

	GHL::ImageDecoderImpl image;
	app->SetImageDecoder(&image);

	
	{
        GHL::Event e;
        e.type = GHL::EVENT_TYPE_APP_STARTED;
        app->OnEvent(&e);
    }

	HINSTANCE hInstance = GetModuleHandle(0);
	
	{
		WNDCLASSW		winclass;
		winclass.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW | CS_BYTEALIGNCLIENT;
		winclass.lpfnWndProc	= &WindowProc;
		winclass.cbClsExtra		= 0;
		winclass.cbWndExtra		= 0;
		winclass.hInstance		= hInstance;
		winclass.hCursor		= LoadCursor(NULL, IDC_ARROW);
		winclass.hbrBackground	= (HBRUSH)GetStockObject(BLACK_BRUSH);
		winclass.lpszMenuName	= NULL;
		winclass.lpszClassName	= WINDOW_CLASS_NAME;
		winclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		if (!RegisterClassW(&winclass)) {
			LOG_ERROR( "Can't register window class" );
			return 1;
		}
	}
	{
		WNDCLASSW		winclass;
		winclass.style = 0;
		winclass.lpfnWndProc	= &InputWindowProc;
		winclass.cbClsExtra		= 0;
		winclass.cbWndExtra		= 0;
		winclass.hInstance		= hInstance;
		winclass.hCursor		= LoadCursor(NULL, IDC_ARROW);
		winclass.hbrBackground	= (HBRUSH)GetStockObject(BLACK_BRUSH);
		winclass.lpszMenuName	= NULL;
		winclass.lpszClassName	= INPUT_MODAL_CLASS_NAME;
		winclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		if (!RegisterClassW(&winclass)) {
			LOG_ERROR( "Can't register input window class" );
			return 1;
		}
	}

	HDC screen = GetDC(NULL);

	GHL::Settings settings;
	settings.width = GetDeviceCaps(screen,HORZRES);
	settings.height = GetDeviceCaps(screen,VERTRES);
	settings.fullscreen = false;
	settings.depth = false;
	
	double hPixelsPerInch = GetDeviceCaps(screen,LOGPIXELSX);
	double vPixelsPerInch = GetDeviceCaps(screen,LOGPIXELSY);
	
	settings.screen_dpi = (hPixelsPerInch + vPixelsPerInch) * 0.5;

	LOG_INFO("screen_dpi: " << settings.screen_dpi);

	ReleaseDC(NULL, screen);

	app->FillSettings(&settings);

	size_t width = settings.width;// +GetSystemMetrics(SM_CXFIXEDFRAME) * 2;
	size_t height = settings.height;// +GetSystemMetrics(SM_CYFIXEDFRAME) * 2 + GetSystemMetrics(SM_CYCAPTION);

	RECT rect_w;
	rect_w.left =(GetSystemMetrics(SM_CXSCREEN) - static_cast<int>(width)) / 2;
	rect_w.top=(GetSystemMetrics(SM_CYSCREEN)-static_cast<int>(height))/2;
	rect_w.right=rect_w.left+width;
	rect_w.bottom=rect_w.top+height;
	DWORD style_w=WS_POPUP|WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX|WS_VISIBLE; 


	HWND hwndParent = 0; /// @todo
	HWND hwnd = 0;
	//if(!settings.fullscreen)

	AdjustWindowRect( &rect_w, style_w, FALSE);

	hwnd = CreateWindowExW(0, WINDOW_CLASS_NAME, WINDOW_TITLE, style_w,
				rect_w.left, rect_w.top, rect_w.right-rect_w.left, 
				rect_w.bottom-rect_w.top,
				hwndParent, NULL, hInstance, NULL);
	
	if (!hwnd)
	{
		LOG_ERROR( "Can't create window" );
		return 1;
	}
	
	sys.SetWnd(hwnd);
	SetWindowLongPtrW(hwnd, GWLP_USERDATA, (LONG_PTR)&sys);

#ifndef GHL_NO_SOUND
	GHL::SoundDSound sound(8);
	if (!sound.SoundInit(hwnd)) {
		LOG_ERROR( "Can't init sound" );
		return 1;
	}
	app->SetSound(&sound);
#endif


	HDC hDC = GetDC (hwnd);
	if (!hDC) {
		DestroyWindow(hwnd);
		return 1;
	}

	PIXELFORMATDESCRIPTOR pfd =											// pfd Tells Windows How We Want Things To Be
	{
		sizeof (PIXELFORMATDESCRIPTOR),									// Size Of This Pixel Format Descriptor
		1,																// Version Number
		PFD_DRAW_TO_WINDOW |											// Format Must Support Window
		PFD_SUPPORT_OPENGL |											// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,												// Must Support Double Buffering
		PFD_TYPE_RGBA,													// Request An RGBA Format
		32,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,												// Color Bits Ignored
		0,																// No Alpha Buffer
		0,																// Shift Bit Ignored
		0,																// No Accumulation Buffer
		0, 0, 0, 0,														// Accumulation Bits Ignored
		24,																// 16Bit Z-Buffer (Depth Buffer)  
		8,																// No Stencil Buffer
		0,																// No Auxiliary Buffer
		PFD_MAIN_PLANE,													// Main Drawing Layer
		0,																// Reserved
		0, 0, 0															// Layer Masks Ignored
	};

	int PixelFormat = ChoosePixelFormat (hDC, &pfd);				// Find A Compatible 

	if (PixelFormat == 0)												// Did We Find A Compatible Format?
	{
		// Failed
		ReleaseDC (hwnd, hDC);							// Release Our Device Context
		hDC = 0;												// Zero The Device Context
		DestroyWindow (hwnd);									// Destroy The Window
		hwnd = 0;												// Zero The Window Handle
		return 1;													// Return False
	}

	if (SetPixelFormat (hDC, PixelFormat, &pfd) == FALSE)		// Try To Set The Pixel Format
	{
		// Failed
		ReleaseDC (hwnd, hDC);							// Release Our Device Context
		hDC = 0;												// Zero The Device Context
		DestroyWindow (hwnd);									// Destroy The Window
		hwnd = 0;												// Zero The Window Handle
		return 1;													// Return False
	}

	HGLRC hRC = wglCreateContext(hDC);

	if (hRC == 0)												// Did We Get A Rendering Context?
	{
		// Failed
		ReleaseDC (hwnd, hDC);							// Release Our Device Context
		hDC = 0;												// Zero The Device Context
		DestroyWindow (hwnd);									// Destroy The Window
		hwnd = 0;												// Zero The Window Handle
		return 1;													// Return False
	}
	
	if (wglMakeCurrent (hDC, hRC) == FALSE)
	{
		// Failed
		wglDeleteContext (hRC);									// Delete The Rendering Context
		hRC = 0;												// Zero The Rendering Context
		ReleaseDC (hwnd, hDC);							// Release Our Device Context
		hDC = 0;												// Zero The Device Context
		DestroyWindow (hwnd);									// Destroy The Window
		hwnd = 0;												// Zero The Window Handle
		return 1;													// Return False
	}

	ShowWindow(hwnd, SW_SHOW);
	

	wglMakeCurrent (hDC, hRC);

	GHL::RenderOpenGLBase* render = GHL_CreateRenderOpenGL(settings.width, settings.height, settings.depth);
	
	app->SetRender(render);

	if (!app->Load())
		return 1;

	{
		LPWSTR cmdline = GetCommandLineW();
		if (cmdline && *cmdline != 0) {
			int num = 0;
			LPWSTR* args = CommandLineToArgvW(cmdline,&num);
			if (args && num > 1 && args[1] && args[1][0]) {
				UINT32 l = WideCharToMultiByte(CP_UTF8, 0, args[1], -1, NULL, 0, "_", NULL);
				char* textu8 = new char[l];
				WideCharToMultiByte(CP_UTF8, 0, args[1], -1, textu8, l, "_", NULL);
				

				GHL::Event e;
		        e.type = GHL::EVENT_TYPE_HANDLE_URL;
		        e.data.handle_url.url = textu8;
		        app->OnEvent(&e);

				delete [] textu8;
			}
			if (args) {
				LocalFree(args);
			}
		}
	}

	bool done = false;
	timeBeginPeriod(1);
	DWORD ms = timeGetTime();
	while (!done) {
	/*
	if (m_input)
		m_input->Update();
		*/
#ifndef GHL_NO_SOUND
		sound.Process();
#endif

		MSG		msg;
		while (PeekMessageW(&msg,NULL,0,0,PM_REMOVE) && !done)
		{
			if (msg.message == WM_QUIT) {
				done = true;
				if (app) {
					app->Release();
					app = 0;
				}
				
#ifndef GHL_NO_SOUND
				sound.SoundDone();
#endif
				LOG_INFO( "Done" );
				break;
			} else {
				TranslateMessage(&msg);
				DispatchMessageW(&msg);
			}
		}
		if (app) {	
			if (sys.IsActive() && wglMakeCurrent(hDC, hRC)) {
				DWORD now = timeGetTime();
				DWORD dt = now - ms;
				ms = now;
				if (dt>1000)
					dt = 1000;
				app->OnFrame(dt * 1000);
				render->get_api().Finish();
				SwapBuffers (hDC);
			}
			Sleep(1);
		}
	}
	GHL_DestroyRenderOpenGL(render);
	timeEndPeriod(1);
	
	return 0;
}

static const WCHAR* level_descr[] = {
    L"F:",
    L"E:",
    L"W:",
    L"I:",
    L"V:",
    L"D:"
};

static WCHAR logbuf[2048];
GHL_API void GHL_CALL GHL_Log( GHL::LogLevel level,const char* message) {
	WCHAR* dst = logbuf;
	memcpy(dst,level_descr[level],sizeof(WCHAR) * 2);
	dst += 2;
	dst += MultiByteToWideChar(CP_UTF8, 0, message, -1, dst, 2048-4);
	memcpy(dst,L"\n",sizeof(WCHAR) * 2);
	OutputDebugStringW( logbuf );
}

GHL_API GHL::UInt32 GHL_CALL GHL_GetCurrentThreadId() {
    return (GHL::UInt32) GetCurrentThreadId();
}

struct critical_section_holder {
	CRITICAL_SECTION section;
	critical_section_holder() {
		InitializeCriticalSection(&section);
	}
	~critical_section_holder() {
		DeleteCriticalSection(&section);
	}
};

CRITICAL_SECTION& ghl_system_mutex() 
{ 
    static critical_section_holder the_x; 
    return the_x.section; 
}

GHL_API void GHL_CALL GHL_GlobalLock() {
    EnterCriticalSection(&ghl_system_mutex());
}

GHL_API void GHL_CALL GHL_GlobalUnlock() {
    LeaveCriticalSection(&ghl_system_mutex());
}

/// Get system time (secs returned)
GHL_API GHL::UInt32 GHL_CALL GHL_SystemGetTime(GHL::TimeValue* ret) {
    DWORD now = timeGetTime();
    if (ret) {
        ret->secs = now / 1000;
        ret->usecs = (now % 1000) * 1000;
    }
    return now / 1000;
}
