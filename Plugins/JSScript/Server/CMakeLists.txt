cmake_minimum_required(VERSION 3.22)

add_library(JSScript STATIC)
target_link_libraries(JSScript PUBLIC Uniti)

set(BUILD_SHARED_LIBS ON)

FetchContent_Declare(socketio
        GIT_REPOSITORY https://github.com/socketio/socket.io-client-cpp.git
        GIT_TAG 3.1.0
)
FetchContent_MakeAvailable(socketio)

include_directories(${socketio_SOURCE_DIR}/src)
include_directories(${socketio_BINARY_DIR})

target_link_libraries(JSScript PUBLIC sioclient)

if (WIN32)
    set(NODE_ARCHIVE_FILENAME "node-v21.1.0-win-x64")
    set(NODE_EXTENSION ".zip")
    set(URL_NODE https://nodejs.org/dist/latest/node-v21.1.0-win-x64.zip)
elseif (APPLE)
    set(NODE_ARCHIVE_FILENAME "node-v21.1.0-darwin-x64")
    set(NODE_EXTENSION ".tar.gz")
    set(URL_NODE https://nodejs.org/dist/latest/node-v21.1.0-darwin-x64.tar.gz)
else ()
    set(NODE_ARCHIVE_FILENAME "node-v21.1.0-linux-x64")
    set(NODE_EXTENSION ".tar.gz")
    set(URL_NODE https://nodejs.org/dist/latest/node-v21.1.0-linux-x64.tar.gz)
endif ()

FetchContent_Declare(nodeJS
        URL ${URL_NODE}
        DOWNLOAD_EXTRACT_TIMESTAMP true
)
FetchContent_Populate(nodeJS)

message(${nodejs_SOURCE_DIR})
add_custom_command(
        TARGET JSScript
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${nodejs_SOURCE_DIR}
        ${CMAKE_BINARY_DIR}/bin/node
)

target_sources(JSScript PUBLIC
        JavascriptPlugin.cpp
        JSScriptPlugin.cpp
        JSEvent.cpp
        JSListener.cpp
)

target_include_directories(JSScript PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

add_library(JSScriptPlugin SHARED EntryPointJSScript.cpp)
target_link_libraries(JSScriptPlugin PUBLIC JSScript)
add_custom_command(
        TARGET JSScriptPlugin
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:JSScriptPlugin>
        ${CMAKE_BINARY_DIR}/bin/CorePlugin/$<TARGET_FILE_NAME:JSScriptPlugin>
)

add_library(JSListener SHARED EntryPointJSListener.cpp)
target_link_libraries(JSListener PUBLIC JSScript)
add_custom_command(
        TARGET JSListener
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:JSListener>
        ${CMAKE_BINARY_DIR}/bin/ObjectPlugin/$<TARGET_FILE_NAME:JSListener>
)