//
// Created by youba on 05/11/2023.
//

#include "Sound.hpp"

bool SFMLSound::playSound(const std::string &name, float volume) {
    return true;
}

bool SFMLSound::playMusic(const std::string &name, float volume, bool loop) {
    return true;
}

bool SFMLSound::pause(const std::string &name) {
    return false;
}

bool SFMLSound::reset(const std::string &name) {
    return false;
}

bool SFMLSound::changeVolume(const std::string &name, float volume) {
    return false;
}

ISound::SoundStatus SFMLSound::getStatus(const std::string &name) {
    return UNDEFINED;
}

bool SFMLSound::addSound(const Json::Value &value) {
    return true;
}

bool SFMLSound::addSound(const std::string &name, const std::string &path) {
    return true;
}

bool SFMLSound::addMusic(const Json::Value &value) {
    return true;
}

bool SFMLSound::addMusic(const std::string &name, const std::string &path) {
    return true;
}