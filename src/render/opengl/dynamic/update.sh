#!/bin/bash

function download()
{
	URL=$1
	FILE=$2
	curl $URL > $FILE || return 1
	#mkdir -p $3
	#cp $FILE $3/$4
	#cp $3/$4 $FILE
	return 0
}

GL_GL_H_URL="http://cygwin.com/cgi-bin/cvsweb.cgi/src/winsup/w32api/include/GL/Attic/gl.h?rev=1.4&content-type=text/plain&cvsroot=src"
GL_GLEXT_H_URL="http://www.opengl.org/registry/api/glext.h"
GLES_GL_H_URL="http://www.khronos.org/registry/gles/api/1.1/gl.h"
GLES_GLEXT_H_URL="http://www.khronos.org/registry/gles/api/1.1/glext.h"
GLES2_GL_H_URL="http://www.khronos.org/registry/gles/api/2.0/gl2.h"
GLES2_GLEXT_H_URL="http://www.khronos.org/registry/gles/api/2.0/gl2ext.h"

download $GL_GL_H_URL "gl.h" "GL" "gl.h"
download $GL_GLEXT_H_URL "glext.h" "GL" "glext.h"

perl parse.pl inc > dynamic_gl_inc.h 
#perl parse.pl cpp > dynamic_gl_inc.cpp

rm -f gl.h
rm -f glext.h

download $GLES_GL_H_URL "gl.h" "GLES" "gl.h"
download $GLES_GLEXT_H_URL "glext.h" "GLES" "glext.h"

perl parse.pl inc > dynamic_gles_inc.h
#perl parse.pl cpp > dynamic_gles_inc.cpp

rm -f gl.h
rm -f glext.h

download $GLES2_GL_H_URL "gl.h" "GLES2" "gl2.h"
download $GLES2_GLEXT_H_URL "glext.h" "GLES2" "gl2ext.h"

perl parse.pl inc > dynamic_gles2_inc.h
#perl parse.pl cpp > dynamic_gles2_inc.cpp

rm -f gl.h
rm -f glext.h