#ifndef GHL_SOUND_ANDROID_H_INCLUDED
#define GHL_SOUND_ANDROID_H_INCLUDED

#include "../ghl_sound_impl.h"

#include "opensl_audio_engine.h"
#include <map>
#include <list>

namespace GHL {
    
    
    class AndroidDecodeMusic;
    class SoundAndroid : public SoundImpl {
    private:
        OpenSLAudioEngine*   m_opensl_engine;
        bool    m_use_decoder;
    public:
        SoundAndroid();
        ~SoundAndroid();
        
        bool SoundInit(int android_os_version);
        bool SoundDone();
        
        void SetFocus(bool focus);
        void Process();
        
        /// create sound effect from data
        virtual SoundEffect* GHL_CALL CreateEffect( SampleType type, UInt32 freq, Data* data );
        /// play effect
        virtual void GHL_CALL PlayEffect( SoundEffect* effect , float vol, float pan, SoundInstance** instance );
        /// open music
        virtual MusicInstance* GHL_CALL OpenMusic( GHL::DataStream* file ) ;
    };
}

#endif /*GHL_SOUND_ANDROID_H_INCLUDED*/
