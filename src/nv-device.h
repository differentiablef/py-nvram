
#ifndef _NV_DEVICE_H_
#define _NV_DEVICE_H_

#include "common.h"

/* **************************************************************
 *    nv-device: parameters and configuration 
 */
 
struct cfg_param
{
    char *identifier; /* config. param. identifier */
    int  type;        /* expected data-type of value */
    bool required;    /* determines if param. is required for
			 initialization */
    char *descr;      /* description of config parameter */
    void *value;
};

struct nvdev_cfg
{
};


/* **************************************************************
 *    nv-device abstract device definition
 */

struct nvdev_obj
{
    /* Basic Info and State Variables */
    char *name;
    uint8_t mode;
    
    /* Initialize and Finalize */
    int (*init)(void);
    int (*deinit)(void);

    /* Named-Cell Find/Update/Insert/Remove */
    void*   (*find)(const char *name, size_t *clen);
    int   (*update)(const char *name, void *ptr, size_t len);
    int   (*insert)(const char *name, void *ptr, size_t len);
    int   (*remove)(const char *name);
    
    /* Addressed Read/Write */
    int  (*read)(off_t addr, void *buf, size_t len);
    int (*write)(off_t addr, void *buf, size_t len);

    
};

#define NVRAM_DEVICE_DEF( name ) \
    LIB_LOCAL struct nvdev_obj name = 

#endif /*_NV_DEVICE_H_*/
