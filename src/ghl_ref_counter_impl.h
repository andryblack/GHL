/*
 GHL - Game Helpers Library
 Copyright (C)  Andrey Kunitsyn 2011
 
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 
 Andrey (AndryBlack) Kunitsyn
 blackicebox (at) gmail (dot) com
 */

#ifndef GHL_REF_COUNTER_IMPL_H
#define GHL_REF_COUNTER_IMPL_H

#include "ghl_ref_counter.h"
#include "ghl_log_impl.h"

namespace GHL {
    
    template <class T>
    class RefCounterImpl : public T {
    private:
        mutable UInt32  m_refs;
        /// noncopyable
        RefCounterImpl( const RefCounterImpl& );
        RefCounterImpl& operator = (const RefCounterImpl&);
    public:
        RefCounterImpl() : m_refs(1) {
            
        }
        virtual ~RefCounterImpl() {
            if (m_refs!=0) {
                ::GHL::LoggerImpl(::GHL::LOG_LEVEL_ERROR,"REFS") << "too many refs on destructor" ;
            }
        }
        
        virtual void GHL_CALL AddRef() const {
            m_refs++;
        }
        
        virtual void GHL_CALL Release() const {
            if (m_refs==0) {
                ::GHL::LoggerImpl(::GHL::LOG_LEVEL_ERROR,"REFS") << "release released object" ;
            } else {
                m_refs--;
                if (m_refs==0) {
                    delete this;
                }
            }
        }
        
    };
    
}


#endif /*GHL_REF_COUNTER_IMPL_H*/
