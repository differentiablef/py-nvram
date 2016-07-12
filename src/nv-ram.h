#ifndef _NV_RAM_H_
#define _NV_RAM_H_

#include <Python.h>

#include "common.h"
#include "nv-device.h"

struct nvram_cell
{
    char *name;
    void *base;
    size_t size;
    
    struct nvram_cell *next;
};


struct nvram_state
{
    struct nvram_cell *wqueue; /* write queue */
    struct nvram_cell *cache;  /* cache of read, but not updated
				  cells*/
    nvdev_t device;
};

/* *******************************************************
 * NVRAM Method Function Prototypes
 * ******************************************************/

extern PyObject *nvram_attach (PyObject *self, PyObject *args, PyObject *params);
extern PyObject *nvram_detach (PyObject *self);
extern PyObject *nvram_get    (PyObject *self, PyObject *args);
extern PyObject *nvram_set    (PyObject *self, PyObject *args);
extern PyObject *nvram_unset  (PyObject *self, PyObject *args);
extern PyObject *nvram_commit (PyObject *self);
extern PyObject *nvram_lock   (PyObject *self);
extern PyObject *nvram_unlock (PyObject *self);
extern PyObject *nvram_stats  (PyObject *self);

/* *******************************************************
 * NVRAM Implemented Drivers
 * ******************************************************/

extern struct nvdev_obj *nvram_drivers[];


#endif /*_NV_RAM_H_*/
