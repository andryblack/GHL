//
//  ghl_sound_cocoa.cpp
//  GHL
//
//  Created by Andrey Kunitsyn on 8/26/12.
//  Copyright (c) 2012 AndryBlack. All rights reserved.
//

#include "ghl_sound_cocoa.h"

namespace GHL {
    
    SoundCocoa::SoundCocoa() : m_openal(8) {
        
    }
    
    
    bool SoundCocoa::SoundInit() {
        if (!SoundImpl::SoundInit())
            return false;
        if (!m_openal.SoundInit())
            return false;
        return true;
    }
    
    bool SoundCocoa::SoundDone() {
        m_openal.SoundDone();
        return SoundImpl::SoundDone();
    }
    
    /// create sound effect from data
    SoundEffect* GHL_CALL SoundCocoa::CreateEffect( SampleType type, UInt32 freq, Data* data ) {
        return m_openal.CreateEffect(type, freq, data);
    }
    /// play effect
    void GHL_CALL SoundCocoa::PlayEffect( SoundEffect* effect , float vol, float pan, SoundInstance** instance ) {
        m_openal.PlayEffect(effect, vol, pan, instance);
    }
    
    /// open music
    MusicInstance* GHL_CALL SoundCocoa::OpenMusic( GHL::DataStream* file ) {
        return 0;
    }
}

GHL::SoundImpl* GHL_CreateSoundCocoa() {
    return new GHL::SoundCocoa();
}