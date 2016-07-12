
#ifndef _NV_DEVICE_H_
#define _NV_DEVICE_H_

#include "common.h"

/* **************************************************************
 *    nv-device: parameters and configuration 
 */

enum
{
    PARAM_STRING = 1,
    PARAM_INTEGER,
    PARAM_BOOL
};

struct nvdev_param
{
    char *id;         /* config. param. identifier */
    int  type;        /* expected data-type of value */
    bool required;    /* determines if param. is required for
			 initialization */
    char *descr;      /* description of config parameter */
};

/* **************************************************************
 *    nv-device abstract device definition
 */

typedef struct nvdev_obj *nvdev_t;

struct nvdev_obj
{
    /* Basic Info and State Variables */
    char *name;
    uint8_t mode;
    
    /* Initialize and Finalize */
    void* (*init)(nvdev_t dev);
    int (*deinit)(nvdev_t dev);

    /* Attach/Detach routines */
    int  (*attach)(nvdev_t dev, uintptr_t params[]);
    int  (*detach)(nvdev_t dev);

    /* Named-Cell Find/Update/Insert/Remove */
    void*   (*find)(nvdev_t dev, const char *name, size_t *clen);
    int   (*update)(nvdev_t dev, const char *name, void *ptr, size_t len);
    int   (*insert)(nvdev_t dev, const char *name, void *ptr, size_t len);
    int   (*remove)(nvdev_t dev, const char *name);
    
    /* Addressed Read/Write */
    int  (*read)(nvdev_t dev, off_t addr, void *buf, size_t len);
    int (*write)(nvdev_t dev, off_t addr, void *buf, size_t len);
    
    struct nvdev_param *config; /* pointer to the first member of sent.
				   terminated array of config parameter objects */
    
    int config_required;        /* if set to true, then driver requires config
				   parameters be passed to it */
    void *locals;
};

#define NVRAM_DEVICE_DEF( name ) \
    LIB_LOCAL struct nvdev_obj name = 

#endif /*_NV_DEVICE_H_*/
