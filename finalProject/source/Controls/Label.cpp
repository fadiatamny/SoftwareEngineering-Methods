#include "Label.hpp"
#include <iostream>

void Label::draw(Graphics &g, int x, int y, size_t z)
{
    if (!z && this->isShown())
    {
        Control::draw(g, x, y, z);
        g.write(x + 1, y + 1, value);
    }
}
