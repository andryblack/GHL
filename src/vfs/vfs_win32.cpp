#include "vfs_win32.h"
#include "memory_stream.h"
#include <windows.h>
#include <shlobj.h> 
#include <iostream>
#include <cstdio>
#include "../ghl_log_impl.h"
#include "../ghl_ref_counter_impl.h"
#include <ghl_data.h>

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
    
    
    class FileWriteStream : public RefCounterImpl<WriteStream> {
    private:
        HANDLE m_file;
        bool m_eof;
    public:
        explicit FileWriteStream(HANDLE file) {
            m_file = file;
        }
        ~FileWriteStream() {
            Close();
        }
        virtual void GHL_CALL Close() {
            if (m_file) {
                CloseHandle(m_file);
                m_file = 0;
            }
        }
        virtual void GHL_CALL Flush() {
            if (m_file) FlushFileBuffers(m_file);
        }
        /// read data
        virtual UInt32 GHL_CALL Write(const Byte* src,UInt32 bytes) {
            if (!m_file) return 0;
            DWORD writed = 0;
            if (!::WriteFile(m_file,src,bytes,&writed,0)) {
                return 0;
            }
            return writed;
        }
        
    };

    static void normalize_dir( std::string& dest, WCHAR* uBuf ) {
        char buf[MAX_PATH];
        WideCharToMultiByte(CP_UTF8,0,uBuf,-1,buf,MAX_PATH,0,0);
        dest = std::string(&buf[0]);
        size_t pos = dest.rfind('\\');
        if (pos!=dest.npos)
            dest.resize(pos+1);
        pos = 0;
        while ( (pos=dest.find('\\',pos))!=dest.npos) {
            dest[pos]='/';
            pos++;
        }
    }

	VFSWin32Impl::VFSWin32Impl() {
        WCHAR uBuf[MAX_PATH];
        m_user_dir = ".";
        m_cache_dir = ".";
            
		if (m_data_dir.empty()) {
				
			GetModuleFileNameW(GetModuleHandle(0),uBuf,MAX_PATH);
            normalize_dir(m_data_dir,uBuf);

			LOG_INFO( "Data dir : " << m_data_dir );
		}

        
        

	}

    void VFSWin32Impl::SetApplicationName(const std::string& name) {
        // Roaming AppData – Legacy
        WCHAR uBuf[MAX_PATH];
        if(SUCCEEDED(SHGetFolderPathW(NULL,  
                             CSIDL_APPDATA|CSIDL_FLAG_CREATE,  
                             NULL,  
                             0,  
                             uBuf))) 
        { 
            normalize_dir(m_user_dir,uBuf);
            if (!name.empty()) {
                m_user_dir += "/" + name;
            }
            LOG_INFO( "User dir : " << m_user_dir );
            DoCreateDir(m_user_dir.c_str());
            m_cache_dir = m_user_dir + "/cache";
            DoCreateDir(m_cache_dir.c_str());
        } else {
            LOG_WARNING("Failed get app data folder");
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
		buf[i] = 0;
        
		return true;
	}

    static void create_dir(const WCHAR* filename) {
        WCHAR dir[MAX_PATH];
        const WCHAR* pos = filename;
        while (pos && *pos) {
            if (*pos == L'\\') {
                size_t i = pos-filename;
                memcpy(dir,filename,sizeof(WCHAR)*i);
                dir[i] = 0;
                CreateDirectoryW(dir,0);
            }
            ++pos;
        }
    }

	/// get dir
	const char* GHL_CALL VFSWin32Impl::GetDir(DirType dt) const {
		if ( dt == DIR_TYPE_DATA) {
			return m_data_dir.c_str();
		}
        if ( dt == DIR_TYPE_USER_PROFILE) {
            return m_user_dir.c_str();
        }
        if ( dt == DIR_TYPE_CACHE) {
            return m_cache_dir.c_str();
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
    
    /// rename file
    bool GHL_CALL VFSWin32Impl::DoRenameFile(const char* from,const char* to) {
        WCHAR tfilename_from[MAX_PATH];
        if (!get_fs_path(from,tfilename_from)) return false;
        WCHAR tfilename_to[MAX_PATH];
        if (!get_fs_path(to,tfilename_to)) return false;
        WIN32_FILE_ATTRIBUTE_DATA attributes = {0};
        if (GetFileAttributesExW(tfilename_to,GetFileExInfoStandard,
                                 &attributes)!=0) {
            DeleteFileW(tfilename_to);
        }
        return MoveFileW(tfilename_from,tfilename_to);
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
        create_dir(tfilename);
        dwDesiredAccess = GENERIC_WRITE;
        dwCreationDisposition = CREATE_ALWAYS;
        dwShareMode = FILE_SHARE_READ;
        
        f = CreateFileW(tfilename,dwDesiredAccess, dwShareMode, NULL, dwCreationDisposition, dwFlagsAndAttributes, NULL);
        if (f==INVALID_HANDLE_VALUE) {
            LOG_ERROR( "creating file : " << file );
            return false;
        }
		DWORD written = 0;
		if (!::WriteFile(f, data->GetData(), data->GetSize(), &written, NULL) || written!=data->GetSize()) {
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
    
    WriteStream* GHL_CALL VFSWin32Impl::OpenFileWrite(const char* file) {
        if (!file) return 0;
        if (file[0]==0) return 0;
        HANDLE f = 0;
        DWORD dwDesiredAccess,dwCreationDisposition,dwShareMode,dwFlagsAndAttributes ;
        dwDesiredAccess = dwShareMode = dwFlagsAndAttributes = 0;
        WCHAR tfilename[MAX_PATH];
        if (!get_fs_path(file,tfilename)) {
            return 0;
        }
        create_dir(tfilename);
        dwDesiredAccess = GENERIC_WRITE;
        dwCreationDisposition = CREATE_ALWAYS;
        dwShareMode = FILE_SHARE_READ;
        
        f = CreateFileW(tfilename,dwDesiredAccess, dwShareMode, NULL, dwCreationDisposition, dwFlagsAndAttributes, NULL);
        if (f==INVALID_HANDLE_VALUE) {
            LOG_ERROR( "failed opening write file : " << file );
            return 0;
        }
        return new FileWriteStream(f);
    }
}