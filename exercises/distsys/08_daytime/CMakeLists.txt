
cmake_minimum_required(VERSION 3.0)

project(xxx)  # change xxx to your project name

set(CMAKE_CXX_STANDARD 14)  # change if necessary

add_definitions(-DASIO_STANDALONE)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  add_definitions(-Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion)
  # add_definitions(-Wl,--no-as-needed)  # needed for building on buggy configurations
else()
  add_definitions(-DASIO_HAS_STD_ADDRESSOF)
  add_definitions(-DASIO_HAS_STD_ARRAY)
  add_definitions(-DASIO_HAS_CSTDINT)
  add_definitions(-DASIO_HAS_STD_SHARED_PTR)
  add_definitions(-DASIO_HAS_STD_TYPE_TRAITS)
  add_definitions(-DASIO_HAS_STD_ATOMIC)
  add_definitions(-D_WIN32_WINNT=0x0501)
  add_definitions(/Wall /EHsc)
endif()

find_package(Threads)

include_directories(include)

# important: Don't forget to set the environment variable accordingly (if needed)!
# https://github.com/chriskohlhoff/asio
include_directories($ENV{ASIO_INCLUDE_PATH})

# https://github.com/gabime/spdlog
include_directories($ENV{SPDLOG_INCLUDE_PATH})

# https://github.com/fmtlib/fmt (http://fmtlib.net)
include_directories($ENV{FMT_PATH})  # should refer to the root directory of fmt

# https://github.com/nlohmann/json (https://nlohmann.github.io/json/)
include_directories($ENV{JSON_INCLUDE_PATH})  # should refer to the directory 'src' of json

# https://github.com/muellan/clipp
include_directories($ENV{CLIPP_INCLUDE_PATH})


set(FMT_LIB_PATH $ENV{FMT_PATH}/build/fmt/libfmt.a)

# only needed for protobuf
#find_package(Protobuf REQUIRED)
#include_directories(${Protobuf_INCLUDE_DIRS})
#include_directories(${CMAKE_CURRENT_BINARY_DIR})
#file(GLOB protos protos/*.proto)
#protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${protos})

macro(create_targets)
  if(${ARGC} GREATER 1)
    foreach(curr_target ${ARGV})
      message(${curr_target})
      file(GLOB sources src/${curr_target}/*.cpp src/*.cpp)
      add_executable(${curr_target} ${sources} ${PROTO_SRCS} ${PROTO_HDRS})
      target_link_libraries(${curr_target} ${CMAKE_THREAD_LIBS_INIT} ${FMT_LIB_PATH} ${Protobuf_LIBRARIES})
    endforeach(curr_target)
  else()
    message(${ARGV0})
    IF(EXISTS "${CMAKE_SOURCE_DIR}/src/${ARGV0}" AND IS_DIRECTORY "${CMAKE_SOURCE_DIR}/src/${ARGV0}")
      file(GLOB sources src/${ARGV0}/*.cpp src/*.cpp)
    else()
      file(GLOB sources src/*.cpp)
    endif()
    message(${sources})
    add_executable(${ARGV0} ${sources} ${PROTO_SRCS} ${PROTO_HDRS})
    target_link_libraries(${ARGV0} ${CMAKE_THREAD_LIBS_INIT} ${FMT_LIB_PATH} ${Protobuf_LIBRARIES})
  endif()
endmacro(create_targets)

# replace xxx with list of executables
# like: create_targets(exe) or create_targets(exe1 exe2 exe3)
# if just one target is given -> source files are in 'src'
# else -> source files specific for each target are in respective
#   subdirectories of 'src' like in 'src/exe1', 'src/exe2', and 'src/exe3'
#   common source files are in 'src'
create_targets(daytime_client daytime_server)
