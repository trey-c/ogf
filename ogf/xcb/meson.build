xcb_src = [
    'client.cpp',
    'driver.cpp'
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