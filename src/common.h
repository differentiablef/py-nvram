#ifndef _COMMON_H_
#define _COMMON_H_
#include <Python.h>

#include <sys/types.h>
#include <unistd.h>

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define LIB_LOCAL __attribute__( (visibility("hidden")) )

#define UNDEFINED  (uintptr_t)(-1)   /* heh */

#ifdef _DEBUG_
# define __FNAME__  (1+rindex(__FILE__, '/'))

# define DEBUG(var, fmt)						\
    (void)fprintf(stderr,						\
		  "DEBUG:%s:%s:%d "#var" = %"fmt"\n",			\
		  __FNAME__, __func__, __LINE__, (var));

# define MARKER()						\
    (void)fprintf(stderr,					\
		  "MARKER:%s:%s:%d\n",				\
		  __FNAME__, __func__, __LINE__)

# define MARKER_MSG(msg)						\
    (void)fprintf(stderr,						\
		  "MARKER:%s:%s:%d %s\n",				\
		  __FNAME__, __func__, __LINE__, (msg))
#else /*_DEBUG_*/
# define MARKER()
# define MARKER_MSG(msg)
# define DEBUG(var, fmt)
#endif /*_DEBUG_*/

#endif /*_COMMON_H_*/

