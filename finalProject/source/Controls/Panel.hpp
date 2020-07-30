#pragma once
#include "vector"
#include "../Common/Border/Border.hpp"
#include "../Common/Control.hpp"

class Panel : public Control
{
public:
    Panel(short x, short y, Border *border, Color textC, Color backgroundColor);
    ~Panel() {}

    bool addControl(Control *control);
    Control *getControl(int index)
    {
        if (index < 0 || index > this->controls.size())
            return nullptr;
        return this->controls[index];
    };

    int getFoucusIndex();
    void emptyVec() { controls.clear(); };

    virtual void draw(Graphics &g, int x, int y, size_t z);
    virtual void keyDown(int key, char charecter)
    {
        if (getFocusIndex() != -1)
            controls[focusIndex]->keyDown(key, charecter);
    };
    virtual void getAllControls(std::vector<Control *> *controls)
    {
        for (int i = 0; this->controls.size(); ++i)
        {
            controls->push_back(this->controls[i]);
            this->controls[i]->getAllControls(controls);
        }
    };

protected:
    std::vector<Control *> controls;
    int focusIndex;

private:
    void clacWidthAndHeight();
};
