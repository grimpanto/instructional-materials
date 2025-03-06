project('protobuf_example', 'cpp',
        license : ['Boost'],
        version : '0.1',
        default_options : ['cpp_std=c++17', 'warning_level=3', 'werror=true'])

thread_dep = dependency('threads')

add_global_arguments('-I' + get_option('asio_include_dir'), language : 'cpp')
add_global_arguments('-DASIO_STANDALONE', language : 'cpp')
add_global_arguments('-DASIO_NO_DEPRECATED', language : 'cpp')

add_global_arguments('-I' + get_option('clipp_include_dir'), language : 'cpp')

add_global_arguments('-I' + get_option('spdlog_include_dir'), language : 'cpp')

add_global_arguments('-I' + get_option('cli11_include_dir'), language : 'cpp')

# subdir('SUBDIR1')

protoc = find_program('protoc', required : true)
dep = dependency('protobuf', required : true)

gen = generator(protoc, \
  output    : ['@BASENAME@.pb.cc', '@BASENAME@.pb.h'],
  arguments : ['--proto_path=@CURRENT_SOURCE_DIR@/src', '--cpp_out=@BUILD_DIR@', '@PLAINNAME@'])

generated = gen.process('src/defs.proto')
                         
inc_dir = include_directories('include')
src = ['src/main.cpp', generated]

executable('go',
           sources : src,
           include_directories : inc_dir,
           override_options : ['unity=off'],
           dependencies : [thread_dep, dep]
          )
