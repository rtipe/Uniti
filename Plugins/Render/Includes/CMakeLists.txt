cmake_minimum_required(VERSION 3.22)

target_include_directories(Render PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(Render PUBLIC
        IRenderPlugin.hpp
        IWindow.hpp)

add_subdirectory(Event)
add_subdirectory(Printable)
add_subdirectory(Sound)