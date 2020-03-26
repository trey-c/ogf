subdir('primative')

if get_option('gl').enabled()
    subdir('gl')
endif

subdir('backend')

if host_machine.system() == 'linux'
    if get_option('xcb').enabled()
        subdir('xcb')
    endif
endif

if host_machine.system() == 'windows'
    if get_option('win32').enabled()
        subdir('win32')
    endif
endif

subdir('core')
subdir('gui')