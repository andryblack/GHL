#ifndef OPENSL_AUDIO_CHANNEL_H_INCLUDED
#define OPENSL_AUDIO_CHANNEL_H_INCLUDED

#include <SLES/OpenSLES.h>
#include <SLES/OpenSLES_Android.h>

#include <ghl_data.h>

#include <string.h>

namespace GHL {
    
    class OpenSLAudioChannelBase {
    protected:
        SLObjectItf m_player_obj;
        SLPlayItf   m_play_i;
        SLVolumeItf m_volume_i;
        SLPitchItf  m_pitch_i;
        SLPlaybackRateItf m_playback_rate_i;
        OpenSLAudioChannelBase(SLObjectItf player_obj);
        virtual ~OpenSLAudioChannelBase();
        float   m_pan_value;
        void Destroy();
    public:
        void Play();
        void Pause();
        void Resume();
        void Stop();
        void SetVolume(float vol);
        void SetPan(float pan);
        void SetPitch(float pitch);
        bool IsStopped();
    };
    
    class OpenSLAudioChannel : public OpenSLAudioChannelBase {
    public:
        class Holder {
        public:
            virtual void ResetChannel() = 0;
        };
    protected:
        SLDataFormat_PCM    m_format;
        SLAndroidSimpleBufferQueueItf    m_buffer_queue;
        Holder*     m_holder;
        void Clear();
        size_t  m_last_used;
        Data*       m_data;
    public:
        OpenSLAudioChannel(SLObjectItf player_obj,const SLDataFormat_PCM& format);
        ~OpenSLAudioChannel();
        
        const SLDataFormat_PCM& GetFormat() const { return m_format; }
        size_t GetLastUsed() const { return m_last_used; }
        void UpdateLastUsed();

        bool IsStopped();
        void PutData(Data* data);
        void EnqueueData(const void* data,size_t size);
        
        void ResetHolder(Holder* holder);
        void SetHolder(Holder* holder);
    };

    
}

#endif /*JNI_AUDIO_TRACK_H_INCLUDED*/
