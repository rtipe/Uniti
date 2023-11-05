cmake_minimum_required(VERSION 3.22)

add_library(Button SHARED Button.cpp)
set_target_properties(Button PROPERTIES PREFIX "")
target_link_libraries(Button PUBLIC Uniti)
target_link_libraries(Button PUBLIC Render)

target_include_directories(Button PUBLIC ".")

add_custom_command(
        TARGET Button
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:Button>
        ${CMAKE_BINARY_DIR}/bin/ObjectPlugin/$<TARGET_FILE_NAME:Button>
)