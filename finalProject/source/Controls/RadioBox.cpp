#include "./RadioBox.hpp"

void RadioBox::keyDown(int key, char character)
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

        for(auto control : this->controls)
        {
            temp = dynamic_cast<CheckBox *>(control);
            if(temp->getSelected())
            {
                temp->select();
                unselectItem(temp->getValue());
            }
        }
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