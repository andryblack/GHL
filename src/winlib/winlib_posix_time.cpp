#include <sys/time.h>
#include <ghl_system.h>

/// Get system time (secs returned)
GHL_API GHL::UInt32 GHL_CALL GHL_SystemGetTime(GHL::TimeValue* ret) {
    struct ::timeval tv;
    ::gettimeofday(&tv, 0);
    if (ret) {
        ret->secs = tv.tv_sec;
        ret->usecs = tv.tv_usec;
    }
    return tv.tv_usec;
}
