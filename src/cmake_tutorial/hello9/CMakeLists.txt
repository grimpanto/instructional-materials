cmake_minimum_required(VERSION 3.5)
project(hello9)

add_subdirectory(catch)

file(GLOB TESTS "tests/*.cpp")

add_executable(calc_test ${TESTS})
target_include_directories(calc_test PUBLIC include)
target_compile_features(calc_test PUBLIC cxx_std_14)
target_link_libraries(calc_test catch)

enable_testing()
add_test(NAME first_test COMMAND calc_test)
