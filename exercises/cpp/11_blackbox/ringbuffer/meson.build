# @copyright 2019 Günter Kolousek

test_src = ['tests/test1.cpp']

test_exe = executable('test1',
                      sources : test_src,
                      include_directories : [inc_dir, doctest_dir]
                     )

test('test1', test_exe)
