#include "android_music_stream.h"

#include "../../ghl_log_impl.h"
#include "../ghl_sound_decoder.h"
#include <cassert>

/*static const char* MODULE = "snd"; */

namespace GHL {


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
         m_channel(channel),
         m_decoder(decoder)
    {
      
        channel->SetHolder(this);
    }

    AndroidDecodeMusic::~AndroidDecodeMusic() {
    	//LOG_INFO("~AndroidDecodeMusic >>>");
        if (m_channel) {
            m_channel->ResetHolder(this);
        }
        if (m_decoder) {
            m_decoder->Release();
        }
        //LOG_INFO("~AndroidDecodeMusic <<<");
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
            //LOG_INFO("AndroidDecodeMusic::Stop <<<");
            m_channel->Stop();
        }
    }
    /// pause
    void GHL_CALL AndroidDecodeMusic::Pause() {
        if (m_channel) {
            //LOG_INFO("AndroidDecodeMusic::Pause <<<");
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
        if (m_channel) {
            m_channel->Play(m_decoder,loop);
        }
    }


    void AndroidDecodeMusic::ResetChannel() {
        {
    	    m_channel = 0;
        }
    }

}