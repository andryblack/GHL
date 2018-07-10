#include "ghl_sound_emscripten.h"
#include <emscripten.h>
#include "../../ghl_log_impl.h"

static const char* MODULE = "sound";

namespace GHL {

	SoundEffectEmscripten::SoundEffectEmscripten(SampleType type, UInt32 freq, int buffer) : SoundEffectImpl(type,freq) {
		m_buffer = buffer;
	}

	SoundEffectEmscripten::~SoundEffectEmscripten() {
		EM_ASM({
			delete Module._sound.buffers[$0];
		},m_buffer);
	}

	SoundEmscripten::SoundEmscripten() {
		m_supported = false;
	}

	SoundEmscripten::~SoundEmscripten() {

	}

	class SoundInstanceEmscripten;
    class SoundChannelEmscripten {
    private:
        int  m_handle;
        SoundEffectEmscripten*      m_effect;
        SoundInstanceEmscripten*    m_instance;
        float   m_pitch;
    public:
        explicit SoundChannelEmscripten( int handle );
        ~SoundChannelEmscripten();
        bool IsPlaying() const;
        void Play(bool loop);
        void Pause();
        void Stop();
        void SetVolume( float val );
        void SetPan( float pan );
        void SetPitch(float pitch);
        void Clear();
        void SetEffect( SoundEffectEmscripten* effect );
        void SetInstance(SoundInstanceEmscripten* instance);
    };
    class SoundInstanceEmscripten: public RefCounterImpl<SoundInstance> {
    private:
        int m_handle;
    public:
        explicit SoundInstanceEmscripten(int handle ) : m_handle(handle) {
            
        }
        ~SoundInstanceEmscripten() {
        	EM_ASM({
        		delete Module._sound.channels[$0];
        	},m_handle);
        }
        /// set volume (0-100)
        virtual void GHL_CALL SetVolume( float vol ) {
            // if (m_channel) {
            //     m_channel->SetVolume(vol);
            // }
        }
        /// set pan (-100..0..+100)
        virtual void GHL_CALL SetPan( float pan ) {
            // if (m_channel) {
            //     m_channel->SetPan(pan);
            // }
        }
        virtual void GHL_CALL SetPitch( float pitch ) {
            EM_ASM({
        		try {
					let node = Module._sound.channels[$0];
					if (node && ('playbackRate' in node)) {
						node.playbackRate = $1;
					};
				} catch (e) {
					console.log('failed stop ' + e);
				};
        	},m_handle, (pitch / 100.0));
        }
        /// stop
        virtual void GHL_CALL Stop() {
            EM_ASM({
				try {
					let node = Module._sound.channels[$0];
					if (node && ('stop' in node)) {
						node.stop();
					};
				} catch (e) {
					console.log('failed stop ' + e);
				};
			},m_handle);
        }
    };
	
	
	bool SoundEmscripten::SoundInit() {
		LOG_INFO("SoundInit");
		m_supported = EM_ASM_INT({
			function isWebAudioAPIsupported() {
                return ('AudioContext' in window) || ('webkitAudioContext' in window);
            };
            if (!isWebAudioAPIsupported()) {
            	console.log('Web audio not supported');
            	return 0 | 0;
            };
            Module._sound = {};
            Module._sound.context = new (window.AudioContext || window.webkitAudioContext)();
            Module._sound.buffers_cntr = 0;
            Module._sound.buffers = {};
            Module._sound.channels_cntr = 0;
            Module._sound.channels = {};
			return 1 | 0;
		});
		if (!m_supported) {
			LOG_INFO("Sound not supported");
		} else {
			LOG_INFO("Sound is supported");
		}
		return SoundImpl::SoundInit();
	}
	bool SoundEmscripten::SoundDone() {
		return SoundImpl::SoundDone();
	}
		
    /// create sound effect from data
    SoundEffect* GHL_CALL SoundEmscripten::CreateEffect( SampleType type, UInt32 freq, Data* data ) {
    	if (!m_supported)
    		return 0;
    	if (type != SAMPLE_TYPE_STEREO_16 &&
    		type != SAMPLE_TYPE_MONO_16) {
    		LOG_ERROR("not supported sample format " << type);
    		return 0;
    	}
    	int buffer = EM_ASM_INT({
    		let numOfchannels = $0;
    		let sampleRate = $1;
    		let data = $2;
    		let data_size = $3;
    		let length = data_size / (2 * numOfchannels);
    		let buffer = Module._sound.context.createBuffer(numOfchannels, length, sampleRate);
    		let base = data >> 1;
    		for (let ch = 0; ch < numOfchannels; ch++) {
    			let chData = buffer.getChannelData(ch);
    			for (let s = 0; s < length; s++) {
    				chData[s] = HEAP16[base+s*numOfchannels+ch] / 32767;
    			};
    		};
    		Module._sound.buffers_cntr++;
    		let handle = Module._sound.buffers_cntr;
    		console.log('created buffer ' + handle);
    		Module._sound.buffers[handle] = buffer;
    		return handle | 0;
    	},
    		SoundDecoderBase::GetChannels(type),
    		freq,
    		data->GetData(),
    		data->GetSize()
    	);
    	if (!buffer)
    		return 0;
    	return new SoundEffectEmscripten(type,freq,buffer);
    }
    /// play effect
    void GHL_CALL SoundEmscripten::PlayEffect( SoundEffect* effect , float vol , float pan, SoundInstance** instance ) {
    	if (instance) {
    		*instance = 0;
    	}
    	if (!effect)
    		return;
    	if (!m_supported)
    		return;

    	SoundEffectEmscripten* em_effect = static_cast<SoundEffectEmscripten*>(effect);

    	int handle = EM_ASM_INT({
    		let buffer_handle = $0;
    		let need_ref = $1;
    		let vol = $2;
    		let buffer = Module._sound.buffers[buffer_handle];
        	let node = Module._sound.context.createBufferSource();
        	let gainNode = null;
        	if (vol == 1.0) {
        		node.connect(Module._sound.context.destination);
        	} else {
        		gainNode = Module._sound.context.createGain();
        		node.connect(gainNode);
        		gainNode.connect(Module._sound.context.destination);
        		gainNode.gain.setValueAtTime(vol, Module._sound.context.currentTime);
        	}
        	node.buffer = buffer;
        	node.start();
        	
        	if (need_ref){
	        	Module._sound.channels_cntr++;
	        	let handle = Module._sound.channels_cntr;
	        	Module._sound.channels[handle] = node;
	        	//console.log('created channel ' + handle);
	        	return handle | 0;
	        }
	        return 0;
        },em_effect->get_handle(),instance, vol / 100.0);

        if (instance) {
            SoundInstanceEmscripten* inst = new SoundInstanceEmscripten(handle);
            *instance = inst;
        }
    }




    /// music
    static const GHL::UInt32 DECODE_SAMPLES_BUFFER = 44100 / 8;

    EmscriptenDecodeMusic::EmscriptenDecodeMusic(SoundDecoder* decoder, int handle) :
         m_decoder(decoder), m_handle(handle)
    {
      	m_buffer = new Byte[ DECODE_SAMPLES_BUFFER * SoundDecoderBase::GetBps(m_decoder->GetSampleType()) ];
      	m_loop = false;
    }

    EmscriptenDecodeMusic::~EmscriptenDecodeMusic() {
    	 if (m_decoder) {
            m_decoder->Release();
        }
        EM_ASM({
        	 Module._sound.music[$0].release();
        	delete Module._sound.music[$0];
        },m_handle);
        delete [] m_buffer;
    }


     /// set volume (0-100)
    void GHL_CALL EmscriptenDecodeMusic::SetVolume( float vol ) {
    	EM_ASM({
    		try {
    			Module._sound.music[$0].setVolume($1);
    		} catch (e) {
    			console.log('failed set volume for ' + $0 + ' ' + e);
    		};
    	},m_handle,double(vol)/100.0);
     }
    /// set pan (-100..0..+100)
    void GHL_CALL EmscriptenDecodeMusic::SetPan( float pan ) {
        // if (m_channel) {
        //     m_channel->SetPan(pan);
        // }
    }
    /// set pitch
    void GHL_CALL EmscriptenDecodeMusic::SetPitch( float pitch ) {
        EM_ASM({
        	try {
    			Module._sound.music[$0].setPitch($1);
    		} catch (e) {
    			console.log('failed set pitch for ' + $0 + ' ' + e);
    		};
    	},m_handle,double(pitch)/100.0);
    }
    /// stop
    void GHL_CALL EmscriptenDecodeMusic::Stop() {
        EM_ASM({
        	try {
    			Module._sound.music[$0].stop();
    		} catch (e) {
    			console.log('failed stop ' + $0 + ' ' + e);
    		};
    	},m_handle);
    }
    /// pause
    void GHL_CALL EmscriptenDecodeMusic::Pause() {
        EM_ASM({
        	try {
    			Module._sound.music[$0].pause();
    		} catch (e) {
    			console.log('failed pause ' + $0 + ' ' + e);
    		};
    	},m_handle);
    }
    /// resume
    void GHL_CALL EmscriptenDecodeMusic::Resume() {
        EM_ASM({
        	try {
    			Module._sound.music[$0].resume();
    		} catch (e) {
    			console.log('failed resume ' + $0 + ' ' + e);
    		};
    	},m_handle);
    }
    /// play
    void GHL_CALL EmscriptenDecodeMusic::Play( bool loop ) {
    	m_loop = loop;
        EM_ASM({
        	try {
    			Module._sound.music[$0].play($1==1);
    		} catch (e) {
    			console.log('failed play ' + $0 + ' ' + e);
    		};
    	},m_handle,loop?1:0);
    }

    bool EmscriptenDecodeMusic::decodeChunk() {
    	UInt32 samples = m_decoder->ReadSamples(DECODE_SAMPLES_BUFFER,m_buffer);
        if (!samples) {
            if (m_loop) {
                m_decoder->Reset();
                samples = m_decoder->ReadSamples(DECODE_SAMPLES_BUFFER,m_buffer);
                if (!samples) {
                    return false;
                }
            } else {
                return false;
            }
        }
        bool result = EM_ASM_INT({
        	try {
        		Module._sound.music[$0].schedule($1,$2);
        		return 1 | 0;
        	} catch (e) {
        		console.log('failed schedule ' + $0 + ' ' + e);
        		return 0 | 0;
        	}
        },m_handle,m_buffer,samples);
        return result;
    }

    
    /// open music
    MusicInstance* GHL_CALL SoundEmscripten::OpenMusic( GHL::DataStream* file ) {
    	SoundDecoder* decoder = GHL_CreateSoundDecoder( file );
        if (!decoder) {
        	LOG_ERROR("failed create music decoder");
            return 0;
        }

     
    	int handle = EM_ASM_INT(({
    		let numOfchannels = $0;
    		let sampleRate = $1;
    		if (!Module._sound.music) {
    			Module._sound.music = {};
    			Module._sound.music_cntr = 0;
    			let GHLMusicStream = function ( numOfchannels, sampleRate ) {
    				this.numOfchannels = numOfchannels;
    				this.sampleRate = sampleRate;
    				this.totalTimeScheduled = 0;
    				this.scheduled_buffers = [];
    				this.loop = false;
    				this.volume = 1.0;
    				this.playing = false;
    				this.ptr = 0;
    			};
    			GHLMusicStream.prototype.play = function(loop) {
    				this.playStartedAt = Module._sound.context.currentTime;
    				if (!this.gainNode) {
	    				this.gainNode = Module._sound.context.createGain();
	        			this.gainNode.connect(Module._sound.context.destination);
	        			this.gainNode.gain.setValueAtTime(this.volume, Module._sound.context.currentTime);
	        		};
    				this.loop = loop;
    				this.totalTimeScheduled = 0;
    				this.playing = true;
    				while (this.scheduled_buffers.length < 2) {
	    				if (!this.decodeChunk()) {
	    					break;
	    				};
	    			};
	    		};
	    		GHLMusicStream.prototype.stop = function() {
	    			this.playing = false;
	    		};
	    		GHLMusicStream.prototype.pause = function() {

	    		};
	    		GHLMusicStream.prototype.resume = function() {

	    		};
	    		GHLMusicStream.prototype.setVolume = function(vol) {
	    			this.volume = vol;
	    			if (this.gainNode) {
	    				this.gainNode.gain.setValueAtTime(vol, Module._sound.context.currentTime);
	    			};
	    		};
	    		GHLMusicStream.prototype.setPitch = function(pitch) {

	    		};
	    		GHLMusicStream.prototype.onAudioNodeEnded = function() {
	    			this.scheduled_buffers.shift();
	    		};
	    		GHLMusicStream.prototype.decodeChunk = function() {
	    			if (this.ptr == 0) {
	    				return false;
	    			}
	    			return Module['_GHLSound_DecodeChunk'](this.ptr) == 1;
	    		};
				GHLMusicStream.prototype.schedule = function(data,length) {
	    			let audioCtx = Module._sound.context;
	    			const audioSrc = audioCtx.createBufferSource(),
          				audioBuffer = audioCtx.createBuffer(this.numOfchannels,length, this.sampleRate);
          			this.scheduled_buffers.push(audioSrc);
          			audioSrc.onended = this.onAudioNodeEnded.bind(this);
          			let base = data >> 1;
		    		for (let ch = 0; ch < this.numOfchannels; ch++) {
		    			let chData = audioBuffer.getChannelData(ch);
		    			for (let s = 0; s < length; s++) {
		    				chData[s] = HEAP16[base+s*this.numOfchannels+ch] / 32767;
		    			};
		    		};
		    		audioSrc.buffer = audioBuffer;
				    audioSrc.connect(this.gainNode);
				    if (this.totalTimeScheduled == 0) {
				    	const startDelay = audioBuffer.duration + (audioCtx.baseLatency || 128 / audioCtx.sampleRate);
				    	this.playStartedAt = this.playStartedAt + startDelay;
				    };
				    audioSrc.start(this.playStartedAt+this.totalTimeScheduled);
				    this.totalTimeScheduled+= audioBuffer.duration;
	    		};
                GHLMusicStream.prototype.process = function() {
                    while (this.scheduled_buffers.length < 2 && this.playing) {
                        if (!this.decodeChunk()) {
                            break;
                        };
                    };
                };
	    		GHLMusicStream.prototype.release = function() {
	    			this.playing = false;
	    			this.ptr = 0;
	    		};
	    		Module.GHLMusicStream = GHLMusicStream;
                Module._sound.processMusic = function() {
                    for(let music_id in Module._sound.music){
                         Module._sound.music[music_id].process()
                    }
                };
    		};
    		Module._sound.music_cntr++;
    		let handle = Module._sound.music_cntr;
    		let music = new Module.GHLMusicStream(numOfchannels,sampleRate);
    		Module._sound.music[handle] = music;
    		return handle | 0;
    	}),
    		SoundDecoderBase::GetChannels(decoder->GetSampleType()),
    		decoder->GetFrequency()
    	);

    	EmscriptenDecodeMusic* music_inst = new EmscriptenDecodeMusic(decoder,handle);
    	

    	EM_ASM({
    		Module._sound.music[$0].ptr = $1;
    	},handle,music_inst);

        return music_inst;
    }

    void SoundEmscripten::Process() {
        EM_ASM({
            if (Module._sound && Module._sound.processMusic) {
                Module._sound.processMusic();
            }
        });
    }

}

extern "C" EMSCRIPTEN_KEEPALIVE int32_t GHLSound_DecodeChunk(GHL::EmscriptenDecodeMusic* music) {
	return music->decodeChunk() ? 1 : 0;
}