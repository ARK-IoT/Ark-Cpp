cmake_minimum_required(VERSION 3.6.2)

project(Ark-Cpp-lib)

set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
 
#set(PROJECT1_SRCS 
#${PROJECT_SOURCE_DIR}/some.cpp
#${PROJECT_SOURCE_DIR}/someother.cpp
#)
 
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/api)
include_directories(${PROJECT_SOURCE_DIR}/api/accountable)
include_directories(${PROJECT_SOURCE_DIR}/api/blockable)
include_directories(${PROJECT_SOURCE_DIR}/api/delegatable)
include_directories(${PROJECT_SOURCE_DIR}/api/loadable)
include_directories(${PROJECT_SOURCE_DIR}/api/multisignaturable)
include_directories(${PROJECT_SOURCE_DIR}/api/peerable)
include_directories(${PROJECT_SOURCE_DIR}/api/signaturable)
include_directories(${PROJECT_SOURCE_DIR}/api/transactionable)
include_directories(${PROJECT_SOURCE_DIR}/constants)
include_directories(${PROJECT_SOURCE_DIR}/model)
include_directories(${PROJECT_SOURCE_DIR}/types)
include_directories(${PROJECT_SOURCE_DIR}/utilities)
 
#add_library(${PROJECT_NAME} SHARED ${PROJECT1_SRCS})

add_library(Ark-Cpp-lib STATIC 
	${PROJECT_SOURCE_DIR}/api/accountable/account_gettable.cpp
	${PROJECT_SOURCE_DIR}/api/accountable/account_respondable.cpp
	${PROJECT_SOURCE_DIR}/api/blockable/block_gettable.cpp
	${PROJECT_SOURCE_DIR}/api/blockable/block_respondable.cpp
	${PROJECT_SOURCE_DIR}/api/delegatable/delegate_gettable.cpp
	${PROJECT_SOURCE_DIR}/api/delegatable/delegate_respondable.cpp
	${PROJECT_SOURCE_DIR}/api/loadable/loader_gettable.cpp
	${PROJECT_SOURCE_DIR}/api/loadable/loader_respondable.cpp
	${PROJECT_SOURCE_DIR}/api/multisignaturable/multisignature_gettable.cpp
	${PROJECT_SOURCE_DIR}/api/peerable/peer_gettable.cpp
	${PROJECT_SOURCE_DIR}/api/peerable/peer_respondable.cpp
	${PROJECT_SOURCE_DIR}/api/signaturable/signature_gettable.cpp
	${PROJECT_SOURCE_DIR}/api/transactionable/transaction_gettable.cpp
	${PROJECT_SOURCE_DIR}/api/transactionable/transaction_respondable.cpp
	${PROJECT_SOURCE_DIR}/constants/networks.cpp
	${PROJECT_SOURCE_DIR}/model/account.cpp
	${PROJECT_SOURCE_DIR}/model/block.cpp
	${PROJECT_SOURCE_DIR}/model/currency.cpp
	${PROJECT_SOURCE_DIR}/model/delegate.cpp
	${PROJECT_SOURCE_DIR}/model/network.cpp
	${PROJECT_SOURCE_DIR}/model/voter.cpp
)


#message(STATUS "Setting MSVC flags")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHc /std:c++latest -D_CRT_SECURE_NO_WARNINGS")

#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../lib")
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../lib")
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../bin")

#add_subdirectory(dependencies/ArduinoJson)

#include_directories(${CMAKE_SOURCE_DIR})
#include_directories(${CMAKE_SOURCE_DIR}/api)
#include_directories(${CMAKE_SOURCE_DIR}/api/accountable)
#include_directories(${CMAKE_SOURCE_DIR}/api/blockable)
#include_directories(${CMAKE_SOURCE_DIR}/api/delegatable)
#include_directories(${CMAKE_SOURCE_DIR}/api/loadable)
#include_directories(${CMAKE_SOURCE_DIR}/api/multisignaturable)
#include_directories(${CMAKE_SOURCE_DIR}/api/peerable)
#include_directories(${CMAKE_SOURCE_DIR}/api/signaturable)
#include_directories(${CMAKE_SOURCE_DIR}/api/transactionable)
#include_directories(${CMAKE_SOURCE_DIR}/constants)
#include_directories(${CMAKE_SOURCE_DIR}/model)
#include_directories(${CMAKE_SOURCE_DIR}/types)
#include_directories(${CMAKE_SOURCE_DIR}/utilities)

#add_library(Ark-Cpp STATIC 
#	api/accountable/account_gettable.cpp
#	api/accountable/account_respondable.cpp
#	api/blockable/block_gettable.cpp
#	api/blockable/block_respondable.cpp
#	api/delegatable/delegate_gettable.cpp
#	api/delegatable/delegate_respondable.cpp
#	api/loadable/loader_gettable.cpp
#	api/loadable/loader_respondable.cpp
#	api/multisignaturable/multisignature_gettable.cpp
#	api/peerable/peer_gettable.cpp
#	api/peerable/peer_respondable.cpp
#	api/signaturable/signature_gettable.cpp
#	api/transactionable/transaction_gettable.cpp
#	api/transactionable/transaction_respondable.cpp
#	constants/networks.cpp
#	model/account.cpp
#	model/delegate.cpp
#	model/network.cpp
#	model/voter.cpp
#)
