#include "application_base.h"
#include <ghl_system.h>
#include <ghl_render.h>
#include <ghl_vfs.h>
#include <ghl_data_stream.h>
#include <ghl_data.h>
#include <ghl_image_decoder.h>
#include <ghl_image.h>
#include <ghl_log.h>
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
void GHL_CALL ApplicationBase::OnKeyDown( GHL::Key key ) {
    if (key==GHL::KEY_ESCAPE) {
        m_system->Exit();
    } else if (key==GHL::KEY_ENTER) {
        if (m_system->GetKeyMods()&GHL::KEYMOD_ALT) {
            m_system->SwitchFullscreen(!m_system->IsFullscreen());
        }
    }
}
///
void GHL_CALL ApplicationBase::OnKeyUp( GHL::Key /*key*/ ) {
}
///
void GHL_CALL ApplicationBase::OnChar( GHL::UInt32 /*ch*/ ) {
}
///
void GHL_CALL ApplicationBase::OnMouseDown( GHL::MouseButton /*btn*/, GHL::Int32 x, GHL::Int32 y) {
    m_mouse_pos_x = x;
    m_mouse_pos_y = y;
}
///
void GHL_CALL ApplicationBase::OnMouseMove( GHL::MouseButton /*btn*/, GHL::Int32 x, GHL::Int32 y) {
    m_mouse_pos_x = x;
    m_mouse_pos_y = y;
}
///
void GHL_CALL ApplicationBase::OnMouseUp( GHL::MouseButton /*btn*/, GHL::Int32 x, GHL::Int32 y) {
    m_mouse_pos_x = x;
    m_mouse_pos_y = y;
}
///
void GHL_CALL ApplicationBase::OnDeactivated() {

}
///
void GHL_CALL ApplicationBase::OnActivated() {

}
///
void GHL_CALL ApplicationBase::Release(  ) {
    delete this;
}

void ApplicationBase::DrawScene() {
    m_render->Clear( 0.0f, 0.0f, 0.0f, 0);
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
    m_render->BeginScene( 0 );
    float w = float(m_render->GetWidth());
    float h = float(m_render->GetHeight());

    float projectionOrtho[16];
    std::fill(projectionOrtho,projectionOrtho+16,0.0f);
    projectionOrtho[0+0*4] = (2.0f / (w - 0.0f));
    projectionOrtho[1+1*4] = (2.0f / (0.0f - h));
    projectionOrtho[2+2*4] = (-2.0f / (1.0f - -1.0f));
    projectionOrtho[0+3*4] = -(w + 0.0f) / (w - 0.0f);
    projectionOrtho[1+3*4] = -(0.0f + h) / (0.0f - h);
    projectionOrtho[2+3*4] = -(1.0f + -1.0f) / (1.0f - -1.0f);
    projectionOrtho[3+3*4] = 1.0f;


    static const float identity[4][4] = {
        { 1.0f, 0.0f, 0.0f, 0.0f },
        { 0.0f, 1.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 1.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f, 1.0f }
    };
    m_render->SetProjectionMatrix(&projectionOrtho[0]);
    m_render->SetViewMatrix(&identity[0][0]);
    DrawScene();
    std::stringstream ss;
    ss << "fps: " << m_fps;
    m_render->DebugDrawText(20,20,ss.str().c_str());
    m_render->EndScene();
    ++m_frames;
    return true;
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
                                      img->GetData());
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
        }
        data->Release();
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