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

#ifndef GHL_DATA_IMPL_H
#define GHL_DATA_IMPL_H

#include "ghl_data.h"
#include "ghl_ref_counter_impl.h"

namespace GHL {
	
	class InlinedData : public Data {
	protected:
		Byte*	m_buffer;
		UInt32	m_size;
	public:
		InlinedData() : m_buffer(0),m_size(0){
			
		}
        virtual ~InlinedData() {}
		/// ctr
		InlinedData( Byte* data, UInt32 size ) : m_buffer( data ), m_size( size ) {
			
		}
		
		/// add reference
        virtual void GHL_CALL AddRef() const {
			
		}
        /// release reference
        virtual void GHL_CALL Release() const {
			
		}
		
		/// Data size
		virtual UInt32 GHL_CALL	GetSize() const { return m_size; }
		/// Data ptr ( read and write )
		Byte* GetDataPtr() { return m_buffer; }
		/// Const data ptr
		virtual const Byte* GHL_CALL	GetData() const { return m_buffer; }
		/// set data
		virtual void GHL_CALL	SetData( UInt32 offset, const Byte* data, UInt32 size ) ;
	};
	
	class ConstInlinedData : public Data {
	protected:
		const Byte*	m_buffer;
		UInt32	m_size;
	public:
			/// ctr
		ConstInlinedData( const Byte* data, UInt32 size ) : m_buffer( data ), m_size( size ) {
			
		}
		/// add reference
        virtual void GHL_CALL AddRef() const {
		}
        /// release reference
        virtual void GHL_CALL Release() const {
		}
		/// Data size
		virtual UInt32 GHL_CALL	GetSize() const { return m_size; }
		/// Const data ptr
		virtual const Byte* GHL_CALL	GetData() const { return m_buffer; }
		/// set data
        virtual void GHL_CALL	SetData( UInt32 /*offset*/, const Byte* /*data*/, UInt32 /*size*/ ) {
			
		}
	};
	
	/// Data buffer holder
	class DataImpl : public RefCounterImpl<InlinedData>
	{
	public:
		/// ctr
		explicit DataImpl(  UInt32 size )  {
			m_buffer = new Byte[ size ];
			m_size = size;
		}
		~DataImpl() {
			delete [] m_buffer;
		}
	};
	
	
	
} /*namespace*/

#endif /*GHL_DATA_IMPL_H*/
