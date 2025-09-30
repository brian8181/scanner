
# @file:    CMakeLists.txt
# @date:    Mon, Sep 29, 2025 10:54:01 PM
# @version: 0.1.0

cmake_minimum_required(VERSION 3.2)
project(scanner)

set(CMAKE_CXX_STANDARD 20)

#set(BUILD_SHARED_LIBS YES)

if(CMAKE_SYSTEM_NAME STREQUAL "CYGWIN")
    message(STATUS "Building under Cygwin, defining CYGWIN macro")
    add_definitions(-DCYGWIN)
endif()

add_executable(scanner
    src/scanner.cpp
    src/Lexer.cpp
    src/utility.cpp
    src/fileio.cpp
)


add_library(lexer_a STATIC
    src/Lexer.cpp
    src/utility.cpp
    src/fileio.cpp
)

#[=[
    # Add Library
    add_library(targetName [STATIC | SHARED | MODULE]
    [EXCLUDE_FROM_ALL]
    source1 [source2 ...]
)
]=]

#[=[
install(TARGETS MyApp AlgoRuntime AlgoSDK
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)
]=]
