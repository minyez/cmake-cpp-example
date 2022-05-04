add_executable(test_mymath test_mymath.cpp)

target_include_directories(test_mymath
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR})
if (BUILD_LIBRARY)
  target_link_libraries(test_mymath cmake_cpp_example_lib)
else()
  target_sources(test_mymath PRIVATE ../src/mymath.cpp)
  target_link_libraries(test_mymath ${LAPACK_LIBRARIES})
endif()

add_test(
  NAME test_mymath
  COMMAND $<TARGET_FILE:test_mymath>
  )
