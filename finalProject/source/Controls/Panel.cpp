#include "./Panel.hpp"

Panel::Panel(short x, short y, Border *border, Color textC, Color backgroundColor) : Control(x, y, 15, 15, border, textC, backgroundColor)
{
    clacWidthAndHeight();
}

bool Panel::addControl(Control *control)
{
    if (control != nullptr)
    {
        try
        {
            controls.push_back(control);
            if (getFocus() == nullptr && control->canGetFocus())
                setFocus(*control);
            this->clacWidthAndHeight();
        }
        catch (...)
        {
            return false;
        }
        return false;
    }
    return false;
}

void Panel::clacWidthAndHeight()
{
    short calWidth = 0, calHight = 0;
    for (auto control : this->controls)
    {
        if ((control->getLeft() + control->getWidth()) > calWidth)
            calWidth = control->getLeft() + control->getWidth();
        if ((control->getTop() + control->getHeight()) > calHight)
            calHight = control->getTop() + control->getHeight();
    }
    this->setHeight(calHight + 5);
    this->setWidth(calWidth + 5);
}

int Panel::getFoucusIndex()
{
    Control *temp = getFocus();
    for (int i = 0; i < controls.size(); ++i)
        if (controls[i] == temp)
        {
            focusIndex = i;
            return i;
        }
        else if (controls[i]->getFocusIndex() != -1)
        {
            focusIndex = i;
            return i;
        }

    focusIndex = -1;
    return -1;
}

void Panel::draw(Graphics &g, int x, int y, size_t z)
{
    int relX;
    int relY;
    clacWidthAndHeight();
    if (z == 0 && this->isShown())
    {
        Control::draw(g, x, y, z);

        for (int i = 0; controls.size() > i; ++i)
        {
            relX = controls[i]->getLeft();
            relY = controls[i]->getTop();
            g.setBackground(controls[i]->getBackgroundColor());
            g.setForeground(controls[i]->getColor());
            controls[i]->draw(g, x + relX + 1, y + relY + 1, z);
        }
    }
    if (z == 1 && this->isShown())
    {
        if (getFocusIndex() != -1)
        {
            relX = controls[focusIndex]->getLeft();
            relY = controls[focusIndex]->getTop();
            g.setBackground(controls[focusIndex]->getBackgroundColor());
            g.setForeground(controls[focusIndex]->getColor());
            controls[focusIndex]->draw(g, x + relX + 1, y + relY + 1, 0);
        }
    }
}