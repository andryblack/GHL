#include <ghl_application.h>
#include <ghl_settings.h>
#include <ghl_render.h>
#include <ghl_system.h>
#include "../common/application_base.h"

class Application : public ApplicationBase {
    private:
    public:
    Application() {
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
        return true;
    }
    ///
    virtual bool GHL_CALL OnFrame( GHL::UInt32 /*usecs*/ ) {
        m_render->BeginScene( 0 );
        m_render->Clear( 0, 1, 0, 0);
        m_render->EndScene();
        return true;
    }

};


#if defined( GHL_PLATFORM_WIN32 )
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
