cmake_minimum_required(VERSION 3.22)

target_sources(Uniti PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/Core.cpp"
)

target_include_directories(Uniti PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(Vector)
add_subdirectory(Box)
add_subdirectory(Color)
add_subdirectory(Logger)
add_subdirectory(Object)
add_subdirectory(Plugin)
add_subdirectory(Scene)
add_subdirectory(Time)
add_subdirectory(Event)