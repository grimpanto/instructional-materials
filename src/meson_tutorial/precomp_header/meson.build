project('precomp_header', 'cpp')
inc_dir = include_directories('include')
src = ['src/main.cpp', 'src/hello.cpp']
executable('precomp',
           sources : src,
           include_directories : inc_dir,
           cpp_pch : 'pch/hello_pch.h')
