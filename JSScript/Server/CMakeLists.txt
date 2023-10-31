cmake_minimum_required(VERSION 3.22)

set(BUILD_SHARED_LIBS OFF)

FetchContent_Declare(socketio
        GIT_REPOSITORY https://github.com/socketio/socket.io-client-cpp.git
        GIT_TAG 3.1.0
)
FetchContent_MakeAvailable(socketio)

include_directories(${socketio_SOURCE_DIR}/src)
include_directories(${socketio_BINARY_DIR})

add_library(JSScript STATIC)
target_link_libraries(JSScript PUBLIC Uniti)
target_link_libraries(JSScript PUBLIC sioclient)

target_sources(JSScript PUBLIC
        JavascriptPlugin.cpp
        JSScriptPlugin.cpp
        JSEvent.cpp
        JSListener.cpp
)

target_include_directories(JSScript PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

add_library(JSScriptPlugin SHARED EntryPointJSScript.cpp)
target_link_libraries(JSScriptPlugin PUBLIC JSScript)
set_target_properties(JSScriptPlugin PROPERTIES
        CXX_STANDARD 20
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)

add_library(JSListener SHARED EntryPointJSListener.cpp)
target_link_libraries(JSListener PUBLIC JSScript)
set_target_properties(JSListener PROPERTIES
        CXX_STANDARD 20
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)
