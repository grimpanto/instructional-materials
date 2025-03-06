cmake_minimum_required(VERSION 3.5)
project(hello_static)

file(GLOB SOURCES "src/*.cpp")

add_library(hello STATIC ${SOURCES})
target_include_directories(hello PUBLIC include)

# nicht unbedingt notwendig:
install(TARGETS hello DESTINATION ~/lib)
