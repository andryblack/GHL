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


#ifndef GHL_LOG_IMPL_H
#define GHL_LOG_IMPL_H

#include <ghl_log.h>
#include <sstream>

namespace GHL {
    
    
    class Logger {
    public:
        explicit Logger( LogLevel level , const char* module = "COMMON" );
        ~Logger();
        
        template <class T>
        Logger& operator << (const T& v) {
            m_stream << v;
            return *this;
        }
        template <class T>
        Logger& operator << (const T* v) {
            m_stream << v;
            return *this;
        }
        Logger& operator << (const std::string& v) {
            m_stream << v.c_str();
            return *this;
        }
    private:
        Logger( const Logger& );
        Logger& operator = (const Logger&);
        LogLevel    m_level;
        std::stringstream   m_stream;
        const char*         m_module;
    };
    
#define LOG_FATAL( MSG ) do { ::GHL::Logger(::GHL::LOG_LEVEL_FATAL,MODULE) << MSG ; } while (false)
#define LOG_ERROR( MSG ) do { ::GHL::Logger(::GHL::LOG_LEVEL_ERROR,MODULE) << MSG ; } while (false)
#define LOG_WARNING( MSG ) do { ::GHL::Logger(::GHL::LOG_LEVEL_WARNING,MODULE) << MSG ; } while (false)
#define LOG_INFO( MSG ) do { ::GHL::Logger(::GHL::LOG_LEVEL_INFO,MODULE) << MSG ; } while (false)

#if defined( GHL_DEBUG ) && !defined( GHL_SILENT )
#define LOG_VERBOSE( MSG ) do { ::GHL::Logger(::GHL::LOG_LEVEL_VERBOSE,MODULE) << MSG ; } while (false)
#define LOG_DEBUG( MSG ) do { ::GHL::Logger(::GHL::LOG_LEVEL_DEBUG,MODULE) << MSG ; } while (false)
#else 
#define LOG_VERBOSE( MSG ) do {  } while (false)
#define LOG_DEBUG( MSG ) do {  } while (false)
#endif
}


#endif /*GHL_LOG_IMPL_H*/
