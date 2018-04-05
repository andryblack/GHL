//
//  ghl_sound_cocoa.h
//  GHL
//
//  Created by Andrey Kunitsyn on 8/26/12.
//  Copyright (c) 2012 AndryBlack. All rights reserved.
//

#ifndef __GHL__ghl_sound_cocoa__
#define __GHL__ghl_sound_cocoa__

#include "../ghl_sound_impl.h"
#ifdef GHL_USE_AVAUDIOENGINE
#include "audio_engine.h"
#else
#include "../openal/ghl_sound_openal.h"
#endif

namespace GHL {
    
    
    
    class SoundCocoa : public SoundImpl {
    private:
#ifdef GHL_USE_AVAUDIOENGINE
        SoundAudioEngine m_effects;
#else
        SoundOpenAL m_effects;
#endif
    public:
        SoundCocoa();
        bool SoundInit();
        bool SoundDone();
        
        void Resume();
        void Suspend();
        
        /// create sound effect from data
        virtual SoundEffect* GHL_CALL CreateEffect( SampleType type, UInt32 freq, Data* data );
        /// play effect
        virtual void GHL_CALL PlayEffect( SoundEffect* effect , float vol, float pan, SoundInstance** instance );
        /// open music
        virtual MusicInstance* GHL_CALL OpenMusic( GHL::DataStream* file ) ;
    };
    
}

GHL::SoundCocoa* GHL_CreateSoundCocoa();

#endif /* defined(__GHL__ghl_sound_cocoa__) */
