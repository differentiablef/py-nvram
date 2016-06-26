
#ifndef _NV_DEVICE_H_
#define _NV_DEVICE_H_

#include "common.h"


/* **************************************************************
 *    nv-device abstract device definition
 */

struct nvdev_obj {
    /* Basic Info and State Variables */
    char *name;
    size_t size;
    size_t weight;
    uint_t flags;
    
    /* Initialize and Finalize */
    int (*init)();
    int (*deinit)();

    /* Named-Cell Find/Update/Insert/Remove */
    void*   (*find)(const char *name, size_t *clen);
    int   (*update)(const char *name, void *ptr, size_t len);
    int   (*insert)(const char *name, void *ptr, size_t len);
    int   (*remove)(const char *name);
    
    /* Addressed Read/Write */
    int  (*read)(off_t addr, void *buf, size_t len);
    int (*write)(off_t addr, void *buf, size_t len);

    
};

void nvram_dev_register( struct nvdev_obj *d );
void nvram_dev_unregister( struct nvdev_obj *d );

#endif /*_NV_DEVICE_H_*/
