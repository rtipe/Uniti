//
// Created by youba on 28/10/2023.
//

#pragma once

#include <string>
#include "json/value.h"

/** @brief Interface for sound and music management.
*/
class ISound {
public:
    /** @brief Enumerates different sound statuses.
    */
    enum SoundStatus {
        RESUME,
        PAUSE,
        UNDEFINED
    };

    /** @brief Virtual destructor for the ISound interface.
    */
    virtual ~ISound() = default;

    /** @brief Play a sound with a specific name and volume.
        @param name: The name of the sound to be played.
        @param volume: The volume level for the sound.
        @return bool: True if the sound is successfully played, false otherwise.
    */
    virtual bool playSound(const std::string &name, float volume) = 0;

    /** @brief Play music with a specific name, volume, and looping option.
        @param name: The name of the music to be played.
        @param volume: The volume level for the music.
        @param loop: True if the music should loop, false otherwise.
        @return bool: True if the music is successfully played, false otherwise.
    */
    virtual bool playMusic(const std::string &name, float volume, bool loop) = 0;

    /** @brief Pause a sound or music with a specific name.
        @param name: The name of the sound or music to be paused.
        @return bool: True if the sound or music is successfully paused, false otherwise.
    */
    virtual bool pause(const std::string &name) = 0;

    /** @brief Reset a sound or music with a specific name.
        @param name: The name of the sound or music to be reset.
        @return bool: True if the sound or music is successfully reset, false otherwise.
    */
    virtual bool reset(const std::string &name) = 0;

    /** @brief Change the volume of a sound or music with a specific name.
        @param name: The name of the sound or music to adjust the volume.
        @param volume: The new volume level.
        @return bool: True if the volume is successfully changed, false otherwise.
    */
    virtual bool changeVolume(const std::string &name, float volume) = 0;

    /** @brief Get the status of a sound or music with a specific name.
        @param name: The name of the sound or music to get the status of.
        @return SoundStatus: The status of the sound or music.
    */
    virtual SoundStatus getStatus(const std::string &name) = 0;

    /** @brief Add a sound based on a JSON value.
        @param value: The JSON value containing sound information.
        @return bool: True if the sound is successfully added, false otherwise.
    */
    virtual bool addSound(const Json::Value &value) = 0;

    /** @brief Add a sound with a specific name and file path.
        @param name: The name of the sound.
        @param path: The file path to the sound file.
        @return bool: True if the sound is successfully added, false otherwise.
    */
    virtual bool addSound(const std::string &name, const std::string &path) = 0;

    /** @brief Add music based on a JSON value.
        @param value: The JSON value containing music information.
        @return bool: True if the music is successfully added, false otherwise.
    */
    virtual bool addMusic(const Json::Value &value) = 0;

    /** @brief Add music with a specific name and file path.
        @param name: The name of the music.
        @param path: The file path to the music file.
        @return bool: True if the music is successfully added, false otherwise.
    */
    virtual bool addMusic(const std::string &name, const std::string &path) = 0;
};
