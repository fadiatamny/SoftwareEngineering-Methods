#include "TextBox.hpp"

void TextBox::draw(Graphics &g, int x, int y, size_t z)
{
    Label::draw(g, x + 1, y + 1, z);
    g.moveTo(currentCoord.X + 2, currentCoord.Y + 2);
    if (this->getFocus() == this)
        g.setCursorVisibility(true);
}

void TextBox::handleStringInput(char c)
{
    if (this->value.length() >= width)
        return;
    value.insert(this->currentCoord.X - this->left - 1, &c);
    ++this->currentCoord.X;
}

void TextBox::handleRepositionHori(int keyCode)
{
    if (this->currentCoord.X - this->left - 1 >= 0 && keyCode == VK_LEFT)
    {
        --this->currentCoord.X;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), this->currentCoord);
    }
    else if (this->currentCoord.X - this->left - 1 < value.length() && keyCode == VK_RIGHT)
    {
        ++this->currentCoord.X;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), this->currentCoord);
    }
}

void TextBox::handleStringDelete(int keyCode)
{
    if (keyCode == VK_BACK && this->value.length() > 0 && this->currentCoord.X - this->left - 1 >= 0)
    {
        this->value.erase(this->value.begin() + this->currentCoord.X - this->left - 2);
        --this->currentCoord.X;
    }
}

void TextBox::keyDown(int keyCode, char character)
{
    if ((keyCode >= 0x30 && keyCode <= 122) || keyCode == VK_SPACE)
        this->handleStringInput(character);
    else if (keyCode == VK_LEFT || keyCode == VK_RIGHT)
        this->handleRepositionHori(keyCode);
    else if (value.length() > 0 && (keyCode == VK_BACK || keyCode == VK_DELETE))
        this->handleStringDelete(keyCode);
}