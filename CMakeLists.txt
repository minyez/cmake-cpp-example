cmake_minimum_required(VERSION 3.1)

# Get the version from the source code file
file(READ src/constants.cpp _version_stamp)

# Generate the version string,
# First match the string from the beginning,
string(REGEX MATCH " *const string _version = \"[a-zA-Z0-9.-_]+" _version ${_version_stamp})
# Then replace the head part with the empty string
string(REGEX REPLACE " *const string _version = \"" "" _version ${_version})

project(cmake_cpp_example VERSION ${_version} LANGUAGES NONE)

# Configure the C++ compiler and the flags.
# NOTE: the C++ cmake module is named with CXX instead of CPP, otherwise will lead to error cannot find cmake module.
# NOTE: the include directories are not configured here
set(CMAKE_CXX_COMPILER "icpc" CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS "-O2 -ip -fp-model precise -std=c++11" CACHE STRING "" FORCE)
# Custom varaible to contorl whether the library should be built
set(BUILD_LIBRARY ON)
# Control whether the library will be built as a static or shared (dynamic) library
set(BUILD_SHARED_LIBS ON)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# WARN: trigger language after the CXX objects are configured.
enable_language(CXX)

# # Optional: disable in-source build
# if (PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
#     message(FATAL_ERROR "Your are building project in the source directory: \
# ${PROJECT_SOURCE_DIR}. In-source builds are not allowed.")
# endif()

# Some helpful message. STATUS flag to add -- before the main text
message(STATUS "Project name: ${PROJECT_NAME}, version ${PROJECT_VERSION}")
message(STATUS "C++ compiler flags: ${CMAKE_CXX_FLAGS}")

# Include the source code directory. You must have CMakeLists.txt in each subdirectory
add_subdirectory(src)
