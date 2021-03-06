#pragma once

#include "./Panel.hpp"
#include "../Common/Control.hpp"
#include "./Button.hpp"
#include "./Label.hpp"
#include <string>

class NumericBox : public Panel
{
public:
    NumericBox(short x, short y, int max, int min, Border *border, Color color, Color backgroundColor) : Panel(x, y, border, color, backgroundColor),
                                                                                                         curr((max + min) / 2),
                                                                                                         valueText(Label(" ", x + 5, y, 3, color, backgroundColor, border)),
                                                                                                         addBtn(Button(" + ", x + 12, y, 1, color, backgroundColor, border, this, 1)),
                                                                                                         subBtn(Button(" - ", x, y, 1, color, backgroundColor, border, this, 1)),
                                                                                                         maxNum(max),
                                                                                                         minNum(min)
    {
        this->valueText.setValue(std::to_string(this->curr));
        this->addControl(&this->addBtn);
        this->addControl(&this->subBtn);
        this->addControl(&this->valueText);
        this->addBtn.setActive(true);
        this->subBtn.setActive(true);
    }

    ~NumericBox() {}

    int getValue() const { return this->curr; };
    void setValue(int val)
    {
        if (val > this->maxNum || val < this->minNum)
            return;
        this->curr = val;
    };
    int getMin() const { return this->minNum; };
    void setMin(int val)
    {
        if (val > this->maxNum)
            return;
        this->minNum = val;
        this->curr = (this->maxNum + this->minNum) / 2;
    };
    int getMax() const { return this->minNum; };
    void setMax(int val)
    {
        if (val < this->minNum)
            return;
        this->maxNum = val;
        this->curr = (this->maxNum + this->minNum) / 2;
    };

    void draw(Graphics &g, int x, int y, size_t z);
    void keyDown(int keyCode, char character);
    void notify(std::string text);
    bool canGetFocus() { return true; };

private:
    Button subBtn;
    Button addBtn;
    Label valueText;
    int curr;
    int minNum;
    int maxNum;

    void increment();
    void decrement();
};