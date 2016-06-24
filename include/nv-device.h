
#ifndef _NV_DEVICE_H_
#define _NV_DEVICE_H_

#include "common.h"

/* **************************************************************
 *    nv-device interface abstraction
 *          (definitions and methods)
 */

struct nv_dev_obj 
{
  size_t size;
  size_t offset;
  void  *mem;
};


#endif /*_NV_DEVICE_H_*/
