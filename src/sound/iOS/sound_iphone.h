/*
 *  sound_iphone.h
 *  GHLiPhone
 *
 *  Created by Андрей Куницын on 20.06.10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef SOUND_IPHONE_H
#define SOUND_IPHONE_H

#include "ghl_sound.h"
#include "../../ghl_log_impl.h"

#include <vector>

namespace GHL {
	
	class SoundIPhone : public Sound {
	private:
		bool	m_music_played;
		DataStream* m_music_ds;
	public:
		explicit SoundIPhone();
		~SoundIPhone();
		
		bool SoundInit() ;
		void SoundUpdate() ;
		void SoundDone() ;
		
		/// load effect
		virtual SoundEffect* GHL_CALL LoadEffect(DataStream* ds) ;
		/// load stream
		/// load str
		virtual bool GHL_CALL Music_Load(DataStream* ds) ;
		virtual void GHL_CALL Music_Unload() ;
		/// play
		virtual void GHL_CALL Music_Play(bool loop) ;
		/// stop channel
		virtual void GHL_CALL Music_Stop() ;
		/// pause channel
		virtual void GHL_CALL Music_Pause() ;
		/// resume
		virtual void GHL_CALL Music_Resume() ;
	/// set channel volume
		virtual void GHL_CALL Music_SetVolume(float vol) ;
		/// set pan
		virtual void GHL_CALL Music_SetPan(float pan) ;		
		/// pause all
		virtual void GHL_CALL PauseAll() ;
		/// resume all
		virtual void GHL_CALL ResumeAll() ;
		/// stop all
		virtual void GHL_CALL StopAll();
		
	};
}

#endif /*SOUND_IPHONE_H*/