cmake_minimum_required(VERSION 3.5)
project(hello7)

add_subdirectory(hello_static)

file(GLOB SOURCES "src/*.cpp")

add_executable(hello ${SOURCES})
target_compile_features(hello PUBLIC cxx_std_14)  # also _11 and _17
target_include_directories(hello PRIVATE hello_static/include)
target_link_libraries(hello hello_static)
