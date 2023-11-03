cmake_minimum_required(VERSION 3.22)

message(STATUS "Fetching JSONCPP")

set(BUILD_STATIC_LIBS OFF)
set(BUILD_OBJECT_LIBS OFF)

FetchContent_Declare(JSONCpp
        GIT_REPOSITORY https://github.com/open-source-parsers/jsoncpp.git
        GIT_TAG 1.9.5)
FetchContent_MakeAvailable(JSONCpp)

target_link_libraries(Uniti PUBLIC jsoncpp_lib)