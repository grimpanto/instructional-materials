project('hello_dist', 'cpp',
        default_options : 'cpp_std=c++17',
        version : '1.0')

subdir('io')

src = ['src/main.cpp']

executable('hello',
           sources : src,
           include_directories : inc_dir,
           link_with : io_lib)
