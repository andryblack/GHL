/*
 *  ghl_time.h
 *
 *  Copyright 2016 andryblack. All rights reserved.
 *
 */

#ifndef GHL_TIME_H
#define GHL_TIME_H

#include "ghl_api.h"
#include "ghl_types.h"

namespace GHL {
    /// Time value
    struct TimeValue {
        UInt32 secs;    ///< seconds part
        UInt32 usecs;   ///< useconds part
    };
}

/// Get system time (secs returned)
GHL_API GHL::UInt32 GHL_CALL GHL_GetTime(GHL::TimeValue* tv);

#endif /*GHL_SYSTEM_H*/
