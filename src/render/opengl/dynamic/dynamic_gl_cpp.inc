/*VERSION_1_1*/
#ifdef USE_DYNAMIC_GL_VERSION_1_1
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearIndex)(GLfloat c) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearColor)(GLclampf red , GLclampf green , GLclampf blue , GLclampf alpha) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Clear)(GLbitfield mask) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_IndexMask)(GLuint mask) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorMask)(GLboolean red , GLboolean green , GLboolean blue , GLboolean alpha) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_AlphaFunc)(GLenum func , GLclampf ref) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendFunc)(GLenum sfactor , GLenum dfactor) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_LogicOp)(GLenum opcode) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CullFace)(GLenum mode) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FrontFace)(GLenum mode) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PointSize)(GLfloat size) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_LineWidth)(GLfloat width) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_LineStipple)(GLint factor , GLushort pattern) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PolygonMode)(GLenum face , GLenum mode) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PolygonOffset)(GLfloat factor , GLfloat units) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PolygonStipple)(const GLubyte *mask) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPolygonStipple)(GLubyte *mask) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EdgeFlag)(GLboolean flag) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EdgeFlagv)(const GLboolean *flag) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Scissor)(GLint x , GLint y , GLsizei width , GLsizei height) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ClipPlane)(GLenum plane , const GLdouble *equation) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetClipPlane)(GLenum plane , GLdouble *equation) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawBuffer)(GLenum mode) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ReadBuffer)(GLenum mode) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Enable)(GLenum cap) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Disable)(GLenum cap) = 0; }
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsEnabled)(GLenum cap) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EnableClientState)(GLenum cap) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DisableClientState)(GLenum cap) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetBooleanv)(GLenum pname , GLboolean *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetDoublev)(GLenum pname , GLdouble *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFloatv)(GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetIntegerv)(GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PushAttrib)(GLbitfield mask) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PopAttrib)() = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PushClientAttrib)(GLbitfield mask) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PopClientAttrib)() = 0; }
extern "C" { GLint (DYNAMIC_GL_APIENTRYP DynamicGL_RenderMode)(GLenum mode) = 0; }
extern "C" { GLenum (DYNAMIC_GL_APIENTRYP DynamicGL_GetError)() = 0; }
extern "C" { GLubyte* (DYNAMIC_GL_APIENTRYP DynamicGL_GetString)(GLenum name) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Finish)() = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Flush)() = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Hint)(GLenum target , GLenum mode) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearDepth)(GLclampd depth) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DepthFunc)(GLenum func) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DepthMask)(GLboolean flag) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DepthRange)(GLclampd near_val , GLclampd far_val) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearAccum)(GLfloat red , GLfloat green , GLfloat blue , GLfloat alpha) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Accum)(GLenum op , GLfloat value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixMode)(GLenum mode) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Ortho)(GLdouble left , GLdouble right , GLdouble bottom , GLdouble top , GLdouble near_val , GLdouble far_val) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Frustum)(GLdouble left , GLdouble right , GLdouble bottom , GLdouble top , GLdouble near_val , GLdouble far_val) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Viewport)(GLint x , GLint y , GLsizei width , GLsizei height) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PushMatrix)() = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PopMatrix)() = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_LoadIdentity)() = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_LoadMatrixd)(const GLdouble *m) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_LoadMatrixf)(const GLfloat *m) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultMatrixd)(const GLdouble *m) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultMatrixf)(const GLfloat *m) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Rotated)(GLdouble angle , GLdouble x , GLdouble y , GLdouble z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Rotatef)(GLfloat angle , GLfloat x , GLfloat y , GLfloat z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Scaled)(GLdouble x , GLdouble y , GLdouble z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Scalef)(GLfloat x , GLfloat y , GLfloat z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Translated)(GLdouble x , GLdouble y , GLdouble z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Translatef)(GLfloat x , GLfloat y , GLfloat z) = 0; }
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsList)(GLuint list) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteLists)(GLuint list , GLsizei range) = 0; }
extern "C" { GLuint (DYNAMIC_GL_APIENTRYP DynamicGL_GenLists)(GLsizei range) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NewList)(GLuint list , GLenum mode) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EndList)() = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CallList)(GLuint list) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CallLists)(GLsizei n , GLenum type , const GLvoid *lists) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ListBase)(GLuint base) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Begin)(GLenum mode) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_End)() = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex2d)(GLdouble x , GLdouble y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex2f)(GLfloat x , GLfloat y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex2i)(GLint x , GLint y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex2s)(GLshort x , GLshort y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex3d)(GLdouble x , GLdouble y , GLdouble z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex3f)(GLfloat x , GLfloat y , GLfloat z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex3i)(GLint x , GLint y , GLint z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex3s)(GLshort x , GLshort y , GLshort z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex4d)(GLdouble x , GLdouble y , GLdouble z , GLdouble w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex4f)(GLfloat x , GLfloat y , GLfloat z , GLfloat w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex4i)(GLint x , GLint y , GLint z , GLint w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex4s)(GLshort x , GLshort y , GLshort z , GLshort w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex2dv)(const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex2fv)(const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex2iv)(const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex2sv)(const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex3dv)(const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex3fv)(const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex3iv)(const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex3sv)(const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex4dv)(const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex4fv)(const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex4iv)(const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex4sv)(const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Normal3b)(GLbyte nx , GLbyte ny , GLbyte nz) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Normal3d)(GLdouble nx , GLdouble ny , GLdouble nz) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Normal3f)(GLfloat nx , GLfloat ny , GLfloat nz) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Normal3i)(GLint nx , GLint ny , GLint nz) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Normal3s)(GLshort nx , GLshort ny , GLshort nz) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Normal3bv)(const GLbyte *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Normal3dv)(const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Normal3fv)(const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Normal3iv)(const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Normal3sv)(const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Indexd)(GLdouble c) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Indexf)(GLfloat c) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Indexi)(GLint c) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Indexs)(GLshort c) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Indexub)(GLubyte c) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Indexdv)(const GLdouble *c) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Indexfv)(const GLfloat *c) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Indexiv)(const GLint *c) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Indexsv)(const GLshort *c) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Indexubv)(const GLubyte *c) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3b)(GLbyte red , GLbyte green , GLbyte blue) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3d)(GLdouble red , GLdouble green , GLdouble blue) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3f)(GLfloat red , GLfloat green , GLfloat blue) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3i)(GLint red , GLint green , GLint blue) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3s)(GLshort red , GLshort green , GLshort blue) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3ub)(GLubyte red , GLubyte green , GLubyte blue) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3ui)(GLuint red , GLuint green , GLuint blue) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3us)(GLushort red , GLushort green , GLushort blue) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4b)(GLbyte red , GLbyte green , GLbyte blue , GLbyte alpha) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4d)(GLdouble red , GLdouble green , GLdouble blue , GLdouble alpha) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4f)(GLfloat red , GLfloat green , GLfloat blue , GLfloat alpha) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4i)(GLint red , GLint green , GLint blue , GLint alpha) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4s)(GLshort red , GLshort green , GLshort blue , GLshort alpha) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4ub)(GLubyte red , GLubyte green , GLubyte blue , GLubyte alpha) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4ui)(GLuint red , GLuint green , GLuint blue , GLuint alpha) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4us)(GLushort red , GLushort green , GLushort blue , GLushort alpha) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3bv)(const GLbyte *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3dv)(const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3fv)(const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3iv)(const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3sv)(const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3ubv)(const GLubyte *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3uiv)(const GLuint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3usv)(const GLushort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4bv)(const GLbyte *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4dv)(const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4fv)(const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4iv)(const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4sv)(const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4ubv)(const GLubyte *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4uiv)(const GLuint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4usv)(const GLushort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord1d)(GLdouble s) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord1f)(GLfloat s) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord1i)(GLint s) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord1s)(GLshort s) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2d)(GLdouble s , GLdouble t) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2f)(GLfloat s , GLfloat t) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2i)(GLint s , GLint t) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2s)(GLshort s , GLshort t) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord3d)(GLdouble s , GLdouble t , GLdouble r) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord3f)(GLfloat s , GLfloat t , GLfloat r) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord3i)(GLint s , GLint t , GLint r) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord3s)(GLshort s , GLshort t , GLshort r) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord4d)(GLdouble s , GLdouble t , GLdouble r , GLdouble q) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord4f)(GLfloat s , GLfloat t , GLfloat r , GLfloat q) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord4i)(GLint s , GLint t , GLint r , GLint q) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord4s)(GLshort s , GLshort t , GLshort r , GLshort q) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord1dv)(const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord1fv)(const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord1iv)(const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord1sv)(const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2dv)(const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2fv)(const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2iv)(const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2sv)(const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord3dv)(const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord3fv)(const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord3iv)(const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord3sv)(const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord4dv)(const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord4fv)(const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord4iv)(const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord4sv)(const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos2d)(GLdouble x , GLdouble y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos2f)(GLfloat x , GLfloat y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos2i)(GLint x , GLint y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos2s)(GLshort x , GLshort y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos3d)(GLdouble x , GLdouble y , GLdouble z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos3f)(GLfloat x , GLfloat y , GLfloat z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos3i)(GLint x , GLint y , GLint z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos3s)(GLshort x , GLshort y , GLshort z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos4d)(GLdouble x , GLdouble y , GLdouble z , GLdouble w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos4f)(GLfloat x , GLfloat y , GLfloat z , GLfloat w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos4i)(GLint x , GLint y , GLint z , GLint w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos4s)(GLshort x , GLshort y , GLshort z , GLshort w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos2dv)(const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos2fv)(const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos2iv)(const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos2sv)(const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos3dv)(const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos3fv)(const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos3iv)(const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos3sv)(const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos4dv)(const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos4fv)(const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos4iv)(const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos4sv)(const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Rectd)(GLdouble x1 , GLdouble y1 , GLdouble x2 , GLdouble y2) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Rectf)(GLfloat x1 , GLfloat y1 , GLfloat x2 , GLfloat y2) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Recti)(GLint x1 , GLint y1 , GLint x2 , GLint y2) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Rects)(GLshort x1 , GLshort y1 , GLshort x2 , GLshort y2) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Rectdv)(const GLdouble *v1 , const GLdouble *v2) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Rectfv)(const GLfloat *v1 , const GLfloat *v2) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Rectiv)(const GLint *v1 , const GLint *v2) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Rectsv)(const GLshort *v1 , const GLshort *v2) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ShadeModel)(GLenum mode) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Lightf)(GLenum light , GLenum pname , GLfloat param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Lighti)(GLenum light , GLenum pname , GLint param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Lightfv)(GLenum light , GLenum pname , const GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Lightiv)(GLenum light , GLenum pname , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetLightfv)(GLenum light , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetLightiv)(GLenum light , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_LightModelf)(GLenum pname , GLfloat param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_LightModeli)(GLenum pname , GLint param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_LightModelfv)(GLenum pname , const GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_LightModeliv)(GLenum pname , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Materialf)(GLenum face , GLenum pname , GLfloat param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Materiali)(GLenum face , GLenum pname , GLint param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Materialfv)(GLenum face , GLenum pname , const GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Materialiv)(GLenum face , GLenum pname , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMaterialfv)(GLenum face , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMaterialiv)(GLenum face , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorMaterial)(GLenum face , GLenum mode) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelZoom)(GLfloat xfactor , GLfloat yfactor) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelStoref)(GLenum pname , GLfloat param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelStorei)(GLenum pname , GLint param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelTransferf)(GLenum pname , GLfloat param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelTransferi)(GLenum pname , GLint param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelMapfv)(GLenum map , GLint mapsize , const GLfloat *values) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelMapuiv)(GLenum map , GLint mapsize , const GLuint *values) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelMapusv)(GLenum map , GLint mapsize , const GLushort *values) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPixelMapfv)(GLenum map , GLfloat *values) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPixelMapuiv)(GLenum map , GLuint *values) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPixelMapusv)(GLenum map , GLushort *values) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Bitmap)(GLsizei width , GLsizei height , GLfloat xorig , GLfloat yorig , GLfloat xmove , GLfloat ymove , const GLubyte *bitmap) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ReadPixels)(GLint x , GLint y , GLsizei width , GLsizei height , GLenum format , GLenum type , GLvoid *pixels) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawPixels)(GLsizei width , GLsizei height , GLenum format , GLenum type , const GLvoid *pixels) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyPixels)(GLint x , GLint y , GLsizei width , GLsizei height , GLenum type) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_StencilFunc)(GLenum func , GLint ref , GLuint mask) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_StencilMask)(GLuint mask) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_StencilOp)(GLenum fail , GLenum zfail , GLenum zpass) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearStencil)(GLint s) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexGend)(GLenum coord , GLenum pname , GLdouble param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexGenf)(GLenum coord , GLenum pname , GLfloat param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexGeni)(GLenum coord , GLenum pname , GLint param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexGendv)(GLenum coord , GLenum pname , const GLdouble *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexGenfv)(GLenum coord , GLenum pname , const GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexGeniv)(GLenum coord , GLenum pname , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexGendv)(GLenum coord , GLenum pname , GLdouble *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexGenfv)(GLenum coord , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexGeniv)(GLenum coord , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexEnvf)(GLenum target , GLenum pname , GLfloat param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexEnvi)(GLenum target , GLenum pname , GLint param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexEnvfv)(GLenum target , GLenum pname , const GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexEnviv)(GLenum target , GLenum pname , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexEnvfv)(GLenum target , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexEnviv)(GLenum target , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexParameterf)(GLenum target , GLenum pname , GLfloat param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexParameteri)(GLenum target , GLenum pname , GLint param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexParameterfv)(GLenum target , GLenum pname , const GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexParameteriv)(GLenum target , GLenum pname , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexParameterfv)(GLenum target , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexParameteriv)(GLenum target , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexLevelParameterfv)(GLenum target , GLint level , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexLevelParameteriv)(GLenum target , GLint level , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexImage1D)(GLenum target , GLint level , GLint internalFormat , GLsizei width , GLint border , GLenum format , GLenum type , const GLvoid *pixels) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexImage2D)(GLenum target , GLint level , GLint internalFormat , GLsizei width , GLsizei height , GLint border , GLenum format , GLenum type , const GLvoid *pixels) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexImage)(GLenum target , GLint level , GLenum format , GLenum type , GLvoid *pixels) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Map1d)(GLenum target , GLdouble u1 , GLdouble u2 , GLint stride , GLint order , const GLdouble *points) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Map1f)(GLenum target , GLfloat u1 , GLfloat u2 , GLint stride , GLint order , const GLfloat *points) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Map2d)(GLenum target , GLdouble u1 , GLdouble u2 , GLint ustride , GLint uorder , GLdouble v1 , GLdouble v2 , GLint vstride , GLint vorder , const GLdouble *points) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Map2f)(GLenum target , GLfloat u1 , GLfloat u2 , GLint ustride , GLint uorder , GLfloat v1 , GLfloat v2 , GLint vstride , GLint vorder , const GLfloat *points) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMapdv)(GLenum target , GLenum query , GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMapfv)(GLenum target , GLenum query , GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMapiv)(GLenum target , GLenum query , GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EvalCoord1d)(GLdouble u) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EvalCoord1f)(GLfloat u) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EvalCoord1dv)(const GLdouble *u) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EvalCoord1fv)(const GLfloat *u) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EvalCoord2d)(GLdouble u , GLdouble v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EvalCoord2f)(GLfloat u , GLfloat v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EvalCoord2dv)(const GLdouble *u) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EvalCoord2fv)(const GLfloat *u) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MapGrid1d)(GLint un , GLdouble u1 , GLdouble u2) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MapGrid1f)(GLint un , GLfloat u1 , GLfloat u2) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MapGrid2d)(GLint un , GLdouble u1 , GLdouble u2 , GLint vn , GLdouble v1 , GLdouble v2) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MapGrid2f)(GLint un , GLfloat u1 , GLfloat u2 , GLint vn , GLfloat v1 , GLfloat v2) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EvalPoint1)(GLint i) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EvalPoint2)(GLint i , GLint j) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EvalMesh1)(GLenum mode , GLint i1 , GLint i2) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EvalMesh2)(GLenum mode , GLint i1 , GLint i2 , GLint j1 , GLint j2) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Fogf)(GLenum pname , GLfloat param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Fogi)(GLenum pname , GLint param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Fogfv)(GLenum pname , const GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Fogiv)(GLenum pname , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FeedbackBuffer)(GLsizei size , GLenum type , GLfloat *buffer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PassThrough)(GLfloat token) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SelectBuffer)(GLsizei size , GLuint *buffer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_InitNames)() = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_LoadName)(GLuint name) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PushName)(GLuint name) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PopName)() = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GenTextures)(GLsizei n , GLuint *textures) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteTextures)(GLsizei n , const GLuint *textures) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BindTexture)(GLenum target , GLuint texture) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PrioritizeTextures)(GLsizei n , const GLuint *textures , const GLclampf *priorities) = 0; }
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_AreTexturesResident)(GLsizei n , const GLuint *textures , GLboolean *residences) = 0; }
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsTexture)(GLuint texture) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexSubImage1D)(GLenum target , GLint level , GLint xoffset , GLsizei width , GLenum format , GLenum type , const GLvoid *pixels) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexSubImage2D)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLsizei width , GLsizei height , GLenum format , GLenum type , const GLvoid *pixels) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyTexImage1D)(GLenum target , GLint level , GLenum internalformat , GLint x , GLint y , GLsizei width , GLint border) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyTexImage2D)(GLenum target , GLint level , GLenum internalformat , GLint x , GLint y , GLsizei width , GLsizei height , GLint border) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyTexSubImage1D)(GLenum target , GLint level , GLint xoffset , GLint x , GLint y , GLsizei width) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyTexSubImage2D)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint x , GLint y , GLsizei width , GLsizei height) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexPointer)(GLint size , GLenum type , GLsizei stride , const GLvoid *ptr) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NormalPointer)(GLenum type , GLsizei stride , const GLvoid *ptr) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorPointer)(GLint size , GLenum type , GLsizei stride , const GLvoid *ptr) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_IndexPointer)(GLenum type , GLsizei stride , const GLvoid *ptr) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoordPointer)(GLint size , GLenum type , GLsizei stride , const GLvoid *ptr) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EdgeFlagPointer)(GLsizei stride , const GLvoid *ptr) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPointerv)(GLenum pname , GLvoid *p1) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ArrayElement)(GLint i) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawArrays)(GLenum mode , GLint first , GLsizei count) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawElements)(GLenum mode , GLsizei count , GLenum type , const GLvoid *indices) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_InterleavedArrays)(GLenum format , GLsizei stride , const GLvoid *pointer) = 0; }
static bool DinamicGLFeature_VERSION_1_1_loaded = false; 
static void InitDinamicGLFeature_VERSION_1_1() {
		DynamicGL_ClearIndex = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat c)>("glClearIndex"); 
		DynamicGL_ClearColor = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLclampf red , GLclampf green , GLclampf blue , GLclampf alpha)>("glClearColor"); 
		DynamicGL_Clear = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLbitfield mask)>("glClear"); 
		DynamicGL_IndexMask = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint mask)>("glIndexMask"); 
		DynamicGL_ColorMask = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLboolean red , GLboolean green , GLboolean blue , GLboolean alpha)>("glColorMask"); 
		DynamicGL_AlphaFunc = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum func , GLclampf ref)>("glAlphaFunc"); 
		DynamicGL_BlendFunc = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum sfactor , GLenum dfactor)>("glBlendFunc"); 
		DynamicGL_LogicOp = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum opcode)>("glLogicOp"); 
		DynamicGL_CullFace = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode)>("glCullFace"); 
		DynamicGL_FrontFace = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode)>("glFrontFace"); 
		DynamicGL_PointSize = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat size)>("glPointSize"); 
		DynamicGL_LineWidth = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat width)>("glLineWidth"); 
		DynamicGL_LineStipple = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint factor , GLushort pattern)>("glLineStipple"); 
		DynamicGL_PolygonMode = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum face , GLenum mode)>("glPolygonMode"); 
		DynamicGL_PolygonOffset = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat factor , GLfloat units)>("glPolygonOffset"); 
		DynamicGL_PolygonStipple = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLubyte *mask)>("glPolygonStipple"); 
		DynamicGL_GetPolygonStipple = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLubyte *mask)>("glGetPolygonStipple"); 
		DynamicGL_EdgeFlag = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLboolean flag)>("glEdgeFlag"); 
		DynamicGL_EdgeFlagv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLboolean *flag)>("glEdgeFlagv"); 
		DynamicGL_Scissor = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint x , GLint y , GLsizei width , GLsizei height)>("glScissor"); 
		DynamicGL_ClipPlane = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum plane , const GLdouble *equation)>("glClipPlane"); 
		DynamicGL_GetClipPlane = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum plane , GLdouble *equation)>("glGetClipPlane"); 
		DynamicGL_DrawBuffer = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode)>("glDrawBuffer"); 
		DynamicGL_ReadBuffer = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode)>("glReadBuffer"); 
		DynamicGL_Enable = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum cap)>("glEnable"); 
		DynamicGL_Disable = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum cap)>("glDisable"); 
		DynamicGL_IsEnabled = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLenum cap)>("glIsEnabled"); 
		DynamicGL_EnableClientState = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum cap)>("glEnableClientState"); 
		DynamicGL_DisableClientState = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum cap)>("glDisableClientState"); 
		DynamicGL_GetBooleanv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLboolean *params)>("glGetBooleanv"); 
		DynamicGL_GetDoublev = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLdouble *params)>("glGetDoublev"); 
		DynamicGL_GetFloatv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLfloat *params)>("glGetFloatv"); 
		DynamicGL_GetIntegerv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLint *params)>("glGetIntegerv"); 
		DynamicGL_PushAttrib = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLbitfield mask)>("glPushAttrib"); 
		DynamicGL_PopAttrib = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glPopAttrib"); 
		DynamicGL_PushClientAttrib = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLbitfield mask)>("glPushClientAttrib"); 
		DynamicGL_PopClientAttrib = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glPopClientAttrib"); 
		DynamicGL_RenderMode = DynamicGL_LoadFunction<GLint (DYNAMIC_GL_APIENTRYP)(GLenum mode)>("glRenderMode"); 
		DynamicGL_GetError = DynamicGL_LoadFunction<GLenum (DYNAMIC_GL_APIENTRYP)()>("glGetError"); 
		DynamicGL_GetString = DynamicGL_LoadFunction<GLubyte* (DYNAMIC_GL_APIENTRYP)(GLenum name)>("glGetString"); 
		DynamicGL_Finish = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glFinish"); 
		DynamicGL_Flush = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glFlush"); 
		DynamicGL_Hint = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum mode)>("glHint"); 
		DynamicGL_ClearDepth = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLclampd depth)>("glClearDepth"); 
		DynamicGL_DepthFunc = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum func)>("glDepthFunc"); 
		DynamicGL_DepthMask = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLboolean flag)>("glDepthMask"); 
		DynamicGL_DepthRange = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLclampd near_val , GLclampd far_val)>("glDepthRange"); 
		DynamicGL_ClearAccum = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat red , GLfloat green , GLfloat blue , GLfloat alpha)>("glClearAccum"); 
		DynamicGL_Accum = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum op , GLfloat value)>("glAccum"); 
		DynamicGL_MatrixMode = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode)>("glMatrixMode"); 
		DynamicGL_Ortho = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble left , GLdouble right , GLdouble bottom , GLdouble top , GLdouble near_val , GLdouble far_val)>("glOrtho"); 
		DynamicGL_Frustum = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble left , GLdouble right , GLdouble bottom , GLdouble top , GLdouble near_val , GLdouble far_val)>("glFrustum"); 
		DynamicGL_Viewport = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint x , GLint y , GLsizei width , GLsizei height)>("glViewport"); 
		DynamicGL_PushMatrix = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glPushMatrix"); 
		DynamicGL_PopMatrix = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glPopMatrix"); 
		DynamicGL_LoadIdentity = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glLoadIdentity"); 
		DynamicGL_LoadMatrixd = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *m)>("glLoadMatrixd"); 
		DynamicGL_LoadMatrixf = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *m)>("glLoadMatrixf"); 
		DynamicGL_MultMatrixd = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *m)>("glMultMatrixd"); 
		DynamicGL_MultMatrixf = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *m)>("glMultMatrixf"); 
		DynamicGL_Rotated = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble angle , GLdouble x , GLdouble y , GLdouble z)>("glRotated"); 
		DynamicGL_Rotatef = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat angle , GLfloat x , GLfloat y , GLfloat z)>("glRotatef"); 
		DynamicGL_Scaled = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble x , GLdouble y , GLdouble z)>("glScaled"); 
		DynamicGL_Scalef = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat x , GLfloat y , GLfloat z)>("glScalef"); 
		DynamicGL_Translated = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble x , GLdouble y , GLdouble z)>("glTranslated"); 
		DynamicGL_Translatef = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat x , GLfloat y , GLfloat z)>("glTranslatef"); 
		DynamicGL_IsList = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLuint list)>("glIsList"); 
		DynamicGL_DeleteLists = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint list , GLsizei range)>("glDeleteLists"); 
		DynamicGL_GenLists = DynamicGL_LoadFunction<GLuint (DYNAMIC_GL_APIENTRYP)(GLsizei range)>("glGenLists"); 
		DynamicGL_NewList = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint list , GLenum mode)>("glNewList"); 
		DynamicGL_EndList = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glEndList"); 
		DynamicGL_CallList = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint list)>("glCallList"); 
		DynamicGL_CallLists = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , GLenum type , const GLvoid *lists)>("glCallLists"); 
		DynamicGL_ListBase = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint base)>("glListBase"); 
		DynamicGL_Begin = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode)>("glBegin"); 
		DynamicGL_End = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glEnd"); 
		DynamicGL_Vertex2d = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble x , GLdouble y)>("glVertex2d"); 
		DynamicGL_Vertex2f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat x , GLfloat y)>("glVertex2f"); 
		DynamicGL_Vertex2i = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint x , GLint y)>("glVertex2i"); 
		DynamicGL_Vertex2s = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLshort x , GLshort y)>("glVertex2s"); 
		DynamicGL_Vertex3d = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble x , GLdouble y , GLdouble z)>("glVertex3d"); 
		DynamicGL_Vertex3f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat x , GLfloat y , GLfloat z)>("glVertex3f"); 
		DynamicGL_Vertex3i = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint x , GLint y , GLint z)>("glVertex3i"); 
		DynamicGL_Vertex3s = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLshort x , GLshort y , GLshort z)>("glVertex3s"); 
		DynamicGL_Vertex4d = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble x , GLdouble y , GLdouble z , GLdouble w)>("glVertex4d"); 
		DynamicGL_Vertex4f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat x , GLfloat y , GLfloat z , GLfloat w)>("glVertex4f"); 
		DynamicGL_Vertex4i = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint x , GLint y , GLint z , GLint w)>("glVertex4i"); 
		DynamicGL_Vertex4s = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLshort x , GLshort y , GLshort z , GLshort w)>("glVertex4s"); 
		DynamicGL_Vertex2dv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *v)>("glVertex2dv"); 
		DynamicGL_Vertex2fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *v)>("glVertex2fv"); 
		DynamicGL_Vertex2iv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLint *v)>("glVertex2iv"); 
		DynamicGL_Vertex2sv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLshort *v)>("glVertex2sv"); 
		DynamicGL_Vertex3dv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *v)>("glVertex3dv"); 
		DynamicGL_Vertex3fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *v)>("glVertex3fv"); 
		DynamicGL_Vertex3iv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLint *v)>("glVertex3iv"); 
		DynamicGL_Vertex3sv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLshort *v)>("glVertex3sv"); 
		DynamicGL_Vertex4dv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *v)>("glVertex4dv"); 
		DynamicGL_Vertex4fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *v)>("glVertex4fv"); 
		DynamicGL_Vertex4iv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLint *v)>("glVertex4iv"); 
		DynamicGL_Vertex4sv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLshort *v)>("glVertex4sv"); 
		DynamicGL_Normal3b = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLbyte nx , GLbyte ny , GLbyte nz)>("glNormal3b"); 
		DynamicGL_Normal3d = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble nx , GLdouble ny , GLdouble nz)>("glNormal3d"); 
		DynamicGL_Normal3f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat nx , GLfloat ny , GLfloat nz)>("glNormal3f"); 
		DynamicGL_Normal3i = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint nx , GLint ny , GLint nz)>("glNormal3i"); 
		DynamicGL_Normal3s = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLshort nx , GLshort ny , GLshort nz)>("glNormal3s"); 
		DynamicGL_Normal3bv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLbyte *v)>("glNormal3bv"); 
		DynamicGL_Normal3dv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *v)>("glNormal3dv"); 
		DynamicGL_Normal3fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *v)>("glNormal3fv"); 
		DynamicGL_Normal3iv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLint *v)>("glNormal3iv"); 
		DynamicGL_Normal3sv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLshort *v)>("glNormal3sv"); 
		DynamicGL_Indexd = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble c)>("glIndexd"); 
		DynamicGL_Indexf = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat c)>("glIndexf"); 
		DynamicGL_Indexi = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint c)>("glIndexi"); 
		DynamicGL_Indexs = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLshort c)>("glIndexs"); 
		DynamicGL_Indexub = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLubyte c)>("glIndexub"); 
		DynamicGL_Indexdv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *c)>("glIndexdv"); 
		DynamicGL_Indexfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *c)>("glIndexfv"); 
		DynamicGL_Indexiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLint *c)>("glIndexiv"); 
		DynamicGL_Indexsv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLshort *c)>("glIndexsv"); 
		DynamicGL_Indexubv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLubyte *c)>("glIndexubv"); 
		DynamicGL_Color3b = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLbyte red , GLbyte green , GLbyte blue)>("glColor3b"); 
		DynamicGL_Color3d = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble red , GLdouble green , GLdouble blue)>("glColor3d"); 
		DynamicGL_Color3f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat red , GLfloat green , GLfloat blue)>("glColor3f"); 
		DynamicGL_Color3i = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint red , GLint green , GLint blue)>("glColor3i"); 
		DynamicGL_Color3s = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLshort red , GLshort green , GLshort blue)>("glColor3s"); 
		DynamicGL_Color3ub = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLubyte red , GLubyte green , GLubyte blue)>("glColor3ub"); 
		DynamicGL_Color3ui = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint red , GLuint green , GLuint blue)>("glColor3ui"); 
		DynamicGL_Color3us = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLushort red , GLushort green , GLushort blue)>("glColor3us"); 
		DynamicGL_Color4b = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLbyte red , GLbyte green , GLbyte blue , GLbyte alpha)>("glColor4b"); 
		DynamicGL_Color4d = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble red , GLdouble green , GLdouble blue , GLdouble alpha)>("glColor4d"); 
		DynamicGL_Color4f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat red , GLfloat green , GLfloat blue , GLfloat alpha)>("glColor4f"); 
		DynamicGL_Color4i = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint red , GLint green , GLint blue , GLint alpha)>("glColor4i"); 
		DynamicGL_Color4s = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLshort red , GLshort green , GLshort blue , GLshort alpha)>("glColor4s"); 
		DynamicGL_Color4ub = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLubyte red , GLubyte green , GLubyte blue , GLubyte alpha)>("glColor4ub"); 
		DynamicGL_Color4ui = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint red , GLuint green , GLuint blue , GLuint alpha)>("glColor4ui"); 
		DynamicGL_Color4us = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLushort red , GLushort green , GLushort blue , GLushort alpha)>("glColor4us"); 
		DynamicGL_Color3bv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLbyte *v)>("glColor3bv"); 
		DynamicGL_Color3dv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *v)>("glColor3dv"); 
		DynamicGL_Color3fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *v)>("glColor3fv"); 
		DynamicGL_Color3iv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLint *v)>("glColor3iv"); 
		DynamicGL_Color3sv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLshort *v)>("glColor3sv"); 
		DynamicGL_Color3ubv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLubyte *v)>("glColor3ubv"); 
		DynamicGL_Color3uiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLuint *v)>("glColor3uiv"); 
		DynamicGL_Color3usv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLushort *v)>("glColor3usv"); 
		DynamicGL_Color4bv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLbyte *v)>("glColor4bv"); 
		DynamicGL_Color4dv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *v)>("glColor4dv"); 
		DynamicGL_Color4fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *v)>("glColor4fv"); 
		DynamicGL_Color4iv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLint *v)>("glColor4iv"); 
		DynamicGL_Color4sv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLshort *v)>("glColor4sv"); 
		DynamicGL_Color4ubv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLubyte *v)>("glColor4ubv"); 
		DynamicGL_Color4uiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLuint *v)>("glColor4uiv"); 
		DynamicGL_Color4usv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLushort *v)>("glColor4usv"); 
		DynamicGL_TexCoord1d = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble s)>("glTexCoord1d"); 
		DynamicGL_TexCoord1f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat s)>("glTexCoord1f"); 
		DynamicGL_TexCoord1i = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint s)>("glTexCoord1i"); 
		DynamicGL_TexCoord1s = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLshort s)>("glTexCoord1s"); 
		DynamicGL_TexCoord2d = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble s , GLdouble t)>("glTexCoord2d"); 
		DynamicGL_TexCoord2f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat s , GLfloat t)>("glTexCoord2f"); 
		DynamicGL_TexCoord2i = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint s , GLint t)>("glTexCoord2i"); 
		DynamicGL_TexCoord2s = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLshort s , GLshort t)>("glTexCoord2s"); 
		DynamicGL_TexCoord3d = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble s , GLdouble t , GLdouble r)>("glTexCoord3d"); 
		DynamicGL_TexCoord3f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat s , GLfloat t , GLfloat r)>("glTexCoord3f"); 
		DynamicGL_TexCoord3i = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint s , GLint t , GLint r)>("glTexCoord3i"); 
		DynamicGL_TexCoord3s = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLshort s , GLshort t , GLshort r)>("glTexCoord3s"); 
		DynamicGL_TexCoord4d = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble s , GLdouble t , GLdouble r , GLdouble q)>("glTexCoord4d"); 
		DynamicGL_TexCoord4f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat s , GLfloat t , GLfloat r , GLfloat q)>("glTexCoord4f"); 
		DynamicGL_TexCoord4i = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint s , GLint t , GLint r , GLint q)>("glTexCoord4i"); 
		DynamicGL_TexCoord4s = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLshort s , GLshort t , GLshort r , GLshort q)>("glTexCoord4s"); 
		DynamicGL_TexCoord1dv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *v)>("glTexCoord1dv"); 
		DynamicGL_TexCoord1fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *v)>("glTexCoord1fv"); 
		DynamicGL_TexCoord1iv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLint *v)>("glTexCoord1iv"); 
		DynamicGL_TexCoord1sv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLshort *v)>("glTexCoord1sv"); 
		DynamicGL_TexCoord2dv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *v)>("glTexCoord2dv"); 
		DynamicGL_TexCoord2fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *v)>("glTexCoord2fv"); 
		DynamicGL_TexCoord2iv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLint *v)>("glTexCoord2iv"); 
		DynamicGL_TexCoord2sv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLshort *v)>("glTexCoord2sv"); 
		DynamicGL_TexCoord3dv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *v)>("glTexCoord3dv"); 
		DynamicGL_TexCoord3fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *v)>("glTexCoord3fv"); 
		DynamicGL_TexCoord3iv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLint *v)>("glTexCoord3iv"); 
		DynamicGL_TexCoord3sv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLshort *v)>("glTexCoord3sv"); 
		DynamicGL_TexCoord4dv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *v)>("glTexCoord4dv"); 
		DynamicGL_TexCoord4fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *v)>("glTexCoord4fv"); 
		DynamicGL_TexCoord4iv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLint *v)>("glTexCoord4iv"); 
		DynamicGL_TexCoord4sv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLshort *v)>("glTexCoord4sv"); 
		DynamicGL_RasterPos2d = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble x , GLdouble y)>("glRasterPos2d"); 
		DynamicGL_RasterPos2f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat x , GLfloat y)>("glRasterPos2f"); 
		DynamicGL_RasterPos2i = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint x , GLint y)>("glRasterPos2i"); 
		DynamicGL_RasterPos2s = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLshort x , GLshort y)>("glRasterPos2s"); 
		DynamicGL_RasterPos3d = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble x , GLdouble y , GLdouble z)>("glRasterPos3d"); 
		DynamicGL_RasterPos3f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat x , GLfloat y , GLfloat z)>("glRasterPos3f"); 
		DynamicGL_RasterPos3i = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint x , GLint y , GLint z)>("glRasterPos3i"); 
		DynamicGL_RasterPos3s = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLshort x , GLshort y , GLshort z)>("glRasterPos3s"); 
		DynamicGL_RasterPos4d = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble x , GLdouble y , GLdouble z , GLdouble w)>("glRasterPos4d"); 
		DynamicGL_RasterPos4f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat x , GLfloat y , GLfloat z , GLfloat w)>("glRasterPos4f"); 
		DynamicGL_RasterPos4i = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint x , GLint y , GLint z , GLint w)>("glRasterPos4i"); 
		DynamicGL_RasterPos4s = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLshort x , GLshort y , GLshort z , GLshort w)>("glRasterPos4s"); 
		DynamicGL_RasterPos2dv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *v)>("glRasterPos2dv"); 
		DynamicGL_RasterPos2fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *v)>("glRasterPos2fv"); 
		DynamicGL_RasterPos2iv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLint *v)>("glRasterPos2iv"); 
		DynamicGL_RasterPos2sv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLshort *v)>("glRasterPos2sv"); 
		DynamicGL_RasterPos3dv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *v)>("glRasterPos3dv"); 
		DynamicGL_RasterPos3fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *v)>("glRasterPos3fv"); 
		DynamicGL_RasterPos3iv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLint *v)>("glRasterPos3iv"); 
		DynamicGL_RasterPos3sv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLshort *v)>("glRasterPos3sv"); 
		DynamicGL_RasterPos4dv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *v)>("glRasterPos4dv"); 
		DynamicGL_RasterPos4fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *v)>("glRasterPos4fv"); 
		DynamicGL_RasterPos4iv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLint *v)>("glRasterPos4iv"); 
		DynamicGL_RasterPos4sv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLshort *v)>("glRasterPos4sv"); 
		DynamicGL_Rectd = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble x1 , GLdouble y1 , GLdouble x2 , GLdouble y2)>("glRectd"); 
		DynamicGL_Rectf = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat x1 , GLfloat y1 , GLfloat x2 , GLfloat y2)>("glRectf"); 
		DynamicGL_Recti = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint x1 , GLint y1 , GLint x2 , GLint y2)>("glRecti"); 
		DynamicGL_Rects = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLshort x1 , GLshort y1 , GLshort x2 , GLshort y2)>("glRects"); 
		DynamicGL_Rectdv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *v1 , const GLdouble *v2)>("glRectdv"); 
		DynamicGL_Rectfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *v1 , const GLfloat *v2)>("glRectfv"); 
		DynamicGL_Rectiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLint *v1 , const GLint *v2)>("glRectiv"); 
		DynamicGL_Rectsv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLshort *v1 , const GLshort *v2)>("glRectsv"); 
		DynamicGL_ShadeModel = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode)>("glShadeModel"); 
		DynamicGL_Lightf = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum light , GLenum pname , GLfloat param)>("glLightf"); 
		DynamicGL_Lighti = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum light , GLenum pname , GLint param)>("glLighti"); 
		DynamicGL_Lightfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum light , GLenum pname , const GLfloat *params)>("glLightfv"); 
		DynamicGL_Lightiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum light , GLenum pname , const GLint *params)>("glLightiv"); 
		DynamicGL_GetLightfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum light , GLenum pname , GLfloat *params)>("glGetLightfv"); 
		DynamicGL_GetLightiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum light , GLenum pname , GLint *params)>("glGetLightiv"); 
		DynamicGL_LightModelf = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLfloat param)>("glLightModelf"); 
		DynamicGL_LightModeli = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLint param)>("glLightModeli"); 
		DynamicGL_LightModelfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , const GLfloat *params)>("glLightModelfv"); 
		DynamicGL_LightModeliv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , const GLint *params)>("glLightModeliv"); 
		DynamicGL_Materialf = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum face , GLenum pname , GLfloat param)>("glMaterialf"); 
		DynamicGL_Materiali = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum face , GLenum pname , GLint param)>("glMateriali"); 
		DynamicGL_Materialfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum face , GLenum pname , const GLfloat *params)>("glMaterialfv"); 
		DynamicGL_Materialiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum face , GLenum pname , const GLint *params)>("glMaterialiv"); 
		DynamicGL_GetMaterialfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum face , GLenum pname , GLfloat *params)>("glGetMaterialfv"); 
		DynamicGL_GetMaterialiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum face , GLenum pname , GLint *params)>("glGetMaterialiv"); 
		DynamicGL_ColorMaterial = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum face , GLenum mode)>("glColorMaterial"); 
		DynamicGL_PixelZoom = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat xfactor , GLfloat yfactor)>("glPixelZoom"); 
		DynamicGL_PixelStoref = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLfloat param)>("glPixelStoref"); 
		DynamicGL_PixelStorei = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLint param)>("glPixelStorei"); 
		DynamicGL_PixelTransferf = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLfloat param)>("glPixelTransferf"); 
		DynamicGL_PixelTransferi = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLint param)>("glPixelTransferi"); 
		DynamicGL_PixelMapfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum map , GLint mapsize , const GLfloat *values)>("glPixelMapfv"); 
		DynamicGL_PixelMapuiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum map , GLint mapsize , const GLuint *values)>("glPixelMapuiv"); 
		DynamicGL_PixelMapusv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum map , GLint mapsize , const GLushort *values)>("glPixelMapusv"); 
		DynamicGL_GetPixelMapfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum map , GLfloat *values)>("glGetPixelMapfv"); 
		DynamicGL_GetPixelMapuiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum map , GLuint *values)>("glGetPixelMapuiv"); 
		DynamicGL_GetPixelMapusv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum map , GLushort *values)>("glGetPixelMapusv"); 
		DynamicGL_Bitmap = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei width , GLsizei height , GLfloat xorig , GLfloat yorig , GLfloat xmove , GLfloat ymove , const GLubyte *bitmap)>("glBitmap"); 
		DynamicGL_ReadPixels = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint x , GLint y , GLsizei width , GLsizei height , GLenum format , GLenum type , GLvoid *pixels)>("glReadPixels"); 
		DynamicGL_DrawPixels = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei width , GLsizei height , GLenum format , GLenum type , const GLvoid *pixels)>("glDrawPixels"); 
		DynamicGL_CopyPixels = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint x , GLint y , GLsizei width , GLsizei height , GLenum type)>("glCopyPixels"); 
		DynamicGL_StencilFunc = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum func , GLint ref , GLuint mask)>("glStencilFunc"); 
		DynamicGL_StencilMask = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint mask)>("glStencilMask"); 
		DynamicGL_StencilOp = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum fail , GLenum zfail , GLenum zpass)>("glStencilOp"); 
		DynamicGL_ClearStencil = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint s)>("glClearStencil"); 
		DynamicGL_TexGend = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum coord , GLenum pname , GLdouble param)>("glTexGend"); 
		DynamicGL_TexGenf = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum coord , GLenum pname , GLfloat param)>("glTexGenf"); 
		DynamicGL_TexGeni = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum coord , GLenum pname , GLint param)>("glTexGeni"); 
		DynamicGL_TexGendv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum coord , GLenum pname , const GLdouble *params)>("glTexGendv"); 
		DynamicGL_TexGenfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum coord , GLenum pname , const GLfloat *params)>("glTexGenfv"); 
		DynamicGL_TexGeniv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum coord , GLenum pname , const GLint *params)>("glTexGeniv"); 
		DynamicGL_GetTexGendv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum coord , GLenum pname , GLdouble *params)>("glGetTexGendv"); 
		DynamicGL_GetTexGenfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum coord , GLenum pname , GLfloat *params)>("glGetTexGenfv"); 
		DynamicGL_GetTexGeniv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum coord , GLenum pname , GLint *params)>("glGetTexGeniv"); 
		DynamicGL_TexEnvf = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLfloat param)>("glTexEnvf"); 
		DynamicGL_TexEnvi = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint param)>("glTexEnvi"); 
		DynamicGL_TexEnvfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , const GLfloat *params)>("glTexEnvfv"); 
		DynamicGL_TexEnviv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , const GLint *params)>("glTexEnviv"); 
		DynamicGL_GetTexEnvfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLfloat *params)>("glGetTexEnvfv"); 
		DynamicGL_GetTexEnviv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint *params)>("glGetTexEnviv"); 
		DynamicGL_TexParameterf = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLfloat param)>("glTexParameterf"); 
		DynamicGL_TexParameteri = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint param)>("glTexParameteri"); 
		DynamicGL_TexParameterfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , const GLfloat *params)>("glTexParameterfv"); 
		DynamicGL_TexParameteriv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , const GLint *params)>("glTexParameteriv"); 
		DynamicGL_GetTexParameterfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLfloat *params)>("glGetTexParameterfv"); 
		DynamicGL_GetTexParameteriv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint *params)>("glGetTexParameteriv"); 
		DynamicGL_GetTexLevelParameterfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLenum pname , GLfloat *params)>("glGetTexLevelParameterfv"); 
		DynamicGL_GetTexLevelParameteriv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLenum pname , GLint *params)>("glGetTexLevelParameteriv"); 
		DynamicGL_TexImage1D = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLint internalFormat , GLsizei width , GLint border , GLenum format , GLenum type , const GLvoid *pixels)>("glTexImage1D"); 
		DynamicGL_TexImage2D = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLint internalFormat , GLsizei width , GLsizei height , GLint border , GLenum format , GLenum type , const GLvoid *pixels)>("glTexImage2D"); 
		DynamicGL_GetTexImage = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLenum format , GLenum type , GLvoid *pixels)>("glGetTexImage"); 
		DynamicGL_Map1d = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLdouble u1 , GLdouble u2 , GLint stride , GLint order , const GLdouble *points)>("glMap1d"); 
		DynamicGL_Map1f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLfloat u1 , GLfloat u2 , GLint stride , GLint order , const GLfloat *points)>("glMap1f"); 
		DynamicGL_Map2d = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLdouble u1 , GLdouble u2 , GLint ustride , GLint uorder , GLdouble v1 , GLdouble v2 , GLint vstride , GLint vorder , const GLdouble *points)>("glMap2d"); 
		DynamicGL_Map2f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLfloat u1 , GLfloat u2 , GLint ustride , GLint uorder , GLfloat v1 , GLfloat v2 , GLint vstride , GLint vorder , const GLfloat *points)>("glMap2f"); 
		DynamicGL_GetMapdv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum query , GLdouble *v)>("glGetMapdv"); 
		DynamicGL_GetMapfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum query , GLfloat *v)>("glGetMapfv"); 
		DynamicGL_GetMapiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum query , GLint *v)>("glGetMapiv"); 
		DynamicGL_EvalCoord1d = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble u)>("glEvalCoord1d"); 
		DynamicGL_EvalCoord1f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat u)>("glEvalCoord1f"); 
		DynamicGL_EvalCoord1dv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *u)>("glEvalCoord1dv"); 
		DynamicGL_EvalCoord1fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *u)>("glEvalCoord1fv"); 
		DynamicGL_EvalCoord2d = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble u , GLdouble v)>("glEvalCoord2d"); 
		DynamicGL_EvalCoord2f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat u , GLfloat v)>("glEvalCoord2f"); 
		DynamicGL_EvalCoord2dv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *u)>("glEvalCoord2dv"); 
		DynamicGL_EvalCoord2fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *u)>("glEvalCoord2fv"); 
		DynamicGL_MapGrid1d = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint un , GLdouble u1 , GLdouble u2)>("glMapGrid1d"); 
		DynamicGL_MapGrid1f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint un , GLfloat u1 , GLfloat u2)>("glMapGrid1f"); 
		DynamicGL_MapGrid2d = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint un , GLdouble u1 , GLdouble u2 , GLint vn , GLdouble v1 , GLdouble v2)>("glMapGrid2d"); 
		DynamicGL_MapGrid2f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint un , GLfloat u1 , GLfloat u2 , GLint vn , GLfloat v1 , GLfloat v2)>("glMapGrid2f"); 
		DynamicGL_EvalPoint1 = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint i)>("glEvalPoint1"); 
		DynamicGL_EvalPoint2 = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint i , GLint j)>("glEvalPoint2"); 
		DynamicGL_EvalMesh1 = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , GLint i1 , GLint i2)>("glEvalMesh1"); 
		DynamicGL_EvalMesh2 = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , GLint i1 , GLint i2 , GLint j1 , GLint j2)>("glEvalMesh2"); 
		DynamicGL_Fogf = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLfloat param)>("glFogf"); 
		DynamicGL_Fogi = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLint param)>("glFogi"); 
		DynamicGL_Fogfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , const GLfloat *params)>("glFogfv"); 
		DynamicGL_Fogiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , const GLint *params)>("glFogiv"); 
		DynamicGL_FeedbackBuffer = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei size , GLenum type , GLfloat *buffer)>("glFeedbackBuffer"); 
		DynamicGL_PassThrough = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat token)>("glPassThrough"); 
		DynamicGL_SelectBuffer = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei size , GLuint *buffer)>("glSelectBuffer"); 
		DynamicGL_InitNames = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glInitNames"); 
		DynamicGL_LoadName = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint name)>("glLoadName"); 
		DynamicGL_PushName = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint name)>("glPushName"); 
		DynamicGL_PopName = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glPopName"); 
		DynamicGL_GenTextures = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , GLuint *textures)>("glGenTextures"); 
		DynamicGL_DeleteTextures = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , const GLuint *textures)>("glDeleteTextures"); 
		DynamicGL_BindTexture = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint texture)>("glBindTexture"); 
		DynamicGL_PrioritizeTextures = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , const GLuint *textures , const GLclampf *priorities)>("glPrioritizeTextures"); 
		DynamicGL_AreTexturesResident = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLsizei n , const GLuint *textures , GLboolean *residences)>("glAreTexturesResident"); 
		DynamicGL_IsTexture = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLuint texture)>("glIsTexture"); 
		DynamicGL_TexSubImage1D = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLint xoffset , GLsizei width , GLenum format , GLenum type , const GLvoid *pixels)>("glTexSubImage1D"); 
		DynamicGL_TexSubImage2D = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLsizei width , GLsizei height , GLenum format , GLenum type , const GLvoid *pixels)>("glTexSubImage2D"); 
		DynamicGL_CopyTexImage1D = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLenum internalformat , GLint x , GLint y , GLsizei width , GLint border)>("glCopyTexImage1D"); 
		DynamicGL_CopyTexImage2D = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLenum internalformat , GLint x , GLint y , GLsizei width , GLsizei height , GLint border)>("glCopyTexImage2D"); 
		DynamicGL_CopyTexSubImage1D = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLint xoffset , GLint x , GLint y , GLsizei width)>("glCopyTexSubImage1D"); 
		DynamicGL_CopyTexSubImage2D = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint x , GLint y , GLsizei width , GLsizei height)>("glCopyTexSubImage2D"); 
		DynamicGL_VertexPointer = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint size , GLenum type , GLsizei stride , const GLvoid *ptr)>("glVertexPointer"); 
		DynamicGL_NormalPointer = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum type , GLsizei stride , const GLvoid *ptr)>("glNormalPointer"); 
		DynamicGL_ColorPointer = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint size , GLenum type , GLsizei stride , const GLvoid *ptr)>("glColorPointer"); 
		DynamicGL_IndexPointer = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum type , GLsizei stride , const GLvoid *ptr)>("glIndexPointer"); 
		DynamicGL_TexCoordPointer = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint size , GLenum type , GLsizei stride , const GLvoid *ptr)>("glTexCoordPointer"); 
		DynamicGL_EdgeFlagPointer = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei stride , const GLvoid *ptr)>("glEdgeFlagPointer"); 
		DynamicGL_GetPointerv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLvoid *p1)>("glGetPointerv"); 
		DynamicGL_ArrayElement = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint i)>("glArrayElement"); 
		DynamicGL_DrawArrays = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , GLint first , GLsizei count)>("glDrawArrays"); 
		DynamicGL_DrawElements = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , GLsizei count , GLenum type , const GLvoid *indices)>("glDrawElements"); 
		DynamicGL_InterleavedArrays = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum format , GLsizei stride , const GLvoid *pointer)>("glInterleavedArrays"); 
		DinamicGLFeature_VERSION_1_1_loaded = true; 
}
bool DinamicGLFeature_VERSION_1_1_Supported() {
		if (!DinamicGLFeature_VERSION_1_1_loaded) {
			InitDinamicGLFeature_VERSION_1_1();
		}
		if (DynamicGL_ClearIndex==0) return false; 
		if (DynamicGL_ClearColor==0) return false; 
		if (DynamicGL_Clear==0) return false; 
		if (DynamicGL_IndexMask==0) return false; 
		if (DynamicGL_ColorMask==0) return false; 
		if (DynamicGL_AlphaFunc==0) return false; 
		if (DynamicGL_BlendFunc==0) return false; 
		if (DynamicGL_LogicOp==0) return false; 
		if (DynamicGL_CullFace==0) return false; 
		if (DynamicGL_FrontFace==0) return false; 
		if (DynamicGL_PointSize==0) return false; 
		if (DynamicGL_LineWidth==0) return false; 
		if (DynamicGL_LineStipple==0) return false; 
		if (DynamicGL_PolygonMode==0) return false; 
		if (DynamicGL_PolygonOffset==0) return false; 
		if (DynamicGL_PolygonStipple==0) return false; 
		if (DynamicGL_GetPolygonStipple==0) return false; 
		if (DynamicGL_EdgeFlag==0) return false; 
		if (DynamicGL_EdgeFlagv==0) return false; 
		if (DynamicGL_Scissor==0) return false; 
		if (DynamicGL_ClipPlane==0) return false; 
		if (DynamicGL_GetClipPlane==0) return false; 
		if (DynamicGL_DrawBuffer==0) return false; 
		if (DynamicGL_ReadBuffer==0) return false; 
		if (DynamicGL_Enable==0) return false; 
		if (DynamicGL_Disable==0) return false; 
		if (DynamicGL_IsEnabled==0) return false; 
		if (DynamicGL_EnableClientState==0) return false; 
		if (DynamicGL_DisableClientState==0) return false; 
		if (DynamicGL_GetBooleanv==0) return false; 
		if (DynamicGL_GetDoublev==0) return false; 
		if (DynamicGL_GetFloatv==0) return false; 
		if (DynamicGL_GetIntegerv==0) return false; 
		if (DynamicGL_PushAttrib==0) return false; 
		if (DynamicGL_PopAttrib==0) return false; 
		if (DynamicGL_PushClientAttrib==0) return false; 
		if (DynamicGL_PopClientAttrib==0) return false; 
		if (DynamicGL_RenderMode==0) return false; 
		if (DynamicGL_GetError==0) return false; 
		if (DynamicGL_GetString==0) return false; 
		if (DynamicGL_Finish==0) return false; 
		if (DynamicGL_Flush==0) return false; 
		if (DynamicGL_Hint==0) return false; 
		if (DynamicGL_ClearDepth==0) return false; 
		if (DynamicGL_DepthFunc==0) return false; 
		if (DynamicGL_DepthMask==0) return false; 
		if (DynamicGL_DepthRange==0) return false; 
		if (DynamicGL_ClearAccum==0) return false; 
		if (DynamicGL_Accum==0) return false; 
		if (DynamicGL_MatrixMode==0) return false; 
		if (DynamicGL_Ortho==0) return false; 
		if (DynamicGL_Frustum==0) return false; 
		if (DynamicGL_Viewport==0) return false; 
		if (DynamicGL_PushMatrix==0) return false; 
		if (DynamicGL_PopMatrix==0) return false; 
		if (DynamicGL_LoadIdentity==0) return false; 
		if (DynamicGL_LoadMatrixd==0) return false; 
		if (DynamicGL_LoadMatrixf==0) return false; 
		if (DynamicGL_MultMatrixd==0) return false; 
		if (DynamicGL_MultMatrixf==0) return false; 
		if (DynamicGL_Rotated==0) return false; 
		if (DynamicGL_Rotatef==0) return false; 
		if (DynamicGL_Scaled==0) return false; 
		if (DynamicGL_Scalef==0) return false; 
		if (DynamicGL_Translated==0) return false; 
		if (DynamicGL_Translatef==0) return false; 
		if (DynamicGL_IsList==0) return false; 
		if (DynamicGL_DeleteLists==0) return false; 
		if (DynamicGL_GenLists==0) return false; 
		if (DynamicGL_NewList==0) return false; 
		if (DynamicGL_EndList==0) return false; 
		if (DynamicGL_CallList==0) return false; 
		if (DynamicGL_CallLists==0) return false; 
		if (DynamicGL_ListBase==0) return false; 
		if (DynamicGL_Begin==0) return false; 
		if (DynamicGL_End==0) return false; 
		if (DynamicGL_Vertex2d==0) return false; 
		if (DynamicGL_Vertex2f==0) return false; 
		if (DynamicGL_Vertex2i==0) return false; 
		if (DynamicGL_Vertex2s==0) return false; 
		if (DynamicGL_Vertex3d==0) return false; 
		if (DynamicGL_Vertex3f==0) return false; 
		if (DynamicGL_Vertex3i==0) return false; 
		if (DynamicGL_Vertex3s==0) return false; 
		if (DynamicGL_Vertex4d==0) return false; 
		if (DynamicGL_Vertex4f==0) return false; 
		if (DynamicGL_Vertex4i==0) return false; 
		if (DynamicGL_Vertex4s==0) return false; 
		if (DynamicGL_Vertex2dv==0) return false; 
		if (DynamicGL_Vertex2fv==0) return false; 
		if (DynamicGL_Vertex2iv==0) return false; 
		if (DynamicGL_Vertex2sv==0) return false; 
		if (DynamicGL_Vertex3dv==0) return false; 
		if (DynamicGL_Vertex3fv==0) return false; 
		if (DynamicGL_Vertex3iv==0) return false; 
		if (DynamicGL_Vertex3sv==0) return false; 
		if (DynamicGL_Vertex4dv==0) return false; 
		if (DynamicGL_Vertex4fv==0) return false; 
		if (DynamicGL_Vertex4iv==0) return false; 
		if (DynamicGL_Vertex4sv==0) return false; 
		if (DynamicGL_Normal3b==0) return false; 
		if (DynamicGL_Normal3d==0) return false; 
		if (DynamicGL_Normal3f==0) return false; 
		if (DynamicGL_Normal3i==0) return false; 
		if (DynamicGL_Normal3s==0) return false; 
		if (DynamicGL_Normal3bv==0) return false; 
		if (DynamicGL_Normal3dv==0) return false; 
		if (DynamicGL_Normal3fv==0) return false; 
		if (DynamicGL_Normal3iv==0) return false; 
		if (DynamicGL_Normal3sv==0) return false; 
		if (DynamicGL_Indexd==0) return false; 
		if (DynamicGL_Indexf==0) return false; 
		if (DynamicGL_Indexi==0) return false; 
		if (DynamicGL_Indexs==0) return false; 
		if (DynamicGL_Indexub==0) return false; 
		if (DynamicGL_Indexdv==0) return false; 
		if (DynamicGL_Indexfv==0) return false; 
		if (DynamicGL_Indexiv==0) return false; 
		if (DynamicGL_Indexsv==0) return false; 
		if (DynamicGL_Indexubv==0) return false; 
		if (DynamicGL_Color3b==0) return false; 
		if (DynamicGL_Color3d==0) return false; 
		if (DynamicGL_Color3f==0) return false; 
		if (DynamicGL_Color3i==0) return false; 
		if (DynamicGL_Color3s==0) return false; 
		if (DynamicGL_Color3ub==0) return false; 
		if (DynamicGL_Color3ui==0) return false; 
		if (DynamicGL_Color3us==0) return false; 
		if (DynamicGL_Color4b==0) return false; 
		if (DynamicGL_Color4d==0) return false; 
		if (DynamicGL_Color4f==0) return false; 
		if (DynamicGL_Color4i==0) return false; 
		if (DynamicGL_Color4s==0) return false; 
		if (DynamicGL_Color4ub==0) return false; 
		if (DynamicGL_Color4ui==0) return false; 
		if (DynamicGL_Color4us==0) return false; 
		if (DynamicGL_Color3bv==0) return false; 
		if (DynamicGL_Color3dv==0) return false; 
		if (DynamicGL_Color3fv==0) return false; 
		if (DynamicGL_Color3iv==0) return false; 
		if (DynamicGL_Color3sv==0) return false; 
		if (DynamicGL_Color3ubv==0) return false; 
		if (DynamicGL_Color3uiv==0) return false; 
		if (DynamicGL_Color3usv==0) return false; 
		if (DynamicGL_Color4bv==0) return false; 
		if (DynamicGL_Color4dv==0) return false; 
		if (DynamicGL_Color4fv==0) return false; 
		if (DynamicGL_Color4iv==0) return false; 
		if (DynamicGL_Color4sv==0) return false; 
		if (DynamicGL_Color4ubv==0) return false; 
		if (DynamicGL_Color4uiv==0) return false; 
		if (DynamicGL_Color4usv==0) return false; 
		if (DynamicGL_TexCoord1d==0) return false; 
		if (DynamicGL_TexCoord1f==0) return false; 
		if (DynamicGL_TexCoord1i==0) return false; 
		if (DynamicGL_TexCoord1s==0) return false; 
		if (DynamicGL_TexCoord2d==0) return false; 
		if (DynamicGL_TexCoord2f==0) return false; 
		if (DynamicGL_TexCoord2i==0) return false; 
		if (DynamicGL_TexCoord2s==0) return false; 
		if (DynamicGL_TexCoord3d==0) return false; 
		if (DynamicGL_TexCoord3f==0) return false; 
		if (DynamicGL_TexCoord3i==0) return false; 
		if (DynamicGL_TexCoord3s==0) return false; 
		if (DynamicGL_TexCoord4d==0) return false; 
		if (DynamicGL_TexCoord4f==0) return false; 
		if (DynamicGL_TexCoord4i==0) return false; 
		if (DynamicGL_TexCoord4s==0) return false; 
		if (DynamicGL_TexCoord1dv==0) return false; 
		if (DynamicGL_TexCoord1fv==0) return false; 
		if (DynamicGL_TexCoord1iv==0) return false; 
		if (DynamicGL_TexCoord1sv==0) return false; 
		if (DynamicGL_TexCoord2dv==0) return false; 
		if (DynamicGL_TexCoord2fv==0) return false; 
		if (DynamicGL_TexCoord2iv==0) return false; 
		if (DynamicGL_TexCoord2sv==0) return false; 
		if (DynamicGL_TexCoord3dv==0) return false; 
		if (DynamicGL_TexCoord3fv==0) return false; 
		if (DynamicGL_TexCoord3iv==0) return false; 
		if (DynamicGL_TexCoord3sv==0) return false; 
		if (DynamicGL_TexCoord4dv==0) return false; 
		if (DynamicGL_TexCoord4fv==0) return false; 
		if (DynamicGL_TexCoord4iv==0) return false; 
		if (DynamicGL_TexCoord4sv==0) return false; 
		if (DynamicGL_RasterPos2d==0) return false; 
		if (DynamicGL_RasterPos2f==0) return false; 
		if (DynamicGL_RasterPos2i==0) return false; 
		if (DynamicGL_RasterPos2s==0) return false; 
		if (DynamicGL_RasterPos3d==0) return false; 
		if (DynamicGL_RasterPos3f==0) return false; 
		if (DynamicGL_RasterPos3i==0) return false; 
		if (DynamicGL_RasterPos3s==0) return false; 
		if (DynamicGL_RasterPos4d==0) return false; 
		if (DynamicGL_RasterPos4f==0) return false; 
		if (DynamicGL_RasterPos4i==0) return false; 
		if (DynamicGL_RasterPos4s==0) return false; 
		if (DynamicGL_RasterPos2dv==0) return false; 
		if (DynamicGL_RasterPos2fv==0) return false; 
		if (DynamicGL_RasterPos2iv==0) return false; 
		if (DynamicGL_RasterPos2sv==0) return false; 
		if (DynamicGL_RasterPos3dv==0) return false; 
		if (DynamicGL_RasterPos3fv==0) return false; 
		if (DynamicGL_RasterPos3iv==0) return false; 
		if (DynamicGL_RasterPos3sv==0) return false; 
		if (DynamicGL_RasterPos4dv==0) return false; 
		if (DynamicGL_RasterPos4fv==0) return false; 
		if (DynamicGL_RasterPos4iv==0) return false; 
		if (DynamicGL_RasterPos4sv==0) return false; 
		if (DynamicGL_Rectd==0) return false; 
		if (DynamicGL_Rectf==0) return false; 
		if (DynamicGL_Recti==0) return false; 
		if (DynamicGL_Rects==0) return false; 
		if (DynamicGL_Rectdv==0) return false; 
		if (DynamicGL_Rectfv==0) return false; 
		if (DynamicGL_Rectiv==0) return false; 
		if (DynamicGL_Rectsv==0) return false; 
		if (DynamicGL_ShadeModel==0) return false; 
		if (DynamicGL_Lightf==0) return false; 
		if (DynamicGL_Lighti==0) return false; 
		if (DynamicGL_Lightfv==0) return false; 
		if (DynamicGL_Lightiv==0) return false; 
		if (DynamicGL_GetLightfv==0) return false; 
		if (DynamicGL_GetLightiv==0) return false; 
		if (DynamicGL_LightModelf==0) return false; 
		if (DynamicGL_LightModeli==0) return false; 
		if (DynamicGL_LightModelfv==0) return false; 
		if (DynamicGL_LightModeliv==0) return false; 
		if (DynamicGL_Materialf==0) return false; 
		if (DynamicGL_Materiali==0) return false; 
		if (DynamicGL_Materialfv==0) return false; 
		if (DynamicGL_Materialiv==0) return false; 
		if (DynamicGL_GetMaterialfv==0) return false; 
		if (DynamicGL_GetMaterialiv==0) return false; 
		if (DynamicGL_ColorMaterial==0) return false; 
		if (DynamicGL_PixelZoom==0) return false; 
		if (DynamicGL_PixelStoref==0) return false; 
		if (DynamicGL_PixelStorei==0) return false; 
		if (DynamicGL_PixelTransferf==0) return false; 
		if (DynamicGL_PixelTransferi==0) return false; 
		if (DynamicGL_PixelMapfv==0) return false; 
		if (DynamicGL_PixelMapuiv==0) return false; 
		if (DynamicGL_PixelMapusv==0) return false; 
		if (DynamicGL_GetPixelMapfv==0) return false; 
		if (DynamicGL_GetPixelMapuiv==0) return false; 
		if (DynamicGL_GetPixelMapusv==0) return false; 
		if (DynamicGL_Bitmap==0) return false; 
		if (DynamicGL_ReadPixels==0) return false; 
		if (DynamicGL_DrawPixels==0) return false; 
		if (DynamicGL_CopyPixels==0) return false; 
		if (DynamicGL_StencilFunc==0) return false; 
		if (DynamicGL_StencilMask==0) return false; 
		if (DynamicGL_StencilOp==0) return false; 
		if (DynamicGL_ClearStencil==0) return false; 
		if (DynamicGL_TexGend==0) return false; 
		if (DynamicGL_TexGenf==0) return false; 
		if (DynamicGL_TexGeni==0) return false; 
		if (DynamicGL_TexGendv==0) return false; 
		if (DynamicGL_TexGenfv==0) return false; 
		if (DynamicGL_TexGeniv==0) return false; 
		if (DynamicGL_GetTexGendv==0) return false; 
		if (DynamicGL_GetTexGenfv==0) return false; 
		if (DynamicGL_GetTexGeniv==0) return false; 
		if (DynamicGL_TexEnvf==0) return false; 
		if (DynamicGL_TexEnvi==0) return false; 
		if (DynamicGL_TexEnvfv==0) return false; 
		if (DynamicGL_TexEnviv==0) return false; 
		if (DynamicGL_GetTexEnvfv==0) return false; 
		if (DynamicGL_GetTexEnviv==0) return false; 
		if (DynamicGL_TexParameterf==0) return false; 
		if (DynamicGL_TexParameteri==0) return false; 
		if (DynamicGL_TexParameterfv==0) return false; 
		if (DynamicGL_TexParameteriv==0) return false; 
		if (DynamicGL_GetTexParameterfv==0) return false; 
		if (DynamicGL_GetTexParameteriv==0) return false; 
		if (DynamicGL_GetTexLevelParameterfv==0) return false; 
		if (DynamicGL_GetTexLevelParameteriv==0) return false; 
		if (DynamicGL_TexImage1D==0) return false; 
		if (DynamicGL_TexImage2D==0) return false; 
		if (DynamicGL_GetTexImage==0) return false; 
		if (DynamicGL_Map1d==0) return false; 
		if (DynamicGL_Map1f==0) return false; 
		if (DynamicGL_Map2d==0) return false; 
		if (DynamicGL_Map2f==0) return false; 
		if (DynamicGL_GetMapdv==0) return false; 
		if (DynamicGL_GetMapfv==0) return false; 
		if (DynamicGL_GetMapiv==0) return false; 
		if (DynamicGL_EvalCoord1d==0) return false; 
		if (DynamicGL_EvalCoord1f==0) return false; 
		if (DynamicGL_EvalCoord1dv==0) return false; 
		if (DynamicGL_EvalCoord1fv==0) return false; 
		if (DynamicGL_EvalCoord2d==0) return false; 
		if (DynamicGL_EvalCoord2f==0) return false; 
		if (DynamicGL_EvalCoord2dv==0) return false; 
		if (DynamicGL_EvalCoord2fv==0) return false; 
		if (DynamicGL_MapGrid1d==0) return false; 
		if (DynamicGL_MapGrid1f==0) return false; 
		if (DynamicGL_MapGrid2d==0) return false; 
		if (DynamicGL_MapGrid2f==0) return false; 
		if (DynamicGL_EvalPoint1==0) return false; 
		if (DynamicGL_EvalPoint2==0) return false; 
		if (DynamicGL_EvalMesh1==0) return false; 
		if (DynamicGL_EvalMesh2==0) return false; 
		if (DynamicGL_Fogf==0) return false; 
		if (DynamicGL_Fogi==0) return false; 
		if (DynamicGL_Fogfv==0) return false; 
		if (DynamicGL_Fogiv==0) return false; 
		if (DynamicGL_FeedbackBuffer==0) return false; 
		if (DynamicGL_PassThrough==0) return false; 
		if (DynamicGL_SelectBuffer==0) return false; 
		if (DynamicGL_InitNames==0) return false; 
		if (DynamicGL_LoadName==0) return false; 
		if (DynamicGL_PushName==0) return false; 
		if (DynamicGL_PopName==0) return false; 
		if (DynamicGL_GenTextures==0) return false; 
		if (DynamicGL_DeleteTextures==0) return false; 
		if (DynamicGL_BindTexture==0) return false; 
		if (DynamicGL_PrioritizeTextures==0) return false; 
		if (DynamicGL_AreTexturesResident==0) return false; 
		if (DynamicGL_IsTexture==0) return false; 
		if (DynamicGL_TexSubImage1D==0) return false; 
		if (DynamicGL_TexSubImage2D==0) return false; 
		if (DynamicGL_CopyTexImage1D==0) return false; 
		if (DynamicGL_CopyTexImage2D==0) return false; 
		if (DynamicGL_CopyTexSubImage1D==0) return false; 
		if (DynamicGL_CopyTexSubImage2D==0) return false; 
		if (DynamicGL_VertexPointer==0) return false; 
		if (DynamicGL_NormalPointer==0) return false; 
		if (DynamicGL_ColorPointer==0) return false; 
		if (DynamicGL_IndexPointer==0) return false; 
		if (DynamicGL_TexCoordPointer==0) return false; 
		if (DynamicGL_EdgeFlagPointer==0) return false; 
		if (DynamicGL_GetPointerv==0) return false; 
		if (DynamicGL_ArrayElement==0) return false; 
		if (DynamicGL_DrawArrays==0) return false; 
		if (DynamicGL_DrawElements==0) return false; 
		if (DynamicGL_InterleavedArrays==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_VERSION_1_1*/

/*SGIS_sharpen_texture*/
#ifdef USE_DYNAMIC_GL_SGIS_sharpen_texture
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SharpenTexFuncSGIS)(GLenum target , GLsizei n , const GLfloat *points) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetSharpenTexFuncSGIS)(GLenum target , GLfloat *points) = 0; }
static bool DinamicGLFeature_SGIS_sharpen_texture_loaded = false; 
static void InitDinamicGLFeature_SGIS_sharpen_texture() {
		DynamicGL_SharpenTexFuncSGIS = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLsizei n , const GLfloat *points)>("glSharpenTexFuncSGIS"); 
		DynamicGL_GetSharpenTexFuncSGIS = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLfloat *points)>("glGetSharpenTexFuncSGIS"); 
		DinamicGLFeature_SGIS_sharpen_texture_loaded = true; 
}
bool DinamicGLFeature_SGIS_sharpen_texture_Supported() {
		if (!DinamicGLFeature_SGIS_sharpen_texture_loaded) {
			InitDinamicGLFeature_SGIS_sharpen_texture();
		}
		if (DynamicGL_SharpenTexFuncSGIS==0) return false; 
		if (DynamicGL_GetSharpenTexFuncSGIS==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIS_sharpen_texture*/

/*SGIX_blend_alpha_minmax*/
#ifdef USE_DYNAMIC_GL_SGIX_blend_alpha_minmax
static bool DinamicGLFeature_SGIX_blend_alpha_minmax_loaded = false; 
static void InitDinamicGLFeature_SGIX_blend_alpha_minmax() {
		DinamicGLFeature_SGIX_blend_alpha_minmax_loaded = true; 
}
bool DinamicGLFeature_SGIX_blend_alpha_minmax_Supported() {
		if (!DinamicGLFeature_SGIX_blend_alpha_minmax_loaded) {
			InitDinamicGLFeature_SGIX_blend_alpha_minmax();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_blend_alpha_minmax*/

/*NV_present_video*/
#ifdef USE_DYNAMIC_GL_NV_present_video
static bool DinamicGLFeature_NV_present_video_loaded = false; 
static void InitDinamicGLFeature_NV_present_video() {
		DinamicGLFeature_NV_present_video_loaded = true; 
}
bool DinamicGLFeature_NV_present_video_Supported() {
		if (!DinamicGLFeature_NV_present_video_loaded) {
			InitDinamicGLFeature_NV_present_video();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_present_video*/

/*SGIX_convolution_accuracy*/
#ifdef USE_DYNAMIC_GL_SGIX_convolution_accuracy
static bool DinamicGLFeature_SGIX_convolution_accuracy_loaded = false; 
static void InitDinamicGLFeature_SGIX_convolution_accuracy() {
		DinamicGLFeature_SGIX_convolution_accuracy_loaded = true; 
}
bool DinamicGLFeature_SGIX_convolution_accuracy_Supported() {
		if (!DinamicGLFeature_SGIX_convolution_accuracy_loaded) {
			InitDinamicGLFeature_SGIX_convolution_accuracy();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_convolution_accuracy*/

/*EXT_bindable_uniform*/
#ifdef USE_DYNAMIC_GL_EXT_bindable_uniform
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformBufferEXT)(GLuint program , GLint location , GLuint buffer) = 0; }
extern "C" { GLint (DYNAMIC_GL_APIENTRYP DynamicGL_GetUniformBufferSizeEXT)(GLuint program , GLint location) = 0; }
extern "C" { GLintptr (DYNAMIC_GL_APIENTRYP DynamicGL_GetUniformOffsetEXT)(GLuint program , GLint location) = 0; }
static bool DinamicGLFeature_EXT_bindable_uniform_loaded = false; 
static void InitDinamicGLFeature_EXT_bindable_uniform() {
		DynamicGL_UniformBufferEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLuint buffer)>("glUniformBufferEXT"); 
		DynamicGL_GetUniformBufferSizeEXT = DynamicGL_LoadFunction<GLint (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location)>("glGetUniformBufferSizeEXT"); 
		DynamicGL_GetUniformOffsetEXT = DynamicGL_LoadFunction<GLintptr (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location)>("glGetUniformOffsetEXT"); 
		DinamicGLFeature_EXT_bindable_uniform_loaded = true; 
}
bool DinamicGLFeature_EXT_bindable_uniform_Supported() {
		if (!DinamicGLFeature_EXT_bindable_uniform_loaded) {
			InitDinamicGLFeature_EXT_bindable_uniform();
		}
		if (DynamicGL_UniformBufferEXT==0) return false; 
		if (DynamicGL_GetUniformBufferSizeEXT==0) return false; 
		if (DynamicGL_GetUniformOffsetEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_bindable_uniform*/

/*SGIS_generate_mipmap*/
#ifdef USE_DYNAMIC_GL_SGIS_generate_mipmap
static bool DinamicGLFeature_SGIS_generate_mipmap_loaded = false; 
static void InitDinamicGLFeature_SGIS_generate_mipmap() {
		DinamicGLFeature_SGIS_generate_mipmap_loaded = true; 
}
bool DinamicGLFeature_SGIS_generate_mipmap_Supported() {
		if (!DinamicGLFeature_SGIS_generate_mipmap_loaded) {
			InitDinamicGLFeature_SGIS_generate_mipmap();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIS_generate_mipmap*/

/*INTEL_parallel_arrays*/
#ifdef USE_DYNAMIC_GL_INTEL_parallel_arrays
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexPointervINTEL)(GLint size , GLenum type , const GLvoid* *pointer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NormalPointervINTEL)(GLenum type , const GLvoid* *pointer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorPointervINTEL)(GLint size , GLenum type , const GLvoid* *pointer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoordPointervINTEL)(GLint size , GLenum type , const GLvoid* *pointer) = 0; }
static bool DinamicGLFeature_INTEL_parallel_arrays_loaded = false; 
static void InitDinamicGLFeature_INTEL_parallel_arrays() {
		DynamicGL_VertexPointervINTEL = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint size , GLenum type , const GLvoid* *pointer)>("glVertexPointervINTEL"); 
		DynamicGL_NormalPointervINTEL = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum type , const GLvoid* *pointer)>("glNormalPointervINTEL"); 
		DynamicGL_ColorPointervINTEL = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint size , GLenum type , const GLvoid* *pointer)>("glColorPointervINTEL"); 
		DynamicGL_TexCoordPointervINTEL = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint size , GLenum type , const GLvoid* *pointer)>("glTexCoordPointervINTEL"); 
		DinamicGLFeature_INTEL_parallel_arrays_loaded = true; 
}
bool DinamicGLFeature_INTEL_parallel_arrays_Supported() {
		if (!DinamicGLFeature_INTEL_parallel_arrays_loaded) {
			InitDinamicGLFeature_INTEL_parallel_arrays();
		}
		if (DynamicGL_VertexPointervINTEL==0) return false; 
		if (DynamicGL_NormalPointervINTEL==0) return false; 
		if (DynamicGL_ColorPointervINTEL==0) return false; 
		if (DynamicGL_TexCoordPointervINTEL==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_INTEL_parallel_arrays*/

/*ARB_multitexture*/
#ifdef USE_DYNAMIC_GL_ARB_multitexture
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ActiveTextureARB)(GLenum texture) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ClientActiveTextureARB)(GLenum texture) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1dARB)(GLenum target , GLdouble s) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1dvARB)(GLenum target , const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1fARB)(GLenum target , GLfloat s) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1fvARB)(GLenum target , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1iARB)(GLenum target , GLint s) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1ivARB)(GLenum target , const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1sARB)(GLenum target , GLshort s) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1svARB)(GLenum target , const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2dARB)(GLenum target , GLdouble s , GLdouble t) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2dvARB)(GLenum target , const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2fARB)(GLenum target , GLfloat s , GLfloat t) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2fvARB)(GLenum target , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2iARB)(GLenum target , GLint s , GLint t) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2ivARB)(GLenum target , const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2sARB)(GLenum target , GLshort s , GLshort t) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2svARB)(GLenum target , const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3dARB)(GLenum target , GLdouble s , GLdouble t , GLdouble r) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3dvARB)(GLenum target , const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3fARB)(GLenum target , GLfloat s , GLfloat t , GLfloat r) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3fvARB)(GLenum target , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3iARB)(GLenum target , GLint s , GLint t , GLint r) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3ivARB)(GLenum target , const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3sARB)(GLenum target , GLshort s , GLshort t , GLshort r) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3svARB)(GLenum target , const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4dARB)(GLenum target , GLdouble s , GLdouble t , GLdouble r , GLdouble q) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4dvARB)(GLenum target , const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4fARB)(GLenum target , GLfloat s , GLfloat t , GLfloat r , GLfloat q) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4fvARB)(GLenum target , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4iARB)(GLenum target , GLint s , GLint t , GLint r , GLint q) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4ivARB)(GLenum target , const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4sARB)(GLenum target , GLshort s , GLshort t , GLshort r , GLshort q) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4svARB)(GLenum target , const GLshort *v) = 0; }
static bool DinamicGLFeature_ARB_multitexture_loaded = false; 
static void InitDinamicGLFeature_ARB_multitexture() {
		DynamicGL_ActiveTextureARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texture)>("glActiveTextureARB"); 
		DynamicGL_ClientActiveTextureARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texture)>("glClientActiveTextureARB"); 
		DynamicGL_MultiTexCoord1dARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLdouble s)>("glMultiTexCoord1dARB"); 
		DynamicGL_MultiTexCoord1dvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLdouble *v)>("glMultiTexCoord1dvARB"); 
		DynamicGL_MultiTexCoord1fARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLfloat s)>("glMultiTexCoord1fARB"); 
		DynamicGL_MultiTexCoord1fvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLfloat *v)>("glMultiTexCoord1fvARB"); 
		DynamicGL_MultiTexCoord1iARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint s)>("glMultiTexCoord1iARB"); 
		DynamicGL_MultiTexCoord1ivARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLint *v)>("glMultiTexCoord1ivARB"); 
		DynamicGL_MultiTexCoord1sARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLshort s)>("glMultiTexCoord1sARB"); 
		DynamicGL_MultiTexCoord1svARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLshort *v)>("glMultiTexCoord1svARB"); 
		DynamicGL_MultiTexCoord2dARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLdouble s , GLdouble t)>("glMultiTexCoord2dARB"); 
		DynamicGL_MultiTexCoord2dvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLdouble *v)>("glMultiTexCoord2dvARB"); 
		DynamicGL_MultiTexCoord2fARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLfloat s , GLfloat t)>("glMultiTexCoord2fARB"); 
		DynamicGL_MultiTexCoord2fvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLfloat *v)>("glMultiTexCoord2fvARB"); 
		DynamicGL_MultiTexCoord2iARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint s , GLint t)>("glMultiTexCoord2iARB"); 
		DynamicGL_MultiTexCoord2ivARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLint *v)>("glMultiTexCoord2ivARB"); 
		DynamicGL_MultiTexCoord2sARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLshort s , GLshort t)>("glMultiTexCoord2sARB"); 
		DynamicGL_MultiTexCoord2svARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLshort *v)>("glMultiTexCoord2svARB"); 
		DynamicGL_MultiTexCoord3dARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLdouble s , GLdouble t , GLdouble r)>("glMultiTexCoord3dARB"); 
		DynamicGL_MultiTexCoord3dvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLdouble *v)>("glMultiTexCoord3dvARB"); 
		DynamicGL_MultiTexCoord3fARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLfloat s , GLfloat t , GLfloat r)>("glMultiTexCoord3fARB"); 
		DynamicGL_MultiTexCoord3fvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLfloat *v)>("glMultiTexCoord3fvARB"); 
		DynamicGL_MultiTexCoord3iARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint s , GLint t , GLint r)>("glMultiTexCoord3iARB"); 
		DynamicGL_MultiTexCoord3ivARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLint *v)>("glMultiTexCoord3ivARB"); 
		DynamicGL_MultiTexCoord3sARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLshort s , GLshort t , GLshort r)>("glMultiTexCoord3sARB"); 
		DynamicGL_MultiTexCoord3svARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLshort *v)>("glMultiTexCoord3svARB"); 
		DynamicGL_MultiTexCoord4dARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLdouble s , GLdouble t , GLdouble r , GLdouble q)>("glMultiTexCoord4dARB"); 
		DynamicGL_MultiTexCoord4dvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLdouble *v)>("glMultiTexCoord4dvARB"); 
		DynamicGL_MultiTexCoord4fARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLfloat s , GLfloat t , GLfloat r , GLfloat q)>("glMultiTexCoord4fARB"); 
		DynamicGL_MultiTexCoord4fvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLfloat *v)>("glMultiTexCoord4fvARB"); 
		DynamicGL_MultiTexCoord4iARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint s , GLint t , GLint r , GLint q)>("glMultiTexCoord4iARB"); 
		DynamicGL_MultiTexCoord4ivARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLint *v)>("glMultiTexCoord4ivARB"); 
		DynamicGL_MultiTexCoord4sARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLshort s , GLshort t , GLshort r , GLshort q)>("glMultiTexCoord4sARB"); 
		DynamicGL_MultiTexCoord4svARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLshort *v)>("glMultiTexCoord4svARB"); 
		DinamicGLFeature_ARB_multitexture_loaded = true; 
}
bool DinamicGLFeature_ARB_multitexture_Supported() {
		if (!DinamicGLFeature_ARB_multitexture_loaded) {
			InitDinamicGLFeature_ARB_multitexture();
		}
		if (DynamicGL_ActiveTextureARB==0) return false; 
		if (DynamicGL_ClientActiveTextureARB==0) return false; 
		if (DynamicGL_MultiTexCoord1dARB==0) return false; 
		if (DynamicGL_MultiTexCoord1dvARB==0) return false; 
		if (DynamicGL_MultiTexCoord1fARB==0) return false; 
		if (DynamicGL_MultiTexCoord1fvARB==0) return false; 
		if (DynamicGL_MultiTexCoord1iARB==0) return false; 
		if (DynamicGL_MultiTexCoord1ivARB==0) return false; 
		if (DynamicGL_MultiTexCoord1sARB==0) return false; 
		if (DynamicGL_MultiTexCoord1svARB==0) return false; 
		if (DynamicGL_MultiTexCoord2dARB==0) return false; 
		if (DynamicGL_MultiTexCoord2dvARB==0) return false; 
		if (DynamicGL_MultiTexCoord2fARB==0) return false; 
		if (DynamicGL_MultiTexCoord2fvARB==0) return false; 
		if (DynamicGL_MultiTexCoord2iARB==0) return false; 
		if (DynamicGL_MultiTexCoord2ivARB==0) return false; 
		if (DynamicGL_MultiTexCoord2sARB==0) return false; 
		if (DynamicGL_MultiTexCoord2svARB==0) return false; 
		if (DynamicGL_MultiTexCoord3dARB==0) return false; 
		if (DynamicGL_MultiTexCoord3dvARB==0) return false; 
		if (DynamicGL_MultiTexCoord3fARB==0) return false; 
		if (DynamicGL_MultiTexCoord3fvARB==0) return false; 
		if (DynamicGL_MultiTexCoord3iARB==0) return false; 
		if (DynamicGL_MultiTexCoord3ivARB==0) return false; 
		if (DynamicGL_MultiTexCoord3sARB==0) return false; 
		if (DynamicGL_MultiTexCoord3svARB==0) return false; 
		if (DynamicGL_MultiTexCoord4dARB==0) return false; 
		if (DynamicGL_MultiTexCoord4dvARB==0) return false; 
		if (DynamicGL_MultiTexCoord4fARB==0) return false; 
		if (DynamicGL_MultiTexCoord4fvARB==0) return false; 
		if (DynamicGL_MultiTexCoord4iARB==0) return false; 
		if (DynamicGL_MultiTexCoord4ivARB==0) return false; 
		if (DynamicGL_MultiTexCoord4sARB==0) return false; 
		if (DynamicGL_MultiTexCoord4svARB==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_multitexture*/

/*EXT_draw_range_elements*/
#ifdef USE_DYNAMIC_GL_EXT_draw_range_elements
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawRangeElementsEXT)(GLenum mode , GLuint start , GLuint end , GLsizei count , GLenum type , const GLvoid *indices) = 0; }
static bool DinamicGLFeature_EXT_draw_range_elements_loaded = false; 
static void InitDinamicGLFeature_EXT_draw_range_elements() {
		DynamicGL_DrawRangeElementsEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , GLuint start , GLuint end , GLsizei count , GLenum type , const GLvoid *indices)>("glDrawRangeElementsEXT"); 
		DinamicGLFeature_EXT_draw_range_elements_loaded = true; 
}
bool DinamicGLFeature_EXT_draw_range_elements_Supported() {
		if (!DinamicGLFeature_EXT_draw_range_elements_loaded) {
			InitDinamicGLFeature_EXT_draw_range_elements();
		}
		if (DynamicGL_DrawRangeElementsEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_draw_range_elements*/

/*NV_evaluators*/
#ifdef USE_DYNAMIC_GL_NV_evaluators
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MapControlPointsNV)(GLenum target , GLuint index , GLenum type , GLsizei ustride , GLsizei vstride , GLint uorder , GLint vorder , GLboolean packed , const GLvoid *points) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MapParameterivNV)(GLenum target , GLenum pname , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MapParameterfvNV)(GLenum target , GLenum pname , const GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMapControlPointsNV)(GLenum target , GLuint index , GLenum type , GLsizei ustride , GLsizei vstride , GLboolean packed , GLvoid *points) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMapParameterivNV)(GLenum target , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMapParameterfvNV)(GLenum target , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMapAttribParameterivNV)(GLenum target , GLuint index , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMapAttribParameterfvNV)(GLenum target , GLuint index , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EvalMapsNV)(GLenum target , GLenum mode) = 0; }
static bool DinamicGLFeature_NV_evaluators_loaded = false; 
static void InitDinamicGLFeature_NV_evaluators() {
		DynamicGL_MapControlPointsNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLenum type , GLsizei ustride , GLsizei vstride , GLint uorder , GLint vorder , GLboolean packed , const GLvoid *points)>("glMapControlPointsNV"); 
		DynamicGL_MapParameterivNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , const GLint *params)>("glMapParameterivNV"); 
		DynamicGL_MapParameterfvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , const GLfloat *params)>("glMapParameterfvNV"); 
		DynamicGL_GetMapControlPointsNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLenum type , GLsizei ustride , GLsizei vstride , GLboolean packed , GLvoid *points)>("glGetMapControlPointsNV"); 
		DynamicGL_GetMapParameterivNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint *params)>("glGetMapParameterivNV"); 
		DynamicGL_GetMapParameterfvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLfloat *params)>("glGetMapParameterfvNV"); 
		DynamicGL_GetMapAttribParameterivNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLenum pname , GLint *params)>("glGetMapAttribParameterivNV"); 
		DynamicGL_GetMapAttribParameterfvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLenum pname , GLfloat *params)>("glGetMapAttribParameterfvNV"); 
		DynamicGL_EvalMapsNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum mode)>("glEvalMapsNV"); 
		DinamicGLFeature_NV_evaluators_loaded = true; 
}
bool DinamicGLFeature_NV_evaluators_Supported() {
		if (!DinamicGLFeature_NV_evaluators_loaded) {
			InitDinamicGLFeature_NV_evaluators();
		}
		if (DynamicGL_MapControlPointsNV==0) return false; 
		if (DynamicGL_MapParameterivNV==0) return false; 
		if (DynamicGL_MapParameterfvNV==0) return false; 
		if (DynamicGL_GetMapControlPointsNV==0) return false; 
		if (DynamicGL_GetMapParameterivNV==0) return false; 
		if (DynamicGL_GetMapParameterfvNV==0) return false; 
		if (DynamicGL_GetMapAttribParameterivNV==0) return false; 
		if (DynamicGL_GetMapAttribParameterfvNV==0) return false; 
		if (DynamicGL_EvalMapsNV==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_evaluators*/

/*OML_interlace*/
#ifdef USE_DYNAMIC_GL_OML_interlace
static bool DinamicGLFeature_OML_interlace_loaded = false; 
static void InitDinamicGLFeature_OML_interlace() {
		DinamicGLFeature_OML_interlace_loaded = true; 
}
bool DinamicGLFeature_OML_interlace_Supported() {
		if (!DinamicGLFeature_OML_interlace_loaded) {
			InitDinamicGLFeature_OML_interlace();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_OML_interlace*/

/*ARB_texture_border_clamp*/
#ifdef USE_DYNAMIC_GL_ARB_texture_border_clamp
static bool DinamicGLFeature_ARB_texture_border_clamp_loaded = false; 
static void InitDinamicGLFeature_ARB_texture_border_clamp() {
		DinamicGLFeature_ARB_texture_border_clamp_loaded = true; 
}
bool DinamicGLFeature_ARB_texture_border_clamp_Supported() {
		if (!DinamicGLFeature_ARB_texture_border_clamp_loaded) {
			InitDinamicGLFeature_ARB_texture_border_clamp();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_texture_border_clamp*/

/*ARB_shadow_ambient*/
#ifdef USE_DYNAMIC_GL_ARB_shadow_ambient
static bool DinamicGLFeature_ARB_shadow_ambient_loaded = false; 
static void InitDinamicGLFeature_ARB_shadow_ambient() {
		DinamicGLFeature_ARB_shadow_ambient_loaded = true; 
}
bool DinamicGLFeature_ARB_shadow_ambient_Supported() {
		if (!DinamicGLFeature_ARB_shadow_ambient_loaded) {
			InitDinamicGLFeature_ARB_shadow_ambient();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_shadow_ambient*/

/*EXT_texture_compression_s3tc*/
#ifdef USE_DYNAMIC_GL_EXT_texture_compression_s3tc
static bool DinamicGLFeature_EXT_texture_compression_s3tc_loaded = false; 
static void InitDinamicGLFeature_EXT_texture_compression_s3tc() {
		DinamicGLFeature_EXT_texture_compression_s3tc_loaded = true; 
}
bool DinamicGLFeature_EXT_texture_compression_s3tc_Supported() {
		if (!DinamicGLFeature_EXT_texture_compression_s3tc_loaded) {
			InitDinamicGLFeature_EXT_texture_compression_s3tc();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_texture_compression_s3tc*/

/*EXT_secondary_color*/
#ifdef USE_DYNAMIC_GL_EXT_secondary_color
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3bEXT)(GLbyte red , GLbyte green , GLbyte blue) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3bvEXT)(const GLbyte *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3dEXT)(GLdouble red , GLdouble green , GLdouble blue) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3dvEXT)(const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3fEXT)(GLfloat red , GLfloat green , GLfloat blue) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3fvEXT)(const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3iEXT)(GLint red , GLint green , GLint blue) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3ivEXT)(const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3sEXT)(GLshort red , GLshort green , GLshort blue) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3svEXT)(const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3ubEXT)(GLubyte red , GLubyte green , GLubyte blue) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3ubvEXT)(const GLubyte *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3uiEXT)(GLuint red , GLuint green , GLuint blue) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3uivEXT)(const GLuint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3usEXT)(GLushort red , GLushort green , GLushort blue) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3usvEXT)(const GLushort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColorPointerEXT)(GLint size , GLenum type , GLsizei stride , const GLvoid *pointer) = 0; }
static bool DinamicGLFeature_EXT_secondary_color_loaded = false; 
static void InitDinamicGLFeature_EXT_secondary_color() {
		DynamicGL_SecondaryColor3bEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLbyte red , GLbyte green , GLbyte blue)>("glSecondaryColor3bEXT"); 
		DynamicGL_SecondaryColor3bvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLbyte *v)>("glSecondaryColor3bvEXT"); 
		DynamicGL_SecondaryColor3dEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble red , GLdouble green , GLdouble blue)>("glSecondaryColor3dEXT"); 
		DynamicGL_SecondaryColor3dvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *v)>("glSecondaryColor3dvEXT"); 
		DynamicGL_SecondaryColor3fEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat red , GLfloat green , GLfloat blue)>("glSecondaryColor3fEXT"); 
		DynamicGL_SecondaryColor3fvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *v)>("glSecondaryColor3fvEXT"); 
		DynamicGL_SecondaryColor3iEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint red , GLint green , GLint blue)>("glSecondaryColor3iEXT"); 
		DynamicGL_SecondaryColor3ivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLint *v)>("glSecondaryColor3ivEXT"); 
		DynamicGL_SecondaryColor3sEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLshort red , GLshort green , GLshort blue)>("glSecondaryColor3sEXT"); 
		DynamicGL_SecondaryColor3svEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLshort *v)>("glSecondaryColor3svEXT"); 
		DynamicGL_SecondaryColor3ubEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLubyte red , GLubyte green , GLubyte blue)>("glSecondaryColor3ubEXT"); 
		DynamicGL_SecondaryColor3ubvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLubyte *v)>("glSecondaryColor3ubvEXT"); 
		DynamicGL_SecondaryColor3uiEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint red , GLuint green , GLuint blue)>("glSecondaryColor3uiEXT"); 
		DynamicGL_SecondaryColor3uivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLuint *v)>("glSecondaryColor3uivEXT"); 
		DynamicGL_SecondaryColor3usEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLushort red , GLushort green , GLushort blue)>("glSecondaryColor3usEXT"); 
		DynamicGL_SecondaryColor3usvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLushort *v)>("glSecondaryColor3usvEXT"); 
		DynamicGL_SecondaryColorPointerEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint size , GLenum type , GLsizei stride , const GLvoid *pointer)>("glSecondaryColorPointerEXT"); 
		DinamicGLFeature_EXT_secondary_color_loaded = true; 
}
bool DinamicGLFeature_EXT_secondary_color_Supported() {
		if (!DinamicGLFeature_EXT_secondary_color_loaded) {
			InitDinamicGLFeature_EXT_secondary_color();
		}
		if (DynamicGL_SecondaryColor3bEXT==0) return false; 
		if (DynamicGL_SecondaryColor3bvEXT==0) return false; 
		if (DynamicGL_SecondaryColor3dEXT==0) return false; 
		if (DynamicGL_SecondaryColor3dvEXT==0) return false; 
		if (DynamicGL_SecondaryColor3fEXT==0) return false; 
		if (DynamicGL_SecondaryColor3fvEXT==0) return false; 
		if (DynamicGL_SecondaryColor3iEXT==0) return false; 
		if (DynamicGL_SecondaryColor3ivEXT==0) return false; 
		if (DynamicGL_SecondaryColor3sEXT==0) return false; 
		if (DynamicGL_SecondaryColor3svEXT==0) return false; 
		if (DynamicGL_SecondaryColor3ubEXT==0) return false; 
		if (DynamicGL_SecondaryColor3ubvEXT==0) return false; 
		if (DynamicGL_SecondaryColor3uiEXT==0) return false; 
		if (DynamicGL_SecondaryColor3uivEXT==0) return false; 
		if (DynamicGL_SecondaryColor3usEXT==0) return false; 
		if (DynamicGL_SecondaryColor3usvEXT==0) return false; 
		if (DynamicGL_SecondaryColorPointerEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_secondary_color*/

/*SGIX_pixel_tiles*/
#ifdef USE_DYNAMIC_GL_SGIX_pixel_tiles
static bool DinamicGLFeature_SGIX_pixel_tiles_loaded = false; 
static void InitDinamicGLFeature_SGIX_pixel_tiles() {
		DinamicGLFeature_SGIX_pixel_tiles_loaded = true; 
}
bool DinamicGLFeature_SGIX_pixel_tiles_Supported() {
		if (!DinamicGLFeature_SGIX_pixel_tiles_loaded) {
			InitDinamicGLFeature_SGIX_pixel_tiles();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_pixel_tiles*/

/*SGIX_scalebias_hint*/
#ifdef USE_DYNAMIC_GL_SGIX_scalebias_hint
static bool DinamicGLFeature_SGIX_scalebias_hint_loaded = false; 
static void InitDinamicGLFeature_SGIX_scalebias_hint() {
		DinamicGLFeature_SGIX_scalebias_hint_loaded = true; 
}
bool DinamicGLFeature_SGIX_scalebias_hint_Supported() {
		if (!DinamicGLFeature_SGIX_scalebias_hint_loaded) {
			InitDinamicGLFeature_SGIX_scalebias_hint();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_scalebias_hint*/

/*EXT_texture_buffer_object*/
#ifdef USE_DYNAMIC_GL_EXT_texture_buffer_object
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexBufferEXT)(GLenum target , GLenum internalformat , GLuint buffer) = 0; }
static bool DinamicGLFeature_EXT_texture_buffer_object_loaded = false; 
static void InitDinamicGLFeature_EXT_texture_buffer_object() {
		DynamicGL_TexBufferEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum internalformat , GLuint buffer)>("glTexBufferEXT"); 
		DinamicGLFeature_EXT_texture_buffer_object_loaded = true; 
}
bool DinamicGLFeature_EXT_texture_buffer_object_Supported() {
		if (!DinamicGLFeature_EXT_texture_buffer_object_loaded) {
			InitDinamicGLFeature_EXT_texture_buffer_object();
		}
		if (DynamicGL_TexBufferEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_texture_buffer_object*/

/*IBM_multimode_draw_arrays*/
#ifdef USE_DYNAMIC_GL_IBM_multimode_draw_arrays
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiModeDrawArraysIBM)(const GLenum *mode , const GLint *first , const GLsizei *count , GLsizei primcount , GLint modestride) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiModeDrawElementsIBM)(const GLenum *mode , const GLsizei *count , GLenum type , const GLvoid* const , GLsizei primcount , GLint modestride) = 0; }
static bool DinamicGLFeature_IBM_multimode_draw_arrays_loaded = false; 
static void InitDinamicGLFeature_IBM_multimode_draw_arrays() {
		DynamicGL_MultiModeDrawArraysIBM = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLenum *mode , const GLint *first , const GLsizei *count , GLsizei primcount , GLint modestride)>("glMultiModeDrawArraysIBM"); 
		DynamicGL_MultiModeDrawElementsIBM = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLenum *mode , const GLsizei *count , GLenum type , const GLvoid* const , GLsizei primcount , GLint modestride)>("glMultiModeDrawElementsIBM"); 
		DinamicGLFeature_IBM_multimode_draw_arrays_loaded = true; 
}
bool DinamicGLFeature_IBM_multimode_draw_arrays_Supported() {
		if (!DinamicGLFeature_IBM_multimode_draw_arrays_loaded) {
			InitDinamicGLFeature_IBM_multimode_draw_arrays();
		}
		if (DynamicGL_MultiModeDrawArraysIBM==0) return false; 
		if (DynamicGL_MultiModeDrawElementsIBM==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_IBM_multimode_draw_arrays*/

/*EXT_framebuffer_object*/
#ifdef USE_DYNAMIC_GL_EXT_framebuffer_object
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsRenderbufferEXT)(GLuint renderbuffer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BindRenderbufferEXT)(GLenum target , GLuint renderbuffer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteRenderbuffersEXT)(GLsizei n , const GLuint *renderbuffers) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GenRenderbuffersEXT)(GLsizei n , GLuint *renderbuffers) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_RenderbufferStorageEXT)(GLenum target , GLenum internalformat , GLsizei width , GLsizei height) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetRenderbufferParameterivEXT)(GLenum target , GLenum pname , GLint *params) = 0; }
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsFramebufferEXT)(GLuint framebuffer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BindFramebufferEXT)(GLenum target , GLuint framebuffer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteFramebuffersEXT)(GLsizei n , const GLuint *framebuffers) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GenFramebuffersEXT)(GLsizei n , GLuint *framebuffers) = 0; }
extern "C" { GLenum (DYNAMIC_GL_APIENTRYP DynamicGL_CheckFramebufferStatusEXT)(GLenum target) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferTexture1DEXT)(GLenum target , GLenum attachment , GLenum textarget , GLuint texture , GLint level) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferTexture2DEXT)(GLenum target , GLenum attachment , GLenum textarget , GLuint texture , GLint level) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferTexture3DEXT)(GLenum target , GLenum attachment , GLenum textarget , GLuint texture , GLint level , GLint zoffset) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferRenderbufferEXT)(GLenum target , GLenum attachment , GLenum renderbuffertarget , GLuint renderbuffer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFramebufferAttachmentParameterivEXT)(GLenum target , GLenum attachment , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GenerateMipmapEXT)(GLenum target) = 0; }
static bool DinamicGLFeature_EXT_framebuffer_object_loaded = false; 
static void InitDinamicGLFeature_EXT_framebuffer_object() {
		DynamicGL_IsRenderbufferEXT = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLuint renderbuffer)>("glIsRenderbufferEXT"); 
		DynamicGL_BindRenderbufferEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint renderbuffer)>("glBindRenderbufferEXT"); 
		DynamicGL_DeleteRenderbuffersEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , const GLuint *renderbuffers)>("glDeleteRenderbuffersEXT"); 
		DynamicGL_GenRenderbuffersEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , GLuint *renderbuffers)>("glGenRenderbuffersEXT"); 
		DynamicGL_RenderbufferStorageEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum internalformat , GLsizei width , GLsizei height)>("glRenderbufferStorageEXT"); 
		DynamicGL_GetRenderbufferParameterivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint *params)>("glGetRenderbufferParameterivEXT"); 
		DynamicGL_IsFramebufferEXT = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLuint framebuffer)>("glIsFramebufferEXT"); 
		DynamicGL_BindFramebufferEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint framebuffer)>("glBindFramebufferEXT"); 
		DynamicGL_DeleteFramebuffersEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , const GLuint *framebuffers)>("glDeleteFramebuffersEXT"); 
		DynamicGL_GenFramebuffersEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , GLuint *framebuffers)>("glGenFramebuffersEXT"); 
		DynamicGL_CheckFramebufferStatusEXT = DynamicGL_LoadFunction<GLenum (DYNAMIC_GL_APIENTRYP)(GLenum target)>("glCheckFramebufferStatusEXT"); 
		DynamicGL_FramebufferTexture1DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum attachment , GLenum textarget , GLuint texture , GLint level)>("glFramebufferTexture1DEXT"); 
		DynamicGL_FramebufferTexture2DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum attachment , GLenum textarget , GLuint texture , GLint level)>("glFramebufferTexture2DEXT"); 
		DynamicGL_FramebufferTexture3DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum attachment , GLenum textarget , GLuint texture , GLint level , GLint zoffset)>("glFramebufferTexture3DEXT"); 
		DynamicGL_FramebufferRenderbufferEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum attachment , GLenum renderbuffertarget , GLuint renderbuffer)>("glFramebufferRenderbufferEXT"); 
		DynamicGL_GetFramebufferAttachmentParameterivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum attachment , GLenum pname , GLint *params)>("glGetFramebufferAttachmentParameterivEXT"); 
		DynamicGL_GenerateMipmapEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target)>("glGenerateMipmapEXT"); 
		DinamicGLFeature_EXT_framebuffer_object_loaded = true; 
}
bool DinamicGLFeature_EXT_framebuffer_object_Supported() {
		if (!DinamicGLFeature_EXT_framebuffer_object_loaded) {
			InitDinamicGLFeature_EXT_framebuffer_object();
		}
		if (DynamicGL_IsRenderbufferEXT==0) return false; 
		if (DynamicGL_BindRenderbufferEXT==0) return false; 
		if (DynamicGL_DeleteRenderbuffersEXT==0) return false; 
		if (DynamicGL_GenRenderbuffersEXT==0) return false; 
		if (DynamicGL_RenderbufferStorageEXT==0) return false; 
		if (DynamicGL_GetRenderbufferParameterivEXT==0) return false; 
		if (DynamicGL_IsFramebufferEXT==0) return false; 
		if (DynamicGL_BindFramebufferEXT==0) return false; 
		if (DynamicGL_DeleteFramebuffersEXT==0) return false; 
		if (DynamicGL_GenFramebuffersEXT==0) return false; 
		if (DynamicGL_CheckFramebufferStatusEXT==0) return false; 
		if (DynamicGL_FramebufferTexture1DEXT==0) return false; 
		if (DynamicGL_FramebufferTexture2DEXT==0) return false; 
		if (DynamicGL_FramebufferTexture3DEXT==0) return false; 
		if (DynamicGL_FramebufferRenderbufferEXT==0) return false; 
		if (DynamicGL_GetFramebufferAttachmentParameterivEXT==0) return false; 
		if (DynamicGL_GenerateMipmapEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_framebuffer_object*/

/*ARB_draw_buffers*/
#ifdef USE_DYNAMIC_GL_ARB_draw_buffers
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawBuffersARB)(GLsizei n , const GLenum *bufs) = 0; }
static bool DinamicGLFeature_ARB_draw_buffers_loaded = false; 
static void InitDinamicGLFeature_ARB_draw_buffers() {
		DynamicGL_DrawBuffersARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , const GLenum *bufs)>("glDrawBuffersARB"); 
		DinamicGLFeature_ARB_draw_buffers_loaded = true; 
}
bool DinamicGLFeature_ARB_draw_buffers_Supported() {
		if (!DinamicGLFeature_ARB_draw_buffers_loaded) {
			InitDinamicGLFeature_ARB_draw_buffers();
		}
		if (DynamicGL_DrawBuffersARB==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_draw_buffers*/

/*EXT_pixel_transform*/
#ifdef USE_DYNAMIC_GL_EXT_pixel_transform
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelTransformParameteriEXT)(GLenum target , GLenum pname , GLint param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelTransformParameterfEXT)(GLenum target , GLenum pname , GLfloat param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelTransformParameterivEXT)(GLenum target , GLenum pname , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelTransformParameterfvEXT)(GLenum target , GLenum pname , const GLfloat *params) = 0; }
static bool DinamicGLFeature_EXT_pixel_transform_loaded = false; 
static void InitDinamicGLFeature_EXT_pixel_transform() {
		DynamicGL_PixelTransformParameteriEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint param)>("glPixelTransformParameteriEXT"); 
		DynamicGL_PixelTransformParameterfEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLfloat param)>("glPixelTransformParameterfEXT"); 
		DynamicGL_PixelTransformParameterivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , const GLint *params)>("glPixelTransformParameterivEXT"); 
		DynamicGL_PixelTransformParameterfvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , const GLfloat *params)>("glPixelTransformParameterfvEXT"); 
		DinamicGLFeature_EXT_pixel_transform_loaded = true; 
}
bool DinamicGLFeature_EXT_pixel_transform_Supported() {
		if (!DinamicGLFeature_EXT_pixel_transform_loaded) {
			InitDinamicGLFeature_EXT_pixel_transform();
		}
		if (DynamicGL_PixelTransformParameteriEXT==0) return false; 
		if (DynamicGL_PixelTransformParameterfEXT==0) return false; 
		if (DynamicGL_PixelTransformParameterivEXT==0) return false; 
		if (DynamicGL_PixelTransformParameterfvEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_pixel_transform*/

/*EXT_index_material*/
#ifdef USE_DYNAMIC_GL_EXT_index_material
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_IndexMaterialEXT)(GLenum face , GLenum mode) = 0; }
static bool DinamicGLFeature_EXT_index_material_loaded = false; 
static void InitDinamicGLFeature_EXT_index_material() {
		DynamicGL_IndexMaterialEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum face , GLenum mode)>("glIndexMaterialEXT"); 
		DinamicGLFeature_EXT_index_material_loaded = true; 
}
bool DinamicGLFeature_EXT_index_material_Supported() {
		if (!DinamicGLFeature_EXT_index_material_loaded) {
			InitDinamicGLFeature_EXT_index_material();
		}
		if (DynamicGL_IndexMaterialEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_index_material*/

/*SGIS_texture_filter4*/
#ifdef USE_DYNAMIC_GL_SGIS_texture_filter4
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexFilterFuncSGIS)(GLenum target , GLenum filter , GLfloat *weights) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexFilterFuncSGIS)(GLenum target , GLenum filter , GLsizei n , const GLfloat *weights) = 0; }
static bool DinamicGLFeature_SGIS_texture_filter4_loaded = false; 
static void InitDinamicGLFeature_SGIS_texture_filter4() {
		DynamicGL_GetTexFilterFuncSGIS = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum filter , GLfloat *weights)>("glGetTexFilterFuncSGIS"); 
		DynamicGL_TexFilterFuncSGIS = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum filter , GLsizei n , const GLfloat *weights)>("glTexFilterFuncSGIS"); 
		DinamicGLFeature_SGIS_texture_filter4_loaded = true; 
}
bool DinamicGLFeature_SGIS_texture_filter4_Supported() {
		if (!DinamicGLFeature_SGIS_texture_filter4_loaded) {
			InitDinamicGLFeature_SGIS_texture_filter4();
		}
		if (DynamicGL_GetTexFilterFuncSGIS==0) return false; 
		if (DynamicGL_TexFilterFuncSGIS==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIS_texture_filter4*/

/*APPLE_flush_buffer_range*/
#ifdef USE_DYNAMIC_GL_APPLE_flush_buffer_range
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BufferParameteriAPPLE)(GLenum target , GLenum pname , GLint param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FlushMappedBufferRangeAPPLE)(GLenum target , GLintptr offset , GLsizeiptr size) = 0; }
static bool DinamicGLFeature_APPLE_flush_buffer_range_loaded = false; 
static void InitDinamicGLFeature_APPLE_flush_buffer_range() {
		DynamicGL_BufferParameteriAPPLE = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint param)>("glBufferParameteriAPPLE"); 
		DynamicGL_FlushMappedBufferRangeAPPLE = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLintptr offset , GLsizeiptr size)>("glFlushMappedBufferRangeAPPLE"); 
		DinamicGLFeature_APPLE_flush_buffer_range_loaded = true; 
}
bool DinamicGLFeature_APPLE_flush_buffer_range_Supported() {
		if (!DinamicGLFeature_APPLE_flush_buffer_range_loaded) {
			InitDinamicGLFeature_APPLE_flush_buffer_range();
		}
		if (DynamicGL_BufferParameteriAPPLE==0) return false; 
		if (DynamicGL_FlushMappedBufferRangeAPPLE==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_APPLE_flush_buffer_range*/

/*SGIS_texture_color_mask*/
#ifdef USE_DYNAMIC_GL_SGIS_texture_color_mask
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureColorMaskSGIS)(GLboolean red , GLboolean green , GLboolean blue , GLboolean alpha) = 0; }
static bool DinamicGLFeature_SGIS_texture_color_mask_loaded = false; 
static void InitDinamicGLFeature_SGIS_texture_color_mask() {
		DynamicGL_TextureColorMaskSGIS = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLboolean red , GLboolean green , GLboolean blue , GLboolean alpha)>("glTextureColorMaskSGIS"); 
		DinamicGLFeature_SGIS_texture_color_mask_loaded = true; 
}
bool DinamicGLFeature_SGIS_texture_color_mask_Supported() {
		if (!DinamicGLFeature_SGIS_texture_color_mask_loaded) {
			InitDinamicGLFeature_SGIS_texture_color_mask();
		}
		if (DynamicGL_TextureColorMaskSGIS==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIS_texture_color_mask*/

/*ARB_fragment_shader*/
#ifdef USE_DYNAMIC_GL_ARB_fragment_shader
static bool DinamicGLFeature_ARB_fragment_shader_loaded = false; 
static void InitDinamicGLFeature_ARB_fragment_shader() {
		DinamicGLFeature_ARB_fragment_shader_loaded = true; 
}
bool DinamicGLFeature_ARB_fragment_shader_Supported() {
		if (!DinamicGLFeature_ARB_fragment_shader_loaded) {
			InitDinamicGLFeature_ARB_fragment_shader();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_fragment_shader*/

/*GREMEDY_frame_terminator*/
#ifdef USE_DYNAMIC_GL_GREMEDY_frame_terminator
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FrameTerminatorGREMEDY)() = 0; }
static bool DinamicGLFeature_GREMEDY_frame_terminator_loaded = false; 
static void InitDinamicGLFeature_GREMEDY_frame_terminator() {
		DynamicGL_FrameTerminatorGREMEDY = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glFrameTerminatorGREMEDY"); 
		DinamicGLFeature_GREMEDY_frame_terminator_loaded = true; 
}
bool DinamicGLFeature_GREMEDY_frame_terminator_Supported() {
		if (!DinamicGLFeature_GREMEDY_frame_terminator_loaded) {
			InitDinamicGLFeature_GREMEDY_frame_terminator();
		}
		if (DynamicGL_FrameTerminatorGREMEDY==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_GREMEDY_frame_terminator*/

/*ARB_shading_language_100*/
#ifdef USE_DYNAMIC_GL_ARB_shading_language_100
static bool DinamicGLFeature_ARB_shading_language_100_loaded = false; 
static void InitDinamicGLFeature_ARB_shading_language_100() {
		DinamicGLFeature_ARB_shading_language_100_loaded = true; 
}
bool DinamicGLFeature_ARB_shading_language_100_Supported() {
		if (!DinamicGLFeature_ARB_shading_language_100_loaded) {
			InitDinamicGLFeature_ARB_shading_language_100();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_shading_language_100*/

/*ARB_fragment_program*/
#ifdef USE_DYNAMIC_GL_ARB_fragment_program
static bool DinamicGLFeature_ARB_fragment_program_loaded = false; 
static void InitDinamicGLFeature_ARB_fragment_program() {
		DinamicGLFeature_ARB_fragment_program_loaded = true; 
}
bool DinamicGLFeature_ARB_fragment_program_Supported() {
		if (!DinamicGLFeature_ARB_fragment_program_loaded) {
			InitDinamicGLFeature_ARB_fragment_program();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_fragment_program*/

/*ARB_shader_objects*/
#ifdef USE_DYNAMIC_GL_ARB_shader_objects
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteObjectARB)(GLhandleARB obj) = 0; }
extern "C" { GLhandleARB (DYNAMIC_GL_APIENTRYP DynamicGL_GetHandleARB)(GLenum pname) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DetachObjectARB)(GLhandleARB containerObj , GLhandleARB attachedObj) = 0; }
extern "C" { GLhandleARB (DYNAMIC_GL_APIENTRYP DynamicGL_CreateShaderObjectARB)(GLenum shaderType) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ShaderSourceARB)(GLhandleARB shaderObj , GLsizei count , const GLcharARB* *string , const GLint *length) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CompileShaderARB)(GLhandleARB shaderObj) = 0; }
extern "C" { GLhandleARB (DYNAMIC_GL_APIENTRYP DynamicGL_CreateProgramObjectARB)() = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_AttachObjectARB)(GLhandleARB containerObj , GLhandleARB obj) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_LinkProgramARB)(GLhandleARB programObj) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_UseProgramObjectARB)(GLhandleARB programObj) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ValidateProgramARB)(GLhandleARB programObj) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform1fARB)(GLint location , GLfloat v0) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform2fARB)(GLint location , GLfloat v0 , GLfloat v1) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform3fARB)(GLint location , GLfloat v0 , GLfloat v1 , GLfloat v2) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform4fARB)(GLint location , GLfloat v0 , GLfloat v1 , GLfloat v2 , GLfloat v3) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform1iARB)(GLint location , GLint v0) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform2iARB)(GLint location , GLint v0 , GLint v1) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform3iARB)(GLint location , GLint v0 , GLint v1 , GLint v2) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform4iARB)(GLint location , GLint v0 , GLint v1 , GLint v2 , GLint v3) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform1fvARB)(GLint location , GLsizei count , const GLfloat *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform2fvARB)(GLint location , GLsizei count , const GLfloat *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform3fvARB)(GLint location , GLsizei count , const GLfloat *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform4fvARB)(GLint location , GLsizei count , const GLfloat *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform1ivARB)(GLint location , GLsizei count , const GLint *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform2ivARB)(GLint location , GLsizei count , const GLint *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform3ivARB)(GLint location , GLsizei count , const GLint *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform4ivARB)(GLint location , GLsizei count , const GLint *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformMatrix2fvARB)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformMatrix3fvARB)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformMatrix4fvARB)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetObjectParameterfvARB)(GLhandleARB obj , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetObjectParameterivARB)(GLhandleARB obj , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetInfoLogARB)(GLhandleARB obj , GLsizei maxLength , GLsizei *length , GLcharARB *infoLog) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetAttachedObjectsARB)(GLhandleARB containerObj , GLsizei maxCount , GLsizei *count , GLhandleARB *obj) = 0; }
extern "C" { GLint (DYNAMIC_GL_APIENTRYP DynamicGL_GetUniformLocationARB)(GLhandleARB programObj , const GLcharARB *name) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetActiveUniformARB)(GLhandleARB programObj , GLuint index , GLsizei maxLength , GLsizei *length , GLint *size , GLenum *type , GLcharARB *name) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetUniformfvARB)(GLhandleARB programObj , GLint location , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetUniformivARB)(GLhandleARB programObj , GLint location , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetShaderSourceARB)(GLhandleARB obj , GLsizei maxLength , GLsizei *length , GLcharARB *source) = 0; }
static bool DinamicGLFeature_ARB_shader_objects_loaded = false; 
static void InitDinamicGLFeature_ARB_shader_objects() {
		DynamicGL_DeleteObjectARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLhandleARB obj)>("glDeleteObjectARB"); 
		DynamicGL_GetHandleARB = DynamicGL_LoadFunction<GLhandleARB (DYNAMIC_GL_APIENTRYP)(GLenum pname)>("glGetHandleARB"); 
		DynamicGL_DetachObjectARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLhandleARB containerObj , GLhandleARB attachedObj)>("glDetachObjectARB"); 
		DynamicGL_CreateShaderObjectARB = DynamicGL_LoadFunction<GLhandleARB (DYNAMIC_GL_APIENTRYP)(GLenum shaderType)>("glCreateShaderObjectARB"); 
		DynamicGL_ShaderSourceARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLhandleARB shaderObj , GLsizei count , const GLcharARB* *string , const GLint *length)>("glShaderSourceARB"); 
		DynamicGL_CompileShaderARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLhandleARB shaderObj)>("glCompileShaderARB"); 
		DynamicGL_CreateProgramObjectARB = DynamicGL_LoadFunction<GLhandleARB (DYNAMIC_GL_APIENTRYP)()>("glCreateProgramObjectARB"); 
		DynamicGL_AttachObjectARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLhandleARB containerObj , GLhandleARB obj)>("glAttachObjectARB"); 
		DynamicGL_LinkProgramARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLhandleARB programObj)>("glLinkProgramARB"); 
		DynamicGL_UseProgramObjectARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLhandleARB programObj)>("glUseProgramObjectARB"); 
		DynamicGL_ValidateProgramARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLhandleARB programObj)>("glValidateProgramARB"); 
		DynamicGL_Uniform1fARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLfloat v0)>("glUniform1fARB"); 
		DynamicGL_Uniform2fARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLfloat v0 , GLfloat v1)>("glUniform2fARB"); 
		DynamicGL_Uniform3fARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLfloat v0 , GLfloat v1 , GLfloat v2)>("glUniform3fARB"); 
		DynamicGL_Uniform4fARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLfloat v0 , GLfloat v1 , GLfloat v2 , GLfloat v3)>("glUniform4fARB"); 
		DynamicGL_Uniform1iARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLint v0)>("glUniform1iARB"); 
		DynamicGL_Uniform2iARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLint v0 , GLint v1)>("glUniform2iARB"); 
		DynamicGL_Uniform3iARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLint v0 , GLint v1 , GLint v2)>("glUniform3iARB"); 
		DynamicGL_Uniform4iARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLint v0 , GLint v1 , GLint v2 , GLint v3)>("glUniform4iARB"); 
		DynamicGL_Uniform1fvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , const GLfloat *value)>("glUniform1fvARB"); 
		DynamicGL_Uniform2fvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , const GLfloat *value)>("glUniform2fvARB"); 
		DynamicGL_Uniform3fvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , const GLfloat *value)>("glUniform3fvARB"); 
		DynamicGL_Uniform4fvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , const GLfloat *value)>("glUniform4fvARB"); 
		DynamicGL_Uniform1ivARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , const GLint *value)>("glUniform1ivARB"); 
		DynamicGL_Uniform2ivARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , const GLint *value)>("glUniform2ivARB"); 
		DynamicGL_Uniform3ivARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , const GLint *value)>("glUniform3ivARB"); 
		DynamicGL_Uniform4ivARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , const GLint *value)>("glUniform4ivARB"); 
		DynamicGL_UniformMatrix2fvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value)>("glUniformMatrix2fvARB"); 
		DynamicGL_UniformMatrix3fvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value)>("glUniformMatrix3fvARB"); 
		DynamicGL_UniformMatrix4fvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value)>("glUniformMatrix4fvARB"); 
		DynamicGL_GetObjectParameterfvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLhandleARB obj , GLenum pname , GLfloat *params)>("glGetObjectParameterfvARB"); 
		DynamicGL_GetObjectParameterivARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLhandleARB obj , GLenum pname , GLint *params)>("glGetObjectParameterivARB"); 
		DynamicGL_GetInfoLogARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLhandleARB obj , GLsizei maxLength , GLsizei *length , GLcharARB *infoLog)>("glGetInfoLogARB"); 
		DynamicGL_GetAttachedObjectsARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLhandleARB containerObj , GLsizei maxCount , GLsizei *count , GLhandleARB *obj)>("glGetAttachedObjectsARB"); 
		DynamicGL_GetUniformLocationARB = DynamicGL_LoadFunction<GLint (DYNAMIC_GL_APIENTRYP)(GLhandleARB programObj , const GLcharARB *name)>("glGetUniformLocationARB"); 
		DynamicGL_GetActiveUniformARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLhandleARB programObj , GLuint index , GLsizei maxLength , GLsizei *length , GLint *size , GLenum *type , GLcharARB *name)>("glGetActiveUniformARB"); 
		DynamicGL_GetUniformfvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLhandleARB programObj , GLint location , GLfloat *params)>("glGetUniformfvARB"); 
		DynamicGL_GetUniformivARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLhandleARB programObj , GLint location , GLint *params)>("glGetUniformivARB"); 
		DynamicGL_GetShaderSourceARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLhandleARB obj , GLsizei maxLength , GLsizei *length , GLcharARB *source)>("glGetShaderSourceARB"); 
		DinamicGLFeature_ARB_shader_objects_loaded = true; 
}
bool DinamicGLFeature_ARB_shader_objects_Supported() {
		if (!DinamicGLFeature_ARB_shader_objects_loaded) {
			InitDinamicGLFeature_ARB_shader_objects();
		}
		if (DynamicGL_DeleteObjectARB==0) return false; 
		if (DynamicGL_GetHandleARB==0) return false; 
		if (DynamicGL_DetachObjectARB==0) return false; 
		if (DynamicGL_CreateShaderObjectARB==0) return false; 
		if (DynamicGL_ShaderSourceARB==0) return false; 
		if (DynamicGL_CompileShaderARB==0) return false; 
		if (DynamicGL_CreateProgramObjectARB==0) return false; 
		if (DynamicGL_AttachObjectARB==0) return false; 
		if (DynamicGL_LinkProgramARB==0) return false; 
		if (DynamicGL_UseProgramObjectARB==0) return false; 
		if (DynamicGL_ValidateProgramARB==0) return false; 
		if (DynamicGL_Uniform1fARB==0) return false; 
		if (DynamicGL_Uniform2fARB==0) return false; 
		if (DynamicGL_Uniform3fARB==0) return false; 
		if (DynamicGL_Uniform4fARB==0) return false; 
		if (DynamicGL_Uniform1iARB==0) return false; 
		if (DynamicGL_Uniform2iARB==0) return false; 
		if (DynamicGL_Uniform3iARB==0) return false; 
		if (DynamicGL_Uniform4iARB==0) return false; 
		if (DynamicGL_Uniform1fvARB==0) return false; 
		if (DynamicGL_Uniform2fvARB==0) return false; 
		if (DynamicGL_Uniform3fvARB==0) return false; 
		if (DynamicGL_Uniform4fvARB==0) return false; 
		if (DynamicGL_Uniform1ivARB==0) return false; 
		if (DynamicGL_Uniform2ivARB==0) return false; 
		if (DynamicGL_Uniform3ivARB==0) return false; 
		if (DynamicGL_Uniform4ivARB==0) return false; 
		if (DynamicGL_UniformMatrix2fvARB==0) return false; 
		if (DynamicGL_UniformMatrix3fvARB==0) return false; 
		if (DynamicGL_UniformMatrix4fvARB==0) return false; 
		if (DynamicGL_GetObjectParameterfvARB==0) return false; 
		if (DynamicGL_GetObjectParameterivARB==0) return false; 
		if (DynamicGL_GetInfoLogARB==0) return false; 
		if (DynamicGL_GetAttachedObjectsARB==0) return false; 
		if (DynamicGL_GetUniformLocationARB==0) return false; 
		if (DynamicGL_GetActiveUniformARB==0) return false; 
		if (DynamicGL_GetUniformfvARB==0) return false; 
		if (DynamicGL_GetUniformivARB==0) return false; 
		if (DynamicGL_GetShaderSourceARB==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_shader_objects*/

/*SGIX_reference_plane*/
#ifdef USE_DYNAMIC_GL_SGIX_reference_plane
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ReferencePlaneSGIX)(const GLdouble *equation) = 0; }
static bool DinamicGLFeature_SGIX_reference_plane_loaded = false; 
static void InitDinamicGLFeature_SGIX_reference_plane() {
		DynamicGL_ReferencePlaneSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *equation)>("glReferencePlaneSGIX"); 
		DinamicGLFeature_SGIX_reference_plane_loaded = true; 
}
bool DinamicGLFeature_SGIX_reference_plane_Supported() {
		if (!DinamicGLFeature_SGIX_reference_plane_loaded) {
			InitDinamicGLFeature_SGIX_reference_plane();
		}
		if (DynamicGL_ReferencePlaneSGIX==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_reference_plane*/

/*HP_image_transform*/
#ifdef USE_DYNAMIC_GL_HP_image_transform
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ImageTransformParameteriHP)(GLenum target , GLenum pname , GLint param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ImageTransformParameterfHP)(GLenum target , GLenum pname , GLfloat param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ImageTransformParameterivHP)(GLenum target , GLenum pname , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ImageTransformParameterfvHP)(GLenum target , GLenum pname , const GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetImageTransformParameterivHP)(GLenum target , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetImageTransformParameterfvHP)(GLenum target , GLenum pname , GLfloat *params) = 0; }
static bool DinamicGLFeature_HP_image_transform_loaded = false; 
static void InitDinamicGLFeature_HP_image_transform() {
		DynamicGL_ImageTransformParameteriHP = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint param)>("glImageTransformParameteriHP"); 
		DynamicGL_ImageTransformParameterfHP = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLfloat param)>("glImageTransformParameterfHP"); 
		DynamicGL_ImageTransformParameterivHP = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , const GLint *params)>("glImageTransformParameterivHP"); 
		DynamicGL_ImageTransformParameterfvHP = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , const GLfloat *params)>("glImageTransformParameterfvHP"); 
		DynamicGL_GetImageTransformParameterivHP = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint *params)>("glGetImageTransformParameterivHP"); 
		DynamicGL_GetImageTransformParameterfvHP = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLfloat *params)>("glGetImageTransformParameterfvHP"); 
		DinamicGLFeature_HP_image_transform_loaded = true; 
}
bool DinamicGLFeature_HP_image_transform_Supported() {
		if (!DinamicGLFeature_HP_image_transform_loaded) {
			InitDinamicGLFeature_HP_image_transform();
		}
		if (DynamicGL_ImageTransformParameteriHP==0) return false; 
		if (DynamicGL_ImageTransformParameterfHP==0) return false; 
		if (DynamicGL_ImageTransformParameterivHP==0) return false; 
		if (DynamicGL_ImageTransformParameterfvHP==0) return false; 
		if (DynamicGL_GetImageTransformParameterivHP==0) return false; 
		if (DynamicGL_GetImageTransformParameterfvHP==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_HP_image_transform*/

/*EXT_direct_state_access*/
#ifdef USE_DYNAMIC_GL_EXT_direct_state_access
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ClientAttribDefaultEXT)(GLbitfield mask) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PushClientAttribDefaultEXT)(GLbitfield mask) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixLoadfEXT)(GLenum mode , const GLfloat *m) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixLoaddEXT)(GLenum mode , const GLdouble *m) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixMultfEXT)(GLenum mode , const GLfloat *m) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixMultdEXT)(GLenum mode , const GLdouble *m) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixLoadIdentityEXT)(GLenum mode) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixRotatefEXT)(GLenum mode , GLfloat angle , GLfloat x , GLfloat y , GLfloat z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixRotatedEXT)(GLenum mode , GLdouble angle , GLdouble x , GLdouble y , GLdouble z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixScalefEXT)(GLenum mode , GLfloat x , GLfloat y , GLfloat z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixScaledEXT)(GLenum mode , GLdouble x , GLdouble y , GLdouble z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixTranslatefEXT)(GLenum mode , GLfloat x , GLfloat y , GLfloat z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixTranslatedEXT)(GLenum mode , GLdouble x , GLdouble y , GLdouble z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixFrustumEXT)(GLenum mode , GLdouble left , GLdouble right , GLdouble bottom , GLdouble top , GLdouble zNear , GLdouble zFar) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixOrthoEXT)(GLenum mode , GLdouble left , GLdouble right , GLdouble bottom , GLdouble top , GLdouble zNear , GLdouble zFar) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixPopEXT)(GLenum mode) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixPushEXT)(GLenum mode) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixLoadTransposefEXT)(GLenum mode , const GLfloat *m) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixLoadTransposedEXT)(GLenum mode , const GLdouble *m) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixMultTransposefEXT)(GLenum mode , const GLfloat *m) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixMultTransposedEXT)(GLenum mode , const GLdouble *m) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureParameterfEXT)(GLuint texture , GLenum target , GLenum pname , GLfloat param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureParameterfvEXT)(GLuint texture , GLenum target , GLenum pname , const GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureParameteriEXT)(GLuint texture , GLenum target , GLenum pname , GLint param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureParameterivEXT)(GLuint texture , GLenum target , GLenum pname , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureImage1DEXT)(GLuint texture , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLint border , GLenum format , GLenum type , const GLvoid *pixels) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureImage2DEXT)(GLuint texture , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLint border , GLenum format , GLenum type , const GLvoid *pixels) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureSubImage1DEXT)(GLuint texture , GLenum target , GLint level , GLint xoffset , GLsizei width , GLenum format , GLenum type , const GLvoid *pixels) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureSubImage2DEXT)(GLuint texture , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLsizei width , GLsizei height , GLenum format , GLenum type , const GLvoid *pixels) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyTextureImage1DEXT)(GLuint texture , GLenum target , GLint level , GLenum internalformat , GLint x , GLint y , GLsizei width , GLint border) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyTextureImage2DEXT)(GLuint texture , GLenum target , GLint level , GLenum internalformat , GLint x , GLint y , GLsizei width , GLsizei height , GLint border) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyTextureSubImage1DEXT)(GLuint texture , GLenum target , GLint level , GLint xoffset , GLint x , GLint y , GLsizei width) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyTextureSubImage2DEXT)(GLuint texture , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint x , GLint y , GLsizei width , GLsizei height) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTextureImageEXT)(GLuint texture , GLenum target , GLint level , GLenum format , GLenum type , GLvoid *pixels) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTextureParameterfvEXT)(GLuint texture , GLenum target , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTextureParameterivEXT)(GLuint texture , GLenum target , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTextureLevelParameterfvEXT)(GLuint texture , GLenum target , GLint level , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTextureLevelParameterivEXT)(GLuint texture , GLenum target , GLint level , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureImage3DEXT)(GLuint texture , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLsizei depth , GLint border , GLenum format , GLenum type , const GLvoid *pixels) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureSubImage3DEXT)(GLuint texture , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLsizei width , GLsizei height , GLsizei depth , GLenum format , GLenum type , const GLvoid *pixels) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyTextureSubImage3DEXT)(GLuint texture , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLint x , GLint y , GLsizei width , GLsizei height) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexParameterfEXT)(GLenum texunit , GLenum target , GLenum pname , GLfloat param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexParameterfvEXT)(GLenum texunit , GLenum target , GLenum pname , const GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexParameteriEXT)(GLenum texunit , GLenum target , GLenum pname , GLint param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexParameterivEXT)(GLenum texunit , GLenum target , GLenum pname , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexImage1DEXT)(GLenum texunit , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLint border , GLenum format , GLenum type , const GLvoid *pixels) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexImage2DEXT)(GLenum texunit , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLint border , GLenum format , GLenum type , const GLvoid *pixels) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexSubImage1DEXT)(GLenum texunit , GLenum target , GLint level , GLint xoffset , GLsizei width , GLenum format , GLenum type , const GLvoid *pixels) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexSubImage2DEXT)(GLenum texunit , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLsizei width , GLsizei height , GLenum format , GLenum type , const GLvoid *pixels) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyMultiTexImage1DEXT)(GLenum texunit , GLenum target , GLint level , GLenum internalformat , GLint x , GLint y , GLsizei width , GLint border) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyMultiTexImage2DEXT)(GLenum texunit , GLenum target , GLint level , GLenum internalformat , GLint x , GLint y , GLsizei width , GLsizei height , GLint border) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyMultiTexSubImage1DEXT)(GLenum texunit , GLenum target , GLint level , GLint xoffset , GLint x , GLint y , GLsizei width) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyMultiTexSubImage2DEXT)(GLenum texunit , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint x , GLint y , GLsizei width , GLsizei height) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMultiTexImageEXT)(GLenum texunit , GLenum target , GLint level , GLenum format , GLenum type , GLvoid *pixels) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMultiTexParameterfvEXT)(GLenum texunit , GLenum target , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMultiTexParameterivEXT)(GLenum texunit , GLenum target , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMultiTexLevelParameterfvEXT)(GLenum texunit , GLenum target , GLint level , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMultiTexLevelParameterivEXT)(GLenum texunit , GLenum target , GLint level , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexImage3DEXT)(GLenum texunit , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLsizei depth , GLint border , GLenum format , GLenum type , const GLvoid *pixels) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexSubImage3DEXT)(GLenum texunit , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLsizei width , GLsizei height , GLsizei depth , GLenum format , GLenum type , const GLvoid *pixels) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyMultiTexSubImage3DEXT)(GLenum texunit , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLint x , GLint y , GLsizei width , GLsizei height) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BindMultiTextureEXT)(GLenum texunit , GLenum target , GLuint texture) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EnableClientStateIndexedEXT)(GLenum array , GLuint index) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DisableClientStateIndexedEXT)(GLenum array , GLuint index) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoordPointerEXT)(GLenum texunit , GLint size , GLenum type , GLsizei stride , const GLvoid *pointer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexEnvfEXT)(GLenum texunit , GLenum target , GLenum pname , GLfloat param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexEnvfvEXT)(GLenum texunit , GLenum target , GLenum pname , const GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexEnviEXT)(GLenum texunit , GLenum target , GLenum pname , GLint param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexEnvivEXT)(GLenum texunit , GLenum target , GLenum pname , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexGendEXT)(GLenum texunit , GLenum coord , GLenum pname , GLdouble param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexGendvEXT)(GLenum texunit , GLenum coord , GLenum pname , const GLdouble *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexGenfEXT)(GLenum texunit , GLenum coord , GLenum pname , GLfloat param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexGenfvEXT)(GLenum texunit , GLenum coord , GLenum pname , const GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexGeniEXT)(GLenum texunit , GLenum coord , GLenum pname , GLint param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexGenivEXT)(GLenum texunit , GLenum coord , GLenum pname , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMultiTexEnvfvEXT)(GLenum texunit , GLenum target , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMultiTexEnvivEXT)(GLenum texunit , GLenum target , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMultiTexGendvEXT)(GLenum texunit , GLenum coord , GLenum pname , GLdouble *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMultiTexGenfvEXT)(GLenum texunit , GLenum coord , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMultiTexGenivEXT)(GLenum texunit , GLenum coord , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFloatIndexedvEXT)(GLenum target , GLuint index , GLfloat *data) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetDoubleIndexedvEXT)(GLenum target , GLuint index , GLdouble *data) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPointerIndexedvEXT)(GLenum target , GLuint index , GLvoid* *data) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTextureImage3DEXT)(GLuint texture , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLsizei depth , GLint border , GLsizei imageSize , const GLvoid *bits) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTextureImage2DEXT)(GLuint texture , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLint border , GLsizei imageSize , const GLvoid *bits) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTextureImage1DEXT)(GLuint texture , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLint border , GLsizei imageSize , const GLvoid *bits) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTextureSubImage3DEXT)(GLuint texture , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLsizei width , GLsizei height , GLsizei depth , GLenum format , GLsizei imageSize , const GLvoid *bits) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTextureSubImage2DEXT)(GLuint texture , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLsizei width , GLsizei height , GLenum format , GLsizei imageSize , const GLvoid *bits) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTextureSubImage1DEXT)(GLuint texture , GLenum target , GLint level , GLint xoffset , GLsizei width , GLenum format , GLsizei imageSize , const GLvoid *bits) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetCompressedTextureImageEXT)(GLuint texture , GLenum target , GLint lod , GLvoid *img) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedMultiTexImage3DEXT)(GLenum texunit , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLsizei depth , GLint border , GLsizei imageSize , const GLvoid *bits) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedMultiTexImage2DEXT)(GLenum texunit , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLint border , GLsizei imageSize , const GLvoid *bits) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedMultiTexImage1DEXT)(GLenum texunit , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLint border , GLsizei imageSize , const GLvoid *bits) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedMultiTexSubImage3DEXT)(GLenum texunit , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLsizei width , GLsizei height , GLsizei depth , GLenum format , GLsizei imageSize , const GLvoid *bits) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedMultiTexSubImage2DEXT)(GLenum texunit , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLsizei width , GLsizei height , GLenum format , GLsizei imageSize , const GLvoid *bits) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedMultiTexSubImage1DEXT)(GLenum texunit , GLenum target , GLint level , GLint xoffset , GLsizei width , GLenum format , GLsizei imageSize , const GLvoid *bits) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetCompressedMultiTexImageEXT)(GLenum texunit , GLenum target , GLint lod , GLvoid *img) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedProgramStringEXT)(GLuint program , GLenum target , GLenum format , GLsizei len , const GLvoid *string) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedProgramLocalParameter4dEXT)(GLuint program , GLenum target , GLuint index , GLdouble x , GLdouble y , GLdouble z , GLdouble w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedProgramLocalParameter4dvEXT)(GLuint program , GLenum target , GLuint index , const GLdouble *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedProgramLocalParameter4fEXT)(GLuint program , GLenum target , GLuint index , GLfloat x , GLfloat y , GLfloat z , GLfloat w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedProgramLocalParameter4fvEXT)(GLuint program , GLenum target , GLuint index , const GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetNamedProgramLocalParameterdvEXT)(GLuint program , GLenum target , GLuint index , GLdouble *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetNamedProgramLocalParameterfvEXT)(GLuint program , GLenum target , GLuint index , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetNamedProgramivEXT)(GLuint program , GLenum target , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetNamedProgramStringEXT)(GLuint program , GLenum target , GLenum pname , GLvoid *string) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedProgramLocalParameters4fvEXT)(GLuint program , GLenum target , GLuint index , GLsizei count , const GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedProgramLocalParameterI4iEXT)(GLuint program , GLenum target , GLuint index , GLint x , GLint y , GLint z , GLint w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedProgramLocalParameterI4ivEXT)(GLuint program , GLenum target , GLuint index , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedProgramLocalParametersI4ivEXT)(GLuint program , GLenum target , GLuint index , GLsizei count , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedProgramLocalParameterI4uiEXT)(GLuint program , GLenum target , GLuint index , GLuint x , GLuint y , GLuint z , GLuint w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedProgramLocalParameterI4uivEXT)(GLuint program , GLenum target , GLuint index , const GLuint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedProgramLocalParametersI4uivEXT)(GLuint program , GLenum target , GLuint index , GLsizei count , const GLuint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetNamedProgramLocalParameterIivEXT)(GLuint program , GLenum target , GLuint index , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetNamedProgramLocalParameterIuivEXT)(GLuint program , GLenum target , GLuint index , GLuint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureParameterIivEXT)(GLuint texture , GLenum target , GLenum pname , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureParameterIuivEXT)(GLuint texture , GLenum target , GLenum pname , const GLuint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTextureParameterIivEXT)(GLuint texture , GLenum target , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTextureParameterIuivEXT)(GLuint texture , GLenum target , GLenum pname , GLuint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexParameterIivEXT)(GLenum texunit , GLenum target , GLenum pname , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexParameterIuivEXT)(GLenum texunit , GLenum target , GLenum pname , const GLuint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMultiTexParameterIivEXT)(GLenum texunit , GLenum target , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMultiTexParameterIuivEXT)(GLenum texunit , GLenum target , GLenum pname , GLuint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform1fEXT)(GLuint program , GLint location , GLfloat v0) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform2fEXT)(GLuint program , GLint location , GLfloat v0 , GLfloat v1) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform3fEXT)(GLuint program , GLint location , GLfloat v0 , GLfloat v1 , GLfloat v2) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform4fEXT)(GLuint program , GLint location , GLfloat v0 , GLfloat v1 , GLfloat v2 , GLfloat v3) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform1iEXT)(GLuint program , GLint location , GLint v0) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform2iEXT)(GLuint program , GLint location , GLint v0 , GLint v1) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform3iEXT)(GLuint program , GLint location , GLint v0 , GLint v1 , GLint v2) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform4iEXT)(GLuint program , GLint location , GLint v0 , GLint v1 , GLint v2 , GLint v3) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform1fvEXT)(GLuint program , GLint location , GLsizei count , const GLfloat *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform2fvEXT)(GLuint program , GLint location , GLsizei count , const GLfloat *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform3fvEXT)(GLuint program , GLint location , GLsizei count , const GLfloat *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform4fvEXT)(GLuint program , GLint location , GLsizei count , const GLfloat *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform1ivEXT)(GLuint program , GLint location , GLsizei count , const GLint *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform2ivEXT)(GLuint program , GLint location , GLsizei count , const GLint *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform3ivEXT)(GLuint program , GLint location , GLsizei count , const GLint *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform4ivEXT)(GLuint program , GLint location , GLsizei count , const GLint *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix2fvEXT)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix3fvEXT)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix4fvEXT)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix2x3fvEXT)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix3x2fvEXT)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix2x4fvEXT)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix4x2fvEXT)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix3x4fvEXT)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix4x3fvEXT)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform1uiEXT)(GLuint program , GLint location , GLuint v0) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform2uiEXT)(GLuint program , GLint location , GLuint v0 , GLuint v1) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform3uiEXT)(GLuint program , GLint location , GLuint v0 , GLuint v1 , GLuint v2) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform4uiEXT)(GLuint program , GLint location , GLuint v0 , GLuint v1 , GLuint v2 , GLuint v3) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform1uivEXT)(GLuint program , GLint location , GLsizei count , const GLuint *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform2uivEXT)(GLuint program , GLint location , GLsizei count , const GLuint *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform3uivEXT)(GLuint program , GLint location , GLsizei count , const GLuint *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform4uivEXT)(GLuint program , GLint location , GLsizei count , const GLuint *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedBufferDataEXT)(GLuint buffer , GLsizeiptr size , const GLvoid *data , GLenum usage) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedBufferSubDataEXT)(GLuint buffer , GLintptr offset , GLsizeiptr size , const GLvoid *data) = 0; }
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_UnmapNamedBufferEXT)(GLuint buffer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetNamedBufferParameterivEXT)(GLuint buffer , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetNamedBufferPointervEXT)(GLuint buffer , GLenum pname , GLvoid* *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetNamedBufferSubDataEXT)(GLuint buffer , GLintptr offset , GLsizeiptr size , GLvoid *data) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureBufferEXT)(GLuint texture , GLenum target , GLenum internalformat , GLuint buffer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexBufferEXT)(GLenum texunit , GLenum target , GLenum internalformat , GLuint buffer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedRenderbufferStorageEXT)(GLuint renderbuffer , GLenum internalformat , GLsizei width , GLsizei height) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetNamedRenderbufferParameterivEXT)(GLuint renderbuffer , GLenum pname , GLint *params) = 0; }
extern "C" { GLenum (DYNAMIC_GL_APIENTRYP DynamicGL_CheckNamedFramebufferStatusEXT)(GLuint framebuffer , GLenum target) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedFramebufferTexture1DEXT)(GLuint framebuffer , GLenum attachment , GLenum textarget , GLuint texture , GLint level) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedFramebufferTexture2DEXT)(GLuint framebuffer , GLenum attachment , GLenum textarget , GLuint texture , GLint level) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedFramebufferTexture3DEXT)(GLuint framebuffer , GLenum attachment , GLenum textarget , GLuint texture , GLint level , GLint zoffset) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedFramebufferRenderbufferEXT)(GLuint framebuffer , GLenum attachment , GLenum renderbuffertarget , GLuint renderbuffer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetNamedFramebufferAttachmentParameterivEXT)(GLuint framebuffer , GLenum attachment , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GenerateTextureMipmapEXT)(GLuint texture , GLenum target) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GenerateMultiTexMipmapEXT)(GLenum texunit , GLenum target) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferDrawBufferEXT)(GLuint framebuffer , GLenum mode) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferDrawBuffersEXT)(GLuint framebuffer , GLsizei n , const GLenum *bufs) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferReadBufferEXT)(GLuint framebuffer , GLenum mode) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFramebufferParameterivEXT)(GLuint framebuffer , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedRenderbufferStorageMultisampleEXT)(GLuint renderbuffer , GLsizei samples , GLenum internalformat , GLsizei width , GLsizei height) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedRenderbufferStorageMultisampleCoverageEXT)(GLuint renderbuffer , GLsizei coverageSamples , GLsizei colorSamples , GLenum internalformat , GLsizei width , GLsizei height) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedFramebufferTextureEXT)(GLuint framebuffer , GLenum attachment , GLuint texture , GLint level) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedFramebufferTextureLayerEXT)(GLuint framebuffer , GLenum attachment , GLuint texture , GLint level , GLint layer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedFramebufferTextureFaceEXT)(GLuint framebuffer , GLenum attachment , GLuint texture , GLint level , GLenum face) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureRenderbufferEXT)(GLuint texture , GLenum target , GLuint renderbuffer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexRenderbufferEXT)(GLenum texunit , GLenum target , GLuint renderbuffer) = 0; }
static bool DinamicGLFeature_EXT_direct_state_access_loaded = false; 
static void InitDinamicGLFeature_EXT_direct_state_access() {
		DynamicGL_ClientAttribDefaultEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLbitfield mask)>("glClientAttribDefaultEXT"); 
		DynamicGL_PushClientAttribDefaultEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLbitfield mask)>("glPushClientAttribDefaultEXT"); 
		DynamicGL_MatrixLoadfEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , const GLfloat *m)>("glMatrixLoadfEXT"); 
		DynamicGL_MatrixLoaddEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , const GLdouble *m)>("glMatrixLoaddEXT"); 
		DynamicGL_MatrixMultfEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , const GLfloat *m)>("glMatrixMultfEXT"); 
		DynamicGL_MatrixMultdEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , const GLdouble *m)>("glMatrixMultdEXT"); 
		DynamicGL_MatrixLoadIdentityEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode)>("glMatrixLoadIdentityEXT"); 
		DynamicGL_MatrixRotatefEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , GLfloat angle , GLfloat x , GLfloat y , GLfloat z)>("glMatrixRotatefEXT"); 
		DynamicGL_MatrixRotatedEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , GLdouble angle , GLdouble x , GLdouble y , GLdouble z)>("glMatrixRotatedEXT"); 
		DynamicGL_MatrixScalefEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , GLfloat x , GLfloat y , GLfloat z)>("glMatrixScalefEXT"); 
		DynamicGL_MatrixScaledEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , GLdouble x , GLdouble y , GLdouble z)>("glMatrixScaledEXT"); 
		DynamicGL_MatrixTranslatefEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , GLfloat x , GLfloat y , GLfloat z)>("glMatrixTranslatefEXT"); 
		DynamicGL_MatrixTranslatedEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , GLdouble x , GLdouble y , GLdouble z)>("glMatrixTranslatedEXT"); 
		DynamicGL_MatrixFrustumEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , GLdouble left , GLdouble right , GLdouble bottom , GLdouble top , GLdouble zNear , GLdouble zFar)>("glMatrixFrustumEXT"); 
		DynamicGL_MatrixOrthoEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , GLdouble left , GLdouble right , GLdouble bottom , GLdouble top , GLdouble zNear , GLdouble zFar)>("glMatrixOrthoEXT"); 
		DynamicGL_MatrixPopEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode)>("glMatrixPopEXT"); 
		DynamicGL_MatrixPushEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode)>("glMatrixPushEXT"); 
		DynamicGL_MatrixLoadTransposefEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , const GLfloat *m)>("glMatrixLoadTransposefEXT"); 
		DynamicGL_MatrixLoadTransposedEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , const GLdouble *m)>("glMatrixLoadTransposedEXT"); 
		DynamicGL_MatrixMultTransposefEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , const GLfloat *m)>("glMatrixMultTransposefEXT"); 
		DynamicGL_MatrixMultTransposedEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , const GLdouble *m)>("glMatrixMultTransposedEXT"); 
		DynamicGL_TextureParameterfEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLenum pname , GLfloat param)>("glTextureParameterfEXT"); 
		DynamicGL_TextureParameterfvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLenum pname , const GLfloat *params)>("glTextureParameterfvEXT"); 
		DynamicGL_TextureParameteriEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLenum pname , GLint param)>("glTextureParameteriEXT"); 
		DynamicGL_TextureParameterivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLenum pname , const GLint *params)>("glTextureParameterivEXT"); 
		DynamicGL_TextureImage1DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLint border , GLenum format , GLenum type , const GLvoid *pixels)>("glTextureImage1DEXT"); 
		DynamicGL_TextureImage2DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLint border , GLenum format , GLenum type , const GLvoid *pixels)>("glTextureImage2DEXT"); 
		DynamicGL_TextureSubImage1DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLint level , GLint xoffset , GLsizei width , GLenum format , GLenum type , const GLvoid *pixels)>("glTextureSubImage1DEXT"); 
		DynamicGL_TextureSubImage2DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLsizei width , GLsizei height , GLenum format , GLenum type , const GLvoid *pixels)>("glTextureSubImage2DEXT"); 
		DynamicGL_CopyTextureImage1DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLint level , GLenum internalformat , GLint x , GLint y , GLsizei width , GLint border)>("glCopyTextureImage1DEXT"); 
		DynamicGL_CopyTextureImage2DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLint level , GLenum internalformat , GLint x , GLint y , GLsizei width , GLsizei height , GLint border)>("glCopyTextureImage2DEXT"); 
		DynamicGL_CopyTextureSubImage1DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLint level , GLint xoffset , GLint x , GLint y , GLsizei width)>("glCopyTextureSubImage1DEXT"); 
		DynamicGL_CopyTextureSubImage2DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint x , GLint y , GLsizei width , GLsizei height)>("glCopyTextureSubImage2DEXT"); 
		DynamicGL_GetTextureImageEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLint level , GLenum format , GLenum type , GLvoid *pixels)>("glGetTextureImageEXT"); 
		DynamicGL_GetTextureParameterfvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLenum pname , GLfloat *params)>("glGetTextureParameterfvEXT"); 
		DynamicGL_GetTextureParameterivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLenum pname , GLint *params)>("glGetTextureParameterivEXT"); 
		DynamicGL_GetTextureLevelParameterfvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLint level , GLenum pname , GLfloat *params)>("glGetTextureLevelParameterfvEXT"); 
		DynamicGL_GetTextureLevelParameterivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLint level , GLenum pname , GLint *params)>("glGetTextureLevelParameterivEXT"); 
		DynamicGL_TextureImage3DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLsizei depth , GLint border , GLenum format , GLenum type , const GLvoid *pixels)>("glTextureImage3DEXT"); 
		DynamicGL_TextureSubImage3DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLsizei width , GLsizei height , GLsizei depth , GLenum format , GLenum type , const GLvoid *pixels)>("glTextureSubImage3DEXT"); 
		DynamicGL_CopyTextureSubImage3DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLint x , GLint y , GLsizei width , GLsizei height)>("glCopyTextureSubImage3DEXT"); 
		DynamicGL_MultiTexParameterfEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLenum pname , GLfloat param)>("glMultiTexParameterfEXT"); 
		DynamicGL_MultiTexParameterfvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLenum pname , const GLfloat *params)>("glMultiTexParameterfvEXT"); 
		DynamicGL_MultiTexParameteriEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLenum pname , GLint param)>("glMultiTexParameteriEXT"); 
		DynamicGL_MultiTexParameterivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLenum pname , const GLint *params)>("glMultiTexParameterivEXT"); 
		DynamicGL_MultiTexImage1DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLint border , GLenum format , GLenum type , const GLvoid *pixels)>("glMultiTexImage1DEXT"); 
		DynamicGL_MultiTexImage2DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLint border , GLenum format , GLenum type , const GLvoid *pixels)>("glMultiTexImage2DEXT"); 
		DynamicGL_MultiTexSubImage1DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLint level , GLint xoffset , GLsizei width , GLenum format , GLenum type , const GLvoid *pixels)>("glMultiTexSubImage1DEXT"); 
		DynamicGL_MultiTexSubImage2DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLsizei width , GLsizei height , GLenum format , GLenum type , const GLvoid *pixels)>("glMultiTexSubImage2DEXT"); 
		DynamicGL_CopyMultiTexImage1DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLint level , GLenum internalformat , GLint x , GLint y , GLsizei width , GLint border)>("glCopyMultiTexImage1DEXT"); 
		DynamicGL_CopyMultiTexImage2DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLint level , GLenum internalformat , GLint x , GLint y , GLsizei width , GLsizei height , GLint border)>("glCopyMultiTexImage2DEXT"); 
		DynamicGL_CopyMultiTexSubImage1DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLint level , GLint xoffset , GLint x , GLint y , GLsizei width)>("glCopyMultiTexSubImage1DEXT"); 
		DynamicGL_CopyMultiTexSubImage2DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint x , GLint y , GLsizei width , GLsizei height)>("glCopyMultiTexSubImage2DEXT"); 
		DynamicGL_GetMultiTexImageEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLint level , GLenum format , GLenum type , GLvoid *pixels)>("glGetMultiTexImageEXT"); 
		DynamicGL_GetMultiTexParameterfvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLenum pname , GLfloat *params)>("glGetMultiTexParameterfvEXT"); 
		DynamicGL_GetMultiTexParameterivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLenum pname , GLint *params)>("glGetMultiTexParameterivEXT"); 
		DynamicGL_GetMultiTexLevelParameterfvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLint level , GLenum pname , GLfloat *params)>("glGetMultiTexLevelParameterfvEXT"); 
		DynamicGL_GetMultiTexLevelParameterivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLint level , GLenum pname , GLint *params)>("glGetMultiTexLevelParameterivEXT"); 
		DynamicGL_MultiTexImage3DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLsizei depth , GLint border , GLenum format , GLenum type , const GLvoid *pixels)>("glMultiTexImage3DEXT"); 
		DynamicGL_MultiTexSubImage3DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLsizei width , GLsizei height , GLsizei depth , GLenum format , GLenum type , const GLvoid *pixels)>("glMultiTexSubImage3DEXT"); 
		DynamicGL_CopyMultiTexSubImage3DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLint x , GLint y , GLsizei width , GLsizei height)>("glCopyMultiTexSubImage3DEXT"); 
		DynamicGL_BindMultiTextureEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLuint texture)>("glBindMultiTextureEXT"); 
		DynamicGL_EnableClientStateIndexedEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum array , GLuint index)>("glEnableClientStateIndexedEXT"); 
		DynamicGL_DisableClientStateIndexedEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum array , GLuint index)>("glDisableClientStateIndexedEXT"); 
		DynamicGL_MultiTexCoordPointerEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLint size , GLenum type , GLsizei stride , const GLvoid *pointer)>("glMultiTexCoordPointerEXT"); 
		DynamicGL_MultiTexEnvfEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLenum pname , GLfloat param)>("glMultiTexEnvfEXT"); 
		DynamicGL_MultiTexEnvfvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLenum pname , const GLfloat *params)>("glMultiTexEnvfvEXT"); 
		DynamicGL_MultiTexEnviEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLenum pname , GLint param)>("glMultiTexEnviEXT"); 
		DynamicGL_MultiTexEnvivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLenum pname , const GLint *params)>("glMultiTexEnvivEXT"); 
		DynamicGL_MultiTexGendEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum coord , GLenum pname , GLdouble param)>("glMultiTexGendEXT"); 
		DynamicGL_MultiTexGendvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum coord , GLenum pname , const GLdouble *params)>("glMultiTexGendvEXT"); 
		DynamicGL_MultiTexGenfEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum coord , GLenum pname , GLfloat param)>("glMultiTexGenfEXT"); 
		DynamicGL_MultiTexGenfvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum coord , GLenum pname , const GLfloat *params)>("glMultiTexGenfvEXT"); 
		DynamicGL_MultiTexGeniEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum coord , GLenum pname , GLint param)>("glMultiTexGeniEXT"); 
		DynamicGL_MultiTexGenivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum coord , GLenum pname , const GLint *params)>("glMultiTexGenivEXT"); 
		DynamicGL_GetMultiTexEnvfvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLenum pname , GLfloat *params)>("glGetMultiTexEnvfvEXT"); 
		DynamicGL_GetMultiTexEnvivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLenum pname , GLint *params)>("glGetMultiTexEnvivEXT"); 
		DynamicGL_GetMultiTexGendvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum coord , GLenum pname , GLdouble *params)>("glGetMultiTexGendvEXT"); 
		DynamicGL_GetMultiTexGenfvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum coord , GLenum pname , GLfloat *params)>("glGetMultiTexGenfvEXT"); 
		DynamicGL_GetMultiTexGenivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum coord , GLenum pname , GLint *params)>("glGetMultiTexGenivEXT"); 
		DynamicGL_GetFloatIndexedvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLfloat *data)>("glGetFloatIndexedvEXT"); 
		DynamicGL_GetDoubleIndexedvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLdouble *data)>("glGetDoubleIndexedvEXT"); 
		DynamicGL_GetPointerIndexedvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLvoid* *data)>("glGetPointerIndexedvEXT"); 
		DynamicGL_CompressedTextureImage3DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLsizei depth , GLint border , GLsizei imageSize , const GLvoid *bits)>("glCompressedTextureImage3DEXT"); 
		DynamicGL_CompressedTextureImage2DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLint border , GLsizei imageSize , const GLvoid *bits)>("glCompressedTextureImage2DEXT"); 
		DynamicGL_CompressedTextureImage1DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLint border , GLsizei imageSize , const GLvoid *bits)>("glCompressedTextureImage1DEXT"); 
		DynamicGL_CompressedTextureSubImage3DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLsizei width , GLsizei height , GLsizei depth , GLenum format , GLsizei imageSize , const GLvoid *bits)>("glCompressedTextureSubImage3DEXT"); 
		DynamicGL_CompressedTextureSubImage2DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLsizei width , GLsizei height , GLenum format , GLsizei imageSize , const GLvoid *bits)>("glCompressedTextureSubImage2DEXT"); 
		DynamicGL_CompressedTextureSubImage1DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLint level , GLint xoffset , GLsizei width , GLenum format , GLsizei imageSize , const GLvoid *bits)>("glCompressedTextureSubImage1DEXT"); 
		DynamicGL_GetCompressedTextureImageEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLint lod , GLvoid *img)>("glGetCompressedTextureImageEXT"); 
		DynamicGL_CompressedMultiTexImage3DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLsizei depth , GLint border , GLsizei imageSize , const GLvoid *bits)>("glCompressedMultiTexImage3DEXT"); 
		DynamicGL_CompressedMultiTexImage2DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLint border , GLsizei imageSize , const GLvoid *bits)>("glCompressedMultiTexImage2DEXT"); 
		DynamicGL_CompressedMultiTexImage1DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLint border , GLsizei imageSize , const GLvoid *bits)>("glCompressedMultiTexImage1DEXT"); 
		DynamicGL_CompressedMultiTexSubImage3DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLsizei width , GLsizei height , GLsizei depth , GLenum format , GLsizei imageSize , const GLvoid *bits)>("glCompressedMultiTexSubImage3DEXT"); 
		DynamicGL_CompressedMultiTexSubImage2DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLsizei width , GLsizei height , GLenum format , GLsizei imageSize , const GLvoid *bits)>("glCompressedMultiTexSubImage2DEXT"); 
		DynamicGL_CompressedMultiTexSubImage1DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLint level , GLint xoffset , GLsizei width , GLenum format , GLsizei imageSize , const GLvoid *bits)>("glCompressedMultiTexSubImage1DEXT"); 
		DynamicGL_GetCompressedMultiTexImageEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLint lod , GLvoid *img)>("glGetCompressedMultiTexImageEXT"); 
		DynamicGL_NamedProgramStringEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLenum target , GLenum format , GLsizei len , const GLvoid *string)>("glNamedProgramStringEXT"); 
		DynamicGL_NamedProgramLocalParameter4dEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLenum target , GLuint index , GLdouble x , GLdouble y , GLdouble z , GLdouble w)>("glNamedProgramLocalParameter4dEXT"); 
		DynamicGL_NamedProgramLocalParameter4dvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLenum target , GLuint index , const GLdouble *params)>("glNamedProgramLocalParameter4dvEXT"); 
		DynamicGL_NamedProgramLocalParameter4fEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLenum target , GLuint index , GLfloat x , GLfloat y , GLfloat z , GLfloat w)>("glNamedProgramLocalParameter4fEXT"); 
		DynamicGL_NamedProgramLocalParameter4fvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLenum target , GLuint index , const GLfloat *params)>("glNamedProgramLocalParameter4fvEXT"); 
		DynamicGL_GetNamedProgramLocalParameterdvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLenum target , GLuint index , GLdouble *params)>("glGetNamedProgramLocalParameterdvEXT"); 
		DynamicGL_GetNamedProgramLocalParameterfvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLenum target , GLuint index , GLfloat *params)>("glGetNamedProgramLocalParameterfvEXT"); 
		DynamicGL_GetNamedProgramivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLenum target , GLenum pname , GLint *params)>("glGetNamedProgramivEXT"); 
		DynamicGL_GetNamedProgramStringEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLenum target , GLenum pname , GLvoid *string)>("glGetNamedProgramStringEXT"); 
		DynamicGL_NamedProgramLocalParameters4fvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLenum target , GLuint index , GLsizei count , const GLfloat *params)>("glNamedProgramLocalParameters4fvEXT"); 
		DynamicGL_NamedProgramLocalParameterI4iEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLenum target , GLuint index , GLint x , GLint y , GLint z , GLint w)>("glNamedProgramLocalParameterI4iEXT"); 
		DynamicGL_NamedProgramLocalParameterI4ivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLenum target , GLuint index , const GLint *params)>("glNamedProgramLocalParameterI4ivEXT"); 
		DynamicGL_NamedProgramLocalParametersI4ivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLenum target , GLuint index , GLsizei count , const GLint *params)>("glNamedProgramLocalParametersI4ivEXT"); 
		DynamicGL_NamedProgramLocalParameterI4uiEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLenum target , GLuint index , GLuint x , GLuint y , GLuint z , GLuint w)>("glNamedProgramLocalParameterI4uiEXT"); 
		DynamicGL_NamedProgramLocalParameterI4uivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLenum target , GLuint index , const GLuint *params)>("glNamedProgramLocalParameterI4uivEXT"); 
		DynamicGL_NamedProgramLocalParametersI4uivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLenum target , GLuint index , GLsizei count , const GLuint *params)>("glNamedProgramLocalParametersI4uivEXT"); 
		DynamicGL_GetNamedProgramLocalParameterIivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLenum target , GLuint index , GLint *params)>("glGetNamedProgramLocalParameterIivEXT"); 
		DynamicGL_GetNamedProgramLocalParameterIuivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLenum target , GLuint index , GLuint *params)>("glGetNamedProgramLocalParameterIuivEXT"); 
		DynamicGL_TextureParameterIivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLenum pname , const GLint *params)>("glTextureParameterIivEXT"); 
		DynamicGL_TextureParameterIuivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLenum pname , const GLuint *params)>("glTextureParameterIuivEXT"); 
		DynamicGL_GetTextureParameterIivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLenum pname , GLint *params)>("glGetTextureParameterIivEXT"); 
		DynamicGL_GetTextureParameterIuivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLenum pname , GLuint *params)>("glGetTextureParameterIuivEXT"); 
		DynamicGL_MultiTexParameterIivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLenum pname , const GLint *params)>("glMultiTexParameterIivEXT"); 
		DynamicGL_MultiTexParameterIuivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLenum pname , const GLuint *params)>("glMultiTexParameterIuivEXT"); 
		DynamicGL_GetMultiTexParameterIivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLenum pname , GLint *params)>("glGetMultiTexParameterIivEXT"); 
		DynamicGL_GetMultiTexParameterIuivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLenum pname , GLuint *params)>("glGetMultiTexParameterIuivEXT"); 
		DynamicGL_ProgramUniform1fEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLfloat v0)>("glProgramUniform1fEXT"); 
		DynamicGL_ProgramUniform2fEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLfloat v0 , GLfloat v1)>("glProgramUniform2fEXT"); 
		DynamicGL_ProgramUniform3fEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLfloat v0 , GLfloat v1 , GLfloat v2)>("glProgramUniform3fEXT"); 
		DynamicGL_ProgramUniform4fEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLfloat v0 , GLfloat v1 , GLfloat v2 , GLfloat v3)>("glProgramUniform4fEXT"); 
		DynamicGL_ProgramUniform1iEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLint v0)>("glProgramUniform1iEXT"); 
		DynamicGL_ProgramUniform2iEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLint v0 , GLint v1)>("glProgramUniform2iEXT"); 
		DynamicGL_ProgramUniform3iEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLint v0 , GLint v1 , GLint v2)>("glProgramUniform3iEXT"); 
		DynamicGL_ProgramUniform4iEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLint v0 , GLint v1 , GLint v2 , GLint v3)>("glProgramUniform4iEXT"); 
		DynamicGL_ProgramUniform1fvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLsizei count , const GLfloat *value)>("glProgramUniform1fvEXT"); 
		DynamicGL_ProgramUniform2fvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLsizei count , const GLfloat *value)>("glProgramUniform2fvEXT"); 
		DynamicGL_ProgramUniform3fvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLsizei count , const GLfloat *value)>("glProgramUniform3fvEXT"); 
		DynamicGL_ProgramUniform4fvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLsizei count , const GLfloat *value)>("glProgramUniform4fvEXT"); 
		DynamicGL_ProgramUniform1ivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLsizei count , const GLint *value)>("glProgramUniform1ivEXT"); 
		DynamicGL_ProgramUniform2ivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLsizei count , const GLint *value)>("glProgramUniform2ivEXT"); 
		DynamicGL_ProgramUniform3ivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLsizei count , const GLint *value)>("glProgramUniform3ivEXT"); 
		DynamicGL_ProgramUniform4ivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLsizei count , const GLint *value)>("glProgramUniform4ivEXT"); 
		DynamicGL_ProgramUniformMatrix2fvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value)>("glProgramUniformMatrix2fvEXT"); 
		DynamicGL_ProgramUniformMatrix3fvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value)>("glProgramUniformMatrix3fvEXT"); 
		DynamicGL_ProgramUniformMatrix4fvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value)>("glProgramUniformMatrix4fvEXT"); 
		DynamicGL_ProgramUniformMatrix2x3fvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value)>("glProgramUniformMatrix2x3fvEXT"); 
		DynamicGL_ProgramUniformMatrix3x2fvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value)>("glProgramUniformMatrix3x2fvEXT"); 
		DynamicGL_ProgramUniformMatrix2x4fvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value)>("glProgramUniformMatrix2x4fvEXT"); 
		DynamicGL_ProgramUniformMatrix4x2fvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value)>("glProgramUniformMatrix4x2fvEXT"); 
		DynamicGL_ProgramUniformMatrix3x4fvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value)>("glProgramUniformMatrix3x4fvEXT"); 
		DynamicGL_ProgramUniformMatrix4x3fvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value)>("glProgramUniformMatrix4x3fvEXT"); 
		DynamicGL_ProgramUniform1uiEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLuint v0)>("glProgramUniform1uiEXT"); 
		DynamicGL_ProgramUniform2uiEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLuint v0 , GLuint v1)>("glProgramUniform2uiEXT"); 
		DynamicGL_ProgramUniform3uiEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLuint v0 , GLuint v1 , GLuint v2)>("glProgramUniform3uiEXT"); 
		DynamicGL_ProgramUniform4uiEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLuint v0 , GLuint v1 , GLuint v2 , GLuint v3)>("glProgramUniform4uiEXT"); 
		DynamicGL_ProgramUniform1uivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLsizei count , const GLuint *value)>("glProgramUniform1uivEXT"); 
		DynamicGL_ProgramUniform2uivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLsizei count , const GLuint *value)>("glProgramUniform2uivEXT"); 
		DynamicGL_ProgramUniform3uivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLsizei count , const GLuint *value)>("glProgramUniform3uivEXT"); 
		DynamicGL_ProgramUniform4uivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLsizei count , const GLuint *value)>("glProgramUniform4uivEXT"); 
		DynamicGL_NamedBufferDataEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint buffer , GLsizeiptr size , const GLvoid *data , GLenum usage)>("glNamedBufferDataEXT"); 
		DynamicGL_NamedBufferSubDataEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint buffer , GLintptr offset , GLsizeiptr size , const GLvoid *data)>("glNamedBufferSubDataEXT"); 
		DynamicGL_UnmapNamedBufferEXT = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLuint buffer)>("glUnmapNamedBufferEXT"); 
		DynamicGL_GetNamedBufferParameterivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint buffer , GLenum pname , GLint *params)>("glGetNamedBufferParameterivEXT"); 
		DynamicGL_GetNamedBufferPointervEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint buffer , GLenum pname , GLvoid* *params)>("glGetNamedBufferPointervEXT"); 
		DynamicGL_GetNamedBufferSubDataEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint buffer , GLintptr offset , GLsizeiptr size , GLvoid *data)>("glGetNamedBufferSubDataEXT"); 
		DynamicGL_TextureBufferEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLenum internalformat , GLuint buffer)>("glTextureBufferEXT"); 
		DynamicGL_MultiTexBufferEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLenum internalformat , GLuint buffer)>("glMultiTexBufferEXT"); 
		DynamicGL_NamedRenderbufferStorageEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint renderbuffer , GLenum internalformat , GLsizei width , GLsizei height)>("glNamedRenderbufferStorageEXT"); 
		DynamicGL_GetNamedRenderbufferParameterivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint renderbuffer , GLenum pname , GLint *params)>("glGetNamedRenderbufferParameterivEXT"); 
		DynamicGL_CheckNamedFramebufferStatusEXT = DynamicGL_LoadFunction<GLenum (DYNAMIC_GL_APIENTRYP)(GLuint framebuffer , GLenum target)>("glCheckNamedFramebufferStatusEXT"); 
		DynamicGL_NamedFramebufferTexture1DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint framebuffer , GLenum attachment , GLenum textarget , GLuint texture , GLint level)>("glNamedFramebufferTexture1DEXT"); 
		DynamicGL_NamedFramebufferTexture2DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint framebuffer , GLenum attachment , GLenum textarget , GLuint texture , GLint level)>("glNamedFramebufferTexture2DEXT"); 
		DynamicGL_NamedFramebufferTexture3DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint framebuffer , GLenum attachment , GLenum textarget , GLuint texture , GLint level , GLint zoffset)>("glNamedFramebufferTexture3DEXT"); 
		DynamicGL_NamedFramebufferRenderbufferEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint framebuffer , GLenum attachment , GLenum renderbuffertarget , GLuint renderbuffer)>("glNamedFramebufferRenderbufferEXT"); 
		DynamicGL_GetNamedFramebufferAttachmentParameterivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint framebuffer , GLenum attachment , GLenum pname , GLint *params)>("glGetNamedFramebufferAttachmentParameterivEXT"); 
		DynamicGL_GenerateTextureMipmapEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target)>("glGenerateTextureMipmapEXT"); 
		DynamicGL_GenerateMultiTexMipmapEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target)>("glGenerateMultiTexMipmapEXT"); 
		DynamicGL_FramebufferDrawBufferEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint framebuffer , GLenum mode)>("glFramebufferDrawBufferEXT"); 
		DynamicGL_FramebufferDrawBuffersEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint framebuffer , GLsizei n , const GLenum *bufs)>("glFramebufferDrawBuffersEXT"); 
		DynamicGL_FramebufferReadBufferEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint framebuffer , GLenum mode)>("glFramebufferReadBufferEXT"); 
		DynamicGL_GetFramebufferParameterivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint framebuffer , GLenum pname , GLint *params)>("glGetFramebufferParameterivEXT"); 
		DynamicGL_NamedRenderbufferStorageMultisampleEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint renderbuffer , GLsizei samples , GLenum internalformat , GLsizei width , GLsizei height)>("glNamedRenderbufferStorageMultisampleEXT"); 
		DynamicGL_NamedRenderbufferStorageMultisampleCoverageEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint renderbuffer , GLsizei coverageSamples , GLsizei colorSamples , GLenum internalformat , GLsizei width , GLsizei height)>("glNamedRenderbufferStorageMultisampleCoverageEXT"); 
		DynamicGL_NamedFramebufferTextureEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint framebuffer , GLenum attachment , GLuint texture , GLint level)>("glNamedFramebufferTextureEXT"); 
		DynamicGL_NamedFramebufferTextureLayerEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint framebuffer , GLenum attachment , GLuint texture , GLint level , GLint layer)>("glNamedFramebufferTextureLayerEXT"); 
		DynamicGL_NamedFramebufferTextureFaceEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint framebuffer , GLenum attachment , GLuint texture , GLint level , GLenum face)>("glNamedFramebufferTextureFaceEXT"); 
		DynamicGL_TextureRenderbufferEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLuint renderbuffer)>("glTextureRenderbufferEXT"); 
		DynamicGL_MultiTexRenderbufferEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texunit , GLenum target , GLuint renderbuffer)>("glMultiTexRenderbufferEXT"); 
		DinamicGLFeature_EXT_direct_state_access_loaded = true; 
}
bool DinamicGLFeature_EXT_direct_state_access_Supported() {
		if (!DinamicGLFeature_EXT_direct_state_access_loaded) {
			InitDinamicGLFeature_EXT_direct_state_access();
		}
		if (DynamicGL_ClientAttribDefaultEXT==0) return false; 
		if (DynamicGL_PushClientAttribDefaultEXT==0) return false; 
		if (DynamicGL_MatrixLoadfEXT==0) return false; 
		if (DynamicGL_MatrixLoaddEXT==0) return false; 
		if (DynamicGL_MatrixMultfEXT==0) return false; 
		if (DynamicGL_MatrixMultdEXT==0) return false; 
		if (DynamicGL_MatrixLoadIdentityEXT==0) return false; 
		if (DynamicGL_MatrixRotatefEXT==0) return false; 
		if (DynamicGL_MatrixRotatedEXT==0) return false; 
		if (DynamicGL_MatrixScalefEXT==0) return false; 
		if (DynamicGL_MatrixScaledEXT==0) return false; 
		if (DynamicGL_MatrixTranslatefEXT==0) return false; 
		if (DynamicGL_MatrixTranslatedEXT==0) return false; 
		if (DynamicGL_MatrixFrustumEXT==0) return false; 
		if (DynamicGL_MatrixOrthoEXT==0) return false; 
		if (DynamicGL_MatrixPopEXT==0) return false; 
		if (DynamicGL_MatrixPushEXT==0) return false; 
		if (DynamicGL_MatrixLoadTransposefEXT==0) return false; 
		if (DynamicGL_MatrixLoadTransposedEXT==0) return false; 
		if (DynamicGL_MatrixMultTransposefEXT==0) return false; 
		if (DynamicGL_MatrixMultTransposedEXT==0) return false; 
		if (DynamicGL_TextureParameterfEXT==0) return false; 
		if (DynamicGL_TextureParameterfvEXT==0) return false; 
		if (DynamicGL_TextureParameteriEXT==0) return false; 
		if (DynamicGL_TextureParameterivEXT==0) return false; 
		if (DynamicGL_TextureImage1DEXT==0) return false; 
		if (DynamicGL_TextureImage2DEXT==0) return false; 
		if (DynamicGL_TextureSubImage1DEXT==0) return false; 
		if (DynamicGL_TextureSubImage2DEXT==0) return false; 
		if (DynamicGL_CopyTextureImage1DEXT==0) return false; 
		if (DynamicGL_CopyTextureImage2DEXT==0) return false; 
		if (DynamicGL_CopyTextureSubImage1DEXT==0) return false; 
		if (DynamicGL_CopyTextureSubImage2DEXT==0) return false; 
		if (DynamicGL_GetTextureImageEXT==0) return false; 
		if (DynamicGL_GetTextureParameterfvEXT==0) return false; 
		if (DynamicGL_GetTextureParameterivEXT==0) return false; 
		if (DynamicGL_GetTextureLevelParameterfvEXT==0) return false; 
		if (DynamicGL_GetTextureLevelParameterivEXT==0) return false; 
		if (DynamicGL_TextureImage3DEXT==0) return false; 
		if (DynamicGL_TextureSubImage3DEXT==0) return false; 
		if (DynamicGL_CopyTextureSubImage3DEXT==0) return false; 
		if (DynamicGL_MultiTexParameterfEXT==0) return false; 
		if (DynamicGL_MultiTexParameterfvEXT==0) return false; 
		if (DynamicGL_MultiTexParameteriEXT==0) return false; 
		if (DynamicGL_MultiTexParameterivEXT==0) return false; 
		if (DynamicGL_MultiTexImage1DEXT==0) return false; 
		if (DynamicGL_MultiTexImage2DEXT==0) return false; 
		if (DynamicGL_MultiTexSubImage1DEXT==0) return false; 
		if (DynamicGL_MultiTexSubImage2DEXT==0) return false; 
		if (DynamicGL_CopyMultiTexImage1DEXT==0) return false; 
		if (DynamicGL_CopyMultiTexImage2DEXT==0) return false; 
		if (DynamicGL_CopyMultiTexSubImage1DEXT==0) return false; 
		if (DynamicGL_CopyMultiTexSubImage2DEXT==0) return false; 
		if (DynamicGL_GetMultiTexImageEXT==0) return false; 
		if (DynamicGL_GetMultiTexParameterfvEXT==0) return false; 
		if (DynamicGL_GetMultiTexParameterivEXT==0) return false; 
		if (DynamicGL_GetMultiTexLevelParameterfvEXT==0) return false; 
		if (DynamicGL_GetMultiTexLevelParameterivEXT==0) return false; 
		if (DynamicGL_MultiTexImage3DEXT==0) return false; 
		if (DynamicGL_MultiTexSubImage3DEXT==0) return false; 
		if (DynamicGL_CopyMultiTexSubImage3DEXT==0) return false; 
		if (DynamicGL_BindMultiTextureEXT==0) return false; 
		if (DynamicGL_EnableClientStateIndexedEXT==0) return false; 
		if (DynamicGL_DisableClientStateIndexedEXT==0) return false; 
		if (DynamicGL_MultiTexCoordPointerEXT==0) return false; 
		if (DynamicGL_MultiTexEnvfEXT==0) return false; 
		if (DynamicGL_MultiTexEnvfvEXT==0) return false; 
		if (DynamicGL_MultiTexEnviEXT==0) return false; 
		if (DynamicGL_MultiTexEnvivEXT==0) return false; 
		if (DynamicGL_MultiTexGendEXT==0) return false; 
		if (DynamicGL_MultiTexGendvEXT==0) return false; 
		if (DynamicGL_MultiTexGenfEXT==0) return false; 
		if (DynamicGL_MultiTexGenfvEXT==0) return false; 
		if (DynamicGL_MultiTexGeniEXT==0) return false; 
		if (DynamicGL_MultiTexGenivEXT==0) return false; 
		if (DynamicGL_GetMultiTexEnvfvEXT==0) return false; 
		if (DynamicGL_GetMultiTexEnvivEXT==0) return false; 
		if (DynamicGL_GetMultiTexGendvEXT==0) return false; 
		if (DynamicGL_GetMultiTexGenfvEXT==0) return false; 
		if (DynamicGL_GetMultiTexGenivEXT==0) return false; 
		if (DynamicGL_GetFloatIndexedvEXT==0) return false; 
		if (DynamicGL_GetDoubleIndexedvEXT==0) return false; 
		if (DynamicGL_GetPointerIndexedvEXT==0) return false; 
		if (DynamicGL_CompressedTextureImage3DEXT==0) return false; 
		if (DynamicGL_CompressedTextureImage2DEXT==0) return false; 
		if (DynamicGL_CompressedTextureImage1DEXT==0) return false; 
		if (DynamicGL_CompressedTextureSubImage3DEXT==0) return false; 
		if (DynamicGL_CompressedTextureSubImage2DEXT==0) return false; 
		if (DynamicGL_CompressedTextureSubImage1DEXT==0) return false; 
		if (DynamicGL_GetCompressedTextureImageEXT==0) return false; 
		if (DynamicGL_CompressedMultiTexImage3DEXT==0) return false; 
		if (DynamicGL_CompressedMultiTexImage2DEXT==0) return false; 
		if (DynamicGL_CompressedMultiTexImage1DEXT==0) return false; 
		if (DynamicGL_CompressedMultiTexSubImage3DEXT==0) return false; 
		if (DynamicGL_CompressedMultiTexSubImage2DEXT==0) return false; 
		if (DynamicGL_CompressedMultiTexSubImage1DEXT==0) return false; 
		if (DynamicGL_GetCompressedMultiTexImageEXT==0) return false; 
		if (DynamicGL_NamedProgramStringEXT==0) return false; 
		if (DynamicGL_NamedProgramLocalParameter4dEXT==0) return false; 
		if (DynamicGL_NamedProgramLocalParameter4dvEXT==0) return false; 
		if (DynamicGL_NamedProgramLocalParameter4fEXT==0) return false; 
		if (DynamicGL_NamedProgramLocalParameter4fvEXT==0) return false; 
		if (DynamicGL_GetNamedProgramLocalParameterdvEXT==0) return false; 
		if (DynamicGL_GetNamedProgramLocalParameterfvEXT==0) return false; 
		if (DynamicGL_GetNamedProgramivEXT==0) return false; 
		if (DynamicGL_GetNamedProgramStringEXT==0) return false; 
		if (DynamicGL_NamedProgramLocalParameters4fvEXT==0) return false; 
		if (DynamicGL_NamedProgramLocalParameterI4iEXT==0) return false; 
		if (DynamicGL_NamedProgramLocalParameterI4ivEXT==0) return false; 
		if (DynamicGL_NamedProgramLocalParametersI4ivEXT==0) return false; 
		if (DynamicGL_NamedProgramLocalParameterI4uiEXT==0) return false; 
		if (DynamicGL_NamedProgramLocalParameterI4uivEXT==0) return false; 
		if (DynamicGL_NamedProgramLocalParametersI4uivEXT==0) return false; 
		if (DynamicGL_GetNamedProgramLocalParameterIivEXT==0) return false; 
		if (DynamicGL_GetNamedProgramLocalParameterIuivEXT==0) return false; 
		if (DynamicGL_TextureParameterIivEXT==0) return false; 
		if (DynamicGL_TextureParameterIuivEXT==0) return false; 
		if (DynamicGL_GetTextureParameterIivEXT==0) return false; 
		if (DynamicGL_GetTextureParameterIuivEXT==0) return false; 
		if (DynamicGL_MultiTexParameterIivEXT==0) return false; 
		if (DynamicGL_MultiTexParameterIuivEXT==0) return false; 
		if (DynamicGL_GetMultiTexParameterIivEXT==0) return false; 
		if (DynamicGL_GetMultiTexParameterIuivEXT==0) return false; 
		if (DynamicGL_ProgramUniform1fEXT==0) return false; 
		if (DynamicGL_ProgramUniform2fEXT==0) return false; 
		if (DynamicGL_ProgramUniform3fEXT==0) return false; 
		if (DynamicGL_ProgramUniform4fEXT==0) return false; 
		if (DynamicGL_ProgramUniform1iEXT==0) return false; 
		if (DynamicGL_ProgramUniform2iEXT==0) return false; 
		if (DynamicGL_ProgramUniform3iEXT==0) return false; 
		if (DynamicGL_ProgramUniform4iEXT==0) return false; 
		if (DynamicGL_ProgramUniform1fvEXT==0) return false; 
		if (DynamicGL_ProgramUniform2fvEXT==0) return false; 
		if (DynamicGL_ProgramUniform3fvEXT==0) return false; 
		if (DynamicGL_ProgramUniform4fvEXT==0) return false; 
		if (DynamicGL_ProgramUniform1ivEXT==0) return false; 
		if (DynamicGL_ProgramUniform2ivEXT==0) return false; 
		if (DynamicGL_ProgramUniform3ivEXT==0) return false; 
		if (DynamicGL_ProgramUniform4ivEXT==0) return false; 
		if (DynamicGL_ProgramUniformMatrix2fvEXT==0) return false; 
		if (DynamicGL_ProgramUniformMatrix3fvEXT==0) return false; 
		if (DynamicGL_ProgramUniformMatrix4fvEXT==0) return false; 
		if (DynamicGL_ProgramUniformMatrix2x3fvEXT==0) return false; 
		if (DynamicGL_ProgramUniformMatrix3x2fvEXT==0) return false; 
		if (DynamicGL_ProgramUniformMatrix2x4fvEXT==0) return false; 
		if (DynamicGL_ProgramUniformMatrix4x2fvEXT==0) return false; 
		if (DynamicGL_ProgramUniformMatrix3x4fvEXT==0) return false; 
		if (DynamicGL_ProgramUniformMatrix4x3fvEXT==0) return false; 
		if (DynamicGL_ProgramUniform1uiEXT==0) return false; 
		if (DynamicGL_ProgramUniform2uiEXT==0) return false; 
		if (DynamicGL_ProgramUniform3uiEXT==0) return false; 
		if (DynamicGL_ProgramUniform4uiEXT==0) return false; 
		if (DynamicGL_ProgramUniform1uivEXT==0) return false; 
		if (DynamicGL_ProgramUniform2uivEXT==0) return false; 
		if (DynamicGL_ProgramUniform3uivEXT==0) return false; 
		if (DynamicGL_ProgramUniform4uivEXT==0) return false; 
		if (DynamicGL_NamedBufferDataEXT==0) return false; 
		if (DynamicGL_NamedBufferSubDataEXT==0) return false; 
		if (DynamicGL_UnmapNamedBufferEXT==0) return false; 
		if (DynamicGL_GetNamedBufferParameterivEXT==0) return false; 
		if (DynamicGL_GetNamedBufferPointervEXT==0) return false; 
		if (DynamicGL_GetNamedBufferSubDataEXT==0) return false; 
		if (DynamicGL_TextureBufferEXT==0) return false; 
		if (DynamicGL_MultiTexBufferEXT==0) return false; 
		if (DynamicGL_NamedRenderbufferStorageEXT==0) return false; 
		if (DynamicGL_GetNamedRenderbufferParameterivEXT==0) return false; 
		if (DynamicGL_CheckNamedFramebufferStatusEXT==0) return false; 
		if (DynamicGL_NamedFramebufferTexture1DEXT==0) return false; 
		if (DynamicGL_NamedFramebufferTexture2DEXT==0) return false; 
		if (DynamicGL_NamedFramebufferTexture3DEXT==0) return false; 
		if (DynamicGL_NamedFramebufferRenderbufferEXT==0) return false; 
		if (DynamicGL_GetNamedFramebufferAttachmentParameterivEXT==0) return false; 
		if (DynamicGL_GenerateTextureMipmapEXT==0) return false; 
		if (DynamicGL_GenerateMultiTexMipmapEXT==0) return false; 
		if (DynamicGL_FramebufferDrawBufferEXT==0) return false; 
		if (DynamicGL_FramebufferDrawBuffersEXT==0) return false; 
		if (DynamicGL_FramebufferReadBufferEXT==0) return false; 
		if (DynamicGL_GetFramebufferParameterivEXT==0) return false; 
		if (DynamicGL_NamedRenderbufferStorageMultisampleEXT==0) return false; 
		if (DynamicGL_NamedRenderbufferStorageMultisampleCoverageEXT==0) return false; 
		if (DynamicGL_NamedFramebufferTextureEXT==0) return false; 
		if (DynamicGL_NamedFramebufferTextureLayerEXT==0) return false; 
		if (DynamicGL_NamedFramebufferTextureFaceEXT==0) return false; 
		if (DynamicGL_TextureRenderbufferEXT==0) return false; 
		if (DynamicGL_MultiTexRenderbufferEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_direct_state_access*/

/*ARB_multisample*/
#ifdef USE_DYNAMIC_GL_ARB_multisample
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SampleCoverageARB)(GLclampf value , GLboolean invert) = 0; }
static bool DinamicGLFeature_ARB_multisample_loaded = false; 
static void InitDinamicGLFeature_ARB_multisample() {
		DynamicGL_SampleCoverageARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLclampf value , GLboolean invert)>("glSampleCoverageARB"); 
		DinamicGLFeature_ARB_multisample_loaded = true; 
}
bool DinamicGLFeature_ARB_multisample_Supported() {
		if (!DinamicGLFeature_ARB_multisample_loaded) {
			InitDinamicGLFeature_ARB_multisample();
		}
		if (DynamicGL_SampleCoverageARB==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_multisample*/

/*SGIX_fog_scale*/
#ifdef USE_DYNAMIC_GL_SGIX_fog_scale
static bool DinamicGLFeature_SGIX_fog_scale_loaded = false; 
static void InitDinamicGLFeature_SGIX_fog_scale() {
		DinamicGLFeature_SGIX_fog_scale_loaded = true; 
}
bool DinamicGLFeature_SGIX_fog_scale_Supported() {
		if (!DinamicGLFeature_SGIX_fog_scale_loaded) {
			InitDinamicGLFeature_SGIX_fog_scale();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_fog_scale*/

/*ATI_texture_mirror_once*/
#ifdef USE_DYNAMIC_GL_ATI_texture_mirror_once
static bool DinamicGLFeature_ATI_texture_mirror_once_loaded = false; 
static void InitDinamicGLFeature_ATI_texture_mirror_once() {
		DinamicGLFeature_ATI_texture_mirror_once_loaded = true; 
}
bool DinamicGLFeature_ATI_texture_mirror_once_Supported() {
		if (!DinamicGLFeature_ATI_texture_mirror_once_loaded) {
			InitDinamicGLFeature_ATI_texture_mirror_once();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_ATI_texture_mirror_once*/

/*EXT_shared_texture_palette*/
#ifdef USE_DYNAMIC_GL_EXT_shared_texture_palette
static bool DinamicGLFeature_EXT_shared_texture_palette_loaded = false; 
static void InitDinamicGLFeature_EXT_shared_texture_palette() {
		DinamicGLFeature_EXT_shared_texture_palette_loaded = true; 
}
bool DinamicGLFeature_EXT_shared_texture_palette_Supported() {
		if (!DinamicGLFeature_EXT_shared_texture_palette_loaded) {
			InitDinamicGLFeature_EXT_shared_texture_palette();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_shared_texture_palette*/

/*ARB_texture_rg*/
#ifdef USE_DYNAMIC_GL_ARB_texture_rg
static bool DinamicGLFeature_ARB_texture_rg_loaded = false; 
static void InitDinamicGLFeature_ARB_texture_rg() {
		DinamicGLFeature_ARB_texture_rg_loaded = true; 
}
bool DinamicGLFeature_ARB_texture_rg_Supported() {
		if (!DinamicGLFeature_ARB_texture_rg_loaded) {
			InitDinamicGLFeature_ARB_texture_rg();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_texture_rg*/

/*EXT_stencil_clear_tag*/
#ifdef USE_DYNAMIC_GL_EXT_stencil_clear_tag
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_StencilClearTagEXT)(GLsizei stencilTagBits , GLuint stencilClearTag) = 0; }
static bool DinamicGLFeature_EXT_stencil_clear_tag_loaded = false; 
static void InitDinamicGLFeature_EXT_stencil_clear_tag() {
		DynamicGL_StencilClearTagEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei stencilTagBits , GLuint stencilClearTag)>("glStencilClearTagEXT"); 
		DinamicGLFeature_EXT_stencil_clear_tag_loaded = true; 
}
bool DinamicGLFeature_EXT_stencil_clear_tag_Supported() {
		if (!DinamicGLFeature_EXT_stencil_clear_tag_loaded) {
			InitDinamicGLFeature_EXT_stencil_clear_tag();
		}
		if (DynamicGL_StencilClearTagEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_stencil_clear_tag*/

/*SGIS_texture_select*/
#ifdef USE_DYNAMIC_GL_SGIS_texture_select
static bool DinamicGLFeature_SGIS_texture_select_loaded = false; 
static void InitDinamicGLFeature_SGIS_texture_select() {
		DinamicGLFeature_SGIS_texture_select_loaded = true; 
}
bool DinamicGLFeature_SGIS_texture_select_Supported() {
		if (!DinamicGLFeature_SGIS_texture_select_loaded) {
			InitDinamicGLFeature_SGIS_texture_select();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIS_texture_select*/

/*NV_geometry_program4*/
#ifdef USE_DYNAMIC_GL_NV_geometry_program4
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramVertexLimitNV)(GLenum target , GLint limit) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferTextureEXT)(GLenum target , GLenum attachment , GLuint texture , GLint level) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferTextureLayerEXT)(GLenum target , GLenum attachment , GLuint texture , GLint level , GLint layer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferTextureFaceEXT)(GLenum target , GLenum attachment , GLuint texture , GLint level , GLenum face) = 0; }
static bool DinamicGLFeature_NV_geometry_program4_loaded = false; 
static void InitDinamicGLFeature_NV_geometry_program4() {
		DynamicGL_ProgramVertexLimitNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint limit)>("glProgramVertexLimitNV"); 
		DynamicGL_FramebufferTextureEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum attachment , GLuint texture , GLint level)>("glFramebufferTextureEXT"); 
		DynamicGL_FramebufferTextureLayerEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum attachment , GLuint texture , GLint level , GLint layer)>("glFramebufferTextureLayerEXT"); 
		DynamicGL_FramebufferTextureFaceEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum attachment , GLuint texture , GLint level , GLenum face)>("glFramebufferTextureFaceEXT"); 
		DinamicGLFeature_NV_geometry_program4_loaded = true; 
}
bool DinamicGLFeature_NV_geometry_program4_Supported() {
		if (!DinamicGLFeature_NV_geometry_program4_loaded) {
			InitDinamicGLFeature_NV_geometry_program4();
		}
		if (DynamicGL_ProgramVertexLimitNV==0) return false; 
		if (DynamicGL_FramebufferTextureEXT==0) return false; 
		if (DynamicGL_FramebufferTextureLayerEXT==0) return false; 
		if (DynamicGL_FramebufferTextureFaceEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_geometry_program4*/

/*ARB_framebuffer_sRGB*/
#ifdef USE_DYNAMIC_GL_ARB_framebuffer_sRGB
static bool DinamicGLFeature_ARB_framebuffer_sRGB_loaded = false; 
static void InitDinamicGLFeature_ARB_framebuffer_sRGB() {
		DinamicGLFeature_ARB_framebuffer_sRGB_loaded = true; 
}
bool DinamicGLFeature_ARB_framebuffer_sRGB_Supported() {
		if (!DinamicGLFeature_ARB_framebuffer_sRGB_loaded) {
			InitDinamicGLFeature_ARB_framebuffer_sRGB();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_framebuffer_sRGB*/

/*IBM_rasterpos_clip*/
#ifdef USE_DYNAMIC_GL_IBM_rasterpos_clip
static bool DinamicGLFeature_IBM_rasterpos_clip_loaded = false; 
static void InitDinamicGLFeature_IBM_rasterpos_clip() {
		DinamicGLFeature_IBM_rasterpos_clip_loaded = true; 
}
bool DinamicGLFeature_IBM_rasterpos_clip_Supported() {
		if (!DinamicGLFeature_IBM_rasterpos_clip_loaded) {
			InitDinamicGLFeature_IBM_rasterpos_clip();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_IBM_rasterpos_clip*/

/*MESA_ycbcr_texture*/
#ifdef USE_DYNAMIC_GL_MESA_ycbcr_texture
static bool DinamicGLFeature_MESA_ycbcr_texture_loaded = false; 
static void InitDinamicGLFeature_MESA_ycbcr_texture() {
		DinamicGLFeature_MESA_ycbcr_texture_loaded = true; 
}
bool DinamicGLFeature_MESA_ycbcr_texture_Supported() {
		if (!DinamicGLFeature_MESA_ycbcr_texture_loaded) {
			InitDinamicGLFeature_MESA_ycbcr_texture();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_MESA_ycbcr_texture*/

/*ATI_vertex_streams*/
#ifdef USE_DYNAMIC_GL_ATI_vertex_streams
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream1sATI)(GLenum stream , GLshort x) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream1svATI)(GLenum stream , const GLshort *coords) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream1iATI)(GLenum stream , GLint x) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream1ivATI)(GLenum stream , const GLint *coords) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream1fATI)(GLenum stream , GLfloat x) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream1fvATI)(GLenum stream , const GLfloat *coords) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream1dATI)(GLenum stream , GLdouble x) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream1dvATI)(GLenum stream , const GLdouble *coords) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream2sATI)(GLenum stream , GLshort x , GLshort y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream2svATI)(GLenum stream , const GLshort *coords) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream2iATI)(GLenum stream , GLint x , GLint y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream2ivATI)(GLenum stream , const GLint *coords) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream2fATI)(GLenum stream , GLfloat x , GLfloat y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream2fvATI)(GLenum stream , const GLfloat *coords) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream2dATI)(GLenum stream , GLdouble x , GLdouble y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream2dvATI)(GLenum stream , const GLdouble *coords) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream3sATI)(GLenum stream , GLshort x , GLshort y , GLshort z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream3svATI)(GLenum stream , const GLshort *coords) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream3iATI)(GLenum stream , GLint x , GLint y , GLint z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream3ivATI)(GLenum stream , const GLint *coords) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream3fATI)(GLenum stream , GLfloat x , GLfloat y , GLfloat z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream3fvATI)(GLenum stream , const GLfloat *coords) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream3dATI)(GLenum stream , GLdouble x , GLdouble y , GLdouble z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream3dvATI)(GLenum stream , const GLdouble *coords) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream4sATI)(GLenum stream , GLshort x , GLshort y , GLshort z , GLshort w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream4svATI)(GLenum stream , const GLshort *coords) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream4iATI)(GLenum stream , GLint x , GLint y , GLint z , GLint w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream4ivATI)(GLenum stream , const GLint *coords) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream4fATI)(GLenum stream , GLfloat x , GLfloat y , GLfloat z , GLfloat w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream4fvATI)(GLenum stream , const GLfloat *coords) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream4dATI)(GLenum stream , GLdouble x , GLdouble y , GLdouble z , GLdouble w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream4dvATI)(GLenum stream , const GLdouble *coords) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NormalStream3bATI)(GLenum stream , GLbyte nx , GLbyte ny , GLbyte nz) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NormalStream3bvATI)(GLenum stream , const GLbyte *coords) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NormalStream3sATI)(GLenum stream , GLshort nx , GLshort ny , GLshort nz) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NormalStream3svATI)(GLenum stream , const GLshort *coords) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NormalStream3iATI)(GLenum stream , GLint nx , GLint ny , GLint nz) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NormalStream3ivATI)(GLenum stream , const GLint *coords) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NormalStream3fATI)(GLenum stream , GLfloat nx , GLfloat ny , GLfloat nz) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NormalStream3fvATI)(GLenum stream , const GLfloat *coords) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NormalStream3dATI)(GLenum stream , GLdouble nx , GLdouble ny , GLdouble nz) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NormalStream3dvATI)(GLenum stream , const GLdouble *coords) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ClientActiveVertexStreamATI)(GLenum stream) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexBlendEnviATI)(GLenum pname , GLint param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexBlendEnvfATI)(GLenum pname , GLfloat param) = 0; }
static bool DinamicGLFeature_ATI_vertex_streams_loaded = false; 
static void InitDinamicGLFeature_ATI_vertex_streams() {
		DynamicGL_VertexStream1sATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , GLshort x)>("glVertexStream1sATI"); 
		DynamicGL_VertexStream1svATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , const GLshort *coords)>("glVertexStream1svATI"); 
		DynamicGL_VertexStream1iATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , GLint x)>("glVertexStream1iATI"); 
		DynamicGL_VertexStream1ivATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , const GLint *coords)>("glVertexStream1ivATI"); 
		DynamicGL_VertexStream1fATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , GLfloat x)>("glVertexStream1fATI"); 
		DynamicGL_VertexStream1fvATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , const GLfloat *coords)>("glVertexStream1fvATI"); 
		DynamicGL_VertexStream1dATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , GLdouble x)>("glVertexStream1dATI"); 
		DynamicGL_VertexStream1dvATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , const GLdouble *coords)>("glVertexStream1dvATI"); 
		DynamicGL_VertexStream2sATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , GLshort x , GLshort y)>("glVertexStream2sATI"); 
		DynamicGL_VertexStream2svATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , const GLshort *coords)>("glVertexStream2svATI"); 
		DynamicGL_VertexStream2iATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , GLint x , GLint y)>("glVertexStream2iATI"); 
		DynamicGL_VertexStream2ivATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , const GLint *coords)>("glVertexStream2ivATI"); 
		DynamicGL_VertexStream2fATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , GLfloat x , GLfloat y)>("glVertexStream2fATI"); 
		DynamicGL_VertexStream2fvATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , const GLfloat *coords)>("glVertexStream2fvATI"); 
		DynamicGL_VertexStream2dATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , GLdouble x , GLdouble y)>("glVertexStream2dATI"); 
		DynamicGL_VertexStream2dvATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , const GLdouble *coords)>("glVertexStream2dvATI"); 
		DynamicGL_VertexStream3sATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , GLshort x , GLshort y , GLshort z)>("glVertexStream3sATI"); 
		DynamicGL_VertexStream3svATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , const GLshort *coords)>("glVertexStream3svATI"); 
		DynamicGL_VertexStream3iATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , GLint x , GLint y , GLint z)>("glVertexStream3iATI"); 
		DynamicGL_VertexStream3ivATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , const GLint *coords)>("glVertexStream3ivATI"); 
		DynamicGL_VertexStream3fATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , GLfloat x , GLfloat y , GLfloat z)>("glVertexStream3fATI"); 
		DynamicGL_VertexStream3fvATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , const GLfloat *coords)>("glVertexStream3fvATI"); 
		DynamicGL_VertexStream3dATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , GLdouble x , GLdouble y , GLdouble z)>("glVertexStream3dATI"); 
		DynamicGL_VertexStream3dvATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , const GLdouble *coords)>("glVertexStream3dvATI"); 
		DynamicGL_VertexStream4sATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , GLshort x , GLshort y , GLshort z , GLshort w)>("glVertexStream4sATI"); 
		DynamicGL_VertexStream4svATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , const GLshort *coords)>("glVertexStream4svATI"); 
		DynamicGL_VertexStream4iATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , GLint x , GLint y , GLint z , GLint w)>("glVertexStream4iATI"); 
		DynamicGL_VertexStream4ivATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , const GLint *coords)>("glVertexStream4ivATI"); 
		DynamicGL_VertexStream4fATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , GLfloat x , GLfloat y , GLfloat z , GLfloat w)>("glVertexStream4fATI"); 
		DynamicGL_VertexStream4fvATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , const GLfloat *coords)>("glVertexStream4fvATI"); 
		DynamicGL_VertexStream4dATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , GLdouble x , GLdouble y , GLdouble z , GLdouble w)>("glVertexStream4dATI"); 
		DynamicGL_VertexStream4dvATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , const GLdouble *coords)>("glVertexStream4dvATI"); 
		DynamicGL_NormalStream3bATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , GLbyte nx , GLbyte ny , GLbyte nz)>("glNormalStream3bATI"); 
		DynamicGL_NormalStream3bvATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , const GLbyte *coords)>("glNormalStream3bvATI"); 
		DynamicGL_NormalStream3sATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , GLshort nx , GLshort ny , GLshort nz)>("glNormalStream3sATI"); 
		DynamicGL_NormalStream3svATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , const GLshort *coords)>("glNormalStream3svATI"); 
		DynamicGL_NormalStream3iATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , GLint nx , GLint ny , GLint nz)>("glNormalStream3iATI"); 
		DynamicGL_NormalStream3ivATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , const GLint *coords)>("glNormalStream3ivATI"); 
		DynamicGL_NormalStream3fATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , GLfloat nx , GLfloat ny , GLfloat nz)>("glNormalStream3fATI"); 
		DynamicGL_NormalStream3fvATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , const GLfloat *coords)>("glNormalStream3fvATI"); 
		DynamicGL_NormalStream3dATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , GLdouble nx , GLdouble ny , GLdouble nz)>("glNormalStream3dATI"); 
		DynamicGL_NormalStream3dvATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream , const GLdouble *coords)>("glNormalStream3dvATI"); 
		DynamicGL_ClientActiveVertexStreamATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stream)>("glClientActiveVertexStreamATI"); 
		DynamicGL_VertexBlendEnviATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLint param)>("glVertexBlendEnviATI"); 
		DynamicGL_VertexBlendEnvfATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLfloat param)>("glVertexBlendEnvfATI"); 
		DinamicGLFeature_ATI_vertex_streams_loaded = true; 
}
bool DinamicGLFeature_ATI_vertex_streams_Supported() {
		if (!DinamicGLFeature_ATI_vertex_streams_loaded) {
			InitDinamicGLFeature_ATI_vertex_streams();
		}
		if (DynamicGL_VertexStream1sATI==0) return false; 
		if (DynamicGL_VertexStream1svATI==0) return false; 
		if (DynamicGL_VertexStream1iATI==0) return false; 
		if (DynamicGL_VertexStream1ivATI==0) return false; 
		if (DynamicGL_VertexStream1fATI==0) return false; 
		if (DynamicGL_VertexStream1fvATI==0) return false; 
		if (DynamicGL_VertexStream1dATI==0) return false; 
		if (DynamicGL_VertexStream1dvATI==0) return false; 
		if (DynamicGL_VertexStream2sATI==0) return false; 
		if (DynamicGL_VertexStream2svATI==0) return false; 
		if (DynamicGL_VertexStream2iATI==0) return false; 
		if (DynamicGL_VertexStream2ivATI==0) return false; 
		if (DynamicGL_VertexStream2fATI==0) return false; 
		if (DynamicGL_VertexStream2fvATI==0) return false; 
		if (DynamicGL_VertexStream2dATI==0) return false; 
		if (DynamicGL_VertexStream2dvATI==0) return false; 
		if (DynamicGL_VertexStream3sATI==0) return false; 
		if (DynamicGL_VertexStream3svATI==0) return false; 
		if (DynamicGL_VertexStream3iATI==0) return false; 
		if (DynamicGL_VertexStream3ivATI==0) return false; 
		if (DynamicGL_VertexStream3fATI==0) return false; 
		if (DynamicGL_VertexStream3fvATI==0) return false; 
		if (DynamicGL_VertexStream3dATI==0) return false; 
		if (DynamicGL_VertexStream3dvATI==0) return false; 
		if (DynamicGL_VertexStream4sATI==0) return false; 
		if (DynamicGL_VertexStream4svATI==0) return false; 
		if (DynamicGL_VertexStream4iATI==0) return false; 
		if (DynamicGL_VertexStream4ivATI==0) return false; 
		if (DynamicGL_VertexStream4fATI==0) return false; 
		if (DynamicGL_VertexStream4fvATI==0) return false; 
		if (DynamicGL_VertexStream4dATI==0) return false; 
		if (DynamicGL_VertexStream4dvATI==0) return false; 
		if (DynamicGL_NormalStream3bATI==0) return false; 
		if (DynamicGL_NormalStream3bvATI==0) return false; 
		if (DynamicGL_NormalStream3sATI==0) return false; 
		if (DynamicGL_NormalStream3svATI==0) return false; 
		if (DynamicGL_NormalStream3iATI==0) return false; 
		if (DynamicGL_NormalStream3ivATI==0) return false; 
		if (DynamicGL_NormalStream3fATI==0) return false; 
		if (DynamicGL_NormalStream3fvATI==0) return false; 
		if (DynamicGL_NormalStream3dATI==0) return false; 
		if (DynamicGL_NormalStream3dvATI==0) return false; 
		if (DynamicGL_ClientActiveVertexStreamATI==0) return false; 
		if (DynamicGL_VertexBlendEnviATI==0) return false; 
		if (DynamicGL_VertexBlendEnvfATI==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_ATI_vertex_streams*/

/*3DFX_texture_compression_FXT1*/
#ifdef USE_DYNAMIC_GL_3DFX_texture_compression_FXT1
static bool DinamicGLFeature_3DFX_texture_compression_FXT1_loaded = false; 
static void InitDinamicGLFeature_3DFX_texture_compression_FXT1() {
		DinamicGLFeature_3DFX_texture_compression_FXT1_loaded = true; 
}
bool DinamicGLFeature_3DFX_texture_compression_FXT1_Supported() {
		if (!DinamicGLFeature_3DFX_texture_compression_FXT1_loaded) {
			InitDinamicGLFeature_3DFX_texture_compression_FXT1();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_3DFX_texture_compression_FXT1*/

/*SGIX_shadow_ambient*/
#ifdef USE_DYNAMIC_GL_SGIX_shadow_ambient
static bool DinamicGLFeature_SGIX_shadow_ambient_loaded = false; 
static void InitDinamicGLFeature_SGIX_shadow_ambient() {
		DinamicGLFeature_SGIX_shadow_ambient_loaded = true; 
}
bool DinamicGLFeature_SGIX_shadow_ambient_Supported() {
		if (!DinamicGLFeature_SGIX_shadow_ambient_loaded) {
			InitDinamicGLFeature_SGIX_shadow_ambient();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_shadow_ambient*/

/*EXT_blend_color*/
#ifdef USE_DYNAMIC_GL_EXT_blend_color
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendColorEXT)(GLclampf red , GLclampf green , GLclampf blue , GLclampf alpha) = 0; }
static bool DinamicGLFeature_EXT_blend_color_loaded = false; 
static void InitDinamicGLFeature_EXT_blend_color() {
		DynamicGL_BlendColorEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLclampf red , GLclampf green , GLclampf blue , GLclampf alpha)>("glBlendColorEXT"); 
		DinamicGLFeature_EXT_blend_color_loaded = true; 
}
bool DinamicGLFeature_EXT_blend_color_Supported() {
		if (!DinamicGLFeature_EXT_blend_color_loaded) {
			InitDinamicGLFeature_EXT_blend_color();
		}
		if (DynamicGL_BlendColorEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_blend_color*/

/*ARB_shadow*/
#ifdef USE_DYNAMIC_GL_ARB_shadow
static bool DinamicGLFeature_ARB_shadow_loaded = false; 
static void InitDinamicGLFeature_ARB_shadow() {
		DinamicGLFeature_ARB_shadow_loaded = true; 
}
bool DinamicGLFeature_ARB_shadow_Supported() {
		if (!DinamicGLFeature_ARB_shadow_loaded) {
			InitDinamicGLFeature_ARB_shadow();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_shadow*/

/*EXT_stencil_wrap*/
#ifdef USE_DYNAMIC_GL_EXT_stencil_wrap
static bool DinamicGLFeature_EXT_stencil_wrap_loaded = false; 
static void InitDinamicGLFeature_EXT_stencil_wrap() {
		DinamicGLFeature_EXT_stencil_wrap_loaded = true; 
}
bool DinamicGLFeature_EXT_stencil_wrap_Supported() {
		if (!DinamicGLFeature_EXT_stencil_wrap_loaded) {
			InitDinamicGLFeature_EXT_stencil_wrap();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_stencil_wrap*/

/*NV_vertex_array_range2*/
#ifdef USE_DYNAMIC_GL_NV_vertex_array_range2
static bool DinamicGLFeature_NV_vertex_array_range2_loaded = false; 
static void InitDinamicGLFeature_NV_vertex_array_range2() {
		DinamicGLFeature_NV_vertex_array_range2_loaded = true; 
}
bool DinamicGLFeature_NV_vertex_array_range2_Supported() {
		if (!DinamicGLFeature_NV_vertex_array_range2_loaded) {
			InitDinamicGLFeature_NV_vertex_array_range2();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_vertex_array_range2*/

/*EXT_bgra*/
#ifdef USE_DYNAMIC_GL_EXT_bgra
static bool DinamicGLFeature_EXT_bgra_loaded = false; 
static void InitDinamicGLFeature_EXT_bgra() {
		DinamicGLFeature_EXT_bgra_loaded = true; 
}
bool DinamicGLFeature_EXT_bgra_Supported() {
		if (!DinamicGLFeature_EXT_bgra_loaded) {
			InitDinamicGLFeature_EXT_bgra();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_bgra*/

/*ARB_framebuffer_object*/
#ifdef USE_DYNAMIC_GL_ARB_framebuffer_object
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsRenderbuffer)(GLuint renderbuffer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BindRenderbuffer)(GLenum target , GLuint renderbuffer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteRenderbuffers)(GLsizei n , const GLuint *renderbuffers) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GenRenderbuffers)(GLsizei n , GLuint *renderbuffers) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_RenderbufferStorage)(GLenum target , GLenum internalformat , GLsizei width , GLsizei height) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetRenderbufferParameteriv)(GLenum target , GLenum pname , GLint *params) = 0; }
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsFramebuffer)(GLuint framebuffer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BindFramebuffer)(GLenum target , GLuint framebuffer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteFramebuffers)(GLsizei n , const GLuint *framebuffers) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GenFramebuffers)(GLsizei n , GLuint *framebuffers) = 0; }
extern "C" { GLenum (DYNAMIC_GL_APIENTRYP DynamicGL_CheckFramebufferStatus)(GLenum target) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferTexture1D)(GLenum target , GLenum attachment , GLenum textarget , GLuint texture , GLint level) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferTexture2D)(GLenum target , GLenum attachment , GLenum textarget , GLuint texture , GLint level) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferTexture3D)(GLenum target , GLenum attachment , GLenum textarget , GLuint texture , GLint level , GLint zoffset) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferRenderbuffer)(GLenum target , GLenum attachment , GLenum renderbuffertarget , GLuint renderbuffer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFramebufferAttachmentParameteriv)(GLenum target , GLenum attachment , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GenerateMipmap)(GLenum target) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BlitFramebuffer)(GLint srcX0 , GLint srcY0 , GLint srcX1 , GLint srcY1 , GLint dstX0 , GLint dstY0 , GLint dstX1 , GLint dstY1 , GLbitfield mask , GLenum filter) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_RenderbufferStorageMultisample)(GLenum target , GLsizei samples , GLenum internalformat , GLsizei width , GLsizei height) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferTextureLayer)(GLenum target , GLenum attachment , GLuint texture , GLint level , GLint layer) = 0; }
static bool DinamicGLFeature_ARB_framebuffer_object_loaded = false; 
static void InitDinamicGLFeature_ARB_framebuffer_object() {
		DynamicGL_IsRenderbuffer = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLuint renderbuffer)>("glIsRenderbuffer"); 
		DynamicGL_BindRenderbuffer = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint renderbuffer)>("glBindRenderbuffer"); 
		DynamicGL_DeleteRenderbuffers = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , const GLuint *renderbuffers)>("glDeleteRenderbuffers"); 
		DynamicGL_GenRenderbuffers = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , GLuint *renderbuffers)>("glGenRenderbuffers"); 
		DynamicGL_RenderbufferStorage = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum internalformat , GLsizei width , GLsizei height)>("glRenderbufferStorage"); 
		DynamicGL_GetRenderbufferParameteriv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint *params)>("glGetRenderbufferParameteriv"); 
		DynamicGL_IsFramebuffer = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLuint framebuffer)>("glIsFramebuffer"); 
		DynamicGL_BindFramebuffer = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint framebuffer)>("glBindFramebuffer"); 
		DynamicGL_DeleteFramebuffers = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , const GLuint *framebuffers)>("glDeleteFramebuffers"); 
		DynamicGL_GenFramebuffers = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , GLuint *framebuffers)>("glGenFramebuffers"); 
		DynamicGL_CheckFramebufferStatus = DynamicGL_LoadFunction<GLenum (DYNAMIC_GL_APIENTRYP)(GLenum target)>("glCheckFramebufferStatus"); 
		DynamicGL_FramebufferTexture1D = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum attachment , GLenum textarget , GLuint texture , GLint level)>("glFramebufferTexture1D"); 
		DynamicGL_FramebufferTexture2D = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum attachment , GLenum textarget , GLuint texture , GLint level)>("glFramebufferTexture2D"); 
		DynamicGL_FramebufferTexture3D = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum attachment , GLenum textarget , GLuint texture , GLint level , GLint zoffset)>("glFramebufferTexture3D"); 
		DynamicGL_FramebufferRenderbuffer = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum attachment , GLenum renderbuffertarget , GLuint renderbuffer)>("glFramebufferRenderbuffer"); 
		DynamicGL_GetFramebufferAttachmentParameteriv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum attachment , GLenum pname , GLint *params)>("glGetFramebufferAttachmentParameteriv"); 
		DynamicGL_GenerateMipmap = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target)>("glGenerateMipmap"); 
		DynamicGL_BlitFramebuffer = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint srcX0 , GLint srcY0 , GLint srcX1 , GLint srcY1 , GLint dstX0 , GLint dstY0 , GLint dstX1 , GLint dstY1 , GLbitfield mask , GLenum filter)>("glBlitFramebuffer"); 
		DynamicGL_RenderbufferStorageMultisample = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLsizei samples , GLenum internalformat , GLsizei width , GLsizei height)>("glRenderbufferStorageMultisample"); 
		DynamicGL_FramebufferTextureLayer = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum attachment , GLuint texture , GLint level , GLint layer)>("glFramebufferTextureLayer"); 
		DinamicGLFeature_ARB_framebuffer_object_loaded = true; 
}
bool DinamicGLFeature_ARB_framebuffer_object_Supported() {
		if (!DinamicGLFeature_ARB_framebuffer_object_loaded) {
			InitDinamicGLFeature_ARB_framebuffer_object();
		}
		if (DynamicGL_IsRenderbuffer==0) return false; 
		if (DynamicGL_BindRenderbuffer==0) return false; 
		if (DynamicGL_DeleteRenderbuffers==0) return false; 
		if (DynamicGL_GenRenderbuffers==0) return false; 
		if (DynamicGL_RenderbufferStorage==0) return false; 
		if (DynamicGL_GetRenderbufferParameteriv==0) return false; 
		if (DynamicGL_IsFramebuffer==0) return false; 
		if (DynamicGL_BindFramebuffer==0) return false; 
		if (DynamicGL_DeleteFramebuffers==0) return false; 
		if (DynamicGL_GenFramebuffers==0) return false; 
		if (DynamicGL_CheckFramebufferStatus==0) return false; 
		if (DynamicGL_FramebufferTexture1D==0) return false; 
		if (DynamicGL_FramebufferTexture2D==0) return false; 
		if (DynamicGL_FramebufferTexture3D==0) return false; 
		if (DynamicGL_FramebufferRenderbuffer==0) return false; 
		if (DynamicGL_GetFramebufferAttachmentParameteriv==0) return false; 
		if (DynamicGL_GenerateMipmap==0) return false; 
		if (DynamicGL_BlitFramebuffer==0) return false; 
		if (DynamicGL_RenderbufferStorageMultisample==0) return false; 
		if (DynamicGL_FramebufferTextureLayer==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_framebuffer_object*/

/*SGIX_async*/
#ifdef USE_DYNAMIC_GL_SGIX_async
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_AsyncMarkerSGIX)(GLuint marker) = 0; }
extern "C" { GLint (DYNAMIC_GL_APIENTRYP DynamicGL_FinishAsyncSGIX)(GLuint *markerp) = 0; }
extern "C" { GLint (DYNAMIC_GL_APIENTRYP DynamicGL_PollAsyncSGIX)(GLuint *markerp) = 0; }
extern "C" { GLuint (DYNAMIC_GL_APIENTRYP DynamicGL_GenAsyncMarkersSGIX)(GLsizei range) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteAsyncMarkersSGIX)(GLuint marker , GLsizei range) = 0; }
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsAsyncMarkerSGIX)(GLuint marker) = 0; }
static bool DinamicGLFeature_SGIX_async_loaded = false; 
static void InitDinamicGLFeature_SGIX_async() {
		DynamicGL_AsyncMarkerSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint marker)>("glAsyncMarkerSGIX"); 
		DynamicGL_FinishAsyncSGIX = DynamicGL_LoadFunction<GLint (DYNAMIC_GL_APIENTRYP)(GLuint *markerp)>("glFinishAsyncSGIX"); 
		DynamicGL_PollAsyncSGIX = DynamicGL_LoadFunction<GLint (DYNAMIC_GL_APIENTRYP)(GLuint *markerp)>("glPollAsyncSGIX"); 
		DynamicGL_GenAsyncMarkersSGIX = DynamicGL_LoadFunction<GLuint (DYNAMIC_GL_APIENTRYP)(GLsizei range)>("glGenAsyncMarkersSGIX"); 
		DynamicGL_DeleteAsyncMarkersSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint marker , GLsizei range)>("glDeleteAsyncMarkersSGIX"); 
		DynamicGL_IsAsyncMarkerSGIX = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLuint marker)>("glIsAsyncMarkerSGIX"); 
		DinamicGLFeature_SGIX_async_loaded = true; 
}
bool DinamicGLFeature_SGIX_async_Supported() {
		if (!DinamicGLFeature_SGIX_async_loaded) {
			InitDinamicGLFeature_SGIX_async();
		}
		if (DynamicGL_AsyncMarkerSGIX==0) return false; 
		if (DynamicGL_FinishAsyncSGIX==0) return false; 
		if (DynamicGL_PollAsyncSGIX==0) return false; 
		if (DynamicGL_GenAsyncMarkersSGIX==0) return false; 
		if (DynamicGL_DeleteAsyncMarkersSGIX==0) return false; 
		if (DynamicGL_IsAsyncMarkerSGIX==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_async*/

/*SGI_texture_color_table*/
#ifdef USE_DYNAMIC_GL_SGI_texture_color_table
static bool DinamicGLFeature_SGI_texture_color_table_loaded = false; 
static void InitDinamicGLFeature_SGI_texture_color_table() {
		DinamicGLFeature_SGI_texture_color_table_loaded = true; 
}
bool DinamicGLFeature_SGI_texture_color_table_Supported() {
		if (!DinamicGLFeature_SGI_texture_color_table_loaded) {
			InitDinamicGLFeature_SGI_texture_color_table();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGI_texture_color_table*/

/*EXT_subtexture*/
#ifdef USE_DYNAMIC_GL_EXT_subtexture
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexSubImage1DEXT)(GLenum target , GLint level , GLint xoffset , GLsizei width , GLenum format , GLenum type , const GLvoid *pixels) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexSubImage2DEXT)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLsizei width , GLsizei height , GLenum format , GLenum type , const GLvoid *pixels) = 0; }
static bool DinamicGLFeature_EXT_subtexture_loaded = false; 
static void InitDinamicGLFeature_EXT_subtexture() {
		DynamicGL_TexSubImage1DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLint xoffset , GLsizei width , GLenum format , GLenum type , const GLvoid *pixels)>("glTexSubImage1DEXT"); 
		DynamicGL_TexSubImage2DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLsizei width , GLsizei height , GLenum format , GLenum type , const GLvoid *pixels)>("glTexSubImage2DEXT"); 
		DinamicGLFeature_EXT_subtexture_loaded = true; 
}
bool DinamicGLFeature_EXT_subtexture_Supported() {
		if (!DinamicGLFeature_EXT_subtexture_loaded) {
			InitDinamicGLFeature_EXT_subtexture();
		}
		if (DynamicGL_TexSubImage1DEXT==0) return false; 
		if (DynamicGL_TexSubImage2DEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_subtexture*/

/*SGIX_subsample*/
#ifdef USE_DYNAMIC_GL_SGIX_subsample
static bool DinamicGLFeature_SGIX_subsample_loaded = false; 
static void InitDinamicGLFeature_SGIX_subsample() {
		DinamicGLFeature_SGIX_subsample_loaded = true; 
}
bool DinamicGLFeature_SGIX_subsample_Supported() {
		if (!DinamicGLFeature_SGIX_subsample_loaded) {
			InitDinamicGLFeature_SGIX_subsample();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_subsample*/

/*GREMEDY_string_marker*/
#ifdef USE_DYNAMIC_GL_GREMEDY_string_marker
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_StringMarkerGREMEDY)(GLsizei len , const GLvoid *string) = 0; }
static bool DinamicGLFeature_GREMEDY_string_marker_loaded = false; 
static void InitDinamicGLFeature_GREMEDY_string_marker() {
		DynamicGL_StringMarkerGREMEDY = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei len , const GLvoid *string)>("glStringMarkerGREMEDY"); 
		DinamicGLFeature_GREMEDY_string_marker_loaded = true; 
}
bool DinamicGLFeature_GREMEDY_string_marker_Supported() {
		if (!DinamicGLFeature_GREMEDY_string_marker_loaded) {
			InitDinamicGLFeature_GREMEDY_string_marker();
		}
		if (DynamicGL_StringMarkerGREMEDY==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_GREMEDY_string_marker*/

/*ARB_draw_instanced*/
#ifdef USE_DYNAMIC_GL_ARB_draw_instanced
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawArraysInstancedARB)(GLenum mode , GLint first , GLsizei count , GLsizei primcount) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawElementsInstancedARB)(GLenum mode , GLsizei count , GLenum type , const GLvoid *indices , GLsizei primcount) = 0; }
static bool DinamicGLFeature_ARB_draw_instanced_loaded = false; 
static void InitDinamicGLFeature_ARB_draw_instanced() {
		DynamicGL_DrawArraysInstancedARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , GLint first , GLsizei count , GLsizei primcount)>("glDrawArraysInstancedARB"); 
		DynamicGL_DrawElementsInstancedARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , GLsizei count , GLenum type , const GLvoid *indices , GLsizei primcount)>("glDrawElementsInstancedARB"); 
		DinamicGLFeature_ARB_draw_instanced_loaded = true; 
}
bool DinamicGLFeature_ARB_draw_instanced_Supported() {
		if (!DinamicGLFeature_ARB_draw_instanced_loaded) {
			InitDinamicGLFeature_ARB_draw_instanced();
		}
		if (DynamicGL_DrawArraysInstancedARB==0) return false; 
		if (DynamicGL_DrawElementsInstancedARB==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_draw_instanced*/

/*ARB_occlusion_query*/
#ifdef USE_DYNAMIC_GL_ARB_occlusion_query
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GenQueriesARB)(GLsizei n , GLuint *ids) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteQueriesARB)(GLsizei n , const GLuint *ids) = 0; }
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsQueryARB)(GLuint id) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BeginQueryARB)(GLenum target , GLuint id) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EndQueryARB)(GLenum target) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetQueryivARB)(GLenum target , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetQueryObjectivARB)(GLuint id , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetQueryObjectuivARB)(GLuint id , GLenum pname , GLuint *params) = 0; }
static bool DinamicGLFeature_ARB_occlusion_query_loaded = false; 
static void InitDinamicGLFeature_ARB_occlusion_query() {
		DynamicGL_GenQueriesARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , GLuint *ids)>("glGenQueriesARB"); 
		DynamicGL_DeleteQueriesARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , const GLuint *ids)>("glDeleteQueriesARB"); 
		DynamicGL_IsQueryARB = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLuint id)>("glIsQueryARB"); 
		DynamicGL_BeginQueryARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint id)>("glBeginQueryARB"); 
		DynamicGL_EndQueryARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target)>("glEndQueryARB"); 
		DynamicGL_GetQueryivARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint *params)>("glGetQueryivARB"); 
		DynamicGL_GetQueryObjectivARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , GLenum pname , GLint *params)>("glGetQueryObjectivARB"); 
		DynamicGL_GetQueryObjectuivARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , GLenum pname , GLuint *params)>("glGetQueryObjectuivARB"); 
		DinamicGLFeature_ARB_occlusion_query_loaded = true; 
}
bool DinamicGLFeature_ARB_occlusion_query_Supported() {
		if (!DinamicGLFeature_ARB_occlusion_query_loaded) {
			InitDinamicGLFeature_ARB_occlusion_query();
		}
		if (DynamicGL_GenQueriesARB==0) return false; 
		if (DynamicGL_DeleteQueriesARB==0) return false; 
		if (DynamicGL_IsQueryARB==0) return false; 
		if (DynamicGL_BeginQueryARB==0) return false; 
		if (DynamicGL_EndQueryARB==0) return false; 
		if (DynamicGL_GetQueryivARB==0) return false; 
		if (DynamicGL_GetQueryObjectivARB==0) return false; 
		if (DynamicGL_GetQueryObjectuivARB==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_occlusion_query*/

/*ATI_fragment_shader*/
#ifdef USE_DYNAMIC_GL_ATI_fragment_shader
extern "C" { GLuint (DYNAMIC_GL_APIENTRYP DynamicGL_GenFragmentShadersATI)(GLuint range) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BindFragmentShaderATI)(GLuint id) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteFragmentShaderATI)(GLuint id) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BeginFragmentShaderATI)() = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EndFragmentShaderATI)() = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PassTexCoordATI)(GLuint dst , GLuint coord , GLenum swizzle) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SampleMapATI)(GLuint dst , GLuint interp , GLenum swizzle) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorFragmentOp1ATI)(GLenum op , GLuint dst , GLuint dstMask , GLuint dstMod , GLuint arg1 , GLuint arg1Rep , GLuint arg1Mod) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorFragmentOp2ATI)(GLenum op , GLuint dst , GLuint dstMask , GLuint dstMod , GLuint arg1 , GLuint arg1Rep , GLuint arg1Mod , GLuint arg2 , GLuint arg2Rep , GLuint arg2Mod) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorFragmentOp3ATI)(GLenum op , GLuint dst , GLuint dstMask , GLuint dstMod , GLuint arg1 , GLuint arg1Rep , GLuint arg1Mod , GLuint arg2 , GLuint arg2Rep , GLuint arg2Mod , GLuint arg3 , GLuint arg3Rep , GLuint arg3Mod) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_AlphaFragmentOp1ATI)(GLenum op , GLuint dst , GLuint dstMod , GLuint arg1 , GLuint arg1Rep , GLuint arg1Mod) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_AlphaFragmentOp2ATI)(GLenum op , GLuint dst , GLuint dstMod , GLuint arg1 , GLuint arg1Rep , GLuint arg1Mod , GLuint arg2 , GLuint arg2Rep , GLuint arg2Mod) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_AlphaFragmentOp3ATI)(GLenum op , GLuint dst , GLuint dstMod , GLuint arg1 , GLuint arg1Rep , GLuint arg1Mod , GLuint arg2 , GLuint arg2Rep , GLuint arg2Mod , GLuint arg3 , GLuint arg3Rep , GLuint arg3Mod) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SetFragmentShaderConstantATI)(GLuint dst , const GLfloat *value) = 0; }
static bool DinamicGLFeature_ATI_fragment_shader_loaded = false; 
static void InitDinamicGLFeature_ATI_fragment_shader() {
		DynamicGL_GenFragmentShadersATI = DynamicGL_LoadFunction<GLuint (DYNAMIC_GL_APIENTRYP)(GLuint range)>("glGenFragmentShadersATI"); 
		DynamicGL_BindFragmentShaderATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id)>("glBindFragmentShaderATI"); 
		DynamicGL_DeleteFragmentShaderATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id)>("glDeleteFragmentShaderATI"); 
		DynamicGL_BeginFragmentShaderATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glBeginFragmentShaderATI"); 
		DynamicGL_EndFragmentShaderATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glEndFragmentShaderATI"); 
		DynamicGL_PassTexCoordATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint dst , GLuint coord , GLenum swizzle)>("glPassTexCoordATI"); 
		DynamicGL_SampleMapATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint dst , GLuint interp , GLenum swizzle)>("glSampleMapATI"); 
		DynamicGL_ColorFragmentOp1ATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum op , GLuint dst , GLuint dstMask , GLuint dstMod , GLuint arg1 , GLuint arg1Rep , GLuint arg1Mod)>("glColorFragmentOp1ATI"); 
		DynamicGL_ColorFragmentOp2ATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum op , GLuint dst , GLuint dstMask , GLuint dstMod , GLuint arg1 , GLuint arg1Rep , GLuint arg1Mod , GLuint arg2 , GLuint arg2Rep , GLuint arg2Mod)>("glColorFragmentOp2ATI"); 
		DynamicGL_ColorFragmentOp3ATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum op , GLuint dst , GLuint dstMask , GLuint dstMod , GLuint arg1 , GLuint arg1Rep , GLuint arg1Mod , GLuint arg2 , GLuint arg2Rep , GLuint arg2Mod , GLuint arg3 , GLuint arg3Rep , GLuint arg3Mod)>("glColorFragmentOp3ATI"); 
		DynamicGL_AlphaFragmentOp1ATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum op , GLuint dst , GLuint dstMod , GLuint arg1 , GLuint arg1Rep , GLuint arg1Mod)>("glAlphaFragmentOp1ATI"); 
		DynamicGL_AlphaFragmentOp2ATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum op , GLuint dst , GLuint dstMod , GLuint arg1 , GLuint arg1Rep , GLuint arg1Mod , GLuint arg2 , GLuint arg2Rep , GLuint arg2Mod)>("glAlphaFragmentOp2ATI"); 
		DynamicGL_AlphaFragmentOp3ATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum op , GLuint dst , GLuint dstMod , GLuint arg1 , GLuint arg1Rep , GLuint arg1Mod , GLuint arg2 , GLuint arg2Rep , GLuint arg2Mod , GLuint arg3 , GLuint arg3Rep , GLuint arg3Mod)>("glAlphaFragmentOp3ATI"); 
		DynamicGL_SetFragmentShaderConstantATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint dst , const GLfloat *value)>("glSetFragmentShaderConstantATI"); 
		DinamicGLFeature_ATI_fragment_shader_loaded = true; 
}
bool DinamicGLFeature_ATI_fragment_shader_Supported() {
		if (!DinamicGLFeature_ATI_fragment_shader_loaded) {
			InitDinamicGLFeature_ATI_fragment_shader();
		}
		if (DynamicGL_GenFragmentShadersATI==0) return false; 
		if (DynamicGL_BindFragmentShaderATI==0) return false; 
		if (DynamicGL_DeleteFragmentShaderATI==0) return false; 
		if (DynamicGL_BeginFragmentShaderATI==0) return false; 
		if (DynamicGL_EndFragmentShaderATI==0) return false; 
		if (DynamicGL_PassTexCoordATI==0) return false; 
		if (DynamicGL_SampleMapATI==0) return false; 
		if (DynamicGL_ColorFragmentOp1ATI==0) return false; 
		if (DynamicGL_ColorFragmentOp2ATI==0) return false; 
		if (DynamicGL_ColorFragmentOp3ATI==0) return false; 
		if (DynamicGL_AlphaFragmentOp1ATI==0) return false; 
		if (DynamicGL_AlphaFragmentOp2ATI==0) return false; 
		if (DynamicGL_AlphaFragmentOp3ATI==0) return false; 
		if (DynamicGL_SetFragmentShaderConstantATI==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_ATI_fragment_shader*/

/*NV_depth_buffer_float*/
#ifdef USE_DYNAMIC_GL_NV_depth_buffer_float
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DepthRangedNV)(GLdouble zNear , GLdouble zFar) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearDepthdNV)(GLdouble depth) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DepthBoundsdNV)(GLdouble zmin , GLdouble zmax) = 0; }
static bool DinamicGLFeature_NV_depth_buffer_float_loaded = false; 
static void InitDinamicGLFeature_NV_depth_buffer_float() {
		DynamicGL_DepthRangedNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble zNear , GLdouble zFar)>("glDepthRangedNV"); 
		DynamicGL_ClearDepthdNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble depth)>("glClearDepthdNV"); 
		DynamicGL_DepthBoundsdNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble zmin , GLdouble zmax)>("glDepthBoundsdNV"); 
		DinamicGLFeature_NV_depth_buffer_float_loaded = true; 
}
bool DinamicGLFeature_NV_depth_buffer_float_Supported() {
		if (!DinamicGLFeature_NV_depth_buffer_float_loaded) {
			InitDinamicGLFeature_NV_depth_buffer_float();
		}
		if (DynamicGL_DepthRangedNV==0) return false; 
		if (DynamicGL_ClearDepthdNV==0) return false; 
		if (DynamicGL_DepthBoundsdNV==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_depth_buffer_float*/

/*NV_pixel_data_range*/
#ifdef USE_DYNAMIC_GL_NV_pixel_data_range
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelDataRangeNV)(GLenum target , GLsizei length , GLvoid *pointer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FlushPixelDataRangeNV)(GLenum target) = 0; }
static bool DinamicGLFeature_NV_pixel_data_range_loaded = false; 
static void InitDinamicGLFeature_NV_pixel_data_range() {
		DynamicGL_PixelDataRangeNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLsizei length , GLvoid *pointer)>("glPixelDataRangeNV"); 
		DynamicGL_FlushPixelDataRangeNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target)>("glFlushPixelDataRangeNV"); 
		DinamicGLFeature_NV_pixel_data_range_loaded = true; 
}
bool DinamicGLFeature_NV_pixel_data_range_Supported() {
		if (!DinamicGLFeature_NV_pixel_data_range_loaded) {
			InitDinamicGLFeature_NV_pixel_data_range();
		}
		if (DynamicGL_PixelDataRangeNV==0) return false; 
		if (DynamicGL_FlushPixelDataRangeNV==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_pixel_data_range*/

/*SGI_color_matrix*/
#ifdef USE_DYNAMIC_GL_SGI_color_matrix
static bool DinamicGLFeature_SGI_color_matrix_loaded = false; 
static void InitDinamicGLFeature_SGI_color_matrix() {
		DinamicGLFeature_SGI_color_matrix_loaded = true; 
}
bool DinamicGLFeature_SGI_color_matrix_Supported() {
		if (!DinamicGLFeature_SGI_color_matrix_loaded) {
			InitDinamicGLFeature_SGI_color_matrix();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGI_color_matrix*/

/*EXT_texture_sRGB*/
#ifdef USE_DYNAMIC_GL_EXT_texture_sRGB
static bool DinamicGLFeature_EXT_texture_sRGB_loaded = false; 
static void InitDinamicGLFeature_EXT_texture_sRGB() {
		DinamicGLFeature_EXT_texture_sRGB_loaded = true; 
}
bool DinamicGLFeature_EXT_texture_sRGB_Supported() {
		if (!DinamicGLFeature_EXT_texture_sRGB_loaded) {
			InitDinamicGLFeature_EXT_texture_sRGB();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_texture_sRGB*/

/*NV_depth_clamp*/
#ifdef USE_DYNAMIC_GL_NV_depth_clamp
static bool DinamicGLFeature_NV_depth_clamp_loaded = false; 
static void InitDinamicGLFeature_NV_depth_clamp() {
		DinamicGLFeature_NV_depth_clamp_loaded = true; 
}
bool DinamicGLFeature_NV_depth_clamp_Supported() {
		if (!DinamicGLFeature_NV_depth_clamp_loaded) {
			InitDinamicGLFeature_NV_depth_clamp();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_depth_clamp*/

/*ARB_half_float_vertex*/
#ifdef USE_DYNAMIC_GL_ARB_half_float_vertex
static bool DinamicGLFeature_ARB_half_float_vertex_loaded = false; 
static void InitDinamicGLFeature_ARB_half_float_vertex() {
		DinamicGLFeature_ARB_half_float_vertex_loaded = true; 
}
bool DinamicGLFeature_ARB_half_float_vertex_Supported() {
		if (!DinamicGLFeature_ARB_half_float_vertex_loaded) {
			InitDinamicGLFeature_ARB_half_float_vertex();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_half_float_vertex*/

/*NV_vertex_program*/
#ifdef USE_DYNAMIC_GL_NV_vertex_program
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_AreProgramsResidentNV)(GLsizei n , const GLuint *programs , GLboolean *residences) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BindProgramNV)(GLenum target , GLuint id) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteProgramsNV)(GLsizei n , const GLuint *programs) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ExecuteProgramNV)(GLenum target , GLuint id , const GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GenProgramsNV)(GLsizei n , GLuint *programs) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramParameterdvNV)(GLenum target , GLuint index , GLenum pname , GLdouble *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramParameterfvNV)(GLenum target , GLuint index , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramivNV)(GLuint id , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramStringNV)(GLuint id , GLenum pname , GLubyte *program) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTrackMatrixivNV)(GLenum target , GLuint address , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribdvNV)(GLuint index , GLenum pname , GLdouble *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribfvNV)(GLuint index , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribivNV)(GLuint index , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribPointervNV)(GLuint index , GLenum pname , GLvoid* *pointer) = 0; }
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsProgramNV)(GLuint id) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_LoadProgramNV)(GLenum target , GLuint id , GLsizei len , const GLubyte *program) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramParameter4dNV)(GLenum target , GLuint index , GLdouble x , GLdouble y , GLdouble z , GLdouble w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramParameter4dvNV)(GLenum target , GLuint index , const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramParameter4fNV)(GLenum target , GLuint index , GLfloat x , GLfloat y , GLfloat z , GLfloat w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramParameter4fvNV)(GLenum target , GLuint index , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramParameters4dvNV)(GLenum target , GLuint index , GLuint count , const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramParameters4fvNV)(GLenum target , GLuint index , GLuint count , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_RequestResidentProgramsNV)(GLsizei n , const GLuint *programs) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TrackMatrixNV)(GLenum target , GLuint address , GLenum matrix , GLenum transform) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribPointerNV)(GLuint index , GLint fsize , GLenum type , GLsizei stride , const GLvoid *pointer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1dNV)(GLuint index , GLdouble x) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1dvNV)(GLuint index , const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1fNV)(GLuint index , GLfloat x) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1fvNV)(GLuint index , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1sNV)(GLuint index , GLshort x) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1svNV)(GLuint index , const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2dNV)(GLuint index , GLdouble x , GLdouble y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2dvNV)(GLuint index , const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2fNV)(GLuint index , GLfloat x , GLfloat y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2fvNV)(GLuint index , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2sNV)(GLuint index , GLshort x , GLshort y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2svNV)(GLuint index , const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3dNV)(GLuint index , GLdouble x , GLdouble y , GLdouble z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3dvNV)(GLuint index , const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3fNV)(GLuint index , GLfloat x , GLfloat y , GLfloat z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3fvNV)(GLuint index , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3sNV)(GLuint index , GLshort x , GLshort y , GLshort z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3svNV)(GLuint index , const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4dNV)(GLuint index , GLdouble x , GLdouble y , GLdouble z , GLdouble w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4dvNV)(GLuint index , const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4fNV)(GLuint index , GLfloat x , GLfloat y , GLfloat z , GLfloat w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4fvNV)(GLuint index , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4sNV)(GLuint index , GLshort x , GLshort y , GLshort z , GLshort w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4svNV)(GLuint index , const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4ubNV)(GLuint index , GLubyte x , GLubyte y , GLubyte z , GLubyte w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4ubvNV)(GLuint index , const GLubyte *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribs1dvNV)(GLuint index , GLsizei count , const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribs1fvNV)(GLuint index , GLsizei count , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribs1svNV)(GLuint index , GLsizei count , const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribs2dvNV)(GLuint index , GLsizei count , const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribs2fvNV)(GLuint index , GLsizei count , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribs2svNV)(GLuint index , GLsizei count , const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribs3dvNV)(GLuint index , GLsizei count , const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribs3fvNV)(GLuint index , GLsizei count , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribs3svNV)(GLuint index , GLsizei count , const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribs4dvNV)(GLuint index , GLsizei count , const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribs4fvNV)(GLuint index , GLsizei count , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribs4svNV)(GLuint index , GLsizei count , const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribs4ubvNV)(GLuint index , GLsizei count , const GLubyte *v) = 0; }
static bool DinamicGLFeature_NV_vertex_program_loaded = false; 
static void InitDinamicGLFeature_NV_vertex_program() {
		DynamicGL_AreProgramsResidentNV = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLsizei n , const GLuint *programs , GLboolean *residences)>("glAreProgramsResidentNV"); 
		DynamicGL_BindProgramNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint id)>("glBindProgramNV"); 
		DynamicGL_DeleteProgramsNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , const GLuint *programs)>("glDeleteProgramsNV"); 
		DynamicGL_ExecuteProgramNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint id , const GLfloat *params)>("glExecuteProgramNV"); 
		DynamicGL_GenProgramsNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , GLuint *programs)>("glGenProgramsNV"); 
		DynamicGL_GetProgramParameterdvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLenum pname , GLdouble *params)>("glGetProgramParameterdvNV"); 
		DynamicGL_GetProgramParameterfvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLenum pname , GLfloat *params)>("glGetProgramParameterfvNV"); 
		DynamicGL_GetProgramivNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , GLenum pname , GLint *params)>("glGetProgramivNV"); 
		DynamicGL_GetProgramStringNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , GLenum pname , GLubyte *program)>("glGetProgramStringNV"); 
		DynamicGL_GetTrackMatrixivNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint address , GLenum pname , GLint *params)>("glGetTrackMatrixivNV"); 
		DynamicGL_GetVertexAttribdvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLenum pname , GLdouble *params)>("glGetVertexAttribdvNV"); 
		DynamicGL_GetVertexAttribfvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLenum pname , GLfloat *params)>("glGetVertexAttribfvNV"); 
		DynamicGL_GetVertexAttribivNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLenum pname , GLint *params)>("glGetVertexAttribivNV"); 
		DynamicGL_GetVertexAttribPointervNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLenum pname , GLvoid* *pointer)>("glGetVertexAttribPointervNV"); 
		DynamicGL_IsProgramNV = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLuint id)>("glIsProgramNV"); 
		DynamicGL_LoadProgramNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint id , GLsizei len , const GLubyte *program)>("glLoadProgramNV"); 
		DynamicGL_ProgramParameter4dNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLdouble x , GLdouble y , GLdouble z , GLdouble w)>("glProgramParameter4dNV"); 
		DynamicGL_ProgramParameter4dvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , const GLdouble *v)>("glProgramParameter4dvNV"); 
		DynamicGL_ProgramParameter4fNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLfloat x , GLfloat y , GLfloat z , GLfloat w)>("glProgramParameter4fNV"); 
		DynamicGL_ProgramParameter4fvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , const GLfloat *v)>("glProgramParameter4fvNV"); 
		DynamicGL_ProgramParameters4dvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLuint count , const GLdouble *v)>("glProgramParameters4dvNV"); 
		DynamicGL_ProgramParameters4fvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLuint count , const GLfloat *v)>("glProgramParameters4fvNV"); 
		DynamicGL_RequestResidentProgramsNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , const GLuint *programs)>("glRequestResidentProgramsNV"); 
		DynamicGL_TrackMatrixNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint address , GLenum matrix , GLenum transform)>("glTrackMatrixNV"); 
		DynamicGL_VertexAttribPointerNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLint fsize , GLenum type , GLsizei stride , const GLvoid *pointer)>("glVertexAttribPointerNV"); 
		DynamicGL_VertexAttrib1dNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLdouble x)>("glVertexAttrib1dNV"); 
		DynamicGL_VertexAttrib1dvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLdouble *v)>("glVertexAttrib1dvNV"); 
		DynamicGL_VertexAttrib1fNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLfloat x)>("glVertexAttrib1fNV"); 
		DynamicGL_VertexAttrib1fvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLfloat *v)>("glVertexAttrib1fvNV"); 
		DynamicGL_VertexAttrib1sNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLshort x)>("glVertexAttrib1sNV"); 
		DynamicGL_VertexAttrib1svNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLshort *v)>("glVertexAttrib1svNV"); 
		DynamicGL_VertexAttrib2dNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLdouble x , GLdouble y)>("glVertexAttrib2dNV"); 
		DynamicGL_VertexAttrib2dvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLdouble *v)>("glVertexAttrib2dvNV"); 
		DynamicGL_VertexAttrib2fNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLfloat x , GLfloat y)>("glVertexAttrib2fNV"); 
		DynamicGL_VertexAttrib2fvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLfloat *v)>("glVertexAttrib2fvNV"); 
		DynamicGL_VertexAttrib2sNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLshort x , GLshort y)>("glVertexAttrib2sNV"); 
		DynamicGL_VertexAttrib2svNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLshort *v)>("glVertexAttrib2svNV"); 
		DynamicGL_VertexAttrib3dNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLdouble x , GLdouble y , GLdouble z)>("glVertexAttrib3dNV"); 
		DynamicGL_VertexAttrib3dvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLdouble *v)>("glVertexAttrib3dvNV"); 
		DynamicGL_VertexAttrib3fNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLfloat x , GLfloat y , GLfloat z)>("glVertexAttrib3fNV"); 
		DynamicGL_VertexAttrib3fvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLfloat *v)>("glVertexAttrib3fvNV"); 
		DynamicGL_VertexAttrib3sNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLshort x , GLshort y , GLshort z)>("glVertexAttrib3sNV"); 
		DynamicGL_VertexAttrib3svNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLshort *v)>("glVertexAttrib3svNV"); 
		DynamicGL_VertexAttrib4dNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLdouble x , GLdouble y , GLdouble z , GLdouble w)>("glVertexAttrib4dNV"); 
		DynamicGL_VertexAttrib4dvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLdouble *v)>("glVertexAttrib4dvNV"); 
		DynamicGL_VertexAttrib4fNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLfloat x , GLfloat y , GLfloat z , GLfloat w)>("glVertexAttrib4fNV"); 
		DynamicGL_VertexAttrib4fvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLfloat *v)>("glVertexAttrib4fvNV"); 
		DynamicGL_VertexAttrib4sNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLshort x , GLshort y , GLshort z , GLshort w)>("glVertexAttrib4sNV"); 
		DynamicGL_VertexAttrib4svNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLshort *v)>("glVertexAttrib4svNV"); 
		DynamicGL_VertexAttrib4ubNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLubyte x , GLubyte y , GLubyte z , GLubyte w)>("glVertexAttrib4ubNV"); 
		DynamicGL_VertexAttrib4ubvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLubyte *v)>("glVertexAttrib4ubvNV"); 
		DynamicGL_VertexAttribs1dvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLsizei count , const GLdouble *v)>("glVertexAttribs1dvNV"); 
		DynamicGL_VertexAttribs1fvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLsizei count , const GLfloat *v)>("glVertexAttribs1fvNV"); 
		DynamicGL_VertexAttribs1svNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLsizei count , const GLshort *v)>("glVertexAttribs1svNV"); 
		DynamicGL_VertexAttribs2dvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLsizei count , const GLdouble *v)>("glVertexAttribs2dvNV"); 
		DynamicGL_VertexAttribs2fvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLsizei count , const GLfloat *v)>("glVertexAttribs2fvNV"); 
		DynamicGL_VertexAttribs2svNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLsizei count , const GLshort *v)>("glVertexAttribs2svNV"); 
		DynamicGL_VertexAttribs3dvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLsizei count , const GLdouble *v)>("glVertexAttribs3dvNV"); 
		DynamicGL_VertexAttribs3fvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLsizei count , const GLfloat *v)>("glVertexAttribs3fvNV"); 
		DynamicGL_VertexAttribs3svNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLsizei count , const GLshort *v)>("glVertexAttribs3svNV"); 
		DynamicGL_VertexAttribs4dvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLsizei count , const GLdouble *v)>("glVertexAttribs4dvNV"); 
		DynamicGL_VertexAttribs4fvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLsizei count , const GLfloat *v)>("glVertexAttribs4fvNV"); 
		DynamicGL_VertexAttribs4svNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLsizei count , const GLshort *v)>("glVertexAttribs4svNV"); 
		DynamicGL_VertexAttribs4ubvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLsizei count , const GLubyte *v)>("glVertexAttribs4ubvNV"); 
		DinamicGLFeature_NV_vertex_program_loaded = true; 
}
bool DinamicGLFeature_NV_vertex_program_Supported() {
		if (!DinamicGLFeature_NV_vertex_program_loaded) {
			InitDinamicGLFeature_NV_vertex_program();
		}
		if (DynamicGL_AreProgramsResidentNV==0) return false; 
		if (DynamicGL_BindProgramNV==0) return false; 
		if (DynamicGL_DeleteProgramsNV==0) return false; 
		if (DynamicGL_ExecuteProgramNV==0) return false; 
		if (DynamicGL_GenProgramsNV==0) return false; 
		if (DynamicGL_GetProgramParameterdvNV==0) return false; 
		if (DynamicGL_GetProgramParameterfvNV==0) return false; 
		if (DynamicGL_GetProgramivNV==0) return false; 
		if (DynamicGL_GetProgramStringNV==0) return false; 
		if (DynamicGL_GetTrackMatrixivNV==0) return false; 
		if (DynamicGL_GetVertexAttribdvNV==0) return false; 
		if (DynamicGL_GetVertexAttribfvNV==0) return false; 
		if (DynamicGL_GetVertexAttribivNV==0) return false; 
		if (DynamicGL_GetVertexAttribPointervNV==0) return false; 
		if (DynamicGL_IsProgramNV==0) return false; 
		if (DynamicGL_LoadProgramNV==0) return false; 
		if (DynamicGL_ProgramParameter4dNV==0) return false; 
		if (DynamicGL_ProgramParameter4dvNV==0) return false; 
		if (DynamicGL_ProgramParameter4fNV==0) return false; 
		if (DynamicGL_ProgramParameter4fvNV==0) return false; 
		if (DynamicGL_ProgramParameters4dvNV==0) return false; 
		if (DynamicGL_ProgramParameters4fvNV==0) return false; 
		if (DynamicGL_RequestResidentProgramsNV==0) return false; 
		if (DynamicGL_TrackMatrixNV==0) return false; 
		if (DynamicGL_VertexAttribPointerNV==0) return false; 
		if (DynamicGL_VertexAttrib1dNV==0) return false; 
		if (DynamicGL_VertexAttrib1dvNV==0) return false; 
		if (DynamicGL_VertexAttrib1fNV==0) return false; 
		if (DynamicGL_VertexAttrib1fvNV==0) return false; 
		if (DynamicGL_VertexAttrib1sNV==0) return false; 
		if (DynamicGL_VertexAttrib1svNV==0) return false; 
		if (DynamicGL_VertexAttrib2dNV==0) return false; 
		if (DynamicGL_VertexAttrib2dvNV==0) return false; 
		if (DynamicGL_VertexAttrib2fNV==0) return false; 
		if (DynamicGL_VertexAttrib2fvNV==0) return false; 
		if (DynamicGL_VertexAttrib2sNV==0) return false; 
		if (DynamicGL_VertexAttrib2svNV==0) return false; 
		if (DynamicGL_VertexAttrib3dNV==0) return false; 
		if (DynamicGL_VertexAttrib3dvNV==0) return false; 
		if (DynamicGL_VertexAttrib3fNV==0) return false; 
		if (DynamicGL_VertexAttrib3fvNV==0) return false; 
		if (DynamicGL_VertexAttrib3sNV==0) return false; 
		if (DynamicGL_VertexAttrib3svNV==0) return false; 
		if (DynamicGL_VertexAttrib4dNV==0) return false; 
		if (DynamicGL_VertexAttrib4dvNV==0) return false; 
		if (DynamicGL_VertexAttrib4fNV==0) return false; 
		if (DynamicGL_VertexAttrib4fvNV==0) return false; 
		if (DynamicGL_VertexAttrib4sNV==0) return false; 
		if (DynamicGL_VertexAttrib4svNV==0) return false; 
		if (DynamicGL_VertexAttrib4ubNV==0) return false; 
		if (DynamicGL_VertexAttrib4ubvNV==0) return false; 
		if (DynamicGL_VertexAttribs1dvNV==0) return false; 
		if (DynamicGL_VertexAttribs1fvNV==0) return false; 
		if (DynamicGL_VertexAttribs1svNV==0) return false; 
		if (DynamicGL_VertexAttribs2dvNV==0) return false; 
		if (DynamicGL_VertexAttribs2fvNV==0) return false; 
		if (DynamicGL_VertexAttribs2svNV==0) return false; 
		if (DynamicGL_VertexAttribs3dvNV==0) return false; 
		if (DynamicGL_VertexAttribs3fvNV==0) return false; 
		if (DynamicGL_VertexAttribs3svNV==0) return false; 
		if (DynamicGL_VertexAttribs4dvNV==0) return false; 
		if (DynamicGL_VertexAttribs4fvNV==0) return false; 
		if (DynamicGL_VertexAttribs4svNV==0) return false; 
		if (DynamicGL_VertexAttribs4ubvNV==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_vertex_program*/

/*MESA_window_pos*/
#ifdef USE_DYNAMIC_GL_MESA_window_pos
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2dMESA)(GLdouble x , GLdouble y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2dvMESA)(const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2fMESA)(GLfloat x , GLfloat y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2fvMESA)(const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2iMESA)(GLint x , GLint y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2ivMESA)(const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2sMESA)(GLshort x , GLshort y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2svMESA)(const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3dMESA)(GLdouble x , GLdouble y , GLdouble z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3dvMESA)(const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3fMESA)(GLfloat x , GLfloat y , GLfloat z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3fvMESA)(const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3iMESA)(GLint x , GLint y , GLint z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3ivMESA)(const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3sMESA)(GLshort x , GLshort y , GLshort z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3svMESA)(const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos4dMESA)(GLdouble x , GLdouble y , GLdouble z , GLdouble w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos4dvMESA)(const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos4fMESA)(GLfloat x , GLfloat y , GLfloat z , GLfloat w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos4fvMESA)(const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos4iMESA)(GLint x , GLint y , GLint z , GLint w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos4ivMESA)(const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos4sMESA)(GLshort x , GLshort y , GLshort z , GLshort w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos4svMESA)(const GLshort *v) = 0; }
static bool DinamicGLFeature_MESA_window_pos_loaded = false; 
static void InitDinamicGLFeature_MESA_window_pos() {
		DynamicGL_WindowPos2dMESA = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble x , GLdouble y)>("glWindowPos2dMESA"); 
		DynamicGL_WindowPos2dvMESA = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *v)>("glWindowPos2dvMESA"); 
		DynamicGL_WindowPos2fMESA = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat x , GLfloat y)>("glWindowPos2fMESA"); 
		DynamicGL_WindowPos2fvMESA = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *v)>("glWindowPos2fvMESA"); 
		DynamicGL_WindowPos2iMESA = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint x , GLint y)>("glWindowPos2iMESA"); 
		DynamicGL_WindowPos2ivMESA = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLint *v)>("glWindowPos2ivMESA"); 
		DynamicGL_WindowPos2sMESA = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLshort x , GLshort y)>("glWindowPos2sMESA"); 
		DynamicGL_WindowPos2svMESA = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLshort *v)>("glWindowPos2svMESA"); 
		DynamicGL_WindowPos3dMESA = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble x , GLdouble y , GLdouble z)>("glWindowPos3dMESA"); 
		DynamicGL_WindowPos3dvMESA = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *v)>("glWindowPos3dvMESA"); 
		DynamicGL_WindowPos3fMESA = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat x , GLfloat y , GLfloat z)>("glWindowPos3fMESA"); 
		DynamicGL_WindowPos3fvMESA = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *v)>("glWindowPos3fvMESA"); 
		DynamicGL_WindowPos3iMESA = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint x , GLint y , GLint z)>("glWindowPos3iMESA"); 
		DynamicGL_WindowPos3ivMESA = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLint *v)>("glWindowPos3ivMESA"); 
		DynamicGL_WindowPos3sMESA = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLshort x , GLshort y , GLshort z)>("glWindowPos3sMESA"); 
		DynamicGL_WindowPos3svMESA = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLshort *v)>("glWindowPos3svMESA"); 
		DynamicGL_WindowPos4dMESA = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble x , GLdouble y , GLdouble z , GLdouble w)>("glWindowPos4dMESA"); 
		DynamicGL_WindowPos4dvMESA = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *v)>("glWindowPos4dvMESA"); 
		DynamicGL_WindowPos4fMESA = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat x , GLfloat y , GLfloat z , GLfloat w)>("glWindowPos4fMESA"); 
		DynamicGL_WindowPos4fvMESA = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *v)>("glWindowPos4fvMESA"); 
		DynamicGL_WindowPos4iMESA = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint x , GLint y , GLint z , GLint w)>("glWindowPos4iMESA"); 
		DynamicGL_WindowPos4ivMESA = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLint *v)>("glWindowPos4ivMESA"); 
		DynamicGL_WindowPos4sMESA = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLshort x , GLshort y , GLshort z , GLshort w)>("glWindowPos4sMESA"); 
		DynamicGL_WindowPos4svMESA = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLshort *v)>("glWindowPos4svMESA"); 
		DinamicGLFeature_MESA_window_pos_loaded = true; 
}
bool DinamicGLFeature_MESA_window_pos_Supported() {
		if (!DinamicGLFeature_MESA_window_pos_loaded) {
			InitDinamicGLFeature_MESA_window_pos();
		}
		if (DynamicGL_WindowPos2dMESA==0) return false; 
		if (DynamicGL_WindowPos2dvMESA==0) return false; 
		if (DynamicGL_WindowPos2fMESA==0) return false; 
		if (DynamicGL_WindowPos2fvMESA==0) return false; 
		if (DynamicGL_WindowPos2iMESA==0) return false; 
		if (DynamicGL_WindowPos2ivMESA==0) return false; 
		if (DynamicGL_WindowPos2sMESA==0) return false; 
		if (DynamicGL_WindowPos2svMESA==0) return false; 
		if (DynamicGL_WindowPos3dMESA==0) return false; 
		if (DynamicGL_WindowPos3dvMESA==0) return false; 
		if (DynamicGL_WindowPos3fMESA==0) return false; 
		if (DynamicGL_WindowPos3fvMESA==0) return false; 
		if (DynamicGL_WindowPos3iMESA==0) return false; 
		if (DynamicGL_WindowPos3ivMESA==0) return false; 
		if (DynamicGL_WindowPos3sMESA==0) return false; 
		if (DynamicGL_WindowPos3svMESA==0) return false; 
		if (DynamicGL_WindowPos4dMESA==0) return false; 
		if (DynamicGL_WindowPos4dvMESA==0) return false; 
		if (DynamicGL_WindowPos4fMESA==0) return false; 
		if (DynamicGL_WindowPos4fvMESA==0) return false; 
		if (DynamicGL_WindowPos4iMESA==0) return false; 
		if (DynamicGL_WindowPos4ivMESA==0) return false; 
		if (DynamicGL_WindowPos4sMESA==0) return false; 
		if (DynamicGL_WindowPos4svMESA==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_MESA_window_pos*/

/*EXT_texture*/
#ifdef USE_DYNAMIC_GL_EXT_texture
static bool DinamicGLFeature_EXT_texture_loaded = false; 
static void InitDinamicGLFeature_EXT_texture() {
		DinamicGLFeature_EXT_texture_loaded = true; 
}
bool DinamicGLFeature_EXT_texture_Supported() {
		if (!DinamicGLFeature_EXT_texture_loaded) {
			InitDinamicGLFeature_EXT_texture();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_texture*/

/*SGIX_tag_sample_buffer*/
#ifdef USE_DYNAMIC_GL_SGIX_tag_sample_buffer
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TagSampleBufferSGIX)() = 0; }
static bool DinamicGLFeature_SGIX_tag_sample_buffer_loaded = false; 
static void InitDinamicGLFeature_SGIX_tag_sample_buffer() {
		DynamicGL_TagSampleBufferSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glTagSampleBufferSGIX"); 
		DinamicGLFeature_SGIX_tag_sample_buffer_loaded = true; 
}
bool DinamicGLFeature_SGIX_tag_sample_buffer_Supported() {
		if (!DinamicGLFeature_SGIX_tag_sample_buffer_loaded) {
			InitDinamicGLFeature_SGIX_tag_sample_buffer();
		}
		if (DynamicGL_TagSampleBufferSGIX==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_tag_sample_buffer*/

/*EXT_texture_env_combine*/
#ifdef USE_DYNAMIC_GL_EXT_texture_env_combine
static bool DinamicGLFeature_EXT_texture_env_combine_loaded = false; 
static void InitDinamicGLFeature_EXT_texture_env_combine() {
		DinamicGLFeature_EXT_texture_env_combine_loaded = true; 
}
bool DinamicGLFeature_EXT_texture_env_combine_Supported() {
		if (!DinamicGLFeature_EXT_texture_env_combine_loaded) {
			InitDinamicGLFeature_EXT_texture_env_combine();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_texture_env_combine*/

/*SGIX_vertex_preclip*/
#ifdef USE_DYNAMIC_GL_SGIX_vertex_preclip
static bool DinamicGLFeature_SGIX_vertex_preclip_loaded = false; 
static void InitDinamicGLFeature_SGIX_vertex_preclip() {
		DinamicGLFeature_SGIX_vertex_preclip_loaded = true; 
}
bool DinamicGLFeature_SGIX_vertex_preclip_Supported() {
		if (!DinamicGLFeature_SGIX_vertex_preclip_loaded) {
			InitDinamicGLFeature_SGIX_vertex_preclip();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_vertex_preclip*/

/*ARB_geometry_shader4*/
#ifdef USE_DYNAMIC_GL_ARB_geometry_shader4
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramParameteriARB)(GLuint program , GLenum pname , GLint value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferTextureARB)(GLenum target , GLenum attachment , GLuint texture , GLint level) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferTextureLayerARB)(GLenum target , GLenum attachment , GLuint texture , GLint level , GLint layer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferTextureFaceARB)(GLenum target , GLenum attachment , GLuint texture , GLint level , GLenum face) = 0; }
static bool DinamicGLFeature_ARB_geometry_shader4_loaded = false; 
static void InitDinamicGLFeature_ARB_geometry_shader4() {
		DynamicGL_ProgramParameteriARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLenum pname , GLint value)>("glProgramParameteriARB"); 
		DynamicGL_FramebufferTextureARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum attachment , GLuint texture , GLint level)>("glFramebufferTextureARB"); 
		DynamicGL_FramebufferTextureLayerARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum attachment , GLuint texture , GLint level , GLint layer)>("glFramebufferTextureLayerARB"); 
		DynamicGL_FramebufferTextureFaceARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum attachment , GLuint texture , GLint level , GLenum face)>("glFramebufferTextureFaceARB"); 
		DinamicGLFeature_ARB_geometry_shader4_loaded = true; 
}
bool DinamicGLFeature_ARB_geometry_shader4_Supported() {
		if (!DinamicGLFeature_ARB_geometry_shader4_loaded) {
			InitDinamicGLFeature_ARB_geometry_shader4();
		}
		if (DynamicGL_ProgramParameteriARB==0) return false; 
		if (DynamicGL_FramebufferTextureARB==0) return false; 
		if (DynamicGL_FramebufferTextureLayerARB==0) return false; 
		if (DynamicGL_FramebufferTextureFaceARB==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_geometry_shader4*/

/*EXT_multi_draw_arrays*/
#ifdef USE_DYNAMIC_GL_EXT_multi_draw_arrays
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiDrawArraysEXT)(GLenum mode , GLint *first , GLsizei *count , GLsizei primcount) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiDrawElementsEXT)(GLenum mode , const GLsizei *count , GLenum type , const GLvoid* *indices , GLsizei primcount) = 0; }
static bool DinamicGLFeature_EXT_multi_draw_arrays_loaded = false; 
static void InitDinamicGLFeature_EXT_multi_draw_arrays() {
		DynamicGL_MultiDrawArraysEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , GLint *first , GLsizei *count , GLsizei primcount)>("glMultiDrawArraysEXT"); 
		DynamicGL_MultiDrawElementsEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , const GLsizei *count , GLenum type , const GLvoid* *indices , GLsizei primcount)>("glMultiDrawElementsEXT"); 
		DinamicGLFeature_EXT_multi_draw_arrays_loaded = true; 
}
bool DinamicGLFeature_EXT_multi_draw_arrays_Supported() {
		if (!DinamicGLFeature_EXT_multi_draw_arrays_loaded) {
			InitDinamicGLFeature_EXT_multi_draw_arrays();
		}
		if (DynamicGL_MultiDrawArraysEXT==0) return false; 
		if (DynamicGL_MultiDrawElementsEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_multi_draw_arrays*/

/*EXT_texture_perturb_normal*/
#ifdef USE_DYNAMIC_GL_EXT_texture_perturb_normal
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureNormalEXT)(GLenum mode) = 0; }
static bool DinamicGLFeature_EXT_texture_perturb_normal_loaded = false; 
static void InitDinamicGLFeature_EXT_texture_perturb_normal() {
		DynamicGL_TextureNormalEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode)>("glTextureNormalEXT"); 
		DinamicGLFeature_EXT_texture_perturb_normal_loaded = true; 
}
bool DinamicGLFeature_EXT_texture_perturb_normal_Supported() {
		if (!DinamicGLFeature_EXT_texture_perturb_normal_loaded) {
			InitDinamicGLFeature_EXT_texture_perturb_normal();
		}
		if (DynamicGL_TextureNormalEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_texture_perturb_normal*/

/*SGIX_sprite*/
#ifdef USE_DYNAMIC_GL_SGIX_sprite
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SpriteParameterfSGIX)(GLenum pname , GLfloat param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SpriteParameterfvSGIX)(GLenum pname , const GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SpriteParameteriSGIX)(GLenum pname , GLint param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SpriteParameterivSGIX)(GLenum pname , const GLint *params) = 0; }
static bool DinamicGLFeature_SGIX_sprite_loaded = false; 
static void InitDinamicGLFeature_SGIX_sprite() {
		DynamicGL_SpriteParameterfSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLfloat param)>("glSpriteParameterfSGIX"); 
		DynamicGL_SpriteParameterfvSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , const GLfloat *params)>("glSpriteParameterfvSGIX"); 
		DynamicGL_SpriteParameteriSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLint param)>("glSpriteParameteriSGIX"); 
		DynamicGL_SpriteParameterivSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , const GLint *params)>("glSpriteParameterivSGIX"); 
		DinamicGLFeature_SGIX_sprite_loaded = true; 
}
bool DinamicGLFeature_SGIX_sprite_Supported() {
		if (!DinamicGLFeature_SGIX_sprite_loaded) {
			InitDinamicGLFeature_SGIX_sprite();
		}
		if (DynamicGL_SpriteParameterfSGIX==0) return false; 
		if (DynamicGL_SpriteParameterfvSGIX==0) return false; 
		if (DynamicGL_SpriteParameteriSGIX==0) return false; 
		if (DynamicGL_SpriteParameterivSGIX==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_sprite*/

/*EXT_draw_buffers2*/
#ifdef USE_DYNAMIC_GL_EXT_draw_buffers2
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorMaskIndexedEXT)(GLuint index , GLboolean r , GLboolean g , GLboolean b , GLboolean a) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetBooleanIndexedvEXT)(GLenum target , GLuint index , GLboolean *data) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetIntegerIndexedvEXT)(GLenum target , GLuint index , GLint *data) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EnableIndexedEXT)(GLenum target , GLuint index) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DisableIndexedEXT)(GLenum target , GLuint index) = 0; }
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsEnabledIndexedEXT)(GLenum target , GLuint index) = 0; }
static bool DinamicGLFeature_EXT_draw_buffers2_loaded = false; 
static void InitDinamicGLFeature_EXT_draw_buffers2() {
		DynamicGL_ColorMaskIndexedEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLboolean r , GLboolean g , GLboolean b , GLboolean a)>("glColorMaskIndexedEXT"); 
		DynamicGL_GetBooleanIndexedvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLboolean *data)>("glGetBooleanIndexedvEXT"); 
		DynamicGL_GetIntegerIndexedvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLint *data)>("glGetIntegerIndexedvEXT"); 
		DynamicGL_EnableIndexedEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index)>("glEnableIndexedEXT"); 
		DynamicGL_DisableIndexedEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index)>("glDisableIndexedEXT"); 
		DynamicGL_IsEnabledIndexedEXT = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index)>("glIsEnabledIndexedEXT"); 
		DinamicGLFeature_EXT_draw_buffers2_loaded = true; 
}
bool DinamicGLFeature_EXT_draw_buffers2_Supported() {
		if (!DinamicGLFeature_EXT_draw_buffers2_loaded) {
			InitDinamicGLFeature_EXT_draw_buffers2();
		}
		if (DynamicGL_ColorMaskIndexedEXT==0) return false; 
		if (DynamicGL_GetBooleanIndexedvEXT==0) return false; 
		if (DynamicGL_GetIntegerIndexedvEXT==0) return false; 
		if (DynamicGL_EnableIndexedEXT==0) return false; 
		if (DynamicGL_DisableIndexedEXT==0) return false; 
		if (DynamicGL_IsEnabledIndexedEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_draw_buffers2*/

/*ARB_texture_rectangle*/
#ifdef USE_DYNAMIC_GL_ARB_texture_rectangle
static bool DinamicGLFeature_ARB_texture_rectangle_loaded = false; 
static void InitDinamicGLFeature_ARB_texture_rectangle() {
		DinamicGLFeature_ARB_texture_rectangle_loaded = true; 
}
bool DinamicGLFeature_ARB_texture_rectangle_Supported() {
		if (!DinamicGLFeature_ARB_texture_rectangle_loaded) {
			InitDinamicGLFeature_ARB_texture_rectangle();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_texture_rectangle*/

/*EXT_packed_pixels*/
#ifdef USE_DYNAMIC_GL_EXT_packed_pixels
static bool DinamicGLFeature_EXT_packed_pixels_loaded = false; 
static void InitDinamicGLFeature_EXT_packed_pixels() {
		DinamicGLFeature_EXT_packed_pixels_loaded = true; 
}
bool DinamicGLFeature_EXT_packed_pixels_Supported() {
		if (!DinamicGLFeature_EXT_packed_pixels_loaded) {
			InitDinamicGLFeature_EXT_packed_pixels();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_packed_pixels*/

/*EXT_texture_env_dot3*/
#ifdef USE_DYNAMIC_GL_EXT_texture_env_dot3
static bool DinamicGLFeature_EXT_texture_env_dot3_loaded = false; 
static void InitDinamicGLFeature_EXT_texture_env_dot3() {
		DinamicGLFeature_EXT_texture_env_dot3_loaded = true; 
}
bool DinamicGLFeature_EXT_texture_env_dot3_Supported() {
		if (!DinamicGLFeature_EXT_texture_env_dot3_loaded) {
			InitDinamicGLFeature_EXT_texture_env_dot3();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_texture_env_dot3*/

/*WIN_phong_shading*/
#ifdef USE_DYNAMIC_GL_WIN_phong_shading
static bool DinamicGLFeature_WIN_phong_shading_loaded = false; 
static void InitDinamicGLFeature_WIN_phong_shading() {
		DinamicGLFeature_WIN_phong_shading_loaded = true; 
}
bool DinamicGLFeature_WIN_phong_shading_Supported() {
		if (!DinamicGLFeature_WIN_phong_shading_loaded) {
			InitDinamicGLFeature_WIN_phong_shading();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_WIN_phong_shading*/

/*ARB_map_buffer_range*/
#ifdef USE_DYNAMIC_GL_ARB_map_buffer_range
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MapBufferRange)(GLenum target , GLintptr offset , GLsizeiptr length , GLbitfield access) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FlushMappedBufferRange)(GLenum target , GLintptr offset , GLsizeiptr length) = 0; }
static bool DinamicGLFeature_ARB_map_buffer_range_loaded = false; 
static void InitDinamicGLFeature_ARB_map_buffer_range() {
		DynamicGL_MapBufferRange = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLintptr offset , GLsizeiptr length , GLbitfield access)>("glMapBufferRange"); 
		DynamicGL_FlushMappedBufferRange = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLintptr offset , GLsizeiptr length)>("glFlushMappedBufferRange"); 
		DinamicGLFeature_ARB_map_buffer_range_loaded = true; 
}
bool DinamicGLFeature_ARB_map_buffer_range_Supported() {
		if (!DinamicGLFeature_ARB_map_buffer_range_loaded) {
			InitDinamicGLFeature_ARB_map_buffer_range();
		}
		if (DynamicGL_MapBufferRange==0) return false; 
		if (DynamicGL_FlushMappedBufferRange==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_map_buffer_range*/

/*EXT_abgr*/
#ifdef USE_DYNAMIC_GL_EXT_abgr
static bool DinamicGLFeature_EXT_abgr_loaded = false; 
static void InitDinamicGLFeature_EXT_abgr() {
		DinamicGLFeature_EXT_abgr_loaded = true; 
}
bool DinamicGLFeature_EXT_abgr_Supported() {
		if (!DinamicGLFeature_EXT_abgr_loaded) {
			InitDinamicGLFeature_EXT_abgr();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_abgr*/

/*EXT_vertex_shader*/
#ifdef USE_DYNAMIC_GL_EXT_vertex_shader
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BeginVertexShaderEXT)() = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EndVertexShaderEXT)() = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BindVertexShaderEXT)(GLuint id) = 0; }
extern "C" { GLuint (DYNAMIC_GL_APIENTRYP DynamicGL_GenVertexShadersEXT)(GLuint range) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteVertexShaderEXT)(GLuint id) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ShaderOp1EXT)(GLenum op , GLuint res , GLuint arg1) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ShaderOp2EXT)(GLenum op , GLuint res , GLuint arg1 , GLuint arg2) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ShaderOp3EXT)(GLenum op , GLuint res , GLuint arg1 , GLuint arg2 , GLuint arg3) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SwizzleEXT)(GLuint res , GLuint in , GLenum outX , GLenum outY , GLenum outZ , GLenum outW) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WriteMaskEXT)(GLuint res , GLuint in , GLenum outX , GLenum outY , GLenum outZ , GLenum outW) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_InsertComponentEXT)(GLuint res , GLuint src , GLuint num) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ExtractComponentEXT)(GLuint res , GLuint src , GLuint num) = 0; }
extern "C" { GLuint (DYNAMIC_GL_APIENTRYP DynamicGL_GenSymbolsEXT)(GLenum datatype , GLenum storagetype , GLenum range , GLuint components) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SetInvariantEXT)(GLuint id , GLenum type , const GLvoid *addr) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SetLocalConstantEXT)(GLuint id , GLenum type , const GLvoid *addr) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VariantbvEXT)(GLuint id , const GLbyte *addr) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VariantsvEXT)(GLuint id , const GLshort *addr) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VariantivEXT)(GLuint id , const GLint *addr) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VariantfvEXT)(GLuint id , const GLfloat *addr) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VariantdvEXT)(GLuint id , const GLdouble *addr) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VariantubvEXT)(GLuint id , const GLubyte *addr) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VariantusvEXT)(GLuint id , const GLushort *addr) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VariantuivEXT)(GLuint id , const GLuint *addr) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VariantPointerEXT)(GLuint id , GLenum type , GLuint stride , const GLvoid *addr) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EnableVariantClientStateEXT)(GLuint id) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DisableVariantClientStateEXT)(GLuint id) = 0; }
extern "C" { GLuint (DYNAMIC_GL_APIENTRYP DynamicGL_BindLightParameterEXT)(GLenum light , GLenum value) = 0; }
extern "C" { GLuint (DYNAMIC_GL_APIENTRYP DynamicGL_BindMaterialParameterEXT)(GLenum face , GLenum value) = 0; }
extern "C" { GLuint (DYNAMIC_GL_APIENTRYP DynamicGL_BindTexGenParameterEXT)(GLenum unit , GLenum coord , GLenum value) = 0; }
extern "C" { GLuint (DYNAMIC_GL_APIENTRYP DynamicGL_BindTextureUnitParameterEXT)(GLenum unit , GLenum value) = 0; }
extern "C" { GLuint (DYNAMIC_GL_APIENTRYP DynamicGL_BindParameterEXT)(GLenum value) = 0; }
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsVariantEnabledEXT)(GLuint id , GLenum cap) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVariantBooleanvEXT)(GLuint id , GLenum value , GLboolean *data) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVariantIntegervEXT)(GLuint id , GLenum value , GLint *data) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVariantFloatvEXT)(GLuint id , GLenum value , GLfloat *data) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVariantPointervEXT)(GLuint id , GLenum value , GLvoid* *data) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetInvariantBooleanvEXT)(GLuint id , GLenum value , GLboolean *data) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetInvariantIntegervEXT)(GLuint id , GLenum value , GLint *data) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetInvariantFloatvEXT)(GLuint id , GLenum value , GLfloat *data) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetLocalConstantBooleanvEXT)(GLuint id , GLenum value , GLboolean *data) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetLocalConstantIntegervEXT)(GLuint id , GLenum value , GLint *data) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetLocalConstantFloatvEXT)(GLuint id , GLenum value , GLfloat *data) = 0; }
static bool DinamicGLFeature_EXT_vertex_shader_loaded = false; 
static void InitDinamicGLFeature_EXT_vertex_shader() {
		DynamicGL_BeginVertexShaderEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glBeginVertexShaderEXT"); 
		DynamicGL_EndVertexShaderEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glEndVertexShaderEXT"); 
		DynamicGL_BindVertexShaderEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id)>("glBindVertexShaderEXT"); 
		DynamicGL_GenVertexShadersEXT = DynamicGL_LoadFunction<GLuint (DYNAMIC_GL_APIENTRYP)(GLuint range)>("glGenVertexShadersEXT"); 
		DynamicGL_DeleteVertexShaderEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id)>("glDeleteVertexShaderEXT"); 
		DynamicGL_ShaderOp1EXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum op , GLuint res , GLuint arg1)>("glShaderOp1EXT"); 
		DynamicGL_ShaderOp2EXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum op , GLuint res , GLuint arg1 , GLuint arg2)>("glShaderOp2EXT"); 
		DynamicGL_ShaderOp3EXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum op , GLuint res , GLuint arg1 , GLuint arg2 , GLuint arg3)>("glShaderOp3EXT"); 
		DynamicGL_SwizzleEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint res , GLuint in , GLenum outX , GLenum outY , GLenum outZ , GLenum outW)>("glSwizzleEXT"); 
		DynamicGL_WriteMaskEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint res , GLuint in , GLenum outX , GLenum outY , GLenum outZ , GLenum outW)>("glWriteMaskEXT"); 
		DynamicGL_InsertComponentEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint res , GLuint src , GLuint num)>("glInsertComponentEXT"); 
		DynamicGL_ExtractComponentEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint res , GLuint src , GLuint num)>("glExtractComponentEXT"); 
		DynamicGL_GenSymbolsEXT = DynamicGL_LoadFunction<GLuint (DYNAMIC_GL_APIENTRYP)(GLenum datatype , GLenum storagetype , GLenum range , GLuint components)>("glGenSymbolsEXT"); 
		DynamicGL_SetInvariantEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , GLenum type , const GLvoid *addr)>("glSetInvariantEXT"); 
		DynamicGL_SetLocalConstantEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , GLenum type , const GLvoid *addr)>("glSetLocalConstantEXT"); 
		DynamicGL_VariantbvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , const GLbyte *addr)>("glVariantbvEXT"); 
		DynamicGL_VariantsvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , const GLshort *addr)>("glVariantsvEXT"); 
		DynamicGL_VariantivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , const GLint *addr)>("glVariantivEXT"); 
		DynamicGL_VariantfvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , const GLfloat *addr)>("glVariantfvEXT"); 
		DynamicGL_VariantdvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , const GLdouble *addr)>("glVariantdvEXT"); 
		DynamicGL_VariantubvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , const GLubyte *addr)>("glVariantubvEXT"); 
		DynamicGL_VariantusvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , const GLushort *addr)>("glVariantusvEXT"); 
		DynamicGL_VariantuivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , const GLuint *addr)>("glVariantuivEXT"); 
		DynamicGL_VariantPointerEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , GLenum type , GLuint stride , const GLvoid *addr)>("glVariantPointerEXT"); 
		DynamicGL_EnableVariantClientStateEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id)>("glEnableVariantClientStateEXT"); 
		DynamicGL_DisableVariantClientStateEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id)>("glDisableVariantClientStateEXT"); 
		DynamicGL_BindLightParameterEXT = DynamicGL_LoadFunction<GLuint (DYNAMIC_GL_APIENTRYP)(GLenum light , GLenum value)>("glBindLightParameterEXT"); 
		DynamicGL_BindMaterialParameterEXT = DynamicGL_LoadFunction<GLuint (DYNAMIC_GL_APIENTRYP)(GLenum face , GLenum value)>("glBindMaterialParameterEXT"); 
		DynamicGL_BindTexGenParameterEXT = DynamicGL_LoadFunction<GLuint (DYNAMIC_GL_APIENTRYP)(GLenum unit , GLenum coord , GLenum value)>("glBindTexGenParameterEXT"); 
		DynamicGL_BindTextureUnitParameterEXT = DynamicGL_LoadFunction<GLuint (DYNAMIC_GL_APIENTRYP)(GLenum unit , GLenum value)>("glBindTextureUnitParameterEXT"); 
		DynamicGL_BindParameterEXT = DynamicGL_LoadFunction<GLuint (DYNAMIC_GL_APIENTRYP)(GLenum value)>("glBindParameterEXT"); 
		DynamicGL_IsVariantEnabledEXT = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLuint id , GLenum cap)>("glIsVariantEnabledEXT"); 
		DynamicGL_GetVariantBooleanvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , GLenum value , GLboolean *data)>("glGetVariantBooleanvEXT"); 
		DynamicGL_GetVariantIntegervEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , GLenum value , GLint *data)>("glGetVariantIntegervEXT"); 
		DynamicGL_GetVariantFloatvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , GLenum value , GLfloat *data)>("glGetVariantFloatvEXT"); 
		DynamicGL_GetVariantPointervEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , GLenum value , GLvoid* *data)>("glGetVariantPointervEXT"); 
		DynamicGL_GetInvariantBooleanvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , GLenum value , GLboolean *data)>("glGetInvariantBooleanvEXT"); 
		DynamicGL_GetInvariantIntegervEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , GLenum value , GLint *data)>("glGetInvariantIntegervEXT"); 
		DynamicGL_GetInvariantFloatvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , GLenum value , GLfloat *data)>("glGetInvariantFloatvEXT"); 
		DynamicGL_GetLocalConstantBooleanvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , GLenum value , GLboolean *data)>("glGetLocalConstantBooleanvEXT"); 
		DynamicGL_GetLocalConstantIntegervEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , GLenum value , GLint *data)>("glGetLocalConstantIntegervEXT"); 
		DynamicGL_GetLocalConstantFloatvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , GLenum value , GLfloat *data)>("glGetLocalConstantFloatvEXT"); 
		DinamicGLFeature_EXT_vertex_shader_loaded = true; 
}
bool DinamicGLFeature_EXT_vertex_shader_Supported() {
		if (!DinamicGLFeature_EXT_vertex_shader_loaded) {
			InitDinamicGLFeature_EXT_vertex_shader();
		}
		if (DynamicGL_BeginVertexShaderEXT==0) return false; 
		if (DynamicGL_EndVertexShaderEXT==0) return false; 
		if (DynamicGL_BindVertexShaderEXT==0) return false; 
		if (DynamicGL_GenVertexShadersEXT==0) return false; 
		if (DynamicGL_DeleteVertexShaderEXT==0) return false; 
		if (DynamicGL_ShaderOp1EXT==0) return false; 
		if (DynamicGL_ShaderOp2EXT==0) return false; 
		if (DynamicGL_ShaderOp3EXT==0) return false; 
		if (DynamicGL_SwizzleEXT==0) return false; 
		if (DynamicGL_WriteMaskEXT==0) return false; 
		if (DynamicGL_InsertComponentEXT==0) return false; 
		if (DynamicGL_ExtractComponentEXT==0) return false; 
		if (DynamicGL_GenSymbolsEXT==0) return false; 
		if (DynamicGL_SetInvariantEXT==0) return false; 
		if (DynamicGL_SetLocalConstantEXT==0) return false; 
		if (DynamicGL_VariantbvEXT==0) return false; 
		if (DynamicGL_VariantsvEXT==0) return false; 
		if (DynamicGL_VariantivEXT==0) return false; 
		if (DynamicGL_VariantfvEXT==0) return false; 
		if (DynamicGL_VariantdvEXT==0) return false; 
		if (DynamicGL_VariantubvEXT==0) return false; 
		if (DynamicGL_VariantusvEXT==0) return false; 
		if (DynamicGL_VariantuivEXT==0) return false; 
		if (DynamicGL_VariantPointerEXT==0) return false; 
		if (DynamicGL_EnableVariantClientStateEXT==0) return false; 
		if (DynamicGL_DisableVariantClientStateEXT==0) return false; 
		if (DynamicGL_BindLightParameterEXT==0) return false; 
		if (DynamicGL_BindMaterialParameterEXT==0) return false; 
		if (DynamicGL_BindTexGenParameterEXT==0) return false; 
		if (DynamicGL_BindTextureUnitParameterEXT==0) return false; 
		if (DynamicGL_BindParameterEXT==0) return false; 
		if (DynamicGL_IsVariantEnabledEXT==0) return false; 
		if (DynamicGL_GetVariantBooleanvEXT==0) return false; 
		if (DynamicGL_GetVariantIntegervEXT==0) return false; 
		if (DynamicGL_GetVariantFloatvEXT==0) return false; 
		if (DynamicGL_GetVariantPointervEXT==0) return false; 
		if (DynamicGL_GetInvariantBooleanvEXT==0) return false; 
		if (DynamicGL_GetInvariantIntegervEXT==0) return false; 
		if (DynamicGL_GetInvariantFloatvEXT==0) return false; 
		if (DynamicGL_GetLocalConstantBooleanvEXT==0) return false; 
		if (DynamicGL_GetLocalConstantIntegervEXT==0) return false; 
		if (DynamicGL_GetLocalConstantFloatvEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_vertex_shader*/

/*NV_packed_depth_stencil*/
#ifdef USE_DYNAMIC_GL_NV_packed_depth_stencil
static bool DinamicGLFeature_NV_packed_depth_stencil_loaded = false; 
static void InitDinamicGLFeature_NV_packed_depth_stencil() {
		DinamicGLFeature_NV_packed_depth_stencil_loaded = true; 
}
bool DinamicGLFeature_NV_packed_depth_stencil_Supported() {
		if (!DinamicGLFeature_NV_packed_depth_stencil_loaded) {
			InitDinamicGLFeature_NV_packed_depth_stencil();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_packed_depth_stencil*/

/*SGI_color_table*/
#ifdef USE_DYNAMIC_GL_SGI_color_table
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorTableSGI)(GLenum target , GLenum internalformat , GLsizei width , GLenum format , GLenum type , const GLvoid *table) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorTableParameterfvSGI)(GLenum target , GLenum pname , const GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorTableParameterivSGI)(GLenum target , GLenum pname , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyColorTableSGI)(GLenum target , GLenum internalformat , GLint x , GLint y , GLsizei width) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetColorTableSGI)(GLenum target , GLenum format , GLenum type , GLvoid *table) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetColorTableParameterfvSGI)(GLenum target , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetColorTableParameterivSGI)(GLenum target , GLenum pname , GLint *params) = 0; }
static bool DinamicGLFeature_SGI_color_table_loaded = false; 
static void InitDinamicGLFeature_SGI_color_table() {
		DynamicGL_ColorTableSGI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum internalformat , GLsizei width , GLenum format , GLenum type , const GLvoid *table)>("glColorTableSGI"); 
		DynamicGL_ColorTableParameterfvSGI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , const GLfloat *params)>("glColorTableParameterfvSGI"); 
		DynamicGL_ColorTableParameterivSGI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , const GLint *params)>("glColorTableParameterivSGI"); 
		DynamicGL_CopyColorTableSGI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum internalformat , GLint x , GLint y , GLsizei width)>("glCopyColorTableSGI"); 
		DynamicGL_GetColorTableSGI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum format , GLenum type , GLvoid *table)>("glGetColorTableSGI"); 
		DynamicGL_GetColorTableParameterfvSGI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLfloat *params)>("glGetColorTableParameterfvSGI"); 
		DynamicGL_GetColorTableParameterivSGI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint *params)>("glGetColorTableParameterivSGI"); 
		DinamicGLFeature_SGI_color_table_loaded = true; 
}
bool DinamicGLFeature_SGI_color_table_Supported() {
		if (!DinamicGLFeature_SGI_color_table_loaded) {
			InitDinamicGLFeature_SGI_color_table();
		}
		if (DynamicGL_ColorTableSGI==0) return false; 
		if (DynamicGL_ColorTableParameterfvSGI==0) return false; 
		if (DynamicGL_ColorTableParameterivSGI==0) return false; 
		if (DynamicGL_CopyColorTableSGI==0) return false; 
		if (DynamicGL_GetColorTableSGI==0) return false; 
		if (DynamicGL_GetColorTableParameterfvSGI==0) return false; 
		if (DynamicGL_GetColorTableParameterivSGI==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_SGI_color_table*/

/*EXT_texture_array*/
#ifdef USE_DYNAMIC_GL_EXT_texture_array
static bool DinamicGLFeature_EXT_texture_array_loaded = false; 
static void InitDinamicGLFeature_EXT_texture_array() {
		DinamicGLFeature_EXT_texture_array_loaded = true; 
}
bool DinamicGLFeature_EXT_texture_array_Supported() {
		if (!DinamicGLFeature_EXT_texture_array_loaded) {
			InitDinamicGLFeature_EXT_texture_array();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_texture_array*/

/*EXT_texture_object*/
#ifdef USE_DYNAMIC_GL_EXT_texture_object
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_AreTexturesResidentEXT)(GLsizei n , const GLuint *textures , GLboolean *residences) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BindTextureEXT)(GLenum target , GLuint texture) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteTexturesEXT)(GLsizei n , const GLuint *textures) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GenTexturesEXT)(GLsizei n , GLuint *textures) = 0; }
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsTextureEXT)(GLuint texture) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PrioritizeTexturesEXT)(GLsizei n , const GLuint *textures , const GLclampf *priorities) = 0; }
static bool DinamicGLFeature_EXT_texture_object_loaded = false; 
static void InitDinamicGLFeature_EXT_texture_object() {
		DynamicGL_AreTexturesResidentEXT = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLsizei n , const GLuint *textures , GLboolean *residences)>("glAreTexturesResidentEXT"); 
		DynamicGL_BindTextureEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint texture)>("glBindTextureEXT"); 
		DynamicGL_DeleteTexturesEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , const GLuint *textures)>("glDeleteTexturesEXT"); 
		DynamicGL_GenTexturesEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , GLuint *textures)>("glGenTexturesEXT"); 
		DynamicGL_IsTextureEXT = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLuint texture)>("glIsTextureEXT"); 
		DynamicGL_PrioritizeTexturesEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , const GLuint *textures , const GLclampf *priorities)>("glPrioritizeTexturesEXT"); 
		DinamicGLFeature_EXT_texture_object_loaded = true; 
}
bool DinamicGLFeature_EXT_texture_object_Supported() {
		if (!DinamicGLFeature_EXT_texture_object_loaded) {
			InitDinamicGLFeature_EXT_texture_object();
		}
		if (DynamicGL_AreTexturesResidentEXT==0) return false; 
		if (DynamicGL_BindTextureEXT==0) return false; 
		if (DynamicGL_DeleteTexturesEXT==0) return false; 
		if (DynamicGL_GenTexturesEXT==0) return false; 
		if (DynamicGL_IsTextureEXT==0) return false; 
		if (DynamicGL_PrioritizeTexturesEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_texture_object*/

/*ATI_texture_env_combine3*/
#ifdef USE_DYNAMIC_GL_ATI_texture_env_combine3
static bool DinamicGLFeature_ATI_texture_env_combine3_loaded = false; 
static void InitDinamicGLFeature_ATI_texture_env_combine3() {
		DinamicGLFeature_ATI_texture_env_combine3_loaded = true; 
}
bool DinamicGLFeature_ATI_texture_env_combine3_Supported() {
		if (!DinamicGLFeature_ATI_texture_env_combine3_loaded) {
			InitDinamicGLFeature_ATI_texture_env_combine3();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_ATI_texture_env_combine3*/

/*EXT_geometry_shader4*/
#ifdef USE_DYNAMIC_GL_EXT_geometry_shader4
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramParameteriEXT)(GLuint program , GLenum pname , GLint value) = 0; }
static bool DinamicGLFeature_EXT_geometry_shader4_loaded = false; 
static void InitDinamicGLFeature_EXT_geometry_shader4() {
		DynamicGL_ProgramParameteriEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLenum pname , GLint value)>("glProgramParameteriEXT"); 
		DinamicGLFeature_EXT_geometry_shader4_loaded = true; 
}
bool DinamicGLFeature_EXT_geometry_shader4_Supported() {
		if (!DinamicGLFeature_EXT_geometry_shader4_loaded) {
			InitDinamicGLFeature_EXT_geometry_shader4();
		}
		if (DynamicGL_ProgramParameteriEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_geometry_shader4*/

/*ARB_transpose_matrix*/
#ifdef USE_DYNAMIC_GL_ARB_transpose_matrix
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_LoadTransposeMatrixfARB)(const GLfloat *m) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_LoadTransposeMatrixdARB)(const GLdouble *m) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultTransposeMatrixfARB)(const GLfloat *m) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultTransposeMatrixdARB)(const GLdouble *m) = 0; }
static bool DinamicGLFeature_ARB_transpose_matrix_loaded = false; 
static void InitDinamicGLFeature_ARB_transpose_matrix() {
		DynamicGL_LoadTransposeMatrixfARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *m)>("glLoadTransposeMatrixfARB"); 
		DynamicGL_LoadTransposeMatrixdARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *m)>("glLoadTransposeMatrixdARB"); 
		DynamicGL_MultTransposeMatrixfARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *m)>("glMultTransposeMatrixfARB"); 
		DynamicGL_MultTransposeMatrixdARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *m)>("glMultTransposeMatrixdARB"); 
		DinamicGLFeature_ARB_transpose_matrix_loaded = true; 
}
bool DinamicGLFeature_ARB_transpose_matrix_Supported() {
		if (!DinamicGLFeature_ARB_transpose_matrix_loaded) {
			InitDinamicGLFeature_ARB_transpose_matrix();
		}
		if (DynamicGL_LoadTransposeMatrixfARB==0) return false; 
		if (DynamicGL_LoadTransposeMatrixdARB==0) return false; 
		if (DynamicGL_MultTransposeMatrixfARB==0) return false; 
		if (DynamicGL_MultTransposeMatrixdARB==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_transpose_matrix*/

/*NV_parameter_buffer_object*/
#ifdef USE_DYNAMIC_GL_NV_parameter_buffer_object
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramBufferParametersfvNV)(GLenum target , GLuint buffer , GLuint index , GLsizei count , const GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramBufferParametersIivNV)(GLenum target , GLuint buffer , GLuint index , GLsizei count , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramBufferParametersIuivNV)(GLenum target , GLuint buffer , GLuint index , GLsizei count , const GLuint *params) = 0; }
static bool DinamicGLFeature_NV_parameter_buffer_object_loaded = false; 
static void InitDinamicGLFeature_NV_parameter_buffer_object() {
		DynamicGL_ProgramBufferParametersfvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint buffer , GLuint index , GLsizei count , const GLfloat *params)>("glProgramBufferParametersfvNV"); 
		DynamicGL_ProgramBufferParametersIivNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint buffer , GLuint index , GLsizei count , const GLint *params)>("glProgramBufferParametersIivNV"); 
		DynamicGL_ProgramBufferParametersIuivNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint buffer , GLuint index , GLsizei count , const GLuint *params)>("glProgramBufferParametersIuivNV"); 
		DinamicGLFeature_NV_parameter_buffer_object_loaded = true; 
}
bool DinamicGLFeature_NV_parameter_buffer_object_Supported() {
		if (!DinamicGLFeature_NV_parameter_buffer_object_loaded) {
			InitDinamicGLFeature_NV_parameter_buffer_object();
		}
		if (DynamicGL_ProgramBufferParametersfvNV==0) return false; 
		if (DynamicGL_ProgramBufferParametersIivNV==0) return false; 
		if (DynamicGL_ProgramBufferParametersIuivNV==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_parameter_buffer_object*/

/*EXT_packed_depth_stencil*/
#ifdef USE_DYNAMIC_GL_EXT_packed_depth_stencil
static bool DinamicGLFeature_EXT_packed_depth_stencil_loaded = false; 
static void InitDinamicGLFeature_EXT_packed_depth_stencil() {
		DinamicGLFeature_EXT_packed_depth_stencil_loaded = true; 
}
bool DinamicGLFeature_EXT_packed_depth_stencil_Supported() {
		if (!DinamicGLFeature_EXT_packed_depth_stencil_loaded) {
			InitDinamicGLFeature_EXT_packed_depth_stencil();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_packed_depth_stencil*/

/*PGI_vertex_hints*/
#ifdef USE_DYNAMIC_GL_PGI_vertex_hints
static bool DinamicGLFeature_PGI_vertex_hints_loaded = false; 
static void InitDinamicGLFeature_PGI_vertex_hints() {
		DinamicGLFeature_PGI_vertex_hints_loaded = true; 
}
bool DinamicGLFeature_PGI_vertex_hints_Supported() {
		if (!DinamicGLFeature_PGI_vertex_hints_loaded) {
			InitDinamicGLFeature_PGI_vertex_hints();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_PGI_vertex_hints*/

/*EXT_vertex_weighting*/
#ifdef USE_DYNAMIC_GL_EXT_vertex_weighting
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexWeightfEXT)(GLfloat weight) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexWeightfvEXT)(const GLfloat *weight) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexWeightPointerEXT)(GLsizei size , GLenum type , GLsizei stride , const GLvoid *pointer) = 0; }
static bool DinamicGLFeature_EXT_vertex_weighting_loaded = false; 
static void InitDinamicGLFeature_EXT_vertex_weighting() {
		DynamicGL_VertexWeightfEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat weight)>("glVertexWeightfEXT"); 
		DynamicGL_VertexWeightfvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *weight)>("glVertexWeightfvEXT"); 
		DynamicGL_VertexWeightPointerEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei size , GLenum type , GLsizei stride , const GLvoid *pointer)>("glVertexWeightPointerEXT"); 
		DinamicGLFeature_EXT_vertex_weighting_loaded = true; 
}
bool DinamicGLFeature_EXT_vertex_weighting_Supported() {
		if (!DinamicGLFeature_EXT_vertex_weighting_loaded) {
			InitDinamicGLFeature_EXT_vertex_weighting();
		}
		if (DynamicGL_VertexWeightfEXT==0) return false; 
		if (DynamicGL_VertexWeightfvEXT==0) return false; 
		if (DynamicGL_VertexWeightPointerEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_vertex_weighting*/

/*ARB_texture_env_dot3*/
#ifdef USE_DYNAMIC_GL_ARB_texture_env_dot3
static bool DinamicGLFeature_ARB_texture_env_dot3_loaded = false; 
static void InitDinamicGLFeature_ARB_texture_env_dot3() {
		DinamicGLFeature_ARB_texture_env_dot3_loaded = true; 
}
bool DinamicGLFeature_ARB_texture_env_dot3_Supported() {
		if (!DinamicGLFeature_ARB_texture_env_dot3_loaded) {
			InitDinamicGLFeature_ARB_texture_env_dot3();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_texture_env_dot3*/

/*EXT_histogram*/
#ifdef USE_DYNAMIC_GL_EXT_histogram
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetHistogramEXT)(GLenum target , GLboolean reset , GLenum format , GLenum type , GLvoid *values) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetHistogramParameterfvEXT)(GLenum target , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetHistogramParameterivEXT)(GLenum target , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMinmaxEXT)(GLenum target , GLboolean reset , GLenum format , GLenum type , GLvoid *values) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMinmaxParameterfvEXT)(GLenum target , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMinmaxParameterivEXT)(GLenum target , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_HistogramEXT)(GLenum target , GLsizei width , GLenum internalformat , GLboolean sink) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MinmaxEXT)(GLenum target , GLenum internalformat , GLboolean sink) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ResetHistogramEXT)(GLenum target) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ResetMinmaxEXT)(GLenum target) = 0; }
static bool DinamicGLFeature_EXT_histogram_loaded = false; 
static void InitDinamicGLFeature_EXT_histogram() {
		DynamicGL_GetHistogramEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLboolean reset , GLenum format , GLenum type , GLvoid *values)>("glGetHistogramEXT"); 
		DynamicGL_GetHistogramParameterfvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLfloat *params)>("glGetHistogramParameterfvEXT"); 
		DynamicGL_GetHistogramParameterivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint *params)>("glGetHistogramParameterivEXT"); 
		DynamicGL_GetMinmaxEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLboolean reset , GLenum format , GLenum type , GLvoid *values)>("glGetMinmaxEXT"); 
		DynamicGL_GetMinmaxParameterfvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLfloat *params)>("glGetMinmaxParameterfvEXT"); 
		DynamicGL_GetMinmaxParameterivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint *params)>("glGetMinmaxParameterivEXT"); 
		DynamicGL_HistogramEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLsizei width , GLenum internalformat , GLboolean sink)>("glHistogramEXT"); 
		DynamicGL_MinmaxEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum internalformat , GLboolean sink)>("glMinmaxEXT"); 
		DynamicGL_ResetHistogramEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target)>("glResetHistogramEXT"); 
		DynamicGL_ResetMinmaxEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target)>("glResetMinmaxEXT"); 
		DinamicGLFeature_EXT_histogram_loaded = true; 
}
bool DinamicGLFeature_EXT_histogram_Supported() {
		if (!DinamicGLFeature_EXT_histogram_loaded) {
			InitDinamicGLFeature_EXT_histogram();
		}
		if (DynamicGL_GetHistogramEXT==0) return false; 
		if (DynamicGL_GetHistogramParameterfvEXT==0) return false; 
		if (DynamicGL_GetHistogramParameterivEXT==0) return false; 
		if (DynamicGL_GetMinmaxEXT==0) return false; 
		if (DynamicGL_GetMinmaxParameterfvEXT==0) return false; 
		if (DynamicGL_GetMinmaxParameterivEXT==0) return false; 
		if (DynamicGL_HistogramEXT==0) return false; 
		if (DynamicGL_MinmaxEXT==0) return false; 
		if (DynamicGL_ResetHistogramEXT==0) return false; 
		if (DynamicGL_ResetMinmaxEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_histogram*/

/*SGIX_pixel_texture*/
#ifdef USE_DYNAMIC_GL_SGIX_pixel_texture
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelTexGenSGIX)(GLenum mode) = 0; }
static bool DinamicGLFeature_SGIX_pixel_texture_loaded = false; 
static void InitDinamicGLFeature_SGIX_pixel_texture() {
		DynamicGL_PixelTexGenSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode)>("glPixelTexGenSGIX"); 
		DinamicGLFeature_SGIX_pixel_texture_loaded = true; 
}
bool DinamicGLFeature_SGIX_pixel_texture_Supported() {
		if (!DinamicGLFeature_SGIX_pixel_texture_loaded) {
			InitDinamicGLFeature_SGIX_pixel_texture();
		}
		if (DynamicGL_PixelTexGenSGIX==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_pixel_texture*/

/*NV_fog_distance*/
#ifdef USE_DYNAMIC_GL_NV_fog_distance
static bool DinamicGLFeature_NV_fog_distance_loaded = false; 
static void InitDinamicGLFeature_NV_fog_distance() {
		DinamicGLFeature_NV_fog_distance_loaded = true; 
}
bool DinamicGLFeature_NV_fog_distance_Supported() {
		if (!DinamicGLFeature_NV_fog_distance_loaded) {
			InitDinamicGLFeature_NV_fog_distance();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_fog_distance*/

/*APPLE_fence*/
#ifdef USE_DYNAMIC_GL_APPLE_fence
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GenFencesAPPLE)(GLsizei n , GLuint *fences) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteFencesAPPLE)(GLsizei n , const GLuint *fences) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SetFenceAPPLE)(GLuint fence) = 0; }
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsFenceAPPLE)(GLuint fence) = 0; }
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_TestFenceAPPLE)(GLuint fence) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FinishFenceAPPLE)(GLuint fence) = 0; }
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_TestObjectAPPLE)(GLenum object , GLuint name) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FinishObjectAPPLE)(GLenum object , GLint name) = 0; }
static bool DinamicGLFeature_APPLE_fence_loaded = false; 
static void InitDinamicGLFeature_APPLE_fence() {
		DynamicGL_GenFencesAPPLE = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , GLuint *fences)>("glGenFencesAPPLE"); 
		DynamicGL_DeleteFencesAPPLE = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , const GLuint *fences)>("glDeleteFencesAPPLE"); 
		DynamicGL_SetFenceAPPLE = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint fence)>("glSetFenceAPPLE"); 
		DynamicGL_IsFenceAPPLE = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLuint fence)>("glIsFenceAPPLE"); 
		DynamicGL_TestFenceAPPLE = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLuint fence)>("glTestFenceAPPLE"); 
		DynamicGL_FinishFenceAPPLE = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint fence)>("glFinishFenceAPPLE"); 
		DynamicGL_TestObjectAPPLE = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLenum object , GLuint name)>("glTestObjectAPPLE"); 
		DynamicGL_FinishObjectAPPLE = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum object , GLint name)>("glFinishObjectAPPLE"); 
		DinamicGLFeature_APPLE_fence_loaded = true; 
}
bool DinamicGLFeature_APPLE_fence_Supported() {
		if (!DinamicGLFeature_APPLE_fence_loaded) {
			InitDinamicGLFeature_APPLE_fence();
		}
		if (DynamicGL_GenFencesAPPLE==0) return false; 
		if (DynamicGL_DeleteFencesAPPLE==0) return false; 
		if (DynamicGL_SetFenceAPPLE==0) return false; 
		if (DynamicGL_IsFenceAPPLE==0) return false; 
		if (DynamicGL_TestFenceAPPLE==0) return false; 
		if (DynamicGL_FinishFenceAPPLE==0) return false; 
		if (DynamicGL_TestObjectAPPLE==0) return false; 
		if (DynamicGL_FinishObjectAPPLE==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_APPLE_fence*/

/*EXT_blend_func_separate*/
#ifdef USE_DYNAMIC_GL_EXT_blend_func_separate
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendFuncSeparateEXT)(GLenum sfactorRGB , GLenum dfactorRGB , GLenum sfactorAlpha , GLenum dfactorAlpha) = 0; }
static bool DinamicGLFeature_EXT_blend_func_separate_loaded = false; 
static void InitDinamicGLFeature_EXT_blend_func_separate() {
		DynamicGL_BlendFuncSeparateEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum sfactorRGB , GLenum dfactorRGB , GLenum sfactorAlpha , GLenum dfactorAlpha)>("glBlendFuncSeparateEXT"); 
		DinamicGLFeature_EXT_blend_func_separate_loaded = true; 
}
bool DinamicGLFeature_EXT_blend_func_separate_Supported() {
		if (!DinamicGLFeature_EXT_blend_func_separate_loaded) {
			InitDinamicGLFeature_EXT_blend_func_separate();
		}
		if (DynamicGL_BlendFuncSeparateEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_blend_func_separate*/

/*SGIS_texture_border_clamp*/
#ifdef USE_DYNAMIC_GL_SGIS_texture_border_clamp
static bool DinamicGLFeature_SGIS_texture_border_clamp_loaded = false; 
static void InitDinamicGLFeature_SGIS_texture_border_clamp() {
		DinamicGLFeature_SGIS_texture_border_clamp_loaded = true; 
}
bool DinamicGLFeature_SGIS_texture_border_clamp_Supported() {
		if (!DinamicGLFeature_SGIS_texture_border_clamp_loaded) {
			InitDinamicGLFeature_SGIS_texture_border_clamp();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIS_texture_border_clamp*/

/*EXT_gpu_program_parameters*/
#ifdef USE_DYNAMIC_GL_EXT_gpu_program_parameters
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramEnvParameters4fvEXT)(GLenum target , GLuint index , GLsizei count , const GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramLocalParameters4fvEXT)(GLenum target , GLuint index , GLsizei count , const GLfloat *params) = 0; }
static bool DinamicGLFeature_EXT_gpu_program_parameters_loaded = false; 
static void InitDinamicGLFeature_EXT_gpu_program_parameters() {
		DynamicGL_ProgramEnvParameters4fvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLsizei count , const GLfloat *params)>("glProgramEnvParameters4fvEXT"); 
		DynamicGL_ProgramLocalParameters4fvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLsizei count , const GLfloat *params)>("glProgramLocalParameters4fvEXT"); 
		DinamicGLFeature_EXT_gpu_program_parameters_loaded = true; 
}
bool DinamicGLFeature_EXT_gpu_program_parameters_Supported() {
		if (!DinamicGLFeature_EXT_gpu_program_parameters_loaded) {
			InitDinamicGLFeature_EXT_gpu_program_parameters();
		}
		if (DynamicGL_ProgramEnvParameters4fvEXT==0) return false; 
		if (DynamicGL_ProgramLocalParameters4fvEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_gpu_program_parameters*/

/*SGIX_texture_add_env*/
#ifdef USE_DYNAMIC_GL_SGIX_texture_add_env
static bool DinamicGLFeature_SGIX_texture_add_env_loaded = false; 
static void InitDinamicGLFeature_SGIX_texture_add_env() {
		DinamicGLFeature_SGIX_texture_add_env_loaded = true; 
}
bool DinamicGLFeature_SGIX_texture_add_env_Supported() {
		if (!DinamicGLFeature_SGIX_texture_add_env_loaded) {
			InitDinamicGLFeature_SGIX_texture_add_env();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_texture_add_env*/

/*EXT_paletted_texture*/
#ifdef USE_DYNAMIC_GL_EXT_paletted_texture
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorTableEXT)(GLenum target , GLenum internalFormat , GLsizei width , GLenum format , GLenum type , const GLvoid *table) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetColorTableEXT)(GLenum target , GLenum format , GLenum type , GLvoid *data) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetColorTableParameterivEXT)(GLenum target , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetColorTableParameterfvEXT)(GLenum target , GLenum pname , GLfloat *params) = 0; }
static bool DinamicGLFeature_EXT_paletted_texture_loaded = false; 
static void InitDinamicGLFeature_EXT_paletted_texture() {
		DynamicGL_ColorTableEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum internalFormat , GLsizei width , GLenum format , GLenum type , const GLvoid *table)>("glColorTableEXT"); 
		DynamicGL_GetColorTableEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum format , GLenum type , GLvoid *data)>("glGetColorTableEXT"); 
		DynamicGL_GetColorTableParameterivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint *params)>("glGetColorTableParameterivEXT"); 
		DynamicGL_GetColorTableParameterfvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLfloat *params)>("glGetColorTableParameterfvEXT"); 
		DinamicGLFeature_EXT_paletted_texture_loaded = true; 
}
bool DinamicGLFeature_EXT_paletted_texture_Supported() {
		if (!DinamicGLFeature_EXT_paletted_texture_loaded) {
			InitDinamicGLFeature_EXT_paletted_texture();
		}
		if (DynamicGL_ColorTableEXT==0) return false; 
		if (DynamicGL_GetColorTableEXT==0) return false; 
		if (DynamicGL_GetColorTableParameterivEXT==0) return false; 
		if (DynamicGL_GetColorTableParameterfvEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_paletted_texture*/

/*EXT_light_texture*/
#ifdef USE_DYNAMIC_GL_EXT_light_texture
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ApplyTextureEXT)(GLenum mode) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureLightEXT)(GLenum pname) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureMaterialEXT)(GLenum face , GLenum mode) = 0; }
static bool DinamicGLFeature_EXT_light_texture_loaded = false; 
static void InitDinamicGLFeature_EXT_light_texture() {
		DynamicGL_ApplyTextureEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode)>("glApplyTextureEXT"); 
		DynamicGL_TextureLightEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname)>("glTextureLightEXT"); 
		DynamicGL_TextureMaterialEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum face , GLenum mode)>("glTextureMaterialEXT"); 
		DinamicGLFeature_EXT_light_texture_loaded = true; 
}
bool DinamicGLFeature_EXT_light_texture_Supported() {
		if (!DinamicGLFeature_EXT_light_texture_loaded) {
			InitDinamicGLFeature_EXT_light_texture();
		}
		if (DynamicGL_ApplyTextureEXT==0) return false; 
		if (DynamicGL_TextureLightEXT==0) return false; 
		if (DynamicGL_TextureMaterialEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_light_texture*/

/*EXT_multisample*/
#ifdef USE_DYNAMIC_GL_EXT_multisample
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SampleMaskEXT)(GLclampf value , GLboolean invert) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SamplePatternEXT)(GLenum pattern) = 0; }
static bool DinamicGLFeature_EXT_multisample_loaded = false; 
static void InitDinamicGLFeature_EXT_multisample() {
		DynamicGL_SampleMaskEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLclampf value , GLboolean invert)>("glSampleMaskEXT"); 
		DynamicGL_SamplePatternEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pattern)>("glSamplePatternEXT"); 
		DinamicGLFeature_EXT_multisample_loaded = true; 
}
bool DinamicGLFeature_EXT_multisample_Supported() {
		if (!DinamicGLFeature_EXT_multisample_loaded) {
			InitDinamicGLFeature_EXT_multisample();
		}
		if (DynamicGL_SampleMaskEXT==0) return false; 
		if (DynamicGL_SamplePatternEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_multisample*/

/*SGIX_resample*/
#ifdef USE_DYNAMIC_GL_SGIX_resample
static bool DinamicGLFeature_SGIX_resample_loaded = false; 
static void InitDinamicGLFeature_SGIX_resample() {
		DinamicGLFeature_SGIX_resample_loaded = true; 
}
bool DinamicGLFeature_SGIX_resample_Supported() {
		if (!DinamicGLFeature_SGIX_resample_loaded) {
			InitDinamicGLFeature_SGIX_resample();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_resample*/

/*ARB_vertex_program*/
#ifdef USE_DYNAMIC_GL_ARB_vertex_program
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1dARB)(GLuint index , GLdouble x) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1dvARB)(GLuint index , const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1fARB)(GLuint index , GLfloat x) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1fvARB)(GLuint index , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1sARB)(GLuint index , GLshort x) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1svARB)(GLuint index , const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2dARB)(GLuint index , GLdouble x , GLdouble y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2dvARB)(GLuint index , const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2fARB)(GLuint index , GLfloat x , GLfloat y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2fvARB)(GLuint index , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2sARB)(GLuint index , GLshort x , GLshort y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2svARB)(GLuint index , const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3dARB)(GLuint index , GLdouble x , GLdouble y , GLdouble z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3dvARB)(GLuint index , const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3fARB)(GLuint index , GLfloat x , GLfloat y , GLfloat z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3fvARB)(GLuint index , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3sARB)(GLuint index , GLshort x , GLshort y , GLshort z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3svARB)(GLuint index , const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4NbvARB)(GLuint index , const GLbyte *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4NivARB)(GLuint index , const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4NsvARB)(GLuint index , const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4NubARB)(GLuint index , GLubyte x , GLubyte y , GLubyte z , GLubyte w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4NubvARB)(GLuint index , const GLubyte *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4NuivARB)(GLuint index , const GLuint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4NusvARB)(GLuint index , const GLushort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4bvARB)(GLuint index , const GLbyte *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4dARB)(GLuint index , GLdouble x , GLdouble y , GLdouble z , GLdouble w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4dvARB)(GLuint index , const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4fARB)(GLuint index , GLfloat x , GLfloat y , GLfloat z , GLfloat w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4fvARB)(GLuint index , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4ivARB)(GLuint index , const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4sARB)(GLuint index , GLshort x , GLshort y , GLshort z , GLshort w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4svARB)(GLuint index , const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4ubvARB)(GLuint index , const GLubyte *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4uivARB)(GLuint index , const GLuint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4usvARB)(GLuint index , const GLushort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribPointerARB)(GLuint index , GLint size , GLenum type , GLboolean normalized , GLsizei stride , const GLvoid *pointer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EnableVertexAttribArrayARB)(GLuint index) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DisableVertexAttribArrayARB)(GLuint index) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramStringARB)(GLenum target , GLenum format , GLsizei len , const GLvoid *string) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BindProgramARB)(GLenum target , GLuint program) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteProgramsARB)(GLsizei n , const GLuint *programs) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GenProgramsARB)(GLsizei n , GLuint *programs) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramEnvParameter4dARB)(GLenum target , GLuint index , GLdouble x , GLdouble y , GLdouble z , GLdouble w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramEnvParameter4dvARB)(GLenum target , GLuint index , const GLdouble *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramEnvParameter4fARB)(GLenum target , GLuint index , GLfloat x , GLfloat y , GLfloat z , GLfloat w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramEnvParameter4fvARB)(GLenum target , GLuint index , const GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramLocalParameter4dARB)(GLenum target , GLuint index , GLdouble x , GLdouble y , GLdouble z , GLdouble w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramLocalParameter4dvARB)(GLenum target , GLuint index , const GLdouble *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramLocalParameter4fARB)(GLenum target , GLuint index , GLfloat x , GLfloat y , GLfloat z , GLfloat w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramLocalParameter4fvARB)(GLenum target , GLuint index , const GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramEnvParameterdvARB)(GLenum target , GLuint index , GLdouble *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramEnvParameterfvARB)(GLenum target , GLuint index , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramLocalParameterdvARB)(GLenum target , GLuint index , GLdouble *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramLocalParameterfvARB)(GLenum target , GLuint index , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramivARB)(GLenum target , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramStringARB)(GLenum target , GLenum pname , GLvoid *string) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribdvARB)(GLuint index , GLenum pname , GLdouble *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribfvARB)(GLuint index , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribivARB)(GLuint index , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribPointervARB)(GLuint index , GLenum pname , GLvoid* *pointer) = 0; }
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsProgramARB)(GLuint program) = 0; }
static bool DinamicGLFeature_ARB_vertex_program_loaded = false; 
static void InitDinamicGLFeature_ARB_vertex_program() {
		DynamicGL_VertexAttrib1dARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLdouble x)>("glVertexAttrib1dARB"); 
		DynamicGL_VertexAttrib1dvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLdouble *v)>("glVertexAttrib1dvARB"); 
		DynamicGL_VertexAttrib1fARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLfloat x)>("glVertexAttrib1fARB"); 
		DynamicGL_VertexAttrib1fvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLfloat *v)>("glVertexAttrib1fvARB"); 
		DynamicGL_VertexAttrib1sARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLshort x)>("glVertexAttrib1sARB"); 
		DynamicGL_VertexAttrib1svARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLshort *v)>("glVertexAttrib1svARB"); 
		DynamicGL_VertexAttrib2dARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLdouble x , GLdouble y)>("glVertexAttrib2dARB"); 
		DynamicGL_VertexAttrib2dvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLdouble *v)>("glVertexAttrib2dvARB"); 
		DynamicGL_VertexAttrib2fARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLfloat x , GLfloat y)>("glVertexAttrib2fARB"); 
		DynamicGL_VertexAttrib2fvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLfloat *v)>("glVertexAttrib2fvARB"); 
		DynamicGL_VertexAttrib2sARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLshort x , GLshort y)>("glVertexAttrib2sARB"); 
		DynamicGL_VertexAttrib2svARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLshort *v)>("glVertexAttrib2svARB"); 
		DynamicGL_VertexAttrib3dARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLdouble x , GLdouble y , GLdouble z)>("glVertexAttrib3dARB"); 
		DynamicGL_VertexAttrib3dvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLdouble *v)>("glVertexAttrib3dvARB"); 
		DynamicGL_VertexAttrib3fARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLfloat x , GLfloat y , GLfloat z)>("glVertexAttrib3fARB"); 
		DynamicGL_VertexAttrib3fvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLfloat *v)>("glVertexAttrib3fvARB"); 
		DynamicGL_VertexAttrib3sARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLshort x , GLshort y , GLshort z)>("glVertexAttrib3sARB"); 
		DynamicGL_VertexAttrib3svARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLshort *v)>("glVertexAttrib3svARB"); 
		DynamicGL_VertexAttrib4NbvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLbyte *v)>("glVertexAttrib4NbvARB"); 
		DynamicGL_VertexAttrib4NivARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLint *v)>("glVertexAttrib4NivARB"); 
		DynamicGL_VertexAttrib4NsvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLshort *v)>("glVertexAttrib4NsvARB"); 
		DynamicGL_VertexAttrib4NubARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLubyte x , GLubyte y , GLubyte z , GLubyte w)>("glVertexAttrib4NubARB"); 
		DynamicGL_VertexAttrib4NubvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLubyte *v)>("glVertexAttrib4NubvARB"); 
		DynamicGL_VertexAttrib4NuivARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLuint *v)>("glVertexAttrib4NuivARB"); 
		DynamicGL_VertexAttrib4NusvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLushort *v)>("glVertexAttrib4NusvARB"); 
		DynamicGL_VertexAttrib4bvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLbyte *v)>("glVertexAttrib4bvARB"); 
		DynamicGL_VertexAttrib4dARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLdouble x , GLdouble y , GLdouble z , GLdouble w)>("glVertexAttrib4dARB"); 
		DynamicGL_VertexAttrib4dvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLdouble *v)>("glVertexAttrib4dvARB"); 
		DynamicGL_VertexAttrib4fARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLfloat x , GLfloat y , GLfloat z , GLfloat w)>("glVertexAttrib4fARB"); 
		DynamicGL_VertexAttrib4fvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLfloat *v)>("glVertexAttrib4fvARB"); 
		DynamicGL_VertexAttrib4ivARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLint *v)>("glVertexAttrib4ivARB"); 
		DynamicGL_VertexAttrib4sARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLshort x , GLshort y , GLshort z , GLshort w)>("glVertexAttrib4sARB"); 
		DynamicGL_VertexAttrib4svARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLshort *v)>("glVertexAttrib4svARB"); 
		DynamicGL_VertexAttrib4ubvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLubyte *v)>("glVertexAttrib4ubvARB"); 
		DynamicGL_VertexAttrib4uivARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLuint *v)>("glVertexAttrib4uivARB"); 
		DynamicGL_VertexAttrib4usvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLushort *v)>("glVertexAttrib4usvARB"); 
		DynamicGL_VertexAttribPointerARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLint size , GLenum type , GLboolean normalized , GLsizei stride , const GLvoid *pointer)>("glVertexAttribPointerARB"); 
		DynamicGL_EnableVertexAttribArrayARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index)>("glEnableVertexAttribArrayARB"); 
		DynamicGL_DisableVertexAttribArrayARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index)>("glDisableVertexAttribArrayARB"); 
		DynamicGL_ProgramStringARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum format , GLsizei len , const GLvoid *string)>("glProgramStringARB"); 
		DynamicGL_BindProgramARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint program)>("glBindProgramARB"); 
		DynamicGL_DeleteProgramsARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , const GLuint *programs)>("glDeleteProgramsARB"); 
		DynamicGL_GenProgramsARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , GLuint *programs)>("glGenProgramsARB"); 
		DynamicGL_ProgramEnvParameter4dARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLdouble x , GLdouble y , GLdouble z , GLdouble w)>("glProgramEnvParameter4dARB"); 
		DynamicGL_ProgramEnvParameter4dvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , const GLdouble *params)>("glProgramEnvParameter4dvARB"); 
		DynamicGL_ProgramEnvParameter4fARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLfloat x , GLfloat y , GLfloat z , GLfloat w)>("glProgramEnvParameter4fARB"); 
		DynamicGL_ProgramEnvParameter4fvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , const GLfloat *params)>("glProgramEnvParameter4fvARB"); 
		DynamicGL_ProgramLocalParameter4dARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLdouble x , GLdouble y , GLdouble z , GLdouble w)>("glProgramLocalParameter4dARB"); 
		DynamicGL_ProgramLocalParameter4dvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , const GLdouble *params)>("glProgramLocalParameter4dvARB"); 
		DynamicGL_ProgramLocalParameter4fARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLfloat x , GLfloat y , GLfloat z , GLfloat w)>("glProgramLocalParameter4fARB"); 
		DynamicGL_ProgramLocalParameter4fvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , const GLfloat *params)>("glProgramLocalParameter4fvARB"); 
		DynamicGL_GetProgramEnvParameterdvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLdouble *params)>("glGetProgramEnvParameterdvARB"); 
		DynamicGL_GetProgramEnvParameterfvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLfloat *params)>("glGetProgramEnvParameterfvARB"); 
		DynamicGL_GetProgramLocalParameterdvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLdouble *params)>("glGetProgramLocalParameterdvARB"); 
		DynamicGL_GetProgramLocalParameterfvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLfloat *params)>("glGetProgramLocalParameterfvARB"); 
		DynamicGL_GetProgramivARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint *params)>("glGetProgramivARB"); 
		DynamicGL_GetProgramStringARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLvoid *string)>("glGetProgramStringARB"); 
		DynamicGL_GetVertexAttribdvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLenum pname , GLdouble *params)>("glGetVertexAttribdvARB"); 
		DynamicGL_GetVertexAttribfvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLenum pname , GLfloat *params)>("glGetVertexAttribfvARB"); 
		DynamicGL_GetVertexAttribivARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLenum pname , GLint *params)>("glGetVertexAttribivARB"); 
		DynamicGL_GetVertexAttribPointervARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLenum pname , GLvoid* *pointer)>("glGetVertexAttribPointervARB"); 
		DynamicGL_IsProgramARB = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLuint program)>("glIsProgramARB"); 
		DinamicGLFeature_ARB_vertex_program_loaded = true; 
}
bool DinamicGLFeature_ARB_vertex_program_Supported() {
		if (!DinamicGLFeature_ARB_vertex_program_loaded) {
			InitDinamicGLFeature_ARB_vertex_program();
		}
		if (DynamicGL_VertexAttrib1dARB==0) return false; 
		if (DynamicGL_VertexAttrib1dvARB==0) return false; 
		if (DynamicGL_VertexAttrib1fARB==0) return false; 
		if (DynamicGL_VertexAttrib1fvARB==0) return false; 
		if (DynamicGL_VertexAttrib1sARB==0) return false; 
		if (DynamicGL_VertexAttrib1svARB==0) return false; 
		if (DynamicGL_VertexAttrib2dARB==0) return false; 
		if (DynamicGL_VertexAttrib2dvARB==0) return false; 
		if (DynamicGL_VertexAttrib2fARB==0) return false; 
		if (DynamicGL_VertexAttrib2fvARB==0) return false; 
		if (DynamicGL_VertexAttrib2sARB==0) return false; 
		if (DynamicGL_VertexAttrib2svARB==0) return false; 
		if (DynamicGL_VertexAttrib3dARB==0) return false; 
		if (DynamicGL_VertexAttrib3dvARB==0) return false; 
		if (DynamicGL_VertexAttrib3fARB==0) return false; 
		if (DynamicGL_VertexAttrib3fvARB==0) return false; 
		if (DynamicGL_VertexAttrib3sARB==0) return false; 
		if (DynamicGL_VertexAttrib3svARB==0) return false; 
		if (DynamicGL_VertexAttrib4NbvARB==0) return false; 
		if (DynamicGL_VertexAttrib4NivARB==0) return false; 
		if (DynamicGL_VertexAttrib4NsvARB==0) return false; 
		if (DynamicGL_VertexAttrib4NubARB==0) return false; 
		if (DynamicGL_VertexAttrib4NubvARB==0) return false; 
		if (DynamicGL_VertexAttrib4NuivARB==0) return false; 
		if (DynamicGL_VertexAttrib4NusvARB==0) return false; 
		if (DynamicGL_VertexAttrib4bvARB==0) return false; 
		if (DynamicGL_VertexAttrib4dARB==0) return false; 
		if (DynamicGL_VertexAttrib4dvARB==0) return false; 
		if (DynamicGL_VertexAttrib4fARB==0) return false; 
		if (DynamicGL_VertexAttrib4fvARB==0) return false; 
		if (DynamicGL_VertexAttrib4ivARB==0) return false; 
		if (DynamicGL_VertexAttrib4sARB==0) return false; 
		if (DynamicGL_VertexAttrib4svARB==0) return false; 
		if (DynamicGL_VertexAttrib4ubvARB==0) return false; 
		if (DynamicGL_VertexAttrib4uivARB==0) return false; 
		if (DynamicGL_VertexAttrib4usvARB==0) return false; 
		if (DynamicGL_VertexAttribPointerARB==0) return false; 
		if (DynamicGL_EnableVertexAttribArrayARB==0) return false; 
		if (DynamicGL_DisableVertexAttribArrayARB==0) return false; 
		if (DynamicGL_ProgramStringARB==0) return false; 
		if (DynamicGL_BindProgramARB==0) return false; 
		if (DynamicGL_DeleteProgramsARB==0) return false; 
		if (DynamicGL_GenProgramsARB==0) return false; 
		if (DynamicGL_ProgramEnvParameter4dARB==0) return false; 
		if (DynamicGL_ProgramEnvParameter4dvARB==0) return false; 
		if (DynamicGL_ProgramEnvParameter4fARB==0) return false; 
		if (DynamicGL_ProgramEnvParameter4fvARB==0) return false; 
		if (DynamicGL_ProgramLocalParameter4dARB==0) return false; 
		if (DynamicGL_ProgramLocalParameter4dvARB==0) return false; 
		if (DynamicGL_ProgramLocalParameter4fARB==0) return false; 
		if (DynamicGL_ProgramLocalParameter4fvARB==0) return false; 
		if (DynamicGL_GetProgramEnvParameterdvARB==0) return false; 
		if (DynamicGL_GetProgramEnvParameterfvARB==0) return false; 
		if (DynamicGL_GetProgramLocalParameterdvARB==0) return false; 
		if (DynamicGL_GetProgramLocalParameterfvARB==0) return false; 
		if (DynamicGL_GetProgramivARB==0) return false; 
		if (DynamicGL_GetProgramStringARB==0) return false; 
		if (DynamicGL_GetVertexAttribdvARB==0) return false; 
		if (DynamicGL_GetVertexAttribfvARB==0) return false; 
		if (DynamicGL_GetVertexAttribivARB==0) return false; 
		if (DynamicGL_GetVertexAttribPointervARB==0) return false; 
		if (DynamicGL_IsProgramARB==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_vertex_program*/

/*EXT_point_parameters*/
#ifdef USE_DYNAMIC_GL_EXT_point_parameters
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameterfEXT)(GLenum pname , GLfloat param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameterfvEXT)(GLenum pname , const GLfloat *params) = 0; }
static bool DinamicGLFeature_EXT_point_parameters_loaded = false; 
static void InitDinamicGLFeature_EXT_point_parameters() {
		DynamicGL_PointParameterfEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLfloat param)>("glPointParameterfEXT"); 
		DynamicGL_PointParameterfvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , const GLfloat *params)>("glPointParameterfvEXT"); 
		DinamicGLFeature_EXT_point_parameters_loaded = true; 
}
bool DinamicGLFeature_EXT_point_parameters_Supported() {
		if (!DinamicGLFeature_EXT_point_parameters_loaded) {
			InitDinamicGLFeature_EXT_point_parameters();
		}
		if (DynamicGL_PointParameterfEXT==0) return false; 
		if (DynamicGL_PointParameterfvEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_point_parameters*/

/*ATI_map_object_buffer*/
#ifdef USE_DYNAMIC_GL_ATI_map_object_buffer
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_UnmapObjectBufferATI)(GLuint buffer) = 0; }
static bool DinamicGLFeature_ATI_map_object_buffer_loaded = false; 
static void InitDinamicGLFeature_ATI_map_object_buffer() {
		DynamicGL_UnmapObjectBufferATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint buffer)>("glUnmapObjectBufferATI"); 
		DinamicGLFeature_ATI_map_object_buffer_loaded = true; 
}
bool DinamicGLFeature_ATI_map_object_buffer_Supported() {
		if (!DinamicGLFeature_ATI_map_object_buffer_loaded) {
			InitDinamicGLFeature_ATI_map_object_buffer();
		}
		if (DynamicGL_UnmapObjectBufferATI==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_ATI_map_object_buffer*/

/*MESAX_texture_stack*/
#ifdef USE_DYNAMIC_GL_MESAX_texture_stack
static bool DinamicGLFeature_MESAX_texture_stack_loaded = false; 
static void InitDinamicGLFeature_MESAX_texture_stack() {
		DinamicGLFeature_MESAX_texture_stack_loaded = true; 
}
bool DinamicGLFeature_MESAX_texture_stack_Supported() {
		if (!DinamicGLFeature_MESAX_texture_stack_loaded) {
			InitDinamicGLFeature_MESAX_texture_stack();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_MESAX_texture_stack*/

/*SGIS_pixel_texture*/
#ifdef USE_DYNAMIC_GL_SGIS_pixel_texture
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelTexGenParameteriSGIS)(GLenum pname , GLint param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelTexGenParameterivSGIS)(GLenum pname , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelTexGenParameterfSGIS)(GLenum pname , GLfloat param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelTexGenParameterfvSGIS)(GLenum pname , const GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPixelTexGenParameterivSGIS)(GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPixelTexGenParameterfvSGIS)(GLenum pname , GLfloat *params) = 0; }
static bool DinamicGLFeature_SGIS_pixel_texture_loaded = false; 
static void InitDinamicGLFeature_SGIS_pixel_texture() {
		DynamicGL_PixelTexGenParameteriSGIS = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLint param)>("glPixelTexGenParameteriSGIS"); 
		DynamicGL_PixelTexGenParameterivSGIS = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , const GLint *params)>("glPixelTexGenParameterivSGIS"); 
		DynamicGL_PixelTexGenParameterfSGIS = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLfloat param)>("glPixelTexGenParameterfSGIS"); 
		DynamicGL_PixelTexGenParameterfvSGIS = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , const GLfloat *params)>("glPixelTexGenParameterfvSGIS"); 
		DynamicGL_GetPixelTexGenParameterivSGIS = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLint *params)>("glGetPixelTexGenParameterivSGIS"); 
		DynamicGL_GetPixelTexGenParameterfvSGIS = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLfloat *params)>("glGetPixelTexGenParameterfvSGIS"); 
		DinamicGLFeature_SGIS_pixel_texture_loaded = true; 
}
bool DinamicGLFeature_SGIS_pixel_texture_Supported() {
		if (!DinamicGLFeature_SGIS_pixel_texture_loaded) {
			InitDinamicGLFeature_SGIS_pixel_texture();
		}
		if (DynamicGL_PixelTexGenParameteriSGIS==0) return false; 
		if (DynamicGL_PixelTexGenParameterivSGIS==0) return false; 
		if (DynamicGL_PixelTexGenParameterfSGIS==0) return false; 
		if (DynamicGL_PixelTexGenParameterfvSGIS==0) return false; 
		if (DynamicGL_GetPixelTexGenParameterivSGIS==0) return false; 
		if (DynamicGL_GetPixelTexGenParameterfvSGIS==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIS_pixel_texture*/

/*SGIS_texture4D*/
#ifdef USE_DYNAMIC_GL_SGIS_texture4D
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexImage4DSGIS)(GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLsizei depth , GLsizei size4d , GLint border , GLenum format , GLenum type , const GLvoid *pixels) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexSubImage4DSGIS)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLint woffset , GLsizei width , GLsizei height , GLsizei depth , GLsizei size4d , GLenum format , GLenum type , const GLvoid *pixels) = 0; }
static bool DinamicGLFeature_SGIS_texture4D_loaded = false; 
static void InitDinamicGLFeature_SGIS_texture4D() {
		DynamicGL_TexImage4DSGIS = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLsizei depth , GLsizei size4d , GLint border , GLenum format , GLenum type , const GLvoid *pixels)>("glTexImage4DSGIS"); 
		DynamicGL_TexSubImage4DSGIS = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLint woffset , GLsizei width , GLsizei height , GLsizei depth , GLsizei size4d , GLenum format , GLenum type , const GLvoid *pixels)>("glTexSubImage4DSGIS"); 
		DinamicGLFeature_SGIS_texture4D_loaded = true; 
}
bool DinamicGLFeature_SGIS_texture4D_Supported() {
		if (!DinamicGLFeature_SGIS_texture4D_loaded) {
			InitDinamicGLFeature_SGIS_texture4D();
		}
		if (DynamicGL_TexImage4DSGIS==0) return false; 
		if (DynamicGL_TexSubImage4DSGIS==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIS_texture4D*/

/*SGIS_multisample*/
#ifdef USE_DYNAMIC_GL_SGIS_multisample
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SampleMaskSGIS)(GLclampf value , GLboolean invert) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SamplePatternSGIS)(GLenum pattern) = 0; }
static bool DinamicGLFeature_SGIS_multisample_loaded = false; 
static void InitDinamicGLFeature_SGIS_multisample() {
		DynamicGL_SampleMaskSGIS = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLclampf value , GLboolean invert)>("glSampleMaskSGIS"); 
		DynamicGL_SamplePatternSGIS = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pattern)>("glSamplePatternSGIS"); 
		DinamicGLFeature_SGIS_multisample_loaded = true; 
}
bool DinamicGLFeature_SGIS_multisample_Supported() {
		if (!DinamicGLFeature_SGIS_multisample_loaded) {
			InitDinamicGLFeature_SGIS_multisample();
		}
		if (DynamicGL_SampleMaskSGIS==0) return false; 
		if (DynamicGL_SamplePatternSGIS==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIS_multisample*/

/*PGI_misc_hints*/
#ifdef USE_DYNAMIC_GL_PGI_misc_hints
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_HintPGI)(GLenum target , GLint mode) = 0; }
static bool DinamicGLFeature_PGI_misc_hints_loaded = false; 
static void InitDinamicGLFeature_PGI_misc_hints() {
		DynamicGL_HintPGI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint mode)>("glHintPGI"); 
		DinamicGLFeature_PGI_misc_hints_loaded = true; 
}
bool DinamicGLFeature_PGI_misc_hints_Supported() {
		if (!DinamicGLFeature_PGI_misc_hints_loaded) {
			InitDinamicGLFeature_PGI_misc_hints();
		}
		if (DynamicGL_HintPGI==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_PGI_misc_hints*/

/*ARB_window_pos*/
#ifdef USE_DYNAMIC_GL_ARB_window_pos
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2dARB)(GLdouble x , GLdouble y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2dvARB)(const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2fARB)(GLfloat x , GLfloat y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2fvARB)(const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2iARB)(GLint x , GLint y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2ivARB)(const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2sARB)(GLshort x , GLshort y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2svARB)(const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3dARB)(GLdouble x , GLdouble y , GLdouble z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3dvARB)(const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3fARB)(GLfloat x , GLfloat y , GLfloat z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3fvARB)(const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3iARB)(GLint x , GLint y , GLint z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3ivARB)(const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3sARB)(GLshort x , GLshort y , GLshort z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3svARB)(const GLshort *v) = 0; }
static bool DinamicGLFeature_ARB_window_pos_loaded = false; 
static void InitDinamicGLFeature_ARB_window_pos() {
		DynamicGL_WindowPos2dARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble x , GLdouble y)>("glWindowPos2dARB"); 
		DynamicGL_WindowPos2dvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *v)>("glWindowPos2dvARB"); 
		DynamicGL_WindowPos2fARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat x , GLfloat y)>("glWindowPos2fARB"); 
		DynamicGL_WindowPos2fvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *v)>("glWindowPos2fvARB"); 
		DynamicGL_WindowPos2iARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint x , GLint y)>("glWindowPos2iARB"); 
		DynamicGL_WindowPos2ivARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLint *v)>("glWindowPos2ivARB"); 
		DynamicGL_WindowPos2sARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLshort x , GLshort y)>("glWindowPos2sARB"); 
		DynamicGL_WindowPos2svARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLshort *v)>("glWindowPos2svARB"); 
		DynamicGL_WindowPos3dARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble x , GLdouble y , GLdouble z)>("glWindowPos3dARB"); 
		DynamicGL_WindowPos3dvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *v)>("glWindowPos3dvARB"); 
		DynamicGL_WindowPos3fARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat x , GLfloat y , GLfloat z)>("glWindowPos3fARB"); 
		DynamicGL_WindowPos3fvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *v)>("glWindowPos3fvARB"); 
		DynamicGL_WindowPos3iARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint x , GLint y , GLint z)>("glWindowPos3iARB"); 
		DynamicGL_WindowPos3ivARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLint *v)>("glWindowPos3ivARB"); 
		DynamicGL_WindowPos3sARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLshort x , GLshort y , GLshort z)>("glWindowPos3sARB"); 
		DynamicGL_WindowPos3svARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLshort *v)>("glWindowPos3svARB"); 
		DinamicGLFeature_ARB_window_pos_loaded = true; 
}
bool DinamicGLFeature_ARB_window_pos_Supported() {
		if (!DinamicGLFeature_ARB_window_pos_loaded) {
			InitDinamicGLFeature_ARB_window_pos();
		}
		if (DynamicGL_WindowPos2dARB==0) return false; 
		if (DynamicGL_WindowPos2dvARB==0) return false; 
		if (DynamicGL_WindowPos2fARB==0) return false; 
		if (DynamicGL_WindowPos2fvARB==0) return false; 
		if (DynamicGL_WindowPos2iARB==0) return false; 
		if (DynamicGL_WindowPos2ivARB==0) return false; 
		if (DynamicGL_WindowPos2sARB==0) return false; 
		if (DynamicGL_WindowPos2svARB==0) return false; 
		if (DynamicGL_WindowPos3dARB==0) return false; 
		if (DynamicGL_WindowPos3dvARB==0) return false; 
		if (DynamicGL_WindowPos3fARB==0) return false; 
		if (DynamicGL_WindowPos3fvARB==0) return false; 
		if (DynamicGL_WindowPos3iARB==0) return false; 
		if (DynamicGL_WindowPos3ivARB==0) return false; 
		if (DynamicGL_WindowPos3sARB==0) return false; 
		if (DynamicGL_WindowPos3svARB==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_window_pos*/

/*SGIX_polynomial_ffd*/
#ifdef USE_DYNAMIC_GL_SGIX_polynomial_ffd
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DeformationMap3dSGIX)(GLenum target , GLdouble u1 , GLdouble u2 , GLint ustride , GLint uorder , GLdouble v1 , GLdouble v2 , GLint vstride , GLint vorder , GLdouble w1 , GLdouble w2 , GLint wstride , GLint worder , const GLdouble *points) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DeformationMap3fSGIX)(GLenum target , GLfloat u1 , GLfloat u2 , GLint ustride , GLint uorder , GLfloat v1 , GLfloat v2 , GLint vstride , GLint vorder , GLfloat w1 , GLfloat w2 , GLint wstride , GLint worder , const GLfloat *points) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DeformSGIX)(GLbitfield mask) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_LoadIdentityDeformationMapSGIX)(GLbitfield mask) = 0; }
static bool DinamicGLFeature_SGIX_polynomial_ffd_loaded = false; 
static void InitDinamicGLFeature_SGIX_polynomial_ffd() {
		DynamicGL_DeformationMap3dSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLdouble u1 , GLdouble u2 , GLint ustride , GLint uorder , GLdouble v1 , GLdouble v2 , GLint vstride , GLint vorder , GLdouble w1 , GLdouble w2 , GLint wstride , GLint worder , const GLdouble *points)>("glDeformationMap3dSGIX"); 
		DynamicGL_DeformationMap3fSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLfloat u1 , GLfloat u2 , GLint ustride , GLint uorder , GLfloat v1 , GLfloat v2 , GLint vstride , GLint vorder , GLfloat w1 , GLfloat w2 , GLint wstride , GLint worder , const GLfloat *points)>("glDeformationMap3fSGIX"); 
		DynamicGL_DeformSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLbitfield mask)>("glDeformSGIX"); 
		DynamicGL_LoadIdentityDeformationMapSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLbitfield mask)>("glLoadIdentityDeformationMapSGIX"); 
		DinamicGLFeature_SGIX_polynomial_ffd_loaded = true; 
}
bool DinamicGLFeature_SGIX_polynomial_ffd_Supported() {
		if (!DinamicGLFeature_SGIX_polynomial_ffd_loaded) {
			InitDinamicGLFeature_SGIX_polynomial_ffd();
		}
		if (DynamicGL_DeformationMap3dSGIX==0) return false; 
		if (DynamicGL_DeformationMap3fSGIX==0) return false; 
		if (DynamicGL_DeformSGIX==0) return false; 
		if (DynamicGL_LoadIdentityDeformationMapSGIX==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_polynomial_ffd*/

/*EXT_timer_query*/
#ifdef USE_DYNAMIC_GL_EXT_timer_query
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetQueryObjecti64vEXT)(GLuint id , GLenum pname , GLint64EXT *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetQueryObjectui64vEXT)(GLuint id , GLenum pname , GLuint64EXT *params) = 0; }
static bool DinamicGLFeature_EXT_timer_query_loaded = false; 
static void InitDinamicGLFeature_EXT_timer_query() {
		DynamicGL_GetQueryObjecti64vEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , GLenum pname , GLint64EXT *params)>("glGetQueryObjecti64vEXT"); 
		DynamicGL_GetQueryObjectui64vEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , GLenum pname , GLuint64EXT *params)>("glGetQueryObjectui64vEXT"); 
		DinamicGLFeature_EXT_timer_query_loaded = true; 
}
bool DinamicGLFeature_EXT_timer_query_Supported() {
		if (!DinamicGLFeature_EXT_timer_query_loaded) {
			InitDinamicGLFeature_EXT_timer_query();
		}
		if (DynamicGL_GetQueryObjecti64vEXT==0) return false; 
		if (DynamicGL_GetQueryObjectui64vEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_timer_query*/

/*SGIX_ir_instrument1*/
#ifdef USE_DYNAMIC_GL_SGIX_ir_instrument1
static bool DinamicGLFeature_SGIX_ir_instrument1_loaded = false; 
static void InitDinamicGLFeature_SGIX_ir_instrument1() {
		DinamicGLFeature_SGIX_ir_instrument1_loaded = true; 
}
bool DinamicGLFeature_SGIX_ir_instrument1_Supported() {
		if (!DinamicGLFeature_SGIX_ir_instrument1_loaded) {
			InitDinamicGLFeature_SGIX_ir_instrument1();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_ir_instrument1*/

/*SGIX_igloo_interface*/
#ifdef USE_DYNAMIC_GL_SGIX_igloo_interface
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_IglooInterfaceSGIX)(GLenum pname , const GLvoid *params) = 0; }
static bool DinamicGLFeature_SGIX_igloo_interface_loaded = false; 
static void InitDinamicGLFeature_SGIX_igloo_interface() {
		DynamicGL_IglooInterfaceSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , const GLvoid *params)>("glIglooInterfaceSGIX"); 
		DinamicGLFeature_SGIX_igloo_interface_loaded = true; 
}
bool DinamicGLFeature_SGIX_igloo_interface_Supported() {
		if (!DinamicGLFeature_SGIX_igloo_interface_loaded) {
			InitDinamicGLFeature_SGIX_igloo_interface();
		}
		if (DynamicGL_IglooInterfaceSGIX==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_igloo_interface*/

/*NV_fence*/
#ifdef USE_DYNAMIC_GL_NV_fence
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteFencesNV)(GLsizei n , const GLuint *fences) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GenFencesNV)(GLsizei n , GLuint *fences) = 0; }
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsFenceNV)(GLuint fence) = 0; }
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_TestFenceNV)(GLuint fence) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFenceivNV)(GLuint fence , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FinishFenceNV)(GLuint fence) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SetFenceNV)(GLuint fence , GLenum condition) = 0; }
static bool DinamicGLFeature_NV_fence_loaded = false; 
static void InitDinamicGLFeature_NV_fence() {
		DynamicGL_DeleteFencesNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , const GLuint *fences)>("glDeleteFencesNV"); 
		DynamicGL_GenFencesNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , GLuint *fences)>("glGenFencesNV"); 
		DynamicGL_IsFenceNV = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLuint fence)>("glIsFenceNV"); 
		DynamicGL_TestFenceNV = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLuint fence)>("glTestFenceNV"); 
		DynamicGL_GetFenceivNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint fence , GLenum pname , GLint *params)>("glGetFenceivNV"); 
		DynamicGL_FinishFenceNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint fence)>("glFinishFenceNV"); 
		DynamicGL_SetFenceNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint fence , GLenum condition)>("glSetFenceNV"); 
		DinamicGLFeature_NV_fence_loaded = true; 
}
bool DinamicGLFeature_NV_fence_Supported() {
		if (!DinamicGLFeature_NV_fence_loaded) {
			InitDinamicGLFeature_NV_fence();
		}
		if (DynamicGL_DeleteFencesNV==0) return false; 
		if (DynamicGL_GenFencesNV==0) return false; 
		if (DynamicGL_IsFenceNV==0) return false; 
		if (DynamicGL_TestFenceNV==0) return false; 
		if (DynamicGL_GetFenceivNV==0) return false; 
		if (DynamicGL_FinishFenceNV==0) return false; 
		if (DynamicGL_SetFenceNV==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_fence*/

/*NV_register_combiners*/
#ifdef USE_DYNAMIC_GL_NV_register_combiners
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CombinerParameterfvNV)(GLenum pname , const GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CombinerParameterfNV)(GLenum pname , GLfloat param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CombinerParameterivNV)(GLenum pname , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CombinerParameteriNV)(GLenum pname , GLint param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CombinerInputNV)(GLenum stage , GLenum portion , GLenum variable , GLenum input , GLenum mapping , GLenum componentUsage) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CombinerOutputNV)(GLenum stage , GLenum portion , GLenum abOutput , GLenum cdOutput , GLenum sumOutput , GLenum scale , GLenum bias , GLboolean abDotProduct , GLboolean cdDotProduct , GLboolean muxSum) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FinalCombinerInputNV)(GLenum variable , GLenum input , GLenum mapping , GLenum componentUsage) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetCombinerInputParameterfvNV)(GLenum stage , GLenum portion , GLenum variable , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetCombinerInputParameterivNV)(GLenum stage , GLenum portion , GLenum variable , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetCombinerOutputParameterfvNV)(GLenum stage , GLenum portion , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetCombinerOutputParameterivNV)(GLenum stage , GLenum portion , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFinalCombinerInputParameterfvNV)(GLenum variable , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFinalCombinerInputParameterivNV)(GLenum variable , GLenum pname , GLint *params) = 0; }
static bool DinamicGLFeature_NV_register_combiners_loaded = false; 
static void InitDinamicGLFeature_NV_register_combiners() {
		DynamicGL_CombinerParameterfvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , const GLfloat *params)>("glCombinerParameterfvNV"); 
		DynamicGL_CombinerParameterfNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLfloat param)>("glCombinerParameterfNV"); 
		DynamicGL_CombinerParameterivNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , const GLint *params)>("glCombinerParameterivNV"); 
		DynamicGL_CombinerParameteriNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLint param)>("glCombinerParameteriNV"); 
		DynamicGL_CombinerInputNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stage , GLenum portion , GLenum variable , GLenum input , GLenum mapping , GLenum componentUsage)>("glCombinerInputNV"); 
		DynamicGL_CombinerOutputNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stage , GLenum portion , GLenum abOutput , GLenum cdOutput , GLenum sumOutput , GLenum scale , GLenum bias , GLboolean abDotProduct , GLboolean cdDotProduct , GLboolean muxSum)>("glCombinerOutputNV"); 
		DynamicGL_FinalCombinerInputNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum variable , GLenum input , GLenum mapping , GLenum componentUsage)>("glFinalCombinerInputNV"); 
		DynamicGL_GetCombinerInputParameterfvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stage , GLenum portion , GLenum variable , GLenum pname , GLfloat *params)>("glGetCombinerInputParameterfvNV"); 
		DynamicGL_GetCombinerInputParameterivNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stage , GLenum portion , GLenum variable , GLenum pname , GLint *params)>("glGetCombinerInputParameterivNV"); 
		DynamicGL_GetCombinerOutputParameterfvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stage , GLenum portion , GLenum pname , GLfloat *params)>("glGetCombinerOutputParameterfvNV"); 
		DynamicGL_GetCombinerOutputParameterivNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stage , GLenum portion , GLenum pname , GLint *params)>("glGetCombinerOutputParameterivNV"); 
		DynamicGL_GetFinalCombinerInputParameterfvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum variable , GLenum pname , GLfloat *params)>("glGetFinalCombinerInputParameterfvNV"); 
		DynamicGL_GetFinalCombinerInputParameterivNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum variable , GLenum pname , GLint *params)>("glGetFinalCombinerInputParameterivNV"); 
		DinamicGLFeature_NV_register_combiners_loaded = true; 
}
bool DinamicGLFeature_NV_register_combiners_Supported() {
		if (!DinamicGLFeature_NV_register_combiners_loaded) {
			InitDinamicGLFeature_NV_register_combiners();
		}
		if (DynamicGL_CombinerParameterfvNV==0) return false; 
		if (DynamicGL_CombinerParameterfNV==0) return false; 
		if (DynamicGL_CombinerParameterivNV==0) return false; 
		if (DynamicGL_CombinerParameteriNV==0) return false; 
		if (DynamicGL_CombinerInputNV==0) return false; 
		if (DynamicGL_CombinerOutputNV==0) return false; 
		if (DynamicGL_FinalCombinerInputNV==0) return false; 
		if (DynamicGL_GetCombinerInputParameterfvNV==0) return false; 
		if (DynamicGL_GetCombinerInputParameterivNV==0) return false; 
		if (DynamicGL_GetCombinerOutputParameterfvNV==0) return false; 
		if (DynamicGL_GetCombinerOutputParameterivNV==0) return false; 
		if (DynamicGL_GetFinalCombinerInputParameterfvNV==0) return false; 
		if (DynamicGL_GetFinalCombinerInputParameterivNV==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_register_combiners*/

/*VERSION_3_0*/
#ifdef USE_DYNAMIC_GL_VERSION_3_0
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorMaski)(GLuint index , GLboolean r , GLboolean g , GLboolean b , GLboolean a) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetBooleani_v)(GLenum target , GLuint index , GLboolean *data) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetIntegeri_v)(GLenum target , GLuint index , GLint *data) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Enablei)(GLenum target , GLuint index) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Disablei)(GLenum target , GLuint index) = 0; }
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsEnabledi)(GLenum target , GLuint index) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BeginTransformFeedback)(GLenum primitiveMode) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EndTransformFeedback)() = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BindBufferRange)(GLenum target , GLuint index , GLuint buffer , GLintptr offset , GLsizeiptr size) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BindBufferBase)(GLenum target , GLuint index , GLuint buffer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TransformFeedbackVaryings)(GLuint program , GLsizei count , const GLint *locations , GLenum bufferMode) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTransformFeedbackVarying)(GLuint program , GLuint index , GLint *location) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ClampColor)(GLenum target , GLenum clamp) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BeginConditionalRender)(GLuint id , GLenum mode) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EndConditionalRender)() = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI1i)(GLuint index , GLint x) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI2i)(GLuint index , GLint x , GLint y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI3i)(GLuint index , GLint x , GLint y , GLint z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI4i)(GLuint index , GLint x , GLint y , GLint z , GLint w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI1ui)(GLuint index , GLuint x) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI2ui)(GLuint index , GLuint x , GLuint y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI3ui)(GLuint index , GLuint x , GLuint y , GLuint z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI4ui)(GLuint index , GLuint x , GLuint y , GLuint z , GLuint w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI1iv)(GLuint index , const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI2iv)(GLuint index , const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI3iv)(GLuint index , const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI4iv)(GLuint index , const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI1uiv)(GLuint index , const GLuint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI2uiv)(GLuint index , const GLuint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI3uiv)(GLuint index , const GLuint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI4uiv)(GLuint index , const GLuint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI4bv)(GLuint index , const GLbyte *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI4sv)(GLuint index , const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI4ubv)(GLuint index , const GLubyte *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI4usv)(GLuint index , const GLushort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribIPointer)(GLuint index , GLint size , GLenum type , GLsizei stride , const GLvoid *pointer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribIiv)(GLuint index , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribIuiv)(GLuint index , GLenum pname , GLuint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetUniformuiv)(GLuint program , GLint location , GLuint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BindFragDataLocation)(GLuint program , GLuint color , const GLchar *name) = 0; }
extern "C" { GLint (DYNAMIC_GL_APIENTRYP DynamicGL_GetFragDataLocation)(GLuint program , const GLchar *name) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform1ui)(GLint location , GLuint v0) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform2ui)(GLint location , GLuint v0 , GLuint v1) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform3ui)(GLint location , GLuint v0 , GLuint v1 , GLuint v2) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform4ui)(GLint location , GLuint v0 , GLuint v1 , GLuint v2 , GLuint v3) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform1uiv)(GLint location , GLsizei count , const GLuint *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform2uiv)(GLint location , GLsizei count , const GLuint *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform3uiv)(GLint location , GLsizei count , const GLuint *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform4uiv)(GLint location , GLsizei count , const GLuint *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexParameterIiv)(GLenum target , GLenum pname , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexParameterIuiv)(GLenum target , GLenum pname , const GLuint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexParameterIiv)(GLenum target , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexParameterIuiv)(GLenum target , GLenum pname , GLuint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearBufferiv)(GLenum buffer , const GLint *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearBufferuiv)(GLenum buffer , const GLuint *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearBufferfv)(GLenum buffer , const GLfloat *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearBufferfi)(GLenum buffer , GLfloat depth , GLint stencil) = 0; }
static bool DinamicGLFeature_VERSION_3_0_loaded = false; 
static void InitDinamicGLFeature_VERSION_3_0() {
		DynamicGL_ColorMaski = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLboolean r , GLboolean g , GLboolean b , GLboolean a)>("glColorMaski"); 
		DynamicGL_GetBooleani_v = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLboolean *data)>("glGetBooleani_v"); 
		DynamicGL_GetIntegeri_v = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLint *data)>("glGetIntegeri_v"); 
		DynamicGL_Enablei = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index)>("glEnablei"); 
		DynamicGL_Disablei = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index)>("glDisablei"); 
		DynamicGL_IsEnabledi = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index)>("glIsEnabledi"); 
		DynamicGL_BeginTransformFeedback = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum primitiveMode)>("glBeginTransformFeedback"); 
		DynamicGL_EndTransformFeedback = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glEndTransformFeedback"); 
		DynamicGL_BindBufferRange = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLuint buffer , GLintptr offset , GLsizeiptr size)>("glBindBufferRange"); 
		DynamicGL_BindBufferBase = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLuint buffer)>("glBindBufferBase"); 
		DynamicGL_TransformFeedbackVaryings = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLsizei count , const GLint *locations , GLenum bufferMode)>("glTransformFeedbackVaryings"); 
		DynamicGL_GetTransformFeedbackVarying = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLuint index , GLint *location)>("glGetTransformFeedbackVarying"); 
		DynamicGL_ClampColor = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum clamp)>("glClampColor"); 
		DynamicGL_BeginConditionalRender = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , GLenum mode)>("glBeginConditionalRender"); 
		DynamicGL_EndConditionalRender = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glEndConditionalRender"); 
		DynamicGL_VertexAttribI1i = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLint x)>("glVertexAttribI1i"); 
		DynamicGL_VertexAttribI2i = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLint x , GLint y)>("glVertexAttribI2i"); 
		DynamicGL_VertexAttribI3i = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLint x , GLint y , GLint z)>("glVertexAttribI3i"); 
		DynamicGL_VertexAttribI4i = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLint x , GLint y , GLint z , GLint w)>("glVertexAttribI4i"); 
		DynamicGL_VertexAttribI1ui = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLuint x)>("glVertexAttribI1ui"); 
		DynamicGL_VertexAttribI2ui = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLuint x , GLuint y)>("glVertexAttribI2ui"); 
		DynamicGL_VertexAttribI3ui = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLuint x , GLuint y , GLuint z)>("glVertexAttribI3ui"); 
		DynamicGL_VertexAttribI4ui = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLuint x , GLuint y , GLuint z , GLuint w)>("glVertexAttribI4ui"); 
		DynamicGL_VertexAttribI1iv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLint *v)>("glVertexAttribI1iv"); 
		DynamicGL_VertexAttribI2iv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLint *v)>("glVertexAttribI2iv"); 
		DynamicGL_VertexAttribI3iv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLint *v)>("glVertexAttribI3iv"); 
		DynamicGL_VertexAttribI4iv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLint *v)>("glVertexAttribI4iv"); 
		DynamicGL_VertexAttribI1uiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLuint *v)>("glVertexAttribI1uiv"); 
		DynamicGL_VertexAttribI2uiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLuint *v)>("glVertexAttribI2uiv"); 
		DynamicGL_VertexAttribI3uiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLuint *v)>("glVertexAttribI3uiv"); 
		DynamicGL_VertexAttribI4uiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLuint *v)>("glVertexAttribI4uiv"); 
		DynamicGL_VertexAttribI4bv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLbyte *v)>("glVertexAttribI4bv"); 
		DynamicGL_VertexAttribI4sv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLshort *v)>("glVertexAttribI4sv"); 
		DynamicGL_VertexAttribI4ubv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLubyte *v)>("glVertexAttribI4ubv"); 
		DynamicGL_VertexAttribI4usv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLushort *v)>("glVertexAttribI4usv"); 
		DynamicGL_VertexAttribIPointer = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLint size , GLenum type , GLsizei stride , const GLvoid *pointer)>("glVertexAttribIPointer"); 
		DynamicGL_GetVertexAttribIiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLenum pname , GLint *params)>("glGetVertexAttribIiv"); 
		DynamicGL_GetVertexAttribIuiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLenum pname , GLuint *params)>("glGetVertexAttribIuiv"); 
		DynamicGL_GetUniformuiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLuint *params)>("glGetUniformuiv"); 
		DynamicGL_BindFragDataLocation = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLuint color , const GLchar *name)>("glBindFragDataLocation"); 
		DynamicGL_GetFragDataLocation = DynamicGL_LoadFunction<GLint (DYNAMIC_GL_APIENTRYP)(GLuint program , const GLchar *name)>("glGetFragDataLocation"); 
		DynamicGL_Uniform1ui = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLuint v0)>("glUniform1ui"); 
		DynamicGL_Uniform2ui = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLuint v0 , GLuint v1)>("glUniform2ui"); 
		DynamicGL_Uniform3ui = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLuint v0 , GLuint v1 , GLuint v2)>("glUniform3ui"); 
		DynamicGL_Uniform4ui = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLuint v0 , GLuint v1 , GLuint v2 , GLuint v3)>("glUniform4ui"); 
		DynamicGL_Uniform1uiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , const GLuint *value)>("glUniform1uiv"); 
		DynamicGL_Uniform2uiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , const GLuint *value)>("glUniform2uiv"); 
		DynamicGL_Uniform3uiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , const GLuint *value)>("glUniform3uiv"); 
		DynamicGL_Uniform4uiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , const GLuint *value)>("glUniform4uiv"); 
		DynamicGL_TexParameterIiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , const GLint *params)>("glTexParameterIiv"); 
		DynamicGL_TexParameterIuiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , const GLuint *params)>("glTexParameterIuiv"); 
		DynamicGL_GetTexParameterIiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint *params)>("glGetTexParameterIiv"); 
		DynamicGL_GetTexParameterIuiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLuint *params)>("glGetTexParameterIuiv"); 
		DynamicGL_ClearBufferiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum buffer , const GLint *value)>("glClearBufferiv"); 
		DynamicGL_ClearBufferuiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum buffer , const GLuint *value)>("glClearBufferuiv"); 
		DynamicGL_ClearBufferfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum buffer , const GLfloat *value)>("glClearBufferfv"); 
		DynamicGL_ClearBufferfi = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum buffer , GLfloat depth , GLint stencil)>("glClearBufferfi"); 
		DinamicGLFeature_VERSION_3_0_loaded = true; 
}
bool DinamicGLFeature_VERSION_3_0_Supported() {
		if (!DinamicGLFeature_VERSION_3_0_loaded) {
			InitDinamicGLFeature_VERSION_3_0();
		}
		if (DynamicGL_ColorMaski==0) return false; 
		if (DynamicGL_GetBooleani_v==0) return false; 
		if (DynamicGL_GetIntegeri_v==0) return false; 
		if (DynamicGL_Enablei==0) return false; 
		if (DynamicGL_Disablei==0) return false; 
		if (DynamicGL_IsEnabledi==0) return false; 
		if (DynamicGL_BeginTransformFeedback==0) return false; 
		if (DynamicGL_EndTransformFeedback==0) return false; 
		if (DynamicGL_BindBufferRange==0) return false; 
		if (DynamicGL_BindBufferBase==0) return false; 
		if (DynamicGL_TransformFeedbackVaryings==0) return false; 
		if (DynamicGL_GetTransformFeedbackVarying==0) return false; 
		if (DynamicGL_ClampColor==0) return false; 
		if (DynamicGL_BeginConditionalRender==0) return false; 
		if (DynamicGL_EndConditionalRender==0) return false; 
		if (DynamicGL_VertexAttribI1i==0) return false; 
		if (DynamicGL_VertexAttribI2i==0) return false; 
		if (DynamicGL_VertexAttribI3i==0) return false; 
		if (DynamicGL_VertexAttribI4i==0) return false; 
		if (DynamicGL_VertexAttribI1ui==0) return false; 
		if (DynamicGL_VertexAttribI2ui==0) return false; 
		if (DynamicGL_VertexAttribI3ui==0) return false; 
		if (DynamicGL_VertexAttribI4ui==0) return false; 
		if (DynamicGL_VertexAttribI1iv==0) return false; 
		if (DynamicGL_VertexAttribI2iv==0) return false; 
		if (DynamicGL_VertexAttribI3iv==0) return false; 
		if (DynamicGL_VertexAttribI4iv==0) return false; 
		if (DynamicGL_VertexAttribI1uiv==0) return false; 
		if (DynamicGL_VertexAttribI2uiv==0) return false; 
		if (DynamicGL_VertexAttribI3uiv==0) return false; 
		if (DynamicGL_VertexAttribI4uiv==0) return false; 
		if (DynamicGL_VertexAttribI4bv==0) return false; 
		if (DynamicGL_VertexAttribI4sv==0) return false; 
		if (DynamicGL_VertexAttribI4ubv==0) return false; 
		if (DynamicGL_VertexAttribI4usv==0) return false; 
		if (DynamicGL_VertexAttribIPointer==0) return false; 
		if (DynamicGL_GetVertexAttribIiv==0) return false; 
		if (DynamicGL_GetVertexAttribIuiv==0) return false; 
		if (DynamicGL_GetUniformuiv==0) return false; 
		if (DynamicGL_BindFragDataLocation==0) return false; 
		if (DynamicGL_GetFragDataLocation==0) return false; 
		if (DynamicGL_Uniform1ui==0) return false; 
		if (DynamicGL_Uniform2ui==0) return false; 
		if (DynamicGL_Uniform3ui==0) return false; 
		if (DynamicGL_Uniform4ui==0) return false; 
		if (DynamicGL_Uniform1uiv==0) return false; 
		if (DynamicGL_Uniform2uiv==0) return false; 
		if (DynamicGL_Uniform3uiv==0) return false; 
		if (DynamicGL_Uniform4uiv==0) return false; 
		if (DynamicGL_TexParameterIiv==0) return false; 
		if (DynamicGL_TexParameterIuiv==0) return false; 
		if (DynamicGL_GetTexParameterIiv==0) return false; 
		if (DynamicGL_GetTexParameterIuiv==0) return false; 
		if (DynamicGL_ClearBufferiv==0) return false; 
		if (DynamicGL_ClearBufferuiv==0) return false; 
		if (DynamicGL_ClearBufferfv==0) return false; 
		if (DynamicGL_ClearBufferfi==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_VERSION_3_0*/

/*NV_point_sprite*/
#ifdef USE_DYNAMIC_GL_NV_point_sprite
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameteriNV)(GLenum pname , GLint param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameterivNV)(GLenum pname , const GLint *params) = 0; }
static bool DinamicGLFeature_NV_point_sprite_loaded = false; 
static void InitDinamicGLFeature_NV_point_sprite() {
		DynamicGL_PointParameteriNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLint param)>("glPointParameteriNV"); 
		DynamicGL_PointParameterivNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , const GLint *params)>("glPointParameterivNV"); 
		DinamicGLFeature_NV_point_sprite_loaded = true; 
}
bool DinamicGLFeature_NV_point_sprite_Supported() {
		if (!DinamicGLFeature_NV_point_sprite_loaded) {
			InitDinamicGLFeature_NV_point_sprite();
		}
		if (DynamicGL_PointParameteriNV==0) return false; 
		if (DynamicGL_PointParameterivNV==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_point_sprite*/

/*EXT_texture_compression_latc*/
#ifdef USE_DYNAMIC_GL_EXT_texture_compression_latc
static bool DinamicGLFeature_EXT_texture_compression_latc_loaded = false; 
static void InitDinamicGLFeature_EXT_texture_compression_latc() {
		DinamicGLFeature_EXT_texture_compression_latc_loaded = true; 
}
bool DinamicGLFeature_EXT_texture_compression_latc_Supported() {
		if (!DinamicGLFeature_EXT_texture_compression_latc_loaded) {
			InitDinamicGLFeature_EXT_texture_compression_latc();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_texture_compression_latc*/

/*ARB_instanced_arrays*/
#ifdef USE_DYNAMIC_GL_ARB_instanced_arrays
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribDivisor)(GLuint index , GLuint divisor) = 0; }
static bool DinamicGLFeature_ARB_instanced_arrays_loaded = false; 
static void InitDinamicGLFeature_ARB_instanced_arrays() {
		DynamicGL_VertexAttribDivisor = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLuint divisor)>("glVertexAttribDivisor"); 
		DinamicGLFeature_ARB_instanced_arrays_loaded = true; 
}
bool DinamicGLFeature_ARB_instanced_arrays_Supported() {
		if (!DinamicGLFeature_ARB_instanced_arrays_loaded) {
			InitDinamicGLFeature_ARB_instanced_arrays();
		}
		if (DynamicGL_VertexAttribDivisor==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_instanced_arrays*/

/*EXT_transform_feedback*/
#ifdef USE_DYNAMIC_GL_EXT_transform_feedback
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BeginTransformFeedbackEXT)(GLenum primitiveMode) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EndTransformFeedbackEXT)() = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BindBufferRangeEXT)(GLenum target , GLuint index , GLuint buffer , GLintptr offset , GLsizeiptr size) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BindBufferOffsetEXT)(GLenum target , GLuint index , GLuint buffer , GLintptr offset) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BindBufferBaseEXT)(GLenum target , GLuint index , GLuint buffer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TransformFeedbackVaryingsEXT)(GLuint program , GLsizei count , const GLint *locations , GLenum bufferMode) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTransformFeedbackVaryingEXT)(GLuint program , GLuint index , GLint *location) = 0; }
static bool DinamicGLFeature_EXT_transform_feedback_loaded = false; 
static void InitDinamicGLFeature_EXT_transform_feedback() {
		DynamicGL_BeginTransformFeedbackEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum primitiveMode)>("glBeginTransformFeedbackEXT"); 
		DynamicGL_EndTransformFeedbackEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glEndTransformFeedbackEXT"); 
		DynamicGL_BindBufferRangeEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLuint buffer , GLintptr offset , GLsizeiptr size)>("glBindBufferRangeEXT"); 
		DynamicGL_BindBufferOffsetEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLuint buffer , GLintptr offset)>("glBindBufferOffsetEXT"); 
		DynamicGL_BindBufferBaseEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLuint buffer)>("glBindBufferBaseEXT"); 
		DynamicGL_TransformFeedbackVaryingsEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLsizei count , const GLint *locations , GLenum bufferMode)>("glTransformFeedbackVaryingsEXT"); 
		DynamicGL_GetTransformFeedbackVaryingEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLuint index , GLint *location)>("glGetTransformFeedbackVaryingEXT"); 
		DinamicGLFeature_EXT_transform_feedback_loaded = true; 
}
bool DinamicGLFeature_EXT_transform_feedback_Supported() {
		if (!DinamicGLFeature_EXT_transform_feedback_loaded) {
			InitDinamicGLFeature_EXT_transform_feedback();
		}
		if (DynamicGL_BeginTransformFeedbackEXT==0) return false; 
		if (DynamicGL_EndTransformFeedbackEXT==0) return false; 
		if (DynamicGL_BindBufferRangeEXT==0) return false; 
		if (DynamicGL_BindBufferOffsetEXT==0) return false; 
		if (DynamicGL_BindBufferBaseEXT==0) return false; 
		if (DynamicGL_TransformFeedbackVaryingsEXT==0) return false; 
		if (DynamicGL_GetTransformFeedbackVaryingEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_transform_feedback*/

/*INGR_color_clamp*/
#ifdef USE_DYNAMIC_GL_INGR_color_clamp
static bool DinamicGLFeature_INGR_color_clamp_loaded = false; 
static void InitDinamicGLFeature_INGR_color_clamp() {
		DinamicGLFeature_INGR_color_clamp_loaded = true; 
}
bool DinamicGLFeature_INGR_color_clamp_Supported() {
		if (!DinamicGLFeature_INGR_color_clamp_loaded) {
			InitDinamicGLFeature_INGR_color_clamp();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_INGR_color_clamp*/

/*ARB_depth_buffer_float*/
#ifdef USE_DYNAMIC_GL_ARB_depth_buffer_float
static bool DinamicGLFeature_ARB_depth_buffer_float_loaded = false; 
static void InitDinamicGLFeature_ARB_depth_buffer_float() {
		DinamicGLFeature_ARB_depth_buffer_float_loaded = true; 
}
bool DinamicGLFeature_ARB_depth_buffer_float_Supported() {
		if (!DinamicGLFeature_ARB_depth_buffer_float_loaded) {
			InitDinamicGLFeature_ARB_depth_buffer_float();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_depth_buffer_float*/

/*NV_texture_shader3*/
#ifdef USE_DYNAMIC_GL_NV_texture_shader3
static bool DinamicGLFeature_NV_texture_shader3_loaded = false; 
static void InitDinamicGLFeature_NV_texture_shader3() {
		DinamicGLFeature_NV_texture_shader3_loaded = true; 
}
bool DinamicGLFeature_NV_texture_shader3_Supported() {
		if (!DinamicGLFeature_NV_texture_shader3_loaded) {
			InitDinamicGLFeature_NV_texture_shader3();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_texture_shader3*/

/*ARB_texture_compression_rgtc*/
#ifdef USE_DYNAMIC_GL_ARB_texture_compression_rgtc
static bool DinamicGLFeature_ARB_texture_compression_rgtc_loaded = false; 
static void InitDinamicGLFeature_ARB_texture_compression_rgtc() {
		DinamicGLFeature_ARB_texture_compression_rgtc_loaded = true; 
}
bool DinamicGLFeature_ARB_texture_compression_rgtc_Supported() {
		if (!DinamicGLFeature_ARB_texture_compression_rgtc_loaded) {
			InitDinamicGLFeature_ARB_texture_compression_rgtc();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_texture_compression_rgtc*/

/*EXT_framebuffer_blit*/
#ifdef USE_DYNAMIC_GL_EXT_framebuffer_blit
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BlitFramebufferEXT)(GLint srcX0 , GLint srcY0 , GLint srcX1 , GLint srcY1 , GLint dstX0 , GLint dstY0 , GLint dstX1 , GLint dstY1 , GLbitfield mask , GLenum filter) = 0; }
static bool DinamicGLFeature_EXT_framebuffer_blit_loaded = false; 
static void InitDinamicGLFeature_EXT_framebuffer_blit() {
		DynamicGL_BlitFramebufferEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint srcX0 , GLint srcY0 , GLint srcX1 , GLint srcY1 , GLint dstX0 , GLint dstY0 , GLint dstX1 , GLint dstY1 , GLbitfield mask , GLenum filter)>("glBlitFramebufferEXT"); 
		DinamicGLFeature_EXT_framebuffer_blit_loaded = true; 
}
bool DinamicGLFeature_EXT_framebuffer_blit_Supported() {
		if (!DinamicGLFeature_EXT_framebuffer_blit_loaded) {
			InitDinamicGLFeature_EXT_framebuffer_blit();
		}
		if (DynamicGL_BlitFramebufferEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_framebuffer_blit*/

/*OML_resample*/
#ifdef USE_DYNAMIC_GL_OML_resample
static bool DinamicGLFeature_OML_resample_loaded = false; 
static void InitDinamicGLFeature_OML_resample() {
		DinamicGLFeature_OML_resample_loaded = true; 
}
bool DinamicGLFeature_OML_resample_Supported() {
		if (!DinamicGLFeature_OML_resample_loaded) {
			InitDinamicGLFeature_OML_resample();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_OML_resample*/

/*EXT_cmyka*/
#ifdef USE_DYNAMIC_GL_EXT_cmyka
static bool DinamicGLFeature_EXT_cmyka_loaded = false; 
static void InitDinamicGLFeature_EXT_cmyka() {
		DinamicGLFeature_EXT_cmyka_loaded = true; 
}
bool DinamicGLFeature_EXT_cmyka_Supported() {
		if (!DinamicGLFeature_EXT_cmyka_loaded) {
			InitDinamicGLFeature_EXT_cmyka();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_cmyka*/

/*SUN_convolution_border_modes*/
#ifdef USE_DYNAMIC_GL_SUN_convolution_border_modes
static bool DinamicGLFeature_SUN_convolution_border_modes_loaded = false; 
static void InitDinamicGLFeature_SUN_convolution_border_modes() {
		DinamicGLFeature_SUN_convolution_border_modes_loaded = true; 
}
bool DinamicGLFeature_SUN_convolution_border_modes_Supported() {
		if (!DinamicGLFeature_SUN_convolution_border_modes_loaded) {
			InitDinamicGLFeature_SUN_convolution_border_modes();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SUN_convolution_border_modes*/

/*EXT_draw_instanced*/
#ifdef USE_DYNAMIC_GL_EXT_draw_instanced
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawArraysInstancedEXT)(GLenum mode , GLint start , GLsizei count , GLsizei primcount) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawElementsInstancedEXT)(GLenum mode , GLsizei count , GLenum type , const GLvoid *indices , GLsizei primcount) = 0; }
static bool DinamicGLFeature_EXT_draw_instanced_loaded = false; 
static void InitDinamicGLFeature_EXT_draw_instanced() {
		DynamicGL_DrawArraysInstancedEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , GLint start , GLsizei count , GLsizei primcount)>("glDrawArraysInstancedEXT"); 
		DynamicGL_DrawElementsInstancedEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , GLsizei count , GLenum type , const GLvoid *indices , GLsizei primcount)>("glDrawElementsInstancedEXT"); 
		DinamicGLFeature_EXT_draw_instanced_loaded = true; 
}
bool DinamicGLFeature_EXT_draw_instanced_Supported() {
		if (!DinamicGLFeature_EXT_draw_instanced_loaded) {
			InitDinamicGLFeature_EXT_draw_instanced();
		}
		if (DynamicGL_DrawArraysInstancedEXT==0) return false; 
		if (DynamicGL_DrawElementsInstancedEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_draw_instanced*/

/*SGIS_detail_texture*/
#ifdef USE_DYNAMIC_GL_SGIS_detail_texture
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DetailTexFuncSGIS)(GLenum target , GLsizei n , const GLfloat *points) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetDetailTexFuncSGIS)(GLenum target , GLfloat *points) = 0; }
static bool DinamicGLFeature_SGIS_detail_texture_loaded = false; 
static void InitDinamicGLFeature_SGIS_detail_texture() {
		DynamicGL_DetailTexFuncSGIS = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLsizei n , const GLfloat *points)>("glDetailTexFuncSGIS"); 
		DynamicGL_GetDetailTexFuncSGIS = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLfloat *points)>("glGetDetailTexFuncSGIS"); 
		DinamicGLFeature_SGIS_detail_texture_loaded = true; 
}
bool DinamicGLFeature_SGIS_detail_texture_Supported() {
		if (!DinamicGLFeature_SGIS_detail_texture_loaded) {
			InitDinamicGLFeature_SGIS_detail_texture();
		}
		if (DynamicGL_DetailTexFuncSGIS==0) return false; 
		if (DynamicGL_GetDetailTexFuncSGIS==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIS_detail_texture*/

/*MESA_resize_buffers*/
#ifdef USE_DYNAMIC_GL_MESA_resize_buffers
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ResizeBuffersMESA)() = 0; }
static bool DinamicGLFeature_MESA_resize_buffers_loaded = false; 
static void InitDinamicGLFeature_MESA_resize_buffers() {
		DynamicGL_ResizeBuffersMESA = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glResizeBuffersMESA"); 
		DinamicGLFeature_MESA_resize_buffers_loaded = true; 
}
bool DinamicGLFeature_MESA_resize_buffers_Supported() {
		if (!DinamicGLFeature_MESA_resize_buffers_loaded) {
			InitDinamicGLFeature_MESA_resize_buffers();
		}
		if (DynamicGL_ResizeBuffersMESA==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_MESA_resize_buffers*/

/*SUN_global_alpha*/
#ifdef USE_DYNAMIC_GL_SUN_global_alpha
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GlobalAlphaFactorbSUN)(GLbyte factor) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GlobalAlphaFactorsSUN)(GLshort factor) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GlobalAlphaFactoriSUN)(GLint factor) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GlobalAlphaFactorfSUN)(GLfloat factor) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GlobalAlphaFactordSUN)(GLdouble factor) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GlobalAlphaFactorubSUN)(GLubyte factor) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GlobalAlphaFactorusSUN)(GLushort factor) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GlobalAlphaFactoruiSUN)(GLuint factor) = 0; }
static bool DinamicGLFeature_SUN_global_alpha_loaded = false; 
static void InitDinamicGLFeature_SUN_global_alpha() {
		DynamicGL_GlobalAlphaFactorbSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLbyte factor)>("glGlobalAlphaFactorbSUN"); 
		DynamicGL_GlobalAlphaFactorsSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLshort factor)>("glGlobalAlphaFactorsSUN"); 
		DynamicGL_GlobalAlphaFactoriSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint factor)>("glGlobalAlphaFactoriSUN"); 
		DynamicGL_GlobalAlphaFactorfSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat factor)>("glGlobalAlphaFactorfSUN"); 
		DynamicGL_GlobalAlphaFactordSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble factor)>("glGlobalAlphaFactordSUN"); 
		DynamicGL_GlobalAlphaFactorubSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLubyte factor)>("glGlobalAlphaFactorubSUN"); 
		DynamicGL_GlobalAlphaFactorusSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLushort factor)>("glGlobalAlphaFactorusSUN"); 
		DynamicGL_GlobalAlphaFactoruiSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint factor)>("glGlobalAlphaFactoruiSUN"); 
		DinamicGLFeature_SUN_global_alpha_loaded = true; 
}
bool DinamicGLFeature_SUN_global_alpha_Supported() {
		if (!DinamicGLFeature_SUN_global_alpha_loaded) {
			InitDinamicGLFeature_SUN_global_alpha();
		}
		if (DynamicGL_GlobalAlphaFactorbSUN==0) return false; 
		if (DynamicGL_GlobalAlphaFactorsSUN==0) return false; 
		if (DynamicGL_GlobalAlphaFactoriSUN==0) return false; 
		if (DynamicGL_GlobalAlphaFactorfSUN==0) return false; 
		if (DynamicGL_GlobalAlphaFactordSUN==0) return false; 
		if (DynamicGL_GlobalAlphaFactorubSUN==0) return false; 
		if (DynamicGL_GlobalAlphaFactorusSUN==0) return false; 
		if (DynamicGL_GlobalAlphaFactoruiSUN==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_SUN_global_alpha*/

/*ARB_depth_texture*/
#ifdef USE_DYNAMIC_GL_ARB_depth_texture
static bool DinamicGLFeature_ARB_depth_texture_loaded = false; 
static void InitDinamicGLFeature_ARB_depth_texture() {
		DinamicGLFeature_ARB_depth_texture_loaded = true; 
}
bool DinamicGLFeature_ARB_depth_texture_Supported() {
		if (!DinamicGLFeature_ARB_depth_texture_loaded) {
			InitDinamicGLFeature_ARB_depth_texture();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_depth_texture*/

/*HP_convolution_border_modes*/
#ifdef USE_DYNAMIC_GL_HP_convolution_border_modes
static bool DinamicGLFeature_HP_convolution_border_modes_loaded = false; 
static void InitDinamicGLFeature_HP_convolution_border_modes() {
		DinamicGLFeature_HP_convolution_border_modes_loaded = true; 
}
bool DinamicGLFeature_HP_convolution_border_modes_Supported() {
		if (!DinamicGLFeature_HP_convolution_border_modes_loaded) {
			InitDinamicGLFeature_HP_convolution_border_modes();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_HP_convolution_border_modes*/

/*NV_fragment_program*/
#ifdef USE_DYNAMIC_GL_NV_fragment_program
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramNamedParameter4fNV)(GLuint id , GLsizei len , const GLubyte *name , GLfloat x , GLfloat y , GLfloat z , GLfloat w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramNamedParameter4dNV)(GLuint id , GLsizei len , const GLubyte *name , GLdouble x , GLdouble y , GLdouble z , GLdouble w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramNamedParameter4fvNV)(GLuint id , GLsizei len , const GLubyte *name , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramNamedParameter4dvNV)(GLuint id , GLsizei len , const GLubyte *name , const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramNamedParameterfvNV)(GLuint id , GLsizei len , const GLubyte *name , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramNamedParameterdvNV)(GLuint id , GLsizei len , const GLubyte *name , GLdouble *params) = 0; }
static bool DinamicGLFeature_NV_fragment_program_loaded = false; 
static void InitDinamicGLFeature_NV_fragment_program() {
		DynamicGL_ProgramNamedParameter4fNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , GLsizei len , const GLubyte *name , GLfloat x , GLfloat y , GLfloat z , GLfloat w)>("glProgramNamedParameter4fNV"); 
		DynamicGL_ProgramNamedParameter4dNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , GLsizei len , const GLubyte *name , GLdouble x , GLdouble y , GLdouble z , GLdouble w)>("glProgramNamedParameter4dNV"); 
		DynamicGL_ProgramNamedParameter4fvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , GLsizei len , const GLubyte *name , const GLfloat *v)>("glProgramNamedParameter4fvNV"); 
		DynamicGL_ProgramNamedParameter4dvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , GLsizei len , const GLubyte *name , const GLdouble *v)>("glProgramNamedParameter4dvNV"); 
		DynamicGL_GetProgramNamedParameterfvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , GLsizei len , const GLubyte *name , GLfloat *params)>("glGetProgramNamedParameterfvNV"); 
		DynamicGL_GetProgramNamedParameterdvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , GLsizei len , const GLubyte *name , GLdouble *params)>("glGetProgramNamedParameterdvNV"); 
		DinamicGLFeature_NV_fragment_program_loaded = true; 
}
bool DinamicGLFeature_NV_fragment_program_Supported() {
		if (!DinamicGLFeature_NV_fragment_program_loaded) {
			InitDinamicGLFeature_NV_fragment_program();
		}
		if (DynamicGL_ProgramNamedParameter4fNV==0) return false; 
		if (DynamicGL_ProgramNamedParameter4dNV==0) return false; 
		if (DynamicGL_ProgramNamedParameter4fvNV==0) return false; 
		if (DynamicGL_ProgramNamedParameter4dvNV==0) return false; 
		if (DynamicGL_GetProgramNamedParameterfvNV==0) return false; 
		if (DynamicGL_GetProgramNamedParameterdvNV==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_fragment_program*/

/*NV_texture_env_combine4*/
#ifdef USE_DYNAMIC_GL_NV_texture_env_combine4
static bool DinamicGLFeature_NV_texture_env_combine4_loaded = false; 
static void InitDinamicGLFeature_NV_texture_env_combine4() {
		DinamicGLFeature_NV_texture_env_combine4_loaded = true; 
}
bool DinamicGLFeature_NV_texture_env_combine4_Supported() {
		if (!DinamicGLFeature_NV_texture_env_combine4_loaded) {
			InitDinamicGLFeature_NV_texture_env_combine4();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_texture_env_combine4*/

/*ARB_texture_buffer_object*/
#ifdef USE_DYNAMIC_GL_ARB_texture_buffer_object
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexBufferARB)(GLenum target , GLenum internalformat , GLuint buffer) = 0; }
static bool DinamicGLFeature_ARB_texture_buffer_object_loaded = false; 
static void InitDinamicGLFeature_ARB_texture_buffer_object() {
		DynamicGL_TexBufferARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum internalformat , GLuint buffer)>("glTexBufferARB"); 
		DinamicGLFeature_ARB_texture_buffer_object_loaded = true; 
}
bool DinamicGLFeature_ARB_texture_buffer_object_Supported() {
		if (!DinamicGLFeature_ARB_texture_buffer_object_loaded) {
			InitDinamicGLFeature_ARB_texture_buffer_object();
		}
		if (DynamicGL_TexBufferARB==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_texture_buffer_object*/

/*SGIX_flush_raster*/
#ifdef USE_DYNAMIC_GL_SGIX_flush_raster
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FlushRasterSGIX)() = 0; }
static bool DinamicGLFeature_SGIX_flush_raster_loaded = false; 
static void InitDinamicGLFeature_SGIX_flush_raster() {
		DynamicGL_FlushRasterSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glFlushRasterSGIX"); 
		DinamicGLFeature_SGIX_flush_raster_loaded = true; 
}
bool DinamicGLFeature_SGIX_flush_raster_Supported() {
		if (!DinamicGLFeature_SGIX_flush_raster_loaded) {
			InitDinamicGLFeature_SGIX_flush_raster();
		}
		if (DynamicGL_FlushRasterSGIX==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_flush_raster*/

/*SGIS_fog_function*/
#ifdef USE_DYNAMIC_GL_SGIS_fog_function
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FogFuncSGIS)(GLsizei n , const GLfloat *points) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFogFuncSGIS)(GLfloat *points) = 0; }
static bool DinamicGLFeature_SGIS_fog_function_loaded = false; 
static void InitDinamicGLFeature_SGIS_fog_function() {
		DynamicGL_FogFuncSGIS = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , const GLfloat *points)>("glFogFuncSGIS"); 
		DynamicGL_GetFogFuncSGIS = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat *points)>("glGetFogFuncSGIS"); 
		DinamicGLFeature_SGIS_fog_function_loaded = true; 
}
bool DinamicGLFeature_SGIS_fog_function_Supported() {
		if (!DinamicGLFeature_SGIS_fog_function_loaded) {
			InitDinamicGLFeature_SGIS_fog_function();
		}
		if (DynamicGL_FogFuncSGIS==0) return false; 
		if (DynamicGL_GetFogFuncSGIS==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIS_fog_function*/

/*VERSION_2_0*/
#ifdef USE_DYNAMIC_GL_VERSION_2_0
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendEquationSeparate)(GLenum modeRGB , GLenum modeAlpha) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawBuffers)(GLsizei n , const GLenum *bufs) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_StencilOpSeparate)(GLenum face , GLenum sfail , GLenum dpfail , GLenum dppass) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_StencilFuncSeparate)(GLenum frontfunc , GLenum backfunc , GLint ref , GLuint mask) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_StencilMaskSeparate)(GLenum face , GLuint mask) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_AttachShader)(GLuint program , GLuint shader) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BindAttribLocation)(GLuint program , GLuint index , const GLchar *name) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CompileShader)(GLuint shader) = 0; }
extern "C" { GLuint (DYNAMIC_GL_APIENTRYP DynamicGL_CreateProgram)() = 0; }
extern "C" { GLuint (DYNAMIC_GL_APIENTRYP DynamicGL_CreateShader)(GLenum type) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteProgram)(GLuint program) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteShader)(GLuint shader) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DetachShader)(GLuint program , GLuint shader) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DisableVertexAttribArray)(GLuint index) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EnableVertexAttribArray)(GLuint index) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetActiveAttrib)(GLuint program , GLuint index , GLsizei bufSize , GLsizei *length , GLint *size , GLenum *type , GLchar *name) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetActiveUniform)(GLuint program , GLuint index , GLsizei bufSize , GLsizei *length , GLint *size , GLenum *type , GLchar *name) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetAttachedShaders)(GLuint program , GLsizei maxCount , GLsizei *count , GLuint *obj) = 0; }
extern "C" { GLint (DYNAMIC_GL_APIENTRYP DynamicGL_GetAttribLocation)(GLuint program , const GLchar *name) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramiv)(GLuint program , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramInfoLog)(GLuint program , GLsizei bufSize , GLsizei *length , GLchar *infoLog) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetShaderiv)(GLuint shader , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetShaderInfoLog)(GLuint shader , GLsizei bufSize , GLsizei *length , GLchar *infoLog) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetShaderSource)(GLuint shader , GLsizei bufSize , GLsizei *length , GLchar *source) = 0; }
extern "C" { GLint (DYNAMIC_GL_APIENTRYP DynamicGL_GetUniformLocation)(GLuint program , const GLchar *name) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetUniformfv)(GLuint program , GLint location , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetUniformiv)(GLuint program , GLint location , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribdv)(GLuint index , GLenum pname , GLdouble *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribfv)(GLuint index , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribiv)(GLuint index , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribPointerv)(GLuint index , GLenum pname , GLvoid* *pointer) = 0; }
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsProgram)(GLuint program) = 0; }
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsShader)(GLuint shader) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_LinkProgram)(GLuint program) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ShaderSource)(GLuint shader , GLsizei count , const GLchar* *string , const GLint *length) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_UseProgram)(GLuint program) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform1f)(GLint location , GLfloat v0) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform2f)(GLint location , GLfloat v0 , GLfloat v1) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform3f)(GLint location , GLfloat v0 , GLfloat v1 , GLfloat v2) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform4f)(GLint location , GLfloat v0 , GLfloat v1 , GLfloat v2 , GLfloat v3) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform1i)(GLint location , GLint v0) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform2i)(GLint location , GLint v0 , GLint v1) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform3i)(GLint location , GLint v0 , GLint v1 , GLint v2) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform4i)(GLint location , GLint v0 , GLint v1 , GLint v2 , GLint v3) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform1fv)(GLint location , GLsizei count , const GLfloat *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform2fv)(GLint location , GLsizei count , const GLfloat *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform3fv)(GLint location , GLsizei count , const GLfloat *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform4fv)(GLint location , GLsizei count , const GLfloat *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform1iv)(GLint location , GLsizei count , const GLint *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform2iv)(GLint location , GLsizei count , const GLint *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform3iv)(GLint location , GLsizei count , const GLint *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform4iv)(GLint location , GLsizei count , const GLint *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformMatrix2fv)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformMatrix3fv)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformMatrix4fv)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ValidateProgram)(GLuint program) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1d)(GLuint index , GLdouble x) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1dv)(GLuint index , const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1f)(GLuint index , GLfloat x) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1fv)(GLuint index , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1s)(GLuint index , GLshort x) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1sv)(GLuint index , const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2d)(GLuint index , GLdouble x , GLdouble y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2dv)(GLuint index , const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2f)(GLuint index , GLfloat x , GLfloat y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2fv)(GLuint index , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2s)(GLuint index , GLshort x , GLshort y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2sv)(GLuint index , const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3d)(GLuint index , GLdouble x , GLdouble y , GLdouble z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3dv)(GLuint index , const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3f)(GLuint index , GLfloat x , GLfloat y , GLfloat z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3fv)(GLuint index , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3s)(GLuint index , GLshort x , GLshort y , GLshort z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3sv)(GLuint index , const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4Nbv)(GLuint index , const GLbyte *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4Niv)(GLuint index , const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4Nsv)(GLuint index , const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4Nub)(GLuint index , GLubyte x , GLubyte y , GLubyte z , GLubyte w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4Nubv)(GLuint index , const GLubyte *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4Nuiv)(GLuint index , const GLuint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4Nusv)(GLuint index , const GLushort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4bv)(GLuint index , const GLbyte *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4d)(GLuint index , GLdouble x , GLdouble y , GLdouble z , GLdouble w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4dv)(GLuint index , const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4f)(GLuint index , GLfloat x , GLfloat y , GLfloat z , GLfloat w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4fv)(GLuint index , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4iv)(GLuint index , const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4s)(GLuint index , GLshort x , GLshort y , GLshort z , GLshort w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4sv)(GLuint index , const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4ubv)(GLuint index , const GLubyte *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4uiv)(GLuint index , const GLuint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4usv)(GLuint index , const GLushort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribPointer)(GLuint index , GLint size , GLenum type , GLboolean normalized , GLsizei stride , const GLvoid *pointer) = 0; }
static bool DinamicGLFeature_VERSION_2_0_loaded = false; 
static void InitDinamicGLFeature_VERSION_2_0() {
		DynamicGL_BlendEquationSeparate = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum modeRGB , GLenum modeAlpha)>("glBlendEquationSeparate"); 
		DynamicGL_DrawBuffers = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , const GLenum *bufs)>("glDrawBuffers"); 
		DynamicGL_StencilOpSeparate = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum face , GLenum sfail , GLenum dpfail , GLenum dppass)>("glStencilOpSeparate"); 
		DynamicGL_StencilFuncSeparate = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum frontfunc , GLenum backfunc , GLint ref , GLuint mask)>("glStencilFuncSeparate"); 
		DynamicGL_StencilMaskSeparate = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum face , GLuint mask)>("glStencilMaskSeparate"); 
		DynamicGL_AttachShader = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLuint shader)>("glAttachShader"); 
		DynamicGL_BindAttribLocation = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLuint index , const GLchar *name)>("glBindAttribLocation"); 
		DynamicGL_CompileShader = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint shader)>("glCompileShader"); 
		DynamicGL_CreateProgram = DynamicGL_LoadFunction<GLuint (DYNAMIC_GL_APIENTRYP)()>("glCreateProgram"); 
		DynamicGL_CreateShader = DynamicGL_LoadFunction<GLuint (DYNAMIC_GL_APIENTRYP)(GLenum type)>("glCreateShader"); 
		DynamicGL_DeleteProgram = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program)>("glDeleteProgram"); 
		DynamicGL_DeleteShader = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint shader)>("glDeleteShader"); 
		DynamicGL_DetachShader = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLuint shader)>("glDetachShader"); 
		DynamicGL_DisableVertexAttribArray = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index)>("glDisableVertexAttribArray"); 
		DynamicGL_EnableVertexAttribArray = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index)>("glEnableVertexAttribArray"); 
		DynamicGL_GetActiveAttrib = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLuint index , GLsizei bufSize , GLsizei *length , GLint *size , GLenum *type , GLchar *name)>("glGetActiveAttrib"); 
		DynamicGL_GetActiveUniform = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLuint index , GLsizei bufSize , GLsizei *length , GLint *size , GLenum *type , GLchar *name)>("glGetActiveUniform"); 
		DynamicGL_GetAttachedShaders = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLsizei maxCount , GLsizei *count , GLuint *obj)>("glGetAttachedShaders"); 
		DynamicGL_GetAttribLocation = DynamicGL_LoadFunction<GLint (DYNAMIC_GL_APIENTRYP)(GLuint program , const GLchar *name)>("glGetAttribLocation"); 
		DynamicGL_GetProgramiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLenum pname , GLint *params)>("glGetProgramiv"); 
		DynamicGL_GetProgramInfoLog = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLsizei bufSize , GLsizei *length , GLchar *infoLog)>("glGetProgramInfoLog"); 
		DynamicGL_GetShaderiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint shader , GLenum pname , GLint *params)>("glGetShaderiv"); 
		DynamicGL_GetShaderInfoLog = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint shader , GLsizei bufSize , GLsizei *length , GLchar *infoLog)>("glGetShaderInfoLog"); 
		DynamicGL_GetShaderSource = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint shader , GLsizei bufSize , GLsizei *length , GLchar *source)>("glGetShaderSource"); 
		DynamicGL_GetUniformLocation = DynamicGL_LoadFunction<GLint (DYNAMIC_GL_APIENTRYP)(GLuint program , const GLchar *name)>("glGetUniformLocation"); 
		DynamicGL_GetUniformfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLfloat *params)>("glGetUniformfv"); 
		DynamicGL_GetUniformiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLint *params)>("glGetUniformiv"); 
		DynamicGL_GetVertexAttribdv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLenum pname , GLdouble *params)>("glGetVertexAttribdv"); 
		DynamicGL_GetVertexAttribfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLenum pname , GLfloat *params)>("glGetVertexAttribfv"); 
		DynamicGL_GetVertexAttribiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLenum pname , GLint *params)>("glGetVertexAttribiv"); 
		DynamicGL_GetVertexAttribPointerv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLenum pname , GLvoid* *pointer)>("glGetVertexAttribPointerv"); 
		DynamicGL_IsProgram = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLuint program)>("glIsProgram"); 
		DynamicGL_IsShader = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLuint shader)>("glIsShader"); 
		DynamicGL_LinkProgram = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program)>("glLinkProgram"); 
		DynamicGL_ShaderSource = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint shader , GLsizei count , const GLchar* *string , const GLint *length)>("glShaderSource"); 
		DynamicGL_UseProgram = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program)>("glUseProgram"); 
		DynamicGL_Uniform1f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLfloat v0)>("glUniform1f"); 
		DynamicGL_Uniform2f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLfloat v0 , GLfloat v1)>("glUniform2f"); 
		DynamicGL_Uniform3f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLfloat v0 , GLfloat v1 , GLfloat v2)>("glUniform3f"); 
		DynamicGL_Uniform4f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLfloat v0 , GLfloat v1 , GLfloat v2 , GLfloat v3)>("glUniform4f"); 
		DynamicGL_Uniform1i = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLint v0)>("glUniform1i"); 
		DynamicGL_Uniform2i = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLint v0 , GLint v1)>("glUniform2i"); 
		DynamicGL_Uniform3i = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLint v0 , GLint v1 , GLint v2)>("glUniform3i"); 
		DynamicGL_Uniform4i = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLint v0 , GLint v1 , GLint v2 , GLint v3)>("glUniform4i"); 
		DynamicGL_Uniform1fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , const GLfloat *value)>("glUniform1fv"); 
		DynamicGL_Uniform2fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , const GLfloat *value)>("glUniform2fv"); 
		DynamicGL_Uniform3fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , const GLfloat *value)>("glUniform3fv"); 
		DynamicGL_Uniform4fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , const GLfloat *value)>("glUniform4fv"); 
		DynamicGL_Uniform1iv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , const GLint *value)>("glUniform1iv"); 
		DynamicGL_Uniform2iv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , const GLint *value)>("glUniform2iv"); 
		DynamicGL_Uniform3iv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , const GLint *value)>("glUniform3iv"); 
		DynamicGL_Uniform4iv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , const GLint *value)>("glUniform4iv"); 
		DynamicGL_UniformMatrix2fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value)>("glUniformMatrix2fv"); 
		DynamicGL_UniformMatrix3fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value)>("glUniformMatrix3fv"); 
		DynamicGL_UniformMatrix4fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value)>("glUniformMatrix4fv"); 
		DynamicGL_ValidateProgram = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program)>("glValidateProgram"); 
		DynamicGL_VertexAttrib1d = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLdouble x)>("glVertexAttrib1d"); 
		DynamicGL_VertexAttrib1dv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLdouble *v)>("glVertexAttrib1dv"); 
		DynamicGL_VertexAttrib1f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLfloat x)>("glVertexAttrib1f"); 
		DynamicGL_VertexAttrib1fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLfloat *v)>("glVertexAttrib1fv"); 
		DynamicGL_VertexAttrib1s = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLshort x)>("glVertexAttrib1s"); 
		DynamicGL_VertexAttrib1sv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLshort *v)>("glVertexAttrib1sv"); 
		DynamicGL_VertexAttrib2d = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLdouble x , GLdouble y)>("glVertexAttrib2d"); 
		DynamicGL_VertexAttrib2dv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLdouble *v)>("glVertexAttrib2dv"); 
		DynamicGL_VertexAttrib2f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLfloat x , GLfloat y)>("glVertexAttrib2f"); 
		DynamicGL_VertexAttrib2fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLfloat *v)>("glVertexAttrib2fv"); 
		DynamicGL_VertexAttrib2s = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLshort x , GLshort y)>("glVertexAttrib2s"); 
		DynamicGL_VertexAttrib2sv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLshort *v)>("glVertexAttrib2sv"); 
		DynamicGL_VertexAttrib3d = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLdouble x , GLdouble y , GLdouble z)>("glVertexAttrib3d"); 
		DynamicGL_VertexAttrib3dv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLdouble *v)>("glVertexAttrib3dv"); 
		DynamicGL_VertexAttrib3f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLfloat x , GLfloat y , GLfloat z)>("glVertexAttrib3f"); 
		DynamicGL_VertexAttrib3fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLfloat *v)>("glVertexAttrib3fv"); 
		DynamicGL_VertexAttrib3s = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLshort x , GLshort y , GLshort z)>("glVertexAttrib3s"); 
		DynamicGL_VertexAttrib3sv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLshort *v)>("glVertexAttrib3sv"); 
		DynamicGL_VertexAttrib4Nbv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLbyte *v)>("glVertexAttrib4Nbv"); 
		DynamicGL_VertexAttrib4Niv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLint *v)>("glVertexAttrib4Niv"); 
		DynamicGL_VertexAttrib4Nsv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLshort *v)>("glVertexAttrib4Nsv"); 
		DynamicGL_VertexAttrib4Nub = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLubyte x , GLubyte y , GLubyte z , GLubyte w)>("glVertexAttrib4Nub"); 
		DynamicGL_VertexAttrib4Nubv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLubyte *v)>("glVertexAttrib4Nubv"); 
		DynamicGL_VertexAttrib4Nuiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLuint *v)>("glVertexAttrib4Nuiv"); 
		DynamicGL_VertexAttrib4Nusv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLushort *v)>("glVertexAttrib4Nusv"); 
		DynamicGL_VertexAttrib4bv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLbyte *v)>("glVertexAttrib4bv"); 
		DynamicGL_VertexAttrib4d = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLdouble x , GLdouble y , GLdouble z , GLdouble w)>("glVertexAttrib4d"); 
		DynamicGL_VertexAttrib4dv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLdouble *v)>("glVertexAttrib4dv"); 
		DynamicGL_VertexAttrib4f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLfloat x , GLfloat y , GLfloat z , GLfloat w)>("glVertexAttrib4f"); 
		DynamicGL_VertexAttrib4fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLfloat *v)>("glVertexAttrib4fv"); 
		DynamicGL_VertexAttrib4iv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLint *v)>("glVertexAttrib4iv"); 
		DynamicGL_VertexAttrib4s = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLshort x , GLshort y , GLshort z , GLshort w)>("glVertexAttrib4s"); 
		DynamicGL_VertexAttrib4sv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLshort *v)>("glVertexAttrib4sv"); 
		DynamicGL_VertexAttrib4ubv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLubyte *v)>("glVertexAttrib4ubv"); 
		DynamicGL_VertexAttrib4uiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLuint *v)>("glVertexAttrib4uiv"); 
		DynamicGL_VertexAttrib4usv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLushort *v)>("glVertexAttrib4usv"); 
		DynamicGL_VertexAttribPointer = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLint size , GLenum type , GLboolean normalized , GLsizei stride , const GLvoid *pointer)>("glVertexAttribPointer"); 
		DinamicGLFeature_VERSION_2_0_loaded = true; 
}
bool DinamicGLFeature_VERSION_2_0_Supported() {
		if (!DinamicGLFeature_VERSION_2_0_loaded) {
			InitDinamicGLFeature_VERSION_2_0();
		}
		if (DynamicGL_BlendEquationSeparate==0) return false; 
		if (DynamicGL_DrawBuffers==0) return false; 
		if (DynamicGL_StencilOpSeparate==0) return false; 
		if (DynamicGL_StencilFuncSeparate==0) return false; 
		if (DynamicGL_StencilMaskSeparate==0) return false; 
		if (DynamicGL_AttachShader==0) return false; 
		if (DynamicGL_BindAttribLocation==0) return false; 
		if (DynamicGL_CompileShader==0) return false; 
		if (DynamicGL_CreateProgram==0) return false; 
		if (DynamicGL_CreateShader==0) return false; 
		if (DynamicGL_DeleteProgram==0) return false; 
		if (DynamicGL_DeleteShader==0) return false; 
		if (DynamicGL_DetachShader==0) return false; 
		if (DynamicGL_DisableVertexAttribArray==0) return false; 
		if (DynamicGL_EnableVertexAttribArray==0) return false; 
		if (DynamicGL_GetActiveAttrib==0) return false; 
		if (DynamicGL_GetActiveUniform==0) return false; 
		if (DynamicGL_GetAttachedShaders==0) return false; 
		if (DynamicGL_GetAttribLocation==0) return false; 
		if (DynamicGL_GetProgramiv==0) return false; 
		if (DynamicGL_GetProgramInfoLog==0) return false; 
		if (DynamicGL_GetShaderiv==0) return false; 
		if (DynamicGL_GetShaderInfoLog==0) return false; 
		if (DynamicGL_GetShaderSource==0) return false; 
		if (DynamicGL_GetUniformLocation==0) return false; 
		if (DynamicGL_GetUniformfv==0) return false; 
		if (DynamicGL_GetUniformiv==0) return false; 
		if (DynamicGL_GetVertexAttribdv==0) return false; 
		if (DynamicGL_GetVertexAttribfv==0) return false; 
		if (DynamicGL_GetVertexAttribiv==0) return false; 
		if (DynamicGL_GetVertexAttribPointerv==0) return false; 
		if (DynamicGL_IsProgram==0) return false; 
		if (DynamicGL_IsShader==0) return false; 
		if (DynamicGL_LinkProgram==0) return false; 
		if (DynamicGL_ShaderSource==0) return false; 
		if (DynamicGL_UseProgram==0) return false; 
		if (DynamicGL_Uniform1f==0) return false; 
		if (DynamicGL_Uniform2f==0) return false; 
		if (DynamicGL_Uniform3f==0) return false; 
		if (DynamicGL_Uniform4f==0) return false; 
		if (DynamicGL_Uniform1i==0) return false; 
		if (DynamicGL_Uniform2i==0) return false; 
		if (DynamicGL_Uniform3i==0) return false; 
		if (DynamicGL_Uniform4i==0) return false; 
		if (DynamicGL_Uniform1fv==0) return false; 
		if (DynamicGL_Uniform2fv==0) return false; 
		if (DynamicGL_Uniform3fv==0) return false; 
		if (DynamicGL_Uniform4fv==0) return false; 
		if (DynamicGL_Uniform1iv==0) return false; 
		if (DynamicGL_Uniform2iv==0) return false; 
		if (DynamicGL_Uniform3iv==0) return false; 
		if (DynamicGL_Uniform4iv==0) return false; 
		if (DynamicGL_UniformMatrix2fv==0) return false; 
		if (DynamicGL_UniformMatrix3fv==0) return false; 
		if (DynamicGL_UniformMatrix4fv==0) return false; 
		if (DynamicGL_ValidateProgram==0) return false; 
		if (DynamicGL_VertexAttrib1d==0) return false; 
		if (DynamicGL_VertexAttrib1dv==0) return false; 
		if (DynamicGL_VertexAttrib1f==0) return false; 
		if (DynamicGL_VertexAttrib1fv==0) return false; 
		if (DynamicGL_VertexAttrib1s==0) return false; 
		if (DynamicGL_VertexAttrib1sv==0) return false; 
		if (DynamicGL_VertexAttrib2d==0) return false; 
		if (DynamicGL_VertexAttrib2dv==0) return false; 
		if (DynamicGL_VertexAttrib2f==0) return false; 
		if (DynamicGL_VertexAttrib2fv==0) return false; 
		if (DynamicGL_VertexAttrib2s==0) return false; 
		if (DynamicGL_VertexAttrib2sv==0) return false; 
		if (DynamicGL_VertexAttrib3d==0) return false; 
		if (DynamicGL_VertexAttrib3dv==0) return false; 
		if (DynamicGL_VertexAttrib3f==0) return false; 
		if (DynamicGL_VertexAttrib3fv==0) return false; 
		if (DynamicGL_VertexAttrib3s==0) return false; 
		if (DynamicGL_VertexAttrib3sv==0) return false; 
		if (DynamicGL_VertexAttrib4Nbv==0) return false; 
		if (DynamicGL_VertexAttrib4Niv==0) return false; 
		if (DynamicGL_VertexAttrib4Nsv==0) return false; 
		if (DynamicGL_VertexAttrib4Nub==0) return false; 
		if (DynamicGL_VertexAttrib4Nubv==0) return false; 
		if (DynamicGL_VertexAttrib4Nuiv==0) return false; 
		if (DynamicGL_VertexAttrib4Nusv==0) return false; 
		if (DynamicGL_VertexAttrib4bv==0) return false; 
		if (DynamicGL_VertexAttrib4d==0) return false; 
		if (DynamicGL_VertexAttrib4dv==0) return false; 
		if (DynamicGL_VertexAttrib4f==0) return false; 
		if (DynamicGL_VertexAttrib4fv==0) return false; 
		if (DynamicGL_VertexAttrib4iv==0) return false; 
		if (DynamicGL_VertexAttrib4s==0) return false; 
		if (DynamicGL_VertexAttrib4sv==0) return false; 
		if (DynamicGL_VertexAttrib4ubv==0) return false; 
		if (DynamicGL_VertexAttrib4uiv==0) return false; 
		if (DynamicGL_VertexAttrib4usv==0) return false; 
		if (DynamicGL_VertexAttribPointer==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_VERSION_2_0*/

/*EXT_compiled_vertex_array*/
#ifdef USE_DYNAMIC_GL_EXT_compiled_vertex_array
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_LockArraysEXT)(GLint first , GLsizei count) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_UnlockArraysEXT)() = 0; }
static bool DinamicGLFeature_EXT_compiled_vertex_array_loaded = false; 
static void InitDinamicGLFeature_EXT_compiled_vertex_array() {
		DynamicGL_LockArraysEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint first , GLsizei count)>("glLockArraysEXT"); 
		DynamicGL_UnlockArraysEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glUnlockArraysEXT"); 
		DinamicGLFeature_EXT_compiled_vertex_array_loaded = true; 
}
bool DinamicGLFeature_EXT_compiled_vertex_array_Supported() {
		if (!DinamicGLFeature_EXT_compiled_vertex_array_loaded) {
			InitDinamicGLFeature_EXT_compiled_vertex_array();
		}
		if (DynamicGL_LockArraysEXT==0) return false; 
		if (DynamicGL_UnlockArraysEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_compiled_vertex_array*/

/*IBM_texture_mirrored_repeat*/
#ifdef USE_DYNAMIC_GL_IBM_texture_mirrored_repeat
static bool DinamicGLFeature_IBM_texture_mirrored_repeat_loaded = false; 
static void InitDinamicGLFeature_IBM_texture_mirrored_repeat() {
		DinamicGLFeature_IBM_texture_mirrored_repeat_loaded = true; 
}
bool DinamicGLFeature_IBM_texture_mirrored_repeat_Supported() {
		if (!DinamicGLFeature_IBM_texture_mirrored_repeat_loaded) {
			InitDinamicGLFeature_IBM_texture_mirrored_repeat();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_IBM_texture_mirrored_repeat*/

/*OML_subsample*/
#ifdef USE_DYNAMIC_GL_OML_subsample
static bool DinamicGLFeature_OML_subsample_loaded = false; 
static void InitDinamicGLFeature_OML_subsample() {
		DinamicGLFeature_OML_subsample_loaded = true; 
}
bool DinamicGLFeature_OML_subsample_Supported() {
		if (!DinamicGLFeature_OML_subsample_loaded) {
			InitDinamicGLFeature_OML_subsample();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_OML_subsample*/

/*NV_texgen_reflection*/
#ifdef USE_DYNAMIC_GL_NV_texgen_reflection
static bool DinamicGLFeature_NV_texgen_reflection_loaded = false; 
static void InitDinamicGLFeature_NV_texgen_reflection() {
		DinamicGLFeature_NV_texgen_reflection_loaded = true; 
}
bool DinamicGLFeature_NV_texgen_reflection_Supported() {
		if (!DinamicGLFeature_NV_texgen_reflection_loaded) {
			InitDinamicGLFeature_NV_texgen_reflection();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_texgen_reflection*/

/*SGIX_list_priority*/
#ifdef USE_DYNAMIC_GL_SGIX_list_priority
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetListParameterfvSGIX)(GLuint list , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetListParameterivSGIX)(GLuint list , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ListParameterfSGIX)(GLuint list , GLenum pname , GLfloat param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ListParameterfvSGIX)(GLuint list , GLenum pname , const GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ListParameteriSGIX)(GLuint list , GLenum pname , GLint param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ListParameterivSGIX)(GLuint list , GLenum pname , const GLint *params) = 0; }
static bool DinamicGLFeature_SGIX_list_priority_loaded = false; 
static void InitDinamicGLFeature_SGIX_list_priority() {
		DynamicGL_GetListParameterfvSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint list , GLenum pname , GLfloat *params)>("glGetListParameterfvSGIX"); 
		DynamicGL_GetListParameterivSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint list , GLenum pname , GLint *params)>("glGetListParameterivSGIX"); 
		DynamicGL_ListParameterfSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint list , GLenum pname , GLfloat param)>("glListParameterfSGIX"); 
		DynamicGL_ListParameterfvSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint list , GLenum pname , const GLfloat *params)>("glListParameterfvSGIX"); 
		DynamicGL_ListParameteriSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint list , GLenum pname , GLint param)>("glListParameteriSGIX"); 
		DynamicGL_ListParameterivSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint list , GLenum pname , const GLint *params)>("glListParameterivSGIX"); 
		DinamicGLFeature_SGIX_list_priority_loaded = true; 
}
bool DinamicGLFeature_SGIX_list_priority_Supported() {
		if (!DinamicGLFeature_SGIX_list_priority_loaded) {
			InitDinamicGLFeature_SGIX_list_priority();
		}
		if (DynamicGL_GetListParameterfvSGIX==0) return false; 
		if (DynamicGL_GetListParameterivSGIX==0) return false; 
		if (DynamicGL_ListParameterfSGIX==0) return false; 
		if (DynamicGL_ListParameterfvSGIX==0) return false; 
		if (DynamicGL_ListParameteriSGIX==0) return false; 
		if (DynamicGL_ListParameterivSGIX==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_list_priority*/

/*NV_occlusion_query*/
#ifdef USE_DYNAMIC_GL_NV_occlusion_query
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GenOcclusionQueriesNV)(GLsizei n , GLuint *ids) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteOcclusionQueriesNV)(GLsizei n , const GLuint *ids) = 0; }
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsOcclusionQueryNV)(GLuint id) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BeginOcclusionQueryNV)(GLuint id) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EndOcclusionQueryNV)() = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetOcclusionQueryivNV)(GLuint id , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetOcclusionQueryuivNV)(GLuint id , GLenum pname , GLuint *params) = 0; }
static bool DinamicGLFeature_NV_occlusion_query_loaded = false; 
static void InitDinamicGLFeature_NV_occlusion_query() {
		DynamicGL_GenOcclusionQueriesNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , GLuint *ids)>("glGenOcclusionQueriesNV"); 
		DynamicGL_DeleteOcclusionQueriesNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , const GLuint *ids)>("glDeleteOcclusionQueriesNV"); 
		DynamicGL_IsOcclusionQueryNV = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLuint id)>("glIsOcclusionQueryNV"); 
		DynamicGL_BeginOcclusionQueryNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id)>("glBeginOcclusionQueryNV"); 
		DynamicGL_EndOcclusionQueryNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glEndOcclusionQueryNV"); 
		DynamicGL_GetOcclusionQueryivNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , GLenum pname , GLint *params)>("glGetOcclusionQueryivNV"); 
		DynamicGL_GetOcclusionQueryuivNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , GLenum pname , GLuint *params)>("glGetOcclusionQueryuivNV"); 
		DinamicGLFeature_NV_occlusion_query_loaded = true; 
}
bool DinamicGLFeature_NV_occlusion_query_Supported() {
		if (!DinamicGLFeature_NV_occlusion_query_loaded) {
			InitDinamicGLFeature_NV_occlusion_query();
		}
		if (DynamicGL_GenOcclusionQueriesNV==0) return false; 
		if (DynamicGL_DeleteOcclusionQueriesNV==0) return false; 
		if (DynamicGL_IsOcclusionQueryNV==0) return false; 
		if (DynamicGL_BeginOcclusionQueryNV==0) return false; 
		if (DynamicGL_EndOcclusionQueryNV==0) return false; 
		if (DynamicGL_GetOcclusionQueryivNV==0) return false; 
		if (DynamicGL_GetOcclusionQueryuivNV==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_occlusion_query*/

/*VERSION_1_3*/
#ifdef USE_DYNAMIC_GL_VERSION_1_3
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ActiveTexture)(GLenum texture) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ClientActiveTexture)(GLenum texture) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1d)(GLenum target , GLdouble s) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1dv)(GLenum target , const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1f)(GLenum target , GLfloat s) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1fv)(GLenum target , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1i)(GLenum target , GLint s) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1iv)(GLenum target , const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1s)(GLenum target , GLshort s) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1sv)(GLenum target , const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2d)(GLenum target , GLdouble s , GLdouble t) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2dv)(GLenum target , const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2f)(GLenum target , GLfloat s , GLfloat t) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2fv)(GLenum target , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2i)(GLenum target , GLint s , GLint t) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2iv)(GLenum target , const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2s)(GLenum target , GLshort s , GLshort t) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2sv)(GLenum target , const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3d)(GLenum target , GLdouble s , GLdouble t , GLdouble r) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3dv)(GLenum target , const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3f)(GLenum target , GLfloat s , GLfloat t , GLfloat r) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3fv)(GLenum target , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3i)(GLenum target , GLint s , GLint t , GLint r) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3iv)(GLenum target , const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3s)(GLenum target , GLshort s , GLshort t , GLshort r) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3sv)(GLenum target , const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4d)(GLenum target , GLdouble s , GLdouble t , GLdouble r , GLdouble q) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4dv)(GLenum target , const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4f)(GLenum target , GLfloat s , GLfloat t , GLfloat r , GLfloat q) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4fv)(GLenum target , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4i)(GLenum target , GLint s , GLint t , GLint r , GLint q) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4iv)(GLenum target , const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4s)(GLenum target , GLshort s , GLshort t , GLshort r , GLshort q) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4sv)(GLenum target , const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_LoadTransposeMatrixf)(const GLfloat *m) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_LoadTransposeMatrixd)(const GLdouble *m) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultTransposeMatrixf)(const GLfloat *m) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultTransposeMatrixd)(const GLdouble *m) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SampleCoverage)(GLclampf value , GLboolean invert) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTexImage3D)(GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLsizei depth , GLint border , GLsizei imageSize , const GLvoid *data) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTexImage2D)(GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLint border , GLsizei imageSize , const GLvoid *data) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTexImage1D)(GLenum target , GLint level , GLenum internalformat , GLsizei width , GLint border , GLsizei imageSize , const GLvoid *data) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTexSubImage3D)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLsizei width , GLsizei height , GLsizei depth , GLenum format , GLsizei imageSize , const GLvoid *data) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTexSubImage2D)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLsizei width , GLsizei height , GLenum format , GLsizei imageSize , const GLvoid *data) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTexSubImage1D)(GLenum target , GLint level , GLint xoffset , GLsizei width , GLenum format , GLsizei imageSize , const GLvoid *data) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetCompressedTexImage)(GLenum target , GLint level , GLvoid *img) = 0; }
static bool DinamicGLFeature_VERSION_1_3_loaded = false; 
static void InitDinamicGLFeature_VERSION_1_3() {
		DynamicGL_ActiveTexture = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texture)>("glActiveTexture"); 
		DynamicGL_ClientActiveTexture = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texture)>("glClientActiveTexture"); 
		DynamicGL_MultiTexCoord1d = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLdouble s)>("glMultiTexCoord1d"); 
		DynamicGL_MultiTexCoord1dv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLdouble *v)>("glMultiTexCoord1dv"); 
		DynamicGL_MultiTexCoord1f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLfloat s)>("glMultiTexCoord1f"); 
		DynamicGL_MultiTexCoord1fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLfloat *v)>("glMultiTexCoord1fv"); 
		DynamicGL_MultiTexCoord1i = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint s)>("glMultiTexCoord1i"); 
		DynamicGL_MultiTexCoord1iv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLint *v)>("glMultiTexCoord1iv"); 
		DynamicGL_MultiTexCoord1s = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLshort s)>("glMultiTexCoord1s"); 
		DynamicGL_MultiTexCoord1sv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLshort *v)>("glMultiTexCoord1sv"); 
		DynamicGL_MultiTexCoord2d = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLdouble s , GLdouble t)>("glMultiTexCoord2d"); 
		DynamicGL_MultiTexCoord2dv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLdouble *v)>("glMultiTexCoord2dv"); 
		DynamicGL_MultiTexCoord2f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLfloat s , GLfloat t)>("glMultiTexCoord2f"); 
		DynamicGL_MultiTexCoord2fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLfloat *v)>("glMultiTexCoord2fv"); 
		DynamicGL_MultiTexCoord2i = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint s , GLint t)>("glMultiTexCoord2i"); 
		DynamicGL_MultiTexCoord2iv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLint *v)>("glMultiTexCoord2iv"); 
		DynamicGL_MultiTexCoord2s = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLshort s , GLshort t)>("glMultiTexCoord2s"); 
		DynamicGL_MultiTexCoord2sv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLshort *v)>("glMultiTexCoord2sv"); 
		DynamicGL_MultiTexCoord3d = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLdouble s , GLdouble t , GLdouble r)>("glMultiTexCoord3d"); 
		DynamicGL_MultiTexCoord3dv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLdouble *v)>("glMultiTexCoord3dv"); 
		DynamicGL_MultiTexCoord3f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLfloat s , GLfloat t , GLfloat r)>("glMultiTexCoord3f"); 
		DynamicGL_MultiTexCoord3fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLfloat *v)>("glMultiTexCoord3fv"); 
		DynamicGL_MultiTexCoord3i = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint s , GLint t , GLint r)>("glMultiTexCoord3i"); 
		DynamicGL_MultiTexCoord3iv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLint *v)>("glMultiTexCoord3iv"); 
		DynamicGL_MultiTexCoord3s = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLshort s , GLshort t , GLshort r)>("glMultiTexCoord3s"); 
		DynamicGL_MultiTexCoord3sv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLshort *v)>("glMultiTexCoord3sv"); 
		DynamicGL_MultiTexCoord4d = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLdouble s , GLdouble t , GLdouble r , GLdouble q)>("glMultiTexCoord4d"); 
		DynamicGL_MultiTexCoord4dv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLdouble *v)>("glMultiTexCoord4dv"); 
		DynamicGL_MultiTexCoord4f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLfloat s , GLfloat t , GLfloat r , GLfloat q)>("glMultiTexCoord4f"); 
		DynamicGL_MultiTexCoord4fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLfloat *v)>("glMultiTexCoord4fv"); 
		DynamicGL_MultiTexCoord4i = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint s , GLint t , GLint r , GLint q)>("glMultiTexCoord4i"); 
		DynamicGL_MultiTexCoord4iv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLint *v)>("glMultiTexCoord4iv"); 
		DynamicGL_MultiTexCoord4s = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLshort s , GLshort t , GLshort r , GLshort q)>("glMultiTexCoord4s"); 
		DynamicGL_MultiTexCoord4sv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLshort *v)>("glMultiTexCoord4sv"); 
		DynamicGL_LoadTransposeMatrixf = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *m)>("glLoadTransposeMatrixf"); 
		DynamicGL_LoadTransposeMatrixd = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *m)>("glLoadTransposeMatrixd"); 
		DynamicGL_MultTransposeMatrixf = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *m)>("glMultTransposeMatrixf"); 
		DynamicGL_MultTransposeMatrixd = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *m)>("glMultTransposeMatrixd"); 
		DynamicGL_SampleCoverage = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLclampf value , GLboolean invert)>("glSampleCoverage"); 
		DynamicGL_CompressedTexImage3D = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLsizei depth , GLint border , GLsizei imageSize , const GLvoid *data)>("glCompressedTexImage3D"); 
		DynamicGL_CompressedTexImage2D = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLint border , GLsizei imageSize , const GLvoid *data)>("glCompressedTexImage2D"); 
		DynamicGL_CompressedTexImage1D = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLenum internalformat , GLsizei width , GLint border , GLsizei imageSize , const GLvoid *data)>("glCompressedTexImage1D"); 
		DynamicGL_CompressedTexSubImage3D = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLsizei width , GLsizei height , GLsizei depth , GLenum format , GLsizei imageSize , const GLvoid *data)>("glCompressedTexSubImage3D"); 
		DynamicGL_CompressedTexSubImage2D = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLsizei width , GLsizei height , GLenum format , GLsizei imageSize , const GLvoid *data)>("glCompressedTexSubImage2D"); 
		DynamicGL_CompressedTexSubImage1D = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLint xoffset , GLsizei width , GLenum format , GLsizei imageSize , const GLvoid *data)>("glCompressedTexSubImage1D"); 
		DynamicGL_GetCompressedTexImage = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLvoid *img)>("glGetCompressedTexImage"); 
		DinamicGLFeature_VERSION_1_3_loaded = true; 
}
bool DinamicGLFeature_VERSION_1_3_Supported() {
		if (!DinamicGLFeature_VERSION_1_3_loaded) {
			InitDinamicGLFeature_VERSION_1_3();
		}
		if (DynamicGL_ActiveTexture==0) return false; 
		if (DynamicGL_ClientActiveTexture==0) return false; 
		if (DynamicGL_MultiTexCoord1d==0) return false; 
		if (DynamicGL_MultiTexCoord1dv==0) return false; 
		if (DynamicGL_MultiTexCoord1f==0) return false; 
		if (DynamicGL_MultiTexCoord1fv==0) return false; 
		if (DynamicGL_MultiTexCoord1i==0) return false; 
		if (DynamicGL_MultiTexCoord1iv==0) return false; 
		if (DynamicGL_MultiTexCoord1s==0) return false; 
		if (DynamicGL_MultiTexCoord1sv==0) return false; 
		if (DynamicGL_MultiTexCoord2d==0) return false; 
		if (DynamicGL_MultiTexCoord2dv==0) return false; 
		if (DynamicGL_MultiTexCoord2f==0) return false; 
		if (DynamicGL_MultiTexCoord2fv==0) return false; 
		if (DynamicGL_MultiTexCoord2i==0) return false; 
		if (DynamicGL_MultiTexCoord2iv==0) return false; 
		if (DynamicGL_MultiTexCoord2s==0) return false; 
		if (DynamicGL_MultiTexCoord2sv==0) return false; 
		if (DynamicGL_MultiTexCoord3d==0) return false; 
		if (DynamicGL_MultiTexCoord3dv==0) return false; 
		if (DynamicGL_MultiTexCoord3f==0) return false; 
		if (DynamicGL_MultiTexCoord3fv==0) return false; 
		if (DynamicGL_MultiTexCoord3i==0) return false; 
		if (DynamicGL_MultiTexCoord3iv==0) return false; 
		if (DynamicGL_MultiTexCoord3s==0) return false; 
		if (DynamicGL_MultiTexCoord3sv==0) return false; 
		if (DynamicGL_MultiTexCoord4d==0) return false; 
		if (DynamicGL_MultiTexCoord4dv==0) return false; 
		if (DynamicGL_MultiTexCoord4f==0) return false; 
		if (DynamicGL_MultiTexCoord4fv==0) return false; 
		if (DynamicGL_MultiTexCoord4i==0) return false; 
		if (DynamicGL_MultiTexCoord4iv==0) return false; 
		if (DynamicGL_MultiTexCoord4s==0) return false; 
		if (DynamicGL_MultiTexCoord4sv==0) return false; 
		if (DynamicGL_LoadTransposeMatrixf==0) return false; 
		if (DynamicGL_LoadTransposeMatrixd==0) return false; 
		if (DynamicGL_MultTransposeMatrixf==0) return false; 
		if (DynamicGL_MultTransposeMatrixd==0) return false; 
		if (DynamicGL_SampleCoverage==0) return false; 
		if (DynamicGL_CompressedTexImage3D==0) return false; 
		if (DynamicGL_CompressedTexImage2D==0) return false; 
		if (DynamicGL_CompressedTexImage1D==0) return false; 
		if (DynamicGL_CompressedTexSubImage3D==0) return false; 
		if (DynamicGL_CompressedTexSubImage2D==0) return false; 
		if (DynamicGL_CompressedTexSubImage1D==0) return false; 
		if (DynamicGL_GetCompressedTexImage==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_VERSION_1_3*/

/*ARB_color_buffer_float*/
#ifdef USE_DYNAMIC_GL_ARB_color_buffer_float
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ClampColorARB)(GLenum target , GLenum clamp) = 0; }
static bool DinamicGLFeature_ARB_color_buffer_float_loaded = false; 
static void InitDinamicGLFeature_ARB_color_buffer_float() {
		DynamicGL_ClampColorARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum clamp)>("glClampColorARB"); 
		DinamicGLFeature_ARB_color_buffer_float_loaded = true; 
}
bool DinamicGLFeature_ARB_color_buffer_float_Supported() {
		if (!DinamicGLFeature_ARB_color_buffer_float_loaded) {
			InitDinamicGLFeature_ARB_color_buffer_float();
		}
		if (DynamicGL_ClampColorARB==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_color_buffer_float*/

/*EXT_texture_shared_exponent*/
#ifdef USE_DYNAMIC_GL_EXT_texture_shared_exponent
static bool DinamicGLFeature_EXT_texture_shared_exponent_loaded = false; 
static void InitDinamicGLFeature_EXT_texture_shared_exponent() {
		DinamicGLFeature_EXT_texture_shared_exponent_loaded = true; 
}
bool DinamicGLFeature_EXT_texture_shared_exponent_Supported() {
		if (!DinamicGLFeature_EXT_texture_shared_exponent_loaded) {
			InitDinamicGLFeature_EXT_texture_shared_exponent();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_texture_shared_exponent*/

/*NV_half_float*/
#ifdef USE_DYNAMIC_GL_NV_half_float
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex2hNV)(GLhalfNV x , GLhalfNV y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex2hvNV)(const GLhalfNV *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex3hNV)(GLhalfNV x , GLhalfNV y , GLhalfNV z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex3hvNV)(const GLhalfNV *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex4hNV)(GLhalfNV x , GLhalfNV y , GLhalfNV z , GLhalfNV w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex4hvNV)(const GLhalfNV *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Normal3hNV)(GLhalfNV nx , GLhalfNV ny , GLhalfNV nz) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Normal3hvNV)(const GLhalfNV *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3hNV)(GLhalfNV red , GLhalfNV green , GLhalfNV blue) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3hvNV)(const GLhalfNV *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4hNV)(GLhalfNV red , GLhalfNV green , GLhalfNV blue , GLhalfNV alpha) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4hvNV)(const GLhalfNV *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord1hNV)(GLhalfNV s) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord1hvNV)(const GLhalfNV *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2hNV)(GLhalfNV s , GLhalfNV t) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2hvNV)(const GLhalfNV *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord3hNV)(GLhalfNV s , GLhalfNV t , GLhalfNV r) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord3hvNV)(const GLhalfNV *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord4hNV)(GLhalfNV s , GLhalfNV t , GLhalfNV r , GLhalfNV q) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord4hvNV)(const GLhalfNV *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1hNV)(GLenum target , GLhalfNV s) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1hvNV)(GLenum target , const GLhalfNV *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2hNV)(GLenum target , GLhalfNV s , GLhalfNV t) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2hvNV)(GLenum target , const GLhalfNV *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3hNV)(GLenum target , GLhalfNV s , GLhalfNV t , GLhalfNV r) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3hvNV)(GLenum target , const GLhalfNV *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4hNV)(GLenum target , GLhalfNV s , GLhalfNV t , GLhalfNV r , GLhalfNV q) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4hvNV)(GLenum target , const GLhalfNV *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FogCoordhNV)(GLhalfNV fog) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FogCoordhvNV)(const GLhalfNV *fog) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3hNV)(GLhalfNV red , GLhalfNV green , GLhalfNV blue) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3hvNV)(const GLhalfNV *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexWeighthNV)(GLhalfNV weight) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexWeighthvNV)(const GLhalfNV *weight) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1hNV)(GLuint index , GLhalfNV x) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1hvNV)(GLuint index , const GLhalfNV *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2hNV)(GLuint index , GLhalfNV x , GLhalfNV y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2hvNV)(GLuint index , const GLhalfNV *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3hNV)(GLuint index , GLhalfNV x , GLhalfNV y , GLhalfNV z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3hvNV)(GLuint index , const GLhalfNV *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4hNV)(GLuint index , GLhalfNV x , GLhalfNV y , GLhalfNV z , GLhalfNV w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4hvNV)(GLuint index , const GLhalfNV *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribs1hvNV)(GLuint index , GLsizei n , const GLhalfNV *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribs2hvNV)(GLuint index , GLsizei n , const GLhalfNV *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribs3hvNV)(GLuint index , GLsizei n , const GLhalfNV *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribs4hvNV)(GLuint index , GLsizei n , const GLhalfNV *v) = 0; }
static bool DinamicGLFeature_NV_half_float_loaded = false; 
static void InitDinamicGLFeature_NV_half_float() {
		DynamicGL_Vertex2hNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLhalfNV x , GLhalfNV y)>("glVertex2hNV"); 
		DynamicGL_Vertex2hvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLhalfNV *v)>("glVertex2hvNV"); 
		DynamicGL_Vertex3hNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLhalfNV x , GLhalfNV y , GLhalfNV z)>("glVertex3hNV"); 
		DynamicGL_Vertex3hvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLhalfNV *v)>("glVertex3hvNV"); 
		DynamicGL_Vertex4hNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLhalfNV x , GLhalfNV y , GLhalfNV z , GLhalfNV w)>("glVertex4hNV"); 
		DynamicGL_Vertex4hvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLhalfNV *v)>("glVertex4hvNV"); 
		DynamicGL_Normal3hNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLhalfNV nx , GLhalfNV ny , GLhalfNV nz)>("glNormal3hNV"); 
		DynamicGL_Normal3hvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLhalfNV *v)>("glNormal3hvNV"); 
		DynamicGL_Color3hNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLhalfNV red , GLhalfNV green , GLhalfNV blue)>("glColor3hNV"); 
		DynamicGL_Color3hvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLhalfNV *v)>("glColor3hvNV"); 
		DynamicGL_Color4hNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLhalfNV red , GLhalfNV green , GLhalfNV blue , GLhalfNV alpha)>("glColor4hNV"); 
		DynamicGL_Color4hvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLhalfNV *v)>("glColor4hvNV"); 
		DynamicGL_TexCoord1hNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLhalfNV s)>("glTexCoord1hNV"); 
		DynamicGL_TexCoord1hvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLhalfNV *v)>("glTexCoord1hvNV"); 
		DynamicGL_TexCoord2hNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLhalfNV s , GLhalfNV t)>("glTexCoord2hNV"); 
		DynamicGL_TexCoord2hvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLhalfNV *v)>("glTexCoord2hvNV"); 
		DynamicGL_TexCoord3hNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLhalfNV s , GLhalfNV t , GLhalfNV r)>("glTexCoord3hNV"); 
		DynamicGL_TexCoord3hvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLhalfNV *v)>("glTexCoord3hvNV"); 
		DynamicGL_TexCoord4hNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLhalfNV s , GLhalfNV t , GLhalfNV r , GLhalfNV q)>("glTexCoord4hNV"); 
		DynamicGL_TexCoord4hvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLhalfNV *v)>("glTexCoord4hvNV"); 
		DynamicGL_MultiTexCoord1hNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLhalfNV s)>("glMultiTexCoord1hNV"); 
		DynamicGL_MultiTexCoord1hvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLhalfNV *v)>("glMultiTexCoord1hvNV"); 
		DynamicGL_MultiTexCoord2hNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLhalfNV s , GLhalfNV t)>("glMultiTexCoord2hNV"); 
		DynamicGL_MultiTexCoord2hvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLhalfNV *v)>("glMultiTexCoord2hvNV"); 
		DynamicGL_MultiTexCoord3hNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLhalfNV s , GLhalfNV t , GLhalfNV r)>("glMultiTexCoord3hNV"); 
		DynamicGL_MultiTexCoord3hvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLhalfNV *v)>("glMultiTexCoord3hvNV"); 
		DynamicGL_MultiTexCoord4hNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLhalfNV s , GLhalfNV t , GLhalfNV r , GLhalfNV q)>("glMultiTexCoord4hNV"); 
		DynamicGL_MultiTexCoord4hvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , const GLhalfNV *v)>("glMultiTexCoord4hvNV"); 
		DynamicGL_FogCoordhNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLhalfNV fog)>("glFogCoordhNV"); 
		DynamicGL_FogCoordhvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLhalfNV *fog)>("glFogCoordhvNV"); 
		DynamicGL_SecondaryColor3hNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLhalfNV red , GLhalfNV green , GLhalfNV blue)>("glSecondaryColor3hNV"); 
		DynamicGL_SecondaryColor3hvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLhalfNV *v)>("glSecondaryColor3hvNV"); 
		DynamicGL_VertexWeighthNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLhalfNV weight)>("glVertexWeighthNV"); 
		DynamicGL_VertexWeighthvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLhalfNV *weight)>("glVertexWeighthvNV"); 
		DynamicGL_VertexAttrib1hNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLhalfNV x)>("glVertexAttrib1hNV"); 
		DynamicGL_VertexAttrib1hvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLhalfNV *v)>("glVertexAttrib1hvNV"); 
		DynamicGL_VertexAttrib2hNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLhalfNV x , GLhalfNV y)>("glVertexAttrib2hNV"); 
		DynamicGL_VertexAttrib2hvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLhalfNV *v)>("glVertexAttrib2hvNV"); 
		DynamicGL_VertexAttrib3hNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLhalfNV x , GLhalfNV y , GLhalfNV z)>("glVertexAttrib3hNV"); 
		DynamicGL_VertexAttrib3hvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLhalfNV *v)>("glVertexAttrib3hvNV"); 
		DynamicGL_VertexAttrib4hNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLhalfNV x , GLhalfNV y , GLhalfNV z , GLhalfNV w)>("glVertexAttrib4hNV"); 
		DynamicGL_VertexAttrib4hvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLhalfNV *v)>("glVertexAttrib4hvNV"); 
		DynamicGL_VertexAttribs1hvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLsizei n , const GLhalfNV *v)>("glVertexAttribs1hvNV"); 
		DynamicGL_VertexAttribs2hvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLsizei n , const GLhalfNV *v)>("glVertexAttribs2hvNV"); 
		DynamicGL_VertexAttribs3hvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLsizei n , const GLhalfNV *v)>("glVertexAttribs3hvNV"); 
		DynamicGL_VertexAttribs4hvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLsizei n , const GLhalfNV *v)>("glVertexAttribs4hvNV"); 
		DinamicGLFeature_NV_half_float_loaded = true; 
}
bool DinamicGLFeature_NV_half_float_Supported() {
		if (!DinamicGLFeature_NV_half_float_loaded) {
			InitDinamicGLFeature_NV_half_float();
		}
		if (DynamicGL_Vertex2hNV==0) return false; 
		if (DynamicGL_Vertex2hvNV==0) return false; 
		if (DynamicGL_Vertex3hNV==0) return false; 
		if (DynamicGL_Vertex3hvNV==0) return false; 
		if (DynamicGL_Vertex4hNV==0) return false; 
		if (DynamicGL_Vertex4hvNV==0) return false; 
		if (DynamicGL_Normal3hNV==0) return false; 
		if (DynamicGL_Normal3hvNV==0) return false; 
		if (DynamicGL_Color3hNV==0) return false; 
		if (DynamicGL_Color3hvNV==0) return false; 
		if (DynamicGL_Color4hNV==0) return false; 
		if (DynamicGL_Color4hvNV==0) return false; 
		if (DynamicGL_TexCoord1hNV==0) return false; 
		if (DynamicGL_TexCoord1hvNV==0) return false; 
		if (DynamicGL_TexCoord2hNV==0) return false; 
		if (DynamicGL_TexCoord2hvNV==0) return false; 
		if (DynamicGL_TexCoord3hNV==0) return false; 
		if (DynamicGL_TexCoord3hvNV==0) return false; 
		if (DynamicGL_TexCoord4hNV==0) return false; 
		if (DynamicGL_TexCoord4hvNV==0) return false; 
		if (DynamicGL_MultiTexCoord1hNV==0) return false; 
		if (DynamicGL_MultiTexCoord1hvNV==0) return false; 
		if (DynamicGL_MultiTexCoord2hNV==0) return false; 
		if (DynamicGL_MultiTexCoord2hvNV==0) return false; 
		if (DynamicGL_MultiTexCoord3hNV==0) return false; 
		if (DynamicGL_MultiTexCoord3hvNV==0) return false; 
		if (DynamicGL_MultiTexCoord4hNV==0) return false; 
		if (DynamicGL_MultiTexCoord4hvNV==0) return false; 
		if (DynamicGL_FogCoordhNV==0) return false; 
		if (DynamicGL_FogCoordhvNV==0) return false; 
		if (DynamicGL_SecondaryColor3hNV==0) return false; 
		if (DynamicGL_SecondaryColor3hvNV==0) return false; 
		if (DynamicGL_VertexWeighthNV==0) return false; 
		if (DynamicGL_VertexWeighthvNV==0) return false; 
		if (DynamicGL_VertexAttrib1hNV==0) return false; 
		if (DynamicGL_VertexAttrib1hvNV==0) return false; 
		if (DynamicGL_VertexAttrib2hNV==0) return false; 
		if (DynamicGL_VertexAttrib2hvNV==0) return false; 
		if (DynamicGL_VertexAttrib3hNV==0) return false; 
		if (DynamicGL_VertexAttrib3hvNV==0) return false; 
		if (DynamicGL_VertexAttrib4hNV==0) return false; 
		if (DynamicGL_VertexAttrib4hvNV==0) return false; 
		if (DynamicGL_VertexAttribs1hvNV==0) return false; 
		if (DynamicGL_VertexAttribs2hvNV==0) return false; 
		if (DynamicGL_VertexAttribs3hvNV==0) return false; 
		if (DynamicGL_VertexAttribs4hvNV==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_half_float*/

/*EXT_gpu_shader4*/
#ifdef USE_DYNAMIC_GL_EXT_gpu_shader4
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetUniformuivEXT)(GLuint program , GLint location , GLuint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BindFragDataLocationEXT)(GLuint program , GLuint color , const GLchar *name) = 0; }
extern "C" { GLint (DYNAMIC_GL_APIENTRYP DynamicGL_GetFragDataLocationEXT)(GLuint program , const GLchar *name) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform1uiEXT)(GLint location , GLuint v0) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform2uiEXT)(GLint location , GLuint v0 , GLuint v1) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform3uiEXT)(GLint location , GLuint v0 , GLuint v1 , GLuint v2) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform4uiEXT)(GLint location , GLuint v0 , GLuint v1 , GLuint v2 , GLuint v3) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform1uivEXT)(GLint location , GLsizei count , const GLuint *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform2uivEXT)(GLint location , GLsizei count , const GLuint *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform3uivEXT)(GLint location , GLsizei count , const GLuint *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform4uivEXT)(GLint location , GLsizei count , const GLuint *value) = 0; }
static bool DinamicGLFeature_EXT_gpu_shader4_loaded = false; 
static void InitDinamicGLFeature_EXT_gpu_shader4() {
		DynamicGL_GetUniformuivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLuint *params)>("glGetUniformuivEXT"); 
		DynamicGL_BindFragDataLocationEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLuint color , const GLchar *name)>("glBindFragDataLocationEXT"); 
		DynamicGL_GetFragDataLocationEXT = DynamicGL_LoadFunction<GLint (DYNAMIC_GL_APIENTRYP)(GLuint program , const GLchar *name)>("glGetFragDataLocationEXT"); 
		DynamicGL_Uniform1uiEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLuint v0)>("glUniform1uiEXT"); 
		DynamicGL_Uniform2uiEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLuint v0 , GLuint v1)>("glUniform2uiEXT"); 
		DynamicGL_Uniform3uiEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLuint v0 , GLuint v1 , GLuint v2)>("glUniform3uiEXT"); 
		DynamicGL_Uniform4uiEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLuint v0 , GLuint v1 , GLuint v2 , GLuint v3)>("glUniform4uiEXT"); 
		DynamicGL_Uniform1uivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , const GLuint *value)>("glUniform1uivEXT"); 
		DynamicGL_Uniform2uivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , const GLuint *value)>("glUniform2uivEXT"); 
		DynamicGL_Uniform3uivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , const GLuint *value)>("glUniform3uivEXT"); 
		DynamicGL_Uniform4uivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , const GLuint *value)>("glUniform4uivEXT"); 
		DinamicGLFeature_EXT_gpu_shader4_loaded = true; 
}
bool DinamicGLFeature_EXT_gpu_shader4_Supported() {
		if (!DinamicGLFeature_EXT_gpu_shader4_loaded) {
			InitDinamicGLFeature_EXT_gpu_shader4();
		}
		if (DynamicGL_GetUniformuivEXT==0) return false; 
		if (DynamicGL_BindFragDataLocationEXT==0) return false; 
		if (DynamicGL_GetFragDataLocationEXT==0) return false; 
		if (DynamicGL_Uniform1uiEXT==0) return false; 
		if (DynamicGL_Uniform2uiEXT==0) return false; 
		if (DynamicGL_Uniform3uiEXT==0) return false; 
		if (DynamicGL_Uniform4uiEXT==0) return false; 
		if (DynamicGL_Uniform1uivEXT==0) return false; 
		if (DynamicGL_Uniform2uivEXT==0) return false; 
		if (DynamicGL_Uniform3uivEXT==0) return false; 
		if (DynamicGL_Uniform4uivEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_gpu_shader4*/

/*NV_light_max_exponent*/
#ifdef USE_DYNAMIC_GL_NV_light_max_exponent
static bool DinamicGLFeature_NV_light_max_exponent_loaded = false; 
static void InitDinamicGLFeature_NV_light_max_exponent() {
		DinamicGLFeature_NV_light_max_exponent_loaded = true; 
}
bool DinamicGLFeature_NV_light_max_exponent_Supported() {
		if (!DinamicGLFeature_NV_light_max_exponent_loaded) {
			InitDinamicGLFeature_NV_light_max_exponent();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_light_max_exponent*/

/*INGR_interlace_read*/
#ifdef USE_DYNAMIC_GL_INGR_interlace_read
static bool DinamicGLFeature_INGR_interlace_read_loaded = false; 
static void InitDinamicGLFeature_INGR_interlace_read() {
		DinamicGLFeature_INGR_interlace_read_loaded = true; 
}
bool DinamicGLFeature_INGR_interlace_read_Supported() {
		if (!DinamicGLFeature_INGR_interlace_read_loaded) {
			InitDinamicGLFeature_INGR_interlace_read();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_INGR_interlace_read*/

/*ATI_pn_triangles*/
#ifdef USE_DYNAMIC_GL_ATI_pn_triangles
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PNTrianglesiATI)(GLenum pname , GLint param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PNTrianglesfATI)(GLenum pname , GLfloat param) = 0; }
static bool DinamicGLFeature_ATI_pn_triangles_loaded = false; 
static void InitDinamicGLFeature_ATI_pn_triangles() {
		DynamicGL_PNTrianglesiATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLint param)>("glPNTrianglesiATI"); 
		DynamicGL_PNTrianglesfATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLfloat param)>("glPNTrianglesfATI"); 
		DinamicGLFeature_ATI_pn_triangles_loaded = true; 
}
bool DinamicGLFeature_ATI_pn_triangles_Supported() {
		if (!DinamicGLFeature_ATI_pn_triangles_loaded) {
			InitDinamicGLFeature_ATI_pn_triangles();
		}
		if (DynamicGL_PNTrianglesiATI==0) return false; 
		if (DynamicGL_PNTrianglesfATI==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_ATI_pn_triangles*/

/*APPLE_ycbcr_422*/
#ifdef USE_DYNAMIC_GL_APPLE_ycbcr_422
static bool DinamicGLFeature_APPLE_ycbcr_422_loaded = false; 
static void InitDinamicGLFeature_APPLE_ycbcr_422() {
		DinamicGLFeature_APPLE_ycbcr_422_loaded = true; 
}
bool DinamicGLFeature_APPLE_ycbcr_422_Supported() {
		if (!DinamicGLFeature_APPLE_ycbcr_422_loaded) {
			InitDinamicGLFeature_APPLE_ycbcr_422();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_APPLE_ycbcr_422*/

/*3DFX_tbuffer*/
#ifdef USE_DYNAMIC_GL_3DFX_tbuffer
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TbufferMask3DFX)(GLuint mask) = 0; }
static bool DinamicGLFeature_3DFX_tbuffer_loaded = false; 
static void InitDinamicGLFeature_3DFX_tbuffer() {
		DynamicGL_TbufferMask3DFX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint mask)>("glTbufferMask3DFX"); 
		DinamicGLFeature_3DFX_tbuffer_loaded = true; 
}
bool DinamicGLFeature_3DFX_tbuffer_Supported() {
		if (!DinamicGLFeature_3DFX_tbuffer_loaded) {
			InitDinamicGLFeature_3DFX_tbuffer();
		}
		if (DynamicGL_TbufferMask3DFX==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_3DFX_tbuffer*/

/*ARB_texture_float*/
#ifdef USE_DYNAMIC_GL_ARB_texture_float
static bool DinamicGLFeature_ARB_texture_float_loaded = false; 
static void InitDinamicGLFeature_ARB_texture_float() {
		DinamicGLFeature_ARB_texture_float_loaded = true; 
}
bool DinamicGLFeature_ARB_texture_float_Supported() {
		if (!DinamicGLFeature_ARB_texture_float_loaded) {
			InitDinamicGLFeature_ARB_texture_float();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_texture_float*/

/*NV_texture_expand_normal*/
#ifdef USE_DYNAMIC_GL_NV_texture_expand_normal
static bool DinamicGLFeature_NV_texture_expand_normal_loaded = false; 
static void InitDinamicGLFeature_NV_texture_expand_normal() {
		DinamicGLFeature_NV_texture_expand_normal_loaded = true; 
}
bool DinamicGLFeature_NV_texture_expand_normal_Supported() {
		if (!DinamicGLFeature_NV_texture_expand_normal_loaded) {
			InitDinamicGLFeature_NV_texture_expand_normal();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_texture_expand_normal*/

/*REND_screen_coordinates*/
#ifdef USE_DYNAMIC_GL_REND_screen_coordinates
static bool DinamicGLFeature_REND_screen_coordinates_loaded = false; 
static void InitDinamicGLFeature_REND_screen_coordinates() {
		DinamicGLFeature_REND_screen_coordinates_loaded = true; 
}
bool DinamicGLFeature_REND_screen_coordinates_Supported() {
		if (!DinamicGLFeature_REND_screen_coordinates_loaded) {
			InitDinamicGLFeature_REND_screen_coordinates();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_REND_screen_coordinates*/

/*EXT_framebuffer_sRGB*/
#ifdef USE_DYNAMIC_GL_EXT_framebuffer_sRGB
static bool DinamicGLFeature_EXT_framebuffer_sRGB_loaded = false; 
static void InitDinamicGLFeature_EXT_framebuffer_sRGB() {
		DinamicGLFeature_EXT_framebuffer_sRGB_loaded = true; 
}
bool DinamicGLFeature_EXT_framebuffer_sRGB_Supported() {
		if (!DinamicGLFeature_EXT_framebuffer_sRGB_loaded) {
			InitDinamicGLFeature_EXT_framebuffer_sRGB();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_framebuffer_sRGB*/

/*SGIX_texture_multi_buffer*/
#ifdef USE_DYNAMIC_GL_SGIX_texture_multi_buffer
static bool DinamicGLFeature_SGIX_texture_multi_buffer_loaded = false; 
static void InitDinamicGLFeature_SGIX_texture_multi_buffer() {
		DinamicGLFeature_SGIX_texture_multi_buffer_loaded = true; 
}
bool DinamicGLFeature_SGIX_texture_multi_buffer_Supported() {
		if (!DinamicGLFeature_SGIX_texture_multi_buffer_loaded) {
			InitDinamicGLFeature_SGIX_texture_multi_buffer();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_texture_multi_buffer*/

/*ARB_imaging*/
#ifdef USE_DYNAMIC_GL_ARB_imaging
static bool DinamicGLFeature_ARB_imaging_loaded = false; 
static void InitDinamicGLFeature_ARB_imaging() {
		DinamicGLFeature_ARB_imaging_loaded = true; 
}
bool DinamicGLFeature_ARB_imaging_Supported() {
		if (!DinamicGLFeature_ARB_imaging_loaded) {
			InitDinamicGLFeature_ARB_imaging();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_imaging*/

/*EXT_index_func*/
#ifdef USE_DYNAMIC_GL_EXT_index_func
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_IndexFuncEXT)(GLenum func , GLclampf ref) = 0; }
static bool DinamicGLFeature_EXT_index_func_loaded = false; 
static void InitDinamicGLFeature_EXT_index_func() {
		DynamicGL_IndexFuncEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum func , GLclampf ref)>("glIndexFuncEXT"); 
		DinamicGLFeature_EXT_index_func_loaded = true; 
}
bool DinamicGLFeature_EXT_index_func_Supported() {
		if (!DinamicGLFeature_EXT_index_func_loaded) {
			InitDinamicGLFeature_EXT_index_func();
		}
		if (DynamicGL_IndexFuncEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_index_func*/

/*NV_multisample_filter_hint*/
#ifdef USE_DYNAMIC_GL_NV_multisample_filter_hint
static bool DinamicGLFeature_NV_multisample_filter_hint_loaded = false; 
static void InitDinamicGLFeature_NV_multisample_filter_hint() {
		DinamicGLFeature_NV_multisample_filter_hint_loaded = true; 
}
bool DinamicGLFeature_NV_multisample_filter_hint_Supported() {
		if (!DinamicGLFeature_NV_multisample_filter_hint_loaded) {
			InitDinamicGLFeature_NV_multisample_filter_hint();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_multisample_filter_hint*/

/*SGIX_framezoom*/
#ifdef USE_DYNAMIC_GL_SGIX_framezoom
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FrameZoomSGIX)(GLint factor) = 0; }
static bool DinamicGLFeature_SGIX_framezoom_loaded = false; 
static void InitDinamicGLFeature_SGIX_framezoom() {
		DynamicGL_FrameZoomSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint factor)>("glFrameZoomSGIX"); 
		DinamicGLFeature_SGIX_framezoom_loaded = true; 
}
bool DinamicGLFeature_SGIX_framezoom_Supported() {
		if (!DinamicGLFeature_SGIX_framezoom_loaded) {
			InitDinamicGLFeature_SGIX_framezoom();
		}
		if (DynamicGL_FrameZoomSGIX==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_framezoom*/

/*SUNX_constant_data*/
#ifdef USE_DYNAMIC_GL_SUNX_constant_data
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FinishTextureSUNX)() = 0; }
static bool DinamicGLFeature_SUNX_constant_data_loaded = false; 
static void InitDinamicGLFeature_SUNX_constant_data() {
		DynamicGL_FinishTextureSUNX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glFinishTextureSUNX"); 
		DinamicGLFeature_SUNX_constant_data_loaded = true; 
}
bool DinamicGLFeature_SUNX_constant_data_Supported() {
		if (!DinamicGLFeature_SUNX_constant_data_loaded) {
			InitDinamicGLFeature_SUNX_constant_data();
		}
		if (DynamicGL_FinishTextureSUNX==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_SUNX_constant_data*/

/*HP_occlusion_test*/
#ifdef USE_DYNAMIC_GL_HP_occlusion_test
static bool DinamicGLFeature_HP_occlusion_test_loaded = false; 
static void InitDinamicGLFeature_HP_occlusion_test() {
		DinamicGLFeature_HP_occlusion_test_loaded = true; 
}
bool DinamicGLFeature_HP_occlusion_test_Supported() {
		if (!DinamicGLFeature_HP_occlusion_test_loaded) {
			InitDinamicGLFeature_HP_occlusion_test();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_HP_occlusion_test*/

/*SGIX_interlace*/
#ifdef USE_DYNAMIC_GL_SGIX_interlace
static bool DinamicGLFeature_SGIX_interlace_loaded = false; 
static void InitDinamicGLFeature_SGIX_interlace() {
		DinamicGLFeature_SGIX_interlace_loaded = true; 
}
bool DinamicGLFeature_SGIX_interlace_Supported() {
		if (!DinamicGLFeature_SGIX_interlace_loaded) {
			InitDinamicGLFeature_SGIX_interlace();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_interlace*/

/*ATI_pixel_format_float*/
#ifdef USE_DYNAMIC_GL_ATI_pixel_format_float
static bool DinamicGLFeature_ATI_pixel_format_float_loaded = false; 
static void InitDinamicGLFeature_ATI_pixel_format_float() {
		DinamicGLFeature_ATI_pixel_format_float_loaded = true; 
}
bool DinamicGLFeature_ATI_pixel_format_float_Supported() {
		if (!DinamicGLFeature_ATI_pixel_format_float_loaded) {
			InitDinamicGLFeature_ATI_pixel_format_float();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_ATI_pixel_format_float*/

/*ARB_point_sprite*/
#ifdef USE_DYNAMIC_GL_ARB_point_sprite
static bool DinamicGLFeature_ARB_point_sprite_loaded = false; 
static void InitDinamicGLFeature_ARB_point_sprite() {
		DinamicGLFeature_ARB_point_sprite_loaded = true; 
}
bool DinamicGLFeature_ARB_point_sprite_Supported() {
		if (!DinamicGLFeature_ARB_point_sprite_loaded) {
			InitDinamicGLFeature_ARB_point_sprite();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_point_sprite*/

/*NV_gpu_program4*/
#ifdef USE_DYNAMIC_GL_NV_gpu_program4
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramLocalParameterI4iNV)(GLenum target , GLuint index , GLint x , GLint y , GLint z , GLint w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramLocalParameterI4ivNV)(GLenum target , GLuint index , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramLocalParametersI4ivNV)(GLenum target , GLuint index , GLsizei count , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramLocalParameterI4uiNV)(GLenum target , GLuint index , GLuint x , GLuint y , GLuint z , GLuint w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramLocalParameterI4uivNV)(GLenum target , GLuint index , const GLuint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramLocalParametersI4uivNV)(GLenum target , GLuint index , GLsizei count , const GLuint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramEnvParameterI4iNV)(GLenum target , GLuint index , GLint x , GLint y , GLint z , GLint w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramEnvParameterI4ivNV)(GLenum target , GLuint index , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramEnvParametersI4ivNV)(GLenum target , GLuint index , GLsizei count , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramEnvParameterI4uiNV)(GLenum target , GLuint index , GLuint x , GLuint y , GLuint z , GLuint w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramEnvParameterI4uivNV)(GLenum target , GLuint index , const GLuint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramEnvParametersI4uivNV)(GLenum target , GLuint index , GLsizei count , const GLuint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramLocalParameterIivNV)(GLenum target , GLuint index , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramLocalParameterIuivNV)(GLenum target , GLuint index , GLuint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramEnvParameterIivNV)(GLenum target , GLuint index , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramEnvParameterIuivNV)(GLenum target , GLuint index , GLuint *params) = 0; }
static bool DinamicGLFeature_NV_gpu_program4_loaded = false; 
static void InitDinamicGLFeature_NV_gpu_program4() {
		DynamicGL_ProgramLocalParameterI4iNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLint x , GLint y , GLint z , GLint w)>("glProgramLocalParameterI4iNV"); 
		DynamicGL_ProgramLocalParameterI4ivNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , const GLint *params)>("glProgramLocalParameterI4ivNV"); 
		DynamicGL_ProgramLocalParametersI4ivNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLsizei count , const GLint *params)>("glProgramLocalParametersI4ivNV"); 
		DynamicGL_ProgramLocalParameterI4uiNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLuint x , GLuint y , GLuint z , GLuint w)>("glProgramLocalParameterI4uiNV"); 
		DynamicGL_ProgramLocalParameterI4uivNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , const GLuint *params)>("glProgramLocalParameterI4uivNV"); 
		DynamicGL_ProgramLocalParametersI4uivNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLsizei count , const GLuint *params)>("glProgramLocalParametersI4uivNV"); 
		DynamicGL_ProgramEnvParameterI4iNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLint x , GLint y , GLint z , GLint w)>("glProgramEnvParameterI4iNV"); 
		DynamicGL_ProgramEnvParameterI4ivNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , const GLint *params)>("glProgramEnvParameterI4ivNV"); 
		DynamicGL_ProgramEnvParametersI4ivNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLsizei count , const GLint *params)>("glProgramEnvParametersI4ivNV"); 
		DynamicGL_ProgramEnvParameterI4uiNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLuint x , GLuint y , GLuint z , GLuint w)>("glProgramEnvParameterI4uiNV"); 
		DynamicGL_ProgramEnvParameterI4uivNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , const GLuint *params)>("glProgramEnvParameterI4uivNV"); 
		DynamicGL_ProgramEnvParametersI4uivNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLsizei count , const GLuint *params)>("glProgramEnvParametersI4uivNV"); 
		DynamicGL_GetProgramLocalParameterIivNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLint *params)>("glGetProgramLocalParameterIivNV"); 
		DynamicGL_GetProgramLocalParameterIuivNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLuint *params)>("glGetProgramLocalParameterIuivNV"); 
		DynamicGL_GetProgramEnvParameterIivNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLint *params)>("glGetProgramEnvParameterIivNV"); 
		DynamicGL_GetProgramEnvParameterIuivNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLuint *params)>("glGetProgramEnvParameterIuivNV"); 
		DinamicGLFeature_NV_gpu_program4_loaded = true; 
}
bool DinamicGLFeature_NV_gpu_program4_Supported() {
		if (!DinamicGLFeature_NV_gpu_program4_loaded) {
			InitDinamicGLFeature_NV_gpu_program4();
		}
		if (DynamicGL_ProgramLocalParameterI4iNV==0) return false; 
		if (DynamicGL_ProgramLocalParameterI4ivNV==0) return false; 
		if (DynamicGL_ProgramLocalParametersI4ivNV==0) return false; 
		if (DynamicGL_ProgramLocalParameterI4uiNV==0) return false; 
		if (DynamicGL_ProgramLocalParameterI4uivNV==0) return false; 
		if (DynamicGL_ProgramLocalParametersI4uivNV==0) return false; 
		if (DynamicGL_ProgramEnvParameterI4iNV==0) return false; 
		if (DynamicGL_ProgramEnvParameterI4ivNV==0) return false; 
		if (DynamicGL_ProgramEnvParametersI4ivNV==0) return false; 
		if (DynamicGL_ProgramEnvParameterI4uiNV==0) return false; 
		if (DynamicGL_ProgramEnvParameterI4uivNV==0) return false; 
		if (DynamicGL_ProgramEnvParametersI4uivNV==0) return false; 
		if (DynamicGL_GetProgramLocalParameterIivNV==0) return false; 
		if (DynamicGL_GetProgramLocalParameterIuivNV==0) return false; 
		if (DynamicGL_GetProgramEnvParameterIivNV==0) return false; 
		if (DynamicGL_GetProgramEnvParameterIuivNV==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_gpu_program4*/

/*SUN_mesh_array*/
#ifdef USE_DYNAMIC_GL_SUN_mesh_array
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawMeshArraysSUN)(GLenum mode , GLint first , GLsizei count , GLsizei width) = 0; }
static bool DinamicGLFeature_SUN_mesh_array_loaded = false; 
static void InitDinamicGLFeature_SUN_mesh_array() {
		DynamicGL_DrawMeshArraysSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , GLint first , GLsizei count , GLsizei width)>("glDrawMeshArraysSUN"); 
		DinamicGLFeature_SUN_mesh_array_loaded = true; 
}
bool DinamicGLFeature_SUN_mesh_array_Supported() {
		if (!DinamicGLFeature_SUN_mesh_array_loaded) {
			InitDinamicGLFeature_SUN_mesh_array();
		}
		if (DynamicGL_DrawMeshArraysSUN==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_SUN_mesh_array*/

/*NV_texgen_emboss*/
#ifdef USE_DYNAMIC_GL_NV_texgen_emboss
static bool DinamicGLFeature_NV_texgen_emboss_loaded = false; 
static void InitDinamicGLFeature_NV_texgen_emboss() {
		DinamicGLFeature_NV_texgen_emboss_loaded = true; 
}
bool DinamicGLFeature_NV_texgen_emboss_Supported() {
		if (!DinamicGLFeature_NV_texgen_emboss_loaded) {
			InitDinamicGLFeature_NV_texgen_emboss();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_texgen_emboss*/

/*NV_framebuffer_multisample_coverage*/
#ifdef USE_DYNAMIC_GL_NV_framebuffer_multisample_coverage
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_RenderbufferStorageMultisampleCoverageNV)(GLenum target , GLsizei coverageSamples , GLsizei colorSamples , GLenum internalformat , GLsizei width , GLsizei height) = 0; }
static bool DinamicGLFeature_NV_framebuffer_multisample_coverage_loaded = false; 
static void InitDinamicGLFeature_NV_framebuffer_multisample_coverage() {
		DynamicGL_RenderbufferStorageMultisampleCoverageNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLsizei coverageSamples , GLsizei colorSamples , GLenum internalformat , GLsizei width , GLsizei height)>("glRenderbufferStorageMultisampleCoverageNV"); 
		DinamicGLFeature_NV_framebuffer_multisample_coverage_loaded = true; 
}
bool DinamicGLFeature_NV_framebuffer_multisample_coverage_Supported() {
		if (!DinamicGLFeature_NV_framebuffer_multisample_coverage_loaded) {
			InitDinamicGLFeature_NV_framebuffer_multisample_coverage();
		}
		if (DynamicGL_RenderbufferStorageMultisampleCoverageNV==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_framebuffer_multisample_coverage*/

/*EXT_separate_specular_color*/
#ifdef USE_DYNAMIC_GL_EXT_separate_specular_color
static bool DinamicGLFeature_EXT_separate_specular_color_loaded = false; 
static void InitDinamicGLFeature_EXT_separate_specular_color() {
		DinamicGLFeature_EXT_separate_specular_color_loaded = true; 
}
bool DinamicGLFeature_EXT_separate_specular_color_Supported() {
		if (!DinamicGLFeature_EXT_separate_specular_color_loaded) {
			InitDinamicGLFeature_EXT_separate_specular_color();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_separate_specular_color*/

/*EXT_blend_subtract*/
#ifdef USE_DYNAMIC_GL_EXT_blend_subtract
static bool DinamicGLFeature_EXT_blend_subtract_loaded = false; 
static void InitDinamicGLFeature_EXT_blend_subtract() {
		DinamicGLFeature_EXT_blend_subtract_loaded = true; 
}
bool DinamicGLFeature_EXT_blend_subtract_Supported() {
		if (!DinamicGLFeature_EXT_blend_subtract_loaded) {
			InitDinamicGLFeature_EXT_blend_subtract();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_blend_subtract*/

/*SGIX_texture_scale_bias*/
#ifdef USE_DYNAMIC_GL_SGIX_texture_scale_bias
static bool DinamicGLFeature_SGIX_texture_scale_bias_loaded = false; 
static void InitDinamicGLFeature_SGIX_texture_scale_bias() {
		DinamicGLFeature_SGIX_texture_scale_bias_loaded = true; 
}
bool DinamicGLFeature_SGIX_texture_scale_bias_Supported() {
		if (!DinamicGLFeature_SGIX_texture_scale_bias_loaded) {
			InitDinamicGLFeature_SGIX_texture_scale_bias();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_texture_scale_bias*/

/*APPLE_vertex_array_object*/
#ifdef USE_DYNAMIC_GL_APPLE_vertex_array_object
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BindVertexArrayAPPLE)(GLuint array) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteVertexArraysAPPLE)(GLsizei n , const GLuint *arrays) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GenVertexArraysAPPLE)(GLsizei n , GLuint *arrays) = 0; }
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsVertexArrayAPPLE)(GLuint array) = 0; }
static bool DinamicGLFeature_APPLE_vertex_array_object_loaded = false; 
static void InitDinamicGLFeature_APPLE_vertex_array_object() {
		DynamicGL_BindVertexArrayAPPLE = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint array)>("glBindVertexArrayAPPLE"); 
		DynamicGL_DeleteVertexArraysAPPLE = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , const GLuint *arrays)>("glDeleteVertexArraysAPPLE"); 
		DynamicGL_GenVertexArraysAPPLE = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , GLuint *arrays)>("glGenVertexArraysAPPLE"); 
		DynamicGL_IsVertexArrayAPPLE = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLuint array)>("glIsVertexArrayAPPLE"); 
		DinamicGLFeature_APPLE_vertex_array_object_loaded = true; 
}
bool DinamicGLFeature_APPLE_vertex_array_object_Supported() {
		if (!DinamicGLFeature_APPLE_vertex_array_object_loaded) {
			InitDinamicGLFeature_APPLE_vertex_array_object();
		}
		if (DynamicGL_BindVertexArrayAPPLE==0) return false; 
		if (DynamicGL_DeleteVertexArraysAPPLE==0) return false; 
		if (DynamicGL_GenVertexArraysAPPLE==0) return false; 
		if (DynamicGL_IsVertexArrayAPPLE==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_APPLE_vertex_array_object*/

/*EXT_copy_texture*/
#ifdef USE_DYNAMIC_GL_EXT_copy_texture
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyTexImage1DEXT)(GLenum target , GLint level , GLenum internalformat , GLint x , GLint y , GLsizei width , GLint border) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyTexImage2DEXT)(GLenum target , GLint level , GLenum internalformat , GLint x , GLint y , GLsizei width , GLsizei height , GLint border) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyTexSubImage1DEXT)(GLenum target , GLint level , GLint xoffset , GLint x , GLint y , GLsizei width) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyTexSubImage2DEXT)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint x , GLint y , GLsizei width , GLsizei height) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyTexSubImage3DEXT)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLint x , GLint y , GLsizei width , GLsizei height) = 0; }
static bool DinamicGLFeature_EXT_copy_texture_loaded = false; 
static void InitDinamicGLFeature_EXT_copy_texture() {
		DynamicGL_CopyTexImage1DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLenum internalformat , GLint x , GLint y , GLsizei width , GLint border)>("glCopyTexImage1DEXT"); 
		DynamicGL_CopyTexImage2DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLenum internalformat , GLint x , GLint y , GLsizei width , GLsizei height , GLint border)>("glCopyTexImage2DEXT"); 
		DynamicGL_CopyTexSubImage1DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLint xoffset , GLint x , GLint y , GLsizei width)>("glCopyTexSubImage1DEXT"); 
		DynamicGL_CopyTexSubImage2DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint x , GLint y , GLsizei width , GLsizei height)>("glCopyTexSubImage2DEXT"); 
		DynamicGL_CopyTexSubImage3DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLint x , GLint y , GLsizei width , GLsizei height)>("glCopyTexSubImage3DEXT"); 
		DinamicGLFeature_EXT_copy_texture_loaded = true; 
}
bool DinamicGLFeature_EXT_copy_texture_Supported() {
		if (!DinamicGLFeature_EXT_copy_texture_loaded) {
			InitDinamicGLFeature_EXT_copy_texture();
		}
		if (DynamicGL_CopyTexImage1DEXT==0) return false; 
		if (DynamicGL_CopyTexImage2DEXT==0) return false; 
		if (DynamicGL_CopyTexSubImage1DEXT==0) return false; 
		if (DynamicGL_CopyTexSubImage2DEXT==0) return false; 
		if (DynamicGL_CopyTexSubImage3DEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_copy_texture*/

/*EXT_texture_cube_map*/
#ifdef USE_DYNAMIC_GL_EXT_texture_cube_map
static bool DinamicGLFeature_EXT_texture_cube_map_loaded = false; 
static void InitDinamicGLFeature_EXT_texture_cube_map() {
		DinamicGLFeature_EXT_texture_cube_map_loaded = true; 
}
bool DinamicGLFeature_EXT_texture_cube_map_Supported() {
		if (!DinamicGLFeature_EXT_texture_cube_map_loaded) {
			InitDinamicGLFeature_EXT_texture_cube_map();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_texture_cube_map*/

/*EXT_coordinate_frame*/
#ifdef USE_DYNAMIC_GL_EXT_coordinate_frame
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Tangent3bEXT)(GLbyte tx , GLbyte ty , GLbyte tz) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Tangent3bvEXT)(const GLbyte *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Tangent3dEXT)(GLdouble tx , GLdouble ty , GLdouble tz) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Tangent3dvEXT)(const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Tangent3fEXT)(GLfloat tx , GLfloat ty , GLfloat tz) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Tangent3fvEXT)(const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Tangent3iEXT)(GLint tx , GLint ty , GLint tz) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Tangent3ivEXT)(const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Tangent3sEXT)(GLshort tx , GLshort ty , GLshort tz) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Tangent3svEXT)(const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Binormal3bEXT)(GLbyte bx , GLbyte by , GLbyte bz) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Binormal3bvEXT)(const GLbyte *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Binormal3dEXT)(GLdouble bx , GLdouble by , GLdouble bz) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Binormal3dvEXT)(const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Binormal3fEXT)(GLfloat bx , GLfloat by , GLfloat bz) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Binormal3fvEXT)(const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Binormal3iEXT)(GLint bx , GLint by , GLint bz) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Binormal3ivEXT)(const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Binormal3sEXT)(GLshort bx , GLshort by , GLshort bz) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Binormal3svEXT)(const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TangentPointerEXT)(GLenum type , GLsizei stride , const GLvoid *pointer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BinormalPointerEXT)(GLenum type , GLsizei stride , const GLvoid *pointer) = 0; }
static bool DinamicGLFeature_EXT_coordinate_frame_loaded = false; 
static void InitDinamicGLFeature_EXT_coordinate_frame() {
		DynamicGL_Tangent3bEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLbyte tx , GLbyte ty , GLbyte tz)>("glTangent3bEXT"); 
		DynamicGL_Tangent3bvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLbyte *v)>("glTangent3bvEXT"); 
		DynamicGL_Tangent3dEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble tx , GLdouble ty , GLdouble tz)>("glTangent3dEXT"); 
		DynamicGL_Tangent3dvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *v)>("glTangent3dvEXT"); 
		DynamicGL_Tangent3fEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat tx , GLfloat ty , GLfloat tz)>("glTangent3fEXT"); 
		DynamicGL_Tangent3fvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *v)>("glTangent3fvEXT"); 
		DynamicGL_Tangent3iEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint tx , GLint ty , GLint tz)>("glTangent3iEXT"); 
		DynamicGL_Tangent3ivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLint *v)>("glTangent3ivEXT"); 
		DynamicGL_Tangent3sEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLshort tx , GLshort ty , GLshort tz)>("glTangent3sEXT"); 
		DynamicGL_Tangent3svEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLshort *v)>("glTangent3svEXT"); 
		DynamicGL_Binormal3bEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLbyte bx , GLbyte by , GLbyte bz)>("glBinormal3bEXT"); 
		DynamicGL_Binormal3bvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLbyte *v)>("glBinormal3bvEXT"); 
		DynamicGL_Binormal3dEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble bx , GLdouble by , GLdouble bz)>("glBinormal3dEXT"); 
		DynamicGL_Binormal3dvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *v)>("glBinormal3dvEXT"); 
		DynamicGL_Binormal3fEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat bx , GLfloat by , GLfloat bz)>("glBinormal3fEXT"); 
		DynamicGL_Binormal3fvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *v)>("glBinormal3fvEXT"); 
		DynamicGL_Binormal3iEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint bx , GLint by , GLint bz)>("glBinormal3iEXT"); 
		DynamicGL_Binormal3ivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLint *v)>("glBinormal3ivEXT"); 
		DynamicGL_Binormal3sEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLshort bx , GLshort by , GLshort bz)>("glBinormal3sEXT"); 
		DynamicGL_Binormal3svEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLshort *v)>("glBinormal3svEXT"); 
		DynamicGL_TangentPointerEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum type , GLsizei stride , const GLvoid *pointer)>("glTangentPointerEXT"); 
		DynamicGL_BinormalPointerEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum type , GLsizei stride , const GLvoid *pointer)>("glBinormalPointerEXT"); 
		DinamicGLFeature_EXT_coordinate_frame_loaded = true; 
}
bool DinamicGLFeature_EXT_coordinate_frame_Supported() {
		if (!DinamicGLFeature_EXT_coordinate_frame_loaded) {
			InitDinamicGLFeature_EXT_coordinate_frame();
		}
		if (DynamicGL_Tangent3bEXT==0) return false; 
		if (DynamicGL_Tangent3bvEXT==0) return false; 
		if (DynamicGL_Tangent3dEXT==0) return false; 
		if (DynamicGL_Tangent3dvEXT==0) return false; 
		if (DynamicGL_Tangent3fEXT==0) return false; 
		if (DynamicGL_Tangent3fvEXT==0) return false; 
		if (DynamicGL_Tangent3iEXT==0) return false; 
		if (DynamicGL_Tangent3ivEXT==0) return false; 
		if (DynamicGL_Tangent3sEXT==0) return false; 
		if (DynamicGL_Tangent3svEXT==0) return false; 
		if (DynamicGL_Binormal3bEXT==0) return false; 
		if (DynamicGL_Binormal3bvEXT==0) return false; 
		if (DynamicGL_Binormal3dEXT==0) return false; 
		if (DynamicGL_Binormal3dvEXT==0) return false; 
		if (DynamicGL_Binormal3fEXT==0) return false; 
		if (DynamicGL_Binormal3fvEXT==0) return false; 
		if (DynamicGL_Binormal3iEXT==0) return false; 
		if (DynamicGL_Binormal3ivEXT==0) return false; 
		if (DynamicGL_Binormal3sEXT==0) return false; 
		if (DynamicGL_Binormal3svEXT==0) return false; 
		if (DynamicGL_TangentPointerEXT==0) return false; 
		if (DynamicGL_BinormalPointerEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_coordinate_frame*/

/*3DFX_multisample*/
#ifdef USE_DYNAMIC_GL_3DFX_multisample
static bool DinamicGLFeature_3DFX_multisample_loaded = false; 
static void InitDinamicGLFeature_3DFX_multisample() {
		DinamicGLFeature_3DFX_multisample_loaded = true; 
}
bool DinamicGLFeature_3DFX_multisample_Supported() {
		if (!DinamicGLFeature_3DFX_multisample_loaded) {
			InitDinamicGLFeature_3DFX_multisample();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_3DFX_multisample*/

/*SGIX_ycrcb*/
#ifdef USE_DYNAMIC_GL_SGIX_ycrcb
static bool DinamicGLFeature_SGIX_ycrcb_loaded = false; 
static void InitDinamicGLFeature_SGIX_ycrcb() {
		DinamicGLFeature_SGIX_ycrcb_loaded = true; 
}
bool DinamicGLFeature_SGIX_ycrcb_Supported() {
		if (!DinamicGLFeature_SGIX_ycrcb_loaded) {
			InitDinamicGLFeature_SGIX_ycrcb();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_ycrcb*/

/*SGIX_async_histogram*/
#ifdef USE_DYNAMIC_GL_SGIX_async_histogram
static bool DinamicGLFeature_SGIX_async_histogram_loaded = false; 
static void InitDinamicGLFeature_SGIX_async_histogram() {
		DinamicGLFeature_SGIX_async_histogram_loaded = true; 
}
bool DinamicGLFeature_SGIX_async_histogram_Supported() {
		if (!DinamicGLFeature_SGIX_async_histogram_loaded) {
			InitDinamicGLFeature_SGIX_async_histogram();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_async_histogram*/

/*SGIX_depth_texture*/
#ifdef USE_DYNAMIC_GL_SGIX_depth_texture
static bool DinamicGLFeature_SGIX_depth_texture_loaded = false; 
static void InitDinamicGLFeature_SGIX_depth_texture() {
		DinamicGLFeature_SGIX_depth_texture_loaded = true; 
}
bool DinamicGLFeature_SGIX_depth_texture_Supported() {
		if (!DinamicGLFeature_SGIX_depth_texture_loaded) {
			InitDinamicGLFeature_SGIX_depth_texture();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_depth_texture*/

/*EXT_stencil_two_side*/
#ifdef USE_DYNAMIC_GL_EXT_stencil_two_side
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ActiveStencilFaceEXT)(GLenum face) = 0; }
static bool DinamicGLFeature_EXT_stencil_two_side_loaded = false; 
static void InitDinamicGLFeature_EXT_stencil_two_side() {
		DynamicGL_ActiveStencilFaceEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum face)>("glActiveStencilFaceEXT"); 
		DinamicGLFeature_EXT_stencil_two_side_loaded = true; 
}
bool DinamicGLFeature_EXT_stencil_two_side_Supported() {
		if (!DinamicGLFeature_EXT_stencil_two_side_loaded) {
			InitDinamicGLFeature_EXT_stencil_two_side();
		}
		if (DynamicGL_ActiveStencilFaceEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_stencil_two_side*/

/*MESA_pack_invert*/
#ifdef USE_DYNAMIC_GL_MESA_pack_invert
static bool DinamicGLFeature_MESA_pack_invert_loaded = false; 
static void InitDinamicGLFeature_MESA_pack_invert() {
		DinamicGLFeature_MESA_pack_invert_loaded = true; 
}
bool DinamicGLFeature_MESA_pack_invert_Supported() {
		if (!DinamicGLFeature_MESA_pack_invert_loaded) {
			InitDinamicGLFeature_MESA_pack_invert();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_MESA_pack_invert*/

/*SGIX_texture_lod_bias*/
#ifdef USE_DYNAMIC_GL_SGIX_texture_lod_bias
static bool DinamicGLFeature_SGIX_texture_lod_bias_loaded = false; 
static void InitDinamicGLFeature_SGIX_texture_lod_bias() {
		DinamicGLFeature_SGIX_texture_lod_bias_loaded = true; 
}
bool DinamicGLFeature_SGIX_texture_lod_bias_Supported() {
		if (!DinamicGLFeature_SGIX_texture_lod_bias_loaded) {
			InitDinamicGLFeature_SGIX_texture_lod_bias();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_texture_lod_bias*/

/*EXT_framebuffer_multisample*/
#ifdef USE_DYNAMIC_GL_EXT_framebuffer_multisample
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_RenderbufferStorageMultisampleEXT)(GLenum target , GLsizei samples , GLenum internalformat , GLsizei width , GLsizei height) = 0; }
static bool DinamicGLFeature_EXT_framebuffer_multisample_loaded = false; 
static void InitDinamicGLFeature_EXT_framebuffer_multisample() {
		DynamicGL_RenderbufferStorageMultisampleEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLsizei samples , GLenum internalformat , GLsizei width , GLsizei height)>("glRenderbufferStorageMultisampleEXT"); 
		DinamicGLFeature_EXT_framebuffer_multisample_loaded = true; 
}
bool DinamicGLFeature_EXT_framebuffer_multisample_Supported() {
		if (!DinamicGLFeature_EXT_framebuffer_multisample_loaded) {
			InitDinamicGLFeature_EXT_framebuffer_multisample();
		}
		if (DynamicGL_RenderbufferStorageMultisampleEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_framebuffer_multisample*/

/*EXT_texture_filter_anisotropic*/
#ifdef USE_DYNAMIC_GL_EXT_texture_filter_anisotropic
static bool DinamicGLFeature_EXT_texture_filter_anisotropic_loaded = false; 
static void InitDinamicGLFeature_EXT_texture_filter_anisotropic() {
		DinamicGLFeature_EXT_texture_filter_anisotropic_loaded = true; 
}
bool DinamicGLFeature_EXT_texture_filter_anisotropic_Supported() {
		if (!DinamicGLFeature_EXT_texture_filter_anisotropic_loaded) {
			InitDinamicGLFeature_EXT_texture_filter_anisotropic();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_texture_filter_anisotropic*/

/*ARB_matrix_palette*/
#ifdef USE_DYNAMIC_GL_ARB_matrix_palette
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CurrentPaletteMatrixARB)(GLint index) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixIndexubvARB)(GLint size , const GLubyte *indices) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixIndexusvARB)(GLint size , const GLushort *indices) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixIndexuivARB)(GLint size , const GLuint *indices) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixIndexPointerARB)(GLint size , GLenum type , GLsizei stride , const GLvoid *pointer) = 0; }
static bool DinamicGLFeature_ARB_matrix_palette_loaded = false; 
static void InitDinamicGLFeature_ARB_matrix_palette() {
		DynamicGL_CurrentPaletteMatrixARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint index)>("glCurrentPaletteMatrixARB"); 
		DynamicGL_MatrixIndexubvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint size , const GLubyte *indices)>("glMatrixIndexubvARB"); 
		DynamicGL_MatrixIndexusvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint size , const GLushort *indices)>("glMatrixIndexusvARB"); 
		DynamicGL_MatrixIndexuivARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint size , const GLuint *indices)>("glMatrixIndexuivARB"); 
		DynamicGL_MatrixIndexPointerARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint size , GLenum type , GLsizei stride , const GLvoid *pointer)>("glMatrixIndexPointerARB"); 
		DinamicGLFeature_ARB_matrix_palette_loaded = true; 
}
bool DinamicGLFeature_ARB_matrix_palette_Supported() {
		if (!DinamicGLFeature_ARB_matrix_palette_loaded) {
			InitDinamicGLFeature_ARB_matrix_palette();
		}
		if (DynamicGL_CurrentPaletteMatrixARB==0) return false; 
		if (DynamicGL_MatrixIndexubvARB==0) return false; 
		if (DynamicGL_MatrixIndexusvARB==0) return false; 
		if (DynamicGL_MatrixIndexuivARB==0) return false; 
		if (DynamicGL_MatrixIndexPointerARB==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_matrix_palette*/

/*NV_texture_shader2*/
#ifdef USE_DYNAMIC_GL_NV_texture_shader2
static bool DinamicGLFeature_NV_texture_shader2_loaded = false; 
static void InitDinamicGLFeature_NV_texture_shader2() {
		DinamicGLFeature_NV_texture_shader2_loaded = true; 
}
bool DinamicGLFeature_NV_texture_shader2_Supported() {
		if (!DinamicGLFeature_NV_texture_shader2_loaded) {
			InitDinamicGLFeature_NV_texture_shader2();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_texture_shader2*/

/*ARB_texture_env_combine*/
#ifdef USE_DYNAMIC_GL_ARB_texture_env_combine
static bool DinamicGLFeature_ARB_texture_env_combine_loaded = false; 
static void InitDinamicGLFeature_ARB_texture_env_combine() {
		DinamicGLFeature_ARB_texture_env_combine_loaded = true; 
}
bool DinamicGLFeature_ARB_texture_env_combine_Supported() {
		if (!DinamicGLFeature_ARB_texture_env_combine_loaded) {
			InitDinamicGLFeature_ARB_texture_env_combine();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_texture_env_combine*/

/*ATI_element_array*/
#ifdef USE_DYNAMIC_GL_ATI_element_array
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ElementPointerATI)(GLenum type , const GLvoid *pointer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawElementArrayATI)(GLenum mode , GLsizei count) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawRangeElementArrayATI)(GLenum mode , GLuint start , GLuint end , GLsizei count) = 0; }
static bool DinamicGLFeature_ATI_element_array_loaded = false; 
static void InitDinamicGLFeature_ATI_element_array() {
		DynamicGL_ElementPointerATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum type , const GLvoid *pointer)>("glElementPointerATI"); 
		DynamicGL_DrawElementArrayATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , GLsizei count)>("glDrawElementArrayATI"); 
		DynamicGL_DrawRangeElementArrayATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , GLuint start , GLuint end , GLsizei count)>("glDrawRangeElementArrayATI"); 
		DinamicGLFeature_ATI_element_array_loaded = true; 
}
bool DinamicGLFeature_ATI_element_array_Supported() {
		if (!DinamicGLFeature_ATI_element_array_loaded) {
			InitDinamicGLFeature_ATI_element_array();
		}
		if (DynamicGL_ElementPointerATI==0) return false; 
		if (DynamicGL_DrawElementArrayATI==0) return false; 
		if (DynamicGL_DrawRangeElementArrayATI==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_ATI_element_array*/

/*EXT_blend_equation_separate*/
#ifdef USE_DYNAMIC_GL_EXT_blend_equation_separate
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendEquationSeparateEXT)(GLenum modeRGB , GLenum modeAlpha) = 0; }
static bool DinamicGLFeature_EXT_blend_equation_separate_loaded = false; 
static void InitDinamicGLFeature_EXT_blend_equation_separate() {
		DynamicGL_BlendEquationSeparateEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum modeRGB , GLenum modeAlpha)>("glBlendEquationSeparateEXT"); 
		DinamicGLFeature_EXT_blend_equation_separate_loaded = true; 
}
bool DinamicGLFeature_EXT_blend_equation_separate_Supported() {
		if (!DinamicGLFeature_EXT_blend_equation_separate_loaded) {
			InitDinamicGLFeature_EXT_blend_equation_separate();
		}
		if (DynamicGL_BlendEquationSeparateEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_blend_equation_separate*/

/*VERSION_1_5*/
#ifdef USE_DYNAMIC_GL_VERSION_1_5
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GenQueries)(GLsizei n , GLuint *ids) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteQueries)(GLsizei n , const GLuint *ids) = 0; }
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsQuery)(GLuint id) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BeginQuery)(GLenum target , GLuint id) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EndQuery)(GLenum target) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetQueryiv)(GLenum target , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetQueryObjectiv)(GLuint id , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetQueryObjectuiv)(GLuint id , GLenum pname , GLuint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BindBuffer)(GLenum target , GLuint buffer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteBuffers)(GLsizei n , const GLuint *buffers) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GenBuffers)(GLsizei n , GLuint *buffers) = 0; }
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsBuffer)(GLuint buffer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BufferData)(GLenum target , GLsizeiptr size , const GLvoid *data , GLenum usage) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BufferSubData)(GLenum target , GLintptr offset , GLsizeiptr size , const GLvoid *data) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetBufferSubData)(GLenum target , GLintptr offset , GLsizeiptr size , GLvoid *data) = 0; }
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_UnmapBuffer)(GLenum target) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetBufferParameteriv)(GLenum target , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetBufferPointerv)(GLenum target , GLenum pname , GLvoid* *params) = 0; }
static bool DinamicGLFeature_VERSION_1_5_loaded = false; 
static void InitDinamicGLFeature_VERSION_1_5() {
		DynamicGL_GenQueries = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , GLuint *ids)>("glGenQueries"); 
		DynamicGL_DeleteQueries = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , const GLuint *ids)>("glDeleteQueries"); 
		DynamicGL_IsQuery = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLuint id)>("glIsQuery"); 
		DynamicGL_BeginQuery = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint id)>("glBeginQuery"); 
		DynamicGL_EndQuery = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target)>("glEndQuery"); 
		DynamicGL_GetQueryiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint *params)>("glGetQueryiv"); 
		DynamicGL_GetQueryObjectiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , GLenum pname , GLint *params)>("glGetQueryObjectiv"); 
		DynamicGL_GetQueryObjectuiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , GLenum pname , GLuint *params)>("glGetQueryObjectuiv"); 
		DynamicGL_BindBuffer = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint buffer)>("glBindBuffer"); 
		DynamicGL_DeleteBuffers = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , const GLuint *buffers)>("glDeleteBuffers"); 
		DynamicGL_GenBuffers = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , GLuint *buffers)>("glGenBuffers"); 
		DynamicGL_IsBuffer = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLuint buffer)>("glIsBuffer"); 
		DynamicGL_BufferData = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLsizeiptr size , const GLvoid *data , GLenum usage)>("glBufferData"); 
		DynamicGL_BufferSubData = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLintptr offset , GLsizeiptr size , const GLvoid *data)>("glBufferSubData"); 
		DynamicGL_GetBufferSubData = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLintptr offset , GLsizeiptr size , GLvoid *data)>("glGetBufferSubData"); 
		DynamicGL_UnmapBuffer = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLenum target)>("glUnmapBuffer"); 
		DynamicGL_GetBufferParameteriv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint *params)>("glGetBufferParameteriv"); 
		DynamicGL_GetBufferPointerv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLvoid* *params)>("glGetBufferPointerv"); 
		DinamicGLFeature_VERSION_1_5_loaded = true; 
}
bool DinamicGLFeature_VERSION_1_5_Supported() {
		if (!DinamicGLFeature_VERSION_1_5_loaded) {
			InitDinamicGLFeature_VERSION_1_5();
		}
		if (DynamicGL_GenQueries==0) return false; 
		if (DynamicGL_DeleteQueries==0) return false; 
		if (DynamicGL_IsQuery==0) return false; 
		if (DynamicGL_BeginQuery==0) return false; 
		if (DynamicGL_EndQuery==0) return false; 
		if (DynamicGL_GetQueryiv==0) return false; 
		if (DynamicGL_GetQueryObjectiv==0) return false; 
		if (DynamicGL_GetQueryObjectuiv==0) return false; 
		if (DynamicGL_BindBuffer==0) return false; 
		if (DynamicGL_DeleteBuffers==0) return false; 
		if (DynamicGL_GenBuffers==0) return false; 
		if (DynamicGL_IsBuffer==0) return false; 
		if (DynamicGL_BufferData==0) return false; 
		if (DynamicGL_BufferSubData==0) return false; 
		if (DynamicGL_GetBufferSubData==0) return false; 
		if (DynamicGL_UnmapBuffer==0) return false; 
		if (DynamicGL_GetBufferParameteriv==0) return false; 
		if (DynamicGL_GetBufferPointerv==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_VERSION_1_5*/

/*NV_vertex_program4*/
#ifdef USE_DYNAMIC_GL_NV_vertex_program4
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI1iEXT)(GLuint index , GLint x) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI2iEXT)(GLuint index , GLint x , GLint y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI3iEXT)(GLuint index , GLint x , GLint y , GLint z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI4iEXT)(GLuint index , GLint x , GLint y , GLint z , GLint w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI1uiEXT)(GLuint index , GLuint x) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI2uiEXT)(GLuint index , GLuint x , GLuint y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI3uiEXT)(GLuint index , GLuint x , GLuint y , GLuint z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI4uiEXT)(GLuint index , GLuint x , GLuint y , GLuint z , GLuint w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI1ivEXT)(GLuint index , const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI2ivEXT)(GLuint index , const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI3ivEXT)(GLuint index , const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI4ivEXT)(GLuint index , const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI1uivEXT)(GLuint index , const GLuint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI2uivEXT)(GLuint index , const GLuint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI3uivEXT)(GLuint index , const GLuint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI4uivEXT)(GLuint index , const GLuint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI4bvEXT)(GLuint index , const GLbyte *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI4svEXT)(GLuint index , const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI4ubvEXT)(GLuint index , const GLubyte *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI4usvEXT)(GLuint index , const GLushort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribIPointerEXT)(GLuint index , GLint size , GLenum type , GLsizei stride , const GLvoid *pointer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribIivEXT)(GLuint index , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribIuivEXT)(GLuint index , GLenum pname , GLuint *params) = 0; }
static bool DinamicGLFeature_NV_vertex_program4_loaded = false; 
static void InitDinamicGLFeature_NV_vertex_program4() {
		DynamicGL_VertexAttribI1iEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLint x)>("glVertexAttribI1iEXT"); 
		DynamicGL_VertexAttribI2iEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLint x , GLint y)>("glVertexAttribI2iEXT"); 
		DynamicGL_VertexAttribI3iEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLint x , GLint y , GLint z)>("glVertexAttribI3iEXT"); 
		DynamicGL_VertexAttribI4iEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLint x , GLint y , GLint z , GLint w)>("glVertexAttribI4iEXT"); 
		DynamicGL_VertexAttribI1uiEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLuint x)>("glVertexAttribI1uiEXT"); 
		DynamicGL_VertexAttribI2uiEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLuint x , GLuint y)>("glVertexAttribI2uiEXT"); 
		DynamicGL_VertexAttribI3uiEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLuint x , GLuint y , GLuint z)>("glVertexAttribI3uiEXT"); 
		DynamicGL_VertexAttribI4uiEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLuint x , GLuint y , GLuint z , GLuint w)>("glVertexAttribI4uiEXT"); 
		DynamicGL_VertexAttribI1ivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLint *v)>("glVertexAttribI1ivEXT"); 
		DynamicGL_VertexAttribI2ivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLint *v)>("glVertexAttribI2ivEXT"); 
		DynamicGL_VertexAttribI3ivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLint *v)>("glVertexAttribI3ivEXT"); 
		DynamicGL_VertexAttribI4ivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLint *v)>("glVertexAttribI4ivEXT"); 
		DynamicGL_VertexAttribI1uivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLuint *v)>("glVertexAttribI1uivEXT"); 
		DynamicGL_VertexAttribI2uivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLuint *v)>("glVertexAttribI2uivEXT"); 
		DynamicGL_VertexAttribI3uivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLuint *v)>("glVertexAttribI3uivEXT"); 
		DynamicGL_VertexAttribI4uivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLuint *v)>("glVertexAttribI4uivEXT"); 
		DynamicGL_VertexAttribI4bvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLbyte *v)>("glVertexAttribI4bvEXT"); 
		DynamicGL_VertexAttribI4svEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLshort *v)>("glVertexAttribI4svEXT"); 
		DynamicGL_VertexAttribI4ubvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLubyte *v)>("glVertexAttribI4ubvEXT"); 
		DynamicGL_VertexAttribI4usvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , const GLushort *v)>("glVertexAttribI4usvEXT"); 
		DynamicGL_VertexAttribIPointerEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLint size , GLenum type , GLsizei stride , const GLvoid *pointer)>("glVertexAttribIPointerEXT"); 
		DynamicGL_GetVertexAttribIivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLenum pname , GLint *params)>("glGetVertexAttribIivEXT"); 
		DynamicGL_GetVertexAttribIuivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLenum pname , GLuint *params)>("glGetVertexAttribIuivEXT"); 
		DinamicGLFeature_NV_vertex_program4_loaded = true; 
}
bool DinamicGLFeature_NV_vertex_program4_Supported() {
		if (!DinamicGLFeature_NV_vertex_program4_loaded) {
			InitDinamicGLFeature_NV_vertex_program4();
		}
		if (DynamicGL_VertexAttribI1iEXT==0) return false; 
		if (DynamicGL_VertexAttribI2iEXT==0) return false; 
		if (DynamicGL_VertexAttribI3iEXT==0) return false; 
		if (DynamicGL_VertexAttribI4iEXT==0) return false; 
		if (DynamicGL_VertexAttribI1uiEXT==0) return false; 
		if (DynamicGL_VertexAttribI2uiEXT==0) return false; 
		if (DynamicGL_VertexAttribI3uiEXT==0) return false; 
		if (DynamicGL_VertexAttribI4uiEXT==0) return false; 
		if (DynamicGL_VertexAttribI1ivEXT==0) return false; 
		if (DynamicGL_VertexAttribI2ivEXT==0) return false; 
		if (DynamicGL_VertexAttribI3ivEXT==0) return false; 
		if (DynamicGL_VertexAttribI4ivEXT==0) return false; 
		if (DynamicGL_VertexAttribI1uivEXT==0) return false; 
		if (DynamicGL_VertexAttribI2uivEXT==0) return false; 
		if (DynamicGL_VertexAttribI3uivEXT==0) return false; 
		if (DynamicGL_VertexAttribI4uivEXT==0) return false; 
		if (DynamicGL_VertexAttribI4bvEXT==0) return false; 
		if (DynamicGL_VertexAttribI4svEXT==0) return false; 
		if (DynamicGL_VertexAttribI4ubvEXT==0) return false; 
		if (DynamicGL_VertexAttribI4usvEXT==0) return false; 
		if (DynamicGL_VertexAttribIPointerEXT==0) return false; 
		if (DynamicGL_GetVertexAttribIivEXT==0) return false; 
		if (DynamicGL_GetVertexAttribIuivEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_vertex_program4*/

/*ARB_vertex_shader*/
#ifdef USE_DYNAMIC_GL_ARB_vertex_shader
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BindAttribLocationARB)(GLhandleARB programObj , GLuint index , const GLcharARB *name) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetActiveAttribARB)(GLhandleARB programObj , GLuint index , GLsizei maxLength , GLsizei *length , GLint *size , GLenum *type , GLcharARB *name) = 0; }
extern "C" { GLint (DYNAMIC_GL_APIENTRYP DynamicGL_GetAttribLocationARB)(GLhandleARB programObj , const GLcharARB *name) = 0; }
static bool DinamicGLFeature_ARB_vertex_shader_loaded = false; 
static void InitDinamicGLFeature_ARB_vertex_shader() {
		DynamicGL_BindAttribLocationARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLhandleARB programObj , GLuint index , const GLcharARB *name)>("glBindAttribLocationARB"); 
		DynamicGL_GetActiveAttribARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLhandleARB programObj , GLuint index , GLsizei maxLength , GLsizei *length , GLint *size , GLenum *type , GLcharARB *name)>("glGetActiveAttribARB"); 
		DynamicGL_GetAttribLocationARB = DynamicGL_LoadFunction<GLint (DYNAMIC_GL_APIENTRYP)(GLhandleARB programObj , const GLcharARB *name)>("glGetAttribLocationARB"); 
		DinamicGLFeature_ARB_vertex_shader_loaded = true; 
}
bool DinamicGLFeature_ARB_vertex_shader_Supported() {
		if (!DinamicGLFeature_ARB_vertex_shader_loaded) {
			InitDinamicGLFeature_ARB_vertex_shader();
		}
		if (DynamicGL_BindAttribLocationARB==0) return false; 
		if (DynamicGL_GetActiveAttribARB==0) return false; 
		if (DynamicGL_GetAttribLocationARB==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_vertex_shader*/

/*EXT_polygon_offset*/
#ifdef USE_DYNAMIC_GL_EXT_polygon_offset
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PolygonOffsetEXT)(GLfloat factor , GLfloat bias) = 0; }
static bool DinamicGLFeature_EXT_polygon_offset_loaded = false; 
static void InitDinamicGLFeature_EXT_polygon_offset() {
		DynamicGL_PolygonOffsetEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat factor , GLfloat bias)>("glPolygonOffsetEXT"); 
		DinamicGLFeature_EXT_polygon_offset_loaded = true; 
}
bool DinamicGLFeature_EXT_polygon_offset_Supported() {
		if (!DinamicGLFeature_EXT_polygon_offset_loaded) {
			InitDinamicGLFeature_EXT_polygon_offset();
		}
		if (DynamicGL_PolygonOffsetEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_polygon_offset*/

/*ARB_vertex_blend*/
#ifdef USE_DYNAMIC_GL_ARB_vertex_blend
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WeightbvARB)(GLint size , const GLbyte *weights) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WeightsvARB)(GLint size , const GLshort *weights) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WeightivARB)(GLint size , const GLint *weights) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WeightfvARB)(GLint size , const GLfloat *weights) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WeightdvARB)(GLint size , const GLdouble *weights) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WeightubvARB)(GLint size , const GLubyte *weights) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WeightusvARB)(GLint size , const GLushort *weights) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WeightuivARB)(GLint size , const GLuint *weights) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WeightPointerARB)(GLint size , GLenum type , GLsizei stride , const GLvoid *pointer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexBlendARB)(GLint count) = 0; }
static bool DinamicGLFeature_ARB_vertex_blend_loaded = false; 
static void InitDinamicGLFeature_ARB_vertex_blend() {
		DynamicGL_WeightbvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint size , const GLbyte *weights)>("glWeightbvARB"); 
		DynamicGL_WeightsvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint size , const GLshort *weights)>("glWeightsvARB"); 
		DynamicGL_WeightivARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint size , const GLint *weights)>("glWeightivARB"); 
		DynamicGL_WeightfvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint size , const GLfloat *weights)>("glWeightfvARB"); 
		DynamicGL_WeightdvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint size , const GLdouble *weights)>("glWeightdvARB"); 
		DynamicGL_WeightubvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint size , const GLubyte *weights)>("glWeightubvARB"); 
		DynamicGL_WeightusvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint size , const GLushort *weights)>("glWeightusvARB"); 
		DynamicGL_WeightuivARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint size , const GLuint *weights)>("glWeightuivARB"); 
		DynamicGL_WeightPointerARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint size , GLenum type , GLsizei stride , const GLvoid *pointer)>("glWeightPointerARB"); 
		DynamicGL_VertexBlendARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint count)>("glVertexBlendARB"); 
		DinamicGLFeature_ARB_vertex_blend_loaded = true; 
}
bool DinamicGLFeature_ARB_vertex_blend_Supported() {
		if (!DinamicGLFeature_ARB_vertex_blend_loaded) {
			InitDinamicGLFeature_ARB_vertex_blend();
		}
		if (DynamicGL_WeightbvARB==0) return false; 
		if (DynamicGL_WeightsvARB==0) return false; 
		if (DynamicGL_WeightivARB==0) return false; 
		if (DynamicGL_WeightfvARB==0) return false; 
		if (DynamicGL_WeightdvARB==0) return false; 
		if (DynamicGL_WeightubvARB==0) return false; 
		if (DynamicGL_WeightusvARB==0) return false; 
		if (DynamicGL_WeightuivARB==0) return false; 
		if (DynamicGL_WeightPointerARB==0) return false; 
		if (DynamicGL_VertexBlendARB==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_vertex_blend*/

/*WIN_specular_fog*/
#ifdef USE_DYNAMIC_GL_WIN_specular_fog
static bool DinamicGLFeature_WIN_specular_fog_loaded = false; 
static void InitDinamicGLFeature_WIN_specular_fog() {
		DinamicGLFeature_WIN_specular_fog_loaded = true; 
}
bool DinamicGLFeature_WIN_specular_fog_Supported() {
		if (!DinamicGLFeature_WIN_specular_fog_loaded) {
			InitDinamicGLFeature_WIN_specular_fog();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_WIN_specular_fog*/

/*SGIX_impact_pixel_texture*/
#ifdef USE_DYNAMIC_GL_SGIX_impact_pixel_texture
static bool DinamicGLFeature_SGIX_impact_pixel_texture_loaded = false; 
static void InitDinamicGLFeature_SGIX_impact_pixel_texture() {
		DinamicGLFeature_SGIX_impact_pixel_texture_loaded = true; 
}
bool DinamicGLFeature_SGIX_impact_pixel_texture_Supported() {
		if (!DinamicGLFeature_SGIX_impact_pixel_texture_loaded) {
			InitDinamicGLFeature_SGIX_impact_pixel_texture();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_impact_pixel_texture*/

/*EXT_depth_bounds_test*/
#ifdef USE_DYNAMIC_GL_EXT_depth_bounds_test
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DepthBoundsEXT)(GLclampd zmin , GLclampd zmax) = 0; }
static bool DinamicGLFeature_EXT_depth_bounds_test_loaded = false; 
static void InitDinamicGLFeature_EXT_depth_bounds_test() {
		DynamicGL_DepthBoundsEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLclampd zmin , GLclampd zmax)>("glDepthBoundsEXT"); 
		DinamicGLFeature_EXT_depth_bounds_test_loaded = true; 
}
bool DinamicGLFeature_EXT_depth_bounds_test_Supported() {
		if (!DinamicGLFeature_EXT_depth_bounds_test_loaded) {
			InitDinamicGLFeature_EXT_depth_bounds_test();
		}
		if (DynamicGL_DepthBoundsEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_depth_bounds_test*/

/*EXT_texture_mirror_clamp*/
#ifdef USE_DYNAMIC_GL_EXT_texture_mirror_clamp
static bool DinamicGLFeature_EXT_texture_mirror_clamp_loaded = false; 
static void InitDinamicGLFeature_EXT_texture_mirror_clamp() {
		DinamicGLFeature_EXT_texture_mirror_clamp_loaded = true; 
}
bool DinamicGLFeature_EXT_texture_mirror_clamp_Supported() {
		if (!DinamicGLFeature_EXT_texture_mirror_clamp_loaded) {
			InitDinamicGLFeature_EXT_texture_mirror_clamp();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_texture_mirror_clamp*/

/*SGIS_texture_lod*/
#ifdef USE_DYNAMIC_GL_SGIS_texture_lod
static bool DinamicGLFeature_SGIS_texture_lod_loaded = false; 
static void InitDinamicGLFeature_SGIS_texture_lod() {
		DinamicGLFeature_SGIS_texture_lod_loaded = true; 
}
bool DinamicGLFeature_SGIS_texture_lod_Supported() {
		if (!DinamicGLFeature_SGIS_texture_lod_loaded) {
			InitDinamicGLFeature_SGIS_texture_lod();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIS_texture_lod*/

/*VERSION_1_2*/
#ifdef USE_DYNAMIC_GL_VERSION_1_2
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendColor)(GLclampf red , GLclampf green , GLclampf blue , GLclampf alpha) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendEquation)(GLenum mode) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawRangeElements)(GLenum mode , GLuint start , GLuint end , GLsizei count , GLenum type , const GLvoid *indices) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorTable)(GLenum target , GLenum internalformat , GLsizei width , GLenum format , GLenum type , const GLvoid *table) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorTableParameterfv)(GLenum target , GLenum pname , const GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorTableParameteriv)(GLenum target , GLenum pname , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyColorTable)(GLenum target , GLenum internalformat , GLint x , GLint y , GLsizei width) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetColorTable)(GLenum target , GLenum format , GLenum type , GLvoid *table) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetColorTableParameterfv)(GLenum target , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetColorTableParameteriv)(GLenum target , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorSubTable)(GLenum target , GLsizei start , GLsizei count , GLenum format , GLenum type , const GLvoid *data) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyColorSubTable)(GLenum target , GLsizei start , GLint x , GLint y , GLsizei width) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ConvolutionFilter1D)(GLenum target , GLenum internalformat , GLsizei width , GLenum format , GLenum type , const GLvoid *image) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ConvolutionFilter2D)(GLenum target , GLenum internalformat , GLsizei width , GLsizei height , GLenum format , GLenum type , const GLvoid *image) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ConvolutionParameterf)(GLenum target , GLenum pname , GLfloat params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ConvolutionParameterfv)(GLenum target , GLenum pname , const GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ConvolutionParameteri)(GLenum target , GLenum pname , GLint params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ConvolutionParameteriv)(GLenum target , GLenum pname , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyConvolutionFilter1D)(GLenum target , GLenum internalformat , GLint x , GLint y , GLsizei width) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyConvolutionFilter2D)(GLenum target , GLenum internalformat , GLint x , GLint y , GLsizei width , GLsizei height) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetConvolutionFilter)(GLenum target , GLenum format , GLenum type , GLvoid *image) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetConvolutionParameterfv)(GLenum target , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetConvolutionParameteriv)(GLenum target , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetSeparableFilter)(GLenum target , GLenum format , GLenum type , GLvoid *row , GLvoid *column , GLvoid *span) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SeparableFilter2D)(GLenum target , GLenum internalformat , GLsizei width , GLsizei height , GLenum format , GLenum type , const GLvoid *row , const GLvoid *column) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetHistogram)(GLenum target , GLboolean reset , GLenum format , GLenum type , GLvoid *values) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetHistogramParameterfv)(GLenum target , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetHistogramParameteriv)(GLenum target , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMinmax)(GLenum target , GLboolean reset , GLenum format , GLenum type , GLvoid *values) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMinmaxParameterfv)(GLenum target , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMinmaxParameteriv)(GLenum target , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Histogram)(GLenum target , GLsizei width , GLenum internalformat , GLboolean sink) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Minmax)(GLenum target , GLenum internalformat , GLboolean sink) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ResetHistogram)(GLenum target) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ResetMinmax)(GLenum target) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexImage3D)(GLenum target , GLint level , GLint internalformat , GLsizei width , GLsizei height , GLsizei depth , GLint border , GLenum format , GLenum type , const GLvoid *pixels) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexSubImage3D)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLsizei width , GLsizei height , GLsizei depth , GLenum format , GLenum type , const GLvoid *pixels) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyTexSubImage3D)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLint x , GLint y , GLsizei width , GLsizei height) = 0; }
static bool DinamicGLFeature_VERSION_1_2_loaded = false; 
static void InitDinamicGLFeature_VERSION_1_2() {
		DynamicGL_BlendColor = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLclampf red , GLclampf green , GLclampf blue , GLclampf alpha)>("glBlendColor"); 
		DynamicGL_BlendEquation = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode)>("glBlendEquation"); 
		DynamicGL_DrawRangeElements = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , GLuint start , GLuint end , GLsizei count , GLenum type , const GLvoid *indices)>("glDrawRangeElements"); 
		DynamicGL_ColorTable = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum internalformat , GLsizei width , GLenum format , GLenum type , const GLvoid *table)>("glColorTable"); 
		DynamicGL_ColorTableParameterfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , const GLfloat *params)>("glColorTableParameterfv"); 
		DynamicGL_ColorTableParameteriv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , const GLint *params)>("glColorTableParameteriv"); 
		DynamicGL_CopyColorTable = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum internalformat , GLint x , GLint y , GLsizei width)>("glCopyColorTable"); 
		DynamicGL_GetColorTable = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum format , GLenum type , GLvoid *table)>("glGetColorTable"); 
		DynamicGL_GetColorTableParameterfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLfloat *params)>("glGetColorTableParameterfv"); 
		DynamicGL_GetColorTableParameteriv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint *params)>("glGetColorTableParameteriv"); 
		DynamicGL_ColorSubTable = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLsizei start , GLsizei count , GLenum format , GLenum type , const GLvoid *data)>("glColorSubTable"); 
		DynamicGL_CopyColorSubTable = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLsizei start , GLint x , GLint y , GLsizei width)>("glCopyColorSubTable"); 
		DynamicGL_ConvolutionFilter1D = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum internalformat , GLsizei width , GLenum format , GLenum type , const GLvoid *image)>("glConvolutionFilter1D"); 
		DynamicGL_ConvolutionFilter2D = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum internalformat , GLsizei width , GLsizei height , GLenum format , GLenum type , const GLvoid *image)>("glConvolutionFilter2D"); 
		DynamicGL_ConvolutionParameterf = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLfloat params)>("glConvolutionParameterf"); 
		DynamicGL_ConvolutionParameterfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , const GLfloat *params)>("glConvolutionParameterfv"); 
		DynamicGL_ConvolutionParameteri = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint params)>("glConvolutionParameteri"); 
		DynamicGL_ConvolutionParameteriv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , const GLint *params)>("glConvolutionParameteriv"); 
		DynamicGL_CopyConvolutionFilter1D = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum internalformat , GLint x , GLint y , GLsizei width)>("glCopyConvolutionFilter1D"); 
		DynamicGL_CopyConvolutionFilter2D = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum internalformat , GLint x , GLint y , GLsizei width , GLsizei height)>("glCopyConvolutionFilter2D"); 
		DynamicGL_GetConvolutionFilter = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum format , GLenum type , GLvoid *image)>("glGetConvolutionFilter"); 
		DynamicGL_GetConvolutionParameterfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLfloat *params)>("glGetConvolutionParameterfv"); 
		DynamicGL_GetConvolutionParameteriv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint *params)>("glGetConvolutionParameteriv"); 
		DynamicGL_GetSeparableFilter = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum format , GLenum type , GLvoid *row , GLvoid *column , GLvoid *span)>("glGetSeparableFilter"); 
		DynamicGL_SeparableFilter2D = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum internalformat , GLsizei width , GLsizei height , GLenum format , GLenum type , const GLvoid *row , const GLvoid *column)>("glSeparableFilter2D"); 
		DynamicGL_GetHistogram = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLboolean reset , GLenum format , GLenum type , GLvoid *values)>("glGetHistogram"); 
		DynamicGL_GetHistogramParameterfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLfloat *params)>("glGetHistogramParameterfv"); 
		DynamicGL_GetHistogramParameteriv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint *params)>("glGetHistogramParameteriv"); 
		DynamicGL_GetMinmax = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLboolean reset , GLenum format , GLenum type , GLvoid *values)>("glGetMinmax"); 
		DynamicGL_GetMinmaxParameterfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLfloat *params)>("glGetMinmaxParameterfv"); 
		DynamicGL_GetMinmaxParameteriv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint *params)>("glGetMinmaxParameteriv"); 
		DynamicGL_Histogram = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLsizei width , GLenum internalformat , GLboolean sink)>("glHistogram"); 
		DynamicGL_Minmax = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum internalformat , GLboolean sink)>("glMinmax"); 
		DynamicGL_ResetHistogram = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target)>("glResetHistogram"); 
		DynamicGL_ResetMinmax = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target)>("glResetMinmax"); 
		DynamicGL_TexImage3D = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLint internalformat , GLsizei width , GLsizei height , GLsizei depth , GLint border , GLenum format , GLenum type , const GLvoid *pixels)>("glTexImage3D"); 
		DynamicGL_TexSubImage3D = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLsizei width , GLsizei height , GLsizei depth , GLenum format , GLenum type , const GLvoid *pixels)>("glTexSubImage3D"); 
		DynamicGL_CopyTexSubImage3D = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLint x , GLint y , GLsizei width , GLsizei height)>("glCopyTexSubImage3D"); 
		DinamicGLFeature_VERSION_1_2_loaded = true; 
}
bool DinamicGLFeature_VERSION_1_2_Supported() {
		if (!DinamicGLFeature_VERSION_1_2_loaded) {
			InitDinamicGLFeature_VERSION_1_2();
		}
		if (DynamicGL_BlendColor==0) return false; 
		if (DynamicGL_BlendEquation==0) return false; 
		if (DynamicGL_DrawRangeElements==0) return false; 
		if (DynamicGL_ColorTable==0) return false; 
		if (DynamicGL_ColorTableParameterfv==0) return false; 
		if (DynamicGL_ColorTableParameteriv==0) return false; 
		if (DynamicGL_CopyColorTable==0) return false; 
		if (DynamicGL_GetColorTable==0) return false; 
		if (DynamicGL_GetColorTableParameterfv==0) return false; 
		if (DynamicGL_GetColorTableParameteriv==0) return false; 
		if (DynamicGL_ColorSubTable==0) return false; 
		if (DynamicGL_CopyColorSubTable==0) return false; 
		if (DynamicGL_ConvolutionFilter1D==0) return false; 
		if (DynamicGL_ConvolutionFilter2D==0) return false; 
		if (DynamicGL_ConvolutionParameterf==0) return false; 
		if (DynamicGL_ConvolutionParameterfv==0) return false; 
		if (DynamicGL_ConvolutionParameteri==0) return false; 
		if (DynamicGL_ConvolutionParameteriv==0) return false; 
		if (DynamicGL_CopyConvolutionFilter1D==0) return false; 
		if (DynamicGL_CopyConvolutionFilter2D==0) return false; 
		if (DynamicGL_GetConvolutionFilter==0) return false; 
		if (DynamicGL_GetConvolutionParameterfv==0) return false; 
		if (DynamicGL_GetConvolutionParameteriv==0) return false; 
		if (DynamicGL_GetSeparableFilter==0) return false; 
		if (DynamicGL_SeparableFilter2D==0) return false; 
		if (DynamicGL_GetHistogram==0) return false; 
		if (DynamicGL_GetHistogramParameterfv==0) return false; 
		if (DynamicGL_GetHistogramParameteriv==0) return false; 
		if (DynamicGL_GetMinmax==0) return false; 
		if (DynamicGL_GetMinmaxParameterfv==0) return false; 
		if (DynamicGL_GetMinmaxParameteriv==0) return false; 
		if (DynamicGL_Histogram==0) return false; 
		if (DynamicGL_Minmax==0) return false; 
		if (DynamicGL_ResetHistogram==0) return false; 
		if (DynamicGL_ResetMinmax==0) return false; 
		if (DynamicGL_TexImage3D==0) return false; 
		if (DynamicGL_TexSubImage3D==0) return false; 
		if (DynamicGL_CopyTexSubImage3D==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_VERSION_1_2*/

/*SGIS_texture_edge_clamp*/
#ifdef USE_DYNAMIC_GL_SGIS_texture_edge_clamp
static bool DinamicGLFeature_SGIS_texture_edge_clamp_loaded = false; 
static void InitDinamicGLFeature_SGIS_texture_edge_clamp() {
		DinamicGLFeature_SGIS_texture_edge_clamp_loaded = true; 
}
bool DinamicGLFeature_SGIS_texture_edge_clamp_Supported() {
		if (!DinamicGLFeature_SGIS_texture_edge_clamp_loaded) {
			InitDinamicGLFeature_SGIS_texture_edge_clamp();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIS_texture_edge_clamp*/

/*SUN_slice_accum*/
#ifdef USE_DYNAMIC_GL_SUN_slice_accum
static bool DinamicGLFeature_SUN_slice_accum_loaded = false; 
static void InitDinamicGLFeature_SUN_slice_accum() {
		DinamicGLFeature_SUN_slice_accum_loaded = true; 
}
bool DinamicGLFeature_SUN_slice_accum_Supported() {
		if (!DinamicGLFeature_SUN_slice_accum_loaded) {
			InitDinamicGLFeature_SUN_slice_accum();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SUN_slice_accum*/

/*APPLE_element_array*/
#ifdef USE_DYNAMIC_GL_APPLE_element_array
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ElementPointerAPPLE)(GLenum type , const GLvoid *pointer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawElementArrayAPPLE)(GLenum mode , GLint first , GLsizei count) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawRangeElementArrayAPPLE)(GLenum mode , GLuint start , GLuint end , GLint first , GLsizei count) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiDrawElementArrayAPPLE)(GLenum mode , const GLint *first , const GLsizei *count , GLsizei primcount) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiDrawRangeElementArrayAPPLE)(GLenum mode , GLuint start , GLuint end , const GLint *first , const GLsizei *count , GLsizei primcount) = 0; }
static bool DinamicGLFeature_APPLE_element_array_loaded = false; 
static void InitDinamicGLFeature_APPLE_element_array() {
		DynamicGL_ElementPointerAPPLE = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum type , const GLvoid *pointer)>("glElementPointerAPPLE"); 
		DynamicGL_DrawElementArrayAPPLE = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , GLint first , GLsizei count)>("glDrawElementArrayAPPLE"); 
		DynamicGL_DrawRangeElementArrayAPPLE = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , GLuint start , GLuint end , GLint first , GLsizei count)>("glDrawRangeElementArrayAPPLE"); 
		DynamicGL_MultiDrawElementArrayAPPLE = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , const GLint *first , const GLsizei *count , GLsizei primcount)>("glMultiDrawElementArrayAPPLE"); 
		DynamicGL_MultiDrawRangeElementArrayAPPLE = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , GLuint start , GLuint end , const GLint *first , const GLsizei *count , GLsizei primcount)>("glMultiDrawRangeElementArrayAPPLE"); 
		DinamicGLFeature_APPLE_element_array_loaded = true; 
}
bool DinamicGLFeature_APPLE_element_array_Supported() {
		if (!DinamicGLFeature_APPLE_element_array_loaded) {
			InitDinamicGLFeature_APPLE_element_array();
		}
		if (DynamicGL_ElementPointerAPPLE==0) return false; 
		if (DynamicGL_DrawElementArrayAPPLE==0) return false; 
		if (DynamicGL_DrawRangeElementArrayAPPLE==0) return false; 
		if (DynamicGL_MultiDrawElementArrayAPPLE==0) return false; 
		if (DynamicGL_MultiDrawRangeElementArrayAPPLE==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_APPLE_element_array*/

/*EXT_blend_minmax*/
#ifdef USE_DYNAMIC_GL_EXT_blend_minmax
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendEquationEXT)(GLenum mode) = 0; }
static bool DinamicGLFeature_EXT_blend_minmax_loaded = false; 
static void InitDinamicGLFeature_EXT_blend_minmax() {
		DynamicGL_BlendEquationEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode)>("glBlendEquationEXT"); 
		DinamicGLFeature_EXT_blend_minmax_loaded = true; 
}
bool DinamicGLFeature_EXT_blend_minmax_Supported() {
		if (!DinamicGLFeature_EXT_blend_minmax_loaded) {
			InitDinamicGLFeature_EXT_blend_minmax();
		}
		if (DynamicGL_BlendEquationEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_blend_minmax*/

/*ATI_texture_float*/
#ifdef USE_DYNAMIC_GL_ATI_texture_float
static bool DinamicGLFeature_ATI_texture_float_loaded = false; 
static void InitDinamicGLFeature_ATI_texture_float() {
		DinamicGLFeature_ATI_texture_float_loaded = true; 
}
bool DinamicGLFeature_ATI_texture_float_Supported() {
		if (!DinamicGLFeature_ATI_texture_float_loaded) {
			InitDinamicGLFeature_ATI_texture_float();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_ATI_texture_float*/

/*SGIX_calligraphic_fragment*/
#ifdef USE_DYNAMIC_GL_SGIX_calligraphic_fragment
static bool DinamicGLFeature_SGIX_calligraphic_fragment_loaded = false; 
static void InitDinamicGLFeature_SGIX_calligraphic_fragment() {
		DinamicGLFeature_SGIX_calligraphic_fragment_loaded = true; 
}
bool DinamicGLFeature_SGIX_calligraphic_fragment_Supported() {
		if (!DinamicGLFeature_SGIX_calligraphic_fragment_loaded) {
			InitDinamicGLFeature_SGIX_calligraphic_fragment();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_calligraphic_fragment*/

/*NV_float_buffer*/
#ifdef USE_DYNAMIC_GL_NV_float_buffer
static bool DinamicGLFeature_NV_float_buffer_loaded = false; 
static void InitDinamicGLFeature_NV_float_buffer() {
		DinamicGLFeature_NV_float_buffer_loaded = true; 
}
bool DinamicGLFeature_NV_float_buffer_Supported() {
		if (!DinamicGLFeature_NV_float_buffer_loaded) {
			InitDinamicGLFeature_NV_float_buffer();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_float_buffer*/

/*SGIX_fragment_lighting*/
#ifdef USE_DYNAMIC_GL_SGIX_fragment_lighting
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FragmentColorMaterialSGIX)(GLenum face , GLenum mode) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FragmentLightfSGIX)(GLenum light , GLenum pname , GLfloat param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FragmentLightfvSGIX)(GLenum light , GLenum pname , const GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FragmentLightiSGIX)(GLenum light , GLenum pname , GLint param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FragmentLightivSGIX)(GLenum light , GLenum pname , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FragmentLightModelfSGIX)(GLenum pname , GLfloat param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FragmentLightModelfvSGIX)(GLenum pname , const GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FragmentLightModeliSGIX)(GLenum pname , GLint param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FragmentLightModelivSGIX)(GLenum pname , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FragmentMaterialfSGIX)(GLenum face , GLenum pname , GLfloat param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FragmentMaterialfvSGIX)(GLenum face , GLenum pname , const GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FragmentMaterialiSGIX)(GLenum face , GLenum pname , GLint param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FragmentMaterialivSGIX)(GLenum face , GLenum pname , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFragmentLightfvSGIX)(GLenum light , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFragmentLightivSGIX)(GLenum light , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFragmentMaterialfvSGIX)(GLenum face , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFragmentMaterialivSGIX)(GLenum face , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_LightEnviSGIX)(GLenum pname , GLint param) = 0; }
static bool DinamicGLFeature_SGIX_fragment_lighting_loaded = false; 
static void InitDinamicGLFeature_SGIX_fragment_lighting() {
		DynamicGL_FragmentColorMaterialSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum face , GLenum mode)>("glFragmentColorMaterialSGIX"); 
		DynamicGL_FragmentLightfSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum light , GLenum pname , GLfloat param)>("glFragmentLightfSGIX"); 
		DynamicGL_FragmentLightfvSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum light , GLenum pname , const GLfloat *params)>("glFragmentLightfvSGIX"); 
		DynamicGL_FragmentLightiSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum light , GLenum pname , GLint param)>("glFragmentLightiSGIX"); 
		DynamicGL_FragmentLightivSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum light , GLenum pname , const GLint *params)>("glFragmentLightivSGIX"); 
		DynamicGL_FragmentLightModelfSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLfloat param)>("glFragmentLightModelfSGIX"); 
		DynamicGL_FragmentLightModelfvSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , const GLfloat *params)>("glFragmentLightModelfvSGIX"); 
		DynamicGL_FragmentLightModeliSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLint param)>("glFragmentLightModeliSGIX"); 
		DynamicGL_FragmentLightModelivSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , const GLint *params)>("glFragmentLightModelivSGIX"); 
		DynamicGL_FragmentMaterialfSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum face , GLenum pname , GLfloat param)>("glFragmentMaterialfSGIX"); 
		DynamicGL_FragmentMaterialfvSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum face , GLenum pname , const GLfloat *params)>("glFragmentMaterialfvSGIX"); 
		DynamicGL_FragmentMaterialiSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum face , GLenum pname , GLint param)>("glFragmentMaterialiSGIX"); 
		DynamicGL_FragmentMaterialivSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum face , GLenum pname , const GLint *params)>("glFragmentMaterialivSGIX"); 
		DynamicGL_GetFragmentLightfvSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum light , GLenum pname , GLfloat *params)>("glGetFragmentLightfvSGIX"); 
		DynamicGL_GetFragmentLightivSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum light , GLenum pname , GLint *params)>("glGetFragmentLightivSGIX"); 
		DynamicGL_GetFragmentMaterialfvSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum face , GLenum pname , GLfloat *params)>("glGetFragmentMaterialfvSGIX"); 
		DynamicGL_GetFragmentMaterialivSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum face , GLenum pname , GLint *params)>("glGetFragmentMaterialivSGIX"); 
		DynamicGL_LightEnviSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLint param)>("glLightEnviSGIX"); 
		DinamicGLFeature_SGIX_fragment_lighting_loaded = true; 
}
bool DinamicGLFeature_SGIX_fragment_lighting_Supported() {
		if (!DinamicGLFeature_SGIX_fragment_lighting_loaded) {
			InitDinamicGLFeature_SGIX_fragment_lighting();
		}
		if (DynamicGL_FragmentColorMaterialSGIX==0) return false; 
		if (DynamicGL_FragmentLightfSGIX==0) return false; 
		if (DynamicGL_FragmentLightfvSGIX==0) return false; 
		if (DynamicGL_FragmentLightiSGIX==0) return false; 
		if (DynamicGL_FragmentLightivSGIX==0) return false; 
		if (DynamicGL_FragmentLightModelfSGIX==0) return false; 
		if (DynamicGL_FragmentLightModelfvSGIX==0) return false; 
		if (DynamicGL_FragmentLightModeliSGIX==0) return false; 
		if (DynamicGL_FragmentLightModelivSGIX==0) return false; 
		if (DynamicGL_FragmentMaterialfSGIX==0) return false; 
		if (DynamicGL_FragmentMaterialfvSGIX==0) return false; 
		if (DynamicGL_FragmentMaterialiSGIX==0) return false; 
		if (DynamicGL_FragmentMaterialivSGIX==0) return false; 
		if (DynamicGL_GetFragmentLightfvSGIX==0) return false; 
		if (DynamicGL_GetFragmentLightivSGIX==0) return false; 
		if (DynamicGL_GetFragmentMaterialfvSGIX==0) return false; 
		if (DynamicGL_GetFragmentMaterialivSGIX==0) return false; 
		if (DynamicGL_LightEnviSGIX==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_fragment_lighting*/

/*SGIX_instruments*/
#ifdef USE_DYNAMIC_GL_SGIX_instruments
extern "C" { GLint (DYNAMIC_GL_APIENTRYP DynamicGL_GetInstrumentsSGIX)() = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_InstrumentsBufferSGIX)(GLsizei size , GLint *buffer) = 0; }
extern "C" { GLint (DYNAMIC_GL_APIENTRYP DynamicGL_PollInstrumentsSGIX)(GLint *marker_p) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ReadInstrumentsSGIX)(GLint marker) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_StartInstrumentsSGIX)() = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_StopInstrumentsSGIX)(GLint marker) = 0; }
static bool DinamicGLFeature_SGIX_instruments_loaded = false; 
static void InitDinamicGLFeature_SGIX_instruments() {
		DynamicGL_GetInstrumentsSGIX = DynamicGL_LoadFunction<GLint (DYNAMIC_GL_APIENTRYP)()>("glGetInstrumentsSGIX"); 
		DynamicGL_InstrumentsBufferSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei size , GLint *buffer)>("glInstrumentsBufferSGIX"); 
		DynamicGL_PollInstrumentsSGIX = DynamicGL_LoadFunction<GLint (DYNAMIC_GL_APIENTRYP)(GLint *marker_p)>("glPollInstrumentsSGIX"); 
		DynamicGL_ReadInstrumentsSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint marker)>("glReadInstrumentsSGIX"); 
		DynamicGL_StartInstrumentsSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glStartInstrumentsSGIX"); 
		DynamicGL_StopInstrumentsSGIX = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint marker)>("glStopInstrumentsSGIX"); 
		DinamicGLFeature_SGIX_instruments_loaded = true; 
}
bool DinamicGLFeature_SGIX_instruments_Supported() {
		if (!DinamicGLFeature_SGIX_instruments_loaded) {
			InitDinamicGLFeature_SGIX_instruments();
		}
		if (DynamicGL_GetInstrumentsSGIX==0) return false; 
		if (DynamicGL_InstrumentsBufferSGIX==0) return false; 
		if (DynamicGL_PollInstrumentsSGIX==0) return false; 
		if (DynamicGL_ReadInstrumentsSGIX==0) return false; 
		if (DynamicGL_StartInstrumentsSGIX==0) return false; 
		if (DynamicGL_StopInstrumentsSGIX==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_instruments*/

/*SGIX_ycrcba*/
#ifdef USE_DYNAMIC_GL_SGIX_ycrcba
static bool DinamicGLFeature_SGIX_ycrcba_loaded = false; 
static void InitDinamicGLFeature_SGIX_ycrcba() {
		DinamicGLFeature_SGIX_ycrcba_loaded = true; 
}
bool DinamicGLFeature_SGIX_ycrcba_Supported() {
		if (!DinamicGLFeature_SGIX_ycrcba_loaded) {
			InitDinamicGLFeature_SGIX_ycrcba();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_ycrcba*/

/*SGIX_texture_coordinate_clamp*/
#ifdef USE_DYNAMIC_GL_SGIX_texture_coordinate_clamp
static bool DinamicGLFeature_SGIX_texture_coordinate_clamp_loaded = false; 
static void InitDinamicGLFeature_SGIX_texture_coordinate_clamp() {
		DinamicGLFeature_SGIX_texture_coordinate_clamp_loaded = true; 
}
bool DinamicGLFeature_SGIX_texture_coordinate_clamp_Supported() {
		if (!DinamicGLFeature_SGIX_texture_coordinate_clamp_loaded) {
			InitDinamicGLFeature_SGIX_texture_coordinate_clamp();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_texture_coordinate_clamp*/

/*S3_s3tc*/
#ifdef USE_DYNAMIC_GL_S3_s3tc
static bool DinamicGLFeature_S3_s3tc_loaded = false; 
static void InitDinamicGLFeature_S3_s3tc() {
		DinamicGLFeature_S3_s3tc_loaded = true; 
}
bool DinamicGLFeature_S3_s3tc_Supported() {
		if (!DinamicGLFeature_S3_s3tc_loaded) {
			InitDinamicGLFeature_S3_s3tc();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_S3_s3tc*/

/*EXT_422_pixels*/
#ifdef USE_DYNAMIC_GL_EXT_422_pixels
static bool DinamicGLFeature_EXT_422_pixels_loaded = false; 
static void InitDinamicGLFeature_EXT_422_pixels() {
		DinamicGLFeature_EXT_422_pixels_loaded = true; 
}
bool DinamicGLFeature_EXT_422_pixels_Supported() {
		if (!DinamicGLFeature_EXT_422_pixels_loaded) {
			InitDinamicGLFeature_EXT_422_pixels();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_422_pixels*/

/*NV_transform_feedback*/
#ifdef USE_DYNAMIC_GL_NV_transform_feedback
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BeginTransformFeedbackNV)(GLenum primitiveMode) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EndTransformFeedbackNV)() = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TransformFeedbackAttribsNV)(GLuint count , const GLint *attribs , GLenum bufferMode) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BindBufferRangeNV)(GLenum target , GLuint index , GLuint buffer , GLintptr offset , GLsizeiptr size) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BindBufferOffsetNV)(GLenum target , GLuint index , GLuint buffer , GLintptr offset) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BindBufferBaseNV)(GLenum target , GLuint index , GLuint buffer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TransformFeedbackVaryingsNV)(GLuint program , GLsizei count , const GLint *locations , GLenum bufferMode) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ActiveVaryingNV)(GLuint program , const GLchar *name) = 0; }
extern "C" { GLint (DYNAMIC_GL_APIENTRYP DynamicGL_GetVaryingLocationNV)(GLuint program , const GLchar *name) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetActiveVaryingNV)(GLuint program , GLuint index , GLsizei bufSize , GLsizei *length , GLsizei *size , GLenum *type , GLchar *name) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTransformFeedbackVaryingNV)(GLuint program , GLuint index , GLint *location) = 0; }
static bool DinamicGLFeature_NV_transform_feedback_loaded = false; 
static void InitDinamicGLFeature_NV_transform_feedback() {
		DynamicGL_BeginTransformFeedbackNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum primitiveMode)>("glBeginTransformFeedbackNV"); 
		DynamicGL_EndTransformFeedbackNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glEndTransformFeedbackNV"); 
		DynamicGL_TransformFeedbackAttribsNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint count , const GLint *attribs , GLenum bufferMode)>("glTransformFeedbackAttribsNV"); 
		DynamicGL_BindBufferRangeNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLuint buffer , GLintptr offset , GLsizeiptr size)>("glBindBufferRangeNV"); 
		DynamicGL_BindBufferOffsetNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLuint buffer , GLintptr offset)>("glBindBufferOffsetNV"); 
		DynamicGL_BindBufferBaseNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint index , GLuint buffer)>("glBindBufferBaseNV"); 
		DynamicGL_TransformFeedbackVaryingsNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLsizei count , const GLint *locations , GLenum bufferMode)>("glTransformFeedbackVaryingsNV"); 
		DynamicGL_ActiveVaryingNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , const GLchar *name)>("glActiveVaryingNV"); 
		DynamicGL_GetVaryingLocationNV = DynamicGL_LoadFunction<GLint (DYNAMIC_GL_APIENTRYP)(GLuint program , const GLchar *name)>("glGetVaryingLocationNV"); 
		DynamicGL_GetActiveVaryingNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLuint index , GLsizei bufSize , GLsizei *length , GLsizei *size , GLenum *type , GLchar *name)>("glGetActiveVaryingNV"); 
		DynamicGL_GetTransformFeedbackVaryingNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLuint index , GLint *location)>("glGetTransformFeedbackVaryingNV"); 
		DinamicGLFeature_NV_transform_feedback_loaded = true; 
}
bool DinamicGLFeature_NV_transform_feedback_Supported() {
		if (!DinamicGLFeature_NV_transform_feedback_loaded) {
			InitDinamicGLFeature_NV_transform_feedback();
		}
		if (DynamicGL_BeginTransformFeedbackNV==0) return false; 
		if (DynamicGL_EndTransformFeedbackNV==0) return false; 
		if (DynamicGL_TransformFeedbackAttribsNV==0) return false; 
		if (DynamicGL_BindBufferRangeNV==0) return false; 
		if (DynamicGL_BindBufferOffsetNV==0) return false; 
		if (DynamicGL_BindBufferBaseNV==0) return false; 
		if (DynamicGL_TransformFeedbackVaryingsNV==0) return false; 
		if (DynamicGL_ActiveVaryingNV==0) return false; 
		if (DynamicGL_GetVaryingLocationNV==0) return false; 
		if (DynamicGL_GetActiveVaryingNV==0) return false; 
		if (DynamicGL_GetTransformFeedbackVaryingNV==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_transform_feedback*/

/*SUN_triangle_list*/
#ifdef USE_DYNAMIC_GL_SUN_triangle_list
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuiSUN)(GLuint code) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeusSUN)(GLushort code) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeubSUN)(GLubyte code) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuivSUN)(const GLuint *code) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeusvSUN)(const GLushort *code) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeubvSUN)(const GLubyte *code) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodePointerSUN)(GLenum type , GLsizei stride , const GLvoid* *pointer) = 0; }
static bool DinamicGLFeature_SUN_triangle_list_loaded = false; 
static void InitDinamicGLFeature_SUN_triangle_list() {
		DynamicGL_ReplacementCodeuiSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint code)>("glReplacementCodeuiSUN"); 
		DynamicGL_ReplacementCodeusSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLushort code)>("glReplacementCodeusSUN"); 
		DynamicGL_ReplacementCodeubSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLubyte code)>("glReplacementCodeubSUN"); 
		DynamicGL_ReplacementCodeuivSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLuint *code)>("glReplacementCodeuivSUN"); 
		DynamicGL_ReplacementCodeusvSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLushort *code)>("glReplacementCodeusvSUN"); 
		DynamicGL_ReplacementCodeubvSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLubyte *code)>("glReplacementCodeubvSUN"); 
		DynamicGL_ReplacementCodePointerSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum type , GLsizei stride , const GLvoid* *pointer)>("glReplacementCodePointerSUN"); 
		DinamicGLFeature_SUN_triangle_list_loaded = true; 
}
bool DinamicGLFeature_SUN_triangle_list_Supported() {
		if (!DinamicGLFeature_SUN_triangle_list_loaded) {
			InitDinamicGLFeature_SUN_triangle_list();
		}
		if (DynamicGL_ReplacementCodeuiSUN==0) return false; 
		if (DynamicGL_ReplacementCodeusSUN==0) return false; 
		if (DynamicGL_ReplacementCodeubSUN==0) return false; 
		if (DynamicGL_ReplacementCodeuivSUN==0) return false; 
		if (DynamicGL_ReplacementCodeusvSUN==0) return false; 
		if (DynamicGL_ReplacementCodeubvSUN==0) return false; 
		if (DynamicGL_ReplacementCodePointerSUN==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_SUN_triangle_list*/

/*SGIX_clipmap*/
#ifdef USE_DYNAMIC_GL_SGIX_clipmap
static bool DinamicGLFeature_SGIX_clipmap_loaded = false; 
static void InitDinamicGLFeature_SGIX_clipmap() {
		DinamicGLFeature_SGIX_clipmap_loaded = true; 
}
bool DinamicGLFeature_SGIX_clipmap_Supported() {
		if (!DinamicGLFeature_SGIX_clipmap_loaded) {
			InitDinamicGLFeature_SGIX_clipmap();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_clipmap*/

/*NV_register_combiners2*/
#ifdef USE_DYNAMIC_GL_NV_register_combiners2
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CombinerStageParameterfvNV)(GLenum stage , GLenum pname , const GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetCombinerStageParameterfvNV)(GLenum stage , GLenum pname , GLfloat *params) = 0; }
static bool DinamicGLFeature_NV_register_combiners2_loaded = false; 
static void InitDinamicGLFeature_NV_register_combiners2() {
		DynamicGL_CombinerStageParameterfvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stage , GLenum pname , const GLfloat *params)>("glCombinerStageParameterfvNV"); 
		DynamicGL_GetCombinerStageParameterfvNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum stage , GLenum pname , GLfloat *params)>("glGetCombinerStageParameterfvNV"); 
		DinamicGLFeature_NV_register_combiners2_loaded = true; 
}
bool DinamicGLFeature_NV_register_combiners2_Supported() {
		if (!DinamicGLFeature_NV_register_combiners2_loaded) {
			InitDinamicGLFeature_NV_register_combiners2();
		}
		if (DynamicGL_CombinerStageParameterfvNV==0) return false; 
		if (DynamicGL_GetCombinerStageParameterfvNV==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_register_combiners2*/

/*EXT_clip_volume_hint*/
#ifdef USE_DYNAMIC_GL_EXT_clip_volume_hint
static bool DinamicGLFeature_EXT_clip_volume_hint_loaded = false; 
static void InitDinamicGLFeature_EXT_clip_volume_hint() {
		DinamicGLFeature_EXT_clip_volume_hint_loaded = true; 
}
bool DinamicGLFeature_EXT_clip_volume_hint_Supported() {
		if (!DinamicGLFeature_EXT_clip_volume_hint_loaded) {
			InitDinamicGLFeature_EXT_clip_volume_hint();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_clip_volume_hint*/

/*SGIS_point_parameters*/
#ifdef USE_DYNAMIC_GL_SGIS_point_parameters
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameterfSGIS)(GLenum pname , GLfloat param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameterfvSGIS)(GLenum pname , const GLfloat *params) = 0; }
static bool DinamicGLFeature_SGIS_point_parameters_loaded = false; 
static void InitDinamicGLFeature_SGIS_point_parameters() {
		DynamicGL_PointParameterfSGIS = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLfloat param)>("glPointParameterfSGIS"); 
		DynamicGL_PointParameterfvSGIS = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , const GLfloat *params)>("glPointParameterfvSGIS"); 
		DinamicGLFeature_SGIS_point_parameters_loaded = true; 
}
bool DinamicGLFeature_SGIS_point_parameters_Supported() {
		if (!DinamicGLFeature_SGIS_point_parameters_loaded) {
			InitDinamicGLFeature_SGIS_point_parameters();
		}
		if (DynamicGL_PointParameterfSGIS==0) return false; 
		if (DynamicGL_PointParameterfvSGIS==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIS_point_parameters*/

/*APPLE_transform_hint*/
#ifdef USE_DYNAMIC_GL_APPLE_transform_hint
static bool DinamicGLFeature_APPLE_transform_hint_loaded = false; 
static void InitDinamicGLFeature_APPLE_transform_hint() {
		DinamicGLFeature_APPLE_transform_hint_loaded = true; 
}
bool DinamicGLFeature_APPLE_transform_hint_Supported() {
		if (!DinamicGLFeature_APPLE_transform_hint_loaded) {
			InitDinamicGLFeature_APPLE_transform_hint();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_APPLE_transform_hint*/

/*NV_fragment_program2*/
#ifdef USE_DYNAMIC_GL_NV_fragment_program2
static bool DinamicGLFeature_NV_fragment_program2_loaded = false; 
static void InitDinamicGLFeature_NV_fragment_program2() {
		DinamicGLFeature_NV_fragment_program2_loaded = true; 
}
bool DinamicGLFeature_NV_fragment_program2_Supported() {
		if (!DinamicGLFeature_NV_fragment_program2_loaded) {
			InitDinamicGLFeature_NV_fragment_program2();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_fragment_program2*/

/*NV_texture_rectangle*/
#ifdef USE_DYNAMIC_GL_NV_texture_rectangle
static bool DinamicGLFeature_NV_texture_rectangle_loaded = false; 
static void InitDinamicGLFeature_NV_texture_rectangle() {
		DinamicGLFeature_NV_texture_rectangle_loaded = true; 
}
bool DinamicGLFeature_NV_texture_rectangle_Supported() {
		if (!DinamicGLFeature_NV_texture_rectangle_loaded) {
			InitDinamicGLFeature_NV_texture_rectangle();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_texture_rectangle*/

/*SGI_depth_pass_instrument*/
#ifdef USE_DYNAMIC_GL_SGI_depth_pass_instrument
static bool DinamicGLFeature_SGI_depth_pass_instrument_loaded = false; 
static void InitDinamicGLFeature_SGI_depth_pass_instrument() {
		DinamicGLFeature_SGI_depth_pass_instrument_loaded = true; 
}
bool DinamicGLFeature_SGI_depth_pass_instrument_Supported() {
		if (!DinamicGLFeature_SGI_depth_pass_instrument_loaded) {
			InitDinamicGLFeature_SGI_depth_pass_instrument();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGI_depth_pass_instrument*/

/*EXT_rescale_normal*/
#ifdef USE_DYNAMIC_GL_EXT_rescale_normal
static bool DinamicGLFeature_EXT_rescale_normal_loaded = false; 
static void InitDinamicGLFeature_EXT_rescale_normal() {
		DinamicGLFeature_EXT_rescale_normal_loaded = true; 
}
bool DinamicGLFeature_EXT_rescale_normal_Supported() {
		if (!DinamicGLFeature_EXT_rescale_normal_loaded) {
			InitDinamicGLFeature_EXT_rescale_normal();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_rescale_normal*/

/*ARB_pixel_buffer_object*/
#ifdef USE_DYNAMIC_GL_ARB_pixel_buffer_object
static bool DinamicGLFeature_ARB_pixel_buffer_object_loaded = false; 
static void InitDinamicGLFeature_ARB_pixel_buffer_object() {
		DinamicGLFeature_ARB_pixel_buffer_object_loaded = true; 
}
bool DinamicGLFeature_ARB_pixel_buffer_object_Supported() {
		if (!DinamicGLFeature_ARB_pixel_buffer_object_loaded) {
			InitDinamicGLFeature_ARB_pixel_buffer_object();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_pixel_buffer_object*/

/*EXT_texture3D*/
#ifdef USE_DYNAMIC_GL_EXT_texture3D
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexImage3DEXT)(GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLsizei depth , GLint border , GLenum format , GLenum type , const GLvoid *pixels) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexSubImage3DEXT)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLsizei width , GLsizei height , GLsizei depth , GLenum format , GLenum type , const GLvoid *pixels) = 0; }
static bool DinamicGLFeature_EXT_texture3D_loaded = false; 
static void InitDinamicGLFeature_EXT_texture3D() {
		DynamicGL_TexImage3DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLsizei depth , GLint border , GLenum format , GLenum type , const GLvoid *pixels)>("glTexImage3DEXT"); 
		DynamicGL_TexSubImage3DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLsizei width , GLsizei height , GLsizei depth , GLenum format , GLenum type , const GLvoid *pixels)>("glTexSubImage3DEXT"); 
		DinamicGLFeature_EXT_texture3D_loaded = true; 
}
bool DinamicGLFeature_EXT_texture3D_Supported() {
		if (!DinamicGLFeature_EXT_texture3D_loaded) {
			InitDinamicGLFeature_EXT_texture3D();
		}
		if (DynamicGL_TexImage3DEXT==0) return false; 
		if (DynamicGL_TexSubImage3DEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_texture3D*/

/*EXT_texture_lod_bias*/
#ifdef USE_DYNAMIC_GL_EXT_texture_lod_bias
static bool DinamicGLFeature_EXT_texture_lod_bias_loaded = false; 
static void InitDinamicGLFeature_EXT_texture_lod_bias() {
		DinamicGLFeature_EXT_texture_lod_bias_loaded = true; 
}
bool DinamicGLFeature_EXT_texture_lod_bias_Supported() {
		if (!DinamicGLFeature_EXT_texture_lod_bias_loaded) {
			InitDinamicGLFeature_EXT_texture_lod_bias();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_texture_lod_bias*/

/*ATI_separate_stencil*/
#ifdef USE_DYNAMIC_GL_ATI_separate_stencil
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_StencilOpSeparateATI)(GLenum face , GLenum sfail , GLenum dpfail , GLenum dppass) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_StencilFuncSeparateATI)(GLenum frontfunc , GLenum backfunc , GLint ref , GLuint mask) = 0; }
static bool DinamicGLFeature_ATI_separate_stencil_loaded = false; 
static void InitDinamicGLFeature_ATI_separate_stencil() {
		DynamicGL_StencilOpSeparateATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum face , GLenum sfail , GLenum dpfail , GLenum dppass)>("glStencilOpSeparateATI"); 
		DynamicGL_StencilFuncSeparateATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum frontfunc , GLenum backfunc , GLint ref , GLuint mask)>("glStencilFuncSeparateATI"); 
		DinamicGLFeature_ATI_separate_stencil_loaded = true; 
}
bool DinamicGLFeature_ATI_separate_stencil_Supported() {
		if (!DinamicGLFeature_ATI_separate_stencil_loaded) {
			InitDinamicGLFeature_ATI_separate_stencil();
		}
		if (DynamicGL_StencilOpSeparateATI==0) return false; 
		if (DynamicGL_StencilFuncSeparateATI==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_ATI_separate_stencil*/

/*APPLE_vertex_array_range*/
#ifdef USE_DYNAMIC_GL_APPLE_vertex_array_range
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexArrayRangeAPPLE)(GLsizei length , GLvoid *pointer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FlushVertexArrayRangeAPPLE)(GLsizei length , GLvoid *pointer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexArrayParameteriAPPLE)(GLenum pname , GLint param) = 0; }
static bool DinamicGLFeature_APPLE_vertex_array_range_loaded = false; 
static void InitDinamicGLFeature_APPLE_vertex_array_range() {
		DynamicGL_VertexArrayRangeAPPLE = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei length , GLvoid *pointer)>("glVertexArrayRangeAPPLE"); 
		DynamicGL_FlushVertexArrayRangeAPPLE = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei length , GLvoid *pointer)>("glFlushVertexArrayRangeAPPLE"); 
		DynamicGL_VertexArrayParameteriAPPLE = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLint param)>("glVertexArrayParameteriAPPLE"); 
		DinamicGLFeature_APPLE_vertex_array_range_loaded = true; 
}
bool DinamicGLFeature_APPLE_vertex_array_range_Supported() {
		if (!DinamicGLFeature_APPLE_vertex_array_range_loaded) {
			InitDinamicGLFeature_APPLE_vertex_array_range();
		}
		if (DynamicGL_VertexArrayRangeAPPLE==0) return false; 
		if (DynamicGL_FlushVertexArrayRangeAPPLE==0) return false; 
		if (DynamicGL_VertexArrayParameteriAPPLE==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_APPLE_vertex_array_range*/

/*NV_conditional_render*/
#ifdef USE_DYNAMIC_GL_NV_conditional_render
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BeginConditionalRenderNV)(GLuint id , GLenum mode) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EndConditionalRenderNV)() = 0; }
static bool DinamicGLFeature_NV_conditional_render_loaded = false; 
static void InitDinamicGLFeature_NV_conditional_render() {
		DynamicGL_BeginConditionalRenderNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , GLenum mode)>("glBeginConditionalRenderNV"); 
		DynamicGL_EndConditionalRenderNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glEndConditionalRenderNV"); 
		DinamicGLFeature_NV_conditional_render_loaded = true; 
}
bool DinamicGLFeature_NV_conditional_render_Supported() {
		if (!DinamicGLFeature_NV_conditional_render_loaded) {
			InitDinamicGLFeature_NV_conditional_render();
		}
		if (DynamicGL_BeginConditionalRenderNV==0) return false; 
		if (DynamicGL_EndConditionalRenderNV==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_conditional_render*/

/*SGIS_point_line_texgen*/
#ifdef USE_DYNAMIC_GL_SGIS_point_line_texgen
static bool DinamicGLFeature_SGIS_point_line_texgen_loaded = false; 
static void InitDinamicGLFeature_SGIS_point_line_texgen() {
		DinamicGLFeature_SGIS_point_line_texgen_loaded = true; 
}
bool DinamicGLFeature_SGIS_point_line_texgen_Supported() {
		if (!DinamicGLFeature_SGIS_point_line_texgen_loaded) {
			InitDinamicGLFeature_SGIS_point_line_texgen();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIS_point_line_texgen*/

/*EXT_fog_coord*/
#ifdef USE_DYNAMIC_GL_EXT_fog_coord
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FogCoordfEXT)(GLfloat coord) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FogCoordfvEXT)(const GLfloat *coord) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FogCoorddEXT)(GLdouble coord) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FogCoorddvEXT)(const GLdouble *coord) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FogCoordPointerEXT)(GLenum type , GLsizei stride , const GLvoid *pointer) = 0; }
static bool DinamicGLFeature_EXT_fog_coord_loaded = false; 
static void InitDinamicGLFeature_EXT_fog_coord() {
		DynamicGL_FogCoordfEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat coord)>("glFogCoordfEXT"); 
		DynamicGL_FogCoordfvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *coord)>("glFogCoordfvEXT"); 
		DynamicGL_FogCoorddEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble coord)>("glFogCoorddEXT"); 
		DynamicGL_FogCoorddvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *coord)>("glFogCoorddvEXT"); 
		DynamicGL_FogCoordPointerEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum type , GLsizei stride , const GLvoid *pointer)>("glFogCoordPointerEXT"); 
		DinamicGLFeature_EXT_fog_coord_loaded = true; 
}
bool DinamicGLFeature_EXT_fog_coord_Supported() {
		if (!DinamicGLFeature_EXT_fog_coord_loaded) {
			InitDinamicGLFeature_EXT_fog_coord();
		}
		if (DynamicGL_FogCoordfEXT==0) return false; 
		if (DynamicGL_FogCoordfvEXT==0) return false; 
		if (DynamicGL_FogCoorddEXT==0) return false; 
		if (DynamicGL_FogCoorddvEXT==0) return false; 
		if (DynamicGL_FogCoordPointerEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_fog_coord*/

/*VERSION_1_4*/
#ifdef USE_DYNAMIC_GL_VERSION_1_4
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendFuncSeparate)(GLenum sfactorRGB , GLenum dfactorRGB , GLenum sfactorAlpha , GLenum dfactorAlpha) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FogCoordf)(GLfloat coord) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FogCoordfv)(const GLfloat *coord) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FogCoordd)(GLdouble coord) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FogCoorddv)(const GLdouble *coord) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FogCoordPointer)(GLenum type , GLsizei stride , const GLvoid *pointer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiDrawArrays)(GLenum mode , GLint *first , GLsizei *count , GLsizei primcount) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiDrawElements)(GLenum mode , const GLsizei *count , GLenum type , const GLvoid* *indices , GLsizei primcount) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameterf)(GLenum pname , GLfloat param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameterfv)(GLenum pname , const GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameteri)(GLenum pname , GLint param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameteriv)(GLenum pname , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3b)(GLbyte red , GLbyte green , GLbyte blue) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3bv)(const GLbyte *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3d)(GLdouble red , GLdouble green , GLdouble blue) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3dv)(const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3f)(GLfloat red , GLfloat green , GLfloat blue) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3fv)(const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3i)(GLint red , GLint green , GLint blue) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3iv)(const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3s)(GLshort red , GLshort green , GLshort blue) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3sv)(const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3ub)(GLubyte red , GLubyte green , GLubyte blue) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3ubv)(const GLubyte *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3ui)(GLuint red , GLuint green , GLuint blue) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3uiv)(const GLuint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3us)(GLushort red , GLushort green , GLushort blue) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3usv)(const GLushort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColorPointer)(GLint size , GLenum type , GLsizei stride , const GLvoid *pointer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2d)(GLdouble x , GLdouble y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2dv)(const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2f)(GLfloat x , GLfloat y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2fv)(const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2i)(GLint x , GLint y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2iv)(const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2s)(GLshort x , GLshort y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2sv)(const GLshort *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3d)(GLdouble x , GLdouble y , GLdouble z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3dv)(const GLdouble *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3f)(GLfloat x , GLfloat y , GLfloat z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3fv)(const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3i)(GLint x , GLint y , GLint z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3iv)(const GLint *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3s)(GLshort x , GLshort y , GLshort z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3sv)(const GLshort *v) = 0; }
static bool DinamicGLFeature_VERSION_1_4_loaded = false; 
static void InitDinamicGLFeature_VERSION_1_4() {
		DynamicGL_BlendFuncSeparate = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum sfactorRGB , GLenum dfactorRGB , GLenum sfactorAlpha , GLenum dfactorAlpha)>("glBlendFuncSeparate"); 
		DynamicGL_FogCoordf = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat coord)>("glFogCoordf"); 
		DynamicGL_FogCoordfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *coord)>("glFogCoordfv"); 
		DynamicGL_FogCoordd = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble coord)>("glFogCoordd"); 
		DynamicGL_FogCoorddv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *coord)>("glFogCoorddv"); 
		DynamicGL_FogCoordPointer = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum type , GLsizei stride , const GLvoid *pointer)>("glFogCoordPointer"); 
		DynamicGL_MultiDrawArrays = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , GLint *first , GLsizei *count , GLsizei primcount)>("glMultiDrawArrays"); 
		DynamicGL_MultiDrawElements = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , const GLsizei *count , GLenum type , const GLvoid* *indices , GLsizei primcount)>("glMultiDrawElements"); 
		DynamicGL_PointParameterf = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLfloat param)>("glPointParameterf"); 
		DynamicGL_PointParameterfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , const GLfloat *params)>("glPointParameterfv"); 
		DynamicGL_PointParameteri = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLint param)>("glPointParameteri"); 
		DynamicGL_PointParameteriv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , const GLint *params)>("glPointParameteriv"); 
		DynamicGL_SecondaryColor3b = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLbyte red , GLbyte green , GLbyte blue)>("glSecondaryColor3b"); 
		DynamicGL_SecondaryColor3bv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLbyte *v)>("glSecondaryColor3bv"); 
		DynamicGL_SecondaryColor3d = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble red , GLdouble green , GLdouble blue)>("glSecondaryColor3d"); 
		DynamicGL_SecondaryColor3dv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *v)>("glSecondaryColor3dv"); 
		DynamicGL_SecondaryColor3f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat red , GLfloat green , GLfloat blue)>("glSecondaryColor3f"); 
		DynamicGL_SecondaryColor3fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *v)>("glSecondaryColor3fv"); 
		DynamicGL_SecondaryColor3i = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint red , GLint green , GLint blue)>("glSecondaryColor3i"); 
		DynamicGL_SecondaryColor3iv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLint *v)>("glSecondaryColor3iv"); 
		DynamicGL_SecondaryColor3s = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLshort red , GLshort green , GLshort blue)>("glSecondaryColor3s"); 
		DynamicGL_SecondaryColor3sv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLshort *v)>("glSecondaryColor3sv"); 
		DynamicGL_SecondaryColor3ub = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLubyte red , GLubyte green , GLubyte blue)>("glSecondaryColor3ub"); 
		DynamicGL_SecondaryColor3ubv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLubyte *v)>("glSecondaryColor3ubv"); 
		DynamicGL_SecondaryColor3ui = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint red , GLuint green , GLuint blue)>("glSecondaryColor3ui"); 
		DynamicGL_SecondaryColor3uiv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLuint *v)>("glSecondaryColor3uiv"); 
		DynamicGL_SecondaryColor3us = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLushort red , GLushort green , GLushort blue)>("glSecondaryColor3us"); 
		DynamicGL_SecondaryColor3usv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLushort *v)>("glSecondaryColor3usv"); 
		DynamicGL_SecondaryColorPointer = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint size , GLenum type , GLsizei stride , const GLvoid *pointer)>("glSecondaryColorPointer"); 
		DynamicGL_WindowPos2d = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble x , GLdouble y)>("glWindowPos2d"); 
		DynamicGL_WindowPos2dv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *v)>("glWindowPos2dv"); 
		DynamicGL_WindowPos2f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat x , GLfloat y)>("glWindowPos2f"); 
		DynamicGL_WindowPos2fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *v)>("glWindowPos2fv"); 
		DynamicGL_WindowPos2i = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint x , GLint y)>("glWindowPos2i"); 
		DynamicGL_WindowPos2iv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLint *v)>("glWindowPos2iv"); 
		DynamicGL_WindowPos2s = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLshort x , GLshort y)>("glWindowPos2s"); 
		DynamicGL_WindowPos2sv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLshort *v)>("glWindowPos2sv"); 
		DynamicGL_WindowPos3d = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLdouble x , GLdouble y , GLdouble z)>("glWindowPos3d"); 
		DynamicGL_WindowPos3dv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLdouble *v)>("glWindowPos3dv"); 
		DynamicGL_WindowPos3f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat x , GLfloat y , GLfloat z)>("glWindowPos3f"); 
		DynamicGL_WindowPos3fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *v)>("glWindowPos3fv"); 
		DynamicGL_WindowPos3i = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint x , GLint y , GLint z)>("glWindowPos3i"); 
		DynamicGL_WindowPos3iv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLint *v)>("glWindowPos3iv"); 
		DynamicGL_WindowPos3s = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLshort x , GLshort y , GLshort z)>("glWindowPos3s"); 
		DynamicGL_WindowPos3sv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLshort *v)>("glWindowPos3sv"); 
		DinamicGLFeature_VERSION_1_4_loaded = true; 
}
bool DinamicGLFeature_VERSION_1_4_Supported() {
		if (!DinamicGLFeature_VERSION_1_4_loaded) {
			InitDinamicGLFeature_VERSION_1_4();
		}
		if (DynamicGL_BlendFuncSeparate==0) return false; 
		if (DynamicGL_FogCoordf==0) return false; 
		if (DynamicGL_FogCoordfv==0) return false; 
		if (DynamicGL_FogCoordd==0) return false; 
		if (DynamicGL_FogCoorddv==0) return false; 
		if (DynamicGL_FogCoordPointer==0) return false; 
		if (DynamicGL_MultiDrawArrays==0) return false; 
		if (DynamicGL_MultiDrawElements==0) return false; 
		if (DynamicGL_PointParameterf==0) return false; 
		if (DynamicGL_PointParameterfv==0) return false; 
		if (DynamicGL_PointParameteri==0) return false; 
		if (DynamicGL_PointParameteriv==0) return false; 
		if (DynamicGL_SecondaryColor3b==0) return false; 
		if (DynamicGL_SecondaryColor3bv==0) return false; 
		if (DynamicGL_SecondaryColor3d==0) return false; 
		if (DynamicGL_SecondaryColor3dv==0) return false; 
		if (DynamicGL_SecondaryColor3f==0) return false; 
		if (DynamicGL_SecondaryColor3fv==0) return false; 
		if (DynamicGL_SecondaryColor3i==0) return false; 
		if (DynamicGL_SecondaryColor3iv==0) return false; 
		if (DynamicGL_SecondaryColor3s==0) return false; 
		if (DynamicGL_SecondaryColor3sv==0) return false; 
		if (DynamicGL_SecondaryColor3ub==0) return false; 
		if (DynamicGL_SecondaryColor3ubv==0) return false; 
		if (DynamicGL_SecondaryColor3ui==0) return false; 
		if (DynamicGL_SecondaryColor3uiv==0) return false; 
		if (DynamicGL_SecondaryColor3us==0) return false; 
		if (DynamicGL_SecondaryColor3usv==0) return false; 
		if (DynamicGL_SecondaryColorPointer==0) return false; 
		if (DynamicGL_WindowPos2d==0) return false; 
		if (DynamicGL_WindowPos2dv==0) return false; 
		if (DynamicGL_WindowPos2f==0) return false; 
		if (DynamicGL_WindowPos2fv==0) return false; 
		if (DynamicGL_WindowPos2i==0) return false; 
		if (DynamicGL_WindowPos2iv==0) return false; 
		if (DynamicGL_WindowPos2s==0) return false; 
		if (DynamicGL_WindowPos2sv==0) return false; 
		if (DynamicGL_WindowPos3d==0) return false; 
		if (DynamicGL_WindowPos3dv==0) return false; 
		if (DynamicGL_WindowPos3f==0) return false; 
		if (DynamicGL_WindowPos3fv==0) return false; 
		if (DynamicGL_WindowPos3i==0) return false; 
		if (DynamicGL_WindowPos3iv==0) return false; 
		if (DynamicGL_WindowPos3s==0) return false; 
		if (DynamicGL_WindowPos3sv==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_VERSION_1_4*/

/*ARB_vertex_buffer_object*/
#ifdef USE_DYNAMIC_GL_ARB_vertex_buffer_object
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BindBufferARB)(GLenum target , GLuint buffer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteBuffersARB)(GLsizei n , const GLuint *buffers) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GenBuffersARB)(GLsizei n , GLuint *buffers) = 0; }
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsBufferARB)(GLuint buffer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BufferDataARB)(GLenum target , GLsizeiptrARB size , const GLvoid *data , GLenum usage) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BufferSubDataARB)(GLenum target , GLintptrARB offset , GLsizeiptrARB size , const GLvoid *data) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetBufferSubDataARB)(GLenum target , GLintptrARB offset , GLsizeiptrARB size , GLvoid *data) = 0; }
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_UnmapBufferARB)(GLenum target) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetBufferParameterivARB)(GLenum target , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetBufferPointervARB)(GLenum target , GLenum pname , GLvoid* *params) = 0; }
static bool DinamicGLFeature_ARB_vertex_buffer_object_loaded = false; 
static void InitDinamicGLFeature_ARB_vertex_buffer_object() {
		DynamicGL_BindBufferARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint buffer)>("glBindBufferARB"); 
		DynamicGL_DeleteBuffersARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , const GLuint *buffers)>("glDeleteBuffersARB"); 
		DynamicGL_GenBuffersARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , GLuint *buffers)>("glGenBuffersARB"); 
		DynamicGL_IsBufferARB = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLuint buffer)>("glIsBufferARB"); 
		DynamicGL_BufferDataARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLsizeiptrARB size , const GLvoid *data , GLenum usage)>("glBufferDataARB"); 
		DynamicGL_BufferSubDataARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLintptrARB offset , GLsizeiptrARB size , const GLvoid *data)>("glBufferSubDataARB"); 
		DynamicGL_GetBufferSubDataARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLintptrARB offset , GLsizeiptrARB size , GLvoid *data)>("glGetBufferSubDataARB"); 
		DynamicGL_UnmapBufferARB = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLenum target)>("glUnmapBufferARB"); 
		DynamicGL_GetBufferParameterivARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint *params)>("glGetBufferParameterivARB"); 
		DynamicGL_GetBufferPointervARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLvoid* *params)>("glGetBufferPointervARB"); 
		DinamicGLFeature_ARB_vertex_buffer_object_loaded = true; 
}
bool DinamicGLFeature_ARB_vertex_buffer_object_Supported() {
		if (!DinamicGLFeature_ARB_vertex_buffer_object_loaded) {
			InitDinamicGLFeature_ARB_vertex_buffer_object();
		}
		if (DynamicGL_BindBufferARB==0) return false; 
		if (DynamicGL_DeleteBuffersARB==0) return false; 
		if (DynamicGL_GenBuffersARB==0) return false; 
		if (DynamicGL_IsBufferARB==0) return false; 
		if (DynamicGL_BufferDataARB==0) return false; 
		if (DynamicGL_BufferSubDataARB==0) return false; 
		if (DynamicGL_GetBufferSubDataARB==0) return false; 
		if (DynamicGL_UnmapBufferARB==0) return false; 
		if (DynamicGL_GetBufferParameterivARB==0) return false; 
		if (DynamicGL_GetBufferPointervARB==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_vertex_buffer_object*/

/*APPLE_specular_vector*/
#ifdef USE_DYNAMIC_GL_APPLE_specular_vector
static bool DinamicGLFeature_APPLE_specular_vector_loaded = false; 
static void InitDinamicGLFeature_APPLE_specular_vector() {
		DinamicGLFeature_APPLE_specular_vector_loaded = true; 
}
bool DinamicGLFeature_APPLE_specular_vector_Supported() {
		if (!DinamicGLFeature_APPLE_specular_vector_loaded) {
			InitDinamicGLFeature_APPLE_specular_vector();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_APPLE_specular_vector*/

/*NV_copy_depth_to_color*/
#ifdef USE_DYNAMIC_GL_NV_copy_depth_to_color
static bool DinamicGLFeature_NV_copy_depth_to_color_loaded = false; 
static void InitDinamicGLFeature_NV_copy_depth_to_color() {
		DinamicGLFeature_NV_copy_depth_to_color_loaded = true; 
}
bool DinamicGLFeature_NV_copy_depth_to_color_Supported() {
		if (!DinamicGLFeature_NV_copy_depth_to_color_loaded) {
			InitDinamicGLFeature_NV_copy_depth_to_color();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_copy_depth_to_color*/

/*ARB_texture_cube_map*/
#ifdef USE_DYNAMIC_GL_ARB_texture_cube_map
static bool DinamicGLFeature_ARB_texture_cube_map_loaded = false; 
static void InitDinamicGLFeature_ARB_texture_cube_map() {
		DinamicGLFeature_ARB_texture_cube_map_loaded = true; 
}
bool DinamicGLFeature_ARB_texture_cube_map_Supported() {
		if (!DinamicGLFeature_ARB_texture_cube_map_loaded) {
			InitDinamicGLFeature_ARB_texture_cube_map();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_texture_cube_map*/

/*NV_vertex_array_range*/
#ifdef USE_DYNAMIC_GL_NV_vertex_array_range
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FlushVertexArrayRangeNV)() = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexArrayRangeNV)(GLsizei length , const GLvoid *pointer) = 0; }
static bool DinamicGLFeature_NV_vertex_array_range_loaded = false; 
static void InitDinamicGLFeature_NV_vertex_array_range() {
		DynamicGL_FlushVertexArrayRangeNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glFlushVertexArrayRangeNV"); 
		DynamicGL_VertexArrayRangeNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei length , const GLvoid *pointer)>("glVertexArrayRangeNV"); 
		DinamicGLFeature_NV_vertex_array_range_loaded = true; 
}
bool DinamicGLFeature_NV_vertex_array_range_Supported() {
		if (!DinamicGLFeature_NV_vertex_array_range_loaded) {
			InitDinamicGLFeature_NV_vertex_array_range();
		}
		if (DynamicGL_FlushVertexArrayRangeNV==0) return false; 
		if (DynamicGL_VertexArrayRangeNV==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_vertex_array_range*/

/*EXT_cull_vertex*/
#ifdef USE_DYNAMIC_GL_EXT_cull_vertex
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CullParameterdvEXT)(GLenum pname , GLdouble *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CullParameterfvEXT)(GLenum pname , GLfloat *params) = 0; }
static bool DinamicGLFeature_EXT_cull_vertex_loaded = false; 
static void InitDinamicGLFeature_EXT_cull_vertex() {
		DynamicGL_CullParameterdvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLdouble *params)>("glCullParameterdvEXT"); 
		DynamicGL_CullParameterfvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLfloat *params)>("glCullParameterfvEXT"); 
		DinamicGLFeature_EXT_cull_vertex_loaded = true; 
}
bool DinamicGLFeature_EXT_cull_vertex_Supported() {
		if (!DinamicGLFeature_EXT_cull_vertex_loaded) {
			InitDinamicGLFeature_EXT_cull_vertex();
		}
		if (DynamicGL_CullParameterdvEXT==0) return false; 
		if (DynamicGL_CullParameterfvEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_cull_vertex*/

/*FfdMaskSGIX*/
#ifdef USE_DYNAMIC_GL_FfdMaskSGIX
static bool DinamicGLFeature_FfdMaskSGIX_loaded = false; 
static void InitDinamicGLFeature_FfdMaskSGIX() {
		DinamicGLFeature_FfdMaskSGIX_loaded = true; 
}
bool DinamicGLFeature_FfdMaskSGIX_Supported() {
		if (!DinamicGLFeature_FfdMaskSGIX_loaded) {
			InitDinamicGLFeature_FfdMaskSGIX();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_FfdMaskSGIX*/

/*OES_read_format*/
#ifdef USE_DYNAMIC_GL_OES_read_format
static bool DinamicGLFeature_OES_read_format_loaded = false; 
static void InitDinamicGLFeature_OES_read_format() {
		DinamicGLFeature_OES_read_format_loaded = true; 
}
bool DinamicGLFeature_OES_read_format_Supported() {
		if (!DinamicGLFeature_OES_read_format_loaded) {
			InitDinamicGLFeature_OES_read_format();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_OES_read_format*/

/*INGR_blend_func_separate*/
#ifdef USE_DYNAMIC_GL_INGR_blend_func_separate
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendFuncSeparateINGR)(GLenum sfactorRGB , GLenum dfactorRGB , GLenum sfactorAlpha , GLenum dfactorAlpha) = 0; }
static bool DinamicGLFeature_INGR_blend_func_separate_loaded = false; 
static void InitDinamicGLFeature_INGR_blend_func_separate() {
		DynamicGL_BlendFuncSeparateINGR = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum sfactorRGB , GLenum dfactorRGB , GLenum sfactorAlpha , GLenum dfactorAlpha)>("glBlendFuncSeparateINGR"); 
		DinamicGLFeature_INGR_blend_func_separate_loaded = true; 
}
bool DinamicGLFeature_INGR_blend_func_separate_Supported() {
		if (!DinamicGLFeature_INGR_blend_func_separate_loaded) {
			InitDinamicGLFeature_INGR_blend_func_separate();
		}
		if (DynamicGL_BlendFuncSeparateINGR==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_INGR_blend_func_separate*/

/*APPLE_client_storage*/
#ifdef USE_DYNAMIC_GL_APPLE_client_storage
static bool DinamicGLFeature_APPLE_client_storage_loaded = false; 
static void InitDinamicGLFeature_APPLE_client_storage() {
		DinamicGLFeature_APPLE_client_storage_loaded = true; 
}
bool DinamicGLFeature_APPLE_client_storage_Supported() {
		if (!DinamicGLFeature_APPLE_client_storage_loaded) {
			InitDinamicGLFeature_APPLE_client_storage();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_APPLE_client_storage*/

/*ATI_envmap_bumpmap*/
#ifdef USE_DYNAMIC_GL_ATI_envmap_bumpmap
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexBumpParameterivATI)(GLenum pname , const GLint *param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexBumpParameterfvATI)(GLenum pname , const GLfloat *param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexBumpParameterivATI)(GLenum pname , GLint *param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexBumpParameterfvATI)(GLenum pname , GLfloat *param) = 0; }
static bool DinamicGLFeature_ATI_envmap_bumpmap_loaded = false; 
static void InitDinamicGLFeature_ATI_envmap_bumpmap() {
		DynamicGL_TexBumpParameterivATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , const GLint *param)>("glTexBumpParameterivATI"); 
		DynamicGL_TexBumpParameterfvATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , const GLfloat *param)>("glTexBumpParameterfvATI"); 
		DynamicGL_GetTexBumpParameterivATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLint *param)>("glGetTexBumpParameterivATI"); 
		DynamicGL_GetTexBumpParameterfvATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLfloat *param)>("glGetTexBumpParameterfvATI"); 
		DinamicGLFeature_ATI_envmap_bumpmap_loaded = true; 
}
bool DinamicGLFeature_ATI_envmap_bumpmap_Supported() {
		if (!DinamicGLFeature_ATI_envmap_bumpmap_loaded) {
			InitDinamicGLFeature_ATI_envmap_bumpmap();
		}
		if (DynamicGL_TexBumpParameterivATI==0) return false; 
		if (DynamicGL_TexBumpParameterfvATI==0) return false; 
		if (DynamicGL_GetTexBumpParameterivATI==0) return false; 
		if (DynamicGL_GetTexBumpParameterfvATI==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_ATI_envmap_bumpmap*/

/*ATI_vertex_array_object*/
#ifdef USE_DYNAMIC_GL_ATI_vertex_array_object
extern "C" { GLuint (DYNAMIC_GL_APIENTRYP DynamicGL_NewObjectBufferATI)(GLsizei size , const GLvoid *pointer , GLenum usage) = 0; }
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsObjectBufferATI)(GLuint buffer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_UpdateObjectBufferATI)(GLuint buffer , GLuint offset , GLsizei size , const GLvoid *pointer , GLenum preserve) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetObjectBufferfvATI)(GLuint buffer , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetObjectBufferivATI)(GLuint buffer , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FreeObjectBufferATI)(GLuint buffer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ArrayObjectATI)(GLenum array , GLint size , GLenum type , GLsizei stride , GLuint buffer , GLuint offset) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetArrayObjectfvATI)(GLenum array , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetArrayObjectivATI)(GLenum array , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VariantArrayObjectATI)(GLuint id , GLenum type , GLsizei stride , GLuint buffer , GLuint offset) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVariantArrayObjectfvATI)(GLuint id , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVariantArrayObjectivATI)(GLuint id , GLenum pname , GLint *params) = 0; }
static bool DinamicGLFeature_ATI_vertex_array_object_loaded = false; 
static void InitDinamicGLFeature_ATI_vertex_array_object() {
		DynamicGL_NewObjectBufferATI = DynamicGL_LoadFunction<GLuint (DYNAMIC_GL_APIENTRYP)(GLsizei size , const GLvoid *pointer , GLenum usage)>("glNewObjectBufferATI"); 
		DynamicGL_IsObjectBufferATI = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLuint buffer)>("glIsObjectBufferATI"); 
		DynamicGL_UpdateObjectBufferATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint buffer , GLuint offset , GLsizei size , const GLvoid *pointer , GLenum preserve)>("glUpdateObjectBufferATI"); 
		DynamicGL_GetObjectBufferfvATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint buffer , GLenum pname , GLfloat *params)>("glGetObjectBufferfvATI"); 
		DynamicGL_GetObjectBufferivATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint buffer , GLenum pname , GLint *params)>("glGetObjectBufferivATI"); 
		DynamicGL_FreeObjectBufferATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint buffer)>("glFreeObjectBufferATI"); 
		DynamicGL_ArrayObjectATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum array , GLint size , GLenum type , GLsizei stride , GLuint buffer , GLuint offset)>("glArrayObjectATI"); 
		DynamicGL_GetArrayObjectfvATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum array , GLenum pname , GLfloat *params)>("glGetArrayObjectfvATI"); 
		DynamicGL_GetArrayObjectivATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum array , GLenum pname , GLint *params)>("glGetArrayObjectivATI"); 
		DynamicGL_VariantArrayObjectATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , GLenum type , GLsizei stride , GLuint buffer , GLuint offset)>("glVariantArrayObjectATI"); 
		DynamicGL_GetVariantArrayObjectfvATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , GLenum pname , GLfloat *params)>("glGetVariantArrayObjectfvATI"); 
		DynamicGL_GetVariantArrayObjectivATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint id , GLenum pname , GLint *params)>("glGetVariantArrayObjectivATI"); 
		DinamicGLFeature_ATI_vertex_array_object_loaded = true; 
}
bool DinamicGLFeature_ATI_vertex_array_object_Supported() {
		if (!DinamicGLFeature_ATI_vertex_array_object_loaded) {
			InitDinamicGLFeature_ATI_vertex_array_object();
		}
		if (DynamicGL_NewObjectBufferATI==0) return false; 
		if (DynamicGL_IsObjectBufferATI==0) return false; 
		if (DynamicGL_UpdateObjectBufferATI==0) return false; 
		if (DynamicGL_GetObjectBufferfvATI==0) return false; 
		if (DynamicGL_GetObjectBufferivATI==0) return false; 
		if (DynamicGL_FreeObjectBufferATI==0) return false; 
		if (DynamicGL_ArrayObjectATI==0) return false; 
		if (DynamicGL_GetArrayObjectfvATI==0) return false; 
		if (DynamicGL_GetArrayObjectivATI==0) return false; 
		if (DynamicGL_VariantArrayObjectATI==0) return false; 
		if (DynamicGL_GetVariantArrayObjectfvATI==0) return false; 
		if (DynamicGL_GetVariantArrayObjectivATI==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_ATI_vertex_array_object*/

/*SGIX_async_pixel*/
#ifdef USE_DYNAMIC_GL_SGIX_async_pixel
static bool DinamicGLFeature_SGIX_async_pixel_loaded = false; 
static void InitDinamicGLFeature_SGIX_async_pixel() {
		DinamicGLFeature_SGIX_async_pixel_loaded = true; 
}
bool DinamicGLFeature_SGIX_async_pixel_Supported() {
		if (!DinamicGLFeature_SGIX_async_pixel_loaded) {
			InitDinamicGLFeature_SGIX_async_pixel();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_async_pixel*/

/*ATI_text_fragment_shader*/
#ifdef USE_DYNAMIC_GL_ATI_text_fragment_shader
static bool DinamicGLFeature_ATI_text_fragment_shader_loaded = false; 
static void InitDinamicGLFeature_ATI_text_fragment_shader() {
		DinamicGLFeature_ATI_text_fragment_shader_loaded = true; 
}
bool DinamicGLFeature_ATI_text_fragment_shader_Supported() {
		if (!DinamicGLFeature_ATI_text_fragment_shader_loaded) {
			InitDinamicGLFeature_ATI_text_fragment_shader();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_ATI_text_fragment_shader*/

/*ARB_point_parameters*/
#ifdef USE_DYNAMIC_GL_ARB_point_parameters
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameterfARB)(GLenum pname , GLfloat param) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameterfvARB)(GLenum pname , const GLfloat *params) = 0; }
static bool DinamicGLFeature_ARB_point_parameters_loaded = false; 
static void InitDinamicGLFeature_ARB_point_parameters() {
		DynamicGL_PointParameterfARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLfloat param)>("glPointParameterfARB"); 
		DynamicGL_PointParameterfvARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , const GLfloat *params)>("glPointParameterfvARB"); 
		DinamicGLFeature_ARB_point_parameters_loaded = true; 
}
bool DinamicGLFeature_ARB_point_parameters_Supported() {
		if (!DinamicGLFeature_ARB_point_parameters_loaded) {
			InitDinamicGLFeature_ARB_point_parameters();
		}
		if (DynamicGL_PointParameterfARB==0) return false; 
		if (DynamicGL_PointParameterfvARB==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_point_parameters*/

/*EXT_pixel_buffer_object*/
#ifdef USE_DYNAMIC_GL_EXT_pixel_buffer_object
static bool DinamicGLFeature_EXT_pixel_buffer_object_loaded = false; 
static void InitDinamicGLFeature_EXT_pixel_buffer_object() {
		DinamicGLFeature_EXT_pixel_buffer_object_loaded = true; 
}
bool DinamicGLFeature_EXT_pixel_buffer_object_Supported() {
		if (!DinamicGLFeature_EXT_pixel_buffer_object_loaded) {
			InitDinamicGLFeature_EXT_pixel_buffer_object();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_pixel_buffer_object*/

/*EXT_index_array_formats*/
#ifdef USE_DYNAMIC_GL_EXT_index_array_formats
static bool DinamicGLFeature_EXT_index_array_formats_loaded = false; 
static void InitDinamicGLFeature_EXT_index_array_formats() {
		DinamicGLFeature_EXT_index_array_formats_loaded = true; 
}
bool DinamicGLFeature_EXT_index_array_formats_Supported() {
		if (!DinamicGLFeature_EXT_index_array_formats_loaded) {
			InitDinamicGLFeature_EXT_index_array_formats();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_index_array_formats*/

/*EXT_vertex_array*/
#ifdef USE_DYNAMIC_GL_EXT_vertex_array
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ArrayElementEXT)(GLint i) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorPointerEXT)(GLint size , GLenum type , GLsizei stride , GLsizei count , const GLvoid *pointer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawArraysEXT)(GLenum mode , GLint first , GLsizei count) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EdgeFlagPointerEXT)(GLsizei stride , GLsizei count , const GLboolean *pointer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPointervEXT)(GLenum pname , GLvoid* *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_IndexPointerEXT)(GLenum type , GLsizei stride , GLsizei count , const GLvoid *pointer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NormalPointerEXT)(GLenum type , GLsizei stride , GLsizei count , const GLvoid *pointer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoordPointerEXT)(GLint size , GLenum type , GLsizei stride , GLsizei count , const GLvoid *pointer) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexPointerEXT)(GLint size , GLenum type , GLsizei stride , GLsizei count , const GLvoid *pointer) = 0; }
static bool DinamicGLFeature_EXT_vertex_array_loaded = false; 
static void InitDinamicGLFeature_EXT_vertex_array() {
		DynamicGL_ArrayElementEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint i)>("glArrayElementEXT"); 
		DynamicGL_ColorPointerEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint size , GLenum type , GLsizei stride , GLsizei count , const GLvoid *pointer)>("glColorPointerEXT"); 
		DynamicGL_DrawArraysEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , GLint first , GLsizei count)>("glDrawArraysEXT"); 
		DynamicGL_EdgeFlagPointerEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei stride , GLsizei count , const GLboolean *pointer)>("glEdgeFlagPointerEXT"); 
		DynamicGL_GetPointervEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLvoid* *params)>("glGetPointervEXT"); 
		DynamicGL_IndexPointerEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum type , GLsizei stride , GLsizei count , const GLvoid *pointer)>("glIndexPointerEXT"); 
		DynamicGL_NormalPointerEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum type , GLsizei stride , GLsizei count , const GLvoid *pointer)>("glNormalPointerEXT"); 
		DynamicGL_TexCoordPointerEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint size , GLenum type , GLsizei stride , GLsizei count , const GLvoid *pointer)>("glTexCoordPointerEXT"); 
		DynamicGL_VertexPointerEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint size , GLenum type , GLsizei stride , GLsizei count , const GLvoid *pointer)>("glVertexPointerEXT"); 
		DinamicGLFeature_EXT_vertex_array_loaded = true; 
}
bool DinamicGLFeature_EXT_vertex_array_Supported() {
		if (!DinamicGLFeature_EXT_vertex_array_loaded) {
			InitDinamicGLFeature_EXT_vertex_array();
		}
		if (DynamicGL_ArrayElementEXT==0) return false; 
		if (DynamicGL_ColorPointerEXT==0) return false; 
		if (DynamicGL_DrawArraysEXT==0) return false; 
		if (DynamicGL_EdgeFlagPointerEXT==0) return false; 
		if (DynamicGL_GetPointervEXT==0) return false; 
		if (DynamicGL_IndexPointerEXT==0) return false; 
		if (DynamicGL_NormalPointerEXT==0) return false; 
		if (DynamicGL_TexCoordPointerEXT==0) return false; 
		if (DynamicGL_VertexPointerEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_vertex_array*/

/*ARB_vertex_array_object*/
#ifdef USE_DYNAMIC_GL_ARB_vertex_array_object
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_BindVertexArray)(GLuint array) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteVertexArrays)(GLsizei n , const GLuint *arrays) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GenVertexArrays)(GLsizei n , GLuint *arrays) = 0; }
extern "C" { GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsVertexArray)(GLuint array) = 0; }
static bool DinamicGLFeature_ARB_vertex_array_object_loaded = false; 
static void InitDinamicGLFeature_ARB_vertex_array_object() {
		DynamicGL_BindVertexArray = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint array)>("glBindVertexArray"); 
		DynamicGL_DeleteVertexArrays = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , const GLuint *arrays)>("glDeleteVertexArrays"); 
		DynamicGL_GenVertexArrays = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , GLuint *arrays)>("glGenVertexArrays"); 
		DynamicGL_IsVertexArray = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLuint array)>("glIsVertexArray"); 
		DinamicGLFeature_ARB_vertex_array_object_loaded = true; 
}
bool DinamicGLFeature_ARB_vertex_array_object_Supported() {
		if (!DinamicGLFeature_ARB_vertex_array_object_loaded) {
			InitDinamicGLFeature_ARB_vertex_array_object();
		}
		if (DynamicGL_BindVertexArray==0) return false; 
		if (DynamicGL_DeleteVertexArrays==0) return false; 
		if (DynamicGL_GenVertexArrays==0) return false; 
		if (DynamicGL_IsVertexArray==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_vertex_array_object*/

/*IBM_vertex_array_lists*/
#ifdef USE_DYNAMIC_GL_IBM_vertex_array_lists
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorPointerListIBM)(GLint size , GLenum type , GLint stride , const GLvoid* *pointer , GLint ptrstride) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColorPointerListIBM)(GLint size , GLenum type , GLint stride , const GLvoid* *pointer , GLint ptrstride) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_EdgeFlagPointerListIBM)(GLint stride , const GLboolean* *pointer , GLint ptrstride) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_FogCoordPointerListIBM)(GLenum type , GLint stride , const GLvoid* *pointer , GLint ptrstride) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_IndexPointerListIBM)(GLenum type , GLint stride , const GLvoid* *pointer , GLint ptrstride) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_NormalPointerListIBM)(GLenum type , GLint stride , const GLvoid* *pointer , GLint ptrstride) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoordPointerListIBM)(GLint size , GLenum type , GLint stride , const GLvoid* *pointer , GLint ptrstride) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexPointerListIBM)(GLint size , GLenum type , GLint stride , const GLvoid* *pointer , GLint ptrstride) = 0; }
static bool DinamicGLFeature_IBM_vertex_array_lists_loaded = false; 
static void InitDinamicGLFeature_IBM_vertex_array_lists() {
		DynamicGL_ColorPointerListIBM = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint size , GLenum type , GLint stride , const GLvoid* *pointer , GLint ptrstride)>("glColorPointerListIBM"); 
		DynamicGL_SecondaryColorPointerListIBM = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint size , GLenum type , GLint stride , const GLvoid* *pointer , GLint ptrstride)>("glSecondaryColorPointerListIBM"); 
		DynamicGL_EdgeFlagPointerListIBM = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint stride , const GLboolean* *pointer , GLint ptrstride)>("glEdgeFlagPointerListIBM"); 
		DynamicGL_FogCoordPointerListIBM = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum type , GLint stride , const GLvoid* *pointer , GLint ptrstride)>("glFogCoordPointerListIBM"); 
		DynamicGL_IndexPointerListIBM = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum type , GLint stride , const GLvoid* *pointer , GLint ptrstride)>("glIndexPointerListIBM"); 
		DynamicGL_NormalPointerListIBM = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum type , GLint stride , const GLvoid* *pointer , GLint ptrstride)>("glNormalPointerListIBM"); 
		DynamicGL_TexCoordPointerListIBM = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint size , GLenum type , GLint stride , const GLvoid* *pointer , GLint ptrstride)>("glTexCoordPointerListIBM"); 
		DynamicGL_VertexPointerListIBM = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint size , GLenum type , GLint stride , const GLvoid* *pointer , GLint ptrstride)>("glVertexPointerListIBM"); 
		DinamicGLFeature_IBM_vertex_array_lists_loaded = true; 
}
bool DinamicGLFeature_IBM_vertex_array_lists_Supported() {
		if (!DinamicGLFeature_IBM_vertex_array_lists_loaded) {
			InitDinamicGLFeature_IBM_vertex_array_lists();
		}
		if (DynamicGL_ColorPointerListIBM==0) return false; 
		if (DynamicGL_SecondaryColorPointerListIBM==0) return false; 
		if (DynamicGL_EdgeFlagPointerListIBM==0) return false; 
		if (DynamicGL_FogCoordPointerListIBM==0) return false; 
		if (DynamicGL_IndexPointerListIBM==0) return false; 
		if (DynamicGL_NormalPointerListIBM==0) return false; 
		if (DynamicGL_TexCoordPointerListIBM==0) return false; 
		if (DynamicGL_VertexPointerListIBM==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_IBM_vertex_array_lists*/

/*ATI_draw_buffers*/
#ifdef USE_DYNAMIC_GL_ATI_draw_buffers
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawBuffersATI)(GLsizei n , const GLenum *bufs) = 0; }
static bool DinamicGLFeature_ATI_draw_buffers_loaded = false; 
static void InitDinamicGLFeature_ATI_draw_buffers() {
		DynamicGL_DrawBuffersATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , const GLenum *bufs)>("glDrawBuffersATI"); 
		DinamicGLFeature_ATI_draw_buffers_loaded = true; 
}
bool DinamicGLFeature_ATI_draw_buffers_Supported() {
		if (!DinamicGLFeature_ATI_draw_buffers_loaded) {
			InitDinamicGLFeature_ATI_draw_buffers();
		}
		if (DynamicGL_DrawBuffersATI==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_ATI_draw_buffers*/

/*EXT_texture_compression_rgtc*/
#ifdef USE_DYNAMIC_GL_EXT_texture_compression_rgtc
static bool DinamicGLFeature_EXT_texture_compression_rgtc_loaded = false; 
static void InitDinamicGLFeature_EXT_texture_compression_rgtc() {
		DinamicGLFeature_EXT_texture_compression_rgtc_loaded = true; 
}
bool DinamicGLFeature_EXT_texture_compression_rgtc_Supported() {
		if (!DinamicGLFeature_EXT_texture_compression_rgtc_loaded) {
			InitDinamicGLFeature_EXT_texture_compression_rgtc();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_texture_compression_rgtc*/

/*ARB_texture_compression*/
#ifdef USE_DYNAMIC_GL_ARB_texture_compression
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTexImage3DARB)(GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLsizei depth , GLint border , GLsizei imageSize , const GLvoid *data) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTexImage2DARB)(GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLint border , GLsizei imageSize , const GLvoid *data) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTexImage1DARB)(GLenum target , GLint level , GLenum internalformat , GLsizei width , GLint border , GLsizei imageSize , const GLvoid *data) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTexSubImage3DARB)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLsizei width , GLsizei height , GLsizei depth , GLenum format , GLsizei imageSize , const GLvoid *data) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTexSubImage2DARB)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLsizei width , GLsizei height , GLenum format , GLsizei imageSize , const GLvoid *data) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTexSubImage1DARB)(GLenum target , GLint level , GLint xoffset , GLsizei width , GLenum format , GLsizei imageSize , const GLvoid *data) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetCompressedTexImageARB)(GLenum target , GLint level , GLvoid *img) = 0; }
static bool DinamicGLFeature_ARB_texture_compression_loaded = false; 
static void InitDinamicGLFeature_ARB_texture_compression() {
		DynamicGL_CompressedTexImage3DARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLsizei depth , GLint border , GLsizei imageSize , const GLvoid *data)>("glCompressedTexImage3DARB"); 
		DynamicGL_CompressedTexImage2DARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLint border , GLsizei imageSize , const GLvoid *data)>("glCompressedTexImage2DARB"); 
		DynamicGL_CompressedTexImage1DARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLenum internalformat , GLsizei width , GLint border , GLsizei imageSize , const GLvoid *data)>("glCompressedTexImage1DARB"); 
		DynamicGL_CompressedTexSubImage3DARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLsizei width , GLsizei height , GLsizei depth , GLenum format , GLsizei imageSize , const GLvoid *data)>("glCompressedTexSubImage3DARB"); 
		DynamicGL_CompressedTexSubImage2DARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLsizei width , GLsizei height , GLenum format , GLsizei imageSize , const GLvoid *data)>("glCompressedTexSubImage2DARB"); 
		DynamicGL_CompressedTexSubImage1DARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLint xoffset , GLsizei width , GLenum format , GLsizei imageSize , const GLvoid *data)>("glCompressedTexSubImage1DARB"); 
		DynamicGL_GetCompressedTexImageARB = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLvoid *img)>("glGetCompressedTexImageARB"); 
		DinamicGLFeature_ARB_texture_compression_loaded = true; 
}
bool DinamicGLFeature_ARB_texture_compression_Supported() {
		if (!DinamicGLFeature_ARB_texture_compression_loaded) {
			InitDinamicGLFeature_ARB_texture_compression();
		}
		if (DynamicGL_CompressedTexImage3DARB==0) return false; 
		if (DynamicGL_CompressedTexImage2DARB==0) return false; 
		if (DynamicGL_CompressedTexImage1DARB==0) return false; 
		if (DynamicGL_CompressedTexSubImage3DARB==0) return false; 
		if (DynamicGL_CompressedTexSubImage2DARB==0) return false; 
		if (DynamicGL_CompressedTexSubImage1DARB==0) return false; 
		if (DynamicGL_GetCompressedTexImageARB==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_texture_compression*/

/*VERSION_2_1*/
#ifdef USE_DYNAMIC_GL_VERSION_2_1
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformMatrix2x3fv)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformMatrix3x2fv)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformMatrix2x4fv)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformMatrix4x2fv)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformMatrix3x4fv)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformMatrix4x3fv)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value) = 0; }
static bool DinamicGLFeature_VERSION_2_1_loaded = false; 
static void InitDinamicGLFeature_VERSION_2_1() {
		DynamicGL_UniformMatrix2x3fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value)>("glUniformMatrix2x3fv"); 
		DynamicGL_UniformMatrix3x2fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value)>("glUniformMatrix3x2fv"); 
		DynamicGL_UniformMatrix2x4fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value)>("glUniformMatrix2x4fv"); 
		DynamicGL_UniformMatrix4x2fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value)>("glUniformMatrix4x2fv"); 
		DynamicGL_UniformMatrix3x4fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value)>("glUniformMatrix3x4fv"); 
		DynamicGL_UniformMatrix4x3fv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value)>("glUniformMatrix4x3fv"); 
		DinamicGLFeature_VERSION_2_1_loaded = true; 
}
bool DinamicGLFeature_VERSION_2_1_Supported() {
		if (!DinamicGLFeature_VERSION_2_1_loaded) {
			InitDinamicGLFeature_VERSION_2_1();
		}
		if (DynamicGL_UniformMatrix2x3fv==0) return false; 
		if (DynamicGL_UniformMatrix3x2fv==0) return false; 
		if (DynamicGL_UniformMatrix2x4fv==0) return false; 
		if (DynamicGL_UniformMatrix4x2fv==0) return false; 
		if (DynamicGL_UniformMatrix3x4fv==0) return false; 
		if (DynamicGL_UniformMatrix4x3fv==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_VERSION_2_1*/

/*EXT_color_subtable*/
#ifdef USE_DYNAMIC_GL_EXT_color_subtable
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorSubTableEXT)(GLenum target , GLsizei start , GLsizei count , GLenum format , GLenum type , const GLvoid *data) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyColorSubTableEXT)(GLenum target , GLsizei start , GLint x , GLint y , GLsizei width) = 0; }
static bool DinamicGLFeature_EXT_color_subtable_loaded = false; 
static void InitDinamicGLFeature_EXT_color_subtable() {
		DynamicGL_ColorSubTableEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLsizei start , GLsizei count , GLenum format , GLenum type , const GLvoid *data)>("glColorSubTableEXT"); 
		DynamicGL_CopyColorSubTableEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLsizei start , GLint x , GLint y , GLsizei width)>("glCopyColorSubTableEXT"); 
		DinamicGLFeature_EXT_color_subtable_loaded = true; 
}
bool DinamicGLFeature_EXT_color_subtable_Supported() {
		if (!DinamicGLFeature_EXT_color_subtable_loaded) {
			InitDinamicGLFeature_EXT_color_subtable();
		}
		if (DynamicGL_ColorSubTableEXT==0) return false; 
		if (DynamicGL_CopyColorSubTableEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_color_subtable*/

/*EXT_convolution*/
#ifdef USE_DYNAMIC_GL_EXT_convolution
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ConvolutionFilter1DEXT)(GLenum target , GLenum internalformat , GLsizei width , GLenum format , GLenum type , const GLvoid *image) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ConvolutionFilter2DEXT)(GLenum target , GLenum internalformat , GLsizei width , GLsizei height , GLenum format , GLenum type , const GLvoid *image) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ConvolutionParameterfEXT)(GLenum target , GLenum pname , GLfloat params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ConvolutionParameterfvEXT)(GLenum target , GLenum pname , const GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ConvolutionParameteriEXT)(GLenum target , GLenum pname , GLint params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ConvolutionParameterivEXT)(GLenum target , GLenum pname , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyConvolutionFilter1DEXT)(GLenum target , GLenum internalformat , GLint x , GLint y , GLsizei width) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyConvolutionFilter2DEXT)(GLenum target , GLenum internalformat , GLint x , GLint y , GLsizei width , GLsizei height) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetConvolutionFilterEXT)(GLenum target , GLenum format , GLenum type , GLvoid *image) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetConvolutionParameterfvEXT)(GLenum target , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetConvolutionParameterivEXT)(GLenum target , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetSeparableFilterEXT)(GLenum target , GLenum format , GLenum type , GLvoid *row , GLvoid *column , GLvoid *span) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_SeparableFilter2DEXT)(GLenum target , GLenum internalformat , GLsizei width , GLsizei height , GLenum format , GLenum type , const GLvoid *row , const GLvoid *column) = 0; }
static bool DinamicGLFeature_EXT_convolution_loaded = false; 
static void InitDinamicGLFeature_EXT_convolution() {
		DynamicGL_ConvolutionFilter1DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum internalformat , GLsizei width , GLenum format , GLenum type , const GLvoid *image)>("glConvolutionFilter1DEXT"); 
		DynamicGL_ConvolutionFilter2DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum internalformat , GLsizei width , GLsizei height , GLenum format , GLenum type , const GLvoid *image)>("glConvolutionFilter2DEXT"); 
		DynamicGL_ConvolutionParameterfEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLfloat params)>("glConvolutionParameterfEXT"); 
		DynamicGL_ConvolutionParameterfvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , const GLfloat *params)>("glConvolutionParameterfvEXT"); 
		DynamicGL_ConvolutionParameteriEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint params)>("glConvolutionParameteriEXT"); 
		DynamicGL_ConvolutionParameterivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , const GLint *params)>("glConvolutionParameterivEXT"); 
		DynamicGL_CopyConvolutionFilter1DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum internalformat , GLint x , GLint y , GLsizei width)>("glCopyConvolutionFilter1DEXT"); 
		DynamicGL_CopyConvolutionFilter2DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum internalformat , GLint x , GLint y , GLsizei width , GLsizei height)>("glCopyConvolutionFilter2DEXT"); 
		DynamicGL_GetConvolutionFilterEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum format , GLenum type , GLvoid *image)>("glGetConvolutionFilterEXT"); 
		DynamicGL_GetConvolutionParameterfvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLfloat *params)>("glGetConvolutionParameterfvEXT"); 
		DynamicGL_GetConvolutionParameterivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint *params)>("glGetConvolutionParameterivEXT"); 
		DynamicGL_GetSeparableFilterEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum format , GLenum type , GLvoid *row , GLvoid *column , GLvoid *span)>("glGetSeparableFilterEXT"); 
		DynamicGL_SeparableFilter2DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum internalformat , GLsizei width , GLsizei height , GLenum format , GLenum type , const GLvoid *row , const GLvoid *column)>("glSeparableFilter2DEXT"); 
		DinamicGLFeature_EXT_convolution_loaded = true; 
}
bool DinamicGLFeature_EXT_convolution_Supported() {
		if (!DinamicGLFeature_EXT_convolution_loaded) {
			InitDinamicGLFeature_EXT_convolution();
		}
		if (DynamicGL_ConvolutionFilter1DEXT==0) return false; 
		if (DynamicGL_ConvolutionFilter2DEXT==0) return false; 
		if (DynamicGL_ConvolutionParameterfEXT==0) return false; 
		if (DynamicGL_ConvolutionParameterfvEXT==0) return false; 
		if (DynamicGL_ConvolutionParameteriEXT==0) return false; 
		if (DynamicGL_ConvolutionParameterivEXT==0) return false; 
		if (DynamicGL_CopyConvolutionFilter1DEXT==0) return false; 
		if (DynamicGL_CopyConvolutionFilter2DEXT==0) return false; 
		if (DynamicGL_GetConvolutionFilterEXT==0) return false; 
		if (DynamicGL_GetConvolutionParameterfvEXT==0) return false; 
		if (DynamicGL_GetConvolutionParameterivEXT==0) return false; 
		if (DynamicGL_GetSeparableFilterEXT==0) return false; 
		if (DynamicGL_SeparableFilter2DEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_convolution*/

/*SGIX_fog_offset*/
#ifdef USE_DYNAMIC_GL_SGIX_fog_offset
static bool DinamicGLFeature_SGIX_fog_offset_loaded = false; 
static void InitDinamicGLFeature_SGIX_fog_offset() {
		DinamicGLFeature_SGIX_fog_offset_loaded = true; 
}
bool DinamicGLFeature_SGIX_fog_offset_Supported() {
		if (!DinamicGLFeature_SGIX_fog_offset_loaded) {
			InitDinamicGLFeature_SGIX_fog_offset();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_fog_offset*/

/*EXT_texture_integer*/
#ifdef USE_DYNAMIC_GL_EXT_texture_integer
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexParameterIivEXT)(GLenum target , GLenum pname , const GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexParameterIuivEXT)(GLenum target , GLenum pname , const GLuint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexParameterIivEXT)(GLenum target , GLenum pname , GLint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexParameterIuivEXT)(GLenum target , GLenum pname , GLuint *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearColorIiEXT)(GLint red , GLint green , GLint blue , GLint alpha) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearColorIuiEXT)(GLuint red , GLuint green , GLuint blue , GLuint alpha) = 0; }
static bool DinamicGLFeature_EXT_texture_integer_loaded = false; 
static void InitDinamicGLFeature_EXT_texture_integer() {
		DynamicGL_TexParameterIivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , const GLint *params)>("glTexParameterIivEXT"); 
		DynamicGL_TexParameterIuivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , const GLuint *params)>("glTexParameterIuivEXT"); 
		DynamicGL_GetTexParameterIivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint *params)>("glGetTexParameterIivEXT"); 
		DynamicGL_GetTexParameterIuivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLuint *params)>("glGetTexParameterIuivEXT"); 
		DynamicGL_ClearColorIiEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint red , GLint green , GLint blue , GLint alpha)>("glClearColorIiEXT"); 
		DynamicGL_ClearColorIuiEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint red , GLuint green , GLuint blue , GLuint alpha)>("glClearColorIuiEXT"); 
		DinamicGLFeature_EXT_texture_integer_loaded = true; 
}
bool DinamicGLFeature_EXT_texture_integer_Supported() {
		if (!DinamicGLFeature_EXT_texture_integer_loaded) {
			InitDinamicGLFeature_EXT_texture_integer();
		}
		if (DynamicGL_TexParameterIivEXT==0) return false; 
		if (DynamicGL_TexParameterIuivEXT==0) return false; 
		if (DynamicGL_GetTexParameterIivEXT==0) return false; 
		if (DynamicGL_GetTexParameterIuivEXT==0) return false; 
		if (DynamicGL_ClearColorIiEXT==0) return false; 
		if (DynamicGL_ClearColorIuiEXT==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_texture_integer*/

/*ATI_vertex_attrib_array_object*/
#ifdef USE_DYNAMIC_GL_ATI_vertex_attrib_array_object
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribArrayObjectATI)(GLuint index , GLint size , GLenum type , GLboolean normalized , GLsizei stride , GLuint buffer , GLuint offset) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribArrayObjectfvATI)(GLuint index , GLenum pname , GLfloat *params) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribArrayObjectivATI)(GLuint index , GLenum pname , GLint *params) = 0; }
static bool DinamicGLFeature_ATI_vertex_attrib_array_object_loaded = false; 
static void InitDinamicGLFeature_ATI_vertex_attrib_array_object() {
		DynamicGL_VertexAttribArrayObjectATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLint size , GLenum type , GLboolean normalized , GLsizei stride , GLuint buffer , GLuint offset)>("glVertexAttribArrayObjectATI"); 
		DynamicGL_GetVertexAttribArrayObjectfvATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLenum pname , GLfloat *params)>("glGetVertexAttribArrayObjectfvATI"); 
		DynamicGL_GetVertexAttribArrayObjectivATI = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index , GLenum pname , GLint *params)>("glGetVertexAttribArrayObjectivATI"); 
		DinamicGLFeature_ATI_vertex_attrib_array_object_loaded = true; 
}
bool DinamicGLFeature_ATI_vertex_attrib_array_object_Supported() {
		if (!DinamicGLFeature_ATI_vertex_attrib_array_object_loaded) {
			InitDinamicGLFeature_ATI_vertex_attrib_array_object();
		}
		if (DynamicGL_VertexAttribArrayObjectATI==0) return false; 
		if (DynamicGL_GetVertexAttribArrayObjectfvATI==0) return false; 
		if (DynamicGL_GetVertexAttribArrayObjectivATI==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_ATI_vertex_attrib_array_object*/

/*EXT_packed_float*/
#ifdef USE_DYNAMIC_GL_EXT_packed_float
static bool DinamicGLFeature_EXT_packed_float_loaded = false; 
static void InitDinamicGLFeature_EXT_packed_float() {
		DinamicGLFeature_EXT_packed_float_loaded = true; 
}
bool DinamicGLFeature_EXT_packed_float_Supported() {
		if (!DinamicGLFeature_EXT_packed_float_loaded) {
			InitDinamicGLFeature_EXT_packed_float();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_packed_float*/

/*NV_texture_shader*/
#ifdef USE_DYNAMIC_GL_NV_texture_shader
static bool DinamicGLFeature_NV_texture_shader_loaded = false; 
static void InitDinamicGLFeature_NV_texture_shader() {
		DinamicGLFeature_NV_texture_shader_loaded = true; 
}
bool DinamicGLFeature_NV_texture_shader_Supported() {
		if (!DinamicGLFeature_NV_texture_shader_loaded) {
			InitDinamicGLFeature_NV_texture_shader();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_texture_shader*/

/*SGIX_shadow*/
#ifdef USE_DYNAMIC_GL_SGIX_shadow
static bool DinamicGLFeature_SGIX_shadow_loaded = false; 
static void InitDinamicGLFeature_SGIX_shadow() {
		DinamicGLFeature_SGIX_shadow_loaded = true; 
}
bool DinamicGLFeature_SGIX_shadow_Supported() {
		if (!DinamicGLFeature_SGIX_shadow_loaded) {
			InitDinamicGLFeature_SGIX_shadow();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_SGIX_shadow*/

/*ARB_half_float_pixel*/
#ifdef USE_DYNAMIC_GL_ARB_half_float_pixel
static bool DinamicGLFeature_ARB_half_float_pixel_loaded = false; 
static void InitDinamicGLFeature_ARB_half_float_pixel() {
		DinamicGLFeature_ARB_half_float_pixel_loaded = true; 
}
bool DinamicGLFeature_ARB_half_float_pixel_Supported() {
		if (!DinamicGLFeature_ARB_half_float_pixel_loaded) {
			InitDinamicGLFeature_ARB_half_float_pixel();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_half_float_pixel*/

/*NV_primitive_restart*/
#ifdef USE_DYNAMIC_GL_NV_primitive_restart
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PrimitiveRestartNV)() = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_PrimitiveRestartIndexNV)(GLuint index) = 0; }
static bool DinamicGLFeature_NV_primitive_restart_loaded = false; 
static void InitDinamicGLFeature_NV_primitive_restart() {
		DynamicGL_PrimitiveRestartNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glPrimitiveRestartNV"); 
		DynamicGL_PrimitiveRestartIndexNV = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint index)>("glPrimitiveRestartIndexNV"); 
		DinamicGLFeature_NV_primitive_restart_loaded = true; 
}
bool DinamicGLFeature_NV_primitive_restart_Supported() {
		if (!DinamicGLFeature_NV_primitive_restart_loaded) {
			InitDinamicGLFeature_NV_primitive_restart();
		}
		if (DynamicGL_PrimitiveRestartNV==0) return false; 
		if (DynamicGL_PrimitiveRestartIndexNV==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_primitive_restart*/

/*SUN_vertex*/
#ifdef USE_DYNAMIC_GL_SUN_vertex
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4ubVertex2fSUN)(GLubyte r , GLubyte g , GLubyte b , GLubyte a , GLfloat x , GLfloat y) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4ubVertex2fvSUN)(const GLubyte *c , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4ubVertex3fSUN)(GLubyte r , GLubyte g , GLubyte b , GLubyte a , GLfloat x , GLfloat y , GLfloat z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4ubVertex3fvSUN)(const GLubyte *c , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3fVertex3fSUN)(GLfloat r , GLfloat g , GLfloat b , GLfloat x , GLfloat y , GLfloat z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3fVertex3fvSUN)(const GLfloat *c , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Normal3fVertex3fSUN)(GLfloat nx , GLfloat ny , GLfloat nz , GLfloat x , GLfloat y , GLfloat z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Normal3fVertex3fvSUN)(const GLfloat *n , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4fNormal3fVertex3fSUN)(GLfloat r , GLfloat g , GLfloat b , GLfloat a , GLfloat nx , GLfloat ny , GLfloat nz , GLfloat x , GLfloat y , GLfloat z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4fNormal3fVertex3fvSUN)(const GLfloat *c , const GLfloat *n , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2fVertex3fSUN)(GLfloat s , GLfloat t , GLfloat x , GLfloat y , GLfloat z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2fVertex3fvSUN)(const GLfloat *tc , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord4fVertex4fSUN)(GLfloat s , GLfloat t , GLfloat p , GLfloat q , GLfloat x , GLfloat y , GLfloat z , GLfloat w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord4fVertex4fvSUN)(const GLfloat *tc , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2fColor4ubVertex3fSUN)(GLfloat s , GLfloat t , GLubyte r , GLubyte g , GLubyte b , GLubyte a , GLfloat x , GLfloat y , GLfloat z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2fColor4ubVertex3fvSUN)(const GLfloat *tc , const GLubyte *c , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2fColor3fVertex3fSUN)(GLfloat s , GLfloat t , GLfloat r , GLfloat g , GLfloat b , GLfloat x , GLfloat y , GLfloat z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2fColor3fVertex3fvSUN)(const GLfloat *tc , const GLfloat *c , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2fNormal3fVertex3fSUN)(GLfloat s , GLfloat t , GLfloat nx , GLfloat ny , GLfloat nz , GLfloat x , GLfloat y , GLfloat z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2fNormal3fVertex3fvSUN)(const GLfloat *tc , const GLfloat *n , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2fColor4fNormal3fVertex3fSUN)(GLfloat s , GLfloat t , GLfloat r , GLfloat g , GLfloat b , GLfloat a , GLfloat nx , GLfloat ny , GLfloat nz , GLfloat x , GLfloat y , GLfloat z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2fColor4fNormal3fVertex3fvSUN)(const GLfloat *tc , const GLfloat *c , const GLfloat *n , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord4fColor4fNormal3fVertex4fSUN)(GLfloat s , GLfloat t , GLfloat p , GLfloat q , GLfloat r , GLfloat g , GLfloat b , GLfloat a , GLfloat nx , GLfloat ny , GLfloat nz , GLfloat x , GLfloat y , GLfloat z , GLfloat w) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord4fColor4fNormal3fVertex4fvSUN)(const GLfloat *tc , const GLfloat *c , const GLfloat *n , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuiVertex3fSUN)(GLuint rc , GLfloat x , GLfloat y , GLfloat z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuiVertex3fvSUN)(const GLuint *rc , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuiColor4ubVertex3fSUN)(GLuint rc , GLubyte r , GLubyte g , GLubyte b , GLubyte a , GLfloat x , GLfloat y , GLfloat z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuiColor4ubVertex3fvSUN)(const GLuint *rc , const GLubyte *c , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuiColor3fVertex3fSUN)(GLuint rc , GLfloat r , GLfloat g , GLfloat b , GLfloat x , GLfloat y , GLfloat z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuiColor3fVertex3fvSUN)(const GLuint *rc , const GLfloat *c , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuiNormal3fVertex3fSUN)(GLuint rc , GLfloat nx , GLfloat ny , GLfloat nz , GLfloat x , GLfloat y , GLfloat z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuiNormal3fVertex3fvSUN)(const GLuint *rc , const GLfloat *n , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuiColor4fNormal3fVertex3fSUN)(GLuint rc , GLfloat r , GLfloat g , GLfloat b , GLfloat a , GLfloat nx , GLfloat ny , GLfloat nz , GLfloat x , GLfloat y , GLfloat z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuiColor4fNormal3fVertex3fvSUN)(const GLuint *rc , const GLfloat *c , const GLfloat *n , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuiTexCoord2fVertex3fSUN)(GLuint rc , GLfloat s , GLfloat t , GLfloat x , GLfloat y , GLfloat z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuiTexCoord2fVertex3fvSUN)(const GLuint *rc , const GLfloat *tc , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuiTexCoord2fNormal3fVertex3fSUN)(GLuint rc , GLfloat s , GLfloat t , GLfloat nx , GLfloat ny , GLfloat nz , GLfloat x , GLfloat y , GLfloat z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN)(const GLuint *rc , const GLfloat *tc , const GLfloat *n , const GLfloat *v) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN)(GLuint rc , GLfloat s , GLfloat t , GLfloat r , GLfloat g , GLfloat b , GLfloat a , GLfloat nx , GLfloat ny , GLfloat nz , GLfloat x , GLfloat y , GLfloat z) = 0; }
extern "C" { void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN)(const GLuint *rc , const GLfloat *tc , const GLfloat *c , const GLfloat *n , const GLfloat *v) = 0; }
static bool DinamicGLFeature_SUN_vertex_loaded = false; 
static void InitDinamicGLFeature_SUN_vertex() {
		DynamicGL_Color4ubVertex2fSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLubyte r , GLubyte g , GLubyte b , GLubyte a , GLfloat x , GLfloat y)>("glColor4ubVertex2fSUN"); 
		DynamicGL_Color4ubVertex2fvSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLubyte *c , const GLfloat *v)>("glColor4ubVertex2fvSUN"); 
		DynamicGL_Color4ubVertex3fSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLubyte r , GLubyte g , GLubyte b , GLubyte a , GLfloat x , GLfloat y , GLfloat z)>("glColor4ubVertex3fSUN"); 
		DynamicGL_Color4ubVertex3fvSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLubyte *c , const GLfloat *v)>("glColor4ubVertex3fvSUN"); 
		DynamicGL_Color3fVertex3fSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat r , GLfloat g , GLfloat b , GLfloat x , GLfloat y , GLfloat z)>("glColor3fVertex3fSUN"); 
		DynamicGL_Color3fVertex3fvSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *c , const GLfloat *v)>("glColor3fVertex3fvSUN"); 
		DynamicGL_Normal3fVertex3fSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat nx , GLfloat ny , GLfloat nz , GLfloat x , GLfloat y , GLfloat z)>("glNormal3fVertex3fSUN"); 
		DynamicGL_Normal3fVertex3fvSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *n , const GLfloat *v)>("glNormal3fVertex3fvSUN"); 
		DynamicGL_Color4fNormal3fVertex3fSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat r , GLfloat g , GLfloat b , GLfloat a , GLfloat nx , GLfloat ny , GLfloat nz , GLfloat x , GLfloat y , GLfloat z)>("glColor4fNormal3fVertex3fSUN"); 
		DynamicGL_Color4fNormal3fVertex3fvSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *c , const GLfloat *n , const GLfloat *v)>("glColor4fNormal3fVertex3fvSUN"); 
		DynamicGL_TexCoord2fVertex3fSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat s , GLfloat t , GLfloat x , GLfloat y , GLfloat z)>("glTexCoord2fVertex3fSUN"); 
		DynamicGL_TexCoord2fVertex3fvSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *tc , const GLfloat *v)>("glTexCoord2fVertex3fvSUN"); 
		DynamicGL_TexCoord4fVertex4fSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat s , GLfloat t , GLfloat p , GLfloat q , GLfloat x , GLfloat y , GLfloat z , GLfloat w)>("glTexCoord4fVertex4fSUN"); 
		DynamicGL_TexCoord4fVertex4fvSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *tc , const GLfloat *v)>("glTexCoord4fVertex4fvSUN"); 
		DynamicGL_TexCoord2fColor4ubVertex3fSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat s , GLfloat t , GLubyte r , GLubyte g , GLubyte b , GLubyte a , GLfloat x , GLfloat y , GLfloat z)>("glTexCoord2fColor4ubVertex3fSUN"); 
		DynamicGL_TexCoord2fColor4ubVertex3fvSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *tc , const GLubyte *c , const GLfloat *v)>("glTexCoord2fColor4ubVertex3fvSUN"); 
		DynamicGL_TexCoord2fColor3fVertex3fSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat s , GLfloat t , GLfloat r , GLfloat g , GLfloat b , GLfloat x , GLfloat y , GLfloat z)>("glTexCoord2fColor3fVertex3fSUN"); 
		DynamicGL_TexCoord2fColor3fVertex3fvSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *tc , const GLfloat *c , const GLfloat *v)>("glTexCoord2fColor3fVertex3fvSUN"); 
		DynamicGL_TexCoord2fNormal3fVertex3fSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat s , GLfloat t , GLfloat nx , GLfloat ny , GLfloat nz , GLfloat x , GLfloat y , GLfloat z)>("glTexCoord2fNormal3fVertex3fSUN"); 
		DynamicGL_TexCoord2fNormal3fVertex3fvSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *tc , const GLfloat *n , const GLfloat *v)>("glTexCoord2fNormal3fVertex3fvSUN"); 
		DynamicGL_TexCoord2fColor4fNormal3fVertex3fSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat s , GLfloat t , GLfloat r , GLfloat g , GLfloat b , GLfloat a , GLfloat nx , GLfloat ny , GLfloat nz , GLfloat x , GLfloat y , GLfloat z)>("glTexCoord2fColor4fNormal3fVertex3fSUN"); 
		DynamicGL_TexCoord2fColor4fNormal3fVertex3fvSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *tc , const GLfloat *c , const GLfloat *n , const GLfloat *v)>("glTexCoord2fColor4fNormal3fVertex3fvSUN"); 
		DynamicGL_TexCoord4fColor4fNormal3fVertex4fSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat s , GLfloat t , GLfloat p , GLfloat q , GLfloat r , GLfloat g , GLfloat b , GLfloat a , GLfloat nx , GLfloat ny , GLfloat nz , GLfloat x , GLfloat y , GLfloat z , GLfloat w)>("glTexCoord4fColor4fNormal3fVertex4fSUN"); 
		DynamicGL_TexCoord4fColor4fNormal3fVertex4fvSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *tc , const GLfloat *c , const GLfloat *n , const GLfloat *v)>("glTexCoord4fColor4fNormal3fVertex4fvSUN"); 
		DynamicGL_ReplacementCodeuiVertex3fSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint rc , GLfloat x , GLfloat y , GLfloat z)>("glReplacementCodeuiVertex3fSUN"); 
		DynamicGL_ReplacementCodeuiVertex3fvSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLuint *rc , const GLfloat *v)>("glReplacementCodeuiVertex3fvSUN"); 
		DynamicGL_ReplacementCodeuiColor4ubVertex3fSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint rc , GLubyte r , GLubyte g , GLubyte b , GLubyte a , GLfloat x , GLfloat y , GLfloat z)>("glReplacementCodeuiColor4ubVertex3fSUN"); 
		DynamicGL_ReplacementCodeuiColor4ubVertex3fvSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLuint *rc , const GLubyte *c , const GLfloat *v)>("glReplacementCodeuiColor4ubVertex3fvSUN"); 
		DynamicGL_ReplacementCodeuiColor3fVertex3fSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint rc , GLfloat r , GLfloat g , GLfloat b , GLfloat x , GLfloat y , GLfloat z)>("glReplacementCodeuiColor3fVertex3fSUN"); 
		DynamicGL_ReplacementCodeuiColor3fVertex3fvSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLuint *rc , const GLfloat *c , const GLfloat *v)>("glReplacementCodeuiColor3fVertex3fvSUN"); 
		DynamicGL_ReplacementCodeuiNormal3fVertex3fSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint rc , GLfloat nx , GLfloat ny , GLfloat nz , GLfloat x , GLfloat y , GLfloat z)>("glReplacementCodeuiNormal3fVertex3fSUN"); 
		DynamicGL_ReplacementCodeuiNormal3fVertex3fvSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLuint *rc , const GLfloat *n , const GLfloat *v)>("glReplacementCodeuiNormal3fVertex3fvSUN"); 
		DynamicGL_ReplacementCodeuiColor4fNormal3fVertex3fSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint rc , GLfloat r , GLfloat g , GLfloat b , GLfloat a , GLfloat nx , GLfloat ny , GLfloat nz , GLfloat x , GLfloat y , GLfloat z)>("glReplacementCodeuiColor4fNormal3fVertex3fSUN"); 
		DynamicGL_ReplacementCodeuiColor4fNormal3fVertex3fvSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLuint *rc , const GLfloat *c , const GLfloat *n , const GLfloat *v)>("glReplacementCodeuiColor4fNormal3fVertex3fvSUN"); 
		DynamicGL_ReplacementCodeuiTexCoord2fVertex3fSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint rc , GLfloat s , GLfloat t , GLfloat x , GLfloat y , GLfloat z)>("glReplacementCodeuiTexCoord2fVertex3fSUN"); 
		DynamicGL_ReplacementCodeuiTexCoord2fVertex3fvSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLuint *rc , const GLfloat *tc , const GLfloat *v)>("glReplacementCodeuiTexCoord2fVertex3fvSUN"); 
		DynamicGL_ReplacementCodeuiTexCoord2fNormal3fVertex3fSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint rc , GLfloat s , GLfloat t , GLfloat nx , GLfloat ny , GLfloat nz , GLfloat x , GLfloat y , GLfloat z)>("glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN"); 
		DynamicGL_ReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLuint *rc , const GLfloat *tc , const GLfloat *n , const GLfloat *v)>("glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN"); 
		DynamicGL_ReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint rc , GLfloat s , GLfloat t , GLfloat r , GLfloat g , GLfloat b , GLfloat a , GLfloat nx , GLfloat ny , GLfloat nz , GLfloat x , GLfloat y , GLfloat z)>("glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN"); 
		DynamicGL_ReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLuint *rc , const GLfloat *tc , const GLfloat *c , const GLfloat *n , const GLfloat *v)>("glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN"); 
		DinamicGLFeature_SUN_vertex_loaded = true; 
}
bool DinamicGLFeature_SUN_vertex_Supported() {
		if (!DinamicGLFeature_SUN_vertex_loaded) {
			InitDinamicGLFeature_SUN_vertex();
		}
		if (DynamicGL_Color4ubVertex2fSUN==0) return false; 
		if (DynamicGL_Color4ubVertex2fvSUN==0) return false; 
		if (DynamicGL_Color4ubVertex3fSUN==0) return false; 
		if (DynamicGL_Color4ubVertex3fvSUN==0) return false; 
		if (DynamicGL_Color3fVertex3fSUN==0) return false; 
		if (DynamicGL_Color3fVertex3fvSUN==0) return false; 
		if (DynamicGL_Normal3fVertex3fSUN==0) return false; 
		if (DynamicGL_Normal3fVertex3fvSUN==0) return false; 
		if (DynamicGL_Color4fNormal3fVertex3fSUN==0) return false; 
		if (DynamicGL_Color4fNormal3fVertex3fvSUN==0) return false; 
		if (DynamicGL_TexCoord2fVertex3fSUN==0) return false; 
		if (DynamicGL_TexCoord2fVertex3fvSUN==0) return false; 
		if (DynamicGL_TexCoord4fVertex4fSUN==0) return false; 
		if (DynamicGL_TexCoord4fVertex4fvSUN==0) return false; 
		if (DynamicGL_TexCoord2fColor4ubVertex3fSUN==0) return false; 
		if (DynamicGL_TexCoord2fColor4ubVertex3fvSUN==0) return false; 
		if (DynamicGL_TexCoord2fColor3fVertex3fSUN==0) return false; 
		if (DynamicGL_TexCoord2fColor3fVertex3fvSUN==0) return false; 
		if (DynamicGL_TexCoord2fNormal3fVertex3fSUN==0) return false; 
		if (DynamicGL_TexCoord2fNormal3fVertex3fvSUN==0) return false; 
		if (DynamicGL_TexCoord2fColor4fNormal3fVertex3fSUN==0) return false; 
		if (DynamicGL_TexCoord2fColor4fNormal3fVertex3fvSUN==0) return false; 
		if (DynamicGL_TexCoord4fColor4fNormal3fVertex4fSUN==0) return false; 
		if (DynamicGL_TexCoord4fColor4fNormal3fVertex4fvSUN==0) return false; 
		if (DynamicGL_ReplacementCodeuiVertex3fSUN==0) return false; 
		if (DynamicGL_ReplacementCodeuiVertex3fvSUN==0) return false; 
		if (DynamicGL_ReplacementCodeuiColor4ubVertex3fSUN==0) return false; 
		if (DynamicGL_ReplacementCodeuiColor4ubVertex3fvSUN==0) return false; 
		if (DynamicGL_ReplacementCodeuiColor3fVertex3fSUN==0) return false; 
		if (DynamicGL_ReplacementCodeuiColor3fVertex3fvSUN==0) return false; 
		if (DynamicGL_ReplacementCodeuiNormal3fVertex3fSUN==0) return false; 
		if (DynamicGL_ReplacementCodeuiNormal3fVertex3fvSUN==0) return false; 
		if (DynamicGL_ReplacementCodeuiColor4fNormal3fVertex3fSUN==0) return false; 
		if (DynamicGL_ReplacementCodeuiColor4fNormal3fVertex3fvSUN==0) return false; 
		if (DynamicGL_ReplacementCodeuiTexCoord2fVertex3fSUN==0) return false; 
		if (DynamicGL_ReplacementCodeuiTexCoord2fVertex3fvSUN==0) return false; 
		if (DynamicGL_ReplacementCodeuiTexCoord2fNormal3fVertex3fSUN==0) return false; 
		if (DynamicGL_ReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN==0) return false; 
		if (DynamicGL_ReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN==0) return false; 
		if (DynamicGL_ReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN==0) return false; 
		return true;
}
#endif /*USE_DYNAMIC_GL_SUN_vertex*/

/*ARB_texture_mirrored_repeat*/
#ifdef USE_DYNAMIC_GL_ARB_texture_mirrored_repeat
static bool DinamicGLFeature_ARB_texture_mirrored_repeat_loaded = false; 
static void InitDinamicGLFeature_ARB_texture_mirrored_repeat() {
		DinamicGLFeature_ARB_texture_mirrored_repeat_loaded = true; 
}
bool DinamicGLFeature_ARB_texture_mirrored_repeat_Supported() {
		if (!DinamicGLFeature_ARB_texture_mirrored_repeat_loaded) {
			InitDinamicGLFeature_ARB_texture_mirrored_repeat();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_ARB_texture_mirrored_repeat*/

/*HP_texture_lighting*/
#ifdef USE_DYNAMIC_GL_HP_texture_lighting
static bool DinamicGLFeature_HP_texture_lighting_loaded = false; 
static void InitDinamicGLFeature_HP_texture_lighting() {
		DinamicGLFeature_HP_texture_lighting_loaded = true; 
}
bool DinamicGLFeature_HP_texture_lighting_Supported() {
		if (!DinamicGLFeature_HP_texture_lighting_loaded) {
			InitDinamicGLFeature_HP_texture_lighting();
		}
		return true;
}
#endif /*USE_DYNAMIC_GL_HP_texture_lighting*/

void InternalDynamicGLLoadSubset() {
#ifdef USE_DYNAMIC_GL_VERSION_1_1
			InitDinamicGLFeature_VERSION_1_1();
#endif /*USE_DYNAMIC_GL_VERSION_1_1*/
#ifdef USE_DYNAMIC_GL_SGIS_sharpen_texture
			InitDinamicGLFeature_SGIS_sharpen_texture();
#endif /*USE_DYNAMIC_GL_SGIS_sharpen_texture*/
#ifdef USE_DYNAMIC_GL_SGIX_blend_alpha_minmax
			InitDinamicGLFeature_SGIX_blend_alpha_minmax();
#endif /*USE_DYNAMIC_GL_SGIX_blend_alpha_minmax*/
#ifdef USE_DYNAMIC_GL_NV_present_video
			InitDinamicGLFeature_NV_present_video();
#endif /*USE_DYNAMIC_GL_NV_present_video*/
#ifdef USE_DYNAMIC_GL_SGIX_convolution_accuracy
			InitDinamicGLFeature_SGIX_convolution_accuracy();
#endif /*USE_DYNAMIC_GL_SGIX_convolution_accuracy*/
#ifdef USE_DYNAMIC_GL_EXT_bindable_uniform
			InitDinamicGLFeature_EXT_bindable_uniform();
#endif /*USE_DYNAMIC_GL_EXT_bindable_uniform*/
#ifdef USE_DYNAMIC_GL_SGIS_generate_mipmap
			InitDinamicGLFeature_SGIS_generate_mipmap();
#endif /*USE_DYNAMIC_GL_SGIS_generate_mipmap*/
#ifdef USE_DYNAMIC_GL_INTEL_parallel_arrays
			InitDinamicGLFeature_INTEL_parallel_arrays();
#endif /*USE_DYNAMIC_GL_INTEL_parallel_arrays*/
#ifdef USE_DYNAMIC_GL_ARB_multitexture
			InitDinamicGLFeature_ARB_multitexture();
#endif /*USE_DYNAMIC_GL_ARB_multitexture*/
#ifdef USE_DYNAMIC_GL_EXT_draw_range_elements
			InitDinamicGLFeature_EXT_draw_range_elements();
#endif /*USE_DYNAMIC_GL_EXT_draw_range_elements*/
#ifdef USE_DYNAMIC_GL_NV_evaluators
			InitDinamicGLFeature_NV_evaluators();
#endif /*USE_DYNAMIC_GL_NV_evaluators*/
#ifdef USE_DYNAMIC_GL_OML_interlace
			InitDinamicGLFeature_OML_interlace();
#endif /*USE_DYNAMIC_GL_OML_interlace*/
#ifdef USE_DYNAMIC_GL_ARB_texture_border_clamp
			InitDinamicGLFeature_ARB_texture_border_clamp();
#endif /*USE_DYNAMIC_GL_ARB_texture_border_clamp*/
#ifdef USE_DYNAMIC_GL_ARB_shadow_ambient
			InitDinamicGLFeature_ARB_shadow_ambient();
#endif /*USE_DYNAMIC_GL_ARB_shadow_ambient*/
#ifdef USE_DYNAMIC_GL_EXT_texture_compression_s3tc
			InitDinamicGLFeature_EXT_texture_compression_s3tc();
#endif /*USE_DYNAMIC_GL_EXT_texture_compression_s3tc*/
#ifdef USE_DYNAMIC_GL_EXT_secondary_color
			InitDinamicGLFeature_EXT_secondary_color();
#endif /*USE_DYNAMIC_GL_EXT_secondary_color*/
#ifdef USE_DYNAMIC_GL_SGIX_pixel_tiles
			InitDinamicGLFeature_SGIX_pixel_tiles();
#endif /*USE_DYNAMIC_GL_SGIX_pixel_tiles*/
#ifdef USE_DYNAMIC_GL_SGIX_scalebias_hint
			InitDinamicGLFeature_SGIX_scalebias_hint();
#endif /*USE_DYNAMIC_GL_SGIX_scalebias_hint*/
#ifdef USE_DYNAMIC_GL_EXT_texture_buffer_object
			InitDinamicGLFeature_EXT_texture_buffer_object();
#endif /*USE_DYNAMIC_GL_EXT_texture_buffer_object*/
#ifdef USE_DYNAMIC_GL_IBM_multimode_draw_arrays
			InitDinamicGLFeature_IBM_multimode_draw_arrays();
#endif /*USE_DYNAMIC_GL_IBM_multimode_draw_arrays*/
#ifdef USE_DYNAMIC_GL_EXT_framebuffer_object
			InitDinamicGLFeature_EXT_framebuffer_object();
#endif /*USE_DYNAMIC_GL_EXT_framebuffer_object*/
#ifdef USE_DYNAMIC_GL_ARB_draw_buffers
			InitDinamicGLFeature_ARB_draw_buffers();
#endif /*USE_DYNAMIC_GL_ARB_draw_buffers*/
#ifdef USE_DYNAMIC_GL_EXT_pixel_transform
			InitDinamicGLFeature_EXT_pixel_transform();
#endif /*USE_DYNAMIC_GL_EXT_pixel_transform*/
#ifdef USE_DYNAMIC_GL_EXT_index_material
			InitDinamicGLFeature_EXT_index_material();
#endif /*USE_DYNAMIC_GL_EXT_index_material*/
#ifdef USE_DYNAMIC_GL_SGIS_texture_filter4
			InitDinamicGLFeature_SGIS_texture_filter4();
#endif /*USE_DYNAMIC_GL_SGIS_texture_filter4*/
#ifdef USE_DYNAMIC_GL_APPLE_flush_buffer_range
			InitDinamicGLFeature_APPLE_flush_buffer_range();
#endif /*USE_DYNAMIC_GL_APPLE_flush_buffer_range*/
#ifdef USE_DYNAMIC_GL_SGIS_texture_color_mask
			InitDinamicGLFeature_SGIS_texture_color_mask();
#endif /*USE_DYNAMIC_GL_SGIS_texture_color_mask*/
#ifdef USE_DYNAMIC_GL_ARB_fragment_shader
			InitDinamicGLFeature_ARB_fragment_shader();
#endif /*USE_DYNAMIC_GL_ARB_fragment_shader*/
#ifdef USE_DYNAMIC_GL_GREMEDY_frame_terminator
			InitDinamicGLFeature_GREMEDY_frame_terminator();
#endif /*USE_DYNAMIC_GL_GREMEDY_frame_terminator*/
#ifdef USE_DYNAMIC_GL_ARB_shading_language_100
			InitDinamicGLFeature_ARB_shading_language_100();
#endif /*USE_DYNAMIC_GL_ARB_shading_language_100*/
#ifdef USE_DYNAMIC_GL_ARB_fragment_program
			InitDinamicGLFeature_ARB_fragment_program();
#endif /*USE_DYNAMIC_GL_ARB_fragment_program*/
#ifdef USE_DYNAMIC_GL_ARB_shader_objects
			InitDinamicGLFeature_ARB_shader_objects();
#endif /*USE_DYNAMIC_GL_ARB_shader_objects*/
#ifdef USE_DYNAMIC_GL_SGIX_reference_plane
			InitDinamicGLFeature_SGIX_reference_plane();
#endif /*USE_DYNAMIC_GL_SGIX_reference_plane*/
#ifdef USE_DYNAMIC_GL_HP_image_transform
			InitDinamicGLFeature_HP_image_transform();
#endif /*USE_DYNAMIC_GL_HP_image_transform*/
#ifdef USE_DYNAMIC_GL_EXT_direct_state_access
			InitDinamicGLFeature_EXT_direct_state_access();
#endif /*USE_DYNAMIC_GL_EXT_direct_state_access*/
#ifdef USE_DYNAMIC_GL_ARB_multisample
			InitDinamicGLFeature_ARB_multisample();
#endif /*USE_DYNAMIC_GL_ARB_multisample*/
#ifdef USE_DYNAMIC_GL_SGIX_fog_scale
			InitDinamicGLFeature_SGIX_fog_scale();
#endif /*USE_DYNAMIC_GL_SGIX_fog_scale*/
#ifdef USE_DYNAMIC_GL_ATI_texture_mirror_once
			InitDinamicGLFeature_ATI_texture_mirror_once();
#endif /*USE_DYNAMIC_GL_ATI_texture_mirror_once*/
#ifdef USE_DYNAMIC_GL_EXT_shared_texture_palette
			InitDinamicGLFeature_EXT_shared_texture_palette();
#endif /*USE_DYNAMIC_GL_EXT_shared_texture_palette*/
#ifdef USE_DYNAMIC_GL_ARB_texture_rg
			InitDinamicGLFeature_ARB_texture_rg();
#endif /*USE_DYNAMIC_GL_ARB_texture_rg*/
#ifdef USE_DYNAMIC_GL_EXT_stencil_clear_tag
			InitDinamicGLFeature_EXT_stencil_clear_tag();
#endif /*USE_DYNAMIC_GL_EXT_stencil_clear_tag*/
#ifdef USE_DYNAMIC_GL_SGIS_texture_select
			InitDinamicGLFeature_SGIS_texture_select();
#endif /*USE_DYNAMIC_GL_SGIS_texture_select*/
#ifdef USE_DYNAMIC_GL_NV_geometry_program4
			InitDinamicGLFeature_NV_geometry_program4();
#endif /*USE_DYNAMIC_GL_NV_geometry_program4*/
#ifdef USE_DYNAMIC_GL_ARB_framebuffer_sRGB
			InitDinamicGLFeature_ARB_framebuffer_sRGB();
#endif /*USE_DYNAMIC_GL_ARB_framebuffer_sRGB*/
#ifdef USE_DYNAMIC_GL_IBM_rasterpos_clip
			InitDinamicGLFeature_IBM_rasterpos_clip();
#endif /*USE_DYNAMIC_GL_IBM_rasterpos_clip*/
#ifdef USE_DYNAMIC_GL_MESA_ycbcr_texture
			InitDinamicGLFeature_MESA_ycbcr_texture();
#endif /*USE_DYNAMIC_GL_MESA_ycbcr_texture*/
#ifdef USE_DYNAMIC_GL_ATI_vertex_streams
			InitDinamicGLFeature_ATI_vertex_streams();
#endif /*USE_DYNAMIC_GL_ATI_vertex_streams*/
#ifdef USE_DYNAMIC_GL_3DFX_texture_compression_FXT1
			InitDinamicGLFeature_3DFX_texture_compression_FXT1();
#endif /*USE_DYNAMIC_GL_3DFX_texture_compression_FXT1*/
#ifdef USE_DYNAMIC_GL_SGIX_shadow_ambient
			InitDinamicGLFeature_SGIX_shadow_ambient();
#endif /*USE_DYNAMIC_GL_SGIX_shadow_ambient*/
#ifdef USE_DYNAMIC_GL_EXT_blend_color
			InitDinamicGLFeature_EXT_blend_color();
#endif /*USE_DYNAMIC_GL_EXT_blend_color*/
#ifdef USE_DYNAMIC_GL_ARB_shadow
			InitDinamicGLFeature_ARB_shadow();
#endif /*USE_DYNAMIC_GL_ARB_shadow*/
#ifdef USE_DYNAMIC_GL_EXT_stencil_wrap
			InitDinamicGLFeature_EXT_stencil_wrap();
#endif /*USE_DYNAMIC_GL_EXT_stencil_wrap*/
#ifdef USE_DYNAMIC_GL_NV_vertex_array_range2
			InitDinamicGLFeature_NV_vertex_array_range2();
#endif /*USE_DYNAMIC_GL_NV_vertex_array_range2*/
#ifdef USE_DYNAMIC_GL_EXT_bgra
			InitDinamicGLFeature_EXT_bgra();
#endif /*USE_DYNAMIC_GL_EXT_bgra*/
#ifdef USE_DYNAMIC_GL_ARB_framebuffer_object
			InitDinamicGLFeature_ARB_framebuffer_object();
#endif /*USE_DYNAMIC_GL_ARB_framebuffer_object*/
#ifdef USE_DYNAMIC_GL_SGIX_async
			InitDinamicGLFeature_SGIX_async();
#endif /*USE_DYNAMIC_GL_SGIX_async*/
#ifdef USE_DYNAMIC_GL_SGI_texture_color_table
			InitDinamicGLFeature_SGI_texture_color_table();
#endif /*USE_DYNAMIC_GL_SGI_texture_color_table*/
#ifdef USE_DYNAMIC_GL_EXT_subtexture
			InitDinamicGLFeature_EXT_subtexture();
#endif /*USE_DYNAMIC_GL_EXT_subtexture*/
#ifdef USE_DYNAMIC_GL_SGIX_subsample
			InitDinamicGLFeature_SGIX_subsample();
#endif /*USE_DYNAMIC_GL_SGIX_subsample*/
#ifdef USE_DYNAMIC_GL_GREMEDY_string_marker
			InitDinamicGLFeature_GREMEDY_string_marker();
#endif /*USE_DYNAMIC_GL_GREMEDY_string_marker*/
#ifdef USE_DYNAMIC_GL_ARB_draw_instanced
			InitDinamicGLFeature_ARB_draw_instanced();
#endif /*USE_DYNAMIC_GL_ARB_draw_instanced*/
#ifdef USE_DYNAMIC_GL_ARB_occlusion_query
			InitDinamicGLFeature_ARB_occlusion_query();
#endif /*USE_DYNAMIC_GL_ARB_occlusion_query*/
#ifdef USE_DYNAMIC_GL_ATI_fragment_shader
			InitDinamicGLFeature_ATI_fragment_shader();
#endif /*USE_DYNAMIC_GL_ATI_fragment_shader*/
#ifdef USE_DYNAMIC_GL_NV_depth_buffer_float
			InitDinamicGLFeature_NV_depth_buffer_float();
#endif /*USE_DYNAMIC_GL_NV_depth_buffer_float*/
#ifdef USE_DYNAMIC_GL_NV_pixel_data_range
			InitDinamicGLFeature_NV_pixel_data_range();
#endif /*USE_DYNAMIC_GL_NV_pixel_data_range*/
#ifdef USE_DYNAMIC_GL_SGI_color_matrix
			InitDinamicGLFeature_SGI_color_matrix();
#endif /*USE_DYNAMIC_GL_SGI_color_matrix*/
#ifdef USE_DYNAMIC_GL_EXT_texture_sRGB
			InitDinamicGLFeature_EXT_texture_sRGB();
#endif /*USE_DYNAMIC_GL_EXT_texture_sRGB*/
#ifdef USE_DYNAMIC_GL_NV_depth_clamp
			InitDinamicGLFeature_NV_depth_clamp();
#endif /*USE_DYNAMIC_GL_NV_depth_clamp*/
#ifdef USE_DYNAMIC_GL_ARB_half_float_vertex
			InitDinamicGLFeature_ARB_half_float_vertex();
#endif /*USE_DYNAMIC_GL_ARB_half_float_vertex*/
#ifdef USE_DYNAMIC_GL_NV_vertex_program
			InitDinamicGLFeature_NV_vertex_program();
#endif /*USE_DYNAMIC_GL_NV_vertex_program*/
#ifdef USE_DYNAMIC_GL_MESA_window_pos
			InitDinamicGLFeature_MESA_window_pos();
#endif /*USE_DYNAMIC_GL_MESA_window_pos*/
#ifdef USE_DYNAMIC_GL_EXT_texture
			InitDinamicGLFeature_EXT_texture();
#endif /*USE_DYNAMIC_GL_EXT_texture*/
#ifdef USE_DYNAMIC_GL_SGIX_tag_sample_buffer
			InitDinamicGLFeature_SGIX_tag_sample_buffer();
#endif /*USE_DYNAMIC_GL_SGIX_tag_sample_buffer*/
#ifdef USE_DYNAMIC_GL_EXT_texture_env_combine
			InitDinamicGLFeature_EXT_texture_env_combine();
#endif /*USE_DYNAMIC_GL_EXT_texture_env_combine*/
#ifdef USE_DYNAMIC_GL_SGIX_vertex_preclip
			InitDinamicGLFeature_SGIX_vertex_preclip();
#endif /*USE_DYNAMIC_GL_SGIX_vertex_preclip*/
#ifdef USE_DYNAMIC_GL_ARB_geometry_shader4
			InitDinamicGLFeature_ARB_geometry_shader4();
#endif /*USE_DYNAMIC_GL_ARB_geometry_shader4*/
#ifdef USE_DYNAMIC_GL_EXT_multi_draw_arrays
			InitDinamicGLFeature_EXT_multi_draw_arrays();
#endif /*USE_DYNAMIC_GL_EXT_multi_draw_arrays*/
#ifdef USE_DYNAMIC_GL_EXT_texture_perturb_normal
			InitDinamicGLFeature_EXT_texture_perturb_normal();
#endif /*USE_DYNAMIC_GL_EXT_texture_perturb_normal*/
#ifdef USE_DYNAMIC_GL_SGIX_sprite
			InitDinamicGLFeature_SGIX_sprite();
#endif /*USE_DYNAMIC_GL_SGIX_sprite*/
#ifdef USE_DYNAMIC_GL_EXT_draw_buffers2
			InitDinamicGLFeature_EXT_draw_buffers2();
#endif /*USE_DYNAMIC_GL_EXT_draw_buffers2*/
#ifdef USE_DYNAMIC_GL_ARB_texture_rectangle
			InitDinamicGLFeature_ARB_texture_rectangle();
#endif /*USE_DYNAMIC_GL_ARB_texture_rectangle*/
#ifdef USE_DYNAMIC_GL_EXT_packed_pixels
			InitDinamicGLFeature_EXT_packed_pixels();
#endif /*USE_DYNAMIC_GL_EXT_packed_pixels*/
#ifdef USE_DYNAMIC_GL_EXT_texture_env_dot3
			InitDinamicGLFeature_EXT_texture_env_dot3();
#endif /*USE_DYNAMIC_GL_EXT_texture_env_dot3*/
#ifdef USE_DYNAMIC_GL_WIN_phong_shading
			InitDinamicGLFeature_WIN_phong_shading();
#endif /*USE_DYNAMIC_GL_WIN_phong_shading*/
#ifdef USE_DYNAMIC_GL_ARB_map_buffer_range
			InitDinamicGLFeature_ARB_map_buffer_range();
#endif /*USE_DYNAMIC_GL_ARB_map_buffer_range*/
#ifdef USE_DYNAMIC_GL_EXT_abgr
			InitDinamicGLFeature_EXT_abgr();
#endif /*USE_DYNAMIC_GL_EXT_abgr*/
#ifdef USE_DYNAMIC_GL_EXT_vertex_shader
			InitDinamicGLFeature_EXT_vertex_shader();
#endif /*USE_DYNAMIC_GL_EXT_vertex_shader*/
#ifdef USE_DYNAMIC_GL_NV_packed_depth_stencil
			InitDinamicGLFeature_NV_packed_depth_stencil();
#endif /*USE_DYNAMIC_GL_NV_packed_depth_stencil*/
#ifdef USE_DYNAMIC_GL_SGI_color_table
			InitDinamicGLFeature_SGI_color_table();
#endif /*USE_DYNAMIC_GL_SGI_color_table*/
#ifdef USE_DYNAMIC_GL_EXT_texture_array
			InitDinamicGLFeature_EXT_texture_array();
#endif /*USE_DYNAMIC_GL_EXT_texture_array*/
#ifdef USE_DYNAMIC_GL_EXT_texture_object
			InitDinamicGLFeature_EXT_texture_object();
#endif /*USE_DYNAMIC_GL_EXT_texture_object*/
#ifdef USE_DYNAMIC_GL_ATI_texture_env_combine3
			InitDinamicGLFeature_ATI_texture_env_combine3();
#endif /*USE_DYNAMIC_GL_ATI_texture_env_combine3*/
#ifdef USE_DYNAMIC_GL_EXT_geometry_shader4
			InitDinamicGLFeature_EXT_geometry_shader4();
#endif /*USE_DYNAMIC_GL_EXT_geometry_shader4*/
#ifdef USE_DYNAMIC_GL_ARB_transpose_matrix
			InitDinamicGLFeature_ARB_transpose_matrix();
#endif /*USE_DYNAMIC_GL_ARB_transpose_matrix*/
#ifdef USE_DYNAMIC_GL_NV_parameter_buffer_object
			InitDinamicGLFeature_NV_parameter_buffer_object();
#endif /*USE_DYNAMIC_GL_NV_parameter_buffer_object*/
#ifdef USE_DYNAMIC_GL_EXT_packed_depth_stencil
			InitDinamicGLFeature_EXT_packed_depth_stencil();
#endif /*USE_DYNAMIC_GL_EXT_packed_depth_stencil*/
#ifdef USE_DYNAMIC_GL_PGI_vertex_hints
			InitDinamicGLFeature_PGI_vertex_hints();
#endif /*USE_DYNAMIC_GL_PGI_vertex_hints*/
#ifdef USE_DYNAMIC_GL_EXT_vertex_weighting
			InitDinamicGLFeature_EXT_vertex_weighting();
#endif /*USE_DYNAMIC_GL_EXT_vertex_weighting*/
#ifdef USE_DYNAMIC_GL_ARB_texture_env_dot3
			InitDinamicGLFeature_ARB_texture_env_dot3();
#endif /*USE_DYNAMIC_GL_ARB_texture_env_dot3*/
#ifdef USE_DYNAMIC_GL_EXT_histogram
			InitDinamicGLFeature_EXT_histogram();
#endif /*USE_DYNAMIC_GL_EXT_histogram*/
#ifdef USE_DYNAMIC_GL_SGIX_pixel_texture
			InitDinamicGLFeature_SGIX_pixel_texture();
#endif /*USE_DYNAMIC_GL_SGIX_pixel_texture*/
#ifdef USE_DYNAMIC_GL_NV_fog_distance
			InitDinamicGLFeature_NV_fog_distance();
#endif /*USE_DYNAMIC_GL_NV_fog_distance*/
#ifdef USE_DYNAMIC_GL_APPLE_fence
			InitDinamicGLFeature_APPLE_fence();
#endif /*USE_DYNAMIC_GL_APPLE_fence*/
#ifdef USE_DYNAMIC_GL_EXT_blend_func_separate
			InitDinamicGLFeature_EXT_blend_func_separate();
#endif /*USE_DYNAMIC_GL_EXT_blend_func_separate*/
#ifdef USE_DYNAMIC_GL_SGIS_texture_border_clamp
			InitDinamicGLFeature_SGIS_texture_border_clamp();
#endif /*USE_DYNAMIC_GL_SGIS_texture_border_clamp*/
#ifdef USE_DYNAMIC_GL_EXT_gpu_program_parameters
			InitDinamicGLFeature_EXT_gpu_program_parameters();
#endif /*USE_DYNAMIC_GL_EXT_gpu_program_parameters*/
#ifdef USE_DYNAMIC_GL_SGIX_texture_add_env
			InitDinamicGLFeature_SGIX_texture_add_env();
#endif /*USE_DYNAMIC_GL_SGIX_texture_add_env*/
#ifdef USE_DYNAMIC_GL_EXT_paletted_texture
			InitDinamicGLFeature_EXT_paletted_texture();
#endif /*USE_DYNAMIC_GL_EXT_paletted_texture*/
#ifdef USE_DYNAMIC_GL_EXT_light_texture
			InitDinamicGLFeature_EXT_light_texture();
#endif /*USE_DYNAMIC_GL_EXT_light_texture*/
#ifdef USE_DYNAMIC_GL_EXT_multisample
			InitDinamicGLFeature_EXT_multisample();
#endif /*USE_DYNAMIC_GL_EXT_multisample*/
#ifdef USE_DYNAMIC_GL_SGIX_resample
			InitDinamicGLFeature_SGIX_resample();
#endif /*USE_DYNAMIC_GL_SGIX_resample*/
#ifdef USE_DYNAMIC_GL_ARB_vertex_program
			InitDinamicGLFeature_ARB_vertex_program();
#endif /*USE_DYNAMIC_GL_ARB_vertex_program*/
#ifdef USE_DYNAMIC_GL_EXT_point_parameters
			InitDinamicGLFeature_EXT_point_parameters();
#endif /*USE_DYNAMIC_GL_EXT_point_parameters*/
#ifdef USE_DYNAMIC_GL_ATI_map_object_buffer
			InitDinamicGLFeature_ATI_map_object_buffer();
#endif /*USE_DYNAMIC_GL_ATI_map_object_buffer*/
#ifdef USE_DYNAMIC_GL_MESAX_texture_stack
			InitDinamicGLFeature_MESAX_texture_stack();
#endif /*USE_DYNAMIC_GL_MESAX_texture_stack*/
#ifdef USE_DYNAMIC_GL_SGIS_pixel_texture
			InitDinamicGLFeature_SGIS_pixel_texture();
#endif /*USE_DYNAMIC_GL_SGIS_pixel_texture*/
#ifdef USE_DYNAMIC_GL_SGIS_texture4D
			InitDinamicGLFeature_SGIS_texture4D();
#endif /*USE_DYNAMIC_GL_SGIS_texture4D*/
#ifdef USE_DYNAMIC_GL_SGIS_multisample
			InitDinamicGLFeature_SGIS_multisample();
#endif /*USE_DYNAMIC_GL_SGIS_multisample*/
#ifdef USE_DYNAMIC_GL_PGI_misc_hints
			InitDinamicGLFeature_PGI_misc_hints();
#endif /*USE_DYNAMIC_GL_PGI_misc_hints*/
#ifdef USE_DYNAMIC_GL_ARB_window_pos
			InitDinamicGLFeature_ARB_window_pos();
#endif /*USE_DYNAMIC_GL_ARB_window_pos*/
#ifdef USE_DYNAMIC_GL_SGIX_polynomial_ffd
			InitDinamicGLFeature_SGIX_polynomial_ffd();
#endif /*USE_DYNAMIC_GL_SGIX_polynomial_ffd*/
#ifdef USE_DYNAMIC_GL_EXT_timer_query
			InitDinamicGLFeature_EXT_timer_query();
#endif /*USE_DYNAMIC_GL_EXT_timer_query*/
#ifdef USE_DYNAMIC_GL_SGIX_ir_instrument1
			InitDinamicGLFeature_SGIX_ir_instrument1();
#endif /*USE_DYNAMIC_GL_SGIX_ir_instrument1*/
#ifdef USE_DYNAMIC_GL_SGIX_igloo_interface
			InitDinamicGLFeature_SGIX_igloo_interface();
#endif /*USE_DYNAMIC_GL_SGIX_igloo_interface*/
#ifdef USE_DYNAMIC_GL_NV_fence
			InitDinamicGLFeature_NV_fence();
#endif /*USE_DYNAMIC_GL_NV_fence*/
#ifdef USE_DYNAMIC_GL_NV_register_combiners
			InitDinamicGLFeature_NV_register_combiners();
#endif /*USE_DYNAMIC_GL_NV_register_combiners*/
#ifdef USE_DYNAMIC_GL_VERSION_3_0
			InitDinamicGLFeature_VERSION_3_0();
#endif /*USE_DYNAMIC_GL_VERSION_3_0*/
#ifdef USE_DYNAMIC_GL_NV_point_sprite
			InitDinamicGLFeature_NV_point_sprite();
#endif /*USE_DYNAMIC_GL_NV_point_sprite*/
#ifdef USE_DYNAMIC_GL_EXT_texture_compression_latc
			InitDinamicGLFeature_EXT_texture_compression_latc();
#endif /*USE_DYNAMIC_GL_EXT_texture_compression_latc*/
#ifdef USE_DYNAMIC_GL_ARB_instanced_arrays
			InitDinamicGLFeature_ARB_instanced_arrays();
#endif /*USE_DYNAMIC_GL_ARB_instanced_arrays*/
#ifdef USE_DYNAMIC_GL_EXT_transform_feedback
			InitDinamicGLFeature_EXT_transform_feedback();
#endif /*USE_DYNAMIC_GL_EXT_transform_feedback*/
#ifdef USE_DYNAMIC_GL_INGR_color_clamp
			InitDinamicGLFeature_INGR_color_clamp();
#endif /*USE_DYNAMIC_GL_INGR_color_clamp*/
#ifdef USE_DYNAMIC_GL_ARB_depth_buffer_float
			InitDinamicGLFeature_ARB_depth_buffer_float();
#endif /*USE_DYNAMIC_GL_ARB_depth_buffer_float*/
#ifdef USE_DYNAMIC_GL_NV_texture_shader3
			InitDinamicGLFeature_NV_texture_shader3();
#endif /*USE_DYNAMIC_GL_NV_texture_shader3*/
#ifdef USE_DYNAMIC_GL_ARB_texture_compression_rgtc
			InitDinamicGLFeature_ARB_texture_compression_rgtc();
#endif /*USE_DYNAMIC_GL_ARB_texture_compression_rgtc*/
#ifdef USE_DYNAMIC_GL_EXT_framebuffer_blit
			InitDinamicGLFeature_EXT_framebuffer_blit();
#endif /*USE_DYNAMIC_GL_EXT_framebuffer_blit*/
#ifdef USE_DYNAMIC_GL_OML_resample
			InitDinamicGLFeature_OML_resample();
#endif /*USE_DYNAMIC_GL_OML_resample*/
#ifdef USE_DYNAMIC_GL_EXT_cmyka
			InitDinamicGLFeature_EXT_cmyka();
#endif /*USE_DYNAMIC_GL_EXT_cmyka*/
#ifdef USE_DYNAMIC_GL_SUN_convolution_border_modes
			InitDinamicGLFeature_SUN_convolution_border_modes();
#endif /*USE_DYNAMIC_GL_SUN_convolution_border_modes*/
#ifdef USE_DYNAMIC_GL_EXT_draw_instanced
			InitDinamicGLFeature_EXT_draw_instanced();
#endif /*USE_DYNAMIC_GL_EXT_draw_instanced*/
#ifdef USE_DYNAMIC_GL_SGIS_detail_texture
			InitDinamicGLFeature_SGIS_detail_texture();
#endif /*USE_DYNAMIC_GL_SGIS_detail_texture*/
#ifdef USE_DYNAMIC_GL_MESA_resize_buffers
			InitDinamicGLFeature_MESA_resize_buffers();
#endif /*USE_DYNAMIC_GL_MESA_resize_buffers*/
#ifdef USE_DYNAMIC_GL_SUN_global_alpha
			InitDinamicGLFeature_SUN_global_alpha();
#endif /*USE_DYNAMIC_GL_SUN_global_alpha*/
#ifdef USE_DYNAMIC_GL_ARB_depth_texture
			InitDinamicGLFeature_ARB_depth_texture();
#endif /*USE_DYNAMIC_GL_ARB_depth_texture*/
#ifdef USE_DYNAMIC_GL_HP_convolution_border_modes
			InitDinamicGLFeature_HP_convolution_border_modes();
#endif /*USE_DYNAMIC_GL_HP_convolution_border_modes*/
#ifdef USE_DYNAMIC_GL_NV_fragment_program
			InitDinamicGLFeature_NV_fragment_program();
#endif /*USE_DYNAMIC_GL_NV_fragment_program*/
#ifdef USE_DYNAMIC_GL_NV_texture_env_combine4
			InitDinamicGLFeature_NV_texture_env_combine4();
#endif /*USE_DYNAMIC_GL_NV_texture_env_combine4*/
#ifdef USE_DYNAMIC_GL_ARB_texture_buffer_object
			InitDinamicGLFeature_ARB_texture_buffer_object();
#endif /*USE_DYNAMIC_GL_ARB_texture_buffer_object*/
#ifdef USE_DYNAMIC_GL_SGIX_flush_raster
			InitDinamicGLFeature_SGIX_flush_raster();
#endif /*USE_DYNAMIC_GL_SGIX_flush_raster*/
#ifdef USE_DYNAMIC_GL_SGIS_fog_function
			InitDinamicGLFeature_SGIS_fog_function();
#endif /*USE_DYNAMIC_GL_SGIS_fog_function*/
#ifdef USE_DYNAMIC_GL_VERSION_2_0
			InitDinamicGLFeature_VERSION_2_0();
#endif /*USE_DYNAMIC_GL_VERSION_2_0*/
#ifdef USE_DYNAMIC_GL_EXT_compiled_vertex_array
			InitDinamicGLFeature_EXT_compiled_vertex_array();
#endif /*USE_DYNAMIC_GL_EXT_compiled_vertex_array*/
#ifdef USE_DYNAMIC_GL_IBM_texture_mirrored_repeat
			InitDinamicGLFeature_IBM_texture_mirrored_repeat();
#endif /*USE_DYNAMIC_GL_IBM_texture_mirrored_repeat*/
#ifdef USE_DYNAMIC_GL_OML_subsample
			InitDinamicGLFeature_OML_subsample();
#endif /*USE_DYNAMIC_GL_OML_subsample*/
#ifdef USE_DYNAMIC_GL_NV_texgen_reflection
			InitDinamicGLFeature_NV_texgen_reflection();
#endif /*USE_DYNAMIC_GL_NV_texgen_reflection*/
#ifdef USE_DYNAMIC_GL_SGIX_list_priority
			InitDinamicGLFeature_SGIX_list_priority();
#endif /*USE_DYNAMIC_GL_SGIX_list_priority*/
#ifdef USE_DYNAMIC_GL_NV_occlusion_query
			InitDinamicGLFeature_NV_occlusion_query();
#endif /*USE_DYNAMIC_GL_NV_occlusion_query*/
#ifdef USE_DYNAMIC_GL_VERSION_1_3
			InitDinamicGLFeature_VERSION_1_3();
#endif /*USE_DYNAMIC_GL_VERSION_1_3*/
#ifdef USE_DYNAMIC_GL_ARB_color_buffer_float
			InitDinamicGLFeature_ARB_color_buffer_float();
#endif /*USE_DYNAMIC_GL_ARB_color_buffer_float*/
#ifdef USE_DYNAMIC_GL_EXT_texture_shared_exponent
			InitDinamicGLFeature_EXT_texture_shared_exponent();
#endif /*USE_DYNAMIC_GL_EXT_texture_shared_exponent*/
#ifdef USE_DYNAMIC_GL_NV_half_float
			InitDinamicGLFeature_NV_half_float();
#endif /*USE_DYNAMIC_GL_NV_half_float*/
#ifdef USE_DYNAMIC_GL_EXT_gpu_shader4
			InitDinamicGLFeature_EXT_gpu_shader4();
#endif /*USE_DYNAMIC_GL_EXT_gpu_shader4*/
#ifdef USE_DYNAMIC_GL_NV_light_max_exponent
			InitDinamicGLFeature_NV_light_max_exponent();
#endif /*USE_DYNAMIC_GL_NV_light_max_exponent*/
#ifdef USE_DYNAMIC_GL_INGR_interlace_read
			InitDinamicGLFeature_INGR_interlace_read();
#endif /*USE_DYNAMIC_GL_INGR_interlace_read*/
#ifdef USE_DYNAMIC_GL_ATI_pn_triangles
			InitDinamicGLFeature_ATI_pn_triangles();
#endif /*USE_DYNAMIC_GL_ATI_pn_triangles*/
#ifdef USE_DYNAMIC_GL_APPLE_ycbcr_422
			InitDinamicGLFeature_APPLE_ycbcr_422();
#endif /*USE_DYNAMIC_GL_APPLE_ycbcr_422*/
#ifdef USE_DYNAMIC_GL_3DFX_tbuffer
			InitDinamicGLFeature_3DFX_tbuffer();
#endif /*USE_DYNAMIC_GL_3DFX_tbuffer*/
#ifdef USE_DYNAMIC_GL_ARB_texture_float
			InitDinamicGLFeature_ARB_texture_float();
#endif /*USE_DYNAMIC_GL_ARB_texture_float*/
#ifdef USE_DYNAMIC_GL_NV_texture_expand_normal
			InitDinamicGLFeature_NV_texture_expand_normal();
#endif /*USE_DYNAMIC_GL_NV_texture_expand_normal*/
#ifdef USE_DYNAMIC_GL_REND_screen_coordinates
			InitDinamicGLFeature_REND_screen_coordinates();
#endif /*USE_DYNAMIC_GL_REND_screen_coordinates*/
#ifdef USE_DYNAMIC_GL_EXT_framebuffer_sRGB
			InitDinamicGLFeature_EXT_framebuffer_sRGB();
#endif /*USE_DYNAMIC_GL_EXT_framebuffer_sRGB*/
#ifdef USE_DYNAMIC_GL_SGIX_texture_multi_buffer
			InitDinamicGLFeature_SGIX_texture_multi_buffer();
#endif /*USE_DYNAMIC_GL_SGIX_texture_multi_buffer*/
#ifdef USE_DYNAMIC_GL_ARB_imaging
			InitDinamicGLFeature_ARB_imaging();
#endif /*USE_DYNAMIC_GL_ARB_imaging*/
#ifdef USE_DYNAMIC_GL_EXT_index_func
			InitDinamicGLFeature_EXT_index_func();
#endif /*USE_DYNAMIC_GL_EXT_index_func*/
#ifdef USE_DYNAMIC_GL_NV_multisample_filter_hint
			InitDinamicGLFeature_NV_multisample_filter_hint();
#endif /*USE_DYNAMIC_GL_NV_multisample_filter_hint*/
#ifdef USE_DYNAMIC_GL_SGIX_framezoom
			InitDinamicGLFeature_SGIX_framezoom();
#endif /*USE_DYNAMIC_GL_SGIX_framezoom*/
#ifdef USE_DYNAMIC_GL_SUNX_constant_data
			InitDinamicGLFeature_SUNX_constant_data();
#endif /*USE_DYNAMIC_GL_SUNX_constant_data*/
#ifdef USE_DYNAMIC_GL_HP_occlusion_test
			InitDinamicGLFeature_HP_occlusion_test();
#endif /*USE_DYNAMIC_GL_HP_occlusion_test*/
#ifdef USE_DYNAMIC_GL_SGIX_interlace
			InitDinamicGLFeature_SGIX_interlace();
#endif /*USE_DYNAMIC_GL_SGIX_interlace*/
#ifdef USE_DYNAMIC_GL_ATI_pixel_format_float
			InitDinamicGLFeature_ATI_pixel_format_float();
#endif /*USE_DYNAMIC_GL_ATI_pixel_format_float*/
#ifdef USE_DYNAMIC_GL_ARB_point_sprite
			InitDinamicGLFeature_ARB_point_sprite();
#endif /*USE_DYNAMIC_GL_ARB_point_sprite*/
#ifdef USE_DYNAMIC_GL_NV_gpu_program4
			InitDinamicGLFeature_NV_gpu_program4();
#endif /*USE_DYNAMIC_GL_NV_gpu_program4*/
#ifdef USE_DYNAMIC_GL_SUN_mesh_array
			InitDinamicGLFeature_SUN_mesh_array();
#endif /*USE_DYNAMIC_GL_SUN_mesh_array*/
#ifdef USE_DYNAMIC_GL_NV_texgen_emboss
			InitDinamicGLFeature_NV_texgen_emboss();
#endif /*USE_DYNAMIC_GL_NV_texgen_emboss*/
#ifdef USE_DYNAMIC_GL_NV_framebuffer_multisample_coverage
			InitDinamicGLFeature_NV_framebuffer_multisample_coverage();
#endif /*USE_DYNAMIC_GL_NV_framebuffer_multisample_coverage*/
#ifdef USE_DYNAMIC_GL_EXT_separate_specular_color
			InitDinamicGLFeature_EXT_separate_specular_color();
#endif /*USE_DYNAMIC_GL_EXT_separate_specular_color*/
#ifdef USE_DYNAMIC_GL_EXT_blend_subtract
			InitDinamicGLFeature_EXT_blend_subtract();
#endif /*USE_DYNAMIC_GL_EXT_blend_subtract*/
#ifdef USE_DYNAMIC_GL_SGIX_texture_scale_bias
			InitDinamicGLFeature_SGIX_texture_scale_bias();
#endif /*USE_DYNAMIC_GL_SGIX_texture_scale_bias*/
#ifdef USE_DYNAMIC_GL_APPLE_vertex_array_object
			InitDinamicGLFeature_APPLE_vertex_array_object();
#endif /*USE_DYNAMIC_GL_APPLE_vertex_array_object*/
#ifdef USE_DYNAMIC_GL_EXT_copy_texture
			InitDinamicGLFeature_EXT_copy_texture();
#endif /*USE_DYNAMIC_GL_EXT_copy_texture*/
#ifdef USE_DYNAMIC_GL_EXT_texture_cube_map
			InitDinamicGLFeature_EXT_texture_cube_map();
#endif /*USE_DYNAMIC_GL_EXT_texture_cube_map*/
#ifdef USE_DYNAMIC_GL_EXT_coordinate_frame
			InitDinamicGLFeature_EXT_coordinate_frame();
#endif /*USE_DYNAMIC_GL_EXT_coordinate_frame*/
#ifdef USE_DYNAMIC_GL_3DFX_multisample
			InitDinamicGLFeature_3DFX_multisample();
#endif /*USE_DYNAMIC_GL_3DFX_multisample*/
#ifdef USE_DYNAMIC_GL_SGIX_ycrcb
			InitDinamicGLFeature_SGIX_ycrcb();
#endif /*USE_DYNAMIC_GL_SGIX_ycrcb*/
#ifdef USE_DYNAMIC_GL_SGIX_async_histogram
			InitDinamicGLFeature_SGIX_async_histogram();
#endif /*USE_DYNAMIC_GL_SGIX_async_histogram*/
#ifdef USE_DYNAMIC_GL_SGIX_depth_texture
			InitDinamicGLFeature_SGIX_depth_texture();
#endif /*USE_DYNAMIC_GL_SGIX_depth_texture*/
#ifdef USE_DYNAMIC_GL_EXT_stencil_two_side
			InitDinamicGLFeature_EXT_stencil_two_side();
#endif /*USE_DYNAMIC_GL_EXT_stencil_two_side*/
#ifdef USE_DYNAMIC_GL_MESA_pack_invert
			InitDinamicGLFeature_MESA_pack_invert();
#endif /*USE_DYNAMIC_GL_MESA_pack_invert*/
#ifdef USE_DYNAMIC_GL_SGIX_texture_lod_bias
			InitDinamicGLFeature_SGIX_texture_lod_bias();
#endif /*USE_DYNAMIC_GL_SGIX_texture_lod_bias*/
#ifdef USE_DYNAMIC_GL_EXT_framebuffer_multisample
			InitDinamicGLFeature_EXT_framebuffer_multisample();
#endif /*USE_DYNAMIC_GL_EXT_framebuffer_multisample*/
#ifdef USE_DYNAMIC_GL_EXT_texture_filter_anisotropic
			InitDinamicGLFeature_EXT_texture_filter_anisotropic();
#endif /*USE_DYNAMIC_GL_EXT_texture_filter_anisotropic*/
#ifdef USE_DYNAMIC_GL_ARB_matrix_palette
			InitDinamicGLFeature_ARB_matrix_palette();
#endif /*USE_DYNAMIC_GL_ARB_matrix_palette*/
#ifdef USE_DYNAMIC_GL_NV_texture_shader2
			InitDinamicGLFeature_NV_texture_shader2();
#endif /*USE_DYNAMIC_GL_NV_texture_shader2*/
#ifdef USE_DYNAMIC_GL_ARB_texture_env_combine
			InitDinamicGLFeature_ARB_texture_env_combine();
#endif /*USE_DYNAMIC_GL_ARB_texture_env_combine*/
#ifdef USE_DYNAMIC_GL_ATI_element_array
			InitDinamicGLFeature_ATI_element_array();
#endif /*USE_DYNAMIC_GL_ATI_element_array*/
#ifdef USE_DYNAMIC_GL_EXT_blend_equation_separate
			InitDinamicGLFeature_EXT_blend_equation_separate();
#endif /*USE_DYNAMIC_GL_EXT_blend_equation_separate*/
#ifdef USE_DYNAMIC_GL_VERSION_1_5
			InitDinamicGLFeature_VERSION_1_5();
#endif /*USE_DYNAMIC_GL_VERSION_1_5*/
#ifdef USE_DYNAMIC_GL_NV_vertex_program4
			InitDinamicGLFeature_NV_vertex_program4();
#endif /*USE_DYNAMIC_GL_NV_vertex_program4*/
#ifdef USE_DYNAMIC_GL_ARB_vertex_shader
			InitDinamicGLFeature_ARB_vertex_shader();
#endif /*USE_DYNAMIC_GL_ARB_vertex_shader*/
#ifdef USE_DYNAMIC_GL_EXT_polygon_offset
			InitDinamicGLFeature_EXT_polygon_offset();
#endif /*USE_DYNAMIC_GL_EXT_polygon_offset*/
#ifdef USE_DYNAMIC_GL_ARB_vertex_blend
			InitDinamicGLFeature_ARB_vertex_blend();
#endif /*USE_DYNAMIC_GL_ARB_vertex_blend*/
#ifdef USE_DYNAMIC_GL_WIN_specular_fog
			InitDinamicGLFeature_WIN_specular_fog();
#endif /*USE_DYNAMIC_GL_WIN_specular_fog*/
#ifdef USE_DYNAMIC_GL_SGIX_impact_pixel_texture
			InitDinamicGLFeature_SGIX_impact_pixel_texture();
#endif /*USE_DYNAMIC_GL_SGIX_impact_pixel_texture*/
#ifdef USE_DYNAMIC_GL_EXT_depth_bounds_test
			InitDinamicGLFeature_EXT_depth_bounds_test();
#endif /*USE_DYNAMIC_GL_EXT_depth_bounds_test*/
#ifdef USE_DYNAMIC_GL_EXT_texture_mirror_clamp
			InitDinamicGLFeature_EXT_texture_mirror_clamp();
#endif /*USE_DYNAMIC_GL_EXT_texture_mirror_clamp*/
#ifdef USE_DYNAMIC_GL_SGIS_texture_lod
			InitDinamicGLFeature_SGIS_texture_lod();
#endif /*USE_DYNAMIC_GL_SGIS_texture_lod*/
#ifdef USE_DYNAMIC_GL_VERSION_1_2
			InitDinamicGLFeature_VERSION_1_2();
#endif /*USE_DYNAMIC_GL_VERSION_1_2*/
#ifdef USE_DYNAMIC_GL_SGIS_texture_edge_clamp
			InitDinamicGLFeature_SGIS_texture_edge_clamp();
#endif /*USE_DYNAMIC_GL_SGIS_texture_edge_clamp*/
#ifdef USE_DYNAMIC_GL_SUN_slice_accum
			InitDinamicGLFeature_SUN_slice_accum();
#endif /*USE_DYNAMIC_GL_SUN_slice_accum*/
#ifdef USE_DYNAMIC_GL_APPLE_element_array
			InitDinamicGLFeature_APPLE_element_array();
#endif /*USE_DYNAMIC_GL_APPLE_element_array*/
#ifdef USE_DYNAMIC_GL_EXT_blend_minmax
			InitDinamicGLFeature_EXT_blend_minmax();
#endif /*USE_DYNAMIC_GL_EXT_blend_minmax*/
#ifdef USE_DYNAMIC_GL_ATI_texture_float
			InitDinamicGLFeature_ATI_texture_float();
#endif /*USE_DYNAMIC_GL_ATI_texture_float*/
#ifdef USE_DYNAMIC_GL_SGIX_calligraphic_fragment
			InitDinamicGLFeature_SGIX_calligraphic_fragment();
#endif /*USE_DYNAMIC_GL_SGIX_calligraphic_fragment*/
#ifdef USE_DYNAMIC_GL_NV_float_buffer
			InitDinamicGLFeature_NV_float_buffer();
#endif /*USE_DYNAMIC_GL_NV_float_buffer*/
#ifdef USE_DYNAMIC_GL_SGIX_fragment_lighting
			InitDinamicGLFeature_SGIX_fragment_lighting();
#endif /*USE_DYNAMIC_GL_SGIX_fragment_lighting*/
#ifdef USE_DYNAMIC_GL_SGIX_instruments
			InitDinamicGLFeature_SGIX_instruments();
#endif /*USE_DYNAMIC_GL_SGIX_instruments*/
#ifdef USE_DYNAMIC_GL_SGIX_ycrcba
			InitDinamicGLFeature_SGIX_ycrcba();
#endif /*USE_DYNAMIC_GL_SGIX_ycrcba*/
#ifdef USE_DYNAMIC_GL_SGIX_texture_coordinate_clamp
			InitDinamicGLFeature_SGIX_texture_coordinate_clamp();
#endif /*USE_DYNAMIC_GL_SGIX_texture_coordinate_clamp*/
#ifdef USE_DYNAMIC_GL_S3_s3tc
			InitDinamicGLFeature_S3_s3tc();
#endif /*USE_DYNAMIC_GL_S3_s3tc*/
#ifdef USE_DYNAMIC_GL_EXT_422_pixels
			InitDinamicGLFeature_EXT_422_pixels();
#endif /*USE_DYNAMIC_GL_EXT_422_pixels*/
#ifdef USE_DYNAMIC_GL_NV_transform_feedback
			InitDinamicGLFeature_NV_transform_feedback();
#endif /*USE_DYNAMIC_GL_NV_transform_feedback*/
#ifdef USE_DYNAMIC_GL_SUN_triangle_list
			InitDinamicGLFeature_SUN_triangle_list();
#endif /*USE_DYNAMIC_GL_SUN_triangle_list*/
#ifdef USE_DYNAMIC_GL_SGIX_clipmap
			InitDinamicGLFeature_SGIX_clipmap();
#endif /*USE_DYNAMIC_GL_SGIX_clipmap*/
#ifdef USE_DYNAMIC_GL_NV_register_combiners2
			InitDinamicGLFeature_NV_register_combiners2();
#endif /*USE_DYNAMIC_GL_NV_register_combiners2*/
#ifdef USE_DYNAMIC_GL_EXT_clip_volume_hint
			InitDinamicGLFeature_EXT_clip_volume_hint();
#endif /*USE_DYNAMIC_GL_EXT_clip_volume_hint*/
#ifdef USE_DYNAMIC_GL_SGIS_point_parameters
			InitDinamicGLFeature_SGIS_point_parameters();
#endif /*USE_DYNAMIC_GL_SGIS_point_parameters*/
#ifdef USE_DYNAMIC_GL_APPLE_transform_hint
			InitDinamicGLFeature_APPLE_transform_hint();
#endif /*USE_DYNAMIC_GL_APPLE_transform_hint*/
#ifdef USE_DYNAMIC_GL_NV_fragment_program2
			InitDinamicGLFeature_NV_fragment_program2();
#endif /*USE_DYNAMIC_GL_NV_fragment_program2*/
#ifdef USE_DYNAMIC_GL_NV_texture_rectangle
			InitDinamicGLFeature_NV_texture_rectangle();
#endif /*USE_DYNAMIC_GL_NV_texture_rectangle*/
#ifdef USE_DYNAMIC_GL_SGI_depth_pass_instrument
			InitDinamicGLFeature_SGI_depth_pass_instrument();
#endif /*USE_DYNAMIC_GL_SGI_depth_pass_instrument*/
#ifdef USE_DYNAMIC_GL_EXT_rescale_normal
			InitDinamicGLFeature_EXT_rescale_normal();
#endif /*USE_DYNAMIC_GL_EXT_rescale_normal*/
#ifdef USE_DYNAMIC_GL_ARB_pixel_buffer_object
			InitDinamicGLFeature_ARB_pixel_buffer_object();
#endif /*USE_DYNAMIC_GL_ARB_pixel_buffer_object*/
#ifdef USE_DYNAMIC_GL_EXT_texture3D
			InitDinamicGLFeature_EXT_texture3D();
#endif /*USE_DYNAMIC_GL_EXT_texture3D*/
#ifdef USE_DYNAMIC_GL_EXT_texture_lod_bias
			InitDinamicGLFeature_EXT_texture_lod_bias();
#endif /*USE_DYNAMIC_GL_EXT_texture_lod_bias*/
#ifdef USE_DYNAMIC_GL_ATI_separate_stencil
			InitDinamicGLFeature_ATI_separate_stencil();
#endif /*USE_DYNAMIC_GL_ATI_separate_stencil*/
#ifdef USE_DYNAMIC_GL_APPLE_vertex_array_range
			InitDinamicGLFeature_APPLE_vertex_array_range();
#endif /*USE_DYNAMIC_GL_APPLE_vertex_array_range*/
#ifdef USE_DYNAMIC_GL_NV_conditional_render
			InitDinamicGLFeature_NV_conditional_render();
#endif /*USE_DYNAMIC_GL_NV_conditional_render*/
#ifdef USE_DYNAMIC_GL_SGIS_point_line_texgen
			InitDinamicGLFeature_SGIS_point_line_texgen();
#endif /*USE_DYNAMIC_GL_SGIS_point_line_texgen*/
#ifdef USE_DYNAMIC_GL_EXT_fog_coord
			InitDinamicGLFeature_EXT_fog_coord();
#endif /*USE_DYNAMIC_GL_EXT_fog_coord*/
#ifdef USE_DYNAMIC_GL_VERSION_1_4
			InitDinamicGLFeature_VERSION_1_4();
#endif /*USE_DYNAMIC_GL_VERSION_1_4*/
#ifdef USE_DYNAMIC_GL_ARB_vertex_buffer_object
			InitDinamicGLFeature_ARB_vertex_buffer_object();
#endif /*USE_DYNAMIC_GL_ARB_vertex_buffer_object*/
#ifdef USE_DYNAMIC_GL_APPLE_specular_vector
			InitDinamicGLFeature_APPLE_specular_vector();
#endif /*USE_DYNAMIC_GL_APPLE_specular_vector*/
#ifdef USE_DYNAMIC_GL_NV_copy_depth_to_color
			InitDinamicGLFeature_NV_copy_depth_to_color();
#endif /*USE_DYNAMIC_GL_NV_copy_depth_to_color*/
#ifdef USE_DYNAMIC_GL_ARB_texture_cube_map
			InitDinamicGLFeature_ARB_texture_cube_map();
#endif /*USE_DYNAMIC_GL_ARB_texture_cube_map*/
#ifdef USE_DYNAMIC_GL_NV_vertex_array_range
			InitDinamicGLFeature_NV_vertex_array_range();
#endif /*USE_DYNAMIC_GL_NV_vertex_array_range*/
#ifdef USE_DYNAMIC_GL_EXT_cull_vertex
			InitDinamicGLFeature_EXT_cull_vertex();
#endif /*USE_DYNAMIC_GL_EXT_cull_vertex*/
#ifdef USE_DYNAMIC_GL_FfdMaskSGIX
			InitDinamicGLFeature_FfdMaskSGIX();
#endif /*USE_DYNAMIC_GL_FfdMaskSGIX*/
#ifdef USE_DYNAMIC_GL_OES_read_format
			InitDinamicGLFeature_OES_read_format();
#endif /*USE_DYNAMIC_GL_OES_read_format*/
#ifdef USE_DYNAMIC_GL_INGR_blend_func_separate
			InitDinamicGLFeature_INGR_blend_func_separate();
#endif /*USE_DYNAMIC_GL_INGR_blend_func_separate*/
#ifdef USE_DYNAMIC_GL_APPLE_client_storage
			InitDinamicGLFeature_APPLE_client_storage();
#endif /*USE_DYNAMIC_GL_APPLE_client_storage*/
#ifdef USE_DYNAMIC_GL_ATI_envmap_bumpmap
			InitDinamicGLFeature_ATI_envmap_bumpmap();
#endif /*USE_DYNAMIC_GL_ATI_envmap_bumpmap*/
#ifdef USE_DYNAMIC_GL_ATI_vertex_array_object
			InitDinamicGLFeature_ATI_vertex_array_object();
#endif /*USE_DYNAMIC_GL_ATI_vertex_array_object*/
#ifdef USE_DYNAMIC_GL_SGIX_async_pixel
			InitDinamicGLFeature_SGIX_async_pixel();
#endif /*USE_DYNAMIC_GL_SGIX_async_pixel*/
#ifdef USE_DYNAMIC_GL_ATI_text_fragment_shader
			InitDinamicGLFeature_ATI_text_fragment_shader();
#endif /*USE_DYNAMIC_GL_ATI_text_fragment_shader*/
#ifdef USE_DYNAMIC_GL_ARB_point_parameters
			InitDinamicGLFeature_ARB_point_parameters();
#endif /*USE_DYNAMIC_GL_ARB_point_parameters*/
#ifdef USE_DYNAMIC_GL_EXT_pixel_buffer_object
			InitDinamicGLFeature_EXT_pixel_buffer_object();
#endif /*USE_DYNAMIC_GL_EXT_pixel_buffer_object*/
#ifdef USE_DYNAMIC_GL_EXT_index_array_formats
			InitDinamicGLFeature_EXT_index_array_formats();
#endif /*USE_DYNAMIC_GL_EXT_index_array_formats*/
#ifdef USE_DYNAMIC_GL_EXT_vertex_array
			InitDinamicGLFeature_EXT_vertex_array();
#endif /*USE_DYNAMIC_GL_EXT_vertex_array*/
#ifdef USE_DYNAMIC_GL_ARB_vertex_array_object
			InitDinamicGLFeature_ARB_vertex_array_object();
#endif /*USE_DYNAMIC_GL_ARB_vertex_array_object*/
#ifdef USE_DYNAMIC_GL_IBM_vertex_array_lists
			InitDinamicGLFeature_IBM_vertex_array_lists();
#endif /*USE_DYNAMIC_GL_IBM_vertex_array_lists*/
#ifdef USE_DYNAMIC_GL_ATI_draw_buffers
			InitDinamicGLFeature_ATI_draw_buffers();
#endif /*USE_DYNAMIC_GL_ATI_draw_buffers*/
#ifdef USE_DYNAMIC_GL_EXT_texture_compression_rgtc
			InitDinamicGLFeature_EXT_texture_compression_rgtc();
#endif /*USE_DYNAMIC_GL_EXT_texture_compression_rgtc*/
#ifdef USE_DYNAMIC_GL_ARB_texture_compression
			InitDinamicGLFeature_ARB_texture_compression();
#endif /*USE_DYNAMIC_GL_ARB_texture_compression*/
#ifdef USE_DYNAMIC_GL_VERSION_2_1
			InitDinamicGLFeature_VERSION_2_1();
#endif /*USE_DYNAMIC_GL_VERSION_2_1*/
#ifdef USE_DYNAMIC_GL_EXT_color_subtable
			InitDinamicGLFeature_EXT_color_subtable();
#endif /*USE_DYNAMIC_GL_EXT_color_subtable*/
#ifdef USE_DYNAMIC_GL_EXT_convolution
			InitDinamicGLFeature_EXT_convolution();
#endif /*USE_DYNAMIC_GL_EXT_convolution*/
#ifdef USE_DYNAMIC_GL_SGIX_fog_offset
			InitDinamicGLFeature_SGIX_fog_offset();
#endif /*USE_DYNAMIC_GL_SGIX_fog_offset*/
#ifdef USE_DYNAMIC_GL_EXT_texture_integer
			InitDinamicGLFeature_EXT_texture_integer();
#endif /*USE_DYNAMIC_GL_EXT_texture_integer*/
#ifdef USE_DYNAMIC_GL_ATI_vertex_attrib_array_object
			InitDinamicGLFeature_ATI_vertex_attrib_array_object();
#endif /*USE_DYNAMIC_GL_ATI_vertex_attrib_array_object*/
#ifdef USE_DYNAMIC_GL_EXT_packed_float
			InitDinamicGLFeature_EXT_packed_float();
#endif /*USE_DYNAMIC_GL_EXT_packed_float*/
#ifdef USE_DYNAMIC_GL_NV_texture_shader
			InitDinamicGLFeature_NV_texture_shader();
#endif /*USE_DYNAMIC_GL_NV_texture_shader*/
#ifdef USE_DYNAMIC_GL_SGIX_shadow
			InitDinamicGLFeature_SGIX_shadow();
#endif /*USE_DYNAMIC_GL_SGIX_shadow*/
#ifdef USE_DYNAMIC_GL_ARB_half_float_pixel
			InitDinamicGLFeature_ARB_half_float_pixel();
#endif /*USE_DYNAMIC_GL_ARB_half_float_pixel*/
#ifdef USE_DYNAMIC_GL_NV_primitive_restart
			InitDinamicGLFeature_NV_primitive_restart();
#endif /*USE_DYNAMIC_GL_NV_primitive_restart*/
#ifdef USE_DYNAMIC_GL_SUN_vertex
			InitDinamicGLFeature_SUN_vertex();
#endif /*USE_DYNAMIC_GL_SUN_vertex*/
#ifdef USE_DYNAMIC_GL_ARB_texture_mirrored_repeat
			InitDinamicGLFeature_ARB_texture_mirrored_repeat();
#endif /*USE_DYNAMIC_GL_ARB_texture_mirrored_repeat*/
#ifdef USE_DYNAMIC_GL_HP_texture_lighting
			InitDinamicGLFeature_HP_texture_lighting();
#endif /*USE_DYNAMIC_GL_HP_texture_lighting*/
}
