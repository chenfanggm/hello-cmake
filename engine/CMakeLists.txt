cmake_minimum_required(VERSION 3.12)
project(vscpp-engine)
message("")
message("========== START: ${PROJECT_NAME} ==========")

# c++ config
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++17 -stdlib=libc++")

message(STATUS "CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}")
message(STATUS "PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")
message(STATUS "PROJECT_BINARY_DIR = ${PROJECT_BINARY_DIR}")
message(STATUS "CMAKE_INCLUDE_PATH = ${CMAKE_INCLUDE_PATH}")
message(STATUS "CMAKE_RUNTIME_OUTPUT_DIRECTORY = ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message(STATUS "CMAKE_LIBRARY_OUTPUT_DIRECTORY = ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
message(STATUS "CMAKE_ARCHIVE_OUTPUT_DIRECTORY = ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
message(STATUS "CMAKE_CXX_COMPILER = ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_CXX_FLAGS = ${CMAKE_CXX_FLAGS}")

# package
find_package(spdlog REQUIRED)
if(spdlog_FOUND)
    message(STATUS "PACKAGE_FOUND = spdlog")
else()
    error("PACKAGE_NOT_FOUND = spdlog")
endif()

# source
set(PROJECT_HEADER_FILES
    src/Viper.h
    src/libs/Core.h
    src/libs/Log.h
    src/libs/Application.h
)
set(PROJECT_SOURCE_FILES 
    ${PROJECT_HEADER_FILES}
    src/libs/Log.cpp
    src/libs/Application.cpp
)
message(STATUS "PROJECT_SOURCE_FILES = ${PROJECT_SOURCE_FILES}")

add_library(${PROJECT_NAME} ${PROJECT_SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} 
    spdlog::spdlog
)

target_compile_definitions(${PROJECT_NAME} 
    PRIVATE 
        VIPER_PLATFORM_OSX
        VIPER_BUILD_DLL
)

message(STATUS "CMAKE_INSTALL_PREFIX = ${CMAKE_INSTALL_PREFIX}")
install(FILES ${PROJECT_HEADER_FILES} DESTINATION include)
install(TARGETS ${PROJECT_NAME} DESTINATION lib)

message("========== END: ${PROJECT_NAME} ==========")
message("")