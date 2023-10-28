//
// Created by youba on 28/10/2023.
//

#pragma once


#include <string>
#include "json/value.h"

class ISound {
public:
    enum SoundStatus {
        RESUME,
        PAUSE,
        UNDEFINED
    };

    virtual ~ISound() = default;

    virtual bool playSound(const std::string &name, float volume) = 0;

    virtual bool playMusic(const std::string &name, float volume, bool loop) = 0;

    virtual bool pause(const std::string &name) = 0;

    virtual bool reset(const std::string &name) = 0;

    virtual bool changeVolume(const std::string &name, float volume) = 0;

    virtual SoundStatus getStatus(const std::string &name) = 0;

    virtual bool addSound(const Json::Value &value) = 0;

    virtual bool addSound(const std::string &name, const std::string &path) = 0;

    virtual bool addMusic(const Json::Value &value) = 0;

    virtual bool addMusic(const std::string &name, const std::string &path) = 0;
};
