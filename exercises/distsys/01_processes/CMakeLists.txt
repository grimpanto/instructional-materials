
cmake_minimum_required(VERSION 3.5)

project(processes)  # change your project name

include_directories(include)

file(GLOB sources src/*.cpp include/*.h)

add_executable(aba src/aba.cpp)
target_compile_features(aba PUBLIC cxx_std_17)
add_executable(charout src/charout.cpp)
target_compile_features(charout PUBLIC cxx_std_17)
