cmake_minimum_required(VERSION 3.9)
project(version)

file(GLOB_RECURSE SOURCES "src/*.cpp")

find_package(Hg)
if(HG_FOUND)
  HG_WC_INFO(${PROJECT_SOURCE_DIR} Project)
  set(REVISION ${Project_WC_REVISION})
  set(CHANGESET ${Project_WC_CHANGESET})
endif()

configure_file(
  "src/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(version ${SOURCES})
