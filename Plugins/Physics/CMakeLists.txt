cmake_minimum_required(VERSION 3.22)

add_library(Physics STATIC)
target_link_libraries(Physics PUBLIC Uniti)

target_sources(Physics PUBLIC
        Collision.cpp
        Movement.cpp
        PhysicsPlugin.cpp
)

target_include_directories(Physics PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

add_library(PhysicsPlugin SHARED EntryPoint.cpp)
set_target_properties(PhysicsPlugin PROPERTIES PREFIX "")
target_link_libraries(PhysicsPlugin PUBLIC Physics)
add_custom_command(
        TARGET PhysicsPlugin
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:PhysicsPlugin>
        ${CMAKE_BINARY_DIR}/bin/ObjectPlugin/$<TARGET_FILE_NAME:PhysicsPlugin>
)