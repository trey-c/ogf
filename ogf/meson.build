subdir('primative')
subdir('platform')

if get_option('gl').enabled()
    subdir('gl')
endif

if host_machine.system() == 'linux'
    if get_option('xcb').enabled()
        subdir('xcb')
    endif
endif

subdir('core')
subdir('gui')
subdir('widget')