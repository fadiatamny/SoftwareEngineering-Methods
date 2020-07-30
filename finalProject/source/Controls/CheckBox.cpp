#include "CheckBox.hpp"

void CheckBox::draw(Graphics &g, int x, int y, size_t z)
{
    std::string selected = "[X] ";
    std::string notSelected = "[ ] ";
    if (this->selected)
    {
        setValue("[X] " + this->value);
    }
    else
    {
        setValue("[ ] " + this->value);
    }
    Label::draw(g, left, top, z);
};