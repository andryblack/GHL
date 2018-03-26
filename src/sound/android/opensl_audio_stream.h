#ifndef OPENSL_AUDIO_STREAM_H_INCLUDED
#define OPENSL_AUDIO_STREAM_H_INCLUDED

#include "opensl_audio_channel.h"

namespace GHL {
    
    class OpenSLFileAudioStream : public OpenSLAudioChannelBase {
    private:
        SLMuteSoloItf m_mute_solo_i;
        SLSeekItf   m_seek_i;
        SLPrefetchStatusItf    m_prefetch_i;
        int m_fd;
    public:
        explicit OpenSLFileAudioStream( SLObjectItf player_obj, int fd );
        ~OpenSLFileAudioStream();
       
        void Play(bool loop);
        void Stop();
    };


    class OpenSLPCMAudioStream : public OpenSLAudioChannel {
    public:
        class Holder : public OpenSLAudioChannel::Holder {
        public:
            virtual void WriteData(OpenSLPCMAudioStream* self) = 0;
        };
        float   m_volume;
    private:
        static void callback(SLAndroidSimpleBufferQueueItf caller,void *pContext);
    public:
        OpenSLPCMAudioStream(SLObjectItf player_obj,const SLDataFormat_PCM& format);
        void Stop();
        void SetVolume(float vol);
        float GetVolume() const { return m_volume; }
    };


}

#endif /*OPENSL_AUDIO_STREAM_H_INCLUDED*/
