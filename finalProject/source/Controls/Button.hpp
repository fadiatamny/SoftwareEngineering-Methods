#pragma once
#include "Label.hpp"
#include "../Common/Observer.hpp"
#include <iostream>

class Button : public Label
{
public:
    Button(std::string value, short x, short y, short width, Color color, Color backgroundColor, Border *border, Observer *ob, short height = 3) : Label(value, x, y, width, color, backgroundColor, border, height)
    {
        if (ob != nullptr)
            addObserver(ob);
    };
    void keyDown(int keyCode, char character);
    bool canGetFocus() { return this->active; };
    void setActive(bool val) { this->active = val; };

private:
    bool active = true;
};