/*
 *  refcount_opengl.h
 *  SR
 *
 *  Created by Андрей Куницын on 13.02.11.
 *  Copyright 2011 andryblack. All rights reserved.
 *
 */
#ifndef REFCOUNT_OPENGL_H
#define REFCOUNT_OPENGL_H

#include <cstring>

namespace GHL {
	
	template <class T>
	class RefCount : public T {
	public:
		RefCount() : m_refs(1) {}
		void AddRef() { m_refs--;}
		bool DeRef() { return (--m_refs==0); }
	private:
		size_t m_refs;
	};
	
}

#endif /*REFCOUNT_OPENGL_H*/
