//
// Created by youba on 25/10/2023.
//

#pragma once

namespace Uniti {
    class Clock {
        void restart();
        float getSeconds() const;
        float getMilliSeconds() const;
        float getMicroSeconds() const;
        void pause();
        void start();
    };
}
