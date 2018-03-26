#include "android_music_stream.h"

#include "../../ghl_log_impl.h"
#include "../ghl_sound_decoder.h"

static const char* MODULE = "snd";

namespace GHL {

	struct slock {
	    pthread_mutex_t& m;
	    slock(pthread_mutex_t& m) : m(m) {
	        pthread_mutex_lock(&m);
	    }
	    ~slock() {
	        pthread_mutex_unlock(&m);
	    }
	private:
		slock(const slock&);
		slock& operator = (const slock&);
	};

	static const size_t DECODE_SAMPLES_BUFFER = 1024;


	AndroidAssetMusic::AndroidAssetMusic(DataStream* ds,OpenSLFileAudioStream* stream) : m_stream(stream),m_ds(ds) {
        m_ds->AddRef();
    }
   	AndroidAssetMusic::~AndroidAssetMusic() {
        //LOG_INFO("~AndroidAssetMusic >>>");
        delete m_stream;
        m_ds->Release();
        //LOG_INFO("~AndroidAssetMusic <<<");
    }
    void GHL_CALL AndroidAssetMusic::Play( bool loop ) {
        m_stream->Play(loop);
    }
    void GHL_CALL AndroidAssetMusic::SetVolume( float volume ) {
        m_stream->SetVolume(volume);
    }
    void GHL_CALL AndroidAssetMusic::Stop() {
        //LOG_INFO("stop MusicInstance >>>");
        m_stream->Stop();
        //LOG_INFO("stop MusicInstance <<<");
    }
    void GHL_CALL AndroidAssetMusic::Pause() {
        m_stream->Pause();
    }
    void GHL_CALL AndroidAssetMusic::Resume() {
        m_stream->Resume();
    }
    void GHL_CALL AndroidAssetMusic::SetPan( float pan ) {
        m_stream->SetPan(pan);
    }
    void GHL_CALL AndroidAssetMusic::SetPitch( float pitch ) {
        m_stream->SetPitch(pitch);
    }

	

	AndroidDecodeMusic::AndroidDecodeMusic(OpenSLPCMAudioStream* channel,SoundDecoder* decoder) :
         m_refs(1),
         m_channel(channel),
         m_decoder(decoder),
         m_loop(false) {
         
        pthread_mutex_init(&m_mutex,0);
        pthread_mutex_init(&m_decoder_lock,0);

        channel->SetHolder(this);
        m_decode_buffer = (Byte*)::malloc(DECODE_SAMPLES_BUFFER*SoundDecoderBase::GetBps(m_decoder->GetSampleType()));
    }

    AndroidDecodeMusic::~AndroidDecodeMusic() {
    	//LOG_INFO("~AndroidDecodeMusic >>>");
        if (m_channel) {
            m_channel->ResetHolder(this);
        }
        if (m_decoder) {
            m_decoder->Release();
        }
        if (m_decode_buffer) {
            ::free(m_decode_buffer);
        }
        pthread_mutex_destroy(&m_mutex);
        pthread_mutex_destroy(&m_decoder_lock);
        //LOG_INFO("~AndroidDecodeMusic <<<");
    }



	void GHL_CALL AndroidDecodeMusic::AddRef() const {
		slock l(m_mutex);
        ++m_refs;
    }
        
    void GHL_CALL AndroidDecodeMusic::Release() const {
    	slock l(m_mutex);
        if (m_refs==0) {
            ::GHL::LoggerImpl(::GHL::LOG_LEVEL_ERROR,"REFS") << "release released object" ;
        } else {
            m_refs--;
        }
    }

     /// set volume (0-100)
    void GHL_CALL AndroidDecodeMusic::SetVolume( float vol ) {
        if (m_channel) {
            m_channel->SetVolume(vol);
        }
    }
    /// set pan (-100..0..+100)
    void GHL_CALL AndroidDecodeMusic::SetPan( float pan ) {
        if (m_channel) {
            m_channel->SetPan(pan);
        }
    }
    /// set pitch
    void GHL_CALL AndroidDecodeMusic::SetPitch( float pitch ) {
        if (m_channel) {
            m_channel->SetPitch(pitch);
        }
    }
    /// stop
    void GHL_CALL AndroidDecodeMusic::Stop() {
        if (m_channel) {
            m_channel->Stop();
        }
    }
    /// pause
    void GHL_CALL AndroidDecodeMusic::Pause() {
        if (m_channel) {
            m_channel->Pause();
        }
    }
    /// resume
    void GHL_CALL AndroidDecodeMusic::Resume() {
        if (m_channel) {
            m_channel->Resume();
        }
    }
    /// play
    void GHL_CALL AndroidDecodeMusic::Play( bool loop ) {
        m_loop = loop;
        if (m_channel) {
        	if (m_decoder) {
        		slock l(m_decoder_lock);
        		m_decoder->Reset();
        	}
        	ProcessDecode(m_channel);
            m_channel->Play();
        }
    }


    void AndroidDecodeMusic::ResetChannel() {
    	slock l(m_mutex);
        m_channel = 0;
    }

    void AndroidDecodeMusic::WriteData(OpenSLPCMAudioStream* channel) {
        if (!ProcessDecode(channel)) {
            channel->Stop();
        }
    }

    bool AndroidDecodeMusic::ProcessDecode(OpenSLPCMAudioStream* channel) {
    	{
    		slock l(m_mutex);
	        if (!m_decoder) return false;
	        if (!m_channel) return false;
	        if (!m_decode_buffer) return false;
	    }
	  	AddRef();
	 
	 	slock l(m_decoder_lock);

        UInt32 samples = m_decoder->ReadSamples(DECODE_SAMPLES_BUFFER,m_decode_buffer);
        if (!samples) {
            if (m_loop) {
                m_decoder->Reset();
                samples = m_decoder->ReadSamples(DECODE_SAMPLES_BUFFER,m_decode_buffer);
                if (!samples) {
                	Release();
                    return false;
                }
            } else {
                Release();
                return false;
            }
        }
        channel->EnqueueData(m_decode_buffer,samples*SoundDecoderBase::GetBps(m_decoder->GetSampleType()));
        {
        	Release();
        	return true;
        }
        return true;
    }

    bool AndroidDecodeMusic::NeedDestroy() {
    	slock l(m_mutex);
        return m_refs == 0;
    }
}