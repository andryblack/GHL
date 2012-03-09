/*
 *  ghl_sound_impl.h
 *  SR
 *
 *  Created by Андрей Куницын on 27.02.11.
 *  Copyright 2011 andryblack. All rights reserved.
 *
 */

#ifndef GHL_SOUND_IMPL_H
#define GHL_SOUND_IMPL_H

#include <ghl_sound.h>
#include "ghl_sound_decoder.h"
#include "../ghl_ref_counter_impl.h"

namespace GHL {
	
	class SamplesBufferImpl : public RefCounterImpl<SamplesBuffer> {
	public:
		SamplesBufferImpl(SampleType type,UInt32 capacity,UInt32 freq);
		virtual ~SamplesBufferImpl();
		virtual SampleType GHL_CALL GetSampleType() const { return m_type;}
		virtual UInt32 GHL_CALL GetCapacity() const { return m_capacity;}
		virtual UInt32 GHL_CALL GetFrequency() const { return m_freq;}
	protected:
		SampleType	m_type;
		UInt32		m_capacity;
		UInt32		m_freq;
	};
	
	class SoundImpl : public Sound {
	protected:
	public:
		SoundImpl();
		virtual ~SoundImpl();

		static UInt32 SampleSize(SampleType type);

		
		virtual SamplesBuffer* GHL_CALL LoadBuffer(DataStream* stream,SampleType resample,UInt32 refreq);
	};
	
}

#endif /*GHL_SOUND_IMPL_H*/