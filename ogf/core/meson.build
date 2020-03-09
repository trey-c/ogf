core_src = [
    'application.cpp'
]

core_deps = []

core_args = []

if host_machine.system() == 'linux'
    if get_option('xcb').enabled()
        core_deps += xcb_dep
        core_args += '-DOGF_XCB'
    endif
endif

core_lib = library('ogf-core', sources: core_src, dependencies: core_deps,
    include_directories: internal_inc, cpp_args: core_args)

core_dep = declare_dependency(link_with : core_lib, dependencies: core_deps,
    include_directories : internal_inc, cpp_args: core_args)