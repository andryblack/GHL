/*VERSION_1_1*/
#ifdef USE_DYNAMIC_GL_VERSION_1_1
typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef void GLvoid;
typedef signed char GLbyte;
typedef short GLshort;
typedef int GLint;
typedef unsigned char GLubyte;
typedef unsigned short GLushort;
typedef unsigned int GLuint;
typedef int GLsizei;
typedef float GLfloat;
typedef float GLclampf;
typedef double GLdouble;
typedef double GLclampd;
#define GL_FALSE 0x0
#define GL_TRUE 0x1
#define GL_BYTE 0x1400
#define GL_UNSIGNED_BYTE 0x1401
#define GL_SHORT 0x1402
#define GL_UNSIGNED_SHORT 0x1403
#define GL_INT 0x1404
#define GL_UNSIGNED_INT 0x1405
#define GL_FLOAT 0x1406
#define GL_DOUBLE 0x140A
#define GL_2_BYTES 0x1407
#define GL_3_BYTES 0x1408
#define GL_4_BYTES 0x1409
#define GL_POINTS 0x0000
#define GL_LINES 0x0001
#define GL_LINE_LOOP 0x0002
#define GL_LINE_STRIP 0x0003
#define GL_TRIANGLES 0x0004
#define GL_TRIANGLE_STRIP 0x0005
#define GL_TRIANGLE_FAN 0x0006
#define GL_QUADS 0x0007
#define GL_QUAD_STRIP 0x0008
#define GL_POLYGON 0x0009
#define GL_VERTEX_ARRAY 0x8074
#define GL_NORMAL_ARRAY 0x8075
#define GL_COLOR_ARRAY 0x8076
#define GL_INDEX_ARRAY 0x8077
#define GL_TEXTURE_COORD_ARRAY 0x8078
#define GL_EDGE_FLAG_ARRAY 0x8079
#define GL_VERTEX_ARRAY_SIZE 0x807A
#define GL_VERTEX_ARRAY_TYPE 0x807B
#define GL_VERTEX_ARRAY_STRIDE 0x807C
#define GL_NORMAL_ARRAY_TYPE 0x807E
#define GL_NORMAL_ARRAY_STRIDE 0x807F
#define GL_COLOR_ARRAY_SIZE 0x8081
#define GL_COLOR_ARRAY_TYPE 0x8082
#define GL_COLOR_ARRAY_STRIDE 0x8083
#define GL_INDEX_ARRAY_TYPE 0x8085
#define GL_INDEX_ARRAY_STRIDE 0x8086
#define GL_TEXTURE_COORD_ARRAY_SIZE 0x8088
#define GL_TEXTURE_COORD_ARRAY_TYPE 0x8089
#define GL_TEXTURE_COORD_ARRAY_STRIDE 0x808A
#define GL_EDGE_FLAG_ARRAY_STRIDE 0x808C
#define GL_VERTEX_ARRAY_POINTER 0x808E
#define GL_NORMAL_ARRAY_POINTER 0x808F
#define GL_COLOR_ARRAY_POINTER 0x8090
#define GL_INDEX_ARRAY_POINTER 0x8091
#define GL_TEXTURE_COORD_ARRAY_POINTER 0x8092
#define GL_EDGE_FLAG_ARRAY_POINTER 0x8093
#define GL_V2F 0x2A20
#define GL_V3F 0x2A21
#define GL_C4UB_V2F 0x2A22
#define GL_C4UB_V3F 0x2A23
#define GL_C3F_V3F 0x2A24
#define GL_N3F_V3F 0x2A25
#define GL_C4F_N3F_V3F 0x2A26
#define GL_T2F_V3F 0x2A27
#define GL_T4F_V4F 0x2A28
#define GL_T2F_C4UB_V3F 0x2A29
#define GL_T2F_C3F_V3F 0x2A2A
#define GL_T2F_N3F_V3F 0x2A2B
#define GL_T2F_C4F_N3F_V3F 0x2A2C
#define GL_T4F_C4F_N3F_V4F 0x2A2D
#define GL_MATRIX_MODE 0x0BA0
#define GL_MODELVIEW 0x1700
#define GL_PROJECTION 0x1701
#define GL_TEXTURE 0x1702
#define GL_POINT_SMOOTH 0x0B10
#define GL_POINT_SIZE 0x0B11
#define GL_POINT_SIZE_GRANULARITY 0x0B13
#define GL_POINT_SIZE_RANGE 0x0B12
#define GL_LINE_SMOOTH 0x0B20
#define GL_LINE_STIPPLE 0x0B24
#define GL_LINE_STIPPLE_PATTERN 0x0B25
#define GL_LINE_STIPPLE_REPEAT 0x0B26
#define GL_LINE_WIDTH 0x0B21
#define GL_LINE_WIDTH_GRANULARITY 0x0B23
#define GL_LINE_WIDTH_RANGE 0x0B22
#define GL_POINT 0x1B00
#define GL_LINE 0x1B01
#define GL_FILL 0x1B02
#define GL_CW 0x0900
#define GL_CCW 0x0901
#define GL_FRONT 0x0404
#define GL_BACK 0x0405
#define GL_POLYGON_MODE 0x0B40
#define GL_POLYGON_SMOOTH 0x0B41
#define GL_POLYGON_STIPPLE 0x0B42
#define GL_EDGE_FLAG 0x0B43
#define GL_CULL_FACE 0x0B44
#define GL_CULL_FACE_MODE 0x0B45
#define GL_FRONT_FACE 0x0B46
#define GL_POLYGON_OFFSET_FACTOR 0x8038
#define GL_POLYGON_OFFSET_UNITS 0x2A00
#define GL_POLYGON_OFFSET_POINT 0x2A01
#define GL_POLYGON_OFFSET_LINE 0x2A02
#define GL_POLYGON_OFFSET_FILL 0x8037
#define GL_COMPILE 0x1300
#define GL_COMPILE_AND_EXECUTE 0x1301
#define GL_LIST_BASE 0x0B32
#define GL_LIST_INDEX 0x0B33
#define GL_LIST_MODE 0x0B30
#define GL_NEVER 0x0200
#define GL_LESS 0x0201
#define GL_EQUAL 0x0202
#define GL_LEQUAL 0x0203
#define GL_GREATER 0x0204
#define GL_NOTEQUAL 0x0205
#define GL_GEQUAL 0x0206
#define GL_ALWAYS 0x0207
#define GL_DEPTH_TEST 0x0B71
#define GL_DEPTH_BITS 0x0D56
#define GL_DEPTH_CLEAR_VALUE 0x0B73
#define GL_DEPTH_FUNC 0x0B74
#define GL_DEPTH_RANGE 0x0B70
#define GL_DEPTH_WRITEMASK 0x0B72
#define GL_DEPTH_COMPONENT 0x1902
#define GL_LIGHTING 0x0B50
#define GL_LIGHT0 0x4000
#define GL_LIGHT1 0x4001
#define GL_LIGHT2 0x4002
#define GL_LIGHT3 0x4003
#define GL_LIGHT4 0x4004
#define GL_LIGHT5 0x4005
#define GL_LIGHT6 0x4006
#define GL_LIGHT7 0x4007
#define GL_SPOT_EXPONENT 0x1205
#define GL_SPOT_CUTOFF 0x1206
#define GL_CONSTANT_ATTENUATION 0x1207
#define GL_LINEAR_ATTENUATION 0x1208
#define GL_QUADRATIC_ATTENUATION 0x1209
#define GL_AMBIENT 0x1200
#define GL_DIFFUSE 0x1201
#define GL_SPECULAR 0x1202
#define GL_SHININESS 0x1601
#define GL_EMISSION 0x1600
#define GL_POSITION 0x1203
#define GL_SPOT_DIRECTION 0x1204
#define GL_AMBIENT_AND_DIFFUSE 0x1602
#define GL_COLOR_INDEXES 0x1603
#define GL_LIGHT_MODEL_TWO_SIDE 0x0B52
#define GL_LIGHT_MODEL_LOCAL_VIEWER 0x0B51
#define GL_LIGHT_MODEL_AMBIENT 0x0B53
#define GL_FRONT_AND_BACK 0x0408
#define GL_SHADE_MODEL 0x0B54
#define GL_FLAT 0x1D00
#define GL_SMOOTH 0x1D01
#define GL_COLOR_MATERIAL 0x0B57
#define GL_COLOR_MATERIAL_FACE 0x0B55
#define GL_COLOR_MATERIAL_PARAMETER 0x0B56
#define GL_NORMALIZE 0x0BA1
#define GL_CLIP_PLANE0 0x3000
#define GL_CLIP_PLANE1 0x3001
#define GL_CLIP_PLANE2 0x3002
#define GL_CLIP_PLANE3 0x3003
#define GL_CLIP_PLANE4 0x3004
#define GL_CLIP_PLANE5 0x3005
#define GL_ACCUM_RED_BITS 0x0D58
#define GL_ACCUM_GREEN_BITS 0x0D59
#define GL_ACCUM_BLUE_BITS 0x0D5A
#define GL_ACCUM_ALPHA_BITS 0x0D5B
#define GL_ACCUM_CLEAR_VALUE 0x0B80
#define GL_ACCUM 0x0100
#define GL_ADD 0x0104
#define GL_LOAD 0x0101
#define GL_MULT 0x0103
#define GL_RETURN 0x0102
#define GL_ALPHA_TEST 0x0BC0
#define GL_ALPHA_TEST_REF 0x0BC2
#define GL_ALPHA_TEST_FUNC 0x0BC1
#define GL_BLEND 0x0BE2
#define GL_BLEND_SRC 0x0BE1
#define GL_BLEND_DST 0x0BE0
#define GL_ZERO 0x0
#define GL_ONE 0x1
#define GL_SRC_COLOR 0x0300
#define GL_ONE_MINUS_SRC_COLOR 0x0301
#define GL_SRC_ALPHA 0x0302
#define GL_ONE_MINUS_SRC_ALPHA 0x0303
#define GL_DST_ALPHA 0x0304
#define GL_ONE_MINUS_DST_ALPHA 0x0305
#define GL_DST_COLOR 0x0306
#define GL_ONE_MINUS_DST_COLOR 0x0307
#define GL_SRC_ALPHA_SATURATE 0x0308
#define GL_CONSTANT_COLOR 0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR 0x8002
#define GL_CONSTANT_ALPHA 0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA 0x8004
#define GL_FEEDBACK 0x1C01
#define GL_RENDER 0x1C00
#define GL_SELECT 0x1C02
#define GL_2D 0x0600
#define GL_3D 0x0601
#define GL_3D_COLOR 0x0602
#define GL_3D_COLOR_TEXTURE 0x0603
#define GL_4D_COLOR_TEXTURE 0x0604
#define GL_POINT_TOKEN 0x0701
#define GL_LINE_TOKEN 0x0702
#define GL_LINE_RESET_TOKEN 0x0707
#define GL_POLYGON_TOKEN 0x0703
#define GL_BITMAP_TOKEN 0x0704
#define GL_DRAW_PIXEL_TOKEN 0x0705
#define GL_COPY_PIXEL_TOKEN 0x0706
#define GL_PASS_THROUGH_TOKEN 0x0700
#define GL_FEEDBACK_BUFFER_POINTER 0x0DF0
#define GL_FEEDBACK_BUFFER_SIZE 0x0DF1
#define GL_FEEDBACK_BUFFER_TYPE 0x0DF2
#define GL_SELECTION_BUFFER_POINTER 0x0DF3
#define GL_SELECTION_BUFFER_SIZE 0x0DF4
#define GL_FOG 0x0B60
#define GL_FOG_MODE 0x0B65
#define GL_FOG_DENSITY 0x0B62
#define GL_FOG_COLOR 0x0B66
#define GL_FOG_INDEX 0x0B61
#define GL_FOG_START 0x0B63
#define GL_FOG_END 0x0B64
#define GL_LINEAR 0x2601
#define GL_EXP 0x0800
#define GL_EXP2 0x0801
#define GL_LOGIC_OP 0x0BF1
#define GL_INDEX_LOGIC_OP 0x0BF1
#define GL_COLOR_LOGIC_OP 0x0BF2
#define GL_LOGIC_OP_MODE 0x0BF0
#define GL_CLEAR 0x1500
#define GL_SET 0x150F
#define GL_COPY 0x1503
#define GL_COPY_INVERTED 0x150C
#define GL_NOOP 0x1505
#define GL_INVERT 0x150A
#define GL_AND 0x1501
#define GL_NAND 0x150E
#define GL_OR 0x1507
#define GL_NOR 0x1508
#define GL_XOR 0x1506
#define GL_EQUIV 0x1509
#define GL_AND_REVERSE 0x1502
#define GL_AND_INVERTED 0x1504
#define GL_OR_REVERSE 0x150B
#define GL_OR_INVERTED 0x150D
#define GL_STENCIL_TEST 0x0B90
#define GL_STENCIL_WRITEMASK 0x0B98
#define GL_STENCIL_BITS 0x0D57
#define GL_STENCIL_FUNC 0x0B92
#define GL_STENCIL_VALUE_MASK 0x0B93
#define GL_STENCIL_REF 0x0B97
#define GL_STENCIL_FAIL 0x0B94
#define GL_STENCIL_PASS_DEPTH_PASS 0x0B96
#define GL_STENCIL_PASS_DEPTH_FAIL 0x0B95
#define GL_STENCIL_CLEAR_VALUE 0x0B91
#define GL_STENCIL_INDEX 0x1901
#define GL_KEEP 0x1E00
#define GL_REPLACE 0x1E01
#define GL_INCR 0x1E02
#define GL_DECR 0x1E03
#define GL_NONE 0x0
#define GL_LEFT 0x0406
#define GL_RIGHT 0x0407
#define GL_FRONT_LEFT 0x0400
#define GL_FRONT_RIGHT 0x0401
#define GL_BACK_LEFT 0x0402
#define GL_BACK_RIGHT 0x0403
#define GL_AUX0 0x0409
#define GL_AUX1 0x040A
#define GL_AUX2 0x040B
#define GL_AUX3 0x040C
#define GL_COLOR_INDEX 0x1900
#define GL_RED 0x1903
#define GL_GREEN 0x1904
#define GL_BLUE 0x1905
#define GL_ALPHA 0x1906
#define GL_LUMINANCE 0x1909
#define GL_LUMINANCE_ALPHA 0x190A
#define GL_ALPHA_BITS 0x0D55
#define GL_RED_BITS 0x0D52
#define GL_GREEN_BITS 0x0D53
#define GL_BLUE_BITS 0x0D54
#define GL_INDEX_BITS 0x0D51
#define GL_SUBPIXEL_BITS 0x0D50
#define GL_AUX_BUFFERS 0x0C00
#define GL_READ_BUFFER 0x0C02
#define GL_DRAW_BUFFER 0x0C01
#define GL_DOUBLEBUFFER 0x0C32
#define GL_STEREO 0x0C33
#define GL_BITMAP 0x1A00
#define GL_COLOR 0x1800
#define GL_DEPTH 0x1801
#define GL_STENCIL 0x1802
#define GL_DITHER 0x0BD0
#define GL_RGB 0x1907
#define GL_RGBA 0x1908
#define GL_MAX_LIST_NESTING 0x0B31
#define GL_MAX_ATTRIB_STACK_DEPTH 0x0D35
#define GL_MAX_MODELVIEW_STACK_DEPTH 0x0D36
#define GL_MAX_NAME_STACK_DEPTH 0x0D37
#define GL_MAX_PROJECTION_STACK_DEPTH 0x0D38
#define GL_MAX_TEXTURE_STACK_DEPTH 0x0D39
#define GL_MAX_EVAL_ORDER 0x0D30
#define GL_MAX_LIGHTS 0x0D31
#define GL_MAX_CLIP_PLANES 0x0D32
#define GL_MAX_TEXTURE_SIZE 0x0D33
#define GL_MAX_PIXEL_MAP_TABLE 0x0D34
#define GL_MAX_VIEWPORT_DIMS 0x0D3A
#define GL_MAX_CLIENT_ATTRIB_STACK_DEPTH 0x0D3B
#define GL_ATTRIB_STACK_DEPTH 0x0BB0
#define GL_CLIENT_ATTRIB_STACK_DEPTH 0x0BB1
#define GL_COLOR_CLEAR_VALUE 0x0C22
#define GL_COLOR_WRITEMASK 0x0C23
#define GL_CURRENT_INDEX 0x0B01
#define GL_CURRENT_COLOR 0x0B00
#define GL_CURRENT_NORMAL 0x0B02
#define GL_CURRENT_RASTER_COLOR 0x0B04
#define GL_CURRENT_RASTER_DISTANCE 0x0B09
#define GL_CURRENT_RASTER_INDEX 0x0B05
#define GL_CURRENT_RASTER_POSITION 0x0B07
#define GL_CURRENT_RASTER_TEXTURE_COORDS 0x0B06
#define GL_CURRENT_RASTER_POSITION_VALID 0x0B08
#define GL_CURRENT_TEXTURE_COORDS 0x0B03
#define GL_INDEX_CLEAR_VALUE 0x0C20
#define GL_INDEX_MODE 0x0C30
#define GL_INDEX_WRITEMASK 0x0C21
#define GL_MODELVIEW_MATRIX 0x0BA6
#define GL_MODELVIEW_STACK_DEPTH 0x0BA3
#define GL_NAME_STACK_DEPTH 0x0D70
#define GL_PROJECTION_MATRIX 0x0BA7
#define GL_PROJECTION_STACK_DEPTH 0x0BA4
#define GL_RENDER_MODE 0x0C40
#define GL_RGBA_MODE 0x0C31
#define GL_TEXTURE_MATRIX 0x0BA8
#define GL_TEXTURE_STACK_DEPTH 0x0BA5
#define GL_VIEWPORT 0x0BA2
#define GL_AUTO_NORMAL 0x0D80
#define GL_MAP1_COLOR_4 0x0D90
#define GL_MAP1_GRID_DOMAIN 0x0DD0
#define GL_MAP1_GRID_SEGMENTS 0x0DD1
#define GL_MAP1_INDEX 0x0D91
#define GL_MAP1_NORMAL 0x0D92
#define GL_MAP1_TEXTURE_COORD_1 0x0D93
#define GL_MAP1_TEXTURE_COORD_2 0x0D94
#define GL_MAP1_TEXTURE_COORD_3 0x0D95
#define GL_MAP1_TEXTURE_COORD_4 0x0D96
#define GL_MAP1_VERTEX_3 0x0D97
#define GL_MAP1_VERTEX_4 0x0D98
#define GL_MAP2_COLOR_4 0x0DB0
#define GL_MAP2_GRID_DOMAIN 0x0DD2
#define GL_MAP2_GRID_SEGMENTS 0x0DD3
#define GL_MAP2_INDEX 0x0DB1
#define GL_MAP2_NORMAL 0x0DB2
#define GL_MAP2_TEXTURE_COORD_1 0x0DB3
#define GL_MAP2_TEXTURE_COORD_2 0x0DB4
#define GL_MAP2_TEXTURE_COORD_3 0x0DB5
#define GL_MAP2_TEXTURE_COORD_4 0x0DB6
#define GL_MAP2_VERTEX_3 0x0DB7
#define GL_MAP2_VERTEX_4 0x0DB8
#define GL_COEFF 0x0A00
#define GL_DOMAIN 0x0A02
#define GL_ORDER 0x0A01
#define GL_FOG_HINT 0x0C54
#define GL_LINE_SMOOTH_HINT 0x0C52
#define GL_PERSPECTIVE_CORRECTION_HINT 0x0C50
#define GL_POINT_SMOOTH_HINT 0x0C51
#define GL_POLYGON_SMOOTH_HINT 0x0C53
#define GL_DONT_CARE 0x1100
#define GL_FASTEST 0x1101
#define GL_NICEST 0x1102
#define GL_SCISSOR_TEST 0x0C11
#define GL_SCISSOR_BOX 0x0C10
#define GL_MAP_COLOR 0x0D10
#define GL_MAP_STENCIL 0x0D11
#define GL_INDEX_SHIFT 0x0D12
#define GL_INDEX_OFFSET 0x0D13
#define GL_RED_SCALE 0x0D14
#define GL_RED_BIAS 0x0D15
#define GL_GREEN_SCALE 0x0D18
#define GL_GREEN_BIAS 0x0D19
#define GL_BLUE_SCALE 0x0D1A
#define GL_BLUE_BIAS 0x0D1B
#define GL_ALPHA_SCALE 0x0D1C
#define GL_ALPHA_BIAS 0x0D1D
#define GL_DEPTH_SCALE 0x0D1E
#define GL_DEPTH_BIAS 0x0D1F
#define GL_PIXEL_MAP_S_TO_S_SIZE 0x0CB1
#define GL_PIXEL_MAP_I_TO_I_SIZE 0x0CB0
#define GL_PIXEL_MAP_I_TO_R_SIZE 0x0CB2
#define GL_PIXEL_MAP_I_TO_G_SIZE 0x0CB3
#define GL_PIXEL_MAP_I_TO_B_SIZE 0x0CB4
#define GL_PIXEL_MAP_I_TO_A_SIZE 0x0CB5
#define GL_PIXEL_MAP_R_TO_R_SIZE 0x0CB6
#define GL_PIXEL_MAP_G_TO_G_SIZE 0x0CB7
#define GL_PIXEL_MAP_B_TO_B_SIZE 0x0CB8
#define GL_PIXEL_MAP_A_TO_A_SIZE 0x0CB9
#define GL_PIXEL_MAP_S_TO_S 0x0C71
#define GL_PIXEL_MAP_I_TO_I 0x0C70
#define GL_PIXEL_MAP_I_TO_R 0x0C72
#define GL_PIXEL_MAP_I_TO_G 0x0C73
#define GL_PIXEL_MAP_I_TO_B 0x0C74
#define GL_PIXEL_MAP_I_TO_A 0x0C75
#define GL_PIXEL_MAP_R_TO_R 0x0C76
#define GL_PIXEL_MAP_G_TO_G 0x0C77
#define GL_PIXEL_MAP_B_TO_B 0x0C78
#define GL_PIXEL_MAP_A_TO_A 0x0C79
#define GL_PACK_ALIGNMENT 0x0D05
#define GL_PACK_LSB_FIRST 0x0D01
#define GL_PACK_ROW_LENGTH 0x0D02
#define GL_PACK_SKIP_PIXELS 0x0D04
#define GL_PACK_SKIP_ROWS 0x0D03
#define GL_PACK_SWAP_BYTES 0x0D00
#define GL_UNPACK_ALIGNMENT 0x0CF5
#define GL_UNPACK_LSB_FIRST 0x0CF1
#define GL_UNPACK_ROW_LENGTH 0x0CF2
#define GL_UNPACK_SKIP_PIXELS 0x0CF4
#define GL_UNPACK_SKIP_ROWS 0x0CF3
#define GL_UNPACK_SWAP_BYTES 0x0CF0
#define GL_ZOOM_X 0x0D16
#define GL_ZOOM_Y 0x0D17
#define GL_TEXTURE_ENV 0x2300
#define GL_TEXTURE_ENV_MODE 0x2200
#define GL_TEXTURE_1D 0x0DE0
#define GL_TEXTURE_2D 0x0DE1
#define GL_TEXTURE_WRAP_S 0x2802
#define GL_TEXTURE_WRAP_T 0x2803
#define GL_TEXTURE_MAG_FILTER 0x2800
#define GL_TEXTURE_MIN_FILTER 0x2801
#define GL_TEXTURE_ENV_COLOR 0x2201
#define GL_TEXTURE_GEN_S 0x0C60
#define GL_TEXTURE_GEN_T 0x0C61
#define GL_TEXTURE_GEN_MODE 0x2500
#define GL_TEXTURE_BORDER_COLOR 0x1004
#define GL_TEXTURE_WIDTH 0x1000
#define GL_TEXTURE_HEIGHT 0x1001
#define GL_TEXTURE_BORDER 0x1005
#define GL_TEXTURE_COMPONENTS 0x1003
#define GL_TEXTURE_RED_SIZE 0x805C
#define GL_TEXTURE_GREEN_SIZE 0x805D
#define GL_TEXTURE_BLUE_SIZE 0x805E
#define GL_TEXTURE_ALPHA_SIZE 0x805F
#define GL_TEXTURE_LUMINANCE_SIZE 0x8060
#define GL_TEXTURE_INTENSITY_SIZE 0x8061
#define GL_NEAREST_MIPMAP_NEAREST 0x2700
#define GL_NEAREST_MIPMAP_LINEAR 0x2702
#define GL_LINEAR_MIPMAP_NEAREST 0x2701
#define GL_LINEAR_MIPMAP_LINEAR 0x2703
#define GL_OBJECT_LINEAR 0x2401
#define GL_OBJECT_PLANE 0x2501
#define GL_EYE_LINEAR 0x2400
#define GL_EYE_PLANE 0x2502
#define GL_SPHERE_MAP 0x2402
#define GL_DECAL 0x2101
#define GL_MODULATE 0x2100
#define GL_NEAREST 0x2600
#define GL_REPEAT 0x2901
#define GL_CLAMP 0x2900
#define GL_S 0x2000
#define GL_T 0x2001
#define GL_R 0x2002
#define GL_Q 0x2003
#define GL_TEXTURE_GEN_R 0x0C62
#define GL_TEXTURE_GEN_Q 0x0C63
#define GL_VENDOR 0x1F00
#define GL_RENDERER 0x1F01
#define GL_VERSION 0x1F02
#define GL_EXTENSIONS 0x1F03
#define GL_NO_ERROR 0x0
#define GL_INVALID_VALUE 0x0501
#define GL_INVALID_ENUM 0x0500
#define GL_INVALID_OPERATION 0x0502
#define GL_STACK_OVERFLOW 0x0503
#define GL_STACK_UNDERFLOW 0x0504
#define GL_OUT_OF_MEMORY 0x0505
#define GL_CURRENT_BIT 0x00000001
#define GL_POINT_BIT 0x00000002
#define GL_LINE_BIT 0x00000004
#define GL_POLYGON_BIT 0x00000008
#define GL_POLYGON_STIPPLE_BIT 0x00000010
#define GL_PIXEL_MODE_BIT 0x00000020
#define GL_LIGHTING_BIT 0x00000040
#define GL_FOG_BIT 0x00000080
#define GL_DEPTH_BUFFER_BIT 0x00000100
#define GL_ACCUM_BUFFER_BIT 0x00000200
#define GL_STENCIL_BUFFER_BIT 0x00000400
#define GL_VIEWPORT_BIT 0x00000800
#define GL_TRANSFORM_BIT 0x00001000
#define GL_ENABLE_BIT 0x00002000
#define GL_COLOR_BUFFER_BIT 0x00004000
#define GL_HINT_BIT 0x00008000
#define GL_EVAL_BIT 0x00010000
#define GL_LIST_BIT 0x00020000
#define GL_TEXTURE_BIT 0x00040000
#define GL_SCISSOR_BIT 0x00080000
#define GL_ALL_ATTRIB_BITS 0x000FFFFF
#define GL_PROXY_TEXTURE_1D 0x8063
#define GL_PROXY_TEXTURE_2D 0x8064
#define GL_TEXTURE_PRIORITY 0x8066
#define GL_TEXTURE_RESIDENT 0x8067
#define GL_TEXTURE_BINDING_1D 0x8068
#define GL_TEXTURE_BINDING_2D 0x8069
#define GL_TEXTURE_INTERNAL_FORMAT 0x1003
#define GL_ALPHA4 0x803B
#define GL_ALPHA8 0x803C
#define GL_ALPHA12 0x803D
#define GL_ALPHA16 0x803E
#define GL_LUMINANCE4 0x803F
#define GL_LUMINANCE8 0x8040
#define GL_LUMINANCE12 0x8041
#define GL_LUMINANCE16 0x8042
#define GL_LUMINANCE4_ALPHA4 0x8043
#define GL_LUMINANCE6_ALPHA2 0x8044
#define GL_LUMINANCE8_ALPHA8 0x8045
#define GL_LUMINANCE12_ALPHA4 0x8046
#define GL_LUMINANCE12_ALPHA12 0x8047
#define GL_LUMINANCE16_ALPHA16 0x8048
#define GL_INTENSITY 0x8049
#define GL_INTENSITY4 0x804A
#define GL_INTENSITY8 0x804B
#define GL_INTENSITY12 0x804C
#define GL_INTENSITY16 0x804D
#define GL_R3_G3_B2 0x2A10
#define GL_RGB4 0x804F
#define GL_RGB5 0x8050
#define GL_RGB8 0x8051
#define GL_RGB10 0x8052
#define GL_RGB12 0x8053
#define GL_RGB16 0x8054
#define GL_RGBA2 0x8055
#define GL_RGBA4 0x8056
#define GL_RGB5_A1 0x8057
#define GL_RGBA8 0x8058
#define GL_RGB10_A2 0x8059
#define GL_RGBA12 0x805A
#define GL_RGBA16 0x805B
#define GL_CLIENT_PIXEL_STORE_BIT 0x00000001
#define GL_CLIENT_VERTEX_ARRAY_BIT 0x00000002
#define GL_ALL_CLIENT_ATTRIB_BITS 0xFFFFFFFF
#define GL_CLIENT_ALL_ATTRIB_BITS 0xFFFFFFFF
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearIndex)(GLfloat c); }
#define glClearIndex DynamicGL_ClearIndex
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearColor)(GLclampf red , GLclampf green , GLclampf blue , GLclampf alpha); }
#define glClearColor DynamicGL_ClearColor
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Clear)(GLbitfield mask); }
#define glClear DynamicGL_Clear
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_IndexMask)(GLuint mask); }
#define glIndexMask DynamicGL_IndexMask
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorMask)(GLboolean red , GLboolean green , GLboolean blue , GLboolean alpha); }
#define glColorMask DynamicGL_ColorMask
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_AlphaFunc)(GLenum func , GLclampf ref); }
#define glAlphaFunc DynamicGL_AlphaFunc
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendFunc)(GLenum sfactor , GLenum dfactor); }
#define glBlendFunc DynamicGL_BlendFunc
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LogicOp)(GLenum opcode); }
#define glLogicOp DynamicGL_LogicOp
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CullFace)(GLenum mode); }
#define glCullFace DynamicGL_CullFace
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FrontFace)(GLenum mode); }
#define glFrontFace DynamicGL_FrontFace
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PointSize)(GLfloat size); }
#define glPointSize DynamicGL_PointSize
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LineWidth)(GLfloat width); }
#define glLineWidth DynamicGL_LineWidth
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LineStipple)(GLint factor , GLushort pattern); }
#define glLineStipple DynamicGL_LineStipple
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PolygonMode)(GLenum face , GLenum mode); }
#define glPolygonMode DynamicGL_PolygonMode
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PolygonOffset)(GLfloat factor , GLfloat units); }
#define glPolygonOffset DynamicGL_PolygonOffset
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PolygonStipple)(const GLubyte *mask); }
#define glPolygonStipple DynamicGL_PolygonStipple
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPolygonStipple)(GLubyte *mask); }
#define glGetPolygonStipple DynamicGL_GetPolygonStipple
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EdgeFlag)(GLboolean flag); }
#define glEdgeFlag DynamicGL_EdgeFlag
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EdgeFlagv)(const GLboolean *flag); }
#define glEdgeFlagv DynamicGL_EdgeFlagv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Scissor)(GLint x , GLint y , GLsizei width , GLsizei height); }
#define glScissor DynamicGL_Scissor
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClipPlane)(GLenum plane , const GLdouble *equation); }
#define glClipPlane DynamicGL_ClipPlane
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetClipPlane)(GLenum plane , GLdouble *equation); }
#define glGetClipPlane DynamicGL_GetClipPlane
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawBuffer)(GLenum mode); }
#define glDrawBuffer DynamicGL_DrawBuffer
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ReadBuffer)(GLenum mode); }
#define glReadBuffer DynamicGL_ReadBuffer
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Enable)(GLenum cap); }
#define glEnable DynamicGL_Enable
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Disable)(GLenum cap); }
#define glDisable DynamicGL_Disable
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsEnabled)(GLenum cap); }
#define glIsEnabled DynamicGL_IsEnabled
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EnableClientState)(GLenum cap); }
#define glEnableClientState DynamicGL_EnableClientState
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DisableClientState)(GLenum cap); }
#define glDisableClientState DynamicGL_DisableClientState
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetBooleanv)(GLenum pname , GLboolean *params); }
#define glGetBooleanv DynamicGL_GetBooleanv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetDoublev)(GLenum pname , GLdouble *params); }
#define glGetDoublev DynamicGL_GetDoublev
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFloatv)(GLenum pname , GLfloat *params); }
#define glGetFloatv DynamicGL_GetFloatv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetIntegerv)(GLenum pname , GLint *params); }
#define glGetIntegerv DynamicGL_GetIntegerv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PushAttrib)(GLbitfield mask); }
#define glPushAttrib DynamicGL_PushAttrib
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PopAttrib)(); }
#define glPopAttrib DynamicGL_PopAttrib
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PushClientAttrib)(GLbitfield mask); }
#define glPushClientAttrib DynamicGL_PushClientAttrib
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PopClientAttrib)(); }
#define glPopClientAttrib DynamicGL_PopClientAttrib
extern "C" { extern GLint (DYNAMIC_GL_APIENTRYP DynamicGL_RenderMode)(GLenum mode); }
#define glRenderMode DynamicGL_RenderMode
extern "C" { extern GLenum (DYNAMIC_GL_APIENTRYP DynamicGL_GetError)(); }
#define glGetError DynamicGL_GetError
extern "C" { extern GLubyte* (DYNAMIC_GL_APIENTRYP DynamicGL_GetString)(GLenum name); }
#define glGetString DynamicGL_GetString
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Finish)(); }
#define glFinish DynamicGL_Finish
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Flush)(); }
#define glFlush DynamicGL_Flush
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Hint)(GLenum target , GLenum mode); }
#define glHint DynamicGL_Hint
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearDepth)(GLclampd depth); }
#define glClearDepth DynamicGL_ClearDepth
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DepthFunc)(GLenum func); }
#define glDepthFunc DynamicGL_DepthFunc
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DepthMask)(GLboolean flag); }
#define glDepthMask DynamicGL_DepthMask
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DepthRange)(GLclampd near_val , GLclampd far_val); }
#define glDepthRange DynamicGL_DepthRange
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearAccum)(GLfloat red , GLfloat green , GLfloat blue , GLfloat alpha); }
#define glClearAccum DynamicGL_ClearAccum
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Accum)(GLenum op , GLfloat value); }
#define glAccum DynamicGL_Accum
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixMode)(GLenum mode); }
#define glMatrixMode DynamicGL_MatrixMode
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Ortho)(GLdouble left , GLdouble right , GLdouble bottom , GLdouble top , GLdouble near_val , GLdouble far_val); }
#define glOrtho DynamicGL_Ortho
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Frustum)(GLdouble left , GLdouble right , GLdouble bottom , GLdouble top , GLdouble near_val , GLdouble far_val); }
#define glFrustum DynamicGL_Frustum
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Viewport)(GLint x , GLint y , GLsizei width , GLsizei height); }
#define glViewport DynamicGL_Viewport
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PushMatrix)(); }
#define glPushMatrix DynamicGL_PushMatrix
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PopMatrix)(); }
#define glPopMatrix DynamicGL_PopMatrix
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LoadIdentity)(); }
#define glLoadIdentity DynamicGL_LoadIdentity
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LoadMatrixd)(const GLdouble *m); }
#define glLoadMatrixd DynamicGL_LoadMatrixd
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LoadMatrixf)(const GLfloat *m); }
#define glLoadMatrixf DynamicGL_LoadMatrixf
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultMatrixd)(const GLdouble *m); }
#define glMultMatrixd DynamicGL_MultMatrixd
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultMatrixf)(const GLfloat *m); }
#define glMultMatrixf DynamicGL_MultMatrixf
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Rotated)(GLdouble angle , GLdouble x , GLdouble y , GLdouble z); }
#define glRotated DynamicGL_Rotated
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Rotatef)(GLfloat angle , GLfloat x , GLfloat y , GLfloat z); }
#define glRotatef DynamicGL_Rotatef
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Scaled)(GLdouble x , GLdouble y , GLdouble z); }
#define glScaled DynamicGL_Scaled
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Scalef)(GLfloat x , GLfloat y , GLfloat z); }
#define glScalef DynamicGL_Scalef
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Translated)(GLdouble x , GLdouble y , GLdouble z); }
#define glTranslated DynamicGL_Translated
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Translatef)(GLfloat x , GLfloat y , GLfloat z); }
#define glTranslatef DynamicGL_Translatef
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsList)(GLuint list); }
#define glIsList DynamicGL_IsList
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteLists)(GLuint list , GLsizei range); }
#define glDeleteLists DynamicGL_DeleteLists
extern "C" { extern GLuint (DYNAMIC_GL_APIENTRYP DynamicGL_GenLists)(GLsizei range); }
#define glGenLists DynamicGL_GenLists
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NewList)(GLuint list , GLenum mode); }
#define glNewList DynamicGL_NewList
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EndList)(); }
#define glEndList DynamicGL_EndList
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CallList)(GLuint list); }
#define glCallList DynamicGL_CallList
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CallLists)(GLsizei n , GLenum type , const GLvoid *lists); }
#define glCallLists DynamicGL_CallLists
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ListBase)(GLuint base); }
#define glListBase DynamicGL_ListBase
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Begin)(GLenum mode); }
#define glBegin DynamicGL_Begin
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_End)(); }
#define glEnd DynamicGL_End
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex2d)(GLdouble x , GLdouble y); }
#define glVertex2d DynamicGL_Vertex2d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex2f)(GLfloat x , GLfloat y); }
#define glVertex2f DynamicGL_Vertex2f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex2i)(GLint x , GLint y); }
#define glVertex2i DynamicGL_Vertex2i
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex2s)(GLshort x , GLshort y); }
#define glVertex2s DynamicGL_Vertex2s
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex3d)(GLdouble x , GLdouble y , GLdouble z); }
#define glVertex3d DynamicGL_Vertex3d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex3f)(GLfloat x , GLfloat y , GLfloat z); }
#define glVertex3f DynamicGL_Vertex3f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex3i)(GLint x , GLint y , GLint z); }
#define glVertex3i DynamicGL_Vertex3i
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex3s)(GLshort x , GLshort y , GLshort z); }
#define glVertex3s DynamicGL_Vertex3s
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex4d)(GLdouble x , GLdouble y , GLdouble z , GLdouble w); }
#define glVertex4d DynamicGL_Vertex4d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex4f)(GLfloat x , GLfloat y , GLfloat z , GLfloat w); }
#define glVertex4f DynamicGL_Vertex4f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex4i)(GLint x , GLint y , GLint z , GLint w); }
#define glVertex4i DynamicGL_Vertex4i
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex4s)(GLshort x , GLshort y , GLshort z , GLshort w); }
#define glVertex4s DynamicGL_Vertex4s
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex2dv)(const GLdouble *v); }
#define glVertex2dv DynamicGL_Vertex2dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex2fv)(const GLfloat *v); }
#define glVertex2fv DynamicGL_Vertex2fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex2iv)(const GLint *v); }
#define glVertex2iv DynamicGL_Vertex2iv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex2sv)(const GLshort *v); }
#define glVertex2sv DynamicGL_Vertex2sv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex3dv)(const GLdouble *v); }
#define glVertex3dv DynamicGL_Vertex3dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex3fv)(const GLfloat *v); }
#define glVertex3fv DynamicGL_Vertex3fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex3iv)(const GLint *v); }
#define glVertex3iv DynamicGL_Vertex3iv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex3sv)(const GLshort *v); }
#define glVertex3sv DynamicGL_Vertex3sv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex4dv)(const GLdouble *v); }
#define glVertex4dv DynamicGL_Vertex4dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex4fv)(const GLfloat *v); }
#define glVertex4fv DynamicGL_Vertex4fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex4iv)(const GLint *v); }
#define glVertex4iv DynamicGL_Vertex4iv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex4sv)(const GLshort *v); }
#define glVertex4sv DynamicGL_Vertex4sv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Normal3b)(GLbyte nx , GLbyte ny , GLbyte nz); }
#define glNormal3b DynamicGL_Normal3b
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Normal3d)(GLdouble nx , GLdouble ny , GLdouble nz); }
#define glNormal3d DynamicGL_Normal3d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Normal3f)(GLfloat nx , GLfloat ny , GLfloat nz); }
#define glNormal3f DynamicGL_Normal3f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Normal3i)(GLint nx , GLint ny , GLint nz); }
#define glNormal3i DynamicGL_Normal3i
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Normal3s)(GLshort nx , GLshort ny , GLshort nz); }
#define glNormal3s DynamicGL_Normal3s
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Normal3bv)(const GLbyte *v); }
#define glNormal3bv DynamicGL_Normal3bv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Normal3dv)(const GLdouble *v); }
#define glNormal3dv DynamicGL_Normal3dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Normal3fv)(const GLfloat *v); }
#define glNormal3fv DynamicGL_Normal3fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Normal3iv)(const GLint *v); }
#define glNormal3iv DynamicGL_Normal3iv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Normal3sv)(const GLshort *v); }
#define glNormal3sv DynamicGL_Normal3sv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Indexd)(GLdouble c); }
#define glIndexd DynamicGL_Indexd
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Indexf)(GLfloat c); }
#define glIndexf DynamicGL_Indexf
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Indexi)(GLint c); }
#define glIndexi DynamicGL_Indexi
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Indexs)(GLshort c); }
#define glIndexs DynamicGL_Indexs
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Indexub)(GLubyte c); }
#define glIndexub DynamicGL_Indexub
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Indexdv)(const GLdouble *c); }
#define glIndexdv DynamicGL_Indexdv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Indexfv)(const GLfloat *c); }
#define glIndexfv DynamicGL_Indexfv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Indexiv)(const GLint *c); }
#define glIndexiv DynamicGL_Indexiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Indexsv)(const GLshort *c); }
#define glIndexsv DynamicGL_Indexsv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Indexubv)(const GLubyte *c); }
#define glIndexubv DynamicGL_Indexubv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3b)(GLbyte red , GLbyte green , GLbyte blue); }
#define glColor3b DynamicGL_Color3b
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3d)(GLdouble red , GLdouble green , GLdouble blue); }
#define glColor3d DynamicGL_Color3d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3f)(GLfloat red , GLfloat green , GLfloat blue); }
#define glColor3f DynamicGL_Color3f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3i)(GLint red , GLint green , GLint blue); }
#define glColor3i DynamicGL_Color3i
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3s)(GLshort red , GLshort green , GLshort blue); }
#define glColor3s DynamicGL_Color3s
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3ub)(GLubyte red , GLubyte green , GLubyte blue); }
#define glColor3ub DynamicGL_Color3ub
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3ui)(GLuint red , GLuint green , GLuint blue); }
#define glColor3ui DynamicGL_Color3ui
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3us)(GLushort red , GLushort green , GLushort blue); }
#define glColor3us DynamicGL_Color3us
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4b)(GLbyte red , GLbyte green , GLbyte blue , GLbyte alpha); }
#define glColor4b DynamicGL_Color4b
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4d)(GLdouble red , GLdouble green , GLdouble blue , GLdouble alpha); }
#define glColor4d DynamicGL_Color4d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4f)(GLfloat red , GLfloat green , GLfloat blue , GLfloat alpha); }
#define glColor4f DynamicGL_Color4f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4i)(GLint red , GLint green , GLint blue , GLint alpha); }
#define glColor4i DynamicGL_Color4i
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4s)(GLshort red , GLshort green , GLshort blue , GLshort alpha); }
#define glColor4s DynamicGL_Color4s
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4ub)(GLubyte red , GLubyte green , GLubyte blue , GLubyte alpha); }
#define glColor4ub DynamicGL_Color4ub
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4ui)(GLuint red , GLuint green , GLuint blue , GLuint alpha); }
#define glColor4ui DynamicGL_Color4ui
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4us)(GLushort red , GLushort green , GLushort blue , GLushort alpha); }
#define glColor4us DynamicGL_Color4us
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3bv)(const GLbyte *v); }
#define glColor3bv DynamicGL_Color3bv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3dv)(const GLdouble *v); }
#define glColor3dv DynamicGL_Color3dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3fv)(const GLfloat *v); }
#define glColor3fv DynamicGL_Color3fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3iv)(const GLint *v); }
#define glColor3iv DynamicGL_Color3iv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3sv)(const GLshort *v); }
#define glColor3sv DynamicGL_Color3sv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3ubv)(const GLubyte *v); }
#define glColor3ubv DynamicGL_Color3ubv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3uiv)(const GLuint *v); }
#define glColor3uiv DynamicGL_Color3uiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3usv)(const GLushort *v); }
#define glColor3usv DynamicGL_Color3usv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4bv)(const GLbyte *v); }
#define glColor4bv DynamicGL_Color4bv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4dv)(const GLdouble *v); }
#define glColor4dv DynamicGL_Color4dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4fv)(const GLfloat *v); }
#define glColor4fv DynamicGL_Color4fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4iv)(const GLint *v); }
#define glColor4iv DynamicGL_Color4iv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4sv)(const GLshort *v); }
#define glColor4sv DynamicGL_Color4sv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4ubv)(const GLubyte *v); }
#define glColor4ubv DynamicGL_Color4ubv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4uiv)(const GLuint *v); }
#define glColor4uiv DynamicGL_Color4uiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4usv)(const GLushort *v); }
#define glColor4usv DynamicGL_Color4usv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord1d)(GLdouble s); }
#define glTexCoord1d DynamicGL_TexCoord1d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord1f)(GLfloat s); }
#define glTexCoord1f DynamicGL_TexCoord1f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord1i)(GLint s); }
#define glTexCoord1i DynamicGL_TexCoord1i
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord1s)(GLshort s); }
#define glTexCoord1s DynamicGL_TexCoord1s
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2d)(GLdouble s , GLdouble t); }
#define glTexCoord2d DynamicGL_TexCoord2d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2f)(GLfloat s , GLfloat t); }
#define glTexCoord2f DynamicGL_TexCoord2f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2i)(GLint s , GLint t); }
#define glTexCoord2i DynamicGL_TexCoord2i
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2s)(GLshort s , GLshort t); }
#define glTexCoord2s DynamicGL_TexCoord2s
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord3d)(GLdouble s , GLdouble t , GLdouble r); }
#define glTexCoord3d DynamicGL_TexCoord3d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord3f)(GLfloat s , GLfloat t , GLfloat r); }
#define glTexCoord3f DynamicGL_TexCoord3f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord3i)(GLint s , GLint t , GLint r); }
#define glTexCoord3i DynamicGL_TexCoord3i
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord3s)(GLshort s , GLshort t , GLshort r); }
#define glTexCoord3s DynamicGL_TexCoord3s
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord4d)(GLdouble s , GLdouble t , GLdouble r , GLdouble q); }
#define glTexCoord4d DynamicGL_TexCoord4d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord4f)(GLfloat s , GLfloat t , GLfloat r , GLfloat q); }
#define glTexCoord4f DynamicGL_TexCoord4f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord4i)(GLint s , GLint t , GLint r , GLint q); }
#define glTexCoord4i DynamicGL_TexCoord4i
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord4s)(GLshort s , GLshort t , GLshort r , GLshort q); }
#define glTexCoord4s DynamicGL_TexCoord4s
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord1dv)(const GLdouble *v); }
#define glTexCoord1dv DynamicGL_TexCoord1dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord1fv)(const GLfloat *v); }
#define glTexCoord1fv DynamicGL_TexCoord1fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord1iv)(const GLint *v); }
#define glTexCoord1iv DynamicGL_TexCoord1iv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord1sv)(const GLshort *v); }
#define glTexCoord1sv DynamicGL_TexCoord1sv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2dv)(const GLdouble *v); }
#define glTexCoord2dv DynamicGL_TexCoord2dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2fv)(const GLfloat *v); }
#define glTexCoord2fv DynamicGL_TexCoord2fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2iv)(const GLint *v); }
#define glTexCoord2iv DynamicGL_TexCoord2iv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2sv)(const GLshort *v); }
#define glTexCoord2sv DynamicGL_TexCoord2sv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord3dv)(const GLdouble *v); }
#define glTexCoord3dv DynamicGL_TexCoord3dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord3fv)(const GLfloat *v); }
#define glTexCoord3fv DynamicGL_TexCoord3fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord3iv)(const GLint *v); }
#define glTexCoord3iv DynamicGL_TexCoord3iv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord3sv)(const GLshort *v); }
#define glTexCoord3sv DynamicGL_TexCoord3sv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord4dv)(const GLdouble *v); }
#define glTexCoord4dv DynamicGL_TexCoord4dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord4fv)(const GLfloat *v); }
#define glTexCoord4fv DynamicGL_TexCoord4fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord4iv)(const GLint *v); }
#define glTexCoord4iv DynamicGL_TexCoord4iv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord4sv)(const GLshort *v); }
#define glTexCoord4sv DynamicGL_TexCoord4sv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos2d)(GLdouble x , GLdouble y); }
#define glRasterPos2d DynamicGL_RasterPos2d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos2f)(GLfloat x , GLfloat y); }
#define glRasterPos2f DynamicGL_RasterPos2f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos2i)(GLint x , GLint y); }
#define glRasterPos2i DynamicGL_RasterPos2i
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos2s)(GLshort x , GLshort y); }
#define glRasterPos2s DynamicGL_RasterPos2s
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos3d)(GLdouble x , GLdouble y , GLdouble z); }
#define glRasterPos3d DynamicGL_RasterPos3d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos3f)(GLfloat x , GLfloat y , GLfloat z); }
#define glRasterPos3f DynamicGL_RasterPos3f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos3i)(GLint x , GLint y , GLint z); }
#define glRasterPos3i DynamicGL_RasterPos3i
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos3s)(GLshort x , GLshort y , GLshort z); }
#define glRasterPos3s DynamicGL_RasterPos3s
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos4d)(GLdouble x , GLdouble y , GLdouble z , GLdouble w); }
#define glRasterPos4d DynamicGL_RasterPos4d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos4f)(GLfloat x , GLfloat y , GLfloat z , GLfloat w); }
#define glRasterPos4f DynamicGL_RasterPos4f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos4i)(GLint x , GLint y , GLint z , GLint w); }
#define glRasterPos4i DynamicGL_RasterPos4i
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos4s)(GLshort x , GLshort y , GLshort z , GLshort w); }
#define glRasterPos4s DynamicGL_RasterPos4s
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos2dv)(const GLdouble *v); }
#define glRasterPos2dv DynamicGL_RasterPos2dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos2fv)(const GLfloat *v); }
#define glRasterPos2fv DynamicGL_RasterPos2fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos2iv)(const GLint *v); }
#define glRasterPos2iv DynamicGL_RasterPos2iv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos2sv)(const GLshort *v); }
#define glRasterPos2sv DynamicGL_RasterPos2sv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos3dv)(const GLdouble *v); }
#define glRasterPos3dv DynamicGL_RasterPos3dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos3fv)(const GLfloat *v); }
#define glRasterPos3fv DynamicGL_RasterPos3fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos3iv)(const GLint *v); }
#define glRasterPos3iv DynamicGL_RasterPos3iv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos3sv)(const GLshort *v); }
#define glRasterPos3sv DynamicGL_RasterPos3sv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos4dv)(const GLdouble *v); }
#define glRasterPos4dv DynamicGL_RasterPos4dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos4fv)(const GLfloat *v); }
#define glRasterPos4fv DynamicGL_RasterPos4fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos4iv)(const GLint *v); }
#define glRasterPos4iv DynamicGL_RasterPos4iv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RasterPos4sv)(const GLshort *v); }
#define glRasterPos4sv DynamicGL_RasterPos4sv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Rectd)(GLdouble x1 , GLdouble y1 , GLdouble x2 , GLdouble y2); }
#define glRectd DynamicGL_Rectd
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Rectf)(GLfloat x1 , GLfloat y1 , GLfloat x2 , GLfloat y2); }
#define glRectf DynamicGL_Rectf
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Recti)(GLint x1 , GLint y1 , GLint x2 , GLint y2); }
#define glRecti DynamicGL_Recti
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Rects)(GLshort x1 , GLshort y1 , GLshort x2 , GLshort y2); }
#define glRects DynamicGL_Rects
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Rectdv)(const GLdouble *v1 , const GLdouble *v2); }
#define glRectdv DynamicGL_Rectdv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Rectfv)(const GLfloat *v1 , const GLfloat *v2); }
#define glRectfv DynamicGL_Rectfv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Rectiv)(const GLint *v1 , const GLint *v2); }
#define glRectiv DynamicGL_Rectiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Rectsv)(const GLshort *v1 , const GLshort *v2); }
#define glRectsv DynamicGL_Rectsv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ShadeModel)(GLenum mode); }
#define glShadeModel DynamicGL_ShadeModel
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Lightf)(GLenum light , GLenum pname , GLfloat param); }
#define glLightf DynamicGL_Lightf
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Lighti)(GLenum light , GLenum pname , GLint param); }
#define glLighti DynamicGL_Lighti
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Lightfv)(GLenum light , GLenum pname , const GLfloat *params); }
#define glLightfv DynamicGL_Lightfv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Lightiv)(GLenum light , GLenum pname , const GLint *params); }
#define glLightiv DynamicGL_Lightiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetLightfv)(GLenum light , GLenum pname , GLfloat *params); }
#define glGetLightfv DynamicGL_GetLightfv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetLightiv)(GLenum light , GLenum pname , GLint *params); }
#define glGetLightiv DynamicGL_GetLightiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LightModelf)(GLenum pname , GLfloat param); }
#define glLightModelf DynamicGL_LightModelf
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LightModeli)(GLenum pname , GLint param); }
#define glLightModeli DynamicGL_LightModeli
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LightModelfv)(GLenum pname , const GLfloat *params); }
#define glLightModelfv DynamicGL_LightModelfv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LightModeliv)(GLenum pname , const GLint *params); }
#define glLightModeliv DynamicGL_LightModeliv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Materialf)(GLenum face , GLenum pname , GLfloat param); }
#define glMaterialf DynamicGL_Materialf
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Materiali)(GLenum face , GLenum pname , GLint param); }
#define glMateriali DynamicGL_Materiali
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Materialfv)(GLenum face , GLenum pname , const GLfloat *params); }
#define glMaterialfv DynamicGL_Materialfv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Materialiv)(GLenum face , GLenum pname , const GLint *params); }
#define glMaterialiv DynamicGL_Materialiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMaterialfv)(GLenum face , GLenum pname , GLfloat *params); }
#define glGetMaterialfv DynamicGL_GetMaterialfv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMaterialiv)(GLenum face , GLenum pname , GLint *params); }
#define glGetMaterialiv DynamicGL_GetMaterialiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorMaterial)(GLenum face , GLenum mode); }
#define glColorMaterial DynamicGL_ColorMaterial
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelZoom)(GLfloat xfactor , GLfloat yfactor); }
#define glPixelZoom DynamicGL_PixelZoom
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelStoref)(GLenum pname , GLfloat param); }
#define glPixelStoref DynamicGL_PixelStoref
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelStorei)(GLenum pname , GLint param); }
#define glPixelStorei DynamicGL_PixelStorei
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelTransferf)(GLenum pname , GLfloat param); }
#define glPixelTransferf DynamicGL_PixelTransferf
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelTransferi)(GLenum pname , GLint param); }
#define glPixelTransferi DynamicGL_PixelTransferi
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelMapfv)(GLenum map , GLint mapsize , const GLfloat *values); }
#define glPixelMapfv DynamicGL_PixelMapfv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelMapuiv)(GLenum map , GLint mapsize , const GLuint *values); }
#define glPixelMapuiv DynamicGL_PixelMapuiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelMapusv)(GLenum map , GLint mapsize , const GLushort *values); }
#define glPixelMapusv DynamicGL_PixelMapusv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPixelMapfv)(GLenum map , GLfloat *values); }
#define glGetPixelMapfv DynamicGL_GetPixelMapfv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPixelMapuiv)(GLenum map , GLuint *values); }
#define glGetPixelMapuiv DynamicGL_GetPixelMapuiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPixelMapusv)(GLenum map , GLushort *values); }
#define glGetPixelMapusv DynamicGL_GetPixelMapusv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Bitmap)(GLsizei width , GLsizei height , GLfloat xorig , GLfloat yorig , GLfloat xmove , GLfloat ymove , const GLubyte *bitmap); }
#define glBitmap DynamicGL_Bitmap
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ReadPixels)(GLint x , GLint y , GLsizei width , GLsizei height , GLenum format , GLenum type , GLvoid *pixels); }
#define glReadPixels DynamicGL_ReadPixels
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawPixels)(GLsizei width , GLsizei height , GLenum format , GLenum type , const GLvoid *pixels); }
#define glDrawPixels DynamicGL_DrawPixels
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyPixels)(GLint x , GLint y , GLsizei width , GLsizei height , GLenum type); }
#define glCopyPixels DynamicGL_CopyPixels
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_StencilFunc)(GLenum func , GLint ref , GLuint mask); }
#define glStencilFunc DynamicGL_StencilFunc
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_StencilMask)(GLuint mask); }
#define glStencilMask DynamicGL_StencilMask
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_StencilOp)(GLenum fail , GLenum zfail , GLenum zpass); }
#define glStencilOp DynamicGL_StencilOp
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearStencil)(GLint s); }
#define glClearStencil DynamicGL_ClearStencil
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexGend)(GLenum coord , GLenum pname , GLdouble param); }
#define glTexGend DynamicGL_TexGend
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexGenf)(GLenum coord , GLenum pname , GLfloat param); }
#define glTexGenf DynamicGL_TexGenf
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexGeni)(GLenum coord , GLenum pname , GLint param); }
#define glTexGeni DynamicGL_TexGeni
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexGendv)(GLenum coord , GLenum pname , const GLdouble *params); }
#define glTexGendv DynamicGL_TexGendv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexGenfv)(GLenum coord , GLenum pname , const GLfloat *params); }
#define glTexGenfv DynamicGL_TexGenfv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexGeniv)(GLenum coord , GLenum pname , const GLint *params); }
#define glTexGeniv DynamicGL_TexGeniv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexGendv)(GLenum coord , GLenum pname , GLdouble *params); }
#define glGetTexGendv DynamicGL_GetTexGendv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexGenfv)(GLenum coord , GLenum pname , GLfloat *params); }
#define glGetTexGenfv DynamicGL_GetTexGenfv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexGeniv)(GLenum coord , GLenum pname , GLint *params); }
#define glGetTexGeniv DynamicGL_GetTexGeniv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexEnvf)(GLenum target , GLenum pname , GLfloat param); }
#define glTexEnvf DynamicGL_TexEnvf
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexEnvi)(GLenum target , GLenum pname , GLint param); }
#define glTexEnvi DynamicGL_TexEnvi
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexEnvfv)(GLenum target , GLenum pname , const GLfloat *params); }
#define glTexEnvfv DynamicGL_TexEnvfv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexEnviv)(GLenum target , GLenum pname , const GLint *params); }
#define glTexEnviv DynamicGL_TexEnviv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexEnvfv)(GLenum target , GLenum pname , GLfloat *params); }
#define glGetTexEnvfv DynamicGL_GetTexEnvfv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexEnviv)(GLenum target , GLenum pname , GLint *params); }
#define glGetTexEnviv DynamicGL_GetTexEnviv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexParameterf)(GLenum target , GLenum pname , GLfloat param); }
#define glTexParameterf DynamicGL_TexParameterf
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexParameteri)(GLenum target , GLenum pname , GLint param); }
#define glTexParameteri DynamicGL_TexParameteri
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexParameterfv)(GLenum target , GLenum pname , const GLfloat *params); }
#define glTexParameterfv DynamicGL_TexParameterfv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexParameteriv)(GLenum target , GLenum pname , const GLint *params); }
#define glTexParameteriv DynamicGL_TexParameteriv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexParameterfv)(GLenum target , GLenum pname , GLfloat *params); }
#define glGetTexParameterfv DynamicGL_GetTexParameterfv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexParameteriv)(GLenum target , GLenum pname , GLint *params); }
#define glGetTexParameteriv DynamicGL_GetTexParameteriv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexLevelParameterfv)(GLenum target , GLint level , GLenum pname , GLfloat *params); }
#define glGetTexLevelParameterfv DynamicGL_GetTexLevelParameterfv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexLevelParameteriv)(GLenum target , GLint level , GLenum pname , GLint *params); }
#define glGetTexLevelParameteriv DynamicGL_GetTexLevelParameteriv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexImage1D)(GLenum target , GLint level , GLint internalFormat , GLsizei width , GLint border , GLenum format , GLenum type , const GLvoid *pixels); }
#define glTexImage1D DynamicGL_TexImage1D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexImage2D)(GLenum target , GLint level , GLint internalFormat , GLsizei width , GLsizei height , GLint border , GLenum format , GLenum type , const GLvoid *pixels); }
#define glTexImage2D DynamicGL_TexImage2D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexImage)(GLenum target , GLint level , GLenum format , GLenum type , GLvoid *pixels); }
#define glGetTexImage DynamicGL_GetTexImage
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Map1d)(GLenum target , GLdouble u1 , GLdouble u2 , GLint stride , GLint order , const GLdouble *points); }
#define glMap1d DynamicGL_Map1d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Map1f)(GLenum target , GLfloat u1 , GLfloat u2 , GLint stride , GLint order , const GLfloat *points); }
#define glMap1f DynamicGL_Map1f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Map2d)(GLenum target , GLdouble u1 , GLdouble u2 , GLint ustride , GLint uorder , GLdouble v1 , GLdouble v2 , GLint vstride , GLint vorder , const GLdouble *points); }
#define glMap2d DynamicGL_Map2d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Map2f)(GLenum target , GLfloat u1 , GLfloat u2 , GLint ustride , GLint uorder , GLfloat v1 , GLfloat v2 , GLint vstride , GLint vorder , const GLfloat *points); }
#define glMap2f DynamicGL_Map2f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMapdv)(GLenum target , GLenum query , GLdouble *v); }
#define glGetMapdv DynamicGL_GetMapdv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMapfv)(GLenum target , GLenum query , GLfloat *v); }
#define glGetMapfv DynamicGL_GetMapfv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMapiv)(GLenum target , GLenum query , GLint *v); }
#define glGetMapiv DynamicGL_GetMapiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EvalCoord1d)(GLdouble u); }
#define glEvalCoord1d DynamicGL_EvalCoord1d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EvalCoord1f)(GLfloat u); }
#define glEvalCoord1f DynamicGL_EvalCoord1f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EvalCoord1dv)(const GLdouble *u); }
#define glEvalCoord1dv DynamicGL_EvalCoord1dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EvalCoord1fv)(const GLfloat *u); }
#define glEvalCoord1fv DynamicGL_EvalCoord1fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EvalCoord2d)(GLdouble u , GLdouble v); }
#define glEvalCoord2d DynamicGL_EvalCoord2d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EvalCoord2f)(GLfloat u , GLfloat v); }
#define glEvalCoord2f DynamicGL_EvalCoord2f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EvalCoord2dv)(const GLdouble *u); }
#define glEvalCoord2dv DynamicGL_EvalCoord2dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EvalCoord2fv)(const GLfloat *u); }
#define glEvalCoord2fv DynamicGL_EvalCoord2fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MapGrid1d)(GLint un , GLdouble u1 , GLdouble u2); }
#define glMapGrid1d DynamicGL_MapGrid1d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MapGrid1f)(GLint un , GLfloat u1 , GLfloat u2); }
#define glMapGrid1f DynamicGL_MapGrid1f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MapGrid2d)(GLint un , GLdouble u1 , GLdouble u2 , GLint vn , GLdouble v1 , GLdouble v2); }
#define glMapGrid2d DynamicGL_MapGrid2d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MapGrid2f)(GLint un , GLfloat u1 , GLfloat u2 , GLint vn , GLfloat v1 , GLfloat v2); }
#define glMapGrid2f DynamicGL_MapGrid2f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EvalPoint1)(GLint i); }
#define glEvalPoint1 DynamicGL_EvalPoint1
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EvalPoint2)(GLint i , GLint j); }
#define glEvalPoint2 DynamicGL_EvalPoint2
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EvalMesh1)(GLenum mode , GLint i1 , GLint i2); }
#define glEvalMesh1 DynamicGL_EvalMesh1
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EvalMesh2)(GLenum mode , GLint i1 , GLint i2 , GLint j1 , GLint j2); }
#define glEvalMesh2 DynamicGL_EvalMesh2
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Fogf)(GLenum pname , GLfloat param); }
#define glFogf DynamicGL_Fogf
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Fogi)(GLenum pname , GLint param); }
#define glFogi DynamicGL_Fogi
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Fogfv)(GLenum pname , const GLfloat *params); }
#define glFogfv DynamicGL_Fogfv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Fogiv)(GLenum pname , const GLint *params); }
#define glFogiv DynamicGL_Fogiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FeedbackBuffer)(GLsizei size , GLenum type , GLfloat *buffer); }
#define glFeedbackBuffer DynamicGL_FeedbackBuffer
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PassThrough)(GLfloat token); }
#define glPassThrough DynamicGL_PassThrough
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SelectBuffer)(GLsizei size , GLuint *buffer); }
#define glSelectBuffer DynamicGL_SelectBuffer
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_InitNames)(); }
#define glInitNames DynamicGL_InitNames
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LoadName)(GLuint name); }
#define glLoadName DynamicGL_LoadName
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PushName)(GLuint name); }
#define glPushName DynamicGL_PushName
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PopName)(); }
#define glPopName DynamicGL_PopName
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GenTextures)(GLsizei n , GLuint *textures); }
#define glGenTextures DynamicGL_GenTextures
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteTextures)(GLsizei n , const GLuint *textures); }
#define glDeleteTextures DynamicGL_DeleteTextures
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindTexture)(GLenum target , GLuint texture); }
#define glBindTexture DynamicGL_BindTexture
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PrioritizeTextures)(GLsizei n , const GLuint *textures , const GLclampf *priorities); }
#define glPrioritizeTextures DynamicGL_PrioritizeTextures
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_AreTexturesResident)(GLsizei n , const GLuint *textures , GLboolean *residences); }
#define glAreTexturesResident DynamicGL_AreTexturesResident
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsTexture)(GLuint texture); }
#define glIsTexture DynamicGL_IsTexture
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexSubImage1D)(GLenum target , GLint level , GLint xoffset , GLsizei width , GLenum format , GLenum type , const GLvoid *pixels); }
#define glTexSubImage1D DynamicGL_TexSubImage1D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexSubImage2D)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLsizei width , GLsizei height , GLenum format , GLenum type , const GLvoid *pixels); }
#define glTexSubImage2D DynamicGL_TexSubImage2D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyTexImage1D)(GLenum target , GLint level , GLenum internalformat , GLint x , GLint y , GLsizei width , GLint border); }
#define glCopyTexImage1D DynamicGL_CopyTexImage1D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyTexImage2D)(GLenum target , GLint level , GLenum internalformat , GLint x , GLint y , GLsizei width , GLsizei height , GLint border); }
#define glCopyTexImage2D DynamicGL_CopyTexImage2D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyTexSubImage1D)(GLenum target , GLint level , GLint xoffset , GLint x , GLint y , GLsizei width); }
#define glCopyTexSubImage1D DynamicGL_CopyTexSubImage1D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyTexSubImage2D)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint x , GLint y , GLsizei width , GLsizei height); }
#define glCopyTexSubImage2D DynamicGL_CopyTexSubImage2D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexPointer)(GLint size , GLenum type , GLsizei stride , const GLvoid *ptr); }
#define glVertexPointer DynamicGL_VertexPointer
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NormalPointer)(GLenum type , GLsizei stride , const GLvoid *ptr); }
#define glNormalPointer DynamicGL_NormalPointer
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorPointer)(GLint size , GLenum type , GLsizei stride , const GLvoid *ptr); }
#define glColorPointer DynamicGL_ColorPointer
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_IndexPointer)(GLenum type , GLsizei stride , const GLvoid *ptr); }
#define glIndexPointer DynamicGL_IndexPointer
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoordPointer)(GLint size , GLenum type , GLsizei stride , const GLvoid *ptr); }
#define glTexCoordPointer DynamicGL_TexCoordPointer
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EdgeFlagPointer)(GLsizei stride , const GLvoid *ptr); }
#define glEdgeFlagPointer DynamicGL_EdgeFlagPointer
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPointerv)(GLenum pname , GLvoid *p1); }
#define glGetPointerv DynamicGL_GetPointerv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ArrayElement)(GLint i); }
#define glArrayElement DynamicGL_ArrayElement
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawArrays)(GLenum mode , GLint first , GLsizei count); }
#define glDrawArrays DynamicGL_DrawArrays
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawElements)(GLenum mode , GLsizei count , GLenum type , const GLvoid *indices); }
#define glDrawElements DynamicGL_DrawElements
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_InterleavedArrays)(GLenum format , GLsizei stride , const GLvoid *pointer); }
#define glInterleavedArrays DynamicGL_InterleavedArrays
extern bool DinamicGLFeature_VERSION_1_1_Supported();
#endif /*USE_DYNAMIC_GL_VERSION_1_1*/

/*ARB_copy_buffer*/
#ifdef USE_DYNAMIC_GL_ARB_copy_buffer
#define GL_COPY_READ_BUFFER_BINDING 0x8F36
#define GL_COPY_WRITE_BUFFER_BINDING 0x8F37
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyBufferSubData)(GLenum readTarget , GLenum writeTarget , GLintptr readOffset , GLintptr writeOffset , GLsizeiptr size); }
#define glCopyBufferSubData DynamicGL_CopyBufferSubData
extern bool DinamicGLFeature_ARB_copy_buffer_Supported();
#endif /*USE_DYNAMIC_GL_ARB_copy_buffer*/

/*SGIS_sharpen_texture*/
#ifdef USE_DYNAMIC_GL_SGIS_sharpen_texture
#define GL_LINEAR_SHARPEN_SGIS 0x80AD
#define GL_LINEAR_SHARPEN_ALPHA_SGIS 0x80AE
#define GL_LINEAR_SHARPEN_COLOR_SGIS 0x80AF
#define GL_SHARPEN_TEXTURE_FUNC_POINTS_SGIS 0x80B0
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SharpenTexFuncSGIS)(GLenum target , GLsizei n , const GLfloat *points); }
#define glSharpenTexFuncSGIS DynamicGL_SharpenTexFuncSGIS
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetSharpenTexFuncSGIS)(GLenum target , GLfloat *points); }
#define glGetSharpenTexFuncSGIS DynamicGL_GetSharpenTexFuncSGIS
extern bool DinamicGLFeature_SGIS_sharpen_texture_Supported();
#endif /*USE_DYNAMIC_GL_SGIS_sharpen_texture*/

/*ARB_internalformat_query*/
#ifdef USE_DYNAMIC_GL_ARB_internalformat_query
#define GL_NUM_SAMPLE_COUNTS 0x9380
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetInternalformativ)(GLenum target , GLenum internalformat , GLenum pname , GLsizei bufSize , GLint *params); }
#define glGetInternalformativ DynamicGL_GetInternalformativ
extern bool DinamicGLFeature_ARB_internalformat_query_Supported();
#endif /*USE_DYNAMIC_GL_ARB_internalformat_query*/

/*SGIX_blend_alpha_minmax*/
#ifdef USE_DYNAMIC_GL_SGIX_blend_alpha_minmax
#define GL_ALPHA_MIN_SGIX 0x8320
#define GL_ALPHA_MAX_SGIX 0x8321
extern bool DinamicGLFeature_SGIX_blend_alpha_minmax_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_blend_alpha_minmax*/

/*ATI_meminfo*/
#ifdef USE_DYNAMIC_GL_ATI_meminfo
#define GL_VBO_FREE_MEMORY_ATI 0x87FB
#define GL_TEXTURE_FREE_MEMORY_ATI 0x87FC
#define GL_RENDERBUFFER_FREE_MEMORY_ATI 0x87FD
extern bool DinamicGLFeature_ATI_meminfo_Supported();
#endif /*USE_DYNAMIC_GL_ATI_meminfo*/

/*NV_present_video*/
#ifdef USE_DYNAMIC_GL_NV_present_video
#define GL_FRAME_NV 0x8E26
#define GL_FIELDS_NV 0x8E27
#define GL_CURRENT_TIME_NV 0x8E28
#define GL_NUM_FILL_STREAMS_NV 0x8E29
#define GL_PRESENT_TIME_NV 0x8E2A
#define GL_PRESENT_DURATION_NV 0x8E2B
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PresentFrameKeyedNV)(GLuint video_slot , GLuint64EXT minPresentTime , GLuint beginPresentTimeId , GLuint presentDurationId , GLenum type , GLenum target0 , GLuint fill0 , GLuint key0 , GLenum target1 , GLuint fill1 , GLuint key1); }
#define glPresentFrameKeyedNV DynamicGL_PresentFrameKeyedNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PresentFrameDualFillNV)(GLuint video_slot , GLuint64EXT minPresentTime , GLuint beginPresentTimeId , GLuint presentDurationId , GLenum type , GLenum target0 , GLuint fill0 , GLenum target1 , GLuint fill1 , GLenum target2 , GLuint fill2 , GLenum target3 , GLuint fill3); }
#define glPresentFrameDualFillNV DynamicGL_PresentFrameDualFillNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVideoivNV)(GLuint video_slot , GLenum pname , GLint *params); }
#define glGetVideoivNV DynamicGL_GetVideoivNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVideouivNV)(GLuint video_slot , GLenum pname , GLuint *params); }
#define glGetVideouivNV DynamicGL_GetVideouivNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVideoi64vNV)(GLuint video_slot , GLenum pname , GLint64EXT *params); }
#define glGetVideoi64vNV DynamicGL_GetVideoi64vNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVideoui64vNV)(GLuint video_slot , GLenum pname , GLuint64EXT *params); }
#define glGetVideoui64vNV DynamicGL_GetVideoui64vNV
extern bool DinamicGLFeature_NV_present_video_Supported();
#endif /*USE_DYNAMIC_GL_NV_present_video*/

/*SGIX_convolution_accuracy*/
#ifdef USE_DYNAMIC_GL_SGIX_convolution_accuracy
#define GL_CONVOLUTION_HINT_SGIX 0x8316
extern bool DinamicGLFeature_SGIX_convolution_accuracy_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_convolution_accuracy*/

/*EXT_bindable_uniform*/
#ifdef USE_DYNAMIC_GL_EXT_bindable_uniform
#define GL_MAX_VERTEX_BINDABLE_UNIFORMS_EXT 0x8DE2
#define GL_MAX_FRAGMENT_BINDABLE_UNIFORMS_EXT 0x8DE3
#define GL_MAX_GEOMETRY_BINDABLE_UNIFORMS_EXT 0x8DE4
#define GL_MAX_BINDABLE_UNIFORM_SIZE_EXT 0x8DED
#define GL_UNIFORM_BUFFER_EXT 0x8DEE
#define GL_UNIFORM_BUFFER_BINDING_EXT 0x8DEF
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformBufferEXT)(GLuint program , GLint location , GLuint buffer); }
#define glUniformBufferEXT DynamicGL_UniformBufferEXT
extern "C" { extern GLint (DYNAMIC_GL_APIENTRYP DynamicGL_GetUniformBufferSizeEXT)(GLuint program , GLint location); }
#define glGetUniformBufferSizeEXT DynamicGL_GetUniformBufferSizeEXT
extern "C" { extern GLintptr (DYNAMIC_GL_APIENTRYP DynamicGL_GetUniformOffsetEXT)(GLuint program , GLint location); }
#define glGetUniformOffsetEXT DynamicGL_GetUniformOffsetEXT
extern bool DinamicGLFeature_EXT_bindable_uniform_Supported();
#endif /*USE_DYNAMIC_GL_EXT_bindable_uniform*/

/*SGIS_generate_mipmap*/
#ifdef USE_DYNAMIC_GL_SGIS_generate_mipmap
#define GL_GENERATE_MIPMAP_SGIS 0x8191
#define GL_GENERATE_MIPMAP_HINT_SGIS 0x8192
extern bool DinamicGLFeature_SGIS_generate_mipmap_Supported();
#endif /*USE_DYNAMIC_GL_SGIS_generate_mipmap*/

/*INTEL_parallel_arrays*/
#ifdef USE_DYNAMIC_GL_INTEL_parallel_arrays
#define GL_PARALLEL_ARRAYS_INTEL 0x83F4
#define GL_VERTEX_ARRAY_PARALLEL_POINTERS_INTEL 0x83F5
#define GL_NORMAL_ARRAY_PARALLEL_POINTERS_INTEL 0x83F6
#define GL_COLOR_ARRAY_PARALLEL_POINTERS_INTEL 0x83F7
#define GL_TEXTURE_COORD_ARRAY_PARALLEL_POINTERS_INTEL 0x83F8
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexPointervINTEL)(GLint size , GLenum type , const GLvoid* *pointer); }
#define glVertexPointervINTEL DynamicGL_VertexPointervINTEL
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NormalPointervINTEL)(GLenum type , const GLvoid* *pointer); }
#define glNormalPointervINTEL DynamicGL_NormalPointervINTEL
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorPointervINTEL)(GLint size , GLenum type , const GLvoid* *pointer); }
#define glColorPointervINTEL DynamicGL_ColorPointervINTEL
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoordPointervINTEL)(GLint size , GLenum type , const GLvoid* *pointer); }
#define glTexCoordPointervINTEL DynamicGL_TexCoordPointervINTEL
extern bool DinamicGLFeature_INTEL_parallel_arrays_Supported();
#endif /*USE_DYNAMIC_GL_INTEL_parallel_arrays*/

/*ARB_multitexture*/
#ifdef USE_DYNAMIC_GL_ARB_multitexture
#define GL_TEXTURE0_ARB 0x84C0
#define GL_TEXTURE1_ARB 0x84C1
#define GL_TEXTURE2_ARB 0x84C2
#define GL_TEXTURE3_ARB 0x84C3
#define GL_TEXTURE4_ARB 0x84C4
#define GL_TEXTURE5_ARB 0x84C5
#define GL_TEXTURE6_ARB 0x84C6
#define GL_TEXTURE7_ARB 0x84C7
#define GL_TEXTURE8_ARB 0x84C8
#define GL_TEXTURE9_ARB 0x84C9
#define GL_TEXTURE10_ARB 0x84CA
#define GL_TEXTURE11_ARB 0x84CB
#define GL_TEXTURE12_ARB 0x84CC
#define GL_TEXTURE13_ARB 0x84CD
#define GL_TEXTURE14_ARB 0x84CE
#define GL_TEXTURE15_ARB 0x84CF
#define GL_TEXTURE16_ARB 0x84D0
#define GL_TEXTURE17_ARB 0x84D1
#define GL_TEXTURE18_ARB 0x84D2
#define GL_TEXTURE19_ARB 0x84D3
#define GL_TEXTURE20_ARB 0x84D4
#define GL_TEXTURE21_ARB 0x84D5
#define GL_TEXTURE22_ARB 0x84D6
#define GL_TEXTURE23_ARB 0x84D7
#define GL_TEXTURE24_ARB 0x84D8
#define GL_TEXTURE25_ARB 0x84D9
#define GL_TEXTURE26_ARB 0x84DA
#define GL_TEXTURE27_ARB 0x84DB
#define GL_TEXTURE28_ARB 0x84DC
#define GL_TEXTURE29_ARB 0x84DD
#define GL_TEXTURE30_ARB 0x84DE
#define GL_TEXTURE31_ARB 0x84DF
#define GL_ACTIVE_TEXTURE_ARB 0x84E0
#define GL_CLIENT_ACTIVE_TEXTURE_ARB 0x84E1
#define GL_MAX_TEXTURE_UNITS_ARB 0x84E2
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ActiveTextureARB)(GLenum texture); }
#define glActiveTextureARB DynamicGL_ActiveTextureARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClientActiveTextureARB)(GLenum texture); }
#define glClientActiveTextureARB DynamicGL_ClientActiveTextureARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1dARB)(GLenum target , GLdouble s); }
#define glMultiTexCoord1dARB DynamicGL_MultiTexCoord1dARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1dvARB)(GLenum target , const GLdouble *v); }
#define glMultiTexCoord1dvARB DynamicGL_MultiTexCoord1dvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1fARB)(GLenum target , GLfloat s); }
#define glMultiTexCoord1fARB DynamicGL_MultiTexCoord1fARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1fvARB)(GLenum target , const GLfloat *v); }
#define glMultiTexCoord1fvARB DynamicGL_MultiTexCoord1fvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1iARB)(GLenum target , GLint s); }
#define glMultiTexCoord1iARB DynamicGL_MultiTexCoord1iARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1ivARB)(GLenum target , const GLint *v); }
#define glMultiTexCoord1ivARB DynamicGL_MultiTexCoord1ivARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1sARB)(GLenum target , GLshort s); }
#define glMultiTexCoord1sARB DynamicGL_MultiTexCoord1sARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1svARB)(GLenum target , const GLshort *v); }
#define glMultiTexCoord1svARB DynamicGL_MultiTexCoord1svARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2dARB)(GLenum target , GLdouble s , GLdouble t); }
#define glMultiTexCoord2dARB DynamicGL_MultiTexCoord2dARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2dvARB)(GLenum target , const GLdouble *v); }
#define glMultiTexCoord2dvARB DynamicGL_MultiTexCoord2dvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2fARB)(GLenum target , GLfloat s , GLfloat t); }
#define glMultiTexCoord2fARB DynamicGL_MultiTexCoord2fARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2fvARB)(GLenum target , const GLfloat *v); }
#define glMultiTexCoord2fvARB DynamicGL_MultiTexCoord2fvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2iARB)(GLenum target , GLint s , GLint t); }
#define glMultiTexCoord2iARB DynamicGL_MultiTexCoord2iARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2ivARB)(GLenum target , const GLint *v); }
#define glMultiTexCoord2ivARB DynamicGL_MultiTexCoord2ivARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2sARB)(GLenum target , GLshort s , GLshort t); }
#define glMultiTexCoord2sARB DynamicGL_MultiTexCoord2sARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2svARB)(GLenum target , const GLshort *v); }
#define glMultiTexCoord2svARB DynamicGL_MultiTexCoord2svARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3dARB)(GLenum target , GLdouble s , GLdouble t , GLdouble r); }
#define glMultiTexCoord3dARB DynamicGL_MultiTexCoord3dARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3dvARB)(GLenum target , const GLdouble *v); }
#define glMultiTexCoord3dvARB DynamicGL_MultiTexCoord3dvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3fARB)(GLenum target , GLfloat s , GLfloat t , GLfloat r); }
#define glMultiTexCoord3fARB DynamicGL_MultiTexCoord3fARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3fvARB)(GLenum target , const GLfloat *v); }
#define glMultiTexCoord3fvARB DynamicGL_MultiTexCoord3fvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3iARB)(GLenum target , GLint s , GLint t , GLint r); }
#define glMultiTexCoord3iARB DynamicGL_MultiTexCoord3iARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3ivARB)(GLenum target , const GLint *v); }
#define glMultiTexCoord3ivARB DynamicGL_MultiTexCoord3ivARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3sARB)(GLenum target , GLshort s , GLshort t , GLshort r); }
#define glMultiTexCoord3sARB DynamicGL_MultiTexCoord3sARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3svARB)(GLenum target , const GLshort *v); }
#define glMultiTexCoord3svARB DynamicGL_MultiTexCoord3svARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4dARB)(GLenum target , GLdouble s , GLdouble t , GLdouble r , GLdouble q); }
#define glMultiTexCoord4dARB DynamicGL_MultiTexCoord4dARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4dvARB)(GLenum target , const GLdouble *v); }
#define glMultiTexCoord4dvARB DynamicGL_MultiTexCoord4dvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4fARB)(GLenum target , GLfloat s , GLfloat t , GLfloat r , GLfloat q); }
#define glMultiTexCoord4fARB DynamicGL_MultiTexCoord4fARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4fvARB)(GLenum target , const GLfloat *v); }
#define glMultiTexCoord4fvARB DynamicGL_MultiTexCoord4fvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4iARB)(GLenum target , GLint s , GLint t , GLint r , GLint q); }
#define glMultiTexCoord4iARB DynamicGL_MultiTexCoord4iARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4ivARB)(GLenum target , const GLint *v); }
#define glMultiTexCoord4ivARB DynamicGL_MultiTexCoord4ivARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4sARB)(GLenum target , GLshort s , GLshort t , GLshort r , GLshort q); }
#define glMultiTexCoord4sARB DynamicGL_MultiTexCoord4sARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4svARB)(GLenum target , const GLshort *v); }
#define glMultiTexCoord4svARB DynamicGL_MultiTexCoord4svARB
extern bool DinamicGLFeature_ARB_multitexture_Supported();
#endif /*USE_DYNAMIC_GL_ARB_multitexture*/

/*EXT_draw_range_elements*/
#ifdef USE_DYNAMIC_GL_EXT_draw_range_elements
#define GL_MAX_ELEMENTS_VERTICES_EXT 0x80E8
#define GL_MAX_ELEMENTS_INDICES_EXT 0x80E9
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawRangeElementsEXT)(GLenum mode , GLuint start , GLuint end , GLsizei count , GLenum type , const GLvoid *indices); }
#define glDrawRangeElementsEXT DynamicGL_DrawRangeElementsEXT
extern bool DinamicGLFeature_EXT_draw_range_elements_Supported();
#endif /*USE_DYNAMIC_GL_EXT_draw_range_elements*/

/*ARB_shading_language_include*/
#ifdef USE_DYNAMIC_GL_ARB_shading_language_include
#define GL_SHADER_INCLUDE_ARB 0x8DAE
#define GL_NAMED_STRING_LENGTH_ARB 0x8DE9
#define GL_NAMED_STRING_TYPE_ARB 0x8DEA
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedStringARB)(GLenum type , GLint namelen , const GLchar *name , GLint stringlen , const GLchar *string); }
#define glNamedStringARB DynamicGL_NamedStringARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteNamedStringARB)(GLint namelen , const GLchar *name); }
#define glDeleteNamedStringARB DynamicGL_DeleteNamedStringARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CompileShaderIncludeARB)(GLuint shader , GLsizei count , const GLchar* *path , const GLint *length); }
#define glCompileShaderIncludeARB DynamicGL_CompileShaderIncludeARB
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsNamedStringARB)(GLint namelen , const GLchar *name); }
#define glIsNamedStringARB DynamicGL_IsNamedStringARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetNamedStringARB)(GLint namelen , const GLchar *name , GLsizei bufSize , GLint *stringlen , GLchar *string); }
#define glGetNamedStringARB DynamicGL_GetNamedStringARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetNamedStringivARB)(GLint namelen , const GLchar *name , GLenum pname , GLint *params); }
#define glGetNamedStringivARB DynamicGL_GetNamedStringivARB
extern bool DinamicGLFeature_ARB_shading_language_include_Supported();
#endif /*USE_DYNAMIC_GL_ARB_shading_language_include*/

/*NV_evaluators*/
#ifdef USE_DYNAMIC_GL_NV_evaluators
#define GL_EVAL_2D_NV 0x86C0
#define GL_EVAL_TRIANGULAR_2D_NV 0x86C1
#define GL_MAP_TESSELLATION_NV 0x86C2
#define GL_MAP_ATTRIB_U_ORDER_NV 0x86C3
#define GL_MAP_ATTRIB_V_ORDER_NV 0x86C4
#define GL_EVAL_FRACTIONAL_TESSELLATION_NV 0x86C5
#define GL_EVAL_VERTEX_ATTRIB0_NV 0x86C6
#define GL_EVAL_VERTEX_ATTRIB1_NV 0x86C7
#define GL_EVAL_VERTEX_ATTRIB2_NV 0x86C8
#define GL_EVAL_VERTEX_ATTRIB3_NV 0x86C9
#define GL_EVAL_VERTEX_ATTRIB4_NV 0x86CA
#define GL_EVAL_VERTEX_ATTRIB5_NV 0x86CB
#define GL_EVAL_VERTEX_ATTRIB6_NV 0x86CC
#define GL_EVAL_VERTEX_ATTRIB7_NV 0x86CD
#define GL_EVAL_VERTEX_ATTRIB8_NV 0x86CE
#define GL_EVAL_VERTEX_ATTRIB9_NV 0x86CF
#define GL_EVAL_VERTEX_ATTRIB10_NV 0x86D0
#define GL_EVAL_VERTEX_ATTRIB11_NV 0x86D1
#define GL_EVAL_VERTEX_ATTRIB12_NV 0x86D2
#define GL_EVAL_VERTEX_ATTRIB13_NV 0x86D3
#define GL_EVAL_VERTEX_ATTRIB14_NV 0x86D4
#define GL_EVAL_VERTEX_ATTRIB15_NV 0x86D5
#define GL_MAX_MAP_TESSELLATION_NV 0x86D6
#define GL_MAX_RATIONAL_EVAL_ORDER_NV 0x86D7
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MapControlPointsNV)(GLenum target , GLuint index , GLenum type , GLsizei ustride , GLsizei vstride , GLint uorder , GLint vorder , GLboolean packed , const GLvoid *points); }
#define glMapControlPointsNV DynamicGL_MapControlPointsNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MapParameterivNV)(GLenum target , GLenum pname , const GLint *params); }
#define glMapParameterivNV DynamicGL_MapParameterivNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MapParameterfvNV)(GLenum target , GLenum pname , const GLfloat *params); }
#define glMapParameterfvNV DynamicGL_MapParameterfvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMapControlPointsNV)(GLenum target , GLuint index , GLenum type , GLsizei ustride , GLsizei vstride , GLboolean packed , GLvoid *points); }
#define glGetMapControlPointsNV DynamicGL_GetMapControlPointsNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMapParameterivNV)(GLenum target , GLenum pname , GLint *params); }
#define glGetMapParameterivNV DynamicGL_GetMapParameterivNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMapParameterfvNV)(GLenum target , GLenum pname , GLfloat *params); }
#define glGetMapParameterfvNV DynamicGL_GetMapParameterfvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMapAttribParameterivNV)(GLenum target , GLuint index , GLenum pname , GLint *params); }
#define glGetMapAttribParameterivNV DynamicGL_GetMapAttribParameterivNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMapAttribParameterfvNV)(GLenum target , GLuint index , GLenum pname , GLfloat *params); }
#define glGetMapAttribParameterfvNV DynamicGL_GetMapAttribParameterfvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EvalMapsNV)(GLenum target , GLenum mode); }
#define glEvalMapsNV DynamicGL_EvalMapsNV
extern bool DinamicGLFeature_NV_evaluators_Supported();
#endif /*USE_DYNAMIC_GL_NV_evaluators*/

/*AMD_sample_positions*/
#ifdef USE_DYNAMIC_GL_AMD_sample_positions
#define GL_SUBSAMPLE_DISTANCE_AMD 0x883F
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SetMultisamplefvAMD)(GLenum pname , GLuint index , const GLfloat *val); }
#define glSetMultisamplefvAMD DynamicGL_SetMultisamplefvAMD
extern bool DinamicGLFeature_AMD_sample_positions_Supported();
#endif /*USE_DYNAMIC_GL_AMD_sample_positions*/

/*OML_interlace*/
#ifdef USE_DYNAMIC_GL_OML_interlace
#define GL_INTERLACE_OML 0x8980
#define GL_INTERLACE_READ_OML 0x8981
extern bool DinamicGLFeature_OML_interlace_Supported();
#endif /*USE_DYNAMIC_GL_OML_interlace*/

/*ARB_texture_border_clamp*/
#ifdef USE_DYNAMIC_GL_ARB_texture_border_clamp
#define GL_CLAMP_TO_BORDER_ARB 0x812D
extern bool DinamicGLFeature_ARB_texture_border_clamp_Supported();
#endif /*USE_DYNAMIC_GL_ARB_texture_border_clamp*/

/*APPLE_texture_range*/
#ifdef USE_DYNAMIC_GL_APPLE_texture_range
#define GL_TEXTURE_RANGE_LENGTH_APPLE 0x85B7
#define GL_TEXTURE_RANGE_POINTER_APPLE 0x85B8
#define GL_TEXTURE_STORAGE_HINT_APPLE 0x85BC
#define GL_STORAGE_PRIVATE_APPLE 0x85BD
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureRangeAPPLE)(GLenum target , GLsizei length , const GLvoid *pointer); }
#define glTextureRangeAPPLE DynamicGL_TextureRangeAPPLE
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexParameterPointervAPPLE)(GLenum target , GLenum pname , GLvoid* *params); }
#define glGetTexParameterPointervAPPLE DynamicGL_GetTexParameterPointervAPPLE
extern bool DinamicGLFeature_APPLE_texture_range_Supported();
#endif /*USE_DYNAMIC_GL_APPLE_texture_range*/

/*ARB_shadow_ambient*/
#ifdef USE_DYNAMIC_GL_ARB_shadow_ambient
#define GL_TEXTURE_COMPARE_FAIL_VALUE_ARB 0x80BF
extern bool DinamicGLFeature_ARB_shadow_ambient_Supported();
#endif /*USE_DYNAMIC_GL_ARB_shadow_ambient*/

/*EXT_texture_compression_s3tc*/
#ifdef USE_DYNAMIC_GL_EXT_texture_compression_s3tc
#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT 0x83F0
#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT 0x83F1
#define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT 0x83F2
#define GL_COMPRESSED_RGBA_S3TC_DXT5_EXT 0x83F3
extern bool DinamicGLFeature_EXT_texture_compression_s3tc_Supported();
#endif /*USE_DYNAMIC_GL_EXT_texture_compression_s3tc*/

/*EXT_secondary_color*/
#ifdef USE_DYNAMIC_GL_EXT_secondary_color
#define GL_COLOR_SUM_EXT 0x8458
#define GL_CURRENT_SECONDARY_COLOR_EXT 0x8459
#define GL_SECONDARY_COLOR_ARRAY_SIZE_EXT 0x845A
#define GL_SECONDARY_COLOR_ARRAY_TYPE_EXT 0x845B
#define GL_SECONDARY_COLOR_ARRAY_STRIDE_EXT 0x845C
#define GL_SECONDARY_COLOR_ARRAY_POINTER_EXT 0x845D
#define GL_SECONDARY_COLOR_ARRAY_EXT 0x845E
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3bEXT)(GLbyte red , GLbyte green , GLbyte blue); }
#define glSecondaryColor3bEXT DynamicGL_SecondaryColor3bEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3bvEXT)(const GLbyte *v); }
#define glSecondaryColor3bvEXT DynamicGL_SecondaryColor3bvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3dEXT)(GLdouble red , GLdouble green , GLdouble blue); }
#define glSecondaryColor3dEXT DynamicGL_SecondaryColor3dEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3dvEXT)(const GLdouble *v); }
#define glSecondaryColor3dvEXT DynamicGL_SecondaryColor3dvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3fEXT)(GLfloat red , GLfloat green , GLfloat blue); }
#define glSecondaryColor3fEXT DynamicGL_SecondaryColor3fEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3fvEXT)(const GLfloat *v); }
#define glSecondaryColor3fvEXT DynamicGL_SecondaryColor3fvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3iEXT)(GLint red , GLint green , GLint blue); }
#define glSecondaryColor3iEXT DynamicGL_SecondaryColor3iEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3ivEXT)(const GLint *v); }
#define glSecondaryColor3ivEXT DynamicGL_SecondaryColor3ivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3sEXT)(GLshort red , GLshort green , GLshort blue); }
#define glSecondaryColor3sEXT DynamicGL_SecondaryColor3sEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3svEXT)(const GLshort *v); }
#define glSecondaryColor3svEXT DynamicGL_SecondaryColor3svEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3ubEXT)(GLubyte red , GLubyte green , GLubyte blue); }
#define glSecondaryColor3ubEXT DynamicGL_SecondaryColor3ubEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3ubvEXT)(const GLubyte *v); }
#define glSecondaryColor3ubvEXT DynamicGL_SecondaryColor3ubvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3uiEXT)(GLuint red , GLuint green , GLuint blue); }
#define glSecondaryColor3uiEXT DynamicGL_SecondaryColor3uiEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3uivEXT)(const GLuint *v); }
#define glSecondaryColor3uivEXT DynamicGL_SecondaryColor3uivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3usEXT)(GLushort red , GLushort green , GLushort blue); }
#define glSecondaryColor3usEXT DynamicGL_SecondaryColor3usEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3usvEXT)(const GLushort *v); }
#define glSecondaryColor3usvEXT DynamicGL_SecondaryColor3usvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColorPointerEXT)(GLint size , GLenum type , GLsizei stride , const GLvoid *pointer); }
#define glSecondaryColorPointerEXT DynamicGL_SecondaryColorPointerEXT
extern bool DinamicGLFeature_EXT_secondary_color_Supported();
#endif /*USE_DYNAMIC_GL_EXT_secondary_color*/

/*SGIX_pixel_tiles*/
#ifdef USE_DYNAMIC_GL_SGIX_pixel_tiles
#define GL_PIXEL_TILE_BEST_ALIGNMENT_SGIX 0x813E
#define GL_PIXEL_TILE_CACHE_INCREMENT_SGIX 0x813F
#define GL_PIXEL_TILE_WIDTH_SGIX 0x8140
#define GL_PIXEL_TILE_HEIGHT_SGIX 0x8141
#define GL_PIXEL_TILE_GRID_WIDTH_SGIX 0x8142
#define GL_PIXEL_TILE_GRID_HEIGHT_SGIX 0x8143
#define GL_PIXEL_TILE_GRID_DEPTH_SGIX 0x8144
#define GL_PIXEL_TILE_CACHE_SIZE_SGIX 0x8145
extern bool DinamicGLFeature_SGIX_pixel_tiles_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_pixel_tiles*/

/*SGIX_scalebias_hint*/
#ifdef USE_DYNAMIC_GL_SGIX_scalebias_hint
#define GL_SCALEBIAS_HINT_SGIX 0x8322
extern bool DinamicGLFeature_SGIX_scalebias_hint_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_scalebias_hint*/

/*EXT_texture_buffer_object*/
#ifdef USE_DYNAMIC_GL_EXT_texture_buffer_object
#define GL_TEXTURE_BUFFER_EXT 0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE_EXT 0x8C2B
#define GL_TEXTURE_BINDING_BUFFER_EXT 0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING_EXT 0x8C2D
#define GL_TEXTURE_BUFFER_FORMAT_EXT 0x8C2E
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexBufferEXT)(GLenum target , GLenum internalformat , GLuint buffer); }
#define glTexBufferEXT DynamicGL_TexBufferEXT
extern bool DinamicGLFeature_EXT_texture_buffer_object_Supported();
#endif /*USE_DYNAMIC_GL_EXT_texture_buffer_object*/

/*APPLE_row_bytes*/
#ifdef USE_DYNAMIC_GL_APPLE_row_bytes
#define GL_PACK_ROW_BYTES_APPLE 0x8A15
#define GL_UNPACK_ROW_BYTES_APPLE 0x8A16
extern bool DinamicGLFeature_APPLE_row_bytes_Supported();
#endif /*USE_DYNAMIC_GL_APPLE_row_bytes*/

/*IBM_multimode_draw_arrays*/
#ifdef USE_DYNAMIC_GL_IBM_multimode_draw_arrays
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiModeDrawArraysIBM)(const GLenum *mode , const GLint *first , const GLsizei *count , GLsizei primcount , GLint modestride); }
#define glMultiModeDrawArraysIBM DynamicGL_MultiModeDrawArraysIBM
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiModeDrawElementsIBM)(const GLenum *mode , const GLsizei *count , GLenum type , const GLvoid* const , GLsizei primcount , GLint modestride); }
#define glMultiModeDrawElementsIBM DynamicGL_MultiModeDrawElementsIBM
extern bool DinamicGLFeature_IBM_multimode_draw_arrays_Supported();
#endif /*USE_DYNAMIC_GL_IBM_multimode_draw_arrays*/

/*ARB_draw_elements_base_vertex*/
#ifdef USE_DYNAMIC_GL_ARB_draw_elements_base_vertex
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawElementsBaseVertex)(GLenum mode , GLsizei count , GLenum type , const GLvoid *indices , GLint basevertex); }
#define glDrawElementsBaseVertex DynamicGL_DrawElementsBaseVertex
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawRangeElementsBaseVertex)(GLenum mode , GLuint start , GLuint end , GLsizei count , GLenum type , const GLvoid *indices , GLint basevertex); }
#define glDrawRangeElementsBaseVertex DynamicGL_DrawRangeElementsBaseVertex
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawElementsInstancedBaseVertex)(GLenum mode , GLsizei count , GLenum type , const GLvoid *indices , GLsizei primcount , GLint basevertex); }
#define glDrawElementsInstancedBaseVertex DynamicGL_DrawElementsInstancedBaseVertex
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiDrawElementsBaseVertex)(GLenum mode , const GLsizei *count , GLenum type , const GLvoid* const , GLsizei primcount , const GLint *basevertex); }
#define glMultiDrawElementsBaseVertex DynamicGL_MultiDrawElementsBaseVertex
extern bool DinamicGLFeature_ARB_draw_elements_base_vertex_Supported();
#endif /*USE_DYNAMIC_GL_ARB_draw_elements_base_vertex*/

/*ARB_depth_clamp*/
#ifdef USE_DYNAMIC_GL_ARB_depth_clamp
#define GL_DEPTH_CLAMP 0x864F
extern bool DinamicGLFeature_ARB_depth_clamp_Supported();
#endif /*USE_DYNAMIC_GL_ARB_depth_clamp*/

/*EXT_framebuffer_object*/
#ifdef USE_DYNAMIC_GL_EXT_framebuffer_object
#define GL_INVALID_FRAMEBUFFER_OPERATION_EXT 0x0506
#define GL_MAX_RENDERBUFFER_SIZE_EXT 0x84E8
#define GL_FRAMEBUFFER_BINDING_EXT 0x8CA6
#define GL_RENDERBUFFER_BINDING_EXT 0x8CA7
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE_EXT 0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME_EXT 0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL_EXT 0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE_EXT 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_3D_ZOFFSET_EXT 0x8CD4
#define GL_FRAMEBUFFER_COMPLETE_EXT 0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT_EXT 0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT 0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT 0x8CD9
#define GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT 0x8CDA
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_EXT 0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_EXT 0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED_EXT 0x8CDD
#define GL_MAX_COLOR_ATTACHMENTS_EXT 0x8CDF
#define GL_COLOR_ATTACHMENT0_EXT 0x8CE0
#define GL_COLOR_ATTACHMENT1_EXT 0x8CE1
#define GL_COLOR_ATTACHMENT2_EXT 0x8CE2
#define GL_COLOR_ATTACHMENT3_EXT 0x8CE3
#define GL_COLOR_ATTACHMENT4_EXT 0x8CE4
#define GL_COLOR_ATTACHMENT5_EXT 0x8CE5
#define GL_COLOR_ATTACHMENT6_EXT 0x8CE6
#define GL_COLOR_ATTACHMENT7_EXT 0x8CE7
#define GL_COLOR_ATTACHMENT8_EXT 0x8CE8
#define GL_COLOR_ATTACHMENT9_EXT 0x8CE9
#define GL_COLOR_ATTACHMENT10_EXT 0x8CEA
#define GL_COLOR_ATTACHMENT11_EXT 0x8CEB
#define GL_COLOR_ATTACHMENT12_EXT 0x8CEC
#define GL_COLOR_ATTACHMENT13_EXT 0x8CED
#define GL_COLOR_ATTACHMENT14_EXT 0x8CEE
#define GL_COLOR_ATTACHMENT15_EXT 0x8CEF
#define GL_DEPTH_ATTACHMENT_EXT 0x8D00
#define GL_STENCIL_ATTACHMENT_EXT 0x8D20
#define GL_FRAMEBUFFER_EXT 0x8D40
#define GL_RENDERBUFFER_EXT 0x8D41
#define GL_RENDERBUFFER_WIDTH_EXT 0x8D42
#define GL_RENDERBUFFER_HEIGHT_EXT 0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT_EXT 0x8D44
#define GL_STENCIL_INDEX1_EXT 0x8D46
#define GL_STENCIL_INDEX4_EXT 0x8D47
#define GL_STENCIL_INDEX8_EXT 0x8D48
#define GL_STENCIL_INDEX16_EXT 0x8D49
#define GL_RENDERBUFFER_RED_SIZE_EXT 0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE_EXT 0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE_EXT 0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE_EXT 0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE_EXT 0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE_EXT 0x8D55
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsRenderbufferEXT)(GLuint renderbuffer); }
#define glIsRenderbufferEXT DynamicGL_IsRenderbufferEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindRenderbufferEXT)(GLenum target , GLuint renderbuffer); }
#define glBindRenderbufferEXT DynamicGL_BindRenderbufferEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteRenderbuffersEXT)(GLsizei n , const GLuint *renderbuffers); }
#define glDeleteRenderbuffersEXT DynamicGL_DeleteRenderbuffersEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GenRenderbuffersEXT)(GLsizei n , GLuint *renderbuffers); }
#define glGenRenderbuffersEXT DynamicGL_GenRenderbuffersEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RenderbufferStorageEXT)(GLenum target , GLenum internalformat , GLsizei width , GLsizei height); }
#define glRenderbufferStorageEXT DynamicGL_RenderbufferStorageEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetRenderbufferParameterivEXT)(GLenum target , GLenum pname , GLint *params); }
#define glGetRenderbufferParameterivEXT DynamicGL_GetRenderbufferParameterivEXT
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsFramebufferEXT)(GLuint framebuffer); }
#define glIsFramebufferEXT DynamicGL_IsFramebufferEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindFramebufferEXT)(GLenum target , GLuint framebuffer); }
#define glBindFramebufferEXT DynamicGL_BindFramebufferEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteFramebuffersEXT)(GLsizei n , const GLuint *framebuffers); }
#define glDeleteFramebuffersEXT DynamicGL_DeleteFramebuffersEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GenFramebuffersEXT)(GLsizei n , GLuint *framebuffers); }
#define glGenFramebuffersEXT DynamicGL_GenFramebuffersEXT
extern "C" { extern GLenum (DYNAMIC_GL_APIENTRYP DynamicGL_CheckFramebufferStatusEXT)(GLenum target); }
#define glCheckFramebufferStatusEXT DynamicGL_CheckFramebufferStatusEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferTexture1DEXT)(GLenum target , GLenum attachment , GLenum textarget , GLuint texture , GLint level); }
#define glFramebufferTexture1DEXT DynamicGL_FramebufferTexture1DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferTexture2DEXT)(GLenum target , GLenum attachment , GLenum textarget , GLuint texture , GLint level); }
#define glFramebufferTexture2DEXT DynamicGL_FramebufferTexture2DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferTexture3DEXT)(GLenum target , GLenum attachment , GLenum textarget , GLuint texture , GLint level , GLint zoffset); }
#define glFramebufferTexture3DEXT DynamicGL_FramebufferTexture3DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferRenderbufferEXT)(GLenum target , GLenum attachment , GLenum renderbuffertarget , GLuint renderbuffer); }
#define glFramebufferRenderbufferEXT DynamicGL_FramebufferRenderbufferEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFramebufferAttachmentParameterivEXT)(GLenum target , GLenum attachment , GLenum pname , GLint *params); }
#define glGetFramebufferAttachmentParameterivEXT DynamicGL_GetFramebufferAttachmentParameterivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GenerateMipmapEXT)(GLenum target); }
#define glGenerateMipmapEXT DynamicGL_GenerateMipmapEXT
extern bool DinamicGLFeature_EXT_framebuffer_object_Supported();
#endif /*USE_DYNAMIC_GL_EXT_framebuffer_object*/

/*ARB_draw_buffers*/
#ifdef USE_DYNAMIC_GL_ARB_draw_buffers
#define GL_MAX_DRAW_BUFFERS_ARB 0x8824
#define GL_DRAW_BUFFER0_ARB 0x8825
#define GL_DRAW_BUFFER1_ARB 0x8826
#define GL_DRAW_BUFFER2_ARB 0x8827
#define GL_DRAW_BUFFER3_ARB 0x8828
#define GL_DRAW_BUFFER4_ARB 0x8829
#define GL_DRAW_BUFFER5_ARB 0x882A
#define GL_DRAW_BUFFER6_ARB 0x882B
#define GL_DRAW_BUFFER7_ARB 0x882C
#define GL_DRAW_BUFFER8_ARB 0x882D
#define GL_DRAW_BUFFER9_ARB 0x882E
#define GL_DRAW_BUFFER10_ARB 0x882F
#define GL_DRAW_BUFFER11_ARB 0x8830
#define GL_DRAW_BUFFER12_ARB 0x8831
#define GL_DRAW_BUFFER13_ARB 0x8832
#define GL_DRAW_BUFFER14_ARB 0x8833
#define GL_DRAW_BUFFER15_ARB 0x8834
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawBuffersARB)(GLsizei n , const GLenum *bufs); }
#define glDrawBuffersARB DynamicGL_DrawBuffersARB
extern bool DinamicGLFeature_ARB_draw_buffers_Supported();
#endif /*USE_DYNAMIC_GL_ARB_draw_buffers*/

/*EXT_pixel_transform*/
#ifdef USE_DYNAMIC_GL_EXT_pixel_transform
#define GL_PIXEL_TRANSFORM_2D_EXT 0x8330
#define GL_PIXEL_MAG_FILTER_EXT 0x8331
#define GL_PIXEL_MIN_FILTER_EXT 0x8332
#define GL_PIXEL_CUBIC_WEIGHT_EXT 0x8333
#define GL_CUBIC_EXT 0x8334
#define GL_AVERAGE_EXT 0x8335
#define GL_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT 0x8336
#define GL_MAX_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT 0x8337
#define GL_PIXEL_TRANSFORM_2D_MATRIX_EXT 0x8338
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelTransformParameteriEXT)(GLenum target , GLenum pname , GLint param); }
#define glPixelTransformParameteriEXT DynamicGL_PixelTransformParameteriEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelTransformParameterfEXT)(GLenum target , GLenum pname , GLfloat param); }
#define glPixelTransformParameterfEXT DynamicGL_PixelTransformParameterfEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelTransformParameterivEXT)(GLenum target , GLenum pname , const GLint *params); }
#define glPixelTransformParameterivEXT DynamicGL_PixelTransformParameterivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelTransformParameterfvEXT)(GLenum target , GLenum pname , const GLfloat *params); }
#define glPixelTransformParameterfvEXT DynamicGL_PixelTransformParameterfvEXT
extern bool DinamicGLFeature_EXT_pixel_transform_Supported();
#endif /*USE_DYNAMIC_GL_EXT_pixel_transform*/

/*ARB_sample_shading*/
#ifdef USE_DYNAMIC_GL_ARB_sample_shading
#define GL_SAMPLE_SHADING_ARB 0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE_ARB 0x8C37
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MinSampleShadingARB)(GLfloat value); }
#define glMinSampleShadingARB DynamicGL_MinSampleShadingARB
extern bool DinamicGLFeature_ARB_sample_shading_Supported();
#endif /*USE_DYNAMIC_GL_ARB_sample_shading*/

/*APPLE_object_purgeable*/
#ifdef USE_DYNAMIC_GL_APPLE_object_purgeable
#define GL_BUFFER_OBJECT_APPLE 0x85B3
#define GL_RELEASED_APPLE 0x8A19
#define GL_VOLATILE_APPLE 0x8A1A
#define GL_RETAINED_APPLE 0x8A1B
#define GL_UNDEFINED_APPLE 0x8A1C
#define GL_PURGEABLE_APPLE 0x8A1D
extern "C" { extern GLenum (DYNAMIC_GL_APIENTRYP DynamicGL_ObjectPurgeableAPPLE)(GLenum objectType , GLuint name , GLenum option); }
#define glObjectPurgeableAPPLE DynamicGL_ObjectPurgeableAPPLE
extern "C" { extern GLenum (DYNAMIC_GL_APIENTRYP DynamicGL_ObjectUnpurgeableAPPLE)(GLenum objectType , GLuint name , GLenum option); }
#define glObjectUnpurgeableAPPLE DynamicGL_ObjectUnpurgeableAPPLE
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetObjectParameterivAPPLE)(GLenum objectType , GLuint name , GLenum pname , GLint *params); }
#define glGetObjectParameterivAPPLE DynamicGL_GetObjectParameterivAPPLE
extern bool DinamicGLFeature_APPLE_object_purgeable_Supported();
#endif /*USE_DYNAMIC_GL_APPLE_object_purgeable*/

/*EXT_index_material*/
#ifdef USE_DYNAMIC_GL_EXT_index_material
#define GL_INDEX_MATERIAL_EXT 0x81B8
#define GL_INDEX_MATERIAL_PARAMETER_EXT 0x81B9
#define GL_INDEX_MATERIAL_FACE_EXT 0x81BA
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_IndexMaterialEXT)(GLenum face , GLenum mode); }
#define glIndexMaterialEXT DynamicGL_IndexMaterialEXT
extern bool DinamicGLFeature_EXT_index_material_Supported();
#endif /*USE_DYNAMIC_GL_EXT_index_material*/

/*SGIS_texture_filter4*/
#ifdef USE_DYNAMIC_GL_SGIS_texture_filter4
#define GL_FILTER4_SGIS 0x8146
#define GL_TEXTURE_FILTER4_SIZE_SGIS 0x8147
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexFilterFuncSGIS)(GLenum target , GLenum filter , GLfloat *weights); }
#define glGetTexFilterFuncSGIS DynamicGL_GetTexFilterFuncSGIS
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexFilterFuncSGIS)(GLenum target , GLenum filter , GLsizei n , const GLfloat *weights); }
#define glTexFilterFuncSGIS DynamicGL_TexFilterFuncSGIS
extern bool DinamicGLFeature_SGIS_texture_filter4_Supported();
#endif /*USE_DYNAMIC_GL_SGIS_texture_filter4*/

/*EXT_framebuffer_multisample_blit_scaled*/
#ifdef USE_DYNAMIC_GL_EXT_framebuffer_multisample_blit_scaled
#define GL_SCALED_RESOLVE_FASTEST_EXT 0x90BA
#define GL_SCALED_RESOLVE_NICEST_EXT 0x90BB
extern bool DinamicGLFeature_EXT_framebuffer_multisample_blit_scaled_Supported();
#endif /*USE_DYNAMIC_GL_EXT_framebuffer_multisample_blit_scaled*/

/*ARB_texture_compression_bptc*/
#ifdef USE_DYNAMIC_GL_ARB_texture_compression_bptc
#define GL_COMPRESSED_RGBA_BPTC_UNORM_ARB 0x8E8C
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB 0x8E8D
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB 0x8E8E
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB 0x8E8F
extern bool DinamicGLFeature_ARB_texture_compression_bptc_Supported();
#endif /*USE_DYNAMIC_GL_ARB_texture_compression_bptc*/

/*APPLE_flush_buffer_range*/
#ifdef USE_DYNAMIC_GL_APPLE_flush_buffer_range
#define GL_BUFFER_SERIALIZED_MODIFY_APPLE 0x8A12
#define GL_BUFFER_FLUSHING_UNMAP_APPLE 0x8A13
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BufferParameteriAPPLE)(GLenum target , GLenum pname , GLint param); }
#define glBufferParameteriAPPLE DynamicGL_BufferParameteriAPPLE
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FlushMappedBufferRangeAPPLE)(GLenum target , GLintptr offset , GLsizeiptr size); }
#define glFlushMappedBufferRangeAPPLE DynamicGL_FlushMappedBufferRangeAPPLE
extern bool DinamicGLFeature_APPLE_flush_buffer_range_Supported();
#endif /*USE_DYNAMIC_GL_APPLE_flush_buffer_range*/

/*SGIS_texture_color_mask*/
#ifdef USE_DYNAMIC_GL_SGIS_texture_color_mask
#define GL_TEXTURE_COLOR_WRITEMASK_SGIS 0x81EF
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureColorMaskSGIS)(GLboolean red , GLboolean green , GLboolean blue , GLboolean alpha); }
#define glTextureColorMaskSGIS DynamicGL_TextureColorMaskSGIS
extern bool DinamicGLFeature_SGIS_texture_color_mask_Supported();
#endif /*USE_DYNAMIC_GL_SGIS_texture_color_mask*/

/*EXT_provoking_vertex*/
#ifdef USE_DYNAMIC_GL_EXT_provoking_vertex
#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION_EXT 0x8E4C
#define GL_FIRST_VERTEX_CONVENTION_EXT 0x8E4D
#define GL_LAST_VERTEX_CONVENTION_EXT 0x8E4E
#define GL_PROVOKING_VERTEX_EXT 0x8E4F
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProvokingVertexEXT)(GLenum mode); }
#define glProvokingVertexEXT DynamicGL_ProvokingVertexEXT
extern bool DinamicGLFeature_EXT_provoking_vertex_Supported();
#endif /*USE_DYNAMIC_GL_EXT_provoking_vertex*/

/*ARB_fragment_shader*/
#ifdef USE_DYNAMIC_GL_ARB_fragment_shader
#define GL_FRAGMENT_SHADER_ARB 0x8B30
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB 0x8B49
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT_ARB 0x8B8B
extern bool DinamicGLFeature_ARB_fragment_shader_Supported();
#endif /*USE_DYNAMIC_GL_ARB_fragment_shader*/

/*GREMEDY_frame_terminator*/
#ifdef USE_DYNAMIC_GL_GREMEDY_frame_terminator
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FrameTerminatorGREMEDY)(); }
#define glFrameTerminatorGREMEDY DynamicGL_FrameTerminatorGREMEDY
extern bool DinamicGLFeature_GREMEDY_frame_terminator_Supported();
#endif /*USE_DYNAMIC_GL_GREMEDY_frame_terminator*/

/*ARB_robustness*/
#ifdef USE_DYNAMIC_GL_ARB_robustness
#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB 0x00000004
#define GL_LOSE_CONTEXT_ON_RESET_ARB 0x8252
#define GL_GUILTY_CONTEXT_RESET_ARB 0x8253
#define GL_INNOCENT_CONTEXT_RESET_ARB 0x8254
#define GL_UNKNOWN_CONTEXT_RESET_ARB 0x8255
#define GL_RESET_NOTIFICATION_STRATEGY_ARB 0x8256
#define GL_NO_RESET_NOTIFICATION_ARB 0x8261
extern "C" { extern GLenum (DYNAMIC_GL_APIENTRYP DynamicGL_GetGraphicsResetStatusARB)(); }
#define glGetGraphicsResetStatusARB DynamicGL_GetGraphicsResetStatusARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetnMapdvARB)(GLenum target , GLenum query , GLsizei bufSize , GLdouble *v); }
#define glGetnMapdvARB DynamicGL_GetnMapdvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetnMapfvARB)(GLenum target , GLenum query , GLsizei bufSize , GLfloat *v); }
#define glGetnMapfvARB DynamicGL_GetnMapfvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetnMapivARB)(GLenum target , GLenum query , GLsizei bufSize , GLint *v); }
#define glGetnMapivARB DynamicGL_GetnMapivARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetnPixelMapfvARB)(GLenum map , GLsizei bufSize , GLfloat *values); }
#define glGetnPixelMapfvARB DynamicGL_GetnPixelMapfvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetnPixelMapuivARB)(GLenum map , GLsizei bufSize , GLuint *values); }
#define glGetnPixelMapuivARB DynamicGL_GetnPixelMapuivARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetnPixelMapusvARB)(GLenum map , GLsizei bufSize , GLushort *values); }
#define glGetnPixelMapusvARB DynamicGL_GetnPixelMapusvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetnPolygonStippleARB)(GLsizei bufSize , GLubyte *pattern); }
#define glGetnPolygonStippleARB DynamicGL_GetnPolygonStippleARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetnColorTableARB)(GLenum target , GLenum format , GLenum type , GLsizei bufSize , GLvoid *table); }
#define glGetnColorTableARB DynamicGL_GetnColorTableARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetnConvolutionFilterARB)(GLenum target , GLenum format , GLenum type , GLsizei bufSize , GLvoid *image); }
#define glGetnConvolutionFilterARB DynamicGL_GetnConvolutionFilterARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetnSeparableFilterARB)(GLenum target , GLenum format , GLenum type , GLsizei rowBufSize , GLvoid *row , GLsizei columnBufSize , GLvoid *column , GLvoid *span); }
#define glGetnSeparableFilterARB DynamicGL_GetnSeparableFilterARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetnHistogramARB)(GLenum target , GLboolean reset , GLenum format , GLenum type , GLsizei bufSize , GLvoid *values); }
#define glGetnHistogramARB DynamicGL_GetnHistogramARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetnMinmaxARB)(GLenum target , GLboolean reset , GLenum format , GLenum type , GLsizei bufSize , GLvoid *values); }
#define glGetnMinmaxARB DynamicGL_GetnMinmaxARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetnTexImageARB)(GLenum target , GLint level , GLenum format , GLenum type , GLsizei bufSize , GLvoid *img); }
#define glGetnTexImageARB DynamicGL_GetnTexImageARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ReadnPixelsARB)(GLint x , GLint y , GLsizei width , GLsizei height , GLenum format , GLenum type , GLsizei bufSize , GLvoid *data); }
#define glReadnPixelsARB DynamicGL_ReadnPixelsARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetnCompressedTexImageARB)(GLenum target , GLint lod , GLsizei bufSize , GLvoid *img); }
#define glGetnCompressedTexImageARB DynamicGL_GetnCompressedTexImageARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetnUniformfvARB)(GLuint program , GLint location , GLsizei bufSize , GLfloat *params); }
#define glGetnUniformfvARB DynamicGL_GetnUniformfvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetnUniformivARB)(GLuint program , GLint location , GLsizei bufSize , GLint *params); }
#define glGetnUniformivARB DynamicGL_GetnUniformivARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetnUniformuivARB)(GLuint program , GLint location , GLsizei bufSize , GLuint *params); }
#define glGetnUniformuivARB DynamicGL_GetnUniformuivARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetnUniformdvARB)(GLuint program , GLint location , GLsizei bufSize , GLdouble *params); }
#define glGetnUniformdvARB DynamicGL_GetnUniformdvARB
extern bool DinamicGLFeature_ARB_robustness_Supported();
#endif /*USE_DYNAMIC_GL_ARB_robustness*/

/*ARB_shading_language_100*/
#ifdef USE_DYNAMIC_GL_ARB_shading_language_100
#define GL_SHADING_LANGUAGE_VERSION_ARB 0x8B8C
extern bool DinamicGLFeature_ARB_shading_language_100_Supported();
#endif /*USE_DYNAMIC_GL_ARB_shading_language_100*/

/*ARB_fragment_program*/
#ifdef USE_DYNAMIC_GL_ARB_fragment_program
#define GL_FRAGMENT_PROGRAM_ARB 0x8804
#define GL_PROGRAM_ALU_INSTRUCTIONS_ARB 0x8805
#define GL_PROGRAM_TEX_INSTRUCTIONS_ARB 0x8806
#define GL_PROGRAM_TEX_INDIRECTIONS_ARB 0x8807
#define GL_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB 0x8808
#define GL_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB 0x8809
#define GL_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB 0x880A
#define GL_MAX_PROGRAM_ALU_INSTRUCTIONS_ARB 0x880B
#define GL_MAX_PROGRAM_TEX_INSTRUCTIONS_ARB 0x880C
#define GL_MAX_PROGRAM_TEX_INDIRECTIONS_ARB 0x880D
#define GL_MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB 0x880E
#define GL_MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB 0x880F
#define GL_MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB 0x8810
#define GL_MAX_TEXTURE_COORDS_ARB 0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS_ARB 0x8872
extern bool DinamicGLFeature_ARB_fragment_program_Supported();
#endif /*USE_DYNAMIC_GL_ARB_fragment_program*/

/*ARB_shader_objects*/
#ifdef USE_DYNAMIC_GL_ARB_shader_objects
typedef char GLcharARB;
typedef unsigned int GLhandleARB;
#define GL_PROGRAM_OBJECT_ARB 0x8B40
#define GL_SHADER_OBJECT_ARB 0x8B48
#define GL_OBJECT_TYPE_ARB 0x8B4E
#define GL_OBJECT_SUBTYPE_ARB 0x8B4F
#define GL_FLOAT_VEC2_ARB 0x8B50
#define GL_FLOAT_VEC3_ARB 0x8B51
#define GL_FLOAT_VEC4_ARB 0x8B52
#define GL_INT_VEC2_ARB 0x8B53
#define GL_INT_VEC3_ARB 0x8B54
#define GL_INT_VEC4_ARB 0x8B55
#define GL_BOOL_ARB 0x8B56
#define GL_BOOL_VEC2_ARB 0x8B57
#define GL_BOOL_VEC3_ARB 0x8B58
#define GL_BOOL_VEC4_ARB 0x8B59
#define GL_FLOAT_MAT2_ARB 0x8B5A
#define GL_FLOAT_MAT3_ARB 0x8B5B
#define GL_FLOAT_MAT4_ARB 0x8B5C
#define GL_SAMPLER_1D_ARB 0x8B5D
#define GL_SAMPLER_2D_ARB 0x8B5E
#define GL_SAMPLER_3D_ARB 0x8B5F
#define GL_SAMPLER_CUBE_ARB 0x8B60
#define GL_SAMPLER_1D_SHADOW_ARB 0x8B61
#define GL_SAMPLER_2D_SHADOW_ARB 0x8B62
#define GL_SAMPLER_2D_RECT_ARB 0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW_ARB 0x8B64
#define GL_OBJECT_DELETE_STATUS_ARB 0x8B80
#define GL_OBJECT_COMPILE_STATUS_ARB 0x8B81
#define GL_OBJECT_LINK_STATUS_ARB 0x8B82
#define GL_OBJECT_VALIDATE_STATUS_ARB 0x8B83
#define GL_OBJECT_INFO_LOG_LENGTH_ARB 0x8B84
#define GL_OBJECT_ATTACHED_OBJECTS_ARB 0x8B85
#define GL_OBJECT_ACTIVE_UNIFORMS_ARB 0x8B86
#define GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB 0x8B87
#define GL_OBJECT_SHADER_SOURCE_LENGTH_ARB 0x8B88
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteObjectARB)(GLhandleARB obj); }
#define glDeleteObjectARB DynamicGL_DeleteObjectARB
extern "C" { extern GLhandleARB (DYNAMIC_GL_APIENTRYP DynamicGL_GetHandleARB)(GLenum pname); }
#define glGetHandleARB DynamicGL_GetHandleARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DetachObjectARB)(GLhandleARB containerObj , GLhandleARB attachedObj); }
#define glDetachObjectARB DynamicGL_DetachObjectARB
extern "C" { extern GLhandleARB (DYNAMIC_GL_APIENTRYP DynamicGL_CreateShaderObjectARB)(GLenum shaderType); }
#define glCreateShaderObjectARB DynamicGL_CreateShaderObjectARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ShaderSourceARB)(GLhandleARB shaderObj , GLsizei count , const GLcharARB* *string , const GLint *length); }
#define glShaderSourceARB DynamicGL_ShaderSourceARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CompileShaderARB)(GLhandleARB shaderObj); }
#define glCompileShaderARB DynamicGL_CompileShaderARB
extern "C" { extern GLhandleARB (DYNAMIC_GL_APIENTRYP DynamicGL_CreateProgramObjectARB)(); }
#define glCreateProgramObjectARB DynamicGL_CreateProgramObjectARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_AttachObjectARB)(GLhandleARB containerObj , GLhandleARB obj); }
#define glAttachObjectARB DynamicGL_AttachObjectARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LinkProgramARB)(GLhandleARB programObj); }
#define glLinkProgramARB DynamicGL_LinkProgramARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_UseProgramObjectARB)(GLhandleARB programObj); }
#define glUseProgramObjectARB DynamicGL_UseProgramObjectARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ValidateProgramARB)(GLhandleARB programObj); }
#define glValidateProgramARB DynamicGL_ValidateProgramARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform1fARB)(GLint location , GLfloat v0); }
#define glUniform1fARB DynamicGL_Uniform1fARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform2fARB)(GLint location , GLfloat v0 , GLfloat v1); }
#define glUniform2fARB DynamicGL_Uniform2fARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform3fARB)(GLint location , GLfloat v0 , GLfloat v1 , GLfloat v2); }
#define glUniform3fARB DynamicGL_Uniform3fARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform4fARB)(GLint location , GLfloat v0 , GLfloat v1 , GLfloat v2 , GLfloat v3); }
#define glUniform4fARB DynamicGL_Uniform4fARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform1iARB)(GLint location , GLint v0); }
#define glUniform1iARB DynamicGL_Uniform1iARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform2iARB)(GLint location , GLint v0 , GLint v1); }
#define glUniform2iARB DynamicGL_Uniform2iARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform3iARB)(GLint location , GLint v0 , GLint v1 , GLint v2); }
#define glUniform3iARB DynamicGL_Uniform3iARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform4iARB)(GLint location , GLint v0 , GLint v1 , GLint v2 , GLint v3); }
#define glUniform4iARB DynamicGL_Uniform4iARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform1fvARB)(GLint location , GLsizei count , const GLfloat *value); }
#define glUniform1fvARB DynamicGL_Uniform1fvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform2fvARB)(GLint location , GLsizei count , const GLfloat *value); }
#define glUniform2fvARB DynamicGL_Uniform2fvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform3fvARB)(GLint location , GLsizei count , const GLfloat *value); }
#define glUniform3fvARB DynamicGL_Uniform3fvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform4fvARB)(GLint location , GLsizei count , const GLfloat *value); }
#define glUniform4fvARB DynamicGL_Uniform4fvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform1ivARB)(GLint location , GLsizei count , const GLint *value); }
#define glUniform1ivARB DynamicGL_Uniform1ivARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform2ivARB)(GLint location , GLsizei count , const GLint *value); }
#define glUniform2ivARB DynamicGL_Uniform2ivARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform3ivARB)(GLint location , GLsizei count , const GLint *value); }
#define glUniform3ivARB DynamicGL_Uniform3ivARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform4ivARB)(GLint location , GLsizei count , const GLint *value); }
#define glUniform4ivARB DynamicGL_Uniform4ivARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformMatrix2fvARB)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value); }
#define glUniformMatrix2fvARB DynamicGL_UniformMatrix2fvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformMatrix3fvARB)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value); }
#define glUniformMatrix3fvARB DynamicGL_UniformMatrix3fvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformMatrix4fvARB)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value); }
#define glUniformMatrix4fvARB DynamicGL_UniformMatrix4fvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetObjectParameterfvARB)(GLhandleARB obj , GLenum pname , GLfloat *params); }
#define glGetObjectParameterfvARB DynamicGL_GetObjectParameterfvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetObjectParameterivARB)(GLhandleARB obj , GLenum pname , GLint *params); }
#define glGetObjectParameterivARB DynamicGL_GetObjectParameterivARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetInfoLogARB)(GLhandleARB obj , GLsizei maxLength , GLsizei *length , GLcharARB *infoLog); }
#define glGetInfoLogARB DynamicGL_GetInfoLogARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetAttachedObjectsARB)(GLhandleARB containerObj , GLsizei maxCount , GLsizei *count , GLhandleARB *obj); }
#define glGetAttachedObjectsARB DynamicGL_GetAttachedObjectsARB
extern "C" { extern GLint (DYNAMIC_GL_APIENTRYP DynamicGL_GetUniformLocationARB)(GLhandleARB programObj , const GLcharARB *name); }
#define glGetUniformLocationARB DynamicGL_GetUniformLocationARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetActiveUniformARB)(GLhandleARB programObj , GLuint index , GLsizei maxLength , GLsizei *length , GLint *size , GLenum *type , GLcharARB *name); }
#define glGetActiveUniformARB DynamicGL_GetActiveUniformARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetUniformfvARB)(GLhandleARB programObj , GLint location , GLfloat *params); }
#define glGetUniformfvARB DynamicGL_GetUniformfvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetUniformivARB)(GLhandleARB programObj , GLint location , GLint *params); }
#define glGetUniformivARB DynamicGL_GetUniformivARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetShaderSourceARB)(GLhandleARB obj , GLsizei maxLength , GLsizei *length , GLcharARB *source); }
#define glGetShaderSourceARB DynamicGL_GetShaderSourceARB
extern bool DinamicGLFeature_ARB_shader_objects_Supported();
#endif /*USE_DYNAMIC_GL_ARB_shader_objects*/

/*SGIX_reference_plane*/
#ifdef USE_DYNAMIC_GL_SGIX_reference_plane
#define GL_REFERENCE_PLANE_SGIX 0x817D
#define GL_REFERENCE_PLANE_EQUATION_SGIX 0x817E
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ReferencePlaneSGIX)(const GLdouble *equation); }
#define glReferencePlaneSGIX DynamicGL_ReferencePlaneSGIX
extern bool DinamicGLFeature_SGIX_reference_plane_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_reference_plane*/

/*ARB_gpu_shader5*/
#ifdef USE_DYNAMIC_GL_ARB_gpu_shader5
#define GL_GEOMETRY_SHADER_INVOCATIONS 0x887F
#define GL_MAX_GEOMETRY_SHADER_INVOCATIONS 0x8E5A
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET 0x8E5B
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET 0x8E5C
#define GL_FRAGMENT_INTERPOLATION_OFFSET_BITS 0x8E5D
extern bool DinamicGLFeature_ARB_gpu_shader5_Supported();
#endif /*USE_DYNAMIC_GL_ARB_gpu_shader5*/

/*HP_image_transform*/
#ifdef USE_DYNAMIC_GL_HP_image_transform
#define GL_IMAGE_SCALE_X_HP 0x8155
#define GL_IMAGE_SCALE_Y_HP 0x8156
#define GL_IMAGE_TRANSLATE_X_HP 0x8157
#define GL_IMAGE_TRANSLATE_Y_HP 0x8158
#define GL_IMAGE_ROTATE_ANGLE_HP 0x8159
#define GL_IMAGE_ROTATE_ORIGIN_X_HP 0x815A
#define GL_IMAGE_ROTATE_ORIGIN_Y_HP 0x815B
#define GL_IMAGE_MAG_FILTER_HP 0x815C
#define GL_IMAGE_MIN_FILTER_HP 0x815D
#define GL_IMAGE_CUBIC_WEIGHT_HP 0x815E
#define GL_CUBIC_HP 0x815F
#define GL_AVERAGE_HP 0x8160
#define GL_IMAGE_TRANSFORM_2D_HP 0x8161
#define GL_POST_IMAGE_TRANSFORM_COLOR_TABLE_HP 0x8162
#define GL_PROXY_POST_IMAGE_TRANSFORM_COLOR_TABLE_HP 0x8163
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ImageTransformParameteriHP)(GLenum target , GLenum pname , GLint param); }
#define glImageTransformParameteriHP DynamicGL_ImageTransformParameteriHP
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ImageTransformParameterfHP)(GLenum target , GLenum pname , GLfloat param); }
#define glImageTransformParameterfHP DynamicGL_ImageTransformParameterfHP
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ImageTransformParameterivHP)(GLenum target , GLenum pname , const GLint *params); }
#define glImageTransformParameterivHP DynamicGL_ImageTransformParameterivHP
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ImageTransformParameterfvHP)(GLenum target , GLenum pname , const GLfloat *params); }
#define glImageTransformParameterfvHP DynamicGL_ImageTransformParameterfvHP
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetImageTransformParameterivHP)(GLenum target , GLenum pname , GLint *params); }
#define glGetImageTransformParameterivHP DynamicGL_GetImageTransformParameterivHP
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetImageTransformParameterfvHP)(GLenum target , GLenum pname , GLfloat *params); }
#define glGetImageTransformParameterfvHP DynamicGL_GetImageTransformParameterfvHP
extern bool DinamicGLFeature_HP_image_transform_Supported();
#endif /*USE_DYNAMIC_GL_HP_image_transform*/

/*EXT_direct_state_access*/
#ifdef USE_DYNAMIC_GL_EXT_direct_state_access
#define GL_PROGRAM_MATRIX_EXT 0x8E2D
#define GL_TRANSPOSE_PROGRAM_MATRIX_EXT 0x8E2E
#define GL_PROGRAM_MATRIX_STACK_DEPTH_EXT 0x8E2F
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClientAttribDefaultEXT)(GLbitfield mask); }
#define glClientAttribDefaultEXT DynamicGL_ClientAttribDefaultEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PushClientAttribDefaultEXT)(GLbitfield mask); }
#define glPushClientAttribDefaultEXT DynamicGL_PushClientAttribDefaultEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixLoadfEXT)(GLenum mode , const GLfloat *m); }
#define glMatrixLoadfEXT DynamicGL_MatrixLoadfEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixLoaddEXT)(GLenum mode , const GLdouble *m); }
#define glMatrixLoaddEXT DynamicGL_MatrixLoaddEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixMultfEXT)(GLenum mode , const GLfloat *m); }
#define glMatrixMultfEXT DynamicGL_MatrixMultfEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixMultdEXT)(GLenum mode , const GLdouble *m); }
#define glMatrixMultdEXT DynamicGL_MatrixMultdEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixLoadIdentityEXT)(GLenum mode); }
#define glMatrixLoadIdentityEXT DynamicGL_MatrixLoadIdentityEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixRotatefEXT)(GLenum mode , GLfloat angle , GLfloat x , GLfloat y , GLfloat z); }
#define glMatrixRotatefEXT DynamicGL_MatrixRotatefEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixRotatedEXT)(GLenum mode , GLdouble angle , GLdouble x , GLdouble y , GLdouble z); }
#define glMatrixRotatedEXT DynamicGL_MatrixRotatedEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixScalefEXT)(GLenum mode , GLfloat x , GLfloat y , GLfloat z); }
#define glMatrixScalefEXT DynamicGL_MatrixScalefEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixScaledEXT)(GLenum mode , GLdouble x , GLdouble y , GLdouble z); }
#define glMatrixScaledEXT DynamicGL_MatrixScaledEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixTranslatefEXT)(GLenum mode , GLfloat x , GLfloat y , GLfloat z); }
#define glMatrixTranslatefEXT DynamicGL_MatrixTranslatefEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixTranslatedEXT)(GLenum mode , GLdouble x , GLdouble y , GLdouble z); }
#define glMatrixTranslatedEXT DynamicGL_MatrixTranslatedEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixFrustumEXT)(GLenum mode , GLdouble left , GLdouble right , GLdouble bottom , GLdouble top , GLdouble zNear , GLdouble zFar); }
#define glMatrixFrustumEXT DynamicGL_MatrixFrustumEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixOrthoEXT)(GLenum mode , GLdouble left , GLdouble right , GLdouble bottom , GLdouble top , GLdouble zNear , GLdouble zFar); }
#define glMatrixOrthoEXT DynamicGL_MatrixOrthoEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixPopEXT)(GLenum mode); }
#define glMatrixPopEXT DynamicGL_MatrixPopEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixPushEXT)(GLenum mode); }
#define glMatrixPushEXT DynamicGL_MatrixPushEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixLoadTransposefEXT)(GLenum mode , const GLfloat *m); }
#define glMatrixLoadTransposefEXT DynamicGL_MatrixLoadTransposefEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixLoadTransposedEXT)(GLenum mode , const GLdouble *m); }
#define glMatrixLoadTransposedEXT DynamicGL_MatrixLoadTransposedEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixMultTransposefEXT)(GLenum mode , const GLfloat *m); }
#define glMatrixMultTransposefEXT DynamicGL_MatrixMultTransposefEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixMultTransposedEXT)(GLenum mode , const GLdouble *m); }
#define glMatrixMultTransposedEXT DynamicGL_MatrixMultTransposedEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureParameterfEXT)(GLuint texture , GLenum target , GLenum pname , GLfloat param); }
#define glTextureParameterfEXT DynamicGL_TextureParameterfEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureParameterfvEXT)(GLuint texture , GLenum target , GLenum pname , const GLfloat *params); }
#define glTextureParameterfvEXT DynamicGL_TextureParameterfvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureParameteriEXT)(GLuint texture , GLenum target , GLenum pname , GLint param); }
#define glTextureParameteriEXT DynamicGL_TextureParameteriEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureParameterivEXT)(GLuint texture , GLenum target , GLenum pname , const GLint *params); }
#define glTextureParameterivEXT DynamicGL_TextureParameterivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureImage1DEXT)(GLuint texture , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLint border , GLenum format , GLenum type , const GLvoid *pixels); }
#define glTextureImage1DEXT DynamicGL_TextureImage1DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureImage2DEXT)(GLuint texture , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLint border , GLenum format , GLenum type , const GLvoid *pixels); }
#define glTextureImage2DEXT DynamicGL_TextureImage2DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureSubImage1DEXT)(GLuint texture , GLenum target , GLint level , GLint xoffset , GLsizei width , GLenum format , GLenum type , const GLvoid *pixels); }
#define glTextureSubImage1DEXT DynamicGL_TextureSubImage1DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureSubImage2DEXT)(GLuint texture , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLsizei width , GLsizei height , GLenum format , GLenum type , const GLvoid *pixels); }
#define glTextureSubImage2DEXT DynamicGL_TextureSubImage2DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyTextureImage1DEXT)(GLuint texture , GLenum target , GLint level , GLenum internalformat , GLint x , GLint y , GLsizei width , GLint border); }
#define glCopyTextureImage1DEXT DynamicGL_CopyTextureImage1DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyTextureImage2DEXT)(GLuint texture , GLenum target , GLint level , GLenum internalformat , GLint x , GLint y , GLsizei width , GLsizei height , GLint border); }
#define glCopyTextureImage2DEXT DynamicGL_CopyTextureImage2DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyTextureSubImage1DEXT)(GLuint texture , GLenum target , GLint level , GLint xoffset , GLint x , GLint y , GLsizei width); }
#define glCopyTextureSubImage1DEXT DynamicGL_CopyTextureSubImage1DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyTextureSubImage2DEXT)(GLuint texture , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint x , GLint y , GLsizei width , GLsizei height); }
#define glCopyTextureSubImage2DEXT DynamicGL_CopyTextureSubImage2DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTextureImageEXT)(GLuint texture , GLenum target , GLint level , GLenum format , GLenum type , GLvoid *pixels); }
#define glGetTextureImageEXT DynamicGL_GetTextureImageEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTextureParameterfvEXT)(GLuint texture , GLenum target , GLenum pname , GLfloat *params); }
#define glGetTextureParameterfvEXT DynamicGL_GetTextureParameterfvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTextureParameterivEXT)(GLuint texture , GLenum target , GLenum pname , GLint *params); }
#define glGetTextureParameterivEXT DynamicGL_GetTextureParameterivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTextureLevelParameterfvEXT)(GLuint texture , GLenum target , GLint level , GLenum pname , GLfloat *params); }
#define glGetTextureLevelParameterfvEXT DynamicGL_GetTextureLevelParameterfvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTextureLevelParameterivEXT)(GLuint texture , GLenum target , GLint level , GLenum pname , GLint *params); }
#define glGetTextureLevelParameterivEXT DynamicGL_GetTextureLevelParameterivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureImage3DEXT)(GLuint texture , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLsizei depth , GLint border , GLenum format , GLenum type , const GLvoid *pixels); }
#define glTextureImage3DEXT DynamicGL_TextureImage3DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureSubImage3DEXT)(GLuint texture , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLsizei width , GLsizei height , GLsizei depth , GLenum format , GLenum type , const GLvoid *pixels); }
#define glTextureSubImage3DEXT DynamicGL_TextureSubImage3DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyTextureSubImage3DEXT)(GLuint texture , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLint x , GLint y , GLsizei width , GLsizei height); }
#define glCopyTextureSubImage3DEXT DynamicGL_CopyTextureSubImage3DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexParameterfEXT)(GLenum texunit , GLenum target , GLenum pname , GLfloat param); }
#define glMultiTexParameterfEXT DynamicGL_MultiTexParameterfEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexParameterfvEXT)(GLenum texunit , GLenum target , GLenum pname , const GLfloat *params); }
#define glMultiTexParameterfvEXT DynamicGL_MultiTexParameterfvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexParameteriEXT)(GLenum texunit , GLenum target , GLenum pname , GLint param); }
#define glMultiTexParameteriEXT DynamicGL_MultiTexParameteriEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexParameterivEXT)(GLenum texunit , GLenum target , GLenum pname , const GLint *params); }
#define glMultiTexParameterivEXT DynamicGL_MultiTexParameterivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexImage1DEXT)(GLenum texunit , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLint border , GLenum format , GLenum type , const GLvoid *pixels); }
#define glMultiTexImage1DEXT DynamicGL_MultiTexImage1DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexImage2DEXT)(GLenum texunit , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLint border , GLenum format , GLenum type , const GLvoid *pixels); }
#define glMultiTexImage2DEXT DynamicGL_MultiTexImage2DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexSubImage1DEXT)(GLenum texunit , GLenum target , GLint level , GLint xoffset , GLsizei width , GLenum format , GLenum type , const GLvoid *pixels); }
#define glMultiTexSubImage1DEXT DynamicGL_MultiTexSubImage1DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexSubImage2DEXT)(GLenum texunit , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLsizei width , GLsizei height , GLenum format , GLenum type , const GLvoid *pixels); }
#define glMultiTexSubImage2DEXT DynamicGL_MultiTexSubImage2DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyMultiTexImage1DEXT)(GLenum texunit , GLenum target , GLint level , GLenum internalformat , GLint x , GLint y , GLsizei width , GLint border); }
#define glCopyMultiTexImage1DEXT DynamicGL_CopyMultiTexImage1DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyMultiTexImage2DEXT)(GLenum texunit , GLenum target , GLint level , GLenum internalformat , GLint x , GLint y , GLsizei width , GLsizei height , GLint border); }
#define glCopyMultiTexImage2DEXT DynamicGL_CopyMultiTexImage2DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyMultiTexSubImage1DEXT)(GLenum texunit , GLenum target , GLint level , GLint xoffset , GLint x , GLint y , GLsizei width); }
#define glCopyMultiTexSubImage1DEXT DynamicGL_CopyMultiTexSubImage1DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyMultiTexSubImage2DEXT)(GLenum texunit , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint x , GLint y , GLsizei width , GLsizei height); }
#define glCopyMultiTexSubImage2DEXT DynamicGL_CopyMultiTexSubImage2DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMultiTexImageEXT)(GLenum texunit , GLenum target , GLint level , GLenum format , GLenum type , GLvoid *pixels); }
#define glGetMultiTexImageEXT DynamicGL_GetMultiTexImageEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMultiTexParameterfvEXT)(GLenum texunit , GLenum target , GLenum pname , GLfloat *params); }
#define glGetMultiTexParameterfvEXT DynamicGL_GetMultiTexParameterfvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMultiTexParameterivEXT)(GLenum texunit , GLenum target , GLenum pname , GLint *params); }
#define glGetMultiTexParameterivEXT DynamicGL_GetMultiTexParameterivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMultiTexLevelParameterfvEXT)(GLenum texunit , GLenum target , GLint level , GLenum pname , GLfloat *params); }
#define glGetMultiTexLevelParameterfvEXT DynamicGL_GetMultiTexLevelParameterfvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMultiTexLevelParameterivEXT)(GLenum texunit , GLenum target , GLint level , GLenum pname , GLint *params); }
#define glGetMultiTexLevelParameterivEXT DynamicGL_GetMultiTexLevelParameterivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexImage3DEXT)(GLenum texunit , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLsizei depth , GLint border , GLenum format , GLenum type , const GLvoid *pixels); }
#define glMultiTexImage3DEXT DynamicGL_MultiTexImage3DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexSubImage3DEXT)(GLenum texunit , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLsizei width , GLsizei height , GLsizei depth , GLenum format , GLenum type , const GLvoid *pixels); }
#define glMultiTexSubImage3DEXT DynamicGL_MultiTexSubImage3DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyMultiTexSubImage3DEXT)(GLenum texunit , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLint x , GLint y , GLsizei width , GLsizei height); }
#define glCopyMultiTexSubImage3DEXT DynamicGL_CopyMultiTexSubImage3DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindMultiTextureEXT)(GLenum texunit , GLenum target , GLuint texture); }
#define glBindMultiTextureEXT DynamicGL_BindMultiTextureEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EnableClientStateIndexedEXT)(GLenum array , GLuint index); }
#define glEnableClientStateIndexedEXT DynamicGL_EnableClientStateIndexedEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DisableClientStateIndexedEXT)(GLenum array , GLuint index); }
#define glDisableClientStateIndexedEXT DynamicGL_DisableClientStateIndexedEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoordPointerEXT)(GLenum texunit , GLint size , GLenum type , GLsizei stride , const GLvoid *pointer); }
#define glMultiTexCoordPointerEXT DynamicGL_MultiTexCoordPointerEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexEnvfEXT)(GLenum texunit , GLenum target , GLenum pname , GLfloat param); }
#define glMultiTexEnvfEXT DynamicGL_MultiTexEnvfEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexEnvfvEXT)(GLenum texunit , GLenum target , GLenum pname , const GLfloat *params); }
#define glMultiTexEnvfvEXT DynamicGL_MultiTexEnvfvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexEnviEXT)(GLenum texunit , GLenum target , GLenum pname , GLint param); }
#define glMultiTexEnviEXT DynamicGL_MultiTexEnviEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexEnvivEXT)(GLenum texunit , GLenum target , GLenum pname , const GLint *params); }
#define glMultiTexEnvivEXT DynamicGL_MultiTexEnvivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexGendEXT)(GLenum texunit , GLenum coord , GLenum pname , GLdouble param); }
#define glMultiTexGendEXT DynamicGL_MultiTexGendEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexGendvEXT)(GLenum texunit , GLenum coord , GLenum pname , const GLdouble *params); }
#define glMultiTexGendvEXT DynamicGL_MultiTexGendvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexGenfEXT)(GLenum texunit , GLenum coord , GLenum pname , GLfloat param); }
#define glMultiTexGenfEXT DynamicGL_MultiTexGenfEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexGenfvEXT)(GLenum texunit , GLenum coord , GLenum pname , const GLfloat *params); }
#define glMultiTexGenfvEXT DynamicGL_MultiTexGenfvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexGeniEXT)(GLenum texunit , GLenum coord , GLenum pname , GLint param); }
#define glMultiTexGeniEXT DynamicGL_MultiTexGeniEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexGenivEXT)(GLenum texunit , GLenum coord , GLenum pname , const GLint *params); }
#define glMultiTexGenivEXT DynamicGL_MultiTexGenivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMultiTexEnvfvEXT)(GLenum texunit , GLenum target , GLenum pname , GLfloat *params); }
#define glGetMultiTexEnvfvEXT DynamicGL_GetMultiTexEnvfvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMultiTexEnvivEXT)(GLenum texunit , GLenum target , GLenum pname , GLint *params); }
#define glGetMultiTexEnvivEXT DynamicGL_GetMultiTexEnvivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMultiTexGendvEXT)(GLenum texunit , GLenum coord , GLenum pname , GLdouble *params); }
#define glGetMultiTexGendvEXT DynamicGL_GetMultiTexGendvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMultiTexGenfvEXT)(GLenum texunit , GLenum coord , GLenum pname , GLfloat *params); }
#define glGetMultiTexGenfvEXT DynamicGL_GetMultiTexGenfvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMultiTexGenivEXT)(GLenum texunit , GLenum coord , GLenum pname , GLint *params); }
#define glGetMultiTexGenivEXT DynamicGL_GetMultiTexGenivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFloatIndexedvEXT)(GLenum target , GLuint index , GLfloat *data); }
#define glGetFloatIndexedvEXT DynamicGL_GetFloatIndexedvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetDoubleIndexedvEXT)(GLenum target , GLuint index , GLdouble *data); }
#define glGetDoubleIndexedvEXT DynamicGL_GetDoubleIndexedvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPointerIndexedvEXT)(GLenum target , GLuint index , GLvoid* *data); }
#define glGetPointerIndexedvEXT DynamicGL_GetPointerIndexedvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTextureImage3DEXT)(GLuint texture , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLsizei depth , GLint border , GLsizei imageSize , const GLvoid *bits); }
#define glCompressedTextureImage3DEXT DynamicGL_CompressedTextureImage3DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTextureImage2DEXT)(GLuint texture , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLint border , GLsizei imageSize , const GLvoid *bits); }
#define glCompressedTextureImage2DEXT DynamicGL_CompressedTextureImage2DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTextureImage1DEXT)(GLuint texture , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLint border , GLsizei imageSize , const GLvoid *bits); }
#define glCompressedTextureImage1DEXT DynamicGL_CompressedTextureImage1DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTextureSubImage3DEXT)(GLuint texture , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLsizei width , GLsizei height , GLsizei depth , GLenum format , GLsizei imageSize , const GLvoid *bits); }
#define glCompressedTextureSubImage3DEXT DynamicGL_CompressedTextureSubImage3DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTextureSubImage2DEXT)(GLuint texture , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLsizei width , GLsizei height , GLenum format , GLsizei imageSize , const GLvoid *bits); }
#define glCompressedTextureSubImage2DEXT DynamicGL_CompressedTextureSubImage2DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTextureSubImage1DEXT)(GLuint texture , GLenum target , GLint level , GLint xoffset , GLsizei width , GLenum format , GLsizei imageSize , const GLvoid *bits); }
#define glCompressedTextureSubImage1DEXT DynamicGL_CompressedTextureSubImage1DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetCompressedTextureImageEXT)(GLuint texture , GLenum target , GLint lod , GLvoid *img); }
#define glGetCompressedTextureImageEXT DynamicGL_GetCompressedTextureImageEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedMultiTexImage3DEXT)(GLenum texunit , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLsizei depth , GLint border , GLsizei imageSize , const GLvoid *bits); }
#define glCompressedMultiTexImage3DEXT DynamicGL_CompressedMultiTexImage3DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedMultiTexImage2DEXT)(GLenum texunit , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLint border , GLsizei imageSize , const GLvoid *bits); }
#define glCompressedMultiTexImage2DEXT DynamicGL_CompressedMultiTexImage2DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedMultiTexImage1DEXT)(GLenum texunit , GLenum target , GLint level , GLenum internalformat , GLsizei width , GLint border , GLsizei imageSize , const GLvoid *bits); }
#define glCompressedMultiTexImage1DEXT DynamicGL_CompressedMultiTexImage1DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedMultiTexSubImage3DEXT)(GLenum texunit , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLsizei width , GLsizei height , GLsizei depth , GLenum format , GLsizei imageSize , const GLvoid *bits); }
#define glCompressedMultiTexSubImage3DEXT DynamicGL_CompressedMultiTexSubImage3DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedMultiTexSubImage2DEXT)(GLenum texunit , GLenum target , GLint level , GLint xoffset , GLint yoffset , GLsizei width , GLsizei height , GLenum format , GLsizei imageSize , const GLvoid *bits); }
#define glCompressedMultiTexSubImage2DEXT DynamicGL_CompressedMultiTexSubImage2DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedMultiTexSubImage1DEXT)(GLenum texunit , GLenum target , GLint level , GLint xoffset , GLsizei width , GLenum format , GLsizei imageSize , const GLvoid *bits); }
#define glCompressedMultiTexSubImage1DEXT DynamicGL_CompressedMultiTexSubImage1DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetCompressedMultiTexImageEXT)(GLenum texunit , GLenum target , GLint lod , GLvoid *img); }
#define glGetCompressedMultiTexImageEXT DynamicGL_GetCompressedMultiTexImageEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedProgramStringEXT)(GLuint program , GLenum target , GLenum format , GLsizei len , const GLvoid *string); }
#define glNamedProgramStringEXT DynamicGL_NamedProgramStringEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedProgramLocalParameter4dEXT)(GLuint program , GLenum target , GLuint index , GLdouble x , GLdouble y , GLdouble z , GLdouble w); }
#define glNamedProgramLocalParameter4dEXT DynamicGL_NamedProgramLocalParameter4dEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedProgramLocalParameter4dvEXT)(GLuint program , GLenum target , GLuint index , const GLdouble *params); }
#define glNamedProgramLocalParameter4dvEXT DynamicGL_NamedProgramLocalParameter4dvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedProgramLocalParameter4fEXT)(GLuint program , GLenum target , GLuint index , GLfloat x , GLfloat y , GLfloat z , GLfloat w); }
#define glNamedProgramLocalParameter4fEXT DynamicGL_NamedProgramLocalParameter4fEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedProgramLocalParameter4fvEXT)(GLuint program , GLenum target , GLuint index , const GLfloat *params); }
#define glNamedProgramLocalParameter4fvEXT DynamicGL_NamedProgramLocalParameter4fvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetNamedProgramLocalParameterdvEXT)(GLuint program , GLenum target , GLuint index , GLdouble *params); }
#define glGetNamedProgramLocalParameterdvEXT DynamicGL_GetNamedProgramLocalParameterdvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetNamedProgramLocalParameterfvEXT)(GLuint program , GLenum target , GLuint index , GLfloat *params); }
#define glGetNamedProgramLocalParameterfvEXT DynamicGL_GetNamedProgramLocalParameterfvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetNamedProgramivEXT)(GLuint program , GLenum target , GLenum pname , GLint *params); }
#define glGetNamedProgramivEXT DynamicGL_GetNamedProgramivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetNamedProgramStringEXT)(GLuint program , GLenum target , GLenum pname , GLvoid *string); }
#define glGetNamedProgramStringEXT DynamicGL_GetNamedProgramStringEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedProgramLocalParameters4fvEXT)(GLuint program , GLenum target , GLuint index , GLsizei count , const GLfloat *params); }
#define glNamedProgramLocalParameters4fvEXT DynamicGL_NamedProgramLocalParameters4fvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedProgramLocalParameterI4iEXT)(GLuint program , GLenum target , GLuint index , GLint x , GLint y , GLint z , GLint w); }
#define glNamedProgramLocalParameterI4iEXT DynamicGL_NamedProgramLocalParameterI4iEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedProgramLocalParameterI4ivEXT)(GLuint program , GLenum target , GLuint index , const GLint *params); }
#define glNamedProgramLocalParameterI4ivEXT DynamicGL_NamedProgramLocalParameterI4ivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedProgramLocalParametersI4ivEXT)(GLuint program , GLenum target , GLuint index , GLsizei count , const GLint *params); }
#define glNamedProgramLocalParametersI4ivEXT DynamicGL_NamedProgramLocalParametersI4ivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedProgramLocalParameterI4uiEXT)(GLuint program , GLenum target , GLuint index , GLuint x , GLuint y , GLuint z , GLuint w); }
#define glNamedProgramLocalParameterI4uiEXT DynamicGL_NamedProgramLocalParameterI4uiEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedProgramLocalParameterI4uivEXT)(GLuint program , GLenum target , GLuint index , const GLuint *params); }
#define glNamedProgramLocalParameterI4uivEXT DynamicGL_NamedProgramLocalParameterI4uivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedProgramLocalParametersI4uivEXT)(GLuint program , GLenum target , GLuint index , GLsizei count , const GLuint *params); }
#define glNamedProgramLocalParametersI4uivEXT DynamicGL_NamedProgramLocalParametersI4uivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetNamedProgramLocalParameterIivEXT)(GLuint program , GLenum target , GLuint index , GLint *params); }
#define glGetNamedProgramLocalParameterIivEXT DynamicGL_GetNamedProgramLocalParameterIivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetNamedProgramLocalParameterIuivEXT)(GLuint program , GLenum target , GLuint index , GLuint *params); }
#define glGetNamedProgramLocalParameterIuivEXT DynamicGL_GetNamedProgramLocalParameterIuivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureParameterIivEXT)(GLuint texture , GLenum target , GLenum pname , const GLint *params); }
#define glTextureParameterIivEXT DynamicGL_TextureParameterIivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureParameterIuivEXT)(GLuint texture , GLenum target , GLenum pname , const GLuint *params); }
#define glTextureParameterIuivEXT DynamicGL_TextureParameterIuivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTextureParameterIivEXT)(GLuint texture , GLenum target , GLenum pname , GLint *params); }
#define glGetTextureParameterIivEXT DynamicGL_GetTextureParameterIivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTextureParameterIuivEXT)(GLuint texture , GLenum target , GLenum pname , GLuint *params); }
#define glGetTextureParameterIuivEXT DynamicGL_GetTextureParameterIuivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexParameterIivEXT)(GLenum texunit , GLenum target , GLenum pname , const GLint *params); }
#define glMultiTexParameterIivEXT DynamicGL_MultiTexParameterIivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexParameterIuivEXT)(GLenum texunit , GLenum target , GLenum pname , const GLuint *params); }
#define glMultiTexParameterIuivEXT DynamicGL_MultiTexParameterIuivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMultiTexParameterIivEXT)(GLenum texunit , GLenum target , GLenum pname , GLint *params); }
#define glGetMultiTexParameterIivEXT DynamicGL_GetMultiTexParameterIivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMultiTexParameterIuivEXT)(GLenum texunit , GLenum target , GLenum pname , GLuint *params); }
#define glGetMultiTexParameterIuivEXT DynamicGL_GetMultiTexParameterIuivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform1fEXT)(GLuint program , GLint location , GLfloat v0); }
#define glProgramUniform1fEXT DynamicGL_ProgramUniform1fEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform2fEXT)(GLuint program , GLint location , GLfloat v0 , GLfloat v1); }
#define glProgramUniform2fEXT DynamicGL_ProgramUniform2fEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform3fEXT)(GLuint program , GLint location , GLfloat v0 , GLfloat v1 , GLfloat v2); }
#define glProgramUniform3fEXT DynamicGL_ProgramUniform3fEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform4fEXT)(GLuint program , GLint location , GLfloat v0 , GLfloat v1 , GLfloat v2 , GLfloat v3); }
#define glProgramUniform4fEXT DynamicGL_ProgramUniform4fEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform1iEXT)(GLuint program , GLint location , GLint v0); }
#define glProgramUniform1iEXT DynamicGL_ProgramUniform1iEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform2iEXT)(GLuint program , GLint location , GLint v0 , GLint v1); }
#define glProgramUniform2iEXT DynamicGL_ProgramUniform2iEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform3iEXT)(GLuint program , GLint location , GLint v0 , GLint v1 , GLint v2); }
#define glProgramUniform3iEXT DynamicGL_ProgramUniform3iEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform4iEXT)(GLuint program , GLint location , GLint v0 , GLint v1 , GLint v2 , GLint v3); }
#define glProgramUniform4iEXT DynamicGL_ProgramUniform4iEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform1fvEXT)(GLuint program , GLint location , GLsizei count , const GLfloat *value); }
#define glProgramUniform1fvEXT DynamicGL_ProgramUniform1fvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform2fvEXT)(GLuint program , GLint location , GLsizei count , const GLfloat *value); }
#define glProgramUniform2fvEXT DynamicGL_ProgramUniform2fvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform3fvEXT)(GLuint program , GLint location , GLsizei count , const GLfloat *value); }
#define glProgramUniform3fvEXT DynamicGL_ProgramUniform3fvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform4fvEXT)(GLuint program , GLint location , GLsizei count , const GLfloat *value); }
#define glProgramUniform4fvEXT DynamicGL_ProgramUniform4fvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform1ivEXT)(GLuint program , GLint location , GLsizei count , const GLint *value); }
#define glProgramUniform1ivEXT DynamicGL_ProgramUniform1ivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform2ivEXT)(GLuint program , GLint location , GLsizei count , const GLint *value); }
#define glProgramUniform2ivEXT DynamicGL_ProgramUniform2ivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform3ivEXT)(GLuint program , GLint location , GLsizei count , const GLint *value); }
#define glProgramUniform3ivEXT DynamicGL_ProgramUniform3ivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform4ivEXT)(GLuint program , GLint location , GLsizei count , const GLint *value); }
#define glProgramUniform4ivEXT DynamicGL_ProgramUniform4ivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix2fvEXT)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value); }
#define glProgramUniformMatrix2fvEXT DynamicGL_ProgramUniformMatrix2fvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix3fvEXT)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value); }
#define glProgramUniformMatrix3fvEXT DynamicGL_ProgramUniformMatrix3fvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix4fvEXT)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value); }
#define glProgramUniformMatrix4fvEXT DynamicGL_ProgramUniformMatrix4fvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix2x3fvEXT)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value); }
#define glProgramUniformMatrix2x3fvEXT DynamicGL_ProgramUniformMatrix2x3fvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix3x2fvEXT)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value); }
#define glProgramUniformMatrix3x2fvEXT DynamicGL_ProgramUniformMatrix3x2fvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix2x4fvEXT)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value); }
#define glProgramUniformMatrix2x4fvEXT DynamicGL_ProgramUniformMatrix2x4fvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix4x2fvEXT)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value); }
#define glProgramUniformMatrix4x2fvEXT DynamicGL_ProgramUniformMatrix4x2fvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix3x4fvEXT)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value); }
#define glProgramUniformMatrix3x4fvEXT DynamicGL_ProgramUniformMatrix3x4fvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix4x3fvEXT)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value); }
#define glProgramUniformMatrix4x3fvEXT DynamicGL_ProgramUniformMatrix4x3fvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform1uiEXT)(GLuint program , GLint location , GLuint v0); }
#define glProgramUniform1uiEXT DynamicGL_ProgramUniform1uiEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform2uiEXT)(GLuint program , GLint location , GLuint v0 , GLuint v1); }
#define glProgramUniform2uiEXT DynamicGL_ProgramUniform2uiEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform3uiEXT)(GLuint program , GLint location , GLuint v0 , GLuint v1 , GLuint v2); }
#define glProgramUniform3uiEXT DynamicGL_ProgramUniform3uiEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform4uiEXT)(GLuint program , GLint location , GLuint v0 , GLuint v1 , GLuint v2 , GLuint v3); }
#define glProgramUniform4uiEXT DynamicGL_ProgramUniform4uiEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform1uivEXT)(GLuint program , GLint location , GLsizei count , const GLuint *value); }
#define glProgramUniform1uivEXT DynamicGL_ProgramUniform1uivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform2uivEXT)(GLuint program , GLint location , GLsizei count , const GLuint *value); }
#define glProgramUniform2uivEXT DynamicGL_ProgramUniform2uivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform3uivEXT)(GLuint program , GLint location , GLsizei count , const GLuint *value); }
#define glProgramUniform3uivEXT DynamicGL_ProgramUniform3uivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform4uivEXT)(GLuint program , GLint location , GLsizei count , const GLuint *value); }
#define glProgramUniform4uivEXT DynamicGL_ProgramUniform4uivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedBufferDataEXT)(GLuint buffer , GLsizeiptr size , const GLvoid *data , GLenum usage); }
#define glNamedBufferDataEXT DynamicGL_NamedBufferDataEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedBufferSubDataEXT)(GLuint buffer , GLintptr offset , GLsizeiptr size , const GLvoid *data); }
#define glNamedBufferSubDataEXT DynamicGL_NamedBufferSubDataEXT
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_UnmapNamedBufferEXT)(GLuint buffer); }
#define glUnmapNamedBufferEXT DynamicGL_UnmapNamedBufferEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FlushMappedNamedBufferRangeEXT)(GLuint buffer , GLintptr offset , GLsizeiptr length); }
#define glFlushMappedNamedBufferRangeEXT DynamicGL_FlushMappedNamedBufferRangeEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedCopyBufferSubDataEXT)(GLuint readBuffer , GLuint writeBuffer , GLintptr readOffset , GLintptr writeOffset , GLsizeiptr size); }
#define glNamedCopyBufferSubDataEXT DynamicGL_NamedCopyBufferSubDataEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetNamedBufferParameterivEXT)(GLuint buffer , GLenum pname , GLint *params); }
#define glGetNamedBufferParameterivEXT DynamicGL_GetNamedBufferParameterivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetNamedBufferPointervEXT)(GLuint buffer , GLenum pname , GLvoid* *params); }
#define glGetNamedBufferPointervEXT DynamicGL_GetNamedBufferPointervEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetNamedBufferSubDataEXT)(GLuint buffer , GLintptr offset , GLsizeiptr size , GLvoid *data); }
#define glGetNamedBufferSubDataEXT DynamicGL_GetNamedBufferSubDataEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureBufferEXT)(GLuint texture , GLenum target , GLenum internalformat , GLuint buffer); }
#define glTextureBufferEXT DynamicGL_TextureBufferEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexBufferEXT)(GLenum texunit , GLenum target , GLenum internalformat , GLuint buffer); }
#define glMultiTexBufferEXT DynamicGL_MultiTexBufferEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedRenderbufferStorageEXT)(GLuint renderbuffer , GLenum internalformat , GLsizei width , GLsizei height); }
#define glNamedRenderbufferStorageEXT DynamicGL_NamedRenderbufferStorageEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetNamedRenderbufferParameterivEXT)(GLuint renderbuffer , GLenum pname , GLint *params); }
#define glGetNamedRenderbufferParameterivEXT DynamicGL_GetNamedRenderbufferParameterivEXT
extern "C" { extern GLenum (DYNAMIC_GL_APIENTRYP DynamicGL_CheckNamedFramebufferStatusEXT)(GLuint framebuffer , GLenum target); }
#define glCheckNamedFramebufferStatusEXT DynamicGL_CheckNamedFramebufferStatusEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedFramebufferTexture1DEXT)(GLuint framebuffer , GLenum attachment , GLenum textarget , GLuint texture , GLint level); }
#define glNamedFramebufferTexture1DEXT DynamicGL_NamedFramebufferTexture1DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedFramebufferTexture2DEXT)(GLuint framebuffer , GLenum attachment , GLenum textarget , GLuint texture , GLint level); }
#define glNamedFramebufferTexture2DEXT DynamicGL_NamedFramebufferTexture2DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedFramebufferTexture3DEXT)(GLuint framebuffer , GLenum attachment , GLenum textarget , GLuint texture , GLint level , GLint zoffset); }
#define glNamedFramebufferTexture3DEXT DynamicGL_NamedFramebufferTexture3DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedFramebufferRenderbufferEXT)(GLuint framebuffer , GLenum attachment , GLenum renderbuffertarget , GLuint renderbuffer); }
#define glNamedFramebufferRenderbufferEXT DynamicGL_NamedFramebufferRenderbufferEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetNamedFramebufferAttachmentParameterivEXT)(GLuint framebuffer , GLenum attachment , GLenum pname , GLint *params); }
#define glGetNamedFramebufferAttachmentParameterivEXT DynamicGL_GetNamedFramebufferAttachmentParameterivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GenerateTextureMipmapEXT)(GLuint texture , GLenum target); }
#define glGenerateTextureMipmapEXT DynamicGL_GenerateTextureMipmapEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GenerateMultiTexMipmapEXT)(GLenum texunit , GLenum target); }
#define glGenerateMultiTexMipmapEXT DynamicGL_GenerateMultiTexMipmapEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferDrawBufferEXT)(GLuint framebuffer , GLenum mode); }
#define glFramebufferDrawBufferEXT DynamicGL_FramebufferDrawBufferEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferDrawBuffersEXT)(GLuint framebuffer , GLsizei n , const GLenum *bufs); }
#define glFramebufferDrawBuffersEXT DynamicGL_FramebufferDrawBuffersEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferReadBufferEXT)(GLuint framebuffer , GLenum mode); }
#define glFramebufferReadBufferEXT DynamicGL_FramebufferReadBufferEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFramebufferParameterivEXT)(GLuint framebuffer , GLenum pname , GLint *params); }
#define glGetFramebufferParameterivEXT DynamicGL_GetFramebufferParameterivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedRenderbufferStorageMultisampleEXT)(GLuint renderbuffer , GLsizei samples , GLenum internalformat , GLsizei width , GLsizei height); }
#define glNamedRenderbufferStorageMultisampleEXT DynamicGL_NamedRenderbufferStorageMultisampleEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedRenderbufferStorageMultisampleCoverageEXT)(GLuint renderbuffer , GLsizei coverageSamples , GLsizei colorSamples , GLenum internalformat , GLsizei width , GLsizei height); }
#define glNamedRenderbufferStorageMultisampleCoverageEXT DynamicGL_NamedRenderbufferStorageMultisampleCoverageEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedFramebufferTextureEXT)(GLuint framebuffer , GLenum attachment , GLuint texture , GLint level); }
#define glNamedFramebufferTextureEXT DynamicGL_NamedFramebufferTextureEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedFramebufferTextureLayerEXT)(GLuint framebuffer , GLenum attachment , GLuint texture , GLint level , GLint layer); }
#define glNamedFramebufferTextureLayerEXT DynamicGL_NamedFramebufferTextureLayerEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NamedFramebufferTextureFaceEXT)(GLuint framebuffer , GLenum attachment , GLuint texture , GLint level , GLenum face); }
#define glNamedFramebufferTextureFaceEXT DynamicGL_NamedFramebufferTextureFaceEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureRenderbufferEXT)(GLuint texture , GLenum target , GLuint renderbuffer); }
#define glTextureRenderbufferEXT DynamicGL_TextureRenderbufferEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexRenderbufferEXT)(GLenum texunit , GLenum target , GLuint renderbuffer); }
#define glMultiTexRenderbufferEXT DynamicGL_MultiTexRenderbufferEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform1dEXT)(GLuint program , GLint location , GLdouble x); }
#define glProgramUniform1dEXT DynamicGL_ProgramUniform1dEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform2dEXT)(GLuint program , GLint location , GLdouble x , GLdouble y); }
#define glProgramUniform2dEXT DynamicGL_ProgramUniform2dEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform3dEXT)(GLuint program , GLint location , GLdouble x , GLdouble y , GLdouble z); }
#define glProgramUniform3dEXT DynamicGL_ProgramUniform3dEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform4dEXT)(GLuint program , GLint location , GLdouble x , GLdouble y , GLdouble z , GLdouble w); }
#define glProgramUniform4dEXT DynamicGL_ProgramUniform4dEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform1dvEXT)(GLuint program , GLint location , GLsizei count , const GLdouble *value); }
#define glProgramUniform1dvEXT DynamicGL_ProgramUniform1dvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform2dvEXT)(GLuint program , GLint location , GLsizei count , const GLdouble *value); }
#define glProgramUniform2dvEXT DynamicGL_ProgramUniform2dvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform3dvEXT)(GLuint program , GLint location , GLsizei count , const GLdouble *value); }
#define glProgramUniform3dvEXT DynamicGL_ProgramUniform3dvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform4dvEXT)(GLuint program , GLint location , GLsizei count , const GLdouble *value); }
#define glProgramUniform4dvEXT DynamicGL_ProgramUniform4dvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix2dvEXT)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLdouble *value); }
#define glProgramUniformMatrix2dvEXT DynamicGL_ProgramUniformMatrix2dvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix3dvEXT)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLdouble *value); }
#define glProgramUniformMatrix3dvEXT DynamicGL_ProgramUniformMatrix3dvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix4dvEXT)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLdouble *value); }
#define glProgramUniformMatrix4dvEXT DynamicGL_ProgramUniformMatrix4dvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix2x3dvEXT)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLdouble *value); }
#define glProgramUniformMatrix2x3dvEXT DynamicGL_ProgramUniformMatrix2x3dvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix2x4dvEXT)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLdouble *value); }
#define glProgramUniformMatrix2x4dvEXT DynamicGL_ProgramUniformMatrix2x4dvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix3x2dvEXT)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLdouble *value); }
#define glProgramUniformMatrix3x2dvEXT DynamicGL_ProgramUniformMatrix3x2dvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix3x4dvEXT)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLdouble *value); }
#define glProgramUniformMatrix3x4dvEXT DynamicGL_ProgramUniformMatrix3x4dvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix4x2dvEXT)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLdouble *value); }
#define glProgramUniformMatrix4x2dvEXT DynamicGL_ProgramUniformMatrix4x2dvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix4x3dvEXT)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLdouble *value); }
#define glProgramUniformMatrix4x3dvEXT DynamicGL_ProgramUniformMatrix4x3dvEXT
extern bool DinamicGLFeature_EXT_direct_state_access_Supported();
#endif /*USE_DYNAMIC_GL_EXT_direct_state_access*/

/*ARB_texture_swizzle*/
#ifdef USE_DYNAMIC_GL_ARB_texture_swizzle
#define GL_TEXTURE_SWIZZLE_R 0x8E42
#define GL_TEXTURE_SWIZZLE_G 0x8E43
#define GL_TEXTURE_SWIZZLE_B 0x8E44
#define GL_TEXTURE_SWIZZLE_A 0x8E45
#define GL_TEXTURE_SWIZZLE_RGBA 0x8E46
extern bool DinamicGLFeature_ARB_texture_swizzle_Supported();
#endif /*USE_DYNAMIC_GL_ARB_texture_swizzle*/

/*ARB_multisample*/
#ifdef USE_DYNAMIC_GL_ARB_multisample
#define GL_MULTISAMPLE_ARB 0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE_ARB 0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_ARB 0x809F
#define GL_SAMPLE_COVERAGE_ARB 0x80A0
#define GL_SAMPLE_BUFFERS_ARB 0x80A8
#define GL_SAMPLES_ARB 0x80A9
#define GL_SAMPLE_COVERAGE_VALUE_ARB 0x80AA
#define GL_SAMPLE_COVERAGE_INVERT_ARB 0x80AB
#define GL_MULTISAMPLE_BIT_ARB 0x20000000
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SampleCoverageARB)(GLfloat value , GLboolean invert); }
#define glSampleCoverageARB DynamicGL_SampleCoverageARB
extern bool DinamicGLFeature_ARB_multisample_Supported();
#endif /*USE_DYNAMIC_GL_ARB_multisample*/

/*SGIX_fog_scale*/
#ifdef USE_DYNAMIC_GL_SGIX_fog_scale
#define GL_FOG_SCALE_SGIX 0x81FC
#define GL_FOG_SCALE_VALUE_SGIX 0x81FD
extern bool DinamicGLFeature_SGIX_fog_scale_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_fog_scale*/

/*ATI_texture_mirror_once*/
#ifdef USE_DYNAMIC_GL_ATI_texture_mirror_once
#define GL_MIRROR_CLAMP_ATI 0x8742
#define GL_MIRROR_CLAMP_TO_EDGE_ATI 0x8743
extern bool DinamicGLFeature_ATI_texture_mirror_once_Supported();
#endif /*USE_DYNAMIC_GL_ATI_texture_mirror_once*/

/*APPLE_rgb_422*/
#ifdef USE_DYNAMIC_GL_APPLE_rgb_422
#define GL_RGB_422_APPLE 0x8A1F
extern bool DinamicGLFeature_APPLE_rgb_422_Supported();
#endif /*USE_DYNAMIC_GL_APPLE_rgb_422*/

/*EXT_shared_texture_palette*/
#ifdef USE_DYNAMIC_GL_EXT_shared_texture_palette
#define GL_SHARED_TEXTURE_PALETTE_EXT 0x81FB
extern bool DinamicGLFeature_EXT_shared_texture_palette_Supported();
#endif /*USE_DYNAMIC_GL_EXT_shared_texture_palette*/

/*ARB_texture_rg*/
#ifdef USE_DYNAMIC_GL_ARB_texture_rg
#define GL_RG 0x8227
#define GL_RG_INTEGER 0x8228
#define GL_R8 0x8229
#define GL_R16 0x822A
#define GL_RG8 0x822B
#define GL_RG16 0x822C
#define GL_R16F 0x822D
#define GL_R32F 0x822E
#define GL_RG16F 0x822F
#define GL_RG32F 0x8230
#define GL_R8I 0x8231
#define GL_R8UI 0x8232
#define GL_R16I 0x8233
#define GL_R16UI 0x8234
#define GL_R32I 0x8235
#define GL_R32UI 0x8236
#define GL_RG8I 0x8237
#define GL_RG8UI 0x8238
#define GL_RG16I 0x8239
#define GL_RG16UI 0x823A
#define GL_RG32I 0x823B
#define GL_RG32UI 0x823C
extern bool DinamicGLFeature_ARB_texture_rg_Supported();
#endif /*USE_DYNAMIC_GL_ARB_texture_rg*/

/*ARB_draw_buffers_blend*/
#ifdef USE_DYNAMIC_GL_ARB_draw_buffers_blend
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendEquationiARB)(GLuint buf , GLenum mode); }
#define glBlendEquationiARB DynamicGL_BlendEquationiARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendEquationSeparateiARB)(GLuint buf , GLenum modeRGB , GLenum modeAlpha); }
#define glBlendEquationSeparateiARB DynamicGL_BlendEquationSeparateiARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendFunciARB)(GLuint buf , GLenum src , GLenum dst); }
#define glBlendFunciARB DynamicGL_BlendFunciARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendFuncSeparateiARB)(GLuint buf , GLenum srcRGB , GLenum dstRGB , GLenum srcAlpha , GLenum dstAlpha); }
#define glBlendFuncSeparateiARB DynamicGL_BlendFuncSeparateiARB
extern bool DinamicGLFeature_ARB_draw_buffers_blend_Supported();
#endif /*USE_DYNAMIC_GL_ARB_draw_buffers_blend*/

/*EXT_stencil_clear_tag*/
#ifdef USE_DYNAMIC_GL_EXT_stencil_clear_tag
#define GL_STENCIL_TAG_BITS_EXT 0x88F2
#define GL_STENCIL_CLEAR_TAG_VALUE_EXT 0x88F3
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_StencilClearTagEXT)(GLsizei stencilTagBits , GLuint stencilClearTag); }
#define glStencilClearTagEXT DynamicGL_StencilClearTagEXT
extern bool DinamicGLFeature_EXT_stencil_clear_tag_Supported();
#endif /*USE_DYNAMIC_GL_EXT_stencil_clear_tag*/

/*SGIS_texture_select*/
#ifdef USE_DYNAMIC_GL_SGIS_texture_select
#define GL_DUAL_ALPHA4_SGIS 0x8110
#define GL_DUAL_ALPHA8_SGIS 0x8111
#define GL_DUAL_ALPHA12_SGIS 0x8112
#define GL_DUAL_ALPHA16_SGIS 0x8113
#define GL_DUAL_LUMINANCE4_SGIS 0x8114
#define GL_DUAL_LUMINANCE8_SGIS 0x8115
#define GL_DUAL_LUMINANCE12_SGIS 0x8116
#define GL_DUAL_LUMINANCE16_SGIS 0x8117
#define GL_DUAL_INTENSITY4_SGIS 0x8118
#define GL_DUAL_INTENSITY8_SGIS 0x8119
#define GL_DUAL_INTENSITY12_SGIS 0x811A
#define GL_DUAL_INTENSITY16_SGIS 0x811B
#define GL_DUAL_LUMINANCE_ALPHA4_SGIS 0x811C
#define GL_DUAL_LUMINANCE_ALPHA8_SGIS 0x811D
#define GL_QUAD_ALPHA4_SGIS 0x811E
#define GL_QUAD_ALPHA8_SGIS 0x811F
#define GL_QUAD_LUMINANCE4_SGIS 0x8120
#define GL_QUAD_LUMINANCE8_SGIS 0x8121
#define GL_QUAD_INTENSITY4_SGIS 0x8122
#define GL_QUAD_INTENSITY8_SGIS 0x8123
#define GL_DUAL_TEXTURE_SELECT_SGIS 0x8124
#define GL_QUAD_TEXTURE_SELECT_SGIS 0x8125
extern bool DinamicGLFeature_SGIS_texture_select_Supported();
#endif /*USE_DYNAMIC_GL_SGIS_texture_select*/

/*NV_geometry_program4*/
#ifdef USE_DYNAMIC_GL_NV_geometry_program4
#define GL_LINES_ADJACENCY_EXT 0x000A
#define GL_LINE_STRIP_ADJACENCY_EXT 0x000B
#define GL_TRIANGLES_ADJACENCY_EXT 0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY_EXT 0x000D
#define GL_GEOMETRY_PROGRAM_NV 0x8C26
#define GL_MAX_PROGRAM_OUTPUT_VERTICES_NV 0x8C27
#define GL_MAX_PROGRAM_TOTAL_OUTPUT_COMPONENTS_NV 0x8C28
#define GL_GEOMETRY_VERTICES_OUT_EXT 0x8DDA
#define GL_GEOMETRY_INPUT_TYPE_EXT 0x8DDB
#define GL_GEOMETRY_OUTPUT_TYPE_EXT 0x8DDC
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_EXT 0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED_EXT 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_EXT 0x8DA8
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_EXT 0x8DA9
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT 0x8CD4
#define GL_PROGRAM_POINT_SIZE_EXT 0x8642
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramVertexLimitNV)(GLenum target , GLint limit); }
#define glProgramVertexLimitNV DynamicGL_ProgramVertexLimitNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferTextureEXT)(GLenum target , GLenum attachment , GLuint texture , GLint level); }
#define glFramebufferTextureEXT DynamicGL_FramebufferTextureEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferTextureLayerEXT)(GLenum target , GLenum attachment , GLuint texture , GLint level , GLint layer); }
#define glFramebufferTextureLayerEXT DynamicGL_FramebufferTextureLayerEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferTextureFaceEXT)(GLenum target , GLenum attachment , GLuint texture , GLint level , GLenum face); }
#define glFramebufferTextureFaceEXT DynamicGL_FramebufferTextureFaceEXT
extern bool DinamicGLFeature_NV_geometry_program4_Supported();
#endif /*USE_DYNAMIC_GL_NV_geometry_program4*/

/*ARB_framebuffer_sRGB*/
#ifdef USE_DYNAMIC_GL_ARB_framebuffer_sRGB
#define GL_FRAMEBUFFER_SRGB 0x8DB9
extern bool DinamicGLFeature_ARB_framebuffer_sRGB_Supported();
#endif /*USE_DYNAMIC_GL_ARB_framebuffer_sRGB*/

/*IBM_rasterpos_clip*/
#ifdef USE_DYNAMIC_GL_IBM_rasterpos_clip
#define GL_RASTER_POSITION_UNCLIPPED_IBM 0x19262
extern bool DinamicGLFeature_IBM_rasterpos_clip_Supported();
#endif /*USE_DYNAMIC_GL_IBM_rasterpos_clip*/

/*MESA_ycbcr_texture*/
#ifdef USE_DYNAMIC_GL_MESA_ycbcr_texture
#define GL_UNSIGNED_SHORT_8_8_MESA 0x85BA
#define GL_UNSIGNED_SHORT_8_8_REV_MESA 0x85BB
#define GL_YCBCR_MESA 0x8757
extern bool DinamicGLFeature_MESA_ycbcr_texture_Supported();
#endif /*USE_DYNAMIC_GL_MESA_ycbcr_texture*/

/*ATI_vertex_streams*/
#ifdef USE_DYNAMIC_GL_ATI_vertex_streams
#define GL_MAX_VERTEX_STREAMS_ATI 0x876B
#define GL_VERTEX_STREAM0_ATI 0x876C
#define GL_VERTEX_STREAM1_ATI 0x876D
#define GL_VERTEX_STREAM2_ATI 0x876E
#define GL_VERTEX_STREAM3_ATI 0x876F
#define GL_VERTEX_STREAM4_ATI 0x8770
#define GL_VERTEX_STREAM5_ATI 0x8771
#define GL_VERTEX_STREAM6_ATI 0x8772
#define GL_VERTEX_STREAM7_ATI 0x8773
#define GL_VERTEX_SOURCE_ATI 0x8774
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream1sATI)(GLenum stream , GLshort x); }
#define glVertexStream1sATI DynamicGL_VertexStream1sATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream1svATI)(GLenum stream , const GLshort *coords); }
#define glVertexStream1svATI DynamicGL_VertexStream1svATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream1iATI)(GLenum stream , GLint x); }
#define glVertexStream1iATI DynamicGL_VertexStream1iATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream1ivATI)(GLenum stream , const GLint *coords); }
#define glVertexStream1ivATI DynamicGL_VertexStream1ivATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream1fATI)(GLenum stream , GLfloat x); }
#define glVertexStream1fATI DynamicGL_VertexStream1fATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream1fvATI)(GLenum stream , const GLfloat *coords); }
#define glVertexStream1fvATI DynamicGL_VertexStream1fvATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream1dATI)(GLenum stream , GLdouble x); }
#define glVertexStream1dATI DynamicGL_VertexStream1dATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream1dvATI)(GLenum stream , const GLdouble *coords); }
#define glVertexStream1dvATI DynamicGL_VertexStream1dvATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream2sATI)(GLenum stream , GLshort x , GLshort y); }
#define glVertexStream2sATI DynamicGL_VertexStream2sATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream2svATI)(GLenum stream , const GLshort *coords); }
#define glVertexStream2svATI DynamicGL_VertexStream2svATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream2iATI)(GLenum stream , GLint x , GLint y); }
#define glVertexStream2iATI DynamicGL_VertexStream2iATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream2ivATI)(GLenum stream , const GLint *coords); }
#define glVertexStream2ivATI DynamicGL_VertexStream2ivATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream2fATI)(GLenum stream , GLfloat x , GLfloat y); }
#define glVertexStream2fATI DynamicGL_VertexStream2fATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream2fvATI)(GLenum stream , const GLfloat *coords); }
#define glVertexStream2fvATI DynamicGL_VertexStream2fvATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream2dATI)(GLenum stream , GLdouble x , GLdouble y); }
#define glVertexStream2dATI DynamicGL_VertexStream2dATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream2dvATI)(GLenum stream , const GLdouble *coords); }
#define glVertexStream2dvATI DynamicGL_VertexStream2dvATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream3sATI)(GLenum stream , GLshort x , GLshort y , GLshort z); }
#define glVertexStream3sATI DynamicGL_VertexStream3sATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream3svATI)(GLenum stream , const GLshort *coords); }
#define glVertexStream3svATI DynamicGL_VertexStream3svATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream3iATI)(GLenum stream , GLint x , GLint y , GLint z); }
#define glVertexStream3iATI DynamicGL_VertexStream3iATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream3ivATI)(GLenum stream , const GLint *coords); }
#define glVertexStream3ivATI DynamicGL_VertexStream3ivATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream3fATI)(GLenum stream , GLfloat x , GLfloat y , GLfloat z); }
#define glVertexStream3fATI DynamicGL_VertexStream3fATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream3fvATI)(GLenum stream , const GLfloat *coords); }
#define glVertexStream3fvATI DynamicGL_VertexStream3fvATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream3dATI)(GLenum stream , GLdouble x , GLdouble y , GLdouble z); }
#define glVertexStream3dATI DynamicGL_VertexStream3dATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream3dvATI)(GLenum stream , const GLdouble *coords); }
#define glVertexStream3dvATI DynamicGL_VertexStream3dvATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream4sATI)(GLenum stream , GLshort x , GLshort y , GLshort z , GLshort w); }
#define glVertexStream4sATI DynamicGL_VertexStream4sATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream4svATI)(GLenum stream , const GLshort *coords); }
#define glVertexStream4svATI DynamicGL_VertexStream4svATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream4iATI)(GLenum stream , GLint x , GLint y , GLint z , GLint w); }
#define glVertexStream4iATI DynamicGL_VertexStream4iATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream4ivATI)(GLenum stream , const GLint *coords); }
#define glVertexStream4ivATI DynamicGL_VertexStream4ivATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream4fATI)(GLenum stream , GLfloat x , GLfloat y , GLfloat z , GLfloat w); }
#define glVertexStream4fATI DynamicGL_VertexStream4fATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream4fvATI)(GLenum stream , const GLfloat *coords); }
#define glVertexStream4fvATI DynamicGL_VertexStream4fvATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream4dATI)(GLenum stream , GLdouble x , GLdouble y , GLdouble z , GLdouble w); }
#define glVertexStream4dATI DynamicGL_VertexStream4dATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexStream4dvATI)(GLenum stream , const GLdouble *coords); }
#define glVertexStream4dvATI DynamicGL_VertexStream4dvATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NormalStream3bATI)(GLenum stream , GLbyte nx , GLbyte ny , GLbyte nz); }
#define glNormalStream3bATI DynamicGL_NormalStream3bATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NormalStream3bvATI)(GLenum stream , const GLbyte *coords); }
#define glNormalStream3bvATI DynamicGL_NormalStream3bvATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NormalStream3sATI)(GLenum stream , GLshort nx , GLshort ny , GLshort nz); }
#define glNormalStream3sATI DynamicGL_NormalStream3sATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NormalStream3svATI)(GLenum stream , const GLshort *coords); }
#define glNormalStream3svATI DynamicGL_NormalStream3svATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NormalStream3iATI)(GLenum stream , GLint nx , GLint ny , GLint nz); }
#define glNormalStream3iATI DynamicGL_NormalStream3iATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NormalStream3ivATI)(GLenum stream , const GLint *coords); }
#define glNormalStream3ivATI DynamicGL_NormalStream3ivATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NormalStream3fATI)(GLenum stream , GLfloat nx , GLfloat ny , GLfloat nz); }
#define glNormalStream3fATI DynamicGL_NormalStream3fATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NormalStream3fvATI)(GLenum stream , const GLfloat *coords); }
#define glNormalStream3fvATI DynamicGL_NormalStream3fvATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NormalStream3dATI)(GLenum stream , GLdouble nx , GLdouble ny , GLdouble nz); }
#define glNormalStream3dATI DynamicGL_NormalStream3dATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NormalStream3dvATI)(GLenum stream , const GLdouble *coords); }
#define glNormalStream3dvATI DynamicGL_NormalStream3dvATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClientActiveVertexStreamATI)(GLenum stream); }
#define glClientActiveVertexStreamATI DynamicGL_ClientActiveVertexStreamATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexBlendEnviATI)(GLenum pname , GLint param); }
#define glVertexBlendEnviATI DynamicGL_VertexBlendEnviATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexBlendEnvfATI)(GLenum pname , GLfloat param); }
#define glVertexBlendEnvfATI DynamicGL_VertexBlendEnvfATI
extern bool DinamicGLFeature_ATI_vertex_streams_Supported();
#endif /*USE_DYNAMIC_GL_ATI_vertex_streams*/

/*AMD_depth_clamp_separate*/
#ifdef USE_DYNAMIC_GL_AMD_depth_clamp_separate
#define GL_DEPTH_CLAMP_NEAR_AMD 0x901E
#define GL_DEPTH_CLAMP_FAR_AMD 0x901F
extern bool DinamicGLFeature_AMD_depth_clamp_separate_Supported();
#endif /*USE_DYNAMIC_GL_AMD_depth_clamp_separate*/

/*3DFX_texture_compression_FXT1*/
#ifdef USE_DYNAMIC_GL_3DFX_texture_compression_FXT1
#define GL_COMPRESSED_RGB_FXT1_3DFX 0x86B0
#define GL_COMPRESSED_RGBA_FXT1_3DFX 0x86B1
extern bool DinamicGLFeature_3DFX_texture_compression_FXT1_Supported();
#endif /*USE_DYNAMIC_GL_3DFX_texture_compression_FXT1*/

/*SGIX_shadow_ambient*/
#ifdef USE_DYNAMIC_GL_SGIX_shadow_ambient
#define GL_SHADOW_AMBIENT_SGIX 0x80BF
extern bool DinamicGLFeature_SGIX_shadow_ambient_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_shadow_ambient*/

/*EXT_blend_color*/
#ifdef USE_DYNAMIC_GL_EXT_blend_color
#define GL_CONSTANT_COLOR_EXT 0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR_EXT 0x8002
#define GL_CONSTANT_ALPHA_EXT 0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA_EXT 0x8004
#define GL_BLEND_COLOR_EXT 0x8005
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendColorEXT)(GLfloat red , GLfloat green , GLfloat blue , GLfloat alpha); }
#define glBlendColorEXT DynamicGL_BlendColorEXT
extern bool DinamicGLFeature_EXT_blend_color_Supported();
#endif /*USE_DYNAMIC_GL_EXT_blend_color*/

/*ARB_shadow*/
#ifdef USE_DYNAMIC_GL_ARB_shadow
#define GL_TEXTURE_COMPARE_MODE_ARB 0x884C
#define GL_TEXTURE_COMPARE_FUNC_ARB 0x884D
#define GL_COMPARE_R_TO_TEXTURE_ARB 0x884E
extern bool DinamicGLFeature_ARB_shadow_Supported();
#endif /*USE_DYNAMIC_GL_ARB_shadow*/

/*EXT_stencil_wrap*/
#ifdef USE_DYNAMIC_GL_EXT_stencil_wrap
#define GL_INCR_WRAP_EXT 0x8507
#define GL_DECR_WRAP_EXT 0x8508
extern bool DinamicGLFeature_EXT_stencil_wrap_Supported();
#endif /*USE_DYNAMIC_GL_EXT_stencil_wrap*/

/*NV_vertex_array_range2*/
#ifdef USE_DYNAMIC_GL_NV_vertex_array_range2
#define GL_VERTEX_ARRAY_RANGE_WITHOUT_FLUSH_NV 0x8533
extern bool DinamicGLFeature_NV_vertex_array_range2_Supported();
#endif /*USE_DYNAMIC_GL_NV_vertex_array_range2*/

/*EXT_bgra*/
#ifdef USE_DYNAMIC_GL_EXT_bgra
#define GL_BGR_EXT 0x80E0
#define GL_BGRA_EXT 0x80E1
extern bool DinamicGLFeature_EXT_bgra_Supported();
#endif /*USE_DYNAMIC_GL_EXT_bgra*/

/*ARB_framebuffer_object*/
#ifdef USE_DYNAMIC_GL_ARB_framebuffer_object
#define GL_INVALID_FRAMEBUFFER_OPERATION 0x0506
#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING 0x8210
#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE 0x8211
#define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE 0x8212
#define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE 0x8213
#define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE 0x8214
#define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE 0x8215
#define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE 0x8216
#define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE 0x8217
#define GL_FRAMEBUFFER_DEFAULT 0x8218
#define GL_FRAMEBUFFER_UNDEFINED 0x8219
#define GL_DEPTH_STENCIL_ATTACHMENT 0x821A
#define GL_MAX_RENDERBUFFER_SIZE 0x84E8
#define GL_DEPTH_STENCIL 0x84F9
#define GL_UNSIGNED_INT_24_8 0x84FA
#define GL_DEPTH24_STENCIL8 0x88F0
#define GL_TEXTURE_STENCIL_SIZE 0x88F1
#define GL_TEXTURE_RED_TYPE 0x8C10
#define GL_TEXTURE_GREEN_TYPE 0x8C11
#define GL_TEXTURE_BLUE_TYPE 0x8C12
#define GL_TEXTURE_ALPHA_TYPE 0x8C13
#define GL_TEXTURE_DEPTH_TYPE 0x8C16
#define GL_UNSIGNED_NORMALIZED 0x8C17
#define GL_FRAMEBUFFER_BINDING 0x8CA6
#define GL_RENDERBUFFER_BINDING 0x8CA7
#define GL_READ_FRAMEBUFFER 0x8CA8
#define GL_DRAW_FRAMEBUFFER 0x8CA9
#define GL_READ_FRAMEBUFFER_BINDING 0x8CAA
#define GL_RENDERBUFFER_SAMPLES 0x8CAB
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE 0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME 0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL 0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER 0x8CD4
#define GL_FRAMEBUFFER_COMPLETE 0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER 0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER 0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED 0x8CDD
#define GL_MAX_COLOR_ATTACHMENTS 0x8CDF
#define GL_COLOR_ATTACHMENT0 0x8CE0
#define GL_COLOR_ATTACHMENT1 0x8CE1
#define GL_COLOR_ATTACHMENT2 0x8CE2
#define GL_COLOR_ATTACHMENT3 0x8CE3
#define GL_COLOR_ATTACHMENT4 0x8CE4
#define GL_COLOR_ATTACHMENT5 0x8CE5
#define GL_COLOR_ATTACHMENT6 0x8CE6
#define GL_COLOR_ATTACHMENT7 0x8CE7
#define GL_COLOR_ATTACHMENT8 0x8CE8
#define GL_COLOR_ATTACHMENT9 0x8CE9
#define GL_COLOR_ATTACHMENT10 0x8CEA
#define GL_COLOR_ATTACHMENT11 0x8CEB
#define GL_COLOR_ATTACHMENT12 0x8CEC
#define GL_COLOR_ATTACHMENT13 0x8CED
#define GL_COLOR_ATTACHMENT14 0x8CEE
#define GL_COLOR_ATTACHMENT15 0x8CEF
#define GL_DEPTH_ATTACHMENT 0x8D00
#define GL_STENCIL_ATTACHMENT 0x8D20
#define GL_FRAMEBUFFER 0x8D40
#define GL_RENDERBUFFER 0x8D41
#define GL_RENDERBUFFER_WIDTH 0x8D42
#define GL_RENDERBUFFER_HEIGHT 0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT 0x8D44
#define GL_STENCIL_INDEX1 0x8D46
#define GL_STENCIL_INDEX4 0x8D47
#define GL_STENCIL_INDEX8 0x8D48
#define GL_STENCIL_INDEX16 0x8D49
#define GL_RENDERBUFFER_RED_SIZE 0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE 0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE 0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE 0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE 0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE 0x8D55
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE 0x8D56
#define GL_MAX_SAMPLES 0x8D57
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsRenderbuffer)(GLuint renderbuffer); }
#define glIsRenderbuffer DynamicGL_IsRenderbuffer
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindRenderbuffer)(GLenum target , GLuint renderbuffer); }
#define glBindRenderbuffer DynamicGL_BindRenderbuffer
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteRenderbuffers)(GLsizei n , const GLuint *renderbuffers); }
#define glDeleteRenderbuffers DynamicGL_DeleteRenderbuffers
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GenRenderbuffers)(GLsizei n , GLuint *renderbuffers); }
#define glGenRenderbuffers DynamicGL_GenRenderbuffers
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RenderbufferStorage)(GLenum target , GLenum internalformat , GLsizei width , GLsizei height); }
#define glRenderbufferStorage DynamicGL_RenderbufferStorage
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetRenderbufferParameteriv)(GLenum target , GLenum pname , GLint *params); }
#define glGetRenderbufferParameteriv DynamicGL_GetRenderbufferParameteriv
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsFramebuffer)(GLuint framebuffer); }
#define glIsFramebuffer DynamicGL_IsFramebuffer
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindFramebuffer)(GLenum target , GLuint framebuffer); }
#define glBindFramebuffer DynamicGL_BindFramebuffer
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteFramebuffers)(GLsizei n , const GLuint *framebuffers); }
#define glDeleteFramebuffers DynamicGL_DeleteFramebuffers
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GenFramebuffers)(GLsizei n , GLuint *framebuffers); }
#define glGenFramebuffers DynamicGL_GenFramebuffers
extern "C" { extern GLenum (DYNAMIC_GL_APIENTRYP DynamicGL_CheckFramebufferStatus)(GLenum target); }
#define glCheckFramebufferStatus DynamicGL_CheckFramebufferStatus
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferTexture1D)(GLenum target , GLenum attachment , GLenum textarget , GLuint texture , GLint level); }
#define glFramebufferTexture1D DynamicGL_FramebufferTexture1D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferTexture2D)(GLenum target , GLenum attachment , GLenum textarget , GLuint texture , GLint level); }
#define glFramebufferTexture2D DynamicGL_FramebufferTexture2D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferTexture3D)(GLenum target , GLenum attachment , GLenum textarget , GLuint texture , GLint level , GLint zoffset); }
#define glFramebufferTexture3D DynamicGL_FramebufferTexture3D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferRenderbuffer)(GLenum target , GLenum attachment , GLenum renderbuffertarget , GLuint renderbuffer); }
#define glFramebufferRenderbuffer DynamicGL_FramebufferRenderbuffer
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFramebufferAttachmentParameteriv)(GLenum target , GLenum attachment , GLenum pname , GLint *params); }
#define glGetFramebufferAttachmentParameteriv DynamicGL_GetFramebufferAttachmentParameteriv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GenerateMipmap)(GLenum target); }
#define glGenerateMipmap DynamicGL_GenerateMipmap
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BlitFramebuffer)(GLint srcX0 , GLint srcY0 , GLint srcX1 , GLint srcY1 , GLint dstX0 , GLint dstY0 , GLint dstX1 , GLint dstY1 , GLbitfield mask , GLenum filter); }
#define glBlitFramebuffer DynamicGL_BlitFramebuffer
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RenderbufferStorageMultisample)(GLenum target , GLsizei samples , GLenum internalformat , GLsizei width , GLsizei height); }
#define glRenderbufferStorageMultisample DynamicGL_RenderbufferStorageMultisample
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferTextureLayer)(GLenum target , GLenum attachment , GLuint texture , GLint level , GLint layer); }
#define glFramebufferTextureLayer DynamicGL_FramebufferTextureLayer
extern bool DinamicGLFeature_ARB_framebuffer_object_Supported();
#endif /*USE_DYNAMIC_GL_ARB_framebuffer_object*/

/*SGIX_async*/
#ifdef USE_DYNAMIC_GL_SGIX_async
#define GL_ASYNC_MARKER_SGIX 0x8329
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_AsyncMarkerSGIX)(GLuint marker); }
#define glAsyncMarkerSGIX DynamicGL_AsyncMarkerSGIX
extern "C" { extern GLint (DYNAMIC_GL_APIENTRYP DynamicGL_FinishAsyncSGIX)(GLuint *markerp); }
#define glFinishAsyncSGIX DynamicGL_FinishAsyncSGIX
extern "C" { extern GLint (DYNAMIC_GL_APIENTRYP DynamicGL_PollAsyncSGIX)(GLuint *markerp); }
#define glPollAsyncSGIX DynamicGL_PollAsyncSGIX
extern "C" { extern GLuint (DYNAMIC_GL_APIENTRYP DynamicGL_GenAsyncMarkersSGIX)(GLsizei range); }
#define glGenAsyncMarkersSGIX DynamicGL_GenAsyncMarkersSGIX
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteAsyncMarkersSGIX)(GLuint marker , GLsizei range); }
#define glDeleteAsyncMarkersSGIX DynamicGL_DeleteAsyncMarkersSGIX
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsAsyncMarkerSGIX)(GLuint marker); }
#define glIsAsyncMarkerSGIX DynamicGL_IsAsyncMarkerSGIX
extern bool DinamicGLFeature_SGIX_async_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_async*/

/*ARB_texture_cube_map_array*/
#ifdef USE_DYNAMIC_GL_ARB_texture_cube_map_array
#define GL_TEXTURE_CUBE_MAP_ARRAY_ARB 0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB 0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY_ARB 0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_ARB 0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900F
extern bool DinamicGLFeature_ARB_texture_cube_map_array_Supported();
#endif /*USE_DYNAMIC_GL_ARB_texture_cube_map_array*/

/*NV_path_rendering*/
#ifdef USE_DYNAMIC_GL_NV_path_rendering
#define GL_PATH_FORMAT_SVG_NV 0x9070
#define GL_PATH_FORMAT_PS_NV 0x9071
#define GL_STANDARD_FONT_NAME_NV 0x9072
#define GL_SYSTEM_FONT_NAME_NV 0x9073
#define GL_FILE_NAME_NV 0x9074
#define GL_PATH_STROKE_WIDTH_NV 0x9075
#define GL_PATH_END_CAPS_NV 0x9076
#define GL_PATH_INITIAL_END_CAP_NV 0x9077
#define GL_PATH_TERMINAL_END_CAP_NV 0x9078
#define GL_PATH_JOIN_STYLE_NV 0x9079
#define GL_PATH_MITER_LIMIT_NV 0x907A
#define GL_PATH_DASH_CAPS_NV 0x907B
#define GL_PATH_INITIAL_DASH_CAP_NV 0x907C
#define GL_PATH_TERMINAL_DASH_CAP_NV 0x907D
#define GL_PATH_DASH_OFFSET_NV 0x907E
#define GL_PATH_CLIENT_LENGTH_NV 0x907F
#define GL_PATH_FILL_MODE_NV 0x9080
#define GL_PATH_FILL_MASK_NV 0x9081
#define GL_PATH_FILL_COVER_MODE_NV 0x9082
#define GL_PATH_STROKE_COVER_MODE_NV 0x9083
#define GL_PATH_STROKE_MASK_NV 0x9084
#define GL_PATH_SAMPLE_QUALITY_NV 0x9085
#define GL_PATH_STROKE_BOUND_NV 0x9086
#define GL_PATH_STROKE_OVERSAMPLE_COUNT_NV 0x9087
#define GL_COUNT_UP_NV 0x9088
#define GL_COUNT_DOWN_NV 0x9089
#define GL_PATH_OBJECT_BOUNDING_BOX_NV 0x908A
#define GL_CONVEX_HULL_NV 0x908B
#define GL_MULTI_HULLS_NV 0x908C
#define GL_BOUNDING_BOX_NV 0x908D
#define GL_TRANSLATE_X_NV 0x908E
#define GL_TRANSLATE_Y_NV 0x908F
#define GL_TRANSLATE_2D_NV 0x9090
#define GL_TRANSLATE_3D_NV 0x9091
#define GL_AFFINE_2D_NV 0x9092
#define GL_PROJECTIVE_2D_NV 0x9093
#define GL_AFFINE_3D_NV 0x9094
#define GL_PROJECTIVE_3D_NV 0x9095
#define GL_TRANSPOSE_AFFINE_2D_NV 0x9096
#define GL_TRANSPOSE_PROJECTIVE_2D_NV 0x9097
#define GL_TRANSPOSE_AFFINE_3D_NV 0x9098
#define GL_TRANSPOSE_PROJECTIVE_3D_NV 0x9099
#define GL_UTF8_NV 0x909A
#define GL_UTF16_NV 0x909B
#define GL_BOUNDING_BOX_OF_BOUNDING_BOXES_NV 0x909C
#define GL_PATH_COMMAND_COUNT_NV 0x909D
#define GL_PATH_COORD_COUNT_NV 0x909E
#define GL_PATH_DASH_ARRAY_COUNT_NV 0x909F
#define GL_PATH_COMPUTED_LENGTH_NV 0x90A0
#define GL_PATH_FILL_BOUNDING_BOX_NV 0x90A1
#define GL_PATH_STROKE_BOUNDING_BOX_NV 0x90A2
#define GL_SQUARE_NV 0x90A3
#define GL_ROUND_NV 0x90A4
#define GL_TRIANGULAR_NV 0x90A5
#define GL_BEVEL_NV 0x90A6
#define GL_MITER_REVERT_NV 0x90A7
#define GL_MITER_TRUNCATE_NV 0x90A8
#define GL_SKIP_MISSING_GLYPH_NV 0x90A9
#define GL_USE_MISSING_GLYPH_NV 0x90AA
#define GL_PATH_ERROR_POSITION_NV 0x90AB
#define GL_PATH_FOG_GEN_MODE_NV 0x90AC
#define GL_ACCUM_ADJACENT_PAIRS_NV 0x90AD
#define GL_ADJACENT_PAIRS_NV 0x90AE
#define GL_FIRST_TO_REST_NV 0x90AF
#define GL_PATH_GEN_MODE_NV 0x90B0
#define GL_PATH_GEN_COEFF_NV 0x90B1
#define GL_PATH_GEN_COLOR_FORMAT_NV 0x90B2
#define GL_PATH_GEN_COMPONENTS_NV 0x90B3
#define GL_PATH_STENCIL_FUNC_NV 0x90B7
#define GL_PATH_STENCIL_REF_NV 0x90B8
#define GL_PATH_STENCIL_VALUE_MASK_NV 0x90B9
#define GL_PATH_STENCIL_DEPTH_OFFSET_FACTOR_NV 0x90BD
#define GL_PATH_STENCIL_DEPTH_OFFSET_UNITS_NV 0x90BE
#define GL_PATH_COVER_DEPTH_FUNC_NV 0x90BF
#define GL_PATH_DASH_OFFSET_RESET_NV 0x90B4
#define GL_MOVE_TO_RESETS_NV 0x90B5
#define GL_MOVE_TO_CONTINUES_NV 0x90B6
#define GL_CLOSE_PATH_NV 0x00
#define GL_MOVE_TO_NV 0x02
#define GL_RELATIVE_MOVE_TO_NV 0x03
#define GL_LINE_TO_NV 0x04
#define GL_RELATIVE_LINE_TO_NV 0x05
#define GL_HORIZONTAL_LINE_TO_NV 0x06
#define GL_RELATIVE_HORIZONTAL_LINE_TO_NV 0x07
#define GL_VERTICAL_LINE_TO_NV 0x08
#define GL_RELATIVE_VERTICAL_LINE_TO_NV 0x09
#define GL_QUADRATIC_CURVE_TO_NV 0x0A
#define GL_RELATIVE_QUADRATIC_CURVE_TO_NV 0x0B
#define GL_CUBIC_CURVE_TO_NV 0x0C
#define GL_RELATIVE_CUBIC_CURVE_TO_NV 0x0D
#define GL_SMOOTH_QUADRATIC_CURVE_TO_NV 0x0E
#define GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV 0x0F
#define GL_SMOOTH_CUBIC_CURVE_TO_NV 0x10
#define GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV 0x11
#define GL_SMALL_CCW_ARC_TO_NV 0x12
#define GL_RELATIVE_SMALL_CCW_ARC_TO_NV 0x13
#define GL_SMALL_CW_ARC_TO_NV 0x14
#define GL_RELATIVE_SMALL_CW_ARC_TO_NV 0x15
#define GL_LARGE_CCW_ARC_TO_NV 0x16
#define GL_RELATIVE_LARGE_CCW_ARC_TO_NV 0x17
#define GL_LARGE_CW_ARC_TO_NV 0x18
#define GL_RELATIVE_LARGE_CW_ARC_TO_NV 0x19
#define GL_RESTART_PATH_NV 0xF0
#define GL_DUP_FIRST_CUBIC_CURVE_TO_NV 0xF2
#define GL_DUP_LAST_CUBIC_CURVE_TO_NV 0xF4
#define GL_RECT_NV 0xF6
#define GL_CIRCULAR_CCW_ARC_TO_NV 0xF8
#define GL_CIRCULAR_CW_ARC_TO_NV 0xFA
#define GL_CIRCULAR_TANGENT_ARC_TO_NV 0xFC
#define GL_ARC_TO_NV 0xFE
#define GL_RELATIVE_ARC_TO_NV 0xFF
#define GL_BOLD_BIT_NV 0x01
#define GL_ITALIC_BIT_NV 0x02
#define GL_GLYPH_WIDTH_BIT_NV 0x01
#define GL_GLYPH_HEIGHT_BIT_NV 0x02
#define GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV 0x04
#define GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV 0x08
#define GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV 0x10
#define GL_GLYPH_VERTICAL_BEARING_X_BIT_NV 0x20
#define GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV 0x40
#define GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV 0x80
#define GL_GLYPH_HAS_KERNING_NV 0x100
#define GL_FONT_X_MIN_BOUNDS_NV 0x00010000
#define GL_FONT_Y_MIN_BOUNDS_NV 0x00020000
#define GL_FONT_X_MAX_BOUNDS_NV 0x00040000
#define GL_FONT_Y_MAX_BOUNDS_NV 0x00080000
#define GL_FONT_UNITS_PER_EM_NV 0x00100000
#define GL_FONT_ASCENDER_NV 0x00200000
#define GL_FONT_DESCENDER_NV 0x00400000
#define GL_FONT_HEIGHT_NV 0x00800000
#define GL_FONT_MAX_ADVANCE_WIDTH_NV 0x01000000
#define GL_FONT_MAX_ADVANCE_HEIGHT_NV 0x02000000
#define GL_FONT_UNDERLINE_POSITION_NV 0x04000000
#define GL_FONT_UNDERLINE_THICKNESS_NV 0x08000000
#define GL_FONT_HAS_KERNING_NV 0x10000000
extern "C" { extern GLuint (DYNAMIC_GL_APIENTRYP DynamicGL_GenPathsNV)(GLsizei range); }
#define glGenPathsNV DynamicGL_GenPathsNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeletePathsNV)(GLuint path , GLsizei range); }
#define glDeletePathsNV DynamicGL_DeletePathsNV
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsPathNV)(GLuint path); }
#define glIsPathNV DynamicGL_IsPathNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PathCommandsNV)(GLuint path , GLsizei numCommands , const GLubyte *commands , GLsizei numCoords , GLenum coordType , const GLvoid *coords); }
#define glPathCommandsNV DynamicGL_PathCommandsNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PathCoordsNV)(GLuint path , GLsizei numCoords , GLenum coordType , const GLvoid *coords); }
#define glPathCoordsNV DynamicGL_PathCoordsNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PathSubCommandsNV)(GLuint path , GLsizei commandStart , GLsizei commandsToDelete , GLsizei numCommands , const GLubyte *commands , GLsizei numCoords , GLenum coordType , const GLvoid *coords); }
#define glPathSubCommandsNV DynamicGL_PathSubCommandsNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PathSubCoordsNV)(GLuint path , GLsizei coordStart , GLsizei numCoords , GLenum coordType , const GLvoid *coords); }
#define glPathSubCoordsNV DynamicGL_PathSubCoordsNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PathStringNV)(GLuint path , GLenum format , GLsizei length , const GLvoid *pathString); }
#define glPathStringNV DynamicGL_PathStringNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PathGlyphsNV)(GLuint firstPathName , GLenum fontTarget , const GLvoid *fontName , GLbitfield fontStyle , GLsizei numGlyphs , GLenum type , const GLvoid *charcodes , GLenum handleMissingGlyphs , GLuint pathParameterTemplate , GLfloat emScale); }
#define glPathGlyphsNV DynamicGL_PathGlyphsNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PathGlyphRangeNV)(GLuint firstPathName , GLenum fontTarget , const GLvoid *fontName , GLbitfield fontStyle , GLuint firstGlyph , GLsizei numGlyphs , GLenum handleMissingGlyphs , GLuint pathParameterTemplate , GLfloat emScale); }
#define glPathGlyphRangeNV DynamicGL_PathGlyphRangeNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WeightPathsNV)(GLuint resultPath , GLsizei numPaths , const GLuint *paths , const GLfloat *weights); }
#define glWeightPathsNV DynamicGL_WeightPathsNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyPathNV)(GLuint resultPath , GLuint srcPath); }
#define glCopyPathNV DynamicGL_CopyPathNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_InterpolatePathsNV)(GLuint resultPath , GLuint pathA , GLuint pathB , GLfloat weight); }
#define glInterpolatePathsNV DynamicGL_InterpolatePathsNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TransformPathNV)(GLuint resultPath , GLuint srcPath , GLenum transformType , const GLfloat *transformValues); }
#define glTransformPathNV DynamicGL_TransformPathNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PathParameterivNV)(GLuint path , GLenum pname , const GLint *value); }
#define glPathParameterivNV DynamicGL_PathParameterivNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PathParameteriNV)(GLuint path , GLenum pname , GLint value); }
#define glPathParameteriNV DynamicGL_PathParameteriNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PathParameterfvNV)(GLuint path , GLenum pname , const GLfloat *value); }
#define glPathParameterfvNV DynamicGL_PathParameterfvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PathParameterfNV)(GLuint path , GLenum pname , GLfloat value); }
#define glPathParameterfNV DynamicGL_PathParameterfNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PathDashArrayNV)(GLuint path , GLsizei dashCount , const GLfloat *dashArray); }
#define glPathDashArrayNV DynamicGL_PathDashArrayNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PathStencilFuncNV)(GLenum func , GLint ref , GLuint mask); }
#define glPathStencilFuncNV DynamicGL_PathStencilFuncNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PathStencilDepthOffsetNV)(GLfloat factor , GLfloat units); }
#define glPathStencilDepthOffsetNV DynamicGL_PathStencilDepthOffsetNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_StencilFillPathNV)(GLuint path , GLenum fillMode , GLuint mask); }
#define glStencilFillPathNV DynamicGL_StencilFillPathNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_StencilStrokePathNV)(GLuint path , GLint reference , GLuint mask); }
#define glStencilStrokePathNV DynamicGL_StencilStrokePathNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_StencilFillPathInstancedNV)(GLsizei numPaths , GLenum pathNameType , const GLvoid *paths , GLuint pathBase , GLenum fillMode , GLuint mask , GLenum transformType , const GLfloat *transformValues); }
#define glStencilFillPathInstancedNV DynamicGL_StencilFillPathInstancedNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_StencilStrokePathInstancedNV)(GLsizei numPaths , GLenum pathNameType , const GLvoid *paths , GLuint pathBase , GLint reference , GLuint mask , GLenum transformType , const GLfloat *transformValues); }
#define glStencilStrokePathInstancedNV DynamicGL_StencilStrokePathInstancedNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PathCoverDepthFuncNV)(GLenum func); }
#define glPathCoverDepthFuncNV DynamicGL_PathCoverDepthFuncNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PathColorGenNV)(GLenum color , GLenum genMode , GLenum colorFormat , const GLfloat *coeffs); }
#define glPathColorGenNV DynamicGL_PathColorGenNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PathTexGenNV)(GLenum texCoordSet , GLenum genMode , GLint components , const GLfloat *coeffs); }
#define glPathTexGenNV DynamicGL_PathTexGenNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PathFogGenNV)(GLenum genMode); }
#define glPathFogGenNV DynamicGL_PathFogGenNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CoverFillPathNV)(GLuint path , GLenum coverMode); }
#define glCoverFillPathNV DynamicGL_CoverFillPathNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CoverStrokePathNV)(GLuint path , GLenum coverMode); }
#define glCoverStrokePathNV DynamicGL_CoverStrokePathNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CoverFillPathInstancedNV)(GLsizei numPaths , GLenum pathNameType , const GLvoid *paths , GLuint pathBase , GLenum coverMode , GLenum transformType , const GLfloat *transformValues); }
#define glCoverFillPathInstancedNV DynamicGL_CoverFillPathInstancedNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CoverStrokePathInstancedNV)(GLsizei numPaths , GLenum pathNameType , const GLvoid *paths , GLuint pathBase , GLenum coverMode , GLenum transformType , const GLfloat *transformValues); }
#define glCoverStrokePathInstancedNV DynamicGL_CoverStrokePathInstancedNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPathParameterivNV)(GLuint path , GLenum pname , GLint *value); }
#define glGetPathParameterivNV DynamicGL_GetPathParameterivNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPathParameterfvNV)(GLuint path , GLenum pname , GLfloat *value); }
#define glGetPathParameterfvNV DynamicGL_GetPathParameterfvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPathCommandsNV)(GLuint path , GLubyte *commands); }
#define glGetPathCommandsNV DynamicGL_GetPathCommandsNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPathCoordsNV)(GLuint path , GLfloat *coords); }
#define glGetPathCoordsNV DynamicGL_GetPathCoordsNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPathDashArrayNV)(GLuint path , GLfloat *dashArray); }
#define glGetPathDashArrayNV DynamicGL_GetPathDashArrayNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPathMetricsNV)(GLbitfield metricQueryMask , GLsizei numPaths , GLenum pathNameType , const GLvoid *paths , GLuint pathBase , GLsizei stride , GLfloat *metrics); }
#define glGetPathMetricsNV DynamicGL_GetPathMetricsNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPathMetricRangeNV)(GLbitfield metricQueryMask , GLuint firstPathName , GLsizei numPaths , GLsizei stride , GLfloat *metrics); }
#define glGetPathMetricRangeNV DynamicGL_GetPathMetricRangeNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPathSpacingNV)(GLenum pathListMode , GLsizei numPaths , GLenum pathNameType , const GLvoid *paths , GLuint pathBase , GLfloat advanceScale , GLfloat kerningScale , GLenum transformType , GLfloat *returnedSpacing); }
#define glGetPathSpacingNV DynamicGL_GetPathSpacingNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPathColorGenivNV)(GLenum color , GLenum pname , GLint *value); }
#define glGetPathColorGenivNV DynamicGL_GetPathColorGenivNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPathColorGenfvNV)(GLenum color , GLenum pname , GLfloat *value); }
#define glGetPathColorGenfvNV DynamicGL_GetPathColorGenfvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPathTexGenivNV)(GLenum texCoordSet , GLenum pname , GLint *value); }
#define glGetPathTexGenivNV DynamicGL_GetPathTexGenivNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPathTexGenfvNV)(GLenum texCoordSet , GLenum pname , GLfloat *value); }
#define glGetPathTexGenfvNV DynamicGL_GetPathTexGenfvNV
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsPointInFillPathNV)(GLuint path , GLuint mask , GLfloat x , GLfloat y); }
#define glIsPointInFillPathNV DynamicGL_IsPointInFillPathNV
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsPointInStrokePathNV)(GLuint path , GLfloat x , GLfloat y); }
#define glIsPointInStrokePathNV DynamicGL_IsPointInStrokePathNV
extern "C" { extern GLfloat (DYNAMIC_GL_APIENTRYP DynamicGL_GetPathLengthNV)(GLuint path , GLsizei startSegment , GLsizei numSegments); }
#define glGetPathLengthNV DynamicGL_GetPathLengthNV
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_PointAlongPathNV)(GLuint path , GLsizei startSegment , GLsizei numSegments , GLfloat distance , GLfloat *x , GLfloat *y , GLfloat *tangentX , GLfloat *tangentY); }
#define glPointAlongPathNV DynamicGL_PointAlongPathNV
extern bool DinamicGLFeature_NV_path_rendering_Supported();
#endif /*USE_DYNAMIC_GL_NV_path_rendering*/

/*SGI_texture_color_table*/
#ifdef USE_DYNAMIC_GL_SGI_texture_color_table
#define GL_TEXTURE_COLOR_TABLE_SGI 0x80BC
#define GL_PROXY_TEXTURE_COLOR_TABLE_SGI 0x80BD
extern bool DinamicGLFeature_SGI_texture_color_table_Supported();
#endif /*USE_DYNAMIC_GL_SGI_texture_color_table*/

/*EXT_subtexture*/
#ifdef USE_DYNAMIC_GL_EXT_subtexture
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexSubImage1DEXT)(GLenum target , GLint level , GLint xoffset , GLsizei width , GLenum format , GLenum type , const GLvoid *pixels); }
#define glTexSubImage1DEXT DynamicGL_TexSubImage1DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexSubImage2DEXT)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLsizei width , GLsizei height , GLenum format , GLenum type , const GLvoid *pixels); }
#define glTexSubImage2DEXT DynamicGL_TexSubImage2DEXT
extern bool DinamicGLFeature_EXT_subtexture_Supported();
#endif /*USE_DYNAMIC_GL_EXT_subtexture*/

/*SGIX_subsample*/
#ifdef USE_DYNAMIC_GL_SGIX_subsample
#define GL_PACK_SUBSAMPLE_RATE_SGIX 0x85A0
#define GL_UNPACK_SUBSAMPLE_RATE_SGIX 0x85A1
#define GL_PIXEL_SUBSAMPLE_4444_SGIX 0x85A2
#define GL_PIXEL_SUBSAMPLE_2424_SGIX 0x85A3
#define GL_PIXEL_SUBSAMPLE_4242_SGIX 0x85A4
extern bool DinamicGLFeature_SGIX_subsample_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_subsample*/

/*GREMEDY_string_marker*/
#ifdef USE_DYNAMIC_GL_GREMEDY_string_marker
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_StringMarkerGREMEDY)(GLsizei len , const GLvoid *string); }
#define glStringMarkerGREMEDY DynamicGL_StringMarkerGREMEDY
extern bool DinamicGLFeature_GREMEDY_string_marker_Supported();
#endif /*USE_DYNAMIC_GL_GREMEDY_string_marker*/

/*ARB_draw_instanced*/
#ifdef USE_DYNAMIC_GL_ARB_draw_instanced
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawArraysInstancedARB)(GLenum mode , GLint first , GLsizei count , GLsizei primcount); }
#define glDrawArraysInstancedARB DynamicGL_DrawArraysInstancedARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawElementsInstancedARB)(GLenum mode , GLsizei count , GLenum type , const GLvoid *indices , GLsizei primcount); }
#define glDrawElementsInstancedARB DynamicGL_DrawElementsInstancedARB
extern bool DinamicGLFeature_ARB_draw_instanced_Supported();
#endif /*USE_DYNAMIC_GL_ARB_draw_instanced*/

/*ARB_occlusion_query*/
#ifdef USE_DYNAMIC_GL_ARB_occlusion_query
#define GL_QUERY_COUNTER_BITS_ARB 0x8864
#define GL_CURRENT_QUERY_ARB 0x8865
#define GL_QUERY_RESULT_ARB 0x8866
#define GL_QUERY_RESULT_AVAILABLE_ARB 0x8867
#define GL_SAMPLES_PASSED_ARB 0x8914
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GenQueriesARB)(GLsizei n , GLuint *ids); }
#define glGenQueriesARB DynamicGL_GenQueriesARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteQueriesARB)(GLsizei n , const GLuint *ids); }
#define glDeleteQueriesARB DynamicGL_DeleteQueriesARB
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsQueryARB)(GLuint id); }
#define glIsQueryARB DynamicGL_IsQueryARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BeginQueryARB)(GLenum target , GLuint id); }
#define glBeginQueryARB DynamicGL_BeginQueryARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EndQueryARB)(GLenum target); }
#define glEndQueryARB DynamicGL_EndQueryARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetQueryivARB)(GLenum target , GLenum pname , GLint *params); }
#define glGetQueryivARB DynamicGL_GetQueryivARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetQueryObjectivARB)(GLuint id , GLenum pname , GLint *params); }
#define glGetQueryObjectivARB DynamicGL_GetQueryObjectivARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetQueryObjectuivARB)(GLuint id , GLenum pname , GLuint *params); }
#define glGetQueryObjectuivARB DynamicGL_GetQueryObjectuivARB
extern bool DinamicGLFeature_ARB_occlusion_query_Supported();
#endif /*USE_DYNAMIC_GL_ARB_occlusion_query*/

/*ATI_fragment_shader*/
#ifdef USE_DYNAMIC_GL_ATI_fragment_shader
#define GL_FRAGMENT_SHADER_ATI 0x8920
#define GL_REG_0_ATI 0x8921
#define GL_REG_1_ATI 0x8922
#define GL_REG_2_ATI 0x8923
#define GL_REG_3_ATI 0x8924
#define GL_REG_4_ATI 0x8925
#define GL_REG_5_ATI 0x8926
#define GL_REG_6_ATI 0x8927
#define GL_REG_7_ATI 0x8928
#define GL_REG_8_ATI 0x8929
#define GL_REG_9_ATI 0x892A
#define GL_REG_10_ATI 0x892B
#define GL_REG_11_ATI 0x892C
#define GL_REG_12_ATI 0x892D
#define GL_REG_13_ATI 0x892E
#define GL_REG_14_ATI 0x892F
#define GL_REG_15_ATI 0x8930
#define GL_REG_16_ATI 0x8931
#define GL_REG_17_ATI 0x8932
#define GL_REG_18_ATI 0x8933
#define GL_REG_19_ATI 0x8934
#define GL_REG_20_ATI 0x8935
#define GL_REG_21_ATI 0x8936
#define GL_REG_22_ATI 0x8937
#define GL_REG_23_ATI 0x8938
#define GL_REG_24_ATI 0x8939
#define GL_REG_25_ATI 0x893A
#define GL_REG_26_ATI 0x893B
#define GL_REG_27_ATI 0x893C
#define GL_REG_28_ATI 0x893D
#define GL_REG_29_ATI 0x893E
#define GL_REG_30_ATI 0x893F
#define GL_REG_31_ATI 0x8940
#define GL_CON_0_ATI 0x8941
#define GL_CON_1_ATI 0x8942
#define GL_CON_2_ATI 0x8943
#define GL_CON_3_ATI 0x8944
#define GL_CON_4_ATI 0x8945
#define GL_CON_5_ATI 0x8946
#define GL_CON_6_ATI 0x8947
#define GL_CON_7_ATI 0x8948
#define GL_CON_8_ATI 0x8949
#define GL_CON_9_ATI 0x894A
#define GL_CON_10_ATI 0x894B
#define GL_CON_11_ATI 0x894C
#define GL_CON_12_ATI 0x894D
#define GL_CON_13_ATI 0x894E
#define GL_CON_14_ATI 0x894F
#define GL_CON_15_ATI 0x8950
#define GL_CON_16_ATI 0x8951
#define GL_CON_17_ATI 0x8952
#define GL_CON_18_ATI 0x8953
#define GL_CON_19_ATI 0x8954
#define GL_CON_20_ATI 0x8955
#define GL_CON_21_ATI 0x8956
#define GL_CON_22_ATI 0x8957
#define GL_CON_23_ATI 0x8958
#define GL_CON_24_ATI 0x8959
#define GL_CON_25_ATI 0x895A
#define GL_CON_26_ATI 0x895B
#define GL_CON_27_ATI 0x895C
#define GL_CON_28_ATI 0x895D
#define GL_CON_29_ATI 0x895E
#define GL_CON_30_ATI 0x895F
#define GL_CON_31_ATI 0x8960
#define GL_MOV_ATI 0x8961
#define GL_ADD_ATI 0x8963
#define GL_MUL_ATI 0x8964
#define GL_SUB_ATI 0x8965
#define GL_DOT3_ATI 0x8966
#define GL_DOT4_ATI 0x8967
#define GL_MAD_ATI 0x8968
#define GL_LERP_ATI 0x8969
#define GL_CND_ATI 0x896A
#define GL_CND0_ATI 0x896B
#define GL_DOT2_ADD_ATI 0x896C
#define GL_SECONDARY_INTERPOLATOR_ATI 0x896D
#define GL_NUM_FRAGMENT_REGISTERS_ATI 0x896E
#define GL_NUM_FRAGMENT_CONSTANTS_ATI 0x896F
#define GL_NUM_PASSES_ATI 0x8970
#define GL_NUM_INSTRUCTIONS_PER_PASS_ATI 0x8971
#define GL_NUM_INSTRUCTIONS_TOTAL_ATI 0x8972
#define GL_NUM_INPUT_INTERPOLATOR_COMPONENTS_ATI 0x8973
#define GL_NUM_LOOPBACK_COMPONENTS_ATI 0x8974
#define GL_COLOR_ALPHA_PAIRING_ATI 0x8975
#define GL_SWIZZLE_STR_ATI 0x8976
#define GL_SWIZZLE_STQ_ATI 0x8977
#define GL_SWIZZLE_STR_DR_ATI 0x8978
#define GL_SWIZZLE_STQ_DQ_ATI 0x8979
#define GL_SWIZZLE_STRQ_ATI 0x897A
#define GL_SWIZZLE_STRQ_DQ_ATI 0x897B
#define GL_RED_BIT_ATI 0x00000001
#define GL_GREEN_BIT_ATI 0x00000002
#define GL_BLUE_BIT_ATI 0x00000004
#define GL_2X_BIT_ATI 0x00000001
#define GL_4X_BIT_ATI 0x00000002
#define GL_8X_BIT_ATI 0x00000004
#define GL_HALF_BIT_ATI 0x00000008
#define GL_QUARTER_BIT_ATI 0x00000010
#define GL_EIGHTH_BIT_ATI 0x00000020
#define GL_SATURATE_BIT_ATI 0x00000040
#define GL_COMP_BIT_ATI 0x00000002
#define GL_NEGATE_BIT_ATI 0x00000004
#define GL_BIAS_BIT_ATI 0x00000008
extern "C" { extern GLuint (DYNAMIC_GL_APIENTRYP DynamicGL_GenFragmentShadersATI)(GLuint range); }
#define glGenFragmentShadersATI DynamicGL_GenFragmentShadersATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindFragmentShaderATI)(GLuint id); }
#define glBindFragmentShaderATI DynamicGL_BindFragmentShaderATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteFragmentShaderATI)(GLuint id); }
#define glDeleteFragmentShaderATI DynamicGL_DeleteFragmentShaderATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BeginFragmentShaderATI)(); }
#define glBeginFragmentShaderATI DynamicGL_BeginFragmentShaderATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EndFragmentShaderATI)(); }
#define glEndFragmentShaderATI DynamicGL_EndFragmentShaderATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PassTexCoordATI)(GLuint dst , GLuint coord , GLenum swizzle); }
#define glPassTexCoordATI DynamicGL_PassTexCoordATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SampleMapATI)(GLuint dst , GLuint interp , GLenum swizzle); }
#define glSampleMapATI DynamicGL_SampleMapATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorFragmentOp1ATI)(GLenum op , GLuint dst , GLuint dstMask , GLuint dstMod , GLuint arg1 , GLuint arg1Rep , GLuint arg1Mod); }
#define glColorFragmentOp1ATI DynamicGL_ColorFragmentOp1ATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorFragmentOp2ATI)(GLenum op , GLuint dst , GLuint dstMask , GLuint dstMod , GLuint arg1 , GLuint arg1Rep , GLuint arg1Mod , GLuint arg2 , GLuint arg2Rep , GLuint arg2Mod); }
#define glColorFragmentOp2ATI DynamicGL_ColorFragmentOp2ATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorFragmentOp3ATI)(GLenum op , GLuint dst , GLuint dstMask , GLuint dstMod , GLuint arg1 , GLuint arg1Rep , GLuint arg1Mod , GLuint arg2 , GLuint arg2Rep , GLuint arg2Mod , GLuint arg3 , GLuint arg3Rep , GLuint arg3Mod); }
#define glColorFragmentOp3ATI DynamicGL_ColorFragmentOp3ATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_AlphaFragmentOp1ATI)(GLenum op , GLuint dst , GLuint dstMod , GLuint arg1 , GLuint arg1Rep , GLuint arg1Mod); }
#define glAlphaFragmentOp1ATI DynamicGL_AlphaFragmentOp1ATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_AlphaFragmentOp2ATI)(GLenum op , GLuint dst , GLuint dstMod , GLuint arg1 , GLuint arg1Rep , GLuint arg1Mod , GLuint arg2 , GLuint arg2Rep , GLuint arg2Mod); }
#define glAlphaFragmentOp2ATI DynamicGL_AlphaFragmentOp2ATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_AlphaFragmentOp3ATI)(GLenum op , GLuint dst , GLuint dstMod , GLuint arg1 , GLuint arg1Rep , GLuint arg1Mod , GLuint arg2 , GLuint arg2Rep , GLuint arg2Mod , GLuint arg3 , GLuint arg3Rep , GLuint arg3Mod); }
#define glAlphaFragmentOp3ATI DynamicGL_AlphaFragmentOp3ATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SetFragmentShaderConstantATI)(GLuint dst , const GLfloat *value); }
#define glSetFragmentShaderConstantATI DynamicGL_SetFragmentShaderConstantATI
extern bool DinamicGLFeature_ATI_fragment_shader_Supported();
#endif /*USE_DYNAMIC_GL_ATI_fragment_shader*/

/*NV_depth_buffer_float*/
#ifdef USE_DYNAMIC_GL_NV_depth_buffer_float
#define GL_DEPTH_COMPONENT32F_NV 0x8DAB
#define GL_DEPTH32F_STENCIL8_NV 0x8DAC
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV_NV 0x8DAD
#define GL_DEPTH_BUFFER_FLOAT_MODE_NV 0x8DAF
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DepthRangedNV)(GLdouble zNear , GLdouble zFar); }
#define glDepthRangedNV DynamicGL_DepthRangedNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearDepthdNV)(GLdouble depth); }
#define glClearDepthdNV DynamicGL_ClearDepthdNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DepthBoundsdNV)(GLdouble zmin , GLdouble zmax); }
#define glDepthBoundsdNV DynamicGL_DepthBoundsdNV
extern bool DinamicGLFeature_NV_depth_buffer_float_Supported();
#endif /*USE_DYNAMIC_GL_NV_depth_buffer_float*/

/*NV_pixel_data_range*/
#ifdef USE_DYNAMIC_GL_NV_pixel_data_range
#define GL_WRITE_PIXEL_DATA_RANGE_NV 0x8878
#define GL_READ_PIXEL_DATA_RANGE_NV 0x8879
#define GL_WRITE_PIXEL_DATA_RANGE_LENGTH_NV 0x887A
#define GL_READ_PIXEL_DATA_RANGE_LENGTH_NV 0x887B
#define GL_WRITE_PIXEL_DATA_RANGE_POINTER_NV 0x887C
#define GL_READ_PIXEL_DATA_RANGE_POINTER_NV 0x887D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelDataRangeNV)(GLenum target , GLsizei length , GLvoid *pointer); }
#define glPixelDataRangeNV DynamicGL_PixelDataRangeNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FlushPixelDataRangeNV)(GLenum target); }
#define glFlushPixelDataRangeNV DynamicGL_FlushPixelDataRangeNV
extern bool DinamicGLFeature_NV_pixel_data_range_Supported();
#endif /*USE_DYNAMIC_GL_NV_pixel_data_range*/

/*SGI_color_matrix*/
#ifdef USE_DYNAMIC_GL_SGI_color_matrix
#define GL_COLOR_MATRIX_SGI 0x80B1
#define GL_COLOR_MATRIX_STACK_DEPTH_SGI 0x80B2
#define GL_MAX_COLOR_MATRIX_STACK_DEPTH_SGI 0x80B3
#define GL_POST_COLOR_MATRIX_RED_SCALE_SGI 0x80B4
#define GL_POST_COLOR_MATRIX_GREEN_SCALE_SGI 0x80B5
#define GL_POST_COLOR_MATRIX_BLUE_SCALE_SGI 0x80B6
#define GL_POST_COLOR_MATRIX_ALPHA_SCALE_SGI 0x80B7
#define GL_POST_COLOR_MATRIX_RED_BIAS_SGI 0x80B8
#define GL_POST_COLOR_MATRIX_GREEN_BIAS_SGI 0x80B9
#define GL_POST_COLOR_MATRIX_BLUE_BIAS_SGI 0x80BA
#define GL_POST_COLOR_MATRIX_ALPHA_BIAS_SGI 0x80BB
extern bool DinamicGLFeature_SGI_color_matrix_Supported();
#endif /*USE_DYNAMIC_GL_SGI_color_matrix*/

/*EXT_x11_sync_object*/
#ifdef USE_DYNAMIC_GL_EXT_x11_sync_object
#define GL_SYNC_X11_FENCE_EXT 0x90E1
extern "C" { extern GLsync (DYNAMIC_GL_APIENTRYP DynamicGL_ImportSyncEXT)(GLenum external_sync_type , GLintptr external_sync , GLbitfield flags); }
#define glImportSyncEXT DynamicGL_ImportSyncEXT
extern bool DinamicGLFeature_EXT_x11_sync_object_Supported();
#endif /*USE_DYNAMIC_GL_EXT_x11_sync_object*/

/*EXT_texture_sRGB*/
#ifdef USE_DYNAMIC_GL_EXT_texture_sRGB
#define GL_SRGB_EXT 0x8C40
#define GL_SRGB8_EXT 0x8C41
#define GL_SRGB_ALPHA_EXT 0x8C42
#define GL_SRGB8_ALPHA8_EXT 0x8C43
#define GL_SLUMINANCE_ALPHA_EXT 0x8C44
#define GL_SLUMINANCE8_ALPHA8_EXT 0x8C45
#define GL_SLUMINANCE_EXT 0x8C46
#define GL_SLUMINANCE8_EXT 0x8C47
#define GL_COMPRESSED_SRGB_EXT 0x8C48
#define GL_COMPRESSED_SRGB_ALPHA_EXT 0x8C49
#define GL_COMPRESSED_SLUMINANCE_EXT 0x8C4A
#define GL_COMPRESSED_SLUMINANCE_ALPHA_EXT 0x8C4B
#define GL_COMPRESSED_SRGB_S3TC_DXT1_EXT 0x8C4C
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT 0x8C4D
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT 0x8C4E
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT 0x8C4F
extern bool DinamicGLFeature_EXT_texture_sRGB_Supported();
#endif /*USE_DYNAMIC_GL_EXT_texture_sRGB*/

/*NV_depth_clamp*/
#ifdef USE_DYNAMIC_GL_NV_depth_clamp
#define GL_DEPTH_CLAMP_NV 0x864F
extern bool DinamicGLFeature_NV_depth_clamp_Supported();
#endif /*USE_DYNAMIC_GL_NV_depth_clamp*/

/*ARB_ES2_compatibility*/
#ifdef USE_DYNAMIC_GL_ARB_ES2_compatibility
#define GL_FIXED 0x140C
#define GL_IMPLEMENTATION_COLOR_READ_TYPE 0x8B9A
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT 0x8B9B
#define GL_LOW_FLOAT 0x8DF0
#define GL_MEDIUM_FLOAT 0x8DF1
#define GL_HIGH_FLOAT 0x8DF2
#define GL_LOW_INT 0x8DF3
#define GL_MEDIUM_INT 0x8DF4
#define GL_HIGH_INT 0x8DF5
#define GL_SHADER_COMPILER 0x8DFA
#define GL_NUM_SHADER_BINARY_FORMATS 0x8DF9
#define GL_MAX_VERTEX_UNIFORM_VECTORS 0x8DFB
#define GL_MAX_VARYING_VECTORS 0x8DFC
#define GL_MAX_FRAGMENT_UNIFORM_VECTORS 0x8DFD
#define GL_RGB565 0x8D62
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ReleaseShaderCompiler)(); }
#define glReleaseShaderCompiler DynamicGL_ReleaseShaderCompiler
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ShaderBinary)(GLsizei count , const GLuint *shaders , GLenum binaryformat , const GLvoid *binary , GLsizei length); }
#define glShaderBinary DynamicGL_ShaderBinary
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetShaderPrecisionFormat)(GLenum shadertype , GLenum precisiontype , GLint *range , GLint *precision); }
#define glGetShaderPrecisionFormat DynamicGL_GetShaderPrecisionFormat
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DepthRangef)(GLfloat n , GLfloat f); }
#define glDepthRangef DynamicGL_DepthRangef
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearDepthf)(GLfloat d); }
#define glClearDepthf DynamicGL_ClearDepthf
extern bool DinamicGLFeature_ARB_ES2_compatibility_Supported();
#endif /*USE_DYNAMIC_GL_ARB_ES2_compatibility*/

/*APPLE_aux_depth_stencil*/
#ifdef USE_DYNAMIC_GL_APPLE_aux_depth_stencil
#define GL_AUX_DEPTH_STENCIL_APPLE 0x8A14
extern bool DinamicGLFeature_APPLE_aux_depth_stencil_Supported();
#endif /*USE_DYNAMIC_GL_APPLE_aux_depth_stencil*/

/*AMD_performance_monitor*/
#ifdef USE_DYNAMIC_GL_AMD_performance_monitor
#define GL_COUNTER_TYPE_AMD 0x8BC0
#define GL_COUNTER_RANGE_AMD 0x8BC1
#define GL_UNSIGNED_INT64_AMD 0x8BC2
#define GL_PERCENTAGE_AMD 0x8BC3
#define GL_PERFMON_RESULT_AVAILABLE_AMD 0x8BC4
#define GL_PERFMON_RESULT_SIZE_AMD 0x8BC5
#define GL_PERFMON_RESULT_AMD 0x8BC6
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPerfMonitorGroupsAMD)(GLint *numGroups , GLsizei groupsSize , GLuint *groups); }
#define glGetPerfMonitorGroupsAMD DynamicGL_GetPerfMonitorGroupsAMD
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPerfMonitorCountersAMD)(GLuint group , GLint *numCounters , GLint *maxActiveCounters , GLsizei counterSize , GLuint *counters); }
#define glGetPerfMonitorCountersAMD DynamicGL_GetPerfMonitorCountersAMD
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPerfMonitorGroupStringAMD)(GLuint group , GLsizei bufSize , GLsizei *length , GLchar *groupString); }
#define glGetPerfMonitorGroupStringAMD DynamicGL_GetPerfMonitorGroupStringAMD
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPerfMonitorCounterStringAMD)(GLuint group , GLuint counter , GLsizei bufSize , GLsizei *length , GLchar *counterString); }
#define glGetPerfMonitorCounterStringAMD DynamicGL_GetPerfMonitorCounterStringAMD
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPerfMonitorCounterInfoAMD)(GLuint group , GLuint counter , GLenum pname , GLvoid *data); }
#define glGetPerfMonitorCounterInfoAMD DynamicGL_GetPerfMonitorCounterInfoAMD
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GenPerfMonitorsAMD)(GLsizei n , GLuint *monitors); }
#define glGenPerfMonitorsAMD DynamicGL_GenPerfMonitorsAMD
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeletePerfMonitorsAMD)(GLsizei n , GLuint *monitors); }
#define glDeletePerfMonitorsAMD DynamicGL_DeletePerfMonitorsAMD
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SelectPerfMonitorCountersAMD)(GLuint monitor , GLboolean enable , GLuint group , GLint numCounters , GLuint *counterList); }
#define glSelectPerfMonitorCountersAMD DynamicGL_SelectPerfMonitorCountersAMD
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BeginPerfMonitorAMD)(GLuint monitor); }
#define glBeginPerfMonitorAMD DynamicGL_BeginPerfMonitorAMD
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EndPerfMonitorAMD)(GLuint monitor); }
#define glEndPerfMonitorAMD DynamicGL_EndPerfMonitorAMD
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPerfMonitorCounterDataAMD)(GLuint monitor , GLenum pname , GLsizei dataSize , GLuint *data , GLint *bytesWritten); }
#define glGetPerfMonitorCounterDataAMD DynamicGL_GetPerfMonitorCounterDataAMD
extern bool DinamicGLFeature_AMD_performance_monitor_Supported();
#endif /*USE_DYNAMIC_GL_AMD_performance_monitor*/

/*ARB_half_float_vertex*/
#ifdef USE_DYNAMIC_GL_ARB_half_float_vertex
#define GL_HALF_FLOAT 0x140B
extern bool DinamicGLFeature_ARB_half_float_vertex_Supported();
#endif /*USE_DYNAMIC_GL_ARB_half_float_vertex*/

/*NV_vertex_program*/
#ifdef USE_DYNAMIC_GL_NV_vertex_program
#define GL_VERTEX_PROGRAM_NV 0x8620
#define GL_VERTEX_STATE_PROGRAM_NV 0x8621
#define GL_ATTRIB_ARRAY_SIZE_NV 0x8623
#define GL_ATTRIB_ARRAY_STRIDE_NV 0x8624
#define GL_ATTRIB_ARRAY_TYPE_NV 0x8625
#define GL_CURRENT_ATTRIB_NV 0x8626
#define GL_PROGRAM_LENGTH_NV 0x8627
#define GL_PROGRAM_STRING_NV 0x8628
#define GL_MODELVIEW_PROJECTION_NV 0x8629
#define GL_IDENTITY_NV 0x862A
#define GL_INVERSE_NV 0x862B
#define GL_TRANSPOSE_NV 0x862C
#define GL_INVERSE_TRANSPOSE_NV 0x862D
#define GL_MAX_TRACK_MATRIX_STACK_DEPTH_NV 0x862E
#define GL_MAX_TRACK_MATRICES_NV 0x862F
#define GL_MATRIX0_NV 0x8630
#define GL_MATRIX1_NV 0x8631
#define GL_MATRIX2_NV 0x8632
#define GL_MATRIX3_NV 0x8633
#define GL_MATRIX4_NV 0x8634
#define GL_MATRIX5_NV 0x8635
#define GL_MATRIX6_NV 0x8636
#define GL_MATRIX7_NV 0x8637
#define GL_CURRENT_MATRIX_STACK_DEPTH_NV 0x8640
#define GL_CURRENT_MATRIX_NV 0x8641
#define GL_VERTEX_PROGRAM_POINT_SIZE_NV 0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE_NV 0x8643
#define GL_PROGRAM_PARAMETER_NV 0x8644
#define GL_ATTRIB_ARRAY_POINTER_NV 0x8645
#define GL_PROGRAM_TARGET_NV 0x8646
#define GL_PROGRAM_RESIDENT_NV 0x8647
#define GL_TRACK_MATRIX_NV 0x8648
#define GL_TRACK_MATRIX_TRANSFORM_NV 0x8649
#define GL_VERTEX_PROGRAM_BINDING_NV 0x864A
#define GL_PROGRAM_ERROR_POSITION_NV 0x864B
#define GL_VERTEX_ATTRIB_ARRAY0_NV 0x8650
#define GL_VERTEX_ATTRIB_ARRAY1_NV 0x8651
#define GL_VERTEX_ATTRIB_ARRAY2_NV 0x8652
#define GL_VERTEX_ATTRIB_ARRAY3_NV 0x8653
#define GL_VERTEX_ATTRIB_ARRAY4_NV 0x8654
#define GL_VERTEX_ATTRIB_ARRAY5_NV 0x8655
#define GL_VERTEX_ATTRIB_ARRAY6_NV 0x8656
#define GL_VERTEX_ATTRIB_ARRAY7_NV 0x8657
#define GL_VERTEX_ATTRIB_ARRAY8_NV 0x8658
#define GL_VERTEX_ATTRIB_ARRAY9_NV 0x8659
#define GL_VERTEX_ATTRIB_ARRAY10_NV 0x865A
#define GL_VERTEX_ATTRIB_ARRAY11_NV 0x865B
#define GL_VERTEX_ATTRIB_ARRAY12_NV 0x865C
#define GL_VERTEX_ATTRIB_ARRAY13_NV 0x865D
#define GL_VERTEX_ATTRIB_ARRAY14_NV 0x865E
#define GL_VERTEX_ATTRIB_ARRAY15_NV 0x865F
#define GL_MAP1_VERTEX_ATTRIB0_4_NV 0x8660
#define GL_MAP1_VERTEX_ATTRIB1_4_NV 0x8661
#define GL_MAP1_VERTEX_ATTRIB2_4_NV 0x8662
#define GL_MAP1_VERTEX_ATTRIB3_4_NV 0x8663
#define GL_MAP1_VERTEX_ATTRIB4_4_NV 0x8664
#define GL_MAP1_VERTEX_ATTRIB5_4_NV 0x8665
#define GL_MAP1_VERTEX_ATTRIB6_4_NV 0x8666
#define GL_MAP1_VERTEX_ATTRIB7_4_NV 0x8667
#define GL_MAP1_VERTEX_ATTRIB8_4_NV 0x8668
#define GL_MAP1_VERTEX_ATTRIB9_4_NV 0x8669
#define GL_MAP1_VERTEX_ATTRIB10_4_NV 0x866A
#define GL_MAP1_VERTEX_ATTRIB11_4_NV 0x866B
#define GL_MAP1_VERTEX_ATTRIB12_4_NV 0x866C
#define GL_MAP1_VERTEX_ATTRIB13_4_NV 0x866D
#define GL_MAP1_VERTEX_ATTRIB14_4_NV 0x866E
#define GL_MAP1_VERTEX_ATTRIB15_4_NV 0x866F
#define GL_MAP2_VERTEX_ATTRIB0_4_NV 0x8670
#define GL_MAP2_VERTEX_ATTRIB1_4_NV 0x8671
#define GL_MAP2_VERTEX_ATTRIB2_4_NV 0x8672
#define GL_MAP2_VERTEX_ATTRIB3_4_NV 0x8673
#define GL_MAP2_VERTEX_ATTRIB4_4_NV 0x8674
#define GL_MAP2_VERTEX_ATTRIB5_4_NV 0x8675
#define GL_MAP2_VERTEX_ATTRIB6_4_NV 0x8676
#define GL_MAP2_VERTEX_ATTRIB7_4_NV 0x8677
#define GL_MAP2_VERTEX_ATTRIB8_4_NV 0x8678
#define GL_MAP2_VERTEX_ATTRIB9_4_NV 0x8679
#define GL_MAP2_VERTEX_ATTRIB10_4_NV 0x867A
#define GL_MAP2_VERTEX_ATTRIB11_4_NV 0x867B
#define GL_MAP2_VERTEX_ATTRIB12_4_NV 0x867C
#define GL_MAP2_VERTEX_ATTRIB13_4_NV 0x867D
#define GL_MAP2_VERTEX_ATTRIB14_4_NV 0x867E
#define GL_MAP2_VERTEX_ATTRIB15_4_NV 0x867F
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_AreProgramsResidentNV)(GLsizei n , const GLuint *programs , GLboolean *residences); }
#define glAreProgramsResidentNV DynamicGL_AreProgramsResidentNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindProgramNV)(GLenum target , GLuint id); }
#define glBindProgramNV DynamicGL_BindProgramNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteProgramsNV)(GLsizei n , const GLuint *programs); }
#define glDeleteProgramsNV DynamicGL_DeleteProgramsNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ExecuteProgramNV)(GLenum target , GLuint id , const GLfloat *params); }
#define glExecuteProgramNV DynamicGL_ExecuteProgramNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GenProgramsNV)(GLsizei n , GLuint *programs); }
#define glGenProgramsNV DynamicGL_GenProgramsNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramParameterdvNV)(GLenum target , GLuint index , GLenum pname , GLdouble *params); }
#define glGetProgramParameterdvNV DynamicGL_GetProgramParameterdvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramParameterfvNV)(GLenum target , GLuint index , GLenum pname , GLfloat *params); }
#define glGetProgramParameterfvNV DynamicGL_GetProgramParameterfvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramivNV)(GLuint id , GLenum pname , GLint *params); }
#define glGetProgramivNV DynamicGL_GetProgramivNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramStringNV)(GLuint id , GLenum pname , GLubyte *program); }
#define glGetProgramStringNV DynamicGL_GetProgramStringNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTrackMatrixivNV)(GLenum target , GLuint address , GLenum pname , GLint *params); }
#define glGetTrackMatrixivNV DynamicGL_GetTrackMatrixivNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribdvNV)(GLuint index , GLenum pname , GLdouble *params); }
#define glGetVertexAttribdvNV DynamicGL_GetVertexAttribdvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribfvNV)(GLuint index , GLenum pname , GLfloat *params); }
#define glGetVertexAttribfvNV DynamicGL_GetVertexAttribfvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribivNV)(GLuint index , GLenum pname , GLint *params); }
#define glGetVertexAttribivNV DynamicGL_GetVertexAttribivNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribPointervNV)(GLuint index , GLenum pname , GLvoid* *pointer); }
#define glGetVertexAttribPointervNV DynamicGL_GetVertexAttribPointervNV
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsProgramNV)(GLuint id); }
#define glIsProgramNV DynamicGL_IsProgramNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LoadProgramNV)(GLenum target , GLuint id , GLsizei len , const GLubyte *program); }
#define glLoadProgramNV DynamicGL_LoadProgramNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramParameter4dNV)(GLenum target , GLuint index , GLdouble x , GLdouble y , GLdouble z , GLdouble w); }
#define glProgramParameter4dNV DynamicGL_ProgramParameter4dNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramParameter4dvNV)(GLenum target , GLuint index , const GLdouble *v); }
#define glProgramParameter4dvNV DynamicGL_ProgramParameter4dvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramParameter4fNV)(GLenum target , GLuint index , GLfloat x , GLfloat y , GLfloat z , GLfloat w); }
#define glProgramParameter4fNV DynamicGL_ProgramParameter4fNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramParameter4fvNV)(GLenum target , GLuint index , const GLfloat *v); }
#define glProgramParameter4fvNV DynamicGL_ProgramParameter4fvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramParameters4dvNV)(GLenum target , GLuint index , GLsizei count , const GLdouble *v); }
#define glProgramParameters4dvNV DynamicGL_ProgramParameters4dvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramParameters4fvNV)(GLenum target , GLuint index , GLsizei count , const GLfloat *v); }
#define glProgramParameters4fvNV DynamicGL_ProgramParameters4fvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RequestResidentProgramsNV)(GLsizei n , const GLuint *programs); }
#define glRequestResidentProgramsNV DynamicGL_RequestResidentProgramsNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TrackMatrixNV)(GLenum target , GLuint address , GLenum matrix , GLenum transform); }
#define glTrackMatrixNV DynamicGL_TrackMatrixNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribPointerNV)(GLuint index , GLint fsize , GLenum type , GLsizei stride , const GLvoid *pointer); }
#define glVertexAttribPointerNV DynamicGL_VertexAttribPointerNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1dNV)(GLuint index , GLdouble x); }
#define glVertexAttrib1dNV DynamicGL_VertexAttrib1dNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1dvNV)(GLuint index , const GLdouble *v); }
#define glVertexAttrib1dvNV DynamicGL_VertexAttrib1dvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1fNV)(GLuint index , GLfloat x); }
#define glVertexAttrib1fNV DynamicGL_VertexAttrib1fNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1fvNV)(GLuint index , const GLfloat *v); }
#define glVertexAttrib1fvNV DynamicGL_VertexAttrib1fvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1sNV)(GLuint index , GLshort x); }
#define glVertexAttrib1sNV DynamicGL_VertexAttrib1sNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1svNV)(GLuint index , const GLshort *v); }
#define glVertexAttrib1svNV DynamicGL_VertexAttrib1svNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2dNV)(GLuint index , GLdouble x , GLdouble y); }
#define glVertexAttrib2dNV DynamicGL_VertexAttrib2dNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2dvNV)(GLuint index , const GLdouble *v); }
#define glVertexAttrib2dvNV DynamicGL_VertexAttrib2dvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2fNV)(GLuint index , GLfloat x , GLfloat y); }
#define glVertexAttrib2fNV DynamicGL_VertexAttrib2fNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2fvNV)(GLuint index , const GLfloat *v); }
#define glVertexAttrib2fvNV DynamicGL_VertexAttrib2fvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2sNV)(GLuint index , GLshort x , GLshort y); }
#define glVertexAttrib2sNV DynamicGL_VertexAttrib2sNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2svNV)(GLuint index , const GLshort *v); }
#define glVertexAttrib2svNV DynamicGL_VertexAttrib2svNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3dNV)(GLuint index , GLdouble x , GLdouble y , GLdouble z); }
#define glVertexAttrib3dNV DynamicGL_VertexAttrib3dNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3dvNV)(GLuint index , const GLdouble *v); }
#define glVertexAttrib3dvNV DynamicGL_VertexAttrib3dvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3fNV)(GLuint index , GLfloat x , GLfloat y , GLfloat z); }
#define glVertexAttrib3fNV DynamicGL_VertexAttrib3fNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3fvNV)(GLuint index , const GLfloat *v); }
#define glVertexAttrib3fvNV DynamicGL_VertexAttrib3fvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3sNV)(GLuint index , GLshort x , GLshort y , GLshort z); }
#define glVertexAttrib3sNV DynamicGL_VertexAttrib3sNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3svNV)(GLuint index , const GLshort *v); }
#define glVertexAttrib3svNV DynamicGL_VertexAttrib3svNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4dNV)(GLuint index , GLdouble x , GLdouble y , GLdouble z , GLdouble w); }
#define glVertexAttrib4dNV DynamicGL_VertexAttrib4dNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4dvNV)(GLuint index , const GLdouble *v); }
#define glVertexAttrib4dvNV DynamicGL_VertexAttrib4dvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4fNV)(GLuint index , GLfloat x , GLfloat y , GLfloat z , GLfloat w); }
#define glVertexAttrib4fNV DynamicGL_VertexAttrib4fNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4fvNV)(GLuint index , const GLfloat *v); }
#define glVertexAttrib4fvNV DynamicGL_VertexAttrib4fvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4sNV)(GLuint index , GLshort x , GLshort y , GLshort z , GLshort w); }
#define glVertexAttrib4sNV DynamicGL_VertexAttrib4sNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4svNV)(GLuint index , const GLshort *v); }
#define glVertexAttrib4svNV DynamicGL_VertexAttrib4svNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4ubNV)(GLuint index , GLubyte x , GLubyte y , GLubyte z , GLubyte w); }
#define glVertexAttrib4ubNV DynamicGL_VertexAttrib4ubNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4ubvNV)(GLuint index , const GLubyte *v); }
#define glVertexAttrib4ubvNV DynamicGL_VertexAttrib4ubvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribs1dvNV)(GLuint index , GLsizei count , const GLdouble *v); }
#define glVertexAttribs1dvNV DynamicGL_VertexAttribs1dvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribs1fvNV)(GLuint index , GLsizei count , const GLfloat *v); }
#define glVertexAttribs1fvNV DynamicGL_VertexAttribs1fvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribs1svNV)(GLuint index , GLsizei count , const GLshort *v); }
#define glVertexAttribs1svNV DynamicGL_VertexAttribs1svNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribs2dvNV)(GLuint index , GLsizei count , const GLdouble *v); }
#define glVertexAttribs2dvNV DynamicGL_VertexAttribs2dvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribs2fvNV)(GLuint index , GLsizei count , const GLfloat *v); }
#define glVertexAttribs2fvNV DynamicGL_VertexAttribs2fvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribs2svNV)(GLuint index , GLsizei count , const GLshort *v); }
#define glVertexAttribs2svNV DynamicGL_VertexAttribs2svNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribs3dvNV)(GLuint index , GLsizei count , const GLdouble *v); }
#define glVertexAttribs3dvNV DynamicGL_VertexAttribs3dvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribs3fvNV)(GLuint index , GLsizei count , const GLfloat *v); }
#define glVertexAttribs3fvNV DynamicGL_VertexAttribs3fvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribs3svNV)(GLuint index , GLsizei count , const GLshort *v); }
#define glVertexAttribs3svNV DynamicGL_VertexAttribs3svNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribs4dvNV)(GLuint index , GLsizei count , const GLdouble *v); }
#define glVertexAttribs4dvNV DynamicGL_VertexAttribs4dvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribs4fvNV)(GLuint index , GLsizei count , const GLfloat *v); }
#define glVertexAttribs4fvNV DynamicGL_VertexAttribs4fvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribs4svNV)(GLuint index , GLsizei count , const GLshort *v); }
#define glVertexAttribs4svNV DynamicGL_VertexAttribs4svNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribs4ubvNV)(GLuint index , GLsizei count , const GLubyte *v); }
#define glVertexAttribs4ubvNV DynamicGL_VertexAttribs4ubvNV
extern bool DinamicGLFeature_NV_vertex_program_Supported();
#endif /*USE_DYNAMIC_GL_NV_vertex_program*/

/*MESA_window_pos*/
#ifdef USE_DYNAMIC_GL_MESA_window_pos
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2dMESA)(GLdouble x , GLdouble y); }
#define glWindowPos2dMESA DynamicGL_WindowPos2dMESA
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2dvMESA)(const GLdouble *v); }
#define glWindowPos2dvMESA DynamicGL_WindowPos2dvMESA
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2fMESA)(GLfloat x , GLfloat y); }
#define glWindowPos2fMESA DynamicGL_WindowPos2fMESA
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2fvMESA)(const GLfloat *v); }
#define glWindowPos2fvMESA DynamicGL_WindowPos2fvMESA
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2iMESA)(GLint x , GLint y); }
#define glWindowPos2iMESA DynamicGL_WindowPos2iMESA
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2ivMESA)(const GLint *v); }
#define glWindowPos2ivMESA DynamicGL_WindowPos2ivMESA
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2sMESA)(GLshort x , GLshort y); }
#define glWindowPos2sMESA DynamicGL_WindowPos2sMESA
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2svMESA)(const GLshort *v); }
#define glWindowPos2svMESA DynamicGL_WindowPos2svMESA
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3dMESA)(GLdouble x , GLdouble y , GLdouble z); }
#define glWindowPos3dMESA DynamicGL_WindowPos3dMESA
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3dvMESA)(const GLdouble *v); }
#define glWindowPos3dvMESA DynamicGL_WindowPos3dvMESA
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3fMESA)(GLfloat x , GLfloat y , GLfloat z); }
#define glWindowPos3fMESA DynamicGL_WindowPos3fMESA
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3fvMESA)(const GLfloat *v); }
#define glWindowPos3fvMESA DynamicGL_WindowPos3fvMESA
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3iMESA)(GLint x , GLint y , GLint z); }
#define glWindowPos3iMESA DynamicGL_WindowPos3iMESA
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3ivMESA)(const GLint *v); }
#define glWindowPos3ivMESA DynamicGL_WindowPos3ivMESA
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3sMESA)(GLshort x , GLshort y , GLshort z); }
#define glWindowPos3sMESA DynamicGL_WindowPos3sMESA
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3svMESA)(const GLshort *v); }
#define glWindowPos3svMESA DynamicGL_WindowPos3svMESA
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos4dMESA)(GLdouble x , GLdouble y , GLdouble z , GLdouble w); }
#define glWindowPos4dMESA DynamicGL_WindowPos4dMESA
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos4dvMESA)(const GLdouble *v); }
#define glWindowPos4dvMESA DynamicGL_WindowPos4dvMESA
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos4fMESA)(GLfloat x , GLfloat y , GLfloat z , GLfloat w); }
#define glWindowPos4fMESA DynamicGL_WindowPos4fMESA
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos4fvMESA)(const GLfloat *v); }
#define glWindowPos4fvMESA DynamicGL_WindowPos4fvMESA
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos4iMESA)(GLint x , GLint y , GLint z , GLint w); }
#define glWindowPos4iMESA DynamicGL_WindowPos4iMESA
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos4ivMESA)(const GLint *v); }
#define glWindowPos4ivMESA DynamicGL_WindowPos4ivMESA
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos4sMESA)(GLshort x , GLshort y , GLshort z , GLshort w); }
#define glWindowPos4sMESA DynamicGL_WindowPos4sMESA
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos4svMESA)(const GLshort *v); }
#define glWindowPos4svMESA DynamicGL_WindowPos4svMESA
extern bool DinamicGLFeature_MESA_window_pos_Supported();
#endif /*USE_DYNAMIC_GL_MESA_window_pos*/

/*EXT_texture*/
#ifdef USE_DYNAMIC_GL_EXT_texture
#define GL_ALPHA4_EXT 0x803B
#define GL_ALPHA8_EXT 0x803C
#define GL_ALPHA12_EXT 0x803D
#define GL_ALPHA16_EXT 0x803E
#define GL_LUMINANCE4_EXT 0x803F
#define GL_LUMINANCE8_EXT 0x8040
#define GL_LUMINANCE12_EXT 0x8041
#define GL_LUMINANCE16_EXT 0x8042
#define GL_LUMINANCE4_ALPHA4_EXT 0x8043
#define GL_LUMINANCE6_ALPHA2_EXT 0x8044
#define GL_LUMINANCE8_ALPHA8_EXT 0x8045
#define GL_LUMINANCE12_ALPHA4_EXT 0x8046
#define GL_LUMINANCE12_ALPHA12_EXT 0x8047
#define GL_LUMINANCE16_ALPHA16_EXT 0x8048
#define GL_INTENSITY_EXT 0x8049
#define GL_INTENSITY4_EXT 0x804A
#define GL_INTENSITY8_EXT 0x804B
#define GL_INTENSITY12_EXT 0x804C
#define GL_INTENSITY16_EXT 0x804D
#define GL_RGB2_EXT 0x804E
#define GL_RGB4_EXT 0x804F
#define GL_RGB5_EXT 0x8050
#define GL_RGB8_EXT 0x8051
#define GL_RGB10_EXT 0x8052
#define GL_RGB12_EXT 0x8053
#define GL_RGB16_EXT 0x8054
#define GL_RGBA2_EXT 0x8055
#define GL_RGBA4_EXT 0x8056
#define GL_RGB5_A1_EXT 0x8057
#define GL_RGBA8_EXT 0x8058
#define GL_RGB10_A2_EXT 0x8059
#define GL_RGBA12_EXT 0x805A
#define GL_RGBA16_EXT 0x805B
#define GL_TEXTURE_RED_SIZE_EXT 0x805C
#define GL_TEXTURE_GREEN_SIZE_EXT 0x805D
#define GL_TEXTURE_BLUE_SIZE_EXT 0x805E
#define GL_TEXTURE_ALPHA_SIZE_EXT 0x805F
#define GL_TEXTURE_LUMINANCE_SIZE_EXT 0x8060
#define GL_TEXTURE_INTENSITY_SIZE_EXT 0x8061
#define GL_REPLACE_EXT 0x8062
#define GL_PROXY_TEXTURE_1D_EXT 0x8063
#define GL_PROXY_TEXTURE_2D_EXT 0x8064
#define GL_TEXTURE_TOO_LARGE_EXT 0x8065
extern bool DinamicGLFeature_EXT_texture_Supported();
#endif /*USE_DYNAMIC_GL_EXT_texture*/

/*SGIX_tag_sample_buffer*/
#ifdef USE_DYNAMIC_GL_SGIX_tag_sample_buffer
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TagSampleBufferSGIX)(); }
#define glTagSampleBufferSGIX DynamicGL_TagSampleBufferSGIX
extern bool DinamicGLFeature_SGIX_tag_sample_buffer_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_tag_sample_buffer*/

/*EXT_texture_env_combine*/
#ifdef USE_DYNAMIC_GL_EXT_texture_env_combine
#define GL_COMBINE_EXT 0x8570
#define GL_COMBINE_RGB_EXT 0x8571
#define GL_COMBINE_ALPHA_EXT 0x8572
#define GL_RGB_SCALE_EXT 0x8573
#define GL_ADD_SIGNED_EXT 0x8574
#define GL_INTERPOLATE_EXT 0x8575
#define GL_CONSTANT_EXT 0x8576
#define GL_PRIMARY_COLOR_EXT 0x8577
#define GL_PREVIOUS_EXT 0x8578
#define GL_SOURCE0_RGB_EXT 0x8580
#define GL_SOURCE1_RGB_EXT 0x8581
#define GL_SOURCE2_RGB_EXT 0x8582
#define GL_SOURCE0_ALPHA_EXT 0x8588
#define GL_SOURCE1_ALPHA_EXT 0x8589
#define GL_SOURCE2_ALPHA_EXT 0x858A
#define GL_OPERAND0_RGB_EXT 0x8590
#define GL_OPERAND1_RGB_EXT 0x8591
#define GL_OPERAND2_RGB_EXT 0x8592
#define GL_OPERAND0_ALPHA_EXT 0x8598
#define GL_OPERAND1_ALPHA_EXT 0x8599
#define GL_OPERAND2_ALPHA_EXT 0x859A
extern bool DinamicGLFeature_EXT_texture_env_combine_Supported();
#endif /*USE_DYNAMIC_GL_EXT_texture_env_combine*/

/*ARB_texture_rgb10_a2ui*/
#ifdef USE_DYNAMIC_GL_ARB_texture_rgb10_a2ui
#define GL_RGB10_A2UI 0x906F
extern bool DinamicGLFeature_ARB_texture_rgb10_a2ui_Supported();
#endif /*USE_DYNAMIC_GL_ARB_texture_rgb10_a2ui*/

/*SGIX_vertex_preclip*/
#ifdef USE_DYNAMIC_GL_SGIX_vertex_preclip
#define GL_VERTEX_PRECLIP_SGIX 0x83EE
#define GL_VERTEX_PRECLIP_HINT_SGIX 0x83EF
extern bool DinamicGLFeature_SGIX_vertex_preclip_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_vertex_preclip*/

/*ARB_geometry_shader4*/
#ifdef USE_DYNAMIC_GL_ARB_geometry_shader4
#define GL_LINES_ADJACENCY_ARB 0x000A
#define GL_LINE_STRIP_ADJACENCY_ARB 0x000B
#define GL_TRIANGLES_ADJACENCY_ARB 0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY_ARB 0x000D
#define GL_PROGRAM_POINT_SIZE_ARB 0x8642
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_ARB 0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED_ARB 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_ARB 0x8DA8
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_ARB 0x8DA9
#define GL_GEOMETRY_SHADER_ARB 0x8DD9
#define GL_GEOMETRY_VERTICES_OUT_ARB 0x8DDA
#define GL_GEOMETRY_INPUT_TYPE_ARB 0x8DDB
#define GL_GEOMETRY_OUTPUT_TYPE_ARB 0x8DDC
#define GL_MAX_GEOMETRY_VARYING_COMPONENTS_ARB 0x8DDD
#define GL_MAX_VERTEX_VARYING_COMPONENTS_ARB 0x8DDE
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_ARB 0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES_ARB 0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_ARB 0x8DE1
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramParameteriARB)(GLuint program , GLenum pname , GLint value); }
#define glProgramParameteriARB DynamicGL_ProgramParameteriARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferTextureARB)(GLenum target , GLenum attachment , GLuint texture , GLint level); }
#define glFramebufferTextureARB DynamicGL_FramebufferTextureARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferTextureLayerARB)(GLenum target , GLenum attachment , GLuint texture , GLint level , GLint layer); }
#define glFramebufferTextureLayerARB DynamicGL_FramebufferTextureLayerARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferTextureFaceARB)(GLenum target , GLenum attachment , GLuint texture , GLint level , GLenum face); }
#define glFramebufferTextureFaceARB DynamicGL_FramebufferTextureFaceARB
extern bool DinamicGLFeature_ARB_geometry_shader4_Supported();
#endif /*USE_DYNAMIC_GL_ARB_geometry_shader4*/

/*EXT_multi_draw_arrays*/
#ifdef USE_DYNAMIC_GL_EXT_multi_draw_arrays
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiDrawArraysEXT)(GLenum mode , const GLint *first , const GLsizei *count , GLsizei primcount); }
#define glMultiDrawArraysEXT DynamicGL_MultiDrawArraysEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiDrawElementsEXT)(GLenum mode , const GLsizei *count , GLenum type , const GLvoid* *indices , GLsizei primcount); }
#define glMultiDrawElementsEXT DynamicGL_MultiDrawElementsEXT
extern bool DinamicGLFeature_EXT_multi_draw_arrays_Supported();
#endif /*USE_DYNAMIC_GL_EXT_multi_draw_arrays*/

/*EXT_texture_perturb_normal*/
#ifdef USE_DYNAMIC_GL_EXT_texture_perturb_normal
#define GL_PERTURB_EXT 0x85AE
#define GL_TEXTURE_NORMAL_EXT 0x85AF
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureNormalEXT)(GLenum mode); }
#define glTextureNormalEXT DynamicGL_TextureNormalEXT
extern bool DinamicGLFeature_EXT_texture_perturb_normal_Supported();
#endif /*USE_DYNAMIC_GL_EXT_texture_perturb_normal*/

/*EXT_separate_shader_objects*/
#ifdef USE_DYNAMIC_GL_EXT_separate_shader_objects
#define GL_ACTIVE_PROGRAM_EXT 0x8B8D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_UseShaderProgramEXT)(GLenum type , GLuint program); }
#define glUseShaderProgramEXT DynamicGL_UseShaderProgramEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ActiveProgramEXT)(GLuint program); }
#define glActiveProgramEXT DynamicGL_ActiveProgramEXT
extern "C" { extern GLuint (DYNAMIC_GL_APIENTRYP DynamicGL_CreateShaderProgramEXT)(GLenum type , const GLchar *string); }
#define glCreateShaderProgramEXT DynamicGL_CreateShaderProgramEXT
extern bool DinamicGLFeature_EXT_separate_shader_objects_Supported();
#endif /*USE_DYNAMIC_GL_EXT_separate_shader_objects*/

/*SGIX_sprite*/
#ifdef USE_DYNAMIC_GL_SGIX_sprite
#define GL_SPRITE_SGIX 0x8148
#define GL_SPRITE_MODE_SGIX 0x8149
#define GL_SPRITE_AXIS_SGIX 0x814A
#define GL_SPRITE_TRANSLATION_SGIX 0x814B
#define GL_SPRITE_AXIAL_SGIX 0x814C
#define GL_SPRITE_OBJECT_ALIGNED_SGIX 0x814D
#define GL_SPRITE_EYE_ALIGNED_SGIX 0x814E
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SpriteParameterfSGIX)(GLenum pname , GLfloat param); }
#define glSpriteParameterfSGIX DynamicGL_SpriteParameterfSGIX
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SpriteParameterfvSGIX)(GLenum pname , const GLfloat *params); }
#define glSpriteParameterfvSGIX DynamicGL_SpriteParameterfvSGIX
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SpriteParameteriSGIX)(GLenum pname , GLint param); }
#define glSpriteParameteriSGIX DynamicGL_SpriteParameteriSGIX
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SpriteParameterivSGIX)(GLenum pname , const GLint *params); }
#define glSpriteParameterivSGIX DynamicGL_SpriteParameterivSGIX
extern bool DinamicGLFeature_SGIX_sprite_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_sprite*/

/*EXT_texture_snorm*/
#ifdef USE_DYNAMIC_GL_EXT_texture_snorm
#define GL_ALPHA_SNORM 0x9010
#define GL_LUMINANCE_SNORM 0x9011
#define GL_LUMINANCE_ALPHA_SNORM 0x9012
#define GL_INTENSITY_SNORM 0x9013
#define GL_ALPHA8_SNORM 0x9014
#define GL_LUMINANCE8_SNORM 0x9015
#define GL_LUMINANCE8_ALPHA8_SNORM 0x9016
#define GL_INTENSITY8_SNORM 0x9017
#define GL_ALPHA16_SNORM 0x9018
#define GL_LUMINANCE16_SNORM 0x9019
#define GL_LUMINANCE16_ALPHA16_SNORM 0x901A
#define GL_INTENSITY16_SNORM 0x901B
extern bool DinamicGLFeature_EXT_texture_snorm_Supported();
#endif /*USE_DYNAMIC_GL_EXT_texture_snorm*/

/*ARB_debug_output*/
#ifdef USE_DYNAMIC_GL_ARB_debug_output
#define GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB 0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_ARB 0x8243
#define GL_DEBUG_CALLBACK_FUNCTION_ARB 0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM_ARB 0x8245
#define GL_DEBUG_SOURCE_API_ARB 0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB 0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER_ARB 0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY_ARB 0x8249
#define GL_DEBUG_SOURCE_APPLICATION_ARB 0x824A
#define GL_DEBUG_SOURCE_OTHER_ARB 0x824B
#define GL_DEBUG_TYPE_ERROR_ARB 0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB 0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB 0x824E
#define GL_DEBUG_TYPE_PORTABILITY_ARB 0x824F
#define GL_DEBUG_TYPE_PERFORMANCE_ARB 0x8250
#define GL_DEBUG_TYPE_OTHER_ARB 0x8251
#define GL_MAX_DEBUG_MESSAGE_LENGTH_ARB 0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES_ARB 0x9144
#define GL_DEBUG_LOGGED_MESSAGES_ARB 0x9145
#define GL_DEBUG_SEVERITY_HIGH_ARB 0x9146
#define GL_DEBUG_SEVERITY_MEDIUM_ARB 0x9147
#define GL_DEBUG_SEVERITY_LOW_ARB 0x9148
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DebugMessageControlARB)(GLenum source , GLenum type , GLenum severity , GLsizei count , const GLuint *ids , GLboolean enabled); }
#define glDebugMessageControlARB DynamicGL_DebugMessageControlARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DebugMessageInsertARB)(GLenum source , GLenum type , GLuint id , GLenum severity , GLsizei length , const GLchar *buf); }
#define glDebugMessageInsertARB DynamicGL_DebugMessageInsertARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DebugMessageCallbackARB)(GLDEBUGPROCARB callback , const GLvoid *userParam); }
#define glDebugMessageCallbackARB DynamicGL_DebugMessageCallbackARB
extern "C" { extern GLuint (DYNAMIC_GL_APIENTRYP DynamicGL_GetDebugMessageLogARB)(GLuint count , GLsizei bufsize , GLenum *sources , GLenum *types , GLuint *ids , GLenum *severities , GLsizei *lengths , GLchar *messageLog); }
#define glGetDebugMessageLogARB DynamicGL_GetDebugMessageLogARB
extern bool DinamicGLFeature_ARB_debug_output_Supported();
#endif /*USE_DYNAMIC_GL_ARB_debug_output*/

/*EXT_draw_buffers2*/
#ifdef USE_DYNAMIC_GL_EXT_draw_buffers2
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorMaskIndexedEXT)(GLuint index , GLboolean r , GLboolean g , GLboolean b , GLboolean a); }
#define glColorMaskIndexedEXT DynamicGL_ColorMaskIndexedEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetBooleanIndexedvEXT)(GLenum target , GLuint index , GLboolean *data); }
#define glGetBooleanIndexedvEXT DynamicGL_GetBooleanIndexedvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetIntegerIndexedvEXT)(GLenum target , GLuint index , GLint *data); }
#define glGetIntegerIndexedvEXT DynamicGL_GetIntegerIndexedvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EnableIndexedEXT)(GLenum target , GLuint index); }
#define glEnableIndexedEXT DynamicGL_EnableIndexedEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DisableIndexedEXT)(GLenum target , GLuint index); }
#define glDisableIndexedEXT DynamicGL_DisableIndexedEXT
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsEnabledIndexedEXT)(GLenum target , GLuint index); }
#define glIsEnabledIndexedEXT DynamicGL_IsEnabledIndexedEXT
extern bool DinamicGLFeature_EXT_draw_buffers2_Supported();
#endif /*USE_DYNAMIC_GL_EXT_draw_buffers2*/

/*ARB_texture_rectangle*/
#ifdef USE_DYNAMIC_GL_ARB_texture_rectangle
#define GL_TEXTURE_RECTANGLE_ARB 0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE_ARB 0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE_ARB 0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE_ARB 0x84F8
extern bool DinamicGLFeature_ARB_texture_rectangle_Supported();
#endif /*USE_DYNAMIC_GL_ARB_texture_rectangle*/

/*EXT_packed_pixels*/
#ifdef USE_DYNAMIC_GL_EXT_packed_pixels
#define GL_UNSIGNED_BYTE_3_3_2_EXT 0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4_EXT 0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1_EXT 0x8034
#define GL_UNSIGNED_INT_8_8_8_8_EXT 0x8035
#define GL_UNSIGNED_INT_10_10_10_2_EXT 0x8036
extern bool DinamicGLFeature_EXT_packed_pixels_Supported();
#endif /*USE_DYNAMIC_GL_EXT_packed_pixels*/

/*EXT_texture_env_dot3*/
#ifdef USE_DYNAMIC_GL_EXT_texture_env_dot3
#define GL_DOT3_RGB_EXT 0x8740
#define GL_DOT3_RGBA_EXT 0x8741
extern bool DinamicGLFeature_EXT_texture_env_dot3_Supported();
#endif /*USE_DYNAMIC_GL_EXT_texture_env_dot3*/

/*NV_video_capture*/
#ifdef USE_DYNAMIC_GL_NV_video_capture
#define GL_VIDEO_BUFFER_NV 0x9020
#define GL_VIDEO_BUFFER_BINDING_NV 0x9021
#define GL_FIELD_UPPER_NV 0x9022
#define GL_FIELD_LOWER_NV 0x9023
#define GL_NUM_VIDEO_CAPTURE_STREAMS_NV 0x9024
#define GL_NEXT_VIDEO_CAPTURE_BUFFER_STATUS_NV 0x9025
#define GL_VIDEO_CAPTURE_TO_422_SUPPORTED_NV 0x9026
#define GL_LAST_VIDEO_CAPTURE_STATUS_NV 0x9027
#define GL_VIDEO_BUFFER_PITCH_NV 0x9028
#define GL_VIDEO_COLOR_CONVERSION_MATRIX_NV 0x9029
#define GL_VIDEO_COLOR_CONVERSION_MAX_NV 0x902A
#define GL_VIDEO_COLOR_CONVERSION_MIN_NV 0x902B
#define GL_VIDEO_COLOR_CONVERSION_OFFSET_NV 0x902C
#define GL_VIDEO_BUFFER_INTERNAL_FORMAT_NV 0x902D
#define GL_PARTIAL_SUCCESS_NV 0x902E
#define GL_SUCCESS_NV 0x902F
#define GL_FAILURE_NV 0x9030
#define GL_YCBYCR8_422_NV 0x9031
#define GL_YCBAYCR8A_4224_NV 0x9032
#define GL_Z6Y10Z6CB10Z6Y10Z6CR10_422_NV 0x9033
#define GL_Z6Y10Z6CB10Z6A10Z6Y10Z6CR10Z6A10_4224_NV 0x9034
#define GL_Z4Y12Z4CB12Z4Y12Z4CR12_422_NV 0x9035
#define GL_Z4Y12Z4CB12Z4A12Z4Y12Z4CR12Z4A12_4224_NV 0x9036
#define GL_Z4Y12Z4CB12Z4CR12_444_NV 0x9037
#define GL_VIDEO_CAPTURE_FRAME_WIDTH_NV 0x9038
#define GL_VIDEO_CAPTURE_FRAME_HEIGHT_NV 0x9039
#define GL_VIDEO_CAPTURE_FIELD_UPPER_HEIGHT_NV 0x903A
#define GL_VIDEO_CAPTURE_FIELD_LOWER_HEIGHT_NV 0x903B
#define GL_VIDEO_CAPTURE_SURFACE_ORIGIN_NV 0x903C
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BeginVideoCaptureNV)(GLuint video_capture_slot); }
#define glBeginVideoCaptureNV DynamicGL_BeginVideoCaptureNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindVideoCaptureStreamBufferNV)(GLuint video_capture_slot , GLuint stream , GLenum frame_region , GLintptrARB offset); }
#define glBindVideoCaptureStreamBufferNV DynamicGL_BindVideoCaptureStreamBufferNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindVideoCaptureStreamTextureNV)(GLuint video_capture_slot , GLuint stream , GLenum frame_region , GLenum target , GLuint texture); }
#define glBindVideoCaptureStreamTextureNV DynamicGL_BindVideoCaptureStreamTextureNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EndVideoCaptureNV)(GLuint video_capture_slot); }
#define glEndVideoCaptureNV DynamicGL_EndVideoCaptureNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVideoCaptureivNV)(GLuint video_capture_slot , GLenum pname , GLint *params); }
#define glGetVideoCaptureivNV DynamicGL_GetVideoCaptureivNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVideoCaptureStreamivNV)(GLuint video_capture_slot , GLuint stream , GLenum pname , GLint *params); }
#define glGetVideoCaptureStreamivNV DynamicGL_GetVideoCaptureStreamivNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVideoCaptureStreamfvNV)(GLuint video_capture_slot , GLuint stream , GLenum pname , GLfloat *params); }
#define glGetVideoCaptureStreamfvNV DynamicGL_GetVideoCaptureStreamfvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVideoCaptureStreamdvNV)(GLuint video_capture_slot , GLuint stream , GLenum pname , GLdouble *params); }
#define glGetVideoCaptureStreamdvNV DynamicGL_GetVideoCaptureStreamdvNV
extern "C" { extern GLenum (DYNAMIC_GL_APIENTRYP DynamicGL_VideoCaptureNV)(GLuint video_capture_slot , GLuint *sequence_num , GLuint64EXT *capture_time); }
#define glVideoCaptureNV DynamicGL_VideoCaptureNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VideoCaptureStreamParameterivNV)(GLuint video_capture_slot , GLuint stream , GLenum pname , const GLint *params); }
#define glVideoCaptureStreamParameterivNV DynamicGL_VideoCaptureStreamParameterivNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VideoCaptureStreamParameterfvNV)(GLuint video_capture_slot , GLuint stream , GLenum pname , const GLfloat *params); }
#define glVideoCaptureStreamParameterfvNV DynamicGL_VideoCaptureStreamParameterfvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VideoCaptureStreamParameterdvNV)(GLuint video_capture_slot , GLuint stream , GLenum pname , const GLdouble *params); }
#define glVideoCaptureStreamParameterdvNV DynamicGL_VideoCaptureStreamParameterdvNV
extern bool DinamicGLFeature_NV_video_capture_Supported();
#endif /*USE_DYNAMIC_GL_NV_video_capture*/

/*WIN_phong_shading*/
#ifdef USE_DYNAMIC_GL_WIN_phong_shading
#define GL_PHONG_WIN 0x80EA
#define GL_PHONG_HINT_WIN 0x80EB
extern bool DinamicGLFeature_WIN_phong_shading_Supported();
#endif /*USE_DYNAMIC_GL_WIN_phong_shading*/

/*ARB_map_buffer_range*/
#ifdef USE_DYNAMIC_GL_ARB_map_buffer_range
#define GL_MAP_READ_BIT 0x0001
#define GL_MAP_WRITE_BIT 0x0002
#define GL_MAP_INVALIDATE_RANGE_BIT 0x0004
#define GL_MAP_INVALIDATE_BUFFER_BIT 0x0008
#define GL_MAP_FLUSH_EXPLICIT_BIT 0x0010
#define GL_MAP_UNSYNCHRONIZED_BIT 0x0020
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FlushMappedBufferRange)(GLenum target , GLintptr offset , GLsizeiptr length); }
#define glFlushMappedBufferRange DynamicGL_FlushMappedBufferRange
extern bool DinamicGLFeature_ARB_map_buffer_range_Supported();
#endif /*USE_DYNAMIC_GL_ARB_map_buffer_range*/

/*EXT_abgr*/
#ifdef USE_DYNAMIC_GL_EXT_abgr
#define GL_ABGR_EXT 0x8000
extern bool DinamicGLFeature_EXT_abgr_Supported();
#endif /*USE_DYNAMIC_GL_EXT_abgr*/

/*EXT_vertex_shader*/
#ifdef USE_DYNAMIC_GL_EXT_vertex_shader
#define GL_VERTEX_SHADER_EXT 0x8780
#define GL_VERTEX_SHADER_BINDING_EXT 0x8781
#define GL_OP_INDEX_EXT 0x8782
#define GL_OP_NEGATE_EXT 0x8783
#define GL_OP_DOT3_EXT 0x8784
#define GL_OP_DOT4_EXT 0x8785
#define GL_OP_MUL_EXT 0x8786
#define GL_OP_ADD_EXT 0x8787
#define GL_OP_MADD_EXT 0x8788
#define GL_OP_FRAC_EXT 0x8789
#define GL_OP_MAX_EXT 0x878A
#define GL_OP_MIN_EXT 0x878B
#define GL_OP_SET_GE_EXT 0x878C
#define GL_OP_SET_LT_EXT 0x878D
#define GL_OP_CLAMP_EXT 0x878E
#define GL_OP_FLOOR_EXT 0x878F
#define GL_OP_ROUND_EXT 0x8790
#define GL_OP_EXP_BASE_2_EXT 0x8791
#define GL_OP_LOG_BASE_2_EXT 0x8792
#define GL_OP_POWER_EXT 0x8793
#define GL_OP_RECIP_EXT 0x8794
#define GL_OP_RECIP_SQRT_EXT 0x8795
#define GL_OP_SUB_EXT 0x8796
#define GL_OP_CROSS_PRODUCT_EXT 0x8797
#define GL_OP_MULTIPLY_MATRIX_EXT 0x8798
#define GL_OP_MOV_EXT 0x8799
#define GL_OUTPUT_VERTEX_EXT 0x879A
#define GL_OUTPUT_COLOR0_EXT 0x879B
#define GL_OUTPUT_COLOR1_EXT 0x879C
#define GL_OUTPUT_TEXTURE_COORD0_EXT 0x879D
#define GL_OUTPUT_TEXTURE_COORD1_EXT 0x879E
#define GL_OUTPUT_TEXTURE_COORD2_EXT 0x879F
#define GL_OUTPUT_TEXTURE_COORD3_EXT 0x87A0
#define GL_OUTPUT_TEXTURE_COORD4_EXT 0x87A1
#define GL_OUTPUT_TEXTURE_COORD5_EXT 0x87A2
#define GL_OUTPUT_TEXTURE_COORD6_EXT 0x87A3
#define GL_OUTPUT_TEXTURE_COORD7_EXT 0x87A4
#define GL_OUTPUT_TEXTURE_COORD8_EXT 0x87A5
#define GL_OUTPUT_TEXTURE_COORD9_EXT 0x87A6
#define GL_OUTPUT_TEXTURE_COORD10_EXT 0x87A7
#define GL_OUTPUT_TEXTURE_COORD11_EXT 0x87A8
#define GL_OUTPUT_TEXTURE_COORD12_EXT 0x87A9
#define GL_OUTPUT_TEXTURE_COORD13_EXT 0x87AA
#define GL_OUTPUT_TEXTURE_COORD14_EXT 0x87AB
#define GL_OUTPUT_TEXTURE_COORD15_EXT 0x87AC
#define GL_OUTPUT_TEXTURE_COORD16_EXT 0x87AD
#define GL_OUTPUT_TEXTURE_COORD17_EXT 0x87AE
#define GL_OUTPUT_TEXTURE_COORD18_EXT 0x87AF
#define GL_OUTPUT_TEXTURE_COORD19_EXT 0x87B0
#define GL_OUTPUT_TEXTURE_COORD20_EXT 0x87B1
#define GL_OUTPUT_TEXTURE_COORD21_EXT 0x87B2
#define GL_OUTPUT_TEXTURE_COORD22_EXT 0x87B3
#define GL_OUTPUT_TEXTURE_COORD23_EXT 0x87B4
#define GL_OUTPUT_TEXTURE_COORD24_EXT 0x87B5
#define GL_OUTPUT_TEXTURE_COORD25_EXT 0x87B6
#define GL_OUTPUT_TEXTURE_COORD26_EXT 0x87B7
#define GL_OUTPUT_TEXTURE_COORD27_EXT 0x87B8
#define GL_OUTPUT_TEXTURE_COORD28_EXT 0x87B9
#define GL_OUTPUT_TEXTURE_COORD29_EXT 0x87BA
#define GL_OUTPUT_TEXTURE_COORD30_EXT 0x87BB
#define GL_OUTPUT_TEXTURE_COORD31_EXT 0x87BC
#define GL_OUTPUT_FOG_EXT 0x87BD
#define GL_SCALAR_EXT 0x87BE
#define GL_VECTOR_EXT 0x87BF
#define GL_MATRIX_EXT 0x87C0
#define GL_VARIANT_EXT 0x87C1
#define GL_INVARIANT_EXT 0x87C2
#define GL_LOCAL_CONSTANT_EXT 0x87C3
#define GL_LOCAL_EXT 0x87C4
#define GL_MAX_VERTEX_SHADER_INSTRUCTIONS_EXT 0x87C5
#define GL_MAX_VERTEX_SHADER_VARIANTS_EXT 0x87C6
#define GL_MAX_VERTEX_SHADER_INVARIANTS_EXT 0x87C7
#define GL_MAX_VERTEX_SHADER_LOCAL_CONSTANTS_EXT 0x87C8
#define GL_MAX_VERTEX_SHADER_LOCALS_EXT 0x87C9
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_INSTRUCTIONS_EXT 0x87CA
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_VARIANTS_EXT 0x87CB
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCAL_CONSTANTS_EXT 0x87CC
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_INVARIANTS_EXT 0x87CD
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCALS_EXT 0x87CE
#define GL_VERTEX_SHADER_INSTRUCTIONS_EXT 0x87CF
#define GL_VERTEX_SHADER_VARIANTS_EXT 0x87D0
#define GL_VERTEX_SHADER_INVARIANTS_EXT 0x87D1
#define GL_VERTEX_SHADER_LOCAL_CONSTANTS_EXT 0x87D2
#define GL_VERTEX_SHADER_LOCALS_EXT 0x87D3
#define GL_VERTEX_SHADER_OPTIMIZED_EXT 0x87D4
#define GL_X_EXT 0x87D5
#define GL_Y_EXT 0x87D6
#define GL_Z_EXT 0x87D7
#define GL_W_EXT 0x87D8
#define GL_NEGATIVE_X_EXT 0x87D9
#define GL_NEGATIVE_Y_EXT 0x87DA
#define GL_NEGATIVE_Z_EXT 0x87DB
#define GL_NEGATIVE_W_EXT 0x87DC
#define GL_ZERO_EXT 0x87DD
#define GL_ONE_EXT 0x87DE
#define GL_NEGATIVE_ONE_EXT 0x87DF
#define GL_NORMALIZED_RANGE_EXT 0x87E0
#define GL_FULL_RANGE_EXT 0x87E1
#define GL_CURRENT_VERTEX_EXT 0x87E2
#define GL_MVP_MATRIX_EXT 0x87E3
#define GL_VARIANT_VALUE_EXT 0x87E4
#define GL_VARIANT_DATATYPE_EXT 0x87E5
#define GL_VARIANT_ARRAY_STRIDE_EXT 0x87E6
#define GL_VARIANT_ARRAY_TYPE_EXT 0x87E7
#define GL_VARIANT_ARRAY_EXT 0x87E8
#define GL_VARIANT_ARRAY_POINTER_EXT 0x87E9
#define GL_INVARIANT_VALUE_EXT 0x87EA
#define GL_INVARIANT_DATATYPE_EXT 0x87EB
#define GL_LOCAL_CONSTANT_VALUE_EXT 0x87EC
#define GL_LOCAL_CONSTANT_DATATYPE_EXT 0x87ED
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BeginVertexShaderEXT)(); }
#define glBeginVertexShaderEXT DynamicGL_BeginVertexShaderEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EndVertexShaderEXT)(); }
#define glEndVertexShaderEXT DynamicGL_EndVertexShaderEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindVertexShaderEXT)(GLuint id); }
#define glBindVertexShaderEXT DynamicGL_BindVertexShaderEXT
extern "C" { extern GLuint (DYNAMIC_GL_APIENTRYP DynamicGL_GenVertexShadersEXT)(GLuint range); }
#define glGenVertexShadersEXT DynamicGL_GenVertexShadersEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteVertexShaderEXT)(GLuint id); }
#define glDeleteVertexShaderEXT DynamicGL_DeleteVertexShaderEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ShaderOp1EXT)(GLenum op , GLuint res , GLuint arg1); }
#define glShaderOp1EXT DynamicGL_ShaderOp1EXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ShaderOp2EXT)(GLenum op , GLuint res , GLuint arg1 , GLuint arg2); }
#define glShaderOp2EXT DynamicGL_ShaderOp2EXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ShaderOp3EXT)(GLenum op , GLuint res , GLuint arg1 , GLuint arg2 , GLuint arg3); }
#define glShaderOp3EXT DynamicGL_ShaderOp3EXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SwizzleEXT)(GLuint res , GLuint in , GLenum outX , GLenum outY , GLenum outZ , GLenum outW); }
#define glSwizzleEXT DynamicGL_SwizzleEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WriteMaskEXT)(GLuint res , GLuint in , GLenum outX , GLenum outY , GLenum outZ , GLenum outW); }
#define glWriteMaskEXT DynamicGL_WriteMaskEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_InsertComponentEXT)(GLuint res , GLuint src , GLuint num); }
#define glInsertComponentEXT DynamicGL_InsertComponentEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ExtractComponentEXT)(GLuint res , GLuint src , GLuint num); }
#define glExtractComponentEXT DynamicGL_ExtractComponentEXT
extern "C" { extern GLuint (DYNAMIC_GL_APIENTRYP DynamicGL_GenSymbolsEXT)(GLenum datatype , GLenum storagetype , GLenum range , GLuint components); }
#define glGenSymbolsEXT DynamicGL_GenSymbolsEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SetInvariantEXT)(GLuint id , GLenum type , const GLvoid *addr); }
#define glSetInvariantEXT DynamicGL_SetInvariantEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SetLocalConstantEXT)(GLuint id , GLenum type , const GLvoid *addr); }
#define glSetLocalConstantEXT DynamicGL_SetLocalConstantEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VariantbvEXT)(GLuint id , const GLbyte *addr); }
#define glVariantbvEXT DynamicGL_VariantbvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VariantsvEXT)(GLuint id , const GLshort *addr); }
#define glVariantsvEXT DynamicGL_VariantsvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VariantivEXT)(GLuint id , const GLint *addr); }
#define glVariantivEXT DynamicGL_VariantivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VariantfvEXT)(GLuint id , const GLfloat *addr); }
#define glVariantfvEXT DynamicGL_VariantfvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VariantdvEXT)(GLuint id , const GLdouble *addr); }
#define glVariantdvEXT DynamicGL_VariantdvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VariantubvEXT)(GLuint id , const GLubyte *addr); }
#define glVariantubvEXT DynamicGL_VariantubvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VariantusvEXT)(GLuint id , const GLushort *addr); }
#define glVariantusvEXT DynamicGL_VariantusvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VariantuivEXT)(GLuint id , const GLuint *addr); }
#define glVariantuivEXT DynamicGL_VariantuivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VariantPointerEXT)(GLuint id , GLenum type , GLuint stride , const GLvoid *addr); }
#define glVariantPointerEXT DynamicGL_VariantPointerEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EnableVariantClientStateEXT)(GLuint id); }
#define glEnableVariantClientStateEXT DynamicGL_EnableVariantClientStateEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DisableVariantClientStateEXT)(GLuint id); }
#define glDisableVariantClientStateEXT DynamicGL_DisableVariantClientStateEXT
extern "C" { extern GLuint (DYNAMIC_GL_APIENTRYP DynamicGL_BindLightParameterEXT)(GLenum light , GLenum value); }
#define glBindLightParameterEXT DynamicGL_BindLightParameterEXT
extern "C" { extern GLuint (DYNAMIC_GL_APIENTRYP DynamicGL_BindMaterialParameterEXT)(GLenum face , GLenum value); }
#define glBindMaterialParameterEXT DynamicGL_BindMaterialParameterEXT
extern "C" { extern GLuint (DYNAMIC_GL_APIENTRYP DynamicGL_BindTexGenParameterEXT)(GLenum unit , GLenum coord , GLenum value); }
#define glBindTexGenParameterEXT DynamicGL_BindTexGenParameterEXT
extern "C" { extern GLuint (DYNAMIC_GL_APIENTRYP DynamicGL_BindTextureUnitParameterEXT)(GLenum unit , GLenum value); }
#define glBindTextureUnitParameterEXT DynamicGL_BindTextureUnitParameterEXT
extern "C" { extern GLuint (DYNAMIC_GL_APIENTRYP DynamicGL_BindParameterEXT)(GLenum value); }
#define glBindParameterEXT DynamicGL_BindParameterEXT
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsVariantEnabledEXT)(GLuint id , GLenum cap); }
#define glIsVariantEnabledEXT DynamicGL_IsVariantEnabledEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVariantBooleanvEXT)(GLuint id , GLenum value , GLboolean *data); }
#define glGetVariantBooleanvEXT DynamicGL_GetVariantBooleanvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVariantIntegervEXT)(GLuint id , GLenum value , GLint *data); }
#define glGetVariantIntegervEXT DynamicGL_GetVariantIntegervEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVariantFloatvEXT)(GLuint id , GLenum value , GLfloat *data); }
#define glGetVariantFloatvEXT DynamicGL_GetVariantFloatvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVariantPointervEXT)(GLuint id , GLenum value , GLvoid* *data); }
#define glGetVariantPointervEXT DynamicGL_GetVariantPointervEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetInvariantBooleanvEXT)(GLuint id , GLenum value , GLboolean *data); }
#define glGetInvariantBooleanvEXT DynamicGL_GetInvariantBooleanvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetInvariantIntegervEXT)(GLuint id , GLenum value , GLint *data); }
#define glGetInvariantIntegervEXT DynamicGL_GetInvariantIntegervEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetInvariantFloatvEXT)(GLuint id , GLenum value , GLfloat *data); }
#define glGetInvariantFloatvEXT DynamicGL_GetInvariantFloatvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetLocalConstantBooleanvEXT)(GLuint id , GLenum value , GLboolean *data); }
#define glGetLocalConstantBooleanvEXT DynamicGL_GetLocalConstantBooleanvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetLocalConstantIntegervEXT)(GLuint id , GLenum value , GLint *data); }
#define glGetLocalConstantIntegervEXT DynamicGL_GetLocalConstantIntegervEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetLocalConstantFloatvEXT)(GLuint id , GLenum value , GLfloat *data); }
#define glGetLocalConstantFloatvEXT DynamicGL_GetLocalConstantFloatvEXT
extern bool DinamicGLFeature_EXT_vertex_shader_Supported();
#endif /*USE_DYNAMIC_GL_EXT_vertex_shader*/

/*NV_packed_depth_stencil*/
#ifdef USE_DYNAMIC_GL_NV_packed_depth_stencil
#define GL_DEPTH_STENCIL_NV 0x84F9
#define GL_UNSIGNED_INT_24_8_NV 0x84FA
extern bool DinamicGLFeature_NV_packed_depth_stencil_Supported();
#endif /*USE_DYNAMIC_GL_NV_packed_depth_stencil*/

/*SGI_color_table*/
#ifdef USE_DYNAMIC_GL_SGI_color_table
#define GL_COLOR_TABLE_SGI 0x80D0
#define GL_POST_CONVOLUTION_COLOR_TABLE_SGI 0x80D1
#define GL_POST_COLOR_MATRIX_COLOR_TABLE_SGI 0x80D2
#define GL_PROXY_COLOR_TABLE_SGI 0x80D3
#define GL_PROXY_POST_CONVOLUTION_COLOR_TABLE_SGI 0x80D4
#define GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE_SGI 0x80D5
#define GL_COLOR_TABLE_SCALE_SGI 0x80D6
#define GL_COLOR_TABLE_BIAS_SGI 0x80D7
#define GL_COLOR_TABLE_FORMAT_SGI 0x80D8
#define GL_COLOR_TABLE_WIDTH_SGI 0x80D9
#define GL_COLOR_TABLE_RED_SIZE_SGI 0x80DA
#define GL_COLOR_TABLE_GREEN_SIZE_SGI 0x80DB
#define GL_COLOR_TABLE_BLUE_SIZE_SGI 0x80DC
#define GL_COLOR_TABLE_ALPHA_SIZE_SGI 0x80DD
#define GL_COLOR_TABLE_LUMINANCE_SIZE_SGI 0x80DE
#define GL_COLOR_TABLE_INTENSITY_SIZE_SGI 0x80DF
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorTableSGI)(GLenum target , GLenum internalformat , GLsizei width , GLenum format , GLenum type , const GLvoid *table); }
#define glColorTableSGI DynamicGL_ColorTableSGI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorTableParameterfvSGI)(GLenum target , GLenum pname , const GLfloat *params); }
#define glColorTableParameterfvSGI DynamicGL_ColorTableParameterfvSGI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorTableParameterivSGI)(GLenum target , GLenum pname , const GLint *params); }
#define glColorTableParameterivSGI DynamicGL_ColorTableParameterivSGI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyColorTableSGI)(GLenum target , GLenum internalformat , GLint x , GLint y , GLsizei width); }
#define glCopyColorTableSGI DynamicGL_CopyColorTableSGI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetColorTableSGI)(GLenum target , GLenum format , GLenum type , GLvoid *table); }
#define glGetColorTableSGI DynamicGL_GetColorTableSGI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetColorTableParameterfvSGI)(GLenum target , GLenum pname , GLfloat *params); }
#define glGetColorTableParameterfvSGI DynamicGL_GetColorTableParameterfvSGI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetColorTableParameterivSGI)(GLenum target , GLenum pname , GLint *params); }
#define glGetColorTableParameterivSGI DynamicGL_GetColorTableParameterivSGI
extern bool DinamicGLFeature_SGI_color_table_Supported();
#endif /*USE_DYNAMIC_GL_SGI_color_table*/

/*EXT_texture_array*/
#ifdef USE_DYNAMIC_GL_EXT_texture_array
#define GL_TEXTURE_1D_ARRAY_EXT 0x8C18
#define GL_PROXY_TEXTURE_1D_ARRAY_EXT 0x8C19
#define GL_TEXTURE_2D_ARRAY_EXT 0x8C1A
#define GL_PROXY_TEXTURE_2D_ARRAY_EXT 0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY_EXT 0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY_EXT 0x8C1D
#define GL_MAX_ARRAY_TEXTURE_LAYERS_EXT 0x88FF
#define GL_COMPARE_REF_DEPTH_TO_TEXTURE_EXT 0x884E
extern bool DinamicGLFeature_EXT_texture_array_Supported();
#endif /*USE_DYNAMIC_GL_EXT_texture_array*/

/*EXT_texture_object*/
#ifdef USE_DYNAMIC_GL_EXT_texture_object
#define GL_TEXTURE_PRIORITY_EXT 0x8066
#define GL_TEXTURE_RESIDENT_EXT 0x8067
#define GL_TEXTURE_1D_BINDING_EXT 0x8068
#define GL_TEXTURE_2D_BINDING_EXT 0x8069
#define GL_TEXTURE_3D_BINDING_EXT 0x806A
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_AreTexturesResidentEXT)(GLsizei n , const GLuint *textures , GLboolean *residences); }
#define glAreTexturesResidentEXT DynamicGL_AreTexturesResidentEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindTextureEXT)(GLenum target , GLuint texture); }
#define glBindTextureEXT DynamicGL_BindTextureEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteTexturesEXT)(GLsizei n , const GLuint *textures); }
#define glDeleteTexturesEXT DynamicGL_DeleteTexturesEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GenTexturesEXT)(GLsizei n , GLuint *textures); }
#define glGenTexturesEXT DynamicGL_GenTexturesEXT
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsTextureEXT)(GLuint texture); }
#define glIsTextureEXT DynamicGL_IsTextureEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PrioritizeTexturesEXT)(GLsizei n , const GLuint *textures , const GLclampf *priorities); }
#define glPrioritizeTexturesEXT DynamicGL_PrioritizeTexturesEXT
extern bool DinamicGLFeature_EXT_texture_object_Supported();
#endif /*USE_DYNAMIC_GL_EXT_texture_object*/

/*ATI_texture_env_combine3*/
#ifdef USE_DYNAMIC_GL_ATI_texture_env_combine3
#define GL_MODULATE_ADD_ATI 0x8744
#define GL_MODULATE_SIGNED_ADD_ATI 0x8745
#define GL_MODULATE_SUBTRACT_ATI 0x8746
extern bool DinamicGLFeature_ATI_texture_env_combine3_Supported();
#endif /*USE_DYNAMIC_GL_ATI_texture_env_combine3*/

/*EXT_geometry_shader4*/
#ifdef USE_DYNAMIC_GL_EXT_geometry_shader4
#define GL_GEOMETRY_SHADER_EXT 0x8DD9
#define GL_MAX_GEOMETRY_VARYING_COMPONENTS_EXT 0x8DDD
#define GL_MAX_VERTEX_VARYING_COMPONENTS_EXT 0x8DDE
#define GL_MAX_VARYING_COMPONENTS_EXT 0x8B4B
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_EXT 0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES_EXT 0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_EXT 0x8DE1
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramParameteriEXT)(GLuint program , GLenum pname , GLint value); }
#define glProgramParameteriEXT DynamicGL_ProgramParameteriEXT
extern bool DinamicGLFeature_EXT_geometry_shader4_Supported();
#endif /*USE_DYNAMIC_GL_EXT_geometry_shader4*/

/*ARB_transpose_matrix*/
#ifdef USE_DYNAMIC_GL_ARB_transpose_matrix
#define GL_TRANSPOSE_MODELVIEW_MATRIX_ARB 0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX_ARB 0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX_ARB 0x84E5
#define GL_TRANSPOSE_COLOR_MATRIX_ARB 0x84E6
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LoadTransposeMatrixfARB)(const GLfloat *m); }
#define glLoadTransposeMatrixfARB DynamicGL_LoadTransposeMatrixfARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LoadTransposeMatrixdARB)(const GLdouble *m); }
#define glLoadTransposeMatrixdARB DynamicGL_LoadTransposeMatrixdARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultTransposeMatrixfARB)(const GLfloat *m); }
#define glMultTransposeMatrixfARB DynamicGL_MultTransposeMatrixfARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultTransposeMatrixdARB)(const GLdouble *m); }
#define glMultTransposeMatrixdARB DynamicGL_MultTransposeMatrixdARB
extern bool DinamicGLFeature_ARB_transpose_matrix_Supported();
#endif /*USE_DYNAMIC_GL_ARB_transpose_matrix*/

/*ARB_transform_feedback_instanced*/
#ifdef USE_DYNAMIC_GL_ARB_transform_feedback_instanced
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawTransformFeedbackInstanced)(GLenum mode , GLuint id , GLsizei primcount); }
#define glDrawTransformFeedbackInstanced DynamicGL_DrawTransformFeedbackInstanced
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawTransformFeedbackStreamInstanced)(GLenum mode , GLuint id , GLuint stream , GLsizei primcount); }
#define glDrawTransformFeedbackStreamInstanced DynamicGL_DrawTransformFeedbackStreamInstanced
extern bool DinamicGLFeature_ARB_transform_feedback_instanced_Supported();
#endif /*USE_DYNAMIC_GL_ARB_transform_feedback_instanced*/

/*NV_parameter_buffer_object*/
#ifdef USE_DYNAMIC_GL_NV_parameter_buffer_object
#define GL_MAX_PROGRAM_PARAMETER_BUFFER_BINDINGS_NV 0x8DA0
#define GL_MAX_PROGRAM_PARAMETER_BUFFER_SIZE_NV 0x8DA1
#define GL_VERTEX_PROGRAM_PARAMETER_BUFFER_NV 0x8DA2
#define GL_GEOMETRY_PROGRAM_PARAMETER_BUFFER_NV 0x8DA3
#define GL_FRAGMENT_PROGRAM_PARAMETER_BUFFER_NV 0x8DA4
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramBufferParametersfvNV)(GLenum target , GLuint buffer , GLuint index , GLsizei count , const GLfloat *params); }
#define glProgramBufferParametersfvNV DynamicGL_ProgramBufferParametersfvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramBufferParametersIivNV)(GLenum target , GLuint buffer , GLuint index , GLsizei count , const GLint *params); }
#define glProgramBufferParametersIivNV DynamicGL_ProgramBufferParametersIivNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramBufferParametersIuivNV)(GLenum target , GLuint buffer , GLuint index , GLsizei count , const GLuint *params); }
#define glProgramBufferParametersIuivNV DynamicGL_ProgramBufferParametersIuivNV
extern bool DinamicGLFeature_NV_parameter_buffer_object_Supported();
#endif /*USE_DYNAMIC_GL_NV_parameter_buffer_object*/

/*EXT_packed_depth_stencil*/
#ifdef USE_DYNAMIC_GL_EXT_packed_depth_stencil
#define GL_DEPTH_STENCIL_EXT 0x84F9
#define GL_UNSIGNED_INT_24_8_EXT 0x84FA
#define GL_DEPTH24_STENCIL8_EXT 0x88F0
#define GL_TEXTURE_STENCIL_SIZE_EXT 0x88F1
extern bool DinamicGLFeature_EXT_packed_depth_stencil_Supported();
#endif /*USE_DYNAMIC_GL_EXT_packed_depth_stencil*/

/*VERSION_3_1*/
#ifdef USE_DYNAMIC_GL_VERSION_3_1
#define GL_SAMPLER_2D_RECT 0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW 0x8B64
#define GL_SAMPLER_BUFFER 0x8DC2
#define GL_INT_SAMPLER_2D_RECT 0x8DCD
#define GL_INT_SAMPLER_BUFFER 0x8DD0
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT 0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_BUFFER 0x8DD8
#define GL_TEXTURE_BUFFER 0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE 0x8C2B
#define GL_TEXTURE_BINDING_BUFFER 0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING 0x8C2D
#define GL_TEXTURE_BUFFER_FORMAT 0x8C2E
#define GL_TEXTURE_RECTANGLE 0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE 0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE 0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE 0x84F8
#define GL_RED_SNORM 0x8F90
#define GL_RG_SNORM 0x8F91
#define GL_RGB_SNORM 0x8F92
#define GL_RGBA_SNORM 0x8F93
#define GL_R8_SNORM 0x8F94
#define GL_RG8_SNORM 0x8F95
#define GL_RGB8_SNORM 0x8F96
#define GL_RGBA8_SNORM 0x8F97
#define GL_R16_SNORM 0x8F98
#define GL_RG16_SNORM 0x8F99
#define GL_RGB16_SNORM 0x8F9A
#define GL_RGBA16_SNORM 0x8F9B
#define GL_SIGNED_NORMALIZED 0x8F9C
#define GL_PRIMITIVE_RESTART 0x8F9D
#define GL_PRIMITIVE_RESTART_INDEX 0x8F9E
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawArraysInstanced)(GLenum mode , GLint first , GLsizei count , GLsizei primcount); }
#define glDrawArraysInstanced DynamicGL_DrawArraysInstanced
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawElementsInstanced)(GLenum mode , GLsizei count , GLenum type , const GLvoid *indices , GLsizei primcount); }
#define glDrawElementsInstanced DynamicGL_DrawElementsInstanced
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexBuffer)(GLenum target , GLenum internalformat , GLuint buffer); }
#define glTexBuffer DynamicGL_TexBuffer
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PrimitiveRestartIndex)(GLuint index); }
#define glPrimitiveRestartIndex DynamicGL_PrimitiveRestartIndex
extern bool DinamicGLFeature_VERSION_3_1_Supported();
#endif /*USE_DYNAMIC_GL_VERSION_3_1*/

/*PGI_vertex_hints*/
#ifdef USE_DYNAMIC_GL_PGI_vertex_hints
#define GL_VERTEX_DATA_HINT_PGI 0x1A22A
#define GL_VERTEX_CONSISTENT_HINT_PGI 0x1A22B
#define GL_MATERIAL_SIDE_HINT_PGI 0x1A22C
#define GL_MAX_VERTEX_HINT_PGI 0x1A22D
#define GL_COLOR3_BIT_PGI 0x00010000
#define GL_COLOR4_BIT_PGI 0x00020000
#define GL_EDGEFLAG_BIT_PGI 0x00040000
#define GL_INDEX_BIT_PGI 0x00080000
#define GL_MAT_AMBIENT_BIT_PGI 0x00100000
#define GL_MAT_AMBIENT_AND_DIFFUSE_BIT_PGI 0x00200000
#define GL_MAT_DIFFUSE_BIT_PGI 0x00400000
#define GL_MAT_EMISSION_BIT_PGI 0x00800000
#define GL_MAT_COLOR_INDEXES_BIT_PGI 0x01000000
#define GL_MAT_SHININESS_BIT_PGI 0x02000000
#define GL_MAT_SPECULAR_BIT_PGI 0x04000000
#define GL_NORMAL_BIT_PGI 0x08000000
#define GL_TEXCOORD1_BIT_PGI 0x10000000
#define GL_TEXCOORD2_BIT_PGI 0x20000000
#define GL_TEXCOORD3_BIT_PGI 0x40000000
#define GL_TEXCOORD4_BIT_PGI 0x80000000
#define GL_VERTEX23_BIT_PGI 0x00000004
#define GL_VERTEX4_BIT_PGI 0x00000008
extern bool DinamicGLFeature_PGI_vertex_hints_Supported();
#endif /*USE_DYNAMIC_GL_PGI_vertex_hints*/

/*EXT_vertex_weighting*/
#ifdef USE_DYNAMIC_GL_EXT_vertex_weighting
#define GL_MODELVIEW1_STACK_DEPTH_EXT 0x8502
#define GL_MODELVIEW1_MATRIX_EXT 0x8506
#define GL_VERTEX_WEIGHTING_EXT 0x8509
#define GL_MODELVIEW1_EXT 0x850A
#define GL_CURRENT_VERTEX_WEIGHT_EXT 0x850B
#define GL_VERTEX_WEIGHT_ARRAY_EXT 0x850C
#define GL_VERTEX_WEIGHT_ARRAY_SIZE_EXT 0x850D
#define GL_VERTEX_WEIGHT_ARRAY_TYPE_EXT 0x850E
#define GL_VERTEX_WEIGHT_ARRAY_STRIDE_EXT 0x850F
#define GL_VERTEX_WEIGHT_ARRAY_POINTER_EXT 0x8510
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexWeightfEXT)(GLfloat weight); }
#define glVertexWeightfEXT DynamicGL_VertexWeightfEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexWeightfvEXT)(const GLfloat *weight); }
#define glVertexWeightfvEXT DynamicGL_VertexWeightfvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexWeightPointerEXT)(GLsizei size , GLenum type , GLsizei stride , const GLvoid *pointer); }
#define glVertexWeightPointerEXT DynamicGL_VertexWeightPointerEXT
extern bool DinamicGLFeature_EXT_vertex_weighting_Supported();
#endif /*USE_DYNAMIC_GL_EXT_vertex_weighting*/

/*ARB_texture_env_dot3*/
#ifdef USE_DYNAMIC_GL_ARB_texture_env_dot3
#define GL_DOT3_RGB_ARB 0x86AE
#define GL_DOT3_RGBA_ARB 0x86AF
extern bool DinamicGLFeature_ARB_texture_env_dot3_Supported();
#endif /*USE_DYNAMIC_GL_ARB_texture_env_dot3*/

/*EXT_histogram*/
#ifdef USE_DYNAMIC_GL_EXT_histogram
#define GL_HISTOGRAM_EXT 0x8024
#define GL_PROXY_HISTOGRAM_EXT 0x8025
#define GL_HISTOGRAM_WIDTH_EXT 0x8026
#define GL_HISTOGRAM_FORMAT_EXT 0x8027
#define GL_HISTOGRAM_RED_SIZE_EXT 0x8028
#define GL_HISTOGRAM_GREEN_SIZE_EXT 0x8029
#define GL_HISTOGRAM_BLUE_SIZE_EXT 0x802A
#define GL_HISTOGRAM_ALPHA_SIZE_EXT 0x802B
#define GL_HISTOGRAM_LUMINANCE_SIZE_EXT 0x802C
#define GL_HISTOGRAM_SINK_EXT 0x802D
#define GL_MINMAX_EXT 0x802E
#define GL_MINMAX_FORMAT_EXT 0x802F
#define GL_MINMAX_SINK_EXT 0x8030
#define GL_TABLE_TOO_LARGE_EXT 0x8031
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetHistogramEXT)(GLenum target , GLboolean reset , GLenum format , GLenum type , GLvoid *values); }
#define glGetHistogramEXT DynamicGL_GetHistogramEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetHistogramParameterfvEXT)(GLenum target , GLenum pname , GLfloat *params); }
#define glGetHistogramParameterfvEXT DynamicGL_GetHistogramParameterfvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetHistogramParameterivEXT)(GLenum target , GLenum pname , GLint *params); }
#define glGetHistogramParameterivEXT DynamicGL_GetHistogramParameterivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMinmaxEXT)(GLenum target , GLboolean reset , GLenum format , GLenum type , GLvoid *values); }
#define glGetMinmaxEXT DynamicGL_GetMinmaxEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMinmaxParameterfvEXT)(GLenum target , GLenum pname , GLfloat *params); }
#define glGetMinmaxParameterfvEXT DynamicGL_GetMinmaxParameterfvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMinmaxParameterivEXT)(GLenum target , GLenum pname , GLint *params); }
#define glGetMinmaxParameterivEXT DynamicGL_GetMinmaxParameterivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_HistogramEXT)(GLenum target , GLsizei width , GLenum internalformat , GLboolean sink); }
#define glHistogramEXT DynamicGL_HistogramEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MinmaxEXT)(GLenum target , GLenum internalformat , GLboolean sink); }
#define glMinmaxEXT DynamicGL_MinmaxEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ResetHistogramEXT)(GLenum target); }
#define glResetHistogramEXT DynamicGL_ResetHistogramEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ResetMinmaxEXT)(GLenum target); }
#define glResetMinmaxEXT DynamicGL_ResetMinmaxEXT
extern bool DinamicGLFeature_EXT_histogram_Supported();
#endif /*USE_DYNAMIC_GL_EXT_histogram*/

/*ARB_vertex_type_2_10_10_10_rev*/
#ifdef USE_DYNAMIC_GL_ARB_vertex_type_2_10_10_10_rev
#define GL_INT_2_10_10_10_REV 0x8D9F
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexP2ui)(GLenum type , GLuint value); }
#define glVertexP2ui DynamicGL_VertexP2ui
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexP2uiv)(GLenum type , const GLuint *value); }
#define glVertexP2uiv DynamicGL_VertexP2uiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexP3ui)(GLenum type , GLuint value); }
#define glVertexP3ui DynamicGL_VertexP3ui
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexP3uiv)(GLenum type , const GLuint *value); }
#define glVertexP3uiv DynamicGL_VertexP3uiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexP4ui)(GLenum type , GLuint value); }
#define glVertexP4ui DynamicGL_VertexP4ui
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexP4uiv)(GLenum type , const GLuint *value); }
#define glVertexP4uiv DynamicGL_VertexP4uiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoordP1ui)(GLenum type , GLuint coords); }
#define glTexCoordP1ui DynamicGL_TexCoordP1ui
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoordP1uiv)(GLenum type , const GLuint *coords); }
#define glTexCoordP1uiv DynamicGL_TexCoordP1uiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoordP2ui)(GLenum type , GLuint coords); }
#define glTexCoordP2ui DynamicGL_TexCoordP2ui
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoordP2uiv)(GLenum type , const GLuint *coords); }
#define glTexCoordP2uiv DynamicGL_TexCoordP2uiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoordP3ui)(GLenum type , GLuint coords); }
#define glTexCoordP3ui DynamicGL_TexCoordP3ui
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoordP3uiv)(GLenum type , const GLuint *coords); }
#define glTexCoordP3uiv DynamicGL_TexCoordP3uiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoordP4ui)(GLenum type , GLuint coords); }
#define glTexCoordP4ui DynamicGL_TexCoordP4ui
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoordP4uiv)(GLenum type , const GLuint *coords); }
#define glTexCoordP4uiv DynamicGL_TexCoordP4uiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoordP1ui)(GLenum texture , GLenum type , GLuint coords); }
#define glMultiTexCoordP1ui DynamicGL_MultiTexCoordP1ui
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoordP1uiv)(GLenum texture , GLenum type , const GLuint *coords); }
#define glMultiTexCoordP1uiv DynamicGL_MultiTexCoordP1uiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoordP2ui)(GLenum texture , GLenum type , GLuint coords); }
#define glMultiTexCoordP2ui DynamicGL_MultiTexCoordP2ui
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoordP2uiv)(GLenum texture , GLenum type , const GLuint *coords); }
#define glMultiTexCoordP2uiv DynamicGL_MultiTexCoordP2uiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoordP3ui)(GLenum texture , GLenum type , GLuint coords); }
#define glMultiTexCoordP3ui DynamicGL_MultiTexCoordP3ui
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoordP3uiv)(GLenum texture , GLenum type , const GLuint *coords); }
#define glMultiTexCoordP3uiv DynamicGL_MultiTexCoordP3uiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoordP4ui)(GLenum texture , GLenum type , GLuint coords); }
#define glMultiTexCoordP4ui DynamicGL_MultiTexCoordP4ui
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoordP4uiv)(GLenum texture , GLenum type , const GLuint *coords); }
#define glMultiTexCoordP4uiv DynamicGL_MultiTexCoordP4uiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NormalP3ui)(GLenum type , GLuint coords); }
#define glNormalP3ui DynamicGL_NormalP3ui
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NormalP3uiv)(GLenum type , const GLuint *coords); }
#define glNormalP3uiv DynamicGL_NormalP3uiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorP3ui)(GLenum type , GLuint color); }
#define glColorP3ui DynamicGL_ColorP3ui
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorP3uiv)(GLenum type , const GLuint *color); }
#define glColorP3uiv DynamicGL_ColorP3uiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorP4ui)(GLenum type , GLuint color); }
#define glColorP4ui DynamicGL_ColorP4ui
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorP4uiv)(GLenum type , const GLuint *color); }
#define glColorP4uiv DynamicGL_ColorP4uiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColorP3ui)(GLenum type , GLuint color); }
#define glSecondaryColorP3ui DynamicGL_SecondaryColorP3ui
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColorP3uiv)(GLenum type , const GLuint *color); }
#define glSecondaryColorP3uiv DynamicGL_SecondaryColorP3uiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribP1ui)(GLuint index , GLenum type , GLboolean normalized , GLuint value); }
#define glVertexAttribP1ui DynamicGL_VertexAttribP1ui
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribP1uiv)(GLuint index , GLenum type , GLboolean normalized , const GLuint *value); }
#define glVertexAttribP1uiv DynamicGL_VertexAttribP1uiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribP2ui)(GLuint index , GLenum type , GLboolean normalized , GLuint value); }
#define glVertexAttribP2ui DynamicGL_VertexAttribP2ui
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribP2uiv)(GLuint index , GLenum type , GLboolean normalized , const GLuint *value); }
#define glVertexAttribP2uiv DynamicGL_VertexAttribP2uiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribP3ui)(GLuint index , GLenum type , GLboolean normalized , GLuint value); }
#define glVertexAttribP3ui DynamicGL_VertexAttribP3ui
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribP3uiv)(GLuint index , GLenum type , GLboolean normalized , const GLuint *value); }
#define glVertexAttribP3uiv DynamicGL_VertexAttribP3uiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribP4ui)(GLuint index , GLenum type , GLboolean normalized , GLuint value); }
#define glVertexAttribP4ui DynamicGL_VertexAttribP4ui
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribP4uiv)(GLuint index , GLenum type , GLboolean normalized , const GLuint *value); }
#define glVertexAttribP4uiv DynamicGL_VertexAttribP4uiv
extern bool DinamicGLFeature_ARB_vertex_type_2_10_10_10_rev_Supported();
#endif /*USE_DYNAMIC_GL_ARB_vertex_type_2_10_10_10_rev*/

/*SGIX_pixel_texture*/
#ifdef USE_DYNAMIC_GL_SGIX_pixel_texture
#define GL_PIXEL_TEX_GEN_SGIX 0x8139
#define GL_PIXEL_TEX_GEN_MODE_SGIX 0x832B
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelTexGenSGIX)(GLenum mode); }
#define glPixelTexGenSGIX DynamicGL_PixelTexGenSGIX
extern bool DinamicGLFeature_SGIX_pixel_texture_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_pixel_texture*/

/*NV_fog_distance*/
#ifdef USE_DYNAMIC_GL_NV_fog_distance
#define GL_FOG_DISTANCE_MODE_NV 0x855A
#define GL_EYE_RADIAL_NV 0x855B
#define GL_EYE_PLANE_ABSOLUTE_NV 0x855C
extern bool DinamicGLFeature_NV_fog_distance_Supported();
#endif /*USE_DYNAMIC_GL_NV_fog_distance*/

/*APPLE_fence*/
#ifdef USE_DYNAMIC_GL_APPLE_fence
#define GL_DRAW_PIXELS_APPLE 0x8A0A
#define GL_FENCE_APPLE 0x8A0B
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GenFencesAPPLE)(GLsizei n , GLuint *fences); }
#define glGenFencesAPPLE DynamicGL_GenFencesAPPLE
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteFencesAPPLE)(GLsizei n , const GLuint *fences); }
#define glDeleteFencesAPPLE DynamicGL_DeleteFencesAPPLE
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SetFenceAPPLE)(GLuint fence); }
#define glSetFenceAPPLE DynamicGL_SetFenceAPPLE
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsFenceAPPLE)(GLuint fence); }
#define glIsFenceAPPLE DynamicGL_IsFenceAPPLE
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_TestFenceAPPLE)(GLuint fence); }
#define glTestFenceAPPLE DynamicGL_TestFenceAPPLE
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FinishFenceAPPLE)(GLuint fence); }
#define glFinishFenceAPPLE DynamicGL_FinishFenceAPPLE
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_TestObjectAPPLE)(GLenum object , GLuint name); }
#define glTestObjectAPPLE DynamicGL_TestObjectAPPLE
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FinishObjectAPPLE)(GLenum object , GLint name); }
#define glFinishObjectAPPLE DynamicGL_FinishObjectAPPLE
extern bool DinamicGLFeature_APPLE_fence_Supported();
#endif /*USE_DYNAMIC_GL_APPLE_fence*/

/*EXT_blend_func_separate*/
#ifdef USE_DYNAMIC_GL_EXT_blend_func_separate
#define GL_BLEND_DST_RGB_EXT 0x80C8
#define GL_BLEND_SRC_RGB_EXT 0x80C9
#define GL_BLEND_DST_ALPHA_EXT 0x80CA
#define GL_BLEND_SRC_ALPHA_EXT 0x80CB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendFuncSeparateEXT)(GLenum sfactorRGB , GLenum dfactorRGB , GLenum sfactorAlpha , GLenum dfactorAlpha); }
#define glBlendFuncSeparateEXT DynamicGL_BlendFuncSeparateEXT
extern bool DinamicGLFeature_EXT_blend_func_separate_Supported();
#endif /*USE_DYNAMIC_GL_EXT_blend_func_separate*/

/*ARB_sampler_objects*/
#ifdef USE_DYNAMIC_GL_ARB_sampler_objects
#define GL_SAMPLER_BINDING 0x8919
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GenSamplers)(GLsizei count , GLuint *samplers); }
#define glGenSamplers DynamicGL_GenSamplers
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteSamplers)(GLsizei count , const GLuint *samplers); }
#define glDeleteSamplers DynamicGL_DeleteSamplers
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsSampler)(GLuint sampler); }
#define glIsSampler DynamicGL_IsSampler
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindSampler)(GLuint unit , GLuint sampler); }
#define glBindSampler DynamicGL_BindSampler
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SamplerParameteri)(GLuint sampler , GLenum pname , GLint param); }
#define glSamplerParameteri DynamicGL_SamplerParameteri
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SamplerParameteriv)(GLuint sampler , GLenum pname , const GLint *param); }
#define glSamplerParameteriv DynamicGL_SamplerParameteriv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SamplerParameterf)(GLuint sampler , GLenum pname , GLfloat param); }
#define glSamplerParameterf DynamicGL_SamplerParameterf
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SamplerParameterfv)(GLuint sampler , GLenum pname , const GLfloat *param); }
#define glSamplerParameterfv DynamicGL_SamplerParameterfv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SamplerParameterIiv)(GLuint sampler , GLenum pname , const GLint *param); }
#define glSamplerParameterIiv DynamicGL_SamplerParameterIiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SamplerParameterIuiv)(GLuint sampler , GLenum pname , const GLuint *param); }
#define glSamplerParameterIuiv DynamicGL_SamplerParameterIuiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetSamplerParameteriv)(GLuint sampler , GLenum pname , GLint *params); }
#define glGetSamplerParameteriv DynamicGL_GetSamplerParameteriv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetSamplerParameterIiv)(GLuint sampler , GLenum pname , GLint *params); }
#define glGetSamplerParameterIiv DynamicGL_GetSamplerParameterIiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetSamplerParameterfv)(GLuint sampler , GLenum pname , GLfloat *params); }
#define glGetSamplerParameterfv DynamicGL_GetSamplerParameterfv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetSamplerParameterIuiv)(GLuint sampler , GLenum pname , GLuint *params); }
#define glGetSamplerParameterIuiv DynamicGL_GetSamplerParameterIuiv
extern bool DinamicGLFeature_ARB_sampler_objects_Supported();
#endif /*USE_DYNAMIC_GL_ARB_sampler_objects*/

/*ARB_vertex_attrib_64bit*/
#ifdef USE_DYNAMIC_GL_ARB_vertex_attrib_64bit
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribL1d)(GLuint index , GLdouble x); }
#define glVertexAttribL1d DynamicGL_VertexAttribL1d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribL2d)(GLuint index , GLdouble x , GLdouble y); }
#define glVertexAttribL2d DynamicGL_VertexAttribL2d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribL3d)(GLuint index , GLdouble x , GLdouble y , GLdouble z); }
#define glVertexAttribL3d DynamicGL_VertexAttribL3d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribL4d)(GLuint index , GLdouble x , GLdouble y , GLdouble z , GLdouble w); }
#define glVertexAttribL4d DynamicGL_VertexAttribL4d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribL1dv)(GLuint index , const GLdouble *v); }
#define glVertexAttribL1dv DynamicGL_VertexAttribL1dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribL2dv)(GLuint index , const GLdouble *v); }
#define glVertexAttribL2dv DynamicGL_VertexAttribL2dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribL3dv)(GLuint index , const GLdouble *v); }
#define glVertexAttribL3dv DynamicGL_VertexAttribL3dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribL4dv)(GLuint index , const GLdouble *v); }
#define glVertexAttribL4dv DynamicGL_VertexAttribL4dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribLPointer)(GLuint index , GLint size , GLenum type , GLsizei stride , const GLvoid *pointer); }
#define glVertexAttribLPointer DynamicGL_VertexAttribLPointer
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribLdv)(GLuint index , GLenum pname , GLdouble *params); }
#define glGetVertexAttribLdv DynamicGL_GetVertexAttribLdv
extern bool DinamicGLFeature_ARB_vertex_attrib_64bit_Supported();
#endif /*USE_DYNAMIC_GL_ARB_vertex_attrib_64bit*/

/*SGIS_texture_border_clamp*/
#ifdef USE_DYNAMIC_GL_SGIS_texture_border_clamp
#define GL_CLAMP_TO_BORDER_SGIS 0x812D
extern bool DinamicGLFeature_SGIS_texture_border_clamp_Supported();
#endif /*USE_DYNAMIC_GL_SGIS_texture_border_clamp*/

/*EXT_gpu_program_parameters*/
#ifdef USE_DYNAMIC_GL_EXT_gpu_program_parameters
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramEnvParameters4fvEXT)(GLenum target , GLuint index , GLsizei count , const GLfloat *params); }
#define glProgramEnvParameters4fvEXT DynamicGL_ProgramEnvParameters4fvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramLocalParameters4fvEXT)(GLenum target , GLuint index , GLsizei count , const GLfloat *params); }
#define glProgramLocalParameters4fvEXT DynamicGL_ProgramLocalParameters4fvEXT
extern bool DinamicGLFeature_EXT_gpu_program_parameters_Supported();
#endif /*USE_DYNAMIC_GL_EXT_gpu_program_parameters*/

/*SGIX_texture_add_env*/
#ifdef USE_DYNAMIC_GL_SGIX_texture_add_env
#define GL_TEXTURE_ENV_BIAS_SGIX 0x80BE
extern bool DinamicGLFeature_SGIX_texture_add_env_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_texture_add_env*/

/*EXT_paletted_texture*/
#ifdef USE_DYNAMIC_GL_EXT_paletted_texture
#define GL_COLOR_INDEX1_EXT 0x80E2
#define GL_COLOR_INDEX2_EXT 0x80E3
#define GL_COLOR_INDEX4_EXT 0x80E4
#define GL_COLOR_INDEX8_EXT 0x80E5
#define GL_COLOR_INDEX12_EXT 0x80E6
#define GL_COLOR_INDEX16_EXT 0x80E7
#define GL_TEXTURE_INDEX_SIZE_EXT 0x80ED
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorTableEXT)(GLenum target , GLenum internalFormat , GLsizei width , GLenum format , GLenum type , const GLvoid *table); }
#define glColorTableEXT DynamicGL_ColorTableEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetColorTableEXT)(GLenum target , GLenum format , GLenum type , GLvoid *data); }
#define glGetColorTableEXT DynamicGL_GetColorTableEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetColorTableParameterivEXT)(GLenum target , GLenum pname , GLint *params); }
#define glGetColorTableParameterivEXT DynamicGL_GetColorTableParameterivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetColorTableParameterfvEXT)(GLenum target , GLenum pname , GLfloat *params); }
#define glGetColorTableParameterfvEXT DynamicGL_GetColorTableParameterfvEXT
extern bool DinamicGLFeature_EXT_paletted_texture_Supported();
#endif /*USE_DYNAMIC_GL_EXT_paletted_texture*/

/*ARB_gpu_shader_fp64*/
#ifdef USE_DYNAMIC_GL_ARB_gpu_shader_fp64
#define GL_DOUBLE_VEC2 0x8FFC
#define GL_DOUBLE_VEC3 0x8FFD
#define GL_DOUBLE_VEC4 0x8FFE
#define GL_DOUBLE_MAT2 0x8F46
#define GL_DOUBLE_MAT3 0x8F47
#define GL_DOUBLE_MAT4 0x8F48
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform1d)(GLint location , GLdouble x); }
#define glUniform1d DynamicGL_Uniform1d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform2d)(GLint location , GLdouble x , GLdouble y); }
#define glUniform2d DynamicGL_Uniform2d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform3d)(GLint location , GLdouble x , GLdouble y , GLdouble z); }
#define glUniform3d DynamicGL_Uniform3d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform4d)(GLint location , GLdouble x , GLdouble y , GLdouble z , GLdouble w); }
#define glUniform4d DynamicGL_Uniform4d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform1dv)(GLint location , GLsizei count , const GLdouble *value); }
#define glUniform1dv DynamicGL_Uniform1dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform2dv)(GLint location , GLsizei count , const GLdouble *value); }
#define glUniform2dv DynamicGL_Uniform2dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform3dv)(GLint location , GLsizei count , const GLdouble *value); }
#define glUniform3dv DynamicGL_Uniform3dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform4dv)(GLint location , GLsizei count , const GLdouble *value); }
#define glUniform4dv DynamicGL_Uniform4dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformMatrix2dv)(GLint location , GLsizei count , GLboolean transpose , const GLdouble *value); }
#define glUniformMatrix2dv DynamicGL_UniformMatrix2dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformMatrix3dv)(GLint location , GLsizei count , GLboolean transpose , const GLdouble *value); }
#define glUniformMatrix3dv DynamicGL_UniformMatrix3dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformMatrix4dv)(GLint location , GLsizei count , GLboolean transpose , const GLdouble *value); }
#define glUniformMatrix4dv DynamicGL_UniformMatrix4dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformMatrix2x3dv)(GLint location , GLsizei count , GLboolean transpose , const GLdouble *value); }
#define glUniformMatrix2x3dv DynamicGL_UniformMatrix2x3dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformMatrix2x4dv)(GLint location , GLsizei count , GLboolean transpose , const GLdouble *value); }
#define glUniformMatrix2x4dv DynamicGL_UniformMatrix2x4dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformMatrix3x2dv)(GLint location , GLsizei count , GLboolean transpose , const GLdouble *value); }
#define glUniformMatrix3x2dv DynamicGL_UniformMatrix3x2dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformMatrix3x4dv)(GLint location , GLsizei count , GLboolean transpose , const GLdouble *value); }
#define glUniformMatrix3x4dv DynamicGL_UniformMatrix3x4dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformMatrix4x2dv)(GLint location , GLsizei count , GLboolean transpose , const GLdouble *value); }
#define glUniformMatrix4x2dv DynamicGL_UniformMatrix4x2dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformMatrix4x3dv)(GLint location , GLsizei count , GLboolean transpose , const GLdouble *value); }
#define glUniformMatrix4x3dv DynamicGL_UniformMatrix4x3dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetUniformdv)(GLuint program , GLint location , GLdouble *params); }
#define glGetUniformdv DynamicGL_GetUniformdv
extern bool DinamicGLFeature_ARB_gpu_shader_fp64_Supported();
#endif /*USE_DYNAMIC_GL_ARB_gpu_shader_fp64*/

/*EXT_light_texture*/
#ifdef USE_DYNAMIC_GL_EXT_light_texture
#define GL_FRAGMENT_MATERIAL_EXT 0x8349
#define GL_FRAGMENT_NORMAL_EXT 0x834A
#define GL_FRAGMENT_COLOR_EXT 0x834C
#define GL_ATTENUATION_EXT 0x834D
#define GL_SHADOW_ATTENUATION_EXT 0x834E
#define GL_TEXTURE_APPLICATION_MODE_EXT 0x834F
#define GL_TEXTURE_LIGHT_EXT 0x8350
#define GL_TEXTURE_MATERIAL_FACE_EXT 0x8351
#define GL_TEXTURE_MATERIAL_PARAMETER_EXT 0x8352
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ApplyTextureEXT)(GLenum mode); }
#define glApplyTextureEXT DynamicGL_ApplyTextureEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureLightEXT)(GLenum pname); }
#define glTextureLightEXT DynamicGL_TextureLightEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureMaterialEXT)(GLenum face , GLenum mode); }
#define glTextureMaterialEXT DynamicGL_TextureMaterialEXT
extern bool DinamicGLFeature_EXT_light_texture_Supported();
#endif /*USE_DYNAMIC_GL_EXT_light_texture*/

/*ARB_map_buffer_alignment*/
#ifdef USE_DYNAMIC_GL_ARB_map_buffer_alignment
#define GL_MIN_MAP_BUFFER_ALIGNMENT 0x90BC
extern bool DinamicGLFeature_ARB_map_buffer_alignment_Supported();
#endif /*USE_DYNAMIC_GL_ARB_map_buffer_alignment*/

/*EXT_multisample*/
#ifdef USE_DYNAMIC_GL_EXT_multisample
#define GL_MULTISAMPLE_EXT 0x809D
#define GL_SAMPLE_ALPHA_TO_MASK_EXT 0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_EXT 0x809F
#define GL_SAMPLE_MASK_EXT 0x80A0
#define GL_1PASS_EXT 0x80A1
#define GL_2PASS_0_EXT 0x80A2
#define GL_2PASS_1_EXT 0x80A3
#define GL_4PASS_0_EXT 0x80A4
#define GL_4PASS_1_EXT 0x80A5
#define GL_4PASS_2_EXT 0x80A6
#define GL_4PASS_3_EXT 0x80A7
#define GL_SAMPLE_BUFFERS_EXT 0x80A8
#define GL_SAMPLES_EXT 0x80A9
#define GL_SAMPLE_MASK_VALUE_EXT 0x80AA
#define GL_SAMPLE_MASK_INVERT_EXT 0x80AB
#define GL_SAMPLE_PATTERN_EXT 0x80AC
#define GL_MULTISAMPLE_BIT_EXT 0x20000000
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SampleMaskEXT)(GLclampf value , GLboolean invert); }
#define glSampleMaskEXT DynamicGL_SampleMaskEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SamplePatternEXT)(GLenum pattern); }
#define glSamplePatternEXT DynamicGL_SamplePatternEXT
extern bool DinamicGLFeature_EXT_multisample_Supported();
#endif /*USE_DYNAMIC_GL_EXT_multisample*/

/*SGIX_resample*/
#ifdef USE_DYNAMIC_GL_SGIX_resample
#define GL_PACK_RESAMPLE_SGIX 0x842C
#define GL_UNPACK_RESAMPLE_SGIX 0x842D
#define GL_RESAMPLE_REPLICATE_SGIX 0x842E
#define GL_RESAMPLE_ZERO_FILL_SGIX 0x842F
#define GL_RESAMPLE_DECIMATE_SGIX 0x8430
extern bool DinamicGLFeature_SGIX_resample_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_resample*/

/*ARB_vertex_program*/
#ifdef USE_DYNAMIC_GL_ARB_vertex_program
#define GL_COLOR_SUM_ARB 0x8458
#define GL_VERTEX_PROGRAM_ARB 0x8620
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB 0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE_ARB 0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE_ARB 0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE_ARB 0x8625
#define GL_CURRENT_VERTEX_ATTRIB_ARB 0x8626
#define GL_PROGRAM_LENGTH_ARB 0x8627
#define GL_PROGRAM_STRING_ARB 0x8628
#define GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB 0x862E
#define GL_MAX_PROGRAM_MATRICES_ARB 0x862F
#define GL_CURRENT_MATRIX_STACK_DEPTH_ARB 0x8640
#define GL_CURRENT_MATRIX_ARB 0x8641
#define GL_VERTEX_PROGRAM_POINT_SIZE_ARB 0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE_ARB 0x8643
#define GL_VERTEX_ATTRIB_ARRAY_POINTER_ARB 0x8645
#define GL_PROGRAM_ERROR_POSITION_ARB 0x864B
#define GL_PROGRAM_BINDING_ARB 0x8677
#define GL_MAX_VERTEX_ATTRIBS_ARB 0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB 0x886A
#define GL_PROGRAM_ERROR_STRING_ARB 0x8874
#define GL_PROGRAM_FORMAT_ASCII_ARB 0x8875
#define GL_PROGRAM_FORMAT_ARB 0x8876
#define GL_PROGRAM_INSTRUCTIONS_ARB 0x88A0
#define GL_MAX_PROGRAM_INSTRUCTIONS_ARB 0x88A1
#define GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB 0x88A2
#define GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB 0x88A3
#define GL_PROGRAM_TEMPORARIES_ARB 0x88A4
#define GL_MAX_PROGRAM_TEMPORARIES_ARB 0x88A5
#define GL_PROGRAM_NATIVE_TEMPORARIES_ARB 0x88A6
#define GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB 0x88A7
#define GL_PROGRAM_PARAMETERS_ARB 0x88A8
#define GL_MAX_PROGRAM_PARAMETERS_ARB 0x88A9
#define GL_PROGRAM_NATIVE_PARAMETERS_ARB 0x88AA
#define GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB 0x88AB
#define GL_PROGRAM_ATTRIBS_ARB 0x88AC
#define GL_MAX_PROGRAM_ATTRIBS_ARB 0x88AD
#define GL_PROGRAM_NATIVE_ATTRIBS_ARB 0x88AE
#define GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB 0x88AF
#define GL_PROGRAM_ADDRESS_REGISTERS_ARB 0x88B0
#define GL_MAX_PROGRAM_ADDRESS_REGISTERS_ARB 0x88B1
#define GL_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB 0x88B2
#define GL_MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB 0x88B3
#define GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB 0x88B4
#define GL_MAX_PROGRAM_ENV_PARAMETERS_ARB 0x88B5
#define GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB 0x88B6
#define GL_TRANSPOSE_CURRENT_MATRIX_ARB 0x88B7
#define GL_MATRIX0_ARB 0x88C0
#define GL_MATRIX1_ARB 0x88C1
#define GL_MATRIX2_ARB 0x88C2
#define GL_MATRIX3_ARB 0x88C3
#define GL_MATRIX4_ARB 0x88C4
#define GL_MATRIX5_ARB 0x88C5
#define GL_MATRIX6_ARB 0x88C6
#define GL_MATRIX7_ARB 0x88C7
#define GL_MATRIX8_ARB 0x88C8
#define GL_MATRIX9_ARB 0x88C9
#define GL_MATRIX10_ARB 0x88CA
#define GL_MATRIX11_ARB 0x88CB
#define GL_MATRIX12_ARB 0x88CC
#define GL_MATRIX13_ARB 0x88CD
#define GL_MATRIX14_ARB 0x88CE
#define GL_MATRIX15_ARB 0x88CF
#define GL_MATRIX16_ARB 0x88D0
#define GL_MATRIX17_ARB 0x88D1
#define GL_MATRIX18_ARB 0x88D2
#define GL_MATRIX19_ARB 0x88D3
#define GL_MATRIX20_ARB 0x88D4
#define GL_MATRIX21_ARB 0x88D5
#define GL_MATRIX22_ARB 0x88D6
#define GL_MATRIX23_ARB 0x88D7
#define GL_MATRIX24_ARB 0x88D8
#define GL_MATRIX25_ARB 0x88D9
#define GL_MATRIX26_ARB 0x88DA
#define GL_MATRIX27_ARB 0x88DB
#define GL_MATRIX28_ARB 0x88DC
#define GL_MATRIX29_ARB 0x88DD
#define GL_MATRIX30_ARB 0x88DE
#define GL_MATRIX31_ARB 0x88DF
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1dARB)(GLuint index , GLdouble x); }
#define glVertexAttrib1dARB DynamicGL_VertexAttrib1dARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1dvARB)(GLuint index , const GLdouble *v); }
#define glVertexAttrib1dvARB DynamicGL_VertexAttrib1dvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1fARB)(GLuint index , GLfloat x); }
#define glVertexAttrib1fARB DynamicGL_VertexAttrib1fARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1fvARB)(GLuint index , const GLfloat *v); }
#define glVertexAttrib1fvARB DynamicGL_VertexAttrib1fvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1sARB)(GLuint index , GLshort x); }
#define glVertexAttrib1sARB DynamicGL_VertexAttrib1sARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1svARB)(GLuint index , const GLshort *v); }
#define glVertexAttrib1svARB DynamicGL_VertexAttrib1svARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2dARB)(GLuint index , GLdouble x , GLdouble y); }
#define glVertexAttrib2dARB DynamicGL_VertexAttrib2dARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2dvARB)(GLuint index , const GLdouble *v); }
#define glVertexAttrib2dvARB DynamicGL_VertexAttrib2dvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2fARB)(GLuint index , GLfloat x , GLfloat y); }
#define glVertexAttrib2fARB DynamicGL_VertexAttrib2fARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2fvARB)(GLuint index , const GLfloat *v); }
#define glVertexAttrib2fvARB DynamicGL_VertexAttrib2fvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2sARB)(GLuint index , GLshort x , GLshort y); }
#define glVertexAttrib2sARB DynamicGL_VertexAttrib2sARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2svARB)(GLuint index , const GLshort *v); }
#define glVertexAttrib2svARB DynamicGL_VertexAttrib2svARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3dARB)(GLuint index , GLdouble x , GLdouble y , GLdouble z); }
#define glVertexAttrib3dARB DynamicGL_VertexAttrib3dARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3dvARB)(GLuint index , const GLdouble *v); }
#define glVertexAttrib3dvARB DynamicGL_VertexAttrib3dvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3fARB)(GLuint index , GLfloat x , GLfloat y , GLfloat z); }
#define glVertexAttrib3fARB DynamicGL_VertexAttrib3fARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3fvARB)(GLuint index , const GLfloat *v); }
#define glVertexAttrib3fvARB DynamicGL_VertexAttrib3fvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3sARB)(GLuint index , GLshort x , GLshort y , GLshort z); }
#define glVertexAttrib3sARB DynamicGL_VertexAttrib3sARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3svARB)(GLuint index , const GLshort *v); }
#define glVertexAttrib3svARB DynamicGL_VertexAttrib3svARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4NbvARB)(GLuint index , const GLbyte *v); }
#define glVertexAttrib4NbvARB DynamicGL_VertexAttrib4NbvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4NivARB)(GLuint index , const GLint *v); }
#define glVertexAttrib4NivARB DynamicGL_VertexAttrib4NivARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4NsvARB)(GLuint index , const GLshort *v); }
#define glVertexAttrib4NsvARB DynamicGL_VertexAttrib4NsvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4NubARB)(GLuint index , GLubyte x , GLubyte y , GLubyte z , GLubyte w); }
#define glVertexAttrib4NubARB DynamicGL_VertexAttrib4NubARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4NubvARB)(GLuint index , const GLubyte *v); }
#define glVertexAttrib4NubvARB DynamicGL_VertexAttrib4NubvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4NuivARB)(GLuint index , const GLuint *v); }
#define glVertexAttrib4NuivARB DynamicGL_VertexAttrib4NuivARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4NusvARB)(GLuint index , const GLushort *v); }
#define glVertexAttrib4NusvARB DynamicGL_VertexAttrib4NusvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4bvARB)(GLuint index , const GLbyte *v); }
#define glVertexAttrib4bvARB DynamicGL_VertexAttrib4bvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4dARB)(GLuint index , GLdouble x , GLdouble y , GLdouble z , GLdouble w); }
#define glVertexAttrib4dARB DynamicGL_VertexAttrib4dARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4dvARB)(GLuint index , const GLdouble *v); }
#define glVertexAttrib4dvARB DynamicGL_VertexAttrib4dvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4fARB)(GLuint index , GLfloat x , GLfloat y , GLfloat z , GLfloat w); }
#define glVertexAttrib4fARB DynamicGL_VertexAttrib4fARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4fvARB)(GLuint index , const GLfloat *v); }
#define glVertexAttrib4fvARB DynamicGL_VertexAttrib4fvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4ivARB)(GLuint index , const GLint *v); }
#define glVertexAttrib4ivARB DynamicGL_VertexAttrib4ivARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4sARB)(GLuint index , GLshort x , GLshort y , GLshort z , GLshort w); }
#define glVertexAttrib4sARB DynamicGL_VertexAttrib4sARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4svARB)(GLuint index , const GLshort *v); }
#define glVertexAttrib4svARB DynamicGL_VertexAttrib4svARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4ubvARB)(GLuint index , const GLubyte *v); }
#define glVertexAttrib4ubvARB DynamicGL_VertexAttrib4ubvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4uivARB)(GLuint index , const GLuint *v); }
#define glVertexAttrib4uivARB DynamicGL_VertexAttrib4uivARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4usvARB)(GLuint index , const GLushort *v); }
#define glVertexAttrib4usvARB DynamicGL_VertexAttrib4usvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribPointerARB)(GLuint index , GLint size , GLenum type , GLboolean normalized , GLsizei stride , const GLvoid *pointer); }
#define glVertexAttribPointerARB DynamicGL_VertexAttribPointerARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EnableVertexAttribArrayARB)(GLuint index); }
#define glEnableVertexAttribArrayARB DynamicGL_EnableVertexAttribArrayARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DisableVertexAttribArrayARB)(GLuint index); }
#define glDisableVertexAttribArrayARB DynamicGL_DisableVertexAttribArrayARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramStringARB)(GLenum target , GLenum format , GLsizei len , const GLvoid *string); }
#define glProgramStringARB DynamicGL_ProgramStringARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindProgramARB)(GLenum target , GLuint program); }
#define glBindProgramARB DynamicGL_BindProgramARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteProgramsARB)(GLsizei n , const GLuint *programs); }
#define glDeleteProgramsARB DynamicGL_DeleteProgramsARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GenProgramsARB)(GLsizei n , GLuint *programs); }
#define glGenProgramsARB DynamicGL_GenProgramsARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramEnvParameter4dARB)(GLenum target , GLuint index , GLdouble x , GLdouble y , GLdouble z , GLdouble w); }
#define glProgramEnvParameter4dARB DynamicGL_ProgramEnvParameter4dARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramEnvParameter4dvARB)(GLenum target , GLuint index , const GLdouble *params); }
#define glProgramEnvParameter4dvARB DynamicGL_ProgramEnvParameter4dvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramEnvParameter4fARB)(GLenum target , GLuint index , GLfloat x , GLfloat y , GLfloat z , GLfloat w); }
#define glProgramEnvParameter4fARB DynamicGL_ProgramEnvParameter4fARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramEnvParameter4fvARB)(GLenum target , GLuint index , const GLfloat *params); }
#define glProgramEnvParameter4fvARB DynamicGL_ProgramEnvParameter4fvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramLocalParameter4dARB)(GLenum target , GLuint index , GLdouble x , GLdouble y , GLdouble z , GLdouble w); }
#define glProgramLocalParameter4dARB DynamicGL_ProgramLocalParameter4dARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramLocalParameter4dvARB)(GLenum target , GLuint index , const GLdouble *params); }
#define glProgramLocalParameter4dvARB DynamicGL_ProgramLocalParameter4dvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramLocalParameter4fARB)(GLenum target , GLuint index , GLfloat x , GLfloat y , GLfloat z , GLfloat w); }
#define glProgramLocalParameter4fARB DynamicGL_ProgramLocalParameter4fARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramLocalParameter4fvARB)(GLenum target , GLuint index , const GLfloat *params); }
#define glProgramLocalParameter4fvARB DynamicGL_ProgramLocalParameter4fvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramEnvParameterdvARB)(GLenum target , GLuint index , GLdouble *params); }
#define glGetProgramEnvParameterdvARB DynamicGL_GetProgramEnvParameterdvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramEnvParameterfvARB)(GLenum target , GLuint index , GLfloat *params); }
#define glGetProgramEnvParameterfvARB DynamicGL_GetProgramEnvParameterfvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramLocalParameterdvARB)(GLenum target , GLuint index , GLdouble *params); }
#define glGetProgramLocalParameterdvARB DynamicGL_GetProgramLocalParameterdvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramLocalParameterfvARB)(GLenum target , GLuint index , GLfloat *params); }
#define glGetProgramLocalParameterfvARB DynamicGL_GetProgramLocalParameterfvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramivARB)(GLenum target , GLenum pname , GLint *params); }
#define glGetProgramivARB DynamicGL_GetProgramivARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramStringARB)(GLenum target , GLenum pname , GLvoid *string); }
#define glGetProgramStringARB DynamicGL_GetProgramStringARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribdvARB)(GLuint index , GLenum pname , GLdouble *params); }
#define glGetVertexAttribdvARB DynamicGL_GetVertexAttribdvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribfvARB)(GLuint index , GLenum pname , GLfloat *params); }
#define glGetVertexAttribfvARB DynamicGL_GetVertexAttribfvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribivARB)(GLuint index , GLenum pname , GLint *params); }
#define glGetVertexAttribivARB DynamicGL_GetVertexAttribivARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribPointervARB)(GLuint index , GLenum pname , GLvoid* *pointer); }
#define glGetVertexAttribPointervARB DynamicGL_GetVertexAttribPointervARB
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsProgramARB)(GLuint program); }
#define glIsProgramARB DynamicGL_IsProgramARB
extern bool DinamicGLFeature_ARB_vertex_program_Supported();
#endif /*USE_DYNAMIC_GL_ARB_vertex_program*/

/*ARB_tessellation_shader*/
#ifdef USE_DYNAMIC_GL_ARB_tessellation_shader
#define GL_PATCHES 0x000E
#define GL_PATCH_VERTICES 0x8E72
#define GL_PATCH_DEFAULT_INNER_LEVEL 0x8E73
#define GL_PATCH_DEFAULT_OUTER_LEVEL 0x8E74
#define GL_TESS_CONTROL_OUTPUT_VERTICES 0x8E75
#define GL_TESS_GEN_MODE 0x8E76
#define GL_TESS_GEN_SPACING 0x8E77
#define GL_TESS_GEN_VERTEX_ORDER 0x8E78
#define GL_TESS_GEN_POINT_MODE 0x8E79
#define GL_ISOLINES 0x8E7A
#define GL_FRACTIONAL_ODD 0x8E7B
#define GL_FRACTIONAL_EVEN 0x8E7C
#define GL_MAX_PATCH_VERTICES 0x8E7D
#define GL_MAX_TESS_GEN_LEVEL 0x8E7E
#define GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E7F
#define GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E80
#define GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS 0x8E81
#define GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS 0x8E82
#define GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS 0x8E83
#define GL_MAX_TESS_PATCH_COMPONENTS 0x8E84
#define GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS 0x8E85
#define GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS 0x8E86
#define GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS 0x8E89
#define GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS 0x8E8A
#define GL_MAX_TESS_CONTROL_INPUT_COMPONENTS 0x886C
#define GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS 0x886D
#define GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E1E
#define GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E1F
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER 0x84F0
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER 0x84F1
#define GL_TESS_EVALUATION_SHADER 0x8E87
#define GL_TESS_CONTROL_SHADER 0x8E88
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PatchParameteri)(GLenum pname , GLint value); }
#define glPatchParameteri DynamicGL_PatchParameteri
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PatchParameterfv)(GLenum pname , const GLfloat *values); }
#define glPatchParameterfv DynamicGL_PatchParameterfv
extern bool DinamicGLFeature_ARB_tessellation_shader_Supported();
#endif /*USE_DYNAMIC_GL_ARB_tessellation_shader*/

/*EXT_point_parameters*/
#ifdef USE_DYNAMIC_GL_EXT_point_parameters
#define GL_POINT_SIZE_MIN_EXT 0x8126
#define GL_POINT_SIZE_MAX_EXT 0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE_EXT 0x8128
#define GL_DISTANCE_ATTENUATION_EXT 0x8129
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameterfEXT)(GLenum pname , GLfloat param); }
#define glPointParameterfEXT DynamicGL_PointParameterfEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameterfvEXT)(GLenum pname , const GLfloat *params); }
#define glPointParameterfvEXT DynamicGL_PointParameterfvEXT
extern bool DinamicGLFeature_EXT_point_parameters_Supported();
#endif /*USE_DYNAMIC_GL_EXT_point_parameters*/

/*ATI_map_object_buffer*/
#ifdef USE_DYNAMIC_GL_ATI_map_object_buffer
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_UnmapObjectBufferATI)(GLuint buffer); }
#define glUnmapObjectBufferATI DynamicGL_UnmapObjectBufferATI
extern bool DinamicGLFeature_ATI_map_object_buffer_Supported();
#endif /*USE_DYNAMIC_GL_ATI_map_object_buffer*/

/*MESAX_texture_stack*/
#ifdef USE_DYNAMIC_GL_MESAX_texture_stack
#define GL_TEXTURE_1D_STACK_MESAX 0x8759
#define GL_TEXTURE_2D_STACK_MESAX 0x875A
#define GL_PROXY_TEXTURE_1D_STACK_MESAX 0x875B
#define GL_PROXY_TEXTURE_2D_STACK_MESAX 0x875C
#define GL_TEXTURE_1D_STACK_BINDING_MESAX 0x875D
#define GL_TEXTURE_2D_STACK_BINDING_MESAX 0x875E
extern bool DinamicGLFeature_MESAX_texture_stack_Supported();
#endif /*USE_DYNAMIC_GL_MESAX_texture_stack*/

/*SGIS_pixel_texture*/
#ifdef USE_DYNAMIC_GL_SGIS_pixel_texture
#define GL_PIXEL_TEXTURE_SGIS 0x8353
#define GL_PIXEL_FRAGMENT_RGB_SOURCE_SGIS 0x8354
#define GL_PIXEL_FRAGMENT_ALPHA_SOURCE_SGIS 0x8355
#define GL_PIXEL_GROUP_COLOR_SGIS 0x8356
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelTexGenParameteriSGIS)(GLenum pname , GLint param); }
#define glPixelTexGenParameteriSGIS DynamicGL_PixelTexGenParameteriSGIS
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelTexGenParameterivSGIS)(GLenum pname , const GLint *params); }
#define glPixelTexGenParameterivSGIS DynamicGL_PixelTexGenParameterivSGIS
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelTexGenParameterfSGIS)(GLenum pname , GLfloat param); }
#define glPixelTexGenParameterfSGIS DynamicGL_PixelTexGenParameterfSGIS
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PixelTexGenParameterfvSGIS)(GLenum pname , const GLfloat *params); }
#define glPixelTexGenParameterfvSGIS DynamicGL_PixelTexGenParameterfvSGIS
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPixelTexGenParameterivSGIS)(GLenum pname , GLint *params); }
#define glGetPixelTexGenParameterivSGIS DynamicGL_GetPixelTexGenParameterivSGIS
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPixelTexGenParameterfvSGIS)(GLenum pname , GLfloat *params); }
#define glGetPixelTexGenParameterfvSGIS DynamicGL_GetPixelTexGenParameterfvSGIS
extern bool DinamicGLFeature_SGIS_pixel_texture_Supported();
#endif /*USE_DYNAMIC_GL_SGIS_pixel_texture*/

/*NV_vertex_attrib_integer_64bit*/
#ifdef USE_DYNAMIC_GL_NV_vertex_attrib_integer_64bit
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribL1i64NV)(GLuint index , GLint64EXT x); }
#define glVertexAttribL1i64NV DynamicGL_VertexAttribL1i64NV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribL2i64NV)(GLuint index , GLint64EXT x , GLint64EXT y); }
#define glVertexAttribL2i64NV DynamicGL_VertexAttribL2i64NV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribL3i64NV)(GLuint index , GLint64EXT x , GLint64EXT y , GLint64EXT z); }
#define glVertexAttribL3i64NV DynamicGL_VertexAttribL3i64NV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribL4i64NV)(GLuint index , GLint64EXT x , GLint64EXT y , GLint64EXT z , GLint64EXT w); }
#define glVertexAttribL4i64NV DynamicGL_VertexAttribL4i64NV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribL1i64vNV)(GLuint index , const GLint64EXT *v); }
#define glVertexAttribL1i64vNV DynamicGL_VertexAttribL1i64vNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribL2i64vNV)(GLuint index , const GLint64EXT *v); }
#define glVertexAttribL2i64vNV DynamicGL_VertexAttribL2i64vNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribL3i64vNV)(GLuint index , const GLint64EXT *v); }
#define glVertexAttribL3i64vNV DynamicGL_VertexAttribL3i64vNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribL4i64vNV)(GLuint index , const GLint64EXT *v); }
#define glVertexAttribL4i64vNV DynamicGL_VertexAttribL4i64vNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribL1ui64NV)(GLuint index , GLuint64EXT x); }
#define glVertexAttribL1ui64NV DynamicGL_VertexAttribL1ui64NV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribL2ui64NV)(GLuint index , GLuint64EXT x , GLuint64EXT y); }
#define glVertexAttribL2ui64NV DynamicGL_VertexAttribL2ui64NV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribL3ui64NV)(GLuint index , GLuint64EXT x , GLuint64EXT y , GLuint64EXT z); }
#define glVertexAttribL3ui64NV DynamicGL_VertexAttribL3ui64NV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribL4ui64NV)(GLuint index , GLuint64EXT x , GLuint64EXT y , GLuint64EXT z , GLuint64EXT w); }
#define glVertexAttribL4ui64NV DynamicGL_VertexAttribL4ui64NV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribL1ui64vNV)(GLuint index , const GLuint64EXT *v); }
#define glVertexAttribL1ui64vNV DynamicGL_VertexAttribL1ui64vNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribL2ui64vNV)(GLuint index , const GLuint64EXT *v); }
#define glVertexAttribL2ui64vNV DynamicGL_VertexAttribL2ui64vNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribL3ui64vNV)(GLuint index , const GLuint64EXT *v); }
#define glVertexAttribL3ui64vNV DynamicGL_VertexAttribL3ui64vNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribL4ui64vNV)(GLuint index , const GLuint64EXT *v); }
#define glVertexAttribL4ui64vNV DynamicGL_VertexAttribL4ui64vNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribLi64vNV)(GLuint index , GLenum pname , GLint64EXT *params); }
#define glGetVertexAttribLi64vNV DynamicGL_GetVertexAttribLi64vNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribLui64vNV)(GLuint index , GLenum pname , GLuint64EXT *params); }
#define glGetVertexAttribLui64vNV DynamicGL_GetVertexAttribLui64vNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribLFormatNV)(GLuint index , GLint size , GLenum type , GLsizei stride); }
#define glVertexAttribLFormatNV DynamicGL_VertexAttribLFormatNV
extern bool DinamicGLFeature_NV_vertex_attrib_integer_64bit_Supported();
#endif /*USE_DYNAMIC_GL_NV_vertex_attrib_integer_64bit*/

/*ARB_provoking_vertex*/
#ifdef USE_DYNAMIC_GL_ARB_provoking_vertex
#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION 0x8E4C
#define GL_FIRST_VERTEX_CONVENTION 0x8E4D
#define GL_LAST_VERTEX_CONVENTION 0x8E4E
#define GL_PROVOKING_VERTEX 0x8E4F
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProvokingVertex)(GLenum mode); }
#define glProvokingVertex DynamicGL_ProvokingVertex
extern bool DinamicGLFeature_ARB_provoking_vertex_Supported();
#endif /*USE_DYNAMIC_GL_ARB_provoking_vertex*/

/*SGIS_texture4D*/
#ifdef USE_DYNAMIC_GL_SGIS_texture4D
#define GL_PACK_SKIP_VOLUMES_SGIS 0x8130
#define GL_PACK_IMAGE_DEPTH_SGIS 0x8131
#define GL_UNPACK_SKIP_VOLUMES_SGIS 0x8132
#define GL_UNPACK_IMAGE_DEPTH_SGIS 0x8133
#define GL_TEXTURE_4D_SGIS 0x8134
#define GL_PROXY_TEXTURE_4D_SGIS 0x8135
#define GL_TEXTURE_4DSIZE_SGIS 0x8136
#define GL_TEXTURE_WRAP_Q_SGIS 0x8137
#define GL_MAX_4D_TEXTURE_SIZE_SGIS 0x8138
#define GL_TEXTURE_4D_BINDING_SGIS 0x814F
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexImage4DSGIS)(GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLsizei depth , GLsizei size4d , GLint border , GLenum format , GLenum type , const GLvoid *pixels); }
#define glTexImage4DSGIS DynamicGL_TexImage4DSGIS
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexSubImage4DSGIS)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLint woffset , GLsizei width , GLsizei height , GLsizei depth , GLsizei size4d , GLenum format , GLenum type , const GLvoid *pixels); }
#define glTexSubImage4DSGIS DynamicGL_TexSubImage4DSGIS
extern bool DinamicGLFeature_SGIS_texture4D_Supported();
#endif /*USE_DYNAMIC_GL_SGIS_texture4D*/

/*PGI_misc_hints*/
#ifdef USE_DYNAMIC_GL_PGI_misc_hints
#define GL_PREFER_DOUBLEBUFFER_HINT_PGI 0x1A1F8
#define GL_CONSERVE_MEMORY_HINT_PGI 0x1A1FD
#define GL_RECLAIM_MEMORY_HINT_PGI 0x1A1FE
#define GL_NATIVE_GRAPHICS_HANDLE_PGI 0x1A202
#define GL_NATIVE_GRAPHICS_BEGIN_HINT_PGI 0x1A203
#define GL_NATIVE_GRAPHICS_END_HINT_PGI 0x1A204
#define GL_ALWAYS_FAST_HINT_PGI 0x1A20C
#define GL_ALWAYS_SOFT_HINT_PGI 0x1A20D
#define GL_ALLOW_DRAW_OBJ_HINT_PGI 0x1A20E
#define GL_ALLOW_DRAW_WIN_HINT_PGI 0x1A20F
#define GL_ALLOW_DRAW_FRG_HINT_PGI 0x1A210
#define GL_ALLOW_DRAW_MEM_HINT_PGI 0x1A211
#define GL_STRICT_DEPTHFUNC_HINT_PGI 0x1A216
#define GL_STRICT_LIGHTING_HINT_PGI 0x1A217
#define GL_STRICT_SCISSOR_HINT_PGI 0x1A218
#define GL_FULL_STIPPLE_HINT_PGI 0x1A219
#define GL_CLIP_NEAR_HINT_PGI 0x1A220
#define GL_CLIP_FAR_HINT_PGI 0x1A221
#define GL_WIDE_LINE_HINT_PGI 0x1A222
#define GL_BACK_NORMALS_HINT_PGI 0x1A223
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_HintPGI)(GLenum target , GLint mode); }
#define glHintPGI DynamicGL_HintPGI
extern bool DinamicGLFeature_PGI_misc_hints_Supported();
#endif /*USE_DYNAMIC_GL_PGI_misc_hints*/

/*SGIS_multisample*/
#ifdef USE_DYNAMIC_GL_SGIS_multisample
#define GL_MULTISAMPLE_SGIS 0x809D
#define GL_SAMPLE_ALPHA_TO_MASK_SGIS 0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_SGIS 0x809F
#define GL_SAMPLE_MASK_SGIS 0x80A0
#define GL_1PASS_SGIS 0x80A1
#define GL_2PASS_0_SGIS 0x80A2
#define GL_2PASS_1_SGIS 0x80A3
#define GL_4PASS_0_SGIS 0x80A4
#define GL_4PASS_1_SGIS 0x80A5
#define GL_4PASS_2_SGIS 0x80A6
#define GL_4PASS_3_SGIS 0x80A7
#define GL_SAMPLE_BUFFERS_SGIS 0x80A8
#define GL_SAMPLES_SGIS 0x80A9
#define GL_SAMPLE_MASK_VALUE_SGIS 0x80AA
#define GL_SAMPLE_MASK_INVERT_SGIS 0x80AB
#define GL_SAMPLE_PATTERN_SGIS 0x80AC
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SampleMaskSGIS)(GLclampf value , GLboolean invert); }
#define glSampleMaskSGIS DynamicGL_SampleMaskSGIS
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SamplePatternSGIS)(GLenum pattern); }
#define glSamplePatternSGIS DynamicGL_SamplePatternSGIS
extern bool DinamicGLFeature_SGIS_multisample_Supported();
#endif /*USE_DYNAMIC_GL_SGIS_multisample*/

/*NV_vdpau_interop*/
#ifdef USE_DYNAMIC_GL_NV_vdpau_interop
typedef GLintptr GLvdpauSurfaceNV;
#define GL_SURFACE_STATE_NV 0x86EB
#define GL_SURFACE_REGISTERED_NV 0x86FD
#define GL_SURFACE_MAPPED_NV 0x8700
#define GL_WRITE_DISCARD_NV 0x88BE
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VDPAUInitNV)(const GLvoid *vdpDevice , const GLvoid *getProcAddress); }
#define glVDPAUInitNV DynamicGL_VDPAUInitNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VDPAUFiniNV)(); }
#define glVDPAUFiniNV DynamicGL_VDPAUFiniNV
extern "C" { extern GLvdpauSurfaceNV (DYNAMIC_GL_APIENTRYP DynamicGL_VDPAURegisterVideoSurfaceNV)(GLvoid *vdpSurface , GLenum target , GLsizei numTextureNames , const GLuint *textureNames); }
#define glVDPAURegisterVideoSurfaceNV DynamicGL_VDPAURegisterVideoSurfaceNV
extern "C" { extern GLvdpauSurfaceNV (DYNAMIC_GL_APIENTRYP DynamicGL_VDPAURegisterOutputSurfaceNV)(GLvoid *vdpSurface , GLenum target , GLsizei numTextureNames , const GLuint *textureNames); }
#define glVDPAURegisterOutputSurfaceNV DynamicGL_VDPAURegisterOutputSurfaceNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VDPAUIsSurfaceNV)(GLvdpauSurfaceNV surface); }
#define glVDPAUIsSurfaceNV DynamicGL_VDPAUIsSurfaceNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VDPAUUnregisterSurfaceNV)(GLvdpauSurfaceNV surface); }
#define glVDPAUUnregisterSurfaceNV DynamicGL_VDPAUUnregisterSurfaceNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VDPAUGetSurfaceivNV)(GLvdpauSurfaceNV surface , GLenum pname , GLsizei bufSize , GLsizei *length , GLint *values); }
#define glVDPAUGetSurfaceivNV DynamicGL_VDPAUGetSurfaceivNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VDPAUSurfaceAccessNV)(GLvdpauSurfaceNV surface , GLenum access); }
#define glVDPAUSurfaceAccessNV DynamicGL_VDPAUSurfaceAccessNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VDPAUMapSurfacesNV)(GLsizei numSurfaces , const GLvdpauSurfaceNV *surfaces); }
#define glVDPAUMapSurfacesNV DynamicGL_VDPAUMapSurfacesNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VDPAUUnmapSurfacesNV)(GLsizei numSurface , const GLvdpauSurfaceNV *surfaces); }
#define glVDPAUUnmapSurfacesNV DynamicGL_VDPAUUnmapSurfacesNV
extern bool DinamicGLFeature_NV_vdpau_interop_Supported();
#endif /*USE_DYNAMIC_GL_NV_vdpau_interop*/

/*EXT_texture_sRGB_decode*/
#ifdef USE_DYNAMIC_GL_EXT_texture_sRGB_decode
#define GL_TEXTURE_SRGB_DECODE_EXT 0x8A48
#define GL_DECODE_EXT 0x8A49
#define GL_SKIP_DECODE_EXT 0x8A4A
extern bool DinamicGLFeature_EXT_texture_sRGB_decode_Supported();
#endif /*USE_DYNAMIC_GL_EXT_texture_sRGB_decode*/

/*ARB_window_pos*/
#ifdef USE_DYNAMIC_GL_ARB_window_pos
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2dARB)(GLdouble x , GLdouble y); }
#define glWindowPos2dARB DynamicGL_WindowPos2dARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2dvARB)(const GLdouble *v); }
#define glWindowPos2dvARB DynamicGL_WindowPos2dvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2fARB)(GLfloat x , GLfloat y); }
#define glWindowPos2fARB DynamicGL_WindowPos2fARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2fvARB)(const GLfloat *v); }
#define glWindowPos2fvARB DynamicGL_WindowPos2fvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2iARB)(GLint x , GLint y); }
#define glWindowPos2iARB DynamicGL_WindowPos2iARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2ivARB)(const GLint *v); }
#define glWindowPos2ivARB DynamicGL_WindowPos2ivARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2sARB)(GLshort x , GLshort y); }
#define glWindowPos2sARB DynamicGL_WindowPos2sARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2svARB)(const GLshort *v); }
#define glWindowPos2svARB DynamicGL_WindowPos2svARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3dARB)(GLdouble x , GLdouble y , GLdouble z); }
#define glWindowPos3dARB DynamicGL_WindowPos3dARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3dvARB)(const GLdouble *v); }
#define glWindowPos3dvARB DynamicGL_WindowPos3dvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3fARB)(GLfloat x , GLfloat y , GLfloat z); }
#define glWindowPos3fARB DynamicGL_WindowPos3fARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3fvARB)(const GLfloat *v); }
#define glWindowPos3fvARB DynamicGL_WindowPos3fvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3iARB)(GLint x , GLint y , GLint z); }
#define glWindowPos3iARB DynamicGL_WindowPos3iARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3ivARB)(const GLint *v); }
#define glWindowPos3ivARB DynamicGL_WindowPos3ivARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3sARB)(GLshort x , GLshort y , GLshort z); }
#define glWindowPos3sARB DynamicGL_WindowPos3sARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3svARB)(const GLshort *v); }
#define glWindowPos3svARB DynamicGL_WindowPos3svARB
extern bool DinamicGLFeature_ARB_window_pos_Supported();
#endif /*USE_DYNAMIC_GL_ARB_window_pos*/

/*NV_transform_feedback2*/
#ifdef USE_DYNAMIC_GL_NV_transform_feedback2
#define GL_TRANSFORM_FEEDBACK_NV 0x8E22
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED_NV 0x8E23
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE_NV 0x8E24
#define GL_TRANSFORM_FEEDBACK_BINDING_NV 0x8E25
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindTransformFeedbackNV)(GLenum target , GLuint id); }
#define glBindTransformFeedbackNV DynamicGL_BindTransformFeedbackNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteTransformFeedbacksNV)(GLsizei n , const GLuint *ids); }
#define glDeleteTransformFeedbacksNV DynamicGL_DeleteTransformFeedbacksNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GenTransformFeedbacksNV)(GLsizei n , GLuint *ids); }
#define glGenTransformFeedbacksNV DynamicGL_GenTransformFeedbacksNV
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsTransformFeedbackNV)(GLuint id); }
#define glIsTransformFeedbackNV DynamicGL_IsTransformFeedbackNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PauseTransformFeedbackNV)(); }
#define glPauseTransformFeedbackNV DynamicGL_PauseTransformFeedbackNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ResumeTransformFeedbackNV)(); }
#define glResumeTransformFeedbackNV DynamicGL_ResumeTransformFeedbackNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawTransformFeedbackNV)(GLenum mode , GLuint id); }
#define glDrawTransformFeedbackNV DynamicGL_DrawTransformFeedbackNV
extern bool DinamicGLFeature_NV_transform_feedback2_Supported();
#endif /*USE_DYNAMIC_GL_NV_transform_feedback2*/

/*SGIX_polynomial_ffd*/
#ifdef USE_DYNAMIC_GL_SGIX_polynomial_ffd
#define GL_GEOMETRY_DEFORMATION_SGIX 0x8194
#define GL_TEXTURE_DEFORMATION_SGIX 0x8195
#define GL_DEFORMATIONS_MASK_SGIX 0x8196
#define GL_MAX_DEFORMATION_ORDER_SGIX 0x8197
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeformationMap3dSGIX)(GLenum target , GLdouble u1 , GLdouble u2 , GLint ustride , GLint uorder , GLdouble v1 , GLdouble v2 , GLint vstride , GLint vorder , GLdouble w1 , GLdouble w2 , GLint wstride , GLint worder , const GLdouble *points); }
#define glDeformationMap3dSGIX DynamicGL_DeformationMap3dSGIX
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeformationMap3fSGIX)(GLenum target , GLfloat u1 , GLfloat u2 , GLint ustride , GLint uorder , GLfloat v1 , GLfloat v2 , GLint vstride , GLint vorder , GLfloat w1 , GLfloat w2 , GLint wstride , GLint worder , const GLfloat *points); }
#define glDeformationMap3fSGIX DynamicGL_DeformationMap3fSGIX
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeformSGIX)(GLbitfield mask); }
#define glDeformSGIX DynamicGL_DeformSGIX
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LoadIdentityDeformationMapSGIX)(GLbitfield mask); }
#define glLoadIdentityDeformationMapSGIX DynamicGL_LoadIdentityDeformationMapSGIX
extern bool DinamicGLFeature_SGIX_polynomial_ffd_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_polynomial_ffd*/

/*EXT_timer_query*/
#ifdef USE_DYNAMIC_GL_EXT_timer_query
typedef int64_t GLint64EXT;
typedef uint64_t GLuint64EXT;
#define GL_TIME_ELAPSED_EXT 0x88BF
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetQueryObjecti64vEXT)(GLuint id , GLenum pname , GLint64EXT *params); }
#define glGetQueryObjecti64vEXT DynamicGL_GetQueryObjecti64vEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetQueryObjectui64vEXT)(GLuint id , GLenum pname , GLuint64EXT *params); }
#define glGetQueryObjectui64vEXT DynamicGL_GetQueryObjectui64vEXT
extern bool DinamicGLFeature_EXT_timer_query_Supported();
#endif /*USE_DYNAMIC_GL_EXT_timer_query*/

/*SGIX_ir_instrument1*/
#ifdef USE_DYNAMIC_GL_SGIX_ir_instrument1
#define GL_IR_INSTRUMENT1_SGIX 0x817F
extern bool DinamicGLFeature_SGIX_ir_instrument1_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_ir_instrument1*/

/*NV_texture_barrier*/
#ifdef USE_DYNAMIC_GL_NV_texture_barrier
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureBarrierNV)(); }
#define glTextureBarrierNV DynamicGL_TextureBarrierNV
extern bool DinamicGLFeature_NV_texture_barrier_Supported();
#endif /*USE_DYNAMIC_GL_NV_texture_barrier*/

/*SGIX_igloo_interface*/
#ifdef USE_DYNAMIC_GL_SGIX_igloo_interface
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_IglooInterfaceSGIX)(GLenum pname , const GLvoid *params); }
#define glIglooInterfaceSGIX DynamicGL_IglooInterfaceSGIX
extern bool DinamicGLFeature_SGIX_igloo_interface_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_igloo_interface*/

/*ARB_texture_multisample*/
#ifdef USE_DYNAMIC_GL_ARB_texture_multisample
#define GL_SAMPLE_POSITION 0x8E50
#define GL_SAMPLE_MASK 0x8E51
#define GL_SAMPLE_MASK_VALUE 0x8E52
#define GL_MAX_SAMPLE_MASK_WORDS 0x8E59
#define GL_TEXTURE_2D_MULTISAMPLE 0x9100
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE 0x9101
#define GL_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9102
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9103
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE 0x9104
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY 0x9105
#define GL_TEXTURE_SAMPLES 0x9106
#define GL_TEXTURE_FIXED_SAMPLE_LOCATIONS 0x9107
#define GL_SAMPLER_2D_MULTISAMPLE 0x9108
#define GL_INT_SAMPLER_2D_MULTISAMPLE 0x9109
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE 0x910A
#define GL_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910B
#define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910C
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910D
#define GL_MAX_COLOR_TEXTURE_SAMPLES 0x910E
#define GL_MAX_DEPTH_TEXTURE_SAMPLES 0x910F
#define GL_MAX_INTEGER_SAMPLES 0x9110
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexImage2DMultisample)(GLenum target , GLsizei samples , GLint internalformat , GLsizei width , GLsizei height , GLboolean fixedsamplelocations); }
#define glTexImage2DMultisample DynamicGL_TexImage2DMultisample
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexImage3DMultisample)(GLenum target , GLsizei samples , GLint internalformat , GLsizei width , GLsizei height , GLsizei depth , GLboolean fixedsamplelocations); }
#define glTexImage3DMultisample DynamicGL_TexImage3DMultisample
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMultisamplefv)(GLenum pname , GLuint index , GLfloat *val); }
#define glGetMultisamplefv DynamicGL_GetMultisamplefv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SampleMaski)(GLuint index , GLbitfield mask); }
#define glSampleMaski DynamicGL_SampleMaski
extern bool DinamicGLFeature_ARB_texture_multisample_Supported();
#endif /*USE_DYNAMIC_GL_ARB_texture_multisample*/

/*AMD_blend_minmax_factor*/
#ifdef USE_DYNAMIC_GL_AMD_blend_minmax_factor
#define GL_FACTOR_MIN_AMD 0x901C
#define GL_FACTOR_MAX_AMD 0x901D
extern bool DinamicGLFeature_AMD_blend_minmax_factor_Supported();
#endif /*USE_DYNAMIC_GL_AMD_blend_minmax_factor*/

/*NV_fence*/
#ifdef USE_DYNAMIC_GL_NV_fence
#define GL_ALL_COMPLETED_NV 0x84F2
#define GL_FENCE_STATUS_NV 0x84F3
#define GL_FENCE_CONDITION_NV 0x84F4
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteFencesNV)(GLsizei n , const GLuint *fences); }
#define glDeleteFencesNV DynamicGL_DeleteFencesNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GenFencesNV)(GLsizei n , GLuint *fences); }
#define glGenFencesNV DynamicGL_GenFencesNV
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsFenceNV)(GLuint fence); }
#define glIsFenceNV DynamicGL_IsFenceNV
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_TestFenceNV)(GLuint fence); }
#define glTestFenceNV DynamicGL_TestFenceNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFenceivNV)(GLuint fence , GLenum pname , GLint *params); }
#define glGetFenceivNV DynamicGL_GetFenceivNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FinishFenceNV)(GLuint fence); }
#define glFinishFenceNV DynamicGL_FinishFenceNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SetFenceNV)(GLuint fence , GLenum condition); }
#define glSetFenceNV DynamicGL_SetFenceNV
extern bool DinamicGLFeature_NV_fence_Supported();
#endif /*USE_DYNAMIC_GL_NV_fence*/

/*NV_register_combiners*/
#ifdef USE_DYNAMIC_GL_NV_register_combiners
#define GL_REGISTER_COMBINERS_NV 0x8522
#define GL_VARIABLE_A_NV 0x8523
#define GL_VARIABLE_B_NV 0x8524
#define GL_VARIABLE_C_NV 0x8525
#define GL_VARIABLE_D_NV 0x8526
#define GL_VARIABLE_E_NV 0x8527
#define GL_VARIABLE_F_NV 0x8528
#define GL_VARIABLE_G_NV 0x8529
#define GL_CONSTANT_COLOR0_NV 0x852A
#define GL_CONSTANT_COLOR1_NV 0x852B
#define GL_PRIMARY_COLOR_NV 0x852C
#define GL_SECONDARY_COLOR_NV 0x852D
#define GL_SPARE0_NV 0x852E
#define GL_SPARE1_NV 0x852F
#define GL_DISCARD_NV 0x8530
#define GL_E_TIMES_F_NV 0x8531
#define GL_SPARE0_PLUS_SECONDARY_COLOR_NV 0x8532
#define GL_UNSIGNED_IDENTITY_NV 0x8536
#define GL_UNSIGNED_INVERT_NV 0x8537
#define GL_EXPAND_NORMAL_NV 0x8538
#define GL_EXPAND_NEGATE_NV 0x8539
#define GL_HALF_BIAS_NORMAL_NV 0x853A
#define GL_HALF_BIAS_NEGATE_NV 0x853B
#define GL_SIGNED_IDENTITY_NV 0x853C
#define GL_SIGNED_NEGATE_NV 0x853D
#define GL_SCALE_BY_TWO_NV 0x853E
#define GL_SCALE_BY_FOUR_NV 0x853F
#define GL_SCALE_BY_ONE_HALF_NV 0x8540
#define GL_BIAS_BY_NEGATIVE_ONE_HALF_NV 0x8541
#define GL_COMBINER_INPUT_NV 0x8542
#define GL_COMBINER_MAPPING_NV 0x8543
#define GL_COMBINER_COMPONENT_USAGE_NV 0x8544
#define GL_COMBINER_AB_DOT_PRODUCT_NV 0x8545
#define GL_COMBINER_CD_DOT_PRODUCT_NV 0x8546
#define GL_COMBINER_MUX_SUM_NV 0x8547
#define GL_COMBINER_SCALE_NV 0x8548
#define GL_COMBINER_BIAS_NV 0x8549
#define GL_COMBINER_AB_OUTPUT_NV 0x854A
#define GL_COMBINER_CD_OUTPUT_NV 0x854B
#define GL_COMBINER_SUM_OUTPUT_NV 0x854C
#define GL_MAX_GENERAL_COMBINERS_NV 0x854D
#define GL_NUM_GENERAL_COMBINERS_NV 0x854E
#define GL_COLOR_SUM_CLAMP_NV 0x854F
#define GL_COMBINER0_NV 0x8550
#define GL_COMBINER1_NV 0x8551
#define GL_COMBINER2_NV 0x8552
#define GL_COMBINER3_NV 0x8553
#define GL_COMBINER4_NV 0x8554
#define GL_COMBINER5_NV 0x8555
#define GL_COMBINER6_NV 0x8556
#define GL_COMBINER7_NV 0x8557
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CombinerParameterfvNV)(GLenum pname , const GLfloat *params); }
#define glCombinerParameterfvNV DynamicGL_CombinerParameterfvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CombinerParameterfNV)(GLenum pname , GLfloat param); }
#define glCombinerParameterfNV DynamicGL_CombinerParameterfNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CombinerParameterivNV)(GLenum pname , const GLint *params); }
#define glCombinerParameterivNV DynamicGL_CombinerParameterivNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CombinerParameteriNV)(GLenum pname , GLint param); }
#define glCombinerParameteriNV DynamicGL_CombinerParameteriNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CombinerInputNV)(GLenum stage , GLenum portion , GLenum variable , GLenum input , GLenum mapping , GLenum componentUsage); }
#define glCombinerInputNV DynamicGL_CombinerInputNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CombinerOutputNV)(GLenum stage , GLenum portion , GLenum abOutput , GLenum cdOutput , GLenum sumOutput , GLenum scale , GLenum bias , GLboolean abDotProduct , GLboolean cdDotProduct , GLboolean muxSum); }
#define glCombinerOutputNV DynamicGL_CombinerOutputNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FinalCombinerInputNV)(GLenum variable , GLenum input , GLenum mapping , GLenum componentUsage); }
#define glFinalCombinerInputNV DynamicGL_FinalCombinerInputNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetCombinerInputParameterfvNV)(GLenum stage , GLenum portion , GLenum variable , GLenum pname , GLfloat *params); }
#define glGetCombinerInputParameterfvNV DynamicGL_GetCombinerInputParameterfvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetCombinerInputParameterivNV)(GLenum stage , GLenum portion , GLenum variable , GLenum pname , GLint *params); }
#define glGetCombinerInputParameterivNV DynamicGL_GetCombinerInputParameterivNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetCombinerOutputParameterfvNV)(GLenum stage , GLenum portion , GLenum pname , GLfloat *params); }
#define glGetCombinerOutputParameterfvNV DynamicGL_GetCombinerOutputParameterfvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetCombinerOutputParameterivNV)(GLenum stage , GLenum portion , GLenum pname , GLint *params); }
#define glGetCombinerOutputParameterivNV DynamicGL_GetCombinerOutputParameterivNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFinalCombinerInputParameterfvNV)(GLenum variable , GLenum pname , GLfloat *params); }
#define glGetFinalCombinerInputParameterfvNV DynamicGL_GetFinalCombinerInputParameterfvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFinalCombinerInputParameterivNV)(GLenum variable , GLenum pname , GLint *params); }
#define glGetFinalCombinerInputParameterivNV DynamicGL_GetFinalCombinerInputParameterivNV
extern bool DinamicGLFeature_NV_register_combiners_Supported();
#endif /*USE_DYNAMIC_GL_NV_register_combiners*/

/*VERSION_3_0*/
#ifdef USE_DYNAMIC_GL_VERSION_3_0
#define GL_COMPARE_REF_TO_TEXTURE 0x884E
#define GL_CLIP_DISTANCE0 0x3000
#define GL_CLIP_DISTANCE1 0x3001
#define GL_CLIP_DISTANCE2 0x3002
#define GL_CLIP_DISTANCE3 0x3003
#define GL_CLIP_DISTANCE4 0x3004
#define GL_CLIP_DISTANCE5 0x3005
#define GL_CLIP_DISTANCE6 0x3006
#define GL_CLIP_DISTANCE7 0x3007
#define GL_MAX_CLIP_DISTANCES 0x0D32
#define GL_MAJOR_VERSION 0x821B
#define GL_MINOR_VERSION 0x821C
#define GL_NUM_EXTENSIONS 0x821D
#define GL_CONTEXT_FLAGS 0x821E
#define GL_COMPRESSED_RED 0x8225
#define GL_COMPRESSED_RG 0x8226
#define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT 0x0001
#define GL_RGBA32F 0x8814
#define GL_RGB32F 0x8815
#define GL_RGBA16F 0x881A
#define GL_RGB16F 0x881B
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER 0x88FD
#define GL_MAX_ARRAY_TEXTURE_LAYERS 0x88FF
#define GL_MIN_PROGRAM_TEXEL_OFFSET 0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET 0x8905
#define GL_CLAMP_READ_COLOR 0x891C
#define GL_FIXED_ONLY 0x891D
#define GL_MAX_VARYING_COMPONENTS 0x8B4B
#define GL_TEXTURE_1D_ARRAY 0x8C18
#define GL_PROXY_TEXTURE_1D_ARRAY 0x8C19
#define GL_TEXTURE_2D_ARRAY 0x8C1A
#define GL_PROXY_TEXTURE_2D_ARRAY 0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY 0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY 0x8C1D
#define GL_R11F_G11F_B10F 0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV 0x8C3B
#define GL_RGB9_E5 0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV 0x8C3E
#define GL_TEXTURE_SHARED_SIZE 0x8C3F
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH 0x8C76
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE 0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS 0x8C80
#define GL_TRANSFORM_FEEDBACK_VARYINGS 0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START 0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE 0x8C85
#define GL_PRIMITIVES_GENERATED 0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN 0x8C88
#define GL_RASTERIZER_DISCARD 0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS 0x8C8B
#define GL_INTERLEAVED_ATTRIBS 0x8C8C
#define GL_SEPARATE_ATTRIBS 0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER 0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING 0x8C8F
#define GL_RGBA32UI 0x8D70
#define GL_RGB32UI 0x8D71
#define GL_RGBA16UI 0x8D76
#define GL_RGB16UI 0x8D77
#define GL_RGBA8UI 0x8D7C
#define GL_RGB8UI 0x8D7D
#define GL_RGBA32I 0x8D82
#define GL_RGB32I 0x8D83
#define GL_RGBA16I 0x8D88
#define GL_RGB16I 0x8D89
#define GL_RGBA8I 0x8D8E
#define GL_RGB8I 0x8D8F
#define GL_RED_INTEGER 0x8D94
#define GL_GREEN_INTEGER 0x8D95
#define GL_BLUE_INTEGER 0x8D96
#define GL_RGB_INTEGER 0x8D98
#define GL_RGBA_INTEGER 0x8D99
#define GL_BGR_INTEGER 0x8D9A
#define GL_BGRA_INTEGER 0x8D9B
#define GL_SAMPLER_1D_ARRAY 0x8DC0
#define GL_SAMPLER_2D_ARRAY 0x8DC1
#define GL_SAMPLER_1D_ARRAY_SHADOW 0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW 0x8DC4
#define GL_SAMPLER_CUBE_SHADOW 0x8DC5
#define GL_UNSIGNED_INT_VEC2 0x8DC6
#define GL_UNSIGNED_INT_VEC3 0x8DC7
#define GL_UNSIGNED_INT_VEC4 0x8DC8
#define GL_INT_SAMPLER_1D 0x8DC9
#define GL_INT_SAMPLER_2D 0x8DCA
#define GL_INT_SAMPLER_3D 0x8DCB
#define GL_INT_SAMPLER_CUBE 0x8DCC
#define GL_INT_SAMPLER_1D_ARRAY 0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY 0x8DCF
#define GL_UNSIGNED_INT_SAMPLER_1D 0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D 0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D 0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE 0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY 0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY 0x8DD7
#define GL_QUERY_WAIT 0x8E13
#define GL_QUERY_NO_WAIT 0x8E14
#define GL_QUERY_BY_REGION_WAIT 0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT 0x8E16
#define GL_BUFFER_ACCESS_FLAGS 0x911F
#define GL_BUFFER_MAP_LENGTH 0x9120
#define GL_BUFFER_MAP_OFFSET 0x9121
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorMaski)(GLuint index , GLboolean r , GLboolean g , GLboolean b , GLboolean a); }
#define glColorMaski DynamicGL_ColorMaski
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetBooleani_v)(GLenum target , GLuint index , GLboolean *data); }
#define glGetBooleani_v DynamicGL_GetBooleani_v
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetIntegeri_v)(GLenum target , GLuint index , GLint *data); }
#define glGetIntegeri_v DynamicGL_GetIntegeri_v
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Enablei)(GLenum target , GLuint index); }
#define glEnablei DynamicGL_Enablei
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Disablei)(GLenum target , GLuint index); }
#define glDisablei DynamicGL_Disablei
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsEnabledi)(GLenum target , GLuint index); }
#define glIsEnabledi DynamicGL_IsEnabledi
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BeginTransformFeedback)(GLenum primitiveMode); }
#define glBeginTransformFeedback DynamicGL_BeginTransformFeedback
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EndTransformFeedback)(); }
#define glEndTransformFeedback DynamicGL_EndTransformFeedback
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindBufferRange)(GLenum target , GLuint index , GLuint buffer , GLintptr offset , GLsizeiptr size); }
#define glBindBufferRange DynamicGL_BindBufferRange
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindBufferBase)(GLenum target , GLuint index , GLuint buffer); }
#define glBindBufferBase DynamicGL_BindBufferBase
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TransformFeedbackVaryings)(GLuint program , GLsizei count , const GLchar* const , GLenum bufferMode); }
#define glTransformFeedbackVaryings DynamicGL_TransformFeedbackVaryings
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTransformFeedbackVarying)(GLuint program , GLuint index , GLsizei bufSize , GLsizei *length , GLsizei *size , GLenum *type , GLchar *name); }
#define glGetTransformFeedbackVarying DynamicGL_GetTransformFeedbackVarying
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClampColor)(GLenum target , GLenum clamp); }
#define glClampColor DynamicGL_ClampColor
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BeginConditionalRender)(GLuint id , GLenum mode); }
#define glBeginConditionalRender DynamicGL_BeginConditionalRender
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EndConditionalRender)(); }
#define glEndConditionalRender DynamicGL_EndConditionalRender
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribIPointer)(GLuint index , GLint size , GLenum type , GLsizei stride , const GLvoid *pointer); }
#define glVertexAttribIPointer DynamicGL_VertexAttribIPointer
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribIiv)(GLuint index , GLenum pname , GLint *params); }
#define glGetVertexAttribIiv DynamicGL_GetVertexAttribIiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribIuiv)(GLuint index , GLenum pname , GLuint *params); }
#define glGetVertexAttribIuiv DynamicGL_GetVertexAttribIuiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI1i)(GLuint index , GLint x); }
#define glVertexAttribI1i DynamicGL_VertexAttribI1i
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI2i)(GLuint index , GLint x , GLint y); }
#define glVertexAttribI2i DynamicGL_VertexAttribI2i
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI3i)(GLuint index , GLint x , GLint y , GLint z); }
#define glVertexAttribI3i DynamicGL_VertexAttribI3i
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI4i)(GLuint index , GLint x , GLint y , GLint z , GLint w); }
#define glVertexAttribI4i DynamicGL_VertexAttribI4i
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI1ui)(GLuint index , GLuint x); }
#define glVertexAttribI1ui DynamicGL_VertexAttribI1ui
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI2ui)(GLuint index , GLuint x , GLuint y); }
#define glVertexAttribI2ui DynamicGL_VertexAttribI2ui
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI3ui)(GLuint index , GLuint x , GLuint y , GLuint z); }
#define glVertexAttribI3ui DynamicGL_VertexAttribI3ui
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI4ui)(GLuint index , GLuint x , GLuint y , GLuint z , GLuint w); }
#define glVertexAttribI4ui DynamicGL_VertexAttribI4ui
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI1iv)(GLuint index , const GLint *v); }
#define glVertexAttribI1iv DynamicGL_VertexAttribI1iv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI2iv)(GLuint index , const GLint *v); }
#define glVertexAttribI2iv DynamicGL_VertexAttribI2iv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI3iv)(GLuint index , const GLint *v); }
#define glVertexAttribI3iv DynamicGL_VertexAttribI3iv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI4iv)(GLuint index , const GLint *v); }
#define glVertexAttribI4iv DynamicGL_VertexAttribI4iv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI1uiv)(GLuint index , const GLuint *v); }
#define glVertexAttribI1uiv DynamicGL_VertexAttribI1uiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI2uiv)(GLuint index , const GLuint *v); }
#define glVertexAttribI2uiv DynamicGL_VertexAttribI2uiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI3uiv)(GLuint index , const GLuint *v); }
#define glVertexAttribI3uiv DynamicGL_VertexAttribI3uiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI4uiv)(GLuint index , const GLuint *v); }
#define glVertexAttribI4uiv DynamicGL_VertexAttribI4uiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI4bv)(GLuint index , const GLbyte *v); }
#define glVertexAttribI4bv DynamicGL_VertexAttribI4bv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI4sv)(GLuint index , const GLshort *v); }
#define glVertexAttribI4sv DynamicGL_VertexAttribI4sv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI4ubv)(GLuint index , const GLubyte *v); }
#define glVertexAttribI4ubv DynamicGL_VertexAttribI4ubv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI4usv)(GLuint index , const GLushort *v); }
#define glVertexAttribI4usv DynamicGL_VertexAttribI4usv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetUniformuiv)(GLuint program , GLint location , GLuint *params); }
#define glGetUniformuiv DynamicGL_GetUniformuiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindFragDataLocation)(GLuint program , GLuint color , const GLchar *name); }
#define glBindFragDataLocation DynamicGL_BindFragDataLocation
extern "C" { extern GLint (DYNAMIC_GL_APIENTRYP DynamicGL_GetFragDataLocation)(GLuint program , const GLchar *name); }
#define glGetFragDataLocation DynamicGL_GetFragDataLocation
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform1ui)(GLint location , GLuint v0); }
#define glUniform1ui DynamicGL_Uniform1ui
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform2ui)(GLint location , GLuint v0 , GLuint v1); }
#define glUniform2ui DynamicGL_Uniform2ui
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform3ui)(GLint location , GLuint v0 , GLuint v1 , GLuint v2); }
#define glUniform3ui DynamicGL_Uniform3ui
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform4ui)(GLint location , GLuint v0 , GLuint v1 , GLuint v2 , GLuint v3); }
#define glUniform4ui DynamicGL_Uniform4ui
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform1uiv)(GLint location , GLsizei count , const GLuint *value); }
#define glUniform1uiv DynamicGL_Uniform1uiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform2uiv)(GLint location , GLsizei count , const GLuint *value); }
#define glUniform2uiv DynamicGL_Uniform2uiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform3uiv)(GLint location , GLsizei count , const GLuint *value); }
#define glUniform3uiv DynamicGL_Uniform3uiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform4uiv)(GLint location , GLsizei count , const GLuint *value); }
#define glUniform4uiv DynamicGL_Uniform4uiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexParameterIiv)(GLenum target , GLenum pname , const GLint *params); }
#define glTexParameterIiv DynamicGL_TexParameterIiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexParameterIuiv)(GLenum target , GLenum pname , const GLuint *params); }
#define glTexParameterIuiv DynamicGL_TexParameterIuiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexParameterIiv)(GLenum target , GLenum pname , GLint *params); }
#define glGetTexParameterIiv DynamicGL_GetTexParameterIiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexParameterIuiv)(GLenum target , GLenum pname , GLuint *params); }
#define glGetTexParameterIuiv DynamicGL_GetTexParameterIuiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearBufferiv)(GLenum buffer , GLint drawbuffer , const GLint *value); }
#define glClearBufferiv DynamicGL_ClearBufferiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearBufferuiv)(GLenum buffer , GLint drawbuffer , const GLuint *value); }
#define glClearBufferuiv DynamicGL_ClearBufferuiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearBufferfv)(GLenum buffer , GLint drawbuffer , const GLfloat *value); }
#define glClearBufferfv DynamicGL_ClearBufferfv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearBufferfi)(GLenum buffer , GLint drawbuffer , GLfloat depth , GLint stencil); }
#define glClearBufferfi DynamicGL_ClearBufferfi
extern bool DinamicGLFeature_VERSION_3_0_Supported();
#endif /*USE_DYNAMIC_GL_VERSION_3_0*/

/*NV_point_sprite*/
#ifdef USE_DYNAMIC_GL_NV_point_sprite
#define GL_POINT_SPRITE_NV 0x8861
#define GL_COORD_REPLACE_NV 0x8862
#define GL_POINT_SPRITE_R_MODE_NV 0x8863
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameteriNV)(GLenum pname , GLint param); }
#define glPointParameteriNV DynamicGL_PointParameteriNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameterivNV)(GLenum pname , const GLint *params); }
#define glPointParameterivNV DynamicGL_PointParameterivNV
extern bool DinamicGLFeature_NV_point_sprite_Supported();
#endif /*USE_DYNAMIC_GL_NV_point_sprite*/

/*ARB_uniform_buffer_object*/
#ifdef USE_DYNAMIC_GL_ARB_uniform_buffer_object
#define GL_UNIFORM_BUFFER 0x8A11
#define GL_UNIFORM_BUFFER_BINDING 0x8A28
#define GL_UNIFORM_BUFFER_START 0x8A29
#define GL_UNIFORM_BUFFER_SIZE 0x8A2A
#define GL_MAX_VERTEX_UNIFORM_BLOCKS 0x8A2B
#define GL_MAX_GEOMETRY_UNIFORM_BLOCKS 0x8A2C
#define GL_MAX_FRAGMENT_UNIFORM_BLOCKS 0x8A2D
#define GL_MAX_COMBINED_UNIFORM_BLOCKS 0x8A2E
#define GL_MAX_UNIFORM_BUFFER_BINDINGS 0x8A2F
#define GL_MAX_UNIFORM_BLOCK_SIZE 0x8A30
#define GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS 0x8A31
#define GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS 0x8A32
#define GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS 0x8A33
#define GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT 0x8A34
#define GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH 0x8A35
#define GL_ACTIVE_UNIFORM_BLOCKS 0x8A36
#define GL_UNIFORM_TYPE 0x8A37
#define GL_UNIFORM_SIZE 0x8A38
#define GL_UNIFORM_NAME_LENGTH 0x8A39
#define GL_UNIFORM_BLOCK_INDEX 0x8A3A
#define GL_UNIFORM_OFFSET 0x8A3B
#define GL_UNIFORM_ARRAY_STRIDE 0x8A3C
#define GL_UNIFORM_MATRIX_STRIDE 0x8A3D
#define GL_UNIFORM_IS_ROW_MAJOR 0x8A3E
#define GL_UNIFORM_BLOCK_BINDING 0x8A3F
#define GL_UNIFORM_BLOCK_DATA_SIZE 0x8A40
#define GL_UNIFORM_BLOCK_NAME_LENGTH 0x8A41
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS 0x8A42
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES 0x8A43
#define GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER 0x8A44
#define GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER 0x8A45
#define GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER 0x8A46
#define GL_INVALID_INDEX 0xFFFFFFFF
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetUniformIndices)(GLuint program , GLsizei uniformCount , const GLchar* const , GLuint *uniformIndices); }
#define glGetUniformIndices DynamicGL_GetUniformIndices
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetActiveUniformsiv)(GLuint program , GLsizei uniformCount , const GLuint *uniformIndices , GLenum pname , GLint *params); }
#define glGetActiveUniformsiv DynamicGL_GetActiveUniformsiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetActiveUniformName)(GLuint program , GLuint uniformIndex , GLsizei bufSize , GLsizei *length , GLchar *uniformName); }
#define glGetActiveUniformName DynamicGL_GetActiveUniformName
extern "C" { extern GLuint (DYNAMIC_GL_APIENTRYP DynamicGL_GetUniformBlockIndex)(GLuint program , const GLchar *uniformBlockName); }
#define glGetUniformBlockIndex DynamicGL_GetUniformBlockIndex
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetActiveUniformBlockiv)(GLuint program , GLuint uniformBlockIndex , GLenum pname , GLint *params); }
#define glGetActiveUniformBlockiv DynamicGL_GetActiveUniformBlockiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetActiveUniformBlockName)(GLuint program , GLuint uniformBlockIndex , GLsizei bufSize , GLsizei *length , GLchar *uniformBlockName); }
#define glGetActiveUniformBlockName DynamicGL_GetActiveUniformBlockName
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformBlockBinding)(GLuint program , GLuint uniformBlockIndex , GLuint uniformBlockBinding); }
#define glUniformBlockBinding DynamicGL_UniformBlockBinding
extern bool DinamicGLFeature_ARB_uniform_buffer_object_Supported();
#endif /*USE_DYNAMIC_GL_ARB_uniform_buffer_object*/

/*EXT_texture_compression_latc*/
#ifdef USE_DYNAMIC_GL_EXT_texture_compression_latc
#define GL_COMPRESSED_LUMINANCE_LATC1_EXT 0x8C70
#define GL_COMPRESSED_SIGNED_LUMINANCE_LATC1_EXT 0x8C71
#define GL_COMPRESSED_LUMINANCE_ALPHA_LATC2_EXT 0x8C72
#define GL_COMPRESSED_SIGNED_LUMINANCE_ALPHA_LATC2_EXT 0x8C73
extern bool DinamicGLFeature_EXT_texture_compression_latc_Supported();
#endif /*USE_DYNAMIC_GL_EXT_texture_compression_latc*/

/*ARB_instanced_arrays*/
#ifdef USE_DYNAMIC_GL_ARB_instanced_arrays
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR_ARB 0x88FE
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribDivisorARB)(GLuint index , GLuint divisor); }
#define glVertexAttribDivisorARB DynamicGL_VertexAttribDivisorARB
extern bool DinamicGLFeature_ARB_instanced_arrays_Supported();
#endif /*USE_DYNAMIC_GL_ARB_instanced_arrays*/

/*EXT_transform_feedback*/
#ifdef USE_DYNAMIC_GL_EXT_transform_feedback
#define GL_TRANSFORM_FEEDBACK_BUFFER_EXT 0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_START_EXT 0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_EXT 0x8C85
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_EXT 0x8C8F
#define GL_INTERLEAVED_ATTRIBS_EXT 0x8C8C
#define GL_SEPARATE_ATTRIBS_EXT 0x8C8D
#define GL_PRIMITIVES_GENERATED_EXT 0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_EXT 0x8C88
#define GL_RASTERIZER_DISCARD_EXT 0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_EXT 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_EXT 0x8C8B
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_EXT 0x8C80
#define GL_TRANSFORM_FEEDBACK_VARYINGS_EXT 0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE_EXT 0x8C7F
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH_EXT 0x8C76
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BeginTransformFeedbackEXT)(GLenum primitiveMode); }
#define glBeginTransformFeedbackEXT DynamicGL_BeginTransformFeedbackEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EndTransformFeedbackEXT)(); }
#define glEndTransformFeedbackEXT DynamicGL_EndTransformFeedbackEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindBufferRangeEXT)(GLenum target , GLuint index , GLuint buffer , GLintptr offset , GLsizeiptr size); }
#define glBindBufferRangeEXT DynamicGL_BindBufferRangeEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindBufferOffsetEXT)(GLenum target , GLuint index , GLuint buffer , GLintptr offset); }
#define glBindBufferOffsetEXT DynamicGL_BindBufferOffsetEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindBufferBaseEXT)(GLenum target , GLuint index , GLuint buffer); }
#define glBindBufferBaseEXT DynamicGL_BindBufferBaseEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TransformFeedbackVaryingsEXT)(GLuint program , GLsizei count , const GLchar* *varyings , GLenum bufferMode); }
#define glTransformFeedbackVaryingsEXT DynamicGL_TransformFeedbackVaryingsEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTransformFeedbackVaryingEXT)(GLuint program , GLuint index , GLsizei bufSize , GLsizei *length , GLsizei *size , GLenum *type , GLchar *name); }
#define glGetTransformFeedbackVaryingEXT DynamicGL_GetTransformFeedbackVaryingEXT
extern bool DinamicGLFeature_EXT_transform_feedback_Supported();
#endif /*USE_DYNAMIC_GL_EXT_transform_feedback*/

/*INGR_color_clamp*/
#ifdef USE_DYNAMIC_GL_INGR_color_clamp
#define GL_RED_MIN_CLAMP_INGR 0x8560
#define GL_GREEN_MIN_CLAMP_INGR 0x8561
#define GL_BLUE_MIN_CLAMP_INGR 0x8562
#define GL_ALPHA_MIN_CLAMP_INGR 0x8563
#define GL_RED_MAX_CLAMP_INGR 0x8564
#define GL_GREEN_MAX_CLAMP_INGR 0x8565
#define GL_BLUE_MAX_CLAMP_INGR 0x8566
#define GL_ALPHA_MAX_CLAMP_INGR 0x8567
extern bool DinamicGLFeature_INGR_color_clamp_Supported();
#endif /*USE_DYNAMIC_GL_INGR_color_clamp*/

/*ARB_depth_buffer_float*/
#ifdef USE_DYNAMIC_GL_ARB_depth_buffer_float
#define GL_DEPTH_COMPONENT32F 0x8CAC
#define GL_DEPTH32F_STENCIL8 0x8CAD
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV 0x8DAD
extern bool DinamicGLFeature_ARB_depth_buffer_float_Supported();
#endif /*USE_DYNAMIC_GL_ARB_depth_buffer_float*/

/*NV_texture_shader3*/
#ifdef USE_DYNAMIC_GL_NV_texture_shader3
#define GL_OFFSET_PROJECTIVE_TEXTURE_2D_NV 0x8850
#define GL_OFFSET_PROJECTIVE_TEXTURE_2D_SCALE_NV 0x8851
#define GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_NV 0x8852
#define GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_SCALE_NV 0x8853
#define GL_OFFSET_HILO_TEXTURE_2D_NV 0x8854
#define GL_OFFSET_HILO_TEXTURE_RECTANGLE_NV 0x8855
#define GL_OFFSET_HILO_PROJECTIVE_TEXTURE_2D_NV 0x8856
#define GL_OFFSET_HILO_PROJECTIVE_TEXTURE_RECTANGLE_NV 0x8857
#define GL_DEPENDENT_HILO_TEXTURE_2D_NV 0x8858
#define GL_DEPENDENT_RGB_TEXTURE_3D_NV 0x8859
#define GL_DEPENDENT_RGB_TEXTURE_CUBE_MAP_NV 0x885A
#define GL_DOT_PRODUCT_PASS_THROUGH_NV 0x885B
#define GL_DOT_PRODUCT_TEXTURE_1D_NV 0x885C
#define GL_DOT_PRODUCT_AFFINE_DEPTH_REPLACE_NV 0x885D
#define GL_HILO8_NV 0x885E
#define GL_SIGNED_HILO8_NV 0x885F
#define GL_FORCE_BLUE_TO_ONE_NV 0x8860
extern bool DinamicGLFeature_NV_texture_shader3_Supported();
#endif /*USE_DYNAMIC_GL_NV_texture_shader3*/

/*ARB_imaging_DEPRECATED*/
#ifdef USE_DYNAMIC_GL_ARB_imaging_DEPRECATED
#define GL_CONVOLUTION_1D 0x8010
#define GL_CONVOLUTION_2D 0x8011
#define GL_SEPARABLE_2D 0x8012
#define GL_CONVOLUTION_BORDER_MODE 0x8013
#define GL_CONVOLUTION_FILTER_SCALE 0x8014
#define GL_CONVOLUTION_FILTER_BIAS 0x8015
#define GL_REDUCE 0x8016
#define GL_CONVOLUTION_FORMAT 0x8017
#define GL_CONVOLUTION_WIDTH 0x8018
#define GL_CONVOLUTION_HEIGHT 0x8019
#define GL_MAX_CONVOLUTION_WIDTH 0x801A
#define GL_MAX_CONVOLUTION_HEIGHT 0x801B
#define GL_POST_CONVOLUTION_RED_SCALE 0x801C
#define GL_POST_CONVOLUTION_GREEN_SCALE 0x801D
#define GL_POST_CONVOLUTION_BLUE_SCALE 0x801E
#define GL_POST_CONVOLUTION_ALPHA_SCALE 0x801F
#define GL_POST_CONVOLUTION_RED_BIAS 0x8020
#define GL_POST_CONVOLUTION_GREEN_BIAS 0x8021
#define GL_POST_CONVOLUTION_BLUE_BIAS 0x8022
#define GL_POST_CONVOLUTION_ALPHA_BIAS 0x8023
#define GL_HISTOGRAM 0x8024
#define GL_PROXY_HISTOGRAM 0x8025
#define GL_HISTOGRAM_WIDTH 0x8026
#define GL_HISTOGRAM_FORMAT 0x8027
#define GL_HISTOGRAM_RED_SIZE 0x8028
#define GL_HISTOGRAM_GREEN_SIZE 0x8029
#define GL_HISTOGRAM_BLUE_SIZE 0x802A
#define GL_HISTOGRAM_ALPHA_SIZE 0x802B
#define GL_HISTOGRAM_LUMINANCE_SIZE 0x802C
#define GL_HISTOGRAM_SINK 0x802D
#define GL_MINMAX 0x802E
#define GL_MINMAX_FORMAT 0x802F
#define GL_MINMAX_SINK 0x8030
#define GL_TABLE_TOO_LARGE 0x8031
#define GL_COLOR_MATRIX 0x80B1
#define GL_COLOR_MATRIX_STACK_DEPTH 0x80B2
#define GL_MAX_COLOR_MATRIX_STACK_DEPTH 0x80B3
#define GL_POST_COLOR_MATRIX_RED_SCALE 0x80B4
#define GL_POST_COLOR_MATRIX_GREEN_SCALE 0x80B5
#define GL_POST_COLOR_MATRIX_BLUE_SCALE 0x80B6
#define GL_POST_COLOR_MATRIX_ALPHA_SCALE 0x80B7
#define GL_POST_COLOR_MATRIX_RED_BIAS 0x80B8
#define GL_POST_COLOR_MATRIX_GREEN_BIAS 0x80B9
#define GL_POST_COLOR_MATRIX_BLUE_BIAS 0x80BA
#define GL_POST_COLOR_MATRIX_ALPHA_BIAS 0x80BB
#define GL_COLOR_TABLE 0x80D0
#define GL_POST_CONVOLUTION_COLOR_TABLE 0x80D1
#define GL_POST_COLOR_MATRIX_COLOR_TABLE 0x80D2
#define GL_PROXY_COLOR_TABLE 0x80D3
#define GL_PROXY_POST_CONVOLUTION_COLOR_TABLE 0x80D4
#define GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE 0x80D5
#define GL_COLOR_TABLE_SCALE 0x80D6
#define GL_COLOR_TABLE_BIAS 0x80D7
#define GL_COLOR_TABLE_FORMAT 0x80D8
#define GL_COLOR_TABLE_WIDTH 0x80D9
#define GL_COLOR_TABLE_RED_SIZE 0x80DA
#define GL_COLOR_TABLE_GREEN_SIZE 0x80DB
#define GL_COLOR_TABLE_BLUE_SIZE 0x80DC
#define GL_COLOR_TABLE_ALPHA_SIZE 0x80DD
#define GL_COLOR_TABLE_LUMINANCE_SIZE 0x80DE
#define GL_COLOR_TABLE_INTENSITY_SIZE 0x80DF
#define GL_CONSTANT_BORDER 0x8151
#define GL_REPLICATE_BORDER 0x8153
#define GL_CONVOLUTION_BORDER_COLOR 0x8154
extern bool DinamicGLFeature_ARB_imaging_DEPRECATED_Supported();
#endif /*USE_DYNAMIC_GL_ARB_imaging_DEPRECATED*/

/*ARB_texture_compression_rgtc*/
#ifdef USE_DYNAMIC_GL_ARB_texture_compression_rgtc
#define GL_COMPRESSED_RED_RGTC1 0x8DBB
#define GL_COMPRESSED_SIGNED_RED_RGTC1 0x8DBC
#define GL_COMPRESSED_RG_RGTC2 0x8DBD
#define GL_COMPRESSED_SIGNED_RG_RGTC2 0x8DBE
extern bool DinamicGLFeature_ARB_texture_compression_rgtc_Supported();
#endif /*USE_DYNAMIC_GL_ARB_texture_compression_rgtc*/

/*EXT_framebuffer_blit*/
#ifdef USE_DYNAMIC_GL_EXT_framebuffer_blit
#define GL_READ_FRAMEBUFFER_EXT 0x8CA8
#define GL_DRAW_FRAMEBUFFER_EXT 0x8CA9
#define GL_READ_FRAMEBUFFER_BINDING_EXT 0x8CAA
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BlitFramebufferEXT)(GLint srcX0 , GLint srcY0 , GLint srcX1 , GLint srcY1 , GLint dstX0 , GLint dstY0 , GLint dstX1 , GLint dstY1 , GLbitfield mask , GLenum filter); }
#define glBlitFramebufferEXT DynamicGL_BlitFramebufferEXT
extern bool DinamicGLFeature_EXT_framebuffer_blit_Supported();
#endif /*USE_DYNAMIC_GL_EXT_framebuffer_blit*/

/*OML_resample*/
#ifdef USE_DYNAMIC_GL_OML_resample
#define GL_PACK_RESAMPLE_OML 0x8984
#define GL_UNPACK_RESAMPLE_OML 0x8985
#define GL_RESAMPLE_REPLICATE_OML 0x8986
#define GL_RESAMPLE_ZERO_FILL_OML 0x8987
#define GL_RESAMPLE_AVERAGE_OML 0x8988
#define GL_RESAMPLE_DECIMATE_OML 0x8989
extern bool DinamicGLFeature_OML_resample_Supported();
#endif /*USE_DYNAMIC_GL_OML_resample*/

/*EXT_cmyka*/
#ifdef USE_DYNAMIC_GL_EXT_cmyka
#define GL_CMYK_EXT 0x800C
#define GL_CMYKA_EXT 0x800D
#define GL_PACK_CMYK_HINT_EXT 0x800E
#define GL_UNPACK_CMYK_HINT_EXT 0x800F
extern bool DinamicGLFeature_EXT_cmyka_Supported();
#endif /*USE_DYNAMIC_GL_EXT_cmyka*/

/*SUN_convolution_border_modes*/
#ifdef USE_DYNAMIC_GL_SUN_convolution_border_modes
#define GL_WRAP_BORDER_SUN 0x81D4
extern bool DinamicGLFeature_SUN_convolution_border_modes_Supported();
#endif /*USE_DYNAMIC_GL_SUN_convolution_border_modes*/

/*EXT_draw_instanced*/
#ifdef USE_DYNAMIC_GL_EXT_draw_instanced
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawArraysInstancedEXT)(GLenum mode , GLint start , GLsizei count , GLsizei primcount); }
#define glDrawArraysInstancedEXT DynamicGL_DrawArraysInstancedEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawElementsInstancedEXT)(GLenum mode , GLsizei count , GLenum type , const GLvoid *indices , GLsizei primcount); }
#define glDrawElementsInstancedEXT DynamicGL_DrawElementsInstancedEXT
extern bool DinamicGLFeature_EXT_draw_instanced_Supported();
#endif /*USE_DYNAMIC_GL_EXT_draw_instanced*/

/*SGIS_detail_texture*/
#ifdef USE_DYNAMIC_GL_SGIS_detail_texture
#define GL_DETAIL_TEXTURE_2D_SGIS 0x8095
#define GL_DETAIL_TEXTURE_2D_BINDING_SGIS 0x8096
#define GL_LINEAR_DETAIL_SGIS 0x8097
#define GL_LINEAR_DETAIL_ALPHA_SGIS 0x8098
#define GL_LINEAR_DETAIL_COLOR_SGIS 0x8099
#define GL_DETAIL_TEXTURE_LEVEL_SGIS 0x809A
#define GL_DETAIL_TEXTURE_MODE_SGIS 0x809B
#define GL_DETAIL_TEXTURE_FUNC_POINTS_SGIS 0x809C
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DetailTexFuncSGIS)(GLenum target , GLsizei n , const GLfloat *points); }
#define glDetailTexFuncSGIS DynamicGL_DetailTexFuncSGIS
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetDetailTexFuncSGIS)(GLenum target , GLfloat *points); }
#define glGetDetailTexFuncSGIS DynamicGL_GetDetailTexFuncSGIS
extern bool DinamicGLFeature_SGIS_detail_texture_Supported();
#endif /*USE_DYNAMIC_GL_SGIS_detail_texture*/

/*AMD_pinned_memory*/
#ifdef USE_DYNAMIC_GL_AMD_pinned_memory
#define GL_EXTERNAL_VIRTUAL_MEMORY_BUFFER_AMD 0x9160
extern bool DinamicGLFeature_AMD_pinned_memory_Supported();
#endif /*USE_DYNAMIC_GL_AMD_pinned_memory*/

/*MESA_resize_buffers*/
#ifdef USE_DYNAMIC_GL_MESA_resize_buffers
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ResizeBuffersMESA)(); }
#define glResizeBuffersMESA DynamicGL_ResizeBuffersMESA
extern bool DinamicGLFeature_MESA_resize_buffers_Supported();
#endif /*USE_DYNAMIC_GL_MESA_resize_buffers*/

/*SUN_global_alpha*/
#ifdef USE_DYNAMIC_GL_SUN_global_alpha
#define GL_GLOBAL_ALPHA_SUN 0x81D9
#define GL_GLOBAL_ALPHA_FACTOR_SUN 0x81DA
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GlobalAlphaFactorbSUN)(GLbyte factor); }
#define glGlobalAlphaFactorbSUN DynamicGL_GlobalAlphaFactorbSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GlobalAlphaFactorsSUN)(GLshort factor); }
#define glGlobalAlphaFactorsSUN DynamicGL_GlobalAlphaFactorsSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GlobalAlphaFactoriSUN)(GLint factor); }
#define glGlobalAlphaFactoriSUN DynamicGL_GlobalAlphaFactoriSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GlobalAlphaFactorfSUN)(GLfloat factor); }
#define glGlobalAlphaFactorfSUN DynamicGL_GlobalAlphaFactorfSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GlobalAlphaFactordSUN)(GLdouble factor); }
#define glGlobalAlphaFactordSUN DynamicGL_GlobalAlphaFactordSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GlobalAlphaFactorubSUN)(GLubyte factor); }
#define glGlobalAlphaFactorubSUN DynamicGL_GlobalAlphaFactorubSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GlobalAlphaFactorusSUN)(GLushort factor); }
#define glGlobalAlphaFactorusSUN DynamicGL_GlobalAlphaFactorusSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GlobalAlphaFactoruiSUN)(GLuint factor); }
#define glGlobalAlphaFactoruiSUN DynamicGL_GlobalAlphaFactoruiSUN
extern bool DinamicGLFeature_SUN_global_alpha_Supported();
#endif /*USE_DYNAMIC_GL_SUN_global_alpha*/

/*ARB_depth_texture*/
#ifdef USE_DYNAMIC_GL_ARB_depth_texture
#define GL_DEPTH_COMPONENT16_ARB 0x81A5
#define GL_DEPTH_COMPONENT24_ARB 0x81A6
#define GL_DEPTH_COMPONENT32_ARB 0x81A7
#define GL_TEXTURE_DEPTH_SIZE_ARB 0x884A
#define GL_DEPTH_TEXTURE_MODE_ARB 0x884B
extern bool DinamicGLFeature_ARB_depth_texture_Supported();
#endif /*USE_DYNAMIC_GL_ARB_depth_texture*/

/*AMD_debug_output*/
#ifdef USE_DYNAMIC_GL_AMD_debug_output
#define GL_MAX_DEBUG_LOGGED_MESSAGES_AMD 0x9144
#define GL_DEBUG_LOGGED_MESSAGES_AMD 0x9145
#define GL_DEBUG_SEVERITY_HIGH_AMD 0x9146
#define GL_DEBUG_SEVERITY_MEDIUM_AMD 0x9147
#define GL_DEBUG_SEVERITY_LOW_AMD 0x9148
#define GL_DEBUG_CATEGORY_API_ERROR_AMD 0x9149
#define GL_DEBUG_CATEGORY_WINDOW_SYSTEM_AMD 0x914A
#define GL_DEBUG_CATEGORY_DEPRECATION_AMD 0x914B
#define GL_DEBUG_CATEGORY_UNDEFINED_BEHAVIOR_AMD 0x914C
#define GL_DEBUG_CATEGORY_PERFORMANCE_AMD 0x914D
#define GL_DEBUG_CATEGORY_SHADER_COMPILER_AMD 0x914E
#define GL_DEBUG_CATEGORY_APPLICATION_AMD 0x914F
#define GL_DEBUG_CATEGORY_OTHER_AMD 0x9150
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DebugMessageEnableAMD)(GLenum category , GLenum severity , GLsizei count , const GLuint *ids , GLboolean enabled); }
#define glDebugMessageEnableAMD DynamicGL_DebugMessageEnableAMD
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DebugMessageInsertAMD)(GLenum category , GLenum severity , GLuint id , GLsizei length , const GLchar *buf); }
#define glDebugMessageInsertAMD DynamicGL_DebugMessageInsertAMD
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DebugMessageCallbackAMD)(GLDEBUGPROCAMD callback , GLvoid *userParam); }
#define glDebugMessageCallbackAMD DynamicGL_DebugMessageCallbackAMD
extern "C" { extern GLuint (DYNAMIC_GL_APIENTRYP DynamicGL_GetDebugMessageLogAMD)(GLuint count , GLsizei bufsize , GLenum *categories , GLuint *severities , GLuint *ids , GLsizei *lengths , GLchar *message); }
#define glGetDebugMessageLogAMD DynamicGL_GetDebugMessageLogAMD
extern bool DinamicGLFeature_AMD_debug_output_Supported();
#endif /*USE_DYNAMIC_GL_AMD_debug_output*/

/*HP_convolution_border_modes*/
#ifdef USE_DYNAMIC_GL_HP_convolution_border_modes
#define GL_IGNORE_BORDER_HP 0x8150
#define GL_CONSTANT_BORDER_HP 0x8151
#define GL_REPLICATE_BORDER_HP 0x8153
#define GL_CONVOLUTION_BORDER_COLOR_HP 0x8154
extern bool DinamicGLFeature_HP_convolution_border_modes_Supported();
#endif /*USE_DYNAMIC_GL_HP_convolution_border_modes*/

/*APPLE_vertex_program_evaluators*/
#ifdef USE_DYNAMIC_GL_APPLE_vertex_program_evaluators
#define GL_VERTEX_ATTRIB_MAP1_APPLE 0x8A00
#define GL_VERTEX_ATTRIB_MAP2_APPLE 0x8A01
#define GL_VERTEX_ATTRIB_MAP1_SIZE_APPLE 0x8A02
#define GL_VERTEX_ATTRIB_MAP1_COEFF_APPLE 0x8A03
#define GL_VERTEX_ATTRIB_MAP1_ORDER_APPLE 0x8A04
#define GL_VERTEX_ATTRIB_MAP1_DOMAIN_APPLE 0x8A05
#define GL_VERTEX_ATTRIB_MAP2_SIZE_APPLE 0x8A06
#define GL_VERTEX_ATTRIB_MAP2_COEFF_APPLE 0x8A07
#define GL_VERTEX_ATTRIB_MAP2_ORDER_APPLE 0x8A08
#define GL_VERTEX_ATTRIB_MAP2_DOMAIN_APPLE 0x8A09
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EnableVertexAttribAPPLE)(GLuint index , GLenum pname); }
#define glEnableVertexAttribAPPLE DynamicGL_EnableVertexAttribAPPLE
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DisableVertexAttribAPPLE)(GLuint index , GLenum pname); }
#define glDisableVertexAttribAPPLE DynamicGL_DisableVertexAttribAPPLE
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsVertexAttribEnabledAPPLE)(GLuint index , GLenum pname); }
#define glIsVertexAttribEnabledAPPLE DynamicGL_IsVertexAttribEnabledAPPLE
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MapVertexAttrib1dAPPLE)(GLuint index , GLuint size , GLdouble u1 , GLdouble u2 , GLint stride , GLint order , const GLdouble *points); }
#define glMapVertexAttrib1dAPPLE DynamicGL_MapVertexAttrib1dAPPLE
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MapVertexAttrib1fAPPLE)(GLuint index , GLuint size , GLfloat u1 , GLfloat u2 , GLint stride , GLint order , const GLfloat *points); }
#define glMapVertexAttrib1fAPPLE DynamicGL_MapVertexAttrib1fAPPLE
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MapVertexAttrib2dAPPLE)(GLuint index , GLuint size , GLdouble u1 , GLdouble u2 , GLint ustride , GLint uorder , GLdouble v1 , GLdouble v2 , GLint vstride , GLint vorder , const GLdouble *points); }
#define glMapVertexAttrib2dAPPLE DynamicGL_MapVertexAttrib2dAPPLE
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MapVertexAttrib2fAPPLE)(GLuint index , GLuint size , GLfloat u1 , GLfloat u2 , GLint ustride , GLint uorder , GLfloat v1 , GLfloat v2 , GLint vstride , GLint vorder , const GLfloat *points); }
#define glMapVertexAttrib2fAPPLE DynamicGL_MapVertexAttrib2fAPPLE
extern bool DinamicGLFeature_APPLE_vertex_program_evaluators_Supported();
#endif /*USE_DYNAMIC_GL_APPLE_vertex_program_evaluators*/

/*NV_fragment_program*/
#ifdef USE_DYNAMIC_GL_NV_fragment_program
#define GL_MAX_FRAGMENT_PROGRAM_LOCAL_PARAMETERS_NV 0x8868
#define GL_FRAGMENT_PROGRAM_NV 0x8870
#define GL_MAX_TEXTURE_COORDS_NV 0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS_NV 0x8872
#define GL_FRAGMENT_PROGRAM_BINDING_NV 0x8873
#define GL_PROGRAM_ERROR_STRING_NV 0x8874
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramNamedParameter4fNV)(GLuint id , GLsizei len , const GLubyte *name , GLfloat x , GLfloat y , GLfloat z , GLfloat w); }
#define glProgramNamedParameter4fNV DynamicGL_ProgramNamedParameter4fNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramNamedParameter4dNV)(GLuint id , GLsizei len , const GLubyte *name , GLdouble x , GLdouble y , GLdouble z , GLdouble w); }
#define glProgramNamedParameter4dNV DynamicGL_ProgramNamedParameter4dNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramNamedParameter4fvNV)(GLuint id , GLsizei len , const GLubyte *name , const GLfloat *v); }
#define glProgramNamedParameter4fvNV DynamicGL_ProgramNamedParameter4fvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramNamedParameter4dvNV)(GLuint id , GLsizei len , const GLubyte *name , const GLdouble *v); }
#define glProgramNamedParameter4dvNV DynamicGL_ProgramNamedParameter4dvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramNamedParameterfvNV)(GLuint id , GLsizei len , const GLubyte *name , GLfloat *params); }
#define glGetProgramNamedParameterfvNV DynamicGL_GetProgramNamedParameterfvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramNamedParameterdvNV)(GLuint id , GLsizei len , const GLubyte *name , GLdouble *params); }
#define glGetProgramNamedParameterdvNV DynamicGL_GetProgramNamedParameterdvNV
extern bool DinamicGLFeature_NV_fragment_program_Supported();
#endif /*USE_DYNAMIC_GL_NV_fragment_program*/

/*VERSION_1_5_DEPRECATED*/
#ifdef USE_DYNAMIC_GL_VERSION_1_5_DEPRECATED
#define GL_VERTEX_ARRAY_BUFFER_BINDING 0x8896
#define GL_NORMAL_ARRAY_BUFFER_BINDING 0x8897
#define GL_COLOR_ARRAY_BUFFER_BINDING 0x8898
#define GL_INDEX_ARRAY_BUFFER_BINDING 0x8899
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING 0x889A
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING 0x889B
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING 0x889C
#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING 0x889D
#define GL_WEIGHT_ARRAY_BUFFER_BINDING 0x889E
#define GL_FOG_COORD_SRC 0x8450
#define GL_FOG_COORD 0x8451
#define GL_CURRENT_FOG_COORD 0x8453
#define GL_FOG_COORD_ARRAY_TYPE 0x8454
#define GL_FOG_COORD_ARRAY_STRIDE 0x8455
#define GL_FOG_COORD_ARRAY_POINTER 0x8456
#define GL_FOG_COORD_ARRAY 0x8457
#define GL_FOG_COORD_ARRAY_BUFFER_BINDING 0x889D
#define GL_SRC0_RGB 0x8580
#define GL_SRC1_RGB 0x8581
#define GL_SRC2_RGB 0x8582
#define GL_SRC0_ALPHA 0x8588
#define GL_SRC1_ALPHA 0x8589
#define GL_SRC2_ALPHA 0x858A
extern bool DinamicGLFeature_VERSION_1_5_DEPRECATED_Supported();
#endif /*USE_DYNAMIC_GL_VERSION_1_5_DEPRECATED*/

/*NV_copy_image*/
#ifdef USE_DYNAMIC_GL_NV_copy_image
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyImageSubDataNV)(GLuint srcName , GLenum srcTarget , GLint srcLevel , GLint srcX , GLint srcY , GLint srcZ , GLuint dstName , GLenum dstTarget , GLint dstLevel , GLint dstX , GLint dstY , GLint dstZ , GLsizei width , GLsizei height , GLsizei depth); }
#define glCopyImageSubDataNV DynamicGL_CopyImageSubDataNV
extern bool DinamicGLFeature_NV_copy_image_Supported();
#endif /*USE_DYNAMIC_GL_NV_copy_image*/

/*NV_shader_buffer_store*/
#ifdef USE_DYNAMIC_GL_NV_shader_buffer_store
#define GL_SHADER_GLOBAL_ACCESS_BARRIER_BIT_NV 0x00000010
extern bool DinamicGLFeature_NV_shader_buffer_store_Supported();
#endif /*USE_DYNAMIC_GL_NV_shader_buffer_store*/

/*NV_texture_env_combine4*/
#ifdef USE_DYNAMIC_GL_NV_texture_env_combine4
#define GL_COMBINE4_NV 0x8503
#define GL_SOURCE3_RGB_NV 0x8583
#define GL_SOURCE3_ALPHA_NV 0x858B
#define GL_OPERAND3_RGB_NV 0x8593
#define GL_OPERAND3_ALPHA_NV 0x859B
extern bool DinamicGLFeature_NV_texture_env_combine4_Supported();
#endif /*USE_DYNAMIC_GL_NV_texture_env_combine4*/

/*ARB_texture_buffer_object*/
#ifdef USE_DYNAMIC_GL_ARB_texture_buffer_object
#define GL_TEXTURE_BUFFER_ARB 0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE_ARB 0x8C2B
#define GL_TEXTURE_BINDING_BUFFER_ARB 0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING_ARB 0x8C2D
#define GL_TEXTURE_BUFFER_FORMAT_ARB 0x8C2E
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexBufferARB)(GLenum target , GLenum internalformat , GLuint buffer); }
#define glTexBufferARB DynamicGL_TexBufferARB
extern bool DinamicGLFeature_ARB_texture_buffer_object_Supported();
#endif /*USE_DYNAMIC_GL_ARB_texture_buffer_object*/

/*SGIX_flush_raster*/
#ifdef USE_DYNAMIC_GL_SGIX_flush_raster
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FlushRasterSGIX)(); }
#define glFlushRasterSGIX DynamicGL_FlushRasterSGIX
extern bool DinamicGLFeature_SGIX_flush_raster_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_flush_raster*/

/*SGIS_fog_function*/
#ifdef USE_DYNAMIC_GL_SGIS_fog_function
#define GL_FOG_FUNC_SGIS 0x812A
#define GL_FOG_FUNC_POINTS_SGIS 0x812B
#define GL_MAX_FOG_FUNC_POINTS_SGIS 0x812C
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FogFuncSGIS)(GLsizei n , const GLfloat *points); }
#define glFogFuncSGIS DynamicGL_FogFuncSGIS
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFogFuncSGIS)(GLfloat *points); }
#define glGetFogFuncSGIS DynamicGL_GetFogFuncSGIS
extern bool DinamicGLFeature_SGIS_fog_function_Supported();
#endif /*USE_DYNAMIC_GL_SGIS_fog_function*/

/*VERSION_2_0*/
#ifdef USE_DYNAMIC_GL_VERSION_2_0
typedef char GLchar;
#define GL_BLEND_EQUATION_RGB 0x8009
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED 0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE 0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE 0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE 0x8625
#define GL_CURRENT_VERTEX_ATTRIB 0x8626
#define GL_VERTEX_PROGRAM_POINT_SIZE 0x8642
#define GL_VERTEX_ATTRIB_ARRAY_POINTER 0x8645
#define GL_STENCIL_BACK_FUNC 0x8800
#define GL_STENCIL_BACK_FAIL 0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL 0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS 0x8803
#define GL_MAX_DRAW_BUFFERS 0x8824
#define GL_DRAW_BUFFER0 0x8825
#define GL_DRAW_BUFFER1 0x8826
#define GL_DRAW_BUFFER2 0x8827
#define GL_DRAW_BUFFER3 0x8828
#define GL_DRAW_BUFFER4 0x8829
#define GL_DRAW_BUFFER5 0x882A
#define GL_DRAW_BUFFER6 0x882B
#define GL_DRAW_BUFFER7 0x882C
#define GL_DRAW_BUFFER8 0x882D
#define GL_DRAW_BUFFER9 0x882E
#define GL_DRAW_BUFFER10 0x882F
#define GL_DRAW_BUFFER11 0x8830
#define GL_DRAW_BUFFER12 0x8831
#define GL_DRAW_BUFFER13 0x8832
#define GL_DRAW_BUFFER14 0x8833
#define GL_DRAW_BUFFER15 0x8834
#define GL_BLEND_EQUATION_ALPHA 0x883D
#define GL_MAX_VERTEX_ATTRIBS 0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_MAX_TEXTURE_IMAGE_UNITS 0x8872
#define GL_FRAGMENT_SHADER 0x8B30
#define GL_VERTEX_SHADER 0x8B31
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS 0x8B4A
#define GL_MAX_VARYING_FLOATS 0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define GL_SHADER_TYPE 0x8B4F
#define GL_FLOAT_VEC2 0x8B50
#define GL_FLOAT_VEC3 0x8B51
#define GL_FLOAT_VEC4 0x8B52
#define GL_INT_VEC2 0x8B53
#define GL_INT_VEC3 0x8B54
#define GL_INT_VEC4 0x8B55
#define GL_BOOL 0x8B56
#define GL_BOOL_VEC2 0x8B57
#define GL_BOOL_VEC3 0x8B58
#define GL_BOOL_VEC4 0x8B59
#define GL_FLOAT_MAT2 0x8B5A
#define GL_FLOAT_MAT3 0x8B5B
#define GL_FLOAT_MAT4 0x8B5C
#define GL_SAMPLER_1D 0x8B5D
#define GL_SAMPLER_2D 0x8B5E
#define GL_SAMPLER_3D 0x8B5F
#define GL_SAMPLER_CUBE 0x8B60
#define GL_SAMPLER_1D_SHADOW 0x8B61
#define GL_SAMPLER_2D_SHADOW 0x8B62
#define GL_DELETE_STATUS 0x8B80
#define GL_COMPILE_STATUS 0x8B81
#define GL_LINK_STATUS 0x8B82
#define GL_VALIDATE_STATUS 0x8B83
#define GL_INFO_LOG_LENGTH 0x8B84
#define GL_ATTACHED_SHADERS 0x8B85
#define GL_ACTIVE_UNIFORMS 0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH 0x8B87
#define GL_SHADER_SOURCE_LENGTH 0x8B88
#define GL_ACTIVE_ATTRIBUTES 0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH 0x8B8A
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
#define GL_SHADING_LANGUAGE_VERSION 0x8B8C
#define GL_CURRENT_PROGRAM 0x8B8D
#define GL_POINT_SPRITE_COORD_ORIGIN 0x8CA0
#define GL_LOWER_LEFT 0x8CA1
#define GL_UPPER_LEFT 0x8CA2
#define GL_STENCIL_BACK_REF 0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK 0x8CA4
#define GL_STENCIL_BACK_WRITEMASK 0x8CA5
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendEquationSeparate)(GLenum modeRGB , GLenum modeAlpha); }
#define glBlendEquationSeparate DynamicGL_BlendEquationSeparate
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawBuffers)(GLsizei n , const GLenum *bufs); }
#define glDrawBuffers DynamicGL_DrawBuffers
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_StencilOpSeparate)(GLenum face , GLenum sfail , GLenum dpfail , GLenum dppass); }
#define glStencilOpSeparate DynamicGL_StencilOpSeparate
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_StencilFuncSeparate)(GLenum face , GLenum func , GLint ref , GLuint mask); }
#define glStencilFuncSeparate DynamicGL_StencilFuncSeparate
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_StencilMaskSeparate)(GLenum face , GLuint mask); }
#define glStencilMaskSeparate DynamicGL_StencilMaskSeparate
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_AttachShader)(GLuint program , GLuint shader); }
#define glAttachShader DynamicGL_AttachShader
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindAttribLocation)(GLuint program , GLuint index , const GLchar *name); }
#define glBindAttribLocation DynamicGL_BindAttribLocation
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CompileShader)(GLuint shader); }
#define glCompileShader DynamicGL_CompileShader
extern "C" { extern GLuint (DYNAMIC_GL_APIENTRYP DynamicGL_CreateProgram)(); }
#define glCreateProgram DynamicGL_CreateProgram
extern "C" { extern GLuint (DYNAMIC_GL_APIENTRYP DynamicGL_CreateShader)(GLenum type); }
#define glCreateShader DynamicGL_CreateShader
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteProgram)(GLuint program); }
#define glDeleteProgram DynamicGL_DeleteProgram
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteShader)(GLuint shader); }
#define glDeleteShader DynamicGL_DeleteShader
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DetachShader)(GLuint program , GLuint shader); }
#define glDetachShader DynamicGL_DetachShader
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DisableVertexAttribArray)(GLuint index); }
#define glDisableVertexAttribArray DynamicGL_DisableVertexAttribArray
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EnableVertexAttribArray)(GLuint index); }
#define glEnableVertexAttribArray DynamicGL_EnableVertexAttribArray
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetActiveAttrib)(GLuint program , GLuint index , GLsizei bufSize , GLsizei *length , GLint *size , GLenum *type , GLchar *name); }
#define glGetActiveAttrib DynamicGL_GetActiveAttrib
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetActiveUniform)(GLuint program , GLuint index , GLsizei bufSize , GLsizei *length , GLint *size , GLenum *type , GLchar *name); }
#define glGetActiveUniform DynamicGL_GetActiveUniform
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetAttachedShaders)(GLuint program , GLsizei maxCount , GLsizei *count , GLuint *obj); }
#define glGetAttachedShaders DynamicGL_GetAttachedShaders
extern "C" { extern GLint (DYNAMIC_GL_APIENTRYP DynamicGL_GetAttribLocation)(GLuint program , const GLchar *name); }
#define glGetAttribLocation DynamicGL_GetAttribLocation
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramiv)(GLuint program , GLenum pname , GLint *params); }
#define glGetProgramiv DynamicGL_GetProgramiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramInfoLog)(GLuint program , GLsizei bufSize , GLsizei *length , GLchar *infoLog); }
#define glGetProgramInfoLog DynamicGL_GetProgramInfoLog
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetShaderiv)(GLuint shader , GLenum pname , GLint *params); }
#define glGetShaderiv DynamicGL_GetShaderiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetShaderInfoLog)(GLuint shader , GLsizei bufSize , GLsizei *length , GLchar *infoLog); }
#define glGetShaderInfoLog DynamicGL_GetShaderInfoLog
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetShaderSource)(GLuint shader , GLsizei bufSize , GLsizei *length , GLchar *source); }
#define glGetShaderSource DynamicGL_GetShaderSource
extern "C" { extern GLint (DYNAMIC_GL_APIENTRYP DynamicGL_GetUniformLocation)(GLuint program , const GLchar *name); }
#define glGetUniformLocation DynamicGL_GetUniformLocation
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetUniformfv)(GLuint program , GLint location , GLfloat *params); }
#define glGetUniformfv DynamicGL_GetUniformfv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetUniformiv)(GLuint program , GLint location , GLint *params); }
#define glGetUniformiv DynamicGL_GetUniformiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribdv)(GLuint index , GLenum pname , GLdouble *params); }
#define glGetVertexAttribdv DynamicGL_GetVertexAttribdv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribfv)(GLuint index , GLenum pname , GLfloat *params); }
#define glGetVertexAttribfv DynamicGL_GetVertexAttribfv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribiv)(GLuint index , GLenum pname , GLint *params); }
#define glGetVertexAttribiv DynamicGL_GetVertexAttribiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribPointerv)(GLuint index , GLenum pname , GLvoid* *pointer); }
#define glGetVertexAttribPointerv DynamicGL_GetVertexAttribPointerv
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsProgram)(GLuint program); }
#define glIsProgram DynamicGL_IsProgram
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsShader)(GLuint shader); }
#define glIsShader DynamicGL_IsShader
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LinkProgram)(GLuint program); }
#define glLinkProgram DynamicGL_LinkProgram
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ShaderSource)(GLuint shader , GLsizei count , const GLchar* const , const GLint *length); }
#define glShaderSource DynamicGL_ShaderSource
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_UseProgram)(GLuint program); }
#define glUseProgram DynamicGL_UseProgram
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform1f)(GLint location , GLfloat v0); }
#define glUniform1f DynamicGL_Uniform1f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform2f)(GLint location , GLfloat v0 , GLfloat v1); }
#define glUniform2f DynamicGL_Uniform2f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform3f)(GLint location , GLfloat v0 , GLfloat v1 , GLfloat v2); }
#define glUniform3f DynamicGL_Uniform3f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform4f)(GLint location , GLfloat v0 , GLfloat v1 , GLfloat v2 , GLfloat v3); }
#define glUniform4f DynamicGL_Uniform4f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform1i)(GLint location , GLint v0); }
#define glUniform1i DynamicGL_Uniform1i
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform2i)(GLint location , GLint v0 , GLint v1); }
#define glUniform2i DynamicGL_Uniform2i
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform3i)(GLint location , GLint v0 , GLint v1 , GLint v2); }
#define glUniform3i DynamicGL_Uniform3i
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform4i)(GLint location , GLint v0 , GLint v1 , GLint v2 , GLint v3); }
#define glUniform4i DynamicGL_Uniform4i
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform1fv)(GLint location , GLsizei count , const GLfloat *value); }
#define glUniform1fv DynamicGL_Uniform1fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform2fv)(GLint location , GLsizei count , const GLfloat *value); }
#define glUniform2fv DynamicGL_Uniform2fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform3fv)(GLint location , GLsizei count , const GLfloat *value); }
#define glUniform3fv DynamicGL_Uniform3fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform4fv)(GLint location , GLsizei count , const GLfloat *value); }
#define glUniform4fv DynamicGL_Uniform4fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform1iv)(GLint location , GLsizei count , const GLint *value); }
#define glUniform1iv DynamicGL_Uniform1iv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform2iv)(GLint location , GLsizei count , const GLint *value); }
#define glUniform2iv DynamicGL_Uniform2iv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform3iv)(GLint location , GLsizei count , const GLint *value); }
#define glUniform3iv DynamicGL_Uniform3iv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform4iv)(GLint location , GLsizei count , const GLint *value); }
#define glUniform4iv DynamicGL_Uniform4iv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformMatrix2fv)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value); }
#define glUniformMatrix2fv DynamicGL_UniformMatrix2fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformMatrix3fv)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value); }
#define glUniformMatrix3fv DynamicGL_UniformMatrix3fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformMatrix4fv)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value); }
#define glUniformMatrix4fv DynamicGL_UniformMatrix4fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ValidateProgram)(GLuint program); }
#define glValidateProgram DynamicGL_ValidateProgram
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1d)(GLuint index , GLdouble x); }
#define glVertexAttrib1d DynamicGL_VertexAttrib1d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1dv)(GLuint index , const GLdouble *v); }
#define glVertexAttrib1dv DynamicGL_VertexAttrib1dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1f)(GLuint index , GLfloat x); }
#define glVertexAttrib1f DynamicGL_VertexAttrib1f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1fv)(GLuint index , const GLfloat *v); }
#define glVertexAttrib1fv DynamicGL_VertexAttrib1fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1s)(GLuint index , GLshort x); }
#define glVertexAttrib1s DynamicGL_VertexAttrib1s
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1sv)(GLuint index , const GLshort *v); }
#define glVertexAttrib1sv DynamicGL_VertexAttrib1sv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2d)(GLuint index , GLdouble x , GLdouble y); }
#define glVertexAttrib2d DynamicGL_VertexAttrib2d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2dv)(GLuint index , const GLdouble *v); }
#define glVertexAttrib2dv DynamicGL_VertexAttrib2dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2f)(GLuint index , GLfloat x , GLfloat y); }
#define glVertexAttrib2f DynamicGL_VertexAttrib2f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2fv)(GLuint index , const GLfloat *v); }
#define glVertexAttrib2fv DynamicGL_VertexAttrib2fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2s)(GLuint index , GLshort x , GLshort y); }
#define glVertexAttrib2s DynamicGL_VertexAttrib2s
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2sv)(GLuint index , const GLshort *v); }
#define glVertexAttrib2sv DynamicGL_VertexAttrib2sv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3d)(GLuint index , GLdouble x , GLdouble y , GLdouble z); }
#define glVertexAttrib3d DynamicGL_VertexAttrib3d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3dv)(GLuint index , const GLdouble *v); }
#define glVertexAttrib3dv DynamicGL_VertexAttrib3dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3f)(GLuint index , GLfloat x , GLfloat y , GLfloat z); }
#define glVertexAttrib3f DynamicGL_VertexAttrib3f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3fv)(GLuint index , const GLfloat *v); }
#define glVertexAttrib3fv DynamicGL_VertexAttrib3fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3s)(GLuint index , GLshort x , GLshort y , GLshort z); }
#define glVertexAttrib3s DynamicGL_VertexAttrib3s
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3sv)(GLuint index , const GLshort *v); }
#define glVertexAttrib3sv DynamicGL_VertexAttrib3sv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4Nbv)(GLuint index , const GLbyte *v); }
#define glVertexAttrib4Nbv DynamicGL_VertexAttrib4Nbv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4Niv)(GLuint index , const GLint *v); }
#define glVertexAttrib4Niv DynamicGL_VertexAttrib4Niv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4Nsv)(GLuint index , const GLshort *v); }
#define glVertexAttrib4Nsv DynamicGL_VertexAttrib4Nsv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4Nub)(GLuint index , GLubyte x , GLubyte y , GLubyte z , GLubyte w); }
#define glVertexAttrib4Nub DynamicGL_VertexAttrib4Nub
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4Nubv)(GLuint index , const GLubyte *v); }
#define glVertexAttrib4Nubv DynamicGL_VertexAttrib4Nubv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4Nuiv)(GLuint index , const GLuint *v); }
#define glVertexAttrib4Nuiv DynamicGL_VertexAttrib4Nuiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4Nusv)(GLuint index , const GLushort *v); }
#define glVertexAttrib4Nusv DynamicGL_VertexAttrib4Nusv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4bv)(GLuint index , const GLbyte *v); }
#define glVertexAttrib4bv DynamicGL_VertexAttrib4bv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4d)(GLuint index , GLdouble x , GLdouble y , GLdouble z , GLdouble w); }
#define glVertexAttrib4d DynamicGL_VertexAttrib4d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4dv)(GLuint index , const GLdouble *v); }
#define glVertexAttrib4dv DynamicGL_VertexAttrib4dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4f)(GLuint index , GLfloat x , GLfloat y , GLfloat z , GLfloat w); }
#define glVertexAttrib4f DynamicGL_VertexAttrib4f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4fv)(GLuint index , const GLfloat *v); }
#define glVertexAttrib4fv DynamicGL_VertexAttrib4fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4iv)(GLuint index , const GLint *v); }
#define glVertexAttrib4iv DynamicGL_VertexAttrib4iv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4s)(GLuint index , GLshort x , GLshort y , GLshort z , GLshort w); }
#define glVertexAttrib4s DynamicGL_VertexAttrib4s
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4sv)(GLuint index , const GLshort *v); }
#define glVertexAttrib4sv DynamicGL_VertexAttrib4sv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4ubv)(GLuint index , const GLubyte *v); }
#define glVertexAttrib4ubv DynamicGL_VertexAttrib4ubv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4uiv)(GLuint index , const GLuint *v); }
#define glVertexAttrib4uiv DynamicGL_VertexAttrib4uiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4usv)(GLuint index , const GLushort *v); }
#define glVertexAttrib4usv DynamicGL_VertexAttrib4usv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribPointer)(GLuint index , GLint size , GLenum type , GLboolean normalized , GLsizei stride , const GLvoid *pointer); }
#define glVertexAttribPointer DynamicGL_VertexAttribPointer
extern bool DinamicGLFeature_VERSION_2_0_Supported();
#endif /*USE_DYNAMIC_GL_VERSION_2_0*/

/*EXT_compiled_vertex_array*/
#ifdef USE_DYNAMIC_GL_EXT_compiled_vertex_array
#define GL_ARRAY_ELEMENT_LOCK_FIRST_EXT 0x81A8
#define GL_ARRAY_ELEMENT_LOCK_COUNT_EXT 0x81A9
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LockArraysEXT)(GLint first , GLsizei count); }
#define glLockArraysEXT DynamicGL_LockArraysEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_UnlockArraysEXT)(); }
#define glUnlockArraysEXT DynamicGL_UnlockArraysEXT
extern bool DinamicGLFeature_EXT_compiled_vertex_array_Supported();
#endif /*USE_DYNAMIC_GL_EXT_compiled_vertex_array*/

/*IBM_texture_mirrored_repeat*/
#ifdef USE_DYNAMIC_GL_IBM_texture_mirrored_repeat
#define GL_MIRRORED_REPEAT_IBM 0x8370
extern bool DinamicGLFeature_IBM_texture_mirrored_repeat_Supported();
#endif /*USE_DYNAMIC_GL_IBM_texture_mirrored_repeat*/

/*OML_subsample*/
#ifdef USE_DYNAMIC_GL_OML_subsample
#define GL_FORMAT_SUBSAMPLE_24_24_OML 0x8982
#define GL_FORMAT_SUBSAMPLE_244_244_OML 0x8983
extern bool DinamicGLFeature_OML_subsample_Supported();
#endif /*USE_DYNAMIC_GL_OML_subsample*/

/*NV_texgen_reflection*/
#ifdef USE_DYNAMIC_GL_NV_texgen_reflection
#define GL_NORMAL_MAP_NV 0x8511
#define GL_REFLECTION_MAP_NV 0x8512
extern bool DinamicGLFeature_NV_texgen_reflection_Supported();
#endif /*USE_DYNAMIC_GL_NV_texgen_reflection*/

/*AMD_name_gen_delete*/
#ifdef USE_DYNAMIC_GL_AMD_name_gen_delete
#define GL_DATA_BUFFER_AMD 0x9151
#define GL_PERFORMANCE_MONITOR_AMD 0x9152
#define GL_QUERY_OBJECT_AMD 0x9153
#define GL_VERTEX_ARRAY_OBJECT_AMD 0x9154
#define GL_SAMPLER_OBJECT_AMD 0x9155
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GenNamesAMD)(GLenum identifier , GLuint num , GLuint *names); }
#define glGenNamesAMD DynamicGL_GenNamesAMD
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteNamesAMD)(GLenum identifier , GLuint num , const GLuint *names); }
#define glDeleteNamesAMD DynamicGL_DeleteNamesAMD
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsNameAMD)(GLenum identifier , GLuint name); }
#define glIsNameAMD DynamicGL_IsNameAMD
extern bool DinamicGLFeature_AMD_name_gen_delete_Supported();
#endif /*USE_DYNAMIC_GL_AMD_name_gen_delete*/

/*SGIX_list_priority*/
#ifdef USE_DYNAMIC_GL_SGIX_list_priority
#define GL_LIST_PRIORITY_SGIX 0x8182
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetListParameterfvSGIX)(GLuint list , GLenum pname , GLfloat *params); }
#define glGetListParameterfvSGIX DynamicGL_GetListParameterfvSGIX
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetListParameterivSGIX)(GLuint list , GLenum pname , GLint *params); }
#define glGetListParameterivSGIX DynamicGL_GetListParameterivSGIX
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ListParameterfSGIX)(GLuint list , GLenum pname , GLfloat param); }
#define glListParameterfSGIX DynamicGL_ListParameterfSGIX
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ListParameterfvSGIX)(GLuint list , GLenum pname , const GLfloat *params); }
#define glListParameterfvSGIX DynamicGL_ListParameterfvSGIX
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ListParameteriSGIX)(GLuint list , GLenum pname , GLint param); }
#define glListParameteriSGIX DynamicGL_ListParameteriSGIX
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ListParameterivSGIX)(GLuint list , GLenum pname , const GLint *params); }
#define glListParameterivSGIX DynamicGL_ListParameterivSGIX
extern bool DinamicGLFeature_SGIX_list_priority_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_list_priority*/

/*NV_occlusion_query*/
#ifdef USE_DYNAMIC_GL_NV_occlusion_query
#define GL_PIXEL_COUNTER_BITS_NV 0x8864
#define GL_CURRENT_OCCLUSION_QUERY_ID_NV 0x8865
#define GL_PIXEL_COUNT_NV 0x8866
#define GL_PIXEL_COUNT_AVAILABLE_NV 0x8867
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GenOcclusionQueriesNV)(GLsizei n , GLuint *ids); }
#define glGenOcclusionQueriesNV DynamicGL_GenOcclusionQueriesNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteOcclusionQueriesNV)(GLsizei n , const GLuint *ids); }
#define glDeleteOcclusionQueriesNV DynamicGL_DeleteOcclusionQueriesNV
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsOcclusionQueryNV)(GLuint id); }
#define glIsOcclusionQueryNV DynamicGL_IsOcclusionQueryNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BeginOcclusionQueryNV)(GLuint id); }
#define glBeginOcclusionQueryNV DynamicGL_BeginOcclusionQueryNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EndOcclusionQueryNV)(); }
#define glEndOcclusionQueryNV DynamicGL_EndOcclusionQueryNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetOcclusionQueryivNV)(GLuint id , GLenum pname , GLint *params); }
#define glGetOcclusionQueryivNV DynamicGL_GetOcclusionQueryivNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetOcclusionQueryuivNV)(GLuint id , GLenum pname , GLuint *params); }
#define glGetOcclusionQueryuivNV DynamicGL_GetOcclusionQueryuivNV
extern bool DinamicGLFeature_NV_occlusion_query_Supported();
#endif /*USE_DYNAMIC_GL_NV_occlusion_query*/

/*EXT_texture_shared_exponent*/
#ifdef USE_DYNAMIC_GL_EXT_texture_shared_exponent
#define GL_RGB9_E5_EXT 0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV_EXT 0x8C3E
#define GL_TEXTURE_SHARED_SIZE_EXT 0x8C3F
extern bool DinamicGLFeature_EXT_texture_shared_exponent_Supported();
#endif /*USE_DYNAMIC_GL_EXT_texture_shared_exponent*/

/*VERSION_1_3*/
#ifdef USE_DYNAMIC_GL_VERSION_1_3
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
#define GL_MULTISAMPLE 0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE 0x809E
#define GL_SAMPLE_ALPHA_TO_ONE 0x809F
#define GL_SAMPLE_COVERAGE 0x80A0
#define GL_SAMPLE_BUFFERS 0x80A8
#define GL_SAMPLES 0x80A9
#define GL_SAMPLE_COVERAGE_VALUE 0x80AA
#define GL_SAMPLE_COVERAGE_INVERT 0x80AB
#define GL_TEXTURE_CUBE_MAP 0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP 0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X 0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X 0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y 0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y 0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z 0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z 0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP 0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE 0x851C
#define GL_COMPRESSED_RGB 0x84ED
#define GL_COMPRESSED_RGBA 0x84EE
#define GL_TEXTURE_COMPRESSION_HINT 0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE 0x86A0
#define GL_TEXTURE_COMPRESSED 0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS 0x86A3
#define GL_CLAMP_TO_BORDER 0x812D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ActiveTexture)(GLenum texture); }
#define glActiveTexture DynamicGL_ActiveTexture
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SampleCoverage)(GLfloat value , GLboolean invert); }
#define glSampleCoverage DynamicGL_SampleCoverage
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTexImage3D)(GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLsizei depth , GLint border , GLsizei imageSize , const GLvoid *data); }
#define glCompressedTexImage3D DynamicGL_CompressedTexImage3D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTexImage2D)(GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLint border , GLsizei imageSize , const GLvoid *data); }
#define glCompressedTexImage2D DynamicGL_CompressedTexImage2D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTexImage1D)(GLenum target , GLint level , GLenum internalformat , GLsizei width , GLint border , GLsizei imageSize , const GLvoid *data); }
#define glCompressedTexImage1D DynamicGL_CompressedTexImage1D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTexSubImage3D)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLsizei width , GLsizei height , GLsizei depth , GLenum format , GLsizei imageSize , const GLvoid *data); }
#define glCompressedTexSubImage3D DynamicGL_CompressedTexSubImage3D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTexSubImage2D)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLsizei width , GLsizei height , GLenum format , GLsizei imageSize , const GLvoid *data); }
#define glCompressedTexSubImage2D DynamicGL_CompressedTexSubImage2D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTexSubImage1D)(GLenum target , GLint level , GLint xoffset , GLsizei width , GLenum format , GLsizei imageSize , const GLvoid *data); }
#define glCompressedTexSubImage1D DynamicGL_CompressedTexSubImage1D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetCompressedTexImage)(GLenum target , GLint level , GLvoid *img); }
#define glGetCompressedTexImage DynamicGL_GetCompressedTexImage
extern bool DinamicGLFeature_VERSION_1_3_Supported();
#endif /*USE_DYNAMIC_GL_VERSION_1_3*/

/*ARB_color_buffer_float*/
#ifdef USE_DYNAMIC_GL_ARB_color_buffer_float
#define GL_RGBA_FLOAT_MODE_ARB 0x8820
#define GL_CLAMP_VERTEX_COLOR_ARB 0x891A
#define GL_CLAMP_FRAGMENT_COLOR_ARB 0x891B
#define GL_CLAMP_READ_COLOR_ARB 0x891C
#define GL_FIXED_ONLY_ARB 0x891D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClampColorARB)(GLenum target , GLenum clamp); }
#define glClampColorARB DynamicGL_ClampColorARB
extern bool DinamicGLFeature_ARB_color_buffer_float_Supported();
#endif /*USE_DYNAMIC_GL_ARB_color_buffer_float*/

/*NV_half_float*/
#ifdef USE_DYNAMIC_GL_NV_half_float
typedef unsigned short GLhalfNV;
#define GL_HALF_FLOAT_NV 0x140B
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex2hNV)(GLhalfNV x , GLhalfNV y); }
#define glVertex2hNV DynamicGL_Vertex2hNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex2hvNV)(const GLhalfNV *v); }
#define glVertex2hvNV DynamicGL_Vertex2hvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex3hNV)(GLhalfNV x , GLhalfNV y , GLhalfNV z); }
#define glVertex3hNV DynamicGL_Vertex3hNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex3hvNV)(const GLhalfNV *v); }
#define glVertex3hvNV DynamicGL_Vertex3hvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex4hNV)(GLhalfNV x , GLhalfNV y , GLhalfNV z , GLhalfNV w); }
#define glVertex4hNV DynamicGL_Vertex4hNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Vertex4hvNV)(const GLhalfNV *v); }
#define glVertex4hvNV DynamicGL_Vertex4hvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Normal3hNV)(GLhalfNV nx , GLhalfNV ny , GLhalfNV nz); }
#define glNormal3hNV DynamicGL_Normal3hNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Normal3hvNV)(const GLhalfNV *v); }
#define glNormal3hvNV DynamicGL_Normal3hvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3hNV)(GLhalfNV red , GLhalfNV green , GLhalfNV blue); }
#define glColor3hNV DynamicGL_Color3hNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3hvNV)(const GLhalfNV *v); }
#define glColor3hvNV DynamicGL_Color3hvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4hNV)(GLhalfNV red , GLhalfNV green , GLhalfNV blue , GLhalfNV alpha); }
#define glColor4hNV DynamicGL_Color4hNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4hvNV)(const GLhalfNV *v); }
#define glColor4hvNV DynamicGL_Color4hvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord1hNV)(GLhalfNV s); }
#define glTexCoord1hNV DynamicGL_TexCoord1hNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord1hvNV)(const GLhalfNV *v); }
#define glTexCoord1hvNV DynamicGL_TexCoord1hvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2hNV)(GLhalfNV s , GLhalfNV t); }
#define glTexCoord2hNV DynamicGL_TexCoord2hNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2hvNV)(const GLhalfNV *v); }
#define glTexCoord2hvNV DynamicGL_TexCoord2hvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord3hNV)(GLhalfNV s , GLhalfNV t , GLhalfNV r); }
#define glTexCoord3hNV DynamicGL_TexCoord3hNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord3hvNV)(const GLhalfNV *v); }
#define glTexCoord3hvNV DynamicGL_TexCoord3hvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord4hNV)(GLhalfNV s , GLhalfNV t , GLhalfNV r , GLhalfNV q); }
#define glTexCoord4hNV DynamicGL_TexCoord4hNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord4hvNV)(const GLhalfNV *v); }
#define glTexCoord4hvNV DynamicGL_TexCoord4hvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1hNV)(GLenum target , GLhalfNV s); }
#define glMultiTexCoord1hNV DynamicGL_MultiTexCoord1hNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1hvNV)(GLenum target , const GLhalfNV *v); }
#define glMultiTexCoord1hvNV DynamicGL_MultiTexCoord1hvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2hNV)(GLenum target , GLhalfNV s , GLhalfNV t); }
#define glMultiTexCoord2hNV DynamicGL_MultiTexCoord2hNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2hvNV)(GLenum target , const GLhalfNV *v); }
#define glMultiTexCoord2hvNV DynamicGL_MultiTexCoord2hvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3hNV)(GLenum target , GLhalfNV s , GLhalfNV t , GLhalfNV r); }
#define glMultiTexCoord3hNV DynamicGL_MultiTexCoord3hNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3hvNV)(GLenum target , const GLhalfNV *v); }
#define glMultiTexCoord3hvNV DynamicGL_MultiTexCoord3hvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4hNV)(GLenum target , GLhalfNV s , GLhalfNV t , GLhalfNV r , GLhalfNV q); }
#define glMultiTexCoord4hNV DynamicGL_MultiTexCoord4hNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4hvNV)(GLenum target , const GLhalfNV *v); }
#define glMultiTexCoord4hvNV DynamicGL_MultiTexCoord4hvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FogCoordhNV)(GLhalfNV fog); }
#define glFogCoordhNV DynamicGL_FogCoordhNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FogCoordhvNV)(const GLhalfNV *fog); }
#define glFogCoordhvNV DynamicGL_FogCoordhvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3hNV)(GLhalfNV red , GLhalfNV green , GLhalfNV blue); }
#define glSecondaryColor3hNV DynamicGL_SecondaryColor3hNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3hvNV)(const GLhalfNV *v); }
#define glSecondaryColor3hvNV DynamicGL_SecondaryColor3hvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexWeighthNV)(GLhalfNV weight); }
#define glVertexWeighthNV DynamicGL_VertexWeighthNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexWeighthvNV)(const GLhalfNV *weight); }
#define glVertexWeighthvNV DynamicGL_VertexWeighthvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1hNV)(GLuint index , GLhalfNV x); }
#define glVertexAttrib1hNV DynamicGL_VertexAttrib1hNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib1hvNV)(GLuint index , const GLhalfNV *v); }
#define glVertexAttrib1hvNV DynamicGL_VertexAttrib1hvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2hNV)(GLuint index , GLhalfNV x , GLhalfNV y); }
#define glVertexAttrib2hNV DynamicGL_VertexAttrib2hNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib2hvNV)(GLuint index , const GLhalfNV *v); }
#define glVertexAttrib2hvNV DynamicGL_VertexAttrib2hvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3hNV)(GLuint index , GLhalfNV x , GLhalfNV y , GLhalfNV z); }
#define glVertexAttrib3hNV DynamicGL_VertexAttrib3hNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib3hvNV)(GLuint index , const GLhalfNV *v); }
#define glVertexAttrib3hvNV DynamicGL_VertexAttrib3hvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4hNV)(GLuint index , GLhalfNV x , GLhalfNV y , GLhalfNV z , GLhalfNV w); }
#define glVertexAttrib4hNV DynamicGL_VertexAttrib4hNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttrib4hvNV)(GLuint index , const GLhalfNV *v); }
#define glVertexAttrib4hvNV DynamicGL_VertexAttrib4hvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribs1hvNV)(GLuint index , GLsizei n , const GLhalfNV *v); }
#define glVertexAttribs1hvNV DynamicGL_VertexAttribs1hvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribs2hvNV)(GLuint index , GLsizei n , const GLhalfNV *v); }
#define glVertexAttribs2hvNV DynamicGL_VertexAttribs2hvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribs3hvNV)(GLuint index , GLsizei n , const GLhalfNV *v); }
#define glVertexAttribs3hvNV DynamicGL_VertexAttribs3hvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribs4hvNV)(GLuint index , GLsizei n , const GLhalfNV *v); }
#define glVertexAttribs4hvNV DynamicGL_VertexAttribs4hvNV
extern bool DinamicGLFeature_NV_half_float_Supported();
#endif /*USE_DYNAMIC_GL_NV_half_float*/

/*APPLE_float_pixels*/
#ifdef USE_DYNAMIC_GL_APPLE_float_pixels
#define GL_HALF_APPLE 0x140B
#define GL_RGBA_FLOAT32_APPLE 0x8814
#define GL_RGB_FLOAT32_APPLE 0x8815
#define GL_ALPHA_FLOAT32_APPLE 0x8816
#define GL_INTENSITY_FLOAT32_APPLE 0x8817
#define GL_LUMINANCE_FLOAT32_APPLE 0x8818
#define GL_LUMINANCE_ALPHA_FLOAT32_APPLE 0x8819
#define GL_RGBA_FLOAT16_APPLE 0x881A
#define GL_RGB_FLOAT16_APPLE 0x881B
#define GL_ALPHA_FLOAT16_APPLE 0x881C
#define GL_INTENSITY_FLOAT16_APPLE 0x881D
#define GL_LUMINANCE_FLOAT16_APPLE 0x881E
#define GL_LUMINANCE_ALPHA_FLOAT16_APPLE 0x881F
#define GL_COLOR_FLOAT_APPLE 0x8A0F
extern bool DinamicGLFeature_APPLE_float_pixels_Supported();
#endif /*USE_DYNAMIC_GL_APPLE_float_pixels*/

/*EXT_gpu_shader4*/
#ifdef USE_DYNAMIC_GL_EXT_gpu_shader4
#define GL_SAMPLER_1D_ARRAY_EXT 0x8DC0
#define GL_SAMPLER_2D_ARRAY_EXT 0x8DC1
#define GL_SAMPLER_BUFFER_EXT 0x8DC2
#define GL_SAMPLER_1D_ARRAY_SHADOW_EXT 0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW_EXT 0x8DC4
#define GL_SAMPLER_CUBE_SHADOW_EXT 0x8DC5
#define GL_UNSIGNED_INT_VEC2_EXT 0x8DC6
#define GL_UNSIGNED_INT_VEC3_EXT 0x8DC7
#define GL_UNSIGNED_INT_VEC4_EXT 0x8DC8
#define GL_INT_SAMPLER_1D_EXT 0x8DC9
#define GL_INT_SAMPLER_2D_EXT 0x8DCA
#define GL_INT_SAMPLER_3D_EXT 0x8DCB
#define GL_INT_SAMPLER_CUBE_EXT 0x8DCC
#define GL_INT_SAMPLER_2D_RECT_EXT 0x8DCD
#define GL_INT_SAMPLER_1D_ARRAY_EXT 0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY_EXT 0x8DCF
#define GL_INT_SAMPLER_BUFFER_EXT 0x8DD0
#define GL_UNSIGNED_INT_SAMPLER_1D_EXT 0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D_EXT 0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D_EXT 0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE_EXT 0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT_EXT 0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY_EXT 0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY_EXT 0x8DD7
#define GL_UNSIGNED_INT_SAMPLER_BUFFER_EXT 0x8DD8
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetUniformuivEXT)(GLuint program , GLint location , GLuint *params); }
#define glGetUniformuivEXT DynamicGL_GetUniformuivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindFragDataLocationEXT)(GLuint program , GLuint color , const GLchar *name); }
#define glBindFragDataLocationEXT DynamicGL_BindFragDataLocationEXT
extern "C" { extern GLint (DYNAMIC_GL_APIENTRYP DynamicGL_GetFragDataLocationEXT)(GLuint program , const GLchar *name); }
#define glGetFragDataLocationEXT DynamicGL_GetFragDataLocationEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform1uiEXT)(GLint location , GLuint v0); }
#define glUniform1uiEXT DynamicGL_Uniform1uiEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform2uiEXT)(GLint location , GLuint v0 , GLuint v1); }
#define glUniform2uiEXT DynamicGL_Uniform2uiEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform3uiEXT)(GLint location , GLuint v0 , GLuint v1 , GLuint v2); }
#define glUniform3uiEXT DynamicGL_Uniform3uiEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform4uiEXT)(GLint location , GLuint v0 , GLuint v1 , GLuint v2 , GLuint v3); }
#define glUniform4uiEXT DynamicGL_Uniform4uiEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform1uivEXT)(GLint location , GLsizei count , const GLuint *value); }
#define glUniform1uivEXT DynamicGL_Uniform1uivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform2uivEXT)(GLint location , GLsizei count , const GLuint *value); }
#define glUniform2uivEXT DynamicGL_Uniform2uivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform3uivEXT)(GLint location , GLsizei count , const GLuint *value); }
#define glUniform3uivEXT DynamicGL_Uniform3uivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform4uivEXT)(GLint location , GLsizei count , const GLuint *value); }
#define glUniform4uivEXT DynamicGL_Uniform4uivEXT
extern bool DinamicGLFeature_EXT_gpu_shader4_Supported();
#endif /*USE_DYNAMIC_GL_EXT_gpu_shader4*/

/*NV_gpu_shader5*/
#ifdef USE_DYNAMIC_GL_NV_gpu_shader5
#define GL_INT64_NV 0x140E
#define GL_UNSIGNED_INT64_NV 0x140F
#define GL_INT8_NV 0x8FE0
#define GL_INT8_VEC2_NV 0x8FE1
#define GL_INT8_VEC3_NV 0x8FE2
#define GL_INT8_VEC4_NV 0x8FE3
#define GL_INT16_NV 0x8FE4
#define GL_INT16_VEC2_NV 0x8FE5
#define GL_INT16_VEC3_NV 0x8FE6
#define GL_INT16_VEC4_NV 0x8FE7
#define GL_INT64_VEC2_NV 0x8FE9
#define GL_INT64_VEC3_NV 0x8FEA
#define GL_INT64_VEC4_NV 0x8FEB
#define GL_UNSIGNED_INT8_NV 0x8FEC
#define GL_UNSIGNED_INT8_VEC2_NV 0x8FED
#define GL_UNSIGNED_INT8_VEC3_NV 0x8FEE
#define GL_UNSIGNED_INT8_VEC4_NV 0x8FEF
#define GL_UNSIGNED_INT16_NV 0x8FF0
#define GL_UNSIGNED_INT16_VEC2_NV 0x8FF1
#define GL_UNSIGNED_INT16_VEC3_NV 0x8FF2
#define GL_UNSIGNED_INT16_VEC4_NV 0x8FF3
#define GL_UNSIGNED_INT64_VEC2_NV 0x8FF5
#define GL_UNSIGNED_INT64_VEC3_NV 0x8FF6
#define GL_UNSIGNED_INT64_VEC4_NV 0x8FF7
#define GL_FLOAT16_NV 0x8FF8
#define GL_FLOAT16_VEC2_NV 0x8FF9
#define GL_FLOAT16_VEC3_NV 0x8FFA
#define GL_FLOAT16_VEC4_NV 0x8FFB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform1i64NV)(GLint location , GLint64EXT x); }
#define glUniform1i64NV DynamicGL_Uniform1i64NV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform2i64NV)(GLint location , GLint64EXT x , GLint64EXT y); }
#define glUniform2i64NV DynamicGL_Uniform2i64NV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform3i64NV)(GLint location , GLint64EXT x , GLint64EXT y , GLint64EXT z); }
#define glUniform3i64NV DynamicGL_Uniform3i64NV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform4i64NV)(GLint location , GLint64EXT x , GLint64EXT y , GLint64EXT z , GLint64EXT w); }
#define glUniform4i64NV DynamicGL_Uniform4i64NV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform1i64vNV)(GLint location , GLsizei count , const GLint64EXT *value); }
#define glUniform1i64vNV DynamicGL_Uniform1i64vNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform2i64vNV)(GLint location , GLsizei count , const GLint64EXT *value); }
#define glUniform2i64vNV DynamicGL_Uniform2i64vNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform3i64vNV)(GLint location , GLsizei count , const GLint64EXT *value); }
#define glUniform3i64vNV DynamicGL_Uniform3i64vNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform4i64vNV)(GLint location , GLsizei count , const GLint64EXT *value); }
#define glUniform4i64vNV DynamicGL_Uniform4i64vNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform1ui64NV)(GLint location , GLuint64EXT x); }
#define glUniform1ui64NV DynamicGL_Uniform1ui64NV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform2ui64NV)(GLint location , GLuint64EXT x , GLuint64EXT y); }
#define glUniform2ui64NV DynamicGL_Uniform2ui64NV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform3ui64NV)(GLint location , GLuint64EXT x , GLuint64EXT y , GLuint64EXT z); }
#define glUniform3ui64NV DynamicGL_Uniform3ui64NV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform4ui64NV)(GLint location , GLuint64EXT x , GLuint64EXT y , GLuint64EXT z , GLuint64EXT w); }
#define glUniform4ui64NV DynamicGL_Uniform4ui64NV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform1ui64vNV)(GLint location , GLsizei count , const GLuint64EXT *value); }
#define glUniform1ui64vNV DynamicGL_Uniform1ui64vNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform2ui64vNV)(GLint location , GLsizei count , const GLuint64EXT *value); }
#define glUniform2ui64vNV DynamicGL_Uniform2ui64vNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform3ui64vNV)(GLint location , GLsizei count , const GLuint64EXT *value); }
#define glUniform3ui64vNV DynamicGL_Uniform3ui64vNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniform4ui64vNV)(GLint location , GLsizei count , const GLuint64EXT *value); }
#define glUniform4ui64vNV DynamicGL_Uniform4ui64vNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetUniformi64vNV)(GLuint program , GLint location , GLint64EXT *params); }
#define glGetUniformi64vNV DynamicGL_GetUniformi64vNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform1i64NV)(GLuint program , GLint location , GLint64EXT x); }
#define glProgramUniform1i64NV DynamicGL_ProgramUniform1i64NV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform2i64NV)(GLuint program , GLint location , GLint64EXT x , GLint64EXT y); }
#define glProgramUniform2i64NV DynamicGL_ProgramUniform2i64NV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform3i64NV)(GLuint program , GLint location , GLint64EXT x , GLint64EXT y , GLint64EXT z); }
#define glProgramUniform3i64NV DynamicGL_ProgramUniform3i64NV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform4i64NV)(GLuint program , GLint location , GLint64EXT x , GLint64EXT y , GLint64EXT z , GLint64EXT w); }
#define glProgramUniform4i64NV DynamicGL_ProgramUniform4i64NV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform1i64vNV)(GLuint program , GLint location , GLsizei count , const GLint64EXT *value); }
#define glProgramUniform1i64vNV DynamicGL_ProgramUniform1i64vNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform2i64vNV)(GLuint program , GLint location , GLsizei count , const GLint64EXT *value); }
#define glProgramUniform2i64vNV DynamicGL_ProgramUniform2i64vNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform3i64vNV)(GLuint program , GLint location , GLsizei count , const GLint64EXT *value); }
#define glProgramUniform3i64vNV DynamicGL_ProgramUniform3i64vNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform4i64vNV)(GLuint program , GLint location , GLsizei count , const GLint64EXT *value); }
#define glProgramUniform4i64vNV DynamicGL_ProgramUniform4i64vNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform1ui64NV)(GLuint program , GLint location , GLuint64EXT x); }
#define glProgramUniform1ui64NV DynamicGL_ProgramUniform1ui64NV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform2ui64NV)(GLuint program , GLint location , GLuint64EXT x , GLuint64EXT y); }
#define glProgramUniform2ui64NV DynamicGL_ProgramUniform2ui64NV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform3ui64NV)(GLuint program , GLint location , GLuint64EXT x , GLuint64EXT y , GLuint64EXT z); }
#define glProgramUniform3ui64NV DynamicGL_ProgramUniform3ui64NV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform4ui64NV)(GLuint program , GLint location , GLuint64EXT x , GLuint64EXT y , GLuint64EXT z , GLuint64EXT w); }
#define glProgramUniform4ui64NV DynamicGL_ProgramUniform4ui64NV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform1ui64vNV)(GLuint program , GLint location , GLsizei count , const GLuint64EXT *value); }
#define glProgramUniform1ui64vNV DynamicGL_ProgramUniform1ui64vNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform2ui64vNV)(GLuint program , GLint location , GLsizei count , const GLuint64EXT *value); }
#define glProgramUniform2ui64vNV DynamicGL_ProgramUniform2ui64vNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform3ui64vNV)(GLuint program , GLint location , GLsizei count , const GLuint64EXT *value); }
#define glProgramUniform3ui64vNV DynamicGL_ProgramUniform3ui64vNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform4ui64vNV)(GLuint program , GLint location , GLsizei count , const GLuint64EXT *value); }
#define glProgramUniform4ui64vNV DynamicGL_ProgramUniform4ui64vNV
extern bool DinamicGLFeature_NV_gpu_shader5_Supported();
#endif /*USE_DYNAMIC_GL_NV_gpu_shader5*/

/*NV_light_max_exponent*/
#ifdef USE_DYNAMIC_GL_NV_light_max_exponent
#define GL_MAX_SHININESS_NV 0x8504
#define GL_MAX_SPOT_EXPONENT_NV 0x8505
extern bool DinamicGLFeature_NV_light_max_exponent_Supported();
#endif /*USE_DYNAMIC_GL_NV_light_max_exponent*/

/*EXT_texture_swizzle*/
#ifdef USE_DYNAMIC_GL_EXT_texture_swizzle
#define GL_TEXTURE_SWIZZLE_R_EXT 0x8E42
#define GL_TEXTURE_SWIZZLE_G_EXT 0x8E43
#define GL_TEXTURE_SWIZZLE_B_EXT 0x8E44
#define GL_TEXTURE_SWIZZLE_A_EXT 0x8E45
#define GL_TEXTURE_SWIZZLE_RGBA_EXT 0x8E46
extern bool DinamicGLFeature_EXT_texture_swizzle_Supported();
#endif /*USE_DYNAMIC_GL_EXT_texture_swizzle*/

/*INGR_interlace_read*/
#ifdef USE_DYNAMIC_GL_INGR_interlace_read
#define GL_INTERLACE_READ_INGR 0x8568
extern bool DinamicGLFeature_INGR_interlace_read_Supported();
#endif /*USE_DYNAMIC_GL_INGR_interlace_read*/

/*ATI_pn_triangles*/
#ifdef USE_DYNAMIC_GL_ATI_pn_triangles
#define GL_PN_TRIANGLES_ATI 0x87F0
#define GL_MAX_PN_TRIANGLES_TESSELATION_LEVEL_ATI 0x87F1
#define GL_PN_TRIANGLES_POINT_MODE_ATI 0x87F2
#define GL_PN_TRIANGLES_NORMAL_MODE_ATI 0x87F3
#define GL_PN_TRIANGLES_TESSELATION_LEVEL_ATI 0x87F4
#define GL_PN_TRIANGLES_POINT_MODE_LINEAR_ATI 0x87F5
#define GL_PN_TRIANGLES_POINT_MODE_CUBIC_ATI 0x87F6
#define GL_PN_TRIANGLES_NORMAL_MODE_LINEAR_ATI 0x87F7
#define GL_PN_TRIANGLES_NORMAL_MODE_QUADRATIC_ATI 0x87F8
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PNTrianglesiATI)(GLenum pname , GLint param); }
#define glPNTrianglesiATI DynamicGL_PNTrianglesiATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PNTrianglesfATI)(GLenum pname , GLfloat param); }
#define glPNTrianglesfATI DynamicGL_PNTrianglesfATI
extern bool DinamicGLFeature_ATI_pn_triangles_Supported();
#endif /*USE_DYNAMIC_GL_ATI_pn_triangles*/

/*AMD_draw_buffers_blend*/
#ifdef USE_DYNAMIC_GL_AMD_draw_buffers_blend
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendFuncIndexedAMD)(GLuint buf , GLenum src , GLenum dst); }
#define glBlendFuncIndexedAMD DynamicGL_BlendFuncIndexedAMD
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendFuncSeparateIndexedAMD)(GLuint buf , GLenum srcRGB , GLenum dstRGB , GLenum srcAlpha , GLenum dstAlpha); }
#define glBlendFuncSeparateIndexedAMD DynamicGL_BlendFuncSeparateIndexedAMD
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendEquationIndexedAMD)(GLuint buf , GLenum mode); }
#define glBlendEquationIndexedAMD DynamicGL_BlendEquationIndexedAMD
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendEquationSeparateIndexedAMD)(GLuint buf , GLenum modeRGB , GLenum modeAlpha); }
#define glBlendEquationSeparateIndexedAMD DynamicGL_BlendEquationSeparateIndexedAMD
extern bool DinamicGLFeature_AMD_draw_buffers_blend_Supported();
#endif /*USE_DYNAMIC_GL_AMD_draw_buffers_blend*/

/*APPLE_ycbcr_422*/
#ifdef USE_DYNAMIC_GL_APPLE_ycbcr_422
#define GL_YCBCR_422_APPLE 0x85B9
#define GL_UNSIGNED_SHORT_8_8_APPLE 0x85BA
#define GL_UNSIGNED_SHORT_8_8_REV_APPLE 0x85BB
extern bool DinamicGLFeature_APPLE_ycbcr_422_Supported();
#endif /*USE_DYNAMIC_GL_APPLE_ycbcr_422*/

/*3DFX_tbuffer*/
#ifdef USE_DYNAMIC_GL_3DFX_tbuffer
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TbufferMask3DFX)(GLuint mask); }
#define glTbufferMask3DFX DynamicGL_TbufferMask3DFX
extern bool DinamicGLFeature_3DFX_tbuffer_Supported();
#endif /*USE_DYNAMIC_GL_3DFX_tbuffer*/

/*NV_texture_expand_normal*/
#ifdef USE_DYNAMIC_GL_NV_texture_expand_normal
#define GL_TEXTURE_UNSIGNED_REMAP_MODE_NV 0x888F
extern bool DinamicGLFeature_NV_texture_expand_normal_Supported();
#endif /*USE_DYNAMIC_GL_NV_texture_expand_normal*/

/*ARB_texture_float*/
#ifdef USE_DYNAMIC_GL_ARB_texture_float
#define GL_TEXTURE_RED_TYPE_ARB 0x8C10
#define GL_TEXTURE_GREEN_TYPE_ARB 0x8C11
#define GL_TEXTURE_BLUE_TYPE_ARB 0x8C12
#define GL_TEXTURE_ALPHA_TYPE_ARB 0x8C13
#define GL_TEXTURE_LUMINANCE_TYPE_ARB 0x8C14
#define GL_TEXTURE_INTENSITY_TYPE_ARB 0x8C15
#define GL_TEXTURE_DEPTH_TYPE_ARB 0x8C16
#define GL_UNSIGNED_NORMALIZED_ARB 0x8C17
#define GL_RGBA32F_ARB 0x8814
#define GL_RGB32F_ARB 0x8815
#define GL_ALPHA32F_ARB 0x8816
#define GL_INTENSITY32F_ARB 0x8817
#define GL_LUMINANCE32F_ARB 0x8818
#define GL_LUMINANCE_ALPHA32F_ARB 0x8819
#define GL_RGBA16F_ARB 0x881A
#define GL_RGB16F_ARB 0x881B
#define GL_ALPHA16F_ARB 0x881C
#define GL_INTENSITY16F_ARB 0x881D
#define GL_LUMINANCE16F_ARB 0x881E
#define GL_LUMINANCE_ALPHA16F_ARB 0x881F
extern bool DinamicGLFeature_ARB_texture_float_Supported();
#endif /*USE_DYNAMIC_GL_ARB_texture_float*/

/*REND_screen_coordinates*/
#ifdef USE_DYNAMIC_GL_REND_screen_coordinates
#define GL_SCREEN_COORDINATES_REND 0x8490
#define GL_INVERTED_SCREEN_W_REND 0x8491
extern bool DinamicGLFeature_REND_screen_coordinates_Supported();
#endif /*USE_DYNAMIC_GL_REND_screen_coordinates*/

/*NV_vertex_buffer_unified_memory*/
#ifdef USE_DYNAMIC_GL_NV_vertex_buffer_unified_memory
#define GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV 0x8F1E
#define GL_ELEMENT_ARRAY_UNIFIED_NV 0x8F1F
#define GL_VERTEX_ATTRIB_ARRAY_ADDRESS_NV 0x8F20
#define GL_VERTEX_ARRAY_ADDRESS_NV 0x8F21
#define GL_NORMAL_ARRAY_ADDRESS_NV 0x8F22
#define GL_COLOR_ARRAY_ADDRESS_NV 0x8F23
#define GL_INDEX_ARRAY_ADDRESS_NV 0x8F24
#define GL_TEXTURE_COORD_ARRAY_ADDRESS_NV 0x8F25
#define GL_EDGE_FLAG_ARRAY_ADDRESS_NV 0x8F26
#define GL_SECONDARY_COLOR_ARRAY_ADDRESS_NV 0x8F27
#define GL_FOG_COORD_ARRAY_ADDRESS_NV 0x8F28
#define GL_ELEMENT_ARRAY_ADDRESS_NV 0x8F29
#define GL_VERTEX_ATTRIB_ARRAY_LENGTH_NV 0x8F2A
#define GL_VERTEX_ARRAY_LENGTH_NV 0x8F2B
#define GL_NORMAL_ARRAY_LENGTH_NV 0x8F2C
#define GL_COLOR_ARRAY_LENGTH_NV 0x8F2D
#define GL_INDEX_ARRAY_LENGTH_NV 0x8F2E
#define GL_TEXTURE_COORD_ARRAY_LENGTH_NV 0x8F2F
#define GL_EDGE_FLAG_ARRAY_LENGTH_NV 0x8F30
#define GL_SECONDARY_COLOR_ARRAY_LENGTH_NV 0x8F31
#define GL_FOG_COORD_ARRAY_LENGTH_NV 0x8F32
#define GL_ELEMENT_ARRAY_LENGTH_NV 0x8F33
#define GL_DRAW_INDIRECT_UNIFIED_NV 0x8F40
#define GL_DRAW_INDIRECT_ADDRESS_NV 0x8F41
#define GL_DRAW_INDIRECT_LENGTH_NV 0x8F42
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BufferAddressRangeNV)(GLenum pname , GLuint index , GLuint64EXT address , GLsizeiptr length); }
#define glBufferAddressRangeNV DynamicGL_BufferAddressRangeNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexFormatNV)(GLint size , GLenum type , GLsizei stride); }
#define glVertexFormatNV DynamicGL_VertexFormatNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NormalFormatNV)(GLenum type , GLsizei stride); }
#define glNormalFormatNV DynamicGL_NormalFormatNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorFormatNV)(GLint size , GLenum type , GLsizei stride); }
#define glColorFormatNV DynamicGL_ColorFormatNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_IndexFormatNV)(GLenum type , GLsizei stride); }
#define glIndexFormatNV DynamicGL_IndexFormatNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoordFormatNV)(GLint size , GLenum type , GLsizei stride); }
#define glTexCoordFormatNV DynamicGL_TexCoordFormatNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EdgeFlagFormatNV)(GLsizei stride); }
#define glEdgeFlagFormatNV DynamicGL_EdgeFlagFormatNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColorFormatNV)(GLint size , GLenum type , GLsizei stride); }
#define glSecondaryColorFormatNV DynamicGL_SecondaryColorFormatNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FogCoordFormatNV)(GLenum type , GLsizei stride); }
#define glFogCoordFormatNV DynamicGL_FogCoordFormatNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribFormatNV)(GLuint index , GLint size , GLenum type , GLboolean normalized , GLsizei stride); }
#define glVertexAttribFormatNV DynamicGL_VertexAttribFormatNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribIFormatNV)(GLuint index , GLint size , GLenum type , GLsizei stride); }
#define glVertexAttribIFormatNV DynamicGL_VertexAttribIFormatNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetIntegerui64i_vNV)(GLenum value , GLuint index , GLuint64EXT *result); }
#define glGetIntegerui64i_vNV DynamicGL_GetIntegerui64i_vNV
extern bool DinamicGLFeature_NV_vertex_buffer_unified_memory_Supported();
#endif /*USE_DYNAMIC_GL_NV_vertex_buffer_unified_memory*/

/*EXT_framebuffer_sRGB*/
#ifdef USE_DYNAMIC_GL_EXT_framebuffer_sRGB
#define GL_FRAMEBUFFER_SRGB_EXT 0x8DB9
#define GL_FRAMEBUFFER_SRGB_CAPABLE_EXT 0x8DBA
extern bool DinamicGLFeature_EXT_framebuffer_sRGB_Supported();
#endif /*USE_DYNAMIC_GL_EXT_framebuffer_sRGB*/

/*AMD_stencil_operation_extended*/
#ifdef USE_DYNAMIC_GL_AMD_stencil_operation_extended
#define GL_SET_AMD 0x874A
#define GL_REPLACE_VALUE_AMD 0x874B
#define GL_STENCIL_OP_VALUE_AMD 0x874C
#define GL_STENCIL_BACK_OP_VALUE_AMD 0x874D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_StencilOpValueAMD)(GLenum face , GLuint value); }
#define glStencilOpValueAMD DynamicGL_StencilOpValueAMD
extern bool DinamicGLFeature_AMD_stencil_operation_extended_Supported();
#endif /*USE_DYNAMIC_GL_AMD_stencil_operation_extended*/

/*SGIX_texture_multi_buffer*/
#ifdef USE_DYNAMIC_GL_SGIX_texture_multi_buffer
#define GL_TEXTURE_MULTI_BUFFER_HINT_SGIX 0x812E
extern bool DinamicGLFeature_SGIX_texture_multi_buffer_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_texture_multi_buffer*/

/*ARB_imaging*/
#ifdef USE_DYNAMIC_GL_ARB_imaging
#define GL_CONSTANT_COLOR 0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR 0x8002
#define GL_CONSTANT_ALPHA 0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA 0x8004
#define GL_BLEND_COLOR 0x8005
#define GL_FUNC_ADD 0x8006
#define GL_MIN 0x8007
#define GL_MAX 0x8008
#define GL_BLEND_EQUATION 0x8009
#define GL_FUNC_SUBTRACT 0x800A
#define GL_FUNC_REVERSE_SUBTRACT 0x800B
extern bool DinamicGLFeature_ARB_imaging_Supported();
#endif /*USE_DYNAMIC_GL_ARB_imaging*/

/*EXT_index_func*/
#ifdef USE_DYNAMIC_GL_EXT_index_func
#define GL_INDEX_TEST_EXT 0x81B5
#define GL_INDEX_TEST_FUNC_EXT 0x81B6
#define GL_INDEX_TEST_REF_EXT 0x81B7
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_IndexFuncEXT)(GLenum func , GLclampf ref); }
#define glIndexFuncEXT DynamicGL_IndexFuncEXT
extern bool DinamicGLFeature_EXT_index_func_Supported();
#endif /*USE_DYNAMIC_GL_EXT_index_func*/

/*NV_gpu_program5*/
#ifdef USE_DYNAMIC_GL_NV_gpu_program5
#define GL_MAX_GEOMETRY_PROGRAM_INVOCATIONS_NV 0x8E5A
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET_NV 0x8E5B
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET_NV 0x8E5C
#define GL_FRAGMENT_PROGRAM_INTERPOLATION_OFFSET_BITS_NV 0x8E5D
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_NV 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_NV 0x8E5F
#define GL_MAX_PROGRAM_SUBROUTINE_PARAMETERS_NV 0x8F44
#define GL_MAX_PROGRAM_SUBROUTINE_NUM_NV 0x8F45
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramSubroutineParametersuivNV)(GLenum target , GLsizei count , const GLuint *params); }
#define glProgramSubroutineParametersuivNV DynamicGL_ProgramSubroutineParametersuivNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramSubroutineParameteruivNV)(GLenum target , GLuint index , GLuint *param); }
#define glGetProgramSubroutineParameteruivNV DynamicGL_GetProgramSubroutineParameteruivNV
extern bool DinamicGLFeature_NV_gpu_program5_Supported();
#endif /*USE_DYNAMIC_GL_NV_gpu_program5*/

/*NV_multisample_filter_hint*/
#ifdef USE_DYNAMIC_GL_NV_multisample_filter_hint
#define GL_MULTISAMPLE_FILTER_HINT_NV 0x8534
extern bool DinamicGLFeature_NV_multisample_filter_hint_Supported();
#endif /*USE_DYNAMIC_GL_NV_multisample_filter_hint*/

/*SGIX_framezoom*/
#ifdef USE_DYNAMIC_GL_SGIX_framezoom
#define GL_FRAMEZOOM_SGIX 0x818B
#define GL_FRAMEZOOM_FACTOR_SGIX 0x818C
#define GL_MAX_FRAMEZOOM_FACTOR_SGIX 0x818D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FrameZoomSGIX)(GLint factor); }
#define glFrameZoomSGIX DynamicGL_FrameZoomSGIX
extern bool DinamicGLFeature_SGIX_framezoom_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_framezoom*/

/*SUNX_constant_data*/
#ifdef USE_DYNAMIC_GL_SUNX_constant_data
#define GL_UNPACK_CONSTANT_DATA_SUNX 0x81D5
#define GL_TEXTURE_CONSTANT_DATA_SUNX 0x81D6
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FinishTextureSUNX)(); }
#define glFinishTextureSUNX DynamicGL_FinishTextureSUNX
extern bool DinamicGLFeature_SUNX_constant_data_Supported();
#endif /*USE_DYNAMIC_GL_SUNX_constant_data*/

/*HP_occlusion_test*/
#ifdef USE_DYNAMIC_GL_HP_occlusion_test
#define GL_OCCLUSION_TEST_HP 0x8165
#define GL_OCCLUSION_TEST_RESULT_HP 0x8166
extern bool DinamicGLFeature_HP_occlusion_test_Supported();
#endif /*USE_DYNAMIC_GL_HP_occlusion_test*/

/*SGIX_interlace*/
#ifdef USE_DYNAMIC_GL_SGIX_interlace
#define GL_INTERLACE_SGIX 0x8094
extern bool DinamicGLFeature_SGIX_interlace_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_interlace*/

/*ATI_pixel_format_float*/
#ifdef USE_DYNAMIC_GL_ATI_pixel_format_float
#define GL_TYPE_RGBA_FLOAT_ATI 0x8820
#define GL_COLOR_CLEAR_UNCLAMPED_VALUE_ATI 0x8835
extern bool DinamicGLFeature_ATI_pixel_format_float_Supported();
#endif /*USE_DYNAMIC_GL_ATI_pixel_format_float*/

/*NV_gpu_program4*/
#ifdef USE_DYNAMIC_GL_NV_gpu_program4
#define GL_MIN_PROGRAM_TEXEL_OFFSET_NV 0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET_NV 0x8905
#define GL_PROGRAM_ATTRIB_COMPONENTS_NV 0x8906
#define GL_PROGRAM_RESULT_COMPONENTS_NV 0x8907
#define GL_MAX_PROGRAM_ATTRIB_COMPONENTS_NV 0x8908
#define GL_MAX_PROGRAM_RESULT_COMPONENTS_NV 0x8909
#define GL_MAX_PROGRAM_GENERIC_ATTRIBS_NV 0x8DA5
#define GL_MAX_PROGRAM_GENERIC_RESULTS_NV 0x8DA6
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramLocalParameterI4iNV)(GLenum target , GLuint index , GLint x , GLint y , GLint z , GLint w); }
#define glProgramLocalParameterI4iNV DynamicGL_ProgramLocalParameterI4iNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramLocalParameterI4ivNV)(GLenum target , GLuint index , const GLint *params); }
#define glProgramLocalParameterI4ivNV DynamicGL_ProgramLocalParameterI4ivNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramLocalParametersI4ivNV)(GLenum target , GLuint index , GLsizei count , const GLint *params); }
#define glProgramLocalParametersI4ivNV DynamicGL_ProgramLocalParametersI4ivNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramLocalParameterI4uiNV)(GLenum target , GLuint index , GLuint x , GLuint y , GLuint z , GLuint w); }
#define glProgramLocalParameterI4uiNV DynamicGL_ProgramLocalParameterI4uiNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramLocalParameterI4uivNV)(GLenum target , GLuint index , const GLuint *params); }
#define glProgramLocalParameterI4uivNV DynamicGL_ProgramLocalParameterI4uivNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramLocalParametersI4uivNV)(GLenum target , GLuint index , GLsizei count , const GLuint *params); }
#define glProgramLocalParametersI4uivNV DynamicGL_ProgramLocalParametersI4uivNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramEnvParameterI4iNV)(GLenum target , GLuint index , GLint x , GLint y , GLint z , GLint w); }
#define glProgramEnvParameterI4iNV DynamicGL_ProgramEnvParameterI4iNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramEnvParameterI4ivNV)(GLenum target , GLuint index , const GLint *params); }
#define glProgramEnvParameterI4ivNV DynamicGL_ProgramEnvParameterI4ivNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramEnvParametersI4ivNV)(GLenum target , GLuint index , GLsizei count , const GLint *params); }
#define glProgramEnvParametersI4ivNV DynamicGL_ProgramEnvParametersI4ivNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramEnvParameterI4uiNV)(GLenum target , GLuint index , GLuint x , GLuint y , GLuint z , GLuint w); }
#define glProgramEnvParameterI4uiNV DynamicGL_ProgramEnvParameterI4uiNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramEnvParameterI4uivNV)(GLenum target , GLuint index , const GLuint *params); }
#define glProgramEnvParameterI4uivNV DynamicGL_ProgramEnvParameterI4uivNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramEnvParametersI4uivNV)(GLenum target , GLuint index , GLsizei count , const GLuint *params); }
#define glProgramEnvParametersI4uivNV DynamicGL_ProgramEnvParametersI4uivNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramLocalParameterIivNV)(GLenum target , GLuint index , GLint *params); }
#define glGetProgramLocalParameterIivNV DynamicGL_GetProgramLocalParameterIivNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramLocalParameterIuivNV)(GLenum target , GLuint index , GLuint *params); }
#define glGetProgramLocalParameterIuivNV DynamicGL_GetProgramLocalParameterIuivNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramEnvParameterIivNV)(GLenum target , GLuint index , GLint *params); }
#define glGetProgramEnvParameterIivNV DynamicGL_GetProgramEnvParameterIivNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramEnvParameterIuivNV)(GLenum target , GLuint index , GLuint *params); }
#define glGetProgramEnvParameterIuivNV DynamicGL_GetProgramEnvParameterIuivNV
extern bool DinamicGLFeature_NV_gpu_program4_Supported();
#endif /*USE_DYNAMIC_GL_NV_gpu_program4*/

/*ARB_point_sprite*/
#ifdef USE_DYNAMIC_GL_ARB_point_sprite
#define GL_POINT_SPRITE_ARB 0x8861
#define GL_COORD_REPLACE_ARB 0x8862
extern bool DinamicGLFeature_ARB_point_sprite_Supported();
#endif /*USE_DYNAMIC_GL_ARB_point_sprite*/

/*ARB_transform_feedback3*/
#ifdef USE_DYNAMIC_GL_ARB_transform_feedback3
#define GL_MAX_TRANSFORM_FEEDBACK_BUFFERS 0x8E70
#define GL_MAX_VERTEX_STREAMS 0x8E71
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawTransformFeedbackStream)(GLenum mode , GLuint id , GLuint stream); }
#define glDrawTransformFeedbackStream DynamicGL_DrawTransformFeedbackStream
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BeginQueryIndexed)(GLenum target , GLuint index , GLuint id); }
#define glBeginQueryIndexed DynamicGL_BeginQueryIndexed
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EndQueryIndexed)(GLenum target , GLuint index); }
#define glEndQueryIndexed DynamicGL_EndQueryIndexed
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetQueryIndexediv)(GLenum target , GLuint index , GLenum pname , GLint *params); }
#define glGetQueryIndexediv DynamicGL_GetQueryIndexediv
extern bool DinamicGLFeature_ARB_transform_feedback3_Supported();
#endif /*USE_DYNAMIC_GL_ARB_transform_feedback3*/

/*AMD_multi_draw_indirect*/
#ifdef USE_DYNAMIC_GL_AMD_multi_draw_indirect
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiDrawArraysIndirectAMD)(GLenum mode , const GLvoid *indirect , GLsizei primcount , GLsizei stride); }
#define glMultiDrawArraysIndirectAMD DynamicGL_MultiDrawArraysIndirectAMD
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiDrawElementsIndirectAMD)(GLenum mode , GLenum type , const GLvoid *indirect , GLsizei primcount , GLsizei stride); }
#define glMultiDrawElementsIndirectAMD DynamicGL_MultiDrawElementsIndirectAMD
extern bool DinamicGLFeature_AMD_multi_draw_indirect_Supported();
#endif /*USE_DYNAMIC_GL_AMD_multi_draw_indirect*/

/*SUN_mesh_array*/
#ifdef USE_DYNAMIC_GL_SUN_mesh_array
#define GL_QUAD_MESH_SUN 0x8614
#define GL_TRIANGLE_MESH_SUN 0x8615
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawMeshArraysSUN)(GLenum mode , GLint first , GLsizei count , GLsizei width); }
#define glDrawMeshArraysSUN DynamicGL_DrawMeshArraysSUN
extern bool DinamicGLFeature_SUN_mesh_array_Supported();
#endif /*USE_DYNAMIC_GL_SUN_mesh_array*/

/*NV_framebuffer_multisample_coverage*/
#ifdef USE_DYNAMIC_GL_NV_framebuffer_multisample_coverage
#define GL_RENDERBUFFER_COVERAGE_SAMPLES_NV 0x8CAB
#define GL_RENDERBUFFER_COLOR_SAMPLES_NV 0x8E10
#define GL_MAX_MULTISAMPLE_COVERAGE_MODES_NV 0x8E11
#define GL_MULTISAMPLE_COVERAGE_MODES_NV 0x8E12
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RenderbufferStorageMultisampleCoverageNV)(GLenum target , GLsizei coverageSamples , GLsizei colorSamples , GLenum internalformat , GLsizei width , GLsizei height); }
#define glRenderbufferStorageMultisampleCoverageNV DynamicGL_RenderbufferStorageMultisampleCoverageNV
extern bool DinamicGLFeature_NV_framebuffer_multisample_coverage_Supported();
#endif /*USE_DYNAMIC_GL_NV_framebuffer_multisample_coverage*/

/*ARB_timer_query*/
#ifdef USE_DYNAMIC_GL_ARB_timer_query
#define GL_TIME_ELAPSED 0x88BF
#define GL_TIMESTAMP 0x8E28
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_QueryCounter)(GLuint id , GLenum target); }
#define glQueryCounter DynamicGL_QueryCounter
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetQueryObjecti64v)(GLuint id , GLenum pname , GLint64 *params); }
#define glGetQueryObjecti64v DynamicGL_GetQueryObjecti64v
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetQueryObjectui64v)(GLuint id , GLenum pname , GLuint64 *params); }
#define glGetQueryObjectui64v DynamicGL_GetQueryObjectui64v
extern bool DinamicGLFeature_ARB_timer_query_Supported();
#endif /*USE_DYNAMIC_GL_ARB_timer_query*/

/*NV_texgen_emboss*/
#ifdef USE_DYNAMIC_GL_NV_texgen_emboss
#define GL_EMBOSS_LIGHT_NV 0x855D
#define GL_EMBOSS_CONSTANT_NV 0x855E
#define GL_EMBOSS_MAP_NV 0x855F
extern bool DinamicGLFeature_NV_texgen_emboss_Supported();
#endif /*USE_DYNAMIC_GL_NV_texgen_emboss*/

/*EXT_separate_specular_color*/
#ifdef USE_DYNAMIC_GL_EXT_separate_specular_color
#define GL_LIGHT_MODEL_COLOR_CONTROL_EXT 0x81F8
#define GL_SINGLE_COLOR_EXT 0x81F9
#define GL_SEPARATE_SPECULAR_COLOR_EXT 0x81FA
extern bool DinamicGLFeature_EXT_separate_specular_color_Supported();
#endif /*USE_DYNAMIC_GL_EXT_separate_specular_color*/

/*ARB_framebuffer_object_DEPRECATED*/
#ifdef USE_DYNAMIC_GL_ARB_framebuffer_object_DEPRECATED
#define GL_INDEX 0x8222
#define GL_TEXTURE_LUMINANCE_TYPE 0x8C14
#define GL_TEXTURE_INTENSITY_TYPE 0x8C15
extern bool DinamicGLFeature_ARB_framebuffer_object_DEPRECATED_Supported();
#endif /*USE_DYNAMIC_GL_ARB_framebuffer_object_DEPRECATED*/

/*ARB_shader_atomic_counters*/
#ifdef USE_DYNAMIC_GL_ARB_shader_atomic_counters
#define GL_ATOMIC_COUNTER_BUFFER 0x92C0
#define GL_ATOMIC_COUNTER_BUFFER_BINDING 0x92C1
#define GL_ATOMIC_COUNTER_BUFFER_START 0x92C2
#define GL_ATOMIC_COUNTER_BUFFER_SIZE 0x92C3
#define GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE 0x92C4
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS 0x92C5
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES 0x92C6
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER 0x92C7
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER 0x92C8
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER 0x92C9
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER 0x92CA
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER 0x92CB
#define GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS 0x92CC
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS 0x92CD
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS 0x92CE
#define GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS 0x92CF
#define GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS 0x92D0
#define GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS 0x92D1
#define GL_MAX_VERTEX_ATOMIC_COUNTERS 0x92D2
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS 0x92D3
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS 0x92D4
#define GL_MAX_GEOMETRY_ATOMIC_COUNTERS 0x92D5
#define GL_MAX_FRAGMENT_ATOMIC_COUNTERS 0x92D6
#define GL_MAX_COMBINED_ATOMIC_COUNTERS 0x92D7
#define GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE 0x92D8
#define GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS 0x92DC
#define GL_ACTIVE_ATOMIC_COUNTER_BUFFERS 0x92D9
#define GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX 0x92DA
#define GL_UNSIGNED_INT_ATOMIC_COUNTER 0x92DB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetActiveAtomicCounterBufferiv)(GLuint program , GLuint bufferIndex , GLenum pname , GLint *params); }
#define glGetActiveAtomicCounterBufferiv DynamicGL_GetActiveAtomicCounterBufferiv
extern bool DinamicGLFeature_ARB_shader_atomic_counters_Supported();
#endif /*USE_DYNAMIC_GL_ARB_shader_atomic_counters*/

/*EXT_blend_subtract*/
#ifdef USE_DYNAMIC_GL_EXT_blend_subtract
#define GL_FUNC_SUBTRACT_EXT 0x800A
#define GL_FUNC_REVERSE_SUBTRACT_EXT 0x800B
extern bool DinamicGLFeature_EXT_blend_subtract_Supported();
#endif /*USE_DYNAMIC_GL_EXT_blend_subtract*/

/*SGIX_texture_scale_bias*/
#ifdef USE_DYNAMIC_GL_SGIX_texture_scale_bias
#define GL_POST_TEXTURE_FILTER_BIAS_SGIX 0x8179
#define GL_POST_TEXTURE_FILTER_SCALE_SGIX 0x817A
#define GL_POST_TEXTURE_FILTER_BIAS_RANGE_SGIX 0x817B
#define GL_POST_TEXTURE_FILTER_SCALE_RANGE_SGIX 0x817C
extern bool DinamicGLFeature_SGIX_texture_scale_bias_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_texture_scale_bias*/

/*APPLE_vertex_array_object*/
#ifdef USE_DYNAMIC_GL_APPLE_vertex_array_object
#define GL_VERTEX_ARRAY_BINDING_APPLE 0x85B5
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindVertexArrayAPPLE)(GLuint array); }
#define glBindVertexArrayAPPLE DynamicGL_BindVertexArrayAPPLE
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteVertexArraysAPPLE)(GLsizei n , const GLuint *arrays); }
#define glDeleteVertexArraysAPPLE DynamicGL_DeleteVertexArraysAPPLE
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GenVertexArraysAPPLE)(GLsizei n , GLuint *arrays); }
#define glGenVertexArraysAPPLE DynamicGL_GenVertexArraysAPPLE
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsVertexArrayAPPLE)(GLuint array); }
#define glIsVertexArrayAPPLE DynamicGL_IsVertexArrayAPPLE
extern bool DinamicGLFeature_APPLE_vertex_array_object_Supported();
#endif /*USE_DYNAMIC_GL_APPLE_vertex_array_object*/

/*EXT_copy_texture*/
#ifdef USE_DYNAMIC_GL_EXT_copy_texture
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyTexImage1DEXT)(GLenum target , GLint level , GLenum internalformat , GLint x , GLint y , GLsizei width , GLint border); }
#define glCopyTexImage1DEXT DynamicGL_CopyTexImage1DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyTexImage2DEXT)(GLenum target , GLint level , GLenum internalformat , GLint x , GLint y , GLsizei width , GLsizei height , GLint border); }
#define glCopyTexImage2DEXT DynamicGL_CopyTexImage2DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyTexSubImage1DEXT)(GLenum target , GLint level , GLint xoffset , GLint x , GLint y , GLsizei width); }
#define glCopyTexSubImage1DEXT DynamicGL_CopyTexSubImage1DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyTexSubImage2DEXT)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint x , GLint y , GLsizei width , GLsizei height); }
#define glCopyTexSubImage2DEXT DynamicGL_CopyTexSubImage2DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyTexSubImage3DEXT)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLint x , GLint y , GLsizei width , GLsizei height); }
#define glCopyTexSubImage3DEXT DynamicGL_CopyTexSubImage3DEXT
extern bool DinamicGLFeature_EXT_copy_texture_Supported();
#endif /*USE_DYNAMIC_GL_EXT_copy_texture*/

/*EXT_texture_cube_map*/
#ifdef USE_DYNAMIC_GL_EXT_texture_cube_map
#define GL_NORMAL_MAP_EXT 0x8511
#define GL_REFLECTION_MAP_EXT 0x8512
#define GL_TEXTURE_CUBE_MAP_EXT 0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP_EXT 0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_EXT 0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_EXT 0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_EXT 0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_EXT 0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_EXT 0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_EXT 0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP_EXT 0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE_EXT 0x851C
extern bool DinamicGLFeature_EXT_texture_cube_map_Supported();
#endif /*USE_DYNAMIC_GL_EXT_texture_cube_map*/

/*EXT_coordinate_frame*/
#ifdef USE_DYNAMIC_GL_EXT_coordinate_frame
#define GL_TANGENT_ARRAY_EXT 0x8439
#define GL_BINORMAL_ARRAY_EXT 0x843A
#define GL_CURRENT_TANGENT_EXT 0x843B
#define GL_CURRENT_BINORMAL_EXT 0x843C
#define GL_TANGENT_ARRAY_TYPE_EXT 0x843E
#define GL_TANGENT_ARRAY_STRIDE_EXT 0x843F
#define GL_BINORMAL_ARRAY_TYPE_EXT 0x8440
#define GL_BINORMAL_ARRAY_STRIDE_EXT 0x8441
#define GL_TANGENT_ARRAY_POINTER_EXT 0x8442
#define GL_BINORMAL_ARRAY_POINTER_EXT 0x8443
#define GL_MAP1_TANGENT_EXT 0x8444
#define GL_MAP2_TANGENT_EXT 0x8445
#define GL_MAP1_BINORMAL_EXT 0x8446
#define GL_MAP2_BINORMAL_EXT 0x8447
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Tangent3bEXT)(GLbyte tx , GLbyte ty , GLbyte tz); }
#define glTangent3bEXT DynamicGL_Tangent3bEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Tangent3bvEXT)(const GLbyte *v); }
#define glTangent3bvEXT DynamicGL_Tangent3bvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Tangent3dEXT)(GLdouble tx , GLdouble ty , GLdouble tz); }
#define glTangent3dEXT DynamicGL_Tangent3dEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Tangent3dvEXT)(const GLdouble *v); }
#define glTangent3dvEXT DynamicGL_Tangent3dvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Tangent3fEXT)(GLfloat tx , GLfloat ty , GLfloat tz); }
#define glTangent3fEXT DynamicGL_Tangent3fEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Tangent3fvEXT)(const GLfloat *v); }
#define glTangent3fvEXT DynamicGL_Tangent3fvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Tangent3iEXT)(GLint tx , GLint ty , GLint tz); }
#define glTangent3iEXT DynamicGL_Tangent3iEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Tangent3ivEXT)(const GLint *v); }
#define glTangent3ivEXT DynamicGL_Tangent3ivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Tangent3sEXT)(GLshort tx , GLshort ty , GLshort tz); }
#define glTangent3sEXT DynamicGL_Tangent3sEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Tangent3svEXT)(const GLshort *v); }
#define glTangent3svEXT DynamicGL_Tangent3svEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Binormal3bEXT)(GLbyte bx , GLbyte by , GLbyte bz); }
#define glBinormal3bEXT DynamicGL_Binormal3bEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Binormal3bvEXT)(const GLbyte *v); }
#define glBinormal3bvEXT DynamicGL_Binormal3bvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Binormal3dEXT)(GLdouble bx , GLdouble by , GLdouble bz); }
#define glBinormal3dEXT DynamicGL_Binormal3dEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Binormal3dvEXT)(const GLdouble *v); }
#define glBinormal3dvEXT DynamicGL_Binormal3dvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Binormal3fEXT)(GLfloat bx , GLfloat by , GLfloat bz); }
#define glBinormal3fEXT DynamicGL_Binormal3fEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Binormal3fvEXT)(const GLfloat *v); }
#define glBinormal3fvEXT DynamicGL_Binormal3fvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Binormal3iEXT)(GLint bx , GLint by , GLint bz); }
#define glBinormal3iEXT DynamicGL_Binormal3iEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Binormal3ivEXT)(const GLint *v); }
#define glBinormal3ivEXT DynamicGL_Binormal3ivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Binormal3sEXT)(GLshort bx , GLshort by , GLshort bz); }
#define glBinormal3sEXT DynamicGL_Binormal3sEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Binormal3svEXT)(const GLshort *v); }
#define glBinormal3svEXT DynamicGL_Binormal3svEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TangentPointerEXT)(GLenum type , GLsizei stride , const GLvoid *pointer); }
#define glTangentPointerEXT DynamicGL_TangentPointerEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BinormalPointerEXT)(GLenum type , GLsizei stride , const GLvoid *pointer); }
#define glBinormalPointerEXT DynamicGL_BinormalPointerEXT
extern bool DinamicGLFeature_EXT_coordinate_frame_Supported();
#endif /*USE_DYNAMIC_GL_EXT_coordinate_frame*/

/*3DFX_multisample*/
#ifdef USE_DYNAMIC_GL_3DFX_multisample
#define GL_MULTISAMPLE_3DFX 0x86B2
#define GL_SAMPLE_BUFFERS_3DFX 0x86B3
#define GL_SAMPLES_3DFX 0x86B4
#define GL_MULTISAMPLE_BIT_3DFX 0x20000000
extern bool DinamicGLFeature_3DFX_multisample_Supported();
#endif /*USE_DYNAMIC_GL_3DFX_multisample*/

/*SGIX_ycrcb*/
#ifdef USE_DYNAMIC_GL_SGIX_ycrcb
#define GL_YCRCB_422_SGIX 0x81BB
#define GL_YCRCB_444_SGIX 0x81BC
extern bool DinamicGLFeature_SGIX_ycrcb_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_ycrcb*/

/*SGIX_async_histogram*/
#ifdef USE_DYNAMIC_GL_SGIX_async_histogram
#define GL_ASYNC_HISTOGRAM_SGIX 0x832C
#define GL_MAX_ASYNC_HISTOGRAM_SGIX 0x832D
extern bool DinamicGLFeature_SGIX_async_histogram_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_async_histogram*/

/*ARB_compressed_texture_pixel_storage*/
#ifdef USE_DYNAMIC_GL_ARB_compressed_texture_pixel_storage
#define GL_UNPACK_COMPRESSED_BLOCK_WIDTH 0x9127
#define GL_UNPACK_COMPRESSED_BLOCK_HEIGHT 0x9128
#define GL_UNPACK_COMPRESSED_BLOCK_DEPTH 0x9129
#define GL_UNPACK_COMPRESSED_BLOCK_SIZE 0x912A
#define GL_PACK_COMPRESSED_BLOCK_WIDTH 0x912B
#define GL_PACK_COMPRESSED_BLOCK_HEIGHT 0x912C
#define GL_PACK_COMPRESSED_BLOCK_DEPTH 0x912D
#define GL_PACK_COMPRESSED_BLOCK_SIZE 0x912E
extern bool DinamicGLFeature_ARB_compressed_texture_pixel_storage_Supported();
#endif /*USE_DYNAMIC_GL_ARB_compressed_texture_pixel_storage*/

/*SGIX_depth_texture*/
#ifdef USE_DYNAMIC_GL_SGIX_depth_texture
#define GL_DEPTH_COMPONENT16_SGIX 0x81A5
#define GL_DEPTH_COMPONENT24_SGIX 0x81A6
#define GL_DEPTH_COMPONENT32_SGIX 0x81A7
extern bool DinamicGLFeature_SGIX_depth_texture_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_depth_texture*/

/*EXT_stencil_two_side*/
#ifdef USE_DYNAMIC_GL_EXT_stencil_two_side
#define GL_STENCIL_TEST_TWO_SIDE_EXT 0x8910
#define GL_ACTIVE_STENCIL_FACE_EXT 0x8911
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ActiveStencilFaceEXT)(GLenum face); }
#define glActiveStencilFaceEXT DynamicGL_ActiveStencilFaceEXT
extern bool DinamicGLFeature_EXT_stencil_two_side_Supported();
#endif /*USE_DYNAMIC_GL_EXT_stencil_two_side*/

/*MESA_pack_invert*/
#ifdef USE_DYNAMIC_GL_MESA_pack_invert
#define GL_PACK_INVERT_MESA 0x8758
extern bool DinamicGLFeature_MESA_pack_invert_Supported();
#endif /*USE_DYNAMIC_GL_MESA_pack_invert*/

/*ARB_get_program_binary*/
#ifdef USE_DYNAMIC_GL_ARB_get_program_binary
#define GL_PROGRAM_BINARY_RETRIEVABLE_HINT 0x8257
#define GL_PROGRAM_BINARY_LENGTH 0x8741
#define GL_NUM_PROGRAM_BINARY_FORMATS 0x87FE
#define GL_PROGRAM_BINARY_FORMATS 0x87FF
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramBinary)(GLuint program , GLsizei bufSize , GLsizei *length , GLenum *binaryFormat , GLvoid *binary); }
#define glGetProgramBinary DynamicGL_GetProgramBinary
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramBinary)(GLuint program , GLenum binaryFormat , const GLvoid *binary , GLsizei length); }
#define glProgramBinary DynamicGL_ProgramBinary
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramParameteri)(GLuint program , GLenum pname , GLint value); }
#define glProgramParameteri DynamicGL_ProgramParameteri
extern bool DinamicGLFeature_ARB_get_program_binary_Supported();
#endif /*USE_DYNAMIC_GL_ARB_get_program_binary*/

/*EXT_framebuffer_multisample*/
#ifdef USE_DYNAMIC_GL_EXT_framebuffer_multisample
#define GL_RENDERBUFFER_SAMPLES_EXT 0x8CAB
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE_EXT 0x8D56
#define GL_MAX_SAMPLES_EXT 0x8D57
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_RenderbufferStorageMultisampleEXT)(GLenum target , GLsizei samples , GLenum internalformat , GLsizei width , GLsizei height); }
#define glRenderbufferStorageMultisampleEXT DynamicGL_RenderbufferStorageMultisampleEXT
extern bool DinamicGLFeature_EXT_framebuffer_multisample_Supported();
#endif /*USE_DYNAMIC_GL_EXT_framebuffer_multisample*/

/*ARB_seamless_cube_map*/
#ifdef USE_DYNAMIC_GL_ARB_seamless_cube_map
#define GL_TEXTURE_CUBE_MAP_SEAMLESS 0x884F
extern bool DinamicGLFeature_ARB_seamless_cube_map_Supported();
#endif /*USE_DYNAMIC_GL_ARB_seamless_cube_map*/

/*SGIX_texture_lod_bias*/
#ifdef USE_DYNAMIC_GL_SGIX_texture_lod_bias
#define GL_TEXTURE_LOD_BIAS_S_SGIX 0x818E
#define GL_TEXTURE_LOD_BIAS_T_SGIX 0x818F
#define GL_TEXTURE_LOD_BIAS_R_SGIX 0x8190
extern bool DinamicGLFeature_SGIX_texture_lod_bias_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_texture_lod_bias*/

/*AMD_vertex_shader_tesselator*/
#ifdef USE_DYNAMIC_GL_AMD_vertex_shader_tesselator
#define GL_SAMPLER_BUFFER_AMD 0x9001
#define GL_INT_SAMPLER_BUFFER_AMD 0x9002
#define GL_UNSIGNED_INT_SAMPLER_BUFFER_AMD 0x9003
#define GL_TESSELLATION_MODE_AMD 0x9004
#define GL_TESSELLATION_FACTOR_AMD 0x9005
#define GL_DISCRETE_AMD 0x9006
#define GL_CONTINUOUS_AMD 0x9007
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TessellationFactorAMD)(GLfloat factor); }
#define glTessellationFactorAMD DynamicGL_TessellationFactorAMD
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TessellationModeAMD)(GLenum mode); }
#define glTessellationModeAMD DynamicGL_TessellationModeAMD
extern bool DinamicGLFeature_AMD_vertex_shader_tesselator_Supported();
#endif /*USE_DYNAMIC_GL_AMD_vertex_shader_tesselator*/

/*EXT_texture_filter_anisotropic*/
#ifdef USE_DYNAMIC_GL_EXT_texture_filter_anisotropic
#define GL_TEXTURE_MAX_ANISOTROPY_EXT 0x84FE
#define GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT 0x84FF
extern bool DinamicGLFeature_EXT_texture_filter_anisotropic_Supported();
#endif /*USE_DYNAMIC_GL_EXT_texture_filter_anisotropic*/

/*VERSION_1_3_DEPRECATED*/
#ifdef USE_DYNAMIC_GL_VERSION_1_3_DEPRECATED
#define GL_CLIENT_ACTIVE_TEXTURE 0x84E1
#define GL_MAX_TEXTURE_UNITS 0x84E2
#define GL_TRANSPOSE_MODELVIEW_MATRIX 0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX 0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX 0x84E5
#define GL_TRANSPOSE_COLOR_MATRIX 0x84E6
#define GL_MULTISAMPLE_BIT 0x20000000
#define GL_NORMAL_MAP 0x8511
#define GL_REFLECTION_MAP 0x8512
#define GL_COMPRESSED_ALPHA 0x84E9
#define GL_COMPRESSED_LUMINANCE 0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA 0x84EB
#define GL_COMPRESSED_INTENSITY 0x84EC
#define GL_COMBINE 0x8570
#define GL_COMBINE_RGB 0x8571
#define GL_COMBINE_ALPHA 0x8572
#define GL_SOURCE0_RGB 0x8580
#define GL_SOURCE1_RGB 0x8581
#define GL_SOURCE2_RGB 0x8582
#define GL_SOURCE0_ALPHA 0x8588
#define GL_SOURCE1_ALPHA 0x8589
#define GL_SOURCE2_ALPHA 0x858A
#define GL_OPERAND0_RGB 0x8590
#define GL_OPERAND1_RGB 0x8591
#define GL_OPERAND2_RGB 0x8592
#define GL_OPERAND0_ALPHA 0x8598
#define GL_OPERAND1_ALPHA 0x8599
#define GL_OPERAND2_ALPHA 0x859A
#define GL_RGB_SCALE 0x8573
#define GL_ADD_SIGNED 0x8574
#define GL_INTERPOLATE 0x8575
#define GL_SUBTRACT 0x84E7
#define GL_CONSTANT 0x8576
#define GL_PRIMARY_COLOR 0x8577
#define GL_PREVIOUS 0x8578
#define GL_DOT3_RGB 0x86AE
#define GL_DOT3_RGBA 0x86AF
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClientActiveTexture)(GLenum texture); }
#define glClientActiveTexture DynamicGL_ClientActiveTexture
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1d)(GLenum target , GLdouble s); }
#define glMultiTexCoord1d DynamicGL_MultiTexCoord1d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1dv)(GLenum target , const GLdouble *v); }
#define glMultiTexCoord1dv DynamicGL_MultiTexCoord1dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1f)(GLenum target , GLfloat s); }
#define glMultiTexCoord1f DynamicGL_MultiTexCoord1f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1fv)(GLenum target , const GLfloat *v); }
#define glMultiTexCoord1fv DynamicGL_MultiTexCoord1fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1i)(GLenum target , GLint s); }
#define glMultiTexCoord1i DynamicGL_MultiTexCoord1i
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1iv)(GLenum target , const GLint *v); }
#define glMultiTexCoord1iv DynamicGL_MultiTexCoord1iv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1s)(GLenum target , GLshort s); }
#define glMultiTexCoord1s DynamicGL_MultiTexCoord1s
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord1sv)(GLenum target , const GLshort *v); }
#define glMultiTexCoord1sv DynamicGL_MultiTexCoord1sv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2d)(GLenum target , GLdouble s , GLdouble t); }
#define glMultiTexCoord2d DynamicGL_MultiTexCoord2d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2dv)(GLenum target , const GLdouble *v); }
#define glMultiTexCoord2dv DynamicGL_MultiTexCoord2dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2f)(GLenum target , GLfloat s , GLfloat t); }
#define glMultiTexCoord2f DynamicGL_MultiTexCoord2f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2fv)(GLenum target , const GLfloat *v); }
#define glMultiTexCoord2fv DynamicGL_MultiTexCoord2fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2i)(GLenum target , GLint s , GLint t); }
#define glMultiTexCoord2i DynamicGL_MultiTexCoord2i
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2iv)(GLenum target , const GLint *v); }
#define glMultiTexCoord2iv DynamicGL_MultiTexCoord2iv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2s)(GLenum target , GLshort s , GLshort t); }
#define glMultiTexCoord2s DynamicGL_MultiTexCoord2s
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord2sv)(GLenum target , const GLshort *v); }
#define glMultiTexCoord2sv DynamicGL_MultiTexCoord2sv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3d)(GLenum target , GLdouble s , GLdouble t , GLdouble r); }
#define glMultiTexCoord3d DynamicGL_MultiTexCoord3d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3dv)(GLenum target , const GLdouble *v); }
#define glMultiTexCoord3dv DynamicGL_MultiTexCoord3dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3f)(GLenum target , GLfloat s , GLfloat t , GLfloat r); }
#define glMultiTexCoord3f DynamicGL_MultiTexCoord3f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3fv)(GLenum target , const GLfloat *v); }
#define glMultiTexCoord3fv DynamicGL_MultiTexCoord3fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3i)(GLenum target , GLint s , GLint t , GLint r); }
#define glMultiTexCoord3i DynamicGL_MultiTexCoord3i
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3iv)(GLenum target , const GLint *v); }
#define glMultiTexCoord3iv DynamicGL_MultiTexCoord3iv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3s)(GLenum target , GLshort s , GLshort t , GLshort r); }
#define glMultiTexCoord3s DynamicGL_MultiTexCoord3s
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord3sv)(GLenum target , const GLshort *v); }
#define glMultiTexCoord3sv DynamicGL_MultiTexCoord3sv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4d)(GLenum target , GLdouble s , GLdouble t , GLdouble r , GLdouble q); }
#define glMultiTexCoord4d DynamicGL_MultiTexCoord4d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4dv)(GLenum target , const GLdouble *v); }
#define glMultiTexCoord4dv DynamicGL_MultiTexCoord4dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4f)(GLenum target , GLfloat s , GLfloat t , GLfloat r , GLfloat q); }
#define glMultiTexCoord4f DynamicGL_MultiTexCoord4f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4fv)(GLenum target , const GLfloat *v); }
#define glMultiTexCoord4fv DynamicGL_MultiTexCoord4fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4i)(GLenum target , GLint s , GLint t , GLint r , GLint q); }
#define glMultiTexCoord4i DynamicGL_MultiTexCoord4i
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4iv)(GLenum target , const GLint *v); }
#define glMultiTexCoord4iv DynamicGL_MultiTexCoord4iv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4s)(GLenum target , GLshort s , GLshort t , GLshort r , GLshort q); }
#define glMultiTexCoord4s DynamicGL_MultiTexCoord4s
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiTexCoord4sv)(GLenum target , const GLshort *v); }
#define glMultiTexCoord4sv DynamicGL_MultiTexCoord4sv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LoadTransposeMatrixf)(const GLfloat *m); }
#define glLoadTransposeMatrixf DynamicGL_LoadTransposeMatrixf
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LoadTransposeMatrixd)(const GLdouble *m); }
#define glLoadTransposeMatrixd DynamicGL_LoadTransposeMatrixd
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultTransposeMatrixf)(const GLfloat *m); }
#define glMultTransposeMatrixf DynamicGL_MultTransposeMatrixf
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultTransposeMatrixd)(const GLdouble *m); }
#define glMultTransposeMatrixd DynamicGL_MultTransposeMatrixd
extern bool DinamicGLFeature_VERSION_1_3_DEPRECATED_Supported();
#endif /*USE_DYNAMIC_GL_VERSION_1_3_DEPRECATED*/

/*VERSION_1_4_DEPRECATED*/
#ifdef USE_DYNAMIC_GL_VERSION_1_4_DEPRECATED
#define GL_POINT_SIZE_MIN 0x8126
#define GL_POINT_SIZE_MAX 0x8127
#define GL_POINT_DISTANCE_ATTENUATION 0x8129
#define GL_GENERATE_MIPMAP 0x8191
#define GL_GENERATE_MIPMAP_HINT 0x8192
#define GL_FOG_COORDINATE_SOURCE 0x8450
#define GL_FOG_COORDINATE 0x8451
#define GL_FRAGMENT_DEPTH 0x8452
#define GL_CURRENT_FOG_COORDINATE 0x8453
#define GL_FOG_COORDINATE_ARRAY_TYPE 0x8454
#define GL_FOG_COORDINATE_ARRAY_STRIDE 0x8455
#define GL_FOG_COORDINATE_ARRAY_POINTER 0x8456
#define GL_FOG_COORDINATE_ARRAY 0x8457
#define GL_COLOR_SUM 0x8458
#define GL_CURRENT_SECONDARY_COLOR 0x8459
#define GL_SECONDARY_COLOR_ARRAY_SIZE 0x845A
#define GL_SECONDARY_COLOR_ARRAY_TYPE 0x845B
#define GL_SECONDARY_COLOR_ARRAY_STRIDE 0x845C
#define GL_SECONDARY_COLOR_ARRAY_POINTER 0x845D
#define GL_SECONDARY_COLOR_ARRAY 0x845E
#define GL_TEXTURE_FILTER_CONTROL 0x8500
#define GL_DEPTH_TEXTURE_MODE 0x884B
#define GL_COMPARE_R_TO_TEXTURE 0x884E
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FogCoordf)(GLfloat coord); }
#define glFogCoordf DynamicGL_FogCoordf
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FogCoordfv)(const GLfloat *coord); }
#define glFogCoordfv DynamicGL_FogCoordfv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FogCoordd)(GLdouble coord); }
#define glFogCoordd DynamicGL_FogCoordd
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FogCoorddv)(const GLdouble *coord); }
#define glFogCoorddv DynamicGL_FogCoorddv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FogCoordPointer)(GLenum type , GLsizei stride , const GLvoid *pointer); }
#define glFogCoordPointer DynamicGL_FogCoordPointer
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3b)(GLbyte red , GLbyte green , GLbyte blue); }
#define glSecondaryColor3b DynamicGL_SecondaryColor3b
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3bv)(const GLbyte *v); }
#define glSecondaryColor3bv DynamicGL_SecondaryColor3bv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3d)(GLdouble red , GLdouble green , GLdouble blue); }
#define glSecondaryColor3d DynamicGL_SecondaryColor3d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3dv)(const GLdouble *v); }
#define glSecondaryColor3dv DynamicGL_SecondaryColor3dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3f)(GLfloat red , GLfloat green , GLfloat blue); }
#define glSecondaryColor3f DynamicGL_SecondaryColor3f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3fv)(const GLfloat *v); }
#define glSecondaryColor3fv DynamicGL_SecondaryColor3fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3i)(GLint red , GLint green , GLint blue); }
#define glSecondaryColor3i DynamicGL_SecondaryColor3i
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3iv)(const GLint *v); }
#define glSecondaryColor3iv DynamicGL_SecondaryColor3iv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3s)(GLshort red , GLshort green , GLshort blue); }
#define glSecondaryColor3s DynamicGL_SecondaryColor3s
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3sv)(const GLshort *v); }
#define glSecondaryColor3sv DynamicGL_SecondaryColor3sv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3ub)(GLubyte red , GLubyte green , GLubyte blue); }
#define glSecondaryColor3ub DynamicGL_SecondaryColor3ub
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3ubv)(const GLubyte *v); }
#define glSecondaryColor3ubv DynamicGL_SecondaryColor3ubv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3ui)(GLuint red , GLuint green , GLuint blue); }
#define glSecondaryColor3ui DynamicGL_SecondaryColor3ui
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3uiv)(const GLuint *v); }
#define glSecondaryColor3uiv DynamicGL_SecondaryColor3uiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3us)(GLushort red , GLushort green , GLushort blue); }
#define glSecondaryColor3us DynamicGL_SecondaryColor3us
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColor3usv)(const GLushort *v); }
#define glSecondaryColor3usv DynamicGL_SecondaryColor3usv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColorPointer)(GLint size , GLenum type , GLsizei stride , const GLvoid *pointer); }
#define glSecondaryColorPointer DynamicGL_SecondaryColorPointer
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2d)(GLdouble x , GLdouble y); }
#define glWindowPos2d DynamicGL_WindowPos2d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2dv)(const GLdouble *v); }
#define glWindowPos2dv DynamicGL_WindowPos2dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2f)(GLfloat x , GLfloat y); }
#define glWindowPos2f DynamicGL_WindowPos2f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2fv)(const GLfloat *v); }
#define glWindowPos2fv DynamicGL_WindowPos2fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2i)(GLint x , GLint y); }
#define glWindowPos2i DynamicGL_WindowPos2i
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2iv)(const GLint *v); }
#define glWindowPos2iv DynamicGL_WindowPos2iv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2s)(GLshort x , GLshort y); }
#define glWindowPos2s DynamicGL_WindowPos2s
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos2sv)(const GLshort *v); }
#define glWindowPos2sv DynamicGL_WindowPos2sv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3d)(GLdouble x , GLdouble y , GLdouble z); }
#define glWindowPos3d DynamicGL_WindowPos3d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3dv)(const GLdouble *v); }
#define glWindowPos3dv DynamicGL_WindowPos3dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3f)(GLfloat x , GLfloat y , GLfloat z); }
#define glWindowPos3f DynamicGL_WindowPos3f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3fv)(const GLfloat *v); }
#define glWindowPos3fv DynamicGL_WindowPos3fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3i)(GLint x , GLint y , GLint z); }
#define glWindowPos3i DynamicGL_WindowPos3i
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3iv)(const GLint *v); }
#define glWindowPos3iv DynamicGL_WindowPos3iv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3s)(GLshort x , GLshort y , GLshort z); }
#define glWindowPos3s DynamicGL_WindowPos3s
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WindowPos3sv)(const GLshort *v); }
#define glWindowPos3sv DynamicGL_WindowPos3sv
extern bool DinamicGLFeature_VERSION_1_4_DEPRECATED_Supported();
#endif /*USE_DYNAMIC_GL_VERSION_1_4_DEPRECATED*/

/*ARB_matrix_palette*/
#ifdef USE_DYNAMIC_GL_ARB_matrix_palette
#define GL_MATRIX_PALETTE_ARB 0x8840
#define GL_MAX_MATRIX_PALETTE_STACK_DEPTH_ARB 0x8841
#define GL_MAX_PALETTE_MATRICES_ARB 0x8842
#define GL_CURRENT_PALETTE_MATRIX_ARB 0x8843
#define GL_MATRIX_INDEX_ARRAY_ARB 0x8844
#define GL_CURRENT_MATRIX_INDEX_ARB 0x8845
#define GL_MATRIX_INDEX_ARRAY_SIZE_ARB 0x8846
#define GL_MATRIX_INDEX_ARRAY_TYPE_ARB 0x8847
#define GL_MATRIX_INDEX_ARRAY_STRIDE_ARB 0x8848
#define GL_MATRIX_INDEX_ARRAY_POINTER_ARB 0x8849
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CurrentPaletteMatrixARB)(GLint index); }
#define glCurrentPaletteMatrixARB DynamicGL_CurrentPaletteMatrixARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixIndexubvARB)(GLint size , const GLubyte *indices); }
#define glMatrixIndexubvARB DynamicGL_MatrixIndexubvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixIndexusvARB)(GLint size , const GLushort *indices); }
#define glMatrixIndexusvARB DynamicGL_MatrixIndexusvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixIndexuivARB)(GLint size , const GLuint *indices); }
#define glMatrixIndexuivARB DynamicGL_MatrixIndexuivARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MatrixIndexPointerARB)(GLint size , GLenum type , GLsizei stride , const GLvoid *pointer); }
#define glMatrixIndexPointerARB DynamicGL_MatrixIndexPointerARB
extern bool DinamicGLFeature_ARB_matrix_palette_Supported();
#endif /*USE_DYNAMIC_GL_ARB_matrix_palette*/

/*NV_texture_shader2*/
#ifdef USE_DYNAMIC_GL_NV_texture_shader2
#define GL_DOT_PRODUCT_TEXTURE_3D_NV 0x86EF
extern bool DinamicGLFeature_NV_texture_shader2_Supported();
#endif /*USE_DYNAMIC_GL_NV_texture_shader2*/

/*ARB_texture_env_combine*/
#ifdef USE_DYNAMIC_GL_ARB_texture_env_combine
#define GL_COMBINE_ARB 0x8570
#define GL_COMBINE_RGB_ARB 0x8571
#define GL_COMBINE_ALPHA_ARB 0x8572
#define GL_SOURCE0_RGB_ARB 0x8580
#define GL_SOURCE1_RGB_ARB 0x8581
#define GL_SOURCE2_RGB_ARB 0x8582
#define GL_SOURCE0_ALPHA_ARB 0x8588
#define GL_SOURCE1_ALPHA_ARB 0x8589
#define GL_SOURCE2_ALPHA_ARB 0x858A
#define GL_OPERAND0_RGB_ARB 0x8590
#define GL_OPERAND1_RGB_ARB 0x8591
#define GL_OPERAND2_RGB_ARB 0x8592
#define GL_OPERAND0_ALPHA_ARB 0x8598
#define GL_OPERAND1_ALPHA_ARB 0x8599
#define GL_OPERAND2_ALPHA_ARB 0x859A
#define GL_RGB_SCALE_ARB 0x8573
#define GL_ADD_SIGNED_ARB 0x8574
#define GL_INTERPOLATE_ARB 0x8575
#define GL_SUBTRACT_ARB 0x84E7
#define GL_CONSTANT_ARB 0x8576
#define GL_PRIMARY_COLOR_ARB 0x8577
#define GL_PREVIOUS_ARB 0x8578
extern bool DinamicGLFeature_ARB_texture_env_combine_Supported();
#endif /*USE_DYNAMIC_GL_ARB_texture_env_combine*/

/*ATI_element_array*/
#ifdef USE_DYNAMIC_GL_ATI_element_array
#define GL_ELEMENT_ARRAY_ATI 0x8768
#define GL_ELEMENT_ARRAY_TYPE_ATI 0x8769
#define GL_ELEMENT_ARRAY_POINTER_ATI 0x876A
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ElementPointerATI)(GLenum type , const GLvoid *pointer); }
#define glElementPointerATI DynamicGL_ElementPointerATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawElementArrayATI)(GLenum mode , GLsizei count); }
#define glDrawElementArrayATI DynamicGL_DrawElementArrayATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawRangeElementArrayATI)(GLenum mode , GLuint start , GLuint end , GLsizei count); }
#define glDrawRangeElementArrayATI DynamicGL_DrawRangeElementArrayATI
extern bool DinamicGLFeature_ATI_element_array_Supported();
#endif /*USE_DYNAMIC_GL_ATI_element_array*/

/*EXT_blend_equation_separate*/
#ifdef USE_DYNAMIC_GL_EXT_blend_equation_separate
#define GL_BLEND_EQUATION_RGB_EXT 0x8009
#define GL_BLEND_EQUATION_ALPHA_EXT 0x883D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendEquationSeparateEXT)(GLenum modeRGB , GLenum modeAlpha); }
#define glBlendEquationSeparateEXT DynamicGL_BlendEquationSeparateEXT
extern bool DinamicGLFeature_EXT_blend_equation_separate_Supported();
#endif /*USE_DYNAMIC_GL_EXT_blend_equation_separate*/

/*VERSION_1_5*/
#ifdef USE_DYNAMIC_GL_VERSION_1_5
typedef ptrdiff_t GLintptr;
typedef ptrdiff_t GLsizeiptr;
#define GL_BUFFER_SIZE 0x8764
#define GL_BUFFER_USAGE 0x8765
#define GL_QUERY_COUNTER_BITS 0x8864
#define GL_CURRENT_QUERY 0x8865
#define GL_QUERY_RESULT 0x8866
#define GL_QUERY_RESULT_AVAILABLE 0x8867
#define GL_ARRAY_BUFFER 0x8892
#define GL_ELEMENT_ARRAY_BUFFER 0x8893
#define GL_ARRAY_BUFFER_BINDING 0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING 0x8895
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define GL_READ_ONLY 0x88B8
#define GL_WRITE_ONLY 0x88B9
#define GL_READ_WRITE 0x88BA
#define GL_BUFFER_ACCESS 0x88BB
#define GL_BUFFER_MAPPED 0x88BC
#define GL_BUFFER_MAP_POINTER 0x88BD
#define GL_STREAM_DRAW 0x88E0
#define GL_STREAM_READ 0x88E1
#define GL_STREAM_COPY 0x88E2
#define GL_STATIC_DRAW 0x88E4
#define GL_STATIC_READ 0x88E5
#define GL_STATIC_COPY 0x88E6
#define GL_DYNAMIC_DRAW 0x88E8
#define GL_DYNAMIC_READ 0x88E9
#define GL_DYNAMIC_COPY 0x88EA
#define GL_SAMPLES_PASSED 0x8914
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GenQueries)(GLsizei n , GLuint *ids); }
#define glGenQueries DynamicGL_GenQueries
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteQueries)(GLsizei n , const GLuint *ids); }
#define glDeleteQueries DynamicGL_DeleteQueries
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsQuery)(GLuint id); }
#define glIsQuery DynamicGL_IsQuery
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BeginQuery)(GLenum target , GLuint id); }
#define glBeginQuery DynamicGL_BeginQuery
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EndQuery)(GLenum target); }
#define glEndQuery DynamicGL_EndQuery
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetQueryiv)(GLenum target , GLenum pname , GLint *params); }
#define glGetQueryiv DynamicGL_GetQueryiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetQueryObjectiv)(GLuint id , GLenum pname , GLint *params); }
#define glGetQueryObjectiv DynamicGL_GetQueryObjectiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetQueryObjectuiv)(GLuint id , GLenum pname , GLuint *params); }
#define glGetQueryObjectuiv DynamicGL_GetQueryObjectuiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindBuffer)(GLenum target , GLuint buffer); }
#define glBindBuffer DynamicGL_BindBuffer
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteBuffers)(GLsizei n , const GLuint *buffers); }
#define glDeleteBuffers DynamicGL_DeleteBuffers
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GenBuffers)(GLsizei n , GLuint *buffers); }
#define glGenBuffers DynamicGL_GenBuffers
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsBuffer)(GLuint buffer); }
#define glIsBuffer DynamicGL_IsBuffer
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BufferData)(GLenum target , GLsizeiptr size , const GLvoid *data , GLenum usage); }
#define glBufferData DynamicGL_BufferData
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BufferSubData)(GLenum target , GLintptr offset , GLsizeiptr size , const GLvoid *data); }
#define glBufferSubData DynamicGL_BufferSubData
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetBufferSubData)(GLenum target , GLintptr offset , GLsizeiptr size , GLvoid *data); }
#define glGetBufferSubData DynamicGL_GetBufferSubData
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_UnmapBuffer)(GLenum target); }
#define glUnmapBuffer DynamicGL_UnmapBuffer
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetBufferParameteriv)(GLenum target , GLenum pname , GLint *params); }
#define glGetBufferParameteriv DynamicGL_GetBufferParameteriv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetBufferPointerv)(GLenum target , GLenum pname , GLvoid* *params); }
#define glGetBufferPointerv DynamicGL_GetBufferPointerv
extern bool DinamicGLFeature_VERSION_1_5_Supported();
#endif /*USE_DYNAMIC_GL_VERSION_1_5*/

/*NV_vertex_program4*/
#ifdef USE_DYNAMIC_GL_NV_vertex_program4
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER_NV 0x88FD
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI1iEXT)(GLuint index , GLint x); }
#define glVertexAttribI1iEXT DynamicGL_VertexAttribI1iEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI2iEXT)(GLuint index , GLint x , GLint y); }
#define glVertexAttribI2iEXT DynamicGL_VertexAttribI2iEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI3iEXT)(GLuint index , GLint x , GLint y , GLint z); }
#define glVertexAttribI3iEXT DynamicGL_VertexAttribI3iEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI4iEXT)(GLuint index , GLint x , GLint y , GLint z , GLint w); }
#define glVertexAttribI4iEXT DynamicGL_VertexAttribI4iEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI1uiEXT)(GLuint index , GLuint x); }
#define glVertexAttribI1uiEXT DynamicGL_VertexAttribI1uiEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI2uiEXT)(GLuint index , GLuint x , GLuint y); }
#define glVertexAttribI2uiEXT DynamicGL_VertexAttribI2uiEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI3uiEXT)(GLuint index , GLuint x , GLuint y , GLuint z); }
#define glVertexAttribI3uiEXT DynamicGL_VertexAttribI3uiEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI4uiEXT)(GLuint index , GLuint x , GLuint y , GLuint z , GLuint w); }
#define glVertexAttribI4uiEXT DynamicGL_VertexAttribI4uiEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI1ivEXT)(GLuint index , const GLint *v); }
#define glVertexAttribI1ivEXT DynamicGL_VertexAttribI1ivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI2ivEXT)(GLuint index , const GLint *v); }
#define glVertexAttribI2ivEXT DynamicGL_VertexAttribI2ivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI3ivEXT)(GLuint index , const GLint *v); }
#define glVertexAttribI3ivEXT DynamicGL_VertexAttribI3ivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI4ivEXT)(GLuint index , const GLint *v); }
#define glVertexAttribI4ivEXT DynamicGL_VertexAttribI4ivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI1uivEXT)(GLuint index , const GLuint *v); }
#define glVertexAttribI1uivEXT DynamicGL_VertexAttribI1uivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI2uivEXT)(GLuint index , const GLuint *v); }
#define glVertexAttribI2uivEXT DynamicGL_VertexAttribI2uivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI3uivEXT)(GLuint index , const GLuint *v); }
#define glVertexAttribI3uivEXT DynamicGL_VertexAttribI3uivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI4uivEXT)(GLuint index , const GLuint *v); }
#define glVertexAttribI4uivEXT DynamicGL_VertexAttribI4uivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI4bvEXT)(GLuint index , const GLbyte *v); }
#define glVertexAttribI4bvEXT DynamicGL_VertexAttribI4bvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI4svEXT)(GLuint index , const GLshort *v); }
#define glVertexAttribI4svEXT DynamicGL_VertexAttribI4svEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI4ubvEXT)(GLuint index , const GLubyte *v); }
#define glVertexAttribI4ubvEXT DynamicGL_VertexAttribI4ubvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribI4usvEXT)(GLuint index , const GLushort *v); }
#define glVertexAttribI4usvEXT DynamicGL_VertexAttribI4usvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribIPointerEXT)(GLuint index , GLint size , GLenum type , GLsizei stride , const GLvoid *pointer); }
#define glVertexAttribIPointerEXT DynamicGL_VertexAttribIPointerEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribIivEXT)(GLuint index , GLenum pname , GLint *params); }
#define glGetVertexAttribIivEXT DynamicGL_GetVertexAttribIivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribIuivEXT)(GLuint index , GLenum pname , GLuint *params); }
#define glGetVertexAttribIuivEXT DynamicGL_GetVertexAttribIuivEXT
extern bool DinamicGLFeature_NV_vertex_program4_Supported();
#endif /*USE_DYNAMIC_GL_NV_vertex_program4*/

/*ARB_vertex_shader*/
#ifdef USE_DYNAMIC_GL_ARB_vertex_shader
#define GL_VERTEX_SHADER_ARB 0x8B31
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS_ARB 0x8B4A
#define GL_MAX_VARYING_FLOATS_ARB 0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB 0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB 0x8B4D
#define GL_OBJECT_ACTIVE_ATTRIBUTES_ARB 0x8B89
#define GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB 0x8B8A
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindAttribLocationARB)(GLhandleARB programObj , GLuint index , const GLcharARB *name); }
#define glBindAttribLocationARB DynamicGL_BindAttribLocationARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetActiveAttribARB)(GLhandleARB programObj , GLuint index , GLsizei maxLength , GLsizei *length , GLint *size , GLenum *type , GLcharARB *name); }
#define glGetActiveAttribARB DynamicGL_GetActiveAttribARB
extern "C" { extern GLint (DYNAMIC_GL_APIENTRYP DynamicGL_GetAttribLocationARB)(GLhandleARB programObj , const GLcharARB *name); }
#define glGetAttribLocationARB DynamicGL_GetAttribLocationARB
extern bool DinamicGLFeature_ARB_vertex_shader_Supported();
#endif /*USE_DYNAMIC_GL_ARB_vertex_shader*/

/*EXT_polygon_offset*/
#ifdef USE_DYNAMIC_GL_EXT_polygon_offset
#define GL_POLYGON_OFFSET_EXT 0x8037
#define GL_POLYGON_OFFSET_FACTOR_EXT 0x8038
#define GL_POLYGON_OFFSET_BIAS_EXT 0x8039
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PolygonOffsetEXT)(GLfloat factor , GLfloat bias); }
#define glPolygonOffsetEXT DynamicGL_PolygonOffsetEXT
extern bool DinamicGLFeature_EXT_polygon_offset_Supported();
#endif /*USE_DYNAMIC_GL_EXT_polygon_offset*/

/*ARB_vertex_blend*/
#ifdef USE_DYNAMIC_GL_ARB_vertex_blend
#define GL_MAX_VERTEX_UNITS_ARB 0x86A4
#define GL_ACTIVE_VERTEX_UNITS_ARB 0x86A5
#define GL_WEIGHT_SUM_UNITY_ARB 0x86A6
#define GL_VERTEX_BLEND_ARB 0x86A7
#define GL_CURRENT_WEIGHT_ARB 0x86A8
#define GL_WEIGHT_ARRAY_TYPE_ARB 0x86A9
#define GL_WEIGHT_ARRAY_STRIDE_ARB 0x86AA
#define GL_WEIGHT_ARRAY_SIZE_ARB 0x86AB
#define GL_WEIGHT_ARRAY_POINTER_ARB 0x86AC
#define GL_WEIGHT_ARRAY_ARB 0x86AD
#define GL_MODELVIEW0_ARB 0x1700
#define GL_MODELVIEW1_ARB 0x850A
#define GL_MODELVIEW2_ARB 0x8722
#define GL_MODELVIEW3_ARB 0x8723
#define GL_MODELVIEW4_ARB 0x8724
#define GL_MODELVIEW5_ARB 0x8725
#define GL_MODELVIEW6_ARB 0x8726
#define GL_MODELVIEW7_ARB 0x8727
#define GL_MODELVIEW8_ARB 0x8728
#define GL_MODELVIEW9_ARB 0x8729
#define GL_MODELVIEW10_ARB 0x872A
#define GL_MODELVIEW11_ARB 0x872B
#define GL_MODELVIEW12_ARB 0x872C
#define GL_MODELVIEW13_ARB 0x872D
#define GL_MODELVIEW14_ARB 0x872E
#define GL_MODELVIEW15_ARB 0x872F
#define GL_MODELVIEW16_ARB 0x8730
#define GL_MODELVIEW17_ARB 0x8731
#define GL_MODELVIEW18_ARB 0x8732
#define GL_MODELVIEW19_ARB 0x8733
#define GL_MODELVIEW20_ARB 0x8734
#define GL_MODELVIEW21_ARB 0x8735
#define GL_MODELVIEW22_ARB 0x8736
#define GL_MODELVIEW23_ARB 0x8737
#define GL_MODELVIEW24_ARB 0x8738
#define GL_MODELVIEW25_ARB 0x8739
#define GL_MODELVIEW26_ARB 0x873A
#define GL_MODELVIEW27_ARB 0x873B
#define GL_MODELVIEW28_ARB 0x873C
#define GL_MODELVIEW29_ARB 0x873D
#define GL_MODELVIEW30_ARB 0x873E
#define GL_MODELVIEW31_ARB 0x873F
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WeightbvARB)(GLint size , const GLbyte *weights); }
#define glWeightbvARB DynamicGL_WeightbvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WeightsvARB)(GLint size , const GLshort *weights); }
#define glWeightsvARB DynamicGL_WeightsvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WeightivARB)(GLint size , const GLint *weights); }
#define glWeightivARB DynamicGL_WeightivARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WeightfvARB)(GLint size , const GLfloat *weights); }
#define glWeightfvARB DynamicGL_WeightfvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WeightdvARB)(GLint size , const GLdouble *weights); }
#define glWeightdvARB DynamicGL_WeightdvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WeightubvARB)(GLint size , const GLubyte *weights); }
#define glWeightubvARB DynamicGL_WeightubvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WeightusvARB)(GLint size , const GLushort *weights); }
#define glWeightusvARB DynamicGL_WeightusvARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WeightuivARB)(GLint size , const GLuint *weights); }
#define glWeightuivARB DynamicGL_WeightuivARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WeightPointerARB)(GLint size , GLenum type , GLsizei stride , const GLvoid *pointer); }
#define glWeightPointerARB DynamicGL_WeightPointerARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexBlendARB)(GLint count); }
#define glVertexBlendARB DynamicGL_VertexBlendARB
extern bool DinamicGLFeature_ARB_vertex_blend_Supported();
#endif /*USE_DYNAMIC_GL_ARB_vertex_blend*/

/*WIN_specular_fog*/
#ifdef USE_DYNAMIC_GL_WIN_specular_fog
#define GL_FOG_SPECULAR_TEXTURE_WIN 0x80EC
extern bool DinamicGLFeature_WIN_specular_fog_Supported();
#endif /*USE_DYNAMIC_GL_WIN_specular_fog*/

/*VERSION_1_2_DEPRECATED*/
#ifdef USE_DYNAMIC_GL_VERSION_1_2_DEPRECATED
#define GL_RESCALE_NORMAL 0x803A
#define GL_LIGHT_MODEL_COLOR_CONTROL 0x81F8
#define GL_SINGLE_COLOR 0x81F9
#define GL_SEPARATE_SPECULAR_COLOR 0x81FA
#define GL_ALIASED_POINT_SIZE_RANGE 0x846D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorTable)(GLenum target , GLenum internalformat , GLsizei width , GLenum format , GLenum type , const GLvoid *table); }
#define glColorTable DynamicGL_ColorTable
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorTableParameterfv)(GLenum target , GLenum pname , const GLfloat *params); }
#define glColorTableParameterfv DynamicGL_ColorTableParameterfv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorTableParameteriv)(GLenum target , GLenum pname , const GLint *params); }
#define glColorTableParameteriv DynamicGL_ColorTableParameteriv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyColorTable)(GLenum target , GLenum internalformat , GLint x , GLint y , GLsizei width); }
#define glCopyColorTable DynamicGL_CopyColorTable
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetColorTable)(GLenum target , GLenum format , GLenum type , GLvoid *table); }
#define glGetColorTable DynamicGL_GetColorTable
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetColorTableParameterfv)(GLenum target , GLenum pname , GLfloat *params); }
#define glGetColorTableParameterfv DynamicGL_GetColorTableParameterfv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetColorTableParameteriv)(GLenum target , GLenum pname , GLint *params); }
#define glGetColorTableParameteriv DynamicGL_GetColorTableParameteriv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorSubTable)(GLenum target , GLsizei start , GLsizei count , GLenum format , GLenum type , const GLvoid *data); }
#define glColorSubTable DynamicGL_ColorSubTable
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyColorSubTable)(GLenum target , GLsizei start , GLint x , GLint y , GLsizei width); }
#define glCopyColorSubTable DynamicGL_CopyColorSubTable
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ConvolutionFilter1D)(GLenum target , GLenum internalformat , GLsizei width , GLenum format , GLenum type , const GLvoid *image); }
#define glConvolutionFilter1D DynamicGL_ConvolutionFilter1D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ConvolutionFilter2D)(GLenum target , GLenum internalformat , GLsizei width , GLsizei height , GLenum format , GLenum type , const GLvoid *image); }
#define glConvolutionFilter2D DynamicGL_ConvolutionFilter2D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ConvolutionParameterf)(GLenum target , GLenum pname , GLfloat params); }
#define glConvolutionParameterf DynamicGL_ConvolutionParameterf
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ConvolutionParameterfv)(GLenum target , GLenum pname , const GLfloat *params); }
#define glConvolutionParameterfv DynamicGL_ConvolutionParameterfv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ConvolutionParameteri)(GLenum target , GLenum pname , GLint params); }
#define glConvolutionParameteri DynamicGL_ConvolutionParameteri
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ConvolutionParameteriv)(GLenum target , GLenum pname , const GLint *params); }
#define glConvolutionParameteriv DynamicGL_ConvolutionParameteriv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyConvolutionFilter1D)(GLenum target , GLenum internalformat , GLint x , GLint y , GLsizei width); }
#define glCopyConvolutionFilter1D DynamicGL_CopyConvolutionFilter1D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyConvolutionFilter2D)(GLenum target , GLenum internalformat , GLint x , GLint y , GLsizei width , GLsizei height); }
#define glCopyConvolutionFilter2D DynamicGL_CopyConvolutionFilter2D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetConvolutionFilter)(GLenum target , GLenum format , GLenum type , GLvoid *image); }
#define glGetConvolutionFilter DynamicGL_GetConvolutionFilter
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetConvolutionParameterfv)(GLenum target , GLenum pname , GLfloat *params); }
#define glGetConvolutionParameterfv DynamicGL_GetConvolutionParameterfv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetConvolutionParameteriv)(GLenum target , GLenum pname , GLint *params); }
#define glGetConvolutionParameteriv DynamicGL_GetConvolutionParameteriv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetSeparableFilter)(GLenum target , GLenum format , GLenum type , GLvoid *row , GLvoid *column , GLvoid *span); }
#define glGetSeparableFilter DynamicGL_GetSeparableFilter
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SeparableFilter2D)(GLenum target , GLenum internalformat , GLsizei width , GLsizei height , GLenum format , GLenum type , const GLvoid *row , const GLvoid *column); }
#define glSeparableFilter2D DynamicGL_SeparableFilter2D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetHistogram)(GLenum target , GLboolean reset , GLenum format , GLenum type , GLvoid *values); }
#define glGetHistogram DynamicGL_GetHistogram
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetHistogramParameterfv)(GLenum target , GLenum pname , GLfloat *params); }
#define glGetHistogramParameterfv DynamicGL_GetHistogramParameterfv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetHistogramParameteriv)(GLenum target , GLenum pname , GLint *params); }
#define glGetHistogramParameteriv DynamicGL_GetHistogramParameteriv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMinmax)(GLenum target , GLboolean reset , GLenum format , GLenum type , GLvoid *values); }
#define glGetMinmax DynamicGL_GetMinmax
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMinmaxParameterfv)(GLenum target , GLenum pname , GLfloat *params); }
#define glGetMinmaxParameterfv DynamicGL_GetMinmaxParameterfv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMinmaxParameteriv)(GLenum target , GLenum pname , GLint *params); }
#define glGetMinmaxParameteriv DynamicGL_GetMinmaxParameteriv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Histogram)(GLenum target , GLsizei width , GLenum internalformat , GLboolean sink); }
#define glHistogram DynamicGL_Histogram
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Minmax)(GLenum target , GLenum internalformat , GLboolean sink); }
#define glMinmax DynamicGL_Minmax
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ResetHistogram)(GLenum target); }
#define glResetHistogram DynamicGL_ResetHistogram
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ResetMinmax)(GLenum target); }
#define glResetMinmax DynamicGL_ResetMinmax
extern bool DinamicGLFeature_VERSION_1_2_DEPRECATED_Supported();
#endif /*USE_DYNAMIC_GL_VERSION_1_2_DEPRECATED*/

/*NV_multisample_coverage*/
#ifdef USE_DYNAMIC_GL_NV_multisample_coverage
#define GL_COVERAGE_SAMPLES_NV 0x80A9
#define GL_COLOR_SAMPLES_NV 0x8E20
extern bool DinamicGLFeature_NV_multisample_coverage_Supported();
#endif /*USE_DYNAMIC_GL_NV_multisample_coverage*/

/*SGIX_impact_pixel_texture*/
#ifdef USE_DYNAMIC_GL_SGIX_impact_pixel_texture
#define GL_PIXEL_TEX_GEN_Q_CEILING_SGIX 0x8184
#define GL_PIXEL_TEX_GEN_Q_ROUND_SGIX 0x8185
#define GL_PIXEL_TEX_GEN_Q_FLOOR_SGIX 0x8186
#define GL_PIXEL_TEX_GEN_ALPHA_REPLACE_SGIX 0x8187
#define GL_PIXEL_TEX_GEN_ALPHA_NO_REPLACE_SGIX 0x8188
#define GL_PIXEL_TEX_GEN_ALPHA_LS_SGIX 0x8189
#define GL_PIXEL_TEX_GEN_ALPHA_MS_SGIX 0x818A
extern bool DinamicGLFeature_SGIX_impact_pixel_texture_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_impact_pixel_texture*/

/*EXT_depth_bounds_test*/
#ifdef USE_DYNAMIC_GL_EXT_depth_bounds_test
#define GL_DEPTH_BOUNDS_TEST_EXT 0x8890
#define GL_DEPTH_BOUNDS_EXT 0x8891
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DepthBoundsEXT)(GLclampd zmin , GLclampd zmax); }
#define glDepthBoundsEXT DynamicGL_DepthBoundsEXT
extern bool DinamicGLFeature_EXT_depth_bounds_test_Supported();
#endif /*USE_DYNAMIC_GL_EXT_depth_bounds_test*/

/*ARB_shader_image_load_store*/
#ifdef USE_DYNAMIC_GL_ARB_shader_image_load_store
#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT 0x00000001
#define GL_ELEMENT_ARRAY_BARRIER_BIT 0x00000002
#define GL_UNIFORM_BARRIER_BIT 0x00000004
#define GL_TEXTURE_FETCH_BARRIER_BIT 0x00000008
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT 0x00000020
#define GL_COMMAND_BARRIER_BIT 0x00000040
#define GL_PIXEL_BUFFER_BARRIER_BIT 0x00000080
#define GL_TEXTURE_UPDATE_BARRIER_BIT 0x00000100
#define GL_BUFFER_UPDATE_BARRIER_BIT 0x00000200
#define GL_FRAMEBUFFER_BARRIER_BIT 0x00000400
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT 0x00000800
#define GL_ATOMIC_COUNTER_BARRIER_BIT 0x00001000
#define GL_ALL_BARRIER_BITS 0xFFFFFFFF
#define GL_MAX_IMAGE_UNITS 0x8F38
#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS 0x8F39
#define GL_IMAGE_BINDING_NAME 0x8F3A
#define GL_IMAGE_BINDING_LEVEL 0x8F3B
#define GL_IMAGE_BINDING_LAYERED 0x8F3C
#define GL_IMAGE_BINDING_LAYER 0x8F3D
#define GL_IMAGE_BINDING_ACCESS 0x8F3E
#define GL_IMAGE_1D 0x904C
#define GL_IMAGE_2D 0x904D
#define GL_IMAGE_3D 0x904E
#define GL_IMAGE_2D_RECT 0x904F
#define GL_IMAGE_CUBE 0x9050
#define GL_IMAGE_BUFFER 0x9051
#define GL_IMAGE_1D_ARRAY 0x9052
#define GL_IMAGE_2D_ARRAY 0x9053
#define GL_IMAGE_CUBE_MAP_ARRAY 0x9054
#define GL_IMAGE_2D_MULTISAMPLE 0x9055
#define GL_IMAGE_2D_MULTISAMPLE_ARRAY 0x9056
#define GL_INT_IMAGE_1D 0x9057
#define GL_INT_IMAGE_2D 0x9058
#define GL_INT_IMAGE_3D 0x9059
#define GL_INT_IMAGE_2D_RECT 0x905A
#define GL_INT_IMAGE_CUBE 0x905B
#define GL_INT_IMAGE_BUFFER 0x905C
#define GL_INT_IMAGE_1D_ARRAY 0x905D
#define GL_INT_IMAGE_2D_ARRAY 0x905E
#define GL_INT_IMAGE_CUBE_MAP_ARRAY 0x905F
#define GL_INT_IMAGE_2D_MULTISAMPLE 0x9060
#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x9061
#define GL_UNSIGNED_INT_IMAGE_1D 0x9062
#define GL_UNSIGNED_INT_IMAGE_2D 0x9063
#define GL_UNSIGNED_INT_IMAGE_3D 0x9064
#define GL_UNSIGNED_INT_IMAGE_2D_RECT 0x9065
#define GL_UNSIGNED_INT_IMAGE_CUBE 0x9066
#define GL_UNSIGNED_INT_IMAGE_BUFFER 0x9067
#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY 0x9068
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY 0x9069
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY 0x906A
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE 0x906B
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x906C
#define GL_MAX_IMAGE_SAMPLES 0x906D
#define GL_IMAGE_BINDING_FORMAT 0x906E
#define GL_IMAGE_FORMAT_COMPATIBILITY_TYPE 0x90C7
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE 0x90C8
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS 0x90C9
#define GL_MAX_VERTEX_IMAGE_UNIFORMS 0x90CA
#define GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS 0x90CB
#define GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS 0x90CC
#define GL_MAX_GEOMETRY_IMAGE_UNIFORMS 0x90CD
#define GL_MAX_FRAGMENT_IMAGE_UNIFORMS 0x90CE
#define GL_MAX_COMBINED_IMAGE_UNIFORMS 0x90CF
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindImageTexture)(GLuint unit , GLuint texture , GLint level , GLboolean layered , GLint layer , GLenum access , GLenum format); }
#define glBindImageTexture DynamicGL_BindImageTexture
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MemoryBarrier)(GLbitfield barriers); }
#define glMemoryBarrier DynamicGL_MemoryBarrier
extern bool DinamicGLFeature_ARB_shader_image_load_store_Supported();
#endif /*USE_DYNAMIC_GL_ARB_shader_image_load_store*/

/*EXT_texture_mirror_clamp*/
#ifdef USE_DYNAMIC_GL_EXT_texture_mirror_clamp
#define GL_MIRROR_CLAMP_EXT 0x8742
#define GL_MIRROR_CLAMP_TO_EDGE_EXT 0x8743
#define GL_MIRROR_CLAMP_TO_BORDER_EXT 0x8912
extern bool DinamicGLFeature_EXT_texture_mirror_clamp_Supported();
#endif /*USE_DYNAMIC_GL_EXT_texture_mirror_clamp*/

/*SGIS_texture_lod*/
#ifdef USE_DYNAMIC_GL_SGIS_texture_lod
#define GL_TEXTURE_MIN_LOD_SGIS 0x813A
#define GL_TEXTURE_MAX_LOD_SGIS 0x813B
#define GL_TEXTURE_BASE_LEVEL_SGIS 0x813C
#define GL_TEXTURE_MAX_LEVEL_SGIS 0x813D
extern bool DinamicGLFeature_SGIS_texture_lod_Supported();
#endif /*USE_DYNAMIC_GL_SGIS_texture_lod*/

/*VERSION_1_2*/
#ifdef USE_DYNAMIC_GL_VERSION_1_2
#define GL_UNSIGNED_BYTE_3_3_2 0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4 0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1 0x8034
#define GL_UNSIGNED_INT_8_8_8_8 0x8035
#define GL_UNSIGNED_INT_10_10_10_2 0x8036
#define GL_TEXTURE_BINDING_3D 0x806A
#define GL_PACK_SKIP_IMAGES 0x806B
#define GL_PACK_IMAGE_HEIGHT 0x806C
#define GL_UNPACK_SKIP_IMAGES 0x806D
#define GL_UNPACK_IMAGE_HEIGHT 0x806E
#define GL_TEXTURE_3D 0x806F
#define GL_PROXY_TEXTURE_3D 0x8070
#define GL_TEXTURE_DEPTH 0x8071
#define GL_TEXTURE_WRAP_R 0x8072
#define GL_MAX_3D_TEXTURE_SIZE 0x8073
#define GL_UNSIGNED_BYTE_2_3_3_REV 0x8362
#define GL_UNSIGNED_SHORT_5_6_5 0x8363
#define GL_UNSIGNED_SHORT_5_6_5_REV 0x8364
#define GL_UNSIGNED_SHORT_4_4_4_4_REV 0x8365
#define GL_UNSIGNED_SHORT_1_5_5_5_REV 0x8366
#define GL_UNSIGNED_INT_8_8_8_8_REV 0x8367
#define GL_UNSIGNED_INT_2_10_10_10_REV 0x8368
#define GL_BGR 0x80E0
#define GL_BGRA 0x80E1
#define GL_MAX_ELEMENTS_VERTICES 0x80E8
#define GL_MAX_ELEMENTS_INDICES 0x80E9
#define GL_CLAMP_TO_EDGE 0x812F
#define GL_TEXTURE_MIN_LOD 0x813A
#define GL_TEXTURE_MAX_LOD 0x813B
#define GL_TEXTURE_BASE_LEVEL 0x813C
#define GL_TEXTURE_MAX_LEVEL 0x813D
#define GL_SMOOTH_POINT_SIZE_RANGE 0x0B12
#define GL_SMOOTH_POINT_SIZE_GRANULARITY 0x0B13
#define GL_SMOOTH_LINE_WIDTH_RANGE 0x0B22
#define GL_SMOOTH_LINE_WIDTH_GRANULARITY 0x0B23
#define GL_ALIASED_LINE_WIDTH_RANGE 0x846E
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendColor)(GLfloat red , GLfloat green , GLfloat blue , GLfloat alpha); }
#define glBlendColor DynamicGL_BlendColor
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendEquation)(GLenum mode); }
#define glBlendEquation DynamicGL_BlendEquation
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawRangeElements)(GLenum mode , GLuint start , GLuint end , GLsizei count , GLenum type , const GLvoid *indices); }
#define glDrawRangeElements DynamicGL_DrawRangeElements
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexImage3D)(GLenum target , GLint level , GLint internalformat , GLsizei width , GLsizei height , GLsizei depth , GLint border , GLenum format , GLenum type , const GLvoid *pixels); }
#define glTexImage3D DynamicGL_TexImage3D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexSubImage3D)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLsizei width , GLsizei height , GLsizei depth , GLenum format , GLenum type , const GLvoid *pixels); }
#define glTexSubImage3D DynamicGL_TexSubImage3D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyTexSubImage3D)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLint x , GLint y , GLsizei width , GLsizei height); }
#define glCopyTexSubImage3D DynamicGL_CopyTexSubImage3D
extern bool DinamicGLFeature_VERSION_1_2_Supported();
#endif /*USE_DYNAMIC_GL_VERSION_1_2*/

/*SGIS_texture_edge_clamp*/
#ifdef USE_DYNAMIC_GL_SGIS_texture_edge_clamp
#define GL_CLAMP_TO_EDGE_SGIS 0x812F
extern bool DinamicGLFeature_SGIS_texture_edge_clamp_Supported();
#endif /*USE_DYNAMIC_GL_SGIS_texture_edge_clamp*/

/*SUN_slice_accum*/
#ifdef USE_DYNAMIC_GL_SUN_slice_accum
#define GL_SLICE_ACCUM_SUN 0x85CC
extern bool DinamicGLFeature_SUN_slice_accum_Supported();
#endif /*USE_DYNAMIC_GL_SUN_slice_accum*/

/*APPLE_element_array*/
#ifdef USE_DYNAMIC_GL_APPLE_element_array
#define GL_ELEMENT_ARRAY_APPLE 0x8A0C
#define GL_ELEMENT_ARRAY_TYPE_APPLE 0x8A0D
#define GL_ELEMENT_ARRAY_POINTER_APPLE 0x8A0E
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ElementPointerAPPLE)(GLenum type , const GLvoid *pointer); }
#define glElementPointerAPPLE DynamicGL_ElementPointerAPPLE
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawElementArrayAPPLE)(GLenum mode , GLint first , GLsizei count); }
#define glDrawElementArrayAPPLE DynamicGL_DrawElementArrayAPPLE
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawRangeElementArrayAPPLE)(GLenum mode , GLuint start , GLuint end , GLint first , GLsizei count); }
#define glDrawRangeElementArrayAPPLE DynamicGL_DrawRangeElementArrayAPPLE
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiDrawElementArrayAPPLE)(GLenum mode , const GLint *first , const GLsizei *count , GLsizei primcount); }
#define glMultiDrawElementArrayAPPLE DynamicGL_MultiDrawElementArrayAPPLE
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiDrawRangeElementArrayAPPLE)(GLenum mode , GLuint start , GLuint end , const GLint *first , const GLsizei *count , GLsizei primcount); }
#define glMultiDrawRangeElementArrayAPPLE DynamicGL_MultiDrawRangeElementArrayAPPLE
extern bool DinamicGLFeature_APPLE_element_array_Supported();
#endif /*USE_DYNAMIC_GL_APPLE_element_array*/

/*ARB_sync*/
#ifdef USE_DYNAMIC_GL_ARB_sync
typedef int64_t GLint64;
typedef uint64_t GLuint64;
#define GL_MAX_SERVER_WAIT_TIMEOUT 0x9111
#define GL_OBJECT_TYPE 0x9112
#define GL_SYNC_CONDITION 0x9113
#define GL_SYNC_STATUS 0x9114
#define GL_SYNC_FLAGS 0x9115
#define GL_SYNC_FENCE 0x9116
#define GL_SYNC_GPU_COMMANDS_COMPLETE 0x9117
#define GL_UNSIGNALED 0x9118
#define GL_SIGNALED 0x9119
#define GL_ALREADY_SIGNALED 0x911A
#define GL_TIMEOUT_EXPIRED 0x911B
#define GL_CONDITION_SATISFIED 0x911C
#define GL_WAIT_FAILED 0x911D
#define GL_SYNC_FLUSH_COMMANDS_BIT 0x00000001
#define GL_TIMEOUT_IGNORED 0xFFFFFFFFFFFFFFFF
extern "C" { extern GLsync (DYNAMIC_GL_APIENTRYP DynamicGL_FenceSync)(GLenum condition , GLbitfield flags); }
#define glFenceSync DynamicGL_FenceSync
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsSync)(GLsync sync); }
#define glIsSync DynamicGL_IsSync
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteSync)(GLsync sync); }
#define glDeleteSync DynamicGL_DeleteSync
extern "C" { extern GLenum (DYNAMIC_GL_APIENTRYP DynamicGL_ClientWaitSync)(GLsync sync , GLbitfield flags , GLuint64 timeout); }
#define glClientWaitSync DynamicGL_ClientWaitSync
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_WaitSync)(GLsync sync , GLbitfield flags , GLuint64 timeout); }
#define glWaitSync DynamicGL_WaitSync
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetInteger64v)(GLenum pname , GLint64 *params); }
#define glGetInteger64v DynamicGL_GetInteger64v
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetSynciv)(GLsync sync , GLenum pname , GLsizei bufSize , GLsizei *length , GLint *values); }
#define glGetSynciv DynamicGL_GetSynciv
extern bool DinamicGLFeature_ARB_sync_Supported();
#endif /*USE_DYNAMIC_GL_ARB_sync*/

/*NV_tessellation_program5*/
#ifdef USE_DYNAMIC_GL_NV_tessellation_program5
#define GL_MAX_PROGRAM_PATCH_ATTRIBS_NV 0x86D8
#define GL_TESS_CONTROL_PROGRAM_NV 0x891E
#define GL_TESS_EVALUATION_PROGRAM_NV 0x891F
#define GL_TESS_CONTROL_PROGRAM_PARAMETER_BUFFER_NV 0x8C74
#define GL_TESS_EVALUATION_PROGRAM_PARAMETER_BUFFER_NV 0x8C75
extern bool DinamicGLFeature_NV_tessellation_program5_Supported();
#endif /*USE_DYNAMIC_GL_NV_tessellation_program5*/

/*ARB_separate_shader_objects*/
#ifdef USE_DYNAMIC_GL_ARB_separate_shader_objects
#define GL_VERTEX_SHADER_BIT 0x00000001
#define GL_FRAGMENT_SHADER_BIT 0x00000002
#define GL_GEOMETRY_SHADER_BIT 0x00000004
#define GL_TESS_CONTROL_SHADER_BIT 0x00000008
#define GL_TESS_EVALUATION_SHADER_BIT 0x00000010
#define GL_ALL_SHADER_BITS 0xFFFFFFFF
#define GL_PROGRAM_SEPARABLE 0x8258
#define GL_ACTIVE_PROGRAM 0x8259
#define GL_PROGRAM_PIPELINE_BINDING 0x825A
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_UseProgramStages)(GLuint pipeline , GLbitfield stages , GLuint program); }
#define glUseProgramStages DynamicGL_UseProgramStages
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ActiveShaderProgram)(GLuint pipeline , GLuint program); }
#define glActiveShaderProgram DynamicGL_ActiveShaderProgram
extern "C" { extern GLuint (DYNAMIC_GL_APIENTRYP DynamicGL_CreateShaderProgramv)(GLenum type , GLsizei count , const GLchar* const); }
#define glCreateShaderProgramv DynamicGL_CreateShaderProgramv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindProgramPipeline)(GLuint pipeline); }
#define glBindProgramPipeline DynamicGL_BindProgramPipeline
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteProgramPipelines)(GLsizei n , const GLuint *pipelines); }
#define glDeleteProgramPipelines DynamicGL_DeleteProgramPipelines
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GenProgramPipelines)(GLsizei n , GLuint *pipelines); }
#define glGenProgramPipelines DynamicGL_GenProgramPipelines
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsProgramPipeline)(GLuint pipeline); }
#define glIsProgramPipeline DynamicGL_IsProgramPipeline
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramPipelineiv)(GLuint pipeline , GLenum pname , GLint *params); }
#define glGetProgramPipelineiv DynamicGL_GetProgramPipelineiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform1i)(GLuint program , GLint location , GLint v0); }
#define glProgramUniform1i DynamicGL_ProgramUniform1i
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform1iv)(GLuint program , GLint location , GLsizei count , const GLint *value); }
#define glProgramUniform1iv DynamicGL_ProgramUniform1iv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform1f)(GLuint program , GLint location , GLfloat v0); }
#define glProgramUniform1f DynamicGL_ProgramUniform1f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform1fv)(GLuint program , GLint location , GLsizei count , const GLfloat *value); }
#define glProgramUniform1fv DynamicGL_ProgramUniform1fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform1d)(GLuint program , GLint location , GLdouble v0); }
#define glProgramUniform1d DynamicGL_ProgramUniform1d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform1dv)(GLuint program , GLint location , GLsizei count , const GLdouble *value); }
#define glProgramUniform1dv DynamicGL_ProgramUniform1dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform1ui)(GLuint program , GLint location , GLuint v0); }
#define glProgramUniform1ui DynamicGL_ProgramUniform1ui
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform1uiv)(GLuint program , GLint location , GLsizei count , const GLuint *value); }
#define glProgramUniform1uiv DynamicGL_ProgramUniform1uiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform2i)(GLuint program , GLint location , GLint v0 , GLint v1); }
#define glProgramUniform2i DynamicGL_ProgramUniform2i
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform2iv)(GLuint program , GLint location , GLsizei count , const GLint *value); }
#define glProgramUniform2iv DynamicGL_ProgramUniform2iv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform2f)(GLuint program , GLint location , GLfloat v0 , GLfloat v1); }
#define glProgramUniform2f DynamicGL_ProgramUniform2f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform2fv)(GLuint program , GLint location , GLsizei count , const GLfloat *value); }
#define glProgramUniform2fv DynamicGL_ProgramUniform2fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform2d)(GLuint program , GLint location , GLdouble v0 , GLdouble v1); }
#define glProgramUniform2d DynamicGL_ProgramUniform2d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform2dv)(GLuint program , GLint location , GLsizei count , const GLdouble *value); }
#define glProgramUniform2dv DynamicGL_ProgramUniform2dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform2ui)(GLuint program , GLint location , GLuint v0 , GLuint v1); }
#define glProgramUniform2ui DynamicGL_ProgramUniform2ui
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform2uiv)(GLuint program , GLint location , GLsizei count , const GLuint *value); }
#define glProgramUniform2uiv DynamicGL_ProgramUniform2uiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform3i)(GLuint program , GLint location , GLint v0 , GLint v1 , GLint v2); }
#define glProgramUniform3i DynamicGL_ProgramUniform3i
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform3iv)(GLuint program , GLint location , GLsizei count , const GLint *value); }
#define glProgramUniform3iv DynamicGL_ProgramUniform3iv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform3f)(GLuint program , GLint location , GLfloat v0 , GLfloat v1 , GLfloat v2); }
#define glProgramUniform3f DynamicGL_ProgramUniform3f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform3fv)(GLuint program , GLint location , GLsizei count , const GLfloat *value); }
#define glProgramUniform3fv DynamicGL_ProgramUniform3fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform3d)(GLuint program , GLint location , GLdouble v0 , GLdouble v1 , GLdouble v2); }
#define glProgramUniform3d DynamicGL_ProgramUniform3d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform3dv)(GLuint program , GLint location , GLsizei count , const GLdouble *value); }
#define glProgramUniform3dv DynamicGL_ProgramUniform3dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform3ui)(GLuint program , GLint location , GLuint v0 , GLuint v1 , GLuint v2); }
#define glProgramUniform3ui DynamicGL_ProgramUniform3ui
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform3uiv)(GLuint program , GLint location , GLsizei count , const GLuint *value); }
#define glProgramUniform3uiv DynamicGL_ProgramUniform3uiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform4i)(GLuint program , GLint location , GLint v0 , GLint v1 , GLint v2 , GLint v3); }
#define glProgramUniform4i DynamicGL_ProgramUniform4i
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform4iv)(GLuint program , GLint location , GLsizei count , const GLint *value); }
#define glProgramUniform4iv DynamicGL_ProgramUniform4iv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform4f)(GLuint program , GLint location , GLfloat v0 , GLfloat v1 , GLfloat v2 , GLfloat v3); }
#define glProgramUniform4f DynamicGL_ProgramUniform4f
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform4fv)(GLuint program , GLint location , GLsizei count , const GLfloat *value); }
#define glProgramUniform4fv DynamicGL_ProgramUniform4fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform4d)(GLuint program , GLint location , GLdouble v0 , GLdouble v1 , GLdouble v2 , GLdouble v3); }
#define glProgramUniform4d DynamicGL_ProgramUniform4d
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform4dv)(GLuint program , GLint location , GLsizei count , const GLdouble *value); }
#define glProgramUniform4dv DynamicGL_ProgramUniform4dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform4ui)(GLuint program , GLint location , GLuint v0 , GLuint v1 , GLuint v2 , GLuint v3); }
#define glProgramUniform4ui DynamicGL_ProgramUniform4ui
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniform4uiv)(GLuint program , GLint location , GLsizei count , const GLuint *value); }
#define glProgramUniform4uiv DynamicGL_ProgramUniform4uiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix2fv)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value); }
#define glProgramUniformMatrix2fv DynamicGL_ProgramUniformMatrix2fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix3fv)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value); }
#define glProgramUniformMatrix3fv DynamicGL_ProgramUniformMatrix3fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix4fv)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value); }
#define glProgramUniformMatrix4fv DynamicGL_ProgramUniformMatrix4fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix2dv)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLdouble *value); }
#define glProgramUniformMatrix2dv DynamicGL_ProgramUniformMatrix2dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix3dv)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLdouble *value); }
#define glProgramUniformMatrix3dv DynamicGL_ProgramUniformMatrix3dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix4dv)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLdouble *value); }
#define glProgramUniformMatrix4dv DynamicGL_ProgramUniformMatrix4dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix2x3fv)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value); }
#define glProgramUniformMatrix2x3fv DynamicGL_ProgramUniformMatrix2x3fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix3x2fv)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value); }
#define glProgramUniformMatrix3x2fv DynamicGL_ProgramUniformMatrix3x2fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix2x4fv)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value); }
#define glProgramUniformMatrix2x4fv DynamicGL_ProgramUniformMatrix2x4fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix4x2fv)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value); }
#define glProgramUniformMatrix4x2fv DynamicGL_ProgramUniformMatrix4x2fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix3x4fv)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value); }
#define glProgramUniformMatrix3x4fv DynamicGL_ProgramUniformMatrix3x4fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix4x3fv)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLfloat *value); }
#define glProgramUniformMatrix4x3fv DynamicGL_ProgramUniformMatrix4x3fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix2x3dv)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLdouble *value); }
#define glProgramUniformMatrix2x3dv DynamicGL_ProgramUniformMatrix2x3dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix3x2dv)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLdouble *value); }
#define glProgramUniformMatrix3x2dv DynamicGL_ProgramUniformMatrix3x2dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix2x4dv)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLdouble *value); }
#define glProgramUniformMatrix2x4dv DynamicGL_ProgramUniformMatrix2x4dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix4x2dv)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLdouble *value); }
#define glProgramUniformMatrix4x2dv DynamicGL_ProgramUniformMatrix4x2dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix3x4dv)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLdouble *value); }
#define glProgramUniformMatrix3x4dv DynamicGL_ProgramUniformMatrix3x4dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformMatrix4x3dv)(GLuint program , GLint location , GLsizei count , GLboolean transpose , const GLdouble *value); }
#define glProgramUniformMatrix4x3dv DynamicGL_ProgramUniformMatrix4x3dv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ValidateProgramPipeline)(GLuint pipeline); }
#define glValidateProgramPipeline DynamicGL_ValidateProgramPipeline
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramPipelineInfoLog)(GLuint pipeline , GLsizei bufSize , GLsizei *length , GLchar *infoLog); }
#define glGetProgramPipelineInfoLog DynamicGL_GetProgramPipelineInfoLog
extern bool DinamicGLFeature_ARB_separate_shader_objects_Supported();
#endif /*USE_DYNAMIC_GL_ARB_separate_shader_objects*/

/*ATI_texture_float*/
#ifdef USE_DYNAMIC_GL_ATI_texture_float
#define GL_RGBA_FLOAT32_ATI 0x8814
#define GL_RGB_FLOAT32_ATI 0x8815
#define GL_ALPHA_FLOAT32_ATI 0x8816
#define GL_INTENSITY_FLOAT32_ATI 0x8817
#define GL_LUMINANCE_FLOAT32_ATI 0x8818
#define GL_LUMINANCE_ALPHA_FLOAT32_ATI 0x8819
#define GL_RGBA_FLOAT16_ATI 0x881A
#define GL_RGB_FLOAT16_ATI 0x881B
#define GL_ALPHA_FLOAT16_ATI 0x881C
#define GL_INTENSITY_FLOAT16_ATI 0x881D
#define GL_LUMINANCE_FLOAT16_ATI 0x881E
#define GL_LUMINANCE_ALPHA_FLOAT16_ATI 0x881F
extern bool DinamicGLFeature_ATI_texture_float_Supported();
#endif /*USE_DYNAMIC_GL_ATI_texture_float*/

/*EXT_blend_minmax*/
#ifdef USE_DYNAMIC_GL_EXT_blend_minmax
#define GL_FUNC_ADD_EXT 0x8006
#define GL_MIN_EXT 0x8007
#define GL_MAX_EXT 0x8008
#define GL_BLEND_EQUATION_EXT 0x8009
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendEquationEXT)(GLenum mode); }
#define glBlendEquationEXT DynamicGL_BlendEquationEXT
extern bool DinamicGLFeature_EXT_blend_minmax_Supported();
#endif /*USE_DYNAMIC_GL_EXT_blend_minmax*/

/*NV_float_buffer*/
#ifdef USE_DYNAMIC_GL_NV_float_buffer
#define GL_FLOAT_R_NV 0x8880
#define GL_FLOAT_RG_NV 0x8881
#define GL_FLOAT_RGB_NV 0x8882
#define GL_FLOAT_RGBA_NV 0x8883
#define GL_FLOAT_R16_NV 0x8884
#define GL_FLOAT_R32_NV 0x8885
#define GL_FLOAT_RG16_NV 0x8886
#define GL_FLOAT_RG32_NV 0x8887
#define GL_FLOAT_RGB16_NV 0x8888
#define GL_FLOAT_RGB32_NV 0x8889
#define GL_FLOAT_RGBA16_NV 0x888A
#define GL_FLOAT_RGBA32_NV 0x888B
#define GL_TEXTURE_FLOAT_COMPONENTS_NV 0x888C
#define GL_FLOAT_CLEAR_COLOR_VALUE_NV 0x888D
#define GL_FLOAT_RGBA_MODE_NV 0x888E
extern bool DinamicGLFeature_NV_float_buffer_Supported();
#endif /*USE_DYNAMIC_GL_NV_float_buffer*/

/*SGIX_calligraphic_fragment*/
#ifdef USE_DYNAMIC_GL_SGIX_calligraphic_fragment
#define GL_CALLIGRAPHIC_FRAGMENT_SGIX 0x8183
extern bool DinamicGLFeature_SGIX_calligraphic_fragment_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_calligraphic_fragment*/

/*ARB_texture_storage*/
#ifdef USE_DYNAMIC_GL_ARB_texture_storage
#define GL_TEXTURE_IMMUTABLE_FORMAT 0x912F
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexStorage1D)(GLenum target , GLsizei levels , GLenum internalformat , GLsizei width); }
#define glTexStorage1D DynamicGL_TexStorage1D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexStorage2D)(GLenum target , GLsizei levels , GLenum internalformat , GLsizei width , GLsizei height); }
#define glTexStorage2D DynamicGL_TexStorage2D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexStorage3D)(GLenum target , GLsizei levels , GLenum internalformat , GLsizei width , GLsizei height , GLsizei depth); }
#define glTexStorage3D DynamicGL_TexStorage3D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureStorage1DEXT)(GLuint texture , GLenum target , GLsizei levels , GLenum internalformat , GLsizei width); }
#define glTextureStorage1DEXT DynamicGL_TextureStorage1DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureStorage2DEXT)(GLuint texture , GLenum target , GLsizei levels , GLenum internalformat , GLsizei width , GLsizei height); }
#define glTextureStorage2DEXT DynamicGL_TextureStorage2DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureStorage3DEXT)(GLuint texture , GLenum target , GLsizei levels , GLenum internalformat , GLsizei width , GLsizei height , GLsizei depth); }
#define glTextureStorage3DEXT DynamicGL_TextureStorage3DEXT
extern bool DinamicGLFeature_ARB_texture_storage_Supported();
#endif /*USE_DYNAMIC_GL_ARB_texture_storage*/

/*NV_bindless_texture*/
#ifdef USE_DYNAMIC_GL_NV_bindless_texture
extern "C" { extern GLuint64 (DYNAMIC_GL_APIENTRYP DynamicGL_GetTextureHandleNV)(GLuint texture); }
#define glGetTextureHandleNV DynamicGL_GetTextureHandleNV
extern "C" { extern GLuint64 (DYNAMIC_GL_APIENTRYP DynamicGL_GetTextureSamplerHandleNV)(GLuint texture , GLuint sampler); }
#define glGetTextureSamplerHandleNV DynamicGL_GetTextureSamplerHandleNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MakeTextureHandleResidentNV)(GLuint64 handle); }
#define glMakeTextureHandleResidentNV DynamicGL_MakeTextureHandleResidentNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MakeTextureHandleNonResidentNV)(GLuint64 handle); }
#define glMakeTextureHandleNonResidentNV DynamicGL_MakeTextureHandleNonResidentNV
extern "C" { extern GLuint64 (DYNAMIC_GL_APIENTRYP DynamicGL_GetImageHandleNV)(GLuint texture , GLint level , GLboolean layered , GLint layer , GLenum format); }
#define glGetImageHandleNV DynamicGL_GetImageHandleNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MakeImageHandleResidentNV)(GLuint64 handle , GLenum access); }
#define glMakeImageHandleResidentNV DynamicGL_MakeImageHandleResidentNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MakeImageHandleNonResidentNV)(GLuint64 handle); }
#define glMakeImageHandleNonResidentNV DynamicGL_MakeImageHandleNonResidentNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformHandleui64NV)(GLint location , GLuint64 value); }
#define glUniformHandleui64NV DynamicGL_UniformHandleui64NV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformHandleui64vNV)(GLint location , GLsizei count , const GLuint64 *value); }
#define glUniformHandleui64vNV DynamicGL_UniformHandleui64vNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformHandleui64NV)(GLuint program , GLint location , GLuint64 value); }
#define glProgramUniformHandleui64NV DynamicGL_ProgramUniformHandleui64NV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformHandleui64vNV)(GLuint program , GLint location , GLsizei count , const GLuint64 *values); }
#define glProgramUniformHandleui64vNV DynamicGL_ProgramUniformHandleui64vNV
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsTextureHandleResidentNV)(GLuint64 handle); }
#define glIsTextureHandleResidentNV DynamicGL_IsTextureHandleResidentNV
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsImageHandleResidentNV)(GLuint64 handle); }
#define glIsImageHandleResidentNV DynamicGL_IsImageHandleResidentNV
extern bool DinamicGLFeature_NV_bindless_texture_Supported();
#endif /*USE_DYNAMIC_GL_NV_bindless_texture*/

/*SGIX_instruments*/
#ifdef USE_DYNAMIC_GL_SGIX_instruments
#define GL_INSTRUMENT_BUFFER_POINTER_SGIX 0x8180
#define GL_INSTRUMENT_MEASUREMENTS_SGIX 0x8181
extern "C" { extern GLint (DYNAMIC_GL_APIENTRYP DynamicGL_GetInstrumentsSGIX)(); }
#define glGetInstrumentsSGIX DynamicGL_GetInstrumentsSGIX
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_InstrumentsBufferSGIX)(GLsizei size , GLint *buffer); }
#define glInstrumentsBufferSGIX DynamicGL_InstrumentsBufferSGIX
extern "C" { extern GLint (DYNAMIC_GL_APIENTRYP DynamicGL_PollInstrumentsSGIX)(GLint *marker_p); }
#define glPollInstrumentsSGIX DynamicGL_PollInstrumentsSGIX
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ReadInstrumentsSGIX)(GLint marker); }
#define glReadInstrumentsSGIX DynamicGL_ReadInstrumentsSGIX
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_StartInstrumentsSGIX)(); }
#define glStartInstrumentsSGIX DynamicGL_StartInstrumentsSGIX
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_StopInstrumentsSGIX)(GLint marker); }
#define glStopInstrumentsSGIX DynamicGL_StopInstrumentsSGIX
extern bool DinamicGLFeature_SGIX_instruments_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_instruments*/

/*SGIX_fragment_lighting*/
#ifdef USE_DYNAMIC_GL_SGIX_fragment_lighting
#define GL_FRAGMENT_LIGHTING_SGIX 0x8400
#define GL_FRAGMENT_COLOR_MATERIAL_SGIX 0x8401
#define GL_FRAGMENT_COLOR_MATERIAL_FACE_SGIX 0x8402
#define GL_FRAGMENT_COLOR_MATERIAL_PARAMETER_SGIX 0x8403
#define GL_MAX_FRAGMENT_LIGHTS_SGIX 0x8404
#define GL_MAX_ACTIVE_LIGHTS_SGIX 0x8405
#define GL_CURRENT_RASTER_NORMAL_SGIX 0x8406
#define GL_LIGHT_ENV_MODE_SGIX 0x8407
#define GL_FRAGMENT_LIGHT_MODEL_LOCAL_VIEWER_SGIX 0x8408
#define GL_FRAGMENT_LIGHT_MODEL_TWO_SIDE_SGIX 0x8409
#define GL_FRAGMENT_LIGHT_MODEL_AMBIENT_SGIX 0x840A
#define GL_FRAGMENT_LIGHT_MODEL_NORMAL_INTERPOLATION_SGIX 0x840B
#define GL_FRAGMENT_LIGHT0_SGIX 0x840C
#define GL_FRAGMENT_LIGHT1_SGIX 0x840D
#define GL_FRAGMENT_LIGHT2_SGIX 0x840E
#define GL_FRAGMENT_LIGHT3_SGIX 0x840F
#define GL_FRAGMENT_LIGHT4_SGIX 0x8410
#define GL_FRAGMENT_LIGHT5_SGIX 0x8411
#define GL_FRAGMENT_LIGHT6_SGIX 0x8412
#define GL_FRAGMENT_LIGHT7_SGIX 0x8413
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FragmentColorMaterialSGIX)(GLenum face , GLenum mode); }
#define glFragmentColorMaterialSGIX DynamicGL_FragmentColorMaterialSGIX
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FragmentLightfSGIX)(GLenum light , GLenum pname , GLfloat param); }
#define glFragmentLightfSGIX DynamicGL_FragmentLightfSGIX
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FragmentLightfvSGIX)(GLenum light , GLenum pname , const GLfloat *params); }
#define glFragmentLightfvSGIX DynamicGL_FragmentLightfvSGIX
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FragmentLightiSGIX)(GLenum light , GLenum pname , GLint param); }
#define glFragmentLightiSGIX DynamicGL_FragmentLightiSGIX
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FragmentLightivSGIX)(GLenum light , GLenum pname , const GLint *params); }
#define glFragmentLightivSGIX DynamicGL_FragmentLightivSGIX
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FragmentLightModelfSGIX)(GLenum pname , GLfloat param); }
#define glFragmentLightModelfSGIX DynamicGL_FragmentLightModelfSGIX
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FragmentLightModelfvSGIX)(GLenum pname , const GLfloat *params); }
#define glFragmentLightModelfvSGIX DynamicGL_FragmentLightModelfvSGIX
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FragmentLightModeliSGIX)(GLenum pname , GLint param); }
#define glFragmentLightModeliSGIX DynamicGL_FragmentLightModeliSGIX
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FragmentLightModelivSGIX)(GLenum pname , const GLint *params); }
#define glFragmentLightModelivSGIX DynamicGL_FragmentLightModelivSGIX
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FragmentMaterialfSGIX)(GLenum face , GLenum pname , GLfloat param); }
#define glFragmentMaterialfSGIX DynamicGL_FragmentMaterialfSGIX
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FragmentMaterialfvSGIX)(GLenum face , GLenum pname , const GLfloat *params); }
#define glFragmentMaterialfvSGIX DynamicGL_FragmentMaterialfvSGIX
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FragmentMaterialiSGIX)(GLenum face , GLenum pname , GLint param); }
#define glFragmentMaterialiSGIX DynamicGL_FragmentMaterialiSGIX
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FragmentMaterialivSGIX)(GLenum face , GLenum pname , const GLint *params); }
#define glFragmentMaterialivSGIX DynamicGL_FragmentMaterialivSGIX
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFragmentLightfvSGIX)(GLenum light , GLenum pname , GLfloat *params); }
#define glGetFragmentLightfvSGIX DynamicGL_GetFragmentLightfvSGIX
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFragmentLightivSGIX)(GLenum light , GLenum pname , GLint *params); }
#define glGetFragmentLightivSGIX DynamicGL_GetFragmentLightivSGIX
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFragmentMaterialfvSGIX)(GLenum face , GLenum pname , GLfloat *params); }
#define glGetFragmentMaterialfvSGIX DynamicGL_GetFragmentMaterialfvSGIX
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFragmentMaterialivSGIX)(GLenum face , GLenum pname , GLint *params); }
#define glGetFragmentMaterialivSGIX DynamicGL_GetFragmentMaterialivSGIX
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_LightEnviSGIX)(GLenum pname , GLint param); }
#define glLightEnviSGIX DynamicGL_LightEnviSGIX
extern bool DinamicGLFeature_SGIX_fragment_lighting_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_fragment_lighting*/

/*SGIX_ycrcba*/
#ifdef USE_DYNAMIC_GL_SGIX_ycrcba
#define GL_YCRCB_SGIX 0x8318
#define GL_YCRCBA_SGIX 0x8319
extern bool DinamicGLFeature_SGIX_ycrcba_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_ycrcba*/

/*SGIX_texture_coordinate_clamp*/
#ifdef USE_DYNAMIC_GL_SGIX_texture_coordinate_clamp
#define GL_TEXTURE_MAX_CLAMP_S_SGIX 0x8369
#define GL_TEXTURE_MAX_CLAMP_T_SGIX 0x836A
#define GL_TEXTURE_MAX_CLAMP_R_SGIX 0x836B
extern bool DinamicGLFeature_SGIX_texture_coordinate_clamp_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_texture_coordinate_clamp*/

/*S3_s3tc*/
#ifdef USE_DYNAMIC_GL_S3_s3tc
#define GL_RGB_S3TC 0x83A0
#define GL_RGB4_S3TC 0x83A1
#define GL_RGBA_S3TC 0x83A2
#define GL_RGBA4_S3TC 0x83A3
extern bool DinamicGLFeature_S3_s3tc_Supported();
#endif /*USE_DYNAMIC_GL_S3_s3tc*/

/*EXT_422_pixels*/
#ifdef USE_DYNAMIC_GL_EXT_422_pixels
#define GL_422_EXT 0x80CC
#define GL_422_REV_EXT 0x80CD
#define GL_422_AVERAGE_EXT 0x80CE
#define GL_422_REV_AVERAGE_EXT 0x80CF
extern bool DinamicGLFeature_EXT_422_pixels_Supported();
#endif /*USE_DYNAMIC_GL_EXT_422_pixels*/

/*ARB_shader_subroutine*/
#ifdef USE_DYNAMIC_GL_ARB_shader_subroutine
#define GL_ACTIVE_SUBROUTINES 0x8DE5
#define GL_ACTIVE_SUBROUTINE_UNIFORMS 0x8DE6
#define GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS 0x8E47
#define GL_ACTIVE_SUBROUTINE_MAX_LENGTH 0x8E48
#define GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH 0x8E49
#define GL_MAX_SUBROUTINES 0x8DE7
#define GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS 0x8DE8
#define GL_NUM_COMPATIBLE_SUBROUTINES 0x8E4A
#define GL_COMPATIBLE_SUBROUTINES 0x8E4B
extern "C" { extern GLint (DYNAMIC_GL_APIENTRYP DynamicGL_GetSubroutineUniformLocation)(GLuint program , GLenum shadertype , const GLchar *name); }
#define glGetSubroutineUniformLocation DynamicGL_GetSubroutineUniformLocation
extern "C" { extern GLuint (DYNAMIC_GL_APIENTRYP DynamicGL_GetSubroutineIndex)(GLuint program , GLenum shadertype , const GLchar *name); }
#define glGetSubroutineIndex DynamicGL_GetSubroutineIndex
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetActiveSubroutineUniformiv)(GLuint program , GLenum shadertype , GLuint index , GLenum pname , GLint *values); }
#define glGetActiveSubroutineUniformiv DynamicGL_GetActiveSubroutineUniformiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetActiveSubroutineUniformName)(GLuint program , GLenum shadertype , GLuint index , GLsizei bufsize , GLsizei *length , GLchar *name); }
#define glGetActiveSubroutineUniformName DynamicGL_GetActiveSubroutineUniformName
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetActiveSubroutineName)(GLuint program , GLenum shadertype , GLuint index , GLsizei bufsize , GLsizei *length , GLchar *name); }
#define glGetActiveSubroutineName DynamicGL_GetActiveSubroutineName
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformSubroutinesuiv)(GLenum shadertype , GLsizei count , const GLuint *indices); }
#define glUniformSubroutinesuiv DynamicGL_UniformSubroutinesuiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetUniformSubroutineuiv)(GLenum shadertype , GLint location , GLuint *params); }
#define glGetUniformSubroutineuiv DynamicGL_GetUniformSubroutineuiv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetProgramStageiv)(GLuint program , GLenum shadertype , GLenum pname , GLint *values); }
#define glGetProgramStageiv DynamicGL_GetProgramStageiv
extern bool DinamicGLFeature_ARB_shader_subroutine_Supported();
#endif /*USE_DYNAMIC_GL_ARB_shader_subroutine*/

/*NV_transform_feedback*/
#ifdef USE_DYNAMIC_GL_NV_transform_feedback
#define GL_BACK_PRIMARY_COLOR_NV 0x8C77
#define GL_BACK_SECONDARY_COLOR_NV 0x8C78
#define GL_TEXTURE_COORD_NV 0x8C79
#define GL_CLIP_DISTANCE_NV 0x8C7A
#define GL_VERTEX_ID_NV 0x8C7B
#define GL_PRIMITIVE_ID_NV 0x8C7C
#define GL_GENERIC_ATTRIB_NV 0x8C7D
#define GL_TRANSFORM_FEEDBACK_ATTRIBS_NV 0x8C7E
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE_NV 0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_NV 0x8C80
#define GL_ACTIVE_VARYINGS_NV 0x8C81
#define GL_ACTIVE_VARYING_MAX_LENGTH_NV 0x8C82
#define GL_TRANSFORM_FEEDBACK_VARYINGS_NV 0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START_NV 0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_NV 0x8C85
#define GL_TRANSFORM_FEEDBACK_RECORD_NV 0x8C86
#define GL_PRIMITIVES_GENERATED_NV 0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_NV 0x8C88
#define GL_RASTERIZER_DISCARD_NV 0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_ATTRIBS_NV 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_NV 0x8C8B
#define GL_INTERLEAVED_ATTRIBS_NV 0x8C8C
#define GL_SEPARATE_ATTRIBS_NV 0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER_NV 0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_NV 0x8C8F
#define GL_LAYER_NV 0x8DAA
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BeginTransformFeedbackNV)(GLenum primitiveMode); }
#define glBeginTransformFeedbackNV DynamicGL_BeginTransformFeedbackNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EndTransformFeedbackNV)(); }
#define glEndTransformFeedbackNV DynamicGL_EndTransformFeedbackNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TransformFeedbackAttribsNV)(GLuint count , const GLint *attribs , GLenum bufferMode); }
#define glTransformFeedbackAttribsNV DynamicGL_TransformFeedbackAttribsNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindBufferRangeNV)(GLenum target , GLuint index , GLuint buffer , GLintptr offset , GLsizeiptr size); }
#define glBindBufferRangeNV DynamicGL_BindBufferRangeNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindBufferOffsetNV)(GLenum target , GLuint index , GLuint buffer , GLintptr offset); }
#define glBindBufferOffsetNV DynamicGL_BindBufferOffsetNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindBufferBaseNV)(GLenum target , GLuint index , GLuint buffer); }
#define glBindBufferBaseNV DynamicGL_BindBufferBaseNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TransformFeedbackVaryingsNV)(GLuint program , GLsizei count , const GLint *locations , GLenum bufferMode); }
#define glTransformFeedbackVaryingsNV DynamicGL_TransformFeedbackVaryingsNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ActiveVaryingNV)(GLuint program , const GLchar *name); }
#define glActiveVaryingNV DynamicGL_ActiveVaryingNV
extern "C" { extern GLint (DYNAMIC_GL_APIENTRYP DynamicGL_GetVaryingLocationNV)(GLuint program , const GLchar *name); }
#define glGetVaryingLocationNV DynamicGL_GetVaryingLocationNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetActiveVaryingNV)(GLuint program , GLuint index , GLsizei bufSize , GLsizei *length , GLsizei *size , GLenum *type , GLchar *name); }
#define glGetActiveVaryingNV DynamicGL_GetActiveVaryingNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTransformFeedbackVaryingNV)(GLuint program , GLuint index , GLint *location); }
#define glGetTransformFeedbackVaryingNV DynamicGL_GetTransformFeedbackVaryingNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TransformFeedbackStreamAttribsNV)(GLsizei count , const GLint *attribs , GLsizei nbuffers , const GLint *bufstreams , GLenum bufferMode); }
#define glTransformFeedbackStreamAttribsNV DynamicGL_TransformFeedbackStreamAttribsNV
extern bool DinamicGLFeature_NV_transform_feedback_Supported();
#endif /*USE_DYNAMIC_GL_NV_transform_feedback*/

/*SUN_triangle_list*/
#ifdef USE_DYNAMIC_GL_SUN_triangle_list
#define GL_RESTART_SUN 0x0001
#define GL_REPLACE_MIDDLE_SUN 0x0002
#define GL_REPLACE_OLDEST_SUN 0x0003
#define GL_TRIANGLE_LIST_SUN 0x81D7
#define GL_REPLACEMENT_CODE_SUN 0x81D8
#define GL_REPLACEMENT_CODE_ARRAY_SUN 0x85C0
#define GL_REPLACEMENT_CODE_ARRAY_TYPE_SUN 0x85C1
#define GL_REPLACEMENT_CODE_ARRAY_STRIDE_SUN 0x85C2
#define GL_REPLACEMENT_CODE_ARRAY_POINTER_SUN 0x85C3
#define GL_R1UI_V3F_SUN 0x85C4
#define GL_R1UI_C4UB_V3F_SUN 0x85C5
#define GL_R1UI_C3F_V3F_SUN 0x85C6
#define GL_R1UI_N3F_V3F_SUN 0x85C7
#define GL_R1UI_C4F_N3F_V3F_SUN 0x85C8
#define GL_R1UI_T2F_V3F_SUN 0x85C9
#define GL_R1UI_T2F_N3F_V3F_SUN 0x85CA
#define GL_R1UI_T2F_C4F_N3F_V3F_SUN 0x85CB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuiSUN)(GLuint code); }
#define glReplacementCodeuiSUN DynamicGL_ReplacementCodeuiSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeusSUN)(GLushort code); }
#define glReplacementCodeusSUN DynamicGL_ReplacementCodeusSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeubSUN)(GLubyte code); }
#define glReplacementCodeubSUN DynamicGL_ReplacementCodeubSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuivSUN)(const GLuint *code); }
#define glReplacementCodeuivSUN DynamicGL_ReplacementCodeuivSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeusvSUN)(const GLushort *code); }
#define glReplacementCodeusvSUN DynamicGL_ReplacementCodeusvSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeubvSUN)(const GLubyte *code); }
#define glReplacementCodeubvSUN DynamicGL_ReplacementCodeubvSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodePointerSUN)(GLenum type , GLsizei stride , const GLvoid* *pointer); }
#define glReplacementCodePointerSUN DynamicGL_ReplacementCodePointerSUN
extern bool DinamicGLFeature_SUN_triangle_list_Supported();
#endif /*USE_DYNAMIC_GL_SUN_triangle_list*/

/*SGIX_clipmap*/
#ifdef USE_DYNAMIC_GL_SGIX_clipmap
#define GL_LINEAR_CLIPMAP_LINEAR_SGIX 0x8170
#define GL_TEXTURE_CLIPMAP_CENTER_SGIX 0x8171
#define GL_TEXTURE_CLIPMAP_FRAME_SGIX 0x8172
#define GL_TEXTURE_CLIPMAP_OFFSET_SGIX 0x8173
#define GL_TEXTURE_CLIPMAP_VIRTUAL_DEPTH_SGIX 0x8174
#define GL_TEXTURE_CLIPMAP_LOD_OFFSET_SGIX 0x8175
#define GL_TEXTURE_CLIPMAP_DEPTH_SGIX 0x8176
#define GL_MAX_CLIPMAP_DEPTH_SGIX 0x8177
#define GL_MAX_CLIPMAP_VIRTUAL_DEPTH_SGIX 0x8178
#define GL_NEAREST_CLIPMAP_NEAREST_SGIX 0x844D
#define GL_NEAREST_CLIPMAP_LINEAR_SGIX 0x844E
#define GL_LINEAR_CLIPMAP_NEAREST_SGIX 0x844F
extern bool DinamicGLFeature_SGIX_clipmap_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_clipmap*/

/*NV_register_combiners2*/
#ifdef USE_DYNAMIC_GL_NV_register_combiners2
#define GL_PER_STAGE_CONSTANTS_NV 0x8535
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CombinerStageParameterfvNV)(GLenum stage , GLenum pname , const GLfloat *params); }
#define glCombinerStageParameterfvNV DynamicGL_CombinerStageParameterfvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetCombinerStageParameterfvNV)(GLenum stage , GLenum pname , GLfloat *params); }
#define glGetCombinerStageParameterfvNV DynamicGL_GetCombinerStageParameterfvNV
extern bool DinamicGLFeature_NV_register_combiners2_Supported();
#endif /*USE_DYNAMIC_GL_NV_register_combiners2*/

/*VERSION_2_1_DEPRECATED*/
#ifdef USE_DYNAMIC_GL_VERSION_2_1_DEPRECATED
#define GL_CURRENT_RASTER_SECONDARY_COLOR 0x845F
#define GL_SLUMINANCE_ALPHA 0x8C44
#define GL_SLUMINANCE8_ALPHA8 0x8C45
#define GL_SLUMINANCE 0x8C46
#define GL_SLUMINANCE8 0x8C47
#define GL_COMPRESSED_SLUMINANCE 0x8C4A
#define GL_COMPRESSED_SLUMINANCE_ALPHA 0x8C4B
extern bool DinamicGLFeature_VERSION_2_1_DEPRECATED_Supported();
#endif /*USE_DYNAMIC_GL_VERSION_2_1_DEPRECATED*/

/*EXT_clip_volume_hint*/
#ifdef USE_DYNAMIC_GL_EXT_clip_volume_hint
#define GL_CLIP_VOLUME_CLIPPING_HINT_EXT 0x80F0
extern bool DinamicGLFeature_EXT_clip_volume_hint_Supported();
#endif /*USE_DYNAMIC_GL_EXT_clip_volume_hint*/

/*SGIS_point_parameters*/
#ifdef USE_DYNAMIC_GL_SGIS_point_parameters
#define GL_POINT_SIZE_MIN_SGIS 0x8126
#define GL_POINT_SIZE_MAX_SGIS 0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE_SGIS 0x8128
#define GL_DISTANCE_ATTENUATION_SGIS 0x8129
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameterfSGIS)(GLenum pname , GLfloat param); }
#define glPointParameterfSGIS DynamicGL_PointParameterfSGIS
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameterfvSGIS)(GLenum pname , const GLfloat *params); }
#define glPointParameterfvSGIS DynamicGL_PointParameterfvSGIS
extern bool DinamicGLFeature_SGIS_point_parameters_Supported();
#endif /*USE_DYNAMIC_GL_SGIS_point_parameters*/

/*APPLE_transform_hint*/
#ifdef USE_DYNAMIC_GL_APPLE_transform_hint
#define GL_TRANSFORM_HINT_APPLE 0x85B1
extern bool DinamicGLFeature_APPLE_transform_hint_Supported();
#endif /*USE_DYNAMIC_GL_APPLE_transform_hint*/

/*ARB_viewport_array*/
#ifdef USE_DYNAMIC_GL_ARB_viewport_array
#define GL_MAX_VIEWPORTS 0x825B
#define GL_VIEWPORT_SUBPIXEL_BITS 0x825C
#define GL_VIEWPORT_BOUNDS_RANGE 0x825D
#define GL_LAYER_PROVOKING_VERTEX 0x825E
#define GL_VIEWPORT_INDEX_PROVOKING_VERTEX 0x825F
#define GL_UNDEFINED_VERTEX 0x8260
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ViewportArrayv)(GLuint first , GLsizei count , const GLfloat *v); }
#define glViewportArrayv DynamicGL_ViewportArrayv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ViewportIndexedf)(GLuint index , GLfloat x , GLfloat y , GLfloat w , GLfloat h); }
#define glViewportIndexedf DynamicGL_ViewportIndexedf
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ViewportIndexedfv)(GLuint index , const GLfloat *v); }
#define glViewportIndexedfv DynamicGL_ViewportIndexedfv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ScissorArrayv)(GLuint first , GLsizei count , const GLint *v); }
#define glScissorArrayv DynamicGL_ScissorArrayv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ScissorIndexed)(GLuint index , GLint left , GLint bottom , GLsizei width , GLsizei height); }
#define glScissorIndexed DynamicGL_ScissorIndexed
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ScissorIndexedv)(GLuint index , const GLint *v); }
#define glScissorIndexedv DynamicGL_ScissorIndexedv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DepthRangeArrayv)(GLuint first , GLsizei count , const GLdouble *v); }
#define glDepthRangeArrayv DynamicGL_DepthRangeArrayv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DepthRangeIndexed)(GLuint index , GLdouble n , GLdouble f); }
#define glDepthRangeIndexed DynamicGL_DepthRangeIndexed
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetFloati_v)(GLenum target , GLuint index , GLfloat *data); }
#define glGetFloati_v DynamicGL_GetFloati_v
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetDoublei_v)(GLenum target , GLuint index , GLdouble *data); }
#define glGetDoublei_v DynamicGL_GetDoublei_v
extern bool DinamicGLFeature_ARB_viewport_array_Supported();
#endif /*USE_DYNAMIC_GL_ARB_viewport_array*/

/*NV_fragment_program2*/
#ifdef USE_DYNAMIC_GL_NV_fragment_program2
#define GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV 0x88F4
#define GL_MAX_PROGRAM_CALL_DEPTH_NV 0x88F5
#define GL_MAX_PROGRAM_IF_DEPTH_NV 0x88F6
#define GL_MAX_PROGRAM_LOOP_DEPTH_NV 0x88F7
#define GL_MAX_PROGRAM_LOOP_COUNT_NV 0x88F8
extern bool DinamicGLFeature_NV_fragment_program2_Supported();
#endif /*USE_DYNAMIC_GL_NV_fragment_program2*/

/*NV_texture_rectangle*/
#ifdef USE_DYNAMIC_GL_NV_texture_rectangle
#define GL_TEXTURE_RECTANGLE_NV 0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE_NV 0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE_NV 0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE_NV 0x84F8
extern bool DinamicGLFeature_NV_texture_rectangle_Supported();
#endif /*USE_DYNAMIC_GL_NV_texture_rectangle*/

/*SGI_depth_pass_instrument*/
#ifdef USE_DYNAMIC_GL_SGI_depth_pass_instrument
#define GL_DEPTH_PASS_INSTRUMENT_SGIX 0x8310
#define GL_DEPTH_PASS_INSTRUMENT_COUNTERS_SGIX 0x8311
#define GL_DEPTH_PASS_INSTRUMENT_MAX_SGIX 0x8312
extern bool DinamicGLFeature_SGI_depth_pass_instrument_Supported();
#endif /*USE_DYNAMIC_GL_SGI_depth_pass_instrument*/

/*EXT_rescale_normal*/
#ifdef USE_DYNAMIC_GL_EXT_rescale_normal
#define GL_RESCALE_NORMAL_EXT 0x803A
extern bool DinamicGLFeature_EXT_rescale_normal_Supported();
#endif /*USE_DYNAMIC_GL_EXT_rescale_normal*/

/*ARB_pixel_buffer_object*/
#ifdef USE_DYNAMIC_GL_ARB_pixel_buffer_object
#define GL_PIXEL_PACK_BUFFER_ARB 0x88EB
#define GL_PIXEL_UNPACK_BUFFER_ARB 0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING_ARB 0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING_ARB 0x88EF
extern bool DinamicGLFeature_ARB_pixel_buffer_object_Supported();
#endif /*USE_DYNAMIC_GL_ARB_pixel_buffer_object*/

/*EXT_texture3D*/
#ifdef USE_DYNAMIC_GL_EXT_texture3D
#define GL_PACK_SKIP_IMAGES_EXT 0x806B
#define GL_PACK_IMAGE_HEIGHT_EXT 0x806C
#define GL_UNPACK_SKIP_IMAGES_EXT 0x806D
#define GL_UNPACK_IMAGE_HEIGHT_EXT 0x806E
#define GL_TEXTURE_3D_EXT 0x806F
#define GL_PROXY_TEXTURE_3D_EXT 0x8070
#define GL_TEXTURE_DEPTH_EXT 0x8071
#define GL_TEXTURE_WRAP_R_EXT 0x8072
#define GL_MAX_3D_TEXTURE_SIZE_EXT 0x8073
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexImage3DEXT)(GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLsizei depth , GLint border , GLenum format , GLenum type , const GLvoid *pixels); }
#define glTexImage3DEXT DynamicGL_TexImage3DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexSubImage3DEXT)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLsizei width , GLsizei height , GLsizei depth , GLenum format , GLenum type , const GLvoid *pixels); }
#define glTexSubImage3DEXT DynamicGL_TexSubImage3DEXT
extern bool DinamicGLFeature_EXT_texture3D_Supported();
#endif /*USE_DYNAMIC_GL_EXT_texture3D*/

/*EXT_texture_lod_bias*/
#ifdef USE_DYNAMIC_GL_EXT_texture_lod_bias
#define GL_MAX_TEXTURE_LOD_BIAS_EXT 0x84FD
#define GL_TEXTURE_FILTER_CONTROL_EXT 0x8500
#define GL_TEXTURE_LOD_BIAS_EXT 0x8501
extern bool DinamicGLFeature_EXT_texture_lod_bias_Supported();
#endif /*USE_DYNAMIC_GL_EXT_texture_lod_bias*/

/*NV_explicit_multisample*/
#ifdef USE_DYNAMIC_GL_NV_explicit_multisample
#define GL_SAMPLE_POSITION_NV 0x8E50
#define GL_SAMPLE_MASK_NV 0x8E51
#define GL_SAMPLE_MASK_VALUE_NV 0x8E52
#define GL_TEXTURE_BINDING_RENDERBUFFER_NV 0x8E53
#define GL_TEXTURE_RENDERBUFFER_DATA_STORE_BINDING_NV 0x8E54
#define GL_TEXTURE_RENDERBUFFER_NV 0x8E55
#define GL_SAMPLER_RENDERBUFFER_NV 0x8E56
#define GL_INT_SAMPLER_RENDERBUFFER_NV 0x8E57
#define GL_UNSIGNED_INT_SAMPLER_RENDERBUFFER_NV 0x8E58
#define GL_MAX_SAMPLE_MASK_WORDS_NV 0x8E59
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetMultisamplefvNV)(GLenum pname , GLuint index , GLfloat *val); }
#define glGetMultisamplefvNV DynamicGL_GetMultisamplefvNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SampleMaskIndexedNV)(GLuint index , GLbitfield mask); }
#define glSampleMaskIndexedNV DynamicGL_SampleMaskIndexedNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexRenderbufferNV)(GLenum target , GLuint renderbuffer); }
#define glTexRenderbufferNV DynamicGL_TexRenderbufferNV
extern bool DinamicGLFeature_NV_explicit_multisample_Supported();
#endif /*USE_DYNAMIC_GL_NV_explicit_multisample*/

/*ATI_separate_stencil*/
#ifdef USE_DYNAMIC_GL_ATI_separate_stencil
#define GL_STENCIL_BACK_FUNC_ATI 0x8800
#define GL_STENCIL_BACK_FAIL_ATI 0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL_ATI 0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS_ATI 0x8803
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_StencilOpSeparateATI)(GLenum face , GLenum sfail , GLenum dpfail , GLenum dppass); }
#define glStencilOpSeparateATI DynamicGL_StencilOpSeparateATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_StencilFuncSeparateATI)(GLenum frontfunc , GLenum backfunc , GLint ref , GLuint mask); }
#define glStencilFuncSeparateATI DynamicGL_StencilFuncSeparateATI
extern bool DinamicGLFeature_ATI_separate_stencil_Supported();
#endif /*USE_DYNAMIC_GL_ATI_separate_stencil*/

/*APPLE_vertex_array_range*/
#ifdef USE_DYNAMIC_GL_APPLE_vertex_array_range
#define GL_VERTEX_ARRAY_RANGE_APPLE 0x851D
#define GL_VERTEX_ARRAY_RANGE_LENGTH_APPLE 0x851E
#define GL_VERTEX_ARRAY_STORAGE_HINT_APPLE 0x851F
#define GL_VERTEX_ARRAY_RANGE_POINTER_APPLE 0x8521
#define GL_STORAGE_CLIENT_APPLE 0x85B4
#define GL_STORAGE_CACHED_APPLE 0x85BE
#define GL_STORAGE_SHARED_APPLE 0x85BF
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexArrayRangeAPPLE)(GLsizei length , GLvoid *pointer); }
#define glVertexArrayRangeAPPLE DynamicGL_VertexArrayRangeAPPLE
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FlushVertexArrayRangeAPPLE)(GLsizei length , GLvoid *pointer); }
#define glFlushVertexArrayRangeAPPLE DynamicGL_FlushVertexArrayRangeAPPLE
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexArrayParameteriAPPLE)(GLenum pname , GLint param); }
#define glVertexArrayParameteriAPPLE DynamicGL_VertexArrayParameteriAPPLE
extern bool DinamicGLFeature_APPLE_vertex_array_range_Supported();
#endif /*USE_DYNAMIC_GL_APPLE_vertex_array_range*/

/*EXT_vertex_attrib_64bit*/
#ifdef USE_DYNAMIC_GL_EXT_vertex_attrib_64bit
#define GL_DOUBLE_VEC2_EXT 0x8FFC
#define GL_DOUBLE_VEC3_EXT 0x8FFD
#define GL_DOUBLE_VEC4_EXT 0x8FFE
#define GL_DOUBLE_MAT2_EXT 0x8F46
#define GL_DOUBLE_MAT3_EXT 0x8F47
#define GL_DOUBLE_MAT4_EXT 0x8F48
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribL1dEXT)(GLuint index , GLdouble x); }
#define glVertexAttribL1dEXT DynamicGL_VertexAttribL1dEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribL2dEXT)(GLuint index , GLdouble x , GLdouble y); }
#define glVertexAttribL2dEXT DynamicGL_VertexAttribL2dEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribL3dEXT)(GLuint index , GLdouble x , GLdouble y , GLdouble z); }
#define glVertexAttribL3dEXT DynamicGL_VertexAttribL3dEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribL4dEXT)(GLuint index , GLdouble x , GLdouble y , GLdouble z , GLdouble w); }
#define glVertexAttribL4dEXT DynamicGL_VertexAttribL4dEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribL1dvEXT)(GLuint index , const GLdouble *v); }
#define glVertexAttribL1dvEXT DynamicGL_VertexAttribL1dvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribL2dvEXT)(GLuint index , const GLdouble *v); }
#define glVertexAttribL2dvEXT DynamicGL_VertexAttribL2dvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribL3dvEXT)(GLuint index , const GLdouble *v); }
#define glVertexAttribL3dvEXT DynamicGL_VertexAttribL3dvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribL4dvEXT)(GLuint index , const GLdouble *v); }
#define glVertexAttribL4dvEXT DynamicGL_VertexAttribL4dvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribLPointerEXT)(GLuint index , GLint size , GLenum type , GLsizei stride , const GLvoid *pointer); }
#define glVertexAttribLPointerEXT DynamicGL_VertexAttribLPointerEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribLdvEXT)(GLuint index , GLenum pname , GLdouble *params); }
#define glGetVertexAttribLdvEXT DynamicGL_GetVertexAttribLdvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexArrayVertexAttribLOffsetEXT)(GLuint vaobj , GLuint buffer , GLuint index , GLint size , GLenum type , GLsizei stride , GLintptr offset); }
#define glVertexArrayVertexAttribLOffsetEXT DynamicGL_VertexArrayVertexAttribLOffsetEXT
extern bool DinamicGLFeature_EXT_vertex_attrib_64bit_Supported();
#endif /*USE_DYNAMIC_GL_EXT_vertex_attrib_64bit*/

/*NV_conditional_render*/
#ifdef USE_DYNAMIC_GL_NV_conditional_render
#define GL_QUERY_WAIT_NV 0x8E13
#define GL_QUERY_NO_WAIT_NV 0x8E14
#define GL_QUERY_BY_REGION_WAIT_NV 0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT_NV 0x8E16
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BeginConditionalRenderNV)(GLuint id , GLenum mode); }
#define glBeginConditionalRenderNV DynamicGL_BeginConditionalRenderNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EndConditionalRenderNV)(); }
#define glEndConditionalRenderNV DynamicGL_EndConditionalRenderNV
extern bool DinamicGLFeature_NV_conditional_render_Supported();
#endif /*USE_DYNAMIC_GL_NV_conditional_render*/

/*SGIS_point_line_texgen*/
#ifdef USE_DYNAMIC_GL_SGIS_point_line_texgen
#define GL_EYE_DISTANCE_TO_POINT_SGIS 0x81F0
#define GL_OBJECT_DISTANCE_TO_POINT_SGIS 0x81F1
#define GL_EYE_DISTANCE_TO_LINE_SGIS 0x81F2
#define GL_OBJECT_DISTANCE_TO_LINE_SGIS 0x81F3
#define GL_EYE_POINT_SGIS 0x81F4
#define GL_OBJECT_POINT_SGIS 0x81F5
#define GL_EYE_LINE_SGIS 0x81F6
#define GL_OBJECT_LINE_SGIS 0x81F7
extern bool DinamicGLFeature_SGIS_point_line_texgen_Supported();
#endif /*USE_DYNAMIC_GL_SGIS_point_line_texgen*/

/*ARB_blend_func_extended*/
#ifdef USE_DYNAMIC_GL_ARB_blend_func_extended
#define GL_SRC1_COLOR 0x88F9
#define GL_ONE_MINUS_SRC1_COLOR 0x88FA
#define GL_ONE_MINUS_SRC1_ALPHA 0x88FB
#define GL_MAX_DUAL_SOURCE_DRAW_BUFFERS 0x88FC
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindFragDataLocationIndexed)(GLuint program , GLuint colorNumber , GLuint index , const GLchar *name); }
#define glBindFragDataLocationIndexed DynamicGL_BindFragDataLocationIndexed
extern "C" { extern GLint (DYNAMIC_GL_APIENTRYP DynamicGL_GetFragDataIndex)(GLuint program , const GLchar *name); }
#define glGetFragDataIndex DynamicGL_GetFragDataIndex
extern bool DinamicGLFeature_ARB_blend_func_extended_Supported();
#endif /*USE_DYNAMIC_GL_ARB_blend_func_extended*/

/*NV_shader_buffer_load*/
#ifdef USE_DYNAMIC_GL_NV_shader_buffer_load
#define GL_BUFFER_GPU_ADDRESS_NV 0x8F1D
#define GL_GPU_ADDRESS_NV 0x8F34
#define GL_MAX_SHADER_BUFFER_ADDRESS_NV 0x8F35
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MakeBufferResidentNV)(GLenum target , GLenum access); }
#define glMakeBufferResidentNV DynamicGL_MakeBufferResidentNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MakeBufferNonResidentNV)(GLenum target); }
#define glMakeBufferNonResidentNV DynamicGL_MakeBufferNonResidentNV
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsBufferResidentNV)(GLenum target); }
#define glIsBufferResidentNV DynamicGL_IsBufferResidentNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MakeNamedBufferResidentNV)(GLuint buffer , GLenum access); }
#define glMakeNamedBufferResidentNV DynamicGL_MakeNamedBufferResidentNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MakeNamedBufferNonResidentNV)(GLuint buffer); }
#define glMakeNamedBufferNonResidentNV DynamicGL_MakeNamedBufferNonResidentNV
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsNamedBufferResidentNV)(GLuint buffer); }
#define glIsNamedBufferResidentNV DynamicGL_IsNamedBufferResidentNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetBufferParameterui64vNV)(GLenum target , GLenum pname , GLuint64EXT *params); }
#define glGetBufferParameterui64vNV DynamicGL_GetBufferParameterui64vNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetNamedBufferParameterui64vNV)(GLuint buffer , GLenum pname , GLuint64EXT *params); }
#define glGetNamedBufferParameterui64vNV DynamicGL_GetNamedBufferParameterui64vNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetIntegerui64vNV)(GLenum value , GLuint64EXT *result); }
#define glGetIntegerui64vNV DynamicGL_GetIntegerui64vNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniformui64NV)(GLint location , GLuint64EXT value); }
#define glUniformui64NV DynamicGL_Uniformui64NV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Uniformui64vNV)(GLint location , GLsizei count , const GLuint64EXT *value); }
#define glUniformui64vNV DynamicGL_Uniformui64vNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetUniformui64vNV)(GLuint program , GLint location , GLuint64EXT *params); }
#define glGetUniformui64vNV DynamicGL_GetUniformui64vNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformui64NV)(GLuint program , GLint location , GLuint64EXT value); }
#define glProgramUniformui64NV DynamicGL_ProgramUniformui64NV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ProgramUniformui64vNV)(GLuint program , GLint location , GLsizei count , const GLuint64EXT *value); }
#define glProgramUniformui64vNV DynamicGL_ProgramUniformui64vNV
extern bool DinamicGLFeature_NV_shader_buffer_load_Supported();
#endif /*USE_DYNAMIC_GL_NV_shader_buffer_load*/

/*EXT_fog_coord*/
#ifdef USE_DYNAMIC_GL_EXT_fog_coord
#define GL_FOG_COORDINATE_SOURCE_EXT 0x8450
#define GL_FOG_COORDINATE_EXT 0x8451
#define GL_FRAGMENT_DEPTH_EXT 0x8452
#define GL_CURRENT_FOG_COORDINATE_EXT 0x8453
#define GL_FOG_COORDINATE_ARRAY_TYPE_EXT 0x8454
#define GL_FOG_COORDINATE_ARRAY_STRIDE_EXT 0x8455
#define GL_FOG_COORDINATE_ARRAY_POINTER_EXT 0x8456
#define GL_FOG_COORDINATE_ARRAY_EXT 0x8457
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FogCoordfEXT)(GLfloat coord); }
#define glFogCoordfEXT DynamicGL_FogCoordfEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FogCoordfvEXT)(const GLfloat *coord); }
#define glFogCoordfvEXT DynamicGL_FogCoordfvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FogCoorddEXT)(GLdouble coord); }
#define glFogCoorddEXT DynamicGL_FogCoorddEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FogCoorddvEXT)(const GLdouble *coord); }
#define glFogCoorddvEXT DynamicGL_FogCoorddvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FogCoordPointerEXT)(GLenum type , GLsizei stride , const GLvoid *pointer); }
#define glFogCoordPointerEXT DynamicGL_FogCoordPointerEXT
extern bool DinamicGLFeature_EXT_fog_coord_Supported();
#endif /*USE_DYNAMIC_GL_EXT_fog_coord*/

/*ARB_vertex_buffer_object*/
#ifdef USE_DYNAMIC_GL_ARB_vertex_buffer_object
typedef ptrdiff_t GLintptrARB;
typedef ptrdiff_t GLsizeiptrARB;
#define GL_BUFFER_SIZE_ARB 0x8764
#define GL_BUFFER_USAGE_ARB 0x8765
#define GL_ARRAY_BUFFER_ARB 0x8892
#define GL_ELEMENT_ARRAY_BUFFER_ARB 0x8893
#define GL_ARRAY_BUFFER_BINDING_ARB 0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING_ARB 0x8895
#define GL_VERTEX_ARRAY_BUFFER_BINDING_ARB 0x8896
#define GL_NORMAL_ARRAY_BUFFER_BINDING_ARB 0x8897
#define GL_COLOR_ARRAY_BUFFER_BINDING_ARB 0x8898
#define GL_INDEX_ARRAY_BUFFER_BINDING_ARB 0x8899
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB 0x889A
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB 0x889B
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB 0x889C
#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB 0x889D
#define GL_WEIGHT_ARRAY_BUFFER_BINDING_ARB 0x889E
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB 0x889F
#define GL_READ_ONLY_ARB 0x88B8
#define GL_WRITE_ONLY_ARB 0x88B9
#define GL_READ_WRITE_ARB 0x88BA
#define GL_BUFFER_ACCESS_ARB 0x88BB
#define GL_BUFFER_MAPPED_ARB 0x88BC
#define GL_BUFFER_MAP_POINTER_ARB 0x88BD
#define GL_STREAM_DRAW_ARB 0x88E0
#define GL_STREAM_READ_ARB 0x88E1
#define GL_STREAM_COPY_ARB 0x88E2
#define GL_STATIC_DRAW_ARB 0x88E4
#define GL_STATIC_READ_ARB 0x88E5
#define GL_STATIC_COPY_ARB 0x88E6
#define GL_DYNAMIC_DRAW_ARB 0x88E8
#define GL_DYNAMIC_READ_ARB 0x88E9
#define GL_DYNAMIC_COPY_ARB 0x88EA
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindBufferARB)(GLenum target , GLuint buffer); }
#define glBindBufferARB DynamicGL_BindBufferARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteBuffersARB)(GLsizei n , const GLuint *buffers); }
#define glDeleteBuffersARB DynamicGL_DeleteBuffersARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GenBuffersARB)(GLsizei n , GLuint *buffers); }
#define glGenBuffersARB DynamicGL_GenBuffersARB
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsBufferARB)(GLuint buffer); }
#define glIsBufferARB DynamicGL_IsBufferARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BufferDataARB)(GLenum target , GLsizeiptrARB size , const GLvoid *data , GLenum usage); }
#define glBufferDataARB DynamicGL_BufferDataARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BufferSubDataARB)(GLenum target , GLintptrARB offset , GLsizeiptrARB size , const GLvoid *data); }
#define glBufferSubDataARB DynamicGL_BufferSubDataARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetBufferSubDataARB)(GLenum target , GLintptrARB offset , GLsizeiptrARB size , GLvoid *data); }
#define glGetBufferSubDataARB DynamicGL_GetBufferSubDataARB
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_UnmapBufferARB)(GLenum target); }
#define glUnmapBufferARB DynamicGL_UnmapBufferARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetBufferParameterivARB)(GLenum target , GLenum pname , GLint *params); }
#define glGetBufferParameterivARB DynamicGL_GetBufferParameterivARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetBufferPointervARB)(GLenum target , GLenum pname , GLvoid* *params); }
#define glGetBufferPointervARB DynamicGL_GetBufferPointervARB
extern bool DinamicGLFeature_ARB_vertex_buffer_object_Supported();
#endif /*USE_DYNAMIC_GL_ARB_vertex_buffer_object*/

/*VERSION_1_4*/
#ifdef USE_DYNAMIC_GL_VERSION_1_4
#define GL_BLEND_DST_RGB 0x80C8
#define GL_BLEND_SRC_RGB 0x80C9
#define GL_BLEND_DST_ALPHA 0x80CA
#define GL_BLEND_SRC_ALPHA 0x80CB
#define GL_POINT_FADE_THRESHOLD_SIZE 0x8128
#define GL_DEPTH_COMPONENT16 0x81A5
#define GL_DEPTH_COMPONENT24 0x81A6
#define GL_DEPTH_COMPONENT32 0x81A7
#define GL_MIRRORED_REPEAT 0x8370
#define GL_MAX_TEXTURE_LOD_BIAS 0x84FD
#define GL_TEXTURE_LOD_BIAS 0x8501
#define GL_INCR_WRAP 0x8507
#define GL_DECR_WRAP 0x8508
#define GL_TEXTURE_DEPTH_SIZE 0x884A
#define GL_TEXTURE_COMPARE_MODE 0x884C
#define GL_TEXTURE_COMPARE_FUNC 0x884D
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendFuncSeparate)(GLenum sfactorRGB , GLenum dfactorRGB , GLenum sfactorAlpha , GLenum dfactorAlpha); }
#define glBlendFuncSeparate DynamicGL_BlendFuncSeparate
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiDrawArrays)(GLenum mode , const GLint *first , const GLsizei *count , GLsizei primcount); }
#define glMultiDrawArrays DynamicGL_MultiDrawArrays
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MultiDrawElements)(GLenum mode , const GLsizei *count , GLenum type , const GLvoid* const , GLsizei primcount); }
#define glMultiDrawElements DynamicGL_MultiDrawElements
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameterf)(GLenum pname , GLfloat param); }
#define glPointParameterf DynamicGL_PointParameterf
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameterfv)(GLenum pname , const GLfloat *params); }
#define glPointParameterfv DynamicGL_PointParameterfv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameteri)(GLenum pname , GLint param); }
#define glPointParameteri DynamicGL_PointParameteri
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameteriv)(GLenum pname , const GLint *params); }
#define glPointParameteriv DynamicGL_PointParameteriv
extern bool DinamicGLFeature_VERSION_1_4_Supported();
#endif /*USE_DYNAMIC_GL_VERSION_1_4*/

/*APPLE_specular_vector*/
#ifdef USE_DYNAMIC_GL_APPLE_specular_vector
#define GL_LIGHT_MODEL_SPECULAR_VECTOR_APPLE 0x85B0
extern bool DinamicGLFeature_APPLE_specular_vector_Supported();
#endif /*USE_DYNAMIC_GL_APPLE_specular_vector*/

/*EXT_shader_image_load_store*/
#ifdef USE_DYNAMIC_GL_EXT_shader_image_load_store
#define GL_MAX_IMAGE_UNITS_EXT 0x8F38
#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS_EXT 0x8F39
#define GL_IMAGE_BINDING_NAME_EXT 0x8F3A
#define GL_IMAGE_BINDING_LEVEL_EXT 0x8F3B
#define GL_IMAGE_BINDING_LAYERED_EXT 0x8F3C
#define GL_IMAGE_BINDING_LAYER_EXT 0x8F3D
#define GL_IMAGE_BINDING_ACCESS_EXT 0x8F3E
#define GL_IMAGE_1D_EXT 0x904C
#define GL_IMAGE_2D_EXT 0x904D
#define GL_IMAGE_3D_EXT 0x904E
#define GL_IMAGE_2D_RECT_EXT 0x904F
#define GL_IMAGE_CUBE_EXT 0x9050
#define GL_IMAGE_BUFFER_EXT 0x9051
#define GL_IMAGE_1D_ARRAY_EXT 0x9052
#define GL_IMAGE_2D_ARRAY_EXT 0x9053
#define GL_IMAGE_CUBE_MAP_ARRAY_EXT 0x9054
#define GL_IMAGE_2D_MULTISAMPLE_EXT 0x9055
#define GL_IMAGE_2D_MULTISAMPLE_ARRAY_EXT 0x9056
#define GL_INT_IMAGE_1D_EXT 0x9057
#define GL_INT_IMAGE_2D_EXT 0x9058
#define GL_INT_IMAGE_3D_EXT 0x9059
#define GL_INT_IMAGE_2D_RECT_EXT 0x905A
#define GL_INT_IMAGE_CUBE_EXT 0x905B
#define GL_INT_IMAGE_BUFFER_EXT 0x905C
#define GL_INT_IMAGE_1D_ARRAY_EXT 0x905D
#define GL_INT_IMAGE_2D_ARRAY_EXT 0x905E
#define GL_INT_IMAGE_CUBE_MAP_ARRAY_EXT 0x905F
#define GL_INT_IMAGE_2D_MULTISAMPLE_EXT 0x9060
#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT 0x9061
#define GL_UNSIGNED_INT_IMAGE_1D_EXT 0x9062
#define GL_UNSIGNED_INT_IMAGE_2D_EXT 0x9063
#define GL_UNSIGNED_INT_IMAGE_3D_EXT 0x9064
#define GL_UNSIGNED_INT_IMAGE_2D_RECT_EXT 0x9065
#define GL_UNSIGNED_INT_IMAGE_CUBE_EXT 0x9066
#define GL_UNSIGNED_INT_IMAGE_BUFFER_EXT 0x9067
#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY_EXT 0x9068
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY_EXT 0x9069
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY_EXT 0x906A
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_EXT 0x906B
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT 0x906C
#define GL_MAX_IMAGE_SAMPLES_EXT 0x906D
#define GL_IMAGE_BINDING_FORMAT_EXT 0x906E
#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT_EXT 0x00000001
#define GL_ELEMENT_ARRAY_BARRIER_BIT_EXT 0x00000002
#define GL_UNIFORM_BARRIER_BIT_EXT 0x00000004
#define GL_TEXTURE_FETCH_BARRIER_BIT_EXT 0x00000008
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT_EXT 0x00000020
#define GL_COMMAND_BARRIER_BIT_EXT 0x00000040
#define GL_PIXEL_BUFFER_BARRIER_BIT_EXT 0x00000080
#define GL_TEXTURE_UPDATE_BARRIER_BIT_EXT 0x00000100
#define GL_BUFFER_UPDATE_BARRIER_BIT_EXT 0x00000200
#define GL_FRAMEBUFFER_BARRIER_BIT_EXT 0x00000400
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT_EXT 0x00000800
#define GL_ATOMIC_COUNTER_BARRIER_BIT_EXT 0x00001000
#define GL_ALL_BARRIER_BITS_EXT 0xFFFFFFFF
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindImageTextureEXT)(GLuint index , GLuint texture , GLint level , GLboolean layered , GLint layer , GLenum access , GLint format); }
#define glBindImageTextureEXT DynamicGL_BindImageTextureEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MemoryBarrierEXT)(GLbitfield barriers); }
#define glMemoryBarrierEXT DynamicGL_MemoryBarrierEXT
extern bool DinamicGLFeature_EXT_shader_image_load_store_Supported();
#endif /*USE_DYNAMIC_GL_EXT_shader_image_load_store*/

/*NV_copy_depth_to_color*/
#ifdef USE_DYNAMIC_GL_NV_copy_depth_to_color
#define GL_DEPTH_STENCIL_TO_RGBA_NV 0x886E
#define GL_DEPTH_STENCIL_TO_BGRA_NV 0x886F
extern bool DinamicGLFeature_NV_copy_depth_to_color_Supported();
#endif /*USE_DYNAMIC_GL_NV_copy_depth_to_color*/

/*ARB_cl_event*/
#ifdef USE_DYNAMIC_GL_ARB_cl_event
#define GL_SYNC_CL_EVENT_ARB 0x8240
#define GL_SYNC_CL_EVENT_COMPLETE_ARB 0x8241
extern "C" { extern GLsync (DYNAMIC_GL_APIENTRYP DynamicGL_CreateSyncFromCLeventARB)(GLstruct _cl_context , GLstruct _cl_event , GLbitfield flags); }
#define glCreateSyncFromCLeventARB DynamicGL_CreateSyncFromCLeventARB
extern bool DinamicGLFeature_ARB_cl_event_Supported();
#endif /*USE_DYNAMIC_GL_ARB_cl_event*/

/*ARB_texture_cube_map*/
#ifdef USE_DYNAMIC_GL_ARB_texture_cube_map
#define GL_NORMAL_MAP_ARB 0x8511
#define GL_REFLECTION_MAP_ARB 0x8512
#define GL_TEXTURE_CUBE_MAP_ARB 0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP_ARB 0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB 0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB 0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB 0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB 0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB 0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB 0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARB 0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB 0x851C
extern bool DinamicGLFeature_ARB_texture_cube_map_Supported();
#endif /*USE_DYNAMIC_GL_ARB_texture_cube_map*/

/*NV_vertex_array_range*/
#ifdef USE_DYNAMIC_GL_NV_vertex_array_range
#define GL_VERTEX_ARRAY_RANGE_NV 0x851D
#define GL_VERTEX_ARRAY_RANGE_LENGTH_NV 0x851E
#define GL_VERTEX_ARRAY_RANGE_VALID_NV 0x851F
#define GL_MAX_VERTEX_ARRAY_RANGE_ELEMENT_NV 0x8520
#define GL_VERTEX_ARRAY_RANGE_POINTER_NV 0x8521
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FlushVertexArrayRangeNV)(); }
#define glFlushVertexArrayRangeNV DynamicGL_FlushVertexArrayRangeNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexArrayRangeNV)(GLsizei length , const GLvoid *pointer); }
#define glVertexArrayRangeNV DynamicGL_VertexArrayRangeNV
extern bool DinamicGLFeature_NV_vertex_array_range_Supported();
#endif /*USE_DYNAMIC_GL_NV_vertex_array_range*/

/*VERSION_2_0_DEPRECATED*/
#ifdef USE_DYNAMIC_GL_VERSION_2_0_DEPRECATED
#define GL_VERTEX_PROGRAM_TWO_SIDE 0x8643
#define GL_POINT_SPRITE 0x8861
#define GL_COORD_REPLACE 0x8862
#define GL_MAX_TEXTURE_COORDS 0x8871
extern bool DinamicGLFeature_VERSION_2_0_DEPRECATED_Supported();
#endif /*USE_DYNAMIC_GL_VERSION_2_0_DEPRECATED*/

/*EXT_cull_vertex*/
#ifdef USE_DYNAMIC_GL_EXT_cull_vertex
#define GL_CULL_VERTEX_EXT 0x81AA
#define GL_CULL_VERTEX_EYE_POSITION_EXT 0x81AB
#define GL_CULL_VERTEX_OBJECT_POSITION_EXT 0x81AC
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CullParameterdvEXT)(GLenum pname , GLdouble *params); }
#define glCullParameterdvEXT DynamicGL_CullParameterdvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CullParameterfvEXT)(GLenum pname , GLfloat *params); }
#define glCullParameterfvEXT DynamicGL_CullParameterfvEXT
extern bool DinamicGLFeature_EXT_cull_vertex_Supported();
#endif /*USE_DYNAMIC_GL_EXT_cull_vertex*/

/*FfdMaskSGIX*/
#ifdef USE_DYNAMIC_GL_FfdMaskSGIX
#define GL_TEXTURE_DEFORMATION_BIT_SGIX 0x00000001
#define GL_GEOMETRY_DEFORMATION_BIT_SGIX 0x00000002
extern bool DinamicGLFeature_FfdMaskSGIX_Supported();
#endif /*USE_DYNAMIC_GL_FfdMaskSGIX*/

/*OES_read_format*/
#ifdef USE_DYNAMIC_GL_OES_read_format
#define GL_IMPLEMENTATION_COLOR_READ_TYPE_OES 0x8B9A
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT_OES 0x8B9B
extern bool DinamicGLFeature_OES_read_format_Supported();
#endif /*USE_DYNAMIC_GL_OES_read_format*/

/*INGR_blend_func_separate*/
#ifdef USE_DYNAMIC_GL_INGR_blend_func_separate
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendFuncSeparateINGR)(GLenum sfactorRGB , GLenum dfactorRGB , GLenum sfactorAlpha , GLenum dfactorAlpha); }
#define glBlendFuncSeparateINGR DynamicGL_BlendFuncSeparateINGR
extern bool DinamicGLFeature_INGR_blend_func_separate_Supported();
#endif /*USE_DYNAMIC_GL_INGR_blend_func_separate*/

/*ARB_draw_indirect*/
#ifdef USE_DYNAMIC_GL_ARB_draw_indirect
#define GL_DRAW_INDIRECT_BUFFER 0x8F3F
#define GL_DRAW_INDIRECT_BUFFER_BINDING 0x8F43
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawArraysIndirect)(GLenum mode , const GLvoid *indirect); }
#define glDrawArraysIndirect DynamicGL_DrawArraysIndirect
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawElementsIndirect)(GLenum mode , GLenum type , const GLvoid *indirect); }
#define glDrawElementsIndirect DynamicGL_DrawElementsIndirect
extern bool DinamicGLFeature_ARB_draw_indirect_Supported();
#endif /*USE_DYNAMIC_GL_ARB_draw_indirect*/

/*APPLE_client_storage*/
#ifdef USE_DYNAMIC_GL_APPLE_client_storage
#define GL_UNPACK_CLIENT_STORAGE_APPLE 0x85B2
extern bool DinamicGLFeature_APPLE_client_storage_Supported();
#endif /*USE_DYNAMIC_GL_APPLE_client_storage*/

/*ATI_envmap_bumpmap*/
#ifdef USE_DYNAMIC_GL_ATI_envmap_bumpmap
#define GL_BUMP_ROT_MATRIX_ATI 0x8775
#define GL_BUMP_ROT_MATRIX_SIZE_ATI 0x8776
#define GL_BUMP_NUM_TEX_UNITS_ATI 0x8777
#define GL_BUMP_TEX_UNITS_ATI 0x8778
#define GL_DUDV_ATI 0x8779
#define GL_DU8DV8_ATI 0x877A
#define GL_BUMP_ENVMAP_ATI 0x877B
#define GL_BUMP_TARGET_ATI 0x877C
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexBumpParameterivATI)(GLenum pname , const GLint *param); }
#define glTexBumpParameterivATI DynamicGL_TexBumpParameterivATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexBumpParameterfvATI)(GLenum pname , const GLfloat *param); }
#define glTexBumpParameterfvATI DynamicGL_TexBumpParameterfvATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexBumpParameterivATI)(GLenum pname , GLint *param); }
#define glGetTexBumpParameterivATI DynamicGL_GetTexBumpParameterivATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexBumpParameterfvATI)(GLenum pname , GLfloat *param); }
#define glGetTexBumpParameterfvATI DynamicGL_GetTexBumpParameterfvATI
extern bool DinamicGLFeature_ATI_envmap_bumpmap_Supported();
#endif /*USE_DYNAMIC_GL_ATI_envmap_bumpmap*/

/*ATI_vertex_array_object*/
#ifdef USE_DYNAMIC_GL_ATI_vertex_array_object
#define GL_STATIC_ATI 0x8760
#define GL_DYNAMIC_ATI 0x8761
#define GL_PRESERVE_ATI 0x8762
#define GL_DISCARD_ATI 0x8763
#define GL_OBJECT_BUFFER_SIZE_ATI 0x8764
#define GL_OBJECT_BUFFER_USAGE_ATI 0x8765
#define GL_ARRAY_OBJECT_BUFFER_ATI 0x8766
#define GL_ARRAY_OBJECT_OFFSET_ATI 0x8767
extern "C" { extern GLuint (DYNAMIC_GL_APIENTRYP DynamicGL_NewObjectBufferATI)(GLsizei size , const GLvoid *pointer , GLenum usage); }
#define glNewObjectBufferATI DynamicGL_NewObjectBufferATI
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsObjectBufferATI)(GLuint buffer); }
#define glIsObjectBufferATI DynamicGL_IsObjectBufferATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_UpdateObjectBufferATI)(GLuint buffer , GLuint offset , GLsizei size , const GLvoid *pointer , GLenum preserve); }
#define glUpdateObjectBufferATI DynamicGL_UpdateObjectBufferATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetObjectBufferfvATI)(GLuint buffer , GLenum pname , GLfloat *params); }
#define glGetObjectBufferfvATI DynamicGL_GetObjectBufferfvATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetObjectBufferivATI)(GLuint buffer , GLenum pname , GLint *params); }
#define glGetObjectBufferivATI DynamicGL_GetObjectBufferivATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FreeObjectBufferATI)(GLuint buffer); }
#define glFreeObjectBufferATI DynamicGL_FreeObjectBufferATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ArrayObjectATI)(GLenum array , GLint size , GLenum type , GLsizei stride , GLuint buffer , GLuint offset); }
#define glArrayObjectATI DynamicGL_ArrayObjectATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetArrayObjectfvATI)(GLenum array , GLenum pname , GLfloat *params); }
#define glGetArrayObjectfvATI DynamicGL_GetArrayObjectfvATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetArrayObjectivATI)(GLenum array , GLenum pname , GLint *params); }
#define glGetArrayObjectivATI DynamicGL_GetArrayObjectivATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VariantArrayObjectATI)(GLuint id , GLenum type , GLsizei stride , GLuint buffer , GLuint offset); }
#define glVariantArrayObjectATI DynamicGL_VariantArrayObjectATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVariantArrayObjectfvATI)(GLuint id , GLenum pname , GLfloat *params); }
#define glGetVariantArrayObjectfvATI DynamicGL_GetVariantArrayObjectfvATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVariantArrayObjectivATI)(GLuint id , GLenum pname , GLint *params); }
#define glGetVariantArrayObjectivATI DynamicGL_GetVariantArrayObjectivATI
extern bool DinamicGLFeature_ATI_vertex_array_object_Supported();
#endif /*USE_DYNAMIC_GL_ATI_vertex_array_object*/

/*SGIX_async_pixel*/
#ifdef USE_DYNAMIC_GL_SGIX_async_pixel
#define GL_ASYNC_TEX_IMAGE_SGIX 0x835C
#define GL_ASYNC_DRAW_PIXELS_SGIX 0x835D
#define GL_ASYNC_READ_PIXELS_SGIX 0x835E
#define GL_MAX_ASYNC_TEX_IMAGE_SGIX 0x835F
#define GL_MAX_ASYNC_DRAW_PIXELS_SGIX 0x8360
#define GL_MAX_ASYNC_READ_PIXELS_SGIX 0x8361
extern bool DinamicGLFeature_SGIX_async_pixel_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_async_pixel*/

/*ATI_text_fragment_shader*/
#ifdef USE_DYNAMIC_GL_ATI_text_fragment_shader
#define GL_TEXT_FRAGMENT_SHADER_ATI 0x8200
extern bool DinamicGLFeature_ATI_text_fragment_shader_Supported();
#endif /*USE_DYNAMIC_GL_ATI_text_fragment_shader*/

/*ARB_point_parameters*/
#ifdef USE_DYNAMIC_GL_ARB_point_parameters
#define GL_POINT_SIZE_MIN_ARB 0x8126
#define GL_POINT_SIZE_MAX_ARB 0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE_ARB 0x8128
#define GL_POINT_DISTANCE_ATTENUATION_ARB 0x8129
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameterfARB)(GLenum pname , GLfloat param); }
#define glPointParameterfARB DynamicGL_PointParameterfARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PointParameterfvARB)(GLenum pname , const GLfloat *params); }
#define glPointParameterfvARB DynamicGL_PointParameterfvARB
extern bool DinamicGLFeature_ARB_point_parameters_Supported();
#endif /*USE_DYNAMIC_GL_ARB_point_parameters*/

/*EXT_pixel_buffer_object*/
#ifdef USE_DYNAMIC_GL_EXT_pixel_buffer_object
#define GL_PIXEL_PACK_BUFFER_EXT 0x88EB
#define GL_PIXEL_UNPACK_BUFFER_EXT 0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING_EXT 0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING_EXT 0x88EF
extern bool DinamicGLFeature_EXT_pixel_buffer_object_Supported();
#endif /*USE_DYNAMIC_GL_EXT_pixel_buffer_object*/

/*EXT_vertex_array*/
#ifdef USE_DYNAMIC_GL_EXT_vertex_array
#define GL_VERTEX_ARRAY_EXT 0x8074
#define GL_NORMAL_ARRAY_EXT 0x8075
#define GL_COLOR_ARRAY_EXT 0x8076
#define GL_INDEX_ARRAY_EXT 0x8077
#define GL_TEXTURE_COORD_ARRAY_EXT 0x8078
#define GL_EDGE_FLAG_ARRAY_EXT 0x8079
#define GL_VERTEX_ARRAY_SIZE_EXT 0x807A
#define GL_VERTEX_ARRAY_TYPE_EXT 0x807B
#define GL_VERTEX_ARRAY_STRIDE_EXT 0x807C
#define GL_VERTEX_ARRAY_COUNT_EXT 0x807D
#define GL_NORMAL_ARRAY_TYPE_EXT 0x807E
#define GL_NORMAL_ARRAY_STRIDE_EXT 0x807F
#define GL_NORMAL_ARRAY_COUNT_EXT 0x8080
#define GL_COLOR_ARRAY_SIZE_EXT 0x8081
#define GL_COLOR_ARRAY_TYPE_EXT 0x8082
#define GL_COLOR_ARRAY_STRIDE_EXT 0x8083
#define GL_COLOR_ARRAY_COUNT_EXT 0x8084
#define GL_INDEX_ARRAY_TYPE_EXT 0x8085
#define GL_INDEX_ARRAY_STRIDE_EXT 0x8086
#define GL_INDEX_ARRAY_COUNT_EXT 0x8087
#define GL_TEXTURE_COORD_ARRAY_SIZE_EXT 0x8088
#define GL_TEXTURE_COORD_ARRAY_TYPE_EXT 0x8089
#define GL_TEXTURE_COORD_ARRAY_STRIDE_EXT 0x808A
#define GL_TEXTURE_COORD_ARRAY_COUNT_EXT 0x808B
#define GL_EDGE_FLAG_ARRAY_STRIDE_EXT 0x808C
#define GL_EDGE_FLAG_ARRAY_COUNT_EXT 0x808D
#define GL_VERTEX_ARRAY_POINTER_EXT 0x808E
#define GL_NORMAL_ARRAY_POINTER_EXT 0x808F
#define GL_COLOR_ARRAY_POINTER_EXT 0x8090
#define GL_INDEX_ARRAY_POINTER_EXT 0x8091
#define GL_TEXTURE_COORD_ARRAY_POINTER_EXT 0x8092
#define GL_EDGE_FLAG_ARRAY_POINTER_EXT 0x8093
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ArrayElementEXT)(GLint i); }
#define glArrayElementEXT DynamicGL_ArrayElementEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorPointerEXT)(GLint size , GLenum type , GLsizei stride , GLsizei count , const GLvoid *pointer); }
#define glColorPointerEXT DynamicGL_ColorPointerEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawArraysEXT)(GLenum mode , GLint first , GLsizei count); }
#define glDrawArraysEXT DynamicGL_DrawArraysEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EdgeFlagPointerEXT)(GLsizei stride , GLsizei count , const GLboolean *pointer); }
#define glEdgeFlagPointerEXT DynamicGL_EdgeFlagPointerEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetPointervEXT)(GLenum pname , GLvoid* *params); }
#define glGetPointervEXT DynamicGL_GetPointervEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_IndexPointerEXT)(GLenum type , GLsizei stride , GLsizei count , const GLvoid *pointer); }
#define glIndexPointerEXT DynamicGL_IndexPointerEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NormalPointerEXT)(GLenum type , GLsizei stride , GLsizei count , const GLvoid *pointer); }
#define glNormalPointerEXT DynamicGL_NormalPointerEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoordPointerEXT)(GLint size , GLenum type , GLsizei stride , GLsizei count , const GLvoid *pointer); }
#define glTexCoordPointerEXT DynamicGL_TexCoordPointerEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexPointerEXT)(GLint size , GLenum type , GLsizei stride , GLsizei count , const GLvoid *pointer); }
#define glVertexPointerEXT DynamicGL_VertexPointerEXT
extern bool DinamicGLFeature_EXT_vertex_array_Supported();
#endif /*USE_DYNAMIC_GL_EXT_vertex_array*/

/*EXT_index_array_formats*/
#ifdef USE_DYNAMIC_GL_EXT_index_array_formats
#define GL_IUI_V2F_EXT 0x81AD
#define GL_IUI_V3F_EXT 0x81AE
#define GL_IUI_N3F_V2F_EXT 0x81AF
#define GL_IUI_N3F_V3F_EXT 0x81B0
#define GL_T2F_IUI_V2F_EXT 0x81B1
#define GL_T2F_IUI_V3F_EXT 0x81B2
#define GL_T2F_IUI_N3F_V2F_EXT 0x81B3
#define GL_T2F_IUI_N3F_V3F_EXT 0x81B4
extern bool DinamicGLFeature_EXT_index_array_formats_Supported();
#endif /*USE_DYNAMIC_GL_EXT_index_array_formats*/

/*ARB_vertex_array_object*/
#ifdef USE_DYNAMIC_GL_ARB_vertex_array_object
#define GL_VERTEX_ARRAY_BINDING 0x85B5
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindVertexArray)(GLuint array); }
#define glBindVertexArray DynamicGL_BindVertexArray
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteVertexArrays)(GLsizei n , const GLuint *arrays); }
#define glDeleteVertexArrays DynamicGL_DeleteVertexArrays
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GenVertexArrays)(GLsizei n , GLuint *arrays); }
#define glGenVertexArrays DynamicGL_GenVertexArrays
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsVertexArray)(GLuint array); }
#define glIsVertexArray DynamicGL_IsVertexArray
extern bool DinamicGLFeature_ARB_vertex_array_object_Supported();
#endif /*USE_DYNAMIC_GL_ARB_vertex_array_object*/

/*NV_texture_multisample*/
#ifdef USE_DYNAMIC_GL_NV_texture_multisample
#define GL_TEXTURE_COVERAGE_SAMPLES_NV 0x9045
#define GL_TEXTURE_COLOR_SAMPLES_NV 0x9046
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexImage2DMultisampleCoverageNV)(GLenum target , GLsizei coverageSamples , GLsizei colorSamples , GLint internalFormat , GLsizei width , GLsizei height , GLboolean fixedSampleLocations); }
#define glTexImage2DMultisampleCoverageNV DynamicGL_TexImage2DMultisampleCoverageNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexImage3DMultisampleCoverageNV)(GLenum target , GLsizei coverageSamples , GLsizei colorSamples , GLint internalFormat , GLsizei width , GLsizei height , GLsizei depth , GLboolean fixedSampleLocations); }
#define glTexImage3DMultisampleCoverageNV DynamicGL_TexImage3DMultisampleCoverageNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureImage2DMultisampleNV)(GLuint texture , GLenum target , GLsizei samples , GLint internalFormat , GLsizei width , GLsizei height , GLboolean fixedSampleLocations); }
#define glTextureImage2DMultisampleNV DynamicGL_TextureImage2DMultisampleNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureImage3DMultisampleNV)(GLuint texture , GLenum target , GLsizei samples , GLint internalFormat , GLsizei width , GLsizei height , GLsizei depth , GLboolean fixedSampleLocations); }
#define glTextureImage3DMultisampleNV DynamicGL_TextureImage3DMultisampleNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureImage2DMultisampleCoverageNV)(GLuint texture , GLenum target , GLsizei coverageSamples , GLsizei colorSamples , GLint internalFormat , GLsizei width , GLsizei height , GLboolean fixedSampleLocations); }
#define glTextureImage2DMultisampleCoverageNV DynamicGL_TextureImage2DMultisampleCoverageNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TextureImage3DMultisampleCoverageNV)(GLuint texture , GLenum target , GLsizei coverageSamples , GLsizei colorSamples , GLint internalFormat , GLsizei width , GLsizei height , GLsizei depth , GLboolean fixedSampleLocations); }
#define glTextureImage3DMultisampleCoverageNV DynamicGL_TextureImage3DMultisampleCoverageNV
extern bool DinamicGLFeature_NV_texture_multisample_Supported();
#endif /*USE_DYNAMIC_GL_NV_texture_multisample*/

/*ARB_occlusion_query2*/
#ifdef USE_DYNAMIC_GL_ARB_occlusion_query2
#define GL_ANY_SAMPLES_PASSED 0x8C2F
extern bool DinamicGLFeature_ARB_occlusion_query2_Supported();
#endif /*USE_DYNAMIC_GL_ARB_occlusion_query2*/

/*IBM_vertex_array_lists*/
#ifdef USE_DYNAMIC_GL_IBM_vertex_array_lists
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorPointerListIBM)(GLint size , GLenum type , GLint stride , const GLvoid* *pointer , GLint ptrstride); }
#define glColorPointerListIBM DynamicGL_ColorPointerListIBM
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SecondaryColorPointerListIBM)(GLint size , GLenum type , GLint stride , const GLvoid* *pointer , GLint ptrstride); }
#define glSecondaryColorPointerListIBM DynamicGL_SecondaryColorPointerListIBM
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_EdgeFlagPointerListIBM)(GLint stride , const GLboolean* *pointer , GLint ptrstride); }
#define glEdgeFlagPointerListIBM DynamicGL_EdgeFlagPointerListIBM
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FogCoordPointerListIBM)(GLenum type , GLint stride , const GLvoid* *pointer , GLint ptrstride); }
#define glFogCoordPointerListIBM DynamicGL_FogCoordPointerListIBM
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_IndexPointerListIBM)(GLenum type , GLint stride , const GLvoid* *pointer , GLint ptrstride); }
#define glIndexPointerListIBM DynamicGL_IndexPointerListIBM
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_NormalPointerListIBM)(GLenum type , GLint stride , const GLvoid* *pointer , GLint ptrstride); }
#define glNormalPointerListIBM DynamicGL_NormalPointerListIBM
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoordPointerListIBM)(GLint size , GLenum type , GLint stride , const GLvoid* *pointer , GLint ptrstride); }
#define glTexCoordPointerListIBM DynamicGL_TexCoordPointerListIBM
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexPointerListIBM)(GLint size , GLenum type , GLint stride , const GLvoid* *pointer , GLint ptrstride); }
#define glVertexPointerListIBM DynamicGL_VertexPointerListIBM
extern bool DinamicGLFeature_IBM_vertex_array_lists_Supported();
#endif /*USE_DYNAMIC_GL_IBM_vertex_array_lists*/

/*EXT_texture_compression_rgtc*/
#ifdef USE_DYNAMIC_GL_EXT_texture_compression_rgtc
#define GL_COMPRESSED_RED_RGTC1_EXT 0x8DBB
#define GL_COMPRESSED_SIGNED_RED_RGTC1_EXT 0x8DBC
#define GL_COMPRESSED_RED_GREEN_RGTC2_EXT 0x8DBD
#define GL_COMPRESSED_SIGNED_RED_GREEN_RGTC2_EXT 0x8DBE
extern bool DinamicGLFeature_EXT_texture_compression_rgtc_Supported();
#endif /*USE_DYNAMIC_GL_EXT_texture_compression_rgtc*/

/*ATI_draw_buffers*/
#ifdef USE_DYNAMIC_GL_ATI_draw_buffers
#define GL_MAX_DRAW_BUFFERS_ATI 0x8824
#define GL_DRAW_BUFFER0_ATI 0x8825
#define GL_DRAW_BUFFER1_ATI 0x8826
#define GL_DRAW_BUFFER2_ATI 0x8827
#define GL_DRAW_BUFFER3_ATI 0x8828
#define GL_DRAW_BUFFER4_ATI 0x8829
#define GL_DRAW_BUFFER5_ATI 0x882A
#define GL_DRAW_BUFFER6_ATI 0x882B
#define GL_DRAW_BUFFER7_ATI 0x882C
#define GL_DRAW_BUFFER8_ATI 0x882D
#define GL_DRAW_BUFFER9_ATI 0x882E
#define GL_DRAW_BUFFER10_ATI 0x882F
#define GL_DRAW_BUFFER11_ATI 0x8830
#define GL_DRAW_BUFFER12_ATI 0x8831
#define GL_DRAW_BUFFER13_ATI 0x8832
#define GL_DRAW_BUFFER14_ATI 0x8833
#define GL_DRAW_BUFFER15_ATI 0x8834
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawBuffersATI)(GLsizei n , const GLenum *bufs); }
#define glDrawBuffersATI DynamicGL_DrawBuffersATI
extern bool DinamicGLFeature_ATI_draw_buffers_Supported();
#endif /*USE_DYNAMIC_GL_ATI_draw_buffers*/

/*ARB_texture_compression*/
#ifdef USE_DYNAMIC_GL_ARB_texture_compression
#define GL_COMPRESSED_ALPHA_ARB 0x84E9
#define GL_COMPRESSED_LUMINANCE_ARB 0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA_ARB 0x84EB
#define GL_COMPRESSED_INTENSITY_ARB 0x84EC
#define GL_COMPRESSED_RGB_ARB 0x84ED
#define GL_COMPRESSED_RGBA_ARB 0x84EE
#define GL_TEXTURE_COMPRESSION_HINT_ARB 0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB 0x86A0
#define GL_TEXTURE_COMPRESSED_ARB 0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB 0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS_ARB 0x86A3
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTexImage3DARB)(GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLsizei depth , GLint border , GLsizei imageSize , const GLvoid *data); }
#define glCompressedTexImage3DARB DynamicGL_CompressedTexImage3DARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTexImage2DARB)(GLenum target , GLint level , GLenum internalformat , GLsizei width , GLsizei height , GLint border , GLsizei imageSize , const GLvoid *data); }
#define glCompressedTexImage2DARB DynamicGL_CompressedTexImage2DARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTexImage1DARB)(GLenum target , GLint level , GLenum internalformat , GLsizei width , GLint border , GLsizei imageSize , const GLvoid *data); }
#define glCompressedTexImage1DARB DynamicGL_CompressedTexImage1DARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTexSubImage3DARB)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLint zoffset , GLsizei width , GLsizei height , GLsizei depth , GLenum format , GLsizei imageSize , const GLvoid *data); }
#define glCompressedTexSubImage3DARB DynamicGL_CompressedTexSubImage3DARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTexSubImage2DARB)(GLenum target , GLint level , GLint xoffset , GLint yoffset , GLsizei width , GLsizei height , GLenum format , GLsizei imageSize , const GLvoid *data); }
#define glCompressedTexSubImage2DARB DynamicGL_CompressedTexSubImage2DARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CompressedTexSubImage1DARB)(GLenum target , GLint level , GLint xoffset , GLsizei width , GLenum format , GLsizei imageSize , const GLvoid *data); }
#define glCompressedTexSubImage1DARB DynamicGL_CompressedTexSubImage1DARB
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetCompressedTexImageARB)(GLenum target , GLint level , GLvoid *img); }
#define glGetCompressedTexImageARB DynamicGL_GetCompressedTexImageARB
extern bool DinamicGLFeature_ARB_texture_compression_Supported();
#endif /*USE_DYNAMIC_GL_ARB_texture_compression*/

/*VERSION_2_1*/
#ifdef USE_DYNAMIC_GL_VERSION_2_1
#define GL_PIXEL_PACK_BUFFER 0x88EB
#define GL_PIXEL_UNPACK_BUFFER 0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING 0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING 0x88EF
#define GL_SRGB 0x8C40
#define GL_SRGB8 0x8C41
#define GL_SRGB_ALPHA 0x8C42
#define GL_SRGB8_ALPHA8 0x8C43
#define GL_COMPRESSED_SRGB 0x8C48
#define GL_COMPRESSED_SRGB_ALPHA 0x8C49
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformMatrix2x3fv)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value); }
#define glUniformMatrix2x3fv DynamicGL_UniformMatrix2x3fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformMatrix3x2fv)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value); }
#define glUniformMatrix3x2fv DynamicGL_UniformMatrix3x2fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformMatrix2x4fv)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value); }
#define glUniformMatrix2x4fv DynamicGL_UniformMatrix2x4fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformMatrix4x2fv)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value); }
#define glUniformMatrix4x2fv DynamicGL_UniformMatrix4x2fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformMatrix3x4fv)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value); }
#define glUniformMatrix3x4fv DynamicGL_UniformMatrix3x4fv
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_UniformMatrix4x3fv)(GLint location , GLsizei count , GLboolean transpose , const GLfloat *value); }
#define glUniformMatrix4x3fv DynamicGL_UniformMatrix4x3fv
extern bool DinamicGLFeature_VERSION_2_1_Supported();
#endif /*USE_DYNAMIC_GL_VERSION_2_1*/

/*EXT_color_subtable*/
#ifdef USE_DYNAMIC_GL_EXT_color_subtable
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ColorSubTableEXT)(GLenum target , GLsizei start , GLsizei count , GLenum format , GLenum type , const GLvoid *data); }
#define glColorSubTableEXT DynamicGL_ColorSubTableEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyColorSubTableEXT)(GLenum target , GLsizei start , GLint x , GLint y , GLsizei width); }
#define glCopyColorSubTableEXT DynamicGL_CopyColorSubTableEXT
extern bool DinamicGLFeature_EXT_color_subtable_Supported();
#endif /*USE_DYNAMIC_GL_EXT_color_subtable*/

/*VERSION_3_0_DEPRECATED*/
#ifdef USE_DYNAMIC_GL_VERSION_3_0_DEPRECATED
#define GL_CLAMP_VERTEX_COLOR 0x891A
#define GL_CLAMP_FRAGMENT_COLOR 0x891B
#define GL_ALPHA_INTEGER 0x8D97
extern bool DinamicGLFeature_VERSION_3_0_DEPRECATED_Supported();
#endif /*USE_DYNAMIC_GL_VERSION_3_0_DEPRECATED*/

/*EXT_convolution*/
#ifdef USE_DYNAMIC_GL_EXT_convolution
#define GL_CONVOLUTION_1D_EXT 0x8010
#define GL_CONVOLUTION_2D_EXT 0x8011
#define GL_SEPARABLE_2D_EXT 0x8012
#define GL_CONVOLUTION_BORDER_MODE_EXT 0x8013
#define GL_CONVOLUTION_FILTER_SCALE_EXT 0x8014
#define GL_CONVOLUTION_FILTER_BIAS_EXT 0x8015
#define GL_REDUCE_EXT 0x8016
#define GL_CONVOLUTION_FORMAT_EXT 0x8017
#define GL_CONVOLUTION_WIDTH_EXT 0x8018
#define GL_CONVOLUTION_HEIGHT_EXT 0x8019
#define GL_MAX_CONVOLUTION_WIDTH_EXT 0x801A
#define GL_MAX_CONVOLUTION_HEIGHT_EXT 0x801B
#define GL_POST_CONVOLUTION_RED_SCALE_EXT 0x801C
#define GL_POST_CONVOLUTION_GREEN_SCALE_EXT 0x801D
#define GL_POST_CONVOLUTION_BLUE_SCALE_EXT 0x801E
#define GL_POST_CONVOLUTION_ALPHA_SCALE_EXT 0x801F
#define GL_POST_CONVOLUTION_RED_BIAS_EXT 0x8020
#define GL_POST_CONVOLUTION_GREEN_BIAS_EXT 0x8021
#define GL_POST_CONVOLUTION_BLUE_BIAS_EXT 0x8022
#define GL_POST_CONVOLUTION_ALPHA_BIAS_EXT 0x8023
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ConvolutionFilter1DEXT)(GLenum target , GLenum internalformat , GLsizei width , GLenum format , GLenum type , const GLvoid *image); }
#define glConvolutionFilter1DEXT DynamicGL_ConvolutionFilter1DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ConvolutionFilter2DEXT)(GLenum target , GLenum internalformat , GLsizei width , GLsizei height , GLenum format , GLenum type , const GLvoid *image); }
#define glConvolutionFilter2DEXT DynamicGL_ConvolutionFilter2DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ConvolutionParameterfEXT)(GLenum target , GLenum pname , GLfloat params); }
#define glConvolutionParameterfEXT DynamicGL_ConvolutionParameterfEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ConvolutionParameterfvEXT)(GLenum target , GLenum pname , const GLfloat *params); }
#define glConvolutionParameterfvEXT DynamicGL_ConvolutionParameterfvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ConvolutionParameteriEXT)(GLenum target , GLenum pname , GLint params); }
#define glConvolutionParameteriEXT DynamicGL_ConvolutionParameteriEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ConvolutionParameterivEXT)(GLenum target , GLenum pname , const GLint *params); }
#define glConvolutionParameterivEXT DynamicGL_ConvolutionParameterivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyConvolutionFilter1DEXT)(GLenum target , GLenum internalformat , GLint x , GLint y , GLsizei width); }
#define glCopyConvolutionFilter1DEXT DynamicGL_CopyConvolutionFilter1DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_CopyConvolutionFilter2DEXT)(GLenum target , GLenum internalformat , GLint x , GLint y , GLsizei width , GLsizei height); }
#define glCopyConvolutionFilter2DEXT DynamicGL_CopyConvolutionFilter2DEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetConvolutionFilterEXT)(GLenum target , GLenum format , GLenum type , GLvoid *image); }
#define glGetConvolutionFilterEXT DynamicGL_GetConvolutionFilterEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetConvolutionParameterfvEXT)(GLenum target , GLenum pname , GLfloat *params); }
#define glGetConvolutionParameterfvEXT DynamicGL_GetConvolutionParameterfvEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetConvolutionParameterivEXT)(GLenum target , GLenum pname , GLint *params); }
#define glGetConvolutionParameterivEXT DynamicGL_GetConvolutionParameterivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetSeparableFilterEXT)(GLenum target , GLenum format , GLenum type , GLvoid *row , GLvoid *column , GLvoid *span); }
#define glGetSeparableFilterEXT DynamicGL_GetSeparableFilterEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_SeparableFilter2DEXT)(GLenum target , GLenum internalformat , GLsizei width , GLsizei height , GLenum format , GLenum type , const GLvoid *row , const GLvoid *column); }
#define glSeparableFilter2DEXT DynamicGL_SeparableFilter2DEXT
extern bool DinamicGLFeature_EXT_convolution_Supported();
#endif /*USE_DYNAMIC_GL_EXT_convolution*/

/*VERSION_4_0*/
#ifdef USE_DYNAMIC_GL_VERSION_4_0
#define GL_SAMPLE_SHADING 0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE 0x8C37
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5F
#define GL_TEXTURE_CUBE_MAP_ARRAY 0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY 0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY 0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY 0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW 0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY 0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY 0x900F
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_MinSampleShading)(GLfloat value); }
#define glMinSampleShading DynamicGL_MinSampleShading
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendEquationi)(GLuint buf , GLenum mode); }
#define glBlendEquationi DynamicGL_BlendEquationi
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendEquationSeparatei)(GLuint buf , GLenum modeRGB , GLenum modeAlpha); }
#define glBlendEquationSeparatei DynamicGL_BlendEquationSeparatei
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendFunci)(GLuint buf , GLenum src , GLenum dst); }
#define glBlendFunci DynamicGL_BlendFunci
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BlendFuncSeparatei)(GLuint buf , GLenum srcRGB , GLenum dstRGB , GLenum srcAlpha , GLenum dstAlpha); }
#define glBlendFuncSeparatei DynamicGL_BlendFuncSeparatei
extern bool DinamicGLFeature_VERSION_4_0_Supported();
#endif /*USE_DYNAMIC_GL_VERSION_4_0*/

/*EXT_texture_integer*/
#ifdef USE_DYNAMIC_GL_EXT_texture_integer
#define GL_RGBA32UI_EXT 0x8D70
#define GL_RGB32UI_EXT 0x8D71
#define GL_ALPHA32UI_EXT 0x8D72
#define GL_INTENSITY32UI_EXT 0x8D73
#define GL_LUMINANCE32UI_EXT 0x8D74
#define GL_LUMINANCE_ALPHA32UI_EXT 0x8D75
#define GL_RGBA16UI_EXT 0x8D76
#define GL_RGB16UI_EXT 0x8D77
#define GL_ALPHA16UI_EXT 0x8D78
#define GL_INTENSITY16UI_EXT 0x8D79
#define GL_LUMINANCE16UI_EXT 0x8D7A
#define GL_LUMINANCE_ALPHA16UI_EXT 0x8D7B
#define GL_RGBA8UI_EXT 0x8D7C
#define GL_RGB8UI_EXT 0x8D7D
#define GL_ALPHA8UI_EXT 0x8D7E
#define GL_INTENSITY8UI_EXT 0x8D7F
#define GL_LUMINANCE8UI_EXT 0x8D80
#define GL_LUMINANCE_ALPHA8UI_EXT 0x8D81
#define GL_RGBA32I_EXT 0x8D82
#define GL_RGB32I_EXT 0x8D83
#define GL_ALPHA32I_EXT 0x8D84
#define GL_INTENSITY32I_EXT 0x8D85
#define GL_LUMINANCE32I_EXT 0x8D86
#define GL_LUMINANCE_ALPHA32I_EXT 0x8D87
#define GL_RGBA16I_EXT 0x8D88
#define GL_RGB16I_EXT 0x8D89
#define GL_ALPHA16I_EXT 0x8D8A
#define GL_INTENSITY16I_EXT 0x8D8B
#define GL_LUMINANCE16I_EXT 0x8D8C
#define GL_LUMINANCE_ALPHA16I_EXT 0x8D8D
#define GL_RGBA8I_EXT 0x8D8E
#define GL_RGB8I_EXT 0x8D8F
#define GL_ALPHA8I_EXT 0x8D90
#define GL_INTENSITY8I_EXT 0x8D91
#define GL_LUMINANCE8I_EXT 0x8D92
#define GL_LUMINANCE_ALPHA8I_EXT 0x8D93
#define GL_RED_INTEGER_EXT 0x8D94
#define GL_GREEN_INTEGER_EXT 0x8D95
#define GL_BLUE_INTEGER_EXT 0x8D96
#define GL_ALPHA_INTEGER_EXT 0x8D97
#define GL_RGB_INTEGER_EXT 0x8D98
#define GL_RGBA_INTEGER_EXT 0x8D99
#define GL_BGR_INTEGER_EXT 0x8D9A
#define GL_BGRA_INTEGER_EXT 0x8D9B
#define GL_LUMINANCE_INTEGER_EXT 0x8D9C
#define GL_LUMINANCE_ALPHA_INTEGER_EXT 0x8D9D
#define GL_RGBA_INTEGER_MODE_EXT 0x8D9E
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexParameterIivEXT)(GLenum target , GLenum pname , const GLint *params); }
#define glTexParameterIivEXT DynamicGL_TexParameterIivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexParameterIuivEXT)(GLenum target , GLenum pname , const GLuint *params); }
#define glTexParameterIuivEXT DynamicGL_TexParameterIuivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexParameterIivEXT)(GLenum target , GLenum pname , GLint *params); }
#define glGetTexParameterIivEXT DynamicGL_GetTexParameterIivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetTexParameterIuivEXT)(GLenum target , GLenum pname , GLuint *params); }
#define glGetTexParameterIuivEXT DynamicGL_GetTexParameterIuivEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearColorIiEXT)(GLint red , GLint green , GLint blue , GLint alpha); }
#define glClearColorIiEXT DynamicGL_ClearColorIiEXT
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ClearColorIuiEXT)(GLuint red , GLuint green , GLuint blue , GLuint alpha); }
#define glClearColorIuiEXT DynamicGL_ClearColorIuiEXT
extern bool DinamicGLFeature_EXT_texture_integer_Supported();
#endif /*USE_DYNAMIC_GL_EXT_texture_integer*/

/*SGIX_fog_offset*/
#ifdef USE_DYNAMIC_GL_SGIX_fog_offset
#define GL_FOG_OFFSET_SGIX 0x8198
#define GL_FOG_OFFSET_VALUE_SGIX 0x8199
extern bool DinamicGLFeature_SGIX_fog_offset_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_fog_offset*/

/*ATI_vertex_attrib_array_object*/
#ifdef USE_DYNAMIC_GL_ATI_vertex_attrib_array_object
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribArrayObjectATI)(GLuint index , GLint size , GLenum type , GLboolean normalized , GLsizei stride , GLuint buffer , GLuint offset); }
#define glVertexAttribArrayObjectATI DynamicGL_VertexAttribArrayObjectATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribArrayObjectfvATI)(GLuint index , GLenum pname , GLfloat *params); }
#define glGetVertexAttribArrayObjectfvATI DynamicGL_GetVertexAttribArrayObjectfvATI
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetVertexAttribArrayObjectivATI)(GLuint index , GLenum pname , GLint *params); }
#define glGetVertexAttribArrayObjectivATI DynamicGL_GetVertexAttribArrayObjectivATI
extern bool DinamicGLFeature_ATI_vertex_attrib_array_object_Supported();
#endif /*USE_DYNAMIC_GL_ATI_vertex_attrib_array_object*/

/*EXT_packed_float*/
#ifdef USE_DYNAMIC_GL_EXT_packed_float
#define GL_R11F_G11F_B10F_EXT 0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV_EXT 0x8C3B
#define GL_RGBA_SIGNED_COMPONENTS_EXT 0x8C3C
extern bool DinamicGLFeature_EXT_packed_float_Supported();
#endif /*USE_DYNAMIC_GL_EXT_packed_float*/

/*NV_texture_shader*/
#ifdef USE_DYNAMIC_GL_NV_texture_shader
#define GL_OFFSET_TEXTURE_RECTANGLE_NV 0x864C
#define GL_OFFSET_TEXTURE_RECTANGLE_SCALE_NV 0x864D
#define GL_DOT_PRODUCT_TEXTURE_RECTANGLE_NV 0x864E
#define GL_RGBA_UNSIGNED_DOT_PRODUCT_MAPPING_NV 0x86D9
#define GL_UNSIGNED_INT_S8_S8_8_8_NV 0x86DA
#define GL_UNSIGNED_INT_8_8_S8_S8_REV_NV 0x86DB
#define GL_DSDT_MAG_INTENSITY_NV 0x86DC
#define GL_SHADER_CONSISTENT_NV 0x86DD
#define GL_TEXTURE_SHADER_NV 0x86DE
#define GL_SHADER_OPERATION_NV 0x86DF
#define GL_CULL_MODES_NV 0x86E0
#define GL_OFFSET_TEXTURE_MATRIX_NV 0x86E1
#define GL_OFFSET_TEXTURE_SCALE_NV 0x86E2
#define GL_OFFSET_TEXTURE_BIAS_NV 0x86E3
#define GL_PREVIOUS_TEXTURE_INPUT_NV 0x86E4
#define GL_CONST_EYE_NV 0x86E5
#define GL_PASS_THROUGH_NV 0x86E6
#define GL_CULL_FRAGMENT_NV 0x86E7
#define GL_OFFSET_TEXTURE_2D_NV 0x86E8
#define GL_DEPENDENT_AR_TEXTURE_2D_NV 0x86E9
#define GL_DEPENDENT_GB_TEXTURE_2D_NV 0x86EA
#define GL_DOT_PRODUCT_NV 0x86EC
#define GL_DOT_PRODUCT_DEPTH_REPLACE_NV 0x86ED
#define GL_DOT_PRODUCT_TEXTURE_2D_NV 0x86EE
#define GL_DOT_PRODUCT_TEXTURE_CUBE_MAP_NV 0x86F0
#define GL_DOT_PRODUCT_DIFFUSE_CUBE_MAP_NV 0x86F1
#define GL_DOT_PRODUCT_REFLECT_CUBE_MAP_NV 0x86F2
#define GL_DOT_PRODUCT_CONST_EYE_REFLECT_CUBE_MAP_NV 0x86F3
#define GL_HILO_NV 0x86F4
#define GL_DSDT_NV 0x86F5
#define GL_DSDT_MAG_NV 0x86F6
#define GL_DSDT_MAG_VIB_NV 0x86F7
#define GL_HILO16_NV 0x86F8
#define GL_SIGNED_HILO_NV 0x86F9
#define GL_SIGNED_HILO16_NV 0x86FA
#define GL_SIGNED_RGBA_NV 0x86FB
#define GL_SIGNED_RGBA8_NV 0x86FC
#define GL_SIGNED_RGB_NV 0x86FE
#define GL_SIGNED_RGB8_NV 0x86FF
#define GL_SIGNED_LUMINANCE_NV 0x8701
#define GL_SIGNED_LUMINANCE8_NV 0x8702
#define GL_SIGNED_LUMINANCE_ALPHA_NV 0x8703
#define GL_SIGNED_LUMINANCE8_ALPHA8_NV 0x8704
#define GL_SIGNED_ALPHA_NV 0x8705
#define GL_SIGNED_ALPHA8_NV 0x8706
#define GL_SIGNED_INTENSITY_NV 0x8707
#define GL_SIGNED_INTENSITY8_NV 0x8708
#define GL_DSDT8_NV 0x8709
#define GL_DSDT8_MAG8_NV 0x870A
#define GL_DSDT8_MAG8_INTENSITY8_NV 0x870B
#define GL_SIGNED_RGB_UNSIGNED_ALPHA_NV 0x870C
#define GL_SIGNED_RGB8_UNSIGNED_ALPHA8_NV 0x870D
#define GL_HI_SCALE_NV 0x870E
#define GL_LO_SCALE_NV 0x870F
#define GL_DS_SCALE_NV 0x8710
#define GL_DT_SCALE_NV 0x8711
#define GL_MAGNITUDE_SCALE_NV 0x8712
#define GL_VIBRANCE_SCALE_NV 0x8713
#define GL_HI_BIAS_NV 0x8714
#define GL_LO_BIAS_NV 0x8715
#define GL_DS_BIAS_NV 0x8716
#define GL_DT_BIAS_NV 0x8717
#define GL_MAGNITUDE_BIAS_NV 0x8718
#define GL_VIBRANCE_BIAS_NV 0x8719
#define GL_TEXTURE_BORDER_VALUES_NV 0x871A
#define GL_TEXTURE_HI_SIZE_NV 0x871B
#define GL_TEXTURE_LO_SIZE_NV 0x871C
#define GL_TEXTURE_DS_SIZE_NV 0x871D
#define GL_TEXTURE_DT_SIZE_NV 0x871E
#define GL_TEXTURE_MAG_SIZE_NV 0x871F
extern bool DinamicGLFeature_NV_texture_shader_Supported();
#endif /*USE_DYNAMIC_GL_NV_texture_shader*/

/*SGIX_shadow*/
#ifdef USE_DYNAMIC_GL_SGIX_shadow
#define GL_TEXTURE_COMPARE_SGIX 0x819A
#define GL_TEXTURE_COMPARE_OPERATOR_SGIX 0x819B
#define GL_TEXTURE_LEQUAL_R_SGIX 0x819C
#define GL_TEXTURE_GEQUAL_R_SGIX 0x819D
extern bool DinamicGLFeature_SGIX_shadow_Supported();
#endif /*USE_DYNAMIC_GL_SGIX_shadow*/

/*VERSION_3_2*/
#ifdef USE_DYNAMIC_GL_VERSION_3_2
#define GL_CONTEXT_CORE_PROFILE_BIT 0x00000001
#define GL_CONTEXT_COMPATIBILITY_PROFILE_BIT 0x00000002
#define GL_LINES_ADJACENCY 0x000A
#define GL_LINE_STRIP_ADJACENCY 0x000B
#define GL_TRIANGLES_ADJACENCY 0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY 0x000D
#define GL_PROGRAM_POINT_SIZE 0x8642
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS 0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS 0x8DA8
#define GL_GEOMETRY_SHADER 0x8DD9
#define GL_GEOMETRY_VERTICES_OUT 0x8916
#define GL_GEOMETRY_INPUT_TYPE 0x8917
#define GL_GEOMETRY_OUTPUT_TYPE 0x8918
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS 0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES 0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS 0x8DE1
#define GL_MAX_VERTEX_OUTPUT_COMPONENTS 0x9122
#define GL_MAX_GEOMETRY_INPUT_COMPONENTS 0x9123
#define GL_MAX_GEOMETRY_OUTPUT_COMPONENTS 0x9124
#define GL_MAX_FRAGMENT_INPUT_COMPONENTS 0x9125
#define GL_CONTEXT_PROFILE_MASK 0x9126
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetInteger64i_v)(GLenum target , GLuint index , GLint64 *data); }
#define glGetInteger64i_v DynamicGL_GetInteger64i_v
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GetBufferParameteri64v)(GLenum target , GLenum pname , GLint64 *params); }
#define glGetBufferParameteri64v DynamicGL_GetBufferParameteri64v
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_FramebufferTexture)(GLenum target , GLenum attachment , GLuint texture , GLint level); }
#define glFramebufferTexture DynamicGL_FramebufferTexture
extern bool DinamicGLFeature_VERSION_3_2_Supported();
#endif /*USE_DYNAMIC_GL_VERSION_3_2*/

/*ARB_half_float_pixel*/
#ifdef USE_DYNAMIC_GL_ARB_half_float_pixel
typedef unsigned short GLhalfARB;
#define GL_HALF_FLOAT_ARB 0x140B
extern bool DinamicGLFeature_ARB_half_float_pixel_Supported();
#endif /*USE_DYNAMIC_GL_ARB_half_float_pixel*/

/*NV_primitive_restart*/
#ifdef USE_DYNAMIC_GL_NV_primitive_restart
#define GL_PRIMITIVE_RESTART_NV 0x8558
#define GL_PRIMITIVE_RESTART_INDEX_NV 0x8559
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PrimitiveRestartNV)(); }
#define glPrimitiveRestartNV DynamicGL_PrimitiveRestartNV
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PrimitiveRestartIndexNV)(GLuint index); }
#define glPrimitiveRestartIndexNV DynamicGL_PrimitiveRestartIndexNV
extern bool DinamicGLFeature_NV_primitive_restart_Supported();
#endif /*USE_DYNAMIC_GL_NV_primitive_restart*/

/*ARB_base_instance*/
#ifdef USE_DYNAMIC_GL_ARB_base_instance
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawArraysInstancedBaseInstance)(GLenum mode , GLint first , GLsizei count , GLsizei primcount , GLuint baseinstance); }
#define glDrawArraysInstancedBaseInstance DynamicGL_DrawArraysInstancedBaseInstance
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawElementsInstancedBaseInstance)(GLenum mode , GLsizei count , GLenum type , const GLvoid *indices , GLsizei primcount , GLuint baseinstance); }
#define glDrawElementsInstancedBaseInstance DynamicGL_DrawElementsInstancedBaseInstance
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawElementsInstancedBaseVertexBaseInstance)(GLenum mode , GLsizei count , GLenum type , const GLvoid *indices , GLsizei primcount , GLint basevertex , GLuint baseinstance); }
#define glDrawElementsInstancedBaseVertexBaseInstance DynamicGL_DrawElementsInstancedBaseVertexBaseInstance
extern bool DinamicGLFeature_ARB_base_instance_Supported();
#endif /*USE_DYNAMIC_GL_ARB_base_instance*/

/*ARB_transform_feedback2*/
#ifdef USE_DYNAMIC_GL_ARB_transform_feedback2
#define GL_TRANSFORM_FEEDBACK 0x8E22
#define GL_TRANSFORM_FEEDBACK_PAUSED 0x8E23
#define GL_TRANSFORM_FEEDBACK_ACTIVE 0x8E24
#define GL_TRANSFORM_FEEDBACK_BINDING 0x8E25
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_BindTransformFeedback)(GLenum target , GLuint id); }
#define glBindTransformFeedback DynamicGL_BindTransformFeedback
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DeleteTransformFeedbacks)(GLsizei n , const GLuint *ids); }
#define glDeleteTransformFeedbacks DynamicGL_DeleteTransformFeedbacks
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_GenTransformFeedbacks)(GLsizei n , GLuint *ids); }
#define glGenTransformFeedbacks DynamicGL_GenTransformFeedbacks
extern "C" { extern GLboolean (DYNAMIC_GL_APIENTRYP DynamicGL_IsTransformFeedback)(GLuint id); }
#define glIsTransformFeedback DynamicGL_IsTransformFeedback
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_PauseTransformFeedback)(); }
#define glPauseTransformFeedback DynamicGL_PauseTransformFeedback
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ResumeTransformFeedback)(); }
#define glResumeTransformFeedback DynamicGL_ResumeTransformFeedback
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_DrawTransformFeedback)(GLenum mode , GLuint id); }
#define glDrawTransformFeedback DynamicGL_DrawTransformFeedback
extern bool DinamicGLFeature_ARB_transform_feedback2_Supported();
#endif /*USE_DYNAMIC_GL_ARB_transform_feedback2*/

/*VERSION_3_3*/
#ifdef USE_DYNAMIC_GL_VERSION_3_3
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR 0x88FE
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_VertexAttribDivisor)(GLuint index , GLuint divisor); }
#define glVertexAttribDivisor DynamicGL_VertexAttribDivisor
extern bool DinamicGLFeature_VERSION_3_3_Supported();
#endif /*USE_DYNAMIC_GL_VERSION_3_3*/

/*ARB_texture_gather*/
#ifdef USE_DYNAMIC_GL_ARB_texture_gather
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_ARB 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_ARB 0x8E5F
extern bool DinamicGLFeature_ARB_texture_gather_Supported();
#endif /*USE_DYNAMIC_GL_ARB_texture_gather*/

/*SUN_vertex*/
#ifdef USE_DYNAMIC_GL_SUN_vertex
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4ubVertex2fSUN)(GLubyte r , GLubyte g , GLubyte b , GLubyte a , GLfloat x , GLfloat y); }
#define glColor4ubVertex2fSUN DynamicGL_Color4ubVertex2fSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4ubVertex2fvSUN)(const GLubyte *c , const GLfloat *v); }
#define glColor4ubVertex2fvSUN DynamicGL_Color4ubVertex2fvSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4ubVertex3fSUN)(GLubyte r , GLubyte g , GLubyte b , GLubyte a , GLfloat x , GLfloat y , GLfloat z); }
#define glColor4ubVertex3fSUN DynamicGL_Color4ubVertex3fSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4ubVertex3fvSUN)(const GLubyte *c , const GLfloat *v); }
#define glColor4ubVertex3fvSUN DynamicGL_Color4ubVertex3fvSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3fVertex3fSUN)(GLfloat r , GLfloat g , GLfloat b , GLfloat x , GLfloat y , GLfloat z); }
#define glColor3fVertex3fSUN DynamicGL_Color3fVertex3fSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color3fVertex3fvSUN)(const GLfloat *c , const GLfloat *v); }
#define glColor3fVertex3fvSUN DynamicGL_Color3fVertex3fvSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Normal3fVertex3fSUN)(GLfloat nx , GLfloat ny , GLfloat nz , GLfloat x , GLfloat y , GLfloat z); }
#define glNormal3fVertex3fSUN DynamicGL_Normal3fVertex3fSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Normal3fVertex3fvSUN)(const GLfloat *n , const GLfloat *v); }
#define glNormal3fVertex3fvSUN DynamicGL_Normal3fVertex3fvSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4fNormal3fVertex3fSUN)(GLfloat r , GLfloat g , GLfloat b , GLfloat a , GLfloat nx , GLfloat ny , GLfloat nz , GLfloat x , GLfloat y , GLfloat z); }
#define glColor4fNormal3fVertex3fSUN DynamicGL_Color4fNormal3fVertex3fSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_Color4fNormal3fVertex3fvSUN)(const GLfloat *c , const GLfloat *n , const GLfloat *v); }
#define glColor4fNormal3fVertex3fvSUN DynamicGL_Color4fNormal3fVertex3fvSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2fVertex3fSUN)(GLfloat s , GLfloat t , GLfloat x , GLfloat y , GLfloat z); }
#define glTexCoord2fVertex3fSUN DynamicGL_TexCoord2fVertex3fSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2fVertex3fvSUN)(const GLfloat *tc , const GLfloat *v); }
#define glTexCoord2fVertex3fvSUN DynamicGL_TexCoord2fVertex3fvSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord4fVertex4fSUN)(GLfloat s , GLfloat t , GLfloat p , GLfloat q , GLfloat x , GLfloat y , GLfloat z , GLfloat w); }
#define glTexCoord4fVertex4fSUN DynamicGL_TexCoord4fVertex4fSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord4fVertex4fvSUN)(const GLfloat *tc , const GLfloat *v); }
#define glTexCoord4fVertex4fvSUN DynamicGL_TexCoord4fVertex4fvSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2fColor4ubVertex3fSUN)(GLfloat s , GLfloat t , GLubyte r , GLubyte g , GLubyte b , GLubyte a , GLfloat x , GLfloat y , GLfloat z); }
#define glTexCoord2fColor4ubVertex3fSUN DynamicGL_TexCoord2fColor4ubVertex3fSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2fColor4ubVertex3fvSUN)(const GLfloat *tc , const GLubyte *c , const GLfloat *v); }
#define glTexCoord2fColor4ubVertex3fvSUN DynamicGL_TexCoord2fColor4ubVertex3fvSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2fColor3fVertex3fSUN)(GLfloat s , GLfloat t , GLfloat r , GLfloat g , GLfloat b , GLfloat x , GLfloat y , GLfloat z); }
#define glTexCoord2fColor3fVertex3fSUN DynamicGL_TexCoord2fColor3fVertex3fSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2fColor3fVertex3fvSUN)(const GLfloat *tc , const GLfloat *c , const GLfloat *v); }
#define glTexCoord2fColor3fVertex3fvSUN DynamicGL_TexCoord2fColor3fVertex3fvSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2fNormal3fVertex3fSUN)(GLfloat s , GLfloat t , GLfloat nx , GLfloat ny , GLfloat nz , GLfloat x , GLfloat y , GLfloat z); }
#define glTexCoord2fNormal3fVertex3fSUN DynamicGL_TexCoord2fNormal3fVertex3fSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2fNormal3fVertex3fvSUN)(const GLfloat *tc , const GLfloat *n , const GLfloat *v); }
#define glTexCoord2fNormal3fVertex3fvSUN DynamicGL_TexCoord2fNormal3fVertex3fvSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2fColor4fNormal3fVertex3fSUN)(GLfloat s , GLfloat t , GLfloat r , GLfloat g , GLfloat b , GLfloat a , GLfloat nx , GLfloat ny , GLfloat nz , GLfloat x , GLfloat y , GLfloat z); }
#define glTexCoord2fColor4fNormal3fVertex3fSUN DynamicGL_TexCoord2fColor4fNormal3fVertex3fSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord2fColor4fNormal3fVertex3fvSUN)(const GLfloat *tc , const GLfloat *c , const GLfloat *n , const GLfloat *v); }
#define glTexCoord2fColor4fNormal3fVertex3fvSUN DynamicGL_TexCoord2fColor4fNormal3fVertex3fvSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord4fColor4fNormal3fVertex4fSUN)(GLfloat s , GLfloat t , GLfloat p , GLfloat q , GLfloat r , GLfloat g , GLfloat b , GLfloat a , GLfloat nx , GLfloat ny , GLfloat nz , GLfloat x , GLfloat y , GLfloat z , GLfloat w); }
#define glTexCoord4fColor4fNormal3fVertex4fSUN DynamicGL_TexCoord4fColor4fNormal3fVertex4fSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_TexCoord4fColor4fNormal3fVertex4fvSUN)(const GLfloat *tc , const GLfloat *c , const GLfloat *n , const GLfloat *v); }
#define glTexCoord4fColor4fNormal3fVertex4fvSUN DynamicGL_TexCoord4fColor4fNormal3fVertex4fvSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuiVertex3fSUN)(GLuint rc , GLfloat x , GLfloat y , GLfloat z); }
#define glReplacementCodeuiVertex3fSUN DynamicGL_ReplacementCodeuiVertex3fSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuiVertex3fvSUN)(const GLuint *rc , const GLfloat *v); }
#define glReplacementCodeuiVertex3fvSUN DynamicGL_ReplacementCodeuiVertex3fvSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuiColor4ubVertex3fSUN)(GLuint rc , GLubyte r , GLubyte g , GLubyte b , GLubyte a , GLfloat x , GLfloat y , GLfloat z); }
#define glReplacementCodeuiColor4ubVertex3fSUN DynamicGL_ReplacementCodeuiColor4ubVertex3fSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuiColor4ubVertex3fvSUN)(const GLuint *rc , const GLubyte *c , const GLfloat *v); }
#define glReplacementCodeuiColor4ubVertex3fvSUN DynamicGL_ReplacementCodeuiColor4ubVertex3fvSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuiColor3fVertex3fSUN)(GLuint rc , GLfloat r , GLfloat g , GLfloat b , GLfloat x , GLfloat y , GLfloat z); }
#define glReplacementCodeuiColor3fVertex3fSUN DynamicGL_ReplacementCodeuiColor3fVertex3fSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuiColor3fVertex3fvSUN)(const GLuint *rc , const GLfloat *c , const GLfloat *v); }
#define glReplacementCodeuiColor3fVertex3fvSUN DynamicGL_ReplacementCodeuiColor3fVertex3fvSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuiNormal3fVertex3fSUN)(GLuint rc , GLfloat nx , GLfloat ny , GLfloat nz , GLfloat x , GLfloat y , GLfloat z); }
#define glReplacementCodeuiNormal3fVertex3fSUN DynamicGL_ReplacementCodeuiNormal3fVertex3fSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuiNormal3fVertex3fvSUN)(const GLuint *rc , const GLfloat *n , const GLfloat *v); }
#define glReplacementCodeuiNormal3fVertex3fvSUN DynamicGL_ReplacementCodeuiNormal3fVertex3fvSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuiColor4fNormal3fVertex3fSUN)(GLuint rc , GLfloat r , GLfloat g , GLfloat b , GLfloat a , GLfloat nx , GLfloat ny , GLfloat nz , GLfloat x , GLfloat y , GLfloat z); }
#define glReplacementCodeuiColor4fNormal3fVertex3fSUN DynamicGL_ReplacementCodeuiColor4fNormal3fVertex3fSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuiColor4fNormal3fVertex3fvSUN)(const GLuint *rc , const GLfloat *c , const GLfloat *n , const GLfloat *v); }
#define glReplacementCodeuiColor4fNormal3fVertex3fvSUN DynamicGL_ReplacementCodeuiColor4fNormal3fVertex3fvSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuiTexCoord2fVertex3fSUN)(GLuint rc , GLfloat s , GLfloat t , GLfloat x , GLfloat y , GLfloat z); }
#define glReplacementCodeuiTexCoord2fVertex3fSUN DynamicGL_ReplacementCodeuiTexCoord2fVertex3fSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuiTexCoord2fVertex3fvSUN)(const GLuint *rc , const GLfloat *tc , const GLfloat *v); }
#define glReplacementCodeuiTexCoord2fVertex3fvSUN DynamicGL_ReplacementCodeuiTexCoord2fVertex3fvSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuiTexCoord2fNormal3fVertex3fSUN)(GLuint rc , GLfloat s , GLfloat t , GLfloat nx , GLfloat ny , GLfloat nz , GLfloat x , GLfloat y , GLfloat z); }
#define glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN DynamicGL_ReplacementCodeuiTexCoord2fNormal3fVertex3fSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN)(const GLuint *rc , const GLfloat *tc , const GLfloat *n , const GLfloat *v); }
#define glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN DynamicGL_ReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN)(GLuint rc , GLfloat s , GLfloat t , GLfloat r , GLfloat g , GLfloat b , GLfloat a , GLfloat nx , GLfloat ny , GLfloat nz , GLfloat x , GLfloat y , GLfloat z); }
#define glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN DynamicGL_ReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN
extern "C" { extern void (DYNAMIC_GL_APIENTRYP DynamicGL_ReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN)(const GLuint *rc , const GLfloat *tc , const GLfloat *c , const GLfloat *n , const GLfloat *v); }
#define glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN DynamicGL_ReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN
extern bool DinamicGLFeature_SUN_vertex_Supported();
#endif /*USE_DYNAMIC_GL_SUN_vertex*/

/*ARB_texture_mirrored_repeat*/
#ifdef USE_DYNAMIC_GL_ARB_texture_mirrored_repeat
#define GL_MIRRORED_REPEAT_ARB 0x8370
extern bool DinamicGLFeature_ARB_texture_mirrored_repeat_Supported();
#endif /*USE_DYNAMIC_GL_ARB_texture_mirrored_repeat*/

/*HP_texture_lighting*/
#ifdef USE_DYNAMIC_GL_HP_texture_lighting
#define GL_TEXTURE_LIGHTING_MODE_HP 0x8167
#define GL_TEXTURE_POST_SPECULAR_HP 0x8168
#define GL_TEXTURE_PRE_SPECULAR_HP 0x8169
extern bool DinamicGLFeature_HP_texture_lighting_Supported();
#endif /*USE_DYNAMIC_GL_HP_texture_lighting*/

