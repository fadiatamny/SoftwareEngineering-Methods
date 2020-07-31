#pragma once
#include "./CheckList.hpp"

class RadioBox : public CheckList
{
public:
    RadioBox(std::string text, short x, short y, short width, Border *border, Color color, Color backColor, Color highlight) : CheckList(x, y, width, border, color, backColor, highlight, text){};
    void keyDown(int key, char charecter);
};