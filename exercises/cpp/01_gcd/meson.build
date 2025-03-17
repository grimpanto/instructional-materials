# @copyright 2019 Günter Kolousek

project('lcd', 'cpp',
        license : ['Boost'],
        version : '0.1',
        default_options : ['cpp_std=c++2a', 'warning_level=3', 'werror=true'])

inc_dir = include_directories('include')
src = ['src/main.cpp', 'src/gcd.cpp']

executable('gcd',
           sources : src,
           include_directories : inc_dir,
          )
