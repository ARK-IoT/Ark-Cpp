
cmake_minimum_required(VERSION 3.6.2)

project(Ark-Cpp-lib)

hunter_add_package(nlohmann_json)
hunter_add_package(PocoCpp)

#set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
 
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/Ark-Cpp)
 
find_package(nlohmann_json CONFIG REQUIRED)
find_package(Poco REQUIRED Net CONFIG)

set(COMMON_SRC 
	${PROJECT_SOURCE_DIR}/Ark-Cpp/api/accountable/account_gettable.cpp
	${PROJECT_SOURCE_DIR}/Ark-Cpp/api/accountable/account_respondable.cpp
	${PROJECT_SOURCE_DIR}/Ark-Cpp/api/blockable/block_gettable.cpp
	${PROJECT_SOURCE_DIR}/Ark-Cpp/api/blockable/block_respondable.cpp
	${PROJECT_SOURCE_DIR}/Ark-Cpp/api/delegatable/delegate_gettable.cpp
	${PROJECT_SOURCE_DIR}/Ark-Cpp/api/delegatable/delegate_respondable.cpp
	${PROJECT_SOURCE_DIR}/Ark-Cpp/api/loadable/loader_gettable.cpp
	${PROJECT_SOURCE_DIR}/Ark-Cpp/api/loadable/loader_respondable.cpp
	${PROJECT_SOURCE_DIR}/Ark-Cpp/api/multisignaturable/multisignature_gettable.cpp
	${PROJECT_SOURCE_DIR}/Ark-Cpp/api/peerable/peer_gettable.cpp
	${PROJECT_SOURCE_DIR}/Ark-Cpp/api/peerable/peer_respondable.cpp
	${PROJECT_SOURCE_DIR}/Ark-Cpp/api/signaturable/signature_gettable.cpp
	${PROJECT_SOURCE_DIR}/Ark-Cpp/api/transactionable/transaction_gettable.cpp
	${PROJECT_SOURCE_DIR}/Ark-Cpp/api/transactionable/transaction_respondable.cpp
	${PROJECT_SOURCE_DIR}/Ark-Cpp/api/manager.cpp
	${PROJECT_SOURCE_DIR}/Ark-Cpp/constants/networks.cpp
	${PROJECT_SOURCE_DIR}/Ark-Cpp/models/account.cpp
	${PROJECT_SOURCE_DIR}/Ark-Cpp/models/block.cpp
	${PROJECT_SOURCE_DIR}/Ark-Cpp/models/currency.cpp
	${PROJECT_SOURCE_DIR}/Ark-Cpp/models/delegate.cpp
	${PROJECT_SOURCE_DIR}/Ark-Cpp/models/fees.cpp
	${PROJECT_SOURCE_DIR}/Ark-Cpp/models/network.cpp
	${PROJECT_SOURCE_DIR}/Ark-Cpp/models/peer.cpp
	${PROJECT_SOURCE_DIR}/Ark-Cpp/models/transaction.cpp
	${PROJECT_SOURCE_DIR}/Ark-Cpp/models/voter.cpp
	${PROJECT_SOURCE_DIR}/Ark-Cpp/utilities/connector.cpp
)

set(PLATFORM_SRC 
	${PROJECT_SOURCE_DIR}/Ark-Cpp/platform/json.cpp
	${PROJECT_SOURCE_DIR}/Ark-Cpp/platform/http.cpp
)

add_library(Ark-Cpp-lib STATIC ${COMMON_SRC} ${PLATFORM_SRC})

target_link_libraries(Ark-Cpp-lib PUBLIC nlohmann_json)
target_link_libraries(Ark-Cpp-lib PUBLIC Poco::Net)

