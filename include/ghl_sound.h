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
    struct Data;
	
    /// Sample format
	enum SampleType {
		SAMPLE_TYPE_UNKNOWN,
		SAMPLE_TYPE_MONO_8,       ///< mono, 8 bit unsigned
		SAMPLE_TYPE_MONO_16,      ///< mono, 16 bit signed
		SAMPLE_TYPE_STEREO_8,     ///< stereo, 8 bit per channel unsigned
		SAMPLE_TYPE_STEREO_16     ///< stereo, 16 but per channel signed
	};
    
    /// Decoder sound data
    struct SoundDecoder : RefCounter {
        /// sample type
        virtual SampleType GHL_CALL GetSampleType() const = 0;
        /// samples rate
        virtual UInt32 GHL_CALL GetFrequency() const = 0;
        /// samples amount
        virtual UInt32 GHL_CALL GetSamplesAmount() const = 0;
        /// read samples
        virtual UInt32 GHL_CALL ReadSamples(UInt32 samples, Byte* buffer) = 0;
        /// restart reading
        virtual void GHL_CALL Reset() = 0;
        /// read all
        virtual Data* GHL_CALL GetAllSamples() = 0;
    };
	
    /// Sound effect
    struct SoundEffect : RefCounter {
        /// sample type
        virtual SampleType GHL_CALL GetSampleType() const = 0;
        /// samples rate
        virtual UInt32 GHL_CALL GetFrequency() const = 0;
        /// samples amount
        virtual UInt32 GHL_CALL GetSamplesAmount() const = 0;
    };
    
    /// Sound instance
    struct SoundInstance : RefCounter {
        /// set volume (0-100)
        virtual void GHL_CALL SetVolume( float vol ) = 0;
        /// set pan (-100..0..+100)
        virtual void GHL_CALL SetPan( float pan ) = 0;
        /// stop
        virtual void GHL_CALL Stop() = 0;
    };
    
    /// Music instance
    struct MusicInstance : SoundInstance {
        /// pause
        virtual void GHL_CALL Pause() = 0;
        /// resume
        virtual void GHL_CALL Resume() = 0;
        /// play
        virtual void GHL_CALL Play( bool loop ) = 0;
    };
	
    /// Sound interface
	struct Sound {
        /// create sound effect from data
        virtual SoundEffect* GHL_CALL CreateEffect( SampleType type, UInt32 freq, Data* data ) = 0;
        /// play effect
        virtual void GHL_CALL PlayEffect( SoundEffect* effect , float vol = 100.0f, float pan=0.0f, SoundInstance** instance = 0) = 0;
        /// open music
        virtual MusicInstance* GHL_CALL OpenMusic( GHL::DataStream* file ) = 0;
    };
	
}

/// Create sound decoder for file
GHL_API GHL::SoundDecoder* GHL_CALL GHL_CreateSoundDecoder( GHL::DataStream* file );


#endif /*GHL_SOUND_H*/