#include "CheckList.hpp"

void CheckList::keyDown(int key,char character) {
    ChackBox *temp;

    int size = Panel::controls.size();
    switch (key)
    {
    case VK_UP:
        if (current == 0)
            current = size -1;
        else
            --current;
        for(auto &value : Panel::controls)
            value->setColor(color);
        temp = dynamic_cast<ChackBox*>(Panel::controls[current]);
        temp->setColor(Color::Green);
        break;

    case VK_SPACE:
        if(current == -1)
            ++current;
        temp = dynamic_cast<ChackBox*>(Panel::controls[current]);
        temp->select();
        if(temp->getSelected())
            selectItem(temp->getValue());
        else
            unselectItem(temp->getValue());
        break;
    
    case VK_DOWN:
        if (current == size -1)
            current = 0;
        else
            ++current;
        for(auto &value : Panel::controls)
            value->setColor(color);
        temp = dynamic_cast<ChackBox*>(Panel::controls[current]);
        temp->setColor(Color::Green);
        break;
    
    default:
        break;
    };
};