#include "opensl_audio_channel.h"
#include "../../ghl_log_impl.h"
#include <assert.h>
#include <math.h>

namespace GHL {
    
    static const char* MODULE = "OpenSL";

    OpenSLAudioChannelBase::OpenSLAudioChannelBase( SLObjectItf player_obj ) : m_player_obj(player_obj)
    , m_play_i(0)
    , m_volume_i(0)
    , m_pitch_i(0)
    , m_pan_value(0.0f)
    {
        SLresult result;
        
        // get the play interface
        result = (*m_player_obj)->GetInterface(m_player_obj, SL_IID_PLAY, &m_play_i);
        assert(SL_RESULT_SUCCESS == result);
        
        // get the volume interface
        result = (*m_player_obj)->GetInterface(m_player_obj, SL_IID_VOLUME, &m_volume_i);
        assert(SL_RESULT_SUCCESS == result);

        // get the pitch interface
        result = (*m_player_obj)->GetInterface(m_player_obj, SL_IID_PITCH, &m_pitch_i);
        if (SL_RESULT_SUCCESS!=result) {
            LOG_DEBUG("failed GetInterface SL_IID_PITCH");
            m_pitch_i = 0;
        }
        if (m_pitch_i == 0) {
            result = (*m_player_obj)->GetInterface(m_player_obj, SL_IID_PLAYBACKRATE, &m_playback_rate_i);
            if (SL_RESULT_SUCCESS!=result) {
                LOG_DEBUG("failed GetInterface SL_IID_PLAYBACKRATE");
                m_playback_rate_i = 0;
            } else {
                result = (*m_playback_rate_i)->SetPropertyConstraints(m_playback_rate_i,
                    SL_RATEPROP_PITCHCORAUDIO);
                if (SL_RESULT_SUCCESS != result) {
                    LOG_DEBUG("failed SetPropertyConstraints SL_RATEPROP_PITCHCORAUDIO");
                }
            }
        }
        //sb_assert(SL_RESULT_SUCCESS == result);
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
    float OpenSLAudioChannelBase::GetVolume() const {
        if (m_volume_i) {
            SLmillibel volume_mb;
            (*m_volume_i)->GetVolumeLevel(m_volume_i, &volume_mb);
            float volume = 100.0f - 100.0f / exp(M_LN2/volume_mb * -1000.0f);
            return volume;
        }
        return 0;
    }

    void OpenSLAudioChannelBase::SetPan(float pan) {
        if (m_volume_i) {
            if ( m_pan_value != pan ) {
                if (m_pan_value == 0.0f) {
                    (*m_volume_i)->EnableStereoPosition(m_volume_i, SL_BOOLEAN_TRUE);
                } else if ( pan == 0.0f ) {
                    (*m_volume_i)->EnableStereoPosition(m_volume_i, SL_BOOLEAN_FALSE);
                }
                m_pan_value = pan;
                SLmillibel pv = pan / 100.0f * 1000.0f;
                (*m_volume_i)->SetStereoPosition(m_volume_i, pv);
            }
        }
    }
    void OpenSLAudioChannelBase::SetPitch(float pitch) {
        if (m_pitch_i) {
            SLpermille pv = pitch / 100.0f * 1000.0f;
            (*m_pitch_i)->SetPitch(m_pitch_i, pv);
        } else if (m_playback_rate_i) {
            SLpermille pv = pitch / 100.0f * 1000.0f;
            SLpermille minRate;
            SLpermille maxRate;
            SLpermille step;
            SLuint32 capa;
            (*m_playback_rate_i)->GetRateRange(m_playback_rate_i,0,&minRate,&maxRate,&step,&capa);
            if (pv<minRate) {
                pv = minRate;
            } else if (pv>maxRate) {
                pv = maxRate;
            }
            (*m_playback_rate_i)->SetRate(m_playback_rate_i, pv);
        }
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
    
    void OpenSLAudioChannel::ResetHolder(Holder* h) {
        if (h == m_holder) {
            m_holder = 0;
        }
    }
    
    void OpenSLAudioChannel::SetHolder(Holder* h) {
        if (m_holder) {
            m_holder->ResetChannel();
        }
        m_holder = h;
    }
    static size_t last_used = 0;
    
    void OpenSLAudioChannel::UpdateLastUsed() {
        m_last_used = last_used++;
    }
    bool OpenSLAudioChannel::IsStopped() {
        if (m_play_i) {
            SLresult res;
            SLAndroidSimpleBufferQueueState state = {0};
            res = (*m_buffer_queue)->GetState(m_buffer_queue, &state);
            if (res == SL_RESULT_SUCCESS && state.count == 0) {
                return true;
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
