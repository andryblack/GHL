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

#ifndef GHL_SOUND_DECODER_H
#define GHL_SOUND_DECODER_H

#include <ghl_types.h>
#include <ghl_sound.h>

namespace GHL
{

	struct DataStream;

	class SoundDecoder
	{
		protected:
			DataStream* m_ds;
			SampleType	m_type;
			UInt32		m_freq;
			UInt32		m_samples;
		public:
			SoundDecoder() : m_ds(0),m_type(SAMPLE_TYPE_UNKNOWN),m_freq(0),m_samples(0) {}
			virtual ~SoundDecoder() {}
			virtual UInt32 Decode(Byte* buf,UInt32 samples) = 0;
			virtual void Reset() = 0;
			DataStream*	get_ds() const { return m_ds;}
			
			SampleType get_type() const { return m_type;}
			UInt32 get_freq() const { return m_freq;}
			UInt32 get_samples() const { return m_samples;}
	};
}

#endif /*GHL_SOUND_DECODER_H*/