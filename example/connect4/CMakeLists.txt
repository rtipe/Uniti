cmake_minimum_required(VERSION 3.22)

add_executable(connect4 index.cpp)

target_link_libraries(connect4 PUBLIC Uniti)

add_custom_command(
        TARGET connect4
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/assets
        ${CMAKE_BINARY_DIR}/bin/assets
)
add_custom_command(
        TARGET connect4
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/javascript
        ${CMAKE_BINARY_DIR}/bin/javascript
)
add_custom_command(
        TARGET connect4
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/json
        ${CMAKE_BINARY_DIR}/bin/json
)