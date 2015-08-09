/*
    GHL - Game Helpers Library
    Copyright (C)  Andrey Kunitsyn 2009

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

#ifndef GHL_NET_H
#define GHL_NET_H

#include "ghl_types.h"
#include "ghl_api.h"
#include "ghl_ref_counter.h"

namespace GHL
{
    
    struct Data;
    
    
    /// connection handler
    struct NetworkRequest : RefCounter
    {
        /// url
        virtual const char* GHL_CALL GetURL() const = 0;
        /// headers
        virtual UInt32 GHL_CALL GetHeadersCount() const = 0;
        /// header name
        virtual const char* GHL_CALL GetHeaderName(UInt32 idx) const = 0;
        /// header value
        virtual const char* GHL_CALL GetHeaderValue(UInt32 idx) const = 0;
        
        /// received response
        virtual void GHL_CALL OnResponse(UInt32 status) = 0;
        /// received header
        virtual void GHL_CALL OnHeader(const char* name,const char* value) = 0;
        /// received data
        virtual void GHL_CALL OnData(const Byte* data,UInt32 size) = 0;
        /// received complete
        virtual void GHL_CALL OnComplete() = 0;
        /// received error
        virtual void GHL_CALL OnError(const char* error) = 0;
    };

	/// network interfacce
	struct Network 
	{
        /// GET request
        virtual bool GHL_CALL Get(NetworkRequest* handler) = 0;
        /// POST request
        virtual bool GHL_CALL Post(NetworkRequest* handler,const Data* data) = 0;
        /// process events on main thread
        virtual void GHL_CALL Process() = 0;
   };

} /* namespace */

/// create network interface
GHL_API GHL::Network* GHL_CALL GHL_CreateNetwork();
/// destroy network interface
GHL_API void GHL_CALL GHL_DestroyNetwork(GHL::Network* vfs);

#endif /*GHL_NET_H*/
