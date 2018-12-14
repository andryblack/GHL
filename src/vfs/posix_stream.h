#ifndef VFS_POSIX_STREAM_H
#define VFS_POSIX_STREAM_H

#include <ghl_vfs.h>
#include <ghl_data_stream.h>
#include "../ghl_ref_counter_impl.h"

#include <stdio.h>

namespace GHL {

	class PosixFileStream : public RefCounterImpl<DataStream> {
    private:
        FILE* m_file;
    public:
        explicit PosixFileStream(FILE* file);
        virtual ~PosixFileStream();
        /// read data
        virtual UInt32 GHL_CALL Read(Byte* dest,UInt32 bytes);
        /// tell
        virtual UInt32 GHL_CALL Tell() const;
        /// seek
        virtual	bool GHL_CALL Seek(Int32 offset,FileSeekType st);
        /// End of file
        virtual bool GHL_CALL Eof() const;
    };
    
    class PosixWriteFileStream : public RefCounterImpl<WriteStream> {
    private:
        FILE* m_file;
    public:
        explicit PosixWriteFileStream(FILE* file);
        virtual ~PosixWriteFileStream();
        virtual void GHL_CALL Flush();
        virtual void GHL_CALL Close();
        /// write data
        virtual UInt32 GHL_CALL Write(const Byte* src,UInt32 bytes);
    };


}

#endif /*VFS_POSIX_STREAM_H*/
