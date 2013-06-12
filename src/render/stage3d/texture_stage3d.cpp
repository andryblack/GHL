#include "texture_stage3d.h"
#include "../../ghl_log_impl.h"

namespace GHL {
    
    static const char* MODULE = "Stage3dTextre";
    
    TextureStage3d::TextureStage3d(const AS3::ui::flash::display3D::textures::Texture& tex,RenderStage3d* parent,UInt32 w,UInt32 h) : TextureImpl(parent,w,h),m_tex(tex),m_have_mipmaps(false),m_internal_data(0) {
        
    }
    
    TextureStage3d::~TextureStage3d() {
        if (m_internal_data) {
            m_internal_data->Release();
        }
    }
    
    void GHL_CALL TextureStage3d::SetData(UInt32 x,UInt32 y,const Image* data,UInt32 level) {
        if (data && (x==0) && (y==0) &&
            (data->GetWidth()==GetWidth()) &&
            (data->GetHeight()==GetHeight())) {
            
            
            Image* img = data->Clone();
            img->Convert(IMAGE_FORMAT_RGBA);
            img->SwapRB();
            
            if (m_internal_data) {
                m_internal_data->Release();
            }
            
            m_internal_data = img;
            
        } else {
            if (!m_internal_data) {
                m_internal_data = GHL_CreateImage(GetWidth(),GetHeight(),IMAGE_FORMAT_RGBA);
            }
            
            Image* img = data->Clone();
            img->Convert(IMAGE_FORMAT_RGBA);
            img->SwapRB();
            m_internal_data->Draw(x,y,img);
            img->Release();

        }
        NotifySetData();
    }
    
    void GHL_CALL TextureStage3d::GenerateMipmaps() {
        
    }
    
    /// flush internal data to texture
    void GHL_CALL TextureStage3d::FlushInternal() {
        if (m_internal_data) {
            const Data* dt = m_internal_data->GetData();
            m_tex->uploadFromByteArray( AS3::ui::internal::get_ram(), (int)dt->GetData(),0 );
        }
        TextureImpl::FlushInternal();
    }
    /// discard internal data (flush if needed)
    void GHL_CALL TextureStage3d::DiscardInternal() {
        if (m_internal_data) {
            FlushInternal();
            m_internal_data->Release();
            m_internal_data = 0;
        }
    }

    
    
}