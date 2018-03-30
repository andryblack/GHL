#include "opensl_audio_stream.h"
#include "../../ghl_log_impl.h"
#include "../ghl_sound_decoder.h"

#include <assert.h>
#include <math.h>
#include <unistd.h>

namespace GHL {
    
    static const char* MODULE = "OpenSL";
    static const size_t DECODE_SAMPLES_BUFFER = 1024;

    
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
        OpenSLAudioChannelBase( player_obj ), m_format(format), m_holder(0),m_volume(0.0f) {
        pthread_mutex_init(&m_mutex,0);
        m_buffer_queue = 0;
        m_decoder = 0;
        SLresult result = (*player_obj)->GetInterface(player_obj,       SL_IID_ANDROIDSIMPLEBUFFERQUEUE, &m_buffer_queue);
        assert(SL_RESULT_SUCCESS == result);
        assert(m_buffer_queue);
        if (m_buffer_queue) {
            (*m_buffer_queue)->RegisterCallback(m_buffer_queue,
                &OpenSLPCMAudioStream::callback,this);
        }
        m_decode_buffer = static_cast<GHL::Byte*>( ::malloc( DECODE_SAMPLES_BUFFER*m_format.numChannels*m_format.containerSize/8 ) );
    }

    OpenSLPCMAudioStream::~OpenSLPCMAudioStream() {
        ResetHolder(0);
        Destroy();
        if (m_decode_buffer) {
            ::free(m_decode_buffer);
        }
        if (m_decoder) {
            pthread_mutex_lock(&m_mutex);
            m_decoder->Release();
            m_decoder = 0;
            pthread_mutex_unlock(&m_mutex);
        }
        pthread_mutex_destroy(&m_mutex);
    }

    void OpenSLPCMAudioStream::callback(SLAndroidSimpleBufferQueueItf caller,void *pContext) {
        //LOG_INFO("audio callback");
        OpenSLPCMAudioStream* self = static_cast<OpenSLPCMAudioStream*>(pContext);
        pthread_mutex_lock(&self->m_mutex);
        SoundDecoder* decoder = self->m_decoder;
        if (decoder) {
            if (!self->WriteData()) {
                self->ResetDecoder();
            }
        }
        pthread_mutex_unlock(&self->m_mutex);
    }

    void OpenSLPCMAudioStream::ResetDecoder() {
        if (m_decoder) {
            m_decoder->Release();
            m_decoder = 0;
        }
    }

    void OpenSLPCMAudioStream::Play(SoundDecoder* decoder,bool loop) {
        pthread_mutex_lock(&m_mutex);
        ResetDecoder();
        Stop();
        m_loop = loop;
        m_decoder = decoder;
        m_decoder->AddRef();
        if (!WriteData()) {
            ResetDecoder();
        }
        pthread_mutex_unlock(&m_mutex);
        OpenSLAudioChannelBase::Play();
    }

    bool OpenSLPCMAudioStream::WriteData() {
        if (!m_decoder) return false;
        UInt32 samples = m_decoder->ReadSamples(DECODE_SAMPLES_BUFFER,m_decode_buffer);
        if (!samples) {
            if (m_loop) {
                m_decoder->Reset();
                samples = m_decoder->ReadSamples(DECODE_SAMPLES_BUFFER,m_decode_buffer);
                if (!samples) {
                    return false;
                }
            } else {
                return false;
            }
        }
        EnqueueData(m_decode_buffer,samples*SoundDecoderBase::GetBps(m_decoder->GetSampleType()));
        return true;
    }

    void OpenSLPCMAudioStream::Stop() {
        OpenSLAudioChannelBase::Stop();
        if (m_buffer_queue) {
            (*m_buffer_queue)->Clear(m_buffer_queue);
        }
    }

    void OpenSLPCMAudioStream::SetVolume(float vol) {
        m_volume = vol;
        OpenSLAudioChannelBase::SetVolume(vol);
    }


    void OpenSLPCMAudioStream::ResetHolder(Holder* holder) {
        assert(holder == 0 || m_holder == holder);
        if (m_holder) {
            m_holder->ResetChannel();
        }
        m_holder = 0;
    }
    void OpenSLPCMAudioStream::SetHolder(Holder* holder) {
        if (m_holder && m_holder!=holder) {
            m_holder->ResetChannel();
        }
        m_holder = holder;
    }

    void OpenSLPCMAudioStream::EnqueueData(const void* data,size_t size) {
        if (!m_buffer_queue)
            return;
        (*m_buffer_queue)->Enqueue(m_buffer_queue, data , size);
    }
    void OpenSLPCMAudioStream::ClearData() {
        if (!m_buffer_queue)
            return;
        (*m_buffer_queue)->Clear(m_buffer_queue);
    }
    
}