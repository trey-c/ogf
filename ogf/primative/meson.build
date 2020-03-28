primative_src = [
    'color.cpp',
    'point.cpp',
    'rect.cpp',
    'size.cpp'
]

primative_headers = [
    'color.hpp',
    'point.hpp',
    'rect.hpp',
    'size.hpp'
]

primative_deps = []

primative_lib = library('ogf-primative', sources: primative_src, dependencies: primative_deps,
    include_directories: internal_inc, install: true)

primative_dep = declare_dependency(link_with : primative_lib, dependencies: primative_deps,
    include_directories : internal_inc)

pkg.generate(primative_lib,
    name: 'ogf-primative',
    description: '',
    version: meson.project_version(),
    libraries: primative_dep,
    subdirs: '.')

install_headers(primative_headers, subdir: 'ogf/primative')