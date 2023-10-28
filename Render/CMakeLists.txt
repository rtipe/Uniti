cmake_minimum_required(VERSION 3.22)


add_library(Render STATIC)
target_link_libraries(Render PUBLIC Uniti)
set_target_properties(Render PROPERTIES
        CXX_STANDARD 20
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)

add_subdirectory(Includes)
add_subdirectory(SFML)