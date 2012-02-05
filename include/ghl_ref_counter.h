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


#ifndef GHL_REF_COUNTER_H
#define GHL_REF_COUNTER_H

namespace GHL {
    
    /** Reference counter interface
     */
    struct RefCounter {
        /// add reference
        virtual void GHL_CALL AddRef() = 0;
        /// release reference
        virtual void GHL_CALL Release() = 0;
    };

}
#endif /*GHL_REF_COUNTER_H*/
