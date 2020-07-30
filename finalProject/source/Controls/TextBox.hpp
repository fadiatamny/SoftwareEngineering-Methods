#pragma once
#include <string>
#include "../Common/Control.hpp"
#include "./Label.hpp"
#include "../../Common/Graphics.hpp"
#include "../Common/Border/Border.hpp"
#include <iostream>
#include <stdlib.h>

class TextBox : public Label{ 

public:
    COORD currentCoord;

    TextBox(short left, short top, short width, BorderDrawer* border, Color textColor, Color backgroundColor);

    void draw(Graphics& g, int x, int y, size_t z);
    bool canGetFocus(){ return true; }

    void keyDown(int keyCode, char character);
    void setText(string text);
    string getText() { return value; }
};