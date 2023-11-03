//
// Created by youba on 25/10/2023.
//

#pragma once

#include <chrono>

namespace Uniti {
    class Clock {
    public:
        Clock();
        void restart();
        float getSeconds() const;
        float getMilliSeconds() const;
        float getMicroSeconds() const;
        void pause();
        void start();
    private:
        std::chrono::high_resolution_clock::time_point _start;
        std::chrono::high_resolution_clock::time_point _pause;
        bool _paused = false;
    };
}
