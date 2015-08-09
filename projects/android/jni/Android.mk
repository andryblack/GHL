GHL_ROOT := $(call my-dir)/../../..


include $(CLEAR_VARS)

APP_STL  := gnustl_static

LOCAL_PATH := $(GHL_ROOT)

LOCAL_MODULE    := GHL

JPEG_SRC := \
	src/image/jpeg/jaricom.c \
	src/image/jpeg/jcapimin.c \
	src/image/jpeg/jcapistd.c \
	src/image/jpeg/jcarith.c \
	src/image/jpeg/jccoefct.c \
	src/image/jpeg/jccolor.c \
	src/image/jpeg/jcdctmgr.c \
	src/image/jpeg/jchuff.c \
	src/image/jpeg/jcinit.c \
	src/image/jpeg/jcmainct.c \
	src/image/jpeg/jcmarker.c \
	src/image/jpeg/jcmaster.c \
	src/image/jpeg/jcomapi.c \
	src/image/jpeg/jcparam.c \
	src/image/jpeg/jcprepct.c \
	src/image/jpeg/jcsample.c \
	src/image/jpeg/jctrans.c \
	src/image/jpeg/jdapimin.c \
	src/image/jpeg/jdapistd.c \
	src/image/jpeg/jdarith.c \
	src/image/jpeg/jdatadst.c \
	src/image/jpeg/jdatasrc.c \
	src/image/jpeg/jdcoefct.c \
	src/image/jpeg/jdcolor.c \
	src/image/jpeg/jddctmgr.c \
	src/image/jpeg/jdhuff.c \
	src/image/jpeg/jdinput.c \
	src/image/jpeg/jdmainct.c \
	src/image/jpeg/jdmarker.c \
	src/image/jpeg/jdmaster.c \
	src/image/jpeg/jdmerge.c \
	src/image/jpeg/jdpostct.c \
	src/image/jpeg/jdsample.c \
	src/image/jpeg/jdtrans.c \
	src/image/jpeg/jerror.c \
	src/image/jpeg/jfdctflt.c \
	src/image/jpeg/jfdctfst.c \
	src/image/jpeg/jfdctint.c \
	src/image/jpeg/jidctflt.c \
	src/image/jpeg/jidctfst.c \
	src/image/jpeg/jidctint.c \
	src/image/jpeg/jmemmgr.c \
	src/image/jpeg/jmemnobs.c \
	src/image/jpeg/jquant1.c \
	src/image/jpeg/jquant2.c \
	src/image/jpeg/jutils.c \
	src/image/jpeg/transupp.c 
	
PNG_SRC := \
	src/image/libpng/png.c \
	src/image/libpng/pngerror.c \
	src/image/libpng/pngget.c \
	src/image/libpng/pngmem.c \
	src/image/libpng/pngpread.c \
	src/image/libpng/pngread.c \
	src/image/libpng/pngrio.c \
	src/image/libpng/pngrtran.c \
	src/image/libpng/pngrutil.c \
	src/image/libpng/pngset.c \
	src/image/libpng/pngtrans.c \
	src/image/libpng/pngwio.c \
	src/image/libpng/pngwrite.c \
	src/image/libpng/pngwtran.c \
	src/image/libpng/pngwutil.c 

ZLIB_SRC := \
	src/zlib/adler32.c \
	src/zlib/crc32.c \
	src/zlib/deflate.c \
	src/zlib/inffast.c \
	src/zlib/inflate.c \
	src/zlib/inftrees.c \
	src/zlib/trees.c \
	src/zlib/zutil.c 

OGG_SRC := \
	src/sound/libogg/src/bitwise.c \
	src/sound/libogg/src/framing.c \


VORBIS_SRC := \
	src/sound/libvorbis/lib/bitrate.c \
	src/sound/libvorbis/lib/block.c \
	src/sound/libvorbis/lib/codebook.c \
	src/sound/libvorbis/lib/envelope.c \
	src/sound/libvorbis/lib/floor0.c \
	src/sound/libvorbis/lib/floor1.c \
	src/sound/libvorbis/lib/info.c \
	src/sound/libvorbis/lib/lookup.c \
	src/sound/libvorbis/lib/lpc.c \
	src/sound/libvorbis/lib/lsp.c \
	src/sound/libvorbis/lib/mapping0.c \
	src/sound/libvorbis/lib/mdct.c \
	src/sound/libvorbis/lib/psy.c \
	src/sound/libvorbis/lib/registry.c \
	src/sound/libvorbis/lib/res0.c \
	src/sound/libvorbis/lib/sharedbook.c \
	src/sound/libvorbis/lib/smallft.c \
	src/sound/libvorbis/lib/synthesis.c \
	src/sound/libvorbis/lib/vorbisfile.c \
	src/sound/libvorbis/lib/window.c \
	


LOCAL_SRC_FILES := \
	src/ghl_log_impl.cpp \
	src/ghl_data_impl.cpp \
	src/winlib/winlib_android.cpp \
	src/render/lucida_console_regular_8.cpp \
	src/render/render_impl.cpp \
	src/render/buffer_impl.cpp \
	src/render/rendertarget_impl.cpp \
	src/render/texture_impl.cpp \
	src/render/shader_impl.cpp \
	src/render/opengl/render_opengl_base.cpp \
	src/render/opengl/render_opengles.cpp \
	src/render/opengl/rendertarget_opengl.cpp \
	src/render/opengl/texture_opengl.cpp \
	src/render/opengl/buffers_opengl.cpp \
	src/render/opengl/shader_glsl.cpp \
	src/render/opengl/gles1_api.cpp \
	src/render/opengl/gles2_api.cpp \
	src/render/opengl/glsl_generator.cpp \
	src/render/pfpl/pfpl_cache.cpp \
	src/render/pfpl/pfpl_render.cpp \
	src/render/pfpl/pfpl_state.cpp \
	src/image/image_decoders.cpp \
	src/image/image_impl.cpp \
	src/image/jpeg_image_decoder.cpp \
	src/image/png_image_decoder.cpp \
	src/image/tga_image_decoder.cpp \
	src/vfs/ghl_vfs_factory.cpp \
	src/vfs/memory_stream.cpp \
	src/vfs/vfs_posix.cpp \
	src/vfs/vfs_android.cpp \
	src/sound/android/ghl_sound_android.cpp \
	src/sound/android/opensl_audio_channel.cpp \
	src/sound/android/opensl_audio_engine.cpp \
	src/sound/android/opensl_audio_stream.cpp \
	src/sound/sound_decoders.cpp \
	src/sound/wav_decoder.cpp \
	src/sound/vorbis_decoder.cpp \
	src/net/ghl_net_android.cpp \
	$(OGG_SRC) \
	$(VORBIS_SRC) \
	$(JPEG_SRC) \
	$(PNG_SRC) \
	$(ZLIB_SRC) \
	
	
ifeq ($(NDK_DEBUG),1)
	LOCAL_CFLAGS+=-DGHL_DEBUG
endif



LOCAL_C_INCLUDES := $(GHL_ROOT)/include 
LOCAL_LDLIBS := -llog -lGLESv1_CM -lGLESv2


include $(BUILD_STATIC_LIBRARY)
