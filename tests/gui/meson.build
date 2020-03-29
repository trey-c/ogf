gui_tests = [
    'box',
    'button',
    'canvas',
    'label',
    'spacer',
    'style',
    'titlebar',
    'widget',
    'window'
]

foreach test : gui_tests
    src = test + '.test.cpp'

    exe = executable(test, src, dependencies: gui_dep, install: false)
    test('gui/' + test, exe)
endforeach