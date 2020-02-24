cmake_minimum_required (VERSION 2.6)

project (main)

add_executable(main main.cpp)
set(OUTPUT_FILE_NAME main)

set(LIBSRC intArrayList.h intArrayList.cpp)
add_library(arr ${LIBSRC})

target_link_libraries(${OUTPUT_FILE_NAME} arr)

set(CMAKE_CXX_FLAGS "-Wall --pedantic -g")

add_custom_target(run ./${OUTPUT_FILE_NAME})
add_custom_target(check valgrind ./${OUTPUT_FILE_NAME})


