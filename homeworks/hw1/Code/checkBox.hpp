#pragma once

#include "includes.hpp"
#include "component.hpp"

class CheckBoxItem
{
public:
    CheckBoxItem(std::string &val) : value(val), ticked(false) {}
    void setTicked(bool val) { this->ticked = val; }
    bool isTicked() const { return this->ticked; }
    const std::string getValue() { return this->value; }

private:
    bool ticked;
    std::string value;
};

class CheckBox : public Component
{
public:
    CheckBox(std::vector<std::string> list, COORD pos, DWORD color) : Component(pos, color), currPos(pos)
    {
        for (auto elem : list)
            this->list.push_back(std::shared_ptr<CheckBoxItem>(new CheckBoxItem(elem)));
    }
    CheckBox(std::vector<std::string> list, COORD pos, DWORD color, HANDLE handle, std::ostream &out) : Component(pos, color, handle, out), currPos(pos)
    {
        for (auto elem : list)
            this->list.push_back(std::shared_ptr<CheckBoxItem>(new CheckBoxItem(elem)));
    }
    ~CheckBox() {}

    void draw() throw(Exception) override;
    void handleKeyStroke(KEY_EVENT_RECORD &e) throw(Exception) override;

    inline void moveUp()
    {
        if (this->index > 0)
        {
            --this->index;
            --this->currPos.Y;
            SetConsoleCursorPosition(this->handle, this->currPos);
        }
    }
    inline void moveDown()
    {
        if (this->index < this->list.size() - 1)
        {
            ++this->index;
            ++this->currPos.Y;
            SetConsoleCursorPosition(this->handle, this->currPos);
        }
    }
    inline void select()
    {
        this->list[index]->setTicked(!this->list[index]->isTicked());
    }

    const std::vector<std::string> getSelected() const
    {
        std::vector<std::string> selected;
        for (auto elem : this->list)
            if (elem->isTicked())
                selected.push_back(elem->getValue());
        return selected;
    }
    void setList(std::vector<std::string> &list)
    {
        this->list.clear();
        for (auto elem : list)
            this->list.push_back(std::shared_ptr<CheckBoxItem>(new CheckBoxItem(elem)));
    }

private:
    COORD currPos;
    std::vector<std::shared_ptr<CheckBoxItem>> list;
    unsigned int index = 0;
};