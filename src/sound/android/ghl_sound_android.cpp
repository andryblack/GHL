#include "ghl_sound_android.h"
#include <jni.h>
#include <android/asset_manager.h>
#include <ghl_data.h>
#include <ghl_data_stream.h>
#include "../ghl_sound_decoder.h"
#include "android_music_stream.h"

#include "../../ghl_log_impl.h"
static const char* MODULE = "snd";

namespace GHL {
    
    AAsset* GetAssetFromDataStream( DataStream* ds );
    
    SoundAndroid::SoundAndroid() : m_opensl_engine(0),m_use_decoder(false) {
        
    }
    
    SoundAndroid::~SoundAndroid() {
    }
    
    bool SoundAndroid::SoundInit(int android_os_version) {
        m_use_decoder = android_os_version >= 24;
        if (!m_opensl_engine) {
            m_opensl_engine = new OpenSLAudioEngine();
        }
        if (m_opensl_engine) {
            return m_opensl_engine->IsValid();
        }
        return false;
    }
    bool SoundAndroid::SoundDone() {
        delete m_opensl_engine;
        m_opensl_engine = 0;
        return true;
    }

    void SoundAndroid::SetFocus(bool focus) {
        if (m_opensl_engine) {
            m_opensl_engine->SetFocus(focus);
        }
    }
    
    class SoundEffectOpenSL : public SoundEffectImpl {
    private:
        Data* m_buffer;
    public:
        SoundEffectOpenSL(SampleType type, UInt32 freq,Data* data) : SoundEffectImpl(type,freq),m_buffer(data) {
            m_buffer->AddRef();
        }
        ~SoundEffectOpenSL() {
            m_buffer->Release();
        }
        Data* GetData() { return m_buffer; }
    };
    
    class SoundInstanceOpenSL : public RefCounterImpl<SoundInstance>, public OpenSLAudioChannel::Holder {
    private:
        OpenSLAudioChannel* m_channel;
    public:
        explicit SoundInstanceOpenSL(OpenSLAudioChannel* channel) : m_channel(channel) {
            
        }
        ~SoundInstanceOpenSL() {
            if (m_channel) {
                m_channel->ResetHolder(this);
            }
        }
        /// set volume (0-100)
        virtual void GHL_CALL SetVolume( float vol ) {
            if (m_channel) {
                m_channel->SetVolume(vol);
            }
        }
        /// set pan (-100..0..+100)
        virtual void GHL_CALL SetPan( float pan ) {
            if (m_channel) {
                m_channel->SetPan(pan);
            }
        }
        virtual void GHL_CALL SetPitch( float pitch ) {
            if (m_channel) {
                m_channel->SetPitch(pitch);
            }
        }
        /// stop
        virtual void GHL_CALL Stop() {
            if (m_channel) {
                m_channel->Stop();
            }
        }

        void ResetChannel() {
            m_channel = 0;
            Release();
        }
    };
    
    /// create sound effect from data
    SoundEffect* GHL_CALL SoundAndroid::CreateEffect( SampleType type, UInt32 freq, Data* data ) {
        if (!data)
            return 0;
        if (!m_opensl_engine)
            return 0;
        return new SoundEffectOpenSL(type,freq,data);
    }
    
    /// play effect
    void GHL_CALL SoundAndroid::PlayEffect( SoundEffect* effect , float vol, float pan, SoundInstance** instance ) {
        if (!m_opensl_engine)
            return;
        if (instance)
            *instance = 0;
        if (!effect)
            return;
        SoundEffectOpenSL* sl_effect = reinterpret_cast<SoundEffectOpenSL*>(effect);
        OpenSLAudioChannel* channel = m_opensl_engine->GetChannel(sl_effect->GetFrequency(),
                                                                 sl_effect->GetChannels(),
                                                                 sl_effect->GetBits());
        if (!channel)
            return;
        channel->SetHolder(0);
        channel->PutData(sl_effect->GetData());
        channel->SetVolume(vol);
        channel->SetPan(pan);
        channel->Play();
        if (instance) {
            SoundInstanceOpenSL* inst = new SoundInstanceOpenSL(channel);
            inst->AddRef();
            channel->SetHolder(inst);
            *instance = inst;
        }
    }
    
    


    

    
    
    /// open music
    MusicInstance* GHL_CALL SoundAndroid::OpenMusic( GHL::DataStream* file ) {
        if (!m_opensl_engine)
            return 0;
        if (!file)
            return 0;

        if (!m_use_decoder) {
            AAsset* asset = GetAssetFromDataStream( file );
            if (asset) {
                OpenSLFileAudioStream* stream = m_opensl_engine->CreateFileStream(asset);
                if (stream) {
                    return new AndroidAssetMusic(file,stream);
                }
            }
        }

        SoundDecoder* decoder = GHL_CreateSoundDecoder( file );
        if (!decoder) {
            return 0;
        }

        OpenSLPCMAudioStream* channel = m_opensl_engine->GetPCMStream(decoder->GetFrequency(),
                                                             SoundDecoderBase::GetChannels(decoder->GetSampleType()),
                                                             SoundDecoderBase::GetBps(decoder->GetSampleType())*8/SoundDecoderBase::GetChannels(decoder->GetSampleType()));
        if (!channel) {
            decoder->Release();
            return 0;
        }
        
        AndroidDecodeMusic* music = new AndroidDecodeMusic(channel,decoder);
        return music;
    }

    void SoundAndroid::Process() {
        
    }
}