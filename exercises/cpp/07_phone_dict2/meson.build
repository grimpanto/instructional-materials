# @copyright 2019 Günter Kolousek

project('phone_dict2', 'cpp',
        license : ['Boost'],
        version : '0.1',
        default_options : ['cpp_std=c++2a', 'warning_level=3', 'werror=true'])

add_global_arguments('-DBACKWARD_HAS_BFD=1', language : 'cpp')

inc_dir = include_directories(['include',
                               get_option('CLI11_include_dir'),
                               get_option('fmt_include_dir'),
                               get_option('json_include_dir')])

src = ['src/main.cpp',
       'src/sll.cpp',
       'src/dictionary.cpp',
       'src/backward.cpp'
      ]

cc = meson.get_compiler('cpp')
fmt_lib_dir = join_paths(meson.current_source_dir(), get_option('fmt_lib_dir'))
lib_fmt = cc.find_library('fmt',
                          dirs : [fmt_lib_dir])


lib_bfd = cc.find_library('bfd')

executable('phone',
           sources : src,
           include_directories : inc_dir,
           dependencies : [lib_fmt, lib_bfd]
          )

doctest_dir = include_directories([get_option('doctest_include_dir')])

test_src = ['tests/test1.cpp',
            'src/sll.cpp',
            'src/dictionary.cpp']

test_exe = executable('test1',
                      sources : test_src,
                      include_directories : [inc_dir, doctest_dir])

test('test1', test_exe)
