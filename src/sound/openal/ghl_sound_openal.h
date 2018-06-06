/*
 *  ghl_sound_openal.h
 *  SR
 *
 *  Created by Андрей Куницын on 27.02.11.
 *  Copyright 2011 andryblack. All rights reserved.
 *
 */

#ifndef GHL_SOUND_OPENAL_H
#define GHL_SOUND_OPENAL_H

#include "../ghl_sound_impl.h"
#include "ghl_openal.h"
#include <list>

namespace GHL {
	
	class SoundEffectOpenAL : public SoundEffectImpl {
	private:
		ALuint m_buffer;
	public:
		SoundEffectOpenAL(SampleType type, UInt32 freq);
		~SoundEffectOpenAL();
		void SetData(const Byte* data, UInt32 bytes);
		ALuint buffer() const { return m_buffer;}
	};
	
    
    class SoundChannelOpenAL;
	
	class SoundOpenAL {
	private:
		ALCdevice* m_device;
		ALCcontext* m_context;
		SoundOpenAL(const SoundOpenAL&);
		SoundOpenAL& operator = (const SoundOpenAL&);
        SoundChannelOpenAL* GetChannel(float vol);
        SoundChannelOpenAL* CreateChannel();
        std::list<SoundChannelOpenAL*>  m_channels;
        size_t  m_max_channels;
	public:
		explicit SoundOpenAL(size_t max_channels);
        ~SoundOpenAL();
		
		bool SoundInit();
		bool SoundDone();
        void Suspend();
        void Resume();
		
        /// create sound effect from data
        SoundEffect* CreateEffect( SampleType type, UInt32 freq, Data* data );
        /// play effect
        void PlayEffect( SoundEffect* effect , float vol , float pan, SoundInstance** instance );
	};
	
}


#endif /*GHL_SOUND_OPENAL_H*/
