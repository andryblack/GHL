
MKDIR=mkdir -p
RM=rm -f
AR=emar rcu

CC=emcc
CXX=em++

GHLROOT=../..
GHLSRC=$(GHLROOT)/src

BUILD=build
LIBDIR=$(GHLROOT)/lib

STATICLIB=$(LIBDIR)/libGHL-emscripten.a


INCLUDES=-I$(GHLROOT)/include


CPP_FLAGS=$(INCLUDES) -O2 -DGHL_NO_SOUND -DGHL_NO_ES1 -DGHL_DEBUG 

COMMON_SOURCES=ghl_data_impl.cpp\
	ghl_log_impl.cpp
COMMON_OBJECTS=$(patsubst %.cpp,$(BUILD)/%.o,$(COMMON_SOURCES))
# VFS
VFS_SOURCES=ghl_vfs_factory.cpp\
    memory_stream.cpp\
    vfs_posix.cpp \
    posix_stream.cpp \
    vfs_emscripten.cpp 

VFS_OBJECTS= $(patsubst %.cpp,$(BUILD)/vfs/%.o,$(VFS_SOURCES))
DIRS+=$(BUILD)/vfs

# Render
RENDER_SOURCES=lucida_console_regular_8.cpp\
    render_impl.cpp\
    buffer_impl.cpp\
    rendertarget_impl.cpp\
    shader_impl.cpp\
    texture_impl.cpp\
    opengl/texture_opengl.cpp\
    opengl/rendertarget_opengl.cpp\
    opengl/buffers_opengl.cpp\
    opengl/gles2_api.cpp\
    opengl/glsl_generator.cpp\
    opengl/render_opengl_base.cpp\
    opengl/render_opengles.cpp\
    opengl/shader_glsl.cpp\
    pfpl/pfpl_cache.cpp\
    pfpl/pfpl_render.cpp\
    pfpl/pfpl_state.cpp
    
DIRS+=$(BUILD)/render/opengl
DIRS+=$(BUILD)/render/pfpl


RENDER_OBJECTS=$(patsubst %.cpp,$(BUILD)/render/%.o,$(RENDER_SOURCES))

# Image
IMAGE_SOURCES=tga_image_decoder.cpp \
    image_decoders.cpp \
    image_impl.cpp \
    png_image_decoder.cpp\
    jpeg_image_decoder.cpp
    
IMAGE_OBJECTS=$(patsubst %.cpp,$(BUILD)/image/%.o,$(IMAGE_SOURCES))
DIRS+=$(BUILD)/image    

# WinLib
WINLIB_SOURCES=winlib_sdl.cpp

WINLIB_OBJECTS=$(patsubst %.cpp,$(BUILD)/winlib/%.o,$(WINLIB_SOURCES))
DIRS+=$(BUILD)/winlib

# sound
SOUND_SOURCES=sound_decoders.cpp \
	wav_decoder.cpp
SOUND_OBJECTS=$(patsubst %.cpp,$(BUILD)/sound/%.o,$(SOUND_SOURCES))
DIRS+=$(BUILD)/sound




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


COBJECTS=$(patsubst src/zlib/%.c,$(BUILD)/zlib/%.c.o,$(ZLIB_SRC))\
	$(patsubst src/image/libpng/%.c,$(BUILD)/image/libpng/%.c.o,$(PNG_SRC))\
	$(patsubst src/image/jpeg/%.c,$(BUILD)/image/jpeg/%.c.o,$(JPEG_SRC))

DIRS+=$(BUILD)/zlib
DIRS+=$(BUILD)/image/libpng
DIRS+=$(BUILD)/image/jpeg

OBJECTS=$(VFS_OBJECTS) $(RENDER_OBJECTS) $(IMAGE_OBJECTS) $(WINLIB_OBJECTS) $(COMMON_OBJECTS) $(SOUND_OBJECTS) $(COBJECTS)




ARTEFACTS=$(STATICLIB)
DIRS+=$(LIBDIR)


all: $(DIRS) $(ARTEFACTS) Makefile


$(STATICLIB) : $(OBJECTS)
	$(AR) $@ $^

$(LIBDIR):
	$(MKDIR) $@

$(BUILD)/vfs:
	$(MKDIR) $@

$(BUILD)/render/opengl:
	$(MKDIR) $@

$(BUILD)/render/pfpl:
	$(MKDIR) $@

$(BUILD)/image:
	$(MKDIR) $@

$(BUILD)/image/libpng:
	$(MKDIR) $@

$(BUILD)/image/jpeg:
	$(MKDIR) $@

$(BUILD)/zlib:
	$(MKDIR) $@

$(BUILD)/winlib:
	$(MKDIR) $@

$(BUILD)/sound:
	$(MKDIR) $@

$(BUILD)/%.o : $(GHLSRC)/%.cpp
	$(CXX) -c -o $@ $< $(CPP_FLAGS) $(CXX_FLAGS)

$(BUILD)/winlib/%.o : $(GHLSRC)/winlib/%.cpp
	$(CXX) -c -o $@ $< $(CPP_FLAGS) $(CXX_FLAGS) $(WINLIB_CPP_FLAGS) $(WINLIB_CXX_FLAGS)

$(BUILD)/%.c.o : $(GHLSRC)/%.c Makefile
	$(CC) $(CPP_FLAGS) $(C_FLAGS) -c -o $@ $< 

clean:
	$(RM) $(OBJECTS) $(ARTEFACTS)


