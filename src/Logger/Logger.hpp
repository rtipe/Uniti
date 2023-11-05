//
// Created by youba on 25/10/2023.
//

#pragma once

#include <string>
#include <functional>
#include <iostream>
#include "json/value.h"

#ifdef _WIN32 || _WIN64
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

        /** @brief Default constructor of the Logger class.
        */
        Logger();

        /** @brief Destructor of the Logger class.
        */
        ~Logger();

        using eventLoggerFunction = std::function<std::string(STATUS status, const std::string &text)>;

        /** @brief Logs a message to the log with "LOG" status.
            @param const std::string &text : Message to log.
        */
        void Log(const std::string &text);

        /** @brief Logs a message to the log with "WARN" status.
            @param const std::string &text : Message to log.
        */
        void Warn(const std::string &text);

        /** @brief Logs a message to the log with "DANGER" status.
            @param const std::string &text : Message to log.
        */
        void Danger(const std::string &text);

        /** @brief Logs a message to the log with "INFO" status.
            @param const std::string &text : Message to log.
        */
        void Info(const std::string &text);

        /** @brief Prints a message to the log with the specified status.
            @param STATUS status : Status of the message.
            @param const std::string &text : Message to print.
        */
        void Print(STATUS status, const std::string &text);

        /** @brief Overload of the << operator to log a string in the log.
            @param const std::string &text : String to log.
            @return Logger & : Reference to the Logger object.
        */
        Logger &operator<<(const std::string &text);

        /** @brief Overload of the << operator to log a character pointer in the log.
            @param const char *text : Character pointer to log.
            @return Logger & : Reference to the Logger object.
        */
        Logger &operator<<(const char *text);

        /** @brief Overload of the << operator to log an integer in the log.
            @param const int &text : Integer to log.
            @return Logger & : Reference to the Logger object.
        */
        Logger &operator<<(const int &text);

        /** @brief Overload of the << operator to log a floating-point number in the log.
            @param const float &text : Floating-point number to log.
            @return Logger & : Reference to the Logger object.
        */
        Logger &operator<<(const float &text);

        /** @brief Overload of the << operator to log a long integer in the log.
            @param const long &text : Long integer to log.
            @return Logger & : Reference to the Logger object.
        */
        Logger &operator<<(const long &text);

        /** @brief Overload of the << operator to log a JSON object in the log.
            @param const Json::Value &text : JSON object to log.
            @return Logger & : Reference to the Logger object.
        */
        Logger &operator<<(const Json::Value &text);

        /** @brief Adds a logging event listener associated with a given name.
            @param const std::string &name : Name of the event listener.
            @param eventLoggerFunction function : Event listener function to add.
        */
        void addEventListener(const std::string &name, eventLoggerFunction function);

        /** @brief Changes the log storage path.
            @param const std::string &path : New storage path.
        */
        void changePath(const std::string &path);

        /** @brief Returns the current log storage path (read/write).
            @return std::string & : Reference to the storage path.
        */
        std::string &getPath();

        /** @brief Changes the current log status.
            @param STATUS status : New log status.
        */
        void changeStatus(STATUS status);

        /** @brief Returns the current log status (read-only).
            @return STATUS : Current log status.
        */
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
