
cmake_minimum_required(VERSION 3.0)

project(05_threads)  # change xxx to your project name

include_directories(include)

file(GLOB sources src/*.cpp include/*.h)

find_package(Threads)

set(target race)  # change xxx to the name of your executable
add_executable(${target} ${sources})
target_compile_features(${target} PUBLIC cxx_std_17)
target_link_libraries(${target} ${CMAKE_THREAD_LIBS_INIT})
