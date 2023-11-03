cmake_minimum_required(VERSION 3.22)

add_library(Network STATIC)
target_link_libraries(Network PUBLIC Uniti)

FetchContent_Declare(zlib
        GIT_REPOSITORY https://github.com/madler/zlib.git
        GIT_TAG v1.3
        CMAKE_ARGS
        "-DCMAKE_INSTALL_PREFIX=${ZLIB_INSTALL_DIR} -DCMAKE_C_FLAGS=-fPIC -DCMAKE_POSITION_INDEPENDENT_CODE=ON"
)
FetchContent_MakeAvailable(zlib)

target_link_libraries(Network PUBLIC zlibstatic)

include_directories(${zlib_SOURCE_DIR})
include_directories(${zlib_BINARY_DIR})

target_sources(Network PUBLIC
        Network.cpp
        Server.cpp
        NetworkPlugin.cpp
)

target_include_directories(Network PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

add_library(NetworkPlugin SHARED EntryPoint.cpp)
target_link_libraries(NetworkPlugin PUBLIC Network)
add_custom_command(
        TARGET NetworkPlugin
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:NetworkPlugin>
        ${CMAKE_BINARY_DIR}/bin/CorePlugin/$<TARGET_FILE_NAME:NetworkPlugin>
)