#include "CheckList.hpp"

void CheckList::addItemToList(std::string listItem, Border *border)
{
    CheckBox *box = new CheckBox(this->left, this->margin, this->title.getWidth(), border, Color::Cyan, Color::White, listItem, this);
    box->setActive(false);
    this->addControl(box);
    this->margin += 3;
}

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
        temp->setColor(this->highlight);
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
        temp->setColor(this->highlight);
        break;

    default:
        break;
    };
};

void CheckList::draw(Graphics &g, int x, int y, size_t z)
{

    this->title.draw(g, x - 1, y, z);
    for (auto value : this->controls)
    {
        value->draw(g, value->getLeft(), value->getTop(), z);
    }
}

bool CheckList::selectItem(std::string item)
{
    for (auto box : this->selectedBoxes)
    {
        if (item.compare(box) == 0)
        {
            return false;
        }
    }
    selectedBoxes.push_back(item);
    return true;
}

bool CheckList::unselectItem(std::string item)
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