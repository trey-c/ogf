backend_src = [
    'client.cpp',
    'driver.cpp',
    'font.cpp',
    'painter.cpp'
]

backend_deps = [
    primative_dep,
    gl_dep,
    dependency('dlg', fallback: ['dlg', 'dlg_dep']),
    dependency('nytl', fallback: ['nytl', 'nytl_dep']),
]

backend_lib = library('ogf-backend', sources: backend_src, dependencies: backend_deps,
    include_directories: internal_inc, install: true)

backend_dep = declare_dependency(link_with : backend_lib, dependencies: backend_deps,
    include_directories : internal_inc)