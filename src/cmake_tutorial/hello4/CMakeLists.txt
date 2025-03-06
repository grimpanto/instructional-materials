cmake_minimum_required(VERSION 3.5)
project(hello4)

file(GLOB SOURCES "src/*.cpp")

add_executable(hello ${SOURCES})
target_include_directories(hello PRIVATE include)
