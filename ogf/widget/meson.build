widget_src = [
    'label.cpp',
    'button.cpp',
    'window.cpp'
]

widget_deps = [
    gui_dep
]

widget_lib = library('ogf-widget', sources: widget_src, dependencies: widget_deps,
    include_directories: internal_inc, install: true)

widget_dep = declare_dependency(link_with : widget_lib, dependencies: widget_deps,
    include_directories : internal_inc)