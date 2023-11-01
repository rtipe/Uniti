//
// Created by youba on 25/10/2023.
//

#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#ifndef __linux__
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#else
#include <dlfcn.h>
#endif

#ifndef WINVER
    #define LIBTYPE void*
    #define OPENLIB(libname) dlopen((libname), RTLD_LAZY)
    #define LIBFUNC(lib, fn) dlsym((lib), (fn))
    #define GET_LIB_ERROR() dlerror()
    #define CLOSELIB(lib) dlclose((lib))
    #define FUNCTYPE void*
#else
    #define LIBTYPE HINSTANCE
    #define OPENLIB(libname) LoadLibrary(libname)
    #define LIBFUNC(lib, fn) GetProcAddress((lib), (fn))
    #define GET_LIB_ERROR() GetLastError()
    #define CLOSELIB(lib) FreeLibrary((lib))
    #define FUNCTYPE FARPROC
#endif

namespace Uniti {
    template<typename Interface, typename Creator, typename Parent>
    class PluginHandler {
    public:
        PluginHandler(const std::string &filePath) : _filePath(filePath) {
            this->_handler = OPENLIB(_filePath.c_str());
            if (!this->_handler) {
#ifndef WINVER
                char *error = nullptr;
                error = GET_LIB_ERROR();
#else
                char error[1024];
                FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM, nullptr, GET_LIB_ERROR(), 0, error, sizeof(error), nullptr);
                std::cout << GET_LIB_ERROR() << std::endl;
#endif
                throw std::runtime_error("Couldn't open in PluginHandler " + _filePath + ": " + std::string(error));
            }
            _creator = this->getResult<Creator *>("getCreator");
            if (!_creator)
                throw std::runtime_error("Creator couldn't be created in PluginHandler");
        }
        ~PluginHandler() {
            this->getResult<void>("deleteCreator", this->_creator);
            CLOSELIB(this->_handler);
        }
        Interface &get(Parent &parent) {
            Interface *element = this->_creator->create(parent);
            this->_elements.push_back(element);
            return *element;
        }
        void deleteElement(Interface *element) {
            this->_creator->remove(element);
            this->_elements.erase(std::find(this->_elements.begin(), this->_elements.end(), element));
        }
    protected:
        template<typename T, typename... Args>
        T getResult(const std::string &name, Args&&... __args) {
            FUNCTYPE sym = LIBFUNC(this->_handler, name.c_str());

            if (!sym) {
#ifndef WINVER
                char *error = nullptr;
                error = GET_LIB_ERROR();
#else
                char error[1024];
                FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM, nullptr, GET_LIB_ERROR(), 0, error, sizeof(error), nullptr);
#endif
                throw std::runtime_error(
                        "Error on open with dlsym in PluginHandler (" + name + " / " + this->_filePath + "): " +
                        std::string(error));
            }
            T (*function)(...) = reinterpret_cast<T(*)(...)>(sym);
            return function(__args...);
        }
        Creator *_creator;
        std::vector<Interface *> _elements;
        std::string _filePath;
        LIBTYPE _handler;
    };
}