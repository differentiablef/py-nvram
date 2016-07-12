
import os

from distutils.core import setup, Extension

def get_device_defs( name ):
    ds = list()
    with open( name ) as f:
        lines = f.readlines()
        for line in lines:
            if line.find("NVRAM_DEVICE_DEF") >= 0:
                ds.append( line.strip() )
    return ds

devs = [ ];
srcs = [ './src/nv-device.c',
         './src/nv-ram.c',
         './src/nv-init.c',
         './src/nv-drivers.c' ];

for ent in os.scandir( "./src/drivers"):
    if ent.is_file() and ent.name.endswith(".c"):
        # add file to our list of sources 
        srcs.append( ent.path )

        # add any devices defined in the file
        devs.extend( get_device_defs( ent.path ) )

print(devs)

# ####################################################################
# Generate Drive Table
#  (results placed in nv-drivers.c)
#
nvdrivers_template = """
/*
 * WARNING: This File Is Auto-Generated
 */

#include "nv-device.h"

#undef NVRAM_DEVICE_DEF
#define NVRAM_DEVICE_DEF
extern struct nvdev_obj {};

#undef NVRAM_DEVICE_DEF
#define NVRAM_DEVICE_DEF &
struct nvdev_obj *nvram_drivers[] = {} {}, NULL {};
"""

fil = nvdrivers_template.format(
    ";\nextern struct nvdev_obj ".join(devs),
    "{", ",\n".join(devs), "}")

with open("./src/nv-drivers.c", "w") as f:
    f.write(fil)


nvram_module = Extension(
    'nvram',
    libraries     = [],
    include_dirs  = [ '../' ],
    library_dirs  = [],
    define_macros = [ ('_DEBUG_', 1) ],
    undef_macros  = [],
    sources       = srcs,
    depends       = [ 'src/common.h',
                      'src/nv-device.h',
                      'src/nv-ram.h' ]
)

setup ( name = 'NVRAM Interface',
	version = '0.01',
	description = 'Module abstracting and automating nvram manipulation.',
	ext_modules = [ nvram_module ] )
