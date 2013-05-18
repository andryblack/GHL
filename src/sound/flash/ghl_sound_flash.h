/*
 *  ghl_sound_flash.h
 *  SR
 *
 *  Created by Андрей Куницын on 27.02.11.
 *  Copyright 2011 andryblack. All rights reserved.
 *
 */

#ifndef GHL_SOUND_FLASH_H
#define GHL_SOUND_FLASH_H

#include "../ghl_sound_impl.h"
#include <list>
#include <AS3/AS3.h>
#include <Flash++.h>

namespace GHL {
	
	class SoundEffectFlash : public SoundEffectImpl {
	private:
        AS3::ui::flash::utils::ByteArray        m_data;
	public:
		SoundEffectFlash(SampleType type, UInt32 freq);
		~SoundEffectFlash();
		void SetData(const Byte* data, UInt32 bytes);
        const AS3::ui::flash::utils::ByteArray& data() const { return m_data;}
	};
	
    class SoundChannelFlash;
    
	class SoundFlash : public SoundImpl {
	private:
		SoundFlash(const SoundFlash&);
		SoundFlash& operator = (const SoundFlash&);
        size_t  m_max_channels;
        SoundChannelFlash* GetChannel();
        SoundChannelFlash* CreateChannel();
        std::list<SoundChannelFlash*>    m_channels;
    public:
		explicit SoundFlash(size_t max_channels);
        ~SoundFlash();
		
		bool SoundInit();
		bool SoundDone();
		
        /// create sound effect from data
        virtual SoundEffect* GHL_CALL CreateEffect( SampleType type, UInt32 freq, Data* data );
        /// play effect
        virtual void GHL_CALL PlayEffect( SoundEffect* effect , float vol , float pan, SoundInstance** instance );
        
        /// open music
        virtual MusicInstance* GHL_CALL OpenMusic( GHL::DataStream* file ) ;
	};
	
}


#endif /*GHL_SOUND_FLASH_H*/