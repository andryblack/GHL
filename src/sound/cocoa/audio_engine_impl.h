#ifndef _GHL_AUDIO_ENGINE_IMPL_H_INCLUDED_
#define _GHL_AUDIO_ENGINE_IMPL_H_INCLUDED_

#include "../ghl_sound_impl.h"
#include <vector>

#import <AVFoundation/AVFoundation.h>

namespace GHL {
    class SoundEffectAudioEngine : public SoundEffectImpl {
    private:
        AVAudioFormat* m_format;
        AVAudioPCMBuffer* m_buffer;
        bool m_valid;
    public:
        SoundEffectAudioEngine(SampleType type, UInt32 freq, Data* data);
        ~SoundEffectAudioEngine();
        AVAudioFormat* format() const { return m_format;}
        AVAudioPCMBuffer* buffer() const { return m_buffer;}
        bool valid() const { return m_valid; }
    };
    
    class AudioEngineSoundInstance;
    class AudioEngineChannel {
    private:
        AVAudioFormat* m_format;
        AVAudioPlayerNode* m_player;
        AudioEngineSoundInstance* m_instance;
    public:
        explicit AudioEngineChannel(AVAudioFormat* format);
        ~AudioEngineChannel();
        
        void set_instance(AudioEngineSoundInstance* instance);
        
        void set_volume(float v);
        void set_pan(float p);
        void set_pitch(float p);
        void stop();
        
        AVAudioPlayerNode* player() const { return m_player; }
        
        bool is_playing();
        
        bool compare_format(AVAudioFormat* format);
        void play_effect(SoundEffectAudioEngine* effect,float vol,float pan);
    };
    
    class SoundAudioEngine::Impl {
    private:
        AVAudioEngine* m_engine;
        std::vector<AudioEngineChannel*> m_channels;
        size_t m_max_channels;
        AudioEngineChannel* get_channel(AVAudioFormat* format);
        void release_channels();
    public:
        explicit Impl(size_t max_channels);
        ~Impl();
        
        bool Init();
        void Done();
        void Suspend();
        void Resume();
        
        SoundEffectAudioEngine* CreateEffect( SampleType type, UInt32 freq, Data* data );
        void PlayEffect( SoundEffect* effect , float vol , float pan, SoundInstance** instance);
    };
}


#endif /*_GHL_AUDIO_ENGINE_IMPL_H_INCLUDED_*/
