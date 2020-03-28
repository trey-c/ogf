gui_src = [
    'box.cpp',
    'button.cpp',
    'label.cpp',
    'spacer.cpp',
    'style.cpp',
    'titlebar.cpp',
    'widget.cpp',
    'window.cpp'
]

gui_headers = [
    'box.hpp',
    'button.hpp',
    'label.hpp',
    'spacer.hpp',
    'style.hpp',
    'titlebar.hpp',
    'widget.hpp',
    'window.hpp'
]

gui_deps = [
    core_dep
]

gui_lib = library('ogf-gui', sources: gui_src, dependencies: gui_deps,
    include_directories: internal_inc, install: true)

gui_dep = declare_dependency(link_with : gui_lib, dependencies: gui_deps,
    include_directories : internal_inc)

pkg.generate(gui_lib,
    name: 'ogf-gui',
    description: '',
    version: meson.project_version(),
    libraries: gui_dep,
    subdirs: '.')

install_headers(gui_headers, subdir: 'ogf/gui')