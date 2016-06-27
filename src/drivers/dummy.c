
#include "../nv-device.h"

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

/* Device Initialize and Finalize Routines */
static int dummy_init(void)
{

    return 0;
}

static int dummy_deinit(void)
{
    return 0;
}

NVRAM_DEVICE_DEF( dummy )
{
    .name   = "dummy",

    .init   = &dummy_init,
    .deinit = &dummy_deinit,

    .find   = &dummy_find,
    .update = &dummy_update,
    .insert = &dummy_insert,
    .remove = &dummy_remove,

    .read   = &dummy_read,
    .write  = &dummy_write
};
