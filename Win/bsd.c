/* Implementation of BSD Unix functions needed by Glulxe
   that are missing from Visual C++. */

#include <time.h>
#include <sys/time.h>

int gettimeofday(struct timeval *tp, struct timezone *tzp)
{
  struct timespec ts;

  if (timespec_get(&ts,TIME_UTC) == 0)
    return -1;

  tp->tv_sec = ts.tv_sec;
  tp->tv_usec = ts.tv_nsec / 1000;
  return 0;
}
