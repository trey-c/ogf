xcb_src = [
    'client.cpp',
    'driver.cpp'
]

xcb_headers = [
    'client.hpp',
    'driver.hpp'
]

xcb_deps = [
    backend_dep,
    dependency('xcb'),
    dependency('xcb-icccm'),
    dependency('cairo-xcb')
]

xcb_lib = library('ogf-xcb', sources: xcb_src, dependencies: xcb_deps,
    include_directories: internal_inc, install: true)

xcb_dep = declare_dependency(link_with : xcb_lib, dependencies: xcb_deps,
    include_directories : internal_inc)

pkg.generate(xcb_lib,
    name: 'ogf-xcb',
    description: '',
    version: meson.project_version(),
    libraries: xcb_dep,
    subdirs: '.')

install_headers(xcb_headers, subdir: 'ogf/xcb')