widget_tests = [
    'button',
    'label',
    'window'
]

foreach test : widget_tests
    src = test + '.test.cpp'

    exe = executable(test, src, dependencies: widget_dep, install: false)
    test('widget/' + test, exe)
endforeach