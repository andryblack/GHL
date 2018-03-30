#ifndef _ANDROID_MUSIC_STREAM_
#define _ANDROID_MUSIC_STREAM_

#include "opensl_audio_stream.h"
#include "ghl_data_stream.h"
#include "../../ghl_ref_counter_impl.h"

#include <pthread.h>

namespace GHL {

	class AndroidAssetMusic : public RefCounterImpl<MusicInstance> {
    private:
        OpenSLFileAudioStream*  m_stream;
        DataStream* m_ds;
    public:
        explicit AndroidAssetMusic(DataStream* ds,OpenSLFileAudioStream* stream);
        ~AndroidAssetMusic();
        virtual void GHL_CALL Play( bool loop );
        virtual void GHL_CALL SetVolume( float volume );
        virtual void GHL_CALL Stop();
        virtual void GHL_CALL Pause();
        virtual void GHL_CALL Resume();
        virtual void GHL_CALL SetPan( float pan );
        virtual void GHL_CALL SetPitch( float pitch );
    };

    class AndroidDecodeMusic : public RefCounterImpl<MusicInstance>, public OpenSLPCMAudioStream::Holder { 
    private:
        mutable UInt32 m_refs;
        OpenSLPCMAudioStream* m_channel;
        SoundDecoder* m_decoder;
    public:
        AndroidDecodeMusic(OpenSLPCMAudioStream* channel,SoundDecoder* decoder);
        ~AndroidDecodeMusic();

        // holde
        virtual void ResetChannel();
        
        virtual void GHL_CALL SetVolume( float vol );
        virtual void GHL_CALL SetPan( float pan );
        virtual void GHL_CALL SetPitch( float pitch );
        virtual void GHL_CALL Stop();
        virtual void GHL_CALL Pause();
        virtual void GHL_CALL Resume();
        virtual void GHL_CALL Play( bool loop );

    };
}

#endif /*_ANDROID_MUSIC_STREAM_*/