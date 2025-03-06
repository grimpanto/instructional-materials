project('hello8', 'cpp',
        version : '1.0.0',
        default_options : 'cpp_std=c++17')

#conf_data = configuration_data()
#conf_data.set('version', meson.project_version())
#conf_data.set('message', 'world')
conf_data = {'version' : meson.project_version(),
             'message' : 'world'}
configure_file(input : 'config.h.in',
               output : 'config.h',
               configuration : conf_data)

inc_dir = include_directories('include')
src = ['src/main.cpp', 'src/hello.cpp']

executable('hello',
           sources : src,
           include_directories : inc_dir)
