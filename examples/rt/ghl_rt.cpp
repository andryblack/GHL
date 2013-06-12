#include <ghl_application.h>
#include <ghl_settings.h>
#include <ghl_render.h>
#include <ghl_system.h>
#include <ghl_texture.h>
#include <ghl_log.h>
#include <ghl_vfs.h>
#include <ghl_sound.h>
#include "../common/application_base.h"
#include <sstream>
#include <list>
#include <vector>

class Application : public ApplicationBase {
private:
    GHL::Texture*       m_tex_star;
    GHL::RenderTarget*  m_rt;
public:
    Application() {
        m_tex_star = 0;
        m_rt = 0;
    }
    
    ~Application() {
        if (m_rt) {
            m_rt->Release();
        }
        if (m_tex_star) {
            m_tex_star->Release();
        }
        GHL_Log(GHL::LOG_LEVEL_INFO,"Application destroyed");
    }
    
    /// called after window created, before first rendered
    virtual void GHL_CALL Initialize() {
        
    }
    
    ///
    virtual void GHL_CALL FillSettings( GHL::Settings* settings ) {
        settings->fullscreen = false;
    }
    ///
    virtual bool GHL_CALL Load() {
        m_tex_star = LoadTexture("data/star.png");
        if (!m_tex_star) {
            GHL_Log(GHL::LOG_LEVEL_ERROR,"load data/star.png");
        } else {
            m_tex_star->SetMinFilter(GHL::TEX_FILTER_LINEAR);
            m_tex_star->SetMagFilter(GHL::TEX_FILTER_LINEAR);
        }
        m_rt = m_render->CreateRenderTarget(128, 128, GHL::TEXTURE_FORMAT_RGBA, false);
        return true;
    }
    
    void OnTimer(GHL::UInt32 usecs) {
        ApplicationBase::OnTimer(usecs);
        //float dt = float(usecs)/1000000.0f;
        if (m_rt) {
            m_render->BeginScene(m_rt);
            m_render->Clear(0.5, 0.3, 0.3, 1, 0);
            DrawStars();
            m_render->EndScene();
        }
    }
    
    void DrawStars() {
        DrawImage(m_tex_star,0,0);
    }
    
    void DrawScene() {
        m_render->Clear( 0.25f, 0.25f, 0.35f, 0.0f, 0.0f);
        
        DrawStars();
        if (m_rt) {
            DrawImage(m_rt->GetTexture(), 256, 256);
        }
    }
    
    virtual int  DrawDebug(GHL::Int32 x, GHL::Int32 y) {
        y = ApplicationBase::DrawDebug(x, y);
        m_render->DebugDrawText(x,y,"GHL example");    y+=16;
        std::stringstream ss;
        ss << "mouse: " << m_mouse_pos_x << "," << m_mouse_pos_y;
        m_render->DebugDrawText(x,y,ss.str().c_str()); y+=16;
        return y;
    }
    
    virtual void GHL_CALL OnMouseDown( GHL::MouseButton btn, GHL::Int32 x, GHL::Int32 y)  {
        ApplicationBase::OnMouseDown(btn,x,y);
    }
};


#if defined( GHL_PLATFORM_WIN )
#include <windows.h>
int WINAPI WinMain(HINSTANCE /*hInst*/,HINSTANCE /*hPrev*/,LPSTR /*cmdLine*/,int /*showCmd*/) {
	int res =  GHL_StartApplication(new Application(),0,0);
	return res;
}
#elif defined( GHL_PLATFORM_ANDROID )
extern "C" __attribute__ ((visibility ("default"))) int ghl_android_app_main(int argc,char** argv) {
    Application* app = new Application;
    return GHL_StartApplication(app,argc,argv);
}
#else
int main(int argc,char* argv[]) {
    Application* app = new Application;
    return GHL_StartApplication(app,argc,argv);
}
#endif
