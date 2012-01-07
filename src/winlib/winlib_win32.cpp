#include <ghl_application.h>
#include <ghl_settings.h>

#include "../vfs/vfs_win32.h"
#include "../render/opengl/render_opengl.h"
#include "../image/image_decoders.h"
#include "../sound/dsound/ghl_sound_dsound.h"
#include "../ghl_log_impl.h"

#include <windows.h>
#include <mmsystem.h>
#include <cstdio>

#include <ghl_system.h>

static const char* MODULE="WinLib";

static GHL::Key convert_key( DWORD code ) {
	switch (code) {
		case VK_SPACE:	return GHL::KEY_SPACE;
		case VK_LEFT:	return GHL::KEY_LEFT;
		case VK_RIGHT:	return GHL::KEY_RIGHT;
		case VK_UP:		return GHL::KEY_UP;
		case VK_DOWN:	return GHL::KEY_DOWN;
		case VK_ESCAPE:	return GHL::KEY_ESCAPE;
		case VK_RETURN:	return GHL::KEY_ENTER;
		
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


LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
	GHL::Application* appl = reinterpret_cast<GHL::Application*>(GetWindowLongPtr(hwnd,GWLP_USERDATA));
	switch(msg)
	{

		case WM_KEYDOWN: {
			GHL::Key key = convert_key(wparam);
			if (key!=GHL::KEY_NONE) {
				if (appl) appl->OnKeyDown(key);
			}
			} break;
		case WM_KEYUP: {
			GHL::Key key = convert_key(wparam);
			if (key!=GHL::KEY_NONE) {
				if (appl) appl->OnKeyUp(key);
			}
			} break;
		case WM_CLOSE:
			SetWindowLongPtr(hwnd,GWLP_USERDATA,(LONG_PTR)0);
			PostMessage (hwnd, WM_QUIT, 0, 0);
			return 0;
			break;
			
		case WM_SETCURSOR:
			/*if (impl) {
				if(impl->m_window_active && LOWORD(lparam)==HTCLIENT && !impl->m_cursor_visible) SetCursor(NULL);
				else SetCursor(LoadCursor(NULL, IDC_ARROW));
				return FALSE;
			}*/
			break;

		case WM_ACTIVATE: 
			if (appl) {
				/*
				// tricky: we should catch WA_ACTIVE and WA_CLICKACTIVE,
				// but only if HIWORD(wParam) (fMinimized) == FALSE (0)
				bool bActivating = (LOWORD(wparam) != WA_INACTIVE) && (HIWORD(wparam) == 0);
				if(impl->m_window_active != bActivating) {
					impl->m_window_active = bActivating;
					if (impl->m_controller) {
						if (bActivating) impl->m_controller->OnFocusGain(impl);
						else impl->m_controller->OnFocusLost(impl);
					}
				}
				return FALSE;
				*/
			}
			break;
		case WM_SYSCOMMAND:
			/*if(wparam==SC_CLOSE)
			{
				if (impl )
				{
					if (impl->m_controller && !impl->m_controller->ExitAllowed())
						return FALSE;
					return DefWindowProc(hwnd, msg, wparam, lparam);
				}
			}*/
			break;
	}
	return DefWindowProc(hwnd, msg, wparam, lparam);;
}

class Win32System : public GHL::System {
private:
	HWND	m_hwnd;
public:
	explicit Win32System(HWND wnd) : m_hwnd(wnd) {}
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
	virtual void GHL_CALL ShowKeyboard() {
	}
        ///
	virtual void GHL_CALL HideKeyboard() {
	}
        ///
	virtual GHL::UInt32  GHL_CALL GetKeyMods() const {
		/// @todo
		return 0;
	}
		///
	virtual bool GHL_CALL SetDeviceState( GHL::DeviceState name, void* data) {
		return false;
	}
		///
	virtual bool GHL_CALL GetDeviceData( GHL::DeviceData name, void* data) {
		return false;
	}
        ///
	virtual void GHL_CALL SetTitle( const char* title ) {
		/// @todo
	}
};
static const TCHAR* WINDOW_CLASS_NAME = TEXT("GHL_WINLIB_WINDOW");
GHL_API int GHL_CALL GHL_StartApplication( GHL::Application* app,int argc, char** argv)
{
	(void)argc;
	(void)argv;

	OSVERSIONINFO	os_ver;
	SYSTEMTIME		tm;
	MEMORYSTATUS	mem_st;

	GetLocalTime(&tm);
	char buf[256];
	sprintf(buf,"Date: %02d.%02d.%d, %02d:%02d:%02d",tm.wDay, tm.wMonth, tm.wYear, tm.wHour, tm.wMinute, tm.wSecond);
	LOG_INFO( buf );

	os_ver.dwOSVersionInfoSize=sizeof(os_ver);
	GetVersionEx(&os_ver);
	sprintf(buf,"OS: Windows %ld.%ld.%ld",os_ver.dwMajorVersion,os_ver.dwMinorVersion,os_ver.dwBuildNumber);
	LOG_INFO( buf );
	GlobalMemoryStatus(&mem_st);
	sprintf(buf,"Memory: %ldK total, %ldK free",mem_st.dwTotalPhys/1024L,mem_st.dwAvailPhys/1024L);
	LOG_INFO( buf );


	
	GHL::VFSWin32Impl vfs;
	app->SetVFS(&vfs);

	GHL::ImageDecoderImpl image;
	app->SetImageDecoder(&image);

	HINSTANCE hInstance = GetModuleHandle(0);
	WNDCLASS		winclass;
	{
		winclass.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
		winclass.lpfnWndProc	= &WindowProc;
		winclass.cbClsExtra		= 0;
		winclass.cbWndExtra		= 0;
		winclass.hInstance		= hInstance;
		winclass.hCursor		= LoadCursor(NULL, IDC_ARROW);
		winclass.hbrBackground	= (HBRUSH)GetStockObject(BLACK_BRUSH);
		winclass.lpszMenuName	= NULL;
		winclass.lpszClassName	= WINDOW_CLASS_NAME;
		winclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		if (!RegisterClass(&winclass)) {
			LOG_ERROR( "Can't register window class" );
			return 1;
		}
	}
	GHL::Settings settings;
	settings.width = 800;
	settings.height = 600;
	settings.fullscreen = false;
	app->FillSettings(&settings);

	size_t width=settings.width + GetSystemMetrics(SM_CXFIXEDFRAME)*2;
	size_t height=settings.height + GetSystemMetrics(SM_CYFIXEDFRAME)*2 + GetSystemMetrics(SM_CYCAPTION);

	RECT rect_w;
	rect_w.left=(GetSystemMetrics(SM_CXSCREEN)-static_cast<int>(width))/2;
	rect_w.top=(GetSystemMetrics(SM_CYSCREEN)-static_cast<int>(height))/2;
	rect_w.right=rect_w.left+width;
	rect_w.bottom=rect_w.top+height;
	DWORD style_w=WS_POPUP|WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX|WS_VISIBLE; 

	/*m_rect_fs.left=0;
	m_rect_fs.top=0;
	m_rect_fs.right=m_width;
	m_rect_fs.bottom=m_height;
	m_style_fs=WS_POPUP|WS_VISIBLE; 
	*/

	HWND hwndParent = 0; /// @todo
	HWND hwnd = 0;
	//if(!settings.fullscreen)

		hwnd = CreateWindowEx(0, WINDOW_CLASS_NAME, TEXT("Test"), style_w,
				rect_w.left, rect_w.top, rect_w.right-rect_w.left, 
				rect_w.bottom-rect_w.top,
				hwndParent, NULL, hInstance, NULL);
	/*else
		m_hwnd = CreateWindowExA(WS_EX_TOPMOST, WINDOW_CLASS_NAME, "Test", m_style_fs,
				0, 0, 0, 0,
				NULL, NULL, hInstance, NULL);*/
	if (!hwnd)
	{
		LOG_ERROR( "Can't create window" );
		return 1;
	}

	GHL::SoundDSound sound;
	if (!sound.SoundInit(hwnd)) {
		LOG_ERROR( "Can't init sound" );
		return 1;
	}
	app->SetSound(&sound);

	Win32System sys(hwnd);
	app->SetSystem(&sys);

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
	SetWindowLongPtr(hwnd,GWLP_USERDATA,(LONG_PTR)app);

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

	GHL::RenderOpenGL render(settings.width,settings.height);
	render.RenderInit();
	app->SetRender(&render);

	if (!app->Load())
		return 1;

	bool done = false;
	timeBeginPeriod(1);
	DWORD ms = timeGetTime();
	while (!done) {
	/*
	if (m_input)
		m_input->Update();
		*/
		sound.Process();

		MSG		msg;
		while (PeekMessage(&msg,hwnd,0,0,PM_REMOVE) && !done)
		{
			if (msg.message == WM_QUIT) {
				done = true;
				if (app) {
					app->Release();
					app = 0;
				}
				render.RenderDone();
				sound.SoundDone();
				LOG_INFO( "Done" );
				break;
			} else
				DispatchMessage(&msg);
		}
		if (app) {	
			wglMakeCurrent (hDC, hRC);
			DWORD now = timeGetTime();
			DWORD dt = now - ms;
			ms = now;
			if (dt>1000)
				dt = 1000;
			app->OnFrame(dt*1000);
			SwapBuffers (hDC);
			Sleep(1);
		}
	}
	timeEndPeriod(1);
	
	return 0;
}

GHL_API void GHL_CALL GHL_Log( GHL::LogLevel level,const char* message) {
	/// @todo
}
 