/*
 *  ghl_system.h
 *  SR
 *
 *  Created by Андрей Куницын on 13.02.11.
 *  Copyright 2011 andryblack. All rights reserved.
 *
 */

#ifndef GHL_SYSTEM_H
#define GHL_SYSTEM_H

#include "ghl_api.h"
#include "ghl_types.h"

namespace GHL {
	
	/// device state
	enum DeviceState {
		DEVICE_STATE_ACCELEROMETER_ENABLED,	///< bool
		DEVICE_STATE_ORIENTATION_LOCKED,	///< bool
		DEVICE_STATE_MULTITOUCH_ENABLED,	///< bool
        DEVICE_STATE_SYSTEM_CURSOR_ENABLED, ///< bool
		DEVICE_STATE_RETINA_ENABLED,		///< bool
        DEVICE_STATE_FRAME_INTERVAL         ///< Int32
	};
	
	/// device data
	enum DeviceData {
		DEVICE_DATA_ACCELEROMETER,      ///< 3floats
		DEVICE_DATA_VIEW_CONTROLLER,	///< UIViewController*
        DEVICE_DATA_VIEW,               ///< NSView** /UIView**
        DEVICE_DATA_APPLICATION,        ///< ANativeActivity**
        DEVICE_DATA_LANGUAGE,           ///< char[32]
        DEVICE_DATA_UTC_OFFSET          ///< Int32*
   };

    /// system interface
    struct System {
        /// Exit from application
        virtual void GHL_CALL Exit() = 0;
        /// Current fullscreen / windowed state
        virtual bool GHL_CALL IsFullscreen() const = 0;
        /// Switch fullscreen / windowed state
        virtual void GHL_CALL SwitchFullscreen(bool fs) = 0;
        /// Show soft keyboard
        virtual void GHL_CALL ShowKeyboard() = 0;
        /// Hide soft keyboard
        virtual void GHL_CALL HideKeyboard() = 0;
        /// Set device specific state
		virtual bool GHL_CALL SetDeviceState( DeviceState name, const void* data) = 0;
		/// Get device specific data
		virtual bool GHL_CALL GetDeviceData( DeviceData name, void* data) = 0;
        /// Set window title
        virtual void GHL_CALL SetTitle( const char* title ) = 0;
    };
 
    struct TimeValue {
        UInt32 secs;
        UInt32 usecs;
    };
}

/// Get system time (secs returned)
GHL_API GHL::UInt32 GHL_CALL GHL_SystemGetTime(GHL::TimeValue* tv);
/// Get opaque thread id
GHL_API GHL::UInt32 GHL_CALL GHL_GetCurrentThreadId();

#endif /*GHL_SYSTEM_H*/
