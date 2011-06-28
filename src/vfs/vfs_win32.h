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
		/// attach package
		virtual void GHL_CALL AttachPack(DataStream* ds) ;
		/// file is exists
		virtual bool GHL_CALL IsFileExists(const char* file) const;
		/// remove file
		virtual bool GHL_CALL DoRemoveFile(const char* file) ;
		/// copy file
		virtual bool GHL_CALL DoCopyFile(const char* from,const char* to) ;
		/// open file
		virtual DataStream* GHL_CALL OpenFile(const char* file,FileOperation ot);
		/// get stream from memory
		virtual DataStream* GHL_CALL CreateStreamFromMemory(Byte* data,UInt32 size) ;
	private:
		std::string m_data_dir;
	};

}

#endif /*VFS_WIN32_H*/