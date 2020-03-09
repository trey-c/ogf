primative_src = [
    'color.cpp',
    'point.cpp',
    'rect.cpp',
    'size.cpp'
]

primative_deps = []

primative_lib = library('ogf-primative', sources: primative_src, dependencies: primative_deps,
    include_directories: internal_inc)

primative_dep = declare_dependency(link_with : primative_lib, dependencies: primative_deps,
    include_directories : internal_inc)