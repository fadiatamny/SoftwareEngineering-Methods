#include "MessageBoxPopup.hpp"
#include <iostream>

void MessageBoxPopup::draw(Graphics &g, int x, int y, size_t z)
{
    if (z == 0 && this->shown)
    {
        Panel::draw(g, x, y, z);
        if (this->messageText.isShown())
            this->messageText.draw(g, x + this->messageText.getLeft() + 1, y + this->messageText.getTop() + 1, z);
        if (this->okBtn.isShown())
            this->okBtn.draw(g, x + this->okBtn.getLeft() + 1, y + this->okBtn.getTop() + 1, z);
        if (this->cancelBtn.isShown())
            this->cancelBtn.draw(g, x + this->cancelBtn.getLeft() + 1, y + this->cancelBtn.getTop() + 1, z);
    }
}

void MessageBoxPopup::toggle()
{
    this->setShown(!this->shown);
    this->cancelBtn.setShown(this->shown);
    this->cancelBtn.setActive(this->shown);
    this->okBtn.setShown(this->shown);
    this->okBtn.setActive(this->shown);
    this->messageText.setShown(this->shown);
}

void MessageBoxPopup::notify(std::string text)
{
    if (text == this->actionBtn->getValue())
    {
        this->toggle();
    }
    else if (text == this->okBtn.getValue())
    {
        this->performed = text;
        this->toggle();
    }
    else if (text == this->cancelBtn.getValue())
    {
        this->performed = text;
        this->toggle();
    }
}