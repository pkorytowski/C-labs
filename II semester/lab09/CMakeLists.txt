cmake_minimum_required(VERSION 2.6)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(List)
add_executable(Instalator main.cpp)
set(OUTPUT_FILE_NAME Instalator)
set(LIBSRC main.cpp MyText.h MyLine.h MyPrintable.h MyPrinter.cpp MyPrinter.h Attributes.h)
add_library(student ${LIBSRC})

target_link_libraries(${OUTPUT_FILE_NAME} student)

set(CMAKE_CXX_FLAGS "-Wall -g --pedantic")
add_custom_target(check valgrind ./${OUTPUT_FILE_NAME})
add_custom_target(run ./${OUTPUT_FILE_NAME})

install(TARGETS ${OUTPUT_FILE_NAME} DESTINATION bin)
