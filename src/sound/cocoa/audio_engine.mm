#ifdef GHL_USE_AVAUDIOENGINE

#include "audio_engine.h"
#include "audio_engine_impl.h"

static const char* MODULE = "audio-engine";

namespace GHL {

    class AudioEngineSoundInstance: public RefCounterImpl<SoundInstance> {
    private:
        AudioEngineChannel* m_channel;
    public:
        AudioEngineSoundInstance( AudioEngineChannel* channel ) : m_channel(channel) {
            m_channel->set_instance(this);
        }
        ~AudioEngineSoundInstance() {
            if (m_channel) {
                m_channel->set_instance(0);
            }
        }
        void Reset() {
            m_channel = 0;
        }
        /// set volume (0-100)
        virtual void GHL_CALL SetVolume( float vol ) {
            if (m_channel) {
                m_channel->set_volume(vol / 100.0f);
            }
        }
        /// set pan (-100..0..+100)
        virtual void GHL_CALL SetPan( float pan ) {
            if (m_channel) {
                m_channel->set_pan(pan / 100.0f);
            }
        }
        virtual void GHL_CALL SetPitch( float pitch ) {
            if (m_channel) {
                m_channel->set_pitch(pitch / 100.0f);
            }
        }
        /// stop
        virtual void GHL_CALL Stop() {
            if (m_channel) {
                m_channel->stop();
            }
        }
    };
    
    

    SoundEffectAudioEngine::SoundEffectAudioEngine(SampleType type, UInt32 freq, Data* data) : SoundEffectImpl(type,freq) , m_format(0),m_buffer(0){
        m_valid = false;
        //data->AddRef();
        if (GetBits()==16) {
            SetCapacity(data->GetSize()/SoundDecoderBase::GetBps(GetSampleType()));
//            m_format = [[AVAudioFormat alloc] initWithCommonFormat:AVAudioPCMFormatInt16 sampleRate:freq channels:GetChannels() interleaved:YES];
//            if (m_format) {
//                assert(m_format.interleaved);
//                m_buffer = [[AVAudioPCMBuffer alloc] initWithPCMFormat:m_format frameCapacity:GetSamplesAmount()];
//                if (m_buffer) {
//                    m_buffer.frameLength = GetSamplesAmount();
//                    memcpy(m_buffer.int16ChannelData[0],data->GetData(),data->GetSize());
////                    m_buffer.mutableAudioBufferList->mBuffers[0].mData = data->GetDataPtr();
////                    m_buffer.mutableAudioBufferList->mBuffers[0].mDataByteSize = data->GetSize();
////                    m_buffer.mutableAudioBufferList->mBuffers[0].mNumberChannels = GetChannels();
////                    m_buffer.mutableAudioBufferList->mNumberBuffers = 1;
////
//                    m_valid = true;
//                }
//            }
            m_format = [[AVAudioFormat alloc] initWithCommonFormat:AVAudioPCMFormatFloat32 sampleRate:freq channels:GetChannels() interleaved:NO];
            if (m_format) {
                m_buffer = [[AVAudioPCMBuffer alloc] initWithPCMFormat:m_format frameCapacity:GetSamplesAmount()];
                if (m_buffer) {
                    m_buffer.frameLength = GetSamplesAmount();
                    if (type == SAMPLE_TYPE_STEREO_16) {
                        for (UInt32 i=0;i<GetSamplesAmount();++i) {
                            SInt16 l = *reinterpret_cast<const SInt16*>(&data->GetData()[i*4]);
                            SInt16 r = *reinterpret_cast<const SInt16*>(&data->GetData()[i*4+2]);
                            m_buffer.floatChannelData[0][i] = float(l) / INT16_MAX;
                            m_buffer.floatChannelData[1][i] = float(r) / INT16_MAX;
                        }
                        m_valid = true;
                    }
                }
            }
        }
        assert(m_valid);
    }

    SoundEffectAudioEngine::~SoundEffectAudioEngine() {
        [m_format release];
        [m_buffer release];
    }
    
	AudioEngineChannel::AudioEngineChannel(AVAudioFormat* format) :
        m_format([format retain]),
		m_player([[AVAudioPlayerNode alloc] init]),
        m_pitch([[AVAudioUnitVarispeed alloc] init]),
        m_instance(0){
    }
    
    AudioEngineChannel::~AudioEngineChannel() {
        if (m_instance) {
            m_instance->Reset();
            m_instance->Release();
        }
        [m_player release];
        [m_pitch release];
        [m_format release];
    }
    
    void AudioEngineChannel::set_instance(GHL::AudioEngineSoundInstance *instance) {
        if (m_instance != instance) {
            if (m_instance) {
                m_instance->Reset();
                m_instance->Release();
            }
            m_instance = instance;
            if (m_instance) {
                m_instance->AddRef();
            }
        }
    }
    
    
    bool AudioEngineChannel::compare_format(AVAudioFormat* format) {
        return [m_format isEqual: format];
    }
    
    bool AudioEngineChannel::is_playing() {
        return [m_player isPlaying];
    }
    
    void AudioEngineChannel::play_effect(SoundEffectAudioEngine* effect,float vol,float pan) {
        @try {
            [m_player stop];
            [m_player scheduleBuffer:effect->buffer() completionHandler:nil];
            [m_player setVolume:vol / 100.0f];
            [m_player setPan:pan / 100.0f];
            [m_player play];
        } @catch ( NSException* e) {
            LOG_ERROR("play_effect failed: " << e.description.UTF8String);
        }
    }
    
    void AudioEngineChannel::set_volume(float v) {
        [m_player setVolume:v];
    }
    void AudioEngineChannel::set_pan(float p) {
        [m_player setPan:p];
    }
    void AudioEngineChannel::set_pitch(float p) {
        [m_pitch setRate:p];
    }
    
    void AudioEngineChannel::stop() {
        [m_player stop];
    }
    
    SoundAudioEngine::Impl::Impl(size_t max_channels) : m_engine(0),
        m_max_channels(max_channels) {
    }
    
    SoundAudioEngine::Impl::~Impl() {
        
    }
    
    AudioEngineChannel* SoundAudioEngine::Impl::get_channel(AVAudioFormat *format) {
        for (std::vector<AudioEngineChannel*>::iterator it = m_channels.begin();it!=m_channels.end();++it) {
            AudioEngineChannel* channel = *it;
            if (channel->compare_format(format) && !channel->is_playing()) {
                return channel;
            }
        }
        if (m_channels.size() < m_max_channels) {
            AudioEngineChannel* channel = new AudioEngineChannel(format);
            m_channels.push_back(channel);
            [m_engine attachNode:channel->player()];
            [m_engine attachNode:channel->pitch()];
            [m_engine connect:channel->player() to:channel->pitch() format:[m_engine.mainMixerNode inputFormatForBus:0]];
            [m_engine connect:channel->pitch() to:m_engine.mainMixerNode format:[m_engine.mainMixerNode inputFormatForBus:0]];
            return channel;
        }
        for (std::vector<AudioEngineChannel*>::iterator it = m_channels.begin();it!=m_channels.end();++it) {
            AudioEngineChannel* channel = *it;
            if (channel->compare_format(format)) {
                m_channels.erase(it);
                m_channels.push_back(channel);
                return channel;
            }
        }
        return 0;
    }
    
    SoundEffectAudioEngine* SoundAudioEngine::Impl::CreateEffect( SampleType type, UInt32 freq, Data* data ) {
        SoundEffectAudioEngine* effect = new SoundEffectAudioEngine(type,freq,data);
        if (!effect->valid()) {
            effect->Release();
            effect = 0;
        }
        return effect;
    }
    
    void SoundAudioEngine::Impl::PlayEffect( SoundEffect* effect , float vol , float pan, SoundInstance** instance) {
        if (instance) {
            *instance = 0;
        }
        if (!effect)
            return;
        SoundEffectAudioEngine* effectimpl = static_cast<SoundEffectAudioEngine*>(effect);
        AudioEngineChannel* channel = get_channel(effectimpl->format());
        if (!channel) {
            return;
        }

        if (!m_engine.running) {
            NSError* error = 0;
            [m_engine startAndReturnError:&error];
            if (error) {
                NSLog(@"AudioEngine start error: %@",[error description]);
                [error release];
            }
            if (!m_engine.running) {
                return;
            }
        }
        channel->play_effect(effectimpl,vol,pan);
        if (instance) {
            AudioEngineSoundInstance* inst = new AudioEngineSoundInstance(channel);
            *instance = inst;
        }
    }
    
    bool SoundAudioEngine::Impl::Init() {
        if (m_engine) {
            Done();
        }
        m_engine = [[AVAudioEngine alloc] init];
        
        [m_engine mainMixerNode];
        m_engine.mainMixerNode.outputVolume = 1.0;
        
        return true;
    }
    void SoundAudioEngine::Impl::Done() {
        [m_engine stop];
        for (std::vector<AudioEngineChannel*>::iterator it = m_channels.begin();it!=m_channels.end();++it) {
            AudioEngineChannel* channel = *it;
            [m_engine detachNode:channel->pitch()];
            [m_engine detachNode:channel->player()];
            delete channel;
        }
        m_channels.clear();
        if (m_engine) {
            [m_engine release];
            m_engine = 0;
        }
    }
    
    void SoundAudioEngine::Impl::release_channels() {
        for (std::vector<AudioEngineChannel*>::iterator it = m_channels.begin();it!=m_channels.end();++it) {
            AudioEngineChannel* channel = *it;
            channel->stop();
            [m_engine detachNode:channel->pitch()];
            [m_engine detachNode:channel->player()];
            delete channel;
        }
        m_channels.clear();
    }
    
    void SoundAudioEngine::Impl::Suspend() {
        if (m_engine) {
            Done();
        }
    }
    void SoundAudioEngine::Impl::Resume() {
        if (!m_engine) {
            if (!Init()) {
                return;
            }
        }
        [m_engine prepare];
        NSError* error = 0;
        [m_engine startAndReturnError:&error];
        if (error) {
            NSLog(@"AudioEngine start error: %@",[error description]);
            [error release];
        }
    }
    
    
    
    
    
    SoundAudioEngine::SoundAudioEngine(size_t max_channels) : m_impl( new Impl(max_channels)) {
    }
    SoundAudioEngine::~SoundAudioEngine() {
        delete m_impl;
    }
        
    bool SoundAudioEngine::SoundInit() {
        return m_impl->Init();
    }
    bool SoundAudioEngine::SoundDone() {
        m_impl->Done();
        return true;
    }
    void SoundAudioEngine::Suspend() {
        m_impl->Suspend();
    }
    void SoundAudioEngine::Resume() {
        m_impl->Resume();
    }
        
    SoundEffect* SoundAudioEngine::CreateEffect( SampleType type, UInt32 freq, Data* data ) {
        return m_impl->CreateEffect( type, freq, data );
    }
   
    void SoundAudioEngine::PlayEffect( SoundEffect* effect , float vol , float pan, SoundInstance** instance ) {
        m_impl->PlayEffect(effect,vol,pan,instance);
    }
    

}

#endif
