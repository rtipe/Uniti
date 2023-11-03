cmake_minimum_required(VERSION 3.22)
project(Uniti)

set(CMAKE_CXX_STANDARD 20)

SET(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install)
set(CMAKE_INSTALL_LOCAL_ONLY ON)

option(VERSION_GAME_ENGINE "version of the game engine" "v0.0.0")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
include(GNUInstallDirs)

find_package(Threads REQUIRED)

add_library(Uniti STATIC)

add_subdirectory(libs)

target_link_libraries(Uniti PUBLIC Threads::Threads)
target_link_libraries(Uniti PUBLIC ${CMAKE_DL_LIBS})

add_subdirectory(src)

install(DIRECTORY src/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        COMPONENT devel
        FILES_MATCHING PATTERN "*.hpp" PATTERN "*.inl")

add_subdirectory(Plugins)

add_subdirectory(example)

install(DIRECTORY "${CMAKE_BINARY_DIR}/bin" DESTINATION ${CMAKE_INSTALL_BINDIR})

include(InstallRequiredSystemLibraries)

if (PACK)
    set(INSTALL_DIR bin)
    set(LIB_DIR bin/lib)
    set(EXT_DIR /bin/ext)
else (PACK)
    set(INSTALL_DIR ${PROJECT_BINARY_DIR}/bin)
    set(LIB_DIR ${PROJECT_BINARY_DIR}/bin/lib)
    set(EXT_DIR ${PROJECT_BINARY_DIR}/bin/ext)
endif (PACK)

set(CPACK_CMAKE_GENERATOR Ninja)
set(CPACK_PACKAGE_NAME "connect4")
set(CPACK_PACKAGE_VERSION ${VERSION_GAME_ENGINE})
set(CPACK_PACKAGE_DESCRIPTION "connect4 game !")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "connect4")

set(CPACK_PACKAGE_CONTACT "younes1.bahri@epitech.eu")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "${CPACK_PACKAGE_CONTACT}")
set(CPACK_SOURCE_INSTALLED_DIRECTORIES "${CMAKE_BINARY_DIR}/bin;/")

if (WIN32)
    set(CPACK_GENERATOR "NSIS")
elseif (APPLE)
    set(CPACK_GENERATOR "DragNDrop")
else ()
    set(CPACK_GENERATOR "DEB;RPM")
endif ()

set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY FALSE)

include(CPack)
