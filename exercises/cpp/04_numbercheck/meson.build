# @copyright 2019 Günter Kolousek

project('numbercheck', 'cpp',
        license : ['Boost'],
        version : '0.1',
        default_options : ['cpp_std=c++2a', 'warning_level=3', 'werror=true'])

inc_dir = include_directories(['include',
                               get_option('CLI11_include_dir'),
                               get_option('fmt_include_dir')])

src = ['src/main.cpp']

executable('isfp',
           sources : src,
           include_directories : inc_dir,
          )

doctest_dir = include_directories([get_option('doctest_include_dir')])

test_src = ['tests/test1.cpp']

test_exe = executable('test1',
                      sources : test_src,
                      include_directories : [inc_dir, doctest_dir])

test('test1', test_exe)
