#include "TextBox.hpp"

void TextBox::draw(Graphics &g, int x, int y, size_t z)
{
    Label::draw(g, x + 1, y + 1, z);
    g.moveTo(currentCoord.X + 2, currentCoord.Y + 2);
    g.setCursorVisibility(true);
}

void TextBox::handleStringInput(char c)
{
    if (this->offset >= this->width && this->value.length() >= this->width)
        return;
    this->value.replace(this->offset, this->offset, &c);
    this->offset++;
    ++this->currentCoord.X;
}

void TextBox::handleRepositionHori(int keyCode)
{
    if (this->offset - 1 >= 0 && keyCode == VK_LEFT)
    {
        --this->currentCoord.X;
        --this->offset;
    }
    else if (this->offset - 1 < value.length() && keyCode == VK_RIGHT)
    {
        ++this->currentCoord.X;
        ++this->offset;
    }
}

void TextBox::handleStringDelete(int keyCode)
{
    if (keyCode == VK_BACK && this->value.length() > 0 && offset - 1 >= 0)
    {
        char c = '\0';
        this->value.replace(this->offset - 1, this->offset - 1, &c);
        --this->currentCoord.X;
        --this->offset;
    }
}

void TextBox::keyDown(int keyCode, char character)
{
    if ((keyCode >= 0x30 && keyCode <= 122) || keyCode == VK_SPACE)
        this->handleStringInput(character);

    if (keyCode == VK_LEFT || keyCode == VK_RIGHT)
        this->handleRepositionHori(keyCode);

    if (value.length() > 0 && (keyCode == VK_BACK || keyCode == VK_DELETE))
        this->handleStringDelete(keyCode);
}