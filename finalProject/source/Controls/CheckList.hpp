#pragma once
#include <vector>
#include "./CheckBox.hpp"
#include "./Panel.hpp"
#include "../Common/Border/BorderSingleLineStyle.hpp"

class CheckList : public Panel
{
public:
    CheckList(short x, short y, short width, Border *border, Color colorText, Color color, std::string text);
    ~CheckList(){};

    void addItemToList(std::string listItem, Border *border);

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

    virtual void keyDown(int key, char charecter);
    virtual void draw(Graphics &g, int x, int y, size_t z);
    bool canGetFocus() { return true; };

protected:
    std::vector<std::string> selected;
    int margin;
    int current;
    Label msg;
};