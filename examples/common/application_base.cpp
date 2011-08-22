#include "application_base.h"
#include <ghl_system.h>


ApplicationBase::ApplicationBase() : m_system(0), m_vfs(0),m_render(0),m_image_decoder(0),m_sound(0) {
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
void GHL_CALL ApplicationBase::OnKeyUp( GHL::Key key ) {
}
///
void GHL_CALL ApplicationBase::OnChar( GHL::UInt32 ch ) {
}
///
void GHL_CALL ApplicationBase::OnMouseDown( GHL::MouseButton btn, GHL::Int32 x, GHL::Int32 y) {
}
///
void GHL_CALL ApplicationBase::OnMouseMove( GHL::MouseButton btn, GHL::Int32 x, GHL::Int32 y) {
}
///
void GHL_CALL ApplicationBase::OnMouseUp( GHL::MouseButton btn, GHL::Int32 x, GHL::Int32 y) {
}
///
void GHL_CALL ApplicationBase::OnDeactivated() {

}
///
void GHL_CALL ApplicationBase::OnActivated() {

}
///
void GHL_CALL ApplicationBase::Release(  ) {

}
