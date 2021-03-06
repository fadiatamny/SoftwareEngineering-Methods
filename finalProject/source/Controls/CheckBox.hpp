#pragma once
#include "Button.hpp"
#include "../Common/Border/Border.hpp"

class CheckBox : public Button
{
public:
    CheckBox(short x, short y, short width, Border *border, Color colorText, Color color, std::string title, Observer *ob) : Button(title, x, y, width, colorText, color, border, ob,1),
                                                                                                                             selected(false),
                                                                                                                             value(title){};

    void select() { this->selected = !this->selected; };
    void draw(Graphics &g, int x, int y, size_t z);
    bool getSelected() { return selected; };
    bool canGetFocus() { return false; };

private:
    bool selected;
    std::string value;
};