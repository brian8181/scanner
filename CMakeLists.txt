# @file:    CMakeLists.txt
# @date:    Mon, Sep 29, 2025 10:54:01 PM
# @version: 0.1.0

cmake_minimum_required(VERSION 3.28.3)
project(scanner)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(CMAKE_SYSTEM_NAME STREQUAL "CYGWIN")
    message(STATUS "Building under Cygwin, defining CYGWIN macro")
    add_definitions(-DCYGWIN)
endif()

#add_subdirectory(/cygdrive/c/Users/brian/src/fmt-11.1.3/src)
 

add_library(lexer_a STATIC
    src/Lexer.cpp
    src/utility.cpp
    src/fileio.cpp
)

#target_link_libraries(scanner PRIVATE lexer_a)

add_executable(scanner
    src/scanner.cpp
    src/Lexer.cpp
    src/utility.cpp
    src/fileio.cpp
)

#target_link_libraries(scanner PRIVATE fmt::fmt)


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
