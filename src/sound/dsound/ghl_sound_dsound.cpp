#ifndef GHL_NO_SOUND
#include "ghl_sound_dsound.h"
#include "../ghl_sound_decoder.h"
#include "../../ghl_log_impl.h"
#include <ghl_data.h>
#include <iostream>
#include <cassert>
#include <algorithm>

namespace GHL {

	const int bitCount = 16; 
	const int channelCount = 2; 
	const int sampleRate = 44100;


	static const char* MODULE = "SOUND:DS";
    

	SoundEffectDSound::SoundEffectDSound( LPDIRECTSOUNDBUFFER buf,SampleType type,UInt32 freq,UInt32 size )
		: SoundEffectImpl(type,freq),m_IDSBuffer(buf)
	{
		m_IDSBuffer->AddRef();
		SetCapacity(size);
	}
	SoundEffectDSound::~SoundEffectDSound() {
		m_IDSBuffer->Release();
	}

	SoundChannelDSound::SoundChannelDSound(SoundEffectDSound* parent,LPDIRECTSOUNDBUFFER buf) :
		m_parent(parent),m_IDSBuffer(buf), m_instance(0) {
			m_paused = true;
			m_loop = false;
			m_started = false;
			m_IDSBuffer->AddRef();
	}
	SoundChannelDSound::~SoundChannelDSound() {
		Clear();
	}

	SoundEffectDSound* SoundChannelDSound::GetParent() {
		return m_parent;
	}

	bool SoundChannelDSound::IsPlaying() const {
		if (m_IDSBuffer==0) return false;
		DWORD status;
		HRESULT rv = m_IDSBuffer->GetStatus(&status);
		return (SUCCEEDED(rv) && ( status & DSBSTATUS_PLAYING) );
	}
	void SoundChannelDSound::Play(bool loop) {
		if (m_IDSBuffer==0) return;
		if (!m_paused) {
			m_IDSBuffer->SetCurrentPosition(0);
		}
		HRESULT hr = m_IDSBuffer->Play(0, 0,  loop ? DSBPLAY_LOOPING : 0);
		if (DSERR_BUFFERLOST == hr)
		{
			m_IDSBuffer->Restore();
			hr = m_IDSBuffer->Play(0, 0, loop ? DSBPLAY_LOOPING : 0 );
		}
		if (SUCCEEDED(hr)) {
			m_loop = loop;
			m_paused = false;
			m_started = true;
		}
	}
	void SoundChannelDSound::Pause() {
		if (m_IDSBuffer==0) return;
		m_paused = IsPlaying();
		if (m_paused)
			m_IDSBuffer->Stop();
	}
	void SoundChannelDSound::Stop() {
		if (m_IDSBuffer==0) return;
		if (!m_started) return;
		m_paused = false;
		m_IDSBuffer->Stop();
		m_started = false;
	}
	void SoundChannelDSound::SetVolume(float vol) {
		if (m_IDSBuffer==0) return;
		LONG val = static_cast<LONG>(DSBVOLUME_MIN + vol * (DSBVOLUME_MAX - DSBVOLUME_MIN));
		m_IDSBuffer->SetVolume(val);
	}

	void SoundChannelDSound::SetPan(float pan) {
		if (m_IDSBuffer==0) return;
		LONG val = static_cast<LONG>( pan * DSBPAN_RIGHT );
		m_IDSBuffer->SetPan( val );
	}

	void SoundChannelDSound::Clear() {
		if (m_instance) {
			m_instance->Reset();
			m_instance->Release();
			m_instance = 0;
		}
		Stop();
		m_loop = false;
		m_started = false;
		if (m_IDSBuffer) {
			m_IDSBuffer->Release();
			m_IDSBuffer = 0;
		}
	}

	void SoundChannelDSound::SetInstance(SoundInstanceDSound* instance) {
		if (m_instance) {
			m_instance->Reset();
			m_instance->Release();
			m_instance = 0;
		}
		m_instance = instance;
		m_instance->AddRef();
	}

	
	SoundInstanceDSound::SoundInstanceDSound(SoundChannelDSound* channel) : m_channel(channel) {
	}

	void SoundInstanceDSound::Reset() {
		m_channel = 0;
	}

	/// set volume (0-100)
	void GHL_CALL SoundInstanceDSound::SetVolume( float vol ) {
		if (m_channel) {
			m_channel->SetVolume( vol ); 
		}
	}
    /// set pan (-100..0..+100)
	void GHL_CALL SoundInstanceDSound::SetPan( float pan ) {
		if (m_channel) {
			m_channel->SetPan(pan);
		}
	}
    /// stop
	void GHL_CALL SoundInstanceDSound::Stop() {
		if (m_channel) {
			m_channel->Stop(); 
		}
	}


	static HRESULT SetBufferData( IDirectSoundBuffer *pdsBuffer, Data* data ) {
		Byte *pPtr1 = 0;
		DWORD dwSize1 = 0;
		HRESULT hr = pdsBuffer->Lock(0, 0, reinterpret_cast<void**>(&pPtr1), &dwSize1, 0, 0, DSBLOCK_ENTIREBUFFER);
			
		if (SUCCEEDED(hr))
		{
				UInt32 size = dwSize1<data->GetSize()?dwSize1:data->GetSize();
				if (pPtr1)
				{
					memcpy(pPtr1,data->GetData(),size);
				}
				hr = pdsBuffer->Unlock(pPtr1, dwSize1, 0, 0);
		}
		return hr;
	}

	SoundDSound::SoundDSound(size_t max_channels) : m_IDS(0),m_IDSBPrimary(0),m_max_channels(max_channels) {
		m_library = 0;
	}

	SoundDSound::~SoundDSound() {
	}

	typedef HRESULT ( WINAPI * DirectSoundCreate8_Func ) (LPCGUID pcGuidDevice, LPDIRECTSOUND8 *ppDS8, LPUNKNOWN pUnkOuter );

	bool SoundDSound::SoundInit(HWND hwnd) {
		if (!SoundImpl::SoundInit()) return false;
		m_library = LoadLibrary( TEXT("dsound.dll") );
		if (!m_library) {
			LOG_ERROR( "failed loading dsound.dll" );
			return false;
		}
		DirectSoundCreate8_Func func = (DirectSoundCreate8_Func)(GetProcAddress(m_library, "DirectSoundCreate8"));
		if (!func) {
			LOG_ERROR( "dsound.dll not have entry point DirectSoundCreate8" );
			return false;
		}
		HRESULT hr = 0; 
		if (FAILED(hr = func(NULL, &m_IDS, NULL))) { 
			LOG_ERROR( "create DirectSound8 interface failed" );
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
				LOG_ERROR("failed init primary buffer");
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
		LOG_INFO( "try set primary buffer "<<sampleRate<<" Hz, "<<bitCount<<" bps, "<<channelCount<<" channels" );
		
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
			LOG_ERROR( "  SetFormat failed" );
			if (hr==DSERR_BADFORMAT)
				LOG_ERROR( "  DSERR_BADFORMAT" );
			else if (hr==DSERR_UNSUPPORTED)
				LOG_ERROR( "  DSERR_UNSUPPORTED" );
			else if (hr==DSERR_INVALIDPARAM)
				LOG_ERROR( "  DSERR_INVALIDPARAM" );

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

	bool SoundDSound::SoundDone() {
		for (std::list<SoundChannelDSound*>::iterator it = m_channels.begin();it!=m_channels.end();++it) {
			delete (*it);
		}
		m_channels.clear();
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
		return SoundImpl::SoundDone();
	}


	/// create sound effect from data
	SoundEffect* GHL_CALL SoundDSound::CreateEffect( SampleType type, UInt32 freq, Data* data ) {
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
		const UInt32 sampleSize = SoundDecoderBase::GetBps(type);
        waveFormat.nSamplesPerSec   = freq;
        waveFormat.wBitsPerSample   = sampleSize*8/waveFormat.nChannels;
        waveFormat.nBlockAlign      = waveFormat.nChannels * waveFormat.wBitsPerSample/8;
        waveFormat.nAvgBytesPerSec  = waveFormat.nSamplesPerSec * waveFormat.nBlockAlign;
		const UInt32 samples = data ? data->GetSize()/sampleSize : 0;
        const UInt32 nSoundLen         = samples * waveFormat.nBlockAlign;
        bufferDesc.dwSize           = sizeof(DSBUFFERDESC);
        bufferDesc.dwFlags          = DSBCAPS_CTRLPAN | DSBCAPS_CTRLVOLUME | DSBCAPS_CTRLFREQUENCY |DSBCAPS_STICKYFOCUS ;
        bufferDesc.dwBufferBytes    = nSoundLen;
        bufferDesc.lpwfxFormat      = &waveFormat;
        HRESULT hr;
        IDirectSoundBuffer *pdsBuffer;
		if (SUCCEEDED(hr = m_IDS->CreateSoundBuffer(&bufferDesc, &pdsBuffer, 0)))
        {
			SoundEffectDSound* effect = new SoundEffectDSound(pdsBuffer,type,freq,samples);
			if (data) {
				SetBufferData(pdsBuffer,data);
			}
			return effect;
        }
        return 0;
	}

	SoundChannelDSound* SoundDSound::GetChannel( SoundEffectDSound* effect ) {
		SoundChannelDSound* ch = 0;
		for (std::list<SoundChannelDSound*>::iterator it=m_channels.begin();it!=m_channels.end();++it) {
			if ( !(*it)->IsPlaying() ) {
				if ( (*it)->GetParent() == effect ) {
					ch = *it;
					m_channels.erase( it );
					m_channels.push_back( ch );
					return ch;
				}
			}
		}
		bool have_parent = false;
		for (std::list<SoundChannelDSound*>::iterator it=m_channels.begin();it!=m_channels.end();) {
			if ( (*it)->GetParent() == effect ) {
				have_parent = true;
			}
			if (m_channels.size() >= m_max_channels && !(*it)->IsPlaying()) {
				delete (*it);
				it = m_channels.erase(it);
			} else 
				++it;
		}
		if (m_channels.size()>=m_max_channels) {
			delete m_channels.front();
			m_channels.pop_front();
		}
		LPDIRECTSOUNDBUFFER buffer = effect->buffer();
		if (have_parent) {
			HRESULT hr;
			if (SUCCEEDED(hr = m_IDS->DuplicateSoundBuffer(buffer, &buffer)))
			{

			} else {
				buffer = effect->buffer();
			}
		}
		ch = new SoundChannelDSound( effect, buffer );
		m_channels.push_back( ch );
		return ch;
	}

    /// play effect
	void GHL_CALL SoundDSound::PlayEffect( SoundEffect* effect , float vol, float pan, SoundInstance** instance) {
		SoundEffectDSound* dseffect = reinterpret_cast<SoundEffectDSound*>(effect);
		SoundChannelDSound* ch = GetChannel( dseffect );
		ch->SetVolume(vol);
		ch->SetPan(pan);
		ch->Play(false);
		if ( instance ) {
			SoundInstanceDSound* inst = new SoundInstanceDSound(ch);
			ch->SetInstance(inst);
			*instance = inst;
		}
	}
	/// open music
	MusicInstance* GHL_CALL SoundDSound::OpenMusic( GHL::DataStream* file ) {
		return 0;
	}
	
	void SoundDSound::Process() {
	}
}
#endif
