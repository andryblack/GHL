SRCDIR=$$PWD/../../src/image

SOURCES += \
        $$SRCDIR/jpeg/jaricom.c \
        $$SRCDIR/jpeg/jcapimin.c \
        $$SRCDIR/jpeg/jcapistd.c \
        $$SRCDIR/jpeg/jcarith.c \
        $$SRCDIR/jpeg/jccoefct.c \
        $$SRCDIR/jpeg/jccolor.c \
        $$SRCDIR/jpeg/jcdctmgr.c \
        $$SRCDIR/jpeg/jchuff.c \
        $$SRCDIR/jpeg/jcinit.c \
        $$SRCDIR/jpeg/jcmainct.c \
        $$SRCDIR/jpeg/jcmarker.c \
        $$SRCDIR/jpeg/jcmaster.c \
        $$SRCDIR/jpeg/jcomapi.c \
        $$SRCDIR/jpeg/jcparam.c \
        $$SRCDIR/jpeg/jcprepct.c \
        $$SRCDIR/jpeg/jcsample.c \
        $$SRCDIR/jpeg/jctrans.c \
        $$SRCDIR/jpeg/jdapimin.c \
        $$SRCDIR/jpeg/jdapistd.c \
        $$SRCDIR/jpeg/jdarith.c \
        $$SRCDIR/jpeg/jdatadst.c \
        $$SRCDIR/jpeg/jdcoefct.c \
        $$SRCDIR/jpeg/jdcolor.c \
        $$SRCDIR/jpeg/jddctmgr.c \
        $$SRCDIR/jpeg/jdhuff.c \
        $$SRCDIR/jpeg/jdinput.c \
        $$SRCDIR/jpeg/jdmainct.c \
        $$SRCDIR/jpeg/jdmarker.c \
        $$SRCDIR/jpeg/jdmaster.c \
        $$SRCDIR/jpeg/jdmerge.c \
        $$SRCDIR/jpeg/jdpostct.c \
        $$SRCDIR/jpeg/jdsample.c \
        $$SRCDIR/jpeg/jdtrans.c \
        $$SRCDIR/jpeg/jerror.c \
        $$SRCDIR/jpeg/jfdctflt.c \
        $$SRCDIR/jpeg/jfdctfst.c \
        $$SRCDIR/jpeg/jfdctint.c \
        $$SRCDIR/jpeg/jidctflt.c \
        $$SRCDIR/jpeg/jidctfst.c \
        $$SRCDIR/jpeg/jidctint.c \
        $$SRCDIR/jpeg/jmemmgr.c \
        $$SRCDIR/jpeg/jmemnobs.c \
        $$SRCDIR/jpeg/jquant1.c \
        $$SRCDIR/jpeg/jquant2.c \
        $$SRCDIR/jpeg/jutils.c \
        $$SRCDIR/jpeg/transupp.c

SOURCES += \
        $$SRCDIR/libpng/png.c \
        $$SRCDIR/libpng/pngerror.c \
        $$SRCDIR/libpng/pngget.c \
        $$SRCDIR/libpng/pngmem.c \
        $$SRCDIR/libpng/pngpread.c \
        $$SRCDIR/libpng/pngread.c \
        $$SRCDIR/libpng/pngrio.c \
        $$SRCDIR/libpng/pngrtran.c \
        $$SRCDIR/libpng/pngrutil.c \
        $$SRCDIR/libpng/pngset.c \
        $$SRCDIR/libpng/pngtrans.c \
        $$SRCDIR/libpng/pngwio.c \
        $$SRCDIR/libpng/pngwrite.c \
        $$SRCDIR/libpng/pngwtran.c \
        $$SRCDIR/libpng/pngwutil.c



HEADERS+=\
    $$SRCDIR/ghl_image_config.h\
    $$SRCDIR/image_decoders.h\
    $$SRCDIR/image_file_decoder.h\
    $$SRCDIR/image_impl.h\
    $$SRCDIR/jpeg_image_decoder.h\
    $$SRCDIR/png_image_decoder.h\
    $$SRCDIR/tga_image_decoder.h\


SOURCES+=\
    $$SRCDIR/image_decoders.cpp\
    $$SRCDIR/image_file_decoder.cpp\
    $$SRCDIR/image_impl.cpp\
    $$SRCDIR/jpeg_image_decoder.cpp\
    $$SRCDIR/png_image_decoder.cpp\
    $$SRCDIR/tga_image_decoder.cpp\
