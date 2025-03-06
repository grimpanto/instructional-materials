project('hello_static_extern', 'cpp',
        default_options : 'cpp_std=c++17')

inc_dir = include_directories('include')

cc = meson.get_compiler('cpp')
lib_hello = cc.find_library('hello',
                            dirs : ['/home/knslnto/workspace/school/scripts/meson_tutorial/hello_static_extern'])

src = ['src/main.cpp']

executable('hello',
           sources : src,
           include_directories : inc_dir,
           dependencies : lib_hello)
