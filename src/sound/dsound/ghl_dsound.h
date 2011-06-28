#ifndef GHL_DSOUND_H
#define GHL_DSOUND_H

/*==========================================================================;
 *
 *  Copyright (C) 1995-2000 Microsoft Corporation.  All Rights Reserved.
 *
 *  File:       dsound.h
 *  Content:    DirectSound include file
 *
 **************************************************************************/

#define COM_NO_WINDOWS_H
#include <objbase.h>
//#include <float.h>
#include <mmreg.h>


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


/* Type definitions shared with Direct3D */



#define _FACDS  0x878   /* DirectSound's facility code */
#define MAKE_DSHRESULT(code)  MAKE_HRESULT(1, _FACDS, code)

// DirectSound Component GUID {47D4D946-62E8-11CF-93BC-444553540000}
DEFINE_GUID(CLSID_DirectSound, 0x47d4d946, 0x62e8, 0x11cf, 0x93, 0xbc, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0);

// DirectSound 8.0 Component GUID {3901CC3F-84B5-4FA4-BA35-AA8172B8A09B}
DEFINE_GUID(CLSID_DirectSound8, 0x3901cc3f, 0x84b5, 0x4fa4, 0xba, 0x35, 0xaa, 0x81, 0x72, 0xb8, 0xa0, 0x9b);

// DirectSound default playback device GUID {DEF00000-9C6D-47ED-AAF1-4DDA8F2B5C03}
DEFINE_GUID(DSDEVID_DefaultPlayback, 0xdef00000, 0x9c6d, 0x47ed, 0xaa, 0xf1, 0x4d, 0xda, 0x8f, 0x2b, 0x5c, 0x03);





//
// Forward declarations for interfaces.
// 'struct' not 'class' per the way DECLARE_INTERFACE_ is defined
//

struct IDirectSound;
struct IDirectSoundBuffer;
struct IDirectSoundNotify;


//
// DirectSound 8.0 interfaces.
//


struct IDirectSound8;

// IDirectSound8, IDirectSoundBuffer8 and IDirectSoundCaptureBuffer8 are the
// only DirectSound 7.0 interfaces with changed functionality in version 8.0.
// The other level 8 interfaces as equivalent to their level 7 counterparts:

#define IDirectSoundNotify8             IDirectSoundNotify


typedef struct IDirectSound                 *LPDIRECTSOUND;
typedef struct IDirectSoundBuffer           *LPDIRECTSOUNDBUFFER;
typedef struct IDirectSoundNotify           *LPDIRECTSOUNDNOTIFY;



typedef struct IDirectSound8                *LPDIRECTSOUND8;
typedef struct IDirectSoundNotify8          *LPDIRECTSOUNDNOTIFY8;


//
// IID definitions for the unchanged DirectSound 8.0 interfaces
//

#define IID_IDirectSoundNotify8             IID_IDirectSoundNotify

//
// Compatibility typedefs
//

#ifndef _LPCWAVEFORMATEX_DEFINED
#define _LPCWAVEFORMATEX_DEFINED
typedef const WAVEFORMATEX *LPCWAVEFORMATEX;
#endif // _LPCWAVEFORMATEX_DEFINED

#ifndef __LPCGUID_DEFINED__
#define __LPCGUID_DEFINED__
typedef const GUID *LPCGUID;
#endif // __LPCGUID_DEFINED__

typedef LPDIRECTSOUND *LPLPDIRECTSOUND;
typedef LPDIRECTSOUNDNOTIFY *LPLPDIRECTSOUNDNOTIFY;

typedef LPDIRECTSOUND8 *LPLPDIRECTSOUND8;

//
// Structures
//

typedef struct _DSCAPS
{
    DWORD           dwSize;
    DWORD           dwFlags;
    DWORD           dwMinSecondarySampleRate;
    DWORD           dwMaxSecondarySampleRate;
    DWORD           dwPrimaryBuffers;
    DWORD           dwMaxHwMixingAllBuffers;
    DWORD           dwMaxHwMixingStaticBuffers;
    DWORD           dwMaxHwMixingStreamingBuffers;
    DWORD           dwFreeHwMixingAllBuffers;
    DWORD           dwFreeHwMixingStaticBuffers;
    DWORD           dwFreeHwMixingStreamingBuffers;
    DWORD           dwMaxHw3DAllBuffers;
    DWORD           dwMaxHw3DStaticBuffers;
    DWORD           dwMaxHw3DStreamingBuffers;
    DWORD           dwFreeHw3DAllBuffers;
    DWORD           dwFreeHw3DStaticBuffers;
    DWORD           dwFreeHw3DStreamingBuffers;
    DWORD           dwTotalHwMemBytes;
    DWORD           dwFreeHwMemBytes;
    DWORD           dwMaxContigFreeHwMemBytes;
    DWORD           dwUnlockTransferRateHwBuffers;
    DWORD           dwPlayCpuOverheadSwBuffers;
    DWORD           dwReserved1;
    DWORD           dwReserved2;
} DSCAPS, *LPDSCAPS;

typedef const DSCAPS *LPCDSCAPS;

typedef struct _DSBCAPS
{
    DWORD           dwSize;
    DWORD           dwFlags;
    DWORD           dwBufferBytes;
    DWORD           dwUnlockTransferRate;
    DWORD           dwPlayCpuOverhead;
} DSBCAPS, *LPDSBCAPS;

typedef const DSBCAPS *LPCDSBCAPS;


typedef struct _DSBUFFERDESC
{
    DWORD           dwSize;
    DWORD           dwFlags;
    DWORD           dwBufferBytes;
    DWORD           dwReserved;
    LPWAVEFORMATEX  lpwfxFormat;
#if DIRECTSOUND_VERSION >= 0x0700
    GUID            guid3DAlgorithm;
#endif
} DSBUFFERDESC, *LPDSBUFFERDESC;

typedef const DSBUFFERDESC *LPCDSBUFFERDESC;

// Older version of this structure:

typedef struct _DSBUFFERDESC1
{
    DWORD           dwSize;
    DWORD           dwFlags;
    DWORD           dwBufferBytes;
    DWORD           dwReserved;
    LPWAVEFORMATEX  lpwfxFormat;
} DSBUFFERDESC1, *LPDSBUFFERDESC1;

typedef const DSBUFFERDESC1 *LPCDSBUFFERDESC1;


typedef struct _DSCCAPS
{
    DWORD           dwSize;
    DWORD           dwFlags;
    DWORD           dwFormats;
    DWORD           dwChannels;
} DSCCAPS, *LPDSCCAPS;

typedef const DSCCAPS *LPCDSCCAPS;

typedef struct _DSCBUFFERDESC1
{
    DWORD           dwSize;
    DWORD           dwFlags;
    DWORD           dwBufferBytes;
    DWORD           dwReserved;
    LPWAVEFORMATEX  lpwfxFormat;
} DSCBUFFERDESC1, *LPDSCBUFFERDESC1;

typedef struct _DSCBUFFERDESC
{
    DWORD           dwSize;
    DWORD           dwFlags;
    DWORD           dwBufferBytes;
    DWORD           dwReserved;
    LPWAVEFORMATEX  lpwfxFormat;
#if 0
    DWORD           dwFXCount;
    LPDSCEFFECTDESC lpDSCFXDesc;
#endif
} DSCBUFFERDESC, *LPDSCBUFFERDESC;

typedef const DSCBUFFERDESC *LPCDSCBUFFERDESC;

typedef struct _DSCBCAPS
{
    DWORD           dwSize;
    DWORD           dwFlags;
    DWORD           dwBufferBytes;
    DWORD           dwReserved;
} DSCBCAPS, *LPDSCBCAPS;

typedef const DSCBCAPS *LPCDSCBCAPS;

typedef struct _DSBPOSITIONNOTIFY
{
    DWORD           dwOffset;
    HANDLE          hEventNotify;
} DSBPOSITIONNOTIFY, *LPDSBPOSITIONNOTIFY;

typedef const DSBPOSITIONNOTIFY *LPCDSBPOSITIONNOTIFY;

//
// DirectSound API
//

typedef BOOL (CALLBACK *LPDSENUMCALLBACKA)(LPGUID, LPCSTR, LPCSTR, LPVOID);
typedef BOOL (CALLBACK *LPDSENUMCALLBACKW)(LPGUID, LPCWSTR, LPCWSTR, LPVOID);

extern HRESULT WINAPI DirectSoundCreate(LPCGUID pcGuidDevice, LPDIRECTSOUND *ppDS, LPUNKNOWN pUnkOuter);
extern HRESULT WINAPI DirectSoundEnumerateA(LPDSENUMCALLBACKA pDSEnumCallback, LPVOID pContext);
extern HRESULT WINAPI DirectSoundEnumerateW(LPDSENUMCALLBACKW pDSEnumCallback, LPVOID pContext);


extern HRESULT WINAPI DirectSoundCreate8(LPCGUID pcGuidDevice, LPDIRECTSOUND8 *ppDS8, LPUNKNOWN pUnkOuter);
extern HRESULT WINAPI GetDeviceID(LPCGUID pGuidSrc, LPGUID pGuidDest);

#ifdef UNICODE
#define LPDSENUMCALLBACK            LPDSENUMCALLBACKW
#define DirectSoundEnumerate        DirectSoundEnumerateW
#else // UNICODE
#define LPDSENUMCALLBACK            LPDSENUMCALLBACKA
#define DirectSoundEnumerate        DirectSoundEnumerateA
#endif // UNICODE


//
// IDirectSound
//

DEFINE_GUID(IID_IDirectSound, 0x279AFA83, 0x4981, 0x11CE, 0xA5, 0x21, 0x00, 0x20, 0xAF, 0x0B, 0xE5, 0x60);

#undef INTERFACE
#define INTERFACE IDirectSound

DECLARE_INTERFACE_(IDirectSound, IUnknown)
{
    // IUnknown methods
    STDMETHOD(QueryInterface)       (THIS_ REFIID, LPVOID *) PURE;
    STDMETHOD_(ULONG,AddRef)        (THIS) PURE;
    STDMETHOD_(ULONG,Release)       (THIS) PURE;

    // IDirectSound methods
    STDMETHOD(CreateSoundBuffer)    (THIS_ LPCDSBUFFERDESC pcDSBufferDesc, LPDIRECTSOUNDBUFFER *ppDSBuffer, LPUNKNOWN pUnkOuter) PURE;
    STDMETHOD(GetCaps)              (THIS_ LPDSCAPS pDSCaps) PURE;
    STDMETHOD(DuplicateSoundBuffer) (THIS_ LPDIRECTSOUNDBUFFER pDSBufferOriginal, LPDIRECTSOUNDBUFFER *ppDSBufferDuplicate) PURE;
    STDMETHOD(SetCooperativeLevel)  (THIS_ HWND hwnd, DWORD dwLevel) PURE;
    STDMETHOD(Compact)              (THIS) PURE;
    STDMETHOD(GetSpeakerConfig)     (THIS_ LPDWORD pdwSpeakerConfig) PURE;
    STDMETHOD(SetSpeakerConfig)     (THIS_ DWORD dwSpeakerConfig) PURE;
    STDMETHOD(Initialize)           (THIS_ LPCGUID pcGuidDevice) PURE;
};



//
// IDirectSound8
//

DEFINE_GUID(IID_IDirectSound8, 0xC50A7E93, 0xF395, 0x4834, 0x9E, 0xF6, 0x7F, 0xA9, 0x9D, 0xE5, 0x09, 0x66);

#undef INTERFACE
#define INTERFACE IDirectSound8

DECLARE_INTERFACE_(IDirectSound8, IDirectSound)
{
    // IUnknown methods
    STDMETHOD(QueryInterface)       (THIS_ REFIID, LPVOID *) PURE;
    STDMETHOD_(ULONG,AddRef)        (THIS) PURE;
    STDMETHOD_(ULONG,Release)       (THIS) PURE;

    // IDirectSound methods
    STDMETHOD(CreateSoundBuffer)    (THIS_ LPCDSBUFFERDESC pcDSBufferDesc, LPDIRECTSOUNDBUFFER *ppDSBuffer, LPUNKNOWN pUnkOuter) PURE;
    STDMETHOD(GetCaps)              (THIS_ LPDSCAPS pDSCaps) PURE;
    STDMETHOD(DuplicateSoundBuffer) (THIS_ LPDIRECTSOUNDBUFFER pDSBufferOriginal, LPDIRECTSOUNDBUFFER *ppDSBufferDuplicate) PURE;
    STDMETHOD(SetCooperativeLevel)  (THIS_ HWND hwnd, DWORD dwLevel) PURE;
    STDMETHOD(Compact)              (THIS) PURE;
    STDMETHOD(GetSpeakerConfig)     (THIS_ LPDWORD pdwSpeakerConfig) PURE;
    STDMETHOD(SetSpeakerConfig)     (THIS_ DWORD dwSpeakerConfig) PURE;
    STDMETHOD(Initialize)           (THIS_ LPCGUID pcGuidDevice) PURE;

    // IDirectSound8 methods
    STDMETHOD(VerifyCertification)  (THIS_ LPDWORD pdwCertified) PURE;
};

//
// IDirectSoundBuffer
//

DEFINE_GUID(IID_IDirectSoundBuffer, 0x279AFA85, 0x4981, 0x11CE, 0xA5, 0x21, 0x00, 0x20, 0xAF, 0x0B, 0xE5, 0x60);

#undef INTERFACE
#define INTERFACE IDirectSoundBuffer

DECLARE_INTERFACE_(IDirectSoundBuffer, IUnknown)
{
    // IUnknown methods
    STDMETHOD(QueryInterface)       (THIS_ REFIID, LPVOID *) PURE;
    STDMETHOD_(ULONG,AddRef)        (THIS) PURE;
    STDMETHOD_(ULONG,Release)       (THIS) PURE;

    // IDirectSoundBuffer methods
    STDMETHOD(GetCaps)              (THIS_ LPDSBCAPS pDSBufferCaps) PURE;
    STDMETHOD(GetCurrentPosition)   (THIS_ LPDWORD pdwCurrentPlayCursor, LPDWORD pdwCurrentWriteCursor) PURE;
    STDMETHOD(GetFormat)            (THIS_ LPWAVEFORMATEX pwfxFormat, DWORD dwSizeAllocated, LPDWORD pdwSizeWritten) PURE;
    STDMETHOD(GetVolume)            (THIS_ LPLONG plVolume) PURE;
    STDMETHOD(GetPan)               (THIS_ LPLONG plPan) PURE;
    STDMETHOD(GetFrequency)         (THIS_ LPDWORD pdwFrequency) PURE;
    STDMETHOD(GetStatus)            (THIS_ LPDWORD pdwStatus) PURE;
    STDMETHOD(Initialize)           (THIS_ LPDIRECTSOUND pDirectSound, LPCDSBUFFERDESC pcDSBufferDesc) PURE;
    STDMETHOD(Lock)                 (THIS_ DWORD dwOffset, DWORD dwBytes, LPVOID *ppvAudioPtr1, LPDWORD pdwAudioBytes1,
                                           LPVOID *ppvAudioPtr2, LPDWORD pdwAudioBytes2, DWORD dwFlags) PURE;
    STDMETHOD(Play)                 (THIS_ DWORD dwReserved1, DWORD dwPriority, DWORD dwFlags) PURE;
    STDMETHOD(SetCurrentPosition)   (THIS_ DWORD dwNewPosition) PURE;
    STDMETHOD(SetFormat)            (THIS_ LPCWAVEFORMATEX pcfxFormat) PURE;
    STDMETHOD(SetVolume)            (THIS_ LONG lVolume) PURE;
    STDMETHOD(SetPan)               (THIS_ LONG lPan) PURE;
    STDMETHOD(SetFrequency)         (THIS_ DWORD dwFrequency) PURE;
    STDMETHOD(Stop)                 (THIS) PURE;
    STDMETHOD(Unlock)               (THIS_ LPVOID pvAudioPtr1, DWORD dwAudioBytes1, LPVOID pvAudioPtr2, DWORD dwAudioBytes2) PURE;
    STDMETHOD(Restore)              (THIS) PURE;
};





//
// IDirectSoundNotify
//

DEFINE_GUID(IID_IDirectSoundNotify, 0xb0210783, 0x89cd, 0x11d0, 0xaf, 0x8, 0x0, 0xa0, 0xc9, 0x25, 0xcd, 0x16);

#undef INTERFACE
#define INTERFACE IDirectSoundNotify

DECLARE_INTERFACE_(IDirectSoundNotify, IUnknown)
{
    // IUnknown methods
    STDMETHOD(QueryInterface)           (THIS_ REFIID, LPVOID *) PURE;
    STDMETHOD_(ULONG,AddRef)            (THIS) PURE;
    STDMETHOD_(ULONG,Release)           (THIS) PURE;

    // IDirectSoundNotify methods
    STDMETHOD(SetNotificationPositions) (THIS_ DWORD dwPositionNotifies, LPCDSBPOSITIONNOTIFY pcPositionNotifies) PURE;
};


//
// Return Codes
//

// The function completed successfully
#define DS_OK                           S_OK

// The call succeeded, but we had to substitute the 3D algorithm
#define DS_NO_VIRTUALIZATION            MAKE_HRESULT(0, _FACDS, 10)

// The call succeeded, but not all of the optional effects were obtained.
#define DS_INCOMPLETE                   MAKE_HRESULT(0, _FACDS, 20)

// The call failed because resources (such as a priority level)
// were already being used by another caller
#define DSERR_ALLOCATED                 MAKE_DSHRESULT(10)

// The control (vol, pan, etc.) requested by the caller is not available
#define DSERR_CONTROLUNAVAIL            MAKE_DSHRESULT(30)

// An invalid parameter was passed to the returning function
#define DSERR_INVALIDPARAM              E_INVALIDARG

// This call is not valid for the current state of this object
#define DSERR_INVALIDCALL               MAKE_DSHRESULT(50)

// An undetermined error occurred inside the DirectSound subsystem
#define DSERR_GENERIC                   E_FAIL

// The caller does not have the priority level required for the function to
// succeed
#define DSERR_PRIOLEVELNEEDED           MAKE_DSHRESULT(70)

// Not enough free memory is available to complete the operation
#define DSERR_OUTOFMEMORY               E_OUTOFMEMORY

// The specified WAVE format is not supported
#define DSERR_BADFORMAT                 MAKE_DSHRESULT(100)

// The function called is not supported at this time
#define DSERR_UNSUPPORTED               E_NOTIMPL

// No sound driver is available for use
#define DSERR_NODRIVER                  MAKE_DSHRESULT(120)

// This object is already initialized
#define DSERR_ALREADYINITIALIZED        MAKE_DSHRESULT(130)

// This object does not support aggregation
#define DSERR_NOAGGREGATION             CLASS_E_NOAGGREGATION

// The buffer memory has been lost, and must be restored
#define DSERR_BUFFERLOST                MAKE_DSHRESULT(150)

// Another app has a higher priority level, preventing this call from
// succeeding
#define DSERR_OTHERAPPHASPRIO           MAKE_DSHRESULT(160)

// This object has not been initialized
#define DSERR_UNINITIALIZED             MAKE_DSHRESULT(170)

// The requested COM interface is not available
#define DSERR_NOINTERFACE               E_NOINTERFACE

// Access is denied
#define DSERR_ACCESSDENIED              E_ACCESSDENIED

// Tried to create a DSBCAPS_CTRLFX buffer shorter than DSBSIZE_FX_MIN milliseconds
#define DSERR_BUFFERTOOSMALL            MAKE_DSHRESULT(180)

// Attempt to use DirectSound 8 functionality on an older DirectSound object
#define DSERR_DS8_REQUIRED              MAKE_DSHRESULT(190)

// A circular loop of send effects was detected
#define DSERR_SENDLOOP                  MAKE_DSHRESULT(200)

// The GUID specified in an audiopath file does not match a valid MIXIN buffer
#define DSERR_BADSENDBUFFERGUID         MAKE_DSHRESULT(210)

// The object requested was not found (numerically equal to DMUS_E_NOT_FOUND)
#define DSERR_OBJECTNOTFOUND            MAKE_DSHRESULT(4449)

//
// Flags
//

#define DSCAPS_PRIMARYMONO          0x00000001
#define DSCAPS_PRIMARYSTEREO        0x00000002
#define DSCAPS_PRIMARY8BIT          0x00000004
#define DSCAPS_PRIMARY16BIT         0x00000008
#define DSCAPS_CONTINUOUSRATE       0x00000010
#define DSCAPS_EMULDRIVER           0x00000020
#define DSCAPS_CERTIFIED            0x00000040
#define DSCAPS_SECONDARYMONO        0x00000100
#define DSCAPS_SECONDARYSTEREO      0x00000200
#define DSCAPS_SECONDARY8BIT        0x00000400
#define DSCAPS_SECONDARY16BIT       0x00000800

#define DSSCL_NORMAL                0x00000001
#define DSSCL_PRIORITY              0x00000002
#define DSSCL_EXCLUSIVE             0x00000003
#define DSSCL_WRITEPRIMARY          0x00000004

#define DSSPEAKER_HEADPHONE         0x00000001
#define DSSPEAKER_MONO              0x00000002
#define DSSPEAKER_QUAD              0x00000003
#define DSSPEAKER_STEREO            0x00000004
#define DSSPEAKER_SURROUND          0x00000005
#define DSSPEAKER_5POINT1           0x00000006

#define DSSPEAKER_GEOMETRY_MIN      0x00000005  //   5 degrees
#define DSSPEAKER_GEOMETRY_NARROW   0x0000000A  //  10 degrees
#define DSSPEAKER_GEOMETRY_WIDE     0x00000014  //  20 degrees
#define DSSPEAKER_GEOMETRY_MAX      0x000000B4  // 180 degrees

#define DSSPEAKER_COMBINED(c, g)    ((DWORD)(((BYTE)(c)) | ((DWORD)((BYTE)(g))) << 16))
#define DSSPEAKER_CONFIG(a)         ((BYTE)(a))
#define DSSPEAKER_GEOMETRY(a)       ((BYTE)(((DWORD)(a) >> 16) & 0x00FF))

#define DSBCAPS_PRIMARYBUFFER       0x00000001
#define DSBCAPS_STATIC              0x00000002
#define DSBCAPS_LOCHARDWARE         0x00000004
#define DSBCAPS_LOCSOFTWARE         0x00000008
#define DSBCAPS_CTRL3D              0x00000010
#define DSBCAPS_CTRLFREQUENCY       0x00000020
#define DSBCAPS_CTRLPAN             0x00000040
#define DSBCAPS_CTRLVOLUME          0x00000080
#define DSBCAPS_CTRLPOSITIONNOTIFY  0x00000100
#define DSBCAPS_CTRLFX              0x00000200
#define DSBCAPS_STICKYFOCUS         0x00004000
#define DSBCAPS_GLOBALFOCUS         0x00008000
#define DSBCAPS_GETCURRENTPOSITION2 0x00010000
#define DSBCAPS_MUTE3DATMAXDISTANCE 0x00020000
#define DSBCAPS_LOCDEFER            0x00040000

#define DSBPLAY_LOOPING             0x00000001
#define DSBPLAY_LOCHARDWARE         0x00000002
#define DSBPLAY_LOCSOFTWARE         0x00000004
#define DSBPLAY_TERMINATEBY_TIME    0x00000008
#define DSBPLAY_TERMINATEBY_DISTANCE    0x000000010
#define DSBPLAY_TERMINATEBY_PRIORITY    0x000000020

#define DSBSTATUS_PLAYING           0x00000001
#define DSBSTATUS_BUFFERLOST        0x00000002
#define DSBSTATUS_LOOPING           0x00000004
#define DSBSTATUS_LOCHARDWARE       0x00000008
#define DSBSTATUS_LOCSOFTWARE       0x00000010
#define DSBSTATUS_TERMINATED        0x00000020

#define DSBLOCK_FROMWRITECURSOR     0x00000001
#define DSBLOCK_ENTIREBUFFER        0x00000002

#define DSBFREQUENCY_MIN            100
#define DSBFREQUENCY_MAX            100000
#define DSBFREQUENCY_ORIGINAL       0

#define DSBPAN_LEFT                 -10000
#define DSBPAN_CENTER               0
#define DSBPAN_RIGHT                10000

#define DSBVOLUME_MIN               -10000
#define DSBVOLUME_MAX               0

#define DSBSIZE_MIN                 4
#define DSBSIZE_MAX                 0x0FFFFFFF
#define DSBSIZE_FX_MIN              150  // NOTE: Milliseconds, not bytes

#define DS3DMODE_NORMAL             0x00000000
#define DS3DMODE_HEADRELATIVE       0x00000001
#define DS3DMODE_DISABLE            0x00000002

#define DS3D_IMMEDIATE              0x00000000
#define DS3D_DEFERRED               0x00000001

// IDirectSoundCapture attributes

#define DSCCAPS_EMULDRIVER          DSCAPS_EMULDRIVER
#define DSCCAPS_CERTIFIED           DSCAPS_CERTIFIED

// IDirectSoundCaptureBuffer attributes

#define DSCBCAPS_WAVEMAPPED         0x80000000

#define DSCBCAPS_CTRLFX             0x00000200


#define DSCBLOCK_ENTIREBUFFER       0x00000001

#define DSCBSTATUS_CAPTURING        0x00000001
#define DSCBSTATUS_LOOPING          0x00000002

#define DSCBSTART_LOOPING           0x00000001

#define DSBPN_OFFSETSTOP            0xFFFFFFFF

#define DS_CERTIFIED                0x00000000
#define DS_UNCERTIFIED              0x00000001

// Dsound SYSTEM resource constants
// Matches the KSAUDIO_CPU_RESOURCES_xxx_HOST_CPU values defined 
// in ksmedia.h.
#define DS_SYSTEM_RESOURCES_NO_HOST_RESOURCES  0x00000000
#define DS_SYSTEM_RESOURCES_ALL_HOST_RESOURCES 0x7FFFFFFF
#define DS_SYSTEM_RESOURCES_UNDEFINED          0x80000000




#ifdef __cplusplus
};
#endif // __cplusplus



#endif /*GHL_DSOUND_H*/