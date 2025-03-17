
src = ['src/string_utilities.cpp']

string_utilities_lib = static_library('string_utilities',
                                      sources : src,
                                      include_directories : [inc_dir]
                                     )

doctest_dir = include_directories([get_option('doctest_include_dir')])

test_src = ['tests/test1.cpp']

test_exe = executable('test1',
                      sources : test_src,
                      include_directories : [inc_dir, doctest_dir],
                      link_with : string_utilities_lib)

test('test1', test_exe)
