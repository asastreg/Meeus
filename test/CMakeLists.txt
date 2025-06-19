# Function to define a Unity test target
function(add_unity_test test_name)

  add_executable(${test_name}
    ${test_name}.c
    ${PROJECT_SOURCE_DIR}/unity/unity.c
  )

  target_include_directories(${test_name} PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/unity
  )

  target_compile_definitions(${test_name} PRIVATE UNITY_INCLUDE_DOUBLE UNITY_OUTPUT_COLOR)

  target_link_libraries(${test_name} PRIVATE meeus)

  add_test(NAME ${test_name} COMMAND ${test_name})
endfunction()

# Add your test targets here
add_unity_test(test_coordinates)
add_unity_test(test_time)
