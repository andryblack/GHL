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
    
    
    class LoggerImpl {
    public:
        explicit LoggerImpl( LogLevel level , const char* module = "COMMON" ,bool native = false);
        ~LoggerImpl();
        
        template <class T>
        LoggerImpl& operator << (const T& v) {
            m_stream << v;
            return *this;
        }
        template <class T>
        LoggerImpl& operator << (const T* v) {
            m_stream << v;
            return *this;
        }
        LoggerImpl& operator << (const std::string& v) {
            m_stream << v.c_str();
            return *this;
        }
        static bool LogExternal( LogLevel level, const char* module, const char* text);
    private:
        LoggerImpl( const LoggerImpl& );
        LoggerImpl& operator = (const LoggerImpl&);
        LogLevel    m_level;
        std::stringstream   m_stream;
        const char*         m_module;
        bool    m_native;
    };
    
#define LOG_FATAL( MSG ) do { ::GHL::LoggerImpl(::GHL::LOG_LEVEL_FATAL,MODULE) << MSG ; } while (false)
#define LOG_ERROR( MSG ) do { ::GHL::LoggerImpl(::GHL::LOG_LEVEL_ERROR,MODULE) << MSG ; } while (false)
#define LOG_WARNING( MSG ) do { ::GHL::LoggerImpl(::GHL::LOG_LEVEL_WARNING,MODULE) << MSG ; } while (false)
#define LOG_INFO( MSG ) do { ::GHL::LoggerImpl(::GHL::LOG_LEVEL_INFO,MODULE) << MSG ; } while (false)

#define ILOG_FATAL( MSG ) do { ::GHL::LoggerImpl(::GHL::LOG_LEVEL_FATAL,MODULE,true) << MSG ; } while (false)
#define ILOG_ERROR( MSG ) do { ::GHL::LoggerImpl(::GHL::LOG_LEVEL_ERROR,MODULE,true) << MSG ; } while (false)
#define ILOG_WARNING( MSG ) do { ::GHL::LoggerImpl(::GHL::LOG_LEVEL_WARNING,MODULE,true) << MSG ; } while (false)
#define ILOG_INFO( MSG ) do { ::GHL::LoggerImpl(::GHL::LOG_LEVEL_INFO,MODULE,true) << MSG ; } while (false)
#define ILOG_VERBOSE( MSG ) do { ::GHL::LoggerImpl(::GHL::LOG_LEVEL_VERBOSE,MODULE,true) << MSG ; } while (false)
#define ILOG_DEBUG( MSG ) do { ::GHL::LoggerImpl(::GHL::LOG_LEVEL_DEBUG,MODULE,true) << MSG ; } while (false)

#if defined( GHL_DEBUG ) && !defined( GHL_SILENT )
#define LOG_VERBOSE( MSG ) do { ::GHL::LoggerImpl(::GHL::LOG_LEVEL_VERBOSE,MODULE) << MSG ; } while (false)
#define LOG_DEBUG( MSG ) do { ::GHL::LoggerImpl(::GHL::LOG_LEVEL_DEBUG,MODULE) << MSG ; } while (false)
#else 
#define LOG_VERBOSE( MSG ) do {  } while (false)
#define LOG_DEBUG( MSG ) do {  } while (false)
#endif
}


#endif /*GHL_LOG_IMPL_H*/
