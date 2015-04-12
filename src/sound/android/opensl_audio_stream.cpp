#include "opensl_audio_stream.h"
#include "../../ghl_log_impl.h"
#include <assert.h>
#include <math.h>

namespace GHL {
    
    static const char* MODULE = "OpenSL";
    
    OpenSLAudioStream::OpenSLAudioStream( SLObjectItf player_obj ) : OpenSLAudioChannelBase( player_obj)
    , m_mute_solo_i(0)
    , m_seek_i(0)
    {
        SLresult result;
        
        // get the mute/solo interface
        result = (*m_player_obj)->GetInterface(m_player_obj, SL_IID_MUTESOLO, &m_mute_solo_i);
        assert(SL_RESULT_SUCCESS == result);
        
        
        // get the seek interface
        result = (*m_player_obj)->GetInterface(m_player_obj, SL_IID_SEEK, &m_seek_i);
        assert(SL_RESULT_SUCCESS == result);

    }
    
    OpenSLAudioStream::~OpenSLAudioStream() {
        Stop();
    }

    void OpenSLAudioStream::Play(bool loop) {
        if (m_seek_i) {
            if ((*m_seek_i)->SetLoop(m_seek_i,loop?SL_BOOLEAN_TRUE:SL_BOOLEAN_FALSE,0,SL_TIME_UNKNOWN)!=SL_RESULT_SUCCESS) {
                LOG_ERROR("failed SetLoop");
            }
        }
        OpenSLAudioChannelBase::Play();
    }
    
    void OpenSLAudioStream::Pause() {
        if (m_play_i) {
            if ((*m_play_i)->SetPlayState(m_play_i, SL_PLAYSTATE_PAUSED) != SL_RESULT_SUCCESS) {
                LOG_ERROR("failed SetPlayState(SL_PLAYSTATE_PAUSED)");
            }
        }
    }
    void OpenSLAudioStream::Resume() {
        if (m_play_i) {
            if ((*m_play_i)->SetPlayState(m_play_i, SL_PLAYSTATE_PLAYING) != SL_RESULT_SUCCESS) {
                LOG_ERROR("failed SetPlayState(SL_PLAYSTATE_PLAYING)");
            }
        }
    }
    
}