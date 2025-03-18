
cmake_minimum_required(VERSION 3.0)

project(factoring)  # change xxx to your project name

set(CMAKE_CXX_STANDARD 14)  # change if necessary

find_package(Threads)

include_directories(include)

macro(create_targets)
  if(${ARGC} GREATER 1)
    foreach(curr_target ${ARGV})
      message(${curr_target})
      file(GLOB sources src/${curr_target}/*.cpp src/*.cpp include/${curr_target}/*.h include/*.h)
      add_executable(${curr_target} ${sources})
      target_compile_features(${curr_target} PUBLIC cxx_std_17)
      target_link_libraries(${curr_target} ${CMAKE_THREAD_LIBS_INIT})      
    endforeach(curr_target)
  else()
    message(${ARGV0})
    file(GLOB sources src/*.cpp include/*.h)
    add_executable(${ARGV0} ${sources})
    target_compile_features(${ARGV0} PUBLIC cxx_std_17)
    target_link_libraries(${ARGV0} ${CMAKE_THREAD_LIBS_INIT})    
  endif()
endmacro(create_targets)

# replace xxx with list of executables
# like: create_targets(exe) or create_targets(exe1 exe2 exe3)
# if just one target is given -> source files are in 'src'
# else -> source files specific for each target are in respective
#   subdirectories of 'src' like in 'src/exe1', 'src/exe2', and 'src/exe3'
#   common source files are in 'src'
create_targets(factoring)
