#! /bin/bash

cd `dirname $0`


xcodebuild -project GHL.xcodeproj -sdk iphoneos -configuration Release -target GHL && \
xcodebuild -project GHL.xcodeproj -sdk iphoneos -configuration Debug -target GHL && \
xcodebuild -project GHL.xcodeproj -sdk iphonesimulator -configuration Release -target GHL && \
xcodebuild -project GHL.xcodeproj -sdk iphonesimulator -configuration Debug -target GHL

lipo ../../lib/libGHL-Debug-iphoneos.a ../../lib/libGHL-Debug-iphonesimulator.a -create -output ../../lib/libGHL_d.a 
lipo ../../lib/libGHL-Release-iphoneos.a ../../lib/libGHL-Release-iphonesimulator.a -create -output ../../lib/libGHL.a 
rm -f ../../lib/libGHL-*
