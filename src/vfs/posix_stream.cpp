#include "posix_stream.h"

namespace GHL {

	
    PosixFileStream::PosixFileStream(FILE* file) : m_file(file) {
    }
    
    PosixFileStream::~PosixFileStream() {
        fclose(m_file);
    }
    
    UInt32 GHL_CALL PosixFileStream::Read(Byte* dest,UInt32 bytes) {
        return fread(dest,1,bytes,m_file);
    }
    
    UInt32 GHL_CALL PosixFileStream::Tell() const {
        return ftell(m_file);
    }
    /// seek
    bool GHL_CALL PosixFileStream::Seek(Int32 offset,FileSeekType st) {
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
    bool GHL_CALL PosixFileStream::Eof() const {
        return feof(m_file) != 0;
    }
    
    PosixWriteFileStream::PosixWriteFileStream(FILE* file) : m_file(file) {
    }

    PosixWriteFileStream::~PosixWriteFileStream() {
    	Close();
    }

    
	void GHL_CALL PosixWriteFileStream::Flush() {
		if (m_file) {
		    fflush(m_file);
		}
	}
	void GHL_CALL PosixWriteFileStream::Close() {
		if (m_file) {
		    fclose(m_file);
		    m_file = 0;
		}
	}
	/// write data
	UInt32 GHL_CALL PosixWriteFileStream::Write(const Byte* src,UInt32 bytes) {
		if (!m_file) return 0;
		return fwrite(src,1,bytes,m_file);
	}
    
}