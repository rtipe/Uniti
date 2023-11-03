//
// Created by youba on 01/11/2023.
//

#include <string>
#include "TextInput.hpp"
#include "RenderPlugin.hpp"
#include "Box.hpp"
#include "PluginCreator.hpp"
#include "API.hpp"

TextInput::TextInput(Uniti::Object &object) : _object(object) {}

Uniti::Object &TextInput::getObject() {
    return this->_object;
}

void TextInput::awake(const Json::Value &value) {
    this->_active = value.get("active", false).asBool();
    this->_height = value.get("height", 100).asFloat();
    this->_width = value.get("width", 300).asFloat();
    this->_maxChar = value.get("maxChar", 32).asInt();
}

void TextInput::preStart() {

}

void TextInput::start() {

}

void TextInput::postStart() {
    std::optional<std::reference_wrapper<RenderPlugin>> render = std::nullopt;
    try {
        render = this->_object.getCore().get<RenderPlugin &>("RenderPlugin");
    } catch (std::exception &e) {
        this->_object.getCore().log().Danger("RenderPlugin not found");
        return;
    }
    this->_window = render->get().getWindow();
}

void TextInput::preUpdate() {

}

void TextInput::checkActive() {
    if (this->_window->get().getMouse().isMousePressed(IMouse::LEFT)) {
        Uniti::Box box(0, 0, this->_width, this->_height);
        box.getPosition() = this->_object.getTransform().getPosition();
        Uniti::Vector2f positionMouse = this->_window->get().getMouse().getPosition();

        if (box.isInside(positionMouse)) {
            this->_active = true;
        } else {
            this->_active = false;
        }
    }
}

void TextInput::writeInputField() {
    auto &events = this->_window->get().getInput().getEvents();
    std::string text;
    int nbReturn = 0;

    if (!this->_active) return;
    for (const auto &event: events) {
        if (!event.ends_with("_PRESSED")) continue;
        size_t firstUnderscore = event.find('_');
        size_t secondUnderscore = event.find('_', firstUnderscore + 1);
        int keyId = std::stoi(event.substr(firstUnderscore + 1, secondUnderscore - firstUnderscore - 1));
        if (keyId >= 0 && keyId <= 25)
            text += keyId + 65;
        if (keyId == 57)
            text += "  ";
        if (keyId == 59)
            nbReturn++;
    }
    std::string nextString = _current + text;
    if (nextString.size() > this->_maxChar)
        nextString = nextString.substr(0, this->_maxChar);
    for (int i = 0; i < nbReturn && nextString.size() >= 1; i++)
        nextString = nextString.substr(0, nextString.length() - nbReturn);
    this->_current = nextString;
    this->_object.emitEvent("setString", nextString);
    this->_object.emitEvent("inputChange", nextString);
}

void TextInput::update() {
    if (!this->_window) return;
    this->checkActive();
    this->writeInputField();
}

void TextInput::postUpdate() {

}

void TextInput::preEnd() {

}

void TextInput::end() {

}

void TextInput::postEnd() {

}

const Uniti::Clock &TextInput::getClock() const {
    return this->_clock;
}

Uniti::Clock &TextInput::getClock() {
    return this->_clock;
}

const Uniti::Event &TextInput::getEvent() const {
    return this->_event;
}

Uniti::Event &TextInput::getEvent() {
    return this->_event;
}

extern "C" {
void *getCreator(void) {
    return new Uniti::PluginCreator<Uniti::IObjectPlugin, TextInput, Uniti::Object>();
}

void deleteCreator(void *creator) {
    delete static_cast<Uniti::PluginCreator<Uniti::IObjectPlugin, TextInput, Uniti::Object> *>(creator);
}
}
