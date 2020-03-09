xcb_src = [
    'client.cpp',
    'driver.cpp',
    'font.cpp',
    'painter.cpp'
]

xcb_deps = [
    platform_dep,
    gl_dep,
    dependency('xcb'),
    dependency('xcb-icccm'),
    dependency('cairo-xcb')
]

xcb_lib = library('ogf-xcb', sources: xcb_src, dependencies: xcb_deps,
    include_directories: internal_inc)

xcb_dep = declare_dependency(link_with : xcb_lib, dependencies: xcb_deps,
    include_directories : internal_inc)