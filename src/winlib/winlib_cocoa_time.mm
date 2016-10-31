#import <Foundation/Foundation.h>

#include "ghl_time.h"


/// Get system time (secs returned)
GHL_API GHL::UInt32 GHL_CALL GHL_GetTime(GHL::TimeValue* tv) {
    NSTimeInterval ti = [[NSDate date] timeIntervalSince1970];
    GHL::UInt32 d = ti;
    if (tv) {
        tv->secs = d;
        tv->usecs = (ti - d) * 1000000;
    }
    return d;
}
