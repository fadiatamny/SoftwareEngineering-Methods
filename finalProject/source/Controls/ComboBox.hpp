#pragma once
#include "./Panel.hpp"
#include "./Label.hpp"
#include "./Button.hpp"
#include "../Common/Border/Border.hpp"
#include "string"

class ComboBox :public Panel {
    public:
    ComboBox(short x,short y, short width, Border* border,Color colorText,Color color);
    ~ComboBox();
    void draw(Graphics &g,int x,int y,size_t z);
    void keyDown(int key, char character);

};