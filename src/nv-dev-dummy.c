
#include "common.h"
#include "nv-device.h"

/* Named-Cell Find/Update/Insert/Remove */
static void* dummy_find(const char *name, size_t *clen)
{
    return NULL;
}

static int dummy_update(const char *name, void *ptr, size_t len)
{
    return 0;
}

static int dummy_insert(const char *name, void *ptr, size_t len)
{
    return 0;
}

static int dummy_remove(const char *name)
{
    return 0;
}
    
/* Addressed Read/Write */
static int dummy_read(off_t addr, void *buf, size_t len)
{
    return 0;
}

static int dummy_write(off_t addr, void *buf, size_t len)
{
    return 0;
}

/* Initialize and Finalize Routines */
static int dummy_init()
{
}

static int dummy_deinit()
{
}



#endif /*_NV_DEVICE_H_*/
