cmake_minimum_required(VERSION 3.22)

add_library(TextInput SHARED TextInput.cpp)
target_link_libraries(TextInput PUBLIC Uniti)
target_link_libraries(TextInput PUBLIC Render)

target_include_directories(TextInput PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

set_target_properties(TextInput PROPERTIES
        CXX_STANDARD 20
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)