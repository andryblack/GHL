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
        ALuint  m_buffer;
        SoundInstanceOpenAL*   m_instance;
    public:
        SoundChannelOpenAL( ALuint source );
        ~SoundChannelOpenAL();
        bool IsPlaying() const;
        void Play(bool loop);
        void Pause();
        void Stop();
        void SetVolume( float val );
        void SetPan( float pan );
        void Clear();
        void SetBuffer(ALuint buff);
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
        /// stop
        virtual void GHL_CALL Stop() {
            if (m_channel) {
                m_channel->Stop();
            }
        }
    };
	
	SoundChannelOpenAL::SoundChannelOpenAL(ALuint source) : m_source(source),m_buffer(0){
        m_instance = 0;
	}
	
	SoundChannelOpenAL::~SoundChannelOpenAL() {
        if (m_instance) {
            m_instance->Release();
        }
		alSourceStop(m_source);
		alDeleteSources(1, &m_source);
		CHECK_ERROR;
	}
	
	
	bool SoundChannelOpenAL::IsPlaying() const {
		ALenum state = AL_UNDETERMINED;
		alGetSourcei(m_source, AL_SOURCE_STATE, &state);
		return state == AL_PLAYING;
	}
	
	void SoundChannelOpenAL::Play(bool loop)  {
		alSourcei(m_source, AL_LOOPING, loop ? AL_TRUE : AL_FALSE);
		alSourcePlay(m_source);
		CHECK_ERROR;
	}
	
	void SoundChannelOpenAL::Pause() {
		alSourcePause(m_source);
	}
	
	void SoundChannelOpenAL::Stop() {
		alSourceStop(m_source);
		alSourceRewind(m_source);
	}
	
	void SoundChannelOpenAL::SetVolume(float val) {
		alSourcef(m_source, AL_GAIN, val / 100.0f );
	}
    
    void SoundChannelOpenAL::SetPan( float pan ) {
        alSource3f(m_source, AL_POSITION, pan/100.0f, 0.0f, 0.0f);
    }
	
	
	void SoundChannelOpenAL::Clear() {
        if (m_instance) {
            m_instance->Reset();
            m_instance = 0;
        }
		alSourceStop(m_source);
		CHECK_ERROR_F(alSourceStop);
        if (m_buffer) {
            alSourcei(m_source, AL_BUFFER, 0);
            m_buffer = 0;
        }
    }
	
	void SoundChannelOpenAL::SetBuffer(ALuint buffer) {
        if (m_buffer!=0)
            Clear();
        alSourcei(m_source, AL_BUFFER, buffer);
	    m_buffer = buffer;
		CHECK_ERROR;
	}
    
    void SoundChannelOpenAL::SetInstance(SoundInstanceOpenAL* instance) {
        if (m_instance) {
            m_instance->Reset();
        }
        m_instance = instance;
    }
	
	
	SoundOpenAL::SoundOpenAL() {
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
		if (EXT) LOG_INFO( "ALC_EXTENSIONS : " << EXT );
		const ALchar* VERSION = alGetString( AL_VERSION );
		if (VERSION) LOG_INFO("AL_VERSION	: " << VERSION );
		const ALchar* VENDOR = alGetString( AL_VENDOR);
		if (VENDOR) LOG_INFO( "AL_VENDOR	: " << VENDOR);
		const ALchar* RENDERER = alGetString( AL_RENDERER);
		if (RENDERER) LOG_INFO( "AL_RENDERER	: " << RENDERER );
		const ALchar* EXTENSIONS = alGetString( AL_EXTENSIONS);
		if (EXTENSIONS) LOG_INFO( "AL_EXTENSIONS: " << EXTENSIONS );
		alcMakeContextCurrent(m_context);
		alcProcessContext(m_context);
		{
			ALCenum err = alcGetError(m_device);
			if (err!=ALC_NO_ERROR) {
				LOG_ERROR( " error" );
			}
		}
		CHECK_ERROR;
		return true;
	}
	
    void SoundOpenAL::SoundDone() {
		LOG_INFO( "SoundOpenAL::SoundDone" );
        for (size_t i=0;i<m_channels.size();i++) {
            delete m_channels[i];
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
	}
	
    SoundChannelOpenAL* SoundOpenAL::CreateChannel() {
        CHECK_ERROR_F(begforealGenSources);
		ALuint source = 0;
		alGetError();
		alGenSources(1, &source);
		if (alGetError()!=AL_NO_ERROR)
			return 0;
		SoundChannelOpenAL* channel = new SoundChannelOpenAL(source);
        m_channels.push_back(channel);
        return channel;
    }
    
	SoundChannelOpenAL* SoundOpenAL::GetChannel() {
        SoundChannelOpenAL* channel = CreateChannel();
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
        SoundChannelOpenAL* channel = GetChannel();
        if (!channel) return;
        SoundEffectOpenAL* effect = static_cast<SoundEffectOpenAL*>(effect_);
        channel->SetBuffer(effect->buffer());
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