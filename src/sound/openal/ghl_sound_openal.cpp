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
#include <cassert>

namespace GHL {

    static const char* MODULE = "SOUND";
    
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

	
	SamplesBufferOpenAL::SamplesBufferOpenAL(SampleType type,UInt32 size,UInt32 freq) : SamplesBufferImpl(type, size, freq) {
		alGenBuffers(1, &m_name);
		CHECK_ERROR;
	}
	SamplesBufferOpenAL::~SamplesBufferOpenAL() {
		alDeleteBuffers(1, &m_name);
	}
	
	void GHL_CALL SamplesBufferOpenAL::SetData(const Byte* data) {
  		alBufferData(m_name, convert_format(GetSampleType()), data, GetCapacity()*SoundImpl::SampleSize(GetSampleType()), GetFrequency());
		CHECK_ERROR;
	}
	
	
	SoundChannelOpenAL::SoundChannelOpenAL(ALuint source,SampleType type,UInt32 freq) : m_source(source), m_type(type),m_freq(freq){
	}
	
	SoundChannelOpenAL::~SoundChannelOpenAL() {
		alSourceStop(m_source);
		alDeleteSources(1, &m_source);
		CHECK_ERROR;
	}
	
	
	bool GHL_CALL SoundChannelOpenAL::IsPlaying() const {
		ALenum state = AL_UNDETERMINED;
		alGetSourcei(m_source, AL_SOURCE_STATE, &state);
		return state == AL_PLAYING;
	}
	
	void GHL_CALL SoundChannelOpenAL::Play(bool loop)  {
		alSourcei(m_source, AL_LOOPING, loop ? AL_TRUE : AL_FALSE);
		alSourcePlay(m_source);
		CHECK_ERROR;
	}
	
	void GHL_CALL SoundChannelOpenAL::Pause() {
		alSourcePause(m_source);
	}
	
	void GHL_CALL SoundChannelOpenAL::Stop() {
		alSourceStop(m_source);
		alSourceRewind(m_source);
	}
	
	void GHL_CALL SoundChannelOpenAL::SetVolume(float val) {
		alSourcef(m_source, AL_GAIN, val);
	}
	
	
	void SoundChannelOpenAL::Clear() {
		alSourceStop(m_source);
		CHECK_ERROR_F(alSourceStop);
		alSourceUnqueueBuffers(m_source, ALuint(m_buffers.size()), &m_buffers.front());
		CHECK_ERROR_F(alSourceUnqueueBuffers);
		m_buffers.clear();
		CHECK_ERROR;
	}
	
	void SoundChannelOpenAL::AddBuffer(SamplesBufferOpenAL* buf) {
		ALuint buf_name = buf->name();
		alSourceQueueBuffers(m_source, 1, &buf_name);
		m_buffers.push_back(buf_name);
		CHECK_ERROR;
	}
	
	void SoundChannelOpenAL::Update() {
		
	}
	
	SoundOpenAL::SoundOpenAL() {
		m_device = 0;
		m_context = 0;
	}
	
	SoundOpenAL::~SoundOpenAL() {
	}
	
	bool SoundOpenAL::SoundInit() {
		LOG_INFO("SoundOpenAL::SoundInit");
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
	
	SamplesBuffer* GHL_CALL SoundOpenAL::CreateBuffer(SampleType type,UInt32 size,UInt32 freq,const Byte* data) {
		SamplesBufferOpenAL* buf = new SamplesBufferOpenAL(type,size,freq);
		buf->SetData(data);
		return buf;
	}
	
	SoundChannel* GHL_CALL SoundOpenAL::CreateChannel(SampleType type,UInt32 freq) {
		CHECK_ERROR_F(begforealGenSources);
		ALuint source = 0;
		alGetError();
		alGenSources(1, &source);
		if (alGetError()!=AL_NO_ERROR)
			return 0;
		return new SoundChannelOpenAL(source,type,freq);
	}
	
	void GHL_CALL SoundOpenAL::ChannelClear(SoundChannel* channel) {
		SoundChannelOpenAL* ch = static_cast<SoundChannelOpenAL*> (channel);
		if (ch) {
			ch->Clear();
		}
	}
	
	void GHL_CALL SoundOpenAL::ChannelAddBuffer(SoundChannel* channel,SamplesBuffer* buffer) {
		SoundChannelOpenAL* ch = static_cast<SoundChannelOpenAL*> (channel);
		SamplesBufferOpenAL* buf = static_cast<SamplesBufferOpenAL*> (buffer);
		if (buf->GetFrequency()!=ch->GetFrequency()) {
			LOG_ERROR( "freq not equal " << ch->GetFrequency() << " <- " << buf->GetFrequency() );
		}
		if (ch && buf) {
			ch->AddBuffer(buf);
		}
		CHECK_ERROR;
	}

}