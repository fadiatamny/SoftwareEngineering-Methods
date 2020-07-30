#include "CheckList.hpp"

void CheckList::addItemToList(std::string listItem, Border *border)
{
    CheckBox *newItem = new CheckBox(this->left, this->margin, 10, border, Color::Cyan, Color::Black, listItem, this);
    newItem->setActive(false);
    this->addControl(newItem);
    this->margin += 3;
};

void CheckList::keyDown(int keyCode, char character)
{
    CheckBox *temp;

    int size = Panel::controls.size();
    if (keyCode == VK_UP)
    {
        if (this->current == 0)
        {
            this->current = size - 1;
        }
        else
        {
            --this->current;
        }

        for (auto &value : Panel::controls)
        {
            value->setColor(color);
        }
        temp = dynamic_cast<CheckBox *>(Panel::controls[this->current]);
        temp->setColor(Color::White);
    }
    if (keyCode == VK_SPACE)
    {
        if (this->current == -1)
            ++this->current;
        temp = dynamic_cast<CheckBox *>(Panel::controls[this->current]);

        temp->select();

        if (temp->getSelected())
        {
            addSelectedItem(temp->getValue());
        }
        else
        {
            removeSelectedItem(temp->getValue());
        }
    }
    if (keyCode == VK_DOWN)
    {
        if (this->current == size - 1)
        {
            this->current = 0;
        }
        else
        {
            ++this->current;
        }

        for (auto &value : Panel::controls)
        {
            value->setColor(color);
        }
        temp = dynamic_cast<CheckBox *>(Panel::controls[this->current]);
        temp->setColor(Color::White);
    }
}

void CheckList::draw(Graphics &g, int x, int y, size_t z)
{

    this->title.draw(g, x, y, z);
    for (auto value : this->controls)
    {
        value->draw(g, value->getLeft(), value->getTop(), z);
    }

}

bool CheckList::addSelectedItem(std::string item)
{
    for (int i = 0; i < selectedBoxes.size(); ++i)
    {
        if (item.compare(selectedBoxes[i]) == 0)
        {
            return false;
        }
    }
    selectedBoxes.push_back(item);
    return true;
}

bool CheckList::removeSelectedItem(std::string item)
{
    for (int i = 0; i < selectedBoxes.size(); ++i)
    {
        if (item.compare(selectedBoxes[i]) == 0)
        {
            selectedBoxes.erase(selectedBoxes.begin() + i);
            return true;
        }
    }
    return false;
}