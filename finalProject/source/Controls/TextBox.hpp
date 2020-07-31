#pragma once
#include <string>

#include "../Common/Control.hpp"
#include "./Label.hpp"
#include "../Common/Graphics.hpp"
#include "../Common/Border/Border.hpp"
#include <iostream>
#include <stdlib.h>

class TextBox : public Label
{
public:
    TextBox(short x, short y, short width, Border *border, Color color, Color backgroundColor) : Label("", x, y, width, color, backgroundColor, border)
    {
        auto handler = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(handler, {(short)(left + 1 + this->value.length()), (short)(top + 1)});
    }

    void draw(Graphics &g, int x, int y, size_t z);
    bool canGetFocus() { return true; }

    void keyDown(int keyCode, char character);
    void setText(std::string text) { this->value = text; };
    std::string getText() { return this->value; }

private:
    COORD currentCoord;
    unsigned int offset = 0;
    void handleStringInput(char c);
    void handleRepositionHori(int keyCode);
    void handleStringDelete(int keyCode);
};