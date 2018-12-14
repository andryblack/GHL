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
#include "posix_stream.h"


namespace GHL {

    static const char* MODULE = "VFS";
	
	
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
#ifndef GHL_PLATFORM_IOS
            NSString* bundleid = [bundle bundleIdentifier];
            if (bundleid) {
                path = [path stringByAppendingPathComponent:bundleid];
            } else {
                path = [path stringByAppendingPathComponent:@"sandbox"];
            }
#endif
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
#ifndef GHL_PLATFORM_IOS
            NSString* bundleid = [bundle bundleIdentifier];
            if (bundleid) {
                path = [path stringByAppendingPathComponent:bundleid];
            } else {
                path = [path stringByAppendingPathComponent:@"sandbox"];
            }
#endif
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
	/// file is exists
	bool GHL_CALL VFSCocoaImpl::IsFileExists(const char* file) const {
		NSString* path = [NSString stringWithUTF8String:file];
		return [[NSFileManager defaultManager] fileExistsAtPath:path] == YES;
	}
	/// remove file
	bool GHL_CALL VFSCocoaImpl::DoRemoveFile(const char* file) {
        NSString* path = [NSString stringWithUTF8String:file];
        return [[NSFileManager defaultManager] removeItemAtPath:path error:nil];
	}
	/// copy file
	bool GHL_CALL VFSCocoaImpl::DoCopyFile(const char* from,const char* to) {
        NSString* path_from = [NSString stringWithUTF8String:from];
        NSString* path_to = [NSString stringWithUTF8String:to];
        return [[NSFileManager defaultManager] copyItemAtPath:path_from toPath:path_to error:nil];
	}
    /// rename file
    bool GHL_CALL VFSCocoaImpl::DoRenameFile(const char* from,const char* to) {
        NSString* path_from = [NSString stringWithUTF8String:from];
        NSString* path_to = [NSString stringWithUTF8String:to];
        return [[NSFileManager defaultManager] moveItemAtPath:path_from toPath:path_to error:nil];
    }
    /// create dir
    bool GHL_CALL VFSCocoaImpl::DoCreateDir(const char* fpath) {
        NSString* path = [NSString stringWithUTF8String:fpath];
        return [[NSFileManager defaultManager] createDirectoryAtPath:path
                                  withIntermediateDirectories:YES
                                                   attributes:nil error:nil];
    }
	/// open file
	DataStream* GHL_CALL VFSCocoaImpl::OpenFile(const char* file) {
        (void)MODULE;
        //LOG_VERBOSE("try open file '" << _file << "'");
        if (!file) return 0;
        if (file[0]==0) return 0;
        FILE* f = fopen(file, "rb" );
        if (f) {
            return new PosixFileStream(f);
        }
        //LOG_VERBOSE("failed open file '" << _file << "' " << errno);
        return 0;
    }
    
    /// open file
    WriteStream* GHL_CALL VFSCocoaImpl::OpenFileWrite(const char* file) {
        if (!file) return 0;
        if (file[0]==0) return 0;
        
        NSFileManager* fm = [NSFileManager defaultManager];
        [fm
         createDirectoryAtPath:[[NSString stringWithUTF8String:file] stringByDeletingLastPathComponent]
         withIntermediateDirectories:YES
         attributes:nil
         error:nil];
        
        FILE* f = fopen(file, "wb"  );
        if (f)
            return new PosixWriteFileStream(f);
        return 0;
    }
    
    /// write file
    bool GHL_CALL VFSCocoaImpl::WriteFile(const char* file, const Data* data ) {
       
        NSString* path = [NSString stringWithUTF8String:file];
        
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

