from distutils.core import setup, Extension

nvram_module = Extension(
    'nvram',
    libraries     = [],
    include_dirs  = [ './include/' ],
    library_dirs  = [],
    define_macros = [ ('DEBUG', 1) ],
    undef_macros  = [],
    sources       = [ 'src/nv-device.c',
                      'src/nv-dev-net.c',
                      'src/nv-dev-dummy.c',
                      'src/nv-dev-file.c',
                      'src/nv-dev-bcrm.c',
                      'src/nv-init.c' ],
    depends       = [ 'src/common.h',
                      'src/nv-device.h',
                      'src/nv-ram.h' ]
)

setup ( name = 'NVRAM Interface',
	version = '0.01',
	description = 'Module abstracting and automating nvram manipulation.',
	ext_modules = [ nvram_module ] )
