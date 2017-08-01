/*
    GHL - Game Helpers Library
    Copyright (C)  Andrey Kunitsyn 2009

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    Andrey (AndryBlack) Kunitsyn
    blackicebox (at) gmail (dot) com
*/

#include "vorbis_decoder.h"
#include <ghl_data_stream.h>
#include <cassert>

namespace GHL
{

	static size_t ghl_ogg_read_func  (void *ptr, size_t size, size_t nmemb, void *datasource) 
	{
		DataStream* ds = reinterpret_cast<DataStream*>(datasource);
		if (!ds) return 0;
		return ds->Read(reinterpret_cast<Byte*>(ptr),UInt32(size*nmemb));
	}
	static   int  ghl_ogg_seek_func  (void *datasource, ogg_int64_t offset, int whence) 
	{
		DataStream* ds = reinterpret_cast<DataStream*>(datasource);
		if (!ds) return 0;
		FileSeekType fst;
		if (whence==SEEK_SET) fst=F_SEEK_BEGIN;
		else if (whence==SEEK_CUR) fst=F_SEEK_CURRENT;
		else if (whence==SEEK_END) fst=F_SEEK_END;
		else return 0;
		return ds->Seek(static_cast<Int32>(offset),fst);
	}
	static   int  ghl_ogg_close_func (void *datasource)
	{
		return 0;
	}
	static   long ghl_ogg_tell_func  (void *datasource)
	{
		DataStream* ds = reinterpret_cast<DataStream*>(datasource);
		if (!ds) return 0;
		return ds->Tell();
	}
	
	
	
	static ov_callbacks	ghl_ogg_callbacks = {
		&ghl_ogg_read_func,
		&ghl_ogg_seek_func,
		&ghl_ogg_close_func,
		&ghl_ogg_tell_func
	};

	VorbisDecoder::VorbisDecoder(DataStream* ds) : SoundDecoderBase(ds)
	{
		m_current_section = 0;
	}
	
	VorbisDecoder::~VorbisDecoder()
	{
        if (m_type!=SAMPLE_TYPE_UNKNOWN)
            ov_clear(&m_file);
    }
	
	
	bool VorbisDecoder::Init() {
        m_ds->Seek(0,F_SEEK_BEGIN);
		int res = ov_open_callbacks(m_ds,&m_file,0,0,ghl_ogg_callbacks);
		if (res!=0) return false;
		vorbis_info *vi=ov_info(&m_file,-1);
		if (!vi) return false;
        if (vi->channels!=1 && vi->channels!=2) return false;
        m_type = vi->channels==2 ? SAMPLE_TYPE_STEREO_16 : SAMPLE_TYPE_MONO_16;
		m_freq = UInt32(vi->rate);
        m_bytes_per_sample = vi->channels * 2;
		m_samples = static_cast<UInt32>(ov_pcm_total(&m_file,-1));
        if (m_samples<=0) return false;
		m_current_section = 0;
		return true;
	}

    UInt32 GHL_CALL VorbisDecoder::ReadSamples(UInt32 samples, Byte* buf) {
		int res = 0;
		while (samples)
		{
			long c_res = ov_read(&m_file,reinterpret_cast<char*>(buf),samples*m_bytes_per_sample,0,2,1,&m_current_section);
			if (c_res<=0) return res;
			buf+=c_res;
			c_res = c_res/m_bytes_per_sample;
			assert(c_res<=static_cast<int>(samples));
			samples-=c_res;
			res+=c_res;
		}
		return res;
	}

	void GHL_CALL VorbisDecoder::Reset()
	{
		ov_pcm_seek(&m_file, 0);
	}
    
    VorbisDecoder* VorbisDecoder::Open(GHL::DataStream *ds) {
        if (!ds) return 0;
        VorbisDecoder* vd = new VorbisDecoder(ds);
		if (!vd->Init()) {
			delete vd;
			return 0;
		}
        return vd;
    }
	
}
