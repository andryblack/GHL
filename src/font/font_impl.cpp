#include "font_impl.h"

namespace GHL {
    
    
    FontImpl::FontImpl(const FontConfig& config) : m_name(config.name),m_config(config) {
        m_config.name = m_name.c_str();
    }
    
    const char* GHL_CALL FontImpl::GetName() const {
        return m_name.c_str();
    }
    float GHL_CALL FontImpl::GetSize() const {
        return m_config.size;
    }
    
    void FontImpl::set_name(const char *name) {
        m_name.assign(name);
        m_config.name = m_name.c_str();
    }
    
    void FontImpl::set_size(float s) {
        m_config.size = s;
    }
    
    bool FontImpl::is_emoji(UInt32 ch) const {
        
        return ((ch >= 0x2702) && (ch <= 0x27B0)) ||
                ((ch >= 0x2139) && (ch <= 0x3299)) ||
                ((ch >= 0x1F000) && (ch <= 0x1FA00));
    }
    
}
