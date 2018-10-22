/*
 *  rendertarget_impl.h
 *  SR
 *
 *  Created by Андрей Куницын on 29.03.11.
 *  Copyright 2011 andryblack. All rights reserved.
 *
 */

#ifndef RENDERTARGET_IMPL_H
#define RENDERTARGET_IMPL_H

#include <ghl_render_target.h>
#include "../ghl_ref_counter_impl.h"

namespace GHL {

	class RenderImpl;
	
	class RenderTargetImpl : public RefCounterImpl<RenderTarget> {
	public:
        explicit RenderTargetImpl( RenderImpl* parent );
		virtual ~RenderTargetImpl();
		virtual void BeginScene( RenderImpl* render ) = 0;
		virtual void EndScene( RenderImpl* render ) = 0;
        bool GetHaveDepth() const { return m_have_depth; }
        UInt32 GetMemoryUsage() const;
    protected:
        RenderImpl* GetParent();
        void SetMemoryUsage(UInt32 m);
        bool    m_have_depth;
    private:
        RenderImpl* m_parent;
        UInt32  m_mem_usage;
	};
	
}

#endif /*RENDERTARGET_IMPL_H*/
