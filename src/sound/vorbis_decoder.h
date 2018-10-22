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

#ifndef VORBIS_DECODER_H
#define VORBIS_DECODER_H

#include "ghl_sound_decoder.h"

#ifdef GHL_USE_IVORBIS_DECODER
#include "tremor/ivorbisfile.h"
#else
#include "libvorbis/include/vorbis/codec.h"
#define OV_EXCLUDE_STATIC_CALLBACKS
#include "libvorbis/include/vorbis/vorbisfile.h"
#endif

namespace GHL
{
	class VorbisDecoder : public SoundDecoderBase
	{
		private:
			OggVorbis_File m_file;
			int	m_current_section;
            explicit VorbisDecoder(DataStream* ds);
            bool Init();
            GHL::UInt32 m_bytes_per_sample;
        public: 
			~VorbisDecoder();
			
            static VorbisDecoder* Open( DataStream* ds );
            
            /// read samples
            virtual UInt32 GHL_CALL ReadSamples(UInt32 samples, Byte* buffer);
            /// restart reading
            virtual void GHL_CALL Reset();
	};
	
	
	
}

#endif /*VORBIS_DECODER_H*/
