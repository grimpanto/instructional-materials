# @copyright 2019 Günter Kolousek

project('calc_awards', 'cpp',
        license : ['Boost'],
        version : '0.1',
        default_options : ['cpp_std=c++2a', 'warning_level=3', 'werror=true'])

inc_dir = include_directories(['include',
                               get_option('CLI11_include_dir'),
                               get_option('fmt_include_dir')])

src = ['src/main.cpp',
       'src/calc_awards.cpp',
       'src/file_utilities.cpp',
       'src/string_utilities.cpp',
       'src/csv_utilities.cpp',
       'src/string_utilities.cpp',
      ]

cc = meson.get_compiler('cpp')
fmt_lib_dir = join_paths(meson.current_source_dir(), get_option('fmt_lib_dir'))
lib_fmt = cc.find_library('fmt',
                          dirs : [fmt_lib_dir])

executable('awards',
           sources : src,
           include_directories : inc_dir,
           dependencies : lib_fmt
          )