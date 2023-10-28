cmake_minimum_required(VERSION 3.22)

FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

target_link_libraries(Render PUBLIC sfml-graphics sfml-window sfml-system sfml-audio)

target_sources(Render PUBLIC
        RenderPlugin.cpp
        Window.cpp)

target_include_directories(Render PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(Event)
add_subdirectory(Printable)
add_subdirectory(Sound)