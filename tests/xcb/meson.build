xcb_tests = [
    'client',
    'driver'
]

foreach test : xcb_tests
    src = test + '.test.cpp'

    exe = executable(test, src, dependencies: xcb_dep, install: false)
    test('xcb/' + test, exe)
endforeach