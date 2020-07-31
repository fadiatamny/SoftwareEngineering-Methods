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
    ComboBox(short x, short y, short width, Border *border, Color colorText, Color color) : Panel(x, y, border, colorText, color),
                                                                                            labelText("", x + 1, y + 1, 10, colorText, color, border),
                                                                                            msg("ComboBox", x + 2, y - 1, 10, Color::Red, Color::White, border),
                                                                                            current(-1),
                                                                                            margin(top + 5),
                                                                                            isOpen(false){};

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
};