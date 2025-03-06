project('unittests', 'cpp',
        default_options : 'cpp_std=c++17')

catch_dir = include_directories('/home/knslnto/workspace/builds/Catch2/single_include/catch2')
inc_dir = include_directories('include')
src = ['src/main.cpp', 'src/fact.cpp']

executable('fact',
           sources : src,
           include_directories : inc_dir)

test_src = ['tests/test1.cpp', 'src/fact.cpp']

test_exe = executable('test_exe',
                      sources : test_src,
                      include_directories : [inc_dir, catch_dir])

test('test1', test_exe,
     suite : 'suite1')

test('test2', test_exe,
     suite : ['suite1', 'suite2'])
