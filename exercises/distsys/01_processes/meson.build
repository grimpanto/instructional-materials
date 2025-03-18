# @copyright 2019 Günter Kolousek

project('01_processes', 'cpp',
        license : ['Boost'],
        version : '0.1',
        default_options : ['cpp_std=c++2a', 'warning_level=3', 'werror=true'])

inc_dir = include_directories(['include'])

src1 = ['src/aba.cpp']

executable('aba',
            sources : src1,
            include_directories : inc_dir,
          )

src2 = ['src/charout.cpp']

executable('charout',
            sources : src2,
            include_directories : inc_dir,
          )