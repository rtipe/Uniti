cmake_minimum_required(VERSION 3.22)

FetchContent_Declare(zlib
        GIT_REPOSITORY https://github.com/madler/zlib.git
        GIT_TAG v1.3)
FetchContent_MakeAvailable(zlib)

add_library(Network STATIC)
target_link_libraries(Network PUBLIC Uniti)
target_link_libraries(Network PUBLIC zlibstatic)

include_directories(${zlib_SOURCE_DIR})
include_directories(${zlib_BINARY_DIR})

set_target_properties(Network PROPERTIES
        CXX_STANDARD 20
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_sources(Network PUBLIC
        Network.cpp
        Server.cpp
        NetworkPlugin.cpp
)

target_include_directories(Network PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

add_library(NetworkPlugin SHARED EntryPoint.cpp)
target_link_libraries(NetworkPlugin PUBLIC Network)
set_target_properties(NetworkPlugin PROPERTIES
        CXX_STANDARD 20
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)