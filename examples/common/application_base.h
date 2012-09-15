#ifndef APPLICATION_BASE_H
#define APPLICATION_BASE_H

#include <ghl_application.h>
#include <ghl_texture.h>
#include <ghl_sound.h>

class ApplicationBase : public GHL::Application {
protected:
	GHL::System*	m_system;
	GHL::VFS*	m_vfs;
	GHL::Render*	m_render;
	GHL::ImageDecoder*	m_image_decoder;
	GHL::Sound*	m_sound;
	ApplicationBase();
	virtual ~ApplicationBase();
    virtual void DrawScene();
    virtual void OnTimer(GHL::UInt32 usecs);

    GHL::Int32  m_mouse_pos_x;
    GHL::Int32  m_mouse_pos_y;

    GHL::UInt32 m_frames;
    GHL::UInt32 m_fps_time;
    float   m_fps;

    GHL::Texture* LoadTexture(const char* fn);
    GHL::SoundEffect*   LoadEffect( const char* fn);
public:
    	///
	virtual void GHL_CALL SetSystem( GHL::System* sys ) ;
	///
	virtual void GHL_CALL SetVFS( GHL::VFS* vfs ) ;
	///
	virtual void GHL_CALL SetRender( GHL::Render* render ) ;
	/// 
	virtual void GHL_CALL SetImageDecoder( GHL::ImageDecoder* decoder ) ;
	///
	virtual void GHL_CALL SetSound( GHL::Sound* sound) ;
	///
	virtual void GHL_CALL FillSettings( GHL::Settings* settings ) = 0;
    /// called after window created, before first rendered
    virtual void GHL_CALL Initialize() = 0;
	///
	virtual bool GHL_CALL Load() = 0;
	///
    virtual bool GHL_CALL OnFrame( GHL::UInt32 usecs );
	///
	virtual void GHL_CALL OnKeyDown( GHL::Key key ) ;
	///
	virtual void GHL_CALL OnKeyUp( GHL::Key key ) ;
	///
	virtual void GHL_CALL OnChar( GHL::UInt32 ch ) ;
	///
	virtual void GHL_CALL OnMouseDown( GHL::MouseButton btn, GHL::Int32 x, GHL::Int32 y) ;
	///
	virtual void GHL_CALL OnMouseMove( GHL::MouseButton btn, GHL::Int32 x, GHL::Int32 y) ;
	///
	virtual void GHL_CALL OnMouseUp( GHL::MouseButton btn, GHL::Int32 x, GHL::Int32 y) ;
	///
	virtual void GHL_CALL OnDeactivated() ;
	///
	virtual void GHL_CALL OnActivated() ;
	///
	virtual void GHL_CALL Release(  ) ;
};

#endif /*APPLICATION_BASE_H*/
