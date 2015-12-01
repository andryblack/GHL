/*
    GHL - Game Helpers Library
    Copyright (C)  Andrey Kunitsyn 2009

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    Andrey (AndryBlack) Kunitsyn
    blackicebox (at) gmail (dot) com
*/

#ifndef GHL_VFS_H
#define GHL_VFS_H

#include "ghl_data_stream.h"

namespace GHL
{

	/// directory type
	enum DirType
	{
		DIR_TYPE_DATA,			///< current application dara dir
        DIR_TYPE_USER_PROFILE,	///< writable user profile dir
        DIR_TYPE_CACHE          ///< writable temp dir
	};


	/// Virtual File System
	struct VFS
	{
		/// get dir
		virtual const char* GHL_CALL GetDir(DirType dt) const = 0;
		/// file is exists
		virtual bool GHL_CALL IsFileExists(const char* file) const = 0;
		/// remove file
		virtual bool GHL_CALL DoRemoveFile(const char* file) = 0;
		/// copy file
		virtual bool GHL_CALL DoCopyFile(const char* from,const char* to) = 0;
        /// rename file
        virtual bool GHL_CALL DoRenameFile(const char* from,const char* to) = 0;
        /// create dir
        virtual bool GHL_CALL DoCreateDir(const char* path) = 0;
		/// open file
		virtual DataStream* GHL_CALL OpenFile(const char* file) = 0;
        /// open write file
        virtual WriteStream* GHL_CALL OpenFileWrite(const char* file) = 0;
        /// write file
        virtual bool GHL_CALL WriteFile(const char* file, const Data* data ) = 0;
	};
	
	


}/*namespace*/


GHL_API GHL::VFS* GHL_CALL GHL_CreateVFS();
GHL_API void GHL_CALL GHL_DestroyVFS(GHL::VFS* vfs);


#endif /*GHL_VFS_H*/
