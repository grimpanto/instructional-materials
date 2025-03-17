
src = ['src/repl.cpp']

repl_lib = shared_library('repl',
                           sources : src,
                           include_directories : [inc_dir],
                           link_with : [pystring_lib],
                           soversion : '1'
                          )