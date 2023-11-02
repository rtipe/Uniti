cmake_minimum_required(VERSION 3.22)

target_include_directories(Render PUBLIC ".")

target_sources(Render PUBLIC
        IPrintable.hpp
        IPrintablePlugin.hpp
        ISprite.hpp
        IText.hpp)