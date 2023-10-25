//
// Created by youba on 25/10/2023.
//

#pragma once

#include <string>
#include <functional>
#include "json/value.h"

namespace Uniti {
    class Logger {
    public:
        enum STATUS {
            LOG,
            WARN,
            DANGER,
            INFO
        };
        using eventLoggerFunction = std::function<std::string(STATUS status, const std::string &text)>;
        static void Log(const std::string &text);
        static void Warn(const std::string &text);
        static void Danger(const std::string &text);
        static void Info(const std::string &text);
        Logger &operator<<(const std::string &text);
        Logger &operator<<(const int &text);
        Logger &operator<<(const float &text);
        Logger &operator<<(const long &text);
        Logger &operator<<(const Json::Value &text);
        void addEventListener(eventLoggerFunction function);
    };
}
