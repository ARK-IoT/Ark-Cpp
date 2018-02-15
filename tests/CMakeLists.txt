cmake_minimum_required(VERSION 3.6.2)

project(Ark-Cpp-tests)

include(CTest)

set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../lib")

include_directories(${PROJECT_SOURCE_DIR}/../src/)
include_directories(${PROJECT_SOURCE_DIR}/../src/api)
include_directories(${PROJECT_SOURCE_DIR}/../src/api/accountable)
include_directories(${PROJECT_SOURCE_DIR}/../src/api/blockable)
include_directories(${PROJECT_SOURCE_DIR}/../src/api/delegatable)
include_directories(${PROJECT_SOURCE_DIR}/../src/api/loadable)
include_directories(${PROJECT_SOURCE_DIR}/../src/api/multisignaturable)
include_directories(${PROJECT_SOURCE_DIR}/../src/api/peerable)
include_directories(${PROJECT_SOURCE_DIR}/../src/api/signaturable)
include_directories(${PROJECT_SOURCE_DIR}/../src/api/transactionable)
include_directories(${PROJECT_SOURCE_DIR}/../src/constants)
include_directories(${PROJECT_SOURCE_DIR}/../src/model)
include_directories(${PROJECT_SOURCE_DIR}/../src/types)
include_directories(${PROJECT_SOURCE_DIR}/../src/utilities)

include_directories(${PROJECT_SOURCE_DIR}/googletest/googletest/include)



#message(STATUS "Setting MSVC flags")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHc /std:c++latest -D_CRT_SECURE_NO_WARNINGS")

#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../lib")
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../lib")
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../bin")

#add_dependencies(Ark-Cpp ${CMAKE_SOURCE_DIR}/../src)

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build.  This adds
# the following targets: gtest, gtest_main, gmock
# and gmock_main
add_subdirectory(
	#"${CMAKE_BINARY_DIR}/googletest-src"
	${PROJECT_SOURCE_DIR}/googletest/
	#"${CMAKE_BINARY_DIR}/googletest-build"
	#"${CMAKE_SOURCE_DIR}/googletest/googletest/build"
)

#include_directories(${CMAKE_SOURCE_DIR}/../src/)
#include_directories(${CMAKE_SOURCE_DIR}/../src/api)
#include_directories(${CMAKE_SOURCE_DIR}/../src/api/accountable)
#include_directories(${CMAKE_SOURCE_DIR}/../src/api/blockable)
#include_directories(${CMAKE_SOURCE_DIR}/../src/api/delegatable)
#include_directories(${CMAKE_SOURCE_DIR}/../src/api/loadable)
#include_directories(${CMAKE_SOURCE_DIR}/../src/api/multisignaturable)
#include_directories(${CMAKE_SOURCE_DIR}/../src/api/peerable)
#include_directories(${CMAKE_SOURCE_DIR}/../src/api/signaturable)
#include_directories(${CMAKE_SOURCE_DIR}/../src/api/transactionable)
#include_directories(${CMAKE_SOURCE_DIR}/../src/constants)
#include_directories(${CMAKE_SOURCE_DIR}/../src/model)
#include_directories(${CMAKE_SOURCE_DIR}/../src/types)
#include_directories(${CMAKE_SOURCE_DIR}/../src/utilities)

#include_directories(${CMAKE_SOURCE_DIR}/googletest/googletest/include)

#target_link_libraries(Ark-Cpp-tests Ark-Cpp)

include_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

add_executable(Ark-Cpp-tests
	${PROJECT_SOURCE_DIR}/model/account.cpp
	${PROJECT_SOURCE_DIR}/model/block.cpp
	${PROJECT_SOURCE_DIR}/model/currency.cpp
	${PROJECT_SOURCE_DIR}/model/delegate.cpp
	${PROJECT_SOURCE_DIR}/model/fees.cpp
	${PROJECT_SOURCE_DIR}/model/network.cpp
	${PROJECT_SOURCE_DIR}/model/peer.cpp
#	${PROJECT_SOURCE_DIR}/model/signature.cpp
#	${PROJECT_SOURCE_DIR}/model/transaction.cpp
#	${PROJECT_SOURCE_DIR}/model/voter.cpp
	${PROJECT_SOURCE_DIR}/types/address.cpp
	${PROJECT_SOURCE_DIR}/types/balance.cpp
	${PROJECT_SOURCE_DIR}/types/hash.cpp
	${PROJECT_SOURCE_DIR}/types/publickey.cpp
)

target_link_libraries(Ark-Cpp-tests 
	${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/debug/Ark-Cpp-libd.${STATIC_LIB_EXTENSION}
	${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/debug/gtestd.${STATIC_LIB_EXTENSION}
	${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/debug/gtest_maind.${STATIC_LIB_EXTENSION}
)

add_test(NAME test COMMAND Ark-Cpp-tests)

