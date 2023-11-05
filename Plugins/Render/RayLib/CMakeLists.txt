cmake_minimum_required(VERSION 3.22)

add_subdirectory(RayLib)

target_link_libraries(Render PUBLIC raylib)

target_sources(Render PUBLIC
        RenderPlugin.cpp
        Window.cpp)

target_include_directories(Render PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(Event)
add_subdirectory(Printable)
add_subdirectory(Sound)