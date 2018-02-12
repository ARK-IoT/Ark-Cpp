cmake_minimum_required(VERSION 3.6.2)

project(Ark-Cpp)

message(STATUS "Setting MSVC flags")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHc /std:c++latest -D_CRT_SECURE_NO_WARNINGS")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../bin")

#add_subdirectory(dependencies/ArduinoJson)

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/api)
include_directories(${CMAKE_SOURCE_DIR}/api/accountable)
include_directories(${CMAKE_SOURCE_DIR}/api/blockable)
include_directories(${CMAKE_SOURCE_DIR}/api/delegatable)
include_directories(${CMAKE_SOURCE_DIR}/api/loadable)
include_directories(${CMAKE_SOURCE_DIR}/api/multisignaturable)
include_directories(${CMAKE_SOURCE_DIR}/api/peerable)
include_directories(${CMAKE_SOURCE_DIR}/api/signaturable)
include_directories(${CMAKE_SOURCE_DIR}/api/transactionable)
include_directories(${CMAKE_SOURCE_DIR}/constants)
include_directories(${CMAKE_SOURCE_DIR}/model)
include_directories(${CMAKE_SOURCE_DIR}/types)
include_directories(${CMAKE_SOURCE_DIR}/utilities)

add_library(Ark-Cpp STATIC 
	api/accountable/account_gettable.cpp
	api/accountable/account_respondable.cpp
	api/blockable/block_gettable.cpp
	api/blockable/block_respondable.cpp
	api/delegatable/delegate_gettable.cpp
	api/delegatable/delegate_respondable.cpp
	api/loadable/loader_gettable.cpp
	api/loadable/loader_respondable.cpp
	api/multisignaturable/multisignature_gettable.cpp
	api/peerable/peer_gettable.cpp
	api/peerable/peer_respondable.cpp
	api/signaturable/signature_gettable.cpp
	api/transactionable/transaction_gettable.cpp
	api/transactionable/transaction_respondable.cpp
)
