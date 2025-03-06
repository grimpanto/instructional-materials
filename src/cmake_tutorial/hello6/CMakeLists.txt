cmake_minimum_required(VERSION 3.5)
project(hello6)

file(GLOB SOURCES "src/*.cpp")

link_directories(../hello_static/build)
# alternativ, wenn statische Library installiert:
#   link_directories(~/lib)
add_executable(hello ${SOURCES})
target_include_directories(hello PRIVATE ../hello_static/include)
target_link_libraries(hello PRIVATE libhello.a)
