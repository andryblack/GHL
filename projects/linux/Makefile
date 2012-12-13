
MKDIR=mkdir -p
RM=rm -f
AR=ar rcu

GHLROOT=../..
GHLSRC=$(GHLROOT)/src

BUILD=build
LIBDIR=$(GHLROOT)/lib

STATICLIB=$(LIBDIR)/libGHL.a


INCLUDES=-I$(GHLROOT)/include


CPP_FLAGS=$(INCLUDES)

# VFS
VFS_SOURCES=ghl_vfs_factory.cpp\
    memory_stream.cpp\
    vfs_posix.cpp

VFS_OBJECTS= $(patsubst %.cpp,$(BUILD)/vfs/%.o,$(VFS_SOURCES))
DIRS+=$(BUILD)/vfs

# Render
RENDER_SOURCES=lucida_console_regular_8.cpp\
    render_impl.cpp\
    opengl/render_opengl.cpp\
    opengl/texture_opengl.cpp\
    opengl/rendertarget_opengl.cpp\
    opengl/shader_glsl.cpp\
    opengl/dynamic/dynamic_gl.cpp
    
RENDER_OBJECTS=$(patsubst %.cpp,$(BUILD)/render/%.o,$(RENDER_SOURCES))
DIRS+=$(BUILD)/render/opengl/dynamic 

# Image
IMAGE_SOURCES=tga_image_decoder.cpp \
    image_decoders.cpp \
    image_impl.cpp
    
IMAGE_OBJECTS=$(parsubst %.cpp,$(BUILD)/image/%.o,$(IMAGE_SOURCES))
DIRS+=$(BUILD)/image    

# WinLib
WINLIB_SOURCES=winlib_x11.cpp

WINLIB_OBJECTS=$(patsubst %.cpp,$(BUILD)/winlib/%.o,$(WINLIB_SOURCES))
DIRS+=$(BUILD)/winlib

OBJECTS=$(VFS_OBJECTS) $(RENDER_OBJECTS) $(IMAGE_OBJECTS) $(WINLIB_OBJECTS)

WINLIB_CPP_FLAGS+=-DHAVE_XF86VMODE

ARTEFACTS=$(STATICLIB)
DIRS+=$(LIBDIR)


all: $(DIRS) $(ARTEFACTS) Makefile


$(STATICLIB) : $(OBJECTS)
	$(AR) $@ $^

$(LIBDIR):
	$(MKDIR) $@

$(BUILD)/vfs:
	$(MKDIR) $@

$(BUILD)/render/opengl/dynamic:
	$(MKDIR) $@

$(BUILD)/image:
	$(MKDIR) $@

$(BUILD)/winlib:
	$(MKDIR) $@

$(BUILD)/%.o : $(GHLSRC)/%.cpp
	$(CXX) -c -o $@ $< $(CPP_FLAGS) $(CXX_FLAGS)

$(BUILD)/winlib/%.o : $(GHLSRC)/winlib/%.cpp
	$(CXX) -c -o $@ $< $(CPP_FLAGS) $(CXX_FLAGS) $(WINLIB_CPP_FLAGS) $(WINLIB_CXX_FLAGS)

clean:
	$(RM) $(OBJECTS) $(ARTEFACTS)


