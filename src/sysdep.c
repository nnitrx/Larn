#include "includes/larnfunc.h"
#include "includes/io.h"
#include "includes/sysdep.h"

#if defined WINDOWS || WINDOWS_VS
#include <windows.h>
#endif

#if defined NIX
#include <time.h>
#endif

void nap(int milliseconds)
{
#if defined WINDOWS || WINDOWS_VS
    Sleep(milliseconds);
#endif

#if defined NIX
    struct timespec tc;
    tc.tv_sec = milliseconds / 1000;
    tc.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&tc, NULL);
#endif
}
