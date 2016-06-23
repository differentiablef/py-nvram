from distutils.core import setup, Extension

nvram_module = Extension(
    'nvram',
    sources       = ['src/nvram-bcrm.c', 'src/nvram.c'],
    libraries     = [],
    
    include_dirs  = [ './include' ],
    library_dirs  = [],
    define_macros = [ ('DEBUG', 1) ],
    undef_macros  = []
    
)


setup ( name = 'NVRAM Interface',
	version = '0.01',
	description = 'Module abstracting and automating nvram manipulation.',
	ext_modules = [ nvram_module ])
