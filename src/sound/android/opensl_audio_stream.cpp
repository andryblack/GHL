#include "opensl_audio_stream.h"
#include "../../ghl_log_impl.h"
#include <assert.h>
#include <math.h>
#include <unistd.h>

namespace GHL {
    
    static const char* MODULE = "OpenSL";
    
    OpenSLFileAudioStream::OpenSLFileAudioStream( SLObjectItf player_obj, int fd ) : OpenSLAudioChannelBase( player_obj)
    , m_mute_solo_i(0)
    , m_seek_i(0)
    , m_prefetch_i(0)
    , m_fd(fd)
    {
        SLresult result;
        
        // get the mute/solo interface
        result = (*m_player_obj)->GetInterface(m_player_obj, SL_IID_MUTESOLO, &m_mute_solo_i);
        assert(SL_RESULT_SUCCESS == result);
        
        
        // get the seek interface
        result = (*m_player_obj)->GetInterface(m_player_obj, SL_IID_SEEK, &m_seek_i);
        assert(SL_RESULT_SUCCESS == result);

        result = (*m_player_obj)->GetInterface(player_obj, SL_IID_PREFETCHSTATUS, &m_prefetch_i);
        if (result != SL_RESULT_SUCCESS) {
            LOG_ERROR("failed get prefetch status interface");
            m_prefetch_i = 0;
        }

    }
    
    OpenSLFileAudioStream::~OpenSLFileAudioStream() {
        //LOG_INFO("~OpenSLFileAudioStream >>>>");
        if (m_seek_i) {
            if ((*m_seek_i)->SetLoop(m_seek_i,SL_BOOLEAN_FALSE,0,SL_TIME_UNKNOWN)!=SL_RESULT_SUCCESS) {
                LOG_ERROR("failed reset SetLoop");
            }
        }
        Stop();
        if (m_prefetch_i) {
            SLuint32 status;
            if ((*m_prefetch_i)->GetPrefetchStatus(m_prefetch_i,&status) == SL_RESULT_SUCCESS) {
                LOG_INFO("prefetch status: " << status );
            }
        }
        ::close(m_fd);
        Destroy();
        //LOG_INFO("~OpenSLAudioStream <<<<");
    }

    void OpenSLFileAudioStream::Play(bool loop) {
        if (m_seek_i) {
            if ((*m_seek_i)->SetLoop(m_seek_i,loop?SL_BOOLEAN_TRUE:SL_BOOLEAN_FALSE,0,SL_TIME_UNKNOWN)!=SL_RESULT_SUCCESS) {
                LOG_ERROR("failed SetLoop");
            }
        }
        OpenSLAudioChannelBase::Play();
    }
    
    void OpenSLFileAudioStream::Stop() {
        OpenSLAudioChannelBase::Stop();
    }
    

     OpenSLPCMAudioStream::OpenSLPCMAudioStream(SLObjectItf player_obj,const SLDataFormat_PCM& format) : 
        OpenSLAudioChannel( player_obj, format) {
        m_volume = 100;
        if (m_buffer_queue) {
            (*m_buffer_queue)->RegisterCallback(m_buffer_queue,
                &OpenSLPCMAudioStream::callback,this);
        }
    }

    void OpenSLPCMAudioStream::callback(SLAndroidSimpleBufferQueueItf caller,void *pContext) {
        //LOG_INFO("audio callback");
        OpenSLPCMAudioStream* self = static_cast<OpenSLPCMAudioStream*>(pContext);
        if (self->m_holder) {
            static_cast<OpenSLPCMAudioStream::Holder*>(self->m_holder)->WriteData(self);
        }
    }

    void OpenSLPCMAudioStream::Stop() {
        OpenSLAudioChannel::Stop();
        if (m_buffer_queue) {
            (*m_buffer_queue)->Clear(m_buffer_queue);
        }
    }

    void OpenSLPCMAudioStream::SetVolume(float vol) {
        OpenSLAudioChannel::SetVolume(vol);
        m_volume = vol;
    }



    
}