#ifndef OPENSL_AUDIO_CHANNEL_H_INCLUDED
#define OPENSL_AUDIO_CHANNEL_H_INCLUDED

#include <SLES/OpenSLES.h>
#include <SLES/OpenSLES_Android.h>

#include <string.h>

namespace GHL {
    
    class OpenSLAudioChannelBase {
    protected:
        SLObjectItf m_player_obj;
        SLPlayItf   m_play_i;
        SLVolumeItf m_volume_i;
        OpenSLAudioChannelBase(SLObjectItf player_obj);
        virtual ~OpenSLAudioChannelBase();
        float   m_pan_value;
    public:
        void Play();
        void Stop();
        void SetVolume(float vol);
        void SetPan(float pan);
    };
    
    class OpenSLAudioChannel : public OpenSLAudioChannelBase {
    public:
        class Holder {
        public:
            virtual void ResetChannel() = 0;
        };
    private:
        SLDataFormat_PCM    m_format;
        SLBufferQueueItf    m_buffer_queue;
        Holder*     m_holder;
        void Clear();
        size_t  m_last_used;
    public:
        OpenSLAudioChannel(SLObjectItf player_obj,const SLDataFormat_PCM& format);
        ~OpenSLAudioChannel();
        
        const SLDataFormat_PCM& GetFormat() const { return m_format; }
        size_t GetLastUsed() const { return m_last_used; }
        void UpdateLastUsed();
        bool IsStopped();
        void PutData(const void* data,size_t size);
        
        void ResetHolder(Holder* holder);
        void SetHolder(Holder* holder);
    };
}

#endif /*JNI_AUDIO_TRACK_H_INCLUDED*/
