project('hello_shared', 'cpp',
        default_options : 'cpp_std=c++17')


inc_dir = include_directories('include')

hello_lib = shared_library('hello',
                           sources : 'hellolib/hello.cpp',
                           include_directories : inc_dir,
                           version : '1.0.0')
src = ['src/main.cpp']

executable('hello',
           sources : src,
           include_directories : inc_dir,
           link_with : hello_lib)
