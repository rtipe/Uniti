cmake_minimum_required(VERSION 3.22)

target_sources(plugin PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/test.cpp"
)

target_include_directories(plugin PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
