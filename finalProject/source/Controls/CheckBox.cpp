#include "CheckBox.hpp"

void CheckBox::draw(Graphics &g, int x, int y, size_t z)
{
    if (this->selected)
        this->setValue("[x] " + this->value);
    else
        this->setValue("[ ] " + this->value);
    Label::draw(g, left, top, z);
};