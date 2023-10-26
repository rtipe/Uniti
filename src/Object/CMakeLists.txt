cmake_minimum_required(VERSION 3.22)

target_sources(Uniti PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/Object.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/ObjectUtils.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/ObjectManager.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Transform.cpp"
)

target_include_directories(Uniti PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")