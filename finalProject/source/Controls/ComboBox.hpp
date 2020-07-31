#pragma once
#include "./Panel.hpp"
#include "./Label.hpp"
#include "./Button.hpp"
#include "../Common/Border/Border.hpp"
#include "../Common/Border/BorderDoubleLineStyle.hpp"
#include "../Common/Border/BorderSingleLineStyle.hpp"
#include <string>

class ComboBox : public Panel
{
public:
    ComboBox(short x, short y, short width, Border *border, Color color, Color backgroundColor, Color highlight) : Panel(x, y, border, color, backgroundColor),
                                                                                                                   labelText("", x + 1, y + 1, 10, color, backgroundColor, border),
                                                                                                                   msg("ComboBox", x + 2, y - 1, 10, color, backgroundColor, border),
                                                                                                                   current(-1),
                                                                                                                   margin(top + 5),
                                                                                                                   isOpen(false),
                                                                                                                   highlight(highlight){};

    ~ComboBox() {}
    void addingToList(std::string listItem, Border *border);
    void draw(Graphics &g, int x, int y, size_t z);
    void keyDown(int key, char character);
    bool canGetFocus() { return true; }

private:
    int current;
    bool isOpen;
    int margin;
    Label msg;
    Label labelText;
    Color highlight;
};