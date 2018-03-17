cmake_minimum_required(VERSION 3.6.2)

project(Ark-Cpp-tests)

if (ARDUINO)
else()
	hunter_add_package(GTest)
	find_package(GTest CONFIG REQUIRED)

	include(CTest)
endif()

set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../lib")

set(COVERAGE OFF CACHE BOOL "Coverage")

include_directories(${PROJECT_SOURCE_DIR}/../src/Ark-Cpp)
include_directories(${PROJECT_SOURCE_DIR}/../src/Ark-Cpp/api)
include_directories(${PROJECT_SOURCE_DIR}/../src/Ark-Cpp/api/accountable)
include_directories(${PROJECT_SOURCE_DIR}/../src/Ark-Cpp/api/blockable)
include_directories(${PROJECT_SOURCE_DIR}/../src/Ark-Cpp/api/delegatable)
include_directories(${PROJECT_SOURCE_DIR}/../src/Ark-Cpp/api/loadable)
include_directories(${PROJECT_SOURCE_DIR}/../src/Ark-Cpp/api/multisignaturable)
include_directories(${PROJECT_SOURCE_DIR}/../src/Ark-Cpp/api/peerable)
include_directories(${PROJECT_SOURCE_DIR}/../src/Ark-Cpp/api/signaturable)
include_directories(${PROJECT_SOURCE_DIR}/../src/Ark-Cpp/api/transactionable)
include_directories(${PROJECT_SOURCE_DIR}/../src/Ark-Cpp/constants)
include_directories(${PROJECT_SOURCE_DIR}/../src/Ark-Cpp/helpers)
include_directories(${PROJECT_SOURCE_DIR}/../src/Ark-Cpp/models)
include_directories(${PROJECT_SOURCE_DIR}/../src/Ark-Cpp/types)
include_directories(${PROJECT_SOURCE_DIR}/../src/Ark-Cpp/utilities)

include_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

if (ARDUINO)
	include_directories(${PROJECT_SOURCE_DIR}/../include)
	include_directories(${PROJECT_SOURCE_DIR}/../include/arduinounit)
	include_directories(${PROJECT_SOURCE_DIR}/arduino)
	include_directories(${PROJECT_SOURCE_DIR}/../src/Ark-Cpp/arduino/stl)
	include_directories(${ARDUINO_SDK_PATH}/hardware/arduino/avr/libraries/SPI/src)
	include_directories(${ARDUINO_SDK_PATH}/libraries/Ethernet/src)
endif()


set (TEST_SRC
	${PROJECT_SOURCE_DIR}/api/account.cpp
	${PROJECT_SOURCE_DIR}/api/block.cpp
	${PROJECT_SOURCE_DIR}/api/delegate.cpp
	${PROJECT_SOURCE_DIR}/api/loader.cpp
	${PROJECT_SOURCE_DIR}/api/peer.cpp
	${PROJECT_SOURCE_DIR}/api/signature.cpp
	${PROJECT_SOURCE_DIR}/api/transaction.cpp	
	${PROJECT_SOURCE_DIR}/model/account.cpp
	${PROJECT_SOURCE_DIR}/model/block.cpp
	${PROJECT_SOURCE_DIR}/model/currency.cpp
	${PROJECT_SOURCE_DIR}/model/delegate.cpp
	${PROJECT_SOURCE_DIR}/model/fees.cpp
	${PROJECT_SOURCE_DIR}/model/network.cpp
	${PROJECT_SOURCE_DIR}/model/peer.cpp
	${PROJECT_SOURCE_DIR}/model/transaction.cpp
	${PROJECT_SOURCE_DIR}/model/voter.cpp
	${PROJECT_SOURCE_DIR}/types/address.cpp
	${PROJECT_SOURCE_DIR}/types/balance.cpp
	${PROJECT_SOURCE_DIR}/types/hash.cpp
	${PROJECT_SOURCE_DIR}/types/publickey.cpp
	${PROJECT_SOURCE_DIR}/types/signature.cpp
)

find_library(Ark-Cpp-tests NAMES Ark-Cpp-lib PATHS ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

if (ARDUINO)
	set(PLATFORM_SRC
		 "${PROJECT_SOURCE_DIR}/../include/arduinounit/ArduinoUnitUtility/ArduinoUnit.cpp"
		 "${ARDUINO_SDK_PATH}/libraries/Ethernet/src/EthernetClient.cpp"
		 "${ARDUINO_SDK_PATH}/libraries/Ethernet/src/Ethernet.cpp"
		 "${PROJECT_SOURCE_DIR}/arduino/tests.cpp"
	)

	link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libraries)

	generate_arduino_firmware(Ark-Cpp-tests
		SRCS ${PLATFORM_SRC}
		LIBS Ark-Cpp-lib
		BOARD ${BOARD_ID}
	)
else()
	add_executable(Ark-Cpp-tests ${TEST_SRC})

	target_link_libraries(Ark-Cpp-tests Ark-Cpp-lib)

	target_link_libraries(Ark-Cpp-tests GTest::main) # GTest::gtest will be linked automatically
	target_link_libraries(Ark-Cpp-tests GTest::gtest)

	if (COVERAGE)
		target_compile_options(tests PRIVATE --coverage)
		target_link_libraries(tests PRIVATE --coverage)
	endif()

	add_test(NAME test COMMAND Ark-Cpp-tests)
endif()
