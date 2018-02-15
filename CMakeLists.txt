cmake_minimum_required(VERSION 3.6.2)

project(Ark-Cpp-All)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
 
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
 
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR})
 
include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")

add_subdirectory(src)
add_subdirectory(tests)
