/*
 *  ghl_sound_impl.cpp
 *  SR
 *
 *  Created by Андрей Куницын on 27.02.11.
 *  Copyright 2011 andryblack. All rights reserved.
 *
 */

#include "ghl_sound_impl.h"
#include <ghl_data_stream.h>

#include "../ghl_log_impl.h"

namespace GHL {

    static const char* MODULE = "SOUND";
    
	SamplesBufferImpl::SamplesBufferImpl(SampleType type,UInt32 capacity,UInt32 freq) : m_type(type),m_capacity(capacity),m_freq(freq) {
	}
	
	SamplesBufferImpl::~SamplesBufferImpl() {
	}
	
	
	
	
	SoundImpl::SoundImpl() {
	}
	
	SoundImpl::~SoundImpl() {
	}
	
	UInt32 SoundImpl::SampleSize(SampleType type) {
		if (type==SAMPLE_TYPE_MONO_8) return 1;
		if (type==SAMPLE_TYPE_MONO_16) return 2;
		if (type==SAMPLE_TYPE_STEREO_8) return 2;
		if (type==SAMPLE_TYPE_STEREO_16) return 4;
		return 0;
	}
	
	
	
	SamplesBuffer* GHL_CALL SoundImpl::LoadBuffer(DataStream* stream,SampleType resample,UInt32 refreq) {
		if (resample!=SAMPLE_TYPE_UNKNOWN || refreq!=0) {
			LOG_ERROR( "resampling not implemented" );
			return 0;
		}
		/*SoundDecoder* decoder = OpenDecoder(stream);
		if (decoder) {
			{
				Byte* data = new Byte[SampleSize(decoder->get_type())*decoder->get_samples()];
 				decoder->Decode(data, decoder->get_samples());
				SamplesBuffer* buffer = CreateBuffer(decoder->get_type(),decoder->get_samples(),decoder->get_freq(),data);
				delete decoder;
				delete [] data;
				return buffer;
			}
		}*/
		return 0;
	}
}