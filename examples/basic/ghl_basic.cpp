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
    GHL::Texture*   m_tex_star;
    struct StarState {
        float x;
        float y;
        float size;
        float alpha;
        float angle;
    };
    std::list<StarState>    m_stars;
    GHL::SoundEffect*   m_effect;
    GHL::MusicInstance* m_music;
public:
    Application() {
        m_tex_star = 0;
        m_effect = 0;
        m_music = 0;
    }

    ~Application() {
        if (m_music) {
            m_music->Release();
        }
        if (m_effect) {
            m_effect->Release();
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
        m_effect = LoadEffect("data/sample.wav");
        if (!m_effect) {
            GHL_Log(GHL::LOG_LEVEL_ERROR,"load data/sample.wav");
        }
        if ( m_sound && m_vfs) {
            std::string file = m_vfs->GetDir(GHL::DIR_TYPE_DATA);
            file+="/data/music.mp3";
            GHL::DataStream* ds = m_vfs->OpenFile(file.c_str());
            if (!ds) {
                GHL_Log(GHL::LOG_LEVEL_ERROR,"not open music file");
            } else {
                m_music = m_sound->OpenMusic( ds );
                if ( m_music ) {
                    m_music->Play(true);
                }
            }
        }
        return true;
    }

    void OnTimer(GHL::UInt32 usecs) {
        ApplicationBase::OnTimer(usecs);
        float dt = float(usecs)/1000000.0f;
        for (std::list<StarState>::iterator it=m_stars.begin();it!=m_stars.end();) {
            it->size += 100.0f * dt;
            if (it->size>128.0f) {
                it->alpha-=dt*2.0f;
                if (it->alpha<0.0f) {
                    it->alpha = 0.0f;
                    it = m_stars.erase(it);
                    continue;
                }
            }
            ++it;
        }

    }

    void DrawScene() {
        m_render->Clear( 0.25f, 0.25f, 0.35f, 0);

        if (m_tex_star && !m_stars.empty() ) {
            std::vector<GHL::Vertex>    vertexes;
            std::vector<GHL::UInt16>    indexes;
            vertexes.resize(m_stars.size()*4);
            indexes.resize(m_stars.size()*6);
            size_t v_index = 0;
            size_t i_index = 0;
            for (std::list<StarState>::const_iterator it=m_stars.begin();it!=m_stars.end();++it) {
                float x = it->x;
                float y = it->y;
                float size = it->size;
                GHL::Byte a = GHL::Byte( it->alpha * 255 );

                vertexes[v_index+0].x = x - size;
                vertexes[v_index+0].y = y - size;
                vertexes[v_index+0].z = 0.0f;
                vertexes[v_index+0].tx = 0.0f;
                vertexes[v_index+0].ty = 0.0f;
                vertexes[v_index+0].color[0]=a;
                vertexes[v_index+0].color[1]=a;
                vertexes[v_index+0].color[2]=a;
                vertexes[v_index+0].color[3]=255;

                vertexes[v_index+1].x = x + size;
                vertexes[v_index+1].y = y - size;
                vertexes[v_index+1].z = 0.0f;
                vertexes[v_index+1].tx = 1.0f;
                vertexes[v_index+1].ty = 0.0f;
                vertexes[v_index+1].color[0]=a;
                vertexes[v_index+1].color[1]=a;
                vertexes[v_index+1].color[2]=a;
                vertexes[v_index+1].color[3]=255;

                vertexes[v_index+2].x = x + size;
                vertexes[v_index+2].y = y + size;
                vertexes[v_index+2].z = 0.0f;
                vertexes[v_index+2].tx = 1.0f;
                vertexes[v_index+2].ty = 1.0f;
                vertexes[v_index+2].color[0]=a;
                vertexes[v_index+2].color[1]=a;
                vertexes[v_index+2].color[2]=a;
                vertexes[v_index+2].color[3]=255;

                vertexes[v_index+3].x = x - size;
                vertexes[v_index+3].y = y + size;
                vertexes[v_index+3].z = 0.0f;
                vertexes[v_index+3].tx = 0.0f;
                vertexes[v_index+3].ty = 1.0f;
                vertexes[v_index+3].color[0]=a;
                vertexes[v_index+3].color[1]=a;
                vertexes[v_index+3].color[2]=a;
                vertexes[v_index+3].color[3]=255;

                indexes[i_index+0] = v_index + 0;
                indexes[i_index+1] = v_index + 1;
                indexes[i_index+2] = v_index + 2;
                indexes[i_index+3] = v_index + 2;
                indexes[i_index+4] = v_index + 3;
                indexes[i_index+5] = v_index + 0;

                v_index+=4;
                i_index+=6;
            }
            m_render->SetTexture(m_tex_star);
            m_render->SetupBlend(true,GHL::BLEND_FACTOR_ONE,GHL::BLEND_FACTOR_ONE);
            m_render->DrawPrimitivesFromMemory(GHL::PRIMITIVE_TYPE_TRIANGLES,
                                               GHL::VERTEX_TYPE_SIMPLE,
                                               &vertexes[0],
                                               GHL::UInt32(vertexes.size()),
                                               &indexes[0],
                                               GHL::UInt32(m_stars.size()*2));
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
        StarState star;
        star.x = float(x);
        star.y = float(y);
        star.size = 10;
        star.angle = 0;
        star.alpha = 1;
        m_stars.push_back(star);
        if (m_effect && m_sound) {
            m_sound->PlayEffect(m_effect);
        }
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
