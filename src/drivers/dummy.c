#include "../nv-device.h"

/* dummy config parameters */
static struct nvdev_param dummy_config[] = {
    { "path",  PARAM_STRING, true,
      "path to the kernel interface device"              },
    { "local", PARAM_BOOL, false,
      " if true, make a local copy of the memory"			\
      " and do not commit writes/updates to the device"			\
      "  (default: True). "                              },
    { "offset", PARAM_INTEGER, false,
      " offset to cpu specific segment of memory"        },
    { "size", PARAM_INTEGER, false,
      " size of cpu specific segment of memory segment"  },
    { "doYouLift", PARAM_BOOL, true,
      " well, bro; do you?"                              },
    { NULL, 0, false, NULL                               } };


/* dummy state information */
typedef struct dummy_obj {
    
} *dummy_t;

/* Named-Cell Find/Update/Insert/Remove */
static void* dummy_find(nvdev_t dev, const char *name, size_t *clen)
{
    return NULL;
}

static int dummy_update(nvdev_t dev, const char *name, void *ptr, size_t len)
{
    return 0;
}

static int dummy_insert(nvdev_t dev, const char *name, void *ptr, size_t len)
{
    return 0;
}

static int dummy_remove(nvdev_t dev, const char *name)
{
    return 0;
}

/* Addressed Read/Write */
static int dummy_read(nvdev_t dev, off_t addr, void *buf, size_t len)
{
    return 0;
}

static int dummy_write(nvdev_t dev, off_t addr, void *buf, size_t len)
{
    return 0;
}

static int dummy_attach (nvdev_t dev, uintptr_t params[])
{
    register int i = 0;
    struct nvdev_param *p = dev->config;
    
    for (; p->id != NULL; p++) {
	DEBUG(p->id, "s");
	DEBUG(params[i], "p");
	i++;
    }

    return 0;
}

static int dummy_detach (nvdev_t dev)
{
    return 0;
}

/* Device Initialize and Finalize Routines */
static int dummy_init( nvdev_t dev )
{
    dev->locals = calloc( sizeof(dummy_config)/sizeof(struct nvdev_param),
			  sizeof(uintptr_t) );
    return dev;
}

static int dummy_deinit( nvdev_t dev )
{
    if(dev->locals)
	free(dev->locals);
    
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
	.write  = &dummy_write,

	.attach = &dummy_attach,
	.detach = &dummy_detach,
	.config = dummy_config,
	.config_required = true
	
};
