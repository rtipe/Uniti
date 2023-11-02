cmake_minimum_required(VERSION 3.22)


add_library(Render STATIC)
target_link_libraries(Render PUBLIC Uniti)

add_subdirectory(Includes)
add_subdirectory(SFML)

if (WIN32)
    target_link_libraries(Render PUBLIC sfml-graphics sfml-window sfml-system sfml-audio sfml-main)
else ()
    target_link_libraries(Render PUBLIC sfml-graphics sfml-window sfml-system sfml-audio)
endif ()

add_library(RenderPlugin SHARED EntryPointRender.cpp)
target_link_libraries(RenderPlugin PUBLIC Render)
add_custom_command(
        TARGET RenderPlugin
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:RenderPlugin>
        ${CMAKE_BINARY_DIR}/bin/CorePlugin/$<TARGET_FILE_NAME:RenderPlugin>
)
add_library(PrintablePlugin SHARED EntryPointPrintable.cpp)
target_link_libraries(PrintablePlugin PUBLIC Render)
add_custom_command(
        TARGET PrintablePlugin
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:PrintablePlugin>
        ${CMAKE_BINARY_DIR}/bin/ObjectPlugin/$<TARGET_FILE_NAME:PrintablePlugin>
)