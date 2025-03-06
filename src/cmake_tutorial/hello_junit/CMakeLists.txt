cmake_minimum_required(VERSION 3.5)
project(hello_java LANGUAGES Java)

enable_testing()

find_package(Java 1.7 REQUIRED COMPONENTS Development)
include(UseJava)

file(GLOB SOURCES "src/*.java")

add_jar(hello ${SOURCES} ENTRY_POINT HelloWorld)
get_target_property(jarFile hello JAR_FILE)

file(GLOB TESTS "tests/*.java")
set(ALL ${SOURCES} ${TESTS})

file(GLOB JUNIT_JAR_FILE "tests/junit*.jar")
file(GLOB HAMCREST_JAR_FILE "tests/hamcrest*.jar")

add_jar(helloTest ${ALL} INCLUDE_JARS ${JUNIT_JAR_FILE} ENTRY_POINT TestHelloWorld)
get_target_property(junitJarFile helloTest JAR_FILE)

add_test(NAME helloTest COMMAND ${Java_JAVA_EXECUTABLE} -cp .:${junitJarFile}:${JUNIT_JAR_FILE}:${HAMCREST_JAR_FILE} org.junit.runner.JUnitCore TestHelloWorld)
