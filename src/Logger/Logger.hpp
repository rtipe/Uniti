//
// Created by youba on 25/10/2023.
//

#pragma once

#include <string>
#include <functional>
#include "json/value.h"

#ifndef __linux__
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#endif

namespace Uniti {
    class Logger {
    public:
        enum STATUS {
            LOG,
            WARN,
            DANGER,
            INFO
        };
        enum Color {
            RED,
            BLUE,
            YELLOW,
            WHITE
        };

        Logger();
        ~Logger();
        using eventLoggerFunction = std::function<std::string(STATUS status, const std::string &text)>;

        void Log(const std::string &text);

        void Warn(const std::string &text);

        void Danger(const std::string &text);

        void Info(const std::string &text);

        void Print(STATUS status, const std::string &text);
        Logger &operator<<(const std::string &text);
        Logger &operator<<(const char *text);
        Logger &operator<<(const int &text);
        Logger &operator<<(const float &text);
        Logger &operator<<(const long &text);
        Logger &operator<<(const Json::Value &text);

        void addEventListener(const std::string &name, eventLoggerFunction function);

        void changePath(const std::string &path);

        std::string &getPath();

        void changeStatus(STATUS status);

        STATUS getStatus();
    private:
        void printColor(Color color) {
#ifdef WINVER
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

            switch (color) {
                case RED:
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                    break;
                case BLUE:
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                    break;
                case YELLOW:
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                    break;
                case WHITE:
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    break;
                default:
                    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
                    break;
            }
#else
            switch (color) {
                case RED:
                    std::cout << "\x1B[31m";
                    break;
                case BLUE:
                    std::cout << "\x1B[34m";
                    break;
                case YELLOW:
                    std::cout << "\x1B[33m";
                    break;
                case WHITE:
                    std::cout << "\x1B[37m";
                    break;
                default:
                    std::cout << "\x1B[0m";
                    break;
            }
#endif
        }

        void resetColor() {
#ifdef WINVER
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
#else
            std::cout << "\x1B[0m";
#endif
        }

        std::map<std::string, eventLoggerFunction> _events;
        std::string _path;
        std::stringstream _buffer;
        STATUS _status;
    };
}
