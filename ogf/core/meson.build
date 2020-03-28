core_src = [
    'application.cpp'
]

core_headers = [
    'application.hpp'
]

core_deps = []

core_args = []

if host_machine.system() == 'linux'
    if get_option('xcb').enabled()
        core_deps += xcb_dep
        core_args += '-DOGF_XCB'
    endif
endif

if host_machine.system() == 'windows'
    if get_option('win32').enabled()
        core_deps += win32_dep
        core_args += '-DOGF_WIN32'
    endif
endif

core_lib = library('ogf-core', sources: core_src, dependencies: core_deps,
    include_directories: internal_inc, cpp_args: core_args, install: true)

core_dep = declare_dependency(link_with : core_lib, dependencies: core_deps,
    include_directories : internal_inc, cpp_args: core_args)

pkg.generate(core_lib,
    name: 'ogf-core',
    description: '',
    version: meson.project_version(),
    libraries: core_dep,
    subdirs: '.')

install_headers(core_headers, subdir: 'ogf/core')