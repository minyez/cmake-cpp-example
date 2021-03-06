# Specify the executable target
add_executable(cmake_cpp_example_exe main.cpp)
# The default name of the executable will be exactly the variable name
# To change the varaiable, we use `set_target_properties`
set_target_properties(cmake_cpp_example_exe PROPERTIES
  OUTPUT_NAME "cmake_cpp_example.exe")

# Now specify where the executable will be generated.
# By default, if the compilation succeeds, you will have the executable at the "src" subdirectory in the build directory
# To put it in the build root directory
set_target_properties(cmake_cpp_example_exe
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
  LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
  RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

# one source file envs.cpp is generated by replacing the cmake variables inside envs.cpp.in
configure_file(envs.cpp.in envs.cpp)
# the source files to use
list(APPEND _sources
            constants.cpp
            mymath.cpp
            ${CMAKE_CURRENT_BINARY_DIR}/envs.cpp)
# set include directories, required when external C/C++ codes are used in the project
# target_include_directories(cmake_cpp_example_exe
#   PUBLIC
#     ${CMAKE_CURRENT_LIST_DIR}
#   )

# Conditionally build the library
if (BUILD_LIBRARY)
# Specify the library target
# We assume that the main library does not contain the main function.
# The sources will be added later.
  add_library(cmake_cpp_example_lib)
# Link to BLAS and LAPACK libraries
  target_link_libraries(cmake_cpp_example_lib ${LAPACK_LIBRARIES})
# Also put the generated lib under the build root.
  set_target_properties(cmake_cpp_example_lib
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
    LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

  # Not surprisingly, the executable should be built upon the library
  # so we link the executable to the library.
  # CMake will handle the building order for us.
  target_link_libraries(cmake_cpp_example_exe PRIVATE cmake_cpp_example_lib)
  target_sources(cmake_cpp_example_lib PRIVATE ${_sources})
  target_include_directories(cmake_cpp_example_lib
    PUBLIC
      ${CMAKE_CURRENT_LIST_DIR}
    )
else()
  # if the library will not be built, then all sources should be added to the executable target
  target_sources(cmake_cpp_example_exe PRIVATE ${_sources})
  # And link to BLAS/LAPACK
  target_link_libraries(cmake_cpp_example_exe ${LAPACK_LIBRARIES})
endif()
