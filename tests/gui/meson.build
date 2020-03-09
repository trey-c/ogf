gui_tests = [
    'layout',
    'style',
    'widget'
]

foreach test : gui_tests
    src = test + '.test.cpp'

    exe = executable(test, src, dependencies: gui_dep, install: false)
    test('gui/' + test, exe)
endforeach