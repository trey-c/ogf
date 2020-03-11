win32_tests = [
    'client',
    'driver'
]

foreach test : win32_tests
    src = test + '.test.cpp'

    exe = executable(test, src, dependencies: win32_dep, install: false)
    test('win32/' + test, exe)
endforeach