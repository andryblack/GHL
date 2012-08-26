#ifndef GHL_SOUND_DSOUND_H
#define GHL_SOUND_DSOUND_H

#include "../ghl_sound_impl.h"
#include "ghl_dsound.h"

#include <vector>

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

#if 0
	class SoundChannelDSound {
	private:
		SoundDSound*			m_parent;
		LPDIRECTSOUNDBUFFER		m_IDSBuffer;
		SampleType		m_type;
		UInt32			m_freq;
		UInt32			m_bps;
		bool	m_loop;
		bool	m_paused;
		bool	m_started;
		bool	m_end;
		UInt32	m_silense_begin;
		size_t	m_current_buf;
		UInt32 m_current_read;
		UInt32 m_write_pos;
		bool Read(Byte* buf,UInt32 bytes,UInt32& readed);
		void WriteToBuffer(UInt32 bytes);
	public:
		SoundChannelDSound(LPDIRECTSOUNDBUFFER buf,SampleType type,UInt32 freq);
		~SoundChannelDSound();
		SampleType GetSampleType() const { return m_type;}
		UInt32 GetFrequency() const { return m_freq;}
		bool IsPlaying() const ;
		void Play(bool loop) ;
		void Pause() ;
		void Stop() ;
		void SetVolume(float val) ;

		void Clear();
		void SetBuffer(SamplesBufferMemory* buffer);
		void Process();
	};
#endif

	class SoundDSound : public SoundImpl {
	private:
		HINSTANCE       m_library;
		LPDIRECTSOUND8	m_IDS;
		LPDIRECTSOUNDBUFFER m_IDSBPrimary;
		HRESULT InitPrimaryBuffer();
		//std::vector<SoundChannelDSound*> m_channels;
	public:
		SoundDSound();
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