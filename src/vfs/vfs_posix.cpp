#include "vfs_posix.h"
#include "memory_stream.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include "../ghl_ref_counter_impl.h"
#include "../ghl_log_impl.h"
#include <ghl_data.h>
#include "posix_stream.h"

namespace GHL {
    
    static const char* MODULE = "VFS";

    

    static void create_dir(const char* filename) {
        std::string dir;
        const char* pos = strchr(filename,'/');
        while (pos) {
            dir.append(filename,pos-filename);
            mkdir(dir.c_str(),0777);
            filename = pos;
            pos = strchr(pos+1,'/');
        }
    }


    VFSPosixImpl::VFSPosixImpl(const char* dat,const char* docs) {
        m_data_dir = dat;
        m_docs_dir = docs;
    }

    VFSPosixImpl::~VFSPosixImpl() {
    }

    void VFSPosixImpl::SetCacheDir(const std::string& dir) {
        m_cache_dir = dir;
    }

    /// get dir
    const char* GHL_CALL VFSPosixImpl::GetDir(DirType dt) const {
        if (dt==DIR_TYPE_DATA) {
            return m_data_dir.c_str();
        }
        if (dt==DIR_TYPE_USER_PROFILE) {
            return m_docs_dir.c_str();
        }
        if (dt==DIR_TYPE_CACHE) {
            return m_cache_dir.c_str();
        }
        return "/";
    }
    /// file is exists
    bool GHL_CALL VFSPosixImpl::IsFileExists(const char* file) const {
		typedef struct stat stat_t;
		stat_t s;
		if (::stat(file, (stat_t*)(&s)) == 0) {
            if ((s.st_mode&S_IFREG)!=0) {
                return true;
            }
        }
        //LOG_VERBOSE("file not exist '" << file << "'");
        return false;
    }
    /// remove file
    bool GHL_CALL VFSPosixImpl::DoRemoveFile(const char* file) {
        ::remove(file);
        return false;
    }
    /// copy file
    bool GHL_CALL VFSPosixImpl::DoCopyFile(const char* from,const char* to) {
        DataStream* src = OpenFile(from);
        if (!src){
            return false;
        }
        WriteStream* dst = OpenFileWrite(to);
        if (!dst) {
            src->Release();
            return false;
        }
        
        while (!src->Eof()) {
            UInt32 w = src->Read(m_buffer, sizeof(m_buffer));
            if (w) {
                w -= dst->Write(m_buffer, w);
            }
        }
        src->Release();
        dst->Release();
        return true;
    }
    /// rename file
    bool GHL_CALL VFSPosixImpl::DoRenameFile(const char* from,const char* to) {
        return ::rename(from,to) == 0;
    }
    /// create dir
    bool GHL_CALL VFSPosixImpl::DoCreateDir(const char* path) {
        return ::mkdir(path, 0777) == 0;
    }
    /// open file
    DataStream* GHL_CALL VFSPosixImpl::OpenFile(const char* _file){
        (void)MODULE;
        //LOG_VERBOSE("try open file '" << _file << "'");
        if (!_file) return 0;
        if (_file[0]==0) return 0;
        if (!IsFileExists(_file)) return 0;
        FILE* f = fopen(_file, "rb" );
        if (f) {
            return new PosixFileStream(f);
        }
        //LOG_VERBOSE("failed open file '" << _file << "' " << errno);
        return 0;
    }
    
    WriteStream* GHL_CALL VFSPosixImpl::OpenFileWrite(const char* _file){
        (void)MODULE;
        //LOG_VERBOSE("try open write file '" << _file << "'");
        if (!_file) return 0;
        if (_file[0]==0) return 0;
        create_dir(_file);
        FILE* f = fopen(_file, "wb"  );
        if (f)
            return new PosixWriteFileStream(f);
        return 0;
    }
    
    /// write file
    bool GHL_CALL VFSPosixImpl::WriteFile(const char* file, const Data* data) {
        create_dir(file);
        FILE* f = fopen(file, "wb" );
        if (!f)
            return false;
        size_t writen = fwrite(data->GetData(), data->GetSize(),1,  f);
        fclose(f);
        return writen == 1;
    }
}


GHL_API GHL::VFS* GHL_CALL GHL_CreateVFSPosix(const char* data,const char* docs) {
    return new GHL::VFSPosixImpl(data,docs);
}

GHL_API void GHL_CALL GHL_DestroyVFSPosix(GHL::VFS* vfs) {
    delete reinterpret_cast<GHL::VFSPosixImpl*>(vfs);
}


