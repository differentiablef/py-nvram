#ifndef _COMMON_H_
#define _COMMON_H_

#include <sys/types.h>
#include <unistd.h>

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define LIB_LOCAL __attribute__( (visibility("hidden")) )

#endif /*_COMMON_H_*/

