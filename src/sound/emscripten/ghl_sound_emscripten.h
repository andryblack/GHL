/*
 *  ghl_sound_emscripten.h
 */

#ifndef GHL_SOUND_EMSCRIPTEN_H
#define GHL_SOUND_EMSCRIPTEN_H

#include "../ghl_sound_impl.h"
#include <list>

namespace GHL {
	
	class SoundEffectEmscripten : public SoundEffectImpl {
	private:
		int m_buffer;
    public:
		SoundEffectEmscripten(SampleType type, UInt32 freq, int buffer);
		~SoundEffectEmscripten();
		int get_handle() const { return m_buffer; }
	};

	class EmscriptenDecodeMusic : public RefCounterImpl<MusicInstance> { 
    private:
        SoundDecoder* m_decoder;
        int m_handle;
        Byte* m_buffer;
        bool m_loop;
    public:
        explicit EmscriptenDecodeMusic(SoundDecoder* decoder,int handle);
        ~EmscriptenDecodeMusic();

        
        virtual void GHL_CALL SetVolume( float vol );
        virtual void GHL_CALL SetPan( float pan );
        virtual void GHL_CALL SetPitch( float pitch );
        virtual void GHL_CALL Stop();
        virtual void GHL_CALL Pause();
        virtual void GHL_CALL Resume();
        virtual void GHL_CALL Play( bool loop );

        bool decodeChunk();

    };
	
    
	class SoundEmscripten : public SoundImpl {
	private:
		SoundEmscripten(const SoundEmscripten&);
		SoundEmscripten& operator = (const SoundEmscripten&);
        bool m_supported;
    public:
		explicit SoundEmscripten();
        ~SoundEmscripten();
		
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


#endif /*GHL_SOUND_EMSCRIPTEN_H*/