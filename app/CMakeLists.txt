cmake_minimum_required(VERSION 3.12)
project(hello-cmake-app)
message("")
message("========== START: ${PROJECT_NAME} ==========")

set(PROJECT_SOURCE_FILES 
    ./main.cpp
)

message(STATUS "CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}")
message(STATUS "PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")
message(STATUS "PROJECT_BINARY_DIR = ${PROJECT_BINARY_DIR}")
message(STATUS "EXECUTABLE_OUTPUT_PATH = ${EXECUTABLE_OUTPUT_PATH}")
message(STATUS "LIBRARY_OUTPUT_PATH = ${LIBRARY_OUTPUT_PATH}")
message(STATUS "PROJECT_SOURCE_FILES = ${PROJECT_SOURCE_FILES}")

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_FILES})

message("========== END: ${PROJECT_NAME} ==========")
message("")