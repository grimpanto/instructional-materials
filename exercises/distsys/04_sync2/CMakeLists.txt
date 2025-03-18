
cmake_minimum_required(VERSION 3.0)

project(07_sync2)  # change xxx to your project name

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

create_targets(loadsim)
