#include "application_base.h"
#include <ghl_system.h>
#include <ghl_render.h>
#include <ghl_vfs.h>
#include <ghl_data_stream.h>
#include <ghl_data.h>
#include <ghl_image_decoder.h>
#include <ghl_image.h>
#include <ghl_log.h>
#include <ghl_event.h>
#include <algorithm>
#include <sstream>


ApplicationBase::ApplicationBase() : m_system(0), m_vfs(0),m_render(0),m_image_decoder(0),m_sound(0) {
    m_mouse_pos_x = 0;
    m_mouse_pos_y = 0;
    m_fps = 0;
    m_fps_time = 0;
    m_frames = 0;
}

ApplicationBase::~ApplicationBase() {
}

///
void GHL_CALL ApplicationBase::SetSystem( GHL::System* sys ) {
    m_system = sys;
}
///
void GHL_CALL ApplicationBase::SetVFS( GHL::VFS* vfs ) {
    m_vfs = vfs;
}
///
void GHL_CALL ApplicationBase::SetRender( GHL::Render* render ) {
    m_render = render;
}
///
void GHL_CALL ApplicationBase::SetImageDecoder( GHL::ImageDecoder* decoder ) {
    m_image_decoder = decoder;
}
///
void GHL_CALL ApplicationBase::SetSound( GHL::Sound* sound) {
    m_sound = sound;
}
///
void GHL_CALL ApplicationBase::OnEvent( const GHL::Event* event ) {
    if (event->type == GHL::EVENT_TYPE_KEY_PRESS) {
        if (event->data.key_press.key == GHL::KEY_ESCAPE) {
            m_system->Exit();
        } else if (event->data.key_press.key == GHL::KEY_ENTER) {
            if (event->data.key_press.modificators & GHL::KEYMOD_ALT) {
                m_system->SwitchFullscreen(!m_system->IsFullscreen());
            }
        }
    } else if (event->type == GHL::EVENT_TYPE_MOUSE_PRESS) {
        m_mouse_pos_x = event->data.mouse_press.x;
        m_mouse_pos_y = event->data.mouse_press.y;
    } else if (event->type == GHL::EVENT_TYPE_MOUSE_MOVE) {
        m_mouse_pos_x = event->data.mouse_move.x;
        m_mouse_pos_y = event->data.mouse_move.y;
    } else if (event->type == GHL::EVENT_TYPE_MOUSE_RELEASE) {
        m_mouse_pos_x = event->data.mouse_release.x;
        m_mouse_pos_y = event->data.mouse_release.y;
    }
}

///
void GHL_CALL ApplicationBase::Release(  ) {
    delete this;
}

void ApplicationBase::DrawScene() {
    m_render->Clear( 0.0f, 0.0f, 0.0f, 0.0f, 0.0f );
}

void ApplicationBase::OnTimer(GHL::UInt32 usecs) {
    m_fps_time += usecs;
    if (m_fps_time>=500000) {
        m_fps = float(m_frames*1000000)/float(m_fps_time);
        m_frames = 0;
        m_fps_time = 0;
    }
}

///
bool GHL_CALL ApplicationBase::OnFrame( GHL::UInt32 usecs ) {
    OnTimer(usecs);
    if (!m_render)
        return false;
    m_render->BeginScene( 0 );
    
    DrawScene();
    
    DrawDebug(20,20);
    
    m_render->EndScene();

    ++m_frames;
    return true;
}

int ApplicationBase::DrawDebug(GHL::Int32 x, GHL::Int32 y) {
    std::stringstream ss;
    ss << "fps: " << m_fps;
    m_render->SetupBlend(true,GHL::BLEND_FACTOR_SRC_ALPHA,GHL::BLEND_FACTOR_SRC_ALPHA_INV);
    m_render->DebugDrawText(x,y,ss.str().c_str());
    return y + 16;
}

GHL::Texture* ApplicationBase::LoadTexture(const char* fn) {
    if (!m_vfs) {
        GHL_Log(GHL::LOG_LEVEL_ERROR,"LoadTexture no vfs");
        return 0;
    }
    std::string file = m_vfs->GetDir(GHL::DIR_TYPE_DATA);
    file+="/";
    file+=fn;
    GHL::DataStream* ds = m_vfs->OpenFile(file.c_str());
    if (!ds) {
        GHL_Log(GHL::LOG_LEVEL_ERROR,"LoadTexture not open file");
        return 0;
    }
    GHL::Image* img = 0;
    if (m_image_decoder) {
        img = m_image_decoder->Decode(ds);
    } else {
        GHL_Log(GHL::LOG_LEVEL_ERROR,"LoadTexture no image decoder");
    }
    ds->Release();
    if (!img) {
        GHL_Log(GHL::LOG_LEVEL_ERROR,"LoadTexture no image");
        return 0;
    }
    GHL::Texture* tex = 0;
    if (m_render) {
        tex = m_render->CreateTexture(img->GetWidth(),img->GetHeight(),
                                      GHL_ImageFormatToTextureFormat(img->GetFormat()),
                                      img);
        if (!tex) {
            GHL_Log(GHL::LOG_LEVEL_ERROR,"LoadTexture error CreateTexture");
        } else {
            tex->DiscardInternal();
        }
    } else {
        GHL_Log(GHL::LOG_LEVEL_ERROR,"LoadTexture no render");
    }
    img->Release();
    return tex;
}

GHL::SoundEffect*   ApplicationBase::LoadEffect( const char* fn) {
    if (!m_vfs) {
        GHL_Log(GHL::LOG_LEVEL_ERROR,"LoadEffect no vfs");
        return 0;
    }
    std::string file = m_vfs->GetDir(GHL::DIR_TYPE_DATA);
    file+="/";
    file+=fn;
    GHL::DataStream* ds = m_vfs->OpenFile(file.c_str());
    if (!ds) {
        GHL_Log(GHL::LOG_LEVEL_ERROR,"LoadEffect not open file");
        return 0;
    }
    GHL::SoundDecoder* decoder = GHL_CreateSoundDecoder(ds);
    ds->Release();
    if (!decoder) {
        GHL_Log(GHL::LOG_LEVEL_ERROR,"LoadEffect not create decoder");
        return 0;
    }
    GHL::SoundEffect* effect = 0;
    if (m_sound) {
        GHL::Data* data = decoder->GetAllSamples();
        if (data) {
            effect = m_sound->CreateEffect(decoder->GetSampleType(), decoder->GetFrequency(), data);
            data->Release();
        } else {
            GHL_Log(GHL::LOG_LEVEL_ERROR,"LoadEffect no data provided");
        }
    } else {
        GHL_Log(GHL::LOG_LEVEL_ERROR,"LoadEffect no sound");
    }
    decoder->Release();
    if (!effect) {
        GHL_Log(GHL::LOG_LEVEL_ERROR,"LoadEffect no create effect");
        return 0;
    }
    return effect;
}


void ApplicationBase::DrawImage(GHL::Texture* tex,int x,int y) {
    GHL::Vertex v[4];
    m_render->SetTexture(tex,0);
    v[0].x = x;
    v[0].y = y;
    v[0].tx = 0;
    v[0].ty = 0;
    
    v[1].x = x+tex->GetWidth();
    v[1].y = y;
    v[1].tx = 1;
    v[1].ty = 0;
    
    v[2].x = x+tex->GetWidth();
    v[2].y = y+tex->GetHeight();
    v[2].tx = 1;
    v[2].ty = 1;
    
    v[3].x = x;
    v[3].y = y+tex->GetHeight();
    v[3].tx = 0;
    v[3].ty = 1;
    
    for (size_t i=0;i<4;++i) {
        v[i].z = 0.0f;
        for (size_t j=0;j<4;++j) {
            v[i].color[j]=0xff;
        }
    }
    
    GHL::UInt16 idx[] = {0,1,2,2,3,0};
    m_render->DrawPrimitivesFromMemory(GHL::PRIMITIVE_TYPE_TRIANGLES,GHL::VERTEX_TYPE_SIMPLE,v,4,idx,2);
}