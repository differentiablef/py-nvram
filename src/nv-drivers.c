
/*
 * WARNING: This File Is Auto-Generated
 */

#include "nv-device.h"

#undef NVRAM_DEVICE_DEF
#define NVRAM_DEVICE_DEF
extern struct nvdev_obj NVRAM_DEVICE_DEF( asus_nvram );
extern struct nvdev_obj NVRAM_DEVICE_DEF( dummy );
extern struct nvdev_obj NVRAM_DEVICE_DEF(filesystem);
extern struct nvdev_obj NVRAM_DEVICE_DEF(network);

#undef NVRAM_DEVICE_DEF
#define NVRAM_DEVICE_DEF &
struct nvdev_obj *nvram_drivers[] = { NVRAM_DEVICE_DEF( asus_nvram ),
NVRAM_DEVICE_DEF( dummy ),
NVRAM_DEVICE_DEF(filesystem),
NVRAM_DEVICE_DEF(network), NULL };
