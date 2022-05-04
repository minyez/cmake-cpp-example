cmake_minimum_required(VERSION 3.4)

# Get the version from the source code file
file(READ src/constants.cpp _version_stamp)

# Generate the version string,
# First match the string from the beginning,
string(REGEX MATCH ".*_version = \"[a-zA-Z0-9.-_]+" _version ${_version_stamp})
# Then replace the head part with the empty string
string(REGEX REPLACE ".*_version = \"" "" _version ${_version})

project(cmake_cpp_example VERSION ${_version} LANGUAGES NONE)

# Configure the C++ compiler and the flags.
# NOTE: the C++ cmake module is named with CXX instead of CPP, otherwise will lead to error cannot find cmake module.
# NOTE: the include directories are not configured here
# # Intel C++
# set(CMAKE_CXX_COMPILER "icpc" CACHE STRING "" FORCE)
# GNU C++
set(CMAKE_CXX_COMPILER "g++" CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS "-g -O2" CACHE STRING "" FORCE)
# Custom varaible to contorl whether the library should be built
set(BUILD_LIBRARY ON)
# Control whether the library will be built as a static or shared (dynamic) library
set(BUILD_SHARED_LIBS OFF)

# Set the BLAS/LAPACK directories.
# Method 1: manually
set(LAPACK_DIR "$ENV{HOME}/local/programs/lapack-3.9.1")
set(LIBS "-llapack -lblas")

# WARN: trigger language after the CXX objects are configured.
enable_language(CXX)

# NOTE: should be after enable_language
if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
  string(APPEND LIBS " -lgfortran")
endif()
set(LAPACK_LIBRARIES "-L${LAPACK_DIR} ${LIBS}")

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# # Optional: disable in-source build
# if (PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
#     message(FATAL_ERROR "Your are building project in the source directory: \
# ${PROJECT_SOURCE_DIR}. In-source builds are not allowed.")
# endif()

# Some helpful message. STATUS flag to add -- before the main text
message(STATUS "Project name: ${PROJECT_NAME}, version ${PROJECT_VERSION}")
message(STATUS "C++ compiler ID: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "C++ compiler flags: ${CMAKE_CXX_FLAGS}")
message(STATUS "LAPACK linking flags: ${LAPACK_LIBRARIES}")

# Include the source code directory. You must have CMakeLists.txt in each subdirectory
add_subdirectory(src)

# Add testings
enable_testing()
add_subdirectory(tests)
