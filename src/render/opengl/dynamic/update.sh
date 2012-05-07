#!/bin/bash

function download()
{
	URL=$1
	FILE=$2
	curl $URL > $FILE || return 1
	return 0
}

GL_GL_H_URL="http://cygwin.com/cgi-bin/cvsweb.cgi/~checkout~/src/winsup/w32api/include/GL/gl.h?rev=1.4&content-type=text/plain&cvsroot=src"
GL_GLEXT_H_URL="http://www.opengl.org/registry/api/glext.h"
GLES_GL_H_URL="http://www.khronos.org/registry/gles/api/1.1/gl.h"
GLES_GLEXT_H_URL="http://www.khronos.org/registry/gles/api/1.1/glext.h"

download $GL_GL_H_URL "gl.h"
download $GL_GLEXT_H_URL "glext.h"

perl parse.pl h > dynamic_gl_h.inc
perl parse.pl cpp > dynamic_gl_cpp.inc

rm -f gl.h
rm -f glext.h

download $GLES_GL_H_URL "gl.h"
download $GLES_GLEXT_H_URL "glext.h"

perl parse.pl h > dynamic_gles_h.inc
perl parse.pl cpp > dynamic_gles_cpp.inc

rm -f gl.h
rm -f glext.h