# @copyright 2019 Günter Kolousek

project('sorting', 'cpp',
        license : ['Boost'],
        version : '0.1',
        default_options : ['cpp_std=c++2a', 'warning_level=3', 'werror=true'])

inc_dir = include_directories(['include',
                               '../builds/fmt/include'])

src = ['src/main.cpp', 'src/sorting.cpp']

executable('sortit',
           sources : src,
           include_directories : inc_dir,
          )

doctest_dir = include_directories(['../builds/doctest/doctest'])

test_src = ['tests/test1.cpp', 'src/sorting.cpp']

test_exe = executable('test1',
                      sources : test_src,
                      include_directories : [inc_dir, doctest_dir])

test('test1', test_exe)
