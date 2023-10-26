//
// Created by youba on 25/10/2023.
//

#include "Clock.hpp"

namespace Uniti {
    Clock::Clock()
    {
        _start = std::chrono::high_resolution_clock::now();
    }

    void Clock::restart()
    {
        _start  = std::chrono::high_resolution_clock::now();
        _paused = false;
    }

    float Clock::getSeconds() const
    {
        auto current_time = (!_paused) ? std::chrono::high_resolution_clock::now() : _pause;
        auto duration     = std::chrono::duration_cast<std::chrono::seconds>(current_time - _start);
        return static_cast<float>(duration.count());
    }

    float Clock::getMilliSeconds() const
    {
        auto current_time = (!_paused) ? std::chrono::high_resolution_clock::now() : _pause;
        auto duration     = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - _start);
        return static_cast<float>(duration.count());
    }

    float Clock::getMicroSeconds() const
    {
        auto current_time = (!_paused) ? std::chrono::high_resolution_clock::now() : _pause;
        auto duration     = std::chrono::duration_cast<std::chrono::microseconds>(current_time - _start);
        return static_cast<float>(duration.count());
    }

    void Clock::pause()
    {
        _paused = true;
        _pause  = std::chrono::high_resolution_clock::now();
    }

    void Clock::start()
    {
        if (_paused) {
            auto current_time = std::chrono::high_resolution_clock::now();
            auto pause_duration =
                    std::chrono::duration_cast<std::chrono::nanoseconds>(current_time - _pause);
            _start += pause_duration;
            _paused = false;
        } else {
            this->restart();
        }
    }
} // Uniti