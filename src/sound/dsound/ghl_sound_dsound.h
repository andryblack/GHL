#ifndef GHL_SOUND_DSOUND_H
#define GHL_SOUND_DSOUND_H

#include "../ghl_sound_impl.h"
#include "../ghl_samples_buffer_memory.h"
#include "ghl_dsound.h"

#include <vector>

namespace GHL {

	const UInt32 BUFFER_SIZE = 44100/2; /// samples (0.5sec)
	
	class SoundDSound;

	class SoundChannelDSound : public SoundChannel {
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
		struct Buffer {
			SamplesBufferMemory* buf;
		};
		std::vector<Buffer> m_buffers;
		size_t	m_current_buf;
		UInt32 m_current_read;
		UInt32 m_write_pos;
		bool Read(Byte* buf,UInt32 bytes,UInt32& readed);
		void WriteToBuffer(UInt32 bytes);
	public:
		SoundChannelDSound(SoundDSound* parent,LPDIRECTSOUNDBUFFER buf,SampleType type,UInt32 freq);
		~SoundChannelDSound();
		virtual void GHL_CALL Release() ;
		virtual SampleType GHL_CALL GetSampleType() const { return m_type;}
		virtual UInt32 GHL_CALL GetFrequency() const { return m_freq;}
		virtual bool GHL_CALL IsPlaying() const ;
		virtual void GHL_CALL Play(bool loop) ;
		virtual void GHL_CALL Pause() ;
		virtual void GHL_CALL Stop() ;
		virtual void GHL_CALL SetVolume(float val) ;

		void Clear();
		void AddBuffer(SamplesBufferMemory* buffer);
		void Process();
	};

	class SoundDSound : public SoundImpl {
	private:
		HINSTANCE       m_library;
		LPDIRECTSOUND8	m_IDS;
		LPDIRECTSOUNDBUFFER m_IDSBPrimary;
		HRESULT InitPrimaryBuffer();
		std::vector<SoundChannelDSound*> m_channels;
	public:
		SoundDSound();
		~SoundDSound();

		bool SoundInit(HWND hwnd);
		virtual void SoundDone();

		void Process();

		void ReleaseChannel(SoundChannelDSound* ch);

		/// create samples buffer
		virtual SamplesBuffer* GHL_CALL CreateBuffer(SampleType type,UInt32 size,UInt32 freq,const Byte* data);
		/// create channel
		virtual SoundChannel* GHL_CALL CreateChannel(SampleType type,UInt32 freq) ;
		virtual void GHL_CALL ChannelClear(SoundChannel* channel) ;
		virtual void GHL_CALL ChannelAddBuffer(SoundChannel* channe,SamplesBuffer* buffer);
	};
}


#endif /*GHL_SOUND_DSOUND_H*/