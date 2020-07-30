#pragma once
#include <vector>
#include "./CheckBox.hpp"
#include "./Panel.hpp"

class CheckList : public Panel
{
public:
    CheckList(short x, short y, short width, Border *border, Color colorText, Color color, std::string text) : Panel(x, y, border, colorText, color),
                                                                                                                          margin(y + 4),
                                                                                                                          current(-1),
                                                                                                                          title(text, x, y, width, colorText, color, border){};
    ~CheckList(){};

    virtual void addItemToList(std::string item, Border* border);
    bool selectItem(std::string item);
    bool unselectItem(std::string item);

    virtual void draw(Graphics &g, int x, int y, size_t z);
    virtual void keyDown(int keyCode, char charecter);
    bool canGetFocus() { return true; };

protected:
    std::vector<std::string> selectedBoxes;
    int margin;
    int current;
    Label title;
};
