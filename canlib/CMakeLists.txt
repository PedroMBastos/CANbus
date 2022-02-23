cmake_minimum_required(VERSION 2.8)
project(canlib)

# Set all the global variables
set(CANLIB_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
Message(STATUS "The project root Path is ${CANLIB_SOURCE_DIR}")


# Set output folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CANLIB_SOURCE_DIR}/output/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CANLIB_SOURCE_DIR}/output/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CANLIB_SOURCE_DIR}/output/lib)

# Set subdirectories
add_subdirectory(drivers)
add_subdirectory(examples)
