# @copyright 2019 Günter Kolousek

project('vmath', 'cpp',
        license : ['Boost'],
        version : '0.1',
        default_options : ['cpp_std=c++2a', 'warning_level=3', 'werror=true'])

inc_dir = include_directories(['include',
                               'pystring/include',
                               get_option('CLI11_include_dir'),
                               get_option('fmt_include_dir'),
                               get_option('spdlog_include_dir'),
                               get_option('json_include_dir'),
                               get_option('magic_enum_include_dir')])

cc = meson.get_compiler('cpp')
fmt_lib_dir = join_paths(meson.current_source_dir(), get_option('fmt_lib_dir'))
spdlog_lib_dir = join_paths(meson.current_source_dir(), get_option('spdlog_lib_dir'))

lib_fmt = cc.find_library('fmt',
                          dirs : [fmt_lib_dir,
                                  spdlog_lib_dir])

subdir('pystring')

src = ['src/main.cpp']

executable('vmath',
           sources : src,
           include_directories : inc_dir,
           dependencies : lib_fmt,
           link_with : [pystring_lib]
          )