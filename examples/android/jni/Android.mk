LOCAL_PATH := $(call my-dir)
GHL_ROOT := ../../..

### ghl section ##################
include $(CLEAR_VARS)
LOCAL_MODULE := GHL
ifeq ($(NDK_DEBUG),1)
	LOCAL_SRC_FILES := $(GHL_ROOT)/lib/libGHL-android_d.a
else
	LOCAL_SRC_FILES := $(GHL_ROOT)/lib/libGHL-android.a
endif
LOCAL_EXPORT_C_INCLUDES:= $(LOCAL_PATH)/$(GHL_ROOT)/include
include $(PREBUILT_STATIC_LIBRARY)
###################################

include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
	../../common/application_base.cpp \
	../../basic/ghl_basic.cpp
	
LOCAL_STATIC_LIBRARIES := GHL
LOCAL_MODULE    := GHL-sample
LOCAL_LDFLAGS:= -llog -lGLESv1_CM -lEGL -landroid

include $(BUILD_SHARED_LIBRARY)

