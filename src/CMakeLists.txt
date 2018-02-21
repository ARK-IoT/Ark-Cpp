cmake_minimum_required(VERSION 3.6.2)

project(Ark-Cpp-lib)

hunter_add_package(nlohmann_json)
hunter_add_package(OpenSSL)
hunter_add_package(PocoCpp)

set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
 
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
 
 find_package(nlohmann_json CONFIG REQUIRED)
 find_package(OpenSSL REQUIRED)
 find_package(Poco REQUIRED Net CONFIG)

set(COMMON_SRC 
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
	${PROJECT_SOURCE_DIR}/api/manager.cpp
	${PROJECT_SOURCE_DIR}/constants/networks.cpp
	${PROJECT_SOURCE_DIR}/model/account.cpp
	${PROJECT_SOURCE_DIR}/model/block.cpp
	${PROJECT_SOURCE_DIR}/model/currency.cpp
	${PROJECT_SOURCE_DIR}/model/delegate.cpp
	${PROJECT_SOURCE_DIR}/model/fees.cpp
	${PROJECT_SOURCE_DIR}/model/network.cpp
	${PROJECT_SOURCE_DIR}/model/peer.cpp
	${PROJECT_SOURCE_DIR}/model/transaction.cpp
	${PROJECT_SOURCE_DIR}/model/voter.cpp
	${PROJECT_SOURCE_DIR}/utilities/connector.cpp
)

set(PLATFORM_SRC 
	${PROJECT_SOURCE_DIR}/utilities/json.cpp
	${PROJECT_SOURCE_DIR}/utilities/http.cpp
)

#set(PLATFORM_SRC 
#	${PROJECT_SOURCE_DIR}/utilities/json_arduino.cpp
#	${PROJECT_SOURCE_DIR}/utilities/http_arduino.cpp
#)

add_library(Ark-Cpp-lib STATIC ${COMMON_SRC} ${PLATFORM_SRC})

target_link_libraries(Ark-Cpp-lib PUBLIC nlohmann_json)
target_link_libraries(Ark-Cpp-lib PUBLIC OpenSSL::SSL OpenSSL::Crypto)
target_link_libraries(Ark-Cpp-lib PUBLIC Poco::Net)

