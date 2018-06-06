/*
 *  ghl_sound_openal.cpp
 *  SR
 *
 *  Created by Андрей Куницын on 27.02.11.
 *  Copyright 2011 andryblack. All rights reserved.
 *
 */

#include "ghl_sound_openal.h"
#include "../../ghl_log_impl.h"
#include "../ghl_sound_decoder.h"
#include <cassert>

namespace GHL {

    static const char* MODULE = "SOUND:OpenAL";
    
#define CHECK_ERROR  do { ALenum err = alGetError(); if (err!=AL_NO_ERROR) { \
		LOG_ERROR(  __FUNCTION__ << " :" << alGetString(err) ); \
	} } while(0)
	
#define CHECK_ERROR_F(Name)  do { ALenum err = alGetError(); if (err!=AL_NO_ERROR) { \
		LOG_ERROR( __FUNCTION__ << ":" << #Name << " :" << alGetString(err) ); \
	} } while(0)
	 
#define CHECK_ERROR  do { ALenum err = alGetError(); if (err!=AL_NO_ERROR) { \
    LOG_ERROR(  __FUNCTION__ << " :" << alGetString(err) ); \
    } } while(0)
    
#define CHECK_AERROR_F(Name)  do { ALCenum err = alcGetError(m_device); if (err!=ALC_NO_ERROR) { \
    LOG_ERROR( __FUNCTION__ << ":" << #Name << " alc :" << err ); \
    } } while(0)
	
	static ALenum convert_format(SampleType type) {
		if (type==SAMPLE_TYPE_MONO_8) return AL_FORMAT_MONO8;
		if (type==SAMPLE_TYPE_MONO_16) return AL_FORMAT_MONO16;
		if (type==SAMPLE_TYPE_STEREO_8) return AL_FORMAT_STEREO8;
		if (type==SAMPLE_TYPE_STEREO_16) return AL_FORMAT_STEREO16;
        LOG_ERROR("unexpected format");
		assert(false && "unexpected format");
		return AL_FORMAT_MONO8;
	}

	
	SoundEffectOpenAL::SoundEffectOpenAL(SampleType type, UInt32 freq)  : SoundEffectImpl(type,freq){
		alGenBuffers(1, &m_buffer);
		CHECK_ERROR;
	}
	SoundEffectOpenAL::~SoundEffectOpenAL() {
     	alDeleteBuffers(1, &m_buffer);
        CHECK_ERROR;
	}
	
	void SoundEffectOpenAL::SetData(const Byte* data, UInt32 bytes ) {
        SetCapacity(bytes/SoundDecoderBase::GetBps(GetSampleType()));
  		alBufferData(m_buffer,
                     convert_format(GetSampleType()),
                     data,
                     GetSamplesAmount()*SoundDecoderBase::GetBps(GetSampleType()),
                     GetFrequency());
		CHECK_ERROR;
	}
	class SoundInstanceOpenAL;
    class SoundChannelOpenAL {
    private:
        ALuint  m_source;
        SoundEffectOpenAL*      m_effect;
        SoundInstanceOpenAL*    m_instance;
    public:
        SoundChannelOpenAL( ALuint source );
        ~SoundChannelOpenAL();
        bool IsPlaying() const;
        void Play(bool loop);
        void Pause();
        void Stop();
        void SetVolume( float val );
        float GetVolume() const;
        void SetPan( float pan );
        void SetPitch(float pitch);
        void Clear();
        void SetEffect( SoundEffectOpenAL* effect );
        void SetInstance(SoundInstanceOpenAL* instance);
    };
    class SoundInstanceOpenAL: public RefCounterImpl<SoundInstance> {
    private:
        SoundChannelOpenAL* m_channel;
    public:
        SoundInstanceOpenAL( SoundChannelOpenAL* channel ) : m_channel(channel) {
            
        }
        void Reset() {
            m_channel = 0;
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
    };
	
	SoundChannelOpenAL::SoundChannelOpenAL(ALuint source) : m_source(source),m_effect(0){
        m_instance = 0;
	}
	
	SoundChannelOpenAL::~SoundChannelOpenAL() {
        Clear();
		alDeleteSources(1, &m_source);
		CHECK_ERROR_F(alDeleteSources);
	}
	
	
	bool SoundChannelOpenAL::IsPlaying() const {
		ALenum state = AL_UNDETERMINED;
		alGetSourcei(m_source, AL_SOURCE_STATE, &state);
        CHECK_ERROR_F(alGetSourcei);
		return state == AL_PLAYING;
	}
	
	void SoundChannelOpenAL::Play(bool loop)  {
		alSourcei(m_source, AL_LOOPING, loop ? AL_TRUE : AL_FALSE);
        CHECK_ERROR_F(alSourcei);
		alSourcePlay(m_source);
		CHECK_ERROR_F(alSourcePlay);
	}
	
	void SoundChannelOpenAL::Pause() {
		alSourcePause(m_source);
        CHECK_ERROR_F(alSourcePause);
	}
	
	void SoundChannelOpenAL::Stop() {
		alSourceStop(m_source);
        CHECK_ERROR_F(alSourceStop);
		alSourceRewind(m_source);
        CHECK_ERROR_F(alSourceRewind);
	}
	
	void SoundChannelOpenAL::SetVolume(float val) {
		alSourcef(m_source, AL_GAIN, val / 100.0f );
        CHECK_ERROR_F(alSourcef);
	}

    float SoundChannelOpenAL::GetVolume() const {
        float val = 0;
        alGetSourcef(m_source, AL_GAIN, &val);
        CHECK_ERROR_F(alSourcef);
        return val * 100;
    }

    void SoundChannelOpenAL::SetPan( float pan ) {
        alSource3f(m_source, AL_POSITION, pan/100.0f, 0.0f, 0.0f);
        CHECK_ERROR_F(alSource3f);
    }
    
    void SoundChannelOpenAL::SetPitch(float pitch) {
        alSourcef(m_source, AL_PITCH, pitch / 100.0f );
        CHECK_ERROR_F(alSourcef);
    }
	
	
	void SoundChannelOpenAL::Clear() {
        if (m_instance) {
            m_instance->Reset();
            m_instance->Release();
            m_instance = 0;
        }
		alSourceStop(m_source);
		CHECK_ERROR_F(alSourceStop);
        if (m_effect) {
            alSourcei(m_source, AL_BUFFER, 0);
            CHECK_ERROR_F(alSourcei);
            m_effect->Release();
            m_effect = 0;
        }
    }
	
	void SoundChannelOpenAL::SetEffect(SoundEffectOpenAL* effect) {
        if (m_effect!=0)
            Clear();
        alSourcei(m_source, AL_BUFFER, effect->buffer() );
        CHECK_ERROR_F(alSourcei);
	    m_effect = effect;
        m_effect->AddRef();
	}
    
    void SoundChannelOpenAL::SetInstance(SoundInstanceOpenAL* instance) {
        if (m_instance) {
            m_instance->Reset();
            m_instance->Release();
        }
        m_instance = instance;
        m_instance->AddRef();
    }
	
	
	SoundOpenAL::SoundOpenAL(size_t max_channels) : m_max_channels(max_channels) {
		m_device = 0;
		m_context = 0;
	}
	
	SoundOpenAL::~SoundOpenAL() {
	}
	
	bool SoundOpenAL::SoundInit() {
		LOG_INFO("SoundInit");
		m_device = alcOpenDevice(NULL);
		if (!m_device) {
			LOG_ERROR( "error opening default device" );
			return false;
		}
		
		m_context = alcCreateContext(m_device, 0);
		if (!m_context) {
			LOG_ERROR( "error creating context" );
			alcCloseDevice(m_device);
			return false;
		}
		const ALCchar* SPEC = alcGetString(m_device, ALC_DEVICE_SPECIFIER);
		if (SPEC) LOG_INFO( "ALC_DEVICE_SPECIFIER : " << SPEC );
		const ALCchar* EXT = alcGetString(m_device, ALC_EXTENSIONS);
        if (EXT) {
            std::string str( EXT );
            LOG_INFO("ALC_EXTENSIONS :");
            {
                std::string::size_type ppos = 0;
                std::string::size_type pos = str.find(' ');
                while ( pos!=str.npos ) {
                    LOG_INFO( "\t" << str.substr(ppos,pos-ppos) );
                    std::string::size_type next = pos+1;
                    pos = str.find( ' ', next );
                    ppos = next;
                    if (pos == str.npos ) {
                        LOG_INFO( "\t" << str.substr(ppos,str.npos) );
                        break;
                    }
                }
            }
        }
        
        
		const ALchar* VERSION = alGetString( AL_VERSION );
		if (VERSION) LOG_INFO("AL_VERSION	: " << VERSION );
		const ALchar* VENDOR = alGetString( AL_VENDOR);
		if (VENDOR) LOG_INFO( "AL_VENDOR	: " << VENDOR);
		const ALchar* RENDERER = alGetString( AL_RENDERER);
		if (RENDERER) LOG_INFO( "AL_RENDERER	: " << RENDERER );
		const ALchar* EXTENSIONS = alGetString( AL_EXTENSIONS);
        if (EXTENSIONS) {
            std::string str(EXTENSIONS);
            LOG_INFO( "AL_EXTENSIONS: ");
            {
                std::string::size_type ppos = 0;
                std::string::size_type pos = str.find(' ');
                while ( pos!=str.npos ) {
                    LOG_INFO( "\t" << str.substr(ppos,pos-ppos) );
                    std::string::size_type next = pos+1;
                    pos = str.find( ' ', next );
                    ppos = next;
                    if (pos == str.npos ) {
                        LOG_INFO( "\t" << str.substr(ppos,str.npos) );
                        break;
                    }
                }
            }
        }
        CHECK_ERROR;
        
		alcMakeContextCurrent(m_context);
        CHECK_AERROR_F(alcMakeContextCurrent);
		alcProcessContext(m_context);
        CHECK_AERROR_F(alcProcessContext);
		
		return true;
	}
	
    bool SoundOpenAL::SoundDone() {
		LOG_INFO( "SoundOpenAL::SoundDone" );
        if (m_context) {
            alcMakeContextCurrent(m_context);
        }
        for (std::list<SoundChannelOpenAL*>::iterator it=m_channels.begin();it!=m_channels.end();++it) {
            delete *it;
        }
        LOG_INFO("released " << m_channels.size() << " channels");
        m_channels.clear();
		if (m_context) {
			alcSuspendContext(m_context);
			alcMakeContextCurrent(0);
			alcDestroyContext(m_context);
			m_context = 0;
		}
		if (m_device) {
			alcCloseDevice(m_device);
			m_device = 0;
		}
        return true;
	}
    
    void SoundOpenAL::Suspend() {
        if (m_context) {
            alcMakeContextCurrent(NULL);
            CHECK_AERROR_F(alcMakeContextCurrent);
            alcSuspendContext(m_context);
            CHECK_AERROR_F(alcSuspendContext);
        }
    }

    
    void SoundOpenAL::Resume() {
        if (m_context) {
            alcMakeContextCurrent(m_context);
            CHECK_AERROR_F(alcMakeContextCurrent);
            alcProcessContext(m_context);
            CHECK_AERROR_F(alcProcessContext);
        }
    }
	
    SoundChannelOpenAL* SoundOpenAL::CreateChannel() {
        CHECK_ERROR_F(begforealGenSources);
		ALuint source = 0;
		alGetError();
		alGenSources(1, &source);
        ALenum err = alGetError();
		if (err!=AL_NO_ERROR) {
            LOG_ERROR("Create channel failed: " << alGetString(err));
            return 0;
        }
		SoundChannelOpenAL* channel = new SoundChannelOpenAL(source);
        m_channels.push_back(channel);
        return channel;
    }
    
	SoundChannelOpenAL* SoundOpenAL::GetChannel(float vol) {
        SoundChannelOpenAL* channel = 0;
        if ( m_channels.size() >= m_max_channels ) {
            for ( std::list<SoundChannelOpenAL*>::iterator it = m_channels.begin();it!=m_channels.end();++it) {
                if ( !(*it)->IsPlaying() ) {
                    channel = *it;
                    m_channels.erase(it);
                    m_channels.push_back(channel);
                    return channel;
                }
            }
            for ( std::list<SoundChannelOpenAL*>::iterator it = m_channels.begin();it!=m_channels.end();++it) {
                float channel_vol = (*it)->GetVolume();
                if ( channel_vol <= vol) {
                    channel = *it;
                    m_channels.erase(it);
                    m_channels.push_back(channel);
                    return channel;
                }
            }

            channel = 0;
        } else {
            channel = CreateChannel();
        }
        return channel;
    }
        
    /// create sound effect from data
    SoundEffect* SoundOpenAL::CreateEffect( SampleType type, UInt32 freq, Data* data ) {
        SoundEffectOpenAL* effect = new SoundEffectOpenAL(type,freq);
        if (data) {
            effect->SetData(data->GetData(), data->GetSize());
        }
        return effect;
    }
    /// play effect
    void SoundOpenAL::PlayEffect( SoundEffect* effect_ , float vol , float pan, SoundInstance** instance ) {
        if (!effect_) return;
        SoundChannelOpenAL* channel = GetChannel(vol);
        if (!channel) return;
        SoundEffectOpenAL* effect = static_cast<SoundEffectOpenAL*>(effect_);
        channel->SetEffect(effect);
        channel->SetVolume(vol);
        channel->SetPan(pan);
        channel->Play(false);
        if (instance) {
            SoundInstanceOpenAL* inst = new SoundInstanceOpenAL(channel);
            channel->SetInstance(inst);
            *instance = inst;
        }
    }
	

}

