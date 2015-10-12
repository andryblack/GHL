
#include <ghl_system.h>

#ifndef _MSC_VER
#include <sys/time.h>
#else
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <stdint.h> // portable: uint64_t   MSVC: __int64 

// MSVC defines this in winsock2.h!?
typedef struct timeval {
	long tv_sec;
	long tv_usec;
} timeval;

static int gettimeofday(struct timeval * tp, struct timezone * tzp)
{
	// Note: some broken versions only have 8 trailing zero's, the correct epoch has 9 trailing zero's
	static const uint64_t EPOCH = ((uint64_t)116444736000000000ULL);

	SYSTEMTIME  system_time;
	FILETIME    file_time;
	uint64_t    time;

	GetSystemTime(&system_time);
	SystemTimeToFileTime(&system_time, &file_time);
	time = ((uint64_t)file_time.dwLowDateTime);
	time += ((uint64_t)file_time.dwHighDateTime) << 32;

	tp->tv_sec = (long)((time - EPOCH) / 10000000L);
	tp->tv_usec = (long)(system_time.wMilliseconds * 1000);
	return 0;
}
#endif

/// Get system time (secs returned)
GHL_API GHL::UInt32 GHL_CALL GHL_SystemGetTime(GHL::TimeValue* ret) {
    struct ::timeval tv;
    ::gettimeofday(&tv, 0);
    if (ret) {
        ret->secs = tv.tv_sec;
        ret->usecs = tv.tv_usec;
    }
    return tv.tv_sec;
}
