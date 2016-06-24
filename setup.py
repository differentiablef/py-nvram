from distutils.core import setup, Extension

nvram_module = Extension(
    'nvram',
    libraries     = [],
    include_dirs  = [ './include' ],
    library_dirs  = [],
    define_macros = [ ('DEBUG', 1) ],
    undef_macros  = [],
    sources       = ['src/nv-init.c',
                     'src/nv-device.c',
                     'src/nvram-bcrm.c']
)

setup ( name = 'NVRAM Interface',
	version = '0.01',
	description = 'Module abstracting and automating nvram manipulation.',
	ext_modules = [ nvram_module ])
