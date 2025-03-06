cmake_minimum_required(VERSION 3.9)
project(version)

set (VERSION v1.0)

file(GLOB_RECURSE SOURCES "src/*.cpp")

configure_file (
  "src/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(version ${SOURCES})
