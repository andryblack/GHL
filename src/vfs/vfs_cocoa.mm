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
#include "../ghl_ref_counter_impl.h"
#include <ghl_data.h>



namespace GHL {

    static const char* MODULE = "VFS";
	
	class CocoaReadFileStream : public RefCounterImpl<DataStream> {
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
	};
	
	class CocoaWriteFileStream : public RefCounterImpl<DataStream> {
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
	};
	
	
	
	VFSCocoaImpl::VFSCocoaImpl() {
		NSBundle* bundle = [NSBundle mainBundle];
		if (bundle) {
			NSString* res = [bundle resourcePath];
			m_data_dir = [res UTF8String];
            LOG_VERBOSE("data_dir: " << m_data_dir);
		}
        NSArray* paths = NSSearchPathForDirectoriesInDomains(
                                                             NSApplicationSupportDirectory,
                                                             NSUserDomainMask,
                                                            YES);
        if ( !paths || paths.count == 0 ) {
            LOG_ERROR("not found any application support directory");
            m_profile_dir = "/Library/Application Support/sandbox";
        } else {
            NSString* path = [paths objectAtIndex:0];
            NSString* bundleid = [bundle bundleIdentifier];
            if (bundleid) {
                path = [path stringByAppendingPathComponent:bundleid];
            } else {
                path = [path stringByAppendingPathComponent:@"sandbox"];
            }
            m_profile_dir = [path UTF8String];
        }
        DoCreateDir(m_profile_dir.c_str());
        
        paths = NSSearchPathForDirectoriesInDomains(
                                                    NSCachesDirectory,
                                                    NSUserDomainMask,
                                                    YES);
        if (!paths || paths.count == 0) {
            LOG_ERROR("not found any cache directory");
            m_cache_dir = "/Library/Caches/sandbox";
        } else {
            NSString* path = [paths objectAtIndex:0];
            NSString* bundleid = [bundle bundleIdentifier];
            if (bundleid) {
                path = [path stringByAppendingPathComponent:bundleid];
            } else {
                path = [path stringByAppendingPathComponent:@"sandbox"];
            }
            m_cache_dir = [path UTF8String];
        }
        DoCreateDir(m_cache_dir.c_str());
	}

	VFSCocoaImpl::~VFSCocoaImpl() {
	}
	
	/// get dir
	const char* GHL_CALL VFSCocoaImpl::GetDir(DirType dt) const {
		if (dt == DIR_TYPE_DATA) {
			return m_data_dir.c_str();
		}
        if (dt == DIR_TYPE_USER_PROFILE) {
			return m_profile_dir.c_str();
		}
        if (dt == DIR_TYPE_CACHE) {
            return m_cache_dir.c_str();
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
    /// create dir
    bool GHL_CALL VFSCocoaImpl::DoCreateDir(const char* fpath) {
        std::string filename = fpath;
        for (size_t i=0;i<filename.length();i++) {
            if (filename[i]=='\\') filename[i]='/';
        }
        NSString* path = [NSString stringWithUTF8String:filename.c_str()];
        return [[NSFileManager defaultManager] createDirectoryAtPath:path
                                  withIntermediateDirectories:YES
                                                   attributes:nil error:nil];
    }
	/// open file
	DataStream* GHL_CALL VFSCocoaImpl::OpenFile(const char* file) {
		std::string filename = file;
		for (size_t i=0;i<filename.length();i++) {
			if (filename[i]=='\\') filename[i]='/';
		}
        NSFileHandle* handle = [NSFileHandle fileHandleForReadingAtPath:[NSString stringWithUTF8String:filename.c_str()]];
        if (handle) {
            return new CocoaReadFileStream(handle);
        }
        return 0;
	}
    
    /// write file
    bool GHL_CALL VFSCocoaImpl::WriteFile(const char* file, const Data* data ) {
        std::string filename = file;
        for (size_t i=0;i<filename.length();i++) {
            if (filename[i]=='\\') filename[i]='/';
        }

        NSString* path = [NSString stringWithUTF8String:filename.c_str()];
        
        NSFileManager* fm = [NSFileManager defaultManager];
        [fm
         createDirectoryAtPath:[path stringByDeletingLastPathComponent]
         withIntermediateDirectories:YES
         attributes:nil
         error:nil];
        [fm removeItemAtPath:path error:nil];
        NSData* data_ = [NSData dataWithBytesNoCopy:const_cast<Byte*>(data->GetData()) length:data->GetSize() freeWhenDone:NO];
        return [data_ writeToFile:path options:NSDataWritingAtomic error:nil];
    }
}

