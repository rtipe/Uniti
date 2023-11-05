cmake_minimum_required(VERSION 3.22)

FetchContent_Declare(
        raylib
        URL https://github.com/raysan5/raylib/archive/master.tar.gz
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
        DOWNLOAD_NO_PROGRESS FALSE
)
FetchContent_MakeAvailable(raylib)