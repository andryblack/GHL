/*VERSION_1_1*/
#ifdef USE_DYNAMIC_GL_VERSION_1_1
typedef void GLvoid;
typedef char GLchar;
typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef khronos_int8_t GLbyte;
typedef short GLshort;
typedef int GLint;
typedef int GLsizei;
typedef khronos_uint8_t GLubyte;
typedef unsigned short GLushort;
typedef unsigned int GLuint;
typedef khronos_float_t GLfloat;
typedef khronos_float_t GLclampf;
typedef khronos_int32_t GLfixed;
typedef khronos_int32_t GLclampx;
typedef khronos_intptr_t GLintptr;
typedef khronos_ssize_t GLsizeiptr;
#define GL_VERSION_ES_CM_1_0 1
#define GL_VERSION_ES_CL_1_0 1
#define GL_VERSION_ES_CM_1_1 1
#define GL_VERSION_ES_CL_1_1 1
#define GL_DEPTH_BUFFER_BIT 0x00000100
#define GL_STENCIL_BUFFER_BIT 0x00000400
#define GL_COLOR_BUFFER_BIT 0x00004000
#define GL_FALSE 0
#define GL_TRUE 1
#define GL_POINTS 0x0000
#define GL_LINES 0x0001
#define GL_LINE_LOOP 0x0002
#define GL_LINE_STRIP 0x0003
#define GL_TRIANGLES 0x0004
#define GL_TRIANGLE_STRIP 0x0005
#define GL_TRIANGLE_FAN 0x0006
#define GL_NEVER 0x0200
#define GL_LESS 0x0201
#define GL_EQUAL 0x0202
#define GL_LEQUAL 0x0203
#define GL_GREATER 0x0204
#define GL_NOTEQUAL 0x0205
#define GL_GEQUAL 0x0206
#define GL_ALWAYS 0x0207
#define GL_ZERO 0
#define GL_ONE 1
#define GL_SRC_COLOR 0x0300
#define GL_ONE_MINUS_SRC_COLOR 0x0301
#define GL_SRC_ALPHA 0x0302
#define GL_ONE_MINUS_SRC_ALPHA 0x0303
#define GL_DST_ALPHA 0x0304
#define GL_ONE_MINUS_DST_ALPHA 0x0305
#define GL_DST_COLOR 0x0306
#define GL_ONE_MINUS_DST_COLOR 0x0307
#define GL_SRC_ALPHA_SATURATE 0x0308
#define GL_CLIP_PLANE0 0x3000
#define GL_CLIP_PLANE1 0x3001
#define GL_CLIP_PLANE2 0x3002
#define GL_CLIP_PLANE3 0x3003
#define GL_CLIP_PLANE4 0x3004
#define GL_CLIP_PLANE5 0x3005
#define GL_FRONT 0x0404
#define GL_BACK 0x0405
#define GL_FRONT_AND_BACK 0x0408
#define GL_FOG 0x0B60
#define GL_LIGHTING 0x0B50
#define GL_TEXTURE_2D 0x0DE1
#define GL_CULL_FACE 0x0B44
#define GL_ALPHA_TEST 0x0BC0
#define GL_BLEND 0x0BE2
#define GL_COLOR_LOGIC_OP 0x0BF2
#define GL_DITHER 0x0BD0
#define GL_STENCIL_TEST 0x0B90
#define GL_DEPTH_TEST 0x0B71
#define GL_POINT_SMOOTH 0x0B10
#define GL_LINE_SMOOTH 0x0B20
#define GL_SCISSOR_TEST 0x0C11
#define GL_COLOR_MATERIAL 0x0B57
#define GL_NORMALIZE 0x0BA1
#define GL_RESCALE_NORMAL 0x803A
#define GL_POLYGON_OFFSET_FILL 0x8037
#define GL_VERTEX_ARRAY 0x8074
#define GL_NORMAL_ARRAY 0x8075
#define GL_COLOR_ARRAY 0x8076
#define GL_TEXTURE_COORD_ARRAY 0x8078
#define GL_MULTISAMPLE 0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE 0x809E
#define GL_SAMPLE_ALPHA_TO_ONE 0x809F
#define GL_SAMPLE_COVERAGE 0x80A0
#define GL_NO_ERROR 0
#define GL_INVALID_ENUM 0x0500
#define GL_INVALID_VALUE 0x0501
#define GL_INVALID_OPERATION 0x0502
#define GL_STACK_OVERFLOW 0x0503
#define GL_STACK_UNDERFLOW 0x0504
#define GL_OUT_OF_MEMORY 0x0505
#define GL_EXP 0x0800
#define GL_EXP2 0x0801
#define GL_FOG_DENSITY 0x0B62
#define GL_FOG_START 0x0B63
#define GL_FOG_END 0x0B64
#define GL_FOG_MODE 0x0B65
#define GL_FOG_COLOR 0x0B66
#define GL_CW 0x0900
#define GL_CCW 0x0901
#define GL_CURRENT_COLOR 0x0B00
#define GL_CURRENT_NORMAL 0x0B02
#define GL_CURRENT_TEXTURE_COORDS 0x0B03
#define GL_POINT_SIZE 0x0B11
#define GL_POINT_SIZE_MIN 0x8126
#define GL_POINT_SIZE_MAX 0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE 0x8128
#define GL_POINT_DISTANCE_ATTENUATION 0x8129
#define GL_SMOOTH_POINT_SIZE_RANGE 0x0B12
#define GL_LINE_WIDTH 0x0B21
#define GL_SMOOTH_LINE_WIDTH_RANGE 0x0B22
#define GL_ALIASED_POINT_SIZE_RANGE 0x846D
#define GL_ALIASED_LINE_WIDTH_RANGE 0x846E
#define GL_CULL_FACE_MODE 0x0B45
#define GL_FRONT_FACE 0x0B46
#define GL_SHADE_MODEL 0x0B54
#define GL_DEPTH_RANGE 0x0B70
#define GL_DEPTH_WRITEMASK 0x0B72
#define GL_DEPTH_CLEAR_VALUE 0x0B73
#define GL_DEPTH_FUNC 0x0B74
#define GL_STENCIL_CLEAR_VALUE 0x0B91
#define GL_STENCIL_FUNC 0x0B92
#define GL_STENCIL_VALUE_MASK 0x0B93
#define GL_STENCIL_FAIL 0x0B94
#define GL_STENCIL_PASS_DEPTH_FAIL 0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS 0x0B96
#define GL_STENCIL_REF 0x0B97
#define GL_STENCIL_WRITEMASK 0x0B98
#define GL_MATRIX_MODE 0x0BA0
#define GL_VIEWPORT 0x0BA2
#define GL_MODELVIEW_STACK_DEPTH 0x0BA3
#define GL_PROJECTION_STACK_DEPTH 0x0BA4
#define GL_TEXTURE_STACK_DEPTH 0x0BA5
#define GL_MODELVIEW_MATRIX 0x0BA6
#define GL_PROJECTION_MATRIX 0x0BA7
#define GL_TEXTURE_MATRIX 0x0BA8
#define GL_ALPHA_TEST_FUNC 0x0BC1
#define GL_ALPHA_TEST_REF 0x0BC2
#define GL_BLEND_DST 0x0BE0
#define GL_BLEND_SRC 0x0BE1
#define GL_LOGIC_OP_MODE 0x0BF0
#define GL_SCISSOR_BOX 0x0C10
#define GL_SCISSOR_TEST 0x0C11
#define GL_COLOR_CLEAR_VALUE 0x0C22
#define GL_COLOR_WRITEMASK 0x0C23
#define GL_UNPACK_ALIGNMENT 0x0CF5
#define GL_PACK_ALIGNMENT 0x0D05
#define GL_MAX_LIGHTS 0x0D31
#define GL_MAX_CLIP_PLANES 0x0D32
#define GL_MAX_TEXTURE_SIZE 0x0D33
#define GL_MAX_MODELVIEW_STACK_DEPTH 0x0D36
#define GL_MAX_PROJECTION_STACK_DEPTH 0x0D38
#define GL_MAX_TEXTURE_STACK_DEPTH 0x0D39
#define GL_MAX_VIEWPORT_DIMS 0x0D3A
#define GL_MAX_TEXTURE_UNITS 0x84E2
#define GL_SUBPIXEL_BITS 0x0D50
#define GL_RED_BITS 0x0D52
#define GL_GREEN_BITS 0x0D53
#define GL_BLUE_BITS 0x0D54
#define GL_ALPHA_BITS 0x0D55
#define GL_DEPTH_BITS 0x0D56
#define GL_STENCIL_BITS 0x0D57
#define GL_POLYGON_OFFSET_UNITS 0x2A00
#define GL_POLYGON_OFFSET_FILL 0x8037
#define GL_POLYGON_OFFSET_FACTOR 0x8038
#define GL_TEXTURE_BINDING_2D 0x8069
#define GL_VERTEX_ARRAY_SIZE 0x807A
#define GL_VERTEX_ARRAY_TYPE 0x807B
#define GL_VERTEX_ARRAY_STRIDE 0x807C
#define GL_NORMAL_ARRAY_TYPE 0x807E
#define GL_NORMAL_ARRAY_STRIDE 0x807F
#define GL_COLOR_ARRAY_SIZE 0x8081
#define GL_COLOR_ARRAY_TYPE 0x8082
#define GL_COLOR_ARRAY_STRIDE 0x8083
#define GL_TEXTURE_COORD_ARRAY_SIZE 0x8088
#define GL_TEXTURE_COORD_ARRAY_TYPE 0x8089
#define GL_TEXTURE_COORD_ARRAY_STRIDE 0x808A
#define GL_VERTEX_ARRAY_POINTER 0x808E
#define GL_NORMAL_ARRAY_POINTER 0x808F
#define GL_COLOR_ARRAY_POINTER 0x8090
#define GL_TEXTURE_COORD_ARRAY_POINTER 0x8092
#define GL_SAMPLE_BUFFERS 0x80A8
#define GL_SAMPLES 0x80A9
#define GL_SAMPLE_COVERAGE_VALUE 0x80AA
#define GL_SAMPLE_COVERAGE_INVERT 0x80AB
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS 0x86A3
#define GL_DONT_CARE 0x1100
#define GL_FASTEST 0x1101
#define GL_NICEST 0x1102
#define GL_PERSPECTIVE_CORRECTION_HINT 0x0C50
#define GL_POINT_SMOOTH_HINT 0x0C51
#define GL_LINE_SMOOTH_HINT 0x0C52
#define GL_FOG_HINT 0x0C54
#define GL_GENERATE_MIPMAP_HINT 0x8192
#define GL_LIGHT_MODEL_AMBIENT 0x0B53
#define GL_LIGHT_MODEL_TWO_SIDE 0x0B52
#define GL_AMBIENT 0x1200
#define GL_DIFFUSE 0x1201
#define GL_SPECULAR 0x1202
#define GL_POSITION 0x1203
#define GL_SPOT_DIRECTION 0x1204
#define GL_SPOT_EXPONENT 0x1205
#define GL_SPOT_CUTOFF 0x1206
#define GL_CONSTANT_ATTENUATION 0x1207
#define GL_LINEAR_ATTENUATION 0x1208
#define GL_QUADRATIC_ATTENUATION 0x1209
#define GL_BYTE 0x1400
#define GL_UNSIGNED_BYTE 0x1401
#define GL_SHORT 0x1402
#define GL_UNSIGNED_SHORT 0x1403
#define GL_FLOAT 0x1406
#define GL_FIXED 0x140C
#define GL_CLEAR 0x1500
#define GL_AND 0x1501
#define GL_AND_REVERSE 0x1502
#define GL_COPY 0x1503
#define GL_AND_INVERTED 0x1504
#define GL_NOOP 0x1505
#define GL_XOR 0x1506
#define GL_OR 0x1507
#define GL_NOR 0x1508
#define GL_EQUIV 0x1509
#define GL_INVERT 0x150A
#define GL_OR_REVERSE 0x150B
#define GL_COPY_INVERTED 0x150C
#define GL_OR_INVERTED 0x150D
#define GL_NAND 0x150E
#define GL_SET 0x150F
#define GL_EMISSION 0x1600
#define GL_SHININESS 0x1601
#define GL_AMBIENT_AND_DIFFUSE 0x1602
#define GL_MODELVIEW 0x1700
#define GL_PROJECTION 0x1701
#define GL_TEXTURE 0x1702
#define GL_ALPHA 0x1906
#define GL_RGB 0x1907
#define GL_RGBA 0x1908
#define GL_LUMINANCE 0x1909
#define GL_LUMINANCE_ALPHA 0x190A
#define GL_UNPACK_ALIGNMENT 0x0CF5
#define GL_PACK_ALIGNMENT 0x0D05
#define GL_UNSIGNED_SHORT_4_4_4_4 0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1 0x8034
#define GL_UNSIGNED_SHORT_5_6_5 0x8363
#define GL_FLAT 0x1D00
#define GL_SMOOTH 0x1D01
#define GL_KEEP 0x1E00
#define GL_REPLACE 0x1E01
#define GL_INCR 0x1E02
#define GL_DECR 0x1E03
#define GL_VENDOR 0x1F00
#define GL_RENDERER 0x1F01
#define GL_VERSION 0x1F02
#define GL_EXTENSIONS 0x1F03
#define GL_MODULATE 0x2100
#define GL_DECAL 0x2101
#define GL_ADD 0x0104
#define GL_TEXTURE_ENV_MODE 0x2200
#define GL_TEXTURE_ENV_COLOR 0x2201
#define GL_TEXTURE_ENV 0x2300
#define GL_NEAREST 0x2600
#define GL_LINEAR 0x2601
#define GL_NEAREST_MIPMAP_NEAREST 0x2700
#define GL_LINEAR_MIPMAP_NEAREST 0x2701
#define GL_NEAREST_MIPMAP_LINEAR 0x2702
#define GL_LINEAR_MIPMAP_LINEAR 0x2703
#define GL_TEXTURE_MAG_FILTER 0x2800
#define GL_TEXTURE_MIN_FILTER 0x2801
#define GL_TEXTURE_WRAP_S 0x2802
#define GL_TEXTURE_WRAP_T 0x2803
#define GL_GENERATE_MIPMAP 0x8191
#define GL_TEXTURE0 0x84C0
#define GL_TEXTURE1 0x84C1
#define GL_TEXTURE2 0x84C2
#define GL_TEXTURE3 0x84C3
#define GL_TEXTURE4 0x84C4
#define GL_TEXTURE5 0x84C5
#define GL_TEXTURE6 0x84C6
#define GL_TEXTURE7 0x84C7
#define GL_TEXTURE8 0x84C8
#define GL_TEXTURE9 0x84C9
#define GL_TEXTURE10 0x84CA
#define GL_TEXTURE11 0x84CB
#define GL_TEXTURE12 0x84CC
#define GL_TEXTURE13 0x84CD
#define GL_TEXTURE14 0x84CE
#define GL_TEXTURE15 0x84CF
#define GL_TEXTURE16 0x84D0
#define GL_TEXTURE17 0x84D1
#define GL_TEXTURE18 0x84D2
#define GL_TEXTURE19 0x84D3
#define GL_TEXTURE20 0x84D4
#define GL_TEXTURE21 0x84D5
#define GL_TEXTURE22 0x84D6
#define GL_TEXTURE23 0x84D7
#define GL_TEXTURE24 0x84D8
#define GL_TEXTURE25 0x84D9
#define GL_TEXTURE26 0x84DA
#define GL_TEXTURE27 0x84DB
#define GL_TEXTURE28 0x84DC
#define GL_TEXTURE29 0x84DD
#define GL_TEXTURE30 0x84DE
#define GL_TEXTURE31 0x84DF
#define GL_ACTIVE_TEXTURE 0x84E0
#define GL_CLIENT_ACTIVE_TEXTURE 0x84E1
#define GL_REPEAT 0x2901
#define GL_CLAMP_TO_EDGE 0x812F
#define GL_LIGHT0 0x4000
#define GL_LIGHT1 0x4001
#define GL_LIGHT2 0x4002
#define GL_LIGHT3 0x4003
#define GL_LIGHT4 0x4004
#define GL_LIGHT5 0x4005
#define GL_LIGHT6 0x4006
#define GL_LIGHT7 0x4007
#define GL_ARRAY_BUFFER 0x8892
#define GL_ELEMENT_ARRAY_BUFFER 0x8893
#define GL_ARRAY_BUFFER_BINDING 0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING 0x8895
#define GL_VERTEX_ARRAY_BUFFER_BINDING 0x8896
#define GL_NORMAL_ARRAY_BUFFER_BINDING 0x8897
#define GL_COLOR_ARRAY_BUFFER_BINDING 0x8898
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING 0x889A
#define GL_STATIC_DRAW 0x88E4
#define GL_DYNAMIC_DRAW 0x88E8
#define GL_BUFFER_SIZE 0x8764
#define GL_BUFFER_USAGE 0x8765
#define GL_SUBTRACT 0x84E7
#define GL_COMBINE 0x8570
#define GL_COMBINE_RGB 0x8571
#define GL_COMBINE_ALPHA 0x8572
#define GL_RGB_SCALE 0x8573
#define GL_ADD_SIGNED 0x8574
#define GL_INTERPOLATE 0x8575
#define GL_CONSTANT 0x8576
#define GL_PRIMARY_COLOR 0x8577
#define GL_PREVIOUS 0x8578
#define GL_OPERAND0_RGB 0x8590
#define GL_OPERAND1_RGB 0x8591
#define GL_OPERAND2_RGB 0x8592
#define GL_OPERAND0_ALPHA 0x8598
#define GL_OPERAND1_ALPHA 0x8599
#define GL_OPERAND2_ALPHA 0x859A
#define GL_ALPHA_SCALE 0x0D1C
#define GL_SRC0_RGB 0x8580
#define GL_SRC1_RGB 0x8581
#define GL_SRC2_RGB 0x8582
#define GL_SRC0_ALPHA 0x8588
#define GL_SRC1_ALPHA 0x8589
#define GL_SRC2_ALPHA 0x858A
#define GL_DOT3_RGB 0x86AE
#define GL_DOT3_RGBA 0x86AF
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_AlphaFunc)(GLenum func , GLclampf ref);
#define glAlphaFunc DynamicGL_AlphaFunc
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearColor)(GLclampf red , GLclampf green , GLclampf blue , GLclampf alpha);
#define glClearColor DynamicGL_ClearColor
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearDepthf)(GLclampf depth);
#define glClearDepthf DynamicGL_ClearDepthf
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClipPlanef)(GLenum plane , const GLfloat *equation);
#define glClipPlanef DynamicGL_ClipPlanef
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4f)(GLfloat red , GLfloat green , GLfloat blue , GLfloat alpha);
#define glColor4f DynamicGL_Color4f
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DepthRangef)(GLclampf zNear , GLclampf zFar);
#define glDepthRangef DynamicGL_DepthRangef
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Fogf)(GLenum pname , GLfloat param);
#define glFogf DynamicGL_Fogf
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Fogfv)(GLenum pname , const GLfloat *params);
#define glFogfv DynamicGL_Fogfv
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Frustumf)(GLfloat left , GLfloat right , GLfloat bottom , GLfloat top , GLfloat zNear , GLfloat zFar);
#define glFrustumf DynamicGL_Frustumf
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFloatv)(GLenum pname , GLfloat *params);
#define glGetFloatv DynamicGL_GetFloatv
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetLightfv)(GLenum light , GLenum pname , GLfloat *params);
#define glGetLightfv DynamicGL_GetLightfv
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMaterialfv)(GLenum face , GLenum pname , GLfloat *params);
#define glGetMaterialfv DynamicGL_GetMaterialfv
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexEnvfv)(GLenum env , GLenum pname , GLfloat *params);
#define glGetTexEnvfv DynamicGL_GetTexEnvfv
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexParameterfv)(GLenum target , GLenum pname , GLfloat *params);
#define glGetTexParameterfv DynamicGL_GetTexParameterfv
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LightModelf)(GLenum pname , GLfloat param);
#define glLightModelf DynamicGL_LightModelf
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LightModelfv)(GLenum pname , const GLfloat *params);
#define glLightModelfv DynamicGL_LightModelfv
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Lightf)(GLenum light , GLenum pname , GLfloat param);
#define glLightf DynamicGL_Lightf
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Lightfv)(GLenum light , GLenum pname , const GLfloat *params);
#define glLightfv DynamicGL_Lightfv
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LineWidth)(GLfloat width);
#define glLineWidth DynamicGL_LineWidth
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LoadMatrixf)(const GLfloat *m);
#define glLoadMatrixf DynamicGL_LoadMatrixf
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Materialf)(GLenum face , GLenum pname , GLfloat param);
#define glMaterialf DynamicGL_Materialf
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Materialfv)(GLenum face , GLenum pname , const GLfloat *params);
#define glMaterialfv DynamicGL_Materialfv
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultMatrixf)(const GLfloat *m);
#define glMultMatrixf DynamicGL_MultMatrixf
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4f)(GLenum target , GLfloat s , GLfloat t , GLfloat r , GLfloat q);
#define glMultiTexCoord4f DynamicGL_MultiTexCoord4f
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Normal3f)(GLfloat nx , GLfloat ny , GLfloat nz);
#define glNormal3f DynamicGL_Normal3f
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Orthof)(GLfloat left , GLfloat right , GLfloat bottom , GLfloat top , GLfloat zNear , GLfloat zFar);
#define glOrthof DynamicGL_Orthof
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameterf)(GLenum pname , GLfloat param);
#define glPointParameterf DynamicGL_PointParameterf
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameterfv)(GLenum pname , const GLfloat *params);
#define glPointParameterfv DynamicGL_PointParameterfv
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PointSize)(GLfloat size);
#define glPointSize DynamicGL_PointSize
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PolygonOffset)(GLfloat factor , GLfloat units);
#define glPolygonOffset DynamicGL_PolygonOffset
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Rotatef)(GLfloat angle , GLfloat x , GLfloat y , GLfloat z);
#define glRotatef DynamicGL_Rotatef
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Scalef)(GLfloat x , GLfloat y , GLfloat z);
#define glScalef DynamicGL_Scalef
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexEnvf)(GLenum target , GLenum pname , GLfloat param);
#define glTexEnvf DynamicGL_TexEnvf
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexEnvfv)(GLenum target , GLenum pname , const GLfloat *params);
#define glTexEnvfv DynamicGL_TexEnvfv
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexParameterf)(GLenum target , GLenum pname , GLfloat param);
#define glTexParameterf DynamicGL_TexParameterf
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexParameterfv)(GLenum target , GLenum pname , const GLfloat *params);
#define glTexParameterfv DynamicGL_TexParameterfv
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Translatef)(GLfloat x , GLfloat y , GLfloat z);
#define glTranslatef DynamicGL_Translatef
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ActiveTexture)(GLenum texture);
#define glActiveTexture DynamicGL_ActiveTexture
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_AlphaFuncx)(GLenum func , GLclampx ref);
#define glAlphaFuncx DynamicGL_AlphaFuncx
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindBuffer)(GLenum target , GLuint buffer);
#define glBindBuffer DynamicGL_BindBuffer
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindTexture)(GLenum target , GLuint texture);
#define glBindTexture DynamicGL_BindTexture
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendFunc)(GLenum sfactor , GLenum dfactor);
#define glBlendFunc DynamicGL_BlendFunc
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BufferData)(GLenum target , GLsizeiptr size , const GLvoid *data , GLenum usage);
#define glBufferData DynamicGL_BufferData
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BufferSubData)(GLenum target , GLintptr offset , GLsizeiptr size , const GLvoid *data);
#define glBufferSubData DynamicGL_BufferSubData
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Clear)(GLbitfield mask);
#define glClear DynamicGL_Clear
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearColorx)(GLclampx red , GLclampx green , GLclampx blue , GLclampx alpha);
#define glClearColorx DynamicGL_ClearColorx
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearDepthx)(GLclampx depth);
#define glClearDepthx DynamicGL_ClearDepthx
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearStencil)(GLint s);
#define glClearStencil DynamicGL_ClearStencil
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClientActiveTexture)(GLenum texture);
#define glClientActiveTexture DynamicGL_ClientActiveTexture
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClipPlanex)(GLenum plane , const GLfixed *equation);
#define glClipPlanex DynamicGL_ClipPlanex
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4ub)(GLubyte red , GLubyte green , GLubyte blue , GLubyte alpha);
#define glColor4ub DynamicGL_Color4ub
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4x)(GLfixed red , GLfixed green , GLfixed blue , GLfixed alpha);
#define glColor4x DynamicGL_Color4x
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorMask)(GLboolean red , GLboolean green , GLboolean blue , GLboolean alpha);
#define glColorMask DynamicGL_ColorMask
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorPointer)(GLint size , GLenum type , GLsizei stride , const GLvoid *pointer);
#define glColorPointer DynamicGL_ColorPointer
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTexImage2D)(GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLint border , GLsizei imageSize , const GLvoid *data);
#define glCompressedTexImage2D DynamicGL_CompressedTexImage2D
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTexSubImage2D)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLsizei width , GLsizei height , GLenum format , GLsizei imageSize , const GLvoid *data);
#define glCompressedTexSubImage2D DynamicGL_CompressedTexSubImage2D
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyTexImage2D)(GLenum target , GLint level , GLenum internalformat , GLint x , GLint y , GLsizei width , GLsizei height , GLint border);
#define glCopyTexImage2D DynamicGL_CopyTexImage2D
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyTexSubImage2D)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint x , GLint y , GLsizei width , GLsizei height);
#define glCopyTexSubImage2D DynamicGL_CopyTexSubImage2D
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CullFace)(GLenum mode);
#define glCullFace DynamicGL_CullFace
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteBuffers)(GLsizei n , const GLuint *buffers);
#define glDeleteBuffers DynamicGL_DeleteBuffers
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteTextures)(GLsizei n , const GLuint *textures);
#define glDeleteTextures DynamicGL_DeleteTextures
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DepthFunc)(GLenum func);
#define glDepthFunc DynamicGL_DepthFunc
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DepthMask)(GLboolean flag);
#define glDepthMask DynamicGL_DepthMask
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DepthRangex)(GLclampx zNear , GLclampx zFar);
#define glDepthRangex DynamicGL_DepthRangex
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Disable)(GLenum cap);
#define glDisable DynamicGL_Disable
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DisableClientState)(GLenum array);
#define glDisableClientState DynamicGL_DisableClientState
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawArrays)(GLenum mode , GLint first , GLsizei count);
#define glDrawArrays DynamicGL_DrawArrays
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawElements)(GLenum mode , GLsizei count , GLenum type , const GLvoid *indices);
#define glDrawElements DynamicGL_DrawElements
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Enable)(GLenum cap);
#define glEnable DynamicGL_Enable
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EnableClientState)(GLenum array);
#define glEnableClientState DynamicGL_EnableClientState
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Finish)();
#define glFinish DynamicGL_Finish
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Flush)();
#define glFlush DynamicGL_Flush
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Fogx)(GLenum pname , GLfixed param);
#define glFogx DynamicGL_Fogx
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Fogxv)(GLenum pname , const GLfixed *params);
#define glFogxv DynamicGL_Fogxv
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FrontFace)(GLenum mode);
#define glFrontFace DynamicGL_FrontFace
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Frustumx)(GLfixed left , GLfixed right , GLfixed bottom , GLfixed top , GLfixed zNear , GLfixed zFar);
#define glFrustumx DynamicGL_Frustumx
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetBooleanv)(GLenum pname , GLboolean *params);
#define glGetBooleanv DynamicGL_GetBooleanv
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetBufferParameteriv)(GLenum target , GLenum pname , GLint *params);
#define glGetBufferParameteriv DynamicGL_GetBufferParameteriv
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GenBuffers)(GLsizei n , GLuint *buffers);
#define glGenBuffers DynamicGL_GenBuffers
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GenTextures)(GLsizei n , GLuint *textures);
#define glGenTextures DynamicGL_GenTextures
extern GLenum (DYNAMIC_GL_APIENTRYP DynamicGL_GetError)();
#define glGetError DynamicGL_GetError
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFixedv)(GLenum pname , GLfixed *params);
#define glGetFixedv DynamicGL_GetFixedv
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetIntegerv)(GLenum pname , GLint *params);
#define glGetIntegerv DynamicGL_GetIntegerv
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetLightxv)(GLenum light , GLenum pname , GLfixed *params);
#define glGetLightxv DynamicGL_GetLightxv
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMaterialxv)(GLenum face , GLenum pname , GLfixed *params);
#define glGetMaterialxv DynamicGL_GetMaterialxv
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPointerv)(GLenum pname , GLvoid *p1);
#define glGetPointerv DynamicGL_GetPointerv
extern GLubyte* (DYNAMIC_GL_APIENTRYP DynamicGL_GetString)(GLenum name);
#define glGetString DynamicGL_GetString
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexEnviv)(GLenum env , GLenum pname , GLint *params);
#define glGetTexEnviv DynamicGL_GetTexEnviv
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexEnvxv)(GLenum env , GLenum pname , GLfixed *params);
#define glGetTexEnvxv DynamicGL_GetTexEnvxv
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexParameteriv)(GLenum target , GLenum pname , GLint *params);
#define glGetTexParameteriv DynamicGL_GetTexParameteriv
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexParameterxv)(GLenum target , GLenum pname , GLfixed *params);
#define glGetTexParameterxv DynamicGL_GetTexParameterxv
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Hint)(GLenum target , GLenum mode);
#define glHint DynamicGL_Hint
extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsBuffer)(GLuint buffer);
#define glIsBuffer DynamicGL_IsBuffer
extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsEnabled)(GLenum cap);
#define glIsEnabled DynamicGL_IsEnabled
extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsTexture)(GLuint texture);
#define glIsTexture DynamicGL_IsTexture
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LightModelx)(GLenum pname , GLfixed param);
#define glLightModelx DynamicGL_LightModelx
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LightModelxv)(GLenum pname , const GLfixed *params);
#define glLightModelxv DynamicGL_LightModelxv
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Lightx)(GLenum light , GLenum pname , GLfixed param);
#define glLightx DynamicGL_Lightx
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Lightxv)(GLenum light , GLenum pname , const GLfixed *params);
#define glLightxv DynamicGL_Lightxv
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LineWidthx)(GLfixed width);
#define glLineWidthx DynamicGL_LineWidthx
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LoadIdentity)();
#define glLoadIdentity DynamicGL_LoadIdentity
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LoadMatrixx)(const GLfixed *m);
#define glLoadMatrixx DynamicGL_LoadMatrixx
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LogicOp)(GLenum opcode);
#define glLogicOp DynamicGL_LogicOp
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Materialx)(GLenum face , GLenum pname , GLfixed param);
#define glMaterialx DynamicGL_Materialx
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Materialxv)(GLenum face , GLenum pname , const GLfixed *params);
#define glMaterialxv DynamicGL_Materialxv
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixMode)(GLenum mode);
#define glMatrixMode DynamicGL_MatrixMode
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultMatrixx)(const GLfixed *m);
#define glMultMatrixx DynamicGL_MultMatrixx
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4x)(GLenum target , GLfixed s , GLfixed t , GLfixed r , GLfixed q);
#define glMultiTexCoord4x DynamicGL_MultiTexCoord4x
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Normal3x)(GLfixed nx , GLfixed ny , GLfixed nz);
#define glNormal3x DynamicGL_Normal3x
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NormalPointer)(GLenum type , GLsizei stride , const GLvoid *pointer);
#define glNormalPointer DynamicGL_NormalPointer
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Orthox)(GLfixed left , GLfixed right , GLfixed bottom , GLfixed top , GLfixed zNear , GLfixed zFar);
#define glOrthox DynamicGL_Orthox
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelStorei)(GLenum pname , GLint param);
#define glPixelStorei DynamicGL_PixelStorei
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameterx)(GLenum pname , GLfixed param);
#define glPointParameterx DynamicGL_PointParameterx
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameterxv)(GLenum pname , const GLfixed *params);
#define glPointParameterxv DynamicGL_PointParameterxv
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PointSizex)(GLfixed size);
#define glPointSizex DynamicGL_PointSizex
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PolygonOffsetx)(GLfixed factor , GLfixed units);
#define glPolygonOffsetx DynamicGL_PolygonOffsetx
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PopMatrix)();
#define glPopMatrix DynamicGL_PopMatrix
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PushMatrix)();
#define glPushMatrix DynamicGL_PushMatrix
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ReadPixels)(GLint x , GLint y , GLsizei width , GLsizei height , GLenum format , GLenum type , GLvoid *pixels);
#define glReadPixels DynamicGL_ReadPixels
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Rotatex)(GLfixed angle , GLfixed x , GLfixed y , GLfixed z);
#define glRotatex DynamicGL_Rotatex
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SampleCoverage)(GLclampf value , GLboolean invert);
#define glSampleCoverage DynamicGL_SampleCoverage
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SampleCoveragex)(GLclampx value , GLboolean invert);
#define glSampleCoveragex DynamicGL_SampleCoveragex
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Scalex)(GLfixed x , GLfixed y , GLfixed z);
#define glScalex DynamicGL_Scalex
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Scissor)(GLint x , GLint y , GLsizei width , GLsizei height);
#define glScissor DynamicGL_Scissor
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ShadeModel)(GLenum mode);
#define glShadeModel DynamicGL_ShadeModel
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_StencilFunc)(GLenum func , GLint ref , GLuint mask);
#define glStencilFunc DynamicGL_StencilFunc
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_StencilMask)(GLuint mask);
#define glStencilMask DynamicGL_StencilMask
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_StencilOp)(GLenum fail , GLenum zfail , GLenum zpass);
#define glStencilOp DynamicGL_StencilOp
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoordPointer)(GLint size , GLenum type , GLsizei stride , const GLvoid *pointer);
#define glTexCoordPointer DynamicGL_TexCoordPointer
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexEnvi)(GLenum target , GLenum pname , GLint param);
#define glTexEnvi DynamicGL_TexEnvi
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexEnvx)(GLenum target , GLenum pname , GLfixed param);
#define glTexEnvx DynamicGL_TexEnvx
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexEnviv)(GLenum target , GLenum pname , const GLint *params);
#define glTexEnviv DynamicGL_TexEnviv
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexEnvxv)(GLenum target , GLenum pname , const GLfixed *params);
#define glTexEnvxv DynamicGL_TexEnvxv
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexImage2D)(GLenum target , GLint level , GLint internalformat , GLsizei width , GLsizei height , GLint border , GLenum format , GLenum type , const GLvoid *pixels);
#define glTexImage2D DynamicGL_TexImage2D
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexParameteri)(GLenum target , GLenum pname , GLint param);
#define glTexParameteri DynamicGL_TexParameteri
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexParameterx)(GLenum target , GLenum pname , GLfixed param);
#define glTexParameterx DynamicGL_TexParameterx
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexParameteriv)(GLenum target , GLenum pname , const GLint *params);
#define glTexParameteriv DynamicGL_TexParameteriv
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexParameterxv)(GLenum target , GLenum pname , const GLfixed *params);
#define glTexParameterxv DynamicGL_TexParameterxv
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexSubImage2D)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLsizei width , GLsizei height , GLenum format , GLenum type , const GLvoid *pixels);
#define glTexSubImage2D DynamicGL_TexSubImage2D
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Translatex)(GLfixed x , GLfixed y , GLfixed z);
#define glTranslatex DynamicGL_Translatex
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexPointer)(GLint size , GLenum type , GLsizei stride , const GLvoid *pointer);
#define glVertexPointer DynamicGL_VertexPointer
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Viewport)(GLint x , GLint y , GLsizei width , GLsizei height);
#define glViewport DynamicGL_Viewport
#else
extern "C" {
 DYNAMIC_GL_APIENTRY void glAlphaFunc( GLenum func , GLclampf ref );
 DYNAMIC_GL_APIENTRY void glClearColor( GLclampf red , GLclampf green , GLclampf blue , GLclampf alpha );
 DYNAMIC_GL_APIENTRY void glClearDepthf( GLclampf depth );
 DYNAMIC_GL_APIENTRY void glClipPlanef( GLenum plane , const GLfloat *equation );
 DYNAMIC_GL_APIENTRY void glColor4f( GLfloat red , GLfloat green , GLfloat blue , GLfloat alpha );
 DYNAMIC_GL_APIENTRY void glDepthRangef( GLclampf zNear , GLclampf zFar );
 DYNAMIC_GL_APIENTRY void glFogf( GLenum pname , GLfloat param );
 DYNAMIC_GL_APIENTRY void glFogfv( GLenum pname , const GLfloat *params );
 DYNAMIC_GL_APIENTRY void glFrustumf( GLfloat left , GLfloat right , GLfloat bottom , GLfloat top , GLfloat zNear , GLfloat zFar );
 DYNAMIC_GL_APIENTRY void glGetFloatv( GLenum pname , GLfloat *params );
 DYNAMIC_GL_APIENTRY void glGetLightfv( GLenum light , GLenum pname , GLfloat *params );
 DYNAMIC_GL_APIENTRY void glGetMaterialfv( GLenum face , GLenum pname , GLfloat *params );
 DYNAMIC_GL_APIENTRY void glGetTexEnvfv( GLenum env , GLenum pname , GLfloat *params );
 DYNAMIC_GL_APIENTRY void glGetTexParameterfv( GLenum target , GLenum pname , GLfloat *params );
 DYNAMIC_GL_APIENTRY void glLightModelf( GLenum pname , GLfloat param );
 DYNAMIC_GL_APIENTRY void glLightModelfv( GLenum pname , const GLfloat *params );
 DYNAMIC_GL_APIENTRY void glLightf( GLenum light , GLenum pname , GLfloat param );
 DYNAMIC_GL_APIENTRY void glLightfv( GLenum light , GLenum pname , const GLfloat *params );
 DYNAMIC_GL_APIENTRY void glLineWidth( GLfloat width );
 DYNAMIC_GL_APIENTRY void glLoadMatrixf( const GLfloat *m );
 DYNAMIC_GL_APIENTRY void glMaterialf( GLenum face , GLenum pname , GLfloat param );
 DYNAMIC_GL_APIENTRY void glMaterialfv( GLenum face , GLenum pname , const GLfloat *params );
 DYNAMIC_GL_APIENTRY void glMultMatrixf( const GLfloat *m );
 DYNAMIC_GL_APIENTRY void glMultiTexCoord4f( GLenum target , GLfloat s , GLfloat t , GLfloat r , GLfloat q );
 DYNAMIC_GL_APIENTRY void glNormal3f( GLfloat nx , GLfloat ny , GLfloat nz );
 DYNAMIC_GL_APIENTRY void glOrthof( GLfloat left , GLfloat right , GLfloat bottom , GLfloat top , GLfloat zNear , GLfloat zFar );
 DYNAMIC_GL_APIENTRY void glPointParameterf( GLenum pname , GLfloat param );
 DYNAMIC_GL_APIENTRY void glPointParameterfv( GLenum pname , const GLfloat *params );
 DYNAMIC_GL_APIENTRY void glPointSize( GLfloat size );
 DYNAMIC_GL_APIENTRY void glPolygonOffset( GLfloat factor , GLfloat units );
 DYNAMIC_GL_APIENTRY void glRotatef( GLfloat angle , GLfloat x , GLfloat y , GLfloat z );
 DYNAMIC_GL_APIENTRY void glScalef( GLfloat x , GLfloat y , GLfloat z );
 DYNAMIC_GL_APIENTRY void glTexEnvf( GLenum target , GLenum pname , GLfloat param );
 DYNAMIC_GL_APIENTRY void glTexEnvfv( GLenum target , GLenum pname , const GLfloat *params );
 DYNAMIC_GL_APIENTRY void glTexParameterf( GLenum target , GLenum pname , GLfloat param );
 DYNAMIC_GL_APIENTRY void glTexParameterfv( GLenum target , GLenum pname , const GLfloat *params );
 DYNAMIC_GL_APIENTRY void glTranslatef( GLfloat x , GLfloat y , GLfloat z );
 DYNAMIC_GL_APIENTRY void glActiveTexture( GLenum texture );
 DYNAMIC_GL_APIENTRY void glAlphaFuncx( GLenum func , GLclampx ref );
 DYNAMIC_GL_APIENTRY void glBindBuffer( GLenum target , GLuint buffer );
 DYNAMIC_GL_APIENTRY void glBindTexture( GLenum target , GLuint texture );
 DYNAMIC_GL_APIENTRY void glBlendFunc( GLenum sfactor , GLenum dfactor );
 DYNAMIC_GL_APIENTRY void glBufferData( GLenum target , GLsizeiptr size , const GLvoid *data , GLenum usage );
 DYNAMIC_GL_APIENTRY void glBufferSubData( GLenum target , GLintptr offset , GLsizeiptr size , const GLvoid *data );
 DYNAMIC_GL_APIENTRY void glClear( GLbitfield mask );
 DYNAMIC_GL_APIENTRY void glClearColorx( GLclampx red , GLclampx green , GLclampx blue , GLclampx alpha );
 DYNAMIC_GL_APIENTRY void glClearDepthx( GLclampx depth );
 DYNAMIC_GL_APIENTRY void glClearStencil( GLint s );
 DYNAMIC_GL_APIENTRY void glClientActiveTexture( GLenum texture );
 DYNAMIC_GL_APIENTRY void glClipPlanex( GLenum plane , const GLfixed *equation );
 DYNAMIC_GL_APIENTRY void glColor4ub( GLubyte red , GLubyte green , GLubyte blue , GLubyte alpha );
 DYNAMIC_GL_APIENTRY void glColor4x( GLfixed red , GLfixed green , GLfixed blue , GLfixed alpha );
 DYNAMIC_GL_APIENTRY void glColorMask( GLboolean red , GLboolean green , GLboolean blue , GLboolean alpha );
 DYNAMIC_GL_APIENTRY void glColorPointer( GLint size , GLenum type , GLsizei stride , const GLvoid *pointer );
 DYNAMIC_GL_APIENTRY void glCompressedTexImage2D( GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLint border , GLsizei imageSize , const GLvoid *data );
 DYNAMIC_GL_APIENTRY void glCompressedTexSubImage2D( GLenum target , GLint level , GLint xoffset , GLint yoffset , GLsizei width , GLsizei height , GLenum format , GLsizei imageSize , const GLvoid *data );
 DYNAMIC_GL_APIENTRY void glCopyTexImage2D( GLenum target , GLint level , GLenum internalformat , GLint x , GLint y , GLsizei width , GLsizei height , GLint border );
 DYNAMIC_GL_APIENTRY void glCopyTexSubImage2D( GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint x , GLint y , GLsizei width , GLsizei height );
 DYNAMIC_GL_APIENTRY void glCullFace( GLenum mode );
 DYNAMIC_GL_APIENTRY void glDeleteBuffers( GLsizei n , const GLuint *buffers );
 DYNAMIC_GL_APIENTRY void glDeleteTextures( GLsizei n , const GLuint *textures );
 DYNAMIC_GL_APIENTRY void glDepthFunc( GLenum func );
 DYNAMIC_GL_APIENTRY void glDepthMask( GLboolean flag );
 DYNAMIC_GL_APIENTRY void glDepthRangex( GLclampx zNear , GLclampx zFar );
 DYNAMIC_GL_APIENTRY void glDisable( GLenum cap );
 DYNAMIC_GL_APIENTRY void glDisableClientState( GLenum array );
 DYNAMIC_GL_APIENTRY void glDrawArrays( GLenum mode , GLint first , GLsizei count );
 DYNAMIC_GL_APIENTRY void glDrawElements( GLenum mode , GLsizei count , GLenum type , const GLvoid *indices );
 DYNAMIC_GL_APIENTRY void glEnable( GLenum cap );
 DYNAMIC_GL_APIENTRY void glEnableClientState( GLenum array );
 DYNAMIC_GL_APIENTRY void glFinish(  );
 DYNAMIC_GL_APIENTRY void glFlush(  );
 DYNAMIC_GL_APIENTRY void glFogx( GLenum pname , GLfixed param );
 DYNAMIC_GL_APIENTRY void glFogxv( GLenum pname , const GLfixed *params );
 DYNAMIC_GL_APIENTRY void glFrontFace( GLenum mode );
 DYNAMIC_GL_APIENTRY void glFrustumx( GLfixed left , GLfixed right , GLfixed bottom , GLfixed top , GLfixed zNear , GLfixed zFar );
 DYNAMIC_GL_APIENTRY void glGetBooleanv( GLenum pname , GLboolean *params );
 DYNAMIC_GL_APIENTRY void glGetBufferParameteriv( GLenum target , GLenum pname , GLint *params );
 DYNAMIC_GL_APIENTRY void glGenBuffers( GLsizei n , GLuint *buffers );
 DYNAMIC_GL_APIENTRY void glGenTextures( GLsizei n , GLuint *textures );
 DYNAMIC_GL_APIENTRY GLenum glGetError(  );
 DYNAMIC_GL_APIENTRY void glGetFixedv( GLenum pname , GLfixed *params );
 DYNAMIC_GL_APIENTRY void glGetIntegerv( GLenum pname , GLint *params );
 DYNAMIC_GL_APIENTRY void glGetLightxv( GLenum light , GLenum pname , GLfixed *params );
 DYNAMIC_GL_APIENTRY void glGetMaterialxv( GLenum face , GLenum pname , GLfixed *params );
 DYNAMIC_GL_APIENTRY void glGetPointerv( GLenum pname , GLvoid *p1 );
 DYNAMIC_GL_APIENTRY GLubyte* glGetString( GLenum name );
 DYNAMIC_GL_APIENTRY void glGetTexEnviv( GLenum env , GLenum pname , GLint *params );
 DYNAMIC_GL_APIENTRY void glGetTexEnvxv( GLenum env , GLenum pname , GLfixed *params );
 DYNAMIC_GL_APIENTRY void glGetTexParameteriv( GLenum target , GLenum pname , GLint *params );
 DYNAMIC_GL_APIENTRY void glGetTexParameterxv( GLenum target , GLenum pname , GLfixed *params );
 DYNAMIC_GL_APIENTRY void glHint( GLenum target , GLenum mode );
 DYNAMIC_GL_APIENTRY GLboolean glIsBuffer( GLuint buffer );
 DYNAMIC_GL_APIENTRY GLboolean glIsEnabled( GLenum cap );
 DYNAMIC_GL_APIENTRY GLboolean glIsTexture( GLuint texture );
 DYNAMIC_GL_APIENTRY void glLightModelx( GLenum pname , GLfixed param );
 DYNAMIC_GL_APIENTRY void glLightModelxv( GLenum pname , const GLfixed *params );
 DYNAMIC_GL_APIENTRY void glLightx( GLenum light , GLenum pname , GLfixed param );
 DYNAMIC_GL_APIENTRY void glLightxv( GLenum light , GLenum pname , const GLfixed *params );
 DYNAMIC_GL_APIENTRY void glLineWidthx( GLfixed width );
 DYNAMIC_GL_APIENTRY void glLoadIdentity(  );
 DYNAMIC_GL_APIENTRY void glLoadMatrixx( const GLfixed *m );
 DYNAMIC_GL_APIENTRY void glLogicOp( GLenum opcode );
 DYNAMIC_GL_APIENTRY void glMaterialx( GLenum face , GLenum pname , GLfixed param );
 DYNAMIC_GL_APIENTRY void glMaterialxv( GLenum face , GLenum pname , const GLfixed *params );
 DYNAMIC_GL_APIENTRY void glMatrixMode( GLenum mode );
 DYNAMIC_GL_APIENTRY void glMultMatrixx( const GLfixed *m );
 DYNAMIC_GL_APIENTRY void glMultiTexCoord4x( GLenum target , GLfixed s , GLfixed t , GLfixed r , GLfixed q );
 DYNAMIC_GL_APIENTRY void glNormal3x( GLfixed nx , GLfixed ny , GLfixed nz );
 DYNAMIC_GL_APIENTRY void glNormalPointer( GLenum type , GLsizei stride , const GLvoid *pointer );
 DYNAMIC_GL_APIENTRY void glOrthox( GLfixed left , GLfixed right , GLfixed bottom , GLfixed top , GLfixed zNear , GLfixed zFar );
 DYNAMIC_GL_APIENTRY void glPixelStorei( GLenum pname , GLint param );
 DYNAMIC_GL_APIENTRY void glPointParameterx( GLenum pname , GLfixed param );
 DYNAMIC_GL_APIENTRY void glPointParameterxv( GLenum pname , const GLfixed *params );
 DYNAMIC_GL_APIENTRY void glPointSizex( GLfixed size );
 DYNAMIC_GL_APIENTRY void glPolygonOffsetx( GLfixed factor , GLfixed units );
 DYNAMIC_GL_APIENTRY void glPopMatrix(  );
 DYNAMIC_GL_APIENTRY void glPushMatrix(  );
 DYNAMIC_GL_APIENTRY void glReadPixels( GLint x , GLint y , GLsizei width , GLsizei height , GLenum format , GLenum type , GLvoid *pixels );
 DYNAMIC_GL_APIENTRY void glRotatex( GLfixed angle , GLfixed x , GLfixed y , GLfixed z );
 DYNAMIC_GL_APIENTRY void glSampleCoverage( GLclampf value , GLboolean invert );
 DYNAMIC_GL_APIENTRY void glSampleCoveragex( GLclampx value , GLboolean invert );
 DYNAMIC_GL_APIENTRY void glScalex( GLfixed x , GLfixed y , GLfixed z );
 DYNAMIC_GL_APIENTRY void glScissor( GLint x , GLint y , GLsizei width , GLsizei height );
 DYNAMIC_GL_APIENTRY void glShadeModel( GLenum mode );
 DYNAMIC_GL_APIENTRY void glStencilFunc( GLenum func , GLint ref , GLuint mask );
 DYNAMIC_GL_APIENTRY void glStencilMask( GLuint mask );
 DYNAMIC_GL_APIENTRY void glStencilOp( GLenum fail , GLenum zfail , GLenum zpass );
 DYNAMIC_GL_APIENTRY void glTexCoordPointer( GLint size , GLenum type , GLsizei stride , const GLvoid *pointer );
 DYNAMIC_GL_APIENTRY void glTexEnvi( GLenum target , GLenum pname , GLint param );
 DYNAMIC_GL_APIENTRY void glTexEnvx( GLenum target , GLenum pname , GLfixed param );
 DYNAMIC_GL_APIENTRY void glTexEnviv( GLenum target , GLenum pname , const GLint *params );
 DYNAMIC_GL_APIENTRY void glTexEnvxv( GLenum target , GLenum pname , const GLfixed *params );
 DYNAMIC_GL_APIENTRY void glTexImage2D( GLenum target , GLint level , GLint internalformat , GLsizei width , GLsizei height , GLint border , GLenum format , GLenum type , const GLvoid *pixels );
 DYNAMIC_GL_APIENTRY void glTexParameteri( GLenum target , GLenum pname , GLint param );
 DYNAMIC_GL_APIENTRY void glTexParameterx( GLenum target , GLenum pname , GLfixed param );
 DYNAMIC_GL_APIENTRY void glTexParameteriv( GLenum target , GLenum pname , const GLint *params );
 DYNAMIC_GL_APIENTRY void glTexParameterxv( GLenum target , GLenum pname , const GLfixed *params );
 DYNAMIC_GL_APIENTRY void glTexSubImage2D( GLenum target , GLint level , GLint xoffset , GLint yoffset , GLsizei width , GLsizei height , GLenum format , GLenum type , const GLvoid *pixels );
 DYNAMIC_GL_APIENTRY void glTranslatex( GLfixed x , GLfixed y , GLfixed z );
 DYNAMIC_GL_APIENTRY void glVertexPointer( GLint size , GLenum type , GLsizei stride , const GLvoid *pointer );
 DYNAMIC_GL_APIENTRY void glViewport( GLint x , GLint y , GLsizei width , GLsizei height );
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
extern bool DinamicGLFeature_VERSION_1_1_Supported();
#endif /*USE_DYNAMIC_GL_VERSION_1_1*/

/*OES_blend_func_separate*/
#ifdef USE_DYNAMIC_GL_OES_blend_func_separate
#define GL_BLEND_DST_RGB_OES 0x80C8
#define GL_BLEND_SRC_RGB_OES 0x80C9
#define GL_BLEND_DST_ALPHA_OES 0x80CA
#define GL_BLEND_SRC_ALPHA_OES 0x80CB
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendFuncSeparateOES)(GLenum srcRGB , GLenum dstRGB , GLenum srcAlpha , GLenum dstAlpha);
#define glBlendFuncSeparateOES DynamicGL_BlendFuncSeparateOES
#else
extern "C" {
 DYNAMIC_GL_APIENTRY void glBlendFuncSeparateOES( GLenum srcRGB , GLenum dstRGB , GLenum srcAlpha , GLenum dstAlpha );
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
extern bool DinamicGLFeature_OES_blend_func_separate_Supported();
#endif /*USE_DYNAMIC_GL_OES_blend_func_separate*/

/*QCOM_driver_control*/
#ifdef USE_DYNAMIC_GL_QCOM_driver_control
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetDriverControlsQCOM)(GLint *num , GLsizei size , GLuint *driverControls);
#define glGetDriverControlsQCOM DynamicGL_GetDriverControlsQCOM
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetDriverControlStringQCOM)(GLuint driverControl , GLsizei bufSize , GLsizei *length , GLchar *driverControlString);
#define glGetDriverControlStringQCOM DynamicGL_GetDriverControlStringQCOM
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EnableDriverControlQCOM)(GLuint driverControl);
#define glEnableDriverControlQCOM DynamicGL_EnableDriverControlQCOM
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DisableDriverControlQCOM)(GLuint driverControl);
#define glDisableDriverControlQCOM DynamicGL_DisableDriverControlQCOM
#else
extern "C" {
 DYNAMIC_GL_APIENTRY void glGetDriverControlsQCOM( GLint *num , GLsizei size , GLuint *driverControls );
 DYNAMIC_GL_APIENTRY void glGetDriverControlStringQCOM( GLuint driverControl , GLsizei bufSize , GLsizei *length , GLchar *driverControlString );
 DYNAMIC_GL_APIENTRY void glEnableDriverControlQCOM( GLuint driverControl );
 DYNAMIC_GL_APIENTRY void glDisableDriverControlQCOM( GLuint driverControl );
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
extern bool DinamicGLFeature_QCOM_driver_control_Supported();
#endif /*USE_DYNAMIC_GL_QCOM_driver_control*/

/*EXT_multisampled_render_to_texture*/
#ifdef USE_DYNAMIC_GL_EXT_multisampled_render_to_texture
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_SAMPLES_EXT 0x8D6C
#define GL_RENDERBUFFER_SAMPLES_EXT 0x9133
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE_EXT 0x9134
#define GL_MAX_SAMPLES_EXT 0x9135
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RenderbufferStorageMultisampleEXT)(GLenum target , GLsizei samples , GLenum internalformat , GLsizei width , GLsizei height);
#define glRenderbufferStorageMultisampleEXT DynamicGL_RenderbufferStorageMultisampleEXT
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferTexture2DMultisampleEXT)(GLenum target , GLenum attachment , GLenum textarget , GLuint texture , GLint level , GLsizei samples);
#define glFramebufferTexture2DMultisampleEXT DynamicGL_FramebufferTexture2DMultisampleEXT
#else
extern "C" {
 DYNAMIC_GL_APIENTRY void glRenderbufferStorageMultisampleEXT( GLenum target , GLsizei samples , GLenum internalformat , GLsizei width , GLsizei height );
 DYNAMIC_GL_APIENTRY void glFramebufferTexture2DMultisampleEXT( GLenum target , GLenum attachment , GLenum textarget , GLuint texture , GLint level , GLsizei samples );
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
extern bool DinamicGLFeature_EXT_multisampled_render_to_texture_Supported();
#endif /*USE_DYNAMIC_GL_EXT_multisampled_render_to_texture*/

/*EXT_texture_storage*/
#ifdef USE_DYNAMIC_GL_EXT_texture_storage
#define GL_TEXTURE_IMMUTABLE_FORMAT_EXT 0x912F
#define GL_ALPHA8_EXT 0x803C
#define GL_LUMINANCE8_EXT 0x8040
#define GL_LUMINANCE8_ALPHA8_EXT 0x8045
#define GL_RGBA32F_EXT 0x8814
#define GL_RGB32F_EXT 0x8815
#define GL_ALPHA32F_EXT 0x8816
#define GL_LUMINANCE32F_EXT 0x8818
#define GL_LUMINANCE_ALPHA32F_EXT 0x8819
#define GL_RGB16F_EXT 0x881B
#define GL_ALPHA16F_EXT 0x881C
#define GL_LUMINANCE16F_EXT 0x881E
#define GL_LUMINANCE_ALPHA16F_EXT 0x881F
#define GL_RGB10_A2_EXT 0x8059
#define GL_RGB10_EXT 0x8052
#define GL_BGRA8_EXT 0x93A1
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexStorage1DEXT)(GLenum target , GLsizei levels , GLenum internalformat , GLsizei width);
#define glTexStorage1DEXT DynamicGL_TexStorage1DEXT
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexStorage2DEXT)(GLenum target , GLsizei levels , GLenum internalformat , GLsizei width , GLsizei height);
#define glTexStorage2DEXT DynamicGL_TexStorage2DEXT
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexStorage3DEXT)(GLenum target , GLsizei levels , GLenum internalformat , GLsizei width , GLsizei height , GLsizei depth);
#define glTexStorage3DEXT DynamicGL_TexStorage3DEXT
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureStorage1DEXT)(GLuint texture , GLenum target , GLsizei levels , GLenum internalformat , GLsizei width);
#define glTextureStorage1DEXT DynamicGL_TextureStorage1DEXT
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureStorage2DEXT)(GLuint texture , GLenum target , GLsizei levels , GLenum internalformat , GLsizei width , GLsizei height);
#define glTextureStorage2DEXT DynamicGL_TextureStorage2DEXT
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureStorage3DEXT)(GLuint texture , GLenum target , GLsizei levels , GLenum internalformat , GLsizei width , GLsizei height , GLsizei depth);
#define glTextureStorage3DEXT DynamicGL_TextureStorage3DEXT
#else
extern "C" {
 DYNAMIC_GL_APIENTRY void glTexStorage1DEXT( GLenum target , GLsizei levels , GLenum internalformat , GLsizei width );
 DYNAMIC_GL_APIENTRY void glTexStorage2DEXT( GLenum target , GLsizei levels , GLenum internalformat , GLsizei width , GLsizei height );
 DYNAMIC_GL_APIENTRY void glTexStorage3DEXT( GLenum target , GLsizei levels , GLenum internalformat , GLsizei width , GLsizei height , GLsizei depth );
 DYNAMIC_GL_APIENTRY void glTextureStorage1DEXT( GLuint texture , GLenum target , GLsizei levels , GLenum internalformat , GLsizei width );
 DYNAMIC_GL_APIENTRY void glTextureStorage2DEXT( GLuint texture , GLenum target , GLsizei levels , GLenum internalformat , GLsizei width , GLsizei height );
 DYNAMIC_GL_APIENTRY void glTextureStorage3DEXT( GLuint texture , GLenum target , GLsizei levels , GLenum internalformat , GLsizei width , GLsizei height , GLsizei depth );
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
extern bool DinamicGLFeature_EXT_texture_storage_Supported();
#endif /*USE_DYNAMIC_GL_EXT_texture_storage*/

/*OES_query_matrix*/
#ifdef USE_DYNAMIC_GL_OES_query_matrix
extern bool DinamicGLFeature_OES_query_matrix_Supported();
#endif /*USE_DYNAMIC_GL_OES_query_matrix*/

/*OES_stencil8*/
#ifdef USE_DYNAMIC_GL_OES_stencil8
#define GL_STENCIL_INDEX8_OES 0x8D48
extern bool DinamicGLFeature_OES_stencil8_Supported();
#endif /*USE_DYNAMIC_GL_OES_stencil8*/

/*APIENTRYP*/
#ifdef USE_DYNAMIC_GL_APIENTRYP
extern bool DinamicGLFeature_APIENTRYP_Supported();
#endif /*USE_DYNAMIC_GL_APIENTRYP*/

/*OES_stencil_wrap*/
#ifdef USE_DYNAMIC_GL_OES_stencil_wrap
#define GL_INCR_WRAP_OES 0x8507
#define GL_DECR_WRAP_OES 0x8508
extern bool DinamicGLFeature_OES_stencil_wrap_Supported();
#endif /*USE_DYNAMIC_GL_OES_stencil_wrap*/

/*APPLE_framebuffer_multisample*/
#ifdef USE_DYNAMIC_GL_APPLE_framebuffer_multisample
#define GL_RENDERBUFFER_SAMPLES_APPLE 0x8CAB
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE_APPLE 0x8D56
#define GL_MAX_SAMPLES_APPLE 0x8D57
#define GL_READ_FRAMEBUFFER_APPLE 0x8CA8
#define GL_DRAW_FRAMEBUFFER_APPLE 0x8CA9
#define GL_DRAW_FRAMEBUFFER_BINDING_APPLE 0x8CA6
#define GL_READ_FRAMEBUFFER_BINDING_APPLE 0x8CAA
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RenderbufferStorageMultisampleAPPLE)(GLenum target , GLsizei samples , GLenum internalformat , GLsizei width , GLsizei height);
#define glRenderbufferStorageMultisampleAPPLE DynamicGL_RenderbufferStorageMultisampleAPPLE
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ResolveMultisampleFramebufferAPPLE)();
#define glResolveMultisampleFramebufferAPPLE DynamicGL_ResolveMultisampleFramebufferAPPLE
#else
extern "C" {
 DYNAMIC_GL_APIENTRY void glRenderbufferStorageMultisampleAPPLE( GLenum target , GLsizei samples , GLenum internalformat , GLsizei width , GLsizei height );
 DYNAMIC_GL_APIENTRY void glResolveMultisampleFramebufferAPPLE(  );
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
extern bool DinamicGLFeature_APPLE_framebuffer_multisample_Supported();
#endif /*USE_DYNAMIC_GL_APPLE_framebuffer_multisample*/

/*OES_extended_matrix_palette*/
#ifdef USE_DYNAMIC_GL_OES_extended_matrix_palette
extern bool DinamicGLFeature_OES_extended_matrix_palette_Supported();
#endif /*USE_DYNAMIC_GL_OES_extended_matrix_palette*/

/*APPLE_texture_format_BGRA8888*/
#ifdef USE_DYNAMIC_GL_APPLE_texture_format_BGRA8888
#define GL_BGRA_EXT 0x80E1
extern bool DinamicGLFeature_APPLE_texture_format_BGRA8888_Supported();
#endif /*USE_DYNAMIC_GL_APPLE_texture_format_BGRA8888*/

/*APPLE_texture_2D_limited_npot*/
#ifdef USE_DYNAMIC_GL_APPLE_texture_2D_limited_npot
extern bool DinamicGLFeature_APPLE_texture_2D_limited_npot_Supported();
#endif /*USE_DYNAMIC_GL_APPLE_texture_2D_limited_npot*/

/*QCOM_perfmon_global_mode*/
#ifdef USE_DYNAMIC_GL_QCOM_perfmon_global_mode
#define GL_PERFMON_GLOBAL_MODE_QCOM 0x8FA0
extern bool DinamicGLFeature_QCOM_perfmon_global_mode_Supported();
#endif /*USE_DYNAMIC_GL_QCOM_perfmon_global_mode*/

/*IMG_user_clip_plane*/
#ifdef USE_DYNAMIC_GL_IMG_user_clip_plane
#define GL_CLIP_PLANE0_IMG 0x3000
#define GL_CLIP_PLANE1_IMG 0x3001
#define GL_CLIP_PLANE2_IMG 0x3002
#define GL_CLIP_PLANE3_IMG 0x3003
#define GL_CLIP_PLANE4_IMG 0x3004
#define GL_CLIP_PLANE5_IMG 0x3005
#define GL_MAX_CLIP_PLANES_IMG 0x0D32
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClipPlanefIMG)(GLenum p , const GLfloat *eqn);
#define glClipPlanefIMG DynamicGL_ClipPlanefIMG
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClipPlanexIMG)(GLenum p , const GLfixed *eqn);
#define glClipPlanexIMG DynamicGL_ClipPlanexIMG
#else
extern "C" {
 DYNAMIC_GL_APIENTRY void glClipPlanefIMG( GLenum p , const GLfloat *eqn );
 DYNAMIC_GL_APIENTRY void glClipPlanexIMG( GLenum p , const GLfixed *eqn );
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
extern bool DinamicGLFeature_IMG_user_clip_plane_Supported();
#endif /*USE_DYNAMIC_GL_IMG_user_clip_plane*/

/*OES_single_precision*/
#ifdef USE_DYNAMIC_GL_OES_single_precision
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DepthRangefOES)(GLclampf zNear , GLclampf zFar);
#define glDepthRangefOES DynamicGL_DepthRangefOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FrustumfOES)(GLfloat left , GLfloat right , GLfloat bottom , GLfloat top , GLfloat zNear , GLfloat zFar);
#define glFrustumfOES DynamicGL_FrustumfOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_OrthofOES)(GLfloat left , GLfloat right , GLfloat bottom , GLfloat top , GLfloat zNear , GLfloat zFar);
#define glOrthofOES DynamicGL_OrthofOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClipPlanefOES)(GLenum plane , const GLfloat *equation);
#define glClipPlanefOES DynamicGL_ClipPlanefOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearDepthfOES)(GLclampf depth);
#define glClearDepthfOES DynamicGL_ClearDepthfOES
#else
extern "C" {
 DYNAMIC_GL_APIENTRY void glDepthRangefOES( GLclampf zNear , GLclampf zFar );
 DYNAMIC_GL_APIENTRY void glFrustumfOES( GLfloat left , GLfloat right , GLfloat bottom , GLfloat top , GLfloat zNear , GLfloat zFar );
 DYNAMIC_GL_APIENTRY void glOrthofOES( GLfloat left , GLfloat right , GLfloat bottom , GLfloat top , GLfloat zNear , GLfloat zFar );
 DYNAMIC_GL_APIENTRY void glClipPlanefOES( GLenum plane , const GLfloat *equation );
 DYNAMIC_GL_APIENTRY void glClearDepthfOES( GLclampf depth );
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
extern bool DinamicGLFeature_OES_single_precision_Supported();
#endif /*USE_DYNAMIC_GL_OES_single_precision*/

/*IMG_texture_compression_pvrtc*/
#ifdef USE_DYNAMIC_GL_IMG_texture_compression_pvrtc
#define GL_COMPRESSED_RGB_PVRTC_4BPPV1_IMG 0x8C00
#define GL_COMPRESSED_RGB_PVRTC_2BPPV1_IMG 0x8C01
#define GL_COMPRESSED_RGBA_PVRTC_4BPPV1_IMG 0x8C02
#define GL_COMPRESSED_RGBA_PVRTC_2BPPV1_IMG 0x8C03
extern bool DinamicGLFeature_IMG_texture_compression_pvrtc_Supported();
#endif /*USE_DYNAMIC_GL_IMG_texture_compression_pvrtc*/

/*EXT_texture_format_BGRA8888*/
#ifdef USE_DYNAMIC_GL_EXT_texture_format_BGRA8888
#define GL_BGRA_EXT 0x80E1
extern bool DinamicGLFeature_EXT_texture_format_BGRA8888_Supported();
#endif /*USE_DYNAMIC_GL_EXT_texture_format_BGRA8888*/

/*OES_depth32*/
#ifdef USE_DYNAMIC_GL_OES_depth32
#define GL_DEPTH_COMPONENT32_OES 0x81A7
extern bool DinamicGLFeature_OES_depth32_Supported();
#endif /*USE_DYNAMIC_GL_OES_depth32*/

/*OES_fbo_render_mipmap*/
#ifdef USE_DYNAMIC_GL_OES_fbo_render_mipmap
extern bool DinamicGLFeature_OES_fbo_render_mipmap_Supported();
#endif /*USE_DYNAMIC_GL_OES_fbo_render_mipmap*/

/*IMG_multisampled_render_to_texture*/
#ifdef USE_DYNAMIC_GL_IMG_multisampled_render_to_texture
#define GL_RENDERBUFFER_SAMPLES_IMG 0x9133
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE_IMG 0x9134
#define GL_MAX_SAMPLES_IMG 0x9135
#define GL_TEXTURE_SAMPLES_IMG 0x9136
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RenderbufferStorageMultisampleIMG)(GLenum p1 , GLsizei p2 , GLenum p3 , GLsizei p4 , GLsizei p5);
#define glRenderbufferStorageMultisampleIMG DynamicGL_RenderbufferStorageMultisampleIMG
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferTexture2DMultisampleIMG)(GLenum p1 , GLenum p2 , GLenum p3 , GLuint p4 , GLint p5 , GLsizei p6);
#define glFramebufferTexture2DMultisampleIMG DynamicGL_FramebufferTexture2DMultisampleIMG
#else
extern "C" {
 DYNAMIC_GL_APIENTRY void glRenderbufferStorageMultisampleIMG( GLenum p1 , GLsizei p2 , GLenum p3 , GLsizei p4 , GLsizei p5 );
 DYNAMIC_GL_APIENTRY void glFramebufferTexture2DMultisampleIMG( GLenum p1 , GLenum p2 , GLenum p3 , GLuint p4 , GLint p5 , GLsizei p6 );
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
extern bool DinamicGLFeature_IMG_multisampled_render_to_texture_Supported();
#endif /*USE_DYNAMIC_GL_IMG_multisampled_render_to_texture*/

/*OES_packed_depth_stencil*/
#ifdef USE_DYNAMIC_GL_OES_packed_depth_stencil
#define GL_DEPTH_STENCIL_OES 0x84F9
#define GL_UNSIGNED_INT_24_8_OES 0x84FA
#define GL_DEPTH24_STENCIL8_OES 0x88F0
extern bool DinamicGLFeature_OES_packed_depth_stencil_Supported();
#endif /*USE_DYNAMIC_GL_OES_packed_depth_stencil*/

/*EXT_discard_framebuffer*/
#ifdef USE_DYNAMIC_GL_EXT_discard_framebuffer
#define GL_COLOR_EXT 0x1800
#define GL_DEPTH_EXT 0x1801
#define GL_STENCIL_EXT 0x1802
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DiscardFramebufferEXT)(GLenum target , GLsizei numAttachments , const GLenum *attachments);
#define glDiscardFramebufferEXT DynamicGL_DiscardFramebufferEXT
#else
extern "C" {
 DYNAMIC_GL_APIENTRY void glDiscardFramebufferEXT( GLenum target , GLsizei numAttachments , const GLenum *attachments );
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
extern bool DinamicGLFeature_EXT_discard_framebuffer_Supported();
#endif /*USE_DYNAMIC_GL_EXT_discard_framebuffer*/

/*OES_EGL_image*/
#ifdef USE_DYNAMIC_GL_OES_EGL_image
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EGLImageTargetTexture2DOES)(GLenum target , GLeglImageOES image);
#define glEGLImageTargetTexture2DOES DynamicGL_EGLImageTargetTexture2DOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EGLImageTargetRenderbufferStorageOES)(GLenum target , GLeglImageOES image);
#define glEGLImageTargetRenderbufferStorageOES DynamicGL_EGLImageTargetRenderbufferStorageOES
#else
extern "C" {
 DYNAMIC_GL_APIENTRY void glEGLImageTargetTexture2DOES( GLenum target , GLeglImageOES image );
 DYNAMIC_GL_APIENTRY void glEGLImageTargetRenderbufferStorageOES( GLenum target , GLeglImageOES image );
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
extern bool DinamicGLFeature_OES_EGL_image_Supported();
#endif /*USE_DYNAMIC_GL_OES_EGL_image*/

/*NV_fence*/
#ifdef USE_DYNAMIC_GL_NV_fence
#define GL_ALL_COMPLETED_NV 0x84F2
#define GL_FENCE_STATUS_NV 0x84F3
#define GL_FENCE_CONDITION_NV 0x84F4
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteFencesNV)(GLsizei n , const GLuint *fences);
#define glDeleteFencesNV DynamicGL_DeleteFencesNV
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GenFencesNV)(GLsizei n , GLuint *fences);
#define glGenFencesNV DynamicGL_GenFencesNV
extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsFenceNV)(GLuint fence);
#define glIsFenceNV DynamicGL_IsFenceNV
extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_TestFenceNV)(GLuint fence);
#define glTestFenceNV DynamicGL_TestFenceNV
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFenceivNV)(GLuint fence , GLenum pname , GLint *params);
#define glGetFenceivNV DynamicGL_GetFenceivNV
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FinishFenceNV)(GLuint fence);
#define glFinishFenceNV DynamicGL_FinishFenceNV
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SetFenceNV)(GLuint fence , GLenum condition);
#define glSetFenceNV DynamicGL_SetFenceNV
#else
extern "C" {
 DYNAMIC_GL_APIENTRY void glDeleteFencesNV( GLsizei n , const GLuint *fences );
 DYNAMIC_GL_APIENTRY void glGenFencesNV( GLsizei n , GLuint *fences );
 DYNAMIC_GL_APIENTRY GLboolean glIsFenceNV( GLuint fence );
 DYNAMIC_GL_APIENTRY GLboolean glTestFenceNV( GLuint fence );
 DYNAMIC_GL_APIENTRY void glGetFenceivNV( GLuint fence , GLenum pname , GLint *params );
 DYNAMIC_GL_APIENTRY void glFinishFenceNV( GLuint fence );
 DYNAMIC_GL_APIENTRY void glSetFenceNV( GLuint fence , GLenum condition );
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
extern bool DinamicGLFeature_NV_fence_Supported();
#endif /*USE_DYNAMIC_GL_NV_fence*/

/*EXT_texture_lod_bias*/
#ifdef USE_DYNAMIC_GL_EXT_texture_lod_bias
#define GL_MAX_TEXTURE_LOD_BIAS_EXT 0x84FD
#define GL_TEXTURE_FILTER_CONTROL_EXT 0x8500
#define GL_TEXTURE_LOD_BIAS_EXT 0x8501
extern bool DinamicGLFeature_EXT_texture_lod_bias_Supported();
#endif /*USE_DYNAMIC_GL_EXT_texture_lod_bias*/

/*EXT_texture_filter_anisotropic*/
#ifdef USE_DYNAMIC_GL_EXT_texture_filter_anisotropic
#define GL_TEXTURE_MAX_ANISOTROPY_EXT 0x84FE
#define GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT 0x84FF
extern bool DinamicGLFeature_EXT_texture_filter_anisotropic_Supported();
#endif /*USE_DYNAMIC_GL_EXT_texture_filter_anisotropic*/

/*EXT_texture_compression_dxt1*/
#ifdef USE_DYNAMIC_GL_EXT_texture_compression_dxt1
#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT 0x83F0
#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT 0x83F1
extern bool DinamicGLFeature_EXT_texture_compression_dxt1_Supported();
#endif /*USE_DYNAMIC_GL_EXT_texture_compression_dxt1*/

/*EXT_sRGB*/
#ifdef USE_DYNAMIC_GL_EXT_sRGB
#define GL_SRGB_EXT 0x8C40
#define GL_SRGB_ALPHA_EXT 0x8C42
#define GL_SRGB8_ALPHA8_EXT 0x8C43
#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING_EXT 0x8210
extern bool DinamicGLFeature_EXT_sRGB_Supported();
#endif /*USE_DYNAMIC_GL_EXT_sRGB*/

/*OES_blend_equation_separate*/
#ifdef USE_DYNAMIC_GL_OES_blend_equation_separate
#define GL_BLEND_EQUATION_RGB_OES 0x8009
#define GL_BLEND_EQUATION_ALPHA_OES 0x883D
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendEquationSeparateOES)(GLenum modeRGB , GLenum modeAlpha);
#define glBlendEquationSeparateOES DynamicGL_BlendEquationSeparateOES
#else
extern "C" {
 DYNAMIC_GL_APIENTRY void glBlendEquationSeparateOES( GLenum modeRGB , GLenum modeAlpha );
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
extern bool DinamicGLFeature_OES_blend_equation_separate_Supported();
#endif /*USE_DYNAMIC_GL_OES_blend_equation_separate*/

/*OES_texture_mirrored_repeat*/
#ifdef USE_DYNAMIC_GL_OES_texture_mirrored_repeat
#define GL_MIRRORED_REPEAT_OES 0x8370
extern bool DinamicGLFeature_OES_texture_mirrored_repeat_Supported();
#endif /*USE_DYNAMIC_GL_OES_texture_mirrored_repeat*/

/*EXT_robustness*/
#ifdef USE_DYNAMIC_GL_EXT_robustness
#define GL_GUILTY_CONTEXT_RESET_EXT 0x8253
#define GL_INNOCENT_CONTEXT_RESET_EXT 0x8254
#define GL_UNKNOWN_CONTEXT_RESET_EXT 0x8255
#define GL_CONTEXT_ROBUST_ACCESS_EXT 0x90F3
#define GL_RESET_NOTIFICATION_STRATEGY_EXT 0x8256
#define GL_LOSE_CONTEXT_ON_RESET_EXT 0x8252
#define GL_NO_RESET_NOTIFICATION_EXT 0x8261
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
extern GLenum (DYNAMIC_GL_APIENTRYP DynamicGL_GetGraphicsResetStatusEXT)();
#define glGetGraphicsResetStatusEXT DynamicGL_GetGraphicsResetStatusEXT
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ReadnPixelsEXT)(GLint x , GLint y , GLsizei width , GLsizei height , GLenum format , GLenum type , GLsizei bufSize , GLvoid *data);
#define glReadnPixelsEXT DynamicGL_ReadnPixelsEXT
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetnUniformfvEXT)(GLuint program , GLint location , GLsizei bufSize , GLfloat *params);
#define glGetnUniformfvEXT DynamicGL_GetnUniformfvEXT
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetnUniformivEXT)(GLuint program , GLint location , GLsizei bufSize , GLint *params);
#define glGetnUniformivEXT DynamicGL_GetnUniformivEXT
#else
extern "C" {
 DYNAMIC_GL_APIENTRY GLenum glGetGraphicsResetStatusEXT(  );
 DYNAMIC_GL_APIENTRY void glReadnPixelsEXT( GLint x , GLint y , GLsizei width , GLsizei height , GLenum format , GLenum type , GLsizei bufSize , GLvoid *data );
 DYNAMIC_GL_APIENTRY void glGetnUniformfvEXT( GLuint program , GLint location , GLsizei bufSize , GLfloat *params );
 DYNAMIC_GL_APIENTRY void glGetnUniformivEXT( GLuint program , GLint location , GLsizei bufSize , GLint *params );
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
extern bool DinamicGLFeature_EXT_robustness_Supported();
#endif /*USE_DYNAMIC_GL_EXT_robustness*/

/*OES_draw_texture*/
#ifdef USE_DYNAMIC_GL_OES_draw_texture
#define GL_TEXTURE_CROP_RECT_OES 0x8B9D
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawTexsOES)(GLshort x , GLshort y , GLshort z , GLshort width , GLshort height);
#define glDrawTexsOES DynamicGL_DrawTexsOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawTexiOES)(GLint x , GLint y , GLint z , GLint width , GLint height);
#define glDrawTexiOES DynamicGL_DrawTexiOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawTexxOES)(GLfixed x , GLfixed y , GLfixed z , GLfixed width , GLfixed height);
#define glDrawTexxOES DynamicGL_DrawTexxOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawTexsvOES)(const GLshort *coords);
#define glDrawTexsvOES DynamicGL_DrawTexsvOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawTexivOES)(const GLint *coords);
#define glDrawTexivOES DynamicGL_DrawTexivOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawTexxvOES)(const GLfixed *coords);
#define glDrawTexxvOES DynamicGL_DrawTexxvOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawTexfOES)(GLfloat x , GLfloat y , GLfloat z , GLfloat width , GLfloat height);
#define glDrawTexfOES DynamicGL_DrawTexfOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawTexfvOES)(const GLfloat *coords);
#define glDrawTexfvOES DynamicGL_DrawTexfvOES
#else
extern "C" {
 DYNAMIC_GL_APIENTRY void glDrawTexsOES( GLshort x , GLshort y , GLshort z , GLshort width , GLshort height );
 DYNAMIC_GL_APIENTRY void glDrawTexiOES( GLint x , GLint y , GLint z , GLint width , GLint height );
 DYNAMIC_GL_APIENTRY void glDrawTexxOES( GLfixed x , GLfixed y , GLfixed z , GLfixed width , GLfixed height );
 DYNAMIC_GL_APIENTRY void glDrawTexsvOES( const GLshort *coords );
 DYNAMIC_GL_APIENTRY void glDrawTexivOES( const GLint *coords );
 DYNAMIC_GL_APIENTRY void glDrawTexxvOES( const GLfixed *coords );
 DYNAMIC_GL_APIENTRY void glDrawTexfOES( GLfloat x , GLfloat y , GLfloat z , GLfloat width , GLfloat height );
 DYNAMIC_GL_APIENTRY void glDrawTexfvOES( const GLfloat *coords );
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
extern bool DinamicGLFeature_OES_draw_texture_Supported();
#endif /*USE_DYNAMIC_GL_OES_draw_texture*/

/*OES_framebuffer_object*/
#ifdef USE_DYNAMIC_GL_OES_framebuffer_object
#define GL_FRAMEBUFFER_OES 0x8D40
#define GL_RENDERBUFFER_OES 0x8D41
#define GL_RGBA4_OES 0x8056
#define GL_RGB5_A1_OES 0x8057
#define GL_RGB565_OES 0x8D62
#define GL_DEPTH_COMPONENT16_OES 0x81A5
#define GL_RENDERBUFFER_WIDTH_OES 0x8D42
#define GL_RENDERBUFFER_HEIGHT_OES 0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT_OES 0x8D44
#define GL_RENDERBUFFER_RED_SIZE_OES 0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE_OES 0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE_OES 0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE_OES 0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE_OES 0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE_OES 0x8D55
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE_OES 0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME_OES 0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL_OES 0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE_OES 0x8CD3
#define GL_COLOR_ATTACHMENT0_OES 0x8CE0
#define GL_DEPTH_ATTACHMENT_OES 0x8D00
#define GL_STENCIL_ATTACHMENT_OES 0x8D20
#define GL_FRAMEBUFFER_COMPLETE_OES 0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT_OES 0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_OES 0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_OES 0x8CD9
#define GL_FRAMEBUFFER_INCOMPLETE_FORMATS_OES 0x8CDA
#define GL_FRAMEBUFFER_UNSUPPORTED_OES 0x8CDD
#define GL_FRAMEBUFFER_BINDING_OES 0x8CA6
#define GL_RENDERBUFFER_BINDING_OES 0x8CA7
#define GL_MAX_RENDERBUFFER_SIZE_OES 0x84E8
#define GL_INVALID_FRAMEBUFFER_OPERATION_OES 0x0506
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsRenderbufferOES)(GLuint renderbuffer);
#define glIsRenderbufferOES DynamicGL_IsRenderbufferOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindRenderbufferOES)(GLenum target , GLuint renderbuffer);
#define glBindRenderbufferOES DynamicGL_BindRenderbufferOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteRenderbuffersOES)(GLsizei n , const GLuint* renderbuffers);
#define glDeleteRenderbuffersOES DynamicGL_DeleteRenderbuffersOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GenRenderbuffersOES)(GLsizei n , GLuint* renderbuffers);
#define glGenRenderbuffersOES DynamicGL_GenRenderbuffersOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RenderbufferStorageOES)(GLenum target , GLenum internalformat , GLsizei width , GLsizei height);
#define glRenderbufferStorageOES DynamicGL_RenderbufferStorageOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetRenderbufferParameterivOES)(GLenum target , GLenum pname , GLint* params);
#define glGetRenderbufferParameterivOES DynamicGL_GetRenderbufferParameterivOES
extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsFramebufferOES)(GLuint framebuffer);
#define glIsFramebufferOES DynamicGL_IsFramebufferOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindFramebufferOES)(GLenum target , GLuint framebuffer);
#define glBindFramebufferOES DynamicGL_BindFramebufferOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteFramebuffersOES)(GLsizei n , const GLuint* framebuffers);
#define glDeleteFramebuffersOES DynamicGL_DeleteFramebuffersOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GenFramebuffersOES)(GLsizei n , GLuint* framebuffers);
#define glGenFramebuffersOES DynamicGL_GenFramebuffersOES
extern GLenum (DYNAMIC_GL_APIENTRYP DynamicGL_CheckFramebufferStatusOES)(GLenum target);
#define glCheckFramebufferStatusOES DynamicGL_CheckFramebufferStatusOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferRenderbufferOES)(GLenum target , GLenum attachment , GLenum renderbuffertarget , GLuint renderbuffer);
#define glFramebufferRenderbufferOES DynamicGL_FramebufferRenderbufferOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferTexture2DOES)(GLenum target , GLenum attachment , GLenum textarget , GLuint texture , GLint level);
#define glFramebufferTexture2DOES DynamicGL_FramebufferTexture2DOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFramebufferAttachmentParameterivOES)(GLenum target , GLenum attachment , GLenum pname , GLint* params);
#define glGetFramebufferAttachmentParameterivOES DynamicGL_GetFramebufferAttachmentParameterivOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GenerateMipmapOES)(GLenum target);
#define glGenerateMipmapOES DynamicGL_GenerateMipmapOES
#else
extern "C" {
 DYNAMIC_GL_APIENTRY GLboolean glIsRenderbufferOES( GLuint renderbuffer );
 DYNAMIC_GL_APIENTRY void glBindRenderbufferOES( GLenum target , GLuint renderbuffer );
 DYNAMIC_GL_APIENTRY void glDeleteRenderbuffersOES( GLsizei n , const GLuint* renderbuffers );
 DYNAMIC_GL_APIENTRY void glGenRenderbuffersOES( GLsizei n , GLuint* renderbuffers );
 DYNAMIC_GL_APIENTRY void glRenderbufferStorageOES( GLenum target , GLenum internalformat , GLsizei width , GLsizei height );
 DYNAMIC_GL_APIENTRY void glGetRenderbufferParameterivOES( GLenum target , GLenum pname , GLint* params );
 DYNAMIC_GL_APIENTRY GLboolean glIsFramebufferOES( GLuint framebuffer );
 DYNAMIC_GL_APIENTRY void glBindFramebufferOES( GLenum target , GLuint framebuffer );
 DYNAMIC_GL_APIENTRY void glDeleteFramebuffersOES( GLsizei n , const GLuint* framebuffers );
 DYNAMIC_GL_APIENTRY void glGenFramebuffersOES( GLsizei n , GLuint* framebuffers );
 DYNAMIC_GL_APIENTRY GLenum glCheckFramebufferStatusOES( GLenum target );
 DYNAMIC_GL_APIENTRY void glFramebufferRenderbufferOES( GLenum target , GLenum attachment , GLenum renderbuffertarget , GLuint renderbuffer );
 DYNAMIC_GL_APIENTRY void glFramebufferTexture2DOES( GLenum target , GLenum attachment , GLenum textarget , GLuint texture , GLint level );
 DYNAMIC_GL_APIENTRY void glGetFramebufferAttachmentParameterivOES( GLenum target , GLenum attachment , GLenum pname , GLint* params );
 DYNAMIC_GL_APIENTRY void glGenerateMipmapOES( GLenum target );
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
extern bool DinamicGLFeature_OES_framebuffer_object_Supported();
#endif /*USE_DYNAMIC_GL_OES_framebuffer_object*/

/*OES_matrix_get*/
#ifdef USE_DYNAMIC_GL_OES_matrix_get
#define GL_MODELVIEW_MATRIX_FLOAT_AS_INT_BITS_OES 0x898D
#define GL_PROJECTION_MATRIX_FLOAT_AS_INT_BITS_OES 0x898E
#define GL_TEXTURE_MATRIX_FLOAT_AS_INT_BITS_OES 0x898F
extern bool DinamicGLFeature_OES_matrix_get_Supported();
#endif /*USE_DYNAMIC_GL_OES_matrix_get*/

/*OES_byte_coordinates*/
#ifdef USE_DYNAMIC_GL_OES_byte_coordinates
extern bool DinamicGLFeature_OES_byte_coordinates_Supported();
#endif /*USE_DYNAMIC_GL_OES_byte_coordinates*/

/*AMD_compressed_3DC_texture*/
#ifdef USE_DYNAMIC_GL_AMD_compressed_3DC_texture
#define GL_3DC_X_AMD 0x87F9
#define GL_3DC_XY_AMD 0x87FA
extern bool DinamicGLFeature_AMD_compressed_3DC_texture_Supported();
#endif /*USE_DYNAMIC_GL_AMD_compressed_3DC_texture*/

/*QCOM_extended_get2*/
#ifdef USE_DYNAMIC_GL_QCOM_extended_get2
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ExtGetShadersQCOM)(GLuint *shaders , GLint maxShaders , GLint *numShaders);
#define glExtGetShadersQCOM DynamicGL_ExtGetShadersQCOM
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ExtGetProgramsQCOM)(GLuint *programs , GLint maxPrograms , GLint *numPrograms);
#define glExtGetProgramsQCOM DynamicGL_ExtGetProgramsQCOM
extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_ExtIsProgramBinaryQCOM)(GLuint program);
#define glExtIsProgramBinaryQCOM DynamicGL_ExtIsProgramBinaryQCOM
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ExtGetProgramBinarySourceQCOM)(GLuint program , GLenum shadertype , GLchar *source , GLint *length);
#define glExtGetProgramBinarySourceQCOM DynamicGL_ExtGetProgramBinarySourceQCOM
#else
extern "C" {
 DYNAMIC_GL_APIENTRY void glExtGetShadersQCOM( GLuint *shaders , GLint maxShaders , GLint *numShaders );
 DYNAMIC_GL_APIENTRY void glExtGetProgramsQCOM( GLuint *programs , GLint maxPrograms , GLint *numPrograms );
 DYNAMIC_GL_APIENTRY GLboolean glExtIsProgramBinaryQCOM( GLuint program );
 DYNAMIC_GL_APIENTRY void glExtGetProgramBinarySourceQCOM( GLuint program , GLenum shadertype , GLchar *source , GLint *length );
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
extern bool DinamicGLFeature_QCOM_extended_get2_Supported();
#endif /*USE_DYNAMIC_GL_QCOM_extended_get2*/

/*IMG_read_format*/
#ifdef USE_DYNAMIC_GL_IMG_read_format
#define GL_BGRA_IMG 0x80E1
#define GL_UNSIGNED_SHORT_4_4_4_4_REV_IMG 0x8365
extern bool DinamicGLFeature_IMG_read_format_Supported();
#endif /*USE_DYNAMIC_GL_IMG_read_format*/

/*OES_matrix_palette*/
#ifdef USE_DYNAMIC_GL_OES_matrix_palette
#define GL_MAX_VERTEX_UNITS_OES 0x86A4
#define GL_MAX_PALETTE_MATRICES_OES 0x8842
#define GL_MATRIX_PALETTE_OES 0x8840
#define GL_MATRIX_INDEX_ARRAY_OES 0x8844
#define GL_WEIGHT_ARRAY_OES 0x86AD
#define GL_CURRENT_PALETTE_MATRIX_OES 0x8843
#define GL_MATRIX_INDEX_ARRAY_SIZE_OES 0x8846
#define GL_MATRIX_INDEX_ARRAY_TYPE_OES 0x8847
#define GL_MATRIX_INDEX_ARRAY_STRIDE_OES 0x8848
#define GL_MATRIX_INDEX_ARRAY_POINTER_OES 0x8849
#define GL_MATRIX_INDEX_ARRAY_BUFFER_BINDING_OES 0x8B9E
#define GL_WEIGHT_ARRAY_SIZE_OES 0x86AB
#define GL_WEIGHT_ARRAY_TYPE_OES 0x86A9
#define GL_WEIGHT_ARRAY_STRIDE_OES 0x86AA
#define GL_WEIGHT_ARRAY_POINTER_OES 0x86AC
#define GL_WEIGHT_ARRAY_BUFFER_BINDING_OES 0x889E
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CurrentPaletteMatrixOES)(GLuint matrixpaletteindex);
#define glCurrentPaletteMatrixOES DynamicGL_CurrentPaletteMatrixOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LoadPaletteFromModelViewMatrixOES)();
#define glLoadPaletteFromModelViewMatrixOES DynamicGL_LoadPaletteFromModelViewMatrixOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixIndexPointerOES)(GLint size , GLenum type , GLsizei stride , const GLvoid *pointer);
#define glMatrixIndexPointerOES DynamicGL_MatrixIndexPointerOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WeightPointerOES)(GLint size , GLenum type , GLsizei stride , const GLvoid *pointer);
#define glWeightPointerOES DynamicGL_WeightPointerOES
#else
extern "C" {
 DYNAMIC_GL_APIENTRY void glCurrentPaletteMatrixOES( GLuint matrixpaletteindex );
 DYNAMIC_GL_APIENTRY void glLoadPaletteFromModelViewMatrixOES(  );
 DYNAMIC_GL_APIENTRY void glMatrixIndexPointerOES( GLint size , GLenum type , GLsizei stride , const GLvoid *pointer );
 DYNAMIC_GL_APIENTRY void glWeightPointerOES( GLint size , GLenum type , GLsizei stride , const GLvoid *pointer );
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
extern bool DinamicGLFeature_OES_matrix_palette_Supported();
#endif /*USE_DYNAMIC_GL_OES_matrix_palette*/

/*OES_stencil4*/
#ifdef USE_DYNAMIC_GL_OES_stencil4
#define GL_STENCIL_INDEX4_OES 0x8D47
extern bool DinamicGLFeature_OES_stencil4_Supported();
#endif /*USE_DYNAMIC_GL_OES_stencil4*/

/*QCOM_extended_get*/
#ifdef USE_DYNAMIC_GL_QCOM_extended_get
#define GL_TEXTURE_WIDTH_QCOM 0x8BD2
#define GL_TEXTURE_HEIGHT_QCOM 0x8BD3
#define GL_TEXTURE_DEPTH_QCOM 0x8BD4
#define GL_TEXTURE_INTERNAL_FORMAT_QCOM 0x8BD5
#define GL_TEXTURE_FORMAT_QCOM 0x8BD6
#define GL_TEXTURE_TYPE_QCOM 0x8BD7
#define GL_TEXTURE_IMAGE_VALID_QCOM 0x8BD8
#define GL_TEXTURE_NUM_LEVELS_QCOM 0x8BD9
#define GL_TEXTURE_TARGET_QCOM 0x8BDA
#define GL_TEXTURE_OBJECT_VALID_QCOM 0x8BDB
#define GL_STATE_RESTORE 0x8BDC
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ExtGetTexturesQCOM)(GLuint *textures , GLint maxTextures , GLint *numTextures);
#define glExtGetTexturesQCOM DynamicGL_ExtGetTexturesQCOM
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ExtGetBuffersQCOM)(GLuint *buffers , GLint maxBuffers , GLint *numBuffers);
#define glExtGetBuffersQCOM DynamicGL_ExtGetBuffersQCOM
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ExtGetRenderbuffersQCOM)(GLuint *renderbuffers , GLint maxRenderbuffers , GLint *numRenderbuffers);
#define glExtGetRenderbuffersQCOM DynamicGL_ExtGetRenderbuffersQCOM
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ExtGetFramebuffersQCOM)(GLuint *framebuffers , GLint maxFramebuffers , GLint *numFramebuffers);
#define glExtGetFramebuffersQCOM DynamicGL_ExtGetFramebuffersQCOM
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ExtGetTexLevelParameterivQCOM)(GLuint texture , GLenum face , GLint level , GLenum pname , GLint *params);
#define glExtGetTexLevelParameterivQCOM DynamicGL_ExtGetTexLevelParameterivQCOM
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ExtTexObjectStateOverrideiQCOM)(GLenum target , GLenum pname , GLint param);
#define glExtTexObjectStateOverrideiQCOM DynamicGL_ExtTexObjectStateOverrideiQCOM
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ExtGetTexSubImageQCOM)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLsizei width , GLsizei height , GLsizei depth , GLenum format , GLenum type , GLvoid *texels);
#define glExtGetTexSubImageQCOM DynamicGL_ExtGetTexSubImageQCOM
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ExtGetBufferPointervQCOM)(GLenum target , GLvoid *p1);
#define glExtGetBufferPointervQCOM DynamicGL_ExtGetBufferPointervQCOM
#else
extern "C" {
 DYNAMIC_GL_APIENTRY void glExtGetTexturesQCOM( GLuint *textures , GLint maxTextures , GLint *numTextures );
 DYNAMIC_GL_APIENTRY void glExtGetBuffersQCOM( GLuint *buffers , GLint maxBuffers , GLint *numBuffers );
 DYNAMIC_GL_APIENTRY void glExtGetRenderbuffersQCOM( GLuint *renderbuffers , GLint maxRenderbuffers , GLint *numRenderbuffers );
 DYNAMIC_GL_APIENTRY void glExtGetFramebuffersQCOM( GLuint *framebuffers , GLint maxFramebuffers , GLint *numFramebuffers );
 DYNAMIC_GL_APIENTRY void glExtGetTexLevelParameterivQCOM( GLuint texture , GLenum face , GLint level , GLenum pname , GLint *params );
 DYNAMIC_GL_APIENTRY void glExtTexObjectStateOverrideiQCOM( GLenum target , GLenum pname , GLint param );
 DYNAMIC_GL_APIENTRY void glExtGetTexSubImageQCOM( GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLsizei width , GLsizei height , GLsizei depth , GLenum format , GLenum type , GLvoid *texels );
 DYNAMIC_GL_APIENTRY void glExtGetBufferPointervQCOM( GLenum target , GLvoid *p1 );
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
extern bool DinamicGLFeature_QCOM_extended_get_Supported();
#endif /*USE_DYNAMIC_GL_QCOM_extended_get*/

/*OES_EGL_image_external*/
#ifdef USE_DYNAMIC_GL_OES_EGL_image_external
#define GL_TEXTURE_EXTERNAL_OES 0x8D65
#define GL_TEXTURE_BINDING_EXTERNAL_OES 0x8D67
#define GL_REQUIRED_TEXTURE_IMAGE_UNITS_OES 0x8D68
extern bool DinamicGLFeature_OES_EGL_image_external_Supported();
#endif /*USE_DYNAMIC_GL_OES_EGL_image_external*/

/*OES_vertex_array_object*/
#ifdef USE_DYNAMIC_GL_OES_vertex_array_object
#define GL_VERTEX_ARRAY_BINDING_OES 0x85B5
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindVertexArrayOES)(GLuint array);
#define glBindVertexArrayOES DynamicGL_BindVertexArrayOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteVertexArraysOES)(GLsizei n , const GLuint *arrays);
#define glDeleteVertexArraysOES DynamicGL_DeleteVertexArraysOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GenVertexArraysOES)(GLsizei n , GLuint *arrays);
#define glGenVertexArraysOES DynamicGL_GenVertexArraysOES
extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsVertexArrayOES)(GLuint array);
#define glIsVertexArrayOES DynamicGL_IsVertexArrayOES
#else
extern "C" {
 DYNAMIC_GL_APIENTRY void glBindVertexArrayOES( GLuint array );
 DYNAMIC_GL_APIENTRY void glDeleteVertexArraysOES( GLsizei n , const GLuint *arrays );
 DYNAMIC_GL_APIENTRY void glGenVertexArraysOES( GLsizei n , GLuint *arrays );
 DYNAMIC_GL_APIENTRY GLboolean glIsVertexArrayOES( GLuint array );
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
extern bool DinamicGLFeature_OES_vertex_array_object_Supported();
#endif /*USE_DYNAMIC_GL_OES_vertex_array_object*/

/*OES_compressed_ETC1_RGB8_texture*/
#ifdef USE_DYNAMIC_GL_OES_compressed_ETC1_RGB8_texture
#define GL_ETC1_RGB8_OES 0x8D64
extern bool DinamicGLFeature_OES_compressed_ETC1_RGB8_texture_Supported();
#endif /*USE_DYNAMIC_GL_OES_compressed_ETC1_RGB8_texture*/

/*OES_depth24*/
#ifdef USE_DYNAMIC_GL_OES_depth24
#define GL_DEPTH_COMPONENT24_OES 0x81A6
extern bool DinamicGLFeature_OES_depth24_Supported();
#endif /*USE_DYNAMIC_GL_OES_depth24*/

/*IMG_texture_env_enhanced_fixed_function*/
#ifdef USE_DYNAMIC_GL_IMG_texture_env_enhanced_fixed_function
#define GL_MODULATE_COLOR_IMG 0x8C04
#define GL_RECIP_ADD_SIGNED_ALPHA_IMG 0x8C05
#define GL_TEXTURE_ALPHA_MODULATE_IMG 0x8C06
#define GL_FACTOR_ALPHA_MODULATE_IMG 0x8C07
#define GL_FRAGMENT_ALPHA_MODULATE_IMG 0x8C08
#define GL_ADD_BLEND_IMG 0x8C09
#define GL_DOT3_RGBA_IMG 0x86AF
extern bool DinamicGLFeature_IMG_texture_env_enhanced_fixed_function_Supported();
#endif /*USE_DYNAMIC_GL_IMG_texture_env_enhanced_fixed_function*/

/*OES_element_index_uint*/
#ifdef USE_DYNAMIC_GL_OES_element_index_uint
#define GL_UNSIGNED_INT 0x1405
extern bool DinamicGLFeature_OES_element_index_uint_Supported();
#endif /*USE_DYNAMIC_GL_OES_element_index_uint*/

/*OES_blend_subtract*/
#ifdef USE_DYNAMIC_GL_OES_blend_subtract
#define GL_BLEND_EQUATION_OES 0x8009
#define GL_FUNC_ADD_OES 0x8006
#define GL_FUNC_SUBTRACT_OES 0x800A
#define GL_FUNC_REVERSE_SUBTRACT_OES 0x800B
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendEquationOES)(GLenum mode);
#define glBlendEquationOES DynamicGL_BlendEquationOES
#else
extern "C" {
 DYNAMIC_GL_APIENTRY void glBlendEquationOES( GLenum mode );
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
extern bool DinamicGLFeature_OES_blend_subtract_Supported();
#endif /*USE_DYNAMIC_GL_OES_blend_subtract*/

/*OES_texture_env_crossbar*/
#ifdef USE_DYNAMIC_GL_OES_texture_env_crossbar
extern bool DinamicGLFeature_OES_texture_env_crossbar_Supported();
#endif /*USE_DYNAMIC_GL_OES_texture_env_crossbar*/

/*QCOM_writeonly_rendering*/
#ifdef USE_DYNAMIC_GL_QCOM_writeonly_rendering
#define GL_WRITEONLY_RENDERING_QCOM 0x8823
extern bool DinamicGLFeature_QCOM_writeonly_rendering_Supported();
#endif /*USE_DYNAMIC_GL_QCOM_writeonly_rendering*/

/*APPLE_texture_max_level*/
#ifdef USE_DYNAMIC_GL_APPLE_texture_max_level
#define GL_TEXTURE_MAX_LEVEL_APPLE 0x813D
extern bool DinamicGLFeature_APPLE_texture_max_level_Supported();
#endif /*USE_DYNAMIC_GL_APPLE_texture_max_level*/

/*ARM_rgba8*/
#ifdef USE_DYNAMIC_GL_ARM_rgba8
extern bool DinamicGLFeature_ARM_rgba8_Supported();
#endif /*USE_DYNAMIC_GL_ARM_rgba8*/

/*QCOM_tiled_rendering*/
#ifdef USE_DYNAMIC_GL_QCOM_tiled_rendering
#define GL_COLOR_BUFFER_BIT0_QCOM 0x00000001
#define GL_COLOR_BUFFER_BIT1_QCOM 0x00000002
#define GL_COLOR_BUFFER_BIT2_QCOM 0x00000004
#define GL_COLOR_BUFFER_BIT3_QCOM 0x00000008
#define GL_COLOR_BUFFER_BIT4_QCOM 0x00000010
#define GL_COLOR_BUFFER_BIT5_QCOM 0x00000020
#define GL_COLOR_BUFFER_BIT6_QCOM 0x00000040
#define GL_COLOR_BUFFER_BIT7_QCOM 0x00000080
#define GL_DEPTH_BUFFER_BIT0_QCOM 0x00000100
#define GL_DEPTH_BUFFER_BIT1_QCOM 0x00000200
#define GL_DEPTH_BUFFER_BIT2_QCOM 0x00000400
#define GL_DEPTH_BUFFER_BIT3_QCOM 0x00000800
#define GL_DEPTH_BUFFER_BIT4_QCOM 0x00001000
#define GL_DEPTH_BUFFER_BIT5_QCOM 0x00002000
#define GL_DEPTH_BUFFER_BIT6_QCOM 0x00004000
#define GL_DEPTH_BUFFER_BIT7_QCOM 0x00008000
#define GL_STENCIL_BUFFER_BIT0_QCOM 0x00010000
#define GL_STENCIL_BUFFER_BIT1_QCOM 0x00020000
#define GL_STENCIL_BUFFER_BIT2_QCOM 0x00040000
#define GL_STENCIL_BUFFER_BIT3_QCOM 0x00080000
#define GL_STENCIL_BUFFER_BIT4_QCOM 0x00100000
#define GL_STENCIL_BUFFER_BIT5_QCOM 0x00200000
#define GL_STENCIL_BUFFER_BIT6_QCOM 0x00400000
#define GL_STENCIL_BUFFER_BIT7_QCOM 0x00800000
#define GL_MULTISAMPLE_BUFFER_BIT0_QCOM 0x01000000
#define GL_MULTISAMPLE_BUFFER_BIT1_QCOM 0x02000000
#define GL_MULTISAMPLE_BUFFER_BIT2_QCOM 0x04000000
#define GL_MULTISAMPLE_BUFFER_BIT3_QCOM 0x08000000
#define GL_MULTISAMPLE_BUFFER_BIT4_QCOM 0x10000000
#define GL_MULTISAMPLE_BUFFER_BIT5_QCOM 0x20000000
#define GL_MULTISAMPLE_BUFFER_BIT6_QCOM 0x40000000
#define GL_MULTISAMPLE_BUFFER_BIT7_QCOM 0x80000000
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_StartTilingQCOM)(GLuint x , GLuint y , GLuint width , GLuint height , GLbitfield preserveMask);
#define glStartTilingQCOM DynamicGL_StartTilingQCOM
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EndTilingQCOM)(GLbitfield preserveMask);
#define glEndTilingQCOM DynamicGL_EndTilingQCOM
#else
extern "C" {
 DYNAMIC_GL_APIENTRY void glStartTilingQCOM( GLuint x , GLuint y , GLuint width , GLuint height , GLbitfield preserveMask );
 DYNAMIC_GL_APIENTRY void glEndTilingQCOM( GLbitfield preserveMask );
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
extern bool DinamicGLFeature_QCOM_tiled_rendering_Supported();
#endif /*USE_DYNAMIC_GL_QCOM_tiled_rendering*/

/*EXT_read_format_bgra*/
#ifdef USE_DYNAMIC_GL_EXT_read_format_bgra
#define GL_BGRA_EXT 0x80E1
#define GL_UNSIGNED_SHORT_4_4_4_4_REV_EXT 0x8365
#define GL_UNSIGNED_SHORT_1_5_5_5_REV_EXT 0x8366
extern bool DinamicGLFeature_EXT_read_format_bgra_Supported();
#endif /*USE_DYNAMIC_GL_EXT_read_format_bgra*/

/*OES_rgb8_rgba8*/
#ifdef USE_DYNAMIC_GL_OES_rgb8_rgba8
#define GL_RGB8_OES 0x8051
#define GL_RGBA8_OES 0x8058
extern bool DinamicGLFeature_OES_rgb8_rgba8_Supported();
#endif /*USE_DYNAMIC_GL_OES_rgb8_rgba8*/

/*OES_stencil1*/
#ifdef USE_DYNAMIC_GL_OES_stencil1
#define GL_STENCIL_INDEX1_OES 0x8D46
extern bool DinamicGLFeature_OES_stencil1_Supported();
#endif /*USE_DYNAMIC_GL_OES_stencil1*/

/*OES_texture_cube_map*/
#ifdef USE_DYNAMIC_GL_OES_texture_cube_map
#define GL_NORMAL_MAP_OES 0x8511
#define GL_REFLECTION_MAP_OES 0x8512
#define GL_TEXTURE_CUBE_MAP_OES 0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP_OES 0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_OES 0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_OES 0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_OES 0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_OES 0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_OES 0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_OES 0x851A
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE_OES 0x851C
#define GL_TEXTURE_GEN_MODE_OES 0x2500
#define GL_TEXTURE_GEN_STR_OES 0x8D60
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexGenfOES)(GLenum coord , GLenum pname , GLfloat param);
#define glTexGenfOES DynamicGL_TexGenfOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexGenfvOES)(GLenum coord , GLenum pname , const GLfloat *params);
#define glTexGenfvOES DynamicGL_TexGenfvOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexGeniOES)(GLenum coord , GLenum pname , GLint param);
#define glTexGeniOES DynamicGL_TexGeniOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexGenivOES)(GLenum coord , GLenum pname , const GLint *params);
#define glTexGenivOES DynamicGL_TexGenivOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexGenxOES)(GLenum coord , GLenum pname , GLfixed param);
#define glTexGenxOES DynamicGL_TexGenxOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexGenxvOES)(GLenum coord , GLenum pname , const GLfixed *params);
#define glTexGenxvOES DynamicGL_TexGenxvOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexGenfvOES)(GLenum coord , GLenum pname , GLfloat *params);
#define glGetTexGenfvOES DynamicGL_GetTexGenfvOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexGenivOES)(GLenum coord , GLenum pname , GLint *params);
#define glGetTexGenivOES DynamicGL_GetTexGenivOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexGenxvOES)(GLenum coord , GLenum pname , GLfixed *params);
#define glGetTexGenxvOES DynamicGL_GetTexGenxvOES
#else
extern "C" {
 DYNAMIC_GL_APIENTRY void glTexGenfOES( GLenum coord , GLenum pname , GLfloat param );
 DYNAMIC_GL_APIENTRY void glTexGenfvOES( GLenum coord , GLenum pname , const GLfloat *params );
 DYNAMIC_GL_APIENTRY void glTexGeniOES( GLenum coord , GLenum pname , GLint param );
 DYNAMIC_GL_APIENTRY void glTexGenivOES( GLenum coord , GLenum pname , const GLint *params );
 DYNAMIC_GL_APIENTRY void glTexGenxOES( GLenum coord , GLenum pname , GLfixed param );
 DYNAMIC_GL_APIENTRY void glTexGenxvOES( GLenum coord , GLenum pname , const GLfixed *params );
 DYNAMIC_GL_APIENTRY void glGetTexGenfvOES( GLenum coord , GLenum pname , GLfloat *params );
 DYNAMIC_GL_APIENTRY void glGetTexGenivOES( GLenum coord , GLenum pname , GLint *params );
 DYNAMIC_GL_APIENTRY void glGetTexGenxvOES( GLenum coord , GLenum pname , GLfixed *params );
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
extern bool DinamicGLFeature_OES_texture_cube_map_Supported();
#endif /*USE_DYNAMIC_GL_OES_texture_cube_map*/

/*AMD_compressed_ATC_texture*/
#ifdef USE_DYNAMIC_GL_AMD_compressed_ATC_texture
#define GL_ATC_RGB_AMD 0x8C92
#define GL_ATC_RGBA_EXPLICIT_ALPHA_AMD 0x8C93
#define GL_ATC_RGBA_INTERPOLATED_ALPHA_AMD 0x87EE
extern bool DinamicGLFeature_AMD_compressed_ATC_texture_Supported();
#endif /*USE_DYNAMIC_GL_AMD_compressed_ATC_texture*/

/*OES_mapbuffer*/
#ifdef USE_DYNAMIC_GL_OES_mapbuffer
#define GL_WRITE_ONLY_OES 0x88B9
#define GL_BUFFER_ACCESS_OES 0x88BB
#define GL_BUFFER_MAPPED_OES 0x88BC
#define GL_BUFFER_MAP_POINTER_OES 0x88BD
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_UnmapBufferOES)(GLenum target);
#define glUnmapBufferOES DynamicGL_UnmapBufferOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetBufferPointervOES)(GLenum target , GLenum pname , GLvoid *p1);
#define glGetBufferPointervOES DynamicGL_GetBufferPointervOES
#else
extern "C" {
 DYNAMIC_GL_APIENTRY GLboolean glUnmapBufferOES( GLenum target );
 DYNAMIC_GL_APIENTRY void glGetBufferPointervOES( GLenum target , GLenum pname , GLvoid *p1 );
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
extern bool DinamicGLFeature_OES_mapbuffer_Supported();
#endif /*USE_DYNAMIC_GL_OES_mapbuffer*/

/*EXT_blend_minmax*/
#ifdef USE_DYNAMIC_GL_EXT_blend_minmax
#define GL_MIN_EXT 0x8007
#define GL_MAX_EXT 0x8008
extern bool DinamicGLFeature_EXT_blend_minmax_Supported();
#endif /*USE_DYNAMIC_GL_EXT_blend_minmax*/

/*EXT_multi_draw_arrays*/
#ifdef USE_DYNAMIC_GL_EXT_multi_draw_arrays
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiDrawArraysEXT)(GLenum mode , GLint *first , GLsizei *count , GLsizei primcount);
#define glMultiDrawArraysEXT DynamicGL_MultiDrawArraysEXT
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiDrawElementsEXT)(GLenum mode , const GLsizei *count , GLenum type , const GLvoid* *indices , GLsizei primcount);
#define glMultiDrawElementsEXT DynamicGL_MultiDrawElementsEXT
#else
extern "C" {
 DYNAMIC_GL_APIENTRY void glMultiDrawArraysEXT( GLenum mode , GLint *first , GLsizei *count , GLsizei primcount );
 DYNAMIC_GL_APIENTRY void glMultiDrawElementsEXT( GLenum mode , const GLsizei *count , GLenum type , const GLvoid* *indices , GLsizei primcount );
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
extern bool DinamicGLFeature_EXT_multi_draw_arrays_Supported();
#endif /*USE_DYNAMIC_GL_EXT_multi_draw_arrays*/

/*OES_fixed_point*/
#ifdef USE_DYNAMIC_GL_OES_fixed_point
#define GL_FIXED_OES 0x140C
#ifndef DYNAMIC_GL_NO_FUCPOINTERS
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_AlphaFuncxOES)(GLenum func , GLclampx ref);
#define glAlphaFuncxOES DynamicGL_AlphaFuncxOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearColorxOES)(GLclampx red , GLclampx green , GLclampx blue , GLclampx alpha);
#define glClearColorxOES DynamicGL_ClearColorxOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearDepthxOES)(GLclampx depth);
#define glClearDepthxOES DynamicGL_ClearDepthxOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClipPlanexOES)(GLenum plane , const GLfixed *equation);
#define glClipPlanexOES DynamicGL_ClipPlanexOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4xOES)(GLfixed red , GLfixed green , GLfixed blue , GLfixed alpha);
#define glColor4xOES DynamicGL_Color4xOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DepthRangexOES)(GLclampx zNear , GLclampx zFar);
#define glDepthRangexOES DynamicGL_DepthRangexOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FogxOES)(GLenum pname , GLfixed param);
#define glFogxOES DynamicGL_FogxOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FogxvOES)(GLenum pname , const GLfixed *params);
#define glFogxvOES DynamicGL_FogxvOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FrustumxOES)(GLfixed left , GLfixed right , GLfixed bottom , GLfixed top , GLfixed zNear , GLfixed zFar);
#define glFrustumxOES DynamicGL_FrustumxOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFixedvOES)(GLenum pname , GLfixed *params);
#define glGetFixedvOES DynamicGL_GetFixedvOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetLightxvOES)(GLenum light , GLenum pname , GLfixed *params);
#define glGetLightxvOES DynamicGL_GetLightxvOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMaterialxvOES)(GLenum face , GLenum pname , GLfixed *params);
#define glGetMaterialxvOES DynamicGL_GetMaterialxvOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexEnvxvOES)(GLenum env , GLenum pname , GLfixed *params);
#define glGetTexEnvxvOES DynamicGL_GetTexEnvxvOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexParameterxvOES)(GLenum target , GLenum pname , GLfixed *params);
#define glGetTexParameterxvOES DynamicGL_GetTexParameterxvOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LightModelxOES)(GLenum pname , GLfixed param);
#define glLightModelxOES DynamicGL_LightModelxOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LightModelxvOES)(GLenum pname , const GLfixed *params);
#define glLightModelxvOES DynamicGL_LightModelxvOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LightxOES)(GLenum light , GLenum pname , GLfixed param);
#define glLightxOES DynamicGL_LightxOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LightxvOES)(GLenum light , GLenum pname , const GLfixed *params);
#define glLightxvOES DynamicGL_LightxvOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LineWidthxOES)(GLfixed width);
#define glLineWidthxOES DynamicGL_LineWidthxOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LoadMatrixxOES)(const GLfixed *m);
#define glLoadMatrixxOES DynamicGL_LoadMatrixxOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MaterialxOES)(GLenum face , GLenum pname , GLfixed param);
#define glMaterialxOES DynamicGL_MaterialxOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MaterialxvOES)(GLenum face , GLenum pname , const GLfixed *params);
#define glMaterialxvOES DynamicGL_MaterialxvOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultMatrixxOES)(const GLfixed *m);
#define glMultMatrixxOES DynamicGL_MultMatrixxOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4xOES)(GLenum target , GLfixed s , GLfixed t , GLfixed r , GLfixed q);
#define glMultiTexCoord4xOES DynamicGL_MultiTexCoord4xOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Normal3xOES)(GLfixed nx , GLfixed ny , GLfixed nz);
#define glNormal3xOES DynamicGL_Normal3xOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_OrthoxOES)(GLfixed left , GLfixed right , GLfixed bottom , GLfixed top , GLfixed zNear , GLfixed zFar);
#define glOrthoxOES DynamicGL_OrthoxOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameterxOES)(GLenum pname , GLfixed param);
#define glPointParameterxOES DynamicGL_PointParameterxOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameterxvOES)(GLenum pname , const GLfixed *params);
#define glPointParameterxvOES DynamicGL_PointParameterxvOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PointSizexOES)(GLfixed size);
#define glPointSizexOES DynamicGL_PointSizexOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PolygonOffsetxOES)(GLfixed factor , GLfixed units);
#define glPolygonOffsetxOES DynamicGL_PolygonOffsetxOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RotatexOES)(GLfixed angle , GLfixed x , GLfixed y , GLfixed z);
#define glRotatexOES DynamicGL_RotatexOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SampleCoveragexOES)(GLclampx value , GLboolean invert);
#define glSampleCoveragexOES DynamicGL_SampleCoveragexOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ScalexOES)(GLfixed x , GLfixed y , GLfixed z);
#define glScalexOES DynamicGL_ScalexOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexEnvxOES)(GLenum target , GLenum pname , GLfixed param);
#define glTexEnvxOES DynamicGL_TexEnvxOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexEnvxvOES)(GLenum target , GLenum pname , const GLfixed *params);
#define glTexEnvxvOES DynamicGL_TexEnvxvOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexParameterxOES)(GLenum target , GLenum pname , GLfixed param);
#define glTexParameterxOES DynamicGL_TexParameterxOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexParameterxvOES)(GLenum target , GLenum pname , const GLfixed *params);
#define glTexParameterxvOES DynamicGL_TexParameterxvOES
extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TranslatexOES)(GLfixed x , GLfixed y , GLfixed z);
#define glTranslatexOES DynamicGL_TranslatexOES
#else
extern "C" {
 DYNAMIC_GL_APIENTRY void glAlphaFuncxOES( GLenum func , GLclampx ref );
 DYNAMIC_GL_APIENTRY void glClearColorxOES( GLclampx red , GLclampx green , GLclampx blue , GLclampx alpha );
 DYNAMIC_GL_APIENTRY void glClearDepthxOES( GLclampx depth );
 DYNAMIC_GL_APIENTRY void glClipPlanexOES( GLenum plane , const GLfixed *equation );
 DYNAMIC_GL_APIENTRY void glColor4xOES( GLfixed red , GLfixed green , GLfixed blue , GLfixed alpha );
 DYNAMIC_GL_APIENTRY void glDepthRangexOES( GLclampx zNear , GLclampx zFar );
 DYNAMIC_GL_APIENTRY void glFogxOES( GLenum pname , GLfixed param );
 DYNAMIC_GL_APIENTRY void glFogxvOES( GLenum pname , const GLfixed *params );
 DYNAMIC_GL_APIENTRY void glFrustumxOES( GLfixed left , GLfixed right , GLfixed bottom , GLfixed top , GLfixed zNear , GLfixed zFar );
 DYNAMIC_GL_APIENTRY void glGetFixedvOES( GLenum pname , GLfixed *params );
 DYNAMIC_GL_APIENTRY void glGetLightxvOES( GLenum light , GLenum pname , GLfixed *params );
 DYNAMIC_GL_APIENTRY void glGetMaterialxvOES( GLenum face , GLenum pname , GLfixed *params );
 DYNAMIC_GL_APIENTRY void glGetTexEnvxvOES( GLenum env , GLenum pname , GLfixed *params );
 DYNAMIC_GL_APIENTRY void glGetTexParameterxvOES( GLenum target , GLenum pname , GLfixed *params );
 DYNAMIC_GL_APIENTRY void glLightModelxOES( GLenum pname , GLfixed param );
 DYNAMIC_GL_APIENTRY void glLightModelxvOES( GLenum pname , const GLfixed *params );
 DYNAMIC_GL_APIENTRY void glLightxOES( GLenum light , GLenum pname , GLfixed param );
 DYNAMIC_GL_APIENTRY void glLightxvOES( GLenum light , GLenum pname , const GLfixed *params );
 DYNAMIC_GL_APIENTRY void glLineWidthxOES( GLfixed width );
 DYNAMIC_GL_APIENTRY void glLoadMatrixxOES( const GLfixed *m );
 DYNAMIC_GL_APIENTRY void glMaterialxOES( GLenum face , GLenum pname , GLfixed param );
 DYNAMIC_GL_APIENTRY void glMaterialxvOES( GLenum face , GLenum pname , const GLfixed *params );
 DYNAMIC_GL_APIENTRY void glMultMatrixxOES( const GLfixed *m );
 DYNAMIC_GL_APIENTRY void glMultiTexCoord4xOES( GLenum target , GLfixed s , GLfixed t , GLfixed r , GLfixed q );
 DYNAMIC_GL_APIENTRY void glNormal3xOES( GLfixed nx , GLfixed ny , GLfixed nz );
 DYNAMIC_GL_APIENTRY void glOrthoxOES( GLfixed left , GLfixed right , GLfixed bottom , GLfixed top , GLfixed zNear , GLfixed zFar );
 DYNAMIC_GL_APIENTRY void glPointParameterxOES( GLenum pname , GLfixed param );
 DYNAMIC_GL_APIENTRY void glPointParameterxvOES( GLenum pname , const GLfixed *params );
 DYNAMIC_GL_APIENTRY void glPointSizexOES( GLfixed size );
 DYNAMIC_GL_APIENTRY void glPolygonOffsetxOES( GLfixed factor , GLfixed units );
 DYNAMIC_GL_APIENTRY void glRotatexOES( GLfixed angle , GLfixed x , GLfixed y , GLfixed z );
 DYNAMIC_GL_APIENTRY void glSampleCoveragexOES( GLclampx value , GLboolean invert );
 DYNAMIC_GL_APIENTRY void glScalexOES( GLfixed x , GLfixed y , GLfixed z );
 DYNAMIC_GL_APIENTRY void glTexEnvxOES( GLenum target , GLenum pname , GLfixed param );
 DYNAMIC_GL_APIENTRY void glTexEnvxvOES( GLenum target , GLenum pname , const GLfixed *params );
 DYNAMIC_GL_APIENTRY void glTexParameterxOES( GLenum target , GLenum pname , GLfixed param );
 DYNAMIC_GL_APIENTRY void glTexParameterxvOES( GLenum target , GLenum pname , const GLfixed *params );
 DYNAMIC_GL_APIENTRY void glTranslatexOES( GLfixed x , GLfixed y , GLfixed z );
}
#endif /*DYNAMIC_GL_NO_FUCPOINTERS*/
extern bool DinamicGLFeature_OES_fixed_point_Supported();
#endif /*USE_DYNAMIC_GL_OES_fixed_point*/

