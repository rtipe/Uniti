//
// Created by youba on 25/10/2023.
//

#pragma once

#include <windows.h>
#include <string>
#include <vector>
#include <stdexcept>

#ifdef __linux__
    #define LIBTYPE void*
    #define OPENLIB(libname) dlopen((libname), RTLD_LAZY)
    #define LIBFUNC(lib, fn) dlsym((lib), (fn))
    #define GET_LIB_ERROR() dlerror()
    #define CLOSELIB(lib) dlclose((lib))
    #define FUNCTYPE void*
#elif defined(WINVER)
    #define LIBTYPE HINSTANCE
    #define OPENLIB(libname) LoadLibrary(libname)
    #define LIBFUNC(lib, fn) GetProcAddress((lib), (fn))
    #define GET_LIB_ERROR() GetLastError()
    #define CLOSELIB(lib) FreeLibrary((lib))
    #define FUNCTYPE FARPROC
#endif

namespace Uniti {
    template<typename Interface, class Creator>
    class PluginHandler {
    public:
        PluginHandler(const std::string &filePath) {
            this->_handler = OPENLIB(filePath.c_str());
            if (!this->_handler) {
#ifdef __linux__
                char *error = nullptr;
                error = GET_LIB_ERROR();
#elif defined(WINVER)
                char error[1024];
                FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM, nullptr, GET_LIB_ERROR(), 0, error, sizeof(error), nullptr);
#endif
                throw std::runtime_error("Couldn't open in PluginHandler: " + std::string(error));
            }
            _creator = this->getResult<Creator *>("getCreator");
            if (!_creator)
                throw std::runtime_error("Creator couldn't be created in PluginHandler");
        }
        ~PluginHandler() {
            this->getResult<void>("deleteCreator", this->_creator);
            CLOSELIB(this->_handler);
        }
        Interface &get() {
            Interface *element = this->_creator->creator();
            this->_elements.push_back(element);
            return *element;
        }
        void deleteElement(Interface *element) {
            this->_creator->remove(element);
            this->_elements.erase(element);
        }
    protected:
        template<typename T, typename... Args>
        T getResult(const std::string &name, Args&&... __args) {
            FUNCTYPE sym = LIBFUNC(this->_handler, name.c_str());

            if (!sym) {
#ifdef __linux__
                char *error = nullptr;
                error = GET_LIB_ERROR();
#elif defined(WINVER)
                char error[1024];
                FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM, nullptr, GET_LIB_ERROR(), 0, error, sizeof(error), nullptr);
#endif
                throw std::runtime_error("Error on open with dlsym in PluginHandler: " + std::string(error));
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