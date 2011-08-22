TARGET=GHL
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


#common VFS
SOURCES+=\
    ../../src/vfs/memory_stream.cpp \
    ../../src/vfs/ghl_vfs_factory.cpp

HEADERS+=../../src/vfs/memory_stream.h

#common image
SOURCES+=../../src/image/tga_image_decoder.cpp  \
        ../../src/image/image_impl.cpp \
        ../../src/image/image_decoders.cpp
HEADERS+=../../src/image/tga_image_decoder.h \
    ../../src/image/image_impl.h \
    ../../src/image/image_file_decoder.h \
    ../../src/image/image_decoders.h \
    ../../src/image/image_config.h

#common render
SOURCES+=../../src/render/render_impl.cpp \
    ../../src/render/lucida_console_regular_8.cpp
HEADERS+=../../src/render/rendertarget_impl.h \
    ../../src/render/render_impl.h \
    ../../src/render/lucida_console_regular_8.h

#opengl render
SOURCES+=\
    ../../src/render/opengl/texture_opengl.cpp \
    ../../src/render/opengl/shader_glsl.cpp \
    ../../src/render/opengl/rendertarget_opengl.cpp \
    ../../src/render/opengl/render_opengl.cpp \
    ../../src/render/opengl/dynamic/dynamic_gl.cpp
HEADERS+=\
    ../../src/render/opengl/texture_opengl.h \
    ../../src/render/opengl/shader_glsl.h \
    ../../src/render/opengl/rendertarget_opengl.h \
    ../../src/render/opengl/render_opengl.h \
    ../../src/render/opengl/refcount_opengl.h \
    ../../src/render/opengl/ghl_opengl.h \
    ../../src/render/opengl/dynamic/dynamic_gl.h \
    ../../src/render/opengl/dynamic/dynamic_gl_subset.h

linux* {
#winlib
    SOURCES+=../../src/winlib/winlib_x11.cpp
#vfs
    SOURCES+=../../src/vfs/vfs_posix.cpp
    HEADERS+=../../src/vfs/vfs_posix.h
# XF86VIDMODE
    DEFINES+=HAVE_XF86VMODE

}

OTHER_FILES += \
    ../../src/render/opengl/dynamic/dynamic_gl_h.inc \
    ../../src/render/opengl/dynamic/dynamic_gl_cpp.inc
