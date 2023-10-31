cmake_minimum_required(VERSION 3.22)

set(NODEJS_VERSION "14.17.0")

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

file(COPY "${nodejs_SOURCE_DIR}" DESTINATION .)

install(DIRECTORY "${nodejs_SOURCE_DIR}" DESTINATION ${CMAKE_INSTALL_BINDIR})

add_subdirectory(Server)
