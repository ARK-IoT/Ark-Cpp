cmake_minimum_required(VERSION 3.6.2)

project(Ark-Cpp)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
 
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
 
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR})

if (MSVC)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
	set(STATIC_LIB_EXTENSION lib)
elseif (UNIX)
	set(STATIC_LIB_EXTENSION a)
	set (CMAKE_CXX_FLAGS -std=c++11)
endif()

 
include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")

add_subdirectory(src)
add_subdirectory(tests)
