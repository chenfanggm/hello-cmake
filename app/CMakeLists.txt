cmake_minimum_required(VERSION 3.12)
project(vscpp-app)
message("")
message("========== START: ${PROJECT_NAME} ==========")

# c++ config
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++17 -stdlib=libc++")

message(STATUS "PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")
message(STATUS "PROJECT_BINARY_DIR = ${PROJECT_BINARY_DIR}")
message(STATUS "CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}")
message(STATUS "CMAKE_INCLUDE_PATH = ${CMAKE_INCLUDE_PATH}")
message(STATUS "CMAKE_RUNTIME_OUTPUT_DIRECTORY = ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message(STATUS "CMAKE_LIBRARY_OUTPUT_DIRECTORY = ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
message(STATUS "CMAKE_ARCHIVE_OUTPUT_DIRECTORY = ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
message(STATUS "CMAKE_CXX_COMPILER = ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_CXX_FLAGS = ${CMAKE_CXX_FLAGS}")
message(STATUS "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}")

# source
set(PROJECT_SOURCE_FILES 
    src/main.cpp
)
message(STATUS "PROJECT_SOURCE_FILES = ${PROJECT_SOURCE_FILES}")

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_FILES})
add_dependencies(${PROJECT_NAME} vscpp-engine)
 
target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${Boost_INCLUDE_DIRS}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/engine/src
)
target_link_libraries(${PROJECT_NAME} 
    ${Boost_LIBRARIES}
    vscpp-engine
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
message(STATUS "CMAKE_INSTALL_PREFIX = ${CMAKE_INSTALL_PREFIX}")

message("========== END: ${PROJECT_NAME} ==========")
message("")

message("========== START: ${PROJECT_NAME} - TEST ==========")
message("========== END: ${PROJECT_NAME} - TEST ==========")
message("")
