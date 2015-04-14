#ifndef GHL_NO_SOUND
#include "ghl_sound_dsound.h"
#include "../ghl_sound_decoder.h"
#include "../../ghl_log_impl.h"
#include <ghl_data.h>
#include <iostream>
#include <cassert>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>

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
    static void SetVolumeImpl(LPDIRECTSOUNDBUFFER buffer, float vol) {
        if (buffer==0) return;
		LONG val =log10(100.0f / vol) * -2000;
		if (val < DSBVOLUME_MIN)
			val = DSBVOLUME_MIN;
		if (val > DSBVOLUME_MAX)
			val = DSBVOLUME_MIN;
        buffer->SetVolume(val);
    }
	void SoundChannelDSound::SetVolume(float vol) {
		SetVolumeImpl(m_IDSBuffer,vol);
	}

    static void SetPanImpl(LPDIRECTSOUNDBUFFER buffer, float pan) {
        if (buffer==0) return;
        LONG val = static_cast<LONG>( pan * DSBPAN_RIGHT / 100.0f );
        buffer->SetPan( val );
    }
	void SoundChannelDSound::SetPan(float pan) {
        SetPanImpl(m_IDSBuffer,pan);
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
		SoundDone();
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
        for (std::list<MusicInstanceDSound*>::iterator it = m_music_streams.begin();it!=m_music_streams.end();++it) {
            (*it)->ResetParent();
        }
        m_music_streams.clear();
        
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

    static void fill_WAVEFORMATEX( WAVEFORMATEX& waveFormat, SampleType type, UInt32 freq ) {
        ZeroMemory(&waveFormat, sizeof(WAVEFORMATEX));
        waveFormat.cbSize           = 0;
        waveFormat.wFormatTag       = WAVE_FORMAT_PCM;
        waveFormat.nChannels        = SoundDecoderBase::GetChannels(type);
        const UInt32 sampleSize     = SoundDecoderBase::GetBps(type);
        waveFormat.nSamplesPerSec   = freq;
        waveFormat.wBitsPerSample   = sampleSize*8/waveFormat.nChannels;
        waveFormat.nBlockAlign      = waveFormat.nChannels * waveFormat.wBitsPerSample/8;
        waveFormat.nAvgBytesPerSec  = waveFormat.nSamplesPerSec * waveFormat.nBlockAlign;
    }

	/// create sound effect from data
	SoundEffect* GHL_CALL SoundDSound::CreateEffect( SampleType type, UInt32 freq, Data* data ) {
		if (!m_IDS) return 0;
        WAVEFORMATEX waveFormat;
        fill_WAVEFORMATEX( waveFormat, type, freq );
       
        DSBUFFERDESC bufferDesc;
        ZeroMemory(&bufferDesc, sizeof(DSBUFFERDESC));

        const UInt32 sampleSize     = SoundDecoderBase::GetBps(type);
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
    
    
    MusicInstanceDSound::MusicInstanceDSound(  SoundDSound* parent, SoundDecoder* decoder , LPDIRECTSOUNDBUFFER buffer , DWORD buffer_size ) : m_parent(parent),
		m_decoder(decoder), m_IDSBuffer(buffer),m_buffer_byte_size(buffer_size)  {
        m_loop = false;
        m_paused = false;
        m_started = false;
        m_cbBufOffset = 0;
		m_buffer_byte_size = buffer_size;
    }
    MusicInstanceDSound::~MusicInstanceDSound() {
        m_decoder->Release();
        if (m_parent)
            m_parent->ReleaseMusicStream(this);
        if (m_IDSBuffer) {
            m_IDSBuffer->Release();
            m_IDSBuffer = 0;
        }
    }
    void MusicInstanceDSound::ResetParent() {
        m_parent = 0;
        Stop();
    }
    
    DWORD MusicInstanceDSound::GetMaxWriteSize (void)
    {
        DWORD  dwPlayCursor, dwMaxSize;
        
        // Get current play position
        if (m_IDSBuffer->GetCurrentPosition (&dwPlayCursor, 0) == DS_OK)
        {
            if (m_cbBufOffset <= dwPlayCursor)
            {
                // Our write position trails play cursor
                dwMaxSize = dwPlayCursor - m_cbBufOffset;
            }
            
            else // (dwWriteCursor > dwPlayCursor)
            {
                // Play cursor has wrapped
                dwMaxSize = m_buffer_byte_size - m_cbBufOffset + dwPlayCursor;
            }
        }
        else
        {
            // GetCurrentPosition call failed
            //ASSERT (0);
            dwMaxSize = 0;
        }
        return (dwMaxSize);
    }
    
    DWORD   MusicInstanceDSound::WriteData(LPVOID data,DWORD size) {
        DWORD sampleSize = SoundDecoderBase::GetBps(m_decoder->GetSampleType());
        DWORD samples = (size / sampleSize);
        DWORD rsamples = 0;
        while (m_loop && samples!=0) {
			DWORD readed = m_decoder->ReadSamples(samples, static_cast<Byte*>(data));
            samples-=readed;
            rsamples+=readed;
            data = static_cast<char*>(data)+readed*sampleSize;
            if (readed < samples) {
                m_decoder->Reset();
            }
        }
        return rsamples * sampleSize;
    }
    
    void MusicInstanceDSound::Process() {
        if (!m_started)
            return;
        if (m_paused)
            return;
        DWORD size = GetMaxWriteSize();
        if (size < 16)
            return;

		LPVOID lpbuf1 = NULL;
		LPVOID lpbuf2 = NULL;
		DWORD dwsize1 = 0;
		DWORD dwsize2 = 0;

        HRESULT hr = m_IDSBuffer->Lock(m_cbBufOffset, size, &lpbuf1, &dwsize1, &lpbuf2, &dwsize2, 0);
        if (hr == DS_OK)
        {
            // Write data to sound buffer. Because the sound buffer is circular,
            // we may have to do two write operations if locked portion of buffer
            // wraps around to start of buffer.
            //ASSERT (lpbuf1);
            DWORD writen = WriteData(lpbuf1,dwsize1);
            if (writen == 0) {
                Stop();
            }
            m_cbBufOffset += writen;
            if (writen == dwsize1) {
                if (lpbuf2) {
                    writen = WriteData(lpbuf2,dwsize2);
                    m_cbBufOffset += writen;
                    if (writen != dwsize2) {
                        ::memset(static_cast<char*>(lpbuf2)+writen,dwsize2-writen,0);
                    }
                }
            } else {
                ::memset(static_cast<char*>(lpbuf1)+writen,dwsize1-writen,0);
            }
            
            // Update our buffer offset and unlock sound buffer
            m_cbBufOffset = m_cbBufOffset % m_buffer_byte_size;
			m_IDSBuffer->Unlock(lpbuf1, dwsize1, lpbuf2, dwsize2);
		}
		else {
			LOG_DEBUG("failed lock music buffer");
		}
    }
    
    /// set volume (0-100)
    void GHL_CALL MusicInstanceDSound::SetVolume( float vol ) {
        SetVolumeImpl(m_IDSBuffer,vol);
    }
    /// set pan (-100..0..+100)
    void GHL_CALL MusicInstanceDSound::SetPan( float pan ) {
		SetPanImpl(m_IDSBuffer,pan);
    }
    /// stop
    void GHL_CALL MusicInstanceDSound::Stop() {
        if (m_IDSBuffer==0) return;
        if (!m_started) return;
        m_paused = false;
        m_IDSBuffer->Stop();
        m_started = false;
        m_IDSBuffer->SetCurrentPosition(0);
        m_cbBufOffset = 0;
    }
    /// pause
    void GHL_CALL MusicInstanceDSound::Pause() {
        if (m_IDSBuffer==0) return;
        if (!m_started) return;
        m_paused = true;
        m_IDSBuffer->Stop();
    }
    /// resume
    void GHL_CALL MusicInstanceDSound::Resume() {
        m_paused = false;
        Play(m_loop);
    }
    /// play
    void GHL_CALL MusicInstanceDSound::Play( bool loop ) {
        if (m_IDSBuffer==0) return;
        m_paused = false;
        m_started = true;
		Process();
        HRESULT hr = m_IDSBuffer->Play(0, 0,  DSBPLAY_LOOPING);
        if (DSERR_BUFFERLOST == hr)
        {
            m_IDSBuffer->Restore();
            hr = m_IDSBuffer->Play(0, 0, DSBPLAY_LOOPING );
        }
        m_loop = loop;
        m_started = SUCCEEDED(hr);
    }

    
    void SoundDSound::ReleaseMusicStream(MusicInstanceDSound* music) {
        std::list<MusicInstanceDSound*>::iterator it = std::find(m_music_streams.begin(),m_music_streams.end(),music);
        if (it!=m_music_streams.end()) {
            m_music_streams.erase(it);
        }
    }


	/// open music
	MusicInstance* GHL_CALL SoundDSound::OpenMusic( GHL::DataStream* file ) {
        SoundDecoder* decoder = GHL_CreateSoundDecoder( file );
        if (!decoder)
            return 0;
        
        WAVEFORMATEX waveFormat;
        fill_WAVEFORMATEX( waveFormat, decoder->GetSampleType(), decoder->GetFrequency() );
        
        DSBUFFERDESC bufferDesc;
        ZeroMemory(&bufferDesc, sizeof(DSBUFFERDESC));
        
        const UInt32 BUFFER_SIZE = decoder->GetFrequency()/2; /// samples (0.5sec)
        
		const UInt32 sampleSize = SoundDecoderBase::GetBps(decoder->GetSampleType());
        const UInt32 nSoundLen       = BUFFER_SIZE * waveFormat.nBlockAlign;
        
        bufferDesc.dwSize           = sizeof(DSBUFFERDESC);
        bufferDesc.dwFlags          = DSBCAPS_CTRLPAN | DSBCAPS_CTRLVOLUME |DSBCAPS_STICKYFOCUS ;
        bufferDesc.dwBufferBytes    = nSoundLen;
        bufferDesc.lpwfxFormat      = &waveFormat;
        
        HRESULT hr;
        IDirectSoundBuffer *pdsBuffer = 0;
        if (SUCCEEDED(hr = m_IDS->CreateSoundBuffer(&bufferDesc, &pdsBuffer, 0)))
        {
            MusicInstanceDSound * res =  new MusicInstanceDSound( this, decoder , pdsBuffer, nSoundLen );
            m_music_streams.push_back(res);
            return res;
        }

        decoder->Release();
        return 0;
	}
	
	void SoundDSound::Process() {
        for (std::list<MusicInstanceDSound*>::iterator it = m_music_streams.begin();it!=m_music_streams.end();++it) {
            (*it)->Process();
        }
	}
}
#endif
