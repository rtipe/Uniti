cmake_minimum_required(VERSION 3.22)
project(Uniti)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

message(STATUS "Fetching JSONCPP")

option(BUILD_STATIC_LIBS "Build jsoncpp_lib as a static library." OFF)
option(BUILD_OBJECT_LIBS "Build jsoncpp_lib as a object library." OFF)

FetchContent_Declare(JSONCpp
        GIT_REPOSITORY https://github.com/open-source-parsers/jsoncpp.git
        GIT_TAG 1.9.5)
FetchContent_MakeAvailable(JSONCpp)

FetchContent_Declare(
        Boost
        URL "https://github.com/boostorg/boost/releases/download/boost-1.83.0/boost-1.83.0.tar.xz"
        DOWNLOAD_EXTRACT_TIMESTAMP ON
)

set(BOOST_RUNTIME_LINK static)
set(BOOST_INCLUDE_LIBRARIES
        asio
        assert
        align
        array
        bind
        coroutine
        config
        context
        core
        chrono
        date_time
        exception
        function
        move
        system
        smart_ptr
        throw_exception
        type_traits
        lockfree
        utility
)
FetchContent_MakeAvailable(Boost)

find_package(Threads REQUIRED)

add_library(Uniti STATIC)

foreach(lib ${BOOST_INCLUDE_LIBRARIES})
    target_link_libraries(
            Uniti
            PUBLIC
            Boost::${lib}
    )
endforeach()

target_link_libraries(Uniti PUBLIC Threads::Threads)
target_link_libraries(Uniti PUBLIC jsoncpp_lib)
target_link_libraries(Uniti PUBLIC ${CMAKE_DL_LIBS})

add_subdirectory(src)

install(DIRECTORY src/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        COMPONENT devel
        FILES_MATCHING PATTERN "*.hpp" PATTERN "*.inl")

add_subdirectory(Render)
add_subdirectory(Network)
add_subdirectory(Physics)

add_executable(test
        index.cpp)
set_target_properties(test PROPERTIES
        CXX_STANDARD 20
        LINK_FLAGS "-rdynamic"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)
target_link_libraries(test PUBLIC Threads::Threads)
target_link_libraries(test PUBLIC jsoncpp_lib)
target_link_libraries(test PUBLIC ${CMAKE_DL_LIBS})
target_link_libraries(test PUBLIC Uniti)

include(CPack)
