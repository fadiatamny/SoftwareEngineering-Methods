#pragma once

#include "./Panel.hpp"
#include "../Common/Control.hpp"
#include "./Button.hpp"
#include "./Label.hpp"
#include <string>


class NumericBox : public Panel
{
public:
    NumericBox(short left, short top, int maxVal, int minVal, Border *border, Color textColor, Color backgroundColor);
    ~NumericBox() {}

    void increase();
    void decrease();
    int getVal();
    void setVal(int);
    int getMin();
    int setMin(int);
    int getMax();
    int setMax(int);
    bool setValue(int);
    void draw(Graphics &g, int x, int y, size_t z);
    void notify(std::string text);
    bool canGetFocus() { return true; };

private:
    int value;
    int minVal;
    int maxVal;
    Button subtract;
    Button add;
    Label currVal;
};