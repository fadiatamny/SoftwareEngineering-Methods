#pragma once
#include "../Common/Control.hpp"
#include "../Common/Border/Border.hpp"
#include "../Common/Subject.hpp"
#include <string>


class Label : public Control, public Subject
{
public:
    Label(std::string value, short x, short y, short width, Color color, Color backgroundColor, Border *border, short height = 1) : Control(x, y, width, height, border, color, backgroundColor), value(value){};
    std::string getValue() const { return this->value; };
    void setValue(std::string value) { this->value = value; };
    void draw(Graphics &g, int x, int y, size_t z);

protected:
    std::string value;
};