gl_src = [
    'context.cpp'
]

gl_headers = [
    'context.hpp'
]

gl_deps = [
    primative_dep,
    dependency('cairo'),
    dependency('pango'),
    dependency('pangocairo'),
    dependency('dlg', fallback: ['dlg', 'dlg_dep']),
]

gl_lib = library('ogf-gl', sources: gl_src, dependencies: gl_deps,
    include_directories: internal_inc, cpp_args: '-DOGF_GL', install: true)

gl_dep = declare_dependency(link_with : gl_lib, dependencies: gl_deps,
    include_directories : internal_inc, cpp_args: '-DOGF_GL')

pkg.generate(gl_lib,
    name: 'ogf-gl',
    description: '',
    version: meson.project_version(),
    libraries: gl_dep,
    subdirs: '.')

install_headers(gl_headers, subdir: 'ogf/gl')