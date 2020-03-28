project('ogf', ['cpp'],
    license: 'LGPL-2.1',
    version: '0.1.0',
    default_options: ['cpp_std=c++17', 'werror=false'])

warnings = [
    '-Wall',
    '-Wextra',
    '-Wpedantic',
    '-Wno-non-virtual-dtor',
    '-Wno-unused-parameter',
]

cc = meson.get_compiler('cpp')
pkg = import('pkgconfig')

add_project_arguments(cc.get_supported_arguments(warnings), language: 'cpp')

internal_inc = include_directories('.')

subdir('ogf')

if get_option('tests')
    subdir('tests')
endif

if get_option('demo')
    subdir('demo')
endif
