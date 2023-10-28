//
// Created by youba on 28/10/2023.
//

#pragma once

#include "ISound.hpp"
#include <map>
#include <SFML/Audio.hpp>

class SFMLSound : public ISound {
public:
    bool playSound(const std::string &name, float volume) override;

    bool playMusic(const std::string &name, float volume, bool loop) override;

    bool pause(const std::string &name) override;

    bool reset(const std::string &name) override;

    bool changeVolume(const std::string &name, float volume) override;

    SoundStatus getStatus(const std::string &name) override;

    bool addSound(const Json::Value &value) override;

    bool addSound(const std::string &name, const std::string &path) override;

    bool addMusic(const Json::Value &value) override;

    bool addMusic(const std::string &name, const std::string &path) override;

private:
    std::map<std::string, sf::SoundBuffer> _soundsBuffer;
    std::map<std::string, sf::Sound> _sounds;
    std::map<std::string, std::unique_ptr<sf::Music>> _musics;
};
