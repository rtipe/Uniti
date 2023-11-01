cmake_minimum_required(VERSION 3.22)

add_library(Button SHARED Button.cpp)
target_link_libraries(Button PUBLIC Uniti)
target_link_libraries(Button PUBLIC Render)

target_include_directories(Button PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

set_target_properties(Button PROPERTIES
        CXX_STANDARD 20
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)