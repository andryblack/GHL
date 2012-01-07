#include "vfs_win32.h"
#include "memory_stream.h"
#include <windows.h>
#include <shlobj.h> 
#include <iostream>
#include <cstdio>
#ifdef _MSC_VER
#define snprintf _snprintf
#endif
namespace GHL {

	class FileStream : public DataStream {
	private:
		HANDLE m_file;
        bool m_eof; 
	public:
		explicit FileStream(HANDLE file) {
			m_file = file;
			m_eof = false;
		}
		~FileStream() {
			 CloseHandle(m_file); 
		}
		/// read data
		virtual UInt32 GHL_CALL Read(Byte* dest,UInt32 bytes) {
		    DWORD readed = 0;
			if (!::ReadFile(m_file,dest,bytes,&readed,0)) {
				DWORD dwErr = GetLastError();
				if (dwErr == ERROR_HANDLE_EOF) {
					dwErr = 0;
					m_eof = true;
				}
			}
			return readed; 
		}
		/// write data
		virtual UInt32 GHL_CALL Write(const Byte* src,UInt32 bytes) {
		    DWORD writed = 0;
			if (::WriteFile(m_file,src,bytes,&writed,0))
				return writed;
			return 0; 
		}
		/// tell
		virtual UInt32 GHL_CALL Tell() const {
		        DWORD dwSet = SetFilePointer(m_file, 0, NULL, FILE_CURRENT);
                if (dwSet == INVALID_SET_FILE_POINTER)
                {
                    return 0;
                }
                else
                    return dwSet; 
		}
		/// seek
		virtual	bool GHL_CALL Seek(Int32 offset,FileSeekType st) {
		   DWORD dwMoveMethod=0xFFFFFFFF;
           switch (st)
           {
           case F_SEEK_CURRENT :
               dwMoveMethod = FILE_CURRENT;
               break;
           case F_SEEK_END :
               dwMoveMethod = FILE_END;
               break;
           case F_SEEK_BEGIN :
               dwMoveMethod = FILE_BEGIN;
               break;
           default: return false;
           }

           {
               DWORD dwSet = SetFilePointer(m_file, offset, NULL, dwMoveMethod);
               if (dwSet == INVALID_SET_FILE_POINTER)
               {
                   return false;
               }

           }
           m_eof = false;
           return true; 
		}
		/// End of file
		virtual bool GHL_CALL Eof() const {
		        return m_eof; 
		}
		/// release stream
		virtual void GHL_CALL Release() {
			delete this;
		}
	};

	VFSWin32Impl::VFSWin32Impl() {
	}

	VFSWin32Impl::~VFSWin32Impl() {
	}

	/// get dir
	const char* GHL_CALL VFSWin32Impl::GetDir(DirType dt) const {
		return ".";
	}
	/// attach package
	void GHL_CALL VFSWin32Impl::AttachPack(DataStream* ds) {
	}
	/// file is exists
	bool GHL_CALL VFSWin32Impl::IsFileExists(const char* file) const {
		return true;
	}
	/// remove file
	bool GHL_CALL VFSWin32Impl::DoRemoveFile(const char* file) {
		return false;
	}
	/// copy file
	bool GHL_CALL VFSWin32Impl::DoCopyFile(const char* from,const char* to) {
		return false;
	}
	/// open file
	DataStream* GHL_CALL VFSWin32Impl::OpenFile(const char* _file,FileOperation ot) {
		if (!_file) return 0;
		if (_file[0]==0) return 0;
		char file[MAX_PATH];
		::strncpy(file,_file,MAX_PATH);
		HANDLE f = 0;
        DWORD dwDesiredAccess,dwCreationDisposition,dwShareMode,dwFlagsAndAttributes ;
        dwDesiredAccess = dwShareMode = dwFlagsAndAttributes = 0;
        WCHAR tfilename[512];
        MultiByteToWideChar(CP_UTF8, 0, file, -1, tfilename, 512);
        if (ot==FILE_READ)
        {
            dwDesiredAccess = GENERIC_READ;
            dwCreationDisposition = OPEN_EXISTING;
            dwShareMode = FILE_SHARE_READ;
        }
        else
        {
            dwDesiredAccess = GENERIC_WRITE | GENERIC_READ;
            dwCreationDisposition = CREATE_ALWAYS;
        }
        f = CreateFileW(tfilename,dwDesiredAccess, dwShareMode, NULL, dwCreationDisposition, dwFlagsAndAttributes, NULL); 
		if (f==INVALID_HANDLE_VALUE) {
			char buf[MAX_PATH]; 
			::snprintf(buf,MAX_PATH,"vfs: error opening file %s",file);
			std::cout << buf << std::endl;
			return 0;
		}
		return new FileStream(f); 
	}
	/// get stream from memory
	DataStream* GHL_CALL VFSWin32Impl::CreateStreamFromMemory(Byte* data,UInt32 size) {
		return new MemoryStream(data,size);
	}
}