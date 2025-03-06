
file(GLOB SOURCES "src/*.cpp")

add_library(hello_static STATIC ${SOURCES})
target_include_directories(hello_static PUBLIC include)
#install(TARGETS sayhello DESTINATION ${CMAKE_SOURCE_DIR}/build)
