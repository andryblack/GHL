#ifndef VFS_WIN32_H
#define VFS_WIN32_H

#include <ghl_vfs.h>
#include <string>

namespace GHL {

	class VFSWin32Impl : public VFS {
	public:
		VFSWin32Impl();
		~VFSWin32Impl();
		/// get dir
		virtual const char* GHL_CALL GetDir(DirType dt) const ;
		/// file is exists
		virtual bool GHL_CALL IsFileExists(const char* file) const;
		/// remove file
		virtual bool GHL_CALL DoRemoveFile(const char* file) ;
		/// copy file
		virtual bool GHL_CALL DoCopyFile(const char* from,const char* to) ;
		/// create dir
		virtual bool GHL_CALL DoCreateDir(const char* path);
		/// open file
		virtual DataStream* GHL_CALL OpenFile(const char* file);
		/// write file
		virtual bool GHL_CALL WriteFile(const char* file, const Data* data);
	private:
		std::string m_data_dir;
	};

}

#endif /*VFS_WIN32_H*/