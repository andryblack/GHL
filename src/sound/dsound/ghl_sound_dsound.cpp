#include "ghl_sound_dsound.h"
#include <iostream>
#include <cassert>
#include <algorithm>

namespace GHL {

	const int bitCount = 16; 
	const int channelCount = 2; 
	const int sampleRate = 44100;


	SoundChannelDSound::SoundChannelDSound(SoundDSound* parent,LPDIRECTSOUNDBUFFER buf,SampleType type,UInt32 freq) :
		m_parent(parent),m_IDSBuffer(buf),m_type(type),m_freq(freq){
			m_paused = true;
			m_loop = false;
			m_started = false;
			m_write_pos = 0;
			m_current_buf = 0;
			m_current_read = 0;
			m_end = false;
			m_bps = SoundImpl::SampleSize(m_type);
	}
	SoundChannelDSound::~SoundChannelDSound() {
		if (m_IDSBuffer) 
			m_IDSBuffer->Release();
		m_IDSBuffer = 0;
	}


	void GHL_CALL SoundChannelDSound::Release() {
		m_parent->ReleaseChannel(this);
	}
	bool GHL_CALL SoundChannelDSound::IsPlaying() const {
		if (m_IDSBuffer==0) return false;
		DWORD status;
		HRESULT rv = m_IDSBuffer->GetStatus(&status);
		return (SUCCEEDED(rv) && ( status & DSBSTATUS_PLAYING) );
	}
	void GHL_CALL SoundChannelDSound::Play(bool loop) {
		if (m_IDSBuffer==0) return;
		if (m_buffers.empty()) return;
		if (m_started) return;
		if (!m_paused) {
			m_current_read = 0;
			m_write_pos = 0;
			m_current_buf = 0;
			m_IDSBuffer->SetCurrentPosition(0);
			m_end = false;
			UInt32 len = m_buffers.front().buf->Size();
			if (len>BUFFER_SIZE*m_bps)
				len = BUFFER_SIZE*m_bps;
			WriteToBuffer(len);
		}
		HRESULT hr = m_IDSBuffer->Play(0, 0,  DSBPLAY_LOOPING );
		if (DSERR_BUFFERLOST == hr)
		{
			m_IDSBuffer->Restore();
			hr = m_IDSBuffer->Play(0, 0, DSBPLAY_LOOPING );
		}
		if (SUCCEEDED(hr)) {
			m_loop = loop;
			m_paused = false;
			m_started = true;
		}
	}
	void GHL_CALL SoundChannelDSound::Pause() {
		if (m_IDSBuffer==0) return;
		m_paused = IsPlaying();
		if (m_paused)
			m_IDSBuffer->Stop();
	}
	void GHL_CALL SoundChannelDSound::Stop() {
		if (m_IDSBuffer==0) return;
		m_paused = false;
		m_current_read = 0;
		m_write_pos = 0;
		m_current_buf = 0;
		m_IDSBuffer->Stop();
		m_started = false;
	}
	void GHL_CALL SoundChannelDSound::SetVolume(float vol) {
		if (m_IDSBuffer==0) return;
		LONG val = static_cast<LONG>(DSBVOLUME_MIN + vol * (DSBVOLUME_MAX - DSBVOLUME_MIN));
		m_IDSBuffer->SetVolume(val);
	}

	void SoundChannelDSound::Clear() {
		Stop();
		m_buffers.clear();
		m_current_buf = 0;
		m_current_read = 0;
		m_loop = false;
		m_started = false;
	}
	void SoundChannelDSound::AddBuffer(SamplesBufferMemory* mem) {
		Buffer buf;
		buf.buf = mem;
		m_buffers.push_back(buf);
	}
	bool SoundChannelDSound::Read(Byte* buf,UInt32 bytes,UInt32& readed) {
		readed = 0;
		if (m_end) return false;
		if (m_current_buf<m_buffers.size()) {
			while (bytes) {
				UInt32 bufSize = m_buffers[m_current_buf].buf->Size();
				UInt32 len = bytes;
				if (len>(bufSize-m_current_read)) {
					len = bufSize-m_current_read;
				}
				m_buffers[m_current_buf].buf->GetData(m_current_read,buf,len);
				buf+=len;
				readed+=len;
				m_current_read+=len;
				if (m_current_read>=bufSize) {
					m_current_read = 0;
					m_current_buf++;
					if (m_current_buf>=m_buffers.size()) {
						m_current_buf = 0;
						if (!m_loop) {
							m_end = true;
							return false;
						}
					}
				}
				bytes-=len;
			}
		} else {
			return false;
		}
		return true;
	}
	
	void SoundChannelDSound::WriteToBuffer(UInt32 bytes) {
		Byte *pPtr1 = 0, *pPtr2 = 0;
		DWORD dwSize1 = 0, dwSize2 = 0;
		HRESULT hr;
		bool set_stop = false;
		hr = m_IDSBuffer->Lock(m_write_pos, bytes, reinterpret_cast<void**>(&pPtr1), &dwSize1, reinterpret_cast<void**>(&pPtr2), &dwSize2, 0);
			if (DSERR_BUFFERLOST == hr)
			{
				m_IDSBuffer->Restore();
				hr = m_IDSBuffer->Lock(m_write_pos, bytes, reinterpret_cast<void**>(&pPtr1), &dwSize1, reinterpret_cast<void**>(&pPtr2), &dwSize2, 0);
			}

			assert((dwSize1%m_bps)==0);
			assert((dwSize2%m_bps)==0);

			if (SUCCEEDED(hr))
			{
				UInt32 size_1 = dwSize1;
				UInt32 size_2 = dwSize2;
				UInt32 read = 0;
				UInt32 nReaded = 0;
				if (pPtr1)
				{
					if (!Read(pPtr1,size_1,nReaded)) {
						m_silense_begin = m_write_pos+nReaded;
						FillMemory(pPtr1 + nReaded, dwSize1 - nReaded, 0);
						set_stop = true;
					}
					read+=nReaded;
				}
				if (pPtr2)
				{
					nReaded = 0;
					if (!Read(pPtr2,size_2,nReaded)) {
						m_silense_begin = nReaded;
						FillMemory(pPtr2 + nReaded, dwSize2 - nReaded, 0);
					}
					read+=nReaded;
				}
				m_IDSBuffer->Unlock(pPtr1, dwSize1, pPtr2, dwSize2);
				m_write_pos=(m_write_pos+read)%(BUFFER_SIZE*m_bps);
			}
			if (set_stop) {
				m_IDSBuffer->Stop();
				m_IDSBuffer->Play(0,0,0);
			}
	}

	void SoundChannelDSound::Process() {
		if (m_paused) return;
		if (!m_started) return;
		if (m_end && !IsPlaying()) {
			m_started = false;
			return;
		}
		DWORD dwReadPos = 0;
		HRESULT hr;
		DWORD dwWritePos;
		if (SUCCEEDED(hr = m_IDSBuffer->GetCurrentPosition(&dwReadPos, &dwWritePos)))
		{
			assert((dwReadPos%m_bps)==0);
			assert((dwWritePos%m_bps)==0);

			UInt32 read_length = 0;
		    if ((dwReadPos) < m_write_pos) {
				read_length = dwReadPos + BUFFER_SIZE*m_bps - m_write_pos;
			} else {
				read_length = dwReadPos - m_write_pos;
			}
			
			if (read_length <= 44100*m_bps/10) { ///0.1sec
			  return;
			} 			

			//std::cout << "w: " << m_write_pos << " rw: " << dwWritePos << " r: "<<dwReadPos << " s: " << read_length<<std::endl;
			
			WriteToBuffer(read_length);
		}
	}



	SoundDSound::SoundDSound() : m_IDS(0),m_IDSBPrimary(0) {
		m_library = 0;
	}

	SoundDSound::~SoundDSound() {
	}

	typedef HRESULT ( WINAPI * DirectSoundCreate8_Func ) (LPCGUID pcGuidDevice, LPDIRECTSOUND8 *ppDS8, LPUNKNOWN pUnkOuter );

	bool SoundDSound::SoundInit(HWND hwnd) {
		m_library = LoadLibrary( TEXT("dsound.dll") );
		if (!m_library) {
			std::cout << "[SOUND] error loading dsound.dll" << std::endl;
			return false;
		}
		DirectSoundCreate8_Func func = (DirectSoundCreate8_Func)(GetProcAddress(m_library, "DirectSoundCreate8"));
		if (!func) {
			std::cout << "[SOUND] error dsound.dll not have entry point DirectSoundCreate8" << std::endl;
			return false;
		}
		HRESULT hr = 0; 
		if (FAILED(hr = func(NULL, &m_IDS, NULL))) { 
			std::cout << "[SOUND] error create DirectSound8 interface" << std::endl;
			return false;
		}

		if ((SUCCEEDED(hr = m_IDS->SetCooperativeLevel(hwnd, DSSCL_PRIORITY))) && 
			(SUCCEEDED(InitPrimaryBuffer()) ) )
		{
			std::cout << "[SOUND] DS: primary buffer in priority mode" << std::endl;
			WAVEFORMATEX format;
			if (SUCCEEDED(hr = m_IDSBPrimary->GetFormat(&format,sizeof(format),0)))
			{
				std::cout << "[SOUND] DS: primary buffer format : " << static_cast<int>(format.wBitsPerSample)
						<< " bps, " << static_cast<int>(format.nChannels) 
						<< " channels, "<< static_cast<int>(format.nSamplesPerSec) <<" Hz" << std::endl;
			}
		} else {
			
			
			if (SUCCEEDED(hr = m_IDS->SetCooperativeLevel(hwnd, DSSCL_NORMAL))) {
				std::cout << "[SOUND] DS: primary buffer in normal mode" << std::endl;
			} else
			{
				std::cout << "[SOUND] DS error init primary buffer" << std::endl;
				return false;
			}
		}
		
		
		
		
		DSCAPS caps;
		ZeroMemory(&caps,sizeof(caps));
		caps.dwSize = sizeof(caps);
		if (SUCCEEDED(hr = m_IDS->GetCaps(&caps)))
		{
			std::cout << "[SOUND] DS: primary support 8bps     : " << ( ( caps.dwFlags & DSCAPS_PRIMARY8BIT ) ? "yes" : "no" ) << std::endl;
			std::cout << "[SOUND] DS: primary support 16bps    : " << (( caps.dwFlags & DSCAPS_PRIMARY16BIT ) ? "yes" : "no") << std::endl;
			std::cout << "[SOUND] DS: primary support stereo   : " << (( caps.dwFlags & DSCAPS_PRIMARYSTEREO  ) ? "yes" : "no") << std::endl;
	
			std::cout << "[SOUND] DS: secondary support 8bps   : " << (( caps.dwFlags & DSCAPS_SECONDARY8BIT ) ? "yes" : "no") << std::endl;
			std::cout << "[SOUND] DS: secondary support 16bps  : " << (( caps.dwFlags & DSCAPS_SECONDARY16BIT ) ? "yes" : "no") << std::endl;
			std::cout << "[SOUND] DS: secondary support stereo : " << (( caps.dwFlags & DSCAPS_SECONDARYSTEREO  ) ? "yes" : "no") << std::endl;
			
		}

		return true;
	}

	HRESULT SoundDSound::InitPrimaryBuffer()
	{
		std::cout << "[SOUND] DS: try set primary buffer "<<sampleRate<<" Hz, "<<bitCount<<" bps, "<<channelCount<<" channels"<<std::endl;
		
		HRESULT hr = S_OK;
		WAVEFORMATEX waveFormat; 
		ZeroMemory(&waveFormat, sizeof(waveFormat)); 
		
		waveFormat.cbSize = 0; 
		waveFormat.wFormatTag = WAVE_FORMAT_PCM; 
		waveFormat.nChannels = (WORD)channelCount; 
		waveFormat.nSamplesPerSec = sampleRate; 
		waveFormat.nBlockAlign = channelCount * bitCount / 8; 
		waveFormat.nAvgBytesPerSec = sampleRate * waveFormat.nBlockAlign; 
		waveFormat.wBitsPerSample = (WORD)bitCount; 
		
		DSBUFFERDESC bufferDesc; 
		ZeroMemory(&bufferDesc, sizeof(DSBUFFERDESC)); 
		bufferDesc.dwSize = sizeof(DSBUFFERDESC); 
		bufferDesc.dwFlags = DSBCAPS_PRIMARYBUFFER; 
		bufferDesc.dwBufferBytes = 0; 
		bufferDesc.lpwfxFormat = 0; 
		
		if (SUCCEEDED(hr = m_IDS->CreateSoundBuffer(&bufferDesc, &m_IDSBPrimary, 0))) { 
		  if (FAILED(hr = m_IDSBPrimary->SetFormat(&waveFormat))) { 
			  std::cout << "[SOUND] DS:  SetFormat failed" << std::endl;
			if (hr==DSERR_BADFORMAT)
				std::cout << "[SOUND] DS: DSERR_BADFORMAT" << std::endl;
			else if (hr==DSERR_UNSUPPORTED)
				std::cout << "[SOUND] DS: DSERR_UNSUPPORTED" << std::endl;
			else if (hr==DSERR_INVALIDPARAM)
				std::cout << "[SOUND] DS: DSERR_INVALIDPARAM" << std::endl;

		  } else
		  {
  			return S_OK; 
		  }
		  m_IDSBPrimary->Release(); 
		  m_IDSBPrimary = 0;
		} else
		{
		}

		return hr;	
	}

	void SoundDSound::SoundDone() {
		if (m_IDSBPrimary) {
			m_IDSBPrimary->Release();
			m_IDSBPrimary = 0;
		}
		if (m_IDS) {
			m_IDS->Release();
			m_IDS = 0;
		}
		if (m_library) {
			FreeLibrary(m_library);
			m_library = 0;
		}
	}


	/// create samples buffer
	SamplesBuffer* GHL_CALL SoundDSound::CreateBuffer(SampleType type,UInt32 size,UInt32 freq,const Byte* data) {
		SamplesBufferMemory* buf = new SamplesBufferMemory(type,size,freq);
		buf->SetData(0,data,size*buf->SampleSize());
		return buf;
	}
	
	/// create channel
	SoundChannel* GHL_CALL SoundDSound::CreateChannel(SampleType type,UInt32 freq) {
		if (!m_IDS) return 0;
        WAVEFORMATEX waveFormat;
        DSBUFFERDESC bufferDesc;
        ZeroMemory(&waveFormat, sizeof(WAVEFORMATEX));
        ZeroMemory(&bufferDesc, sizeof(DSBUFFERDESC));

        waveFormat.cbSize           = 0;
        waveFormat.wFormatTag       = WAVE_FORMAT_PCM;
		if (type==SAMPLE_TYPE_MONO_8  || type==SAMPLE_TYPE_MONO_16)
			waveFormat.nChannels        = 1;
		if (type==SAMPLE_TYPE_STEREO_8  || type==SAMPLE_TYPE_STEREO_16)
			waveFormat.nChannels        = 2;
        waveFormat.nSamplesPerSec   = freq;
        waveFormat.wBitsPerSample   = SampleSize(type)*8/waveFormat.nChannels;
        waveFormat.nBlockAlign      = waveFormat.nChannels * waveFormat.wBitsPerSample/8;
        waveFormat.nAvgBytesPerSec  = waveFormat.nSamplesPerSec * waveFormat.nBlockAlign;
        const UInt32 nSoundLen         = BUFFER_SIZE * waveFormat.nBlockAlign;
        bufferDesc.dwSize           = sizeof(DSBUFFERDESC);
        bufferDesc.dwFlags          = DSBCAPS_CTRLPAN | DSBCAPS_CTRLVOLUME | DSBCAPS_CTRLFREQUENCY | DSBCAPS_GETCURRENTPOSITION2 |DSBCAPS_STICKYFOCUS ;
        bufferDesc.dwBufferBytes    = nSoundLen;
        bufferDesc.lpwfxFormat      = &waveFormat;
        HRESULT hr;
        IDirectSoundBuffer *pdsBuffer;
		if (SUCCEEDED(hr = m_IDS->CreateSoundBuffer(&bufferDesc, &pdsBuffer, 0)))
        {
			SoundChannelDSound* ch = new SoundChannelDSound(this,pdsBuffer,type,freq);
			m_channels.push_back(ch);
			return ch;
        }
        return 0;
	}

	void SoundDSound::ReleaseChannel(SoundChannelDSound* ch) {
		std::vector<SoundChannelDSound*>::iterator it = std::find(m_channels.begin(),m_channels.end(),ch);
		if (it!=m_channels.end()) {
			m_channels.erase(it);
			delete ch;
		}
	}

	void GHL_CALL SoundDSound::ChannelClear(SoundChannel* channel) {
		SoundChannelDSound* ch = reinterpret_cast<SoundChannelDSound*>(channel);
		ch->Clear();
	}

	void GHL_CALL SoundDSound::ChannelAddBuffer(SoundChannel* channel,SamplesBuffer* buffer) {
		SoundChannelDSound* ch = reinterpret_cast<SoundChannelDSound*>(channel);
		SamplesBufferMemory* buf = reinterpret_cast<SamplesBufferMemory*>(buffer);
		ch->AddBuffer(buf);
	}

	void SoundDSound::Process() {
		for (size_t i=0;i<m_channels.size();i++) {
			m_channels[i]->Process();
		}
	}
}
