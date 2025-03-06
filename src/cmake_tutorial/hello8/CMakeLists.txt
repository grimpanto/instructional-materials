cmake_minimum_required(VERSION 3.5)
project(hello8)

add_subdirectory(hello_headeronly)

file(GLOB SOURCES "src/*.cpp")

add_executable(hello ${SOURCES})
target_compile_features(hello PUBLIC cxx_std_14)
target_link_libraries(hello say_hello_headeronly)
