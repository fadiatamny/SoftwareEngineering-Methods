#pragma once
#include "./CheckList.hpp"

class RadioBox : public CheckList
{
public:
    RadioBox(std::string text, short x, short y, short width, Border *border, Color color, Color backColor) : CheckList(x, y, width, border, color, backColor, text){};
    void keyDown(int key, char charecter);
};