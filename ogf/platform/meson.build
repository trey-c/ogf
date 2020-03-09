platform_src = [
    'client.cpp',
    'driver.cpp',
    'font.cpp',
    'painter.cpp'
]

platform_deps = [
    primative_dep,
    dependency('dlg', fallback: ['dlg', 'dlg_dep']),
    dependency('nytl', fallback: ['nytl', 'nytl_dep']),
]

platform_lib = library('ogf-platform', sources: platform_src, dependencies: platform_deps,
    include_directories: internal_inc)

platform_dep = declare_dependency(link_with : platform_lib, dependencies: platform_deps,
    include_directories : internal_inc)