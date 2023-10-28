cmake_minimum_required(VERSION 3.22)


add_library(Render STATIC)
target_link_libraries(Render PUBLIC Uniti)
set_target_properties(Render PROPERTIES
        CXX_STANDARD 20
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)

add_subdirectory(Includes)
add_subdirectory(SFML)

add_library(RenderPlugin SHARED EntryPointRender.cpp)
target_link_libraries(RenderPlugin PUBLIC Render)
set_target_properties(RenderPlugin PROPERTIES
        CXX_STANDARD 20
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)

add_library(PrintablePlugin SHARED EntryPointPrintable.cpp)
target_link_libraries(PrintablePlugin PUBLIC Render)
set_target_properties(PrintablePlugin PROPERTIES
        CXX_STANDARD 20
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)