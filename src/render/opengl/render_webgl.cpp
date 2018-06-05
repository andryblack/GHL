#include "render_webgl.h"
#include <assert.h>

static const char* MODULE = "RENDER:WebGL";


namespace GHL {

	RenderWebGL::BufferEntry::BufferEntry() : id(0),size(0) {

	}
    GL::GLuint RenderWebGL::BufferEntry::Create(GL& gl,UInt32 size) {
        if (id) Release(gl);
        CHECK_GL(gl.vboapi.GenBuffers(1,&id));
        this->size = size;
        return id;
    }
    void RenderWebGL::BufferEntry::Release(GL& gl) {
        if (id) {
            CHECK_GL(gl.vboapi.DeleteBuffers(1,&id));
            id = 0;
        }
    }

	RenderWebGL::TempBuffersSet::TempBuffersSet(GL &gl,
        GL::GLuint target,
        UInt32 element_size) : gl(gl), index(0), 
        target(target), element_size(element_size) { 
        
    }
    void RenderWebGL::TempBuffersSet::Release() {
        for (size_t i=0;i<BUFFERS_COUNT;++i) {
            buffers[i].Release(gl);
        }
    }
    GL::GLuint RenderWebGL::TempBuffersSet::Get(UInt32 size,const void* data) {
       GL:: GLuint result = 0;
        if (!buffers[index].id || buffers[index].size < size) {
            result = buffers[index].Create(gl,size);
            CHECK_GL(gl.vboapi.BindBuffer(target,result));
            CHECK_GL(gl.vboapi.BufferData(target,size*element_size,data,gl.vboapi.DYNAMIC_DRAW));
        } else {
            result = buffers[index].id;
            CHECK_GL(gl.vboapi.BindBuffer(target,result));
            CHECK_GL(gl.vboapi.BufferSubData(target,0,size*element_size,data));
        }
        index = (index + 1) % BUFFERS_COUNT;
        return result;
    }


	RenderWebGL::RenderWebGL(UInt32 w,UInt32 h,bool haveDepth) : RenderOpenGLES2(w,h,haveDepth),
		m_index_buffers(0),m_vertex_buffers(0),m_vertex2_buffers(0) {
		
	}

	RenderWebGL::~RenderWebGL() {
		delete m_index_buffers;
        delete m_vertex_buffers;
        delete m_vertex2_buffers;
	}

	bool RenderWebGL::RenderInit() {
		if (!RenderOpenGLES2::RenderInit())
			return false;
		if (!m_index_buffers) {
   			m_index_buffers = new TempBuffersSet(gl,gl.vboapi.ELEMENT_ARRAY_BUFFER,sizeof(UInt16));
   		}
   		if (!m_vertex_buffers) {
   			m_vertex_buffers = new TempBuffersSet(gl,gl.vboapi.ARRAY_BUFFER,sizeof(Vertex));
   		}
   		if (!m_vertex2_buffers) {
   			m_vertex2_buffers = new TempBuffersSet(gl,gl.vboapi.ARRAY_BUFFER,sizeof(Vertex2Tex));
   		}
   		return true;
	}
   	void RenderWebGL::RenderDone() {
   		if (m_index_buffers) {
   			m_index_buffers->Release();
   		}
   		if (m_vertex_buffers) {
   			m_vertex_buffers->Release();
   		}
   		if (m_vertex2_buffers) {
   			m_vertex2_buffers->Release();
   		}
   		RenderOpenGLES2::RenderDone();
    }

	void GHL_CALL RenderWebGL::DrawPrimitivesFromMemory(PrimitiveType type,VertexType v_type,const void* vertices,UInt32 v_amount,const UInt16* indexes,UInt32 prim_amount) {
		DoDrawPrimitives(v_type);
		TempBuffersSet* vbuffer = (v_type == VERTEX_TYPE_SIMPLE) ? m_vertex_buffers : m_vertex2_buffers;
		GL::GLuint vid = vbuffer->Get(v_amount,vertices);
		ResetPointers(); // always different buffer
		SetupVertexData(0,v_type);
		GL::GLenum element =gl.TRIANGLES;
		UInt32 iamount = prim_amount * 3;
		GetPrimitiveInfo(type,prim_amount,element,iamount);
        GL::GLuint iid = m_index_buffers->Get(iamount,indexes);
        for (UInt32 i=0;i<iamount;++i) {
        	assert(indexes[i]<v_amount);
        }
        //LOG_INFO("DrawElements " << element << " " << iamount << " iid: " << iid << " vid: " << vid);
        CHECK_GL(gl.DrawElements(element, iamount, gl.UNSIGNED_SHORT, 0));
	}
       

}