//
// Created by youba on 25/10/2023.
//

#pragma once

#include <chrono>

namespace Uniti {
    class Clock {
    public:
        /** @brief Constructor for the Clock class. Initializes the clock.
        */
        Clock();

        /** @brief Restarts the clock, resetting its time.
        */
        void restart();

        /** @brief Get the elapsed time in seconds since the last restart.
            @return float: Elapsed time in seconds.
        */
        float getSeconds() const;

        /** @brief Get the elapsed time in milliseconds since the last restart.
            @return float: Elapsed time in milliseconds.
        */
        float getMilliSeconds() const;

        /** @brief Get the elapsed time in microseconds since the last restart.
            @return float: Elapsed time in microseconds.
        */
        float getMicroSeconds() const;

        /** @brief Pauses the clock, stopping the time measurement.
        */
        void pause();

        /** @brief Resumes the clock, continuing time measurement if paused.
        */
        void start();

    private:
        std::chrono::high_resolution_clock::time_point _start;
        std::chrono::high_resolution_clock::time_point _pause;
        bool _paused = false;
    };
}
