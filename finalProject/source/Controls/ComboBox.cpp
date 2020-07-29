#include "ComboBox.hpp"

void ComboBox::draw(Graphics &g, int x, int y, size_t z)
{
    if (z == 0)
    {
        if (Control::getFocus() == this)
            msg.draw(g, msg.getLeft(), msg.getTop(), z);
        if (this->isShown())
            for (auto &value : Panel::controls)
            {
                value->draw(g, value->getLeft(), value->getTop(), z);
                this->margin = margin + 3;
            }
        text.draw(g, text.getLeft() + 1, text.getTop() + 1, z);
    }
}