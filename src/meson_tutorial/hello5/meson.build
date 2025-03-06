project('hello5', 'cpp',
        default_options : ['c_std=c11', 'cpp_std=c++11'])

inc_dir = include_directories('include')
src = ['src/main.cpp', 'src/hello.cpp']

executable('hello',
           sources : src,
           include_directories : inc_dir,
           override_options : ['cpp_std=c++17'])
