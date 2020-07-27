#include "Button.hpp"

void Button::keyDown(int keyCode, char character)
{
    if (keyCode == VK_SPACE)
    {
        performAction(this->getValue());
    }
}
