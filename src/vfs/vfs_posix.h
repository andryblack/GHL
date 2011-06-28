#ifndef VFS_POSIX_H
#define VFS_POSIX_H

#include <ghl_vfs.h>
#include <string>

namespace GHL {

	class VFSPosixImpl : public VFS {
	public:
		VFSPosixImpl();
		virtual ~VFSPosixImpl();
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

#endif /*VFS_POSIX_H*/
