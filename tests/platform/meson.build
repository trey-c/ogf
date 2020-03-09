platform_tests = [
    'client',
    'driver',
    'painter'
]

foreach test : platform_tests
    src = test + '.test.cpp'

    exe = executable(test, src, dependencies: platform_dep, install: false)
    test('platform/' + test, exe)
endforeach