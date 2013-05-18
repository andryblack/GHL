/*
 *  ghl_sound_flash.cpp
 *  SR
 *
 *  Created by Андрей Куницын on 27.02.11.
 *  Copyright 2011 andryblack. All rights reserved.
 *
 */

#include "ghl_sound_flash.h"
#include "../../ghl_log_impl.h"
#include "../ghl_sound_decoder.h"
#include <ghl_data_stream.h>
#include <cassert>

#include <AS3/AS3.h>
#include <Flash++.h>

namespace GHL {

    static const char* MODULE = "SOUND:Flash";
    
    

    SoundEffectFlash::SoundEffectFlash(SampleType type, UInt32 freq)  : SoundEffectImpl(type,freq){
	}
	SoundEffectFlash::~SoundEffectFlash() {
    }
	
	void SoundEffectFlash::SetData(const Byte* data, UInt32 bytes ) {
        UInt32 bps = SoundDecoderBase::GetBps(GetSampleType());
        SetCapacity(bytes/bps);
        
        m_data = AS3::ui::flash::utils::ByteArray::_new();
        size_t samples = GetSamplesAmount();
        float lf = 0.0f;
        float rf = 0.0f;
        if (GetSampleType()==SAMPLE_TYPE_STEREO_16) {
            for (size_t i=0;i<samples;++i) {
                lf = float( *(short*)&data[i*4+0] ) / SHRT_MAX ;
                rf = float( *(short*)&data[i*4+2] ) / SHRT_MAX ;
                
                m_data->writeFloat(lf);
                m_data->writeFloat(rf);
            }
        } else {
            LOG_ERROR("unsupported format");
        }
        
        m_data->position = 0;
        
  	}
    
    class SoundInstanceFlash;
    class SoundChannelFlash {
    private:
        SoundEffectFlash*      m_effect;
        SoundInstanceFlash*    m_instance;
        AS3::ui::flash::media::SoundChannel m_channel;
        AS3::ui::flash::media::SoundTransform m_transform;
        bool    m_played;
        int  m_position;
        
        static AS3::ui::var getDataHandler(void *arg, AS3::ui::var as3Args) {
            SoundChannelFlash* _this = (SoundChannelFlash*)arg;
            SoundEffectFlash* e = _this->m_effect;
            if (!_this->m_played || !e) return AS3::ui::internal::_undefined;
            
            
            AS3::ui::flash::events::SampleDataEvent event = AS3::ui::var(as3Args[0]);
            AS3::ui::flash::utils::ByteArray data = event->data;
            
            AS3::ui::flash::utils::ByteArray srcData = e->data();
            
            const int buf_len = 8192 * 4 * 2;
            int avaliable = int(srcData->length)-_this->m_position;
            if (avaliable<=0) {
                _this->m_played = false;
                return AS3::ui::internal::_undefined;
            }
            size_t len = std::min(avaliable,buf_len);
            data->writeBytes(srcData,_this->m_position,len);
            if (len<2048*4*2) {
                size_t add = 2048-(len/8);
                for (size_t i=0;i<add;++i) {
                    data->writeFloat(0.0f);
                    data->writeFloat(0.0f);
                }
            }
            _this->m_position += len;
            return AS3::ui::internal::_undefined;
        }
        AS3::ui::flash::media::Sound    m_sound;
        AS3::ui::Function   m_sound_data;
    public:
        SoundChannelFlash();
        ~SoundChannelFlash();
        bool IsPlaying() const;
        void Play(bool loop);
        void Pause();
        void Stop();
        void SetVolume( float val );
        void SetPan( float pan );
        void Clear();
        void SetEffect( SoundEffectFlash* effect );
        void SetInstance(SoundInstanceFlash* instance);
    };
    
    class SoundInstanceFlash: public RefCounterImpl<SoundInstance> {
    private:
        SoundChannelFlash* m_channel;
    public:
        explicit SoundInstanceFlash( SoundChannelFlash* channel ) : m_channel(channel) {
            
        }
        void Reset() {
            m_channel = 0;
        }
        /// set volume (0-100)
        virtual void GHL_CALL SetVolume( float vol ) {
            if (m_channel) {
                m_channel->SetVolume(vol);
            }
        }
        /// set pan (-100..0..+100)
        virtual void GHL_CALL SetPan( float pan ) {
            if (m_channel) {
                m_channel->SetPan(pan);
            }
        }
        /// stop
        virtual void GHL_CALL Stop() {
            if (m_channel) {
                m_channel->Stop();
            }
        }
    };
	
   	SoundChannelFlash::SoundChannelFlash() : m_effect(0){
        m_instance = 0;
        m_played = false;
        m_position = 0;
        m_sound = AS3::ui::flash::media::Sound::_new();
        m_channel = AS3::ui::flash::media::SoundChannel();
        m_transform = AS3::ui::flash::media::SoundTransform::_new();
        m_sound_data = AS3::ui::Function::_new(SoundChannelFlash::getDataHandler, this);
        m_sound->addEventListener(AS3::ui::flash::events::SampleDataEvent::SAMPLE_DATA,
                         m_sound_data);
	}
	
	SoundChannelFlash::~SoundChannelFlash() {
        Clear();
	}
	
	
	bool SoundChannelFlash::IsPlaying() const {
        return m_played;
	}
	
	void SoundChannelFlash::Play(bool loop)  {
        Stop();
        m_position = 0;
        m_played = true;
        m_channel = m_sound->play(0,0,m_transform);
    }
	
	void SoundChannelFlash::Pause() {
	}
	
	void SoundChannelFlash::Stop() {
        if (m_played) {
            m_channel->stop();
            m_played = false;
        }
   }
	
    /// set volume (0-100)
    void SoundChannelFlash::SetVolume( float vol ) {
        m_transform->volume = vol / 100.0f;
        if (m_played) {
            m_channel->soundTransform = m_transform;
        }
    }
    /// set pan (-100..0..+100)
    void SoundChannelFlash::SetPan( float pan ) {
        m_transform->pan = pan / 100.0f;
        if (m_played) {
            m_channel->soundTransform = m_transform;
        }
    }
    
	
	
	void SoundChannelFlash::Clear() {
        if (m_instance) {
            m_instance->Reset();
            m_instance->Release();
            m_instance = 0;
        }
        Stop();
        if (m_effect) {
            m_effect->Release();
            m_effect = 0;
        }
    }
	
	void SoundChannelFlash::SetEffect(SoundEffectFlash* effect) {
        effect->AddRef();
        if (m_effect!=0)
            Clear();
 	    m_effect = effect;
 	}
    
    void SoundChannelFlash::SetInstance(SoundInstanceFlash* instance) {
        instance->AddRef();
        if (m_instance) {
            m_instance->Reset();
            m_instance->Release();
        }
        m_instance = instance;
    }

    
    struct MusicInstanceFlash : RefCounterImpl<MusicInstance> {
    private:
        AS3::ui::flash::media::Sound        m_sound;
        AS3::ui::flash::media::SoundChannel m_channel;
        AS3::ui::flash::media::SoundTransform m_transform;
        size_t  m_position;
        AS3::ui::flash::utils::ByteArray    m_buffer;
        bool    m_played;
        bool    m_paused;
        bool    m_loop;
        AS3::ui::Function   m_end_func;
    public:
        
        void SetData( GHL::DataStream* file ) {
            GHL::Data* data = GHL_ReadAllData(file);
            if (data) {
                LOG_INFO("set music data: " << (int)data->GetData() << " " << data->GetSize());
                AS3::ui::flash::utils::ByteArray ba = AS3::ui::flash::utils::ByteArray::_new();
                AS3::ui::flash::utils::ByteArray mem = AS3::ui::internal::get_ram();
                ba->writeBytes(mem,(int)data->GetData(),data->GetSize());
                ba->position = 0;
                m_sound->loadCompressedDataFromByteArray(ba,data->GetSize());
                LOG_INFO("loaded " << int(ba->length) << " bytes to music");
                m_buffer = ba;
                data->Release();
            } else {
                LOG_ERROR("failed read music file");
            }
        }
        
        static AS3::ui::var endPlayHandler(void *arg, AS3::ui::var as3Args) {
            MusicInstanceFlash* _this = (MusicInstanceFlash*)arg;
            bool need_start = false;
            if (_this->m_played && !_this->m_paused && _this->m_loop) {
                need_start = true;
            }
            _this->m_played = false;
            if (need_start) {
                _this->Play(_this->m_loop);
            }
            return AS3::ui::internal::_undefined;
        }
        
        MusicInstanceFlash() {
            m_played = false;
            m_paused = false;
            m_loop = false;
            m_sound = AS3::ui::flash::media::Sound::_new();
            m_channel = AS3::ui::flash::media::SoundChannel::_new();
            m_transform = AS3::ui::flash::media::SoundTransform::_new();
            m_position = 0;
            m_end_func = AS3::ui::Function::_new(MusicInstanceFlash::endPlayHandler, this);
        }
        ~MusicInstanceFlash() {
            
        }
        
        /// pause
        virtual void GHL_CALL Pause() {
            m_position = m_channel->position;
            m_paused = true;
            if (m_played) {
                m_channel->stop();
            }
        }
        /// resume
        virtual void GHL_CALL Resume() {
            if (m_paused && m_played) {
                m_channel = m_sound->play(m_position,0,m_transform);
                m_channel->addEventListener(AS3::ui::flash::events::Event::SOUND_COMPLETE,
                                            m_end_func);
            }
        }
        /// play
        virtual void GHL_CALL Play( bool loop ) {
            if (m_played) {
                m_channel->stop();
            }
            m_played = true;
            m_paused = false;
            m_loop = loop;
            m_channel = m_sound->play(m_position,0,m_transform);
            m_channel->addEventListener(AS3::ui::flash::events::Event::SOUND_COMPLETE,
                                      m_end_func);

        }
        
        /// set volume (0-100)
        virtual void GHL_CALL SetVolume( float vol ) {
            m_transform->volume = vol / 100.0f;
            if (m_played) {
                m_channel->soundTransform = m_transform;
            }
        }
        /// set pan (-100..0..+100)
        virtual void GHL_CALL SetPan( float pan ) {
            m_transform->pan = pan / 100.0f;
            if (m_played) {
                m_channel->soundTransform = m_transform;
            }
        }
        /// stop
        virtual void GHL_CALL Stop() {
            if (m_played) {
                m_played = false;
                m_channel->stop();
            }
            m_position = 0;
            m_played = false;
            m_paused = false;
        }
    };
    
	
	SoundFlash::SoundFlash(size_t max_channels) : m_max_channels(max_channels) {
	}
	
	SoundFlash::~SoundFlash() {
	}
	
	bool SoundFlash::SoundInit() {
		LOG_INFO("SoundInit");
		return true;
	}
	
    bool SoundFlash::SoundDone() {
		LOG_INFO( "SoundDone" );
        for (std::list<SoundChannelFlash*>::iterator it=m_channels.begin();it!=m_channels.end();++it) {
            delete *it;
        }
        LOG_INFO("released " << m_channels.size() << " channels");
        m_channels.clear();
        return true;
	}
	
    
    SoundChannelFlash* SoundFlash::CreateChannel() {
      	SoundChannelFlash* channel = new SoundChannelFlash();
        m_channels.push_back(channel);
        return channel;
    }
    
	SoundChannelFlash* SoundFlash::GetChannel() {
        SoundChannelFlash* channel = 0;
        if ( m_channels.size() >= m_max_channels ) {
            for ( std::list<SoundChannelFlash*>::iterator it = m_channels.begin();it!=m_channels.end();++it) {
                if ( !(*it)->IsPlaying() ) {
                    channel = *it;
                    m_channels.erase(it);
                    m_channels.push_back(channel);
                    return channel;
                }
            }
            channel = m_channels.front();
            m_channels.pop_front();
            m_channels.push_back(channel);
        } else {
            channel = CreateChannel();
        }
        return channel;
    }
            
    /// create sound effect from data
    SoundEffect* GHL_CALL SoundFlash::CreateEffect( SampleType type, UInt32 freq, Data* data ) {
        SoundEffectFlash* effect = new SoundEffectFlash(type,freq);
        if (data) {
            effect->SetData(data->GetData(), data->GetSize());
        }
        return effect;
    }
    /// play effect
    void GHL_CALL SoundFlash::PlayEffect( SoundEffect* effect_ , float vol , float pan, SoundInstance** instance ) {
        if (!effect_) return;
        SoundChannelFlash* channel = GetChannel();
        if (!channel) return;
        
        SoundEffectFlash* effect = static_cast<SoundEffectFlash*>(effect_);
       
        channel->SetEffect(effect);
        channel->SetVolume(vol);
        channel->SetPan(pan);
        channel->Play(false);
        
        if (instance) {
            SoundInstanceFlash* inst = new SoundInstanceFlash(channel);
            channel->SetInstance(inst);
            *instance = inst;
        }
    }
    
    /// open music
    MusicInstance* GHL_CALL SoundFlash::OpenMusic( GHL::DataStream* file )  {
        //return 0;
        MusicInstanceFlash* music = new  MusicInstanceFlash();
        music->SetData(file);
        return music;
    }
	

}

