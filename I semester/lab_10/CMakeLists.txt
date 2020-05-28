cmake_minimum_required(VERSION 2.6)

project(List)
add_executable(List main.cpp)
set(OUTPUT_FILE_NAME List)
set(LIBSRC linkedList.h linkedList.cpp point.h point.cpp)
add_library(student ${LIBSRC})

target_link_libraries(${OUTPUT_FILE_NAME} student)

set(CMAKE_CXX_FLAGS "-Wall --pedantic")
add_custom_target(check valgrind ./${OUTPUT_FILE_NAME})
add_custom_target(run ./${OUTPUT_FILE_NAME})

install(TARGETS ${OUTPUT_FILE_NAME} DESTINATION bin)
