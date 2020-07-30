#pragma once
#include <iostream>
#include "Button.hpp"
#include "../Common/Border/Border.hpp"
#include <string>

class CheckBox : public Button
{
public:
    CheckBox(short x, short y, short width, Border *border, Color colorText, Color color, std::string title, Observer *ob) : Button(title, x, y, width, colorText, color, border, ob),
                                                                                                                             selected(false),
                                                                                                                             value(title){};

    void select() { this->selected = !this->selected; };

    void draw(Graphics &g, int x, int y, size_t z);
    bool getSelected() { return selected; };
    bool canGetFocus() { return true; };

private:
    bool selected;
    std::string value;
};