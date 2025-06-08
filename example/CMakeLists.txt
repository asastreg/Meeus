add_executable(example_meeus main.c)

target_include_directories(example_meeus PRIVATE "${PROJECT_SOURCE_DIR}/include")

target_link_libraries(example_meeus PRIVATE meeus)
