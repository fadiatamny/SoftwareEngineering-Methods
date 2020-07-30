#include "CheckBox.hpp"

void CheckBox::draw(Graphics &g, int x, int y, size_t z)
{
    std::string select = "[x] ";
    std::string notSelect = "[ ] ";
    if (selected)
        setValue(select + this->value);
    else
        setValue(notSelect + this->value);
    Label::draw(g, left, top, z);
};