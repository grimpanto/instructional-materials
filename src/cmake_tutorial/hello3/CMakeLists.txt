cmake_minimum_required(VERSION 3.5)
project(hello3)
# 1.
#set(SOURCES src/main.cpp src/hello.cpp)

# 2.
file(GLOB SOURCES "src/*.cpp")

add_executable(hello ${SOURCES})

