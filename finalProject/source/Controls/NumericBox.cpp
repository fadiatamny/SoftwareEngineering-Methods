#include "./NumericBox.hpp"

void NumericBox::draw(Graphics &g, int x, int y, size_t z)
{
    if (z == 0)
    {
        this->valueText.draw(g, this->subBtn.getLeft() + 1, this->valueText.getTop() + 1, z);
        this->addBtn.draw(g, this->subBtn.getLeft() + 1, this->addBtn.getTop() + 1, z);
        this->subBtn.draw(g, this->subBtn.getLeft() + 1, this->subBtn.getTop() + 1, z);
    }
}

void NumericBox::notify(std::string text)
{
    if (text == " + ")
    {
        this->increment();
    }
    else
    {
        this->decrement();
    }
}

void NumericBox::increment()
{
    if (this->curr + 1 > this->maxNum)
        return;

    std::string strVal = "";
    ++this->curr;
    this->valueText.setValue(std::to_string(this->curr));
}

void NumericBox::decrement()
{
    if (this->curr - 1 < this->minNum)
        return;

    std::string strVal = "";
    --this->curr;
    this->valueText.setValue(std::to_string(this->curr));
}

void NumericBox::keyDown(int keyCode, char character)
{
    if (keyCode == VK_OEM_PLUS)
        this->increment();
    else if (keyCode == VK_OEM_MINUS)
        this->decrement();
}