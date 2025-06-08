# Add executable
add_executable(test_coordinates
  "test_coordinates.c"
  "${PROJECT_SOURCE_DIR}/unity/unity.c"
)

# Include headers for both Unity and project
target_include_directories(test_coordinates PRIVATE
  "${PROJECT_SOURCE_DIR}/include"
  "${PROJECT_SOURCE_DIR}/unity"
)

# Link the project library
target_link_libraries(test_coordinates PRIVATE meeus)

# Register the test with CTest
add_test(NAME test_coordinates COMMAND test_coordinates)