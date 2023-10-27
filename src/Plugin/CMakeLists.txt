cmake_minimum_required(VERSION 3.22)

target_include_directories(Uniti PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(Uniti PUBLIC
        TPluginManager.hpp
        ScenePluginManager.hpp
        ICorePlugin.hpp
        IPlugin.hpp
        IObjectPlugin.hpp
        IScenePlugin.hpp
        PluginHandler.hpp
        ObjectPluginManager.hpp
        CorePluginManager.hpp
        PluginLoader.cpp)

add_subdirectory(Creator)
add_subdirectory(Factory)