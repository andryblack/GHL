#include "vfs_posix.h"
#include "memory_stream.h"
#include <iostream>
#include <cstdio>
#ifdef _MSC_VER
#define snprintf _snprintf
#endif
namespace GHL {

	class PosixFileStream : public DataStream {
	private:
		FILE* m_file;
        	bool m_eof; 
	public:
		explicit PosixFileStream(FILE* file) {
			m_file = file;
		}
		virtual ~PosixFileStream() {
			fclose(m_file); 
		}
		/// read data
		virtual UInt32 GHL_CALL Read(Byte* dest,UInt32 bytes) {
		    return fread(dest,1,bytes,m_file);
		}
		/// write data
		virtual UInt32 GHL_CALL Write(const Byte* src,UInt32 bytes) {
		    return fwrite(src,1,bytes,m_file);
		}
		/// tell
		virtual UInt32 GHL_CALL Tell() const {
		       return ftell(m_file);
		}
		/// seek
		virtual	bool GHL_CALL Seek(Int32 offset,FileSeekType st) {
		   int dir = 0;
		   switch (st)
		   {
		   case F_SEEK_CURRENT :
		       dir = SEEK_CUR;
		       break;
		   case F_SEEK_END :
		       dir = SEEK_END;
		       break;
		   case F_SEEK_BEGIN :
		       dir = SEEK_SET;
		       break;
		   default: return false;
		   }
		   return fseek(m_file,offset,dir)==0;
		}
		/// End of file
		virtual bool GHL_CALL Eof() const {
		        return feof(m_file); 
		}
		/// release stream
		virtual void GHL_CALL Release() {
			delete this;
		}
	};

	VFSPosixImpl::VFSPosixImpl() {
	}

	VFSPosixImpl::~VFSPosixImpl() {
	}

	/// get dir
	const char* GHL_CALL VFSPosixImpl::GetDir(DirType dt) const {
		return ".";
	}
	/// attach package
	void GHL_CALL VFSPosixImpl::AttachPack(DataStream* ds) {
	}
	/// file is exists
	bool GHL_CALL VFSPosixImpl::IsFileExists(const char* file) const {
		return true;
	}
	/// remove file
	bool GHL_CALL VFSPosixImpl::DoRemoveFile(const char* file) {
		return false;
	}
	/// copy file
	bool GHL_CALL VFSPosixImpl::DoCopyFile(const char* from,const char* to) {
		return false;
	}
	/// open file
	DataStream* GHL_CALL VFSPosixImpl::OpenFile(const char* _file,FileOperation ot) {
		if (!_file) return 0;
		if (_file[0]==0) return 0;
		FILE* f = fopen(_file,ot==FILE_READ ? "rb" : "rwb" );
		if (f)
			return new PosixFileStream(f); 
		return 0;
	}
	/// get stream from memory
	DataStream* GHL_CALL VFSPosixImpl::CreateStreamFromMemory(Byte* data,UInt32 size) {
		return new MemoryStream(data,size);
	}
}


GHL_API GHL::VFS* GHL_CALL GHL_CreateVFSPosix() {
	return new GHL::VFSPosixImpl();
}

GHL_API void GHL_CALL GHL_DestroyVFSPosix(GHL::VFS* vfs) {
	delete reinterpret_cast<GHL::VFSPosixImpl*>(vfs);
}


