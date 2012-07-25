#!/bin/sh

if [ "x$ANDROID_NDK_ROOT" == "x" ]; then
	echo "ANDROID_NDK_ROOT empty"
	exit 1
fi

if [ ! -d "$ANDROID_NDK_ROOT" ]; then
	echo "ANDROID_NDK_ROOT not a folder"
	exit 1
fi

if [ "x$ANDROID_SDK_ROOT" == "x" ]; then
	echo "ANDROID_SDK_ROOT empty"
	exit 1
fi

if [ ! -d "$ANDROID_SDK_ROOT" ]; then
	echo "ANDROID_SDK_ROOT not a folder"
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

mkdir -p $GHL_ROOT/examples/android/assets
cp -r $GHL_ROOT/examples/data $GHL_ROOT/examples/android/assets

export NDK_PROJECT_PATH="$GHL_ROOT/examples/android"
#export NDK_MODULE_PATH="$GHL_ROOT/projects/android"

$NDK_BUILD NDK_DEBUG=1 V=1 NDK_DEBUG_IMPORTS=1 NDK_TRACE=1 NDK_LOG=1 || exit 1

$ANDROID_SDK_ROOT/tools/android update project --name GHL-example --path . --target android-10

ant debug
