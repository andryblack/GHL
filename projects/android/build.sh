#!/bin/sh

if [ "x$ANDROID_NDK_ROOT" == "x" ]; then
	echo "ANDROID_NDK_ROOT empty"
	exit 1
fi

if [ ! -d "$ANDROID_NDK_ROOT" ]; then
	echo "ANDROID_NDK_ROOT not a folder"
	exit 1
fi

#todo detect
PLATFORM="osx"
NDK_BUILD=$ANDROID_NDK_ROOT
if [ "$PLATFORM" == "win" ]; then
	echo "unsupported platform $PLATFORM"
	exit 1
	NDK_BUILD="$NDK_BUILD/ndk-build.cmd"
else
	NDK_BUILD="$NDK_BUILD/ndk-build"
fi

if [ ! -e "$NDK_BUILD" ]; then
	echo "$NDK_BUILD not a file"
	exit 1
fi

GHL_ROOT="$(git rev-parse --show-toplevel)"
export NDK_PROJECT_PATH="$GHL_ROOT/projects/android"
$NDK_BUILD V=1 NDK_DEBUG_IMPORTS=1 NDK_TRACE=1 NDK_LOG=1 || exit 1
mv obj/local/armeabi/libGHL.a "$GHL_ROOT/lib/libGHL-android.a"
$NDK_BUILD NDK_DEBUG=1 V=1 || exit 1
mv obj/local/armeabi/libGHL.a "$GHL_ROOT/lib/libGHL-android_d.a"


