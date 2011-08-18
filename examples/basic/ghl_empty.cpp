#include <ghl_application.h>
#include <ghl_settings.h>
#include <ghl_render.h>
#include "../common/application_base.h"

class Application : public ApplicationBase {
    private:
    public:
	Application() {
	}
	
	///
	virtual void GHL_CALL FillSettings( GHL::Settings* settings ) {
	
	}
	///
	virtual bool GHL_CALL Load() {
	    return true;
	}
	///
	virtual bool GHL_CALL OnFrame( GHL::UInt32 usecs ) {
	    m_render->BeginScene( 0 );
	    m_render->Clear( 0, 1, 0, 0);
	    m_render->EndScene();
	    return true;
	}
};


#ifdef GHL_WIN32
#else
int main(int argc,char* argv[]) {
    Application app;
    GHL_StartApplication(&app,argc,argv);
    return 0;
}
#endif