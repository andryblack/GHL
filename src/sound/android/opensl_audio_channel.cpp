#include "opensl_audio_channel.h"
#include "../../ghl_log_impl.h"
#include <assert.h>
#include <math.h>

namespace GHL {
    
    static const char* MODULE = "OpenSL";
    
    OpenSLAudioChannelBase::OpenSLAudioChannelBase( SLObjectItf player_obj ) : m_player_obj(player_obj)
    , m_play_i(0)
    , m_volume_i(0)
    {
        SLresult result;
        
        // get the play interface
        result = (*m_player_obj)->GetInterface(m_player_obj, SL_IID_PLAY, &m_play_i);
        assert(SL_RESULT_SUCCESS == result);
        
        // get the volume interface
        result = (*m_player_obj)->GetInterface(m_player_obj, SL_IID_VOLUME, &m_volume_i);
        assert(SL_RESULT_SUCCESS == result);
        
    }

    OpenSLAudioChannelBase::~OpenSLAudioChannelBase() {
        if (m_player_obj) {
            (*m_player_obj)->Destroy(m_player_obj);
        }
    }
    
    void OpenSLAudioChannelBase::Play() {
        if (m_play_i) {
            if ((*m_play_i)->SetPlayState(m_play_i, SL_PLAYSTATE_PLAYING) != SL_RESULT_SUCCESS) {
                LOG_ERROR("failed SetPlayState(SL_PLAYSTATE_PLAYING)");
            }
        }
    }
    void OpenSLAudioChannelBase::Stop() {
        if (m_play_i) {
            if ((*m_play_i)->SetPlayState(m_play_i, SL_PLAYSTATE_STOPPED) != SL_RESULT_SUCCESS) {
                LOG_ERROR("failed SetPlayState(SL_PLAYSTATE_STOPPED)");
            }
        }
    }
    
    void OpenSLAudioChannelBase::SetVolume(float volume) {
        if (m_volume_i) {
            SLmillibel volume_mb;
            if (volume >= 100.0f)
                (*m_volume_i)->GetMaxVolumeLevel(m_volume_i, &volume_mb);
            else if (volume <= 0.02f)
                volume_mb = SL_MILLIBEL_MIN;
            else {
                volume_mb = M_LN2 / log(100.0f / (100.0f - volume)) * -1000.0f;
                if (volume_mb > 0)
                    volume_mb = SL_MILLIBEL_MIN;
            }
            (*m_volume_i)->SetVolumeLevel(m_volume_i, volume_mb);
        }
    }
    void OpenSLAudioChannelBase::SetPan(float pan) {
        
    }
    
    OpenSLAudioChannel::OpenSLAudioChannel( SLObjectItf player_obj ,const SLDataFormat_PCM& format) : OpenSLAudioChannelBase( player_obj ),
    m_format(format),m_buffer_queue(0), m_holder(0) {
        SLresult result = (*player_obj)->GetInterface(player_obj,       SL_IID_ANDROIDSIMPLEBUFFERQUEUE, &m_buffer_queue);
        assert(SL_RESULT_SUCCESS == result);
    }
    
    OpenSLAudioChannel::~OpenSLAudioChannel() {
        Clear();
    }
    
    void OpenSLAudioChannel::Clear() {
        if (m_holder) {
            m_holder->ResetChannel();
            m_holder = 0;
        }
    }
    
    void OpenSLAudioChannel::SetHolder(Holder* h) {
        if (m_holder) {
            m_holder->ResetChannel();
        }
        m_holder = h;
    }
    
    void OpenSLAudioChannel::UpdateLastUsed() {
        m_last_used = time(0);
    }
    bool OpenSLAudioChannel::IsStopped() {
        if (m_play_i) {
            SLuint32 state;
            if ( (*m_play_i)->GetPlayState(m_play_i, &state) == SL_RESULT_SUCCESS) {
                return state != SL_PLAYSTATE_PLAYING;
            }
        }
        return false;
    }
    void OpenSLAudioChannel::PutData(const void* data,size_t size) {
        if (!m_buffer_queue)
            return;
        (*m_buffer_queue)->Clear(m_buffer_queue);
        (*m_buffer_queue)->Enqueue(m_buffer_queue, data , size);
    }
}