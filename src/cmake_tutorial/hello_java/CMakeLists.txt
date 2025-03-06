cmake_minimum_required(VERSION 3.5)
project(hello_java LANGUAGES Java)

find_package(Java 1.7 REQUIRED COMPONENTS Development)
include(UseJava)

file(GLOB SOURCES "src/*.java")

add_jar(hello ${SOURCES} ENTRY_POINT HelloWorld)
