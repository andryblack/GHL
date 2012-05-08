/*VERSION_1_1*/
#ifdef USE_DYNAMIC_GL_VERSION_1_1
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
void (DYNAMIC_GL_APIENTRYP DynamicGL_AlphaFunc)(GLenum func , GLclampf ref) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearColor)(GLclampf red , GLclampf green , GLclampf blue , GLclampf alpha) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearDepthf)(GLclampf depth) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_ClipPlanef)(GLenum plane , const GLfloat *equation) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4f)(GLfloat red , GLfloat green , GLfloat blue , GLfloat alpha) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_DepthRangef)(GLclampf zNear , GLclampf zFar) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Fogf)(GLenum pname , GLfloat param) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Fogfv)(GLenum pname , const GLfloat *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Frustumf)(GLfloat left , GLfloat right , GLfloat bottom , GLfloat top , GLfloat zNear , GLfloat zFar) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFloatv)(GLenum pname , GLfloat *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GetLightfv)(GLenum light , GLenum pname , GLfloat *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMaterialfv)(GLenum face , GLenum pname , GLfloat *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexEnvfv)(GLenum env , GLenum pname , GLfloat *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexParameterfv)(GLenum target , GLenum pname , GLfloat *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_LightModelf)(GLenum pname , GLfloat param) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_LightModelfv)(GLenum pname , const GLfloat *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Lightf)(GLenum light , GLenum pname , GLfloat param) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Lightfv)(GLenum light , GLenum pname , const GLfloat *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_LineWidth)(GLfloat width) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_LoadMatrixf)(const GLfloat *m) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Materialf)(GLenum face , GLenum pname , GLfloat param) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Materialfv)(GLenum face , GLenum pname , const GLfloat *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_MultMatrixf)(const GLfloat *m) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4f)(GLenum target , GLfloat s , GLfloat t , GLfloat r , GLfloat q) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Normal3f)(GLfloat nx , GLfloat ny , GLfloat nz) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Orthof)(GLfloat left , GLfloat right , GLfloat bottom , GLfloat top , GLfloat zNear , GLfloat zFar) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameterf)(GLenum pname , GLfloat param) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameterfv)(GLenum pname , const GLfloat *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_PointSize)(GLfloat size) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_PolygonOffset)(GLfloat factor , GLfloat units) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Rotatef)(GLfloat angle , GLfloat x , GLfloat y , GLfloat z) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Scalef)(GLfloat x , GLfloat y , GLfloat z) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_TexEnvf)(GLenum target , GLenum pname , GLfloat param) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_TexEnvfv)(GLenum target , GLenum pname , const GLfloat *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_TexParameterf)(GLenum target , GLenum pname , GLfloat param) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_TexParameterfv)(GLenum target , GLenum pname , const GLfloat *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Translatef)(GLfloat x , GLfloat y , GLfloat z) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_ActiveTexture)(GLenum texture) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_AlphaFuncx)(GLenum func , GLclampx ref) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_BindBuffer)(GLenum target , GLuint buffer) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_BindTexture)(GLenum target , GLuint texture) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendFunc)(GLenum sfactor , GLenum dfactor) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_BufferData)(GLenum target , GLsizeiptr size , const GLvoid *data , GLenum usage) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_BufferSubData)(GLenum target , GLintptr offset , GLsizeiptr size , const GLvoid *data) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Clear)(GLbitfield mask) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearColorx)(GLclampx red , GLclampx green , GLclampx blue , GLclampx alpha) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearDepthx)(GLclampx depth) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearStencil)(GLint s) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_ClientActiveTexture)(GLenum texture) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_ClipPlanex)(GLenum plane , const GLfixed *equation) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4ub)(GLubyte red , GLubyte green , GLubyte blue , GLubyte alpha) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4x)(GLfixed red , GLfixed green , GLfixed blue , GLfixed alpha) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorMask)(GLboolean red , GLboolean green , GLboolean blue , GLboolean alpha) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorPointer)(GLint size , GLenum type , GLsizei stride , const GLvoid *pointer) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTexImage2D)(GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLint border , GLsizei imageSize , const GLvoid *data) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTexSubImage2D)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLsizei width , GLsizei height , GLenum format , GLsizei imageSize , const GLvoid *data) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyTexImage2D)(GLenum target , GLint level , GLenum internalformat , GLint x , GLint y , GLsizei width , GLsizei height , GLint border) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyTexSubImage2D)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint x , GLint y , GLsizei width , GLsizei height) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_CullFace)(GLenum mode) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteBuffers)(GLsizei n , const GLuint *buffers) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteTextures)(GLsizei n , const GLuint *textures) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_DepthFunc)(GLenum func) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_DepthMask)(GLboolean flag) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_DepthRangex)(GLclampx zNear , GLclampx zFar) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Disable)(GLenum cap) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_DisableClientState)(GLenum array) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawArrays)(GLenum mode , GLint first , GLsizei count) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawElements)(GLenum mode , GLsizei count , GLenum type , const GLvoid *indices) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Enable)(GLenum cap) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_EnableClientState)(GLenum array) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Finish)() = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Flush)() = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Fogx)(GLenum pname , GLfixed param) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Fogxv)(GLenum pname , const GLfixed *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_FrontFace)(GLenum mode) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Frustumx)(GLfixed left , GLfixed right , GLfixed bottom , GLfixed top , GLfixed zNear , GLfixed zFar) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GetBooleanv)(GLenum pname , GLboolean *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GetBufferParameteriv)(GLenum target , GLenum pname , GLint *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GenBuffers)(GLsizei n , GLuint *buffers) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GenTextures)(GLsizei n , GLuint *textures) = 0;
GLenum (DYNAMIC_GL_APIENTRYP DynamicGL_GetError)() = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFixedv)(GLenum pname , GLfixed *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GetIntegerv)(GLenum pname , GLint *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GetLightxv)(GLenum light , GLenum pname , GLfixed *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMaterialxv)(GLenum face , GLenum pname , GLfixed *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPointerv)(GLenum pname , GLvoid *p1) = 0;
GLubyte* (DYNAMIC_GL_APIENTRYP DynamicGL_GetString)(GLenum name) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexEnviv)(GLenum env , GLenum pname , GLint *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexEnvxv)(GLenum env , GLenum pname , GLfixed *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexParameteriv)(GLenum target , GLenum pname , GLint *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexParameterxv)(GLenum target , GLenum pname , GLfixed *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Hint)(GLenum target , GLenum mode) = 0;
GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsBuffer)(GLuint buffer) = 0;
GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsEnabled)(GLenum cap) = 0;
GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsTexture)(GLuint texture) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_LightModelx)(GLenum pname , GLfixed param) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_LightModelxv)(GLenum pname , const GLfixed *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Lightx)(GLenum light , GLenum pname , GLfixed param) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Lightxv)(GLenum light , GLenum pname , const GLfixed *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_LineWidthx)(GLfixed width) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_LoadIdentity)() = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_LoadMatrixx)(const GLfixed *m) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_LogicOp)(GLenum opcode) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Materialx)(GLenum face , GLenum pname , GLfixed param) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Materialxv)(GLenum face , GLenum pname , const GLfixed *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixMode)(GLenum mode) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_MultMatrixx)(const GLfixed *m) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4x)(GLenum target , GLfixed s , GLfixed t , GLfixed r , GLfixed q) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Normal3x)(GLfixed nx , GLfixed ny , GLfixed nz) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_NormalPointer)(GLenum type , GLsizei stride , const GLvoid *pointer) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Orthox)(GLfixed left , GLfixed right , GLfixed bottom , GLfixed top , GLfixed zNear , GLfixed zFar) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelStorei)(GLenum pname , GLint param) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameterx)(GLenum pname , GLfixed param) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameterxv)(GLenum pname , const GLfixed *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_PointSizex)(GLfixed size) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_PolygonOffsetx)(GLfixed factor , GLfixed units) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_PopMatrix)() = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_PushMatrix)() = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_ReadPixels)(GLint x , GLint y , GLsizei width , GLsizei height , GLenum format , GLenum type , GLvoid *pixels) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Rotatex)(GLfixed angle , GLfixed x , GLfixed y , GLfixed z) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_SampleCoverage)(GLclampf value , GLboolean invert) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_SampleCoveragex)(GLclampx value , GLboolean invert) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Scalex)(GLfixed x , GLfixed y , GLfixed z) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Scissor)(GLint x , GLint y , GLsizei width , GLsizei height) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_ShadeModel)(GLenum mode) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_StencilFunc)(GLenum func , GLint ref , GLuint mask) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_StencilMask)(GLuint mask) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_StencilOp)(GLenum fail , GLenum zfail , GLenum zpass) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoordPointer)(GLint size , GLenum type , GLsizei stride , const GLvoid *pointer) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_TexEnvi)(GLenum target , GLenum pname , GLint param) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_TexEnvx)(GLenum target , GLenum pname , GLfixed param) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_TexEnviv)(GLenum target , GLenum pname , const GLint *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_TexEnvxv)(GLenum target , GLenum pname , const GLfixed *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_TexImage2D)(GLenum target , GLint level , GLint internalformat , GLsizei width , GLsizei height , GLint border , GLenum format , GLenum type , const GLvoid *pixels) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_TexParameteri)(GLenum target , GLenum pname , GLint param) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_TexParameterx)(GLenum target , GLenum pname , GLfixed param) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_TexParameteriv)(GLenum target , GLenum pname , const GLint *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_TexParameterxv)(GLenum target , GLenum pname , const GLfixed *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_TexSubImage2D)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLsizei width , GLsizei height , GLenum format , GLenum type , const GLvoid *pixels) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Translatex)(GLfixed x , GLfixed y , GLfixed z) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexPointer)(GLint size , GLenum type , GLsizei stride , const GLvoid *pointer) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Viewport)(GLint x , GLint y , GLsizei width , GLsizei height) = 0;
static bool DinamicGLFeature_VERSION_1_1_loaded = false; 
static void InitDinamicGLFeature_VERSION_1_1() {
		DynamicGL_AlphaFunc = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum func , GLclampf ref)>("glAlphaFunc"); 
		DynamicGL_ClearColor = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLclampf red , GLclampf green , GLclampf blue , GLclampf alpha)>("glClearColor"); 
		DynamicGL_ClearDepthf = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLclampf depth)>("glClearDepthf"); 
		DynamicGL_ClipPlanef = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum plane , const GLfloat *equation)>("glClipPlanef"); 
		DynamicGL_Color4f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat red , GLfloat green , GLfloat blue , GLfloat alpha)>("glColor4f"); 
		DynamicGL_DepthRangef = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLclampf zNear , GLclampf zFar)>("glDepthRangef"); 
		DynamicGL_Fogf = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLfloat param)>("glFogf"); 
		DynamicGL_Fogfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , const GLfloat *params)>("glFogfv"); 
		DynamicGL_Frustumf = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat left , GLfloat right , GLfloat bottom , GLfloat top , GLfloat zNear , GLfloat zFar)>("glFrustumf"); 
		DynamicGL_GetFloatv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLfloat *params)>("glGetFloatv"); 
		DynamicGL_GetLightfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum light , GLenum pname , GLfloat *params)>("glGetLightfv"); 
		DynamicGL_GetMaterialfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum face , GLenum pname , GLfloat *params)>("glGetMaterialfv"); 
		DynamicGL_GetTexEnvfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum env , GLenum pname , GLfloat *params)>("glGetTexEnvfv"); 
		DynamicGL_GetTexParameterfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLfloat *params)>("glGetTexParameterfv"); 
		DynamicGL_LightModelf = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLfloat param)>("glLightModelf"); 
		DynamicGL_LightModelfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , const GLfloat *params)>("glLightModelfv"); 
		DynamicGL_Lightf = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum light , GLenum pname , GLfloat param)>("glLightf"); 
		DynamicGL_Lightfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum light , GLenum pname , const GLfloat *params)>("glLightfv"); 
		DynamicGL_LineWidth = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat width)>("glLineWidth"); 
		DynamicGL_LoadMatrixf = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *m)>("glLoadMatrixf"); 
		DynamicGL_Materialf = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum face , GLenum pname , GLfloat param)>("glMaterialf"); 
		DynamicGL_Materialfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum face , GLenum pname , const GLfloat *params)>("glMaterialfv"); 
		DynamicGL_MultMatrixf = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *m)>("glMultMatrixf"); 
		DynamicGL_MultiTexCoord4f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLfloat s , GLfloat t , GLfloat r , GLfloat q)>("glMultiTexCoord4f"); 
		DynamicGL_Normal3f = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat nx , GLfloat ny , GLfloat nz)>("glNormal3f"); 
		DynamicGL_Orthof = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat left , GLfloat right , GLfloat bottom , GLfloat top , GLfloat zNear , GLfloat zFar)>("glOrthof"); 
		DynamicGL_PointParameterf = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLfloat param)>("glPointParameterf"); 
		DynamicGL_PointParameterfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , const GLfloat *params)>("glPointParameterfv"); 
		DynamicGL_PointSize = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat size)>("glPointSize"); 
		DynamicGL_PolygonOffset = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat factor , GLfloat units)>("glPolygonOffset"); 
		DynamicGL_Rotatef = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat angle , GLfloat x , GLfloat y , GLfloat z)>("glRotatef"); 
		DynamicGL_Scalef = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat x , GLfloat y , GLfloat z)>("glScalef"); 
		DynamicGL_TexEnvf = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLfloat param)>("glTexEnvf"); 
		DynamicGL_TexEnvfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , const GLfloat *params)>("glTexEnvfv"); 
		DynamicGL_TexParameterf = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLfloat param)>("glTexParameterf"); 
		DynamicGL_TexParameterfv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , const GLfloat *params)>("glTexParameterfv"); 
		DynamicGL_Translatef = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat x , GLfloat y , GLfloat z)>("glTranslatef"); 
		DynamicGL_ActiveTexture = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texture)>("glActiveTexture"); 
		DynamicGL_AlphaFuncx = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum func , GLclampx ref)>("glAlphaFuncx"); 
		DynamicGL_BindBuffer = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint buffer)>("glBindBuffer"); 
		DynamicGL_BindTexture = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint texture)>("glBindTexture"); 
		DynamicGL_BlendFunc = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum sfactor , GLenum dfactor)>("glBlendFunc"); 
		DynamicGL_BufferData = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLsizeiptr size , const GLvoid *data , GLenum usage)>("glBufferData"); 
		DynamicGL_BufferSubData = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLintptr offset , GLsizeiptr size , const GLvoid *data)>("glBufferSubData"); 
		DynamicGL_Clear = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLbitfield mask)>("glClear"); 
		DynamicGL_ClearColorx = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLclampx red , GLclampx green , GLclampx blue , GLclampx alpha)>("glClearColorx"); 
		DynamicGL_ClearDepthx = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLclampx depth)>("glClearDepthx"); 
		DynamicGL_ClearStencil = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint s)>("glClearStencil"); 
		DynamicGL_ClientActiveTexture = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum texture)>("glClientActiveTexture"); 
		DynamicGL_ClipPlanex = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum plane , const GLfixed *equation)>("glClipPlanex"); 
		DynamicGL_Color4ub = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLubyte red , GLubyte green , GLubyte blue , GLubyte alpha)>("glColor4ub"); 
		DynamicGL_Color4x = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfixed red , GLfixed green , GLfixed blue , GLfixed alpha)>("glColor4x"); 
		DynamicGL_ColorMask = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLboolean red , GLboolean green , GLboolean blue , GLboolean alpha)>("glColorMask"); 
		DynamicGL_ColorPointer = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint size , GLenum type , GLsizei stride , const GLvoid *pointer)>("glColorPointer"); 
		DynamicGL_CompressedTexImage2D = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLint border , GLsizei imageSize , const GLvoid *data)>("glCompressedTexImage2D"); 
		DynamicGL_CompressedTexSubImage2D = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLsizei width , GLsizei height , GLenum format , GLsizei imageSize , const GLvoid *data)>("glCompressedTexSubImage2D"); 
		DynamicGL_CopyTexImage2D = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLenum internalformat , GLint x , GLint y , GLsizei width , GLsizei height , GLint border)>("glCopyTexImage2D"); 
		DynamicGL_CopyTexSubImage2D = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint x , GLint y , GLsizei width , GLsizei height)>("glCopyTexSubImage2D"); 
		DynamicGL_CullFace = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode)>("glCullFace"); 
		DynamicGL_DeleteBuffers = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , const GLuint *buffers)>("glDeleteBuffers"); 
		DynamicGL_DeleteTextures = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , const GLuint *textures)>("glDeleteTextures"); 
		DynamicGL_DepthFunc = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum func)>("glDepthFunc"); 
		DynamicGL_DepthMask = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLboolean flag)>("glDepthMask"); 
		DynamicGL_DepthRangex = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLclampx zNear , GLclampx zFar)>("glDepthRangex"); 
		DynamicGL_Disable = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum cap)>("glDisable"); 
		DynamicGL_DisableClientState = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum array)>("glDisableClientState"); 
		DynamicGL_DrawArrays = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , GLint first , GLsizei count)>("glDrawArrays"); 
		DynamicGL_DrawElements = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , GLsizei count , GLenum type , const GLvoid *indices)>("glDrawElements"); 
		DynamicGL_Enable = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum cap)>("glEnable"); 
		DynamicGL_EnableClientState = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum array)>("glEnableClientState"); 
		DynamicGL_Finish = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glFinish"); 
		DynamicGL_Flush = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glFlush"); 
		DynamicGL_Fogx = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLfixed param)>("glFogx"); 
		DynamicGL_Fogxv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , const GLfixed *params)>("glFogxv"); 
		DynamicGL_FrontFace = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode)>("glFrontFace"); 
		DynamicGL_Frustumx = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfixed left , GLfixed right , GLfixed bottom , GLfixed top , GLfixed zNear , GLfixed zFar)>("glFrustumx"); 
		DynamicGL_GetBooleanv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLboolean *params)>("glGetBooleanv"); 
		DynamicGL_GetBufferParameteriv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint *params)>("glGetBufferParameteriv"); 
		DynamicGL_GenBuffers = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , GLuint *buffers)>("glGenBuffers"); 
		DynamicGL_GenTextures = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , GLuint *textures)>("glGenTextures"); 
		DynamicGL_GetError = DynamicGL_LoadFunction<GLenum (DYNAMIC_GL_APIENTRYP)()>("glGetError"); 
		DynamicGL_GetFixedv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLfixed *params)>("glGetFixedv"); 
		DynamicGL_GetIntegerv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLint *params)>("glGetIntegerv"); 
		DynamicGL_GetLightxv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum light , GLenum pname , GLfixed *params)>("glGetLightxv"); 
		DynamicGL_GetMaterialxv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum face , GLenum pname , GLfixed *params)>("glGetMaterialxv"); 
		DynamicGL_GetPointerv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLvoid *p1)>("glGetPointerv"); 
		DynamicGL_GetString = DynamicGL_LoadFunction<GLubyte* (DYNAMIC_GL_APIENTRYP)(GLenum name)>("glGetString"); 
		DynamicGL_GetTexEnviv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum env , GLenum pname , GLint *params)>("glGetTexEnviv"); 
		DynamicGL_GetTexEnvxv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum env , GLenum pname , GLfixed *params)>("glGetTexEnvxv"); 
		DynamicGL_GetTexParameteriv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint *params)>("glGetTexParameteriv"); 
		DynamicGL_GetTexParameterxv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLfixed *params)>("glGetTexParameterxv"); 
		DynamicGL_Hint = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum mode)>("glHint"); 
		DynamicGL_IsBuffer = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLuint buffer)>("glIsBuffer"); 
		DynamicGL_IsEnabled = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLenum cap)>("glIsEnabled"); 
		DynamicGL_IsTexture = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLuint texture)>("glIsTexture"); 
		DynamicGL_LightModelx = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLfixed param)>("glLightModelx"); 
		DynamicGL_LightModelxv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , const GLfixed *params)>("glLightModelxv"); 
		DynamicGL_Lightx = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum light , GLenum pname , GLfixed param)>("glLightx"); 
		DynamicGL_Lightxv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum light , GLenum pname , const GLfixed *params)>("glLightxv"); 
		DynamicGL_LineWidthx = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfixed width)>("glLineWidthx"); 
		DynamicGL_LoadIdentity = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glLoadIdentity"); 
		DynamicGL_LoadMatrixx = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfixed *m)>("glLoadMatrixx"); 
		DynamicGL_LogicOp = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum opcode)>("glLogicOp"); 
		DynamicGL_Materialx = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum face , GLenum pname , GLfixed param)>("glMaterialx"); 
		DynamicGL_Materialxv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum face , GLenum pname , const GLfixed *params)>("glMaterialxv"); 
		DynamicGL_MatrixMode = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode)>("glMatrixMode"); 
		DynamicGL_MultMatrixx = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfixed *m)>("glMultMatrixx"); 
		DynamicGL_MultiTexCoord4x = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLfixed s , GLfixed t , GLfixed r , GLfixed q)>("glMultiTexCoord4x"); 
		DynamicGL_Normal3x = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfixed nx , GLfixed ny , GLfixed nz)>("glNormal3x"); 
		DynamicGL_NormalPointer = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum type , GLsizei stride , const GLvoid *pointer)>("glNormalPointer"); 
		DynamicGL_Orthox = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfixed left , GLfixed right , GLfixed bottom , GLfixed top , GLfixed zNear , GLfixed zFar)>("glOrthox"); 
		DynamicGL_PixelStorei = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLint param)>("glPixelStorei"); 
		DynamicGL_PointParameterx = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLfixed param)>("glPointParameterx"); 
		DynamicGL_PointParameterxv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , const GLfixed *params)>("glPointParameterxv"); 
		DynamicGL_PointSizex = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfixed size)>("glPointSizex"); 
		DynamicGL_PolygonOffsetx = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfixed factor , GLfixed units)>("glPolygonOffsetx"); 
		DynamicGL_PopMatrix = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glPopMatrix"); 
		DynamicGL_PushMatrix = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glPushMatrix"); 
		DynamicGL_ReadPixels = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint x , GLint y , GLsizei width , GLsizei height , GLenum format , GLenum type , GLvoid *pixels)>("glReadPixels"); 
		DynamicGL_Rotatex = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfixed angle , GLfixed x , GLfixed y , GLfixed z)>("glRotatex"); 
		DynamicGL_SampleCoverage = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLclampf value , GLboolean invert)>("glSampleCoverage"); 
		DynamicGL_SampleCoveragex = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLclampx value , GLboolean invert)>("glSampleCoveragex"); 
		DynamicGL_Scalex = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfixed x , GLfixed y , GLfixed z)>("glScalex"); 
		DynamicGL_Scissor = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint x , GLint y , GLsizei width , GLsizei height)>("glScissor"); 
		DynamicGL_ShadeModel = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode)>("glShadeModel"); 
		DynamicGL_StencilFunc = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum func , GLint ref , GLuint mask)>("glStencilFunc"); 
		DynamicGL_StencilMask = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint mask)>("glStencilMask"); 
		DynamicGL_StencilOp = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum fail , GLenum zfail , GLenum zpass)>("glStencilOp"); 
		DynamicGL_TexCoordPointer = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint size , GLenum type , GLsizei stride , const GLvoid *pointer)>("glTexCoordPointer"); 
		DynamicGL_TexEnvi = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint param)>("glTexEnvi"); 
		DynamicGL_TexEnvx = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLfixed param)>("glTexEnvx"); 
		DynamicGL_TexEnviv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , const GLint *params)>("glTexEnviv"); 
		DynamicGL_TexEnvxv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , const GLfixed *params)>("glTexEnvxv"); 
		DynamicGL_TexImage2D = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLint internalformat , GLsizei width , GLsizei height , GLint border , GLenum format , GLenum type , const GLvoid *pixels)>("glTexImage2D"); 
		DynamicGL_TexParameteri = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint param)>("glTexParameteri"); 
		DynamicGL_TexParameterx = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLfixed param)>("glTexParameterx"); 
		DynamicGL_TexParameteriv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , const GLint *params)>("glTexParameteriv"); 
		DynamicGL_TexParameterxv = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , const GLfixed *params)>("glTexParameterxv"); 
		DynamicGL_TexSubImage2D = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLsizei width , GLsizei height , GLenum format , GLenum type , const GLvoid *pixels)>("glTexSubImage2D"); 
		DynamicGL_Translatex = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfixed x , GLfixed y , GLfixed z)>("glTranslatex"); 
		DynamicGL_VertexPointer = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint size , GLenum type , GLsizei stride , const GLvoid *pointer)>("glVertexPointer"); 
		DynamicGL_Viewport = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint x , GLint y , GLsizei width , GLsizei height)>("glViewport"); 
		DinamicGLFeature_VERSION_1_1_loaded = true; 
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
bool DinamicGLFeature_VERSION_1_1_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
		if (!DinamicGLFeature_VERSION_1_1_loaded) {
			InitDinamicGLFeature_VERSION_1_1();
		}
		if (DynamicGL_AlphaFunc==0) return false; 
		if (DynamicGL_ClearColor==0) return false; 
		if (DynamicGL_ClearDepthf==0) return false; 
		if (DynamicGL_ClipPlanef==0) return false; 
		if (DynamicGL_Color4f==0) return false; 
		if (DynamicGL_DepthRangef==0) return false; 
		if (DynamicGL_Fogf==0) return false; 
		if (DynamicGL_Fogfv==0) return false; 
		if (DynamicGL_Frustumf==0) return false; 
		if (DynamicGL_GetFloatv==0) return false; 
		if (DynamicGL_GetLightfv==0) return false; 
		if (DynamicGL_GetMaterialfv==0) return false; 
		if (DynamicGL_GetTexEnvfv==0) return false; 
		if (DynamicGL_GetTexParameterfv==0) return false; 
		if (DynamicGL_LightModelf==0) return false; 
		if (DynamicGL_LightModelfv==0) return false; 
		if (DynamicGL_Lightf==0) return false; 
		if (DynamicGL_Lightfv==0) return false; 
		if (DynamicGL_LineWidth==0) return false; 
		if (DynamicGL_LoadMatrixf==0) return false; 
		if (DynamicGL_Materialf==0) return false; 
		if (DynamicGL_Materialfv==0) return false; 
		if (DynamicGL_MultMatrixf==0) return false; 
		if (DynamicGL_MultiTexCoord4f==0) return false; 
		if (DynamicGL_Normal3f==0) return false; 
		if (DynamicGL_Orthof==0) return false; 
		if (DynamicGL_PointParameterf==0) return false; 
		if (DynamicGL_PointParameterfv==0) return false; 
		if (DynamicGL_PointSize==0) return false; 
		if (DynamicGL_PolygonOffset==0) return false; 
		if (DynamicGL_Rotatef==0) return false; 
		if (DynamicGL_Scalef==0) return false; 
		if (DynamicGL_TexEnvf==0) return false; 
		if (DynamicGL_TexEnvfv==0) return false; 
		if (DynamicGL_TexParameterf==0) return false; 
		if (DynamicGL_TexParameterfv==0) return false; 
		if (DynamicGL_Translatef==0) return false; 
		if (DynamicGL_ActiveTexture==0) return false; 
		if (DynamicGL_AlphaFuncx==0) return false; 
		if (DynamicGL_BindBuffer==0) return false; 
		if (DynamicGL_BindTexture==0) return false; 
		if (DynamicGL_BlendFunc==0) return false; 
		if (DynamicGL_BufferData==0) return false; 
		if (DynamicGL_BufferSubData==0) return false; 
		if (DynamicGL_Clear==0) return false; 
		if (DynamicGL_ClearColorx==0) return false; 
		if (DynamicGL_ClearDepthx==0) return false; 
		if (DynamicGL_ClearStencil==0) return false; 
		if (DynamicGL_ClientActiveTexture==0) return false; 
		if (DynamicGL_ClipPlanex==0) return false; 
		if (DynamicGL_Color4ub==0) return false; 
		if (DynamicGL_Color4x==0) return false; 
		if (DynamicGL_ColorMask==0) return false; 
		if (DynamicGL_ColorPointer==0) return false; 
		if (DynamicGL_CompressedTexImage2D==0) return false; 
		if (DynamicGL_CompressedTexSubImage2D==0) return false; 
		if (DynamicGL_CopyTexImage2D==0) return false; 
		if (DynamicGL_CopyTexSubImage2D==0) return false; 
		if (DynamicGL_CullFace==0) return false; 
		if (DynamicGL_DeleteBuffers==0) return false; 
		if (DynamicGL_DeleteTextures==0) return false; 
		if (DynamicGL_DepthFunc==0) return false; 
		if (DynamicGL_DepthMask==0) return false; 
		if (DynamicGL_DepthRangex==0) return false; 
		if (DynamicGL_Disable==0) return false; 
		if (DynamicGL_DisableClientState==0) return false; 
		if (DynamicGL_DrawArrays==0) return false; 
		if (DynamicGL_DrawElements==0) return false; 
		if (DynamicGL_Enable==0) return false; 
		if (DynamicGL_EnableClientState==0) return false; 
		if (DynamicGL_Finish==0) return false; 
		if (DynamicGL_Flush==0) return false; 
		if (DynamicGL_Fogx==0) return false; 
		if (DynamicGL_Fogxv==0) return false; 
		if (DynamicGL_FrontFace==0) return false; 
		if (DynamicGL_Frustumx==0) return false; 
		if (DynamicGL_GetBooleanv==0) return false; 
		if (DynamicGL_GetBufferParameteriv==0) return false; 
		if (DynamicGL_GenBuffers==0) return false; 
		if (DynamicGL_GenTextures==0) return false; 
		if (DynamicGL_GetError==0) return false; 
		if (DynamicGL_GetFixedv==0) return false; 
		if (DynamicGL_GetIntegerv==0) return false; 
		if (DynamicGL_GetLightxv==0) return false; 
		if (DynamicGL_GetMaterialxv==0) return false; 
		if (DynamicGL_GetPointerv==0) return false; 
		if (DynamicGL_GetString==0) return false; 
		if (DynamicGL_GetTexEnviv==0) return false; 
		if (DynamicGL_GetTexEnvxv==0) return false; 
		if (DynamicGL_GetTexParameteriv==0) return false; 
		if (DynamicGL_GetTexParameterxv==0) return false; 
		if (DynamicGL_Hint==0) return false; 
		if (DynamicGL_IsBuffer==0) return false; 
		if (DynamicGL_IsEnabled==0) return false; 
		if (DynamicGL_IsTexture==0) return false; 
		if (DynamicGL_LightModelx==0) return false; 
		if (DynamicGL_LightModelxv==0) return false; 
		if (DynamicGL_Lightx==0) return false; 
		if (DynamicGL_Lightxv==0) return false; 
		if (DynamicGL_LineWidthx==0) return false; 
		if (DynamicGL_LoadIdentity==0) return false; 
		if (DynamicGL_LoadMatrixx==0) return false; 
		if (DynamicGL_LogicOp==0) return false; 
		if (DynamicGL_Materialx==0) return false; 
		if (DynamicGL_Materialxv==0) return false; 
		if (DynamicGL_MatrixMode==0) return false; 
		if (DynamicGL_MultMatrixx==0) return false; 
		if (DynamicGL_MultiTexCoord4x==0) return false; 
		if (DynamicGL_Normal3x==0) return false; 
		if (DynamicGL_NormalPointer==0) return false; 
		if (DynamicGL_Orthox==0) return false; 
		if (DynamicGL_PixelStorei==0) return false; 
		if (DynamicGL_PointParameterx==0) return false; 
		if (DynamicGL_PointParameterxv==0) return false; 
		if (DynamicGL_PointSizex==0) return false; 
		if (DynamicGL_PolygonOffsetx==0) return false; 
		if (DynamicGL_PopMatrix==0) return false; 
		if (DynamicGL_PushMatrix==0) return false; 
		if (DynamicGL_ReadPixels==0) return false; 
		if (DynamicGL_Rotatex==0) return false; 
		if (DynamicGL_SampleCoverage==0) return false; 
		if (DynamicGL_SampleCoveragex==0) return false; 
		if (DynamicGL_Scalex==0) return false; 
		if (DynamicGL_Scissor==0) return false; 
		if (DynamicGL_ShadeModel==0) return false; 
		if (DynamicGL_StencilFunc==0) return false; 
		if (DynamicGL_StencilMask==0) return false; 
		if (DynamicGL_StencilOp==0) return false; 
		if (DynamicGL_TexCoordPointer==0) return false; 
		if (DynamicGL_TexEnvi==0) return false; 
		if (DynamicGL_TexEnvx==0) return false; 
		if (DynamicGL_TexEnviv==0) return false; 
		if (DynamicGL_TexEnvxv==0) return false; 
		if (DynamicGL_TexImage2D==0) return false; 
		if (DynamicGL_TexParameteri==0) return false; 
		if (DynamicGL_TexParameterx==0) return false; 
		if (DynamicGL_TexParameteriv==0) return false; 
		if (DynamicGL_TexParameterxv==0) return false; 
		if (DynamicGL_TexSubImage2D==0) return false; 
		if (DynamicGL_Translatex==0) return false; 
		if (DynamicGL_VertexPointer==0) return false; 
		if (DynamicGL_Viewport==0) return false; 
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_VERSION_1_1*/

/*OES_blend_func_separate*/
#ifdef USE_DYNAMIC_GL_OES_blend_func_separate
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendFuncSeparateOES)(GLenum srcRGB , GLenum dstRGB , GLenum srcAlpha , GLenum dstAlpha) = 0;
static bool DinamicGLFeature_OES_blend_func_separate_loaded = false; 
static void InitDinamicGLFeature_OES_blend_func_separate() {
		DynamicGL_BlendFuncSeparateOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum srcRGB , GLenum dstRGB , GLenum srcAlpha , GLenum dstAlpha)>("glBlendFuncSeparateOES"); 
		DinamicGLFeature_OES_blend_func_separate_loaded = true; 
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
bool DinamicGLFeature_OES_blend_func_separate_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_OES_blend_func_separate")) return false;
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
		if (!DinamicGLFeature_OES_blend_func_separate_loaded) {
			InitDinamicGLFeature_OES_blend_func_separate();
		}
		if (DynamicGL_BlendFuncSeparateOES==0) return false; 
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_OES_blend_func_separate*/

/*QCOM_driver_control*/
#ifdef USE_DYNAMIC_GL_QCOM_driver_control
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
void (DYNAMIC_GL_APIENTRYP DynamicGL_GetDriverControlsQCOM)(GLint *num , GLsizei size , GLuint *driverControls) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GetDriverControlStringQCOM)(GLuint driverControl , GLsizei bufSize , GLsizei *length , GLchar *driverControlString) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_EnableDriverControlQCOM)(GLuint driverControl) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_DisableDriverControlQCOM)(GLuint driverControl) = 0;
static bool DinamicGLFeature_QCOM_driver_control_loaded = false; 
static void InitDinamicGLFeature_QCOM_driver_control() {
		DynamicGL_GetDriverControlsQCOM = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint *num , GLsizei size , GLuint *driverControls)>("glGetDriverControlsQCOM"); 
		DynamicGL_GetDriverControlStringQCOM = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint driverControl , GLsizei bufSize , GLsizei *length , GLchar *driverControlString)>("glGetDriverControlStringQCOM"); 
		DynamicGL_EnableDriverControlQCOM = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint driverControl)>("glEnableDriverControlQCOM"); 
		DynamicGL_DisableDriverControlQCOM = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint driverControl)>("glDisableDriverControlQCOM"); 
		DinamicGLFeature_QCOM_driver_control_loaded = true; 
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
bool DinamicGLFeature_QCOM_driver_control_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_QCOM_driver_control")) return false;
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
		if (!DinamicGLFeature_QCOM_driver_control_loaded) {
			InitDinamicGLFeature_QCOM_driver_control();
		}
		if (DynamicGL_GetDriverControlsQCOM==0) return false; 
		if (DynamicGL_GetDriverControlStringQCOM==0) return false; 
		if (DynamicGL_EnableDriverControlQCOM==0) return false; 
		if (DynamicGL_DisableDriverControlQCOM==0) return false; 
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_QCOM_driver_control*/

/*EXT_multisampled_render_to_texture*/
#ifdef USE_DYNAMIC_GL_EXT_multisampled_render_to_texture
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
void (DYNAMIC_GL_APIENTRYP DynamicGL_RenderbufferStorageMultisampleEXT)(GLenum target , GLsizei samples , GLenum internalformat , GLsizei width , GLsizei height) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferTexture2DMultisampleEXT)(GLenum target , GLenum attachment , GLenum textarget , GLuint texture , GLint level , GLsizei samples) = 0;
static bool DinamicGLFeature_EXT_multisampled_render_to_texture_loaded = false; 
static void InitDinamicGLFeature_EXT_multisampled_render_to_texture() {
		DynamicGL_RenderbufferStorageMultisampleEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLsizei samples , GLenum internalformat , GLsizei width , GLsizei height)>("glRenderbufferStorageMultisampleEXT"); 
		DynamicGL_FramebufferTexture2DMultisampleEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum attachment , GLenum textarget , GLuint texture , GLint level , GLsizei samples)>("glFramebufferTexture2DMultisampleEXT"); 
		DinamicGLFeature_EXT_multisampled_render_to_texture_loaded = true; 
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
bool DinamicGLFeature_EXT_multisampled_render_to_texture_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_EXT_multisampled_render_to_texture")) return false;
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
		if (!DinamicGLFeature_EXT_multisampled_render_to_texture_loaded) {
			InitDinamicGLFeature_EXT_multisampled_render_to_texture();
		}
		if (DynamicGL_RenderbufferStorageMultisampleEXT==0) return false; 
		if (DynamicGL_FramebufferTexture2DMultisampleEXT==0) return false; 
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_multisampled_render_to_texture*/

/*EXT_texture_storage*/
#ifdef USE_DYNAMIC_GL_EXT_texture_storage
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
void (DYNAMIC_GL_APIENTRYP DynamicGL_TexStorage1DEXT)(GLenum target , GLsizei levels , GLenum internalformat , GLsizei width) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_TexStorage2DEXT)(GLenum target , GLsizei levels , GLenum internalformat , GLsizei width , GLsizei height) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_TexStorage3DEXT)(GLenum target , GLsizei levels , GLenum internalformat , GLsizei width , GLsizei height , GLsizei depth) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureStorage1DEXT)(GLuint texture , GLenum target , GLsizei levels , GLenum internalformat , GLsizei width) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureStorage2DEXT)(GLuint texture , GLenum target , GLsizei levels , GLenum internalformat , GLsizei width , GLsizei height) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureStorage3DEXT)(GLuint texture , GLenum target , GLsizei levels , GLenum internalformat , GLsizei width , GLsizei height , GLsizei depth) = 0;
static bool DinamicGLFeature_EXT_texture_storage_loaded = false; 
static void InitDinamicGLFeature_EXT_texture_storage() {
		DynamicGL_TexStorage1DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLsizei levels , GLenum internalformat , GLsizei width)>("glTexStorage1DEXT"); 
		DynamicGL_TexStorage2DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLsizei levels , GLenum internalformat , GLsizei width , GLsizei height)>("glTexStorage2DEXT"); 
		DynamicGL_TexStorage3DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLsizei levels , GLenum internalformat , GLsizei width , GLsizei height , GLsizei depth)>("glTexStorage3DEXT"); 
		DynamicGL_TextureStorage1DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLsizei levels , GLenum internalformat , GLsizei width)>("glTextureStorage1DEXT"); 
		DynamicGL_TextureStorage2DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLsizei levels , GLenum internalformat , GLsizei width , GLsizei height)>("glTextureStorage2DEXT"); 
		DynamicGL_TextureStorage3DEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum target , GLsizei levels , GLenum internalformat , GLsizei width , GLsizei height , GLsizei depth)>("glTextureStorage3DEXT"); 
		DinamicGLFeature_EXT_texture_storage_loaded = true; 
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
bool DinamicGLFeature_EXT_texture_storage_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_EXT_texture_storage")) return false;
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
		if (!DinamicGLFeature_EXT_texture_storage_loaded) {
			InitDinamicGLFeature_EXT_texture_storage();
		}
		if (DynamicGL_TexStorage1DEXT==0) return false; 
		if (DynamicGL_TexStorage2DEXT==0) return false; 
		if (DynamicGL_TexStorage3DEXT==0) return false; 
		if (DynamicGL_TextureStorage1DEXT==0) return false; 
		if (DynamicGL_TextureStorage2DEXT==0) return false; 
		if (DynamicGL_TextureStorage3DEXT==0) return false; 
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_texture_storage*/

/*OES_query_matrix*/
#ifdef USE_DYNAMIC_GL_OES_query_matrix
bool DinamicGLFeature_OES_query_matrix_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_OES_query_matrix")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_OES_query_matrix*/

/*OES_stencil8*/
#ifdef USE_DYNAMIC_GL_OES_stencil8
bool DinamicGLFeature_OES_stencil8_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_OES_stencil8")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_OES_stencil8*/

/*APIENTRYP*/
#ifdef USE_DYNAMIC_GL_APIENTRYP
bool DinamicGLFeature_APIENTRYP_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_APIENTRYP")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_APIENTRYP*/

/*OES_stencil_wrap*/
#ifdef USE_DYNAMIC_GL_OES_stencil_wrap
bool DinamicGLFeature_OES_stencil_wrap_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_OES_stencil_wrap")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_OES_stencil_wrap*/

/*APPLE_framebuffer_multisample*/
#ifdef USE_DYNAMIC_GL_APPLE_framebuffer_multisample
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
void (DYNAMIC_GL_APIENTRYP DynamicGL_RenderbufferStorageMultisampleAPPLE)(GLenum target , GLsizei samples , GLenum internalformat , GLsizei width , GLsizei height) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_ResolveMultisampleFramebufferAPPLE)() = 0;
static bool DinamicGLFeature_APPLE_framebuffer_multisample_loaded = false; 
static void InitDinamicGLFeature_APPLE_framebuffer_multisample() {
		DynamicGL_RenderbufferStorageMultisampleAPPLE = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLsizei samples , GLenum internalformat , GLsizei width , GLsizei height)>("glRenderbufferStorageMultisampleAPPLE"); 
		DynamicGL_ResolveMultisampleFramebufferAPPLE = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glResolveMultisampleFramebufferAPPLE"); 
		DinamicGLFeature_APPLE_framebuffer_multisample_loaded = true; 
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
bool DinamicGLFeature_APPLE_framebuffer_multisample_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_APPLE_framebuffer_multisample")) return false;
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
		if (!DinamicGLFeature_APPLE_framebuffer_multisample_loaded) {
			InitDinamicGLFeature_APPLE_framebuffer_multisample();
		}
		if (DynamicGL_RenderbufferStorageMultisampleAPPLE==0) return false; 
		if (DynamicGL_ResolveMultisampleFramebufferAPPLE==0) return false; 
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_APPLE_framebuffer_multisample*/

/*OES_extended_matrix_palette*/
#ifdef USE_DYNAMIC_GL_OES_extended_matrix_palette
bool DinamicGLFeature_OES_extended_matrix_palette_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_OES_extended_matrix_palette")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_OES_extended_matrix_palette*/

/*APPLE_texture_format_BGRA8888*/
#ifdef USE_DYNAMIC_GL_APPLE_texture_format_BGRA8888
bool DinamicGLFeature_APPLE_texture_format_BGRA8888_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_APPLE_texture_format_BGRA8888")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_APPLE_texture_format_BGRA8888*/

/*APPLE_texture_2D_limited_npot*/
#ifdef USE_DYNAMIC_GL_APPLE_texture_2D_limited_npot
bool DinamicGLFeature_APPLE_texture_2D_limited_npot_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_APPLE_texture_2D_limited_npot")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_APPLE_texture_2D_limited_npot*/

/*QCOM_perfmon_global_mode*/
#ifdef USE_DYNAMIC_GL_QCOM_perfmon_global_mode
bool DinamicGLFeature_QCOM_perfmon_global_mode_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_QCOM_perfmon_global_mode")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_QCOM_perfmon_global_mode*/

/*IMG_user_clip_plane*/
#ifdef USE_DYNAMIC_GL_IMG_user_clip_plane
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
void (DYNAMIC_GL_APIENTRYP DynamicGL_ClipPlanefIMG)(GLenum p , const GLfloat *eqn) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_ClipPlanexIMG)(GLenum p , const GLfixed *eqn) = 0;
static bool DinamicGLFeature_IMG_user_clip_plane_loaded = false; 
static void InitDinamicGLFeature_IMG_user_clip_plane() {
		DynamicGL_ClipPlanefIMG = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum p , const GLfloat *eqn)>("glClipPlanefIMG"); 
		DynamicGL_ClipPlanexIMG = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum p , const GLfixed *eqn)>("glClipPlanexIMG"); 
		DinamicGLFeature_IMG_user_clip_plane_loaded = true; 
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
bool DinamicGLFeature_IMG_user_clip_plane_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_IMG_user_clip_plane")) return false;
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
		if (!DinamicGLFeature_IMG_user_clip_plane_loaded) {
			InitDinamicGLFeature_IMG_user_clip_plane();
		}
		if (DynamicGL_ClipPlanefIMG==0) return false; 
		if (DynamicGL_ClipPlanexIMG==0) return false; 
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_IMG_user_clip_plane*/

/*OES_single_precision*/
#ifdef USE_DYNAMIC_GL_OES_single_precision
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
void (DYNAMIC_GL_APIENTRYP DynamicGL_DepthRangefOES)(GLclampf zNear , GLclampf zFar) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_FrustumfOES)(GLfloat left , GLfloat right , GLfloat bottom , GLfloat top , GLfloat zNear , GLfloat zFar) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_OrthofOES)(GLfloat left , GLfloat right , GLfloat bottom , GLfloat top , GLfloat zNear , GLfloat zFar) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_ClipPlanefOES)(GLenum plane , const GLfloat *equation) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearDepthfOES)(GLclampf depth) = 0;
static bool DinamicGLFeature_OES_single_precision_loaded = false; 
static void InitDinamicGLFeature_OES_single_precision() {
		DynamicGL_DepthRangefOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLclampf zNear , GLclampf zFar)>("glDepthRangefOES"); 
		DynamicGL_FrustumfOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat left , GLfloat right , GLfloat bottom , GLfloat top , GLfloat zNear , GLfloat zFar)>("glFrustumfOES"); 
		DynamicGL_OrthofOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat left , GLfloat right , GLfloat bottom , GLfloat top , GLfloat zNear , GLfloat zFar)>("glOrthofOES"); 
		DynamicGL_ClipPlanefOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum plane , const GLfloat *equation)>("glClipPlanefOES"); 
		DynamicGL_ClearDepthfOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLclampf depth)>("glClearDepthfOES"); 
		DinamicGLFeature_OES_single_precision_loaded = true; 
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
bool DinamicGLFeature_OES_single_precision_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_OES_single_precision")) return false;
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
		if (!DinamicGLFeature_OES_single_precision_loaded) {
			InitDinamicGLFeature_OES_single_precision();
		}
		if (DynamicGL_DepthRangefOES==0) return false; 
		if (DynamicGL_FrustumfOES==0) return false; 
		if (DynamicGL_OrthofOES==0) return false; 
		if (DynamicGL_ClipPlanefOES==0) return false; 
		if (DynamicGL_ClearDepthfOES==0) return false; 
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_OES_single_precision*/

/*IMG_texture_compression_pvrtc*/
#ifdef USE_DYNAMIC_GL_IMG_texture_compression_pvrtc
bool DinamicGLFeature_IMG_texture_compression_pvrtc_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_IMG_texture_compression_pvrtc")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_IMG_texture_compression_pvrtc*/

/*EXT_texture_format_BGRA8888*/
#ifdef USE_DYNAMIC_GL_EXT_texture_format_BGRA8888
bool DinamicGLFeature_EXT_texture_format_BGRA8888_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_EXT_texture_format_BGRA8888")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_texture_format_BGRA8888*/

/*OES_depth32*/
#ifdef USE_DYNAMIC_GL_OES_depth32
bool DinamicGLFeature_OES_depth32_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_OES_depth32")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_OES_depth32*/

/*OES_fbo_render_mipmap*/
#ifdef USE_DYNAMIC_GL_OES_fbo_render_mipmap
bool DinamicGLFeature_OES_fbo_render_mipmap_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_OES_fbo_render_mipmap")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_OES_fbo_render_mipmap*/

/*IMG_multisampled_render_to_texture*/
#ifdef USE_DYNAMIC_GL_IMG_multisampled_render_to_texture
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
void (DYNAMIC_GL_APIENTRYP DynamicGL_RenderbufferStorageMultisampleIMG)(GLenum p1 , GLsizei p2 , GLenum p3 , GLsizei p4 , GLsizei p5) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferTexture2DMultisampleIMG)(GLenum p1 , GLenum p2 , GLenum p3 , GLuint p4 , GLint p5 , GLsizei p6) = 0;
static bool DinamicGLFeature_IMG_multisampled_render_to_texture_loaded = false; 
static void InitDinamicGLFeature_IMG_multisampled_render_to_texture() {
		DynamicGL_RenderbufferStorageMultisampleIMG = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum p1 , GLsizei p2 , GLenum p3 , GLsizei p4 , GLsizei p5)>("glRenderbufferStorageMultisampleIMG"); 
		DynamicGL_FramebufferTexture2DMultisampleIMG = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum p1 , GLenum p2 , GLenum p3 , GLuint p4 , GLint p5 , GLsizei p6)>("glFramebufferTexture2DMultisampleIMG"); 
		DinamicGLFeature_IMG_multisampled_render_to_texture_loaded = true; 
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
bool DinamicGLFeature_IMG_multisampled_render_to_texture_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_IMG_multisampled_render_to_texture")) return false;
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
		if (!DinamicGLFeature_IMG_multisampled_render_to_texture_loaded) {
			InitDinamicGLFeature_IMG_multisampled_render_to_texture();
		}
		if (DynamicGL_RenderbufferStorageMultisampleIMG==0) return false; 
		if (DynamicGL_FramebufferTexture2DMultisampleIMG==0) return false; 
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_IMG_multisampled_render_to_texture*/

/*OES_packed_depth_stencil*/
#ifdef USE_DYNAMIC_GL_OES_packed_depth_stencil
bool DinamicGLFeature_OES_packed_depth_stencil_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_OES_packed_depth_stencil")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_OES_packed_depth_stencil*/

/*EXT_discard_framebuffer*/
#ifdef USE_DYNAMIC_GL_EXT_discard_framebuffer
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
void (DYNAMIC_GL_APIENTRYP DynamicGL_DiscardFramebufferEXT)(GLenum target , GLsizei numAttachments , const GLenum *attachments) = 0;
static bool DinamicGLFeature_EXT_discard_framebuffer_loaded = false; 
static void InitDinamicGLFeature_EXT_discard_framebuffer() {
		DynamicGL_DiscardFramebufferEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLsizei numAttachments , const GLenum *attachments)>("glDiscardFramebufferEXT"); 
		DinamicGLFeature_EXT_discard_framebuffer_loaded = true; 
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
bool DinamicGLFeature_EXT_discard_framebuffer_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_EXT_discard_framebuffer")) return false;
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
		if (!DinamicGLFeature_EXT_discard_framebuffer_loaded) {
			InitDinamicGLFeature_EXT_discard_framebuffer();
		}
		if (DynamicGL_DiscardFramebufferEXT==0) return false; 
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_discard_framebuffer*/

/*OES_EGL_image*/
#ifdef USE_DYNAMIC_GL_OES_EGL_image
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
void (DYNAMIC_GL_APIENTRYP DynamicGL_EGLImageTargetTexture2DOES)(GLenum target , GLeglImageOES image) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_EGLImageTargetRenderbufferStorageOES)(GLenum target , GLeglImageOES image) = 0;
static bool DinamicGLFeature_OES_EGL_image_loaded = false; 
static void InitDinamicGLFeature_OES_EGL_image() {
		DynamicGL_EGLImageTargetTexture2DOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLeglImageOES image)>("glEGLImageTargetTexture2DOES"); 
		DynamicGL_EGLImageTargetRenderbufferStorageOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLeglImageOES image)>("glEGLImageTargetRenderbufferStorageOES"); 
		DinamicGLFeature_OES_EGL_image_loaded = true; 
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
bool DinamicGLFeature_OES_EGL_image_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_OES_EGL_image")) return false;
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
		if (!DinamicGLFeature_OES_EGL_image_loaded) {
			InitDinamicGLFeature_OES_EGL_image();
		}
		if (DynamicGL_EGLImageTargetTexture2DOES==0) return false; 
		if (DynamicGL_EGLImageTargetRenderbufferStorageOES==0) return false; 
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_OES_EGL_image*/

/*NV_fence*/
#ifdef USE_DYNAMIC_GL_NV_fence
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteFencesNV)(GLsizei n , const GLuint *fences) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GenFencesNV)(GLsizei n , GLuint *fences) = 0;
GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsFenceNV)(GLuint fence) = 0;
GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_TestFenceNV)(GLuint fence) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFenceivNV)(GLuint fence , GLenum pname , GLint *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_FinishFenceNV)(GLuint fence) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_SetFenceNV)(GLuint fence , GLenum condition) = 0;
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
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
bool DinamicGLFeature_NV_fence_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_NV_fence")) return false;
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
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
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_NV_fence*/

/*EXT_texture_lod_bias*/
#ifdef USE_DYNAMIC_GL_EXT_texture_lod_bias
bool DinamicGLFeature_EXT_texture_lod_bias_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_EXT_texture_lod_bias")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_texture_lod_bias*/

/*EXT_texture_filter_anisotropic*/
#ifdef USE_DYNAMIC_GL_EXT_texture_filter_anisotropic
bool DinamicGLFeature_EXT_texture_filter_anisotropic_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_EXT_texture_filter_anisotropic")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_texture_filter_anisotropic*/

/*EXT_texture_compression_dxt1*/
#ifdef USE_DYNAMIC_GL_EXT_texture_compression_dxt1
bool DinamicGLFeature_EXT_texture_compression_dxt1_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_EXT_texture_compression_dxt1")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_texture_compression_dxt1*/

/*EXT_sRGB*/
#ifdef USE_DYNAMIC_GL_EXT_sRGB
bool DinamicGLFeature_EXT_sRGB_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_EXT_sRGB")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_sRGB*/

/*OES_blend_equation_separate*/
#ifdef USE_DYNAMIC_GL_OES_blend_equation_separate
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendEquationSeparateOES)(GLenum modeRGB , GLenum modeAlpha) = 0;
static bool DinamicGLFeature_OES_blend_equation_separate_loaded = false; 
static void InitDinamicGLFeature_OES_blend_equation_separate() {
		DynamicGL_BlendEquationSeparateOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum modeRGB , GLenum modeAlpha)>("glBlendEquationSeparateOES"); 
		DinamicGLFeature_OES_blend_equation_separate_loaded = true; 
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
bool DinamicGLFeature_OES_blend_equation_separate_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_OES_blend_equation_separate")) return false;
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
		if (!DinamicGLFeature_OES_blend_equation_separate_loaded) {
			InitDinamicGLFeature_OES_blend_equation_separate();
		}
		if (DynamicGL_BlendEquationSeparateOES==0) return false; 
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_OES_blend_equation_separate*/

/*OES_texture_mirrored_repeat*/
#ifdef USE_DYNAMIC_GL_OES_texture_mirrored_repeat
bool DinamicGLFeature_OES_texture_mirrored_repeat_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_OES_texture_mirrored_repeat")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_OES_texture_mirrored_repeat*/

/*EXT_robustness*/
#ifdef USE_DYNAMIC_GL_EXT_robustness
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
GLenum (DYNAMIC_GL_APIENTRYP DynamicGL_GetGraphicsResetStatusEXT)() = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_ReadnPixelsEXT)(GLint x , GLint y , GLsizei width , GLsizei height , GLenum format , GLenum type , GLsizei bufSize , GLvoid *data) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GetnUniformfvEXT)(GLuint program , GLint location , GLsizei bufSize , GLfloat *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GetnUniformivEXT)(GLuint program , GLint location , GLsizei bufSize , GLint *params) = 0;
static bool DinamicGLFeature_EXT_robustness_loaded = false; 
static void InitDinamicGLFeature_EXT_robustness() {
		DynamicGL_GetGraphicsResetStatusEXT = DynamicGL_LoadFunction<GLenum (DYNAMIC_GL_APIENTRYP)()>("glGetGraphicsResetStatusEXT"); 
		DynamicGL_ReadnPixelsEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint x , GLint y , GLsizei width , GLsizei height , GLenum format , GLenum type , GLsizei bufSize , GLvoid *data)>("glReadnPixelsEXT"); 
		DynamicGL_GetnUniformfvEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLsizei bufSize , GLfloat *params)>("glGetnUniformfvEXT"); 
		DynamicGL_GetnUniformivEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLint location , GLsizei bufSize , GLint *params)>("glGetnUniformivEXT"); 
		DinamicGLFeature_EXT_robustness_loaded = true; 
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
bool DinamicGLFeature_EXT_robustness_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_EXT_robustness")) return false;
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
		if (!DinamicGLFeature_EXT_robustness_loaded) {
			InitDinamicGLFeature_EXT_robustness();
		}
		if (DynamicGL_GetGraphicsResetStatusEXT==0) return false; 
		if (DynamicGL_ReadnPixelsEXT==0) return false; 
		if (DynamicGL_GetnUniformfvEXT==0) return false; 
		if (DynamicGL_GetnUniformivEXT==0) return false; 
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_robustness*/

/*OES_draw_texture*/
#ifdef USE_DYNAMIC_GL_OES_draw_texture
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawTexsOES)(GLshort x , GLshort y , GLshort z , GLshort width , GLshort height) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawTexiOES)(GLint x , GLint y , GLint z , GLint width , GLint height) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawTexxOES)(GLfixed x , GLfixed y , GLfixed z , GLfixed width , GLfixed height) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawTexsvOES)(const GLshort *coords) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawTexivOES)(const GLint *coords) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawTexxvOES)(const GLfixed *coords) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawTexfOES)(GLfloat x , GLfloat y , GLfloat z , GLfloat width , GLfloat height) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawTexfvOES)(const GLfloat *coords) = 0;
static bool DinamicGLFeature_OES_draw_texture_loaded = false; 
static void InitDinamicGLFeature_OES_draw_texture() {
		DynamicGL_DrawTexsOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLshort x , GLshort y , GLshort z , GLshort width , GLshort height)>("glDrawTexsOES"); 
		DynamicGL_DrawTexiOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint x , GLint y , GLint z , GLint width , GLint height)>("glDrawTexiOES"); 
		DynamicGL_DrawTexxOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfixed x , GLfixed y , GLfixed z , GLfixed width , GLfixed height)>("glDrawTexxOES"); 
		DynamicGL_DrawTexsvOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLshort *coords)>("glDrawTexsvOES"); 
		DynamicGL_DrawTexivOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLint *coords)>("glDrawTexivOES"); 
		DynamicGL_DrawTexxvOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfixed *coords)>("glDrawTexxvOES"); 
		DynamicGL_DrawTexfOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfloat x , GLfloat y , GLfloat z , GLfloat width , GLfloat height)>("glDrawTexfOES"); 
		DynamicGL_DrawTexfvOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfloat *coords)>("glDrawTexfvOES"); 
		DinamicGLFeature_OES_draw_texture_loaded = true; 
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
bool DinamicGLFeature_OES_draw_texture_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_OES_draw_texture")) return false;
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
		if (!DinamicGLFeature_OES_draw_texture_loaded) {
			InitDinamicGLFeature_OES_draw_texture();
		}
		if (DynamicGL_DrawTexsOES==0) return false; 
		if (DynamicGL_DrawTexiOES==0) return false; 
		if (DynamicGL_DrawTexxOES==0) return false; 
		if (DynamicGL_DrawTexsvOES==0) return false; 
		if (DynamicGL_DrawTexivOES==0) return false; 
		if (DynamicGL_DrawTexxvOES==0) return false; 
		if (DynamicGL_DrawTexfOES==0) return false; 
		if (DynamicGL_DrawTexfvOES==0) return false; 
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_OES_draw_texture*/

/*OES_framebuffer_object*/
#ifdef USE_DYNAMIC_GL_OES_framebuffer_object
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsRenderbufferOES)(GLuint renderbuffer) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_BindRenderbufferOES)(GLenum target , GLuint renderbuffer) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteRenderbuffersOES)(GLsizei n , const GLuint* renderbuffers) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GenRenderbuffersOES)(GLsizei n , GLuint* renderbuffers) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_RenderbufferStorageOES)(GLenum target , GLenum internalformat , GLsizei width , GLsizei height) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GetRenderbufferParameterivOES)(GLenum target , GLenum pname , GLint* params) = 0;
GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsFramebufferOES)(GLuint framebuffer) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_BindFramebufferOES)(GLenum target , GLuint framebuffer) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteFramebuffersOES)(GLsizei n , const GLuint* framebuffers) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GenFramebuffersOES)(GLsizei n , GLuint* framebuffers) = 0;
GLenum (DYNAMIC_GL_APIENTRYP DynamicGL_CheckFramebufferStatusOES)(GLenum target) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferRenderbufferOES)(GLenum target , GLenum attachment , GLenum renderbuffertarget , GLuint renderbuffer) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferTexture2DOES)(GLenum target , GLenum attachment , GLenum textarget , GLuint texture , GLint level) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFramebufferAttachmentParameterivOES)(GLenum target , GLenum attachment , GLenum pname , GLint* params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GenerateMipmapOES)(GLenum target) = 0;
static bool DinamicGLFeature_OES_framebuffer_object_loaded = false; 
static void InitDinamicGLFeature_OES_framebuffer_object() {
		DynamicGL_IsRenderbufferOES = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLuint renderbuffer)>("glIsRenderbufferOES"); 
		DynamicGL_BindRenderbufferOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint renderbuffer)>("glBindRenderbufferOES"); 
		DynamicGL_DeleteRenderbuffersOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , const GLuint* renderbuffers)>("glDeleteRenderbuffersOES"); 
		DynamicGL_GenRenderbuffersOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , GLuint* renderbuffers)>("glGenRenderbuffersOES"); 
		DynamicGL_RenderbufferStorageOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum internalformat , GLsizei width , GLsizei height)>("glRenderbufferStorageOES"); 
		DynamicGL_GetRenderbufferParameterivOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint* params)>("glGetRenderbufferParameterivOES"); 
		DynamicGL_IsFramebufferOES = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLuint framebuffer)>("glIsFramebufferOES"); 
		DynamicGL_BindFramebufferOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLuint framebuffer)>("glBindFramebufferOES"); 
		DynamicGL_DeleteFramebuffersOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , const GLuint* framebuffers)>("glDeleteFramebuffersOES"); 
		DynamicGL_GenFramebuffersOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , GLuint* framebuffers)>("glGenFramebuffersOES"); 
		DynamicGL_CheckFramebufferStatusOES = DynamicGL_LoadFunction<GLenum (DYNAMIC_GL_APIENTRYP)(GLenum target)>("glCheckFramebufferStatusOES"); 
		DynamicGL_FramebufferRenderbufferOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum attachment , GLenum renderbuffertarget , GLuint renderbuffer)>("glFramebufferRenderbufferOES"); 
		DynamicGL_FramebufferTexture2DOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum attachment , GLenum textarget , GLuint texture , GLint level)>("glFramebufferTexture2DOES"); 
		DynamicGL_GetFramebufferAttachmentParameterivOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum attachment , GLenum pname , GLint* params)>("glGetFramebufferAttachmentParameterivOES"); 
		DynamicGL_GenerateMipmapOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target)>("glGenerateMipmapOES"); 
		DinamicGLFeature_OES_framebuffer_object_loaded = true; 
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
bool DinamicGLFeature_OES_framebuffer_object_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_OES_framebuffer_object")) return false;
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
		if (!DinamicGLFeature_OES_framebuffer_object_loaded) {
			InitDinamicGLFeature_OES_framebuffer_object();
		}
		if (DynamicGL_IsRenderbufferOES==0) return false; 
		if (DynamicGL_BindRenderbufferOES==0) return false; 
		if (DynamicGL_DeleteRenderbuffersOES==0) return false; 
		if (DynamicGL_GenRenderbuffersOES==0) return false; 
		if (DynamicGL_RenderbufferStorageOES==0) return false; 
		if (DynamicGL_GetRenderbufferParameterivOES==0) return false; 
		if (DynamicGL_IsFramebufferOES==0) return false; 
		if (DynamicGL_BindFramebufferOES==0) return false; 
		if (DynamicGL_DeleteFramebuffersOES==0) return false; 
		if (DynamicGL_GenFramebuffersOES==0) return false; 
		if (DynamicGL_CheckFramebufferStatusOES==0) return false; 
		if (DynamicGL_FramebufferRenderbufferOES==0) return false; 
		if (DynamicGL_FramebufferTexture2DOES==0) return false; 
		if (DynamicGL_GetFramebufferAttachmentParameterivOES==0) return false; 
		if (DynamicGL_GenerateMipmapOES==0) return false; 
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_OES_framebuffer_object*/

/*OES_matrix_get*/
#ifdef USE_DYNAMIC_GL_OES_matrix_get
bool DinamicGLFeature_OES_matrix_get_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_OES_matrix_get")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_OES_matrix_get*/

/*OES_byte_coordinates*/
#ifdef USE_DYNAMIC_GL_OES_byte_coordinates
bool DinamicGLFeature_OES_byte_coordinates_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_OES_byte_coordinates")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_OES_byte_coordinates*/

/*AMD_compressed_3DC_texture*/
#ifdef USE_DYNAMIC_GL_AMD_compressed_3DC_texture
bool DinamicGLFeature_AMD_compressed_3DC_texture_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_AMD_compressed_3DC_texture")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_AMD_compressed_3DC_texture*/

/*QCOM_extended_get2*/
#ifdef USE_DYNAMIC_GL_QCOM_extended_get2
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
void (DYNAMIC_GL_APIENTRYP DynamicGL_ExtGetShadersQCOM)(GLuint *shaders , GLint maxShaders , GLint *numShaders) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_ExtGetProgramsQCOM)(GLuint *programs , GLint maxPrograms , GLint *numPrograms) = 0;
GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_ExtIsProgramBinaryQCOM)(GLuint program) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_ExtGetProgramBinarySourceQCOM)(GLuint program , GLenum shadertype , GLchar *source , GLint *length) = 0;
static bool DinamicGLFeature_QCOM_extended_get2_loaded = false; 
static void InitDinamicGLFeature_QCOM_extended_get2() {
		DynamicGL_ExtGetShadersQCOM = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint *shaders , GLint maxShaders , GLint *numShaders)>("glExtGetShadersQCOM"); 
		DynamicGL_ExtGetProgramsQCOM = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint *programs , GLint maxPrograms , GLint *numPrograms)>("glExtGetProgramsQCOM"); 
		DynamicGL_ExtIsProgramBinaryQCOM = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLuint program)>("glExtIsProgramBinaryQCOM"); 
		DynamicGL_ExtGetProgramBinarySourceQCOM = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint program , GLenum shadertype , GLchar *source , GLint *length)>("glExtGetProgramBinarySourceQCOM"); 
		DinamicGLFeature_QCOM_extended_get2_loaded = true; 
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
bool DinamicGLFeature_QCOM_extended_get2_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_QCOM_extended_get2")) return false;
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
		if (!DinamicGLFeature_QCOM_extended_get2_loaded) {
			InitDinamicGLFeature_QCOM_extended_get2();
		}
		if (DynamicGL_ExtGetShadersQCOM==0) return false; 
		if (DynamicGL_ExtGetProgramsQCOM==0) return false; 
		if (DynamicGL_ExtIsProgramBinaryQCOM==0) return false; 
		if (DynamicGL_ExtGetProgramBinarySourceQCOM==0) return false; 
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_QCOM_extended_get2*/

/*IMG_read_format*/
#ifdef USE_DYNAMIC_GL_IMG_read_format
bool DinamicGLFeature_IMG_read_format_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_IMG_read_format")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_IMG_read_format*/

/*OES_matrix_palette*/
#ifdef USE_DYNAMIC_GL_OES_matrix_palette
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
void (DYNAMIC_GL_APIENTRYP DynamicGL_CurrentPaletteMatrixOES)(GLuint matrixpaletteindex) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_LoadPaletteFromModelViewMatrixOES)() = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixIndexPointerOES)(GLint size , GLenum type , GLsizei stride , const GLvoid *pointer) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_WeightPointerOES)(GLint size , GLenum type , GLsizei stride , const GLvoid *pointer) = 0;
static bool DinamicGLFeature_OES_matrix_palette_loaded = false; 
static void InitDinamicGLFeature_OES_matrix_palette() {
		DynamicGL_CurrentPaletteMatrixOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint matrixpaletteindex)>("glCurrentPaletteMatrixOES"); 
		DynamicGL_LoadPaletteFromModelViewMatrixOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)()>("glLoadPaletteFromModelViewMatrixOES"); 
		DynamicGL_MatrixIndexPointerOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint size , GLenum type , GLsizei stride , const GLvoid *pointer)>("glMatrixIndexPointerOES"); 
		DynamicGL_WeightPointerOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLint size , GLenum type , GLsizei stride , const GLvoid *pointer)>("glWeightPointerOES"); 
		DinamicGLFeature_OES_matrix_palette_loaded = true; 
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
bool DinamicGLFeature_OES_matrix_palette_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_OES_matrix_palette")) return false;
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
		if (!DinamicGLFeature_OES_matrix_palette_loaded) {
			InitDinamicGLFeature_OES_matrix_palette();
		}
		if (DynamicGL_CurrentPaletteMatrixOES==0) return false; 
		if (DynamicGL_LoadPaletteFromModelViewMatrixOES==0) return false; 
		if (DynamicGL_MatrixIndexPointerOES==0) return false; 
		if (DynamicGL_WeightPointerOES==0) return false; 
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_OES_matrix_palette*/

/*OES_stencil4*/
#ifdef USE_DYNAMIC_GL_OES_stencil4
bool DinamicGLFeature_OES_stencil4_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_OES_stencil4")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_OES_stencil4*/

/*QCOM_extended_get*/
#ifdef USE_DYNAMIC_GL_QCOM_extended_get
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
void (DYNAMIC_GL_APIENTRYP DynamicGL_ExtGetTexturesQCOM)(GLuint *textures , GLint maxTextures , GLint *numTextures) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_ExtGetBuffersQCOM)(GLuint *buffers , GLint maxBuffers , GLint *numBuffers) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_ExtGetRenderbuffersQCOM)(GLuint *renderbuffers , GLint maxRenderbuffers , GLint *numRenderbuffers) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_ExtGetFramebuffersQCOM)(GLuint *framebuffers , GLint maxFramebuffers , GLint *numFramebuffers) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_ExtGetTexLevelParameterivQCOM)(GLuint texture , GLenum face , GLint level , GLenum pname , GLint *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_ExtTexObjectStateOverrideiQCOM)(GLenum target , GLenum pname , GLint param) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_ExtGetTexSubImageQCOM)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLsizei width , GLsizei height , GLsizei depth , GLenum format , GLenum type , GLvoid *texels) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_ExtGetBufferPointervQCOM)(GLenum target , GLvoid *p1) = 0;
static bool DinamicGLFeature_QCOM_extended_get_loaded = false; 
static void InitDinamicGLFeature_QCOM_extended_get() {
		DynamicGL_ExtGetTexturesQCOM = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint *textures , GLint maxTextures , GLint *numTextures)>("glExtGetTexturesQCOM"); 
		DynamicGL_ExtGetBuffersQCOM = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint *buffers , GLint maxBuffers , GLint *numBuffers)>("glExtGetBuffersQCOM"); 
		DynamicGL_ExtGetRenderbuffersQCOM = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint *renderbuffers , GLint maxRenderbuffers , GLint *numRenderbuffers)>("glExtGetRenderbuffersQCOM"); 
		DynamicGL_ExtGetFramebuffersQCOM = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint *framebuffers , GLint maxFramebuffers , GLint *numFramebuffers)>("glExtGetFramebuffersQCOM"); 
		DynamicGL_ExtGetTexLevelParameterivQCOM = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint texture , GLenum face , GLint level , GLenum pname , GLint *params)>("glExtGetTexLevelParameterivQCOM"); 
		DynamicGL_ExtTexObjectStateOverrideiQCOM = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLint param)>("glExtTexObjectStateOverrideiQCOM"); 
		DynamicGL_ExtGetTexSubImageQCOM = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLsizei width , GLsizei height , GLsizei depth , GLenum format , GLenum type , GLvoid *texels)>("glExtGetTexSubImageQCOM"); 
		DynamicGL_ExtGetBufferPointervQCOM = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLvoid *p1)>("glExtGetBufferPointervQCOM"); 
		DinamicGLFeature_QCOM_extended_get_loaded = true; 
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
bool DinamicGLFeature_QCOM_extended_get_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_QCOM_extended_get")) return false;
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
		if (!DinamicGLFeature_QCOM_extended_get_loaded) {
			InitDinamicGLFeature_QCOM_extended_get();
		}
		if (DynamicGL_ExtGetTexturesQCOM==0) return false; 
		if (DynamicGL_ExtGetBuffersQCOM==0) return false; 
		if (DynamicGL_ExtGetRenderbuffersQCOM==0) return false; 
		if (DynamicGL_ExtGetFramebuffersQCOM==0) return false; 
		if (DynamicGL_ExtGetTexLevelParameterivQCOM==0) return false; 
		if (DynamicGL_ExtTexObjectStateOverrideiQCOM==0) return false; 
		if (DynamicGL_ExtGetTexSubImageQCOM==0) return false; 
		if (DynamicGL_ExtGetBufferPointervQCOM==0) return false; 
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_QCOM_extended_get*/

/*OES_EGL_image_external*/
#ifdef USE_DYNAMIC_GL_OES_EGL_image_external
bool DinamicGLFeature_OES_EGL_image_external_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_OES_EGL_image_external")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_OES_EGL_image_external*/

/*OES_vertex_array_object*/
#ifdef USE_DYNAMIC_GL_OES_vertex_array_object
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
void (DYNAMIC_GL_APIENTRYP DynamicGL_BindVertexArrayOES)(GLuint array) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteVertexArraysOES)(GLsizei n , const GLuint *arrays) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GenVertexArraysOES)(GLsizei n , GLuint *arrays) = 0;
GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsVertexArrayOES)(GLuint array) = 0;
static bool DinamicGLFeature_OES_vertex_array_object_loaded = false; 
static void InitDinamicGLFeature_OES_vertex_array_object() {
		DynamicGL_BindVertexArrayOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint array)>("glBindVertexArrayOES"); 
		DynamicGL_DeleteVertexArraysOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , const GLuint *arrays)>("glDeleteVertexArraysOES"); 
		DynamicGL_GenVertexArraysOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLsizei n , GLuint *arrays)>("glGenVertexArraysOES"); 
		DynamicGL_IsVertexArrayOES = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLuint array)>("glIsVertexArrayOES"); 
		DinamicGLFeature_OES_vertex_array_object_loaded = true; 
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
bool DinamicGLFeature_OES_vertex_array_object_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_OES_vertex_array_object")) return false;
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
		if (!DinamicGLFeature_OES_vertex_array_object_loaded) {
			InitDinamicGLFeature_OES_vertex_array_object();
		}
		if (DynamicGL_BindVertexArrayOES==0) return false; 
		if (DynamicGL_DeleteVertexArraysOES==0) return false; 
		if (DynamicGL_GenVertexArraysOES==0) return false; 
		if (DynamicGL_IsVertexArrayOES==0) return false; 
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_OES_vertex_array_object*/

/*OES_compressed_ETC1_RGB8_texture*/
#ifdef USE_DYNAMIC_GL_OES_compressed_ETC1_RGB8_texture
bool DinamicGLFeature_OES_compressed_ETC1_RGB8_texture_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_OES_compressed_ETC1_RGB8_texture")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_OES_compressed_ETC1_RGB8_texture*/

/*OES_depth24*/
#ifdef USE_DYNAMIC_GL_OES_depth24
bool DinamicGLFeature_OES_depth24_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_OES_depth24")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_OES_depth24*/

/*IMG_texture_env_enhanced_fixed_function*/
#ifdef USE_DYNAMIC_GL_IMG_texture_env_enhanced_fixed_function
bool DinamicGLFeature_IMG_texture_env_enhanced_fixed_function_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_IMG_texture_env_enhanced_fixed_function")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_IMG_texture_env_enhanced_fixed_function*/

/*OES_element_index_uint*/
#ifdef USE_DYNAMIC_GL_OES_element_index_uint
bool DinamicGLFeature_OES_element_index_uint_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_OES_element_index_uint")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_OES_element_index_uint*/

/*OES_blend_subtract*/
#ifdef USE_DYNAMIC_GL_OES_blend_subtract
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendEquationOES)(GLenum mode) = 0;
static bool DinamicGLFeature_OES_blend_subtract_loaded = false; 
static void InitDinamicGLFeature_OES_blend_subtract() {
		DynamicGL_BlendEquationOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode)>("glBlendEquationOES"); 
		DinamicGLFeature_OES_blend_subtract_loaded = true; 
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
bool DinamicGLFeature_OES_blend_subtract_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_OES_blend_subtract")) return false;
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
		if (!DinamicGLFeature_OES_blend_subtract_loaded) {
			InitDinamicGLFeature_OES_blend_subtract();
		}
		if (DynamicGL_BlendEquationOES==0) return false; 
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_OES_blend_subtract*/

/*OES_texture_env_crossbar*/
#ifdef USE_DYNAMIC_GL_OES_texture_env_crossbar
bool DinamicGLFeature_OES_texture_env_crossbar_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_OES_texture_env_crossbar")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_OES_texture_env_crossbar*/

/*QCOM_writeonly_rendering*/
#ifdef USE_DYNAMIC_GL_QCOM_writeonly_rendering
bool DinamicGLFeature_QCOM_writeonly_rendering_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_QCOM_writeonly_rendering")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_QCOM_writeonly_rendering*/

/*APPLE_texture_max_level*/
#ifdef USE_DYNAMIC_GL_APPLE_texture_max_level
bool DinamicGLFeature_APPLE_texture_max_level_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_APPLE_texture_max_level")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_APPLE_texture_max_level*/

/*ARM_rgba8*/
#ifdef USE_DYNAMIC_GL_ARM_rgba8
bool DinamicGLFeature_ARM_rgba8_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_ARM_rgba8")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_ARM_rgba8*/

/*QCOM_tiled_rendering*/
#ifdef USE_DYNAMIC_GL_QCOM_tiled_rendering
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
void (DYNAMIC_GL_APIENTRYP DynamicGL_StartTilingQCOM)(GLuint x , GLuint y , GLuint width , GLuint height , GLbitfield preserveMask) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_EndTilingQCOM)(GLbitfield preserveMask) = 0;
static bool DinamicGLFeature_QCOM_tiled_rendering_loaded = false; 
static void InitDinamicGLFeature_QCOM_tiled_rendering() {
		DynamicGL_StartTilingQCOM = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLuint x , GLuint y , GLuint width , GLuint height , GLbitfield preserveMask)>("glStartTilingQCOM"); 
		DynamicGL_EndTilingQCOM = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLbitfield preserveMask)>("glEndTilingQCOM"); 
		DinamicGLFeature_QCOM_tiled_rendering_loaded = true; 
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
bool DinamicGLFeature_QCOM_tiled_rendering_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_QCOM_tiled_rendering")) return false;
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
		if (!DinamicGLFeature_QCOM_tiled_rendering_loaded) {
			InitDinamicGLFeature_QCOM_tiled_rendering();
		}
		if (DynamicGL_StartTilingQCOM==0) return false; 
		if (DynamicGL_EndTilingQCOM==0) return false; 
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_QCOM_tiled_rendering*/

/*EXT_read_format_bgra*/
#ifdef USE_DYNAMIC_GL_EXT_read_format_bgra
bool DinamicGLFeature_EXT_read_format_bgra_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_EXT_read_format_bgra")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_read_format_bgra*/

/*OES_rgb8_rgba8*/
#ifdef USE_DYNAMIC_GL_OES_rgb8_rgba8
bool DinamicGLFeature_OES_rgb8_rgba8_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_OES_rgb8_rgba8")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_OES_rgb8_rgba8*/

/*OES_stencil1*/
#ifdef USE_DYNAMIC_GL_OES_stencil1
bool DinamicGLFeature_OES_stencil1_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_OES_stencil1")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_OES_stencil1*/

/*OES_texture_cube_map*/
#ifdef USE_DYNAMIC_GL_OES_texture_cube_map
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
void (DYNAMIC_GL_APIENTRYP DynamicGL_TexGenfOES)(GLenum coord , GLenum pname , GLfloat param) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_TexGenfvOES)(GLenum coord , GLenum pname , const GLfloat *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_TexGeniOES)(GLenum coord , GLenum pname , GLint param) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_TexGenivOES)(GLenum coord , GLenum pname , const GLint *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_TexGenxOES)(GLenum coord , GLenum pname , GLfixed param) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_TexGenxvOES)(GLenum coord , GLenum pname , const GLfixed *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexGenfvOES)(GLenum coord , GLenum pname , GLfloat *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexGenivOES)(GLenum coord , GLenum pname , GLint *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexGenxvOES)(GLenum coord , GLenum pname , GLfixed *params) = 0;
static bool DinamicGLFeature_OES_texture_cube_map_loaded = false; 
static void InitDinamicGLFeature_OES_texture_cube_map() {
		DynamicGL_TexGenfOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum coord , GLenum pname , GLfloat param)>("glTexGenfOES"); 
		DynamicGL_TexGenfvOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum coord , GLenum pname , const GLfloat *params)>("glTexGenfvOES"); 
		DynamicGL_TexGeniOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum coord , GLenum pname , GLint param)>("glTexGeniOES"); 
		DynamicGL_TexGenivOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum coord , GLenum pname , const GLint *params)>("glTexGenivOES"); 
		DynamicGL_TexGenxOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum coord , GLenum pname , GLfixed param)>("glTexGenxOES"); 
		DynamicGL_TexGenxvOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum coord , GLenum pname , const GLfixed *params)>("glTexGenxvOES"); 
		DynamicGL_GetTexGenfvOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum coord , GLenum pname , GLfloat *params)>("glGetTexGenfvOES"); 
		DynamicGL_GetTexGenivOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum coord , GLenum pname , GLint *params)>("glGetTexGenivOES"); 
		DynamicGL_GetTexGenxvOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum coord , GLenum pname , GLfixed *params)>("glGetTexGenxvOES"); 
		DinamicGLFeature_OES_texture_cube_map_loaded = true; 
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
bool DinamicGLFeature_OES_texture_cube_map_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_OES_texture_cube_map")) return false;
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
		if (!DinamicGLFeature_OES_texture_cube_map_loaded) {
			InitDinamicGLFeature_OES_texture_cube_map();
		}
		if (DynamicGL_TexGenfOES==0) return false; 
		if (DynamicGL_TexGenfvOES==0) return false; 
		if (DynamicGL_TexGeniOES==0) return false; 
		if (DynamicGL_TexGenivOES==0) return false; 
		if (DynamicGL_TexGenxOES==0) return false; 
		if (DynamicGL_TexGenxvOES==0) return false; 
		if (DynamicGL_GetTexGenfvOES==0) return false; 
		if (DynamicGL_GetTexGenivOES==0) return false; 
		if (DynamicGL_GetTexGenxvOES==0) return false; 
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_OES_texture_cube_map*/

/*AMD_compressed_ATC_texture*/
#ifdef USE_DYNAMIC_GL_AMD_compressed_ATC_texture
bool DinamicGLFeature_AMD_compressed_ATC_texture_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_AMD_compressed_ATC_texture")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_AMD_compressed_ATC_texture*/

/*OES_mapbuffer*/
#ifdef USE_DYNAMIC_GL_OES_mapbuffer
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_UnmapBufferOES)(GLenum target) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GetBufferPointervOES)(GLenum target , GLenum pname , GLvoid *p1) = 0;
static bool DinamicGLFeature_OES_mapbuffer_loaded = false; 
static void InitDinamicGLFeature_OES_mapbuffer() {
		DynamicGL_UnmapBufferOES = DynamicGL_LoadFunction<GLboolean (DYNAMIC_GL_APIENTRYP)(GLenum target)>("glUnmapBufferOES"); 
		DynamicGL_GetBufferPointervOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLvoid *p1)>("glGetBufferPointervOES"); 
		DinamicGLFeature_OES_mapbuffer_loaded = true; 
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
bool DinamicGLFeature_OES_mapbuffer_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_OES_mapbuffer")) return false;
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
		if (!DinamicGLFeature_OES_mapbuffer_loaded) {
			InitDinamicGLFeature_OES_mapbuffer();
		}
		if (DynamicGL_UnmapBufferOES==0) return false; 
		if (DynamicGL_GetBufferPointervOES==0) return false; 
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_OES_mapbuffer*/

/*EXT_blend_minmax*/
#ifdef USE_DYNAMIC_GL_EXT_blend_minmax
bool DinamicGLFeature_EXT_blend_minmax_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_EXT_blend_minmax")) return false;
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_blend_minmax*/

/*EXT_multi_draw_arrays*/
#ifdef USE_DYNAMIC_GL_EXT_multi_draw_arrays
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiDrawArraysEXT)(GLenum mode , GLint *first , GLsizei *count , GLsizei primcount) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiDrawElementsEXT)(GLenum mode , const GLsizei *count , GLenum type , const GLvoid* *indices , GLsizei primcount) = 0;
static bool DinamicGLFeature_EXT_multi_draw_arrays_loaded = false; 
static void InitDinamicGLFeature_EXT_multi_draw_arrays() {
		DynamicGL_MultiDrawArraysEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , GLint *first , GLsizei *count , GLsizei primcount)>("glMultiDrawArraysEXT"); 
		DynamicGL_MultiDrawElementsEXT = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum mode , const GLsizei *count , GLenum type , const GLvoid* *indices , GLsizei primcount)>("glMultiDrawElementsEXT"); 
		DinamicGLFeature_EXT_multi_draw_arrays_loaded = true; 
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
bool DinamicGLFeature_EXT_multi_draw_arrays_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_EXT_multi_draw_arrays")) return false;
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
		if (!DinamicGLFeature_EXT_multi_draw_arrays_loaded) {
			InitDinamicGLFeature_EXT_multi_draw_arrays();
		}
		if (DynamicGL_MultiDrawArraysEXT==0) return false; 
		if (DynamicGL_MultiDrawElementsEXT==0) return false; 
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_EXT_multi_draw_arrays*/

/*OES_fixed_point*/
#ifdef USE_DYNAMIC_GL_OES_fixed_point
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
void (DYNAMIC_GL_APIENTRYP DynamicGL_AlphaFuncxOES)(GLenum func , GLclampx ref) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearColorxOES)(GLclampx red , GLclampx green , GLclampx blue , GLclampx alpha) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearDepthxOES)(GLclampx depth) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_ClipPlanexOES)(GLenum plane , const GLfixed *equation) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4xOES)(GLfixed red , GLfixed green , GLfixed blue , GLfixed alpha) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_DepthRangexOES)(GLclampx zNear , GLclampx zFar) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_FogxOES)(GLenum pname , GLfixed param) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_FogxvOES)(GLenum pname , const GLfixed *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_FrustumxOES)(GLfixed left , GLfixed right , GLfixed bottom , GLfixed top , GLfixed zNear , GLfixed zFar) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFixedvOES)(GLenum pname , GLfixed *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GetLightxvOES)(GLenum light , GLenum pname , GLfixed *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMaterialxvOES)(GLenum face , GLenum pname , GLfixed *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexEnvxvOES)(GLenum env , GLenum pname , GLfixed *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexParameterxvOES)(GLenum target , GLenum pname , GLfixed *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_LightModelxOES)(GLenum pname , GLfixed param) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_LightModelxvOES)(GLenum pname , const GLfixed *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_LightxOES)(GLenum light , GLenum pname , GLfixed param) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_LightxvOES)(GLenum light , GLenum pname , const GLfixed *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_LineWidthxOES)(GLfixed width) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_LoadMatrixxOES)(const GLfixed *m) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_MaterialxOES)(GLenum face , GLenum pname , GLfixed param) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_MaterialxvOES)(GLenum face , GLenum pname , const GLfixed *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_MultMatrixxOES)(const GLfixed *m) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4xOES)(GLenum target , GLfixed s , GLfixed t , GLfixed r , GLfixed q) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_Normal3xOES)(GLfixed nx , GLfixed ny , GLfixed nz) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_OrthoxOES)(GLfixed left , GLfixed right , GLfixed bottom , GLfixed top , GLfixed zNear , GLfixed zFar) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameterxOES)(GLenum pname , GLfixed param) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameterxvOES)(GLenum pname , const GLfixed *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_PointSizexOES)(GLfixed size) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_PolygonOffsetxOES)(GLfixed factor , GLfixed units) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_RotatexOES)(GLfixed angle , GLfixed x , GLfixed y , GLfixed z) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_SampleCoveragexOES)(GLclampx value , GLboolean invert) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_ScalexOES)(GLfixed x , GLfixed y , GLfixed z) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_TexEnvxOES)(GLenum target , GLenum pname , GLfixed param) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_TexEnvxvOES)(GLenum target , GLenum pname , const GLfixed *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_TexParameterxOES)(GLenum target , GLenum pname , GLfixed param) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_TexParameterxvOES)(GLenum target , GLenum pname , const GLfixed *params) = 0;
void (DYNAMIC_GL_APIENTRYP DynamicGL_TranslatexOES)(GLfixed x , GLfixed y , GLfixed z) = 0;
static bool DinamicGLFeature_OES_fixed_point_loaded = false; 
static void InitDinamicGLFeature_OES_fixed_point() {
		DynamicGL_AlphaFuncxOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum func , GLclampx ref)>("glAlphaFuncxOES"); 
		DynamicGL_ClearColorxOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLclampx red , GLclampx green , GLclampx blue , GLclampx alpha)>("glClearColorxOES"); 
		DynamicGL_ClearDepthxOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLclampx depth)>("glClearDepthxOES"); 
		DynamicGL_ClipPlanexOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum plane , const GLfixed *equation)>("glClipPlanexOES"); 
		DynamicGL_Color4xOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfixed red , GLfixed green , GLfixed blue , GLfixed alpha)>("glColor4xOES"); 
		DynamicGL_DepthRangexOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLclampx zNear , GLclampx zFar)>("glDepthRangexOES"); 
		DynamicGL_FogxOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLfixed param)>("glFogxOES"); 
		DynamicGL_FogxvOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , const GLfixed *params)>("glFogxvOES"); 
		DynamicGL_FrustumxOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfixed left , GLfixed right , GLfixed bottom , GLfixed top , GLfixed zNear , GLfixed zFar)>("glFrustumxOES"); 
		DynamicGL_GetFixedvOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLfixed *params)>("glGetFixedvOES"); 
		DynamicGL_GetLightxvOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum light , GLenum pname , GLfixed *params)>("glGetLightxvOES"); 
		DynamicGL_GetMaterialxvOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum face , GLenum pname , GLfixed *params)>("glGetMaterialxvOES"); 
		DynamicGL_GetTexEnvxvOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum env , GLenum pname , GLfixed *params)>("glGetTexEnvxvOES"); 
		DynamicGL_GetTexParameterxvOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLfixed *params)>("glGetTexParameterxvOES"); 
		DynamicGL_LightModelxOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLfixed param)>("glLightModelxOES"); 
		DynamicGL_LightModelxvOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , const GLfixed *params)>("glLightModelxvOES"); 
		DynamicGL_LightxOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum light , GLenum pname , GLfixed param)>("glLightxOES"); 
		DynamicGL_LightxvOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum light , GLenum pname , const GLfixed *params)>("glLightxvOES"); 
		DynamicGL_LineWidthxOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfixed width)>("glLineWidthxOES"); 
		DynamicGL_LoadMatrixxOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfixed *m)>("glLoadMatrixxOES"); 
		DynamicGL_MaterialxOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum face , GLenum pname , GLfixed param)>("glMaterialxOES"); 
		DynamicGL_MaterialxvOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum face , GLenum pname , const GLfixed *params)>("glMaterialxvOES"); 
		DynamicGL_MultMatrixxOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(const GLfixed *m)>("glMultMatrixxOES"); 
		DynamicGL_MultiTexCoord4xOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLfixed s , GLfixed t , GLfixed r , GLfixed q)>("glMultiTexCoord4xOES"); 
		DynamicGL_Normal3xOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfixed nx , GLfixed ny , GLfixed nz)>("glNormal3xOES"); 
		DynamicGL_OrthoxOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfixed left , GLfixed right , GLfixed bottom , GLfixed top , GLfixed zNear , GLfixed zFar)>("glOrthoxOES"); 
		DynamicGL_PointParameterxOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , GLfixed param)>("glPointParameterxOES"); 
		DynamicGL_PointParameterxvOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum pname , const GLfixed *params)>("glPointParameterxvOES"); 
		DynamicGL_PointSizexOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfixed size)>("glPointSizexOES"); 
		DynamicGL_PolygonOffsetxOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfixed factor , GLfixed units)>("glPolygonOffsetxOES"); 
		DynamicGL_RotatexOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfixed angle , GLfixed x , GLfixed y , GLfixed z)>("glRotatexOES"); 
		DynamicGL_SampleCoveragexOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLclampx value , GLboolean invert)>("glSampleCoveragexOES"); 
		DynamicGL_ScalexOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfixed x , GLfixed y , GLfixed z)>("glScalexOES"); 
		DynamicGL_TexEnvxOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLfixed param)>("glTexEnvxOES"); 
		DynamicGL_TexEnvxvOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , const GLfixed *params)>("glTexEnvxvOES"); 
		DynamicGL_TexParameterxOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , GLfixed param)>("glTexParameterxOES"); 
		DynamicGL_TexParameterxvOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLenum target , GLenum pname , const GLfixed *params)>("glTexParameterxvOES"); 
		DynamicGL_TranslatexOES = DynamicGL_LoadFunction<void (DYNAMIC_GL_APIENTRYP)(GLfixed x , GLfixed y , GLfixed z)>("glTranslatexOES"); 
		DinamicGLFeature_OES_fixed_point_loaded = true; 
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
bool DinamicGLFeature_OES_fixed_point_Supported() {
		static bool supported = false;
		static bool checked = false;
		if (checked) return supported;
		checked = true;
		if(!DynamicGL_CheckExtensionSupported("GL_OES_fixed_point")) return false;
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
		if (!DinamicGLFeature_OES_fixed_point_loaded) {
			InitDinamicGLFeature_OES_fixed_point();
		}
		if (DynamicGL_AlphaFuncxOES==0) return false; 
		if (DynamicGL_ClearColorxOES==0) return false; 
		if (DynamicGL_ClearDepthxOES==0) return false; 
		if (DynamicGL_ClipPlanexOES==0) return false; 
		if (DynamicGL_Color4xOES==0) return false; 
		if (DynamicGL_DepthRangexOES==0) return false; 
		if (DynamicGL_FogxOES==0) return false; 
		if (DynamicGL_FogxvOES==0) return false; 
		if (DynamicGL_FrustumxOES==0) return false; 
		if (DynamicGL_GetFixedvOES==0) return false; 
		if (DynamicGL_GetLightxvOES==0) return false; 
		if (DynamicGL_GetMaterialxvOES==0) return false; 
		if (DynamicGL_GetTexEnvxvOES==0) return false; 
		if (DynamicGL_GetTexParameterxvOES==0) return false; 
		if (DynamicGL_LightModelxOES==0) return false; 
		if (DynamicGL_LightModelxvOES==0) return false; 
		if (DynamicGL_LightxOES==0) return false; 
		if (DynamicGL_LightxvOES==0) return false; 
		if (DynamicGL_LineWidthxOES==0) return false; 
		if (DynamicGL_LoadMatrixxOES==0) return false; 
		if (DynamicGL_MaterialxOES==0) return false; 
		if (DynamicGL_MaterialxvOES==0) return false; 
		if (DynamicGL_MultMatrixxOES==0) return false; 
		if (DynamicGL_MultiTexCoord4xOES==0) return false; 
		if (DynamicGL_Normal3xOES==0) return false; 
		if (DynamicGL_OrthoxOES==0) return false; 
		if (DynamicGL_PointParameterxOES==0) return false; 
		if (DynamicGL_PointParameterxvOES==0) return false; 
		if (DynamicGL_PointSizexOES==0) return false; 
		if (DynamicGL_PolygonOffsetxOES==0) return false; 
		if (DynamicGL_RotatexOES==0) return false; 
		if (DynamicGL_SampleCoveragexOES==0) return false; 
		if (DynamicGL_ScalexOES==0) return false; 
		if (DynamicGL_TexEnvxOES==0) return false; 
		if (DynamicGL_TexEnvxvOES==0) return false; 
		if (DynamicGL_TexParameterxOES==0) return false; 
		if (DynamicGL_TexParameterxvOES==0) return false; 
		if (DynamicGL_TranslatexOES==0) return false; 
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
		supported = true;
		return true;
}
#endif /*USE_DYNAMIC_GL_OES_fixed_point*/

void InternalDynamicGLLoadSubset() {
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
#ifdef USE_DYNAMIC_GL_VERSION_1_1
			InitDinamicGLFeature_VERSION_1_1();
#endif /*USE_DYNAMIC_GL_VERSION_1_1*/
#ifdef USE_DYNAMIC_GL_OES_blend_func_separate
			InitDinamicGLFeature_OES_blend_func_separate();
#endif /*USE_DYNAMIC_GL_OES_blend_func_separate*/
#ifdef USE_DYNAMIC_GL_QCOM_driver_control
			InitDinamicGLFeature_QCOM_driver_control();
#endif /*USE_DYNAMIC_GL_QCOM_driver_control*/
#ifdef USE_DYNAMIC_GL_EXT_multisampled_render_to_texture
			InitDinamicGLFeature_EXT_multisampled_render_to_texture();
#endif /*USE_DYNAMIC_GL_EXT_multisampled_render_to_texture*/
#ifdef USE_DYNAMIC_GL_EXT_texture_storage
			InitDinamicGLFeature_EXT_texture_storage();
#endif /*USE_DYNAMIC_GL_EXT_texture_storage*/
#ifdef USE_DYNAMIC_GL_APPLE_framebuffer_multisample
			InitDinamicGLFeature_APPLE_framebuffer_multisample();
#endif /*USE_DYNAMIC_GL_APPLE_framebuffer_multisample*/
#ifdef USE_DYNAMIC_GL_IMG_user_clip_plane
			InitDinamicGLFeature_IMG_user_clip_plane();
#endif /*USE_DYNAMIC_GL_IMG_user_clip_plane*/
#ifdef USE_DYNAMIC_GL_OES_single_precision
			InitDinamicGLFeature_OES_single_precision();
#endif /*USE_DYNAMIC_GL_OES_single_precision*/
#ifdef USE_DYNAMIC_GL_IMG_multisampled_render_to_texture
			InitDinamicGLFeature_IMG_multisampled_render_to_texture();
#endif /*USE_DYNAMIC_GL_IMG_multisampled_render_to_texture*/
#ifdef USE_DYNAMIC_GL_EXT_discard_framebuffer
			InitDinamicGLFeature_EXT_discard_framebuffer();
#endif /*USE_DYNAMIC_GL_EXT_discard_framebuffer*/
#ifdef USE_DYNAMIC_GL_OES_EGL_image
			InitDinamicGLFeature_OES_EGL_image();
#endif /*USE_DYNAMIC_GL_OES_EGL_image*/
#ifdef USE_DYNAMIC_GL_NV_fence
			InitDinamicGLFeature_NV_fence();
#endif /*USE_DYNAMIC_GL_NV_fence*/
#ifdef USE_DYNAMIC_GL_OES_blend_equation_separate
			InitDinamicGLFeature_OES_blend_equation_separate();
#endif /*USE_DYNAMIC_GL_OES_blend_equation_separate*/
#ifdef USE_DYNAMIC_GL_EXT_robustness
			InitDinamicGLFeature_EXT_robustness();
#endif /*USE_DYNAMIC_GL_EXT_robustness*/
#ifdef USE_DYNAMIC_GL_OES_draw_texture
			InitDinamicGLFeature_OES_draw_texture();
#endif /*USE_DYNAMIC_GL_OES_draw_texture*/
#ifdef USE_DYNAMIC_GL_OES_framebuffer_object
			InitDinamicGLFeature_OES_framebuffer_object();
#endif /*USE_DYNAMIC_GL_OES_framebuffer_object*/
#ifdef USE_DYNAMIC_GL_QCOM_extended_get2
			InitDinamicGLFeature_QCOM_extended_get2();
#endif /*USE_DYNAMIC_GL_QCOM_extended_get2*/
#ifdef USE_DYNAMIC_GL_OES_matrix_palette
			InitDinamicGLFeature_OES_matrix_palette();
#endif /*USE_DYNAMIC_GL_OES_matrix_palette*/
#ifdef USE_DYNAMIC_GL_QCOM_extended_get
			InitDinamicGLFeature_QCOM_extended_get();
#endif /*USE_DYNAMIC_GL_QCOM_extended_get*/
#ifdef USE_DYNAMIC_GL_OES_vertex_array_object
			InitDinamicGLFeature_OES_vertex_array_object();
#endif /*USE_DYNAMIC_GL_OES_vertex_array_object*/
#ifdef USE_DYNAMIC_GL_OES_blend_subtract
			InitDinamicGLFeature_OES_blend_subtract();
#endif /*USE_DYNAMIC_GL_OES_blend_subtract*/
#ifdef USE_DYNAMIC_GL_QCOM_tiled_rendering
			InitDinamicGLFeature_QCOM_tiled_rendering();
#endif /*USE_DYNAMIC_GL_QCOM_tiled_rendering*/
#ifdef USE_DYNAMIC_GL_OES_texture_cube_map
			InitDinamicGLFeature_OES_texture_cube_map();
#endif /*USE_DYNAMIC_GL_OES_texture_cube_map*/
#ifdef USE_DYNAMIC_GL_OES_mapbuffer
			InitDinamicGLFeature_OES_mapbuffer();
#endif /*USE_DYNAMIC_GL_OES_mapbuffer*/
#ifdef USE_DYNAMIC_GL_EXT_multi_draw_arrays
			InitDinamicGLFeature_EXT_multi_draw_arrays();
#endif /*USE_DYNAMIC_GL_EXT_multi_draw_arrays*/
#ifdef USE_DYNAMIC_GL_OES_fixed_point
			InitDinamicGLFeature_OES_fixed_point();
#endif /*USE_DYNAMIC_GL_OES_fixed_point*/
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
}
