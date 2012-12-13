MKDIR=mkdir -p
RM=rm -rf

GHLROOT=../..
GHLSRC=$(GHLROOT)/examples

BUILD=build
LIBDIR=$(GHLROOT)/lib


GHL_LIB=$(LIBDIR)/libGHL-flash$(POSTFIX).a
LINK_FLAGS= $(OPT_FLAGS) -lAS3++ -lFlash++ -emit-swf -swf-version=17 -flto-api=exports.txt -swf-size=800x600

INCLUDES=-I$(GHLROOT)/include

BASE_CFLAGS:=-Werror -Wno-write-strings -Wno-trigraphs

CPP_FLAGS= $(INCLUDES) $(DEFINES)

CC=$(FLASCC)/usr/bin/gcc
CXX=$(FLASCC)/usr/bin/g++
AR=$(FLASCC)/usr/bin/ar rcu
GENFS=$(FLASCC)/usr/bin/genfs --type=embed 

CXX_FLAGS=$(BASE_CFLAGS) $(OPT_FLAGS)

AS3COMPILER:=asc2.jar

AS3COMPILERARGS=java $(JVMARGS) -jar $(FLASCC)/usr/lib/$(AS3COMPILER) -merge -md 

DIRS=$(BUILD)

# common
COMMON_SOURCES=application_base.cpp

COMMON_OBJECTS= $(patsubst %.cpp,$(BUILD)/common/%.o,$(COMMON_SOURCES))
DIRS+=$(BUILD)/common

BASIC=$(BUILD)/basic.swf
BASIC_SOURCES=ghl_basic.cpp
BASIC_OBJECTS= $(patsubst %.cpp,$(BUILD)/basic/%.o,$(BASIC_SOURCES))
DIRS+=$(BUILD)/basic

ARTEFACTS=$(BASIC)

all: check 
	make build_all OPT_FLAGS=-O4
debug: check
	make build_all OPT_FLAGS="-g -O0" DEFINES=-DGHL_DEBUG POSTFIX=_d

build_all: $(DIRS) $(BUILD)/Console.abc  $(ARTEFACTS) Makefile

$(BUILD):
	$(MKDIR) $@

$(BUILD)/common:
	$(MKDIR) $@

$(BUILD)/basic:
	$(MKDIR) $@

$(BUILD)/data.abc: $(BUILD)
	
	$(RM) $(BUILD)/data*

	$(GENFS) ../data $(BUILD)/data

	$(AS3COMPILERARGS)	-import $(FLASCC)/usr/lib/builtin.abc \
			-import $(FLASCC)/usr/lib/playerglobal.abc \
			-import $(FLASCC)/usr/lib/BinaryData.abc \
			-import $(FLASCC)/usr/lib/ISpecialFile.abc \
			-import $(FLASCC)/usr/lib/IBackingStore.abc \
			-import $(FLASCC)/usr/lib/IVFS.abc \
			-import $(FLASCC)/usr/lib/InMemoryBackingStore.abc \
			-import $(FLASCC)/usr/lib/PlayerKernel.abc \
			 $(FLASCC)/usr/share/LSOBackingStore.as \
			 $(BUILD)/data*.as -outdir $(BUILD) -out data


$(BUILD)/Console.abc: $(BUILD)/data.abc
	$(AS3COMPILERARGS)	-import $(FLASCC)/usr/lib/builtin.abc \
				-import $(FLASCC)/usr/lib/playerglobal.abc \
				-import $(FLASCC)/usr/lib/BinaryData.abc \
				-import $(FLASCC)/usr/lib/ISpecialFile.abc \
				-import $(FLASCC)/usr/lib/IBackingStore.abc \
				-import $(FLASCC)/usr/lib/IVFS.abc \
				-import $(FLASCC)/usr/lib/InMemoryBackingStore.abc \
				-import $(FLASCC)/usr/lib/PlayerKernel.abc \
				-import $(BUILD)/data.abc \
				$(GHLROOT)/src/flash/Console$(POSTFIX).as -outdir $(BUILD) -out Console

$(BASIC) : $(COMMON_OBJECTS) $(BASIC_OBJECTS) $(GHL_LIB) 
	$(CXX)  $^  $(LINK_FLAGS) $(BUILD)/data.abc $(FLASCC)/usr/lib/AlcVFSZip.abc -symbol-abc=$(BUILD)/Console.abc -o $@ 

$(BUILD)/%.o : $(GHLSRC)/%.cpp Makefile
	$(CXX) $(CPP_FLAGS) $(CXX_FLAGS) -c -o $@ $< 

check:
	@if [ -d $(FLASCC)/usr/bin ] ; then true ; \
	else echo "Couldn't locate FLASCC sdk directory, please invoke make with \"make FLASCC=/path/to/FLASCC/sdk ...\"" ; exit 1 ; \
	fi



clean:
	$(RM) $(BUILD)
