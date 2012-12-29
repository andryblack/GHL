TARGET=GHL-qt
debug {
    TARGET=GHL-qt_d
}

CONFIG-=qt
TEMPLATE=lib
DESTDIR = ../../lib
CONFIG+=staticlib

#public includes
HEADERS+=../../include/ghl_vfs.h \
    ../../include/ghl_types.h \
    ../../include/ghl_texture.h \
    ../../include/ghl_system.h \
    ../../include/ghl_sound.h \
    ../../include/ghl_shader.h \
    ../../include/ghl_settings.h \
    ../../include/ghl_render.h \
    ../../include/ghl_render_target.h \
    ../../include/ghl_keys.h \
    ../../include/ghl_image.h \
    ../../include/ghl_image_decoder.h \
    ../../include/ghl_data_stream.h \
    ../../include/ghl_application.h \
    ../../include/ghl_api.h

INCLUDEPATH+=../../include

#common
SOURCES+=\
    ../../src/ghl_data_impl.cpp \
    ../../src/ghl_log_impl.cpp

HEADERS+=\
    ../../src/ghl_data_impl.h \
    ../../src/ghl_log_impl.h \
    ../../src/ghl_ref_counter_impl.h


#common VFS
SOURCES+=\
    ../../src/vfs/memory_stream.cpp \
    ../../src/vfs/ghl_vfs_factory.cpp

HEADERS+=../../src/vfs/memory_stream.h

#common image
SOURCES+=../../src/image/tga_image_decoder.cpp  \
        ../../src/image/image_impl.cpp \
        ../../src/image/image_decoders.cpp \
        ../../src/image/png_image_decoder.cpp \
        ../../src/image/jpeg_image_decoder.cpp

HEADERS+=../../src/image/tga_image_decoder.h \
    ../../src/image/image_impl.h \
    ../../src/image/image_file_decoder.h \
    ../../src/image/image_decoders.h \
    ../../src/image/image_config.h

#common render
SOURCES+=../../src/render/render_impl.cpp \
    ../../src/render/texture_impl.cpp \
    ../../src/render/buffer_impl.cpp \
    ../../src/render/shader_impl.cpp \
    ../../src/render/rendertarget_impl.cpp \
    ../../src/render/lucida_console_regular_8.cpp
HEADERS+=../../src/render/rendertarget_impl.h \
    ../../src/render/render_impl.h \
    ../../src/render/texture_impl.h \
    ../../src/render/buffer_impl.h \
    ../../src/render/shader_impl.h \
    ../../src/render/lucida_console_regular_8.h

#opengl render
SOURCES+=\
    ../../src/render/opengl/texture_opengl.cpp \
    ../../src/render/opengl/shader_glsl.cpp \
    ../../src/render/opengl/rendertarget_opengl.cpp \
    ../../src/render/opengl/render_opengl.cpp \
    ../../src/render/opengl/render_opengl2.cpp \
    ../../src/render/opengl/dynamic/dynamic_gl.cpp
HEADERS+=\
    ../../src/render/opengl/texture_opengl.h \
    ../../src/render/opengl/shader_glsl.h \
    ../../src/render/opengl/rendertarget_opengl.h \
    ../../src/render/opengl/render_opengl.h \
    ../../src/render/opengl/render_opengl2.h \
    ../../src/render/opengl/ghl_opengl.h \
    ../../src/render/opengl/dynamic/dynamic_gl.h \
    ../../src/render/opengl/dynamic/dynamic_gl_subset.h

#common decoders
SOURCES+=\
    ../../src/sound/sound_decoders.cpp
HEADERS+=\
    ../../src/sound/ghl_sound_decoder.h

SOURCES += \
        ../../src/image/jpeg/jaricom.c \
        ../../src/image/jpeg/jcapimin.c \
        ../../src/image/jpeg/jcapistd.c \
        ../../src/image/jpeg/jcarith.c \
        ../../src/image/jpeg/jccoefct.c \
        ../../src/image/jpeg/jccolor.c \
        ../../src/image/jpeg/jcdctmgr.c \
        ../../src/image/jpeg/jchuff.c \
        ../../src/image/jpeg/jcinit.c \
        ../../src/image/jpeg/jcmainct.c \
        ../../src/image/jpeg/jcmarker.c \
        ../../src/image/jpeg/jcmaster.c \
        ../../src/image/jpeg/jcomapi.c \
        ../../src/image/jpeg/jcparam.c \
        ../../src/image/jpeg/jcprepct.c \
        ../../src/image/jpeg/jcsample.c \
        ../../src/image/jpeg/jctrans.c \
        ../../src/image/jpeg/jdapimin.c \
        ../../src/image/jpeg/jdapistd.c \
        ../../src/image/jpeg/jdarith.c \
        ../../src/image/jpeg/jdatadst.c \
        ../../src/image/jpeg/jdatasrc.c \
        ../../src/image/jpeg/jdcoefct.c \
        ../../src/image/jpeg/jdcolor.c \
        ../../src/image/jpeg/jddctmgr.c \
        ../../src/image/jpeg/jdhuff.c \
        ../../src/image/jpeg/jdinput.c \
        ../../src/image/jpeg/jdmainct.c \
        ../../src/image/jpeg/jdmarker.c \
        ../../src/image/jpeg/jdmaster.c \
        ../../src/image/jpeg/jdmerge.c \
        ../../src/image/jpeg/jdpostct.c \
        ../../src/image/jpeg/jdsample.c \
        ../../src/image/jpeg/jdtrans.c \
        ../../src/image/jpeg/jerror.c \
        ../../src/image/jpeg/jfdctflt.c \
        ../../src/image/jpeg/jfdctfst.c \
        ../../src/image/jpeg/jfdctint.c \
        ../../src/image/jpeg/jidctflt.c \
        ../../src/image/jpeg/jidctfst.c \
        ../../src/image/jpeg/jidctint.c \
        ../../src/image/jpeg/jmemmgr.c \
        ../../src/image/jpeg/jmemnobs.c \
        ../../src/image/jpeg/jquant1.c \
        ../../src/image/jpeg/jquant2.c \
        ../../src/image/jpeg/jutils.c \
        ../../src/image/jpeg/transupp.c

SOURCES += \
        ../../src/image/libpng/png.c \
        ../../src/image/libpng/pngerror.c \
        ../../src/image/libpng/pngget.c \
        ../../src/image/libpng/pngmem.c \
        ../../src/image/libpng/pngpread.c \
        ../../src/image/libpng/pngread.c \
        ../../src/image/libpng/pngrio.c \
        ../../src/image/libpng/pngrtran.c \
        ../../src/image/libpng/pngrutil.c \
        ../../src/image/libpng/pngset.c \
        ../../src/image/libpng/pngtrans.c \
        ../../src/image/libpng/pngwio.c \
        ../../src/image/libpng/pngwrite.c \
        ../../src/image/libpng/pngwtran.c \
        ../../src/image/libpng/pngwutil.c

SOURCES += \
        ../../src/zlib/adler32.c \
        ../../src/zlib/crc32.c \
        ../../src/zlib/deflate.c \
        ../../src/zlib/inffast.c \
        ../../src/zlib/inflate.c \
        ../../src/zlib/inftrees.c \
        ../../src/zlib/trees.c \
        ../../src/zlib/zutil.c

linux* {
#winlib
    SOURCES+=../../src/winlib/winlib_x11.cpp
#vfs
    SOURCES+=../../src/vfs/vfs_posix.cpp
    HEADERS+=../../src/vfs/vfs_posix.h
# XF86VIDMODE
    DEFINES+=HAVE_XF86VMODE
}

macx {
#winlib
    OBJECTIVE_SOURCES+=../../src/winlib/winlib_cocoa.mm
#vfs
    OBJECTIVE_SOURCES+=../../src/vfs/vfs_cocoa.mm
    HEADERS+=../../src/vfs/vfs_cocoa.h
}

OTHER_FILES += \
    ../../src/render/opengl/dynamic/dynamic_gl_h.inc \
    ../../src/render/opengl/dynamic/dynamic_gl_cpp.inc
