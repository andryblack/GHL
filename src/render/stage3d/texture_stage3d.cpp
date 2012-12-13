#include "texture_stage3d.h"

namespace GHL {
    
    TextureStage3d::TextureStage3d(const AS3::ui::flash::display3D::textures::Texture& tex,RenderStage3d* parent,UInt32 w,UInt32 h) : TextureImpl(parent,w,h),m_tex(tex),m_have_mipmaps(false) {
        
    }
    
    TextureStage3d::~TextureStage3d() {
        
    }
    
    void GHL_CALL TextureStage3d::SetData(UInt32 x,UInt32 y,const Image* data,UInt32 level) {
        
    }
    
    void GHL_CALL TextureStage3d::GenerateMipmaps() {
        
    }
    
    
}