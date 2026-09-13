//
// Created by youba on 28/10/2023.
//

#pragma once

#include "ISound.hpp"

/** @brief SFMLSound class for managing audio playback using SFML.
*/
class SFMLSound : public ISound {
public:
    /** @brief Play a sound with a specific name and volume.
        @param const std::string &name: Name of the sound.
        @param float volume: Volume level to set for the sound.
        @return bool: True if the sound was successfully played, false otherwise.
    */
    bool playSound(const std::string &name, float volume) override;

    /** @brief Play background music with a specific name, volume, and looping option.
        @param const std::string &name: Name of the music.
        @param float volume: Volume level to set for the music.
        @param bool loop: Indicates whether the music should loop.
        @return bool: True if the music was successfully played, false otherwise.
    */
    bool playMusic(const std::string &name, float volume, bool loop) override;

    /** @brief Pause audio playback with a specific name.
        @param const std::string &name: Name of the audio to pause.
        @return bool: True if the audio was successfully paused, false otherwise.
    */
    bool pause(const std::string &name) override;

    /** @brief Reset audio playback with a specific name.
        @param const std::string &name: Name of the audio to reset.
        @return bool: True if the audio was successfully reset, false otherwise.
    */
    bool reset(const std::string &name) override;

    /** @brief Change the volume of audio playback with a specific name.
        @param const std::string &name: Name of the audio to adjust the volume.
        @param float volume: New volume level to set for the audio.
        @return bool: True if the volume was successfully changed, false otherwise.
    */
    bool changeVolume(const std::string &name, float volume) override;

    /** @brief Get the status of audio playback with a specific name.
        @param const std::string &name: Name of the audio to check the status.
        @return SoundStatus: The current status of the audio (RESUME, PAUSE, or UNDEFINED).
    */
    SoundStatus getStatus(const std::string &name) override;

    /** @brief Add a sound from a JSON value.
        @param const Json::Value &value: JSON data containing sound information.
        @return bool: True if the sound was successfully added, false otherwise.
    */
    bool addSound(const Json::Value &value) override;

    /** @brief Add a sound from a name and file path.
        @param const std::string &name: Name of the sound.
        @param const std::string &path: File path to the sound.
        @return bool: True if the sound was successfully added, false otherwise.
    */
    bool addSound(const std::string &name, const std::string &path) override;

    /** @brief Add background music from a JSON value.
        @param const Json::Value &value: JSON data containing music information.
        @return bool: True if the music was successfully added, false otherwise.
    */
    bool addMusic(const Json::Value &value) override;

    /** @brief Add background music from a name and file path.
        @param const std::string &name: Name of the music.
        @param const std::string &path: File path to the music.
        @return bool: True if the music was successfully added, false otherwise.
    */
    bool addMusic(const std::string &name, const std::string &path) override;

private:
};

