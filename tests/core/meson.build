core_tests = [
    'application'
]

foreach test : core_tests
    src = test + '.test.cpp'

    exe = executable(test, src, dependencies: core_dep, install: false)
    test('core/' + test, exe)
endforeach