gl_tests = [
    'context',
]

foreach test : gl_tests
    src = test + '.test.cpp'

    exe = executable(test, src, dependencies: gl_dep, install: false)
    test('gl/' + test, exe)
endforeach