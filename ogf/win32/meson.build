win32_src = [
    'client.cpp',
    'driver.cpp'
]

win32_deps = [
    backend_dep,
    dependency('cairo-win32'),
]

win32_lib = library('ogf-win32', sources: win32_src, dependencies: win32_deps,
    include_directories: internal_inc, install: true)

win32_dep = declare_dependency(link_with : win32_lib, dependencies: win32_deps,
    include_directories : internal_inc)