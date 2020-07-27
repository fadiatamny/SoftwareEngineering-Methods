#include "Label.hpp"
#include <iostream>

void Label::draw(Graphics &g, int x, int y, size_t z)
{
    if (!z && this->isShown())
    {
        Control::draw(g, x, y, z);
        if (this->border != nullptr)
            this->border->draw(g, x, y, this->height, this->width);
        g.write(x + 1, y + 1, value);
    }
}
