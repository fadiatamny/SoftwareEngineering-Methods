#include "./RadioBox.hpp"

void RadioBox::keyDown(int key, char character)
{
    CheckBox *temp;

    int size = Panel::controls.size();
    switch (key)
    {
    case VK_UP:
        if (current == 0)
            current = size - 1;
        else
            --current;
        for (auto &value : Panel::controls)
            value->setColor(color);
        temp = dynamic_cast<CheckBox *>(Panel::controls[current]);
        if (temp == nullptr)
            return;
        temp->setColor(Color::Green);
        break;

    case VK_SPACE:
        if (current == -1)
            ++current;
        for (int i = 0; Panel::controls.size() > i; ++i)
        {
            temp = dynamic_cast<CheckBox *>(Panel::controls[i]);
            if (temp == nullptr)
                return;
            if (temp->getSelected())
            {
                temp->getSelected();
                unselectItem(temp->getValue());
            }
        }
        temp = dynamic_cast<CheckBox *>(Panel::controls[current]);
        if (temp == nullptr)
            return;
        temp->getSelected();
        if (temp->getSelected())
            selectItem(temp->getValue());
        else
            unselectItem(temp->getValue());
        break;

    case VK_DOWN:
        if (current == size - 1)
            current = 0;
        else
            ++current;
        for (auto &value : Panel::controls)
            value->setColor(color);
        temp = dynamic_cast<CheckBox *>(Panel::controls[current]);
        if (temp == nullptr)
            return;
        temp->setColor(Color::Green);
        break;
    };
};