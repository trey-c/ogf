gui_src = [
    'box.cpp',
    'button.cpp',
    'label.cpp',
    'layout.cpp',
    'spacer.cpp',
    'style.cpp',
    'titlebar.cpp',
    'widget.cpp',
    'window.cpp'
]

gui_deps = [
    core_dep
]

gui_lib = library('ogf-gui', sources: gui_src, dependencies: gui_deps,
    include_directories: internal_inc, install: true)

gui_dep = declare_dependency(link_with : gui_lib, dependencies: gui_deps,
    include_directories : internal_inc)