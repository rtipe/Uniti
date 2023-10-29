cmake_minimum_required(VERSION 3.22)

add_library(Physics STATIC)
target_link_libraries(Physics PUBLIC Uniti)

set_target_properties(Physics PROPERTIES
        CXX_STANDARD 20
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_sources(Physics PUBLIC
        Collision.cpp
        Movement.cpp
        PhysicsPlugin.cpp
)

target_include_directories(Physics PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

add_library(PhysicsPlugin SHARED EntryPoint.cpp)
target_link_libraries(PhysicsPlugin PUBLIC Physics)
set_target_properties(PhysicsPlugin PROPERTIES
        CXX_STANDARD 20
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)