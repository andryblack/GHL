#include "texture_stage3d.h"
#include "../../ghl_log_impl.h"

namespace GHL {
    
    static const char* MODULE = "Stage3dTextre";
    
    TextureStage3d::TextureStage3d(const AS3::ui::flash::display3D::textures::Texture& tex,RenderStage3d* parent,UInt32 w,UInt32 h) : TextureImpl(parent,w,h),m_tex(tex),m_have_mipmaps(false) {
        
    }
    
    TextureStage3d::~TextureStage3d() {
        
    }
    
    void GHL_CALL TextureStage3d::SetData(UInt32 x,UInt32 y,const Image* data,UInt32 level) {
        if (data && data->GetWidth()==GetWidth() && data->GetHeight()==GetHeight()) {
            Image* img = data->Clone();
            img->Convert(IMAGE_FORMAT_RGBA);
            img->SwapRB();
            const Data* dt = img->GetData();
            
            m_tex->uploadFromByteArray( AS3::ui::internal::get_ram(), (int)dt->GetData(),0 );
            img->Release();
        } else {
            LOG_ERROR("unimplemented set partial data");
        }
    }
    
    void GHL_CALL TextureStage3d::GenerateMipmaps() {
        
    }
    
    
}