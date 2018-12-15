cmake_minimum_required(VERSION 3.12)
project(artifacted)
message("")
message("========== START: ${PROJECT_NAME} ==========")

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_VERBOSE_MAKEFILE ON)

# evironment
if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	message(STATUS "Mac OS")
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	message(STATUS "Linux")
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	message(STATUS "Windows")
endif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
# prevent in-sorce build
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "In-source builds are not allowed. 
    You should create a separate directory for build files.
")
endif()

if(${CMAKE_BUILD_TYPE} MATCHES Debug)
    message(STATUS "Debug Build")
elseif(${CMAKE_BUILD_TYPE} MATCHES Release)
    message(STATUS "Release Build")
endif()

# DIR config
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/installed)

message(STATUS "PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")
message(STATUS "PROJECT_BINARY_DIR = ${PROJECT_BINARY_DIR}")
message(STATUS "CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_INCLUDE_PATH = ${CMAKE_INCLUDE_PATH}")
message(STATUS "CMAKE_MODULE_PATH = ${CMAKE_MODULE_PATH}")
message(STATUS "CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}")
message(STATUS "CMAKE_RUNTIME_OUTPUT_DIRECTORY = ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message(STATUS "CMAKE_LIBRARY_OUTPUT_DIRECTORY = ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
message(STATUS "CMAKE_ARCHIVE_OUTPUT_DIRECTORY = ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
message(STATUS "CMAKE_INSTALL_PREFIX = ${CMAKE_INSTALL_PREFIX}")

# package
find_package(Boost REQUIRED)
if(Boost_FOUND)
    message(STATUS "PACKAGE_FOUND = Boost")
else()
    error("PACKAGE_NOT_FOUND = Boost")
endif()

# sub project
add_subdirectory(engine)
add_subdirectory(app)

message("========== END: ${PROJECT_NAME} ==========")
message("")