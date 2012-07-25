#ifndef VFS_ANDROID_H
#define VFS_ANDROID_H

#include "vfs_posix.h"

struct AAssetManager;

namespace GHL {

	class VFSAndroidImpl : public VFSPosixImpl {
	public:
		explicit VFSAndroidImpl(AAssetManager* assetManager,const char* dataDir);
		virtual ~VFSAndroidImpl();
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
        AAssetManager*  m_asset_manager;
		std::string m_data_dir;
	};

}

#endif /*VFS_POSIX_H*/
