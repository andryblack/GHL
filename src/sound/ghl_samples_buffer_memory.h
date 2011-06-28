#ifndef GHL_SAMPLES_BUFFER_MEMORY_H
#define GHL_SAMPLES_BUFFER_MEMORY_H

#include "ghl_sound_impl.h"

namespace GHL {

	class SamplesBufferMemory : public SamplesBufferImpl {
	private:
		SamplesBufferMemory(const SamplesBufferMemory&);
		SamplesBufferMemory& operator = (const SamplesBufferMemory&);
	public:
		SamplesBufferMemory(SampleType type,UInt32 capacity,UInt32 freq);
		~SamplesBufferMemory();
		void SetData(UInt32 offset,const Byte* data,UInt32 size);
		void GetData(UInt32 offset,Byte* buffer,UInt32 size);
		UInt32 Size() const { return m_capacity*SampleSize();}
		UInt32 SampleSize() const;
		virtual void GHL_CALL Release();
		virtual SampleType GHL_CALL GetSampleType() const { return m_type;}
		virtual UInt32 GHL_CALL GetCapacity() const { return m_capacity;}
		virtual UInt32 GHL_CALL GetFrequency() const { return m_freq;}
	private:
		Byte*		m_data;
	};

}

#endif /*GHL_SAMPLES_BUFFER_MEMORY_H*/