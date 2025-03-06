project('hello_install', 'cpp')

conf_data = configuration_data()

configure_file(input : 'data/data.txt',
               output : 'data.txt',
               configuration : conf_data,
               install_mode : 'rw-------',
               install_dir : '/tmp/hello')

executable('hello', 'hello.cpp',
           install : true,
           install_mode : 'rwx------',
           install_dir : '/tmp/hello')
