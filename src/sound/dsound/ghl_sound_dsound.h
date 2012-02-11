#ifndef GHL_SOUND_DSOUND_H
#define GHL_SOUND_DSOUND_H

#include <ghl_types.h>
#include <ghl_sound.h>
#include "ghl_dsound.h"

#include <vector>

namespace GHL {

	const UInt32 BUFFER_SIZE = 44100/2; /// samples (0.5sec)
	
	class SoundDSound;
	class SoundDSound : public Sound {
	private:
		HINSTANCE       m_library;
		LPDIRECTSOUND8	m_IDS;
		LPDIRECTSOUNDBUFFER m_IDSBPrimary;
		HRESULT InitPrimaryBuffer();
	public:
		SoundDSound();
		~SoundDSound();

		bool SoundInit(HWND hwnd);
		void SoundDone();
		void SoundUpdate() ;
		
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


#endif /*GHL_SOUND_DSOUND_H*/