//
// Created by youba on 25/10/2023.
//

#include "json/json.h"
#include "Logger.hpp"

namespace Uniti {
    void Logger::Log(const std::string &text) {
        std::string printElement = text;
        if (_events.count("print"))
            printElement = _events.at("print")(LOG, text);
        if (!printElement.empty())
            std::cout << "[Logger:Log] (" << _path << ") : " << printElement << std::endl;
    }

    void Logger::Warn(const std::string &text) {
        std::string printElement = text;
        if (_events.count("print"))
            printElement = _events.at("print")(WARN, text);
        if (!printElement.empty()) {
            printColor(YELLOW);
            std::cout << "[Logger:Warn] (" << _path << ") : " << printElement << std::endl;
            resetColor();
        }
    }

    void Logger::Danger(const std::string &text) {
        std::string printElement = text;
        if (_events.count("print"))
            printElement = _events.at("print")(DANGER, text);
        if (!printElement.empty()) {
            printColor(RED);
            std::cout << "[Logger:Danger] (" << _path << ") : " << printElement << std::endl;
            resetColor();
        }
    }

    void Logger::Info(const std::string &text) {
        std::string printElement = text;
        if (_events.count("print"))
            printElement = _events.at("print")(INFO, text);
        if (!printElement.empty()) {
            printColor(BLUE);
            std::cout << "[Logger:Info] (" << _path << ") : " << printElement << std::endl;
            resetColor();
        }
    }

    Logger &Logger::operator<<(const std::string &text) {
        if (text.empty()) return *this;
        this->_buffer << text;
        std::string print;
        for (const char &c : this->_buffer.str()) {
            if (c == '\n') {
                Print(this->_status, print);
                print.clear();
            } else {
                print += c;
            }
        }
        this->_buffer.clear();
        this->_buffer << print;
        return *this;
    }

    Logger &Logger::operator<<(const char *text) {
        this->_buffer << text;
        std::string print;
        for (const char &c : this->_buffer.str()) {
            if (c == '\n') {
                Print(this->_status, print);
                print.clear();
            } else {
                print += c;
            }
        }
        this->_buffer.clear();
        this->_buffer << print;
        return *this;
    }

    Logger &Logger::operator<<(const int &text) {
        this->_buffer << text;
        std::string print;
        for (const char &c : this->_buffer.str()) {
            if (c == '\n') {
                Print(this->_status, print);
                print.clear();
            } else {
                print += c;
            }
        }
        this->_buffer.clear();
        this->_buffer << print;
        return *this;
    }

    Logger &Logger::operator<<(const float &text) {
        this->_buffer << text;
        std::string print;
        for (const char &c : this->_buffer.str()) {
            if (c == '\n') {
                Print(this->_status, print);
                print.clear();
            } else {
                print += c;
            }
        }
        this->_buffer.clear();
        this->_buffer << print;
        return *this;
    }

    Logger &Logger::operator<<(const long &text) {
        this->_buffer << text;
        std::string print;
        for (const char &c : this->_buffer.str()) {
            if (c == '\n') {
                Print(this->_status, print);
                print.clear();
            } else {
                print += c;
            }
        }
        this->_buffer.clear();
        this->_buffer << print;
        return *this;
    }

    Logger &Logger::operator<<(const Json::Value &text) {
        Json::FastWriter fastWriter;
        std::string output = fastWriter.write(text);
        return this->operator<<(output);
    }

    void Logger::addEventListener(const std::string &name, Logger::eventLoggerFunction function) {
        _events[name] = function;
    }

    Logger::Logger() : _status(LOG) {}

    Logger::~Logger() {
        Print(this->_status, this->_buffer.str());
    }

    void Logger::changePath(const std::string &path) {
        _path = path;
    }

    void Logger::Print(Logger::STATUS status, const std::string &text) {
        switch (status) {
            case LOG:
                Logger::Log(text);
                break;
            case WARN:
                Logger::Warn(text);
                break;
            case DANGER:
                Logger::Danger(text);
                break;
            case INFO:
                Logger::Info(text);
                break;
        }
    }

    std::string &Logger::getPath() {
        return _path;
    }

    void Logger::changeStatus(Logger::STATUS status) {
        this->_status = status;
    }

    Logger::STATUS Logger::getStatus() {
        return this->_status;
    }
}
