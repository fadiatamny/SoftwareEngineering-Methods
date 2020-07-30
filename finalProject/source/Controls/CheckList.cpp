#include "CheckList.hpp"

CheckList::CheckList(short x, short y, short width, Border *border, Color colorText, Color color, std::string text) : Panel(x, y, border, colorText, color),
                                                                                                                      margin(y + 4),
                                                                                                                      current(-1),
                                                                                                                      msg(text, x, y, width, colorText, color, border)
{
    this->addControl(&this->msg);
};

void CheckList::addItemToList(std::string listItem, Border *border)
{
    CheckBox *newItem = new CheckBox(this->left, this->margin, 11, border, this->color, this->backgroundColor, listItem, this);
    newItem->setActive(false);
    this->addControl(newItem);
    this->margin += 3;
};

void CheckList::keyDown(int key, char character)
{
    CheckBox *temp;

    int size = this->controls.size();
    switch (key)
    {
    case VK_UP:
        if (this->current == 0)
            this->current = size - 1;
        else
            --this->current;
        for (auto &value : this->controls)
            value->setColor(color);
        temp = dynamic_cast<CheckBox *>(this->controls[this->current]);
        if (temp == nullptr)
            return;
        temp->setColor(Color::Green);
        break;

    case VK_SPACE:
        if (this->current == -1)
            ++this->current;
        temp = dynamic_cast<CheckBox *>(this->controls[this->current]);
        if (temp == nullptr)
            return;
        temp->select();
        if (temp->getSelected())
            selectItem(temp->getValue());
        else
            unselectItem(temp->getValue());
        break;

    case VK_DOWN:
        if (this->current == size - 1)
            this->current = 0;
        else
            ++this->current;
        for (auto &value : Panel::controls)
            value->setColor(color);
        temp = dynamic_cast<CheckBox *>(Panel::controls[this->current]);
        if (temp == nullptr)
            return;
        temp->setColor(Color::Green);
        break;

    default:
        break;
    };
};

void CheckList::draw(Graphics &g, int x, int y, size_t z)
{
    if (Control::getFocus() == this)
    {
        this->msg.draw(g, x, y, z);
    }
    for (auto value : this->controls)
    {
        value->draw(g, value->getLeft(), value->getTop(), z);
    }
}