#include "Control.hpp"

void Control::draw(Graphics &g, int x, int y, size_t z)
{
    if (this->shown)
    {
        if (getFocus() == this)
        {
            g.setForeground(this->backgroundColor);
            g.setBackground(this->color);
        }
        else
        {
            g.setForeground(this->color);
            g.setBackground(this->backgroundColor);
        }
        g.setCursorVisibility(false);

        this->border->draw(g, x, y, height + 2, width + 2);
    }
}

Control *Control::focus = nullptr;