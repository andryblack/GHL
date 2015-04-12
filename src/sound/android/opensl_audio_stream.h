#ifndef OPENSL_AUDIO_STREAM_H_INCLUDED
#define OPENSL_AUDIO_STREAM_H_INCLUDED

#include "opensl_audio_channel.h"

namespace GHL {
    
    class OpenSLAudioStream : public OpenSLAudioChannelBase {
    private:
        SLMuteSoloItf m_mute_solo_i;
        SLSeekItf   m_seek_i;
        
    public:
        explicit OpenSLAudioStream( SLObjectItf player_obj );
        ~OpenSLAudioStream();
       
        void Play(bool loop);
        void Pause();
        void Resume();
    };
    
}

#endif /*OPENSL_AUDIO_STREAM_H_INCLUDED*/
