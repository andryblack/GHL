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


#include "ghl_log_impl.h"

namespace GHL{
    
    static Logger*  g_external_logger = 0;
    
    static const char* level_descr[] = {
        ": FATAL :",
        ": ERROR :",
        ":WARNING:",
        ": INFO  :",
        ":VERBOSE:",
        ": DEBUG :"
    };
    
    LoggerImpl::LoggerImpl( LogLevel level , const char* module) : m_level( level ), m_module(module){
        m_stream << "GHL:[" << m_module << "]" << level_descr[m_level];
    }
    
    LoggerImpl::~LoggerImpl() {
        if (g_external_logger) {
            g_external_logger->AddMessage(m_level,m_stream.str().c_str());
        } else {
            GHL_Log(m_level, m_stream.str().c_str());
        }
    }
    
}

GHL_API void GHL_CALL GHL_SetLogger( GHL::Logger* logger ) {
    GHL::g_external_logger = logger;
}