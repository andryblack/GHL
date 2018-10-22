#ifndef OPENSL_AUDIO_STREAM_H_INCLUDED
#define OPENSL_AUDIO_STREAM_H_INCLUDED

#include "ghl_sound.h"
#include "opensl_audio_channel.h"
#include <pthread.h>

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


    class OpenSLPCMAudioStream : public OpenSLAudioChannelBase {
    public:
        SLDataFormat_PCM    m_format;
        SLAndroidSimpleBufferQueueItf    m_buffer_queue;
        class Holder {
        public:
            virtual void ResetChannel() = 0;
        };
        Holder* m_holder;
        float   m_volume;
        pthread_mutex_t m_mutex;
        SoundDecoder* m_decoder;
        Byte* m_decode_buffer;
        bool m_loop;
        bool WriteData();
        void ResetDecoder();
    private:
        static void callback(SLAndroidSimpleBufferQueueItf caller,void *pContext);
    public:
        OpenSLPCMAudioStream(SLObjectItf player_obj,const SLDataFormat_PCM& format);
        ~OpenSLPCMAudioStream();
        void Stop();
        void SetVolume(float vol);
        float GetVolume() const { return m_volume; }

        void ClearData();
        void EnqueueData(const void* data,size_t size);
        
        const SLDataFormat_PCM& GetFormat() const { return m_format; }
        
        // main thread
        void ResetHolder(Holder* holder);
        void SetHolder(Holder* holder);

        void Play(SoundDecoder* decoder,bool loop);
    };


}

#endif /*OPENSL_AUDIO_STREAM_H_INCLUDED*/
