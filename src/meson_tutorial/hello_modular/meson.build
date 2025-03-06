project('hello_modular', 'cpp',
        default_options : 'cpp_std=c++17')

subdir('io')

inc_dir = include_directories('include')
src = ['src/main.cpp']

executable('hello',
           sources : src,
           include_directories : [inc_dir, io_inc_dir],
           link_with : io_lib)
