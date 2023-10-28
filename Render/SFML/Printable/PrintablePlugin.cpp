//
// Created by youba on 28/10/2023.
//

#include "PrintablePlugin.hpp"

PrintablePlugin::PrintablePlugin(Uniti::Object &object) : _object(object) {}

Uniti::Object &PrintablePlugin::getObject() {
    return this->_object;
}

IPrintable &PrintablePlugin::getPrintable() const {
    if (this->_printable == nullptr)
        throw std::runtime_error("printable not ready");
    return *this->_printable;
}

IPrintable &PrintablePlugin::getPrintable() {
    if (this->_printable == nullptr)
        throw std::runtime_error("printable not ready");
    return *this->_printable;
}

void PrintablePlugin::awake(const Json::Value &value) {
    std::optional<std::reference_wrapper<RenderPlugin>> render = std::nullopt;
    try {
        render = this->_object.getCore().get<RenderPlugin &>("RenderPlugin");
    } catch (std::exception &e) {
        this->_object.getCore().log().Danger("RenderPlugin not found");
        return;
    }
    std::optional<std::reference_wrapper<Window>> window = std::nullopt;
    this->_window = render->get().getWindow();
    try {
        window = dynamic_cast<Window &>(render->get().getWindow());
    } catch (std::exception &e) {
        this->_object.getCore().log().Danger("RenderPlugin and PrintablePlugin are not compatible");
        return;
    }
    const std::string &type = value.get("type", "empty").asString();

    try {
        if (type == "sprite") {
            std::unique_ptr<Sprite> sprite =
                    std::make_unique<Sprite>(window->get().getRenderWindow());
            sprite->setTexture(value.get("texture", ""));
            sprite->setZIndex(value.get("zIndex", 0).asFloat());
            if (value.isMember("textureRect"))
                sprite->setTextureRect(value["textureRect"]);
            this->_printable = std::move(sprite);
        } else if (type == "text") {
            const std::string &fontName = value.get("font", "").asString();
            std::unique_ptr<Text> text =
                    std::make_unique<Text>(window->get().getRenderWindow());
            text->setFont(fontName);
            text->setString(value.get("text", "").asString());
            text->setColor(value["color"]);
            text->setZIndex(value.get("zIndex", 0).asFloat());
            const std::string &style = value.get("style", "regular").asString();
            if (style == "regular")
                text->setStyle(Text::REGULAR);
            if (style == "bold")
                text->setStyle(Text::BOLD);
            if (style == "italic")
                text->setStyle(Text::ITALIC);
            text->setCharacterSize(value.get("size", 24).asInt());
            this->_printable = std::move(text);
        } else if (type == "empty") {
            this->_object.getCore().log().Warn("Empty printable object created");
        } else {
            this->_object.getCore().log().Warn("Invalid printable type : " + type);
        }
    } catch (std::exception &e) {
        this->_object.getCore().log().Danger("Error while creating printable :");
        this->_object.getCore().log().Danger(e.what());
    }

}

void PrintablePlugin::preStart() {

}

void PrintablePlugin::start() {

}

void PrintablePlugin::postStart() {

}

void PrintablePlugin::preUpdate() {

}

void PrintablePlugin::update() {

}

void PrintablePlugin::postUpdate() {
    if (!this->_printable) return;
    this->_printable->setPosition(this->_object.getTransform().getPosition());
    this->_printable->setRotation(this->_object.getTransform().getRotation());
    this->_printable->setScale(this->_object.getTransform().getScale());
    this->_printable->setOrigin(this->_object.getTransform().getOrigin());
    this->_object.getCore().log().Info("add " + this->_object.getName() + " to display queue");
    this->_window->get().print(*this->_printable);
}

void PrintablePlugin::preEnd() {

}

void PrintablePlugin::end() {

}

void PrintablePlugin::postEnd() {

}

const Uniti::Clock &PrintablePlugin::getClock() const {
    return this->_clock;
}

Uniti::Clock &PrintablePlugin::getClock() {
    return this->_clock;
}

const Uniti::Event &PrintablePlugin::getEvent() const {
    return this->_event;
}

Uniti::Event &PrintablePlugin::getEvent() {
    return this->_event;
}
