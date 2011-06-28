#include "ghl_samples_buffer_memory.h"
#include "ghl_sound_impl.h"
#include <cassert>
#include <cstring>


namespace GHL {

	SamplesBufferMemory::SamplesBufferMemory(SampleType type,UInt32 capacity,UInt32 freq) :
		SamplesBufferImpl(type,capacity,freq),m_data(0) {
		m_data = new Byte[GetCapacity()*SampleSize()];
	}

	SamplesBufferMemory::~SamplesBufferMemory() {
		delete [] m_data;
	}
	void SamplesBufferMemory::SetData(UInt32 offset,const Byte* data,UInt32 size) {
		assert((offset+size)<=(m_capacity*SampleSize()));
		::memcpy(m_data+offset,data,size);
	}

	void SamplesBufferMemory::GetData(UInt32 offset,Byte* buffer,UInt32 size) {
		assert((offset+size)<=(m_capacity*SampleSize()));
		::memcpy(buffer,m_data+offset,size);
	}
		
	UInt32 SamplesBufferMemory::SampleSize() const {
		return SoundImpl::SampleSize(m_type);
	}

	void GHL_CALL SamplesBufferMemory::Release() {
		delete this;
	}

}