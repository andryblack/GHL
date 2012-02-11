#! /bin/bash

cd `dirname $0`


xcodebuild -project GHL.xcodeproj -configuration Release -target GHL && \
xcodebuild -project GHL.xcodeproj -configuration Debug -target GHL 
