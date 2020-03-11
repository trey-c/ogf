backend_tests = [
    'client',
    'driver',
    'painter'
]

foreach test : backend_tests
    src = test + '.test.cpp'

    exe = executable(test, src, dependencies: backend_dep, install: false)
    test('backend/' + test, exe)
endforeach