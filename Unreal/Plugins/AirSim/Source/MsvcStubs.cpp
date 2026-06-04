// MsvcStubs.cpp
// Provides stub implementations for MSVC CRT symbols that were removed in newer
// MSVC toolchains (VS 2022 17.10+, MSVC 14.40+) but are still referenced by
// prebuilt AirSim dependency libraries (MavLinkCom.lib, rpc.lib).
//
// These prebuilt libs were compiled against an older MSVC CRT that had C11
// threads.h internal symbols (_Thrd_sleep_for, _Cnd_timedwait_for_unchecked).
// The newer CRT inlines these differently, so the exported symbols are gone.

// Use only Win32 API headers — no UE dependencies.
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

// Sleep for a given number of milliseconds (C11 thrd_sleep / MSVC internal).
// The underlying Windows Sleep() takes a DWORD (32-bit max), so values larger
// than MAXDWORD-1 are split into chunks.  This matches the original MSVC CRT
// behaviour.
extern "C" int __cdecl _Thrd_sleep_for(unsigned __int64 ms)
{
    while (ms > 0)
    {
        DWORD chunk = (ms > MAXDWORD - 1) ? MAXDWORD - 1 : static_cast<DWORD>(ms);
        Sleep(chunk);
        ms -= chunk;
    }
    return 0;
}

// Condition-variable timed wait (MSVC CRT internal for cnd_timedwait).
// The prebuilt libs call this with opaque handles that our CRT originally
// backed by CONDITION_VARIABLE / SRWLOCK.  Delegate to the Win32 API.
//
// Returns 0 on signal, 1 on timeout (matches C11 thrd_timedout convention),
// or -1 on error (thrd_error).
extern "C" int __cdecl _Cnd_timedwait_for_unchecked(
    void*       cond,    // actually CONDITION_VARIABLE*
    void*       mtx,     // actually SRWLOCK*
    unsigned __int64 ms) // timeout in milliseconds
{
    DWORD timeout = (ms > MAXDWORD - 1) ? MAXDWORD - 1 : static_cast<DWORD>(ms);

    if (SleepConditionVariableSRW(
            static_cast<PCONDITION_VARIABLE>(cond),
            static_cast<PSRWLOCK>(mtx),
            timeout,
            0))
    {
        return 0; // condition was signaled
    }

    DWORD err = GetLastError();
    if (err == ERROR_TIMEOUT)
    {
        return 1; // thrd_timedout (same convention as C11)
    }

    // A real error occurred; map to thrd_error.
    return -1;
}
