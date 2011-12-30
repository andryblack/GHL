//
//  vfs_cocoa.m
//  SR
//
//  Created by Андрей Куницын on 04.02.11.
//  Copyright 2011 andryblack. All rights reserved.
//

#import "vfs_cocoa.h"
#import <Foundation/Foundation.h>

#include "memory_stream.h"
#include "../ghl_log_impl.h"



namespace GHL {

    static const char* MODULE = "VFS";
	
	class CocoaReadFileStream : public DataStream {
	private:
		NSFileHandle* m_file;
		UInt32 m_size;
		~CocoaReadFileStream() {
			if (m_file) {
				[m_file closeFile];
				[m_file release];
			}
		}
	public:
		explicit CocoaReadFileStream(NSFileHandle* file) : m_file(file) {
			[m_file retain];
			[m_file seekToEndOfFile];
			m_size = static_cast<UInt32>([m_file offsetInFile]);
			[m_file seekToFileOffset:0];
		}
		/// read data
		virtual UInt32 GHL_CALL Read(Byte* dest,UInt32 bytes) {
			NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
			UInt32 len = 0;
			NSData* data = [m_file readDataOfLength:bytes];
			if (data) {
				[data getBytes:dest length:bytes];
				len = static_cast<UInt32>([data length]);
			}
			[pool release];
			return len;
		}
		/// write data
		virtual UInt32 GHL_CALL Write(const Byte* /*src*/,UInt32 /*bytes*/) {
            LOG_ERROR("CocoaReadFileStream::Write unimplemented");
			return 0;
		}
		/// tell
		virtual UInt32 GHL_CALL Tell() const {
			return UInt32([m_file offsetInFile]);
		}
		/// seek
		virtual	bool GHL_CALL Seek(Int32 offset,FileSeekType st) {
			if (st == F_SEEK_BEGIN) {
				[m_file seekToFileOffset:offset];
				return true;
			} else if (st == F_SEEK_END) {
				[m_file seekToFileOffset:(m_size- offset)];
				return true;
			} else if (st == F_SEEK_CURRENT) {
				[m_file seekToFileOffset:([m_file offsetInFile] + offset)];
				return true;
			}
			return false;
		}
		/// End of file
		virtual bool GHL_CALL Eof() const {
			return [m_file offsetInFile] == m_size;
		}
		/// release stream
		virtual void GHL_CALL Release() {
			delete this;
		}
	};
	
	class CocoaWriteFileStream : public DataStream {
	private:
		NSFileHandle* m_file;
		size_t m_size;
		~CocoaWriteFileStream() {
			if (m_file) {
				[m_file closeFile];
				[m_file release];
			}
		}
	public:
		explicit CocoaWriteFileStream(NSFileHandle* file) : m_file(file) {
			[m_file retain];
			m_size = 0;
		}
		/// read data
		virtual UInt32 GHL_CALL Read(Byte* /*dest*/,UInt32 /*bytes*/) {
            LOG_ERROR("CocoaWriteFileStream::Read unimplemented");
			return 0;
		}
		/// write data
		virtual UInt32 GHL_CALL Write(const Byte* src,UInt32 bytes) {
			NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
			[m_file writeData:[NSData dataWithBytes:src length:bytes]];
			[pool release];
			m_size+=bytes;
			return bytes;
		}
		/// tell
		virtual UInt32 GHL_CALL Tell() const {
			return UInt32([m_file offsetInFile]);
		}
		/// seek
		virtual	bool GHL_CALL Seek(Int32 offset,FileSeekType st) {
			if (st == F_SEEK_BEGIN) {
				[m_file seekToFileOffset:offset];
				return true;
			} else if (st == F_SEEK_END) {
				[m_file seekToFileOffset:(m_size-offset)];
				return true;
			} else if (st == F_SEEK_CURRENT) {
				[m_file seekToFileOffset:([m_file offsetInFile] + offset)];
				return true;
			}
			return false;
		}
		/// End of file
		virtual bool GHL_CALL Eof() const {
			return false;
		}
		/// release stream
		virtual void GHL_CALL Release() {
			delete this;
		}
	};
	
	
	
	VFSCocoaImpl::VFSCocoaImpl() {
		NSBundle* bundle = [NSBundle mainBundle];
		if (bundle) {
			NSString* res = [bundle resourcePath];
			m_data_dir = [res UTF8String];
            LOG_VERBOSE("data_dir: " << m_data_dir);
		}
	}

	VFSCocoaImpl::~VFSCocoaImpl() {
	}
	
	/// get dir
	const char* GHL_CALL VFSCocoaImpl::GetDir(DirType dt) const {
		if (dt == DIR_TYPE_DATA) {
			return m_data_dir.c_str();
		}
		return 0;
	}
	/// attach package
	void GHL_CALL VFSCocoaImpl::AttachPack(DataStream* /*ds*/) {
	}
	/// file is exists
	bool GHL_CALL VFSCocoaImpl::IsFileExists(const char* file) const {
		std::string filename = file;
		for (size_t i=0;i<filename.length();i++) {
			if (filename[i]=='\\') filename[i]='/';
		}
		NSString* path = [NSString stringWithUTF8String:filename.c_str()];
		return [[NSFileManager defaultManager] fileExistsAtPath:path] == YES;
	}
	/// remove file
	bool GHL_CALL VFSCocoaImpl::DoRemoveFile(const char* /*file*/) {
        LOG_ERROR("VFSCocoaImpl::DoRemoveFile unimplemented");
		return false;
	}
	/// copy file
	bool GHL_CALL VFSCocoaImpl::DoCopyFile(const char* /*from*/,const char* /*to*/) {
        LOG_ERROR("VFSCocoaImpl::DoCopyFile unimplemented");
		return false;
	}
	/// open file
	DataStream* GHL_CALL VFSCocoaImpl::OpenFile(const char* file,FileOperation ot) {
		std::string filename = file;
		for (size_t i=0;i<filename.length();i++) {
			if (filename[i]=='\\') filename[i]='/';
		}
		if (ot == FILE_READ) {
			NSFileHandle* handle = [NSFileHandle fileHandleForReadingAtPath:[NSString stringWithUTF8String:filename.c_str()]];
			if (handle) {
				return new CocoaReadFileStream(handle);
			}
		} else if (ot==FILE_WRITE) {
			NSString* path = [NSString stringWithUTF8String:filename.c_str()];
			NSFileHandle* handle = [NSFileHandle fileHandleForWritingAtPath:path];
			if (handle) {
				return new CocoaWriteFileStream(handle);
			} else {
				if ([[NSFileManager defaultManager] createFileAtPath:path contents:nil attributes:nil]) {
					handle = [NSFileHandle fileHandleForWritingAtPath:path];
					if (handle) {
						return new CocoaWriteFileStream(handle);
					}
				}
			}
		}
		return 0;
	}
	/// get stream from memory
	DataStream* GHL_CALL VFSCocoaImpl::CreateStreamFromMemory(Byte* data,UInt32 size) {
		return new MemoryStream(data,size);
	}
}