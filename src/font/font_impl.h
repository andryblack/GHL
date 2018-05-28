#ifndef FONT_IMPL_H
#define FONT_IMPL_H

#include "ghl_font.h"
#include "ghl_ref_counter_impl.h"
#include "ghl_system.h"

#include <string>

namespace GHL {
    
    class FontImpl : public RefCounterImpl<Font> {
    private:
        std::string m_name;
        FontConfig m_config;
    protected:
        void set_name(const char* name);
        void set_size(float s);
        const FontConfig& get_config() const { return m_config; }
        bool is_emoji(UInt32 ch) const;
    public:
        FontImpl( const FontConfig& config );
        
        virtual const char* GHL_CALL GetName() const;
        virtual float GHL_CALL GetSize() const;
    };
    
}

#endif /*FONT_IMPL_H*/
