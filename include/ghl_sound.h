/*
 *  sb_sound_mgr.h
 *  SR
 *
 *  Created by Андрей Куницын on 27.02.11.
 *  Copyright 2011 andryblack. All rights reserved.
 *
 */

#ifndef GHL_SOUND_H
#define GHL_SOUND_H

#include "ghl_api.h"
#include "ghl_types.h"
#include "ghl_ref_counter.h"

namespace GHL {
	
	struct DataStream;
	
	enum SampleType {
		SAMPLE_TYPE_UNKNOWN,
		SAMPLE_TYPE_MONO_8,
		SAMPLE_TYPE_MONO_16,
		SAMPLE_TYPE_STEREO_8,
		SAMPLE_TYPE_STEREO_16
	};
	
	struct SamplesBuffer : RefCounter {
		virtual SampleType GHL_CALL GetSampleType() const = 0;
		virtual UInt32 GHL_CALL GetCapacity() const = 0;
		virtual UInt32 GHL_CALL GetFrequency() const = 0;
	};
	
	struct SoundChannel : RefCounter {
		virtual SampleType GHL_CALL GetSampleType() const = 0;
		virtual UInt32 GHL_CALL GetFrequency() const = 0;
		virtual bool GHL_CALL IsPlaying() const = 0;
		virtual void GHL_CALL Play(bool loop) = 0;
		virtual void GHL_CALL Pause() = 0;
		virtual void GHL_CALL Stop() = 0;
		virtual void GHL_CALL SetVolume(float val) = 0;
	};
	
	struct Sound {
		/// create samples buffer
		/**
		 * @arg type type of samples
		 * @arg size capacity of buffer in samples 
		 * @arg freq frequency in hetz
		 * @arg data data pointer
		 */
		virtual SamplesBuffer* GHL_CALL CreateBuffer(SampleType type,UInt32 size,UInt32 freq,const Byte* data) = 0;
		/// load samples buffer
		virtual SamplesBuffer* GHL_CALL LoadBuffer(DataStream* stream,SampleType resample = SAMPLE_TYPE_UNKNOWN,UInt32 refreq = 0) = 0;
		/// create channel
		virtual SoundChannel* GHL_CALL CreateChannel(SampleType type,UInt32 freq) = 0;
		virtual void GHL_CALL ChannelClear(SoundChannel* channel) = 0;
		virtual void GHL_CALL ChannelAddBuffer(SoundChannel* channe,SamplesBuffer* buffer) = 0;
	};
	
}


#endif /*GHL_SOUND_H*/