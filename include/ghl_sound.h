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

#ifndef GHL_SOUND_H
#define GHL_SOUND_H

#include "ghl_api.h"
#include "ghl_ref_counter.h"

namespace GHL
{


	struct DataStream;

	
	/// sound effect
	struct SoundEffect : RefCounter
	{
		/// play
		virtual void GHL_CALL Play() = 0;
		/// stop channel
		virtual void GHL_CALL Stop() = 0;
		/// set channel volume
		virtual void GHL_CALL SetVolume(float vol) = 0;
	};
	
	

	/// sound interface
	struct Sound
	{
		/// load effect
		virtual SoundEffect* GHL_CALL LoadEffect(DataStream* ds) = 0;
		/// load stream
		virtual bool GHL_CALL Music_Load(DataStream* ds) = 0;
		virtual void GHL_CALL Music_Unload() = 0;
		/// play
		virtual void GHL_CALL Music_Play(bool loop) = 0;
		/// stop channel
		virtual void GHL_CALL Music_Stop() = 0;
		/// pause channel
		virtual void GHL_CALL Music_Pause() = 0;
		/// resume
		virtual void GHL_CALL Music_Resume() = 0;
		/// set channel volume
		virtual void GHL_CALL Music_SetVolume(float vol) = 0;
		/// set pan
		virtual void GHL_CALL Music_SetPan(float pan) = 0;
		
		/// pause all
		virtual void GHL_CALL PauseAll() = 0;
		/// resume all
		virtual void GHL_CALL ResumeAll() = 0;
		/// stop all
		virtual void GHL_CALL StopAll() = 0;
	};
	
}

#endif /*GHL_SOUND_H*/