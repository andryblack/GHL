#ifndef GHL_SOUND_DSOUND_H
#define GHL_SOUND_DSOUND_H

#include "../ghl_sound_impl.h"
#include "ghl_dsound.h"

#include <list>

namespace GHL {

	const UInt32 BUFFER_SIZE = 44100/2; /// samples (0.5sec)
	
	class SoundDSound;

	class SoundEffectDSound : public SoundEffectImpl {
	private:
		LPDIRECTSOUNDBUFFER		m_IDSBuffer;
	public:
		SoundEffectDSound( LPDIRECTSOUNDBUFFER buf,SampleType type,UInt32 freq,UInt32 size );
		~SoundEffectDSound();
		LPDIRECTSOUNDBUFFER buffer() { return m_IDSBuffer; }
	};

	class SoundInstanceDSound;
	class SoundChannelDSound {
	private:
		SoundEffectDSound*		m_parent;
		LPDIRECTSOUNDBUFFER		m_IDSBuffer;
		bool	m_loop;
		bool	m_paused;
		bool	m_started;
		SoundInstanceDSound*	m_instance;
	public:
		explicit SoundChannelDSound(SoundEffectDSound* parent,LPDIRECTSOUNDBUFFER buf);
		~SoundChannelDSound();
		SoundEffectDSound* GetParent();
		bool IsPlaying() const ;
		void Play(bool loop) ;
		void Pause() ;
		void Stop() ;
		void SetVolume(float val) ;
		void SetPan(float pan) ;

		void SetInstance( SoundInstanceDSound* instance );

		void Clear();
		void Process();
	};

	class SoundInstanceDSound : public RefCounterImpl<SoundInstance> {
	private:
		SoundChannelDSound*	m_channel;
	public:
		explicit SoundInstanceDSound( SoundChannelDSound* channel);
		void Reset();
		/// set volume (0-100)
        virtual void GHL_CALL SetVolume( float vol );
        /// set pan (-100..0..+100)
        virtual void GHL_CALL SetPan( float pan );
        /// stop
        virtual void GHL_CALL Stop();
	};

	class SoundDSound : public SoundImpl {
	private:
		HINSTANCE       m_library;
		LPDIRECTSOUND8	m_IDS;
		LPDIRECTSOUNDBUFFER m_IDSBPrimary;
		HRESULT InitPrimaryBuffer();
		std::list<SoundChannelDSound*> m_channels;
		size_t	m_max_channels;
		SoundChannelDSound* GetChannel( SoundEffectDSound* effect );
	public:
		explicit SoundDSound(size_t max_channels);
		~SoundDSound();

		bool SoundInit(HWND hwnd);
		virtual bool SoundDone();

		void Process();

		/// create sound effect from data
        virtual SoundEffect* GHL_CALL CreateEffect( SampleType type, UInt32 freq, Data* data );
        /// play effect
        virtual void GHL_CALL PlayEffect( SoundEffect* effect , float vol, float pan, SoundInstance** instance);
		/// open music
        virtual MusicInstance* GHL_CALL OpenMusic( GHL::DataStream* file );
	};
}


#endif /*GHL_SOUND_DSOUND_H*/