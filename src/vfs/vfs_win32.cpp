#include "vfs_win32.h"
#include "memory_stream.h"
#include <windows.h>
#include <shlobj.h> 
#include <iostream>
#include <cstdio>
#include "../ghl_log_impl.h"
#include "../ghl_ref_counter_impl.h"

#ifdef _MSC_VER
#define snprintf _snprintf
#endif
namespace GHL {

	static const char* MODULE = "VFS";

	class FileStream : public RefCounterImpl<DataStream> {
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
			} else if (bytes && (readed==0)) {
				m_eof = true;
			}
			return readed; 
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
		


	};

	VFSWin32Impl::VFSWin32Impl() {
		if (m_data_dir.empty()) {
				
				WCHAR uBuf[MAX_PATH];
				GetModuleFileNameW(GetModuleHandle(0),uBuf,MAX_PATH);
				char buf[MAX_PATH];
				WideCharToMultiByte(CP_UTF8,0,uBuf,-1,buf,MAX_PATH,0,0);
				m_data_dir = std::string(&buf[0]);
				size_t pos = m_data_dir.rfind('\\');
				if (pos!=m_data_dir.npos)
					m_data_dir.resize(pos+1);
				pos = 0;
				while ( (pos=m_data_dir.find('\\',pos))!=m_data_dir.npos) {
					m_data_dir[pos]='/';
					pos++;
				}

				LOG_INFO( "Data dir : " << m_data_dir );
		}
	}

	VFSWin32Impl::~VFSWin32Impl() {
	}

	static bool get_fs_path( const char* file , WCHAR* buf ) {
		MultiByteToWideChar(CP_UTF8, 0, file, -1, buf, MAX_PATH);
		size_t i=0;
		for (i=0;i<MAX_PATH;++i) {
			if (!buf[i]) break;
			if (buf[i]==L'/') buf[i]=L'\\';
		}
        
		return true;
	}

	/// get dir
	const char* GHL_CALL VFSWin32Impl::GetDir(DirType dt) const {
		if ( dt == DIR_TYPE_DATA) {
			return m_data_dir.c_str();
		}
		return ".";
	}

	/// file is exists
	bool GHL_CALL VFSWin32Impl::IsFileExists(const char* file) const {
		WCHAR tfilename[MAX_PATH];
        if (!get_fs_path(file,tfilename)) return false;
        WIN32_FILE_ATTRIBUTE_DATA attributes = {0};
        if (!GetFileAttributesExW(tfilename,GetFileExInfoStandard,
                                  &attributes))
            return false;
		
		return true;
	}
	/// remove file
	bool GHL_CALL VFSWin32Impl::DoRemoveFile(const char* file) {
        WCHAR tfilename[MAX_PATH];
        if (!get_fs_path(file,tfilename)) return false;
		return DeleteFileW(tfilename);
	}
	/// copy file
	bool GHL_CALL VFSWin32Impl::DoCopyFile(const char* from,const char* to) {
        WCHAR tfilename_from[MAX_PATH];
        if (!get_fs_path(from,tfilename_from)) return false;
        WCHAR tfilename_to[MAX_PATH];
        if (!get_fs_path(to,tfilename_to)) return false;
		return CopyFileW(tfilename_from,tfilename_to,FALSE);
	}

	/// create dir
	bool GHL_CALL VFSWin32Impl::DoCreateDir(const char* path) {
		WCHAR tfilename[MAX_PATH];
		if (!get_fs_path(path, tfilename)) return false;
		if (::CreateDirectoryW(tfilename, 0) == 0) {
			return ::GetLastError() != ERROR_ALREADY_EXISTS;
		}
		return true;
	}
	/// write file
	bool GHL_CALL VFSWin32Impl::WriteFile(const char* file, const Data* data) {
        HANDLE f = 0;
        DWORD dwDesiredAccess,dwCreationDisposition,dwShareMode,dwFlagsAndAttributes ;
        dwDesiredAccess = dwShareMode = dwFlagsAndAttributes = 0;
        WCHAR tfilename[MAX_PATH];
        if (!get_fs_path(file,tfilename)) return 0;
        dwDesiredAccess = GENERIC_WRITE;
        dwCreationDisposition = CREATE_ALWAYS;
        dwShareMode = FILE_SHARE_READ;
        
        f = CreateFileW(tfilename,dwDesiredAccess, dwShareMode, NULL, dwCreationDisposition, dwFlagsAndAttributes, NULL);
        if (f==INVALID_HANDLE_VALUE) {
            LOG_ERROR( "creating file : " << file );
            return false;
        }
        if (!WriteFileEx(f,data->GetData(),data->GetSize(),NULL,NULL)) {
            LOG_ERROR( "writing file : " << file );
            CloseHandle(f);
            return false;
        }
        
        CloseHandle(f);

		return true;
	}

	/// open file
	DataStream* GHL_CALL VFSWin32Impl::OpenFile(const char* file) {
		if (!file) return 0;
		if (file[0]==0) return 0;
		HANDLE f = 0;
        DWORD dwDesiredAccess,dwCreationDisposition,dwShareMode,dwFlagsAndAttributes ;
        dwDesiredAccess = dwShareMode = dwFlagsAndAttributes = 0;
        WCHAR tfilename[MAX_PATH];
        if (!get_fs_path(file,tfilename)) return 0;
		dwDesiredAccess = GENERIC_READ;
		dwCreationDisposition = OPEN_EXISTING;
		dwShareMode = FILE_SHARE_READ;

        f = CreateFileW(tfilename,dwDesiredAccess, dwShareMode, NULL, dwCreationDisposition, dwFlagsAndAttributes, NULL); 
		if (f==INVALID_HANDLE_VALUE) {
			LOG_ERROR( "opening file : " << file );
			return 0;
		}
		return new FileStream(f); 
	}
}