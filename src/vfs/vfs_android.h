#ifndef VFS_ANDROID_H
#define VFS_ANDROID_H

#include "vfs_posix.h"

struct AAssetManager;

namespace GHL {

	class VFSAndroidImpl : public VFSPosixImpl {
	public:
		explicit VFSAndroidImpl(AAssetManager* assetManager,const char* dataDir);
		virtual ~VFSAndroidImpl();
		/// attach package
		virtual void GHL_CALL AttachPack(DataStream* ds) ;
		/// file is exists
		virtual bool GHL_CALL IsFileExists(const char* file) const;
		/// remove file
		virtual bool GHL_CALL DoRemoveFile(const char* file) ;
		/// copy file
		virtual bool GHL_CALL DoCopyFile(const char* from,const char* to) ;
		/// open file
		virtual DataStream* GHL_CALL OpenFile(const char* file);
		
	private:
        AAssetManager*  m_asset_manager;
	};

}

#endif /*VFS_POSIX_H*/
