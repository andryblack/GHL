MKDIR=mkdir -p
RM=rm -rf

GHLROOT=../..
GHLSRC=$(GHLROOT)/examples

BUILD=build
LIBDIR=$(GHLROOT)/lib


GHL_LIB=$(LIBDIR)/libGHL-emscripten$(POSTFIX).a
LINK_FLAGS= $(OPT_FLAGS) -s USE_SDL=2 -s FULL_ES2=1 

INCLUDES=-I$(GHLROOT)/include

BASE_CFLAGS:=-Werror -Wno-write-strings -Wno-trigraphs

CPP_FLAGS= $(INCLUDES) $(DEFINES) -s FULL_ES2=1

CC=emcc
CXX=em++
AR=ar rcu

C_FLAGS=$(BASE_CFLAGS) $(OPT_FLAGS)
CXX_FLAGS=$(BASE_CFLAGS) $(OPT_FLAGS)

DIRS=$(BUILD)

# common
COMMON_SOURCES=application_base.cpp

COMMON_OBJECTS= $(patsubst %.cpp,$(BUILD)/common/%.o,$(COMMON_SOURCES))
DIRS+=$(BUILD)/common

BASIC=$(BUILD)/basic.html
BASIC_SOURCES=ghl_basic.cpp
BASIC_OBJECTS= $(patsubst %.cpp,$(BUILD)/basic/%.o,$(BASIC_SOURCES))
DIRS+=$(BUILD)/basic

RT=$(BUILD)/rt.html
RT_SOURCES=ghl_rt.cpp
RT_OBJECTS= $(patsubst %.cpp,$(BUILD)/rt/%.o,$(RT_SOURCES))
DIRS+=$(BUILD)/rt

ARTEFACTS=$(BASIC) $(RT)

all:  
	make build_all OPT_FLAGS=-O2 
debug: 
	make build_all OPT_FLAGS="-g -O0" DEFINES=-DGHL_DEBUG POSTFIX=_d

build_all: $(DIRS) art $(ARTEFACTS) Makefile

art:
	cp -rf ../data $(BUILD)/
$(BUILD):
	$(MKDIR) $@

$(BUILD)/common:
	$(MKDIR) $@

$(BUILD)/basic:
	$(MKDIR) $@

$(BUILD)/rt:
	$(MKDIR) $@


$(BASIC) : $(COMMON_OBJECTS) $(BASIC_OBJECTS) $(GHL_LIB) 
	$(CXX)  $^  $(LINK_FLAGS)  -o $@ --embed-file $(BUILD)/data@data

$(RT) : $(COMMON_OBJECTS) $(RT_OBJECTS) $(GHL_LIB) 
	$(CXX)  $^  $(LINK_FLAGS)  -o $@ --embed-file $(BUILD)/data@data

$(BUILD)/%.o : $(GHLSRC)/%.cpp Makefile
	$(CXX) $(CPP_FLAGS) $(CXX_FLAGS) -c -o $@ $< 



clean:
	$(RM) $(BUILD)
