/* Visual C++ lacks sys/time.h */

#define WIN32_LEAN_AND_MEAN
#include "winsock.h"

int gettimeofday(struct timeval *tp, struct timezone *tzp);
