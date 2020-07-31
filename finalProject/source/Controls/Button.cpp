#include "Button.hpp"

void Button::keyDown(int keyCode, char character)
{
    if (this->active && keyCode == VK_SPACE)
    {
        performAction(this->getValue());
    }
}