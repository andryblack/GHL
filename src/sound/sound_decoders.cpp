/*
 GHL - Game Helpers Library
 Copyright (C)  Andrey Kunitsyn 2009
 
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 
 Andrey (AndryBlack) Kunitsyn
 blackicebox (at) gmail (dot) com
 */

#include <ghl_api.h>
#include <ghl_data_stream.h>
#include "ghl_sound_decoder.h"
#ifndef GHL_NO_SOUND
#if defined( GHL_PLATFORM_MAC )
#define GHL_USE_WAV_DECODER
#elif defined( GHL_PLATFORM_WIN )
#define GHL_USE_WAV_DECODER
#elif defined( GHL_PLATFORM_FLASH )
#define GHL_USE_WAV_DECODER
#else
#define GHL_USE_WAV_DECODER
#define GHL_USE_VORBIS_DECODER
#endif

#ifdef GHL_USE_WAV_DECODER
#include "wav_decoder.h"
#endif
#ifdef GHL_USE_VORBIS_DECODER
#include "vorbis_decoder.h"
#endif
#endif

namespace GHL
{
    
    SoundDecoderBase::SoundDecoderBase(DataStream* ds) : m_ds(ds),m_type(SAMPLE_TYPE_UNKNOWN),m_freq(0),m_samples(0) {
        m_ds->AddRef();
    }
    SoundDecoderBase::~SoundDecoderBase() {
        if (m_ds) {
            m_ds->Release();
        }
    }
	
}

GHL_API GHL::SoundDecoder* GHL_CALL GHL_CreateSoundDecoder( GHL::DataStream* file ) {
    GHL::SoundDecoder* result = 0;
#ifdef GHL_USE_WAV_DECODER
    result = GHL::WavDecoder::Open( file );
    if (result) return result;
#endif
#ifdef GHL_USE_VORBIS_DECODER
    result = GHL::VorbisDecoder::Open( file );
    if (result) return result;
#endif
    return result;
}
