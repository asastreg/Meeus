# Add executable
add_executable(meeus "main.c" "coordinates.c" "time.c")

# # Add library
# add_library(meeus STATIC "coordinates.c" "time.c")
# target_include_directories(meeus PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
