# @copyright 2019 Günter Kolousek

project('daytime_protobuf', 'cpp',
        license : ['Boost'],
        version : '0.1',
        default_options : ['cpp_std=c++2a', 'warning_level=3', 'werror=true'])

thread_dep = dependency('threads')

inc_dir = include_directories(['include',
                               get_option('cli11_include_dir'),
                               get_option('asio_include_dir')
                               ])

add_global_arguments('-DASIO_STANDALONE', language : 'cpp')
add_global_arguments('-DASIO_NO_DEPRECATED', language : 'cpp')

# add additional include global arguments appropriately!

# begin protobuf: https://developers.google.com/protocol-buffers/
# protobuf: must be installed independently and has to be found...
protoc = find_program('protoc', required : true)
protobuf_dep = dependency('protobuf', required : true)

gen = generator(protoc, \
  output    : ['@BASENAME@.pb.cc', '@BASENAME@.pb.h'],
  arguments : ['--proto_path=@CURRENT_SOURCE_DIR@/src', '--cpp_out=@BUILD_DIR@', '@PLAINNAME@'])

# change proto file accordingly
generated = gen.process('src/msg.proto')
# end protobuf

client_src = ['src/daytime_client/main.cpp', generated]
server_src = ['src/daytime_server/main.cpp', generated]

executable('client',
           sources : client_src,
           include_directories : inc_dir,
           dependencies : protobuf_dep,
          )

executable('server',
           sources : server_src,
           include_directories : inc_dir,
           dependencies : protobuf_dep,
          )
