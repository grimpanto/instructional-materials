cmake_minimum_required(VERSION 3.5)
project(hello_shared)

file(GLOB SOURCES "src/*.cpp")

add_library(hello SHARED ${SOURCES})
target_include_directories(hello PUBLIC include)
install(TARGETS hello DESTINATION ~/lib)
