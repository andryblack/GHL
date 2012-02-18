#include "sound_iphone.h"

#include <algorithm>

#include "SoundEngine.h"
#include "../../ghl_ref_counter_impl.h"

namespace GHL {

	static const char* MODULE = "SOUND";
	
	/// sound effect
	class SoundEffectIPhone : public RefCounterImpl<SoundEffect>
	{
	private:
		::UInt32 m_id;
	public:
		explicit SoundEffectIPhone(::UInt32 id) : m_id(id) {}
        ~SoundEffectIPhone() {
     		SoundEngine_UnloadEffect(m_id);
        }
		/// play
		virtual void GHL_CALL Play() {
			SoundEngine_StartEffect(m_id);
		}
		/// stop channel
		virtual void GHL_CALL Stop() {
			SoundEngine_StopEffect(m_id,false);
		}
		/// set channel volume
		virtual void GHL_CALL SetVolume(float vol) {
			SoundEngine_SetEffectLevel(m_id,vol);
		}
	};
	
	
	SoundIPhone::SoundIPhone()  {
        m_music_ds = 0;
		m_music_played = false;
	}
	SoundIPhone::~SoundIPhone() {
	}
	
	bool SoundIPhone::SoundInit() {
		OSStatus res = SoundEngine_Initialize(0);
		return res==noErr;
	}
	
	void SoundIPhone::SoundUpdate() {
		
	}
	
	void SoundIPhone::SoundDone() {
		SoundEngine_Teardown();
	}
	
#define PROCESS_RESULT \
	if (res!=noErr) {\
        LOG_ERROR( "error code : " << res ); \
	}
	/// load effect
	SoundEffect* GHL_CALL SoundIPhone::LoadEffect(DataStream* ds) {
		::UInt32 id = 0;
		OSStatus res = SoundEngine_LoadEffect(ds,&id);
		if (res!=noErr)
			return 0;
		return new SoundEffectIPhone(id);
	}
	
	bool GHL_CALL SoundIPhone::Music_Load(DataStream* ds) {
		OSStatus res = SoundEngine_LoadBackgroundMusicTrack(ds,false,false);
		m_music_played = false;
		m_music_ds = ds;
		return res == noErr;
	}
	
	void GHL_CALL SoundIPhone::Music_Unload() {
		m_music_played = false;
		m_music_ds = 0;
		SoundEngine_UnloadBackgroundMusicTrack();
	}
											 
											 																					  
	/// play
	void GHL_CALL SoundIPhone::Music_Play(bool loop) {
		OSStatus res = SoundEngine_StartBackgroundMusic();
		if (!loop) SoundEngine_StopBackgroundMusic(true);
		PROCESS_RESULT;
		m_music_played = true;
	}
	/// stop channel
	void GHL_CALL SoundIPhone::Music_Stop() {
		OSStatus res = SoundEngine_StopBackgroundMusic(false);
		PROCESS_RESULT;
		SoundEngine_UnloadBackgroundMusicTrack();
		m_music_played = false;
		if (m_music_ds) {
			res = SoundEngine_LoadBackgroundMusicTrack(m_music_ds,false,false);
			PROCESS_RESULT;
		}
	}
	/// pause channel
	void GHL_CALL SoundIPhone::Music_Pause() {
		SoundEngine_PauseBackgroundMusic();
	}
	/// resume
	void GHL_CALL SoundIPhone::Music_Resume() {
	}
	
	/// set channel volume
	void GHL_CALL SoundIPhone::Music_SetVolume(float vol) {
	}
	/// set pan
	void GHL_CALL SoundIPhone::Music_SetPan(float pan) {
	}
	
	
	/// pause all
	void GHL_CALL SoundIPhone::PauseAll() {
	}
	/// resume all
	void GHL_CALL SoundIPhone::ResumeAll() {
	}
	/// stop all
	void GHL_CALL SoundIPhone::StopAll() {
	}
}
