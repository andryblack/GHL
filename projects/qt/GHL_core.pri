SRCDIR=$$PWD/../../src

SOURCES += \
        $$SRCDIR/zlib/adler32.c \
        $$SRCDIR/zlib/crc32.c \
        $$SRCDIR/zlib/deflate.c \
        $$SRCDIR/zlib/inffast.c \
        $$SRCDIR/zlib/inflate.c \
        $$SRCDIR/zlib/inftrees.c \
        $$SRCDIR/zlib/trees.c \
        $$SRCDIR/zlib/zutil.c

HEADERS+=\
    $$SRCDIR/ghl_data_impl.h\
    $$SRCDIR/ghl_log_impl.h\
    $$SRCDIR/ghl_ref_counter_impl.h\


SOURCES+=\
    $$SRCDIR/ghl_data_impl.cpp\
    $$SRCDIR/ghl_log_impl.cpp\
    $$SRCDIR/winlib/winlib_qt.cpp

