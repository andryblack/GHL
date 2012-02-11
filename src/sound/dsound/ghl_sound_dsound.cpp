#include "ghl_sound_dsound.h"
#include "../../ghl_log_impl.h"
#include <cassert>
#include <algorithm>

namespace GHL {

	static const char* MODULE = "SOUND";

	const int bitCount = 16; 
	const int channelCount = 2; 
	const int sampleRate = 44100;


	

	SoundDSound::SoundDSound() : m_IDS(0),m_IDSBPrimary(0) {
		m_library = 0;
	}

	SoundDSound::~SoundDSound() {
	}

	typedef HRESULT ( WINAPI * DirectSoundCreate8_Func ) (LPCGUID pcGuidDevice, LPDIRECTSOUND8 *ppDS8, LPUNKNOWN pUnkOuter );

	bool SoundDSound::SoundInit(HWND hwnd) {
		m_library = LoadLibrary( TEXT("dsound.dll") );
		if (!m_library) {
			LOG_ERROR( "error loading dsound.dll" );
			return false;
		}
		DirectSoundCreate8_Func func = (DirectSoundCreate8_Func)(GetProcAddress(m_library, "DirectSoundCreate8"));
		if (!func) {
			LOG_ERROR( "dsound.dll not have entry point DirectSoundCreate8" );
			return false;
		}
		HRESULT hr = 0; 
		if (FAILED(hr = func(NULL, &m_IDS, NULL))) { 
			LOG_ERROR( "error create DirectSound8 interface" );
			return false;
		}

		if ((SUCCEEDED(hr = m_IDS->SetCooperativeLevel(hwnd, DSSCL_PRIORITY))) && 
			(SUCCEEDED(InitPrimaryBuffer()) ) )
		{
			LOG_INFO( "primary buffer in priority mode" );
			WAVEFORMATEX format;
			if (SUCCEEDED(hr = m_IDSBPrimary->GetFormat(&format,sizeof(format),0)))
			{
				LOG_INFO( "primary buffer format : " << static_cast<int>(format.wBitsPerSample)
						<< " bps, " << static_cast<int>(format.nChannels) 
						<< " channels, "<< static_cast<int>(format.nSamplesPerSec) <<" Hz" );
			}
		} else {
			
			
			if (SUCCEEDED(hr = m_IDS->SetCooperativeLevel(hwnd, DSSCL_NORMAL))) {
				LOG_INFO( "primary buffer in normal mode" );
			} else
			{
				LOG_INFO( "error init primary buffer" );
				return false;
			}
		}
		
		
		
		
		DSCAPS caps;
		ZeroMemory(&caps,sizeof(caps));
		caps.dwSize = sizeof(caps);
		if (SUCCEEDED(hr = m_IDS->GetCaps(&caps)))
		{
			LOG_INFO( "primary support 8bps     : " << ( ( caps.dwFlags & DSCAPS_PRIMARY8BIT ) ? "yes" : "no" ) );
			LOG_INFO( "primary support 16bps    : " << (( caps.dwFlags & DSCAPS_PRIMARY16BIT ) ? "yes" : "no") );
			LOG_INFO( "primary support stereo   : " << (( caps.dwFlags & DSCAPS_PRIMARYSTEREO  ) ? "yes" : "no") );
	
			LOG_INFO( "secondary support 8bps   : " << (( caps.dwFlags & DSCAPS_SECONDARY8BIT ) ? "yes" : "no") );
			LOG_INFO( "secondary support 16bps  : " << (( caps.dwFlags & DSCAPS_SECONDARY16BIT ) ? "yes" : "no") );
			LOG_INFO( "secondary support stereo : " << (( caps.dwFlags & DSCAPS_SECONDARYSTEREO  ) ? "yes" : "no") );
			
		}

		return true;
	}

	HRESULT SoundDSound::InitPrimaryBuffer()
	{
		LOG_INFO( "try set primary buffer "<<sampleRate<<" Hz, "<<bitCount<<" bps, "<<channelCount<<" channels");
		
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
			  LOG_ERROR( "SetFormat failed" );
			if (hr==DSERR_BADFORMAT)
				LOG_ERROR( "DSERR_BADFORMAT");
			else if (hr==DSERR_UNSUPPORTED)
				LOG_ERROR( "DSERR_UNSUPPORTED");
			else if (hr==DSERR_INVALIDPARAM)
				LOG_ERROR( "DSERR_INVALIDPARAM");

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


	
	void SoundDSound::SoundUpdate() {
	}


	/// load effect
	SoundEffect* GHL_CALL SoundDSound::LoadEffect(DataStream* ds) {
		return 0;
	}
		/// load stream
		/// load str
	bool GHL_CALL SoundDSound::Music_Load(DataStream* ds) {
		return false;
	}

	void GHL_CALL SoundDSound::Music_Unload() {
	}

		/// play
	void GHL_CALL SoundDSound::Music_Play(bool loop) {
	}
		/// stop channel
	void GHL_CALL SoundDSound::Music_Stop() {
	}
		/// pause channel
	void GHL_CALL SoundDSound::Music_Pause() {
	}
		/// resume
	void GHL_CALL SoundDSound::Music_Resume() {
	}
	/// set channel volume
	void GHL_CALL SoundDSound::Music_SetVolume(float vol) {
	}
		/// set pan
	void GHL_CALL SoundDSound::Music_SetPan(float pan) {
	}
		/// pause all
	void GHL_CALL SoundDSound::PauseAll() {
	}
		/// resume all
	void GHL_CALL SoundDSound::ResumeAll() {
	}
		/// stop all
	void GHL_CALL SoundDSound::StopAll() {
	}

}
