#ifndef VFS_POSIX_H
#define VFS_POSIX_H

#include <ghl_vfs.h>
#include <string>

namespace GHL {

	class VFSPosixImpl : public VFS {
	public:
		VFSPosixImpl(const char* dat,const char* docs);
		virtual ~VFSPosixImpl();
		/// get dir
		virtual const char* GHL_CALL GetDir(DirType dt) const ;
		/// file is exists
		virtual bool GHL_CALL IsFileExists(const char* file) const;
		/// remove file
		virtual bool GHL_CALL DoRemoveFile(const char* file) ;
		/// copy file
		virtual bool GHL_CALL DoCopyFile(const char* from,const char* to) ;
        virtual bool GHL_CALL DoRenameFile(const char* from,const char* to) ;
        /// create dir
        virtual bool GHL_CALL DoCreateDir(const char* path);
		/// open file
		virtual DataStream* GHL_CALL OpenFile(const char* file);
        virtual WriteStream* GHL_CALL OpenFileWrite(const char* file);
        /// write file
        virtual bool GHL_CALL WriteFile(const char* file, const Data* data);

        void SetCacheDir(const std::string& dir);
    protected:
    	std::string m_cache_dir;
	private:
		std::string m_data_dir;
        std::string m_docs_dir;
        Byte m_buffer[1024*8];
	};

}

#endif /*VFS_POSIX_H*/
