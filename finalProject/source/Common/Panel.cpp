#include "./Panel.hpp"

Panel::Panel(short x, short y, Border *border, Color textC, Color backgroundColor) : Control(x, y, 15, 15, border, textC, backgroundColor)
{
    clacWidthAndHeight();
}

Panel::~Panel() {}

bool Panel::addControl(Control *control)
{
    if (control != nullptr)
    {
        try
        {
            controls.push_back(control);
            if (getFocus() == nullptr && control->canGetFocus())
            {
                setFocus(*control);
            }
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
    short calWidth = 0, calHight = 0, ciX, ciY, ciWidth, ciHight;
    for (int i = 0; i < controls.size(); ++i)
    {
        ciX = controls[i]->getLeft();
        ciY = controls[i]->getTop();
        ciHight = controls[i]->getHeight();
        ciWidth = controls[i]->getWidth();
        if (ciX + ciWidth > calWidth)
            calWidth = ciX + ciWidth;
        if (ciY + ciHight > calHight)
            calHight = ciY + ciHight;
    }
    setHeight(calHight + 5);
    setWidth(calWidth + 5);
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