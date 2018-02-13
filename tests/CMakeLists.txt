cmake_minimum_required(VERSION 3.6.2)

project(Ark-Cpp-tests)

message(STATUS "Setting MSVC flags")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHc /std:c++latest -D_CRT_SECURE_NO_WARNINGS")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../bin")

add_dependencies(Ark-Cpp ${CMAKE_SOURCE_DIR}/../src)

include_directories(${CMAKE_SOURCE_DIR}/../src/)
include_directories(${CMAKE_SOURCE_DIR}/../src/api)
include_directories(${CMAKE_SOURCE_DIR}/../src/api/accountable)
include_directories(${CMAKE_SOURCE_DIR}/../src/api/blockable)
include_directories(${CMAKE_SOURCE_DIR}/../src/api/delegatable)
include_directories(${CMAKE_SOURCE_DIR}/../src/api/loadable)
include_directories(${CMAKE_SOURCE_DIR}/../src/api/multisignaturable)
include_directories(${CMAKE_SOURCE_DIR}/../src/api/peerable)
include_directories(${CMAKE_SOURCE_DIR}/../src/api/signaturable)
include_directories(${CMAKE_SOURCE_DIR}/../src/api/transactionable)
include_directories(${CMAKE_SOURCE_DIR}/../src/constants)
include_directories(${CMAKE_SOURCE_DIR}/../src/model)
include_directories(${CMAKE_SOURCE_DIR}/../src/types)
include_directories(${CMAKE_SOURCE_DIR}/../src/utilities)

target_link_libraries(Ark-Cpp ${CMAKE_SOURCE_DIR}/../lib/Ark-Cpp.lib)

add_executable(Ark-Cpp-tests STATIC 
	types/address.cpp
	types/balance.cpp
	types/hash.cpp
	types/publickey.cpp
)

enable_testing()

add_test(NAME address COMMAND test)