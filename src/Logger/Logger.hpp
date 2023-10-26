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
        ~Logger();
        using eventLoggerFunction = std::function<std::string(STATUS status, const std::string &text)>;
        static void Log(const std::string &text);
        static void Warn(const std::string &text);
        static void Danger(const std::string &text);
        static void Info(const std::string &text);
        static void Print(STATUS status, const std::string &text);
        Logger &operator<<(const std::string &text);
        Logger &operator<<(const char *text);
        Logger &operator<<(const int &text);
        Logger &operator<<(const float &text);
        Logger &operator<<(const long &text);
        Logger &operator<<(const Json::Value &text);
        static Logger Log();
        static Logger Warn();
        static Logger Danger();
        static Logger Info();
        static void addEventListener(const std::string &name, eventLoggerFunction function);
        static void changePath(const std::string &path);
        static std::string &getPath();
    private:
        Logger(STATUS status);
        static std::map<std::string, eventLoggerFunction> _events;
        static std::string _path;
        std::stringstream _buffer;
        STATUS _status;
    };
}
