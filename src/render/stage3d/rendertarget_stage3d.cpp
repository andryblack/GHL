#include "rendertarget_stage3d.h"
#include "../../ghl_log_impl.h"

namespace GHL {
    
    static const char* MODULE = "Stage3dRT";
    
    RenderTargetStage3d::RenderTargetStage3d(TextureStage3d* texture,RenderStage3d* parent,bool have_depth) : RenderTargetImpl(parent),m_texture(texture),m_have_depth(have_depth) {
    }
    
    RenderTargetStage3d::~RenderTargetStage3d() {
        m_texture->Release();
    }
    
    void RenderTargetStage3d::BeginScene( RenderImpl* render ) {
        
    }
    
    void RenderTargetStage3d::EndScene( RenderImpl* render ) {
        
    }
    
    
    void GHL_CALL RenderTargetStage3d::GetPixels(UInt32 x,UInt32 y,UInt32 w,UInt32 h,Byte* data) {
        
    }
}