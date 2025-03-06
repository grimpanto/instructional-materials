project('hello7', 'cpp',
        default_options : 'cpp_std=c++17')

add_global_arguments('-DMESSAGE="world"', language : 'cpp')

inc_dir = include_directories('include')
src = ['src/main.cpp', 'src/hello.cpp']

executable('hello',
           sources : src,
           include_directories : inc_dir)
