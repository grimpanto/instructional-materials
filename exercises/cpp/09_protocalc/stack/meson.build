
src = ['src/stack.cpp']

stack_lib = static_library('calc',
                           sources : src,
                           include_directories : [inc_dir]
                          )

test_src = ['tests/test1.cpp']

test_exe = executable('test1',
                      sources : test_src,
                      include_directories : [inc_dir, doctest_dir],
                      dependencies : lib_fmt,
                      link_with : stack_lib)

test('test1', test_exe)
