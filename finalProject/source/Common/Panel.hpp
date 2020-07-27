#pragma once
#include "vector"
#include "./Border/Border.hpp"
#include "./Control.hpp"

class Panel : public Control {
    public:
        Panel(short x,short y, Border* border,Color textC,Color backgroundColor);
        ~Panel();

        bool addControl(Control* control);
        Control* getControl(int index);
        int getFoucusIndex();
        void emptyVec() {controls.clear();};

        virtual void draw(Graphics& g, int x,int y,size_t z);
        virtual void keyDown(int key,char charecter);
        virtual void getAllControls(std::vector<Control*>* controls);
    
    protected:
        std::vector<Control*> controls;
        int focusIndex;
        void clacWidthAndHeight();
};

