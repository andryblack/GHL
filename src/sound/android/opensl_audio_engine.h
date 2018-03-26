#ifndef OPENSL_AUDIO_ENGINE_H_INCLUDED
#define OPENSL_AUDIO_ENGINE_H_INCLUDED

#include <SLES/OpenSLES.h>
#include <SLES/OpenSLES_Android.h>
#include <android/asset_manager.h>

#include <vector>

#include "opensl_audio_stream.h"

namespace GHL {
    
    class OpenSLAudioEngine {
    private:
        SLEngineItf m_engine;
        SLObjectItf m_engine_obj;
        SLObjectItf m_output_mix_obj;
        std::vector<OpenSLAudioChannel*> m_channels;
        std::vector<OpenSLPCMAudioStream*> m_music_streams;
        
        OpenSLAudioChannel* find_channel( SLDataFormat_PCM& format );
        OpenSLPCMAudioStream* find_stream( SLDataFormat_PCM& format );
    public:
        OpenSLAudioEngine();
        ~OpenSLAudioEngine();
        
        bool IsValid() const;
        void SetFocus(bool focus);
        
        OpenSLAudioChannel* GetChannel(int freq,int channels,int bits);
        
        OpenSLFileAudioStream* CreateFileStream(AAsset* asset);
        OpenSLPCMAudioStream* GetPCMStream(int freq,int channels,int bits);
    };
    
}

#endif /*OPENSL_AUDIO_ENGINE_H_INCLUDED*/
