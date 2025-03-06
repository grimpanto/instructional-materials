cmake_minimum_required(VERSION 3.5)

project(hello5)

#include_directories(include)

file(GLOB SOURCES "src/*.cpp")

link_directories(~/lib)
# alternativ, wenn direkt verwendet:
#   link_directories(../hello_shared/build)
link_directories(../hello_shared/build)
add_executable(hello ${SOURCES})
target_include_directories(hello PRIVATE ../hello_shared/include)
target_link_libraries(hello PRIVATE libhello.so)

set(MY_DEBUG_OPTIONS -Wall)
set(MY_RELEASE_OPTIONS -O2)

target_compile_options(hello PUBLIC "$<$<CONFIG:Debug>:${MY_DEBUG_OPTIONS}>")
target_compile_options(hello PUBLIC "$<$<CONFIG:Release>:${MY_RELEASE_OPTIONS}>")
