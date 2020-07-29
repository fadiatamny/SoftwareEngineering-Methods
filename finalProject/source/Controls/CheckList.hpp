#pragma once
#include <vector>
#include "./CheckBox.hpp"
#include "./Panel.hpp"
#include "../Common/Border/BorderSingleLineStyle.hpp"

class CheckList : public Panel
{
public:
    CheckList(short x, short y, short width, Border *border, Color colorText, Color color, std::string text) : Panel(x, y, border, colorText, color), margin(y + 4), current(-1), msg(text, x, y, width, colorText, color, border){};

    ~CheckList()
    {
        if (border)
            delete border;
    };

    virtual void addItemToList(std::string listItem)
    {
        ChackBox *newItem = new ChackBox(left, this->margin, 11, new BorderSingleLineStyle(), Color::Orange, Color::Black, listItem, this);
        newItem->setActive(false);
        this->width = width + 3;
    };

    bool selectItem(std::string listItem)
    {
        for (int i = 0; selected.size() > i; ++i)
            if (listItem.compare(selected[i]) == 0)
            {
                selected.erase(selected.begin() + i);
                return true;
            }
        return false;
    };

    bool unselectItem(std::string listItem)
    {
        for (int i = 0; selected.size() > i; ++i)
            if (listItem.compare(selected[i]) == 0)
                return false;
        selected.push_back(listItem);
        return true;
    };
    ;

    virtual void draw(Graphics &g, int x, int y, size_t z)
    {
        if (Control::getFocus() == this)
            msg.draw(g, x, y, z);
        for (auto &value : Panel::controls)
            value->draw(g, value->getLeft(), value->getTop(), z);
    };

    virtual void keyDown(int key, char charecter);
    bool canGetFocus() { return true; };

protected:
    std::vector<std::string> selected;
    int margin;
    int current;
    Label msg;
};