#include "ComboBox.hpp"

void ComboBox::draw(Graphics &g, int x, int y, size_t z)
{
    if (z == 0)
    {
        if (Control::getFocus() == this)
            msg.draw(g, msg.getLeft(), msg.getTop(), z);
        if (this->isShown())
            for (auto &value : Panel::controls)
            {
                value->draw(g, value->getLeft(), value->getTop(), z);
                this->margin = margin + 3;
            }
        labelText.draw(g, labelText.getLeft() + 1, labelText.getTop() + 1, z);
    }
}

void ComboBox::keyDown(int key, char character)
{
    Button *temp;

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
        temp = dynamic_cast<Button *>(Panel::controls[current]);
        if (temp == nullptr)
            return;
        temp->setColor(Color::Green);
        break;

    case VK_SPACE:
        if (current == -1)
            ++current;
        temp = dynamic_cast<Button *>(Panel::controls[current]);
        if (temp == nullptr)
            return;
        this->labelText.setValue(temp->getValue());
        this->isOpen = !this->isOpen;
        this->setShown(false);
        for (auto &val : Panel::controls)
            val->setShown(false);
        break;

    case VK_DOWN:
        if (current == size - 1)
            current = 0;
        else
            ++current;
        for (auto &value : Panel::controls)
            value->setColor(color);
        temp = dynamic_cast<Button *>(Panel::controls[current]);
        if (temp == nullptr)
            return;
        temp->setColor(Color::Green);
        break;

    default:
        break;
    };
};

void ComboBox::notifying(std::string item)
{
    if (item.compare(" +") == 0)
    {
        if (this->isOpen)
        {
            this->isOpen = !this->isOpen;
            this->setShown(false);
            for (auto &val : Panel::controls)
                val->setShown(false);
        }
        else
        {
            this->setShown(true);
            this->isOpen = !this->isOpen;
            for (auto &val : Panel::controls)
                val->setShown(false);
        }
    }
    else
    {
        this->labelText.setValue(item);
        this->isOpen = !this->isOpen;
        this->setShown(false);
        for (auto &val : Panel::controls)
            val->setShown(false);
    }
}

void ComboBox::addingToList(std::string listItem, Border* border)
{
    Button *button = new Button(listItem, left - 3, this->margin, 10, color, backgroundColor, border, this);
    button->setShown(false);
    button->setActive(false);
    this->addControl(button);
    this->margin += 3;
};