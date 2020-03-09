gl_src = [
    'context.cpp'
]

gl_deps = [
    primative_dep,
    dependency('cairo'),
    dependency('pango'),
    dependency('pangocairo')
]

gl_lib = library('ogf-gl', sources: gl_src, dependencies: gl_deps,
    include_directories: internal_inc, cpp_args: '-DOGF_GL')

gl_dep = declare_dependency(link_with : gl_lib, dependencies: gl_deps,
    include_directories : internal_inc, cpp_args: '-DOGF_GL')