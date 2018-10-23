#include "opensl_audio_engine.h"
#include "../../ghl_log_impl.h"
#include <assert.h>
#include <unistd.h>

namespace GHL {
    
    static const char* MODULE = "OpenSL";
    static const size_t MAX_EFFECTS_CHANNELS = 4;
    static const size_t MAX_MUSIC_CHANNELS = 2;
    
    OpenSLAudioEngine::OpenSLAudioEngine() : m_engine_obj(0),m_output_mix_obj(0) {
        SLresult result;
        
        const SLuint32 engine_mix_count = 1;
        const SLInterfaceID engine_mix_IIDs[engine_mix_count] = {SL_IID_ENGINE};
        const SLboolean engine_mix_reqs[engine_mix_count] = {SL_BOOLEAN_TRUE};
        const SLuint32 output_mix_count = 0;
        const SLInterfaceID output_mix_IIDs[output_mix_count] = {};
        const SLboolean output_mix_reqs[output_mix_count] = { };
        
        result = slCreateEngine(&m_engine_obj, //pointer to object
                                0, // count of elements is array of additional options
                                NULL, // array of additional options
                                engine_mix_count, // interface count
                                engine_mix_IIDs, // array of interface ids
                                engine_mix_reqs);
        
        if (result != SL_RESULT_SUCCESS ) {
            LOG_ERROR("failed slCreateEngine");
            return;
        }
        
        result = (*m_engine_obj)->Realize(m_engine_obj, SL_BOOLEAN_FALSE );
        
        if (result != SL_RESULT_SUCCESS ) {
            LOG_ERROR("failed m_engine_obj->Realize");
            return;
        }
        
        result = (*m_engine_obj)->GetInterface(m_engine_obj, SL_IID_ENGINE, &m_engine);
        
        if (result != SL_RESULT_SUCCESS ) {
            LOG_ERROR("failed m_engine_obj->GetInterface");
            return;
        }
        
        result = (*m_engine)->CreateOutputMix(m_engine, &m_output_mix_obj,
                                            output_mix_count, output_mix_IIDs, output_mix_reqs);
        
        if (result != SL_RESULT_SUCCESS ) {
            LOG_ERROR("failed m_engine->CreateOutputMix");
            return;
        }
        
        result = (*m_output_mix_obj)->Realize(m_output_mix_obj, SL_BOOLEAN_FALSE );
        
        if (result != SL_RESULT_SUCCESS ) {
            LOG_ERROR("failed m_output_mix_obj->Realize");
            return;
        }
        
        LOG_INFO("success init");
    }
    
    bool OpenSLAudioEngine::IsValid() const {
        return m_engine_obj && m_engine_obj && m_output_mix_obj;
    }

    void OpenSLAudioEngine::SetFocus(bool focus) {

    }
    
    OpenSLAudioEngine::~OpenSLAudioEngine() {
        for (std::vector<OpenSLAudioChannel*>::const_iterator it = m_channels.begin();it!=m_channels.end();++it) {
            delete *it;
        }
        m_channels.clear();
        for ( std::vector<OpenSLPCMAudioStream*>::const_iterator it = m_music_streams.begin();it!=m_music_streams.end();++it) {
            delete *it;
        }
        m_channels.clear();
        // destroy output mix object, and invalidate all associated interfaces
        if (m_output_mix_obj != NULL) {
            (*m_output_mix_obj)->Destroy(m_output_mix_obj);
            m_output_mix_obj = NULL;
        }
        
        // destroy engine object, and invalidate all associated interfaces
        if (m_engine_obj != NULL) {
            (*m_engine_obj)->Destroy(m_engine_obj);
            m_engine_obj = NULL;
            m_engine = NULL;
        }
        LOG_INFO("destroyed");
    }
    
    OpenSLFileAudioStream* OpenSLAudioEngine::CreateFileStream(AAsset* asset) {
        off_t start, length;
        int fd = AAsset_openFileDescriptor(asset, &start, &length);
        assert(0 <= fd);
        if (fd <= 0) {
            LOG_ERROR("failed open file descriptor");
            return 0;
        }
        
        SLresult result;
        
        // configure audio source
        SLDataLocator_AndroidFD loc_fd = {SL_DATALOCATOR_ANDROIDFD, fd, start, length};
        SLDataFormat_MIME format_mime = {SL_DATAFORMAT_MIME, NULL, SL_CONTAINERTYPE_UNSPECIFIED};
        SLDataSource audio_src = {&loc_fd, &format_mime};
        
        // configure audio sink
        SLDataLocator_OutputMix loc_outmix = {SL_DATALOCATOR_OUTPUTMIX,  m_output_mix_obj};
        SLDataSink audio_snk = {&loc_outmix, NULL};
        
        // create audio player
        const SLuint32 ids_count = 5;
        const SLInterfaceID ids[ids_count] = {SL_IID_PREFETCHSTATUS, SL_IID_SEEK, SL_IID_MUTESOLO, SL_IID_VOLUME,SL_IID_PITCH};
        const SLboolean req[ids_count] = {SL_BOOLEAN_TRUE, SL_BOOLEAN_TRUE, SL_BOOLEAN_TRUE, SL_BOOLEAN_TRUE,SL_BOOLEAN_FALSE};
        
        SLObjectItf player_obj;
        
        result = (*m_engine)->CreateAudioPlayer(m_engine, &player_obj, &audio_src, &audio_snk,
                                                            ids_count, ids, req);
        
        if (result != SL_RESULT_SUCCESS) {
            LOG_ERROR("failed create audio player");
            ::close(fd);
            return 0;
        }

        
        
        // realize the player
        result = (*player_obj)->Realize(player_obj, SL_BOOLEAN_FALSE);
        if (result != SL_RESULT_SUCCESS) {
            LOG_ERROR("failed realize");
            ::close(fd);
            return 0;
        }
        
        return new OpenSLFileAudioStream(player_obj,fd);
    }
    
    static bool CompareFormat(const SLDataFormat_PCM& a,const SLDataFormat_PCM& b) {
        return a.numChannels == b.numChannels &&
            a.samplesPerSec == b.samplesPerSec &&
            a.bitsPerSample == b.bitsPerSample;
    }
    
    OpenSLAudioChannel* OpenSLAudioEngine::find_channel(SLDataFormat_PCM& format,float volume) {
        OpenSLAudioChannel* best = 0;
        size_t last_used = 0;
        for (std::vector<OpenSLAudioChannel*>::iterator it = m_channels.begin();it!=m_channels.end();++it) {
            if (CompareFormat((*it)->GetFormat(),format)) {
                if ((*it)->IsStopped()) {
                    return *it;
                }
                if (!best || ((*it)->GetLastUsed() < last_used)) {
                    if ((*it)->GetVolume() <= volume) {
			best = *it;
			last_used = (*it)->GetLastUsed();
		    }
                }
            }
        }
        if (m_channels.size() < MAX_EFFECTS_CHANNELS) {
            LOG_INFO("requested new channel: " << format.numChannels << " " << format.samplesPerSec/1000 << " " << format.bitsPerSample);
            SLDataLocator_AndroidSimpleBufferQueue locatorBufferQueue = {0};
            locatorBufferQueue.locatorType = SL_DATALOCATOR_ANDROIDSIMPLEBUFFERQUEUE;
            locatorBufferQueue.numBuffers = 2;
            SLDataSource audio_src = {&locatorBufferQueue, &format};
            // configure audio sink
            SLDataLocator_OutputMix loc_outmix = {SL_DATALOCATOR_OUTPUTMIX,  m_output_mix_obj};
            SLDataSink audio_snk = {&loc_outmix, NULL};
            
            // create audio player
            const SLuint32 ids_count = 5;
            const SLInterfaceID ids[ids_count] = {
                SL_IID_ANDROIDSIMPLEBUFFERQUEUE,
                SL_IID_PLAY, 
                SL_IID_SEEK, 
                SL_IID_VOLUME, 
                SL_IID_PITCH};
            const SLboolean req[ids_count] = {
                SL_BOOLEAN_TRUE,
                SL_BOOLEAN_TRUE, 
                SL_BOOLEAN_FALSE, 
                SL_BOOLEAN_TRUE,
                SL_BOOLEAN_FALSE};
            
            SLObjectItf player_obj;
            
            SLresult result = (*m_engine)->CreateAudioPlayer(m_engine, &player_obj, &audio_src, &audio_snk,
                                                    ids_count, ids, req);
            
            if (result != SL_RESULT_SUCCESS) {
                LOG_ERROR("CreateAudioPlayer failed " << result);
                return 0;
            }
            
            // realize the player
            result = (*player_obj)->Realize(player_obj, SL_BOOLEAN_FALSE);
            if (result != SL_RESULT_SUCCESS) {
                LOG_ERROR("Realize player failed " << result);
                return 0;
            }
            
            best = new OpenSLAudioChannel(player_obj,format);
            
            m_channels.push_back(best);
                                                    
        }
        if (best) {
            best->UpdateLastUsed();
        }
        return best;
    }

     OpenSLPCMAudioStream* OpenSLAudioEngine::find_stream( SLDataFormat_PCM& format ) {
        OpenSLPCMAudioStream* best = 0;
        float min_volume = 100;
        for (std::vector<OpenSLPCMAudioStream*>::iterator it = m_music_streams.begin();it!=m_music_streams.end();++it) {
            if (CompareFormat((*it)->GetFormat(),format)) {
                if ((*it)->IsStopped()) {
                    return *it;
                }
                if (!best || ((*it)->GetVolume() < min_volume)) {
                    best = *it;
                    min_volume = (*it)->GetVolume();
                }
            }
        }
        if (m_music_streams.size() < MAX_MUSIC_CHANNELS || !best) {
            LOG_INFO("requested new stream : " << format.numChannels << " " << format.samplesPerSec/1000 << " " << format.bitsPerSample);
            SLDataLocator_AndroidSimpleBufferQueue locatorBufferQueue = {0};
            locatorBufferQueue.locatorType = SL_DATALOCATOR_ANDROIDSIMPLEBUFFERQUEUE;
            locatorBufferQueue.numBuffers = 2;
            SLDataSource audio_src = {&locatorBufferQueue, &format};
            // configure audio sink
            SLDataLocator_OutputMix loc_outmix = {SL_DATALOCATOR_OUTPUTMIX,  m_output_mix_obj};
            SLDataSink audio_snk = {&loc_outmix, NULL};
            
            // create audio player
            // create audio player
            const SLuint32 ids_count = 5;
            const SLInterfaceID ids[ids_count] = {
                SL_IID_ANDROIDSIMPLEBUFFERQUEUE,
                SL_IID_PLAY, 
                SL_IID_SEEK, 
                SL_IID_VOLUME, 
                SL_IID_PITCH};
            const SLboolean req[ids_count] = {
                SL_BOOLEAN_TRUE,
                SL_BOOLEAN_TRUE, 
                SL_BOOLEAN_FALSE, 
                SL_BOOLEAN_TRUE,
                SL_BOOLEAN_FALSE};
            
            SLObjectItf player_obj;
            
            SLresult result = (*m_engine)->CreateAudioPlayer(m_engine, &player_obj, &audio_src, &audio_snk,
                                                    ids_count, ids, req);
            
            if (result != SL_RESULT_SUCCESS) {
                LOG_ERROR("CreateAudioPlayer failed " << result);
                return 0;
            }
            
            // realize the player
            result = (*player_obj)->Realize(player_obj, SL_BOOLEAN_FALSE);
            if (result != SL_RESULT_SUCCESS)
                return 0;
            
            best = new OpenSLPCMAudioStream(player_obj,format);
            
            m_music_streams.push_back(best);
                                                    
        }
        return best;
     }
    
    OpenSLAudioChannel* OpenSLAudioEngine::GetChannel(int freq,int channels,int bits,float volume) {
        SLDataFormat_PCM formatPCM = {0};
        formatPCM.formatType = SL_DATAFORMAT_PCM;
        formatPCM.numChannels = channels;
        formatPCM.samplesPerSec = freq*1000;
        formatPCM.bitsPerSample = bits ;//header.bitsPerSample;
        formatPCM.containerSize = bits;// header.fmtSize;
        formatPCM.channelMask = channels == 2 ? (SL_SPEAKER_FRONT_LEFT|SL_SPEAKER_FRONT_RIGHT) : SL_SPEAKER_FRONT_CENTER;
        formatPCM.endianness = SL_BYTEORDER_LITTLEENDIAN;
        return find_channel(formatPCM, volume);
    }
    OpenSLPCMAudioStream* OpenSLAudioEngine::GetPCMStream(int freq,int channels,int bits) {
        SLDataFormat_PCM formatPCM = {0};
        formatPCM.formatType = SL_DATAFORMAT_PCM;
        formatPCM.numChannels = channels;
        formatPCM.samplesPerSec = freq*1000;
        formatPCM.bitsPerSample = bits ;//header.bitsPerSample;
        formatPCM.containerSize = bits;// header.fmtSize;
        formatPCM.channelMask = channels == 2 ? (SL_SPEAKER_FRONT_LEFT|SL_SPEAKER_FRONT_RIGHT) : SL_SPEAKER_FRONT_CENTER;
        formatPCM.endianness = SL_BYTEORDER_LITTLEENDIAN;
        return find_stream(formatPCM);
    }
    
}
