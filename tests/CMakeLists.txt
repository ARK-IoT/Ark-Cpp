cmake_minimum_required(VERSION 3.6.2)

project(Ark-Cpp-tests)

include(CTest)

message(STATUS "Setting MSVC flags")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHc /std:c++latest -D_CRT_SECURE_NO_WARNINGS")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../bin")

#add_dependencies(Ark-Cpp ${CMAKE_SOURCE_DIR}/../src)

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build.  This adds
# the following targets: gtest, gtest_main, gmock
# and gmock_main
add_subdirectory(
	#"${CMAKE_BINARY_DIR}/googletest-src"
	"${CMAKE_SOURCE_DIR}/googletest/"
	#"${CMAKE_BINARY_DIR}/googletest-build"
	#"${CMAKE_SOURCE_DIR}/googletest/googletest/build"
)

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

include_directories(${CMAKE_SOURCE_DIR}/googletest/googletest/include)

#target_link_libraries(Ark-Cpp-tests Ark-Cpp)

add_executable(Ark-Cpp-tests
	model/account.cpp
	model/block.cpp
	model/currency.cpp
#	model/delegate.cpp
#	model/fees.cpp
#	model/network.cpp
#	model/peer.cpp
#	model/signature.cpp
#	model/transaction.cpp
#	model/voter.cpp
	types/address.cpp
	types/balance.cpp
	types/hash.cpp
	types/publickey.cpp
)

target_link_libraries(Ark-Cpp-tests 
	${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/Ark-Cpp.lib
	${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/gtestd.lib 
	${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/gtest_maind.lib
)

add_test(NAME test COMMAND Ark-Cpp-tests)

