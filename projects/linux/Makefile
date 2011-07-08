
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

VFS_SOURCES=ghl_vfs_factory.cpp\
    memory_stream.cpp\
    vfs_posix.cpp

VFS_OBJECTS= $(patsubst %.cpp,$(BUILD)/vfs/%.o,$(VFS_SOURCES))
DIRS+=$(BUILD)/vfs

RENDER_SOURCES=lucida_console_regular_8.cpp\
    render_impl.cpp\
    opengl/render_opengl.cpp\
    opengl/texture_opengl.cpp\
    opengl/rendertarget_opengl.cpp\
    opengl/shader_glsl.cpp\
    opengl/dynamic/dynamic_gl.cpp

RENDER_OBJECTS=$(patsubst %.cpp,$(BUILD)/render/%.o,$(RENDER_SOURCES))
DIRS+=$(BUILD)/render/opengl/dynamic 

OBJECTS=$(VFS_OBJECTS) $(RENDER_OBJECTS)

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

$(BUILD)/%.o : $(GHLSRC)/%.cpp
	$(CXX) -c -o $@ $< $(CPP_FLAGS) $(CXX_FLAGS)


clean:
	$(RM) $(OBJECTS) $(ARTEFACTS)