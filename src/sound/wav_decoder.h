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

#ifndef WAV_DECODER_H
#define WAV_DECODER_H

#include "ghl_sound_decoder.h"

namespace GHL
{

	class WavDecoder : public SoundDecoderBase
	{
		private:

// byte-align structures
#if defined(_MSC_VER) ||  defined(__BORLANDC__) || defined (__BCPLUSPLUS__)
#    pragma pack( push, packing )
#    pragma pack( 1 )
#    define PACK_STRUCT
#elif defined(__MINGW32__) || defined(__MINGW64__)
        _Pragma("pack(push,1)")
#   define PACK_STRUCT
#elif defined(__GNUC__) || defined(__clang__)
#    define PACK_STRUCT    __attribute__((packed))
#else
#   error "unknown compilator need pack structure"
#    define PACK_STRUCT
#endif
			struct WaveFmtDescr {
				UInt16	compression_code;
				UInt16	num_channels;
				UInt32 	sample_rate;
				UInt32	bytes_per_second;
				UInt16	block_align;
				UInt16 	bits_per_sample;
			} PACK_STRUCT;
// Default alignment
#if defined(_MSC_VER) ||  defined(__BORLANDC__) || defined (__BCPLUSPLUS__)
#    pragma pack( pop, packing )
#elif defined(__MINGW32__) || defined(__MINGW64__)
        _Pragma("pack(pop)")
#endif

#undef PACK_STRUCT
        
            GHL_STATIC_ASSERT(sizeof(WaveFmtDescr) == (2+2+4+4+2+2));

			WaveFmtDescr	m_format;
			UInt32	m_unreaded;
            explicit WavDecoder(DataStream* ds);
            bool Init();
		public: 
			~WavDecoder();
			
            static WavDecoder* Open( DataStream* ds );
			
            /// read samples
            virtual UInt32 GHL_CALL ReadSamples(UInt32 samples, Byte* buffer);
            /// restart reading
            virtual void GHL_CALL Reset();
    };
	
}

#endif /*WAV_DECODER_H*/
