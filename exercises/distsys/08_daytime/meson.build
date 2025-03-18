# @copyright 2016 Günter Kolousek

project('daytime', 'cpp',
        license : ['Boost'],
        version : '0.1',
        default_options : ['cpp_std=c++17', 'warning_level=3', 'werror=true'])

thread_dep = dependency('threads')

add_global_arguments('-DASIO_STANDALONE', language : 'cpp')
add_global_arguments('-DASIO_NO_DEPRECATED', language : 'cpp')

inc_dir = include_directories(['include',
                               get_option('cli11_include_dir'),
                               get_option('spdlog_include_dir'),
                               get_option('asio_include_dir')
                               ])

cc = meson.get_compiler('cpp')
spdlog_lib_dir = join_paths(meson.current_source_dir(), get_option('spdlog_lib_dir'))
lib_spdlog = cc.find_library('spdlog',
                             dirs : [spdlog_lib_dir])

client_src = ['src/daytime_client/main.cpp']
server_src = ['src/daytime_server/main.cpp']

executable('client',
           sources : client_src,
           include_directories : inc_dir,
           dependencies : [thread_dep, lib_spdlog]
          )

executable('server',
           sources : server_src,
           include_directories : inc_dir,
           dependencies : [thread_dep, lib_spdlog]
          )
