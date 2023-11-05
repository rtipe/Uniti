cmake_minimum_required(VERSION 3.22)

add_library(TextInput SHARED TextInput.cpp)
set_target_properties(TextInput PROPERTIES PREFIX "")
target_link_libraries(TextInput PUBLIC Uniti)
target_link_libraries(TextInput PUBLIC Render)
add_custom_command(
        TARGET TextInput
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:TextInput>
        ${CMAKE_BINARY_DIR}/bin/ObjectPlugin/$<TARGET_FILE_NAME:TextInput>
)


target_include_directories(TextInput PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")