cmake_minimum_required(VERSION 3.6.2)

if (ARDUINO)

	#if (${BOARD_ID} EQUAL "nodemcuv2")
		#set(PLATFORM_PATH "$ENV{localappdata}\arduino15\packages\esp8266\hardware\esp8266\2.4.0")
		set (PLATFORM_PATH "C:/Users/chris/AppData/Local/arduino15/packages/esp8266/hardware/esp8266")
	#endif()

	set(CMAKE_TOOLCHAIN_FILE cmake/ArduinoToolchain.cmake)

	set(ARDUINO_DEFAULT_PORT COM1) # Default Port, when not specified

else()
	set (HUNTER_ROOT .)

	include("cmake/HunterGate.cmake")

	HunterGate(
		URL "https://github.com/ruslo/hunter/archive/v0.20.14.tar.gz"
		SHA1 "18cdbf5c47abdda437c73bf5437b7c3c65afe47c"
)
endif()

project(Ark-Cpp)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
 
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
 
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR})

if (MSVC)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
elseif (UNIX)
	set (CMAKE_CXX_FLAGS "-std=c++11")
elseif (ARDUINO)
	set (CMAKE_CXX_FLAGS "-std=gnu++11 -fno-threadsafe-statics")
endif()

 
include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")

add_subdirectory(src)
add_subdirectory(tests)
