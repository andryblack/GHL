//
//  vfs_cocoa.h
//  SR
//
//  Created by Андрей Куницын on 04.02.11.
//  Copyright 2011 andryblack. All rights reserved.
//



#include <ghl_vfs.h>

#include <string>

namespace GHL  {
	class VFSCocoaImpl : public VFS {
	public:
		VFSCocoaImpl();
        virtual ~VFSCocoaImpl();
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
		virtual DataStream* GHL_CALL OpenFile(const char* file,FileOperation ot=FILE_READ);
		/// get stream from memory
		virtual DataStream* GHL_CALL CreateStreamFromMemory(Byte* data,UInt32 size) ;
	private:
		std::string m_data_dir;
	};
}



