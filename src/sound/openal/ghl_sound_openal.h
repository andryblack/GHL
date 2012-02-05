/*
 *  ghl_sound_openal.h
 *  SR
 *
 *  Created by Андрей Куницын on 27.02.11.
 *  Copyright 2011 andryblack. All rights reserved.
 *
 */

#ifndef GHL_SOUND_OPENAL_H
#define GHL_SOUND_OPENAL_H

#include "../ghl_sound_impl.h"

#include "ghl_openal.h"
#include <vector>

namespace GHL {
	
	class SamplesBufferOpenAL : public SamplesBufferImpl {
	private:
		ALuint m_name;
	public:
		SamplesBufferOpenAL(SampleType type,UInt32 capacity,UInt32 freq);
		~SamplesBufferOpenAL();
		void GHL_CALL SetData(const Byte* data);
		ALuint name() const { return m_name;}
	};
	
	class SoundChannelOpenAL : public RefCounterImpl<SoundChannel> {
	public:
		SoundChannelOpenAL(ALuint source,SampleType type,UInt32 freq);
		~SoundChannelOpenAL();
		virtual SampleType GHL_CALL GetSampleType() const { return m_type;}
		virtual UInt32 GHL_CALL GetFrequency() const { return m_freq;}
		virtual bool GHL_CALL IsPlaying() const;
		virtual void GHL_CALL Play(bool loop) ;
		virtual void GHL_CALL Pause() ;
		virtual void GHL_CALL Stop() ;
		virtual void GHL_CALL SetVolume(float val);
		
		void Clear();
		void AddBuffer(SamplesBufferOpenAL* buf);
		void Update();
	private:
		ALuint	m_source;
		SampleType	m_type;
		UInt32	m_freq;
		std::vector<ALuint> m_buffers;
	};
	
	class SoundOpenAL : public SoundImpl {
	private:
		ALCdevice* m_device;
		ALCcontext* m_context;
		SoundOpenAL(const SoundOpenAL&);
		SoundOpenAL& operator = (const SoundOpenAL&);
	public:
		SoundOpenAL();
		virtual ~SoundOpenAL();
		
		bool SoundInit();
		void SoundDone();
		
		virtual SamplesBuffer* GHL_CALL CreateBuffer(SampleType type,UInt32 size,UInt32 freq,const Byte* data);
		virtual SoundChannel* GHL_CALL CreateChannel(SampleType type,UInt32 freq);
		virtual void GHL_CALL ChannelClear(SoundChannel* channel) ;
		virtual void GHL_CALL ChannelAddBuffer(SoundChannel* channe,SamplesBuffer* buffer);
	};
	
}


#endif /*GHL_SOUND_OPENAL_H*/