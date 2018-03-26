#ifndef _ANDROID_MUSIC_STREAM_
#define _ANDROID_MUSIC_STREAM_

#include "opensl_audio_stream.h"
#include "ghl_data_stream.h"
#include "ghl_sound.h"
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

    class AndroidDecodeMusic : public MusicInstance, public OpenSLPCMAudioStream::Holder { 
    private:
        mutable UInt32 m_refs;
        OpenSLPCMAudioStream* m_channel;
        SoundDecoder* m_decoder;
        bool m_loop;
        Byte* m_decode_buffer;
        mutable pthread_mutex_t m_mutex;
        pthread_mutex_t	m_decoder_lock;
        bool ProcessDecode(OpenSLPCMAudioStream* channel);
    public:
        AndroidDecodeMusic(OpenSLPCMAudioStream* channel,SoundDecoder* decoder);
        ~AndroidDecodeMusic();


        virtual void GHL_CALL AddRef() const;
        
        virtual void GHL_CALL Release() const;

        void WriteData(OpenSLPCMAudioStream* channel);
        void ResetChannel();
        
        virtual void GHL_CALL SetVolume( float vol );
        virtual void GHL_CALL SetPan( float pan );
        virtual void GHL_CALL SetPitch( float pitch );
        virtual void GHL_CALL Stop();
        virtual void GHL_CALL Pause();
        virtual void GHL_CALL Resume();
        virtual void GHL_CALL Play( bool loop );

        
        bool NeedDestroy();
    };
}

#endif /*_ANDROID_MUSIC_STREAM_*/