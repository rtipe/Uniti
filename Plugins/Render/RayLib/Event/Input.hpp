//
// Created by youba on 05/11/2023.
//

#pragma once

#include "IInput.hpp"

class Input : public IInput {
public:
    Input();

    void update() override;

    bool isPressed(const std::string &key) override;

    bool isPressed(Key key) override;

    bool isReleased(const std::string &key) override;

    bool isReleased(Key key) override;

    std::vector<std::string> &getEvents() override;

    void clearEvents() override;

private:
    std::vector<std::string> _events;
};