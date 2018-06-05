//
//  render_webgl.h
//  GHL
//

#ifndef RENDER_WEBGL_H
#define RENDER_WEBGL_H

#include "render_opengles.h"

namespace GHL {
    class RenderWebGL : public RenderOpenGLES2 {
    private:
        struct BufferEntry {
            GL::GLuint id;
            UInt32 size;
            BufferEntry();
            GL::GLuint Create(GL& gl,UInt32 size);
            void Release(GL& gl);
        };
        struct TempBuffersSet {
            GL&  gl;
            GL::GLuint target;
            UInt32 element_size;
            static const size_t BUFFERS_COUNT = 8;
            BufferEntry buffers[BUFFERS_COUNT];
            size_t index;
            TempBuffersSet(GL &gl,
                GL::GLuint target,
                UInt32 element_size);
            void Release();
            GL::GLuint Get(UInt32 size,const void* data);
        };
        TempBuffersSet* m_index_buffers;
        TempBuffersSet* m_vertex_buffers;
        TempBuffersSet* m_vertex2_buffers;
    public:
        RenderWebGL(UInt32 w,UInt32 h,bool haveDepth);
        ~RenderWebGL();

        virtual bool RenderInit();
        virtual void RenderDone();
        
        virtual void GHL_CALL DrawPrimitivesFromMemory(PrimitiveType type,VertexType v_type,const void* vertices,UInt32 v_amount,const UInt16* indexes,UInt32 prim_amoun);
        
        
    };
    
}

#endif /* RENDER_WEBGL_H */
