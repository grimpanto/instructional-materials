project('hello_static', 'cpp',
        default_options : 'cpp_std=c++17')


inc_dir = include_directories('include')

hello_lib = static_library('hello',
                           sources : 'hello/hello.cpp',
                           include_directories : inc_dir)
src = ['src/main.cpp']

executable('hello',
           sources : src,
           include_directories : inc_dir,
           link_with : hello_lib)
