cmake_minimum_required(VERSION 3.22)

target_sources(Uniti PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/Event.cpp"
)

target_include_directories(Uniti PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")