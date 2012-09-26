//
//  ghl_sound_cocoa.cpp
//  GHL
//
//  Created by Andrey Kunitsyn on 8/26/12.
//  Copyright (c) 2012 AndryBlack. All rights reserved.
//

#include "ghl_sound_cocoa.h"

#include <AudioToolbox/AudioFile.h>
#include <AudioToolbox/AudioQueue.h>
#include <AudioToolbox/AudioFormat.h>

#include <ghl_data_stream.h>

#include "../../ghl_log_impl.h"

namespace GHL {
    
    static const char* MODULE = "SOUND";
    
    class MusicInstanceCocoa : public RefCounterImpl<MusicInstance> {
    private:
        AudioFileID                     m_audio_file;
        AudioStreamBasicDescription     m_data_format;
        AudioChannelLayout*             m_channel_layout;
        ::UInt32                          m_channel_layout_size;
        AudioQueueRef                   m_queue;
        static const int number_buffers = 3;
        ::UInt32                          m_buffer_byte_size;
        AudioQueueBufferRef             m_buffers[number_buffers];
        ::SInt64                          m_current_packet;
        ::UInt32                          m_num_packets_to_read;
        AudioStreamPacketDescription*   m_packet_description;
        bool                            m_done;
        double                          m_volume;
        double                          m_pan;
        GHL::DataStream*                m_input_stream;
        bool                            m_loop;
    protected:
        static OSStatus AFReadProc (
                                    void     *inClientData,
                                    ::SInt64   inPosition,
                                    ::UInt32   requestCount,
                                    void     *buffer,
                                    ::UInt32   *actualCount
                                    ) {
            DataStream* info = reinterpret_cast<DataStream*> (inClientData);
            if (info->Seek( GHL::Int32( inPosition) , GHL::F_SEEK_BEGIN )) {
                GHL::UInt32 readed = info->Read( reinterpret_cast<Byte*> (buffer),requestCount);
                if (actualCount) *actualCount = readed;
                return noErr;
            }
            if (actualCount) *actualCount = 0;
            return noErr;
        }
        
        static ::SInt64 AFGetSizeProc (
                                       void  *inClientData
                                       ) {
            DataStream* info = reinterpret_cast<DataStream*> (inClientData);
            if (info->Seek( 0, GHL::F_SEEK_END )) {
                return info->Tell();
            }
            return 0;
        }
        
        static void AQBufferCallback(void *                 inUserData,
                                     AudioQueueRef           inAQ,
                                     AudioQueueBufferRef     inCompleteAQBuffer)
        {
            MusicInstanceCocoa * myInfo = reinterpret_cast<MusicInstanceCocoa*> (inUserData);
            if (myInfo->m_done) return;
            
            ::UInt32 numBytes;
            ::UInt32 nPackets = myInfo->m_num_packets_to_read;
            
            OSStatus result = AudioFileReadPackets(myInfo->m_audio_file,
                                                   false, &numBytes,
                                                   myInfo->m_packet_description,
                                                   myInfo->m_current_packet,
                                                   &nPackets,
                                                   inCompleteAQBuffer->mAudioData);
            if (result) {
                LOG_ERROR("reading packets: " << (int)result);
                nPackets = -1;
                myInfo->m_loop = false;
            }
            
            if (nPackets > 0) {
                inCompleteAQBuffer->mAudioDataByteSize = numBytes;
                
                AudioQueueEnqueueBuffer(inAQ,
                                        inCompleteAQBuffer,
                                        (myInfo->m_packet_description ? nPackets : 0),
                                        myInfo->m_packet_description);
                
                myInfo->m_current_packet += nPackets;
            } else {
                if ( !myInfo->m_loop ) {
                    result = AudioQueueStop(myInfo->m_queue, false);
                    if (result) {
                        LOG_ERROR("stopping qeue: " << (int)result);
                    }
                    // reading nPackets == 0 is our EOF condition
                    myInfo->m_done = true;
                } else {
                    // restart from 0
                    myInfo->m_current_packet = 0;
                    AQBufferCallback( inUserData, inAQ, inCompleteAQBuffer );
                }
            }
        }

        // we only use time here as a guideline
        // we're really trying to get somewhere between 16K and 64K buffers, but not allocate too much if we don't need it
        static void CalculateBytesForTime (AudioStreamBasicDescription & inDesc, ::UInt32 inMaxPacketSize, Float64 inSeconds, ::UInt32 *outBufferSize, ::UInt32 *outNumPackets)
        {
            static const int maxBufferSize = 0x10000;   // limit size to 64K
            static const int minBufferSize = 0x4000;    // limit size to 16K
            
            if (inDesc.mFramesPerPacket) {
                Float64 numPacketsForTime = inDesc.mSampleRate / inDesc.mFramesPerPacket * inSeconds;
                *outBufferSize = numPacketsForTime * inMaxPacketSize;
            } else {
                // if frames per packet is zero, then the codec has no predictable packet == time
                // so we can't tailor this (we don't know how many Packets represent a time period
                // we'll just return a default buffer size
                *outBufferSize = maxBufferSize > inMaxPacketSize ? maxBufferSize : inMaxPacketSize;
            }
            
            // we're going to limit our size to our default
            if (*outBufferSize > maxBufferSize && *outBufferSize > inMaxPacketSize)
                *outBufferSize = maxBufferSize;
            else {
                // also make sure we're not too small - we don't want to go the disk for too small chunks
                if (*outBufferSize < minBufferSize)
                    *outBufferSize = minBufferSize;
            }
            *outNumPackets = *outBufferSize / inMaxPacketSize;
        }
    public:

        explicit MusicInstanceCocoa( GHL::DataStream* ds,
                                    AudioFileID audioFile,
                                    const AudioStreamBasicDescription& dataFormat,
                                    AudioChannelLayout* channelLayout,
                                    ::UInt32 channelLayoutSize,
                                    ::UInt32 bufferByteSize,
                                    ::UInt32 numPacketsToRead,
                                    AudioStreamPacketDescription* packetDescription) :
            m_audio_file(audioFile),
            m_data_format(dataFormat),
            m_channel_layout(channelLayout),
            m_channel_layout_size(channelLayoutSize),
            m_queue(0),
            m_buffer_byte_size(bufferByteSize),
            m_current_packet(0),
            m_num_packets_to_read(numPacketsToRead),
            m_packet_description(packetDescription),
            m_done(true),
            m_input_stream(ds),
            m_loop(false) {
            m_volume = 100.0;
            m_pan = 0.0;
            m_input_stream->AddRef();
        }
        static MusicInstanceCocoa* Open( GHL::DataStream* ds ) {
            AudioFileID audioFile;
            if (AudioFileOpenWithCallbacks(ds, &MusicInstanceCocoa::AFReadProc,
                                           0,
                                           &MusicInstanceCocoa::AFGetSizeProc,
                                           0,0,
                                           &audioFile)!=noErr) {
                return 0;
            }
            
            ::UInt32 size;
            if (AudioFileGetPropertyInfo(audioFile,
                                         kAudioFilePropertyFormatList, &size, NULL)!=noErr) {
                AudioFileClose(audioFile);
                return 0;
            }
            
            UInt32 numFormats = size / sizeof(AudioFormatListItem);
            AudioFormatListItem *formatList = new AudioFormatListItem [ numFormats ];
            
            if (AudioFileGetProperty(audioFile,
                                     kAudioFilePropertyFormatList, &size, formatList)!=noErr) {
                delete [] formatList;
                AudioFileClose(audioFile);
                return 0;
            }
            numFormats = size / sizeof(AudioFormatListItem); // we need to reassess the actual number of formats when we get it
            if (numFormats!=1) {
                LOG_ERROR("too many formats in file " << numFormats);
                delete [] formatList;
                AudioFileClose(audioFile);
                return 0;
            }
            AudioStreamBasicDescription     dataFormat = formatList[0].mASBD;
            
            AudioChannelLayout*             channelLayout = 0;
            ::UInt32                        channelLayoutSize = 0;
            
            OSStatus result = AudioFileGetPropertyInfo(audioFile,
                                                       kAudioFilePropertyChannelLayout,
                                                       &channelLayoutSize, NULL);
            if (result == noErr && channelLayoutSize > 0) {
                channelLayout = (AudioChannelLayout *)new char [channelLayoutSize];
                AudioFileGetProperty(audioFile, kAudioFilePropertyChannelLayout, &channelLayoutSize, channelLayout);
            }
            
            delete [] formatList;
            
            ::UInt32                          bufferByteSize = 0;
            ::UInt32                          numPacketsToRead = 0;
            AudioStreamPacketDescription*     packetDescription = 0;
            
            // we need to calculate how many packets we read at a time, and how big a buffer we need
            // we base this on the size of the packets in the file and an approximate duration for each buffer
            {
                bool isFormatVBR = (dataFormat.mBytesPerPacket == 0 || dataFormat.mFramesPerPacket == 0);
                
                // first check to see what the max size of a packet is - if it is bigger
                // than our allocation default size, that needs to become larger
                ::UInt32 maxPacketSize;
                size = sizeof(maxPacketSize);
                result = AudioFileGetProperty(audioFile,
                                              kAudioFilePropertyPacketSizeUpperBound,
                                              &size, &maxPacketSize);
                if (result!=noErr) {
                    delete [] ((char*)channelLayout);
                    AudioFileClose(audioFile);
                    return 0;
                }
                
                // adjust buffer size to represent about a half second of audio based on this format
                CalculateBytesForTime (dataFormat, maxPacketSize, 0.5/*seconds*/, &bufferByteSize, &numPacketsToRead);
                
                if (isFormatVBR)
                    packetDescription = new AudioStreamPacketDescription[numPacketsToRead];
                else
                    packetDescription = NULL; // we don't provide packet descriptions for constant bit rate formats (like linear PCM)
                
            }
            return new MusicInstanceCocoa(ds,audioFile,dataFormat,
                                          channelLayout,
                                          channelLayoutSize,bufferByteSize,
                                          numPacketsToRead,packetDescription);
        }

        
        ~MusicInstanceCocoa() {
            if (m_queue) {
                AudioQueueDispose(m_queue,true);
            }
            if (m_audio_file) {
                AudioFileClose(m_audio_file);
            }

            delete [] ((char*)m_channel_layout);
            delete [] m_packet_description;
            m_input_stream->Release();
        }
        
        
        virtual void GHL_CALL Play( bool loop ) {
            OSStatus result;
            
            m_done = false;
            m_loop = loop;
            m_current_packet = 0;
            
            
            if (!m_queue) {
                result = AudioQueueNewOutput(&m_data_format,
                                             &MusicInstanceCocoa::AQBufferCallback, this,
                                             CFRunLoopGetCurrent(), kCFRunLoopCommonModes,
                                             0, &m_queue);
                if (result!=noErr) {
                    LOG_ERROR("AudioQueueNewOutput" );
                    return;
                }
                
                ::UInt32 size;
                
                // (2) If the file has a cookie, we should get it and set it on the AQ
                size = sizeof(::UInt32);
                result = AudioFileGetPropertyInfo (m_audio_file, kAudioFilePropertyMagicCookieData, &size, NULL);
                
                if (!result && size) {
                    char* cookie = new char [size];
                    AudioFileGetProperty (m_audio_file, kAudioFilePropertyMagicCookieData, &size, cookie);
                    AudioQueueSetProperty(m_queue, kAudioQueueProperty_MagicCookie, cookie, size);
                    delete [] cookie;
                }
                
                // set ACL if there is one
                if (m_channel_layout)
                    AudioQueueSetProperty(m_queue, kAudioQueueProperty_ChannelLayout, m_channel_layout, m_channel_layout_size);
                
                for (int i = 0; i < number_buffers; ++i) {
                    AudioQueueAllocateBuffer(m_queue, m_buffer_byte_size, &m_buffers[i]);
                }
                
            } else {
                AudioQueueReset(m_queue);
            }
            
            AudioQueueSetParameter(m_queue, kAudioQueueParam_Volume, m_volume/100.0);
            AudioQueueSetParameter(m_queue, kAudioQueueParam_Pan, m_pan/100.0);
            
            for (int i = 0; i < number_buffers; ++i) {
                AQBufferCallback (this, m_queue, m_buffers[i]);
                if (m_done) break;
            }
            
            AudioQueueStart(m_queue, NULL);
        }
        
        virtual void GHL_CALL SetVolume( float volume ) {
            m_volume = volume;
            if ( m_queue && !m_done ) {
                AudioQueueSetParameter(m_queue, kAudioQueueParam_Volume, m_volume/100.0);
            }
        }
        virtual void GHL_CALL Stop() {
            if ( m_queue ) {
                AudioQueueStop(m_queue, true);
                //AudioQueueDispose(m_queue,true);
                //m_queue = 0;
                m_done = true;
            }
        }
        
        virtual void GHL_CALL Pause() {
            if ( m_queue && !m_done ) {
                AudioQueuePause(m_queue);
            }
        }
        
        virtual void GHL_CALL Resume() {
            if ( m_queue && !m_done ) {
                AudioQueueStart(m_queue,0);
            }
        }
        
        /// set pan (-100..0..+100)
        virtual void GHL_CALL SetPan( float pan ) {
            m_pan = pan;
            if ( m_queue && !m_done ) {
                AudioQueueSetParameter(m_queue, kAudioQueueParam_Pan, m_pan/100.0);
            }
        }
    };
    
    SoundCocoa::SoundCocoa() : m_openal(8) {
        
    }
    
    
    bool SoundCocoa::SoundInit() {
        if (!SoundImpl::SoundInit())
            return false;
        if (!m_openal.SoundInit())
            return false;
        return true;
    }
    
    bool SoundCocoa::SoundDone() {
        m_openal.SoundDone();
        return SoundImpl::SoundDone();
    }
    
    /// create sound effect from data
    SoundEffect* GHL_CALL SoundCocoa::CreateEffect( SampleType type, UInt32 freq, Data* data ) {
        return m_openal.CreateEffect(type, freq, data);
    }
    /// play effect
    void GHL_CALL SoundCocoa::PlayEffect( SoundEffect* effect , float vol, float pan, SoundInstance** instance ) {
        m_openal.PlayEffect(effect, vol, pan, instance);
    }
    
    /// open music
    MusicInstance* GHL_CALL SoundCocoa::OpenMusic( GHL::DataStream* file ) {
        if (!file) return 0;
        MusicInstance* res = MusicInstanceCocoa::Open( file );
        if ( res ) return res;
        return 0;
    }
}

GHL::SoundImpl* GHL_CreateSoundCocoa() {
    return new GHL::SoundCocoa();
}