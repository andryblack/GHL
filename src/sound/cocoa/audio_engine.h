#ifndef _GHL_AUDIO_ENGINE_H_INCLUDED_
#define _GHL_AUDIO_ENGINE_H_INCLUDED_

#include "../ghl_sound_impl.h"


namespace GHL {

	
   
	class SoundAudioEngine {
	private:
        class Impl;
        Impl* m_impl;
    public:
		explicit SoundAudioEngine(size_t max_channels);
        ~SoundAudioEngine();
		
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

#endif /*_GHL_AUDIO_ENGINE_H_INCLUDED_*/
