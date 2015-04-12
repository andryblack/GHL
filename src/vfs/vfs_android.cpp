#include "vfs_android.h"
#include "memory_stream.h"
#include "../ghl_ref_counter_impl.h"
#include "../ghl_log_impl.h"

#include <jni.h>
#include <android/asset_manager.h>

namespace GHL {

    const char* MODULE = "VFS";
    static const UInt32 magick = 0xBEAFAD10;
    
    class AssetFileStream : public RefCounterImpl<DataStream> {
    private:
        UInt32  m_magick;
        AAsset* m_file;
        UInt32 m_position;
        UInt32 m_size;
    public:
        
        explicit AssetFileStream(AAsset* file) {
            m_magick = magick;
            m_file = file;
            m_position = 0;
            m_size = AAsset_getLength(m_file);
        }
        virtual ~AssetFileStream() {
            m_magick = 0;
            AAsset_close( m_file );
        }
        static AAsset* GetAsset( DataStream* ds ) {
            if (!ds) return 0;
            AssetFileStream* afs = reinterpret_cast<AssetFileStream*>(ds);
            if (afs->m_magick == magick) {
                return afs->m_file;
            }
            return 0;
        }
        /// read data
        virtual UInt32 GHL_CALL Read(Byte* dest,UInt32 bytes) {
            UInt32 readed = AAsset_read(m_file,dest,bytes);
            m_position+=readed;
            return readed;
        }
        /// write data
        virtual UInt32 GHL_CALL Write(const Byte* src,UInt32 bytes) {
            return 0;
        }
        /// tell
        virtual UInt32 GHL_CALL Tell() const {
            return m_position;
        }
        /// seek
        virtual	bool GHL_CALL Seek(Int32 offset,FileSeekType st) {
            int dir = 0;
            switch (st)
            {
                case F_SEEK_CURRENT :
                    dir = SEEK_CUR;
                    break;
                case F_SEEK_END :
                    dir = SEEK_END;
                    break;
                case F_SEEK_BEGIN :
                    dir = SEEK_SET;
                    break;
                default: return false;
            }
            off_t pos = AAsset_seek(m_file,offset,dir);
            if (pos==-1) return false;
            m_position = pos;
            return true;
        }
        /// End of file
        virtual bool GHL_CALL Eof() const {
            return m_position>=m_size;
        }
    };
    
    AAsset* GetAssetFromDataStream( DataStream* ds ) {
        return AssetFileStream::GetAsset(ds);
    }

    static const char* assets_prefix = "assets:";
    
    static bool is_asset_file(const char* fn) {
        return strncmp(fn,assets_prefix,7)==0;
    }
    
    VFSAndroidImpl::VFSAndroidImpl(AAssetManager* assetManager,const char* dataDir)
        : VFSPosixImpl(assets_prefix,dataDir), m_asset_manager(assetManager) {
    }

    VFSAndroidImpl::~VFSAndroidImpl() {
    }

    /// attach package
    void GHL_CALL VFSAndroidImpl::AttachPack(DataStream* /*ds*/) {
    }
    /// file is exists
    bool GHL_CALL VFSAndroidImpl::IsFileExists(const char* file) const {
        if (is_asset_file(file)) {
            file = file + 7;
            if (*file=='/')
                ++file;
            AAsset* asset = AAssetManager_open(m_asset_manager,file,AASSET_MODE_UNKNOWN);
            if (!asset)
                return false;
            AAsset_close(asset);
            return true;
        }
        return VFSPosixImpl::IsFileExists(file);
    }
    /// remove file
    bool GHL_CALL VFSAndroidImpl::DoRemoveFile(const char* file) {
        if (is_asset_file(file)) {
            return false;
        }
        return VFSPosixImpl::DoRemoveFile(file);
    }
    /// copy file
    bool GHL_CALL VFSAndroidImpl::DoCopyFile(const char* from,const char* to) {
        if (is_asset_file(to)) {
            return false;
        }
        if (is_asset_file(from)) {
            /// @todo
            return false;
        }
        return VFSPosixImpl::DoCopyFile( from, to );
    }
    /// open file
    DataStream* GHL_CALL VFSAndroidImpl::OpenFile(const char* _file) {
        if (!_file) return 0;
        if (_file[0]==0) return 0;
        //LOG_DEBUG( "OpenFile " << _file );
        bool is_asset = is_asset_file(_file);
        if (!is_asset)
            return VFSPosixImpl::OpenFile(_file);
        const char* file = _file + 7;
        if (*file=='/')
            ++file;
        //LOG_DEBUG( "AAssetManager_open " << file );
        AAsset* asset = AAssetManager_open(m_asset_manager,file,AASSET_MODE_RANDOM);
        if (!asset) return 0;
        return new AssetFileStream(asset);
    }
}



