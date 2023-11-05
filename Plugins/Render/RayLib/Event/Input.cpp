//
// Created by youba on 05/11/2023.
//

#include <raylib.h>
#include <map>
#include "Input.hpp"

static const std::map<IInput::Key, int> keyToRaylibKey = {
        {IInput::Key::A,          KEY_A},
        {IInput::Key::B,          KEY_B},
        {IInput::Key::C,          KEY_C},
        {IInput::Key::D,          KEY_D},
        {IInput::Key::E,          KEY_E},
        {IInput::Key::F,          KEY_F},
        {IInput::Key::G,          KEY_G},
        {IInput::Key::H,          KEY_H},
        {IInput::Key::I,          KEY_I},
        {IInput::Key::J,          KEY_J},
        {IInput::Key::K,          KEY_K},
        {IInput::Key::L,          KEY_L},
        {IInput::Key::M,          KEY_M},
        {IInput::Key::N,          KEY_N},
        {IInput::Key::O,          KEY_O},
        {IInput::Key::P,          KEY_P},
        {IInput::Key::Q,          KEY_Q},
        {IInput::Key::R,          KEY_R},
        {IInput::Key::S,          KEY_S},
        {IInput::Key::T,          KEY_T},
        {IInput::Key::U,          KEY_U},
        {IInput::Key::V,          KEY_V},
        {IInput::Key::W,          KEY_W},
        {IInput::Key::X,          KEY_X},
        {IInput::Key::Y,          KEY_Y},
        {IInput::Key::Z,          KEY_Z},
        {IInput::Key::Num0,       KEY_ZERO},
        {IInput::Key::Num1,       KEY_ONE},
        {IInput::Key::Num2,       KEY_TWO},
        {IInput::Key::Num3,       KEY_THREE},
        {IInput::Key::Num4,       KEY_FOUR},
        {IInput::Key::Num5,       KEY_FIVE},
        {IInput::Key::Num6,       KEY_SIX},
        {IInput::Key::Num7,       KEY_SEVEN},
        {IInput::Key::Num8,       KEY_EIGHT},
        {IInput::Key::Num9,       KEY_NINE},
        {IInput::Key::Escape,     KEY_ESCAPE},
        {IInput::Key::LControl,   KEY_LEFT_CONTROL},
        {IInput::Key::LShift,     KEY_LEFT_SHIFT},
        {IInput::Key::LAlt,       KEY_LEFT_ALT},
        {IInput::Key::LSystem,    KEY_LEFT_SUPER},
        {IInput::Key::RControl,   KEY_RIGHT_CONTROL},
        {IInput::Key::RShift,     KEY_RIGHT_SHIFT},
        {IInput::Key::RAlt,       KEY_RIGHT_ALT},
        {IInput::Key::RSystem,    KEY_RIGHT_SUPER},
        {IInput::Key::Menu,       KEY_MENU},
        {IInput::Key::LBracket,   KEY_LEFT_BRACKET},
        {IInput::Key::RBracket,   KEY_RIGHT_BRACKET},
        {IInput::Key::Semicolon,  KEY_SEMICOLON},
        {IInput::Key::Comma,      KEY_COMMA},
        {IInput::Key::Period,     KEY_PERIOD},
        {IInput::Key::Apostrophe, KEY_APOSTROPHE},
        {IInput::Key::Slash,      KEY_SLASH},
        {IInput::Key::Backslash,  KEY_BACKSLASH},
        {IInput::Key::Grave,      KEY_GRAVE},
        {IInput::Key::Equal,      KEY_EQUAL},
        {IInput::Key::Space,      KEY_SPACE},
        {IInput::Key::Enter,      KEY_ENTER},
        {IInput::Key::Backspace,  KEY_BACKSPACE},
        {IInput::Key::Tab,        KEY_TAB},
        {IInput::Key::PageUp,     KEY_PAGE_UP},
        {IInput::Key::PageDown,   KEY_PAGE_DOWN},
        {IInput::Key::End,        KEY_END},
        {IInput::Key::Home,       KEY_HOME},
        {IInput::Key::Insert,     KEY_INSERT},
        {IInput::Key::Delete,     KEY_DELETE},
        {IInput::Key::Add,        KEY_KP_ADD},
        {IInput::Key::Subtract,   KEY_KP_SUBTRACT},
        {IInput::Key::Multiply,   KEY_KP_MULTIPLY},
        {IInput::Key::Divide,     KEY_KP_DIVIDE},
        {IInput::Key::Left,       KEY_LEFT},
        {IInput::Key::Right,      KEY_RIGHT},
        {IInput::Key::Up,         KEY_UP},
        {IInput::Key::Down,       KEY_DOWN},
        {IInput::Key::Numpad0,    KEY_KP_0},
        {IInput::Key::Numpad1,    KEY_KP_1},
        {IInput::Key::Numpad2,    KEY_KP_2},
        {IInput::Key::Numpad3,    KEY_KP_3},
        {IInput::Key::Numpad4,    KEY_KP_4},
        {IInput::Key::Numpad5,    KEY_KP_5},
        {IInput::Key::Numpad6,    KEY_KP_6},
        {IInput::Key::Numpad7,    KEY_KP_7},
        {IInput::Key::Numpad8,    KEY_KP_8},
        {IInput::Key::Numpad9,    KEY_KP_9},
        {IInput::Key::F1,         KEY_F1},
        {IInput::Key::F2,         KEY_F2},
        {IInput::Key::F3,         KEY_F3},
        {IInput::Key::F4,         KEY_F4},
        {IInput::Key::F5,         KEY_F5},
        {IInput::Key::F6,         KEY_F6},
        {IInput::Key::F7,         KEY_F7},
        {IInput::Key::F8,         KEY_F8},
        {IInput::Key::F9,         KEY_F9},
        {IInput::Key::F10,        KEY_F10},
        {IInput::Key::F11,        KEY_F11},
        {IInput::Key::F12,        KEY_F12},
        {IInput::Key::Pause,      KEY_PAUSE}
};

void Input::update() {
    std::string name;

    for (const auto &element: keyToRaylibKey) {
        if (IsKeyPressed(element.second))
            _events.push_back("KEY_" + std::to_string(element.first) + "_PRESSED");
        if (IsKeyReleased(element.second))
            _events.push_back("KEY_" + std::to_string(element.first) + "_RELEASED");
    }
}

bool Input::isPressed(const std::string &key) {
    std::string name = key;
    for (auto &c: name)
        c = toupper(c);
    std::string eventName = "KEY_" + name + "_PRESSED";
    return std::find(Input::_events.begin(), Input::_events.end(), eventName) != Input::_events.end();
}

bool Input::isPressed(IInput::Key key) {
    std::string eventName = "KEY_" + std::to_string(key) + "_PRESSED";
    return std::find(Input::_events.begin(), Input::_events.end(), eventName) != Input::_events.end();
}

bool Input::isReleased(const std::string &key) {
    std::string name = key;
    for (auto &c: name)
        c = toupper(c);
    std::string eventName = "KEY_" + name + "_RELEASED";
    return std::find(Input::_events.begin(), Input::_events.end(), eventName) != Input::_events.end();
}

bool Input::isReleased(IInput::Key key) {
    std::string eventName = "KEY_" + std::to_string(key) + "_RELEASED";
    return std::find(Input::_events.begin(), Input::_events.end(), eventName) != Input::_events.end();
}

std::vector<std::string> &Input::getEvents() {
    return this->_events;
}

void Input::clearEvents() {
    this->_events.clear();
}