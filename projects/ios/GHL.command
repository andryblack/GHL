#! /bin/bash

cd `dirname $0`


xcodebuild -project GHL.xcodeproj -sdk iphoneos4.3 -configuration Release -target GHL && \
xcodebuild -project GHL.xcodeproj -sdk iphoneos4.3 -configuration Debug -target GHL && \
xcodebuild -project GHL.xcodeproj -sdk iphonesimulator4.3 -configuration Release -target GHL && \ 
xcodebuild -project GHL.xcodeproj -sdk iphonesimulator4.3 -configuration Debug -target GHL 
