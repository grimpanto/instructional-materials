# @copyright 2019 Günter Kolousek

project('sync3', 'cpp',
        license : ['Boost'],
        version : '0.1',
        default_options : ['cpp_std=c++2a', 'warning_level=3', 'werror=true'])

thread_dep = dependency('threads')

inc_dir = include_directories(['include',
                               get_option('cli11_include_dir')
                              ])

src = ['src/dining.cpp',
       'src/philosopher.cpp',
       'src/semaphore.cpp',
       'src/utils.cpp']

executable('dining',
            sources : src,
            include_directories : inc_dir,
            dependencies : thread_dep,
           )
