#include "./Panel.hpp"

Panel::Panel(short x,short y, Border* border,Color textC,Color backgroundColor):
    Control(x,y,15,15, border,textC,backgroundColor) {
        clacWidthAndHeight();
    }

Panel::~Panel(){}

bool Panel::addControl(Control* control) {
    if(control != nullptr) {
        try
        {
            controls.push_back(control);
            if(getFocus() == nullptr && control->canGetFocus()) {
                setFocus(*control);
            }
        }
        catch(...)
        {
            return false;
        }
        return false;
    }
    return false;
}