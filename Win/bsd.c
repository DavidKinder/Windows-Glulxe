/* Implementation of BSD Unix functions needed by Glulxe
   that are missing from Visual C++. */

#include <stdint.h>
#include <sys/time.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

int gettimeofday(struct timeval *tp, struct timezone *tzp)
{
  FILETIME sysTime;
  GetSystemTimeAsFileTime(&sysTime);

  // System time in microseconds since 1601-01-01
  uint64_t time = (uint64_t)sysTime.dwLowDateTime;
  time += (uint64_t)sysTime.dwHighDateTime << 32;
  time /= 10;

  // System time in microseconds since 1970-01-01
  time -= 11644473600000000ULL;

  tp->tv_sec = (long)(time / 1000000);
  tp->tv_usec = (long)(time % 1000000);
  return 0;
}
