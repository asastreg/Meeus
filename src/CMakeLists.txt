# Create a static library from source files
add_library(meeus STATIC "coordinates.c" "time.c" "utils.c")

# Include headers
target_include_directories(meeus PUBLIC "${PROJECT_SOURCE_DIR}/include")
