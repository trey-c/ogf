primative_tests = [
    'color',
    'point',
    'rect',
    'size'
]

foreach test : primative_tests
    src = test + '.test.cpp'

    exe = executable(test, src, dependencies: primative_dep, install: false)
    test('primative/' + test, exe)
endforeach